/* cally 逆向卡：Command_Change（原版 libyoyo.so，armv7）
 * @func 0x1c9bb4 0x1c9c88  size 212  53 条（52 条指令 + 末字 1c9c84 为 literal pool 一个字）
 * 级别: 正文（52/52 逐条落锚；三条前置闸、四个出口、四次事件派发、错误串的实参链全部定位；
 *       字段 +0x7c/+0x6a 与事件号 1/12/14/0 的名字依赖跨卡，逐条注明出处）
 * 符号: _Z14Command_ChangeP9CInstanceib → void Command_Change(CInstance* inst, int objindex, bool perform_events)
 * 位置: 紧跟 Command_Destroy(0x1c9b54) 之后（中间只隔 1c9bb0 一个池字）；其后 Command_DestroyAt(0x1c9c88)、
 *       Command_ChangeAt(0x1c9cf8)
 * 调用者: 全 .text 精确 5 处（扫全部 B/BL 编码：1 bl + 4 b）——
 *       F_InstanceChange 109974（b，GML instance_change 的内建体）、
 *       YYGML_instance_change 10b248（dynsym size=4 的 thunk，b）、
 *       F_ActionChangeObject 13e50c（b，DnD 的 Change Object）、
 *       YYGML_action_change_object 141a94（thunk，b）、
 *       Command_ChangeAt 1c9d74（bl：按坐标找实例后逐个复用本函数）
 * 同层: Object_Exists 0x19ecf8、CInstance::ChangeObjectIndex 0x193368、Perform_Event 0xf3380
 *       （→ Perform_Event_Object 0xf32e4）、Error_Show_Action 0xecf70、无符号拼接器 0x1c8380
 * 尾注: Command_EndGame 0x1c9f50（4 字节、只有一条 bx lr）不单独建卡 —— 见文末「附注」一节。
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   把 inst 换成另一个对象：目标对象必须存在（否则组一条错误串交给 Error_Show_Action）；
 *   目标与当前对象索引相同就直接返回；perform_events 为假只改索引；为真时先（若实例还没进销毁
 *   流程）派 Destroy(1)+CleanUp(12)，再改索引，再派 PreCreate(14)，最后以尾调派 Create(0)。
 *   除 ChangeObjectIndex 与这四次事件外，本函数不写任何字段、不碰任何全局。
 *
 * ── 语义草案 ───────────────────────────────────────────────────
 *   void Command_Change(CInstance* inst, int objindex, bool perform_events) {
 *     if (!Object_Exists(objindex)) {                        // 1c9bc8..1c9bd0
 *        Error_Show_Action(Splice("Asking to change into non-existing object: ", objindex), false);
 *        return;                                             // 1c9c3c..1c9c54（尾跳）
 *     }
 *     if (inst->[0x7c] == objindex) return;                  // 1c9bd4..1c9bdc（popeq）
 *     if (!perform_events) {                                 // 1c9be0..1c9be4
 *        inst->ChangeObjectIndex(objindex);                  // 1c9c2c..1c9c38（尾跳）
 *        return;
 *     }
 *     if (inst->[0x6a]（destroying）== 0) {                    // 1c9be8..1c9bf0
 *        Perform_Event(inst, inst, 1, 0);                    // 1c9c58..1c9c68  = Destroy
 *        Perform_Event(inst, inst, 12, 0);                   // 1c9c6c..1c9c7c = CleanUp
 *     }                                                      // 1c9c80 回 1c9bf4
 *     inst->ChangeObjectIndex(objindex);                     // 1c9bf4..1c9bfc
 *     Perform_Event(inst, inst, 14, 0);                      // 1c9c00..1c9c10 = PreCreate
 *     Perform_Event(inst, inst, 0, 0);                       // 1c9c14..1c9c28 = Create（尾调）
 *   }
 *
 * ── 门表（按执行顺序；本卡全部实测）────────────────────────────
 *   ① Object_Exists(objindex) ？                          1c9bc8..1c9bd0
 *        否 → 错误出口：组串 + Error_Show_Action(串,0)；不派事件、不改索引
 *   ② inst->[0x7c] == objindex ？                         1c9bd4..1c9bdc
 *        是 → 直接返回（连 perform_events 都不看）
 *   ③ perform_events == 0 ？                              1c9be0..1c9be4
 *        是 → 尾调 ChangeObjectIndex，零事件
 *   ④ inst->[0x6a] == 0 ？                                1c9be8..1c9bf0
 *        否（已在销毁流程里）→ 跳过 Destroy/CleanUp 这一对
 *   ⇒ 过了 ④ 之后恒为 ChangeObjectIndex → 14 → 0；只有 ④ 决定 1/12 跑不跑。
 *   ⇒ 事件号顺序 1、12、14、0 与 StartRoom 卡「14 在 0 之前 ⇒ 14=PreCreate」互证。
 *
 * ── 字段表（本函数真正读写的；名字凡未在本卡证过的都标出处）────────
 *   CInstance
 *     +0x7c  int   object_index   读于 1c9bd4（同索引短路）；写入在 ChangeObjectIndex 里
 *     +0x6a  byte  destroying     读于 1c9be8；语义名与全库唯一置位者见 Command_Destroy 卡（1c9b70）
 *   全局: 无。本函数没有一条全局读写指令（错误串与码表都在被调函数里）。
 *   写集: 无直接写。本函数的所有 ldr/ldrb 只有 1c9bd4、1c9be8、1c9c3c 三处。
 *
 * ── 已证（指令级）─────────────────────────────────────────────
 *  1. 实参落位且没有 inst 空指针闸：1c9bb4 push {r4-r8,lr}（r8 压进去却全程未读写）；
 *     1c9bb8 r4=inst、1c9bbc 把 r1 摆进 r0 交给 Object_Exists、1c9bc0 r5=objindex、1c9bc4 r6=perform_events。
 *     inst 之后只在 1c9bd4、1c9be8 被解引用（都经 r4）⇒ inst 为空且 objindex 存在时会崩。
 *  2. Object_Exists 的返回值只服务两个分支：1c9bcc subs r7,r0,#0 把结果留在 r7（错误出口拿它当
 *     Error_Show_Action 的第 2 实参 = 0）；1c9bd0 beq 跳错误块。
 *  3. 错误出口的实参链（本卡最容易算错的一处：同一段里两个 PC 基准差 8）：
 *     · 1c9c3c ldr r0,[pc,#0x40] 的 PC = 1c9c44 ⇒ 取池字 1c9c84 = 0x00186fcc；
 *     · 1c9c44 add r0,pc,r0 的 PC = 1c9c4c ⇒ 串址 = 1c9c4c + 0x186fcc = 0x350c18；
 *     · 0x350c18 实测 = "Asking to change into non-existing object: "（紧邻的前一串在 0x350bf0：
 *       " specified layer \"%s\" does not exist" —— 两者同处一个错误串池）；
 *     · 1c9c40 mov r1,r5 把 objindex 当第 2 实参，1c9c48 bl 0x1c8380 = 无 dynsym 的拼接器
 *       （形状：strcpy 到 .bss 0x53f6b4 → strlen → _itoa(base 10) → 返回缓冲），返回值就是第 1 实参；
 *     · 1c9c4c mov r1,r7（=0）→ 1c9c50 pop 干净 → 1c9c54 b Error_Show_Action（尾跳，不回来）。
 *     若按「统一 PC+8」去算 add，会得到 0x350c10 = 串中段的 "xist"，是错的。
 *  4. 同索引短路优先于 perf 门：1c9bd4 ldr r3,[r4,#0x7c] / 1c9bd8 cmp r5,r3 / 1c9bdc popeq ⇒
 *     instance_change(当前对象, true) 也是零事件、零写入。
 *  5. perf 门是干净二分：1c9be0 cmp r6,#0 / 1c9be4 beq 1c9c2c；1c9c2c..1c9c38 只有四条
 *     （mov r0,r4 / mov r1,r5 / pop / b ChangeObjectIndex）⇒ 关事件时是长跳尾调，不吃本函数栈帧。
 *  6. 销毁闸 +0x6a：1c9be8 ldrb r6,[r4,#0x6a] / 1c9bec cmp r6,#0 / 1c9bf0 beq 1c9c58，
 *     只有 ==0 才去派 1/12；派完 1c9c80 b 1c9bf4 汇合。注意 r6 在这条 ldrb 之后不再代表
 *     perform_events（值恒 0），并且被后面两次 Perform_Event 直接当 num（1c9c60 / 1c9c74 mov r3,r6）。
 *     ⇒ 「已销毁的实例再换对象」不会重复派 Destroy/CleanUp（Command_Destroy 已把 +0x6a 置 1）。
 *  7. 事件序与四个调用点的实参：1/12 在改索引之前，14/0 在之后；四个调用点 r1 恒 = r4（other=inst）、
 *     num 恒 0（1c9c0c mov r3,#0；1c9c14..1c9c20 mov r2,#0 / mov r3,r2）⇒ 本函数从不给事件传子号。
 *     1/12/14 是 bl，0 是 b（1c9c24 pop / 1c9c28 b）—— 0 号事件就是返回路径，r0 留着 Perform_Event 的
 *     残值，调用者不得当返回值用。
 *  8. 控制转移共 10 条：6 bl（Object_Exists 1c9bc8、ChangeObjectIndex 1c9bfc、Perform_Event 1c9c10 /
 *     1c9c68 / 1c9c7c、拼接器 1c9c48）+ 4 b（Perform_Event 1c9c28、ChangeObjectIndex 1c9c38、
 *     Error_Show_Action 1c9c54、回汇合点 1c9c80）。四个出口（1c9bdc / 1c9c24-1c9c28 / 1c9c34-1c9c38 /
 *     1c9c50-1c9c54）都先把本函数压的寄存器弹干净再走，没有半开栈帧。
 *  9. GML 侧签名（跨函数，只给地址不给锚点）：F_InstanceChange 10993c 用 YYGetInt32(args,0) 与
 *     YYGetBool(args,1) 分别填 r1/r2、r0 用 self ⇒ instance_change(obj, perf)；F_ActionChangeObject
 *     13e4d4 四条指令同构 ⇒ DnD 的 Change Object 同签名；两个 YYGML_* thunk（10b248 / 141a94）
 *     就是「一条 b 到本函数」的跳板。
 *
 * ── open ────────────────────────────────────────────────────────────────
 *  · 1c8380 无 dynsym 名：只证形状（strcpy 到 0x53f6b4 静态缓冲、strlen、_itoa base 10、返回缓冲），
 *    不证它的官方名，也不证它可重入（全库共用同一块 .bss 缓冲）。
 *  · +0x6a 的语义名 destroying 来自 Command_Destroy 卡；本卡只证「非 0 → 不派 1/12」。
 *  · 事件号 1/12/14/0 的名字来自 GM 惯例 + Command_Destroy / StartRoom / DoDestroy 卡；
 *    本二进制没有事件名表可对。
 *  · Error_Show_Action 的第 2 实参（恒 0）语义未证（可能是「非致命」或「带栈」开关）。
 *  · objindex 为负或超界时 Object_Exists 的行为不在本卡范围（本函数不做符号检查，直接下传）。
 *  · inst 为空指针时本函数会解引用（无闸）；谁可能传空未定位。
 *
 * ── 逐条锚点 ─────────────────────────────────────────────────────────────
 */

