/* cally 逆向卡：DoPush（原版 libyoyo.so，armv7）
 * @func 0xe9e88 0xeb3f8  size 5488  1372 条指令
 * 级别: 正文（顶层 7 类、负 id 14 项分派、4 张 tag 表已逐条定位；
 *       -9/-10 的键/容器语义与各报错分支未逐条闭环）
 * 符号: _Z6DoPushjPhPKhP6VMExec → uchar* DoPush(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   序言 r7=exec r8=arg r4=sp r9=base r5=GOT；帧 2192+4 字节；哨兵值存 sp+0x88c   ; e9e8c-e9ebc
 *   PushContextStack(NULL) 与出口 PopContextStack 成对（全程持有一个空上下文帧）     ; e9ec0 / ea028
 *   kind = (arg >> 16) & 0xF                        ; e9ec4 ubfx r3,r8,#0x10,#0x4
 *   16 项跳转表（表基 0xe9ed4，addls 在 0xe9ecc）：                                 ; e9ed4..e9f0c
 *     0,1,3 → 0xea1f0   2,4 → 0xea04c   5 → 0xea06c   6 → 0xea130
 *     7 → 0xea19c       15 → 0xea05c    8..14 及 kind>15 → 0xea028（不压值）
 *   kind 0/1/3：ldrd r2,r3,[r9] / sub r4,#8 / strd → 压 8 字节，返回 sp-8          ; ea1f0-ea1fc
 *   kind 2/4  ：ldr r3,[r9] / sub r4,#4 / str      → 压 4 字节，返回 sp-4          ; ea04c-ea058
 *   kind 15   ：sxth r8,r8 / sub r4,#4 / str       → 压 (int16)arg，返回 sp-4       ; ea05c-ea068
 *   kind 6/7  ：new(12)+strlen→+8+YYStrDup→+0+计数1→+4，压 RefThing*（4 字节）     ; ea168-ea190
 *   kind 5    ：变量取值主体（下列 12 条）
 *     tst r8,#0x40000000（位 30）                  ; ea06c
 *     sxth r8,r8（id = 有符号低 16 位）             ; ea070
 *     w = *(uint32*)base                           ; ea078
 *     w>=0 → 从栈弹 base 值，否则 0x80000000 哨兵   ; ea080 / ea084
 *     tst w,#0x20000000（位 29）→ 0 则 id 也从栈弹   ; ea090 / ea094
 *     位 30 置位时 id += 100000                    ; ea09c / ea0a4
 *     mask = w & 0x0FFFFFFF → [sp+0x1c]            ; ea0a0 / ea0a8
 *     id == -9 → 0xea7c0；id == -10 → 0xe9f14      ; ea0ac/ea0b0、ea0b4/ea0b8
 *     模板：dest = sp-16，+0/+4/+8 清零，+12 = 0x00FFFFFF（未解析占位）  ; ea0c4-ea0d8
 *     负 id 二级分派：r2 = id+14 ≤13 → 14 项表（表基 0xea0f8）        ; ea0d0 / ea0ec / ea0f0
 *     tag 跳转表 4 份（0xea4d4 / 0xea55c / 0xeac20 / 0xeae50）映射一致  ; ea4cc / ea554 / eac18 / eae48
 *     未解析判据：dest 的 tag 字仍 == 0x00FFFFFF → 0xea5ac 报错        ; ea248-ea250
 *   出口：PopContextStack + 哨兵比较（不等 → __stack_chk_fail）+ 返回 r4    ; ea028-ea048 / eb214
 *
 * 已证（负 id → 处理块；全部为调用点 + 实参级证据）：
 *   -1  0xea2cc  Variable_GetValue_Direct(exec->[0x14], [sp+0x1c], [sp+0x24], dest)   ; ea2cc-ea2dc
 *   -2  0xea618  同上，基址换成 exec->[0x18]                                          ; ea618 / ea2d0
 *   -3  0xea628  Variable_GetValue(r8, [sp+0x1c], [sp+0x24], dest)                    ; ea628-ea638
 *   -4  0xea598  置 *(byte*)[sp+0x20]=1，随后并入共享报错 0xea5a8 → 0xea5ac            ; ea598-ea5a8
 *   -5  0xea22c  Variable_Global_GetVar([sp+0x1c], [sp+0x24], dest)                   ; ea22c-ea238
 *   -6  0xea21c  Variable_Global_Declared([sp+0x1c]) == 0 → 转 -1 的 0xea2cc           ; ea21c-ea228
 *   -7  0xea2f0  obj=exec->[0x10]；count=obj->[0x24]（0 → 报错 ea5a8）；src=obj->[0x4]+(idx-100000)*16
 *                （槽数组 obj->[0x4]==0 → 退 InternalGetYYVar(obj, slot)）；GET_RValue(dest, src, i)  ; ea2f0-ea32c
 *   -8  0xea340  仅当 [sp+0x1c] > 0x1869F(=99999) 才走 -7 的 GET_RValue；否则退到 0xea954
 *                （改用 exec->[0x14] 走 -1 的直接取值；它也空则 dest 保持占位 tag → 报错）   ; ea344-ea350
 *   -9  0xea7c0  双操作数：*sp→sp+0x3c、*(sp+16)→sp+0x4c，按第一操作数 tag 分派         ; ea7c0-ea82c
 *   -10 0xe9f14  同构双操作数，分派链在 e9f98-e9fb4（tag 2/5/6/0x00FFFFFF/其它）        ; e9f98-e9fb4
 *   -11 0xea39c  Variable_Scope_GetVar([sp+0x1c], [sp+0x24], dest)                   ; ea39c-ea3a8
 *   -12 0xea3bc  从 exec->[0x10] 沿 +0xc 链逐层试 slot=[sp+0x1c]-100000，命中即停       ; ea3bc-ea45c
 *   -13 0xea510  全局数组：表基=*(GOT)，项=table[mask&0xFF]，按项 tag 走 #2 表；
 *                次字节非 0 → 0xeab50（沿 +0xc 链下降 N 层后取槽）                     ; ea510-ea534 / eab50-eabb8
 *   -14 0xea620  r11=1 后进共享路径 0xea5a8（无取值动作）                              ; ea620-ea624
 *
 * 结论（新增六条硬事实）：
 *   1. DoPush 名下是 **7 种形态**，kind 只决定「压什么、压多宽」：8 字节（0/1/3）、4 字节（2/4）、
 *      4 字节符号扩展立即数（15）、4 字节字符串引用（6/7）、16 字节整 RValue（5）、不压（8..14）。
 *      4/8/16 三档宽度与 DoRet 的 size 参数完全对应，二者是同一套 push/return 协议的两端。
 *   2. 变量号基址 100000 再确认（#99328 + #672 两段加），并新证 **位 29 (0x20000000) = 「id 内嵌于 arg」**：
 *      该位为 0 时 ldreq r8,[r4],#4 从值栈取 id；位 30 置位才做 +100000。DoPop 已证的三条位域
 *      （[15:0] 有符号 count、[19:16] 种类、位 30 变量基址）在 DoPush 里即「种类 = 5、[15:0] = 变量 id」。
 *   3. 基址字 w 是**打包结构**：符号位 = 是否从栈弹对象值（负则 INT_MIN 当「无基址」哨兵）、
 *      bit30/bit29 如上、低 28 位单独存入 [sp+0x1c] 当索引/打包字段（-13 取它的低字节当数组下标、
 *      次字节当对象链深度）。
 *   4. 负 id 是第二级 opcode：14 项表把 push 目标分成 8 个变量域 —— exec+0x14、exec+0x18、全局表、
 *      作用域表、exec+0x10 对象链（两种查法：定槽 / 逐层试槽）、全局数组表、双操作数取下标
 *      （-9/-10）、无取值只报错（-4/-14）。
 *   5. RValue tag（+12 高字节，0..14）的拷贝语义在本函数以四份同构跳转表出现：
 *      0/10/13 → 拷 8 字节载荷；1 → _RefThing<const char*>::assign；2 → (+0) 计数++ 且 +8 回填持有者；
 *      3/7/14 → 只拷首字；6 → DeterminePotentialRoot(GetContextStackTop(), ptr)；4/5/8/9/11/12 → 不拷载荷。
 *      DoPop（表基 e7a90）与 DoPushGlobal（表基 d4c50）各有一份同样的表：DoPop 逐 case 同构，
 *      DoPushGlobal 仅 case 1 用内联 [ptr+4]++ 代替 _RefThing::assign（同一 RefThing 计数域）。
 *   6. 12 字节字符串 RefThing 布局：+0 = char*、+4 = 计数、+8 = 长度（构造 ea168-ea18c，
 *      释放 ead40-ead60：计数--，归零则 YYFree(*p) + operator delete）。YYObjectBase 侧：
 *      +0x04 变量槽数组、+0x24 槽数、+0x0C 上级链（-7 与 -12 两处同构证据）。
 *
 * open：-9/-10 的键/容器语义（0xea978 的 CHashMap 哈希探测 vs 0xead74 的 strcmp("length") +
 *       JSArrayGet/F_JS_Object_Get，两条路径各自适用条件未定）；kind 6 表项偏移为 0 时 0xea200
 *       把 r7 置 4 的意图（随后 strlen/YYStrDup 会拿 4 当指针）；kind 8..14 是否真为无操作；
 *       -4/-14 两条只报错的 id 在 GML 层的用途；exec+0x14/+0x18/+0x34 三个参数域与变量索引的对应。
 *
 * ── 结构（本批证到，逐条锚在下方）: 从变量读值入栈 ──
 *   Code_Variable_Find_Name ×6 → YYObjectBase::InternalGetYYVar ×6 → GET_RValue ×6；Variable_GetObjectName ×5 与 GetContextStackTop ×4 处理 with() 上下文；snprintf ×4（数值/字符串化）；FREE_RValue__Pre ×8 释放临时值
 *   ⚠ LOCK_RVALUE_MUTEX / UNLOCK_RVALUE_MUTEX 在本库是单条 `bx lr` 空桩（0x190f2c / 0x190f30），
 *     本函数里出现的「加锁」按无锁读，不写「有锁保护」。
 *   open: 变量名解析优先级（局部/实例/全局）、with 栈查表顺序、boxing 后 tag 归属
 */

/* 序言：r7=exec(r3) r8=arg(r0) r4=sp(r1) r9=base(r2)；r5=GOT 基址；开 2192+4 字节栈帧；全局哨兵值存入 sp+0x88c */
/* @0xe9e88 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xe9e8c mov r7, r3 */
/* @0xe9e90 ldr r5, [pc, #0xff4] */  —— r5 = GOT 基址（pc 相对）
/* @0xe9e94 sub sp, sp, #2192 */
/* @0xe9e98 ldr r12, [pc, #0xff0] */  —— r12 = GOT 槽偏移
/* @0xe9e9c sub sp, sp, #4 */
/* @0xe9ea0 add r5, pc, r5 */
/* @0xe9ea4 mov r8, r0 */  —— r8 = arg
/* @0xe9ea8 mov r0, #0 */
/* @0xe9eac mov r4, r1 */  —— r4 = sp
/* @0xe9eb0 ldr r6, [r5, r12] */
/* @0xe9eb4 mov r9, r2 */  —— r9 = base
/* @0xe9eb8 ldr r3, [r6] */  —— 载入全局哨兵
/* @0xe9ebc str r3, [sp, #0x88c] */

/* PushContextStack(NULL)：DoPush 全程压一个空上下文帧（与出口 ea028 的 PopContextStack 成对） */
/* @0xe9ec0 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */  —— PushContextStack(NULL)

/* 顶层分派：kind = (arg>>16)&0xF；16 项跳转表，表基 = e9ed4（addls 在 e9ecc，PC = e9ecc+8） */
/* @0xe9ec4 ubfx r3, r8, #0x10, #0x4 */  —— kind = (arg>>16)&0xF
/* @0xe9ec8 cmp r3, #15 */
/* @0xe9ecc addls pc, pc, r3, lsl #2 */  —— 16 项跳转表

/* 默认出口（kind>15 或 8..14）：不压任何值，直接走公共收尾 */
/* @0xe9ed0 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */

/* kind 0 → ea1f0（压 *base 的 8 字节） */
/* @0xe9ed4 b 0xea1f0 <_Z6DoPushjPhPKhP6VMExec+0x368> */
/* @0xe9ed8 b 0xea1f0 <_Z6DoPushjPhPKhP6VMExec+0x368> */

/* kind 2 → ea04c（压 *base 的 4 字节） */
/* @0xe9edc b 0xea04c <_Z6DoPushjPhPKhP6VMExec+0x1c4> */
/* @0xe9ee0 b 0xea1f0 <_Z6DoPushjPhPKhP6VMExec+0x368> */

/* kind 4 → ea04c */
/* @0xe9ee4 b 0xea04c <_Z6DoPushjPhPKhP6VMExec+0x1c4> */

/* kind 5 → ea06c（变量取值，本函数主体） */
/* @0xe9ee8 b 0xea06c <_Z6DoPushjPhPKhP6VMExec+0x1e4> */

/* kind 6 → ea130（字符串表 A） */
/* @0xe9eec b 0xea130 <_Z6DoPushjPhPKhP6VMExec+0x2a8> */

