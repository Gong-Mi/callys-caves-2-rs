/* cally 逆向卡：Variable_GetValue（原版 libyoyo.so，armv7）
 * @func 0x1f3ce0 0x1f3f8c  size 684  171 条（164 条指令 + 7 条字面量池字，池 0x1f3f70..0x1f3f88）
 * 级别: 正文（171/171 逐条锚定；四段分派、两张哈希表、两次退化扫描、六个 .bss 全局全部落地；
 *            三个 int 的合成与返回值约定各有「调用点实参 + 错误文案 + 被调方指令」三重证据；open 3 条见文末）
 * 符号: _Z17Variable_GetValueiiiP6RValue → int Variable_GetValue(int id, int varid, int arrindex, RValue* out)
 *
 * ── 一句话 ──────────────────────────────────────────────────────────
 *   「按 p1 选出一个 CInstance*，然后把 (实例, p2, p3, out) 整体转交 Variable_GetValue_Direct」。
 *   本函数一个字节的变量值都不读、也不写 out：它只做**实例解析**；取值在 Direct(0x1f3b8c, 156 B) 里完成。
 *   全函数 push 里没有 lr、体内零 bl —— 六条出口：五条 pop 后 b 尾跳 Direct，一条 pop 后 bx lr（唯一，返回 0）。
 *
 * ── 三个 int 如何合成（域 / 变量号 / 下标）──────────────────────────
 *   唯一调用点 DoPush 0xea628..0xea638：Variable_GetValue(r8, [sp+0x1c], [sp+0x24], r10=dest)
 *     p1 = r8        ← GML 实例号：0xea070 sxth 取 arg 低 16 位有符号值，位 30 置位时再 +=100000（0xea09c/0xea0a4）
 *     p2 = [sp+0x1c] ← 操作数字 w = *(uint32*)base 的**低 28 位**（0xea0a0 bic r3,r3,#-268435456 后 0xea0a8 落栈）
 *     p3 = [sp+0x24] ← w 符号位为 1 → INT_MIN 哨兵 0x80000000（0xea084/0xea088）；为 0 → 从值栈弹 4 B（0xea080/0xea08c）
 *
 *   ① p1 = 域/对象。四段，判据就是三条比较（0x1f3ce4 cmn #3、0x1f3d04 blt #0、0x1f3d14 cmp #0x1869f）：
 *        -3        → 「全体实例」：取 Run_Room 实例链上第一个活实例
 *        0..99999  → 对象索引（对象资产 id）：查 g_ObjectHash，再取其实例链表第一个活实例
 *        > 99999   → 实例 id：查 CInstance::ms_ID2InstanceE
 *        其余负数   → 直接失败（-1 self / -2 other 不由本函数解析：DoPush 的 -1 走 0xea2cc、-2 走 0xea618，
 *                    负 id 分派表在 0xea0f8 起 14 项，-3 恰好落回本函数入口）
 *   ② p2 = 变量号。本函数完全不解码它，只往下传；语义由 Direct 的两段比较钉死：
 *        0..9999   → 内建(引擎)变量序号：16 B 表项、fn 在 +4、以 fn(obj, p3, out) 调用
 *                    （Direct 0x1f3be4..0x1f3bfc；表基址 = GOT 0x3edc40 → 0x75310c，与 Code_Variable_Find_Name 卡
 *                     CVFN-003 指的**同一张内建变量表**，名字在槽 +0）
 *        ≥ 10000   → 变量 id：槽号 = p2 − 100000（Direct 0x1f3bb4 sub #99328 / 0x1f3bb8 sub #672 两段减），
 *                    槽 = [obj+4] + 槽号*16（0x1f3bc4）；[obj+0x24]==0 → 返回 0（0x1f3ba4..0x1f3bd8）；
 *                    [obj+4]==0 → 先 InternalGetYYVar(obj, 槽号) 惰性建槽（0x1f3c08..0x1f3c10）
 *   ③ p3 = 数组下标。INT_MIN = 标量读；其它值当数组下标，但只有源变量是 tag 2（数组）时才被消费：
 *        GET_RValue(0xd13bc) 对非 tag2 源先 `cmp r2,#0x80000000`（0xd13e4），不等就 YYError(0xd13ec..0xd13f4)；
 *        tag2 源走 0xd1594，把 p3 送 ldiv(index, 32000)（0xd15a4）拆成两级下标。
 *   三者互不偏序：p1 = 读谁的，p2 = 读哪个变量/槽，p3 = 取数组哪一格。
 *   旁证（错误文案）：DoPush 0xea614 + 字面量 0x24a350 = 0x334964
 *     "Variable %s.%s(%d, %d) not set before reading it."
 *   四个变参 = 对象名（姊妹函数 Variable_GetObjectName 的返回值，r2）、变量名（Code_Variable_Find_Name，r3）、
 *   第 3 参 [sp+0x1c]（p2）、第 4 参 [sp+0x24]（p3）—— (对象, 变量号, 下标) 就是三个 int 的角色。
 *
 * ── 全局寻址：.got 基址 0x3f1c58 + 六个负偏移（全部 R_ARM_RELATIVE，目标是本模块 .bss，不是导入符号）──
 *   基址：0x1f3cf4 add r6,pc,r6，pc=0x1f3cfc + 0x001fdf5c（池 0x1f3f70）= 0x3f1c58（与 VMError / UpdateActiveLists 同锚点）
 *     槽 0x3edd68  (-0x3ef0) → 0x75505c  1 B 「取值失败」标志（本函数入口清 0、失败置 1；DoPush 0xea0e0..0xea0e8 先清、0xea65c 后读）
 *     槽 0x3edc4c  (-0x400c) → 0x536f28  CInstance::ms_ID2InstanceE（12 B：+0 buckets / +4 mask=511 / +8 count）
 *     槽 0x3edc44  (-0x4014) → 0x542374  g_ObjectHash —— **指针变量**（多一层解引用），指向 {+0 buckets / +4 mask / +8 count}
 *     槽 0x3edc48  (-0x4010) → 0x542a64  退化扫描列表 1（12 B：+0 数组 / +4 ? / +8 count）
 *     槽 0x3edc50  (-0x4008) → 0x542a4c  退化扫描列表 2（同构，见 open 1 的命名来源）
 *     槽 0x3ed930  (-0x4328) → 0x54298c  Run_Room（指针变量；live-mem 实测 = 0xeafc63e0）
 *   六个槽的 addend 都在文件里（.got 全 R_ARM_RELATIVE），所以上面这些 .bss 地址是**直读**出来的，不是猜的。
 *
 * ── 对象/实例两套容器（本函数是它们唯一的「取值侧」消费者）────────────
 *   ms_ID2InstanceE(0x536f28)：bucket 8 B {head@0,tail@4}；node 16 B {prev@0,next@4,id@8,inst@0xc}；mask=511
 *     —— 与 reconstruction/contracts/live-oracle-registrations.md §3.2 的记录逐字段吻合（本卡 0x1f3d24..0x1f3d58 复现）
 *   g_ObjectHash：同形桶链，但值域是 CObjectGM*（key@+8 = 对象索引）。
 *     CObjectGM 侧字段（本函数用到 +0x18/+0x48/+0xd0）：ctor 0x19d548 `str r6,[r5,#0x18]` = 索引、+0x48 = 上级对象
 *     （AddInstance 0x19e0d8 沿它递归把实例登记进祖先）、+0xd0/+0xd4/+0xd8 = 实例双向链表头/尾/计数
 *     （CObjectGM::AddInstance 0x19e02c 建节点 12 B {+0 next,+4 prev,+8 inst}）。
 *   ⇒ 这组字段同时是 Variable_SetValue 卡 open 2 所缺的那条独立证据：CObjectGM ctor(0x19d4f4) 在 0x19d548
 *     `str r6,[r5,#0x18]` 把构造参数写进 +0x18、0x19d54c `str r4,[r5,#0x48]` 把 0 写进 +0x48；AddInstance
 *     在 0x19e0d8 `ldr r4,[r4,#0x48]` 后回跳，循环给**祖先**也登记同一实例 ⇒「+0x18 = 对象下标、+0x48 = 父对象、
 *     +0xd0 = 该对象的实例链」三件在本函数侧闭合（不修改该卡，只在此登记）。
 *
 * ── 四个分支的控制流（每条边都在锚点里）──────────────────────────
 *   A  p1 == -3        0x1f3f0c..0x1f3f54  room=*(0x54298c); inst=room->[0x80]; 沿 +0x178 找第一个 +0x68/+0x69 皆 0
 *   B  p1 < 0（≠-3）   0x1f3d08 → 0x1f3e68  立即失败，不试探任何表
 *   C  p1 > 99999      0x1f3d0c..0x1f3d74  ms_ID2InstanceE 按完整 32 位 id 命中；**只查 +0x68，不查 +0x69**
 *   D  0 ≤ p1 ≤ 99999  0x1f3e7c..0x1f3f08  g_ObjectHash → CObjectGM* → [+0xd0] 实例链 → 第一个活实例
 *      任一环节为空（无对象 / 无链 / 链空 / 全死）→ 退化扫描 1（0x542a64）→ 退化扫描 2（0x542a4c）→ 失败
 *   退化扫描的判据不是「对象指针相等」，而是**沿 CObjectGM 上级链找索引**：
 *     for (inst in arr) { for (o = inst->[0x80]; o; o = o->[0x48]) if (o->[0x18] == p1) 命中;
 *                         命中且 inst->[0x68]==0 && inst->[0x69]==0 → 用 }
 *   ⇒ 即「实例属于 p1 或 p1 的子孙对象」等价于 `with (p1)` 的成员判定。
 *   ⇒ 与 UpdateActiveLists 卡对齐：0x542a64 是「待重链(改类型)队列」、0x542a4c 是「待激活/反激活队列」，
 *     恰好是「对象链可能过期」的两批实例，所以它们构成对象表未命中后的兜底（本卡只证布局与元素类型，命名引自该卡）。
 *   ⇒ 与姊妹卡 Variable_SetValue(0x1f4348) 的**唯一结构差别**：那边两个后备容器无条件跑（写要覆盖全集），
 *     这边只在对象表没给出活实例时才跑（读只要一个实例）。两卡的槽位、判据、链字段逐条同构（该卡 0x1f4450/0x1f4514）。
 *
 * ── 返回值约定 ─────────────────────────────────────────────────────
 *   返回 int：**非 0 = 已解析**，0 = 未解析。本函数自身只在一条出口造 0：
 *     0x1f3e68..0x1f3e78（六个失败分支全部汇合到这里，`mov r0,#0` + `strb 1,[r7]`）
 *   成功时返回值是 Direct 的返回值原样透传（尾跳），不是本函数算的：内建变量路 = getter 的返回值，
 *   实例变量路 = GET_RValue 的返回值（GET_RValue 多数出口显式 `mov r0,#1`：0xd14d4 / 0xd153c / 0xd157c；
 *   也有出口不设 r0 直接 pop，如 0xd14ec —— 所以这个返回值只能当布尔看，DoPush 0xea654 就是这么用的）。
 *   失败时的三个副作用约定（调用方 DoPush 全部依赖）：
 *     ① 0x75505c 置 1（入口已先清 0，所以它是「本次调用失败」而不是粘性状态）；
 *     ② **out 一个字节都不写** —— 调用方预置的 tag 0x00FFFFFF（未解析变量引用）原样保留，
 *        这正是 DoPush 0xea248 那条「dest 的 tag 字仍 == 0x00FFFFFF → 报错」判据能工作的前提；
 *     ③ 不回滚任何状态（本函数只读表，唯一的写就是那个标志字节）。
 *
 * ── 已证（每条都指到指令）──────────────────────────────────────────
 *   1. 入口无条件清 0x75505c（0x1f3cf8/0x1f3cfc），p1 四段分派由 cmn#3 / blt#0 / cmp#0x1869f 三条比较决定
 *      （0x1f3ce4、0x1f3d04、0x1f3d14）。
 *   2. p1 == -3 取「房间实例链第一个活实例」：Run_Room→+0x80 是链头（0x1f3f18），next 在 +0x178（0x1f3f38）。
 *   3. p1 > 99999 走 ms_ID2InstanceE，桶 8 B、节点 {next@+4, id@+8, inst@+0xc}，mask 在 +4
 *      （0x1f3d24..0x1f3d58）；命中后**只查 +0x68**，deactivated(+0x69) 的实例按 id 仍可读（0x1f3d64）。
 *   4. 0..99999 是对象索引：g_ObjectHash 是**指针变量**（0x1f3e80 取址 + 0x1f3e84 解引用），
 *      值 = CObjectGM*，实例链头在其 +0xd0（0x1f3ec4）。
 *   5. 对象链全空/全死不算失败，先扫 0x542a64 再扫 0x542a4c；两处判据都是沿 CObjectGM 上级链（+0x48）
 *      比对索引（+0x18），再要求实例两标志皆 0（0x1f3da4..0x1f3dc0、0x1f3e1c..0x1f3e38）。
 *   6. 六个 .bss 全局与 GOT 槽一一对应（见上表），全部由文件内 addend 直读。
 *   7. 失败 = 返回 0 + 标志置 1 + out 不写（0x1f3e68..0x1f3e78）；out 的占位 tag 由调用方负责。
 *   8. 与 Direct 的分工：五条成功出口全是 `pop {r4..r11}` + `b 0x1f3b8c`（0x1f3d74 / 0x1f3f08 / 0x1f3f54 /
 *      0x1f3f60 / 0x1f3f6c），尾跳前只把实例放进 r0，p2/p3/out 三个寄存器原样未动。
 *
 * ── open ───────────────────────────────────────────────────────────
 *   1. 两个退化扫描列表（0x542a64 / 0x542a4c）的**类名**未定：只证 12 B {+0 数组,+4 ?, +8 count}、元素是
 *      CInstance*、且 +8 为 0 时整段跳过。命名借 UpdateActiveLists 卡（ChangeInstanceTypes / ProcessActivateDeactveLists），
 *      该卡自己也把类名标为 narrowed。+4 字段本函数从未读。
 *   2. p2 ∈ [10000, 99999] 是空档：本函数不校验，Direct 也只用 `cmp ≤ 9999` 一条门，该区间会算出负槽号
 *      （槽 = [obj+4] + (p2-100000)*16）。这个区间是否真能出现（名字表是否会给这种 id）未证；
 *      若可达，就是原版的一处越界读。
 *   3. p1 ∈ {-1,-2} 落进「p1 < 0 → 失败」；GML 语义上 self/other 由 DoPush 负 id 分派表提前解析，
 *      但**其它调用者**（如 YYGML_Variable_GetValue 0x1f40cc 这条 GML 内建包装）是否也会传 -1/-2 未逐一审计。
 */