/* ── 1. 入口：三实参落位，objindex 立刻交给 Object_Exists（1c9bb4..1c9bc8）──────────
 *    push 了 r8 却全程不读写；r0 到 1c9bbc 就被 objindex 覆盖，inst 只活在 r4 里。
 */

/* @0x1c9bb4 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c9bb8 mov r4, r0 */
/* @0x1c9bbc mov r0, r1 */
/* @0x1c9bc0 mov r5, r1 */
/* @0x1c9bc4 mov r6, r2 */
/* @0x1c9bc8 bl 0x19ecf8 <_Z13Object_Existsi> */

/* ── 2. 存在门：subs 把结果留在 r7（错误出口的第 2 实参），beq 进错误块（1c9bcc..1c9bd0）── */

/* @0x1c9bcc subs r7, r0, #0 */
/* @0x1c9bd0 beq 0x1c9c3c <_Z14Command_ChangeP9CInstanceib+0x88> */

/* ── 3. 同索引短路：inst->[0x7c] == objindex 就地返回，连 perf 都不看（1c9bd4..1c9bdc）─── */

/* @0x1c9bd4 ldr r3, [r4, #0x7c] */
/* @0x1c9bd8 cmp r5, r3 */
/* @0x1c9bdc popeq {r4, r5, r6, r7, r8, pc} */