/* kind 7 → ea19c（字符串表 B） */
/* @0xe9ef0 b 0xea19c <_Z6DoPushjPhPKhP6VMExec+0x314> */
/* @0xe9ef4 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xe9ef8 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xe9efc b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xe9f00 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xe9f04 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xe9f08 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xe9f0c b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */

/* kind 15 → ea05c（压 sxth(arg)） */
/* @0xe9f10 b 0xea05c <_Z6DoPushjPhPKhP6VMExec+0x1d4> */

/* id == -10：双操作数取值（*sp 为键、*(sp+16) 为容器），先各拷进 sp+0x3c / sp+0x4c 两个 16 字节临时 RValue */
/* @0xe9f14 add r3, sp, #60 */
/* @0xe9f18 str r3, [sp, #0x2c] */
/* @0xe9f1c ldr r0, [r4] */
/* @0xe9f20 mov r10, r4 */
/* @0xe9f24 ldr r1, [r4, #0x4] */
/* @0xe9f28 add r11, sp, #76 */
/* @0xe9f2c ldr r2, [r4, #0x8] */
/* @0xe9f30 mov r9, #0 */
/* @0xe9f34 ldr r3, [r4, #0xc] */
/* @0xe9f38 ldr r12, [sp, #0x2c] */
/* @0xe9f3c stm r12!, {r0, r1, r2, r3} */
/* @0xe9f40 mov r12, r11 */

/* 第二个操作数（容器）的 16 字节拷到 sp+0x4c；随后把 dest（= sp+16）写成 {0,0,0,0x00FFFFFF} */
/* @0xe9f44 ldr r0, [r10, #0x10]! */
/* @0xe9f48 ldr lr, [sp, #0x48] */
/* @0xe9f4c ldr r1, [r10, #0x4] */
/* @0xe9f50 bic lr, lr, #-16777216 */
/* @0xe9f54 ldr r2, [r10, #0x8] */
/* @0xe9f58 cmp lr, #2 */
/* @0xe9f5c ldr r3, [r10, #0xc] */
/* @0xe9f60 stm r12!, {r0, r1, r2, r3} */
/* @0xe9f64 mvn r3, #-16777216 */
/* @0xe9f68 ldr r2, [pc, #0xf24] */
/* @0xe9f6c str r9, [r4, #0x10] */
/* @0xe9f70 str r9, [r4, #0x14] */
/* @0xe9f74 str r9, [r4, #0x18] */
/* @0xe9f78 str r3, [r4, #0x1c] */
/* @0xe9f7c ldr r2, [r5, r2] */
/* @0xe9f80 str r9, [sp, #0x5c] */
/* @0xe9f84 str r9, [sp, #0x60] */
/* @0xe9f88 str r2, [sp, #0x20] */
/* @0xe9f8c strb r9, [r2] */
/* @0xe9f90 str r9, [sp, #0x64] */
/* @0xe9f94 str r3, [sp, #0x68] */

/* 按第一个操作数的 tag 分流：2 → eb148（double 载荷转整数作下标）、5 → eb0bc、≤5 且非 3 → eafc4、6 → ead74、0x00FFFFFF → 0xeb23c/0xea008（ReferenceError） */
/* @0xe9f98 beq 0xeb148 <_Z6DoPushjPhPKhP6VMExec+0x12c0> */
/* @0xe9f9c cmp lr, #5 */
/* @0xe9fa0 beq 0xeb0bc <_Z6DoPushjPhPKhP6VMExec+0x1234> */
/* @0xe9fa4 ble 0xeafc4 <_Z6DoPushjPhPKhP6VMExec+0x113c> */
/* @0xe9fa8 cmp lr, #6 */
/* @0xe9fac beq 0xead74 <_Z6DoPushjPhPKhP6VMExec+0xeec> */
/* @0xe9fb0 cmp lr, r3 */
/* @0xe9fb4 bne 0xeafcc <_Z6DoPushjPhPKhP6VMExec+0x1144> */
/* @0xe9fb8 ldr r2, [sp, #0x1c] */
/* @0xe9fbc mov r1, r8 */
/* @0xe9fc0 ldr r0, [r7, #0x34] */
/* @0xe9fc4 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xe9fc8 ldr r1, [sp, #0x1c] */
/* @0xe9fcc mov r5, r0 */
/* @0xe9fd0 mov r0, r8 */
/* @0xe9fd4 bl 0x1f3f8c <_Z22Variable_GetObjectNameii> */
/* @0xe9fd8 ldr r2, [sp, #0x24] */
/* @0xe9fdc ldr r1, [sp, #0x1c] */
/* @0xe9fe0 str r5, [sp] */
/* @0xe9fe4 add r5, sp, #140 */
/* @0xe9fe8 str r2, [sp, #0x8] */
/* @0xe9fec ldr r2, [pc, #0xea4] */
/* @0xe9ff0 str r1, [sp, #0x4] */
/* @0xe9ff4 mov r1, #2048 */
/* @0xe9ff8 add r2, pc, r2 */
/* @0xe9ffc mov r3, r0 */
/* @0xea000 mov r0, r5 */
/* @0xea004 bl 0xb65c8 <snprintf@plt> */
/* @0xea008 mov r0, r5 */
/* @0xea00c strb r9, [sp, #0x88b] */
/* @0xea010 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xea014 mov r3, #5 */
/* @0xea018 str r9, [r4, #0x10] */
/* @0xea01c str r9, [r4, #0x14] */
/* @0xea020 str r3, [r4, #0x1c] */
/* @0xea024 mov r4, r10 */

/* 公共出口：PopContextStack → 比较栈哨兵（不等则 __stack_chk_fail）→ 恢复栈并返回 r4（新 sp） */
/* @0xea028 bl 0xd3a34 <_Z15PopContextStackv> */  —— PopContextStack()
/* @0xea02c ldr r2, [sp, #0x88c] */
/* @0xea030 ldr r3, [r6] */  —— 哨兵比较
/* @0xea034 mov r0, r4 */
/* @0xea038 cmp r2, r3 */  —— 哨兵不等 → __stack_chk_fail
/* @0xea03c bne 0xeb214 <_Z6DoPushjPhPKhP6VMExec+0x138c> */
/* @0xea040 add sp, sp, #2192 */
/* @0xea044 add sp, sp, #4 */
/* @0xea048 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */  —— 返回 r4 = 新 sp

/* kind 2/4：把 *base 的 4 字节原样压栈（sp -= 4），返回 sp-4 */
/* @0xea04c ldr r3, [r9] */  —— r3 = *(uint32*)base
/* @0xea050 sub r4, r4, #4 */  —— sp -= 4
/* @0xea054 str r3, [r4] */
/* @0xea058 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */

/* kind 15：压 (int16)arg 符号扩展后的 4 字节，返回 sp-4 */
/* @0xea05c sxth r8, r8 */  —— r8 = (int16)arg
/* @0xea060 sub r4, r4, #4 */
/* @0xea064 str r8, [r4] */
/* @0xea068 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */

/* kind 5 起点：tst 位 30 判「是否带变量基址」；sxth 取有符号 16 位 id */
/* @0xea06c tst r8, #1073741824 */  —— 位 30：带变量基址？
/* @0xea070 sxth r8, r8 */  —— id = sxth(arg)
/* @0xea074 beq 0xea208 <_Z6DoPushjPhPKhP6VMExec+0x380> */

/* 位 30 置位：基址字 w = *(uint32*)base；w 的符号位决定是否从值栈弹 base 值（负 → INT_MIN 哨兵）；位 29 决定 id 是否内嵌；位 30 置位时 id += 100000 */
/* @0xea078 ldr r3, [r9] */  —— w = *(uint32*)base
/* @0xea07c cmp r3, #0 */
/* @0xea080 ldrge r1, [r4], #4 */  —— w >= 0：弹一个 base 值
/* @0xea084 movlt r2, #-2147483648 */  —— w < 0：INT_MIN 哨兵
/* @0xea088 strlt r2, [sp, #0x24] */
/* @0xea08c strge r1, [sp, #0x24] */
/* @0xea090 tst r3, #536870912 */  —— 位 29：id 在 arg 内？
/* @0xea094 ldreq r8, [r4], #4 */  —— 位 29 为 0：id 从值栈弹
/* @0xea098 tst r3, #1073741824 */
/* @0xea09c addne r8, r8, #99328 */  —— +99328
/* @0xea0a0 bic r3, r3, #-268435456 */  —— mask = w & 0x0FFFFFFF
/* @0xea0a4 addne r8, r8, #672 */  —— +672 → 合计 +100000
/* @0xea0a8 str r3, [sp, #0x1c] */

/* id == -9 / -10 在写模板之前分流（-9 → ea7c0，-10 → e9f14） */
/* @0xea0ac cmn r8, #9 */  —— id == -9 ?
/* @0xea0b0 beq 0xea7c0 <_Z6DoPushjPhPKhP6VMExec+0x938> */
/* @0xea0b4 cmn r8, #10 */  —— id == -10 ?
/* @0xea0b8 beq 0xe9f14 <_Z6DoPushjPhPKhP6VMExec+0x8c> */
/* @0xea0bc ldr r1, [pc, #0xdd0] */

/* 写 RValue 占位模板：dest = sp-16，+0/+4/+8 清零，+12 = 0x00FFFFFF（未解析占位符，与 DoPop/DoPushGlobal 同一常量） */
/* @0xea0c0 mov r3, #0 */
/* @0xea0c4 mvn r0, #-16777216 */  —— 0x00FFFFFF = 未解析占位 tag
/* @0xea0c8 str r3, [r4, #-0x10] */
/* @0xea0cc str r3, [r4, #-0xc] */
/* @0xea0d0 add r2, r8, #14 */
/* @0xea0d4 str r3, [r4, #-0x8] */
/* @0xea0d8 sub r10, r4, #16 */  —— r10 = dest = sp-16
/* @0xea0dc str r0, [r4, #-0x4] */
/* @0xea0e0 ldr r1, [r5, r1] */
/* @0xea0e4 str r1, [sp, #0x20] */
/* @0xea0e8 strb r3, [r1] */

/* 负 id 二级分派表（14 项，表基 ea0f8，k = id+14）： */
/* -14→ea620  -13→ea510  -12→ea3bc  -11→ea39c */
/* -10→ea628  -9 →ea628  -8 →ea340  -7 →ea2f0 */
/* -6 →ea21c  -5 →ea22c  -4 →ea598  -3 →ea628 */
/* -2 →ea618  -1 →ea2cc */
/* （-9/-10 的这两个表项已被 ea0ac/ea0b4 提前截走，属死项） */
/* @0xea0ec cmp r2, #13 */  —— id+14 <= 13
/* @0xea0f0 addls pc, pc, r2, lsl #2 */  —— 负 id 跳转表
/* @0xea0f4 b 0xea628 <_Z6DoPushjPhPKhP6VMExec+0x7a0> */
/* @0xea0f8 b 0xea620 <_Z6DoPushjPhPKhP6VMExec+0x798> */
/* @0xea0fc b 0xea510 <_Z6DoPushjPhPKhP6VMExec+0x688> */
/* @0xea100 b 0xea3bc <_Z6DoPushjPhPKhP6VMExec+0x534> */
/* @0xea104 b 0xea39c <_Z6DoPushjPhPKhP6VMExec+0x514> */
/* @0xea108 b 0xea628 <_Z6DoPushjPhPKhP6VMExec+0x7a0> */
/* @0xea10c b 0xea628 <_Z6DoPushjPhPKhP6VMExec+0x7a0> */
/* @0xea110 b 0xea340 <_Z6DoPushjPhPKhP6VMExec+0x4b8> */
/* @0xea114 b 0xea2f0 <_Z6DoPushjPhPKhP6VMExec+0x468> */
/* @0xea118 b 0xea21c <_Z6DoPushjPhPKhP6VMExec+0x394> */
/* @0xea11c b 0xea22c <_Z6DoPushjPhPKhP6VMExec+0x3a4> */
/* @0xea120 b 0xea598 <_Z6DoPushjPhPKhP6VMExec+0x710> */
/* @0xea124 b 0xea628 <_Z6DoPushjPhPKhP6VMExec+0x7a0> */
/* @0xea128 b 0xea618 <_Z6DoPushjPhPKhP6VMExec+0x790> */
/* @0xea12c b 0xea2cc <_Z6DoPushjPhPKhP6VMExec+0x444> */

