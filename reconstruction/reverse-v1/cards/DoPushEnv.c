/* cally 逆向卡：DoPushEnv（原版 libyoyo.so，armv7）
 * @func 0xd4dfc 0xd547c  size 1664  416 条指令（含尾部 11 个 literal 字）
 * 级别: 骨架（416 条全部解码；五种记录形态与全部入口分派已定，with 循环的字节码协议未定）
 * 符号: _Z9DoPushEnvjPhPKhP6VMExec → uchar* DoPushEnv(uint32 arg, uchar* sp, const uchar* base, VMExec* exec)
 *
 * 已证（指令级）：
 *   arg 位域：bit23 (0x800000) = "值栈顶是 RValue"；其余位 = 以字为单位的码偏移，code = (exec[0x44]-4) + arg*4
 *                                                  ; d4e00 / d4f20 / d4f34 / d4f5c / d5010
 *   码流回填是统一动作：exec[0x44] = code；exec[0x48] = exec[0x5c][code>>2]（负 code 先 +3 再 asr 2 做零向取整）
 *                                                  ; d4f54..d4f64 / d5018..d502c / d52d8..d52ec
 *   主路径：w0 = *(uint32_t*)sp（消费 4 B），switch(w0+7) 覆盖 w0 = -7..-1（cmp r3,#6 + addls pc,r3,lsl #2）
 *                                                  ; d4e50 / d4e54 / d4e58 / d4e60
 *     w0 = -7 → VMError "Cannot use local in with statement"（串 0x332a84）→ 返回 sp+4      ; d4e68 → d4ed8..d4ee8
 *     w0 = -5 → VMError "Cannot use global in with statement"（串 0x332a60）→ 返回 sp+4     ; d4e70 → d4f08..d4f18
 *     w0 = -4 → 压 [0, env2, env1] 12 B（env1 写进被消费的那一个字），跳码；env1/env2 都不动     ; d4e74 → d4f1c..d4f68
 *     w0 = -3 → 遍历 Run_Room->[0x80] 的实例链，计数后压：0 → [0] 8 B；1 → [0, env1] 8 B；
 *               2 → [inst, 0, env1] 12 B；>2 → [-1, end, base, env2, env1] 20 B          ; d4e78 → d4f6c..d53d0
 *     w0 = -2 → 压 [0, env2, env1] 且 env1/env2 互换（exec[0x14]=旧 env2、exec[0x18]=旧 env1） ; d4e7c → d4eb8..d4ed4
 *     w0 = -1 与 w0 = -6 → 同一条：压 [0, env2, env1]，env2 = 旧 env1（env1 不动）            ; d4e80 / d4e6c → d4eec..d4f04
 *   bit23 路径：栈顶 RValue 的 tag 必须 == 6，否则 VMError "FOo"（串 0x332a5c，原文如此）；通过则
 *     env1 = RValue 载荷、env2 = 旧 env1，并在 sp+4 起写 [0, 旧 env2, 旧 env1]，返回 sp+4      ; d4e20..d4eb4
 *   w0 ∈ [0, 99999]（0x1869F）→ 对象 id：g_ObjectHash（0x542374）桶链 —— mask 在 [+4]、桶基址 [+0]、
 *   节点 {+4 next, +8 key, +0xc 值}；值是 CObjectGM*，其 [+0xd0] 为**实例节点链的头**，
 *   节点布局 {+0 next, +8 inst}（不是把实例本身串起来、next 也不在 inst+0x178）。
 *   ⚠ 修正（batchR，cards/Variable_GetValue.c 与 AddInstance 0x19e02c/0x19e0d8 互证）
 *     只挑 [inst+0x68]==0 且 [inst+0x69]==0 的实例                                ; d504c..d50c4
 *   w0 > 99999 → 实例 id：CInstance::ms_ID2Instance（0x536f28）同构桶链，命中且两个 flag 都为 0 才用  ; d51b4..d5214
 *   "已处理"集合两个探针：HandleInstance(inst)（d5110）与 InstanceHandled(inst)（d5194 / d5288）；
 *     计数在 r3、上一个实例在 r10，两者都在这一层维护                              ; d50e0..d51b0 / d5254..d52a0
 *   计数决定压什么：0 → [0] 8 B；1 → [0, env2, env1] 12 B；2 → [inst, 0, env2, env1] 16 B；
 *     >2 → Alloc(count*4) 填数组后压 [-1, end, base, env2, env1] 20 B              ; d4fcc..d53d0 / d52a4..d53f0
 *   两条 Alloc 都是 MemoryManager::Alloc(size, "VM_Exec.cpp", 8769 / 8904, true)      ; d5324..d5338 / d5398..d53b0
 *   >2 的第二形态用 IterateInstances(array, exec) 填数组，返回值当 end                 ; d53bc
 *   用过 HandleInstance/InstanceHandled 的路径收尾调 ClearHandledContainerv()          ; d52f0
 *   env 只有一对字：env1 = exec+0x14、env2 = exec+0x18；压栈时最常见的改写是 env2 := env1 ; d5060 / d4f00 / d5220
 *   通用入口（w0 ≥ 0 或 w0 ≤ -8）在分叉前先把 (env2 → [sp-4], env1 → [sp]) 铺好，压栈块再往 sp-8..sp-16 扩 ; d5040 / d5044
 *
 * 结论：
 *   1. 环境表不是数组：它就是 (exec+0x14, exec+0x18) 两个指针 + 值栈上的小记录。所以 local(self+4) / global(GOT 单例+4) /
 *      env(exec+0x14) 是三张不同的表：前两张有 +4 表基址与 16 B 槽；env 没有槽数组，只有"当前 + 历史"两个指针。
 *   2. 一个操作数同时编码三件事：bit23（栈顶是 RValue）、码流跳转偏移（×4）、以及值栈字 w0 的操作数类型
 *      （6 个负标记 / 对象 id / 实例 id）。这就是 with 语句的全部输入面。
 *   3. RValue tag 6 是 with 操作数专用类型：bit23 路径只接受 tag 6，其它一律 "FOo"；而 tag 6 在 SET_RValue 里是唯一
 *      会调 DeterminePotentialRoot 的类型（0xd0c50），说明它承载的是会被 GC 追踪的对象引用。
 *   4. 记录只有 4/8/12/16/20 B 五种，与 DoPopEnv 的四个收尾点严格对应：
 *      4 B = 单个实例或纯标记（只改 env1 后 sp+4）；8 B = [0] 或 [0, env1]；12 B = [0, env2, env1] 或 [inst, 0, env1]；
 *      16 B = [inst, 0, env2, env1]；20 B = [-1, end, base, env2, env1]（堆数组）。
 * open：with 循环的字节码协议（PushEnv ↔ PopEnv 的配对与迭代次数）；CObjectGM +0xd0 节点链与 CInstance +0x178 步进链的命名；
 *       数组 [0]=0 的填充用途（d5368 存的是上一轮的 r6，不是当前实例）；0xF0 记录的产生方；
 *       MemoryManager 行号 8769/8904 对应的源码语句。
 */