/* ── 4. perf 门：为假 → 尾调 ChangeObjectIndex（目标在 1c9c2c）──────────────────── */

/* @0x1c9be0 cmp r6, #0 */
/* @0x1c9be4 beq 0x1c9c2c <_Z14Command_ChangeP9CInstanceib+0x78> */

/* ── 5. 销毁闸：+0x6a 非 0（已在销毁流程）就跳过 1/12，直接去汇合点 1c9bf4 ──────────── */

/* @0x1c9be8 ldrb r6, [r4, #0x6a] */
/* @0x1c9bec cmp r6, #0 */
/* @0x1c9bf0 beq 0x1c9c58 <_Z14Command_ChangeP9CInstanceib+0xa4> */

/* ── 6. 汇合点：改对象索引，再派 PreCreate(14) ─────────────────────────────────── */

/* @0x1c9bf4 mov r1, r5 */
/* @0x1c9bf8 mov r0, r4 */
/* @0x1c9bfc bl 0x193368 <_ZN9CInstance17ChangeObjectIndexEi> */
/* @0x1c9c00 mov r0, r4 */
/* @0x1c9c04 mov r1, r4 */
/* @0x1c9c08 mov r2, #14 */
/* @0x1c9c0c mov r3, #0 */
/* @0x1c9c10 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */

/* ── 7. Create(0) 走尾调：先弹干净再 b（r2=r3=0）─────────────────────────────────── */

/* @0x1c9c14 mov r2, #0 */
/* @0x1c9c18 mov r0, r4 */
/* @0x1c9c1c mov r1, r4 */
/* @0x1c9c20 mov r3, r2 */
/* @0x1c9c24 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1c9c28 b 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */

/* ── 8. perf==0 出口：同样先弹再尾调 ChangeObjectIndex ──────────────────────────── */

/* @0x1c9c2c mov r0, r4 */
/* @0x1c9c30 mov r1, r5 */
/* @0x1c9c34 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1c9c38 b 0x193368 <_ZN9CInstance17ChangeObjectIndexEi> */

/* ── 9. 错误出口：取池字 → 串址 0x350c18（注意 add 的 PC 基准）→ 拼接 → 尾跳显示 ──────
 *    1c9c3c 的池字在 1c9c84；1c9c44 的 add 用 PC=1c9c4c 才是串起点。
 *    1c9c48 的 bl 目标 0x1c8380 在 objdump 里印成 <DeSerializeLayer+0xeb0>，那是「最近前一个
 *    符号」的标注假象（该地址没有 dynsym 名）；同址被 Command_SetSprite 1c9df4、Command_ChangeAt
 *    1c9d90、Command_GotoRoom 1c9e40 等错误路径共用。
 */