/* ═══ 段 1 · 序言 + 清失败标志 + 四段分派的头两条比较（0x1f3ce0..0x1f3d08）═══ */
/* @0x1f3ce0 push {r4, r5, r6, r7, r8, r9, r10, r11} */  —— 无 lr：五条成功出口都是 pop + 尾跳 b，唯一 bx lr 在失败出口
/* @0x1f3ce4 cmn r0, #3 */  —— r0+3==0 ⇔ p1 == -3（all）
/* @0x1f3ce8 ldr r6, [pc, #0x280] */  —— 池 0x1f3f70 = 0x001fdf5c（GOT 基址偏移）
/* @0x1f3cec mov r4, #0 */  —— 0：既当「清标志」的写入值，也当后面的空指针比较基准
/* @0x1f3cf0 ldr r12, [pc, #0x27c] */  —— 池 0x1f3f74 = 0xffffc110 = -0x3ef0（失败标志槽）
/* @0x1f3cf4 add r6, pc, r6 */  —— r6 = 0x1f3cfc + 0x1fdf5c = 0x3f1c58（.got 基址）
/* @0x1f3cf8 ldr r7, [r6, r12] */  —— r7 = *(0x3edd68) = 0x75505c —— 1 B 失败标志的**地址**
/* @0x1f3cfc strb r4, [r7] */  —— ★ 0x75505c = 0：入口无条件清失败标志
/* @0x1f3d00 beq 0x1f3f0c <_Z17Variable_GetValueiiiP6RValue+0x22c> */  —— p1 == -3 → all 分支
/* @0x1f3d04 cmp r0, #0 */
/* @0x1f3d08 blt 0x1f3e68 <_Z17Variable_GetValueiiiP6RValue+0x188> */  —— p1 < 0 且 ≠ -3（-1/-2/-4…）→ 直接失败
/* ═══ 段 2 · 实例 id 分支（p1 > 99999）：ms_ID2InstanceE 桶链（0x1f3d0c..0x1f3d74）═══ */
/* @0x1f3d0c movw r12, #0x869f */  —— r12 = 0x1869f
/* @0x1f3d10 movt r12, #0x1 */  —— 拼出 99999 —— 对象索引 / 实例 id 的分界
/* @0x1f3d14 cmp r0, r12 */
/* @0x1f3d18 ble 0x1f3e7c <_Z17Variable_GetValueiiiP6RValue+0x19c> */  —— p1 ≤ 99999 → 对象索引分支（0x1f3e7c）
/* @0x1f3d1c ldr r12, [pc, #0x254] */  —— 池 0x1f3f78 = 0xffffbff4 = -0x400c
/* @0x1f3d20 ldr r12, [r6, r12] */  —— r12 = 0x536f28 = ms_ID2InstanceE（结构体本体，后面只再解一次）
/* @0x1f3d24 ldr r4, [r12, #0x4] */  —— mask（=511，容量-1）
/* @0x1f3d28 ldr r12, [r12] */  —— bucket 数组基址
/* @0x1f3d2c and r4, r0, r4 */  —— idx = p1 & mask
/* @0x1f3d30 ldr r12, [r12, r4, lsl #3] */  —— bucket 8 B {head@0, tail@4} → 取 head
/* @0x1f3d34 cmp r12, #0 */
/* @0x1f3d38 bne 0x1f3d4c <_Z17Variable_GetValueiiiP6RValue+0x6c> */  —— 非空桶 → 比 key
/* @0x1f3d3c b 0x1f3e68 <_Z17Variable_GetValueiiiP6RValue+0x188> */  —— 空桶 → 失败
/* @0x1f3d40 ldr r12, [r12, #0x4] */  —— node = node->next（+4）
/* @0x1f3d44 cmp r12, #0 */
/* @0x1f3d48 beq 0x1f3e68 <_Z17Variable_GetValueiiiP6RValue+0x188> */  —— 链尾仍未命中 → 失败
/* @0x1f3d4c ldr r4, [r12, #0x8] */  —— node->id（完整 32 位；桶号只是索引，撞桶不会误命中）
/* @0x1f3d50 cmp r0, r4 */
/* @0x1f3d54 bne 0x1f3d40 <_Z17Variable_GetValueiiiP6RValue+0x60> */  —— 撞桶 → 继续
/* @0x1f3d58 ldr r0, [r12, #0xc] */  —— node->instance
/* @0x1f3d5c cmp r0, #0 */
/* @0x1f3d60 beq 0x1f3e68 <_Z17Variable_GetValueiiiP6RValue+0x188> */  —— 空值 → 失败
/* @0x1f3d64 ldrb r12, [r0, #0x68] */  —— skip 标志（DoDestroy 软销毁置 1）
/* @0x1f3d68 cmp r12, #0 */
/* @0x1f3d6c bne 0x1f3e68 <_Z17Variable_GetValueiiiP6RValue+0x188> */  —— ★ 已 skip → 失败；本路**不查 +0x69**，deactivated 实例按 id 仍可读
/* @0x1f3d70 pop {r4, r5, r6, r7, r8, r9, r10, r11} */  —— r0 已是实例，p2/p3/out 未动
/* @0x1f3d74 b 0x1f3b8c <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue> */  —— 尾跳 Direct(inst, p2, p3, out)
/* ═══ 段 3 · 退化扫描 1：列表 0x542a64（0x1f3d78..0x1f3dec）═══
 *   进入条件：对象表未命中 / 命中但对象或实例链为空 / 链上全死。
 *   判据：先沿 inst->[0x80] 的 +0x48 上级链比对 +0x18 对象索引（等价 with(p1) 的成员判定），
 *         命中后再要求 +0x68 / +0x69 皆 0。 */