/* kind 6：字符串表 A —— 先 *(GOT) → 表结构，表结构[0] 为偏移数组；ptr = *(GOT2)->[0] + offset；再 new(12) 造 RefThing{str=YYStrDup, count=1, len=strlen}，压其指针 */
/* @0xea130 ldr r3, [pc, #0xd64] */
/* @0xea134 sub r8, r4, #4 */
/* @0xea138 ldr r2, [r9] */
/* @0xea13c ldr r3, [r5, r3] */
/* @0xea140 ldr r3, [r3] */
/* @0xea144 ldr r3, [r3, r2, lsl #2] */
/* @0xea148 cmp r3, #0 */
/* @0xea14c beq 0xea200 <_Z6DoPushjPhPKhP6VMExec+0x378> */
/* @0xea150 ldr r2, [pc, #0xd48] */
/* @0xea154 ldr r2, [r5, r2] */
/* @0xea158 ldr r7, [r2] */
/* @0xea15c add r3, r7, r3 */
/* @0xea160 adds r7, r3, #4 */
/* @0xea164 beq 0xea1e4 <_Z6DoPushjPhPKhP6VMExec+0x35c> */
/* @0xea168 mov r0, #12 */  —— 12 字节 RefThing
/* @0xea16c bl 0x27c524 <_Znwj> */
/* @0xea170 mov r5, r0 */
/* @0xea174 mov r0, r7 */
/* @0xea178 bl 0xb6538 <strlen@plt> */  —— len = strlen(str)
/* @0xea17c str r0, [r5, #0x8] */
/* @0xea180 mov r0, r7 */
/* @0xea184 bl 0xdb8c8 <_Z8YYStrDupPKc> */  —— str = YYStrDup(src)
/* @0xea188 mov r3, #1 */  —— count = 1
/* @0xea18c stm r5, {r0, r3} */
/* @0xea190 str r5, [r4, #-0x4] */  —— 压 RefThing*（4 字节）
/* @0xea194 mov r4, r8 */
/* @0xea198 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */

/* kind 7：字符串表 B —— 表项是绝对 char*（ldr r5,[r3,r2,lsl #2]）；空指针走 ea7b4（压 0） */
/* @0xea19c ldr r3, [pc, #0xd00] */
/* @0xea1a0 sub r8, r4, #4 */
/* @0xea1a4 ldr r2, [r9] */
/* @0xea1a8 ldr r3, [r5, r3] */
/* @0xea1ac ldr r3, [r3] */
/* @0xea1b0 ldr r5, [r3, r2, lsl #2] */  —— 表项直接是 char*
/* @0xea1b4 cmp r5, #0 */
/* @0xea1b8 beq 0xea7b4 <_Z6DoPushjPhPKhP6VMExec+0x92c> */
/* @0xea1bc mov r0, #12 */
/* @0xea1c0 bl 0x27c524 <_Znwj> */
/* @0xea1c4 mov r7, r0 */
/* @0xea1c8 mov r0, r5 */
/* @0xea1cc bl 0xb6538 <strlen@plt> */
/* @0xea1d0 str r0, [r7, #0x8] */
/* @0xea1d4 mov r0, r5 */
/* @0xea1d8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xea1dc mov r3, #1 */
/* @0xea1e0 stm r7, {r0, r3} */
/* @0xea1e4 str r7, [r4, #-0x4] */
/* @0xea1e8 mov r4, r8 */
/* @0xea1ec b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */

/* kind 0/1/3：把 *base 的 8 字节原样压栈（ldrd/strd），返回 sp-8 */
/* @0xea1f0 ldrd r2, r3, [r9] */  —— 8 字节载荷
/* @0xea1f4 sub r4, r4, #8 */
/* @0xea1f8 strd r2, r3, [r4] */
/* @0xea1fc b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xea200 mov r7, #4 */
/* @0xea204 b 0xea168 <_Z6DoPushjPhPKhP6VMExec+0x2e0> */
/* @0xea208 mov r3, #-2147483648 */
/* @0xea20c mvn r1, #0 */
/* @0xea210 str r3, [sp, #0x24] */
/* @0xea214 str r1, [sp, #0x1c] */
/* @0xea218 b 0xea0ac <_Z6DoPushjPhPKhP6VMExec+0x224> */

/* id=-6：先 Variable_Global_Declared(id)；未声明则转到 -1 的处理块 ea2cc */
/* @0xea21c ldr r0, [sp, #0x1c] */  —— Variable_Global_Declared(id)
/* @0xea220 bl 0x1f3484 <_Z24Variable_Global_Declaredi> */
/* @0xea224 cmp r0, #0 */
/* @0xea228 beq 0xea2cc <_Z6DoPushjPhPKhP6VMExec+0x444> */

/* id=-5：Variable_Global_GetVar([sp+0x1c], [sp+0x24], dest) */
/* @0xea22c ldr r0, [sp, #0x1c] */
/* @0xea230 mov r2, r10 */
/* @0xea234 ldr r1, [sp, #0x24] */
/* @0xea238 bl 0x1f3984 <_Z22Variable_Global_GetVariiP6RValue> */  —— Variable_Global_GetVar(idx, base, dest)
/* @0xea23c ldr r3, [r4, #-0x4] */
/* @0xea240 mov r4, r10 */
/* @0xea244 mov r11, r0 */

/* 统一收尾判据：dest 的 tag 字仍为 0x00FFFFFF ⇒ 未解析 ⇒ 走 ea5ac 拼报错信息；否则 r11（Variable_* 返回值）非 0 才算成功 */
/* @0xea248 mvn r2, #-16777216 */  —— tag 仍是占位符？
/* @0xea24c cmp r3, r2 */
/* @0xea250 beq 0xea5ac <_Z6DoPushjPhPKhP6VMExec+0x724> */  —— 是 → 未解析报错
/* @0xea254 cmp r11, #0 */
/* @0xea258 bne 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xea25c mov r1, r8 */
/* @0xea260 ldr r2, [sp, #0x1c] */
/* @0xea264 ldr r0, [r7, #0x34] */
/* @0xea268 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xea26c ldr r3, [pc, #0xc34] */
/* @0xea270 ldr r2, [r5, r3] */
/* @0xea274 ldrb r2, [r2] */
/* @0xea278 cmp r2, #0 */
/* @0xea27c mov r1, r0 */
/* @0xea280 bne 0xea8cc <_Z6DoPushjPhPKhP6VMExec+0xa44> */
/* @0xea284 ldr r2, [sp, #0x20] */
/* @0xea288 ldrb r3, [r2] */
/* @0xea28c cmp r3, #0 */
/* @0xea290 bne 0xea930 <_Z6DoPushjPhPKhP6VMExec+0xaa8> */
/* @0xea294 cmn r8, #1 */
/* @0xea298 mov r0, r7 */
/* @0xea29c ldreq r3, [r7, #0x14] */
/* @0xea2a0 movne r2, r8 */
/* @0xea2a4 ldreq r2, [r3, #0x78] */
/* @0xea2a8 ldr r3, [sp, #0x1c] */
/* @0xea2ac str r3, [sp] */
/* @0xea2b0 ldr r3, [sp, #0x24] */
/* @0xea2b4 str r3, [sp, #0x4] */
/* @0xea2b8 mov r3, r1 */
/* @0xea2bc ldr r1, [pc, #0xbe8] */
/* @0xea2c0 add r1, pc, r1 */
/* @0xea2c4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xea2c8 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */

/* id=-1：Variable_GetValue_Direct(exec->[0x14], [sp+0x1c], [sp+0x24], dest) */
/* @0xea2cc ldr r0, [r7, #0x14] */
/* @0xea2d0 mov r3, r10 */
/* @0xea2d4 ldr r1, [sp, #0x1c] */
/* @0xea2d8 ldr r2, [sp, #0x24] */
/* @0xea2dc bl 0x1f3b8c <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue> */  —— Variable_GetValue_Direct(exec+0x14, ...)
/* @0xea2e0 ldr r3, [r4, #-0x4] */
/* @0xea2e4 mov r4, r10 */
/* @0xea2e8 mov r11, r0 */
/* @0xea2ec b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */

/* id=-7：obj = exec->[0x10]；count = obj->[0x24]；src = obj->[0x4] + (idx-100000)*16（count 为 0 时退 InternalGetYYVar）；GET_RValue(dest, src, [sp+0x24]) */
/* @0xea2f0 ldr r0, [r7, #0x10] */
/* @0xea2f4 cmp r0, #0 */
/* @0xea2f8 beq 0xeb11c <_Z6DoPushjPhPKhP6VMExec+0x1294> */
/* @0xea2fc ldr r11, [r0, #0x24] */
/* @0xea300 cmp r11, #0 */
/* @0xea304 beq 0xea5a8 <_Z6DoPushjPhPKhP6VMExec+0x720> */
/* @0xea308 ldr r3, [r0, #0x4] */
/* @0xea30c ldr r2, [sp, #0x1c] */
/* @0xea310 cmp r3, #0 */
/* @0xea314 sub r1, r2, #99328 */
/* @0xea318 sub r1, r1, #672 */
/* @0xea31c beq 0xeb2dc <_Z6DoPushjPhPKhP6VMExec+0x1454> */
/* @0xea320 add r1, r3, r1, lsl #4 */
/* @0xea324 mov r0, r10 */
/* @0xea328 ldr r2, [sp, #0x24] */
/* @0xea32c bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */  —— GET_RValue(dest, src, i)
/* @0xea330 ldr r3, [r4, #-0x4] */
/* @0xea334 mov r4, r10 */
/* @0xea338 mov r11, r0 */
/* @0xea33c b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */

/* id=-8：仅当 [sp+0x1c] > 0x1869F(=99999) 且 exec->[0x10] 非空才走 GET_RValue；否则退到 ea954，改用 exec->[0x14] 走 -1 的直接取值（exec->[0x14] 也为 0 时 dest 保持占位 tag → 报错） */
/* @0xea340 ldr r2, [sp, #0x1c] */
/* @0xea344 movw r3, #0x869f */
/* @0xea348 movt r3, #0x1 */
/* @0xea34c cmp r2, r3 */
/* @0xea350 ble 0xea954 <_Z6DoPushjPhPKhP6VMExec+0xacc> */  —— idx <= 99999 → ea954
/* @0xea354 ldr r0, [r7, #0x10] */
/* @0xea358 cmp r0, #0 */
/* @0xea35c beq 0xea954 <_Z6DoPushjPhPKhP6VMExec+0xacc> */
/* @0xea360 ldr r3, [r0, #0x4] */
/* @0xea364 sub r1, r2, #99328 */
/* @0xea368 sub r1, r1, #672 */
/* @0xea36c cmp r3, #0 */
/* @0xea370 beq 0xeb2e8 <_Z6DoPushjPhPKhP6VMExec+0x1460> */
/* @0xea374 add r1, r3, r1, lsl #4 */
/* @0xea378 mov r0, r10 */
/* @0xea37c ldr r2, [sp, #0x24] */
/* @0xea380 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0xea384 cmp r0, #0 */
/* @0xea388 beq 0xea954 <_Z6DoPushjPhPKhP6VMExec+0xacc> */
/* @0xea38c ldr r3, [r4, #-0x4] */
/* @0xea390 mov r11, #1 */
/* @0xea394 mov r4, r10 */
/* @0xea398 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */

/* id=-11：Variable_Scope_GetVar([sp+0x1c], [sp+0x24], dest) */
/* @0xea39c ldr r0, [sp, #0x1c] */
/* @0xea3a0 mov r2, r10 */
/* @0xea3a4 ldr r1, [sp, #0x24] */
/* @0xea3a8 bl 0x1f3798 <_Z21Variable_Scope_GetVariiP6RValue> */  —— Variable_Scope_GetVar(idx, base, dest)
/* @0xea3ac ldr r3, [r4, #-0x4] */
/* @0xea3b0 mov r4, r10 */
/* @0xea3b4 mov r11, r0 */
/* @0xea3b8 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */

/* id=-12：从 exec->[0x10] 沿 +0xc 链逐层试 slot = [sp+0x1c]-100000；命中（临时 tag 不再是 0x00FFFFFF）即停；每层用 GET_RValue(tmp, &obj->[0x4][slot], [sp+0x24]) */
/* @0xea3bc ldr r9, [r7, #0x10] */
/* @0xea3c0 mvn r3, #-16777216 */
/* @0xea3c4 str r3, [sp, #0x88] */
/* @0xea3c8 cmp r9, #0 */
/* @0xea3cc moveq r11, r9 */
/* @0xea3d0 beq 0xea470 <_Z6DoPushjPhPKhP6VMExec+0x5e8> */
/* @0xea3d4 ldr r1, [sp, #0x1c] */
/* @0xea3d8 mov r11, #0 */
/* @0xea3dc mov r0, r11 */
/* @0xea3e0 mov r11, r6 */
/* @0xea3e4 sub r12, r1, #99328 */
/* @0xea3e8 mov r6, r5 */
/* @0xea3ec sub r12, r12, #672 */
/* @0xea3f0 mov r5, r4 */
/* @0xea3f4 add r2, sp, #124 */
/* @0xea3f8 str r2, [sp, #0x28] */
/* @0xea3fc mov r4, r12 */
/* @0xea400 lsl r2, r12, #4 */
/* @0xea404 str r2, [sp, #0x2c] */
/* @0xea408 ldr r2, [r9, #0x24] */  —— 槽数 obj->[0x24]
/* @0xea40c cmp r2, #0 */
/* @0xea410 beq 0xea444 <_Z6DoPushjPhPKhP6VMExec+0x5bc> */
/* @0xea414 cmp r2, r4 */
/* @0xea418 bls 0xea444 <_Z6DoPushjPhPKhP6VMExec+0x5bc> */
/* @0xea41c ldr r1, [r9, #0x4] */  —— 槽数组 obj->[0x4]
/* @0xea420 cmp r1, #0 */
/* @0xea424 beq 0xeb0a0 <_Z6DoPushjPhPKhP6VMExec+0x1218> */
/* @0xea428 ldr r2, [sp, #0x2c] */
/* @0xea42c add r1, r1, r2 */
/* @0xea430 ldr r0, [sp, #0x28] */
/* @0xea434 ldr r2, [sp, #0x24] */
/* @0xea438 str r3, [sp, #0x18] */
/* @0xea43c bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0xea440 ldr r3, [sp, #0x18] */
/* @0xea444 ldr r9, [r9, #0xc] */  —— 下一层 obj->[0xc]
/* @0xea448 cmp r9, #0 */
/* @0xea44c beq 0xea460 <_Z6DoPushjPhPKhP6VMExec+0x5d8> */
/* @0xea450 ldr r2, [sp, #0x88] */
/* @0xea454 bic r2, r2, #-16777216 */
/* @0xea458 cmp r2, r3 */
/* @0xea45c beq 0xea408 <_Z6DoPushjPhPKhP6VMExec+0x580> */
/* @0xea460 mov r4, r5 */
/* @0xea464 mov r5, r6 */
/* @0xea468 mov r6, r11 */
/* @0xea46c mov r11, r0 */

