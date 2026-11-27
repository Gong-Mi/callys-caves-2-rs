/* cally 逆向卡：DoDestroy（原版 libyoyo.so，armv7）
 * @func 0x10b0c4 0x10b12c  size 104  26 条（末条指令 0x10b128 实为 literal 池词 0x002e2fa8，反汇编器当指令显示）
 * 级别: 正文（26/26 逐条落锚；两条出口、事件调用、标志位、计数器、唯一调用点全证）
 * 符号: _Z9DoDestroyP9CInstanceb → void DoDestroy(CInstance* inst, bool hard)
 * 位置: 紧接 YYGML_instance_create(0x10b09c)，其后是 DoInstanceDestroy(0x10b12c)、F_InstanceDestroy(0x10b190)
 *       本批两函数都是实例销毁路径，不是 VM 处理器；栈帧只有 8 字节（push {r4,lr}）
 *
 * ── 语义草案 ─────────────────────────────────────────────────────────────
 *   void DoDestroy(CInstance* inst, bool hard) {
 *     if (!inst) return;                             // 0x10b0c8 / 0x10b0cc
 *     if (inst->[0x68]) return;                      // 0x10b0d0..0x10b0d8   已 skip 就返回
 *     if (inst->[0x69]) return;                      // 0x10b0dc..0x10b0e4   已 deactivated 就返回
 *     if (hard) { Command_Destroy(inst); return; }   // 0x10b0e8 / 0x10b0ec → 0x10b120 / 0x10b124（尾跳）
 *     Perform_Event(inst, inst, 12, 0);              // 0x10b0f0..0x10b0fc
 *     inst->[0x68] = 1;                              // 0x10b104 / 0x10b108
 *     ++*(uint32_t*)0x536d7c;                        // 0x10b100..0x10b118（经 GOT 槽 0x3ee0bc）
 *   }
 *
 * ── 已证（指令级）─────────────────────────────────────────────────────────
 *  1) 两道闸门在 hard 判断之前：ldrb/cmp + popne（0x10b0d0..0x10b0e4）。命中任一闸门即 pop 返回，
 *     既不跑事件也不计数 —— 所以 hard=1 也救不回已置位的实例。
 *  2) hard 分流：cmp r1,#0 / bne 0x10b120；hard!=0 走 0x10b120 pop {r4,lr} + b 0x1c9b54
 *     Command_Destroy(CInstance*)，是尾跳（本函数不再返回自己的 epilogue）。
 *  3) 软路径唯一的事件调用：Perform_Event(r0=inst, r1=inst, r2=12, r3=0)。
 *     r3 取自 r1（hard==0），r0 自函数入口未改；Perform_Event(0xf3380) 立刻转
 *     Perform_Event_Object(inst, other, inst->[0x7c], type=12, num=0) —— 事件按「对象索引 + 事件类型」派发。
 *  4) 软路径只置 +0x68 = 1（0x10b104 mov r2,#1 / 0x10b108 strb）。它不置 +0x6A：
 *     硬路径 Command_Destroy(0x1c9b54) 才置 +0x6A（0x1c9b70）。故同一实例软销毁后仍能被硬销毁一次，
 *     而 +0x68 一旦为 1，后续任何 DoDestroy 都被第 2 步闸门挡掉（含 instance_destroy 重入）。
 *  5) 计数器：0x10b100 ldr r3,[pc,#0x20] 取 0x10b128 处的 0x002e2fa8；
 *     0x10b10c ldr r3,[pc,r3]，PC=0x10b114，目标 = 0x10b114+0x2e2fa8 = 0x3EE0BC（.got，R_ARM_RELATIVE）；
 *     槽内值 = 0x536D7C（.bss 4 字节零初始化本地静态 → 无符号名）；随后 ldr/add #1/str ⇒ ++(*(uint32*)0x536D7C)。
 *  6) Command_Destroy 用同一个槽：0x1c9b9c ldr r3,[pc,r3]，PC=0x1c9ba4，目标 = 0x1c9ba4+0x224518 = 0x3EE0BC。
 *     硬路径的顺序是：+0x6A!=0 就返回 → +0x6A=1 → 事件 1 → 事件 12 → +0x68=1 → 同一计数器 ++。
 *     即软/硬两路共用「+0x68 闩 + 全局计数器」，只在「事件 1」与「+0x6A」上不同。
 *  7) 调用点：全图唯一 0x10b168（DoInstanceDestroy 循环体内）。对整份 .so 做 4 字节地址搜索，
 *     0x10B0C4 只出现在 .dynsym 的 st_value（文件偏移 0x873C，.dynsym 0x148..0x2df58）——
 *     没有函数指针/表项引用它，DoPop/DoPush 也不可能间接到这里。
 *  8) 交叉证据（跨批，非本卡独立证明）：+0x68 = skip、+0x69 = deactivated 见
 *     reconstruction/live-mem/live-findings-v2.md:74；Perform_Event_All(0xf33fc/0xf340c) 与
 *     DrawInstancesOnly 同样按这两字节跳过；DoPushEnv 的 with 遍历也按它们过滤（0xd4f9c、0xd50f0）。
 *
 * ── open ────────────────────────────────────────────────────────────────
 *  · 事件号 12 的名称：Command_Change(0x1c9bb4) 在换对象索引「前」跑 1、12，「后」跑 14、0，
 *    据此推断 1=Destroy、12=CleanUp；本卡未独立证明编号含义。
 *  · 0x536D7C 计数器用途（销毁计数？）未定；.dynsym 无此符号。
 *  · 软路径不摘链：本函数不碰 +0x178/+0x17C（实例链）也不释放对象，摘链/释放发生在别处，未定位。
 */