/* ── 段 1 · 序言 / PIC 基址 / arg bit23 分派（0xd4dfc..0xd4e1c） ── */
/* @0xd4dfc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd4e00 tst r0, #8388608 */
/* @0xd4e04 ldr r7, [pc, #0x644] */
/* @0xd4e08 sub sp, sp, #12 */
/* @0xd4e0c mov r8, r0 */
/* @0xd4e10 mov r4, r1 */
/* @0xd4e14 mov r5, r3 */
/* @0xd4e18 add r7, pc, r7 */
/* @0xd4e1c beq 0xd4e50 <_Z9DoPushEnvjPhPKhP6VMExec+0x54> */

/* ── 段 2 · bit23 路径：栈顶 RValue（tag 必须 6）（0xd4e20..0xd4e4c） ── */
/* @0xd4e20 ldr r3, [r1, #0xc] */
/* @0xd4e24 bic r3, r3, #-16777216 */
/* @0xd4e28 cmp r3, #6 */
/* @0xd4e2c beq 0xd4e84 <_Z9DoPushEnvjPhPKhP6VMExec+0x88> */
/* @0xd4e30 ldr r1, [pc, #0x61c] */
/* @0xd4e34 mov r0, r5 */
/* @0xd4e38 add r6, r4, #16 */
/* @0xd4e3c add r1, pc, r1 */
/* @0xd4e40 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd4e44 mov r0, r6 */
/* @0xd4e48 add sp, sp, #12 */
/* @0xd4e4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── 段 3 · 主分派：w0 = *(uint32*)sp，switch(w0+7)（0xd4e50..0xd4e80） ── */
/* @0xd4e50 mov r6, r1 */
/* @0xd4e54 ldr r2, [r6], #4 */
/* @0xd4e58 add r3, r2, #7 */
/* @0xd4e5c cmp r3, #6 */
/* @0xd4e60 addls pc, pc, r3, lsl #2 */
/* @0xd4e64 b 0xd5034 <_Z9DoPushEnvjPhPKhP6VMExec+0x238> */
/* @0xd4e68 b 0xd4ed8 <_Z9DoPushEnvjPhPKhP6VMExec+0xdc> */
/* @0xd4e6c b 0xd4eec <_Z9DoPushEnvjPhPKhP6VMExec+0xf0> */
/* @0xd4e70 b 0xd4f08 <_Z9DoPushEnvjPhPKhP6VMExec+0x10c> */
/* @0xd4e74 b 0xd4f1c <_Z9DoPushEnvjPhPKhP6VMExec+0x120> */
/* @0xd4e78 b 0xd4f6c <_Z9DoPushEnvjPhPKhP6VMExec+0x170> */
/* @0xd4e7c b 0xd4eb8 <_Z9DoPushEnvjPhPKhP6VMExec+0xbc> */
/* @0xd4e80 b 0xd4eec <_Z9DoPushEnvjPhPKhP6VMExec+0xf0> */