/* @0x1f3d78 ldr r12, [pc, #0x1fc] */  —— 池 0x1f3f7c = 0xffffbff0 = -0x4010
/* @0x1f3d7c ldr r10, [r6, r12] */  —— r10 = 0x542a64 —— 列表 1 本体（12 B）
/* @0x1f3d80 ldr r11, [r10, #0x8] */  —— count 在 +8
/* @0x1f3d84 cmp r11, #0 */
/* @0x1f3d88 ble 0x1f3df0 <_Z17Variable_GetValueiiiP6RValue+0x110> */  —— 空 → 直接看列表 2
/* @0x1f3d8c mov r8, #0 */  —— i = 0
/* @0x1f3d90 ldr r12, [r10] */  —— 数组基址
/* @0x1f3d94 ldr r9, [r12, r8, lsl #2] */  —— inst = arr[i]（元素就是 CInstance*，4 B）
/* @0x1f3d98 ldr r12, [r9, #0x80] */  —— inst->[0x80] = CObjectGM*（SetObjectIndex 写 / RelinkObjectTypes 读的同一字段）
/* @0x1f3d9c cmp r12, #0 */
/* @0x1f3da0 beq 0x1f3de4 <_Z17Variable_GetValueiiiP6RValue+0x104> */  —— 无对象 → 下一个实例
/* @0x1f3da4 ldr r4, [r12, #0x18] */  —— 该层对象的索引（CObjectGM ctor 0x19d548 写 +0x18）
/* @0x1f3da8 ldr r12, [r12, #0x48] */  —— 上级对象（AddInstance 0x19e0d8 沿 +0x48 上溯）
/* @0x1f3dac cmp r0, r4 */  —— p1 == 该层索引？
/* @0x1f3db0 movne r5, #0 */  —— 未命中位
/* @0x1f3db4 moveq r5, #1 */  —— 命中位
/* @0x1f3db8 cmp r0, r4 */  —— 再判一次：相等即跳出循环（命中）
/* @0x1f3dbc cmpne r12, #0 */  —— 不等时才看上级是否为空
/* @0x1f3dc0 bne 0x1f3da4 <_Z17Variable_GetValueiiiP6RValue+0xc4> */  —— 沿 +0x48 上溯：判定「实例属于 p1 或其子孙对象」
/* @0x1f3dc4 cmp r5, #0 */
/* @0x1f3dc8 beq 0x1f3de4 <_Z17Variable_GetValueiiiP6RValue+0x104> */  —— 上级链无匹配 → 下一个实例
/* @0x1f3dcc ldrb r12, [r9, #0x68] */
/* @0x1f3dd0 cmp r12, #0 */
/* @0x1f3dd4 bne 0x1f3de4 <_Z17Variable_GetValueiiiP6RValue+0x104> */  —— → 下一个实例
/* @0x1f3dd8 ldrb r12, [r9, #0x69] */
/* @0x1f3ddc cmp r12, #0 */
/* @0x1f3de0 beq 0x1f3f58 <_Z17Variable_GetValueiiiP6RValue+0x278> */  —— 两标志皆 0 → 命中，r9 交 Direct
/* @0x1f3de4 add r8, r8, #1 */  —— ++i
/* @0x1f3de8 cmp r8, r11 */
/* @0x1f3dec bne 0x1f3d90 <_Z17Variable_GetValueiiiP6RValue+0xb0> */
/* ═══ 段 4 · 退化扫描 2：列表 0x542a4c（0x1f3df0..0x1f3e64）═══
 *   与段 3 逐指令同构，只有三处差别：全局换成 0x542a4c、命中位改用 subs/rsbs/adcs 求「差为 0」的进位、
 *   「i 上限」留在 r10（段 3 是 r11）。两段都不写 out。 */