/* dest 槽里已有旧值时的清理：tag==1 → ead40（_RefThing::remove + 计数--，归零则 YYFree + delete）；tag==2 → ea488（计数--，按 tag∈{1,2,3,4} 判据决定 FREE_RValue__Pre），随后把 dest 置 {+8=0, +12=5} */
/* @0xea470 ldr r2, [r4, #-0x4] */
/* @0xea474 bic r3, r2, #-16777216 */
/* @0xea478 cmp r3, #1 */
/* @0xea47c beq 0xead40 <_Z6DoPushjPhPKhP6VMExec+0xeb8> */
/* @0xea480 cmp r3, #2 */
/* @0xea484 bne 0xea4a8 <_Z6DoPushjPhPKhP6VMExec+0x620> */
/* @0xea488 sub r3, r2, #1 */
/* @0xea48c bic r3, r3, #-16777216 */
/* @0xea490 bic r3, r3, #3 */
/* @0xea494 cmp r3, #0 */
/* @0xea498 beq 0xeb1c8 <_Z6DoPushjPhPKhP6VMExec+0x1340> */
/* @0xea49c mov r2, #0 */
/* @0xea4a0 mov r3, #5 */
/* @0xea4a4 stmdb r4, {r2, r3} */

/* RValue tag 跳转表 #1（15 项，表基 ea4d4）：0/10/13 → 8 字节载荷；1 → _RefThing<const char*>::assign；2 → (+0) 计数++ 且 +8 回填持有者；3/7/14 → 只拷首字；6 → DeterminePotentialRoot；4/5/8/9/11/12 → 不拷载荷 */
/* @0xea4a8 ldr r3, [sp, #0x88] */
/* @0xea4ac mov r1, #0 */
/* @0xea4b0 ldr r2, [sp, #0x84] */
/* @0xea4b4 str r1, [r4, #-0x10] */
/* @0xea4b8 str r3, [r4, #-0x4] */
/* @0xea4bc ldr r3, [sp, #0x88] */
/* @0xea4c0 str r2, [r4, #-0x8] */
/* @0xea4c4 bic r3, r3, #-16777216 */
/* @0xea4c8 cmp r3, #14 */  —— cmp tag, #14
/* @0xea4cc addls pc, pc, r3, lsl #2 */
/* @0xea4d0 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea4d4 b 0xea684 <_Z6DoPushjPhPKhP6VMExec+0x7fc> */
/* @0xea4d8 b 0xea718 <_Z6DoPushjPhPKhP6VMExec+0x890> */
/* @0xea4dc b 0xea6ec <_Z6DoPushjPhPKhP6VMExec+0x864> */
/* @0xea4e0 b 0xea678 <_Z6DoPushjPhPKhP6VMExec+0x7f0> */
/* @0xea4e4 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea4e8 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea4ec b 0xea6c8 <_Z6DoPushjPhPKhP6VMExec+0x840> */
/* @0xea4f0 b 0xea678 <_Z6DoPushjPhPKhP6VMExec+0x7f0> */
/* @0xea4f4 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea4f8 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea4fc b 0xea684 <_Z6DoPushjPhPKhP6VMExec+0x7fc> */
/* @0xea500 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea504 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea508 b 0xea684 <_Z6DoPushjPhPKhP6VMExec+0x7fc> */
/* @0xea50c b 0xea678 <_Z6DoPushjPhPKhP6VMExec+0x7f0> */

/* id=-13：全局数组 —— 表基 = *(GOT)，项 = table[mask28 & 0xFF]，按项 tag 走 #2 表拷贝；mask28 的次字节非 0 时走 eab50（沿 exec->[0x10] 的 +0xc 链下降 N 层再取槽） */
/* @0xea510 ldr r1, [sp, #0x1c] */
/* @0xea514 ubfx r3, r1, #0x8, #0x8 */  —— byte1 = 链深度
/* @0xea518 cmp r3, #0 */
/* @0xea51c uxtb r9, r1 */  —— r9 = mask & 0xFF（下标）
/* @0xea520 bne 0xeab50 <_Z6DoPushjPhPKhP6VMExec+0xcc8> */
/* @0xea524 ldr r2, [pc, #0x984] */
/* @0xea528 ldr r2, [r5, r2] */
/* @0xea52c ldr r11, [r2] */
/* @0xea530 str r3, [r4, #-0x10] */
/* @0xea534 add r2, r11, r9, lsl #4 */  —— 项 = table[idx]
/* @0xea538 ldr r3, [r2, #0xc] */
/* @0xea53c ldr r0, [r2, #0x8] */
/* @0xea540 str r3, [r4, #-0x4] */
/* @0xea544 ldr r1, [r2, #0xc] */
/* @0xea548 str r0, [r4, #-0x8] */
/* @0xea54c bic r1, r1, #-16777216 */
/* @0xea550 cmp r1, #14 */
/* @0xea554 addls pc, pc, r1, lsl #2 */  —— tag 跳转表 #2
/* @0xea558 b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xea55c b 0xea6ac <_Z6DoPushjPhPKhP6VMExec+0x824> */
/* @0xea560 b 0xea728 <_Z6DoPushjPhPKhP6VMExec+0x8a0> */
/* @0xea564 b 0xea744 <_Z6DoPushjPhPKhP6VMExec+0x8bc> */
/* @0xea568 b 0xea698 <_Z6DoPushjPhPKhP6VMExec+0x810> */
/* @0xea56c b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xea570 b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xea574 b 0xea784 <_Z6DoPushjPhPKhP6VMExec+0x8fc> */
/* @0xea578 b 0xea698 <_Z6DoPushjPhPKhP6VMExec+0x810> */
/* @0xea57c b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xea580 b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xea584 b 0xea6ac <_Z6DoPushjPhPKhP6VMExec+0x824> */
/* @0xea588 b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xea58c b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xea590 b 0xea6ac <_Z6DoPushjPhPKhP6VMExec+0x824> */
/* @0xea594 b 0xea698 <_Z6DoPushjPhPKhP6VMExec+0x810> */

/* id=-4：置 *(byte*)[sp+0x20] = 1 后并入共享报错路径（ea5a8 → ea5ac） */
/* @0xea598 ldr r1, [sp, #0x20] */  —— 置错误标志字节
/* @0xea59c mov r11, #0 */
/* @0xea5a0 mov r3, #1 */
/* @0xea5a4 strb r3, [r1] */
/* @0xea5a8 mov r4, r10 */
/* @0xea5ac mov r1, r8 */
/* @0xea5b0 ldr r2, [sp, #0x1c] */
/* @0xea5b4 ldr r0, [r7, #0x34] */
/* @0xea5b8 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xea5bc ldr r3, [r7, #0x14] */
/* @0xea5c0 cmn r8, #1 */
/* @0xea5c4 ldr r1, [sp, #0x1c] */
/* @0xea5c8 mov r9, r0 */
/* @0xea5cc ldreq r0, [r3, #0x78] */
/* @0xea5d0 movne r0, r8 */
/* @0xea5d4 bl 0x1f3f8c <_Z22Variable_GetObjectNameii> */
/* @0xea5d8 ldr r3, [pc, #0x8d4] */
/* @0xea5dc ldr r3, [r5, r3] */
/* @0xea5e0 ldrb r3, [r3] */
/* @0xea5e4 cmp r3, #0 */
/* @0xea5e8 bne 0xea254 <_Z6DoPushjPhPKhP6VMExec+0x3cc> */
/* @0xea5ec ldr r1, [sp, #0x24] */
/* @0xea5f0 mov r2, r0 */
/* @0xea5f4 ldr r3, [sp, #0x1c] */
/* @0xea5f8 mov r0, r7 */
/* @0xea5fc str r1, [sp, #0x4] */
/* @0xea600 ldr r1, [pc, #0x8b0] */
/* @0xea604 str r3, [sp] */
/* @0xea608 mov r3, r9 */
/* @0xea60c add r1, pc, r1 */
/* @0xea610 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xea614 b 0xea254 <_Z6DoPushjPhPKhP6VMExec+0x3cc> */

/* id=-2：与 -1 同构，基址取 exec->[0x18] */
/* @0xea618 ldr r0, [r7, #0x18] */
/* @0xea61c b 0xea2d0 <_Z6DoPushjPhPKhP6VMExec+0x448> */

/* id=-14：r11 = 1 后同样进 ea5a8（无取值动作） */
/* @0xea620 mov r11, #1 */
/* @0xea624 b 0xea5a8 <_Z6DoPushjPhPKhP6VMExec+0x720> */

/* 默认（-3 及其它）：Variable_GetValue(r8, [sp+0x1c], [sp+0x24], dest)；返回 0（未解析）时按 (调试字节, 错误标志字节 [sp+0x20]) 选报错出口，最终都经 ea248 的占位 tag 判据 */
/* @0xea628 mov r3, r10 */
/* @0xea62c mov r0, r8 */
/* @0xea630 ldr r1, [sp, #0x1c] */
/* @0xea634 ldr r2, [sp, #0x24] */
/* @0xea638 bl 0x1f3ce0 <_Z17Variable_GetValueiiiP6RValue> */  —— Variable_GetValue(id, idx, base, dest)
/* @0xea63c ldr r3, [pc, #0x864] */
/* @0xea640 ldr r3, [r5, r3] */
/* @0xea644 ldrb r3, [r3] */
/* @0xea648 cmp r3, #0 */
/* @0xea64c mov r11, r0 */
/* @0xea650 bne 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea654 cmp r0, #0 */
/* @0xea658 bne 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea65c ldr r2, [sp, #0x20] */
/* @0xea660 ldrb r3, [r2] */
/* @0xea664 cmp r3, #0 */
/* @0xea668 bne 0xeb218 <_Z6DoPushjPhPKhP6VMExec+0x1390> */
/* @0xea66c ldr r3, [r4, #-0x4] */
/* @0xea670 mov r4, r10 */
/* @0xea674 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xea678 ldr r3, [sp, #0x7c] */
/* @0xea67c str r3, [r4, #-0x10] */
/* @0xea680 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea684 ldr r2, [sp, #0x7c] */
/* @0xea688 ldr r3, [sp, #0x80] */
/* @0xea68c str r2, [r4, #-0x10] */
/* @0xea690 str r3, [r4, #-0xc] */
/* @0xea694 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea698 ldr r2, [r11, r9, lsl #4] */
/* @0xea69c mov r11, #1 */
/* @0xea6a0 str r2, [r4, #-0x10] */
/* @0xea6a4 mov r4, r10 */
/* @0xea6a8 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xea6ac ldr r1, [r11, r9, lsl #4] */
/* @0xea6b0 mov r11, #1 */
/* @0xea6b4 ldr r2, [r2, #0x4] */
/* @0xea6b8 str r1, [r4, #-0x10] */
/* @0xea6bc str r2, [r4, #-0xc] */
/* @0xea6c0 mov r4, r10 */
/* @0xea6c4 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xea6c8 ldr r3, [sp, #0x7c] */
/* @0xea6cc str r3, [r4, #-0x10] */
/* @0xea6d0 ldr r3, [sp, #0x7c] */
/* @0xea6d4 cmp r3, #0 */
/* @0xea6d8 beq 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea6dc bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xea6e0 ldr r1, [sp, #0x7c] */
/* @0xea6e4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xea6e8 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea6ec ldr r3, [sp, #0x7c] */
/* @0xea6f0 cmp r3, #0 */
/* @0xea6f4 str r3, [r4, #-0x10] */
/* @0xea6f8 beq 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea6fc ldr r1, [r3, #0x8] */
/* @0xea700 ldr r2, [r3] */
/* @0xea704 cmp r1, #0 */
/* @0xea708 streq r10, [r3, #0x8] */
/* @0xea70c add r2, r2, #1 */
/* @0xea710 str r2, [r3] */
/* @0xea714 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea718 ldr r0, [sp, #0x7c] */  —— _RefThing::assign
/* @0xea71c bl 0xdc418 <_ZN9_RefThingIPKcE6assignEPS2_> */
/* @0xea720 str r0, [r4, #-0x10] */
/* @0xea724 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xea728 ldr r0, [r11, r9, lsl #4] */
/* @0xea72c bl 0xdc418 <_ZN9_RefThingIPKcE6assignEPS2_> */  —— _RefThing::assign（表项版）
/* @0xea730 mov r11, #1 */
/* @0xea734 ldr r3, [r4, #-0x4] */
/* @0xea738 str r0, [r4, #-0x10] */
/* @0xea73c mov r4, r10 */
/* @0xea740 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xea744 ldr r2, [r11, r9, lsl #4] */
/* @0xea748 cmp r2, #0 */
/* @0xea74c str r2, [r4, #-0x10] */
/* @0xea750 beq 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xea754 ldr r0, [r2, #0x8] */
/* @0xea758 ldr r1, [r2] */
/* @0xea75c cmp r0, #0 */
/* @0xea760 streq r10, [r2, #0x8] */
/* @0xea764 add r1, r1, #1 */
/* @0xea768 str r1, [r2] */
/* @0xea76c moveq r4, r10 */
/* @0xea770 moveq r11, #1 */
/* @0xea774 beq 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xea778 mov r4, r10 */
/* @0xea77c mov r11, #1 */
/* @0xea780 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xea784 ldr r2, [r11, r9, lsl #4] */
/* @0xea788 str r2, [r4, #-0x10] */
/* @0xea78c ldr r2, [r11, r9, lsl #4] */
/* @0xea790 cmp r2, #0 */
/* @0xea794 beq 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xea798 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xea79c ldr r1, [r11, r9, lsl #4] */
/* @0xea7a0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xea7a4 mov r11, #1 */
/* @0xea7a8 ldr r3, [r4, #-0x4] */
/* @0xea7ac mov r4, r10 */
/* @0xea7b0 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xea7b4 str r5, [r4, #-0x4] */
/* @0xea7b8 mov r4, r8 */
/* @0xea7bc b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */

/* id=-9：双操作数；按第一操作数 tag 分流（2 → eb148 用 double 低位作下标；5 → eb0bc；6/3 → ead74；0x00FFFFFF → eb23c ReferenceError） */
/* @0xea7c0 add r3, sp, #60 */  —— 第一操作数拷到 sp+0x3c
/* @0xea7c4 str r3, [sp, #0x2c] */
/* @0xea7c8 ldr r0, [r4] */
/* @0xea7cc mvn r12, #-16777216 */
/* @0xea7d0 ldr r2, [r4, #0x8] */
/* @0xea7d4 ldr r3, [r4, #0xc] */
/* @0xea7d8 ldr r1, [r4, #0x4] */
/* @0xea7dc ldr r9, [sp, #0x2c] */
/* @0xea7e0 ldr lr, [pc, #0x6ac] */
/* @0xea7e4 stm r9!, {r0, r1, r2, r3} */
/* @0xea7e8 add r2, r4, #16 */
/* @0xea7ec str r12, [r4, #0xc] */
/* @0xea7f0 mov r3, #0 */
/* @0xea7f4 str r2, [sp, #0x28] */
/* @0xea7f8 ldr r2, [sp, #0x48] */
/* @0xea7fc str r3, [r4] */
/* @0xea800 str r3, [r4, #0x4] */
/* @0xea804 and r2, r2, r12 */
/* @0xea808 str r3, [r4, #0x8] */
/* @0xea80c cmp r2, #5 */
/* @0xea810 ldr lr, [r5, lr] */
/* @0xea814 str r3, [sp, #0x6c] */
/* @0xea818 str r3, [sp, #0x70] */
/* @0xea81c str lr, [sp, #0x20] */
/* @0xea820 strb r3, [lr] */
/* @0xea824 str r3, [sp, #0x74] */
/* @0xea828 str r12, [sp, #0x78] */
/* @0xea82c beq 0xeb02c <_Z6DoPushjPhPKhP6VMExec+0x11a4> */
/* @0xea830 ble 0xea970 <_Z6DoPushjPhPKhP6VMExec+0xae8> */
/* @0xea834 cmp r2, #6 */
/* @0xea838 beq 0xea978 <_Z6DoPushjPhPKhP6VMExec+0xaf0> */
/* @0xea83c cmp r2, r12 */
/* @0xea840 bne 0xeb00c <_Z6DoPushjPhPKhP6VMExec+0x1184> */
/* @0xea844 ldr r2, [pc, #0x690] */  —— 调试字节
/* @0xea848 ldr r2, [r5, r2] */
/* @0xea84c ldrb r9, [r2] */
/* @0xea850 cmp r9, #0 */
/* @0xea854 strne r3, [r4] */
/* @0xea858 strne r3, [r4, #0x4] */
/* @0xea85c movne r2, #5 */
/* @0xea860 beq 0xeb23c <_Z6DoPushjPhPKhP6VMExec+0x13b4> */
/* @0xea864 str r2, [r4, #0xc] */
/* @0xea868 ldr r3, [sp, #0x78] */
/* @0xea86c sub r3, r3, #1 */
/* @0xea870 bic r3, r3, #-16777216 */
/* @0xea874 bic r3, r3, #3 */
/* @0xea878 cmp r3, #0 */
/* @0xea87c beq 0xeb000 <_Z6DoPushjPhPKhP6VMExec+0x1178> */
/* @0xea880 ldr r1, [sp, #0x48] */
/* @0xea884 mov r3, #0 */
/* @0xea888 str r3, [sp, #0x74] */
/* @0xea88c mov r2, #5 */
/* @0xea890 sub r1, r1, #1 */
/* @0xea894 str r3, [sp, #0x6c] */
/* @0xea898 bic r3, r1, #-16777216 */
/* @0xea89c str r2, [sp, #0x78] */
/* @0xea8a0 bic r3, r3, #3 */
/* @0xea8a4 cmp r3, #0 */
/* @0xea8a8 beq 0xeaff4 <_Z6DoPushjPhPKhP6VMExec+0x116c> */
/* @0xea8ac mov r3, #5 */
/* @0xea8b0 mov r2, #0 */
/* @0xea8b4 str r3, [sp, #0x48] */
/* @0xea8b8 mov r11, #1 */
/* @0xea8bc ldr r3, [r4, #0xc] */
/* @0xea8c0 str r2, [sp, #0x44] */
/* @0xea8c4 str r2, [sp, #0x3c] */
/* @0xea8c8 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xea8cc ldr r12, [pc, #0x5e8] */  —— VMError 参数拼装
/* @0xea8d0 mov r0, r7 */
/* @0xea8d4 ldr r2, [pc, #0x5e4] */
/* @0xea8d8 ldr r3, [pc, #0x5e4] */
/* @0xea8dc ldr lr, [r5, r12] */
/* @0xea8e0 ldr r2, [r5, r2] */
/* @0xea8e4 ldr r12, [pc, #0x5dc] */
/* @0xea8e8 ldr lr, [lr] */
/* @0xea8ec ldr r3, [r5, r3] */
/* @0xea8f0 ldr r2, [r2] */
/* @0xea8f4 str lr, [sp] */
/* @0xea8f8 ldr r12, [r5, r12] */
/* @0xea8fc ldr r3, [r3] */
/* @0xea900 str r8, [sp, #0x8] */
/* @0xea904 ldr r12, [r12] */
/* @0xea908 str r1, [sp, #0xc] */
/* @0xea90c ldr r1, [sp, #0x1c] */
/* @0xea910 str r12, [sp, #0x4] */
/* @0xea914 str r1, [sp, #0x10] */
/* @0xea918 ldr r1, [sp, #0x24] */
/* @0xea91c str r1, [sp, #0x14] */
/* @0xea920 ldr r1, [pc, #0x5a4] */
/* @0xea924 add r1, pc, r1 */
/* @0xea928 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xea92c b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xea930 mov r0, r8 */  —— Object_Name(id)
/* @0xea934 bl 0x19ed54 <_Z11Object_Namei> */
/* @0xea938 ldr r1, [pc, #0x590] */
/* @0xea93c mov r2, r8 */
/* @0xea940 add r1, pc, r1 */
/* @0xea944 mov r3, r0 */
/* @0xea948 mov r0, r7 */
/* @0xea94c bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xea950 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xea954 ldr r0, [r7, #0x14] */
/* @0xea958 cmp r0, #0 */
/* @0xea95c bne 0xea2d0 <_Z6DoPushjPhPKhP6VMExec+0x448> */
/* @0xea960 ldr r3, [r4, #-0x4] */
/* @0xea964 mov r11, r0 */
/* @0xea968 mov r4, r10 */
/* @0xea96c b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xea970 cmp r2, #3 */
/* @0xea974 bne 0xeb00c <_Z6DoPushjPhPKhP6VMExec+0x1184> */

/* 对象成员两段式：先按名字算哈希（CHashMapCalculateHash）再沿桶链比对，命中后 GET_RValue；未命中则沿 obj->[0x18] 继续找下一层 */
/* @0xea978 ldr r3, [sp, #0x3c] */
/* @0xea97c str r3, [sp, #0x34] */
/* @0xea980 ldr r3, [sp, #0x34] */
/* @0xea984 ldr r1, [sp, #0x1c] */
/* @0xea988 cmp r3, #0 */
/* @0xea98c sub r3, r1, #99328 */
/* @0xea990 sub r3, r3, #672 */
/* @0xea994 str r3, [sp, #0x30] */
/* @0xea998 beq 0xeb3c0 <_Z6DoPushjPhPKhP6VMExec+0x1538> */
/* @0xea99c ldr r3, [sp, #0x34] */
/* @0xea9a0 ldr r9, [r3, #0x60] */
/* @0xea9a4 cmp r9, #0 */
/* @0xea9a8 beq 0xeaa48 <_Z6DoPushjPhPKhP6VMExec+0xbc0> */
/* @0xea9ac ldr r0, [sp, #0x30] */
/* @0xea9b0 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */  —— CHashMapCalculateHash(name)
/* @0xea9b4 ldr r1, [r9, #0x8] */
/* @0xea9b8 ldr r11, [r9, #0x10] */
/* @0xea9bc bic r10, r0, #-2147483648 */
/* @0xea9c0 and r3, r10, r1 */
/* @0xea9c4 lsl r12, r3, #1 */
/* @0xea9c8 add r2, r12, r3 */
/* @0xea9cc add r2, r11, r2, lsl #2 */
/* @0xea9d0 ldr r2, [r2, #0x8] */
/* @0xea9d4 cmp r2, #0 */
/* @0xea9d8 beq 0xeaa48 <_Z6DoPushjPhPKhP6VMExec+0xbc0> */
/* @0xea9dc cmp r10, r2 */
/* @0xea9e0 beq 0xead1c <_Z6DoPushjPhPKhP6VMExec+0xe94> */
/* @0xea9e4 ldr lr, [r9] */
/* @0xea9e8 and r2, r1, r2 */
/* @0xea9ec add r0, lr, r3 */
/* @0xea9f0 rsb r2, r2, r0 */
/* @0xea9f4 tst r2, r1 */
/* @0xea9f8 movpl r0, #0 */
/* @0xea9fc bpl 0xeaa24 <_Z6DoPushjPhPKhP6VMExec+0xb9c> */
/* @0xeaa00 b 0xeaa48 <_Z6DoPushjPhPKhP6VMExec+0xbc0> */
/* @0xeaa04 cmp r10, r2 */
/* @0xeaa08 beq 0xead14 <_Z6DoPushjPhPKhP6VMExec+0xe8c> */
/* @0xeaa0c and r2, r1, r2 */
/* @0xeaa10 add r12, lr, r3 */
/* @0xeaa14 rsb r2, r2, r12 */
/* @0xeaa18 and r2, r2, r1 */
/* @0xeaa1c cmp r2, r0 */
/* @0xeaa20 blt 0xeaa48 <_Z6DoPushjPhPKhP6VMExec+0xbc0> */
/* @0xeaa24 add r3, r3, #1 */
/* @0xeaa28 add r0, r0, #1 */
/* @0xeaa2c and r3, r1, r3 */
/* @0xeaa30 lsl r12, r3, #1 */
/* @0xeaa34 add r2, r12, r3 */
/* @0xeaa38 add r2, r11, r2, lsl #2 */
/* @0xeaa3c ldr r2, [r2, #0x8] */
/* @0xeaa40 cmp r2, #0 */
/* @0xeaa44 bne 0xeaa04 <_Z6DoPushjPhPKhP6VMExec+0xb7c> */
/* @0xeaa48 ldr r2, [r4, #0xc] */
/* @0xeaa4c ldr r9, [sp, #0x34] */
/* @0xeaa50 mvn r1, #-16777216 */
/* @0xeaa54 cmp r2, r1 */
/* @0xeaa58 bne 0xeacd8 <_Z6DoPushjPhPKhP6VMExec+0xe50> */
/* @0xeaa5c cmp r9, #0 */
/* @0xeaa60 beq 0xead08 <_Z6DoPushjPhPKhP6VMExec+0xe80> */
/* @0xeaa64 ldr r9, [r9, #0x18] */
/* @0xeaa68 cmp r9, #0 */
/* @0xeaa6c beq 0xeaa50 <_Z6DoPushjPhPKhP6VMExec+0xbc8> */
/* @0xeaa70 ldr r11, [r9, #0x60] */
/* @0xeaa74 cmp r11, #0 */
/* @0xeaa78 beq 0xeaa50 <_Z6DoPushjPhPKhP6VMExec+0xbc8> */
/* @0xeaa7c ldr r0, [sp, #0x30] */
/* @0xeaa80 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0xeaa84 ldr r1, [r11, #0x8] */
/* @0xeaa88 ldr r10, [r11, #0x10] */
/* @0xeaa8c bic r0, r0, #-2147483648 */
/* @0xeaa90 and r3, r0, r1 */
/* @0xeaa94 lsl lr, r3, #1 */
/* @0xeaa98 add r2, lr, r3 */
/* @0xeaa9c add r2, r10, r2, lsl #2 */
/* @0xeaaa0 ldr r2, [r2, #0x8] */
/* @0xeaaa4 cmp r2, #0 */
/* @0xeaaa8 beq 0xeab18 <_Z6DoPushjPhPKhP6VMExec+0xc90> */
/* @0xeaaac cmp r0, r2 */
/* @0xeaab0 beq 0xeab2c <_Z6DoPushjPhPKhP6VMExec+0xca4> */
/* @0xeaab4 ldr r11, [r11] */
/* @0xeaab8 and r2, r1, r2 */
/* @0xeaabc add r12, r3, r11 */
/* @0xeaac0 rsb r2, r2, r12 */
/* @0xeaac4 tst r2, r1 */
/* @0xeaac8 movpl r12, #0 */
/* @0xeaacc bpl 0xeaaf4 <_Z6DoPushjPhPKhP6VMExec+0xc6c> */
/* @0xeaad0 b 0xeab18 <_Z6DoPushjPhPKhP6VMExec+0xc90> */
/* @0xeaad4 cmp r0, r2 */
/* @0xeaad8 beq 0xeab24 <_Z6DoPushjPhPKhP6VMExec+0xc9c> */
/* @0xeaadc and r2, r1, r2 */
/* @0xeaae0 add lr, r3, r11 */
/* @0xeaae4 rsb r2, r2, lr */
/* @0xeaae8 and r2, r2, r1 */
/* @0xeaaec cmp r2, r12 */
/* @0xeaaf0 blt 0xeab18 <_Z6DoPushjPhPKhP6VMExec+0xc90> */
/* @0xeaaf4 add r3, r3, #1 */
/* @0xeaaf8 add r12, r12, #1 */
/* @0xeaafc and r3, r1, r3 */
/* @0xeab00 lsl lr, r3, #1 */
/* @0xeab04 add r2, lr, r3 */
/* @0xeab08 add r2, r10, r2, lsl #2 */
/* @0xeab0c ldr r2, [r2, #0x8] */
/* @0xeab10 cmp r2, #0 */
/* @0xeab14 bne 0xeaad4 <_Z6DoPushjPhPKhP6VMExec+0xc4c> */
/* @0xeab18 ldr r3, [sp, #0x28] */
/* @0xeab1c ldr r2, [r3, #-0x4] */
/* @0xeab20 b 0xeaa50 <_Z6DoPushjPhPKhP6VMExec+0xbc8> */
/* @0xeab24 cmn r3, #1 */
/* @0xeab28 beq 0xeab18 <_Z6DoPushjPhPKhP6VMExec+0xc90> */
/* @0xeab2c add r3, lr, r3 */
/* @0xeab30 add r10, r10, r3, lsl #2 */
/* @0xeab34 cmn r10, #4 */
/* @0xeab38 beq 0xeab18 <_Z6DoPushjPhPKhP6VMExec+0xc90> */
/* @0xeab3c ldr r1, [r10, #0x4] */
/* @0xeab40 mov r0, r4 */
/* @0xeab44 ldr r2, [sp, #0x24] */
/* @0xeab48 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0xeab4c b 0xeab18 <_Z6DoPushjPhPKhP6VMExec+0xc90> */