/* ── 段 4 · bit23 通过：env 换位 + 12 B 记录（0xd4e84..0xd4eb4） ── */
/* @0xd4e84 ldr r3, [r5, #0x14] */
/* @0xd4e88 mov r2, #0 */
/* @0xd4e8c add r6, r1, #4 */
/* @0xd4e90 str r3, [r1, #0xc] */
/* @0xd4e94 mov r0, r6 */
/* @0xd4e98 ldr r3, [r5, #0x18] */
/* @0xd4e9c stmib r1, {r2, r3} */
/* @0xd4ea0 ldr r3, [r5, #0x14] */
/* @0xd4ea4 str r3, [r5, #0x18] */
/* @0xd4ea8 ldr r3, [r1] */
/* @0xd4eac str r3, [r5, #0x14] */
/* @0xd4eb0 add sp, sp, #12 */
/* @0xd4eb4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── 段 5 · w0 = -2/-1/-6：两个 env 的保存/换位（0xd4eb8..0xd4f04） ── */
/* @0xd4eb8 ldr r3, [r5, #0x14] */
/* @0xd4ebc mov r1, #0 */
/* @0xd4ec0 ldr r2, [r5, #0x18] */
/* @0xd4ec4 sub r6, r4, #8 */
/* @0xd4ec8 stmda r4, {r1, r2, r3} */
/* @0xd4ecc str r2, [r5, #0x14] */
/* @0xd4ed0 str r3, [r5, #0x18] */
/* @0xd4ed4 b 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */
/* @0xd4ed8 ldr r1, [pc, #0x578] */
/* @0xd4edc mov r0, r5 */
/* @0xd4ee0 add r1, pc, r1 */
/* @0xd4ee4 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd4ee8 b 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */
/* @0xd4eec ldr r3, [r5, #0x14] */
/* @0xd4ef0 mov r1, #0 */
/* @0xd4ef4 ldr r2, [r5, #0x18] */
/* @0xd4ef8 sub r6, r4, #8 */
/* @0xd4efc stmda r4, {r1, r2, r3} */
/* @0xd4f00 str r3, [r5, #0x18] */
/* @0xd4f04 b 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */

/* ── 段 6 · w0 = -5 错误（0xd4f08..0xd4f18） ── */
/* @0xd4f08 ldr r1, [pc, #0x54c] */
/* @0xd4f0c mov r0, r5 */
/* @0xd4f10 add r1, pc, r1 */
/* @0xd4f14 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd4f18 b 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */

/* ── 段 7 · w0 = -4：压 [0, env2, env1] 并跳码（0xd4f1c..0xd4f68） ── */
/* @0xd4f1c ldr r0, [r5, #0x44] */
/* @0xd4f20 lsl r8, r8, #9 */
/* @0xd4f24 ldr r3, [r5, #0x18] */
/* @0xd4f28 mov r2, #0 */
/* @0xd4f2c sub r0, r0, #4 */
/* @0xd4f30 ldr r1, [r5, #0x14] */
/* @0xd4f34 add r8, r0, r8, asr #7 */
/* @0xd4f38 str r2, [r4, #-0x8] */
/* @0xd4f3c cmp r8, #0 */
/* @0xd4f40 add r2, r8, #3 */
/* @0xd4f44 str r1, [r4] */
/* @0xd4f48 sub r6, r4, #8 */
/* @0xd4f4c str r3, [r4, #-0x4] */
/* @0xd4f50 movge r2, r8 */
/* @0xd4f54 ldr r3, [r5, #0x5c] */
/* @0xd4f58 asr r2, r2, #2 */
/* @0xd4f5c str r8, [r5, #0x44] */
/* @0xd4f60 ldr r3, [r3, r2, lsl #2] */
/* @0xd4f64 str r3, [r5, #0x48] */
/* @0xd4f68 b 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */

/* ── 段 8 · w0 = -3：遍历 Run_Room 实例链 + 计数（0xd4f6c..0xd5030） ── */
/* @0xd4f6c ldr r3, [r5, #0x14] */
/* @0xd4f70 ldr r1, [r5, #0x18] */
/* @0xd4f74 ldr r2, [pc, #0x4e4] */
/* @0xd4f78 stmda r4, {r1, r3} */
/* @0xd4f7c str r3, [r5, #0x18] */
/* @0xd4f80 ldr r7, [r7, r2] */
/* @0xd4f84 ldr r3, [r7] */
/* @0xd4f88 ldr r3, [r3, #0x80] */
/* @0xd4f8c cmp r3, #0 */
/* @0xd4f90 beq 0xd53e8 <_Z9DoPushEnvjPhPKhP6VMExec+0x5ec> */
/* @0xd4f94 mov r0, #0 */
/* @0xd4f98 mov r1, r0 */
/* @0xd4f9c ldrb r2, [r3, #0x68] */
/* @0xd4fa0 ldr r6, [r3, #0x178] */
/* @0xd4fa4 cmp r2, #0 */
/* @0xd4fa8 bne 0xd4fc0 <_Z9DoPushEnvjPhPKhP6VMExec+0x1c4> */
/* @0xd4fac ldrb r2, [r3, #0x69] */
/* @0xd4fb0 cmp r2, #0 */
/* @0xd4fb4 addeq r0, r0, #1 */
/* @0xd4fb8 streq r1, [r5, #0x14] */
/* @0xd4fbc moveq r1, r3 */
/* @0xd4fc0 cmp r6, #0 */
/* @0xd4fc4 mov r3, r6 */
/* @0xd4fc8 bne 0xd4f9c <_Z9DoPushEnvjPhPKhP6VMExec+0x1a0> */
/* @0xd4fcc cmp r0, #2 */
/* @0xd4fd0 bgt 0xd5324 <_Z9DoPushEnvjPhPKhP6VMExec+0x528> */
/* @0xd4fd4 streq r6, [r4, #-0x8] */
/* @0xd4fd8 subeq r6, r4, #12 */
/* @0xd4fdc streq r1, [r4, #-0xc] */
/* @0xd4fe0 beq 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */
/* @0xd4fe4 cmp r0, #1 */
/* @0xd4fe8 streq r6, [r4, #-0x8] */
/* @0xd4fec subeq r6, r4, #8 */
/* @0xd4ff0 streq r1, [r5, #0x14] */
/* @0xd4ff4 beq 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */
/* @0xd4ff8 ldr r2, [r5, #0x44] */
/* @0xd4ffc lsl r8, r8, #9 */
/* @0xd5000 str r1, [r4, #-0x8] */
/* @0xd5004 sub r6, r4, #8 */
/* @0xd5008 sub r2, r2, #4 */
/* @0xd500c ldr r3, [r5, #0x5c] */
/* @0xd5010 add r8, r2, r8, asr #7 */
/* @0xd5014 str r8, [r5, #0x44] */
/* @0xd5018 add r2, r8, #3 */
/* @0xd501c cmp r8, #0 */
/* @0xd5020 movlt r8, r2 */
/* @0xd5024 asr r8, r8, #2 */
/* @0xd5028 ldr r3, [r3, r8, lsl #2] */
/* @0xd502c str r3, [r5, #0x48] */
/* @0xd5030 b 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */

/* ── 段 9 · 通用入口：w0 < 0 / 对象 id / 实例 id 三路（0xd5034..0xd50b4） ── */
/* @0xd5034 ldr r0, [r5, #0x14] */
/* @0xd5038 cmp r2, #0 */
/* @0xd503c ldr r3, [r5, #0x18] */
/* @0xd5040 str r0, [r1] */
/* @0xd5044 str r3, [r1, #-0x4] */
/* @0xd5048 blt 0xd52f8 <_Z9DoPushEnvjPhPKhP6VMExec+0x4fc> */
/* @0xd504c movw r3, #0x869f */
/* @0xd5050 movt r3, #0x1 */
/* @0xd5054 cmp r2, r3 */
/* @0xd5058 bgt 0xd51b4 <_Z9DoPushEnvjPhPKhP6VMExec+0x3b8> */
/* @0xd505c ldr r3, [pc, #0x400] */
/* @0xd5060 str r0, [r5, #0x18] */
/* @0xd5064 ldr r3, [r7, r3] */
/* @0xd5068 ldr r3, [r3] */
/* @0xd506c ldr r1, [r3, #0x4] */
/* @0xd5070 ldr r3, [r3] */
/* @0xd5074 and r1, r2, r1 */
/* @0xd5078 ldr r3, [r3, r1, lsl #3] */
/* @0xd507c cmp r3, #0 */
/* @0xd5080 bne 0xd5094 <_Z9DoPushEnvjPhPKhP6VMExec+0x298> */
/* @0xd5084 b 0xd5404 <_Z9DoPushEnvjPhPKhP6VMExec+0x608> */
/* @0xd5088 ldr r3, [r3, #0x4] */
/* @0xd508c cmp r3, #0 */
/* @0xd5090 beq 0xd5404 <_Z9DoPushEnvjPhPKhP6VMExec+0x608> */
/* @0xd5094 ldr r1, [r3, #0x8] */
/* @0xd5098 cmp r2, r1 */
/* @0xd509c bne 0xd5088 <_Z9DoPushEnvjPhPKhP6VMExec+0x28c> */
/* @0xd50a0 ldr r11, [r3, #0xc] */
/* @0xd50a4 cmp r11, #0 */
/* @0xd50a8 beq 0xd5404 <_Z9DoPushEnvjPhPKhP6VMExec+0x608> */
/* @0xd50ac ldr r6, [r11, #0xd0] */
/* @0xd50b0 cmp r6, #0 */
/* @0xd50b4 beq 0xd5444 <_Z9DoPushEnvjPhPKhP6VMExec+0x648> */