/* @0x1f3df0 ldr r12, [pc, #0x188] */  —— 池 0x1f3f80 = 0xffffbff8 = -0x4008
/* @0x1f3df4 ldr r9, [r6, r12] */  —— r9 = 0x542a4c —— 列表 2 本体
/* @0x1f3df8 ldr r10, [r9, #0x8] */  —— count 在 +8
/* @0x1f3dfc cmp r10, #0 */
/* @0x1f3e00 ble 0x1f3e68 <_Z17Variable_GetValueiiiP6RValue+0x188> */  —— 两个列表都没命中 → 失败（最后一道门）
/* @0x1f3e04 mov r6, #0 */  —— i = 0（r6 原本存 GOT 基址，此处已无用，被复用）
/* @0x1f3e08 ldr r12, [r9] */  —— 数组基址
/* @0x1f3e0c ldr r8, [r12, r6, lsl #2] */  —— inst = arr[i]
/* @0x1f3e10 ldr r12, [r8, #0x80] */  —— inst->[0x80] = CObjectGM*
/* @0x1f3e14 cmp r12, #0 */
/* @0x1f3e18 beq 0x1f3e5c <_Z17Variable_GetValueiiiP6RValue+0x17c> */  —— 无对象 → 下一个
/* @0x1f3e1c ldr r4, [r12, #0x18] */  —— 该层对象索引
/* @0x1f3e20 ldr r12, [r12, #0x48] */  —— 上级对象
/* @0x1f3e24 subs r11, r0, r4 */  —— subs：p1-索引
/* @0x1f3e28 rsbs r5, r11, #0 */  —— rsbs
/* @0x1f3e2c adcs r5, r5, r11 */  —— r5 = (p1 == 该层索引) ? 1 : 0（差为 0 时 rsbs 置 C=1，adcs 把它加回来）
/* @0x1f3e30 cmp r0, r4 */
/* @0x1f3e34 cmpne r12, #0 */
/* @0x1f3e38 bne 0x1f3e1c <_Z17Variable_GetValueiiiP6RValue+0x13c> */
/* @0x1f3e3c cmp r5, #0 */
/* @0x1f3e40 beq 0x1f3e5c <_Z17Variable_GetValueiiiP6RValue+0x17c> */  —— r5==0 即不相等 → 下一个实例（与段 3 的 r5 语义相反：那边 1=命中）
/* @0x1f3e44 ldrb r12, [r8, #0x68] */
/* @0x1f3e48 cmp r12, #0 */
/* @0x1f3e4c bne 0x1f3e5c <_Z17Variable_GetValueiiiP6RValue+0x17c> */  —— → 下一个
/* @0x1f3e50 ldrb r12, [r8, #0x69] */
/* @0x1f3e54 cmp r12, #0 */
/* @0x1f3e58 beq 0x1f3f64 <_Z17Variable_GetValueiiiP6RValue+0x284> */  —— 两标志皆 0 → 命中，r8 交 Direct
/* @0x1f3e5c add r6, r6, #1 */  —— ++i
/* @0x1f3e60 cmp r6, r10 */
/* @0x1f3e64 bne 0x1f3e08 <_Z17Variable_GetValueiiiP6RValue+0x128> */
/* ═══ 段 5 · 失败出口（0x1f3e68..0x1f3e78）═══ */
/* @0x1f3e68 mov r3, #1 */  —— 1：标志值
/* @0x1f3e6c mov r0, #0 */  —— 0：返回值
/* @0x1f3e70 strb r3, [r7] */  —— ★ 0x75505c = 1（本次调用失败）
/* @0x1f3e74 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x1f3e78 bx lr */  —— 全函数唯一 bx lr：返回 0，**out 未写**
/* ═══ 段 6 · 对象索引分支（0 ≤ p1 ≤ 99999）：g_ObjectHash → CObjectGM → 实例链（0x1f3e7c..0x1f3f08）═══
 *   注意与段 2 的差别：这里 GOT 槽里放的是**指针变量** 0x542374，所以要多解一次引用。 */