/* mask28 次字节 N > 0：沿 exec->[0x10] 的 +0xc 链下降 N 层，再经 +0x4 → +0x10 取槽数组，项 = vars[r9] */
/* @0xeab50 ldr r0, [r7, #0x10] */
/* @0xeab54 cmp r0, #0 */
/* @0xeab58 beq 0xeab80 <_Z6DoPushjPhPKhP6VMExec+0xcf8> */
/* @0xeab5c subs r3, r3, #1 */
/* @0xeab60 ldr r0, [r0, #0xc] */
/* @0xeab64 moveq r2, #0 */
/* @0xeab68 movne r2, #1 */
/* @0xeab6c cmp r0, #0 */
/* @0xeab70 moveq r2, #0 */
/* @0xeab74 andne r2, r2, #1 */
/* @0xeab78 cmp r2, #0 */
/* @0xeab7c bne 0xeab5c <_Z6DoPushjPhPKhP6VMExec+0xcd4> */
/* @0xeab80 ldr r1, [r0, #0x4] */
/* @0xeab84 cmp r1, #0 */
/* @0xeab88 beq 0xeb2a8 <_Z6DoPushjPhPKhP6VMExec+0x1420> */
/* @0xeab8c ldr r0, [r1] */
/* @0xeab90 cmp r0, #0 */
/* @0xeab94 beq 0xea960 <_Z6DoPushjPhPKhP6VMExec+0xad8> */
/* @0xeab98 ldr r3, [r0, #0x4] */
/* @0xeab9c cmp r3, #0 */
/* @0xeaba0 beq 0xeb364 <_Z6DoPushjPhPKhP6VMExec+0x14dc> */
/* @0xeaba4 add r0, r3, #16 */
/* @0xeaba8 ldr r0, [r0] */
/* @0xeabac ldr r3, [r0, #0x4] */
/* @0xeabb0 cmp r3, #0 */
/* @0xeabb4 beq 0xeb354 <_Z6DoPushjPhPKhP6VMExec+0x14cc> */
/* @0xeabb8 add r9, r3, r9, lsl #4 */
/* @0xeabbc ldr r2, [r4, #-0x4] */
/* @0xeabc0 bic r3, r2, #-16777216 */
/* @0xeabc4 cmp r3, #1 */
/* @0xeabc8 beq 0xeb19c <_Z6DoPushjPhPKhP6VMExec+0x1314> */
/* @0xeabcc cmp r3, #2 */
/* @0xeabd0 bne 0xeabf4 <_Z6DoPushjPhPKhP6VMExec+0xd6c> */
/* @0xeabd4 sub r3, r2, #1 */
/* @0xeabd8 bic r3, r3, #-16777216 */
/* @0xeabdc bic r3, r3, #3 */
/* @0xeabe0 cmp r3, #0 */
/* @0xeabe4 beq 0xeb2c4 <_Z6DoPushjPhPKhP6VMExec+0x143c> */
/* @0xeabe8 mov r2, #0 */
/* @0xeabec mov r3, #5 */
/* @0xeabf0 stmdb r4, {r2, r3} */
/* @0xeabf4 ldr r3, [r9, #0xc] */
/* @0xeabf8 mov r2, #0 */
/* @0xeabfc ldr r1, [r9, #0x8] */
/* @0xeac00 str r2, [r4, #-0x10] */
/* @0xeac04 str r3, [r4, #-0x4] */
/* @0xeac08 ldr r2, [r9, #0xc] */
/* @0xeac0c str r1, [r4, #-0x8] */
/* @0xeac10 bic r2, r2, #-16777216 */

/* RValue tag 跳转表 #3（表基 eac20，与 #1 同映射） */
/* @0xeac14 cmp r2, #14 */
/* @0xeac18 addls pc, pc, r2, lsl #2 */
/* @0xeac1c b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xeac20 b 0xeac70 <_Z6DoPushjPhPKhP6VMExec+0xde8> */
/* @0xeac24 b 0xeacd0 <_Z6DoPushjPhPKhP6VMExec+0xe48> */
/* @0xeac28 b 0xeacbc <_Z6DoPushjPhPKhP6VMExec+0xe34> */
/* @0xeac2c b 0xeac5c <_Z6DoPushjPhPKhP6VMExec+0xdd4> */
/* @0xeac30 b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xeac34 b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xeac38 b 0xeac8c <_Z6DoPushjPhPKhP6VMExec+0xe04> */
/* @0xeac3c b 0xeac5c <_Z6DoPushjPhPKhP6VMExec+0xdd4> */
/* @0xeac40 b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xeac44 b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xeac48 b 0xeac70 <_Z6DoPushjPhPKhP6VMExec+0xde8> */
/* @0xeac4c b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xeac50 b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xeac54 b 0xeac70 <_Z6DoPushjPhPKhP6VMExec+0xde8> */
/* @0xeac58 b 0xeac5c <_Z6DoPushjPhPKhP6VMExec+0xdd4> */
/* @0xeac5c ldr r2, [r9] */
/* @0xeac60 mov r11, #1 */
/* @0xeac64 str r2, [r4, #-0x10] */
/* @0xeac68 mov r4, r10 */
/* @0xeac6c b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xeac70 ldr r1, [r9] */
/* @0xeac74 mov r11, #1 */
/* @0xeac78 ldr r2, [r9, #0x4] */
/* @0xeac7c str r1, [r4, #-0x10] */
/* @0xeac80 str r2, [r4, #-0xc] */
/* @0xeac84 mov r4, r10 */
/* @0xeac88 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xeac8c ldr r2, [r9] */
/* @0xeac90 str r2, [r4, #-0x10] */
/* @0xeac94 ldr r2, [r9] */
/* @0xeac98 cmp r2, #0 */
/* @0xeac9c beq 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xeaca0 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xeaca4 ldr r1, [r9] */
/* @0xeaca8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xeacac mov r11, #1 */
/* @0xeacb0 ldr r3, [r4, #-0x4] */
/* @0xeacb4 mov r4, r10 */
/* @0xeacb8 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xeacbc ldr r2, [r9] */
/* @0xeacc0 cmp r2, #0 */
/* @0xeacc4 str r2, [r4, #-0x10] */
/* @0xeacc8 bne 0xea754 <_Z6DoPushjPhPKhP6VMExec+0x8cc> */
/* @0xeaccc b 0xea778 <_Z6DoPushjPhPKhP6VMExec+0x8f0> */
/* @0xeacd0 ldr r0, [r9] */
/* @0xeacd4 b 0xea72c <_Z6DoPushjPhPKhP6VMExec+0x8a4> */
/* @0xeacd8 and r12, r2, r1 */
/* @0xeacdc cmp r12, #6 */
/* @0xeace0 bne 0xeacfc <_Z6DoPushjPhPKhP6VMExec+0xe74> */
/* @0xeace4 ldr r3, [r4] */
/* @0xeace8 cmp r3, #0 */
/* @0xeacec beq 0xeacfc <_Z6DoPushjPhPKhP6VMExec+0xe74> */
/* @0xeacf0 ldr r1, [r3, #0x48] */
/* @0xeacf4 cmp r1, #2 */
/* @0xeacf8 beq 0xeb334 <_Z6DoPushjPhPKhP6VMExec+0x14ac> */
/* @0xeacfc mvn r3, #-16777216 */
/* @0xead00 cmp r2, r3 */
/* @0xead04 bne 0xea868 <_Z6DoPushjPhPKhP6VMExec+0x9e0> */
/* @0xead08 mov r3, #5 */
/* @0xead0c str r3, [r4, #0xc] */
/* @0xead10 b 0xea868 <_Z6DoPushjPhPKhP6VMExec+0x9e0> */
/* @0xead14 cmn r3, #1 */
/* @0xead18 beq 0xeaa48 <_Z6DoPushjPhPKhP6VMExec+0xbc0> */
/* @0xead1c add r3, r12, r3 */
/* @0xead20 add r11, r11, r3, lsl #2 */
/* @0xead24 cmn r11, #4 */
/* @0xead28 beq 0xeaa48 <_Z6DoPushjPhPKhP6VMExec+0xbc0> */
/* @0xead2c ldr r1, [r11, #0x4] */
/* @0xead30 mov r0, r4 */
/* @0xead34 ldr r2, [sp, #0x24] */
/* @0xead38 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0xead3c b 0xeaa48 <_Z6DoPushjPhPKhP6VMExec+0xbc0> */

/* tag1 旧值释放：LOCK_RVALUE_MUTEX → [ptr+4]-- → 归零则 YYFree(*ptr)、清 +0/+8、UNLOCK、operator delete */
/* @0xead40 ldr r9, [r4, #-0x10] */
/* @0xead44 cmp r9, #0 */
/* @0xead48 beq 0xead68 <_Z6DoPushjPhPKhP6VMExec+0xee0> */
/* @0xead4c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */  —— LOCK_RVALUE_MUTEX
/* @0xead50 ldr r3, [r9, #0x4] */  —— 计数--
/* @0xead54 sub r3, r3, #1 */
/* @0xead58 str r3, [r9, #0x4] */
/* @0xead5c cmp r3, #0 */
/* @0xead60 beq 0xeb1d4 <_Z6DoPushjPhPKhP6VMExec+0x134c> */  —— 归零 → YYFree + delete
/* @0xead64 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xead68 mov r3, #0 */
/* @0xead6c str r3, [r4, #-0x10] */
/* @0xead70 b 0xea4a8 <_Z6DoPushjPhPKhP6VMExec+0x620> */