/* ── 段 10 · 对象 id 路径：CObjectGM 实例链 + HandleInstance（0xd50b8..0xd5128） ── */
/* @0xd50b8 ldr r3, [r6, #0x8] */
/* @0xd50bc cmp r3, #0 */
/* @0xd50c0 moveq r10, r3 */
/* @0xd50c4 beq 0xd512c <_Z9DoPushEnvjPhPKhP6VMExec+0x330> */
/* @0xd50c8 mov r3, #0 */
/* @0xd50cc mov r10, r3 */
/* @0xd50d0 b 0xd50e0 <_Z9DoPushEnvjPhPKhP6VMExec+0x2e4> */
/* @0xd50d4 ldr r2, [r6, #0x8] */
/* @0xd50d8 cmp r2, #0 */
/* @0xd50dc beq 0xd512c <_Z9DoPushEnvjPhPKhP6VMExec+0x330> */
/* @0xd50e0 ldr r9, [r6, #0x8] */
/* @0xd50e4 ldr r6, [r6] */
/* @0xd50e8 cmp r9, #0 */
/* @0xd50ec beq 0xd5124 <_Z9DoPushEnvjPhPKhP6VMExec+0x328> */
/* @0xd50f0 ldrb r2, [r9, #0x68] */
/* @0xd50f4 cmp r2, #0 */
/* @0xd50f8 bne 0xd5124 <_Z9DoPushEnvjPhPKhP6VMExec+0x328> */
/* @0xd50fc ldrb r2, [r9, #0x69] */
/* @0xd5100 mov r0, r9 */
/* @0xd5104 cmp r2, #0 */
/* @0xd5108 bne 0xd5124 <_Z9DoPushEnvjPhPKhP6VMExec+0x328> */
/* @0xd510c str r3, [sp] */
/* @0xd5110 bl 0xd3fd0 <_Z14HandleInstanceP9CInstance> */
/* @0xd5114 ldr r3, [sp] */
/* @0xd5118 str r10, [r5, #0x14] */
/* @0xd511c mov r10, r9 */
/* @0xd5120 add r3, r3, #1 */
/* @0xd5124 cmp r6, #0 */
/* @0xd5128 bne 0xd50d4 <_Z9DoPushEnvjPhPKhP6VMExec+0x2d8> */

/* ── 段 11 · 变更表 g_InstanceChangeArray 的 InstanceHandled 复筛（0xd512c..0xd51b0） ── */
/* @0xd512c ldr r2, [pc, #0x334] */
/* @0xd5130 ldr r11, [r11, #0x18] */
/* @0xd5134 ldr r2, [r7, r2] */
/* @0xd5138 ldr r1, [r2, #0x8] */
/* @0xd513c cmp r1, #0 */
/* @0xd5140 ble 0xd5228 <_Z9DoPushEnvjPhPKhP6VMExec+0x42c> */
/* @0xd5144 mov r6, #0 */
/* @0xd5148 b 0xd515c <_Z9DoPushEnvjPhPKhP6VMExec+0x360> */
/* @0xd514c ldr r1, [r2, #0x8] */
/* @0xd5150 add r6, r6, #1 */
/* @0xd5154 cmp r1, r6 */
/* @0xd5158 ble 0xd5228 <_Z9DoPushEnvjPhPKhP6VMExec+0x42c> */
/* @0xd515c ldr r1, [r2] */
/* @0xd5160 ldr r9, [r1, r6, lsl #2] */
/* @0xd5164 ldr r1, [r9, #0x7c] */
/* @0xd5168 cmp r11, r1 */
/* @0xd516c bne 0xd514c <_Z9DoPushEnvjPhPKhP6VMExec+0x350> */
/* @0xd5170 ldrb r1, [r9, #0x68] */
/* @0xd5174 cmp r1, #0 */
/* @0xd5178 bne 0xd514c <_Z9DoPushEnvjPhPKhP6VMExec+0x350> */
/* @0xd517c ldrb r1, [r9, #0x69] */
/* @0xd5180 cmp r1, #0 */
/* @0xd5184 bne 0xd514c <_Z9DoPushEnvjPhPKhP6VMExec+0x350> */
/* @0xd5188 mov r0, r9 */
/* @0xd518c str r2, [sp, #0x4] */
/* @0xd5190 str r3, [sp] */
/* @0xd5194 bl 0xd3f50 <_Z15InstanceHandledP9CInstance> */
/* @0xd5198 ldr r2, [sp, #0x4] */
/* @0xd519c ldr r3, [sp] */
/* @0xd51a0 cmp r0, #0 */
/* @0xd51a4 streq r10, [r5, #0x14] */
/* @0xd51a8 addeq r3, r3, #1 */
/* @0xd51ac moveq r10, r9 */
/* @0xd51b0 b 0xd514c <_Z9DoPushEnvjPhPKhP6VMExec+0x350> */