/* ── 1. 入口：栈帧 8 字节 + 空指针闸（0x10b0c4..0x10b0cc）─────────────────── */
/* @0x10b0c4 push {r4, lr} */
/* @0x10b0c8 subs r4, r0, #0 */
/* @0x10b0cc popeq {r4, pc} */

/* ── 2. 两道标志闸：+0x68(skip)、+0x69(deactivated) 命中即返回（0x10b0d0..0x10b0e4）── */
/* @0x10b0d0 ldrb r2, [r4, #0x68] */
/* @0x10b0d4 cmp r2, #0 */
/* @0x10b0d8 popne {r4, pc} */
/* @0x10b0dc ldrb r3, [r4, #0x69] */
/* @0x10b0e0 cmp r3, #0 */
/* @0x10b0e4 popne {r4, pc} */

/* ── 3. hard 分流：cmp r1,#0 / bne 0x10b120（0x10b0e8..0x10b0ec）────────────── */
/* @0x10b0e8 cmp r1, #0 */
/* @0x10b0ec bne 0x10b120 <_Z9DoDestroyP9CInstanceb+0x5c> */

/* ── 4. 软路径：Perform_Event(inst, inst, 12, 0)（0x10b0f0..0x10b0fc）───────── */
/* @0x10b0f0 mov r3, r1 */
/* @0x10b0f4 mov r2, #12 */
/* @0x10b0f8 mov r1, r4 */
/* @0x10b0fc bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */

/* ── 5. 置 +0x68=1 后递增全局计数器（GOT 0x3ee0bc → .bss 0x536d7c）（0x10b100..0x10b118）── */
/* @0x10b100 ldr r3, [pc, #0x20] */
/* @0x10b104 mov r2, #1 */
/* @0x10b108 strb r2, [r4, #0x68] */
/* @0x10b10c ldr r3, [pc, r3] */
/* @0x10b110 ldr r2, [r3] */
/* @0x10b114 add r2, r2, #1 */
/* @0x10b118 str r2, [r3] */

/* ── 6. 软路径返回（0x10b11c）──────────────────────────────────────────────── */
/* @0x10b11c pop {r4, pc} */

/* ── 7. 硬路径：pop + 尾跳 Command_Destroy（0x10b120..0x10b124）──────────────── */
/* @0x10b120 pop {r4, lr} */
/* @0x10b124 b 0x1c9b54 <_Z15Command_DestroyP9CInstance> */

/* ── 8. literal 池词 0x002e2fa8 = GOT 槽 0x3ee0bc 的 PC 相对偏移（0x10b128）────── */
/* @0x10b128 eoreq r2, lr, r8, lsr #31 */