/* -9/-10 的 tag∈{3,6} 分支：F_JS_ToObject 后 strcmp(名字, "length")，相等走 JSArrayGet，否则 F_JS_Object_Get */
/* @0xead74 ldr r9, [sp, #0x3c] */
/* @0xead78 ldr r0, [r9, #0x40] */
/* @0xead7c cmp r0, #0 */
/* @0xead80 beq 0xead98 <_Z6DoPushjPhPKhP6VMExec+0xf10> */
/* @0xead84 ldr r1, [pc, #0x148] */
/* @0xead88 add r1, pc, r1 */
/* @0xead8c bl 0xb6574 <strcmp@plt> */  —— strcmp(名字, "length")
/* @0xead90 cmp r0, #0 */
/* @0xead94 beq 0xeb130 <_Z6DoPushjPhPKhP6VMExec+0x12a8> */
/* @0xead98 mov r1, r11 */
/* @0xead9c add r11, sp, #108 */  —— F_JS_ToString
/* @0xeada0 mov r3, #5 */
/* @0xeada4 str r3, [sp, #0x78] */
/* @0xeada8 mov r0, r11 */
/* @0xeadac str r3, [sp, #0x18] */
/* @0xeadb0 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0xeadb4 ldr r2, [sp, #0x6c] */
/* @0xeadb8 ldr r3, [sp, #0x18] */
/* @0xeadbc mvn r12, #-16777216 */
/* @0xeadc0 mov r0, r9 */
/* @0xeadc4 add r1, sp, #124 */
/* @0xeadc8 str r3, [r4, #0x1c] */
/* @0xeadcc mov r3, #0 */
/* @0xeadd0 str r12, [sp, #0x88] */
/* @0xeadd4 str r3, [sp, #0x7c] */
/* @0xeadd8 str r3, [sp, #0x80] */
/* @0xeaddc str r3, [sp, #0x84] */
/* @0xeade0 ldr r2, [r2] */
/* @0xeade4 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */  —— F_JS_Object_Get
/* @0xeade8 ldr r2, [r4, #0x1c] */
/* @0xeadec bic r3, r2, #-16777216 */
/* @0xeadf0 cmp r3, #1 */
/* @0xeadf4 beq 0xeb1ac <_Z6DoPushjPhPKhP6VMExec+0x1324> */
/* @0xeadf8 cmp r3, #2 */
/* @0xeadfc bne 0xeae24 <_Z6DoPushjPhPKhP6VMExec+0xf9c> */
/* @0xeae00 sub r3, r2, #1 */
/* @0xeae04 bic r3, r3, #-16777216 */
/* @0xeae08 bic r3, r3, #3 */
/* @0xeae0c cmp r3, #0 */
/* @0xeae10 beq 0xeb2d0 <_Z6DoPushjPhPKhP6VMExec+0x1448> */
/* @0xeae14 mov r2, #0 */
/* @0xeae18 mov r3, #5 */
/* @0xeae1c str r2, [r4, #0x18] */
/* @0xeae20 str r3, [r4, #0x1c] */
/* @0xeae24 ldr r3, [sp, #0x88] */
/* @0xeae28 mov r1, #0 */
/* @0xeae2c ldr r2, [sp, #0x84] */
/* @0xeae30 str r1, [r4, #0x10] */
/* @0xeae34 str r3, [r4, #0x1c] */
/* @0xeae38 ldr r3, [sp, #0x88] */
/* @0xeae3c str r2, [r4, #0x18] */
/* @0xeae40 bic r3, r3, #-16777216 */

/* RValue tag 跳转表 #4（表基 eae50，与 #1 同映射） */
/* @0xeae44 cmp r3, #14 */
/* @0xeae48 addls pc, pc, r3, lsl #2 */
/* @0xeae4c b 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeae50 b 0xeaf50 <_Z6DoPushjPhPKhP6VMExec+0x10c8> */
/* @0xeae54 b 0xeafb4 <_Z6DoPushjPhPKhP6VMExec+0x112c> */
/* @0xeae58 b 0xeaf88 <_Z6DoPushjPhPKhP6VMExec+0x1100> */
/* @0xeae5c b 0xeaef4 <_Z6DoPushjPhPKhP6VMExec+0x106c> */
/* @0xeae60 b 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeae64 b 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeae68 b 0xeaf64 <_Z6DoPushjPhPKhP6VMExec+0x10dc> */
/* @0xeae6c b 0xeaef4 <_Z6DoPushjPhPKhP6VMExec+0x106c> */
/* @0xeae70 b 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeae74 b 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeae78 b 0xeaf50 <_Z6DoPushjPhPKhP6VMExec+0x10c8> */
/* @0xeae7c b 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeae80 b 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeae84 b 0xeaf50 <_Z6DoPushjPhPKhP6VMExec+0x10c8> */
/* @0xeae88 b 0xeaef4 <_Z6DoPushjPhPKhP6VMExec+0x106c> */
/* @0xeae8c ldrhteq r7, [r0], -r0 */
/* @0xeae90 .word 0xffffbd00 */
/* @0xeae94 .word 0xffffc110 */
/* @0xeae98 eoreq r10, r4, r4, lsl r6 */
/* @0xeae9c .word 0xffffc114 */
/* @0xeaea0 .word 0xffffbcf4 */
/* @0xeaea4 .word 0xffffc118 */
/* @0xeaea8 .word 0xffffbf24 */
/* @0xeaeac eoreq r10, r4, r8, lsr #14 */
/* @0xeaeb0 .word 0xffffc0c0 */
/* @0xeaeb4 .word 0xffffbf68 */
/* @0xeaeb8 eoreq r10, r4, r0, asr r3 */
/* @0xeaebc .word 0xffffbf30 */
/* @0xeaec0 .word 0xffffbf28 */
/* @0xeaec4 .word 0xffffbf2c */
/* @0xeaec8 .word 0xffffbf34 */
/* @0xeaecc eoreq r10, r4, r12, rrx */
/* @0xeaed0 eoreq r9, r4, r0, ror #31 */
/* @0xeaed4 mlaeq r4, r0, r11, r9 */
/* @0xeaed8 eoreq r9, r4, r4, lsl r9 */
/* @0xeaedc .word 0xffffc0fc */
/* @0xeaee0 eoreq r9, r4, r12, lsl #11 */
/* @0xeaee4 eoreq r9, r4, r0, lsl r5 */
/* @0xeaee8 .word 0x002496f8 */
/* @0xeaeec mlaeq r4, r0, r3, r9 */
/* @0xeaef0 eoreq r9, r4, r8, lsl #11 */
/* @0xeaef4 ldr r3, [sp, #0x7c] */
/* @0xeaef8 str r3, [r4, #0x10] */
/* @0xeaefc ldr r3, [sp, #0x78] */
/* @0xeaf00 sub r3, r3, #1 */
/* @0xeaf04 bic r3, r3, #-16777216 */
/* @0xeaf08 bic r3, r3, #3 */
/* @0xeaf0c cmp r3, #0 */
/* @0xeaf10 beq 0xeb1bc <_Z6DoPushjPhPKhP6VMExec+0x1334> */
/* @0xeaf14 mov r11, #1 */
/* @0xeaf18 ldr r2, [r4, #0x1c] */
/* @0xeaf1c mvn r3, #-16777216 */
/* @0xeaf20 cmp r2, r3 */
/* @0xeaf24 moveq r3, #5 */
/* @0xeaf28 streq r3, [r4, #0x1c] */
/* @0xeaf2c ldr r3, [sp, #0x68] */
/* @0xeaf30 sub r3, r3, #1 */
/* @0xeaf34 bic r3, r3, #-16777216 */
/* @0xeaf38 bic r3, r3, #3 */
/* @0xeaf3c cmp r3, #0 */
/* @0xeaf40 beq 0xeb124 <_Z6DoPushjPhPKhP6VMExec+0x129c> */
/* @0xeaf44 ldr r3, [r4, #0x1c] */
/* @0xeaf48 mov r4, r10 */
/* @0xeaf4c b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xeaf50 ldr r2, [sp, #0x7c] */
/* @0xeaf54 ldr r3, [sp, #0x80] */
/* @0xeaf58 str r2, [r4, #0x10] */
/* @0xeaf5c str r3, [r4, #0x14] */
/* @0xeaf60 b 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeaf64 ldr r3, [sp, #0x7c] */
/* @0xeaf68 str r3, [r4, #0x10] */
/* @0xeaf6c ldr r3, [sp, #0x7c] */
/* @0xeaf70 cmp r3, #0 */
/* @0xeaf74 beq 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeaf78 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0xeaf7c ldr r1, [sp, #0x7c] */
/* @0xeaf80 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0xeaf84 b 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeaf88 ldr r3, [sp, #0x7c] */
/* @0xeaf8c cmp r3, #0 */
/* @0xeaf90 str r3, [r4, #0x10] */
/* @0xeaf94 beq 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeaf98 ldr r1, [r3, #0x8] */
/* @0xeaf9c ldr r2, [r3] */
/* @0xeafa0 cmp r1, #0 */
/* @0xeafa4 streq r10, [r3, #0x8] */
/* @0xeafa8 add r2, r2, #1 */
/* @0xeafac str r2, [r3] */
/* @0xeafb0 b 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeafb4 ldr r0, [sp, #0x7c] */
/* @0xeafb8 bl 0xdc418 <_ZN9_RefThingIPKcE6assignEPS2_> */
/* @0xeafbc str r0, [r4, #0x10] */
/* @0xeafc0 b 0xeaefc <_Z6DoPushjPhPKhP6VMExec+0x1074> */
/* @0xeafc4 cmp lr, #3 */
/* @0xeafc8 beq 0xead74 <_Z6DoPushjPhPKhP6VMExec+0xeec> */
/* @0xeafcc ldr r1, [sp, #0x2c] */
/* @0xeafd0 add r0, sp, #92 */
/* @0xeafd4 bl 0x247388 <_Z13F_JS_ToObjectR6RValuePS_> */
/* @0xeafd8 cmp r0, #1 */
/* @0xeafdc ldrne r9, [sp, #0x5c] */
/* @0xeafe0 bne 0xead78 <_Z6DoPushjPhPKhP6VMExec+0xef0> */
/* @0xeafe4 ldr r0, [pc, #-0x114] */
/* @0xeafe8 add r0, pc, r0 */
/* @0xeafec bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xeaff0 b 0xea024 <_Z6DoPushjPhPKhP6VMExec+0x19c> */
/* @0xeaff4 ldr r0, [sp, #0x2c] */
/* @0xeaff8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xeaffc b 0xea8ac <_Z6DoPushjPhPKhP6VMExec+0xa24> */
/* @0xeb000 add r0, sp, #108 */
/* @0xeb004 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xeb008 b 0xea880 <_Z6DoPushjPhPKhP6VMExec+0x9f8> */
/* @0xeb00c ldr r1, [sp, #0x2c] */
/* @0xeb010 add r0, sp, #108 */
/* @0xeb014 bl 0x247388 <_Z13F_JS_ToObjectR6RValuePS_> */
/* @0xeb018 cmp r0, #1 */
/* @0xeb01c beq 0xeb370 <_Z6DoPushjPhPKhP6VMExec+0x14e8> */
/* @0xeb020 ldr r3, [sp, #0x6c] */
/* @0xeb024 str r3, [sp, #0x34] */
/* @0xeb028 b 0xea980 <_Z6DoPushjPhPKhP6VMExec+0xaf8> */
/* @0xeb02c ldr r3, [pc, #-0x158] */
/* @0xeb030 ldr r3, [r5, r3] */
/* @0xeb034 ldrb r9, [r3] */
/* @0xeb038 cmp r9, #0 */
/* @0xeb03c bne 0xea864 <_Z6DoPushjPhPKhP6VMExec+0x9dc> */
/* @0xeb040 ldr r2, [sp, #0x1c] */
/* @0xeb044 mov r1, r8 */
/* @0xeb048 ldr r0, [r7, #0x34] */
/* @0xeb04c bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xeb050 ldr r1, [sp, #0x1c] */
/* @0xeb054 mov r5, r0 */
/* @0xeb058 mov r0, r8 */
/* @0xeb05c bl 0x1f3f8c <_Z22Variable_GetObjectNameii> */
/* @0xeb060 ldr r2, [sp, #0x24] */
/* @0xeb064 ldr r1, [sp, #0x1c] */
/* @0xeb068 str r5, [sp] */
/* @0xeb06c add r5, sp, #140 */
/* @0xeb070 str r2, [sp, #0x8] */
/* @0xeb074 ldr r2, [pc, #-0x19c] */
/* @0xeb078 str r1, [sp, #0x4] */
/* @0xeb07c mov r1, #2048 */
/* @0xeb080 add r2, pc, r2 */
/* @0xeb084 mov r3, r0 */
/* @0xeb088 mov r0, r5 */
/* @0xeb08c bl 0xb65c8 <snprintf@plt> */
/* @0xeb090 mov r0, r5 */
/* @0xeb094 strb r9, [sp, #0x88b] */
/* @0xeb098 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xeb09c b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xeb0a0 mov r1, r4 */
/* @0xeb0a4 mov r0, r9 */
/* @0xeb0a8 str r3, [sp, #0x18] */
/* @0xeb0ac bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xeb0b0 ldr r3, [sp, #0x18] */
/* @0xeb0b4 mov r1, r0 */
/* @0xeb0b8 b 0xea430 <_Z6DoPushjPhPKhP6VMExec+0x5a8> */
/* @0xeb0bc ldr r2, [sp, #0x1c] */
/* @0xeb0c0 mov r1, r8 */
/* @0xeb0c4 ldr r0, [r7, #0x34] */
/* @0xeb0c8 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xeb0cc ldr r1, [sp, #0x1c] */
/* @0xeb0d0 mov r4, r0 */
/* @0xeb0d4 mov r0, r8 */
/* @0xeb0d8 bl 0x1f3f8c <_Z22Variable_GetObjectNameii> */
/* @0xeb0dc ldr r2, [sp, #0x24] */
/* @0xeb0e0 ldr r1, [sp, #0x1c] */
/* @0xeb0e4 str r4, [sp] */
/* @0xeb0e8 add r4, sp, #140 */
/* @0xeb0ec str r2, [sp, #0x8] */
/* @0xeb0f0 ldr r2, [pc, #-0x214] */
/* @0xeb0f4 str r1, [sp, #0x4] */
/* @0xeb0f8 mov r1, #2048 */
/* @0xeb0fc add r2, pc, r2 */
/* @0xeb100 mov r3, r0 */
/* @0xeb104 mov r0, r4 */
/* @0xeb108 bl 0xb65c8 <snprintf@plt> */
/* @0xeb10c mov r0, r4 */
/* @0xeb110 strb r9, [sp, #0x88b] */
/* @0xeb114 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xeb118 b 0xea024 <_Z6DoPushjPhPKhP6VMExec+0x19c> */
/* @0xeb11c mov r11, r0 */
/* @0xeb120 b 0xea5a8 <_Z6DoPushjPhPKhP6VMExec+0x720> */
/* @0xeb124 add r0, sp, #92 */
/* @0xeb128 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xeb12c b 0xeaf44 <_Z6DoPushjPhPKhP6VMExec+0x10bc> */
/* @0xeb130 mov r1, r11 */
/* @0xeb134 ldr r0, [sp, #0x2c] */
/* @0xeb138 mov r2, r10 */
/* @0xeb13c bl 0x249cdc <_Z10JSArrayGetP6RValueS0_S0_> */
/* @0xeb140 mov r11, r0 */
/* @0xeb144 b 0xeaf18 <_Z6DoPushjPhPKhP6VMExec+0x1090> */