/* ── 段 12 · 实例 id 路径：ms_ID2Instance 查表（0xd51b4..0xd5224） ── */
/* @0xd51b4 ldr r3, [pc, #0x2b0] */
/* @0xd51b8 ldr r3, [r7, r3] */
/* @0xd51bc ldr r1, [r3, #0x4] */
/* @0xd51c0 ldr r3, [r3] */
/* @0xd51c4 and r1, r2, r1 */
/* @0xd51c8 ldr r3, [r3, r1, lsl #3] */
/* @0xd51cc cmp r3, #0 */
/* @0xd51d0 bne 0xd51e4 <_Z9DoPushEnvjPhPKhP6VMExec+0x3e8> */
/* @0xd51d4 b 0xd52f8 <_Z9DoPushEnvjPhPKhP6VMExec+0x4fc> */
/* @0xd51d8 ldr r3, [r3, #0x4] */
/* @0xd51dc cmp r3, #0 */
/* @0xd51e0 beq 0xd52f8 <_Z9DoPushEnvjPhPKhP6VMExec+0x4fc> */
/* @0xd51e4 ldr r1, [r3, #0x8] */
/* @0xd51e8 cmp r2, r1 */
/* @0xd51ec bne 0xd51d8 <_Z9DoPushEnvjPhPKhP6VMExec+0x3dc> */
/* @0xd51f0 ldr r3, [r3, #0xc] */
/* @0xd51f4 cmp r3, #0 */
/* @0xd51f8 beq 0xd52f8 <_Z9DoPushEnvjPhPKhP6VMExec+0x4fc> */
/* @0xd51fc ldrb r2, [r3, #0x68] */
/* @0xd5200 cmp r2, #0 */
/* @0xd5204 bne 0xd52f8 <_Z9DoPushEnvjPhPKhP6VMExec+0x4fc> */
/* @0xd5208 ldrb r2, [r3, #0x69] */
/* @0xd520c cmp r2, #0 */
/* @0xd5210 bne 0xd52f8 <_Z9DoPushEnvjPhPKhP6VMExec+0x4fc> */
/* @0xd5214 str r2, [r4, #-0x8] */
/* @0xd5218 sub r6, r4, #8 */
/* @0xd521c str r3, [r5, #0x14] */
/* @0xd5220 str r0, [r5, #0x18] */
/* @0xd5224 b 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */

/* ── 段 13 · 失活表 g_InstanceActivateDeactive 的 InstanceHandled 复筛（0xd5228..0xd52a0） ── */
/* @0xd5228 ldr r2, [pc, #0x240] */
/* @0xd522c ldr r9, [r7, r2] */
/* @0xd5230 ldr r2, [r9, #0x8] */
/* @0xd5234 cmp r2, #0 */
/* @0xd5238 ble 0xd52a4 <_Z9DoPushEnvjPhPKhP6VMExec+0x4a8> */
/* @0xd523c mov r6, #0 */
/* @0xd5240 b 0xd5254 <_Z9DoPushEnvjPhPKhP6VMExec+0x458> */
/* @0xd5244 ldr r2, [r9, #0x8] */
/* @0xd5248 add r6, r6, #1 */
/* @0xd524c cmp r2, r6 */
/* @0xd5250 ble 0xd52a4 <_Z9DoPushEnvjPhPKhP6VMExec+0x4a8> */
/* @0xd5254 ldr r2, [r9] */
/* @0xd5258 ldr r7, [r2, r6, lsl #2] */
/* @0xd525c ldr r2, [r7, #0x7c] */
/* @0xd5260 cmp r11, r2 */
/* @0xd5264 bne 0xd5244 <_Z9DoPushEnvjPhPKhP6VMExec+0x448> */
/* @0xd5268 ldrb r2, [r7, #0x68] */
/* @0xd526c cmp r2, #0 */
/* @0xd5270 bne 0xd5244 <_Z9DoPushEnvjPhPKhP6VMExec+0x448> */
/* @0xd5274 ldrb r2, [r7, #0x69] */
/* @0xd5278 cmp r2, #0 */
/* @0xd527c bne 0xd5244 <_Z9DoPushEnvjPhPKhP6VMExec+0x448> */
/* @0xd5280 mov r0, r7 */
/* @0xd5284 str r3, [sp] */
/* @0xd5288 bl 0xd3f50 <_Z15InstanceHandledP9CInstance> */
/* @0xd528c ldr r3, [sp] */
/* @0xd5290 cmp r0, #0 */
/* @0xd5294 streq r10, [r5, #0x14] */
/* @0xd5298 addeq r3, r3, #1 */
/* @0xd529c moveq r10, r7 */
/* @0xd52a0 b 0xd5244 <_Z9DoPushEnvjPhPKhP6VMExec+0x448> */