/* @0x1f3e7c ldr r12, [pc, #0x100] */  —— 池 0x1f3f84 = 0xffffbfec = -0x4014
/* @0x1f3e80 ldr r12, [r6, r12] */  —— r12 = 0x542374 —— .bss 里的**指针变量** g_ObjectHash
/* @0x1f3e84 ldr r12, [r12] */  —— ★ 第二次解引用才到 {+0 buckets, +4 mask, +8 count}（ms_ID2InstanceE 没有这一步）
/* @0x1f3e88 ldr r4, [r12, #0x4] */  —— mask
/* @0x1f3e8c ldr r12, [r12] */  —— buckets
/* @0x1f3e90 and r4, r0, r4 */  —— idx = p1 & mask
/* @0x1f3e94 ldr r12, [r12, r4, lsl #3] */  —— bucket 头
/* @0x1f3e98 cmp r12, #0 */
/* @0x1f3e9c bne 0x1f3eb0 <_Z17Variable_GetValueiiiP6RValue+0x1d0> */  —— 非空 → 比 key
/* @0x1f3ea0 b 0x1f3d78 <_Z17Variable_GetValueiiiP6RValue+0x98> */  —— 未命中 → 退化扫描 1
/* @0x1f3ea4 ldr r12, [r12, #0x4] */  —— next（+4）
/* @0x1f3ea8 cmp r12, #0 */
/* @0x1f3eac beq 0x1f3d78 <_Z17Variable_GetValueiiiP6RValue+0x98> */  —— 链尾 → 退化扫描 1
/* @0x1f3eb0 ldr r4, [r12, #0x8] */  —— key = 对象索引
/* @0x1f3eb4 cmp r0, r4 */
/* @0x1f3eb8 bne 0x1f3ea4 <_Z17Variable_GetValueiiiP6RValue+0x1c4> */  —— 撞桶 → 继续
/* @0x1f3ebc ldr r12, [r12, #0xc] */  —— value = CObjectGM*
/* @0x1f3ec0 cmp r12, #0 */
/* @0x1f3ec4 ldrne r12, [r12, #0xd0] */  —— obj->[0xd0] = 实例双向链表头（AddInstance 0x19e02c 建：头/尾 +0xd0/+0xd4、计数 +0xd8、节点 12 B {+0 next,+4 prev,+8 inst}）
/* @0x1f3ec8 beq 0x1f3d78 <_Z17Variable_GetValueiiiP6RValue+0x98> */  —— 无对象 → 退化扫描
/* @0x1f3ecc cmp r12, #0 */
/* @0x1f3ed0 beq 0x1f3d78 <_Z17Variable_GetValueiiiP6RValue+0x98> */  —— 无实例 → 退化扫描（不是失败）
/* @0x1f3ed4 ldr r4, [r12, #0x8] */  —— node->inst
/* @0x1f3ed8 cmp r4, #0 */
/* @0x1f3edc beq 0x1f3d78 <_Z17Variable_GetValueiiiP6RValue+0x98> */  —— 空节点 → 退化扫描
/* @0x1f3ee0 ldr r4, [r12, #0x8] */  —— 重取（上一份结果已被 0x1f3ed8 的比较消费）
/* @0x1f3ee4 ldr r12, [r12] */  —— node = node->next（+0）
/* @0x1f3ee8 ldrb r5, [r4, #0x68] */
/* @0x1f3eec cmp r5, #0 */
/* @0x1f3ef0 bne 0x1f3ecc <_Z17Variable_GetValueiiiP6RValue+0x1ec> */  —— skip → 下一个节点
/* @0x1f3ef4 ldrb r5, [r4, #0x69] */
/* @0x1f3ef8 cmp r5, #0 */
/* @0x1f3efc bne 0x1f3ecc <_Z17Variable_GetValueiiiP6RValue+0x1ec> */  —— deactivated → 下一个节点
/* @0x1f3f00 mov r0, r4 */  —— r0 = 实例
/* @0x1f3f04 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x1f3f08 b 0x1f3b8c <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue> */  —— 尾跳 Direct
/* ═══ 段 7 · all 分支（p1 == -3）：房间实例链第一个活实例（0x1f3f0c..0x1f3f54）═══ */
/* @0x1f3f0c ldr r0, [pc, #0x74] */  —— 池 0x1f3f88 = 0xffffbcd8 = -0x4328
/* @0x1f3f10 ldr r0, [r6, r0] */  —— r0 = 0x54298c = Run_Room（指针变量；live-mem 实测 = 0xeafc63e0）
/* @0x1f3f14 ldr r0, [r0] */  —— CRoom*
/* @0x1f3f18 ldr r0, [r0, #0x80] */  —— 房间实例链头（RelinkObjectTypes 0x192c24 在空链时写这里；尾在 +0x84）
/* @0x1f3f1c cmp r0, r4 */  —— r4 仍是入口的 0
/* @0x1f3f20 bne 0x1f3f34 <_Z17Variable_GetValueiiiP6RValue+0x254> */  —— 非空 → 进判定循环
/* @0x1f3f24 b 0x1f3e68 <_Z17Variable_GetValueiiiP6RValue+0x188> */  —— 空房间 → 失败
/* @0x1f3f28 cmp r12, #0 */  —— r12 = 上一条已取好的 next
/* @0x1f3f2c mov r0, r12 */  —— r0 = next
/* @0x1f3f30 beq 0x1f3e68 <_Z17Variable_GetValueiiiP6RValue+0x188> */  —— 链尾 → 失败
/* @0x1f3f34 ldrb r4, [r0, #0x68] */
/* @0x1f3f38 ldr r12, [r0, #0x178] */  —— ★ 先取 next 再判存活（允许判定期间实例被摘链）
/* @0x1f3f3c cmp r4, #0 */
/* @0x1f3f40 bne 0x1f3f28 <_Z17Variable_GetValueiiiP6RValue+0x248> */  —— skip → 前进
/* @0x1f3f44 ldrb r4, [r0, #0x69] */
/* @0x1f3f48 cmp r4, #0 */
/* @0x1f3f4c bne 0x1f3f28 <_Z17Variable_GetValueiiiP6RValue+0x248> */  —— deactivated → 前进
/* @0x1f3f50 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x1f3f54 b 0x1f3b8c <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue> */  —— 命中：链上**第一个**活实例（链按 depth 升序，depth 在 +0x180）
/* ═══ 段 8 · 两处退化扫描的命中出口（0x1f3f58..0x1f3f6c）═══ */
/* @0x1f3f58 mov r0, r9 */  —— 列表 1 的命中实例
/* @0x1f3f5c pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x1f3f60 b 0x1f3b8c <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue> */  —— 尾跳 Direct
/* @0x1f3f64 mov r0, r8 */  —— 列表 2 的命中实例
/* @0x1f3f68 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x1f3f6c b 0x1f3b8c <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue> */  —— 尾跳 Direct
/* ═══ 段 9 · 字面量池（0x1f3f70..0x1f3f88，7 个字；0x1f3f70 被反汇编器当指令显示，非指令）═══ */
/* @0x1f3f70 andseq sp, pc, r12, asr pc */  —— 池：GOT 相对偏移 0x001fdf5c（0x1f3cf4 消费）
/* @0x1f3f74 .word 0xffffc110 */  —— 池：-0x3ef0 → 失败标志槽 0x3edd68
/* @0x1f3f78 .word 0xffffbff4 */  —— 池：-0x400c → ms_ID2InstanceE 槽 0x3edc4c
/* @0x1f3f7c .word 0xffffbff0 */  —— 池：-0x4010 → 列表 1 槽 0x3edc48
/* @0x1f3f80 .word 0xffffbff8 */  —— 池：-0x4008 → 列表 2 槽 0x3edc50
/* @0x1f3f84 .word 0xffffbfec */  —— 池：-0x4014 → g_ObjectHash 槽 0x3edc44
/* @0x1f3f88 .word 0xffffbcd8 */  —— 池：-0x4328 → Run_Room 槽 0x3ed930