/* @0x1c9c3c ldr r0, [pc, #0x40] */
/* @0x1c9c40 mov r1, r5 */
/* @0x1c9c44 add r0, pc, r0 */
/* @0x1c9c48 bl 0x1c8380 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xeb0> */
/* @0x1c9c4c mov r1, r7 */
/* @0x1c9c50 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1c9c54 b 0xecf70 <_Z17Error_Show_ActionPKcb> */

/* ── 10. Destroy(1) / CleanUp(12) 这一对：只有 +0x6a==0 才落地，跑完回 1c9bf4（1c9c58..1c9c80）── */

/* @0x1c9c58 mov r0, r4 */
/* @0x1c9c5c mov r1, r4 */
/* @0x1c9c60 mov r3, r6 */
/* @0x1c9c64 mov r2, #1 */
/* @0x1c9c68 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c9c6c mov r0, r4 */
/* @0x1c9c70 mov r1, r4 */
/* @0x1c9c74 mov r3, r6 */
/* @0x1c9c78 mov r2, #12 */
/* @0x1c9c7c bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c9c80 b 0x1c9bf4 <_Z14Command_ChangeP9CInstanceib+0x40> */

/* ── literal pool 一字（非指令）：1c9c84 = 0x00186fcc ─────────────────────────────
 *   1c9c44 + 0x00186fcc = 0x350c18（错误串起点）；objdump 译成 andseq，非指令。
 */

/* @0x1c9c84 andseq r6, r8, r12, asr #31 */

/* ══ 附注：Command_EndGame 0x1c9f50（4 字节，同卡附注，不单独建文件）════════════════════
 *   形态: 0x1c9f50 一条 e12fff1e `bx lr` 就结束（dynsym 里 size 也是 4）。4 字节里没有栈帧、没有
 *         池字、没有一条 ldr/str、没有一次调用 ⇒ 被调到就等于「立刻返回」。
 *   调用者: 全 .text 精确 5 处，全是 b 尾跳、没有一处 bl ——
 *         F_GameEnd 109bfc（dynsym size=4 的 thunk）、YYGML_game_end 10c320（thunk）、
 *         F_ActionEndGame 13ec4c（thunk）、YYGML_action_end_game 141ca0（thunk）、
 *         DoAStep 1d35c0（帧循环里的「退出请求」分支）。
 *         前四个就是 GML 内建 game_end() 与 DnD「End Game」行动的全部入口；它们都先弹掉自己的帧
 *         再尾跳进来，所以 bx lr 回到的是最初调用者的返回点 —— 中间没有任何一层还能补副作用。
 *   结论: 这一层观察不到 EndGame 的任何效果：不置退出标志、不 exit、不报错、不动房间/全局。
 *         本 build 的 game_end() 因此是空操作；DoAStep 的「退出请求非 0」分支
 *         （1d35b4..1d35c0，读 0x544b98）与它上一条 1d35b8 的直接返回分支完全等价 ——
 *         两条分支都只弹同样的寄存器、r0 也都没被改（bx lr 不动 r0），返回点相同。
 *   对照: 紧随其后的 Command_RestartGame 1c9f54（208 字节）才是真干活的同族实现 —— 它把
 *         *(int*)0x542954（New_Room，GOT 槽 0x3eddac 实测）写成 -201，再读 0x5428e8（Zeus 字节，
 *         GOT 槽 0x3ed92c 实测）。两个相邻函数一个空、一个有状态写 ⇒ （推断）这个空实现是本 build
 *         里的实体实现，而不是链接期截断留下的半截函数（残迹通常会连 dynsym 的 size 一起缺）。
 *   open: 0x544b98 的写入者未定位（DoAStep 卡同 open）；是否有函数指针表间接指向 1c9f50 未穷举，
 *         但即使有，结论不变（仍然是一条 bx lr）。
 *   ⇒ 对重建方的约束: 不要把 Command_EndGame 实现成「退出进程」；本 build 里它是 return。
 */

/* 0x1c9f50: e12fff1e  bx lr      ← 不写成 @锚点：本函数不属于 index-Command_Change.tsv */