/* ── 段 14 · 按计数选压栈形态（0..>2）（0xd52a4..0xd52f4） ── */
/* @0xd52a4 cmp r3, #2 */
/* @0xd52a8 bgt 0xd5398 <_Z9DoPushEnvjPhPKhP6VMExec+0x59c> */
/* @0xd52ac beq 0xd53d4 <_Z9DoPushEnvjPhPKhP6VMExec+0x5d8> */
/* @0xd52b0 cmp r3, #1 */
/* @0xd52b4 beq 0xd53f0 <_Z9DoPushEnvjPhPKhP6VMExec+0x5f4> */
/* @0xd52b8 ldr r3, [r5, #0x44] */
/* @0xd52bc lsl r8, r8, #9 */
/* @0xd52c0 str r10, [r4, #-0x8] */
/* @0xd52c4 sub r6, r4, #8 */
/* @0xd52c8 sub r3, r3, #4 */
/* @0xd52cc ldr r2, [r5, #0x5c] */
/* @0xd52d0 add r3, r3, r8, asr #7 */
/* @0xd52d4 str r3, [r5, #0x44] */
/* @0xd52d8 add r1, r3, #3 */
/* @0xd52dc cmp r3, #0 */
/* @0xd52e0 movlt r3, r1 */
/* @0xd52e4 asr r3, r3, #2 */
/* @0xd52e8 ldr r3, [r2, r3, lsl #2] */
/* @0xd52ec str r3, [r5, #0x48] */
/* @0xd52f0 bl 0xd3ee0 <_Z21ClearHandledContainerv> */
/* @0xd52f4 b 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */

/* ── 段 15 · 无匹配（w0 < -7）：压 [0] + 跳码（0xd52f8..0xd5320） ── */
/* @0xd52f8 ldr r2, [r5, #0x44] */
/* @0xd52fc lsl r8, r8, #9 */
/* @0xd5300 mov r3, #0 */
/* @0xd5304 sub r6, r4, #8 */
/* @0xd5308 sub r2, r2, #4 */
/* @0xd530c str r3, [r4, #-0x8] */
/* @0xd5310 add r8, r2, r8, asr #7 */
/* @0xd5314 ldr r3, [r5, #0x5c] */
/* @0xd5318 str r8, [r5, #0x44] */
/* @0xd531c add r2, r8, #3 */
/* @0xd5320 b 0xd501c <_Z9DoPushEnvjPhPKhP6VMExec+0x220> */

/* ── 段 16 · >2 形态 A：Alloc + 手工填数组（0xd5324..0xd5394） ── */
/* @0xd5324 ldr r1, [pc, #0x148] */
/* @0xd5328 mov r3, #1 */
/* @0xd532c lsl r0, r0, #2 */
/* @0xd5330 movw r2, #0x2241 */
/* @0xd5334 add r1, pc, r1 */
/* @0xd5338 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xd533c ldr r3, [r7] */
/* @0xd5340 ldr r3, [r3, #0x80] */
/* @0xd5344 cmp r3, #0 */
/* @0xd5348 mov r12, r0 */
/* @0xd534c beq 0xd5380 <_Z9DoPushEnvjPhPKhP6VMExec+0x584> */
/* @0xd5350 ldrb r1, [r3, #0x68] */
/* @0xd5354 ldr r2, [r3, #0x178] */
/* @0xd5358 cmp r1, #0 */
/* @0xd535c bne 0xd5374 <_Z9DoPushEnvjPhPKhP6VMExec+0x578> */
/* @0xd5360 ldrb r1, [r3, #0x69] */
/* @0xd5364 cmp r1, #0 */
/* @0xd5368 streq r6, [r12], #4 */
/* @0xd536c moveq r6, r3 */
/* @0xd5370 streq r3, [r5, #0x14] */
/* @0xd5374 cmp r2, #0 */
/* @0xd5378 mov r3, r2 */
/* @0xd537c bne 0xd5350 <_Z9DoPushEnvjPhPKhP6VMExec+0x554> */
/* @0xd5380 mvn r3, #0 */
/* @0xd5384 str r0, [r4, #-0x8] */
/* @0xd5388 str r12, [r4, #-0xc] */
/* @0xd538c sub r6, r4, #16 */
/* @0xd5390 str r3, [r4, #-0x10] */
/* @0xd5394 b 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */

/* ── 段 17 · >2 形态 B：Alloc + IterateInstances（0xd5398..0xd53d0） ── */
/* @0xd5398 ldr r1, [pc, #0xd8] */
/* @0xd539c lsl r0, r3, #2 */
/* @0xd53a0 movw r2, #0x22c8 */
/* @0xd53a4 mov r3, #1 */
/* @0xd53a8 add r1, pc, r1 */
/* @0xd53ac sub r6, r4, #16 */
/* @0xd53b0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xd53b4 mov r1, r5 */
/* @0xd53b8 mov r7, r0 */
/* @0xd53bc bl 0xd410c <_Z16IterateInstancesPP12YYObjectBaseP6VMExec> */
/* @0xd53c0 mvn r3, #0 */
/* @0xd53c4 str r7, [r4, #-0x8] */
/* @0xd53c8 str r3, [r4, #-0x10] */
/* @0xd53cc str r0, [r4, #-0xc] */
/* @0xd53d0 b 0xd52f0 <_Z9DoPushEnvjPhPKhP6VMExec+0x4f4> */

/* ── 段 18 · 计数 2 / 1 的压栈形态（0xd53d4..0xd5400） ── */
/* @0xd53d4 mov r3, #0 */
/* @0xd53d8 str r10, [r4, #-0xc] */
/* @0xd53dc sub r6, r4, #12 */
/* @0xd53e0 str r3, [r4, #-0x8] */
/* @0xd53e4 b 0xd52f0 <_Z9DoPushEnvjPhPKhP6VMExec+0x4f4> */
/* @0xd53e8 mov r1, r3 */
/* @0xd53ec b 0xd4ff8 <_Z9DoPushEnvjPhPKhP6VMExec+0x1fc> */
/* @0xd53f0 mov r3, #0 */
/* @0xd53f4 sub r6, r4, #8 */
/* @0xd53f8 str r3, [r4, #-0x8] */
/* @0xd53fc str r10, [r5, #0x14] */
/* @0xd5400 b 0xd52f0 <_Z9DoPushEnvjPhPKhP6VMExec+0x4f4> */

/* ── 段 19 · 对象/实例查不到时的收尾（0xd5404..0xd5440） ── */
/* @0xd5404 ldr r3, [r5, #0x44] */
/* @0xd5408 lsl r8, r8, #9 */
/* @0xd540c mov r2, #0 */
/* @0xd5410 str r2, [r4, #-0x8] */
/* @0xd5414 sub r3, r3, #4 */
/* @0xd5418 ldr r2, [r5, #0x5c] */
/* @0xd541c add r3, r3, r8, asr #7 */
/* @0xd5420 str r3, [r5, #0x44] */
/* @0xd5424 add r1, r3, #3 */
/* @0xd5428 cmp r3, #0 */
/* @0xd542c sub r6, r4, #8 */
/* @0xd5430 movlt r3, r1 */
/* @0xd5434 asr r3, r3, #2 */
/* @0xd5438 ldr r3, [r2, r3, lsl #2] */
/* @0xd543c str r3, [r5, #0x48] */
/* @0xd5440 b 0xd4e44 <_Z9DoPushEnvjPhPKhP6VMExec+0x48> */

/* ── 段 20 · 对象无实例时 r10=0 的收尾 + literal pool（0xd5444..0xd5478） ── */
/* @0xd5444 mov r3, r6 */
/* @0xd5448 mov r10, r6 */
/* @0xd544c b 0xd512c <_Z9DoPushEnvjPhPKhP6VMExec+0x330> */
/* @0xd5450 eorseq r12, r1, r8, lsr lr —— 非指令（literal pool 数据字，objdump 误译） */
/* @0xd5454 eoreq sp, r5, r8, lsl r12 —— 非指令（literal pool 数据字，objdump 误译） */
/* @0xd5458 mlaeq r5, r12, r11, sp —— 非指令（literal pool 数据字，objdump 误译） */
/* @0xd545c eoreq sp, r5, r8, asr #22 —— 非指令（literal pool 数据字，objdump 误译） */
/* @0xd5460 .word 0xffffbcd8 */
/* @0xd5464 .word 0xffffbfec */
/* @0xd5468 .word 0xffffbff0 */
/* @0xd546c .word 0xffffbff4 */
/* @0xd5470 .word 0xffffbff8 */
/* @0xd5474 eoreq sp, r5, r8, asr #8 */
/* @0xd5478 .word 0x0025d3d4 */