/* tag2 分支：把 double 载荷 vcvt 成 int 当索引，GET_RValue(dest, sp+0x3c 的容器, idx) */
/* @0xeb148 ldr r2, [sp, #0x4c] */
/* @0xeb14c mov r0, r10 */
/* @0xeb150 ldr r3, [sp, #0x50] */
/* @0xeb154 ldr r1, [sp, #0x2c] */
/* @0xeb158 vmov d7, r2, r3 */
/* @0xeb15c vcvt.s32.f64 s15, d7 */
/* @0xeb160 vmov r2, s15 */
/* @0xeb164 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */  —— GET_RValue(dest, container, idx)
/* @0xeb168 ldr r3, [sp, #0x48] */
/* @0xeb16c sub r3, r3, #1 */
/* @0xeb170 bic r3, r3, #-16777216 */
/* @0xeb174 bic r3, r3, #3 */
/* @0xeb178 cmp r3, #0 */
/* @0xeb17c beq 0xeb29c <_Z6DoPushjPhPKhP6VMExec+0x1414> */
/* @0xeb180 mov r3, #0 */
/* @0xeb184 mov r2, #5 */
/* @0xeb188 str r3, [sp, #0x44] */
/* @0xeb18c mov r11, #1 */
/* @0xeb190 str r3, [sp, #0x3c] */
/* @0xeb194 str r2, [sp, #0x48] */
/* @0xeb198 b 0xeaf44 <_Z6DoPushjPhPKhP6VMExec+0x10bc> */
/* @0xeb19c ldr r0, [r4, #-0x10] */
/* @0xeb1a0 bl 0xdc42c <_ZN9_RefThingIPKcE6removeEPS2_> */
/* @0xeb1a4 str r0, [r4, #-0x10] */
/* @0xeb1a8 b 0xeabf4 <_Z6DoPushjPhPKhP6VMExec+0xd6c> */
/* @0xeb1ac ldr r0, [r4, #0x10] */
/* @0xeb1b0 bl 0xdc42c <_ZN9_RefThingIPKcE6removeEPS2_> */
/* @0xeb1b4 str r0, [r4, #0x10] */
/* @0xeb1b8 b 0xeae24 <_Z6DoPushjPhPKhP6VMExec+0xf9c> */
/* @0xeb1bc mov r0, r11 */
/* @0xeb1c0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xeb1c4 b 0xeaf14 <_Z6DoPushjPhPKhP6VMExec+0x108c> */
/* @0xeb1c8 mov r0, r10 */
/* @0xeb1cc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xeb1d0 b 0xea49c <_Z6DoPushjPhPKhP6VMExec+0x614> */
/* @0xeb1d4 ldr r0, [r9] */
/* @0xeb1d8 str r3, [sp, #0x18] */
/* @0xeb1dc bl 0xcef90 <_Z6YYFreePKv> */  —— YYFree(载荷)
/* @0xeb1e0 ldr r3, [sp, #0x18] */
/* @0xeb1e4 str r3, [r9] */
/* @0xeb1e8 str r3, [r9, #0x8] */
/* @0xeb1ec bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xeb1f0 ldr r3, [r9, #0x4] */
/* @0xeb1f4 sub r3, r3, #1 */
/* @0xeb1f8 str r3, [r9, #0x4] */
/* @0xeb1fc cmp r3, #0 */
/* @0xeb200 beq 0xeb2f4 <_Z6DoPushjPhPKhP6VMExec+0x146c> */
/* @0xeb204 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xeb208 mov r0, r9 */
/* @0xeb20c bl 0x27d1d0 <_ZdlPv> */
/* @0xeb210 b 0xead64 <_Z6DoPushjPhPKhP6VMExec+0xedc> */
/* @0xeb214 bl 0xb65d4 <__stack_chk_fail@plt> */  —— 栈哨兵失败
/* @0xeb218 mov r0, r8 */
/* @0xeb21c bl 0x19ed54 <_Z11Object_Namei> */
/* @0xeb220 ldr r1, [pc, #-0x340] */
/* @0xeb224 mov r2, r8 */
/* @0xeb228 add r1, pc, r1 */
/* @0xeb22c mov r3, r0 */
/* @0xeb230 mov r0, r7 */
/* @0xeb234 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xeb238 b 0xea66c <_Z6DoPushjPhPKhP6VMExec+0x7e4> */
/* @0xeb23c ldr r2, [sp, #0x1c] */
/* @0xeb240 mov r1, r8 */
/* @0xeb244 ldr r0, [r7, #0x34] */
/* @0xeb248 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0xeb24c ldr r1, [sp, #0x1c] */
/* @0xeb250 mov r5, r0 */
/* @0xeb254 mov r0, r8 */
/* @0xeb258 bl 0x1f3f8c <_Z22Variable_GetObjectNameii> */
/* @0xeb25c ldr r2, [sp, #0x24] */
/* @0xeb260 ldr r1, [sp, #0x1c] */
/* @0xeb264 str r5, [sp] */
/* @0xeb268 add r5, sp, #140 */
/* @0xeb26c str r2, [sp, #0x8] */
/* @0xeb270 ldr r2, [pc, #-0x38c] */
/* @0xeb274 str r1, [sp, #0x4] */
/* @0xeb278 mov r1, #2048 */
/* @0xeb27c add r2, pc, r2 */
/* @0xeb280 mov r3, r0 */
/* @0xeb284 mov r0, r5 */
/* @0xeb288 bl 0xb65c8 <snprintf@plt> */
/* @0xeb28c mov r0, r5 */
/* @0xeb290 strb r9, [sp, #0x88b] */
/* @0xeb294 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xeb298 b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xeb29c ldr r0, [sp, #0x2c] */
/* @0xeb2a0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xeb2a4 b 0xeb180 <_Z6DoPushjPhPKhP6VMExec+0x12f8> */
/* @0xeb2a8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xeb2ac subs r1, r0, #0 */
/* @0xeb2b0 bne 0xeab8c <_Z6DoPushjPhPKhP6VMExec+0xd04> */
/* @0xeb2b4 ldr r3, [r4, #-0x4] */
/* @0xeb2b8 mov r11, r1 */
/* @0xeb2bc mov r4, r10 */
/* @0xeb2c0 b 0xea248 <_Z6DoPushjPhPKhP6VMExec+0x3c0> */
/* @0xeb2c4 mov r0, r10 */
/* @0xeb2c8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xeb2cc b 0xeabe8 <_Z6DoPushjPhPKhP6VMExec+0xd60> */
/* @0xeb2d0 mov r0, r10 */
/* @0xeb2d4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xeb2d8 b 0xeae14 <_Z6DoPushjPhPKhP6VMExec+0xf8c> */
/* @0xeb2dc bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xeb2e0 mov r1, r0 */
/* @0xeb2e4 b 0xea324 <_Z6DoPushjPhPKhP6VMExec+0x49c> */
/* @0xeb2e8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xeb2ec mov r1, r0 */
/* @0xeb2f0 b 0xea378 <_Z6DoPushjPhPKhP6VMExec+0x4f0> */
/* @0xeb2f4 ldr r0, [r9] */
/* @0xeb2f8 str r3, [sp, #0x18] */
/* @0xeb2fc bl 0xcef90 <_Z6YYFreePKv> */
/* @0xeb300 ldr r3, [sp, #0x18] */
/* @0xeb304 str r3, [r9] */
/* @0xeb308 str r3, [r9, #0x8] */
/* @0xeb30c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xeb310 ldr r3, [r9, #0x4] */
/* @0xeb314 sub r3, r3, #1 */
/* @0xeb318 str r3, [r9, #0x4] */
/* @0xeb31c cmp r3, #0 */
/* @0xeb320 beq 0xeb380 <_Z6DoPushjPhPKhP6VMExec+0x14f8> */
/* @0xeb324 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xeb328 mov r0, r9 */
/* @0xeb32c bl 0x27d1d0 <_ZdlPv> */
/* @0xeb330 b 0xeb204 <_Z6DoPushjPhPKhP6VMExec+0x137c> */
/* @0xeb334 add r2, sp, #124 */
/* @0xeb338 ldr r0, [sp, #0x34] */
/* @0xeb33c mov r1, r4 */
/* @0xeb340 str r12, [sp, #0x88] */
/* @0xeb344 str r3, [sp, #0x7c] */
/* @0xeb348 bl 0x248fec <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_> */  —— Call_Accessor_Get
/* @0xeb34c ldr r2, [r4, #0xc] */
/* @0xeb350 b 0xeacfc <_Z6DoPushjPhPKhP6VMExec+0xe74> */
/* @0xeb354 mov r1, r9 */
/* @0xeb358 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xeb35c mov r9, r0 */
/* @0xeb360 b 0xeabbc <_Z6DoPushjPhPKhP6VMExec+0xd34> */
/* @0xeb364 mov r1, #1 */
/* @0xeb368 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0xeb36c b 0xeaba8 <_Z6DoPushjPhPKhP6VMExec+0xd20> */
/* @0xeb370 ldr r0, [pc, #-0x488] */
/* @0xeb374 add r0, pc, r0 */
/* @0xeb378 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xeb37c b 0xea028 <_Z6DoPushjPhPKhP6VMExec+0x1a0> */
/* @0xeb380 ldr r0, [r9] */
/* @0xeb384 str r3, [sp, #0x18] */
/* @0xeb388 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xeb38c ldr r3, [sp, #0x18] */
/* @0xeb390 str r3, [r9] */
/* @0xeb394 str r3, [r9, #0x8] */
/* @0xeb398 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xeb39c ldr r3, [r9, #0x4] */
/* @0xeb3a0 sub r3, r3, #1 */
/* @0xeb3a4 str r3, [r9, #0x4] */
/* @0xeb3a8 cmp r3, #0 */
/* @0xeb3ac beq 0xeb3cc <_Z6DoPushjPhPKhP6VMExec+0x1544> */
/* @0xeb3b0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xeb3b4 mov r0, r9 */
/* @0xeb3b8 bl 0x27d1d0 <_ZdlPv> */
/* @0xeb3bc b 0xeb324 <_Z6DoPushjPhPKhP6VMExec+0x149c> */
/* @0xeb3c0 ldr r2, [r4, #0xc] */
/* @0xeb3c4 bic r12, r2, #-16777216 */
/* @0xeb3c8 b 0xeacdc <_Z6DoPushjPhPKhP6VMExec+0xe54> */
/* @0xeb3cc ldr r0, [r9] */
/* @0xeb3d0 str r3, [sp, #0x18] */
/* @0xeb3d4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xeb3d8 ldr r3, [sp, #0x18] */
/* @0xeb3dc mov r0, r9 */
/* @0xeb3e0 str r3, [r9] */
/* @0xeb3e4 str r3, [r9, #0x8] */
/* @0xeb3e8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */  —— _RefThing::dec
/* @0xeb3ec mov r0, r9 */
/* @0xeb3f0 bl 0x27d1d0 <_ZdlPv> */
/* @0xeb3f4 b 0xeb3b0 <_Z6DoPushjPhPKhP6VMExec+0x1528> */
