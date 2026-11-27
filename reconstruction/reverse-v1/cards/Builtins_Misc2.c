/*
 * cally 逆向卡：游戏内建 API 第二批 14 个（原版 libyoyo.so，armv7）
 * 节: 14 个 @func 小节，顺序 = move_bounce_solid / move_bounce_all / room_goto / room_restart /
 *     audio_pause_all / audio_resume_all / audio_stop_all / draw_set_alpha / draw_set_color /
 *     draw_set_font / action_current_room / action_kill_object / draw_self / game_restart
 * 级别: 正文（81/81 逐条落锚 = 76 条指令 + 5 个池字；14 个函数的实参、门、转发目标、result 全解；
 *       两个「命令层」被调方（Command_Bounce 660 B、Command_GotoRoom 96 B）只到调用边界，列进 open）
 * 索引: asm/index-builtins_misc2_all.tsv（14 个函数按地址合并，81 行）
 *       逐函数索引 asm/index-F_*.tsv 也在库里（同 14 个函数，各是本文件的子集）；本卡只用合并索引校验。
 * 重叠: 0 —— 本卡 14 个区间与 cards/ 下任何既存卡无共享地址；也不与 Builtins_Misc1.c 交错。
 *
 * ── 统一签名（14 个一模一样）───────────────────────────────────────────────
 *   F_Xxx(RValue& result, CInstance* self, CInstance* other, int argc, RValue** args)
 *   r0 = &result、r1 = self、r2 = other、r3 = argc、[sp] = args。
 *   **14 个没有一条指令读 argc 或 other(r2)**；self(r1) 只在 4 个里出现（两个 move_bounce 的 mov r4,r1、
 *   action_kill_object 与 draw_self 的 mov r0,r1）。
 *   ⇒ **14/14 都不写 result**：8 个连 bl 都没有（room_restart、三个 audio、action_current_room、
 *      action_kill_object、draw_self、game_restart），6 个只 bl 一次 YYGet*（两个 move_bounce、room_goto、
 *      三个 draw_set），其余全是 `b` 尾跳。GML 侧这些内建一律得到 undefined。
 *   帧量只有两档：push {r3,lr}(8) 的（RoomGoto / 三个 DrawSet）与 push {r4,lr}(8) 的（两个 move_bounce），
 *   其余 8 个**没有栈帧**（直接 ldr/ldrb 后 b）。
 *
 * ── 尾跳清单（14/14 都是 `b`，不是 bl）──────────────────────────────────────
 *   move_bounce_solid 0x1083a0│move_bounce_all 0x1083c8│room_goto 0x109ad8│room_restart 0x109bf4│
 *   audio_pause_all 0x13363c│audio_resume_all 0x133658│audio_stop_all 0x133674│
 *   draw_set_alpha 0x11a9f0│draw_set_color 0x11a9d8│draw_set_font 0x11bd6c│
 *   action_current_room 0x13e6d4│action_kill_object 0x141afc│draw_self 0x123138│game_restart 0x109c00。
 *   ⇒ 这一批全是「薄封装 + 尾跳」，没有一个带返回值处理。
 *
 * ── room_* 与 New_Room 的衔接（本卡三个入口 + 一个 setter 全落到同一条命令层）────────────
 *   Command_GotoRoom 0x1c9e08（96 B = 24 字：21 条指令 + 3 个池字）逐条如下（旁证，无锚点）：
 *     *New_Room(0x542954) = room         // 0x1c9e20 str r0,[r4]，r4 由 GOT 0x3eddac 取
 *     *Transition_Kind(0x542950) = 0     // 0x1c9e24 str r2,[r3]，r2 在 0x1c9e0c 被置 0
 *     if (!Room_Exists(room)) {          // 0x1c9e28 bl 0x1b52f8 / 0x1c9e30 popne
 *         Error_Show_Action("Unexisting room number: ", 1);   // 0x350c70
 *         *New_Room = -400;              // 0x1c9e4c movw #0xfe70 + movt #0xffff
 *     }
 *   **第二实参 kind 是死参**：21 条指令里 r1 一次都没出现（入口值被 0x1c9e0c 的 r2=0 完全取代）。
 *     ⇒ F_RoomGoto 在 0x109ad0 读 *Transition_Kind 传进来、F_RoomRestart 在 0x109bf0 做同样的事，
 *       两次都被丢掉 —— 结果都是 Transition_Kind 被强制清 0，而不是保留调用前的值。
 *   F_RoomRestart 的目标不是常量：Command_CurrentRoom(0x1c9f38, 6 条) 读 *Current_Room(0x542958) 再进 GotoRoom，
 *     所以 room_restart() = room_goto(当前房间号)；它一个实参都不取。
 *   F_ActionCurrentRoom = Command_CurrentRoom(0) 的两条指令版 ⇒ 与 room_restart 同义（见 §11）。
 *   game_restart 走同一条通道的另一格：*New_Room = **-200**（0x1c9f64；mvn r1,#199 = 0xFFFFFF38），
 *     不是 -1 也不是某个房间号。
 *   消费端（不在本卡锚点内，地址已核）：SingleStep 0x1d4dd8 在 DoAStep 之后读 *New_Room：
 *     -1 → 无请求；-200 → Run_EndGame + GamePadRestart + StartGame + srand48(2101988)；
 *     -300 → LoadGame()；-100 / -400 → *(u8*)0x54297a(Run_Running) = 0 后返回；
 *     其余（0..N 与 -201 之类）→ SwitchRoom(idx) → EndRoom(0) + StartRoom(idx,0)，
 *     而 StartRoom 入口又把 *New_Room 写回 -1（cards/StartRoom.c）—— 一次换房到此闭合。
 *
 * ── 全局绘制状态（draw_set_* 三个写点）────────────────────────────────────
 *   Draw_Color 0x3f23d0（GOT 0x3edd04，初值 0xFF000000）、Draw_Alpha 0x3f23cc（GOT 0x3edd08，初值 0xFF）：
 *     draw_set_color  : Draw_Color = (arg & 0x00FFFFFF) | (Draw_Alpha << 24)   —— 不 clamp、不调函数
 *     draw_set_alpha  : b = clamp(arg·255)；Draw_Alpha = b；Draw_Color = GR_D3DColor_Change_Alpha(Draw_Color,b)
 *   Graphics_Text::fontid 0x3f2410（初值 -1，经 .data 0x3f02a8 的指针访问；deffont 0x48ffd8）：
 *     draw_set_font   : Font_Exists(font) ? fontid = font : (deffont==0 && MakeDefaultFont(), fontid = -1)
 *   ⇒ 三个内建都只写全局、不写 result；读侧不在本卡：Draw_Color 另有 10 个读点、Draw_Alpha 另有 5 个，
 *     全在 GR_Draw_* 家族（Set_Color3/4、Get_Color/Red/Green/Blue/D3DColor/Alpha、Circle/Ellipse/RoundRect/*_Ext）。
 *
 * ── 注册形态（14 个同一形状，已扫描证实）──────────────────────────────────
 *   14 个入口在 .text 里**没有任何 b/bl 指向**；.got(0x3ed718..0x3f2000) 里各恰有 1 个槽：
 *   MoveBounceSolid 0x3ee100｜MoveBounceAll 0x3ee104｜RoomGoto 0x3ee1f4｜RoomRestart 0x3ee208｜
 *   GameRestart 0x3ee210｜AudioPauseAll 0x3ef140｜AudioResumeAll 0x3ef144｜AudioStopAll 0x3ef190｜
 *   DrawSetAlpha 0x3ee708｜DrawSetColor 0x3ee704｜DrawSetFont 0x3ee81c｜ActionCurrentRoom 0x3ef490｜
 *   ActionKillObject 0x3ef45c｜DrawSelf 0x3ee85c。
 *
 * ── 逐条锚点（14 节）─────────────────────────────────────────────────────
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 1 · F_MoveBounceSolid（move_bounce_solid）
 * @func 0x10837c 0x1083b4  size 56  14 条（无池字）
 * 符号: _Z17F_MoveBounceSolidR6RValueP9CInstanceS2_iPS_
 * 一句话: adv=YYGetBool(args,0) → 尾跳 Command_Bounce(self, adv, **0**)；第三实参恒 0 = 用
 *         Command_IsFree 谓词。result 不写。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 1.1 帧 + 唯一实参（0x10837c..0x108394）───────────────────────────────
 *   push {r4,lr}(8) ⇒ args 在 [sp,#0x8]；r4=self；YYGetBool(args,0) 取 advanced。
 *   0x108390 `mov r2,#0` 是**本函数与 move_bounce_all 唯一不同的指令**。
 */
/* @0x10837c push {r4, lr} */
/* @0x108380 mov r4, r1 */
/* @0x108384 ldr r0, [sp, #0x8] */
/* @0x108388 mov r1, #0 */
/* @0x10838c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x108390 mov r2, #0 */
/* @0x108394 mov r1, r0 */
/*
 * ── 1.2 尾跳 Command_Bounce(self, adv, 0)（0x108398..0x1083a0）─────────────
 *   r1=adv、r2=0、r0=self；pop 后 `b 0x1cafa0`。result 一个字都不写（本函数连 &result 都没保存）。
 */
/* @0x108398 mov r0, r4 */
/* @0x10839c pop {r4, lr} */
/* @0x1083a0 b 0x1cafa0 <_Z14Command_BounceP9CInstancebb> */
/*
 * ── 1.3 「solid」落在哪（旁证 0x1caf90 Bounce_Test, 4 条）──────────────────────
 *   `cmp r3,#0` → **r3!=0** 走 Command_IsEmpty(0x1caa1c)，**r3==0** 走 Command_IsFree(0x1cab94)。
 *   两者的唯一判据差异：IsFree 在 0x1cacd8 多读一条 `ldrb r12,[r0,#0x66]`（+0x66 bit0 = solid，
 *   见 cards/CInstance_ctor.c 行 152），只把 solid 实例算障碍；IsEmpty 不看 +0x66，任何实例都算。
 *   ⇒ solid 变体传 0 → 只撞 solid；all 变体传 1 → 撞所有。
 *   advanced 位只决定 Command_Bounce 内部走「四向翻转」还是「35 步角度扫描」（详见证 Builtins_Misc1 §3.3）。
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 2 · F_MoveBounceAll（move_bounce_all）
 * @func 0x1083a4 0x1083cc  size 40  10 条（无池字）
 * 符号: _Z15F_MoveBounceAllR6RValueP9CInstanceS2_iPS_
 * 一句话: adv=YYGetBool(args,0) → 尾跳 Command_Bounce(self, adv, **1**)；第三实参恒 1 = 用
 *         Command_IsEmpty 谓词。result 不写。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 2.1 帧 + 唯一实参（0x1083a4..0x1083bc）───────────────────────────────
 *   与节 1 逐指令同构，只有 0x1083b8 的 `mov r2,#1`。两函数相差 0x28 字节，且都在 0x1083xx 一段。
 */
/* @0x1083a4 push {r4, lr} */
/* @0x1083a8 mov r4, r1 */
/* @0x1083ac ldr r0, [sp, #0x8] */
/* @0x1083b0 mov r1, #0 */
/* @0x1083b4 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1083b8 mov r2, #1 */
/* @0x1083bc mov r1, r0 */
/*
 * ── 2.2 尾跳 Command_Bounce(self, adv, 1)（0x1083c0..0x1083c8）─────────────
 *   pop 后 `b 0x1cafa0`。
 *   ⇒ 两个内建的 GML 签名都只有 1 个 bool（advanced），「solid/all」不是参数而是**写死的第三实参**；
 *     唯一把第三实参暴露给 GML 的是 Builtins_Misc1 的 action_bounce。
 */
/* @0x1083c0 mov r0, r4 */
/* @0x1083c4 pop {r4, lr} */
/* @0x1083c8 b 0x1cafa0 <_Z14Command_BounceP9CInstancebb> */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 3 · F_RoomGoto（room_goto）
 * @func 0x109ab8 0x109ae0  size 40  10 条（9 条指令 + 1 个池字 0x109adc）
 * 符号: _Z10F_RoomGotoR6RValueP9CInstanceS2_iPS_
 * 一句话: room=YYGetInt32(args,0)、kind=*Transition_Kind → 尾跳 Command_GotoRoom(room,kind)；
 *         kind 在命令层是死参（被强制清 0）。result 不写。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 3.1 帧 + 取房间号（0x109ab8..0x109ac4）───────────────────────────────
 *   push {r3,lr}(8) ⇒ args [sp,#0x8]；mov r1,#0 + ldr r0,[sp,#8] + bl YYGetInt32 ⇒ room 在 r0。
 */
/* @0x109ab8 push {r3, lr} */
/* @0x109abc mov r1, #0 */
/* @0x109ac0 ldr r0, [sp, #0x8] */
/* @0x109ac4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/*
 * ── 3.2 第二实参来自全局 *Transition_Kind（0x109ac8..0x109ad4 + 池字）───────────
 *   池字 0x109adc = 0x002e45dc；0x109acc `ldr r3,[pc,r3]` 的 PC=0x109ad4 ⇒ 槽 = 0x109ad4+0x2e45dc
 *   = **0x3ee0b0** → 0x542950 = Transition_Kind。0x109ad0 `ldr r1,[r3]` 取出当前值当第二实参。
 */
/* @0x109ac8 ldr r3, [pc, #0xc] */
/* @0x109acc ldr r3, [pc, r3] */
/* @0x109ad0 ldr r1, [r3] */
/* @0x109ad4 pop {r3, lr} */
/*
 * ── 3.3 尾跳 + 池字（0x109ad8 / 0x109adc）──────────────────────────────────
 *   pop 后 `b 0x1c9e08 Command_GotoRoom(room, *Transition_Kind)`；池字按 objdump 写法保留（eoreq = 非指令）。
 *   **命令层把这个第二实参丢掉了**（0x1c9e0c 用 r2=0 覆盖，之后只写 r0/r2 两个全局）⇒
 *   room_goto 的真实效果是：New_Room = room、Transition_Kind = **0**、Room_Exists 门、无效房间 →
 *   Error_Show_Action("Unexisting room number: ",1) 且 New_Room = -400（详见证头部「room_* 与 New_Room」）。
 */
/* @0x109ad8 b 0x1c9e08 <_Z16Command_GotoRoomii> */
/* @0x109adc .word 0x002e45dc */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 4 · F_RoomRestart（room_restart）
 * @func 0x109be8 0x109bfc  size 20  5 条（4 条指令 + 1 个池字 0x109bf8）
 * 符号: _Z13F_RoomRestartR6RValueP9CInstanceS2_iPS_
 * 一句话: 读 *Transition_Kind 当实参 → 尾跳 Command_CurrentRoom(kind)；后者取 *Current_Room 再进 Command_GotoRoom。
 *         **不取任何 GML 实参、不写 result、没有栈帧**。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 4.1 三条 ldr + 一条 b（0x109be8..0x109bf4）─────────────────────────────
 *   池字 0x109bf8 = 0x002e44bc；0x109bec `ldr r3,[pc,r3]` 的 PC=0x109bf4 ⇒ 槽 = 0x109bf4+0x2e44bc
 *   = **0x3ee0b0**（与 room_goto 同一槽）。0x109bf0 ldr r0,[r3] 取 *Transition_Kind，0x109bf4 直接 b。
 */
/* @0x109be8 ldr r3, [pc, #0x8] */
/* @0x109bec ldr r3, [pc, r3] */
/* @0x109bf0 ldr r0, [r3] */
/* @0x109bf4 b 0x1c9f38 <_Z19Command_CurrentRoomi> */
/*
 * ── 4.2 池字（0x109bf8，非指令）─────────────────────────────────────────────
 *   = 0x002e44bc，objdump 记作 .word；它是 0x109bec 那条 ldr 的字面。
 */
/* @0x109bf8 .word 0x002e44bc */
/*
 * ── 4.3 为什么「重启当前房」不需要实参（旁证 0x1c9f38, 6 条）──────────────────
 *   Command_CurrentRoom(int)：r3 = &Current_Room(0x542958，GOT 0x3ef3dc)；r1 = 入参；
 *   r0 = *Current_Room；`b Command_GotoRoom` ⇒ 目标恒为当前房间号。
 *   本函数传进去的 *Transition_Kind 只占 r1 的位置，而 Command_GotoRoom 不读 r1。
 *   ⇒ room_restart() 的真实语义：New_Room = *Current_Room、Transition_Kind = 0、再过一次 Room_Exists 门；
 *     与 room_goto(room) 写的是同一个变量，区别只在「房间号从哪来」。
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 5 · F_AudioPauseAll（audio_pause_all）
 * @func 0x133628 0x133654  size 44  11 条（6 条指令 + 1 个池字 0x133640）
 * 符号: _Z15F_AudioPauseAllR6RValueP9CInstanceS2_iPS_
 * 一句话: g_fNoAudio 门（非 0 直接返回）→ 尾跳 Audio_PauseAll()。无实参、无栈帧、不写 result。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 5.1 门 + 尾跳（0x133628..0x13363c）───────────────────────────────────
 *   池字 0x133640 = 0x002bba20；0x13362c `ldr r3,[pc,r3]` 的 PC=0x133634 ⇒ 槽 = 0x3ef054 → **0x755363**
 *   = g_fNoAudio。ldrb + cmp + `bxne lr` ⇒ 门非 0 时整个内建是空操作。
 *   注意这里用的是 **bx lr 而不是 pop**（本函数没有栈帧），所以门命中时连返回地址都不动。
 */
/* @0x133628 ldr r3, [pc, #0x10] */
/* @0x13362c ldr r3, [pc, r3] */
/* @0x133630 ldrb r3, [r3] */
/* @0x133634 cmp r3, #0 */
/* @0x133638 bxne lr */
/* @0x13363c b 0x217c48 <_Z14Audio_PauseAllv> */
/*
 * ── 5.2 池字（0x133640，非指令）───────────────────────────────────────────
 */
/* @0x133640 eoreq r11, r11, r0, lsr #20 */
/*
 * ── 5.3 被调方（旁证 0x217c48, 168 B）──────────────────────────────────────
 *   Audio_PauseAll() 自己再查两道门：g_fNoAudio(0x217c4c) 与 g_UseNewAudio(0x755314, 0x217c60)，任一不满足即返回
 *   ⇒ wrapper 那道门只省了一次函数调用，旧后端（g_UseNewAudio==0）下这里仍然什么都不做。
 *   然后遍历 CNoise 池（0x75529c：+0x38 count / +0x3c items），对每个 items[i] != 0 且
 *   noise+0x5 != 0 的节点调 Audio_PauseSoundNoise(noise)（0x217cd4）——**只暂停 +0x5 标记过的**。
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 6 · F_AudioResumeAll（audio_resume_all）
 * @func 0x133644 0x133670  size 44  11 条（6 条指令 + 1 个池字 0x13365c）
 * 符号: _Z16F_AudioResumeAllR6RValueP9CInstanceS2_iPS_
 * 一句话: 与 audio_pause_all 逐指令同构，只把尾跳目标换成 Audio_ResumeAll()。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 6.1 门 + 尾跳（0x133644..0x133658）───────────────────────────────────
 *   池字 0x13365c = 0x002bba04；PC=0x133650 ⇒ 同一个槽 0x3ef054 → g_fNoAudio。
 *   ⇒ 三个 audio_*_all 与 audio_stop_sound 用的是**同一道门**（0x755363），只是各自带一份池字。
 */
/* @0x133644 ldr r3, [pc, #0x10] */
/* @0x133648 ldr r3, [pc, r3] */
/* @0x13364c ldrb r3, [r3] */
/* @0x133650 cmp r3, #0 */
/* @0x133654 bxne lr */
/* @0x133658 b 0x217df4 <_Z15Audio_ResumeAllv> */
/*
 * ── 6.2 池字（0x13365c，非指令）───────────────────────────────────────────
 */
/* @0x13365c eoreq r11, r11, r4, lsl #20 */
/*
 * ── 6.3 被调方差异（旁证 0x217df4, 168 B）───────────────────────────────────
 *   与 PauseAll 只在最后一条 bl 上不同：0x217e80 → Audio_ResumeSoundNoise(noise)（PauseAll 是 0x217cd4）。
 *   两道门、CNoise 池、+0x5 筛选、循环结构全部逐字相同。
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 7 · F_AudioStopAll（audio_stop_all）
 * @func 0x133660 0x13367c  size 28  7 条（6 条指令 + 1 个池字 0x133678）
 * 符号: _Z14F_AudioStopAllR6RValueP9CInstanceS2_iPS_
 * 一句话: g_fNoAudio 门 → 尾跳 Audio_StopAll(**门字节**)。注意 r0 没有显式置参，它是 0x133668 的 ldrb 结果。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 7.1 门 + 尾跳（0x133660..0x133674）───────────────────────────────────
 *   池字 0x133678 = 0x002bb9e8；PC=0x13366c ⇒ 槽 0x3ef054 → g_fNoAudio。
 *   ★ 与 PauseAll/ResumeAll 的唯一结构差异：ldrb 的目标是 **r0**（不是 r3）—— 因为 Audio_StopAll 有 1 个
 *     bool 实参，编译器直接复用了刚读进来的门字节。走这条路它必为 0 ⇒ 实际调用是 Audio_StopAll(**false**)。
 */
/* @0x133660 ldr r3, [pc, #0x10] */
/* @0x133664 ldr r3, [pc, r3] */
/* @0x133668 ldrb r0, [r3] */
/* @0x13366c cmp r0, #0 */
/* @0x133670 bxne lr */
/* @0x133674 b 0x21a3bc <_Z13Audio_StopAllb> */
/*
 * ── 7.2 池字（0x133678，非指令）───────────────────────────────────────────
 */
/* @0x133678 eoreq r11, r11, r8, ror #19 */
/*
 * ── 7.3 被调方（旁证 0x21a3bc, 152 B）──────────────────────────────────────
 *   两道门（g_fNoAudio 0x21a3c4 / g_UseNewAudio 0x21a3dc）→ 取池 count（+0x38）→ 从 i=0 循环到 count-1：
 *   r0 = (i<count) ? items[i] : 0，r1 = flag(=入口 bool)，逐个调 Audio_StopSoundNoise(noise,flag)（0x21a42c）。
 *   ⇒ 与 StopSound 不同，它**不做 id 过滤**，对池里每个非空/空元素都调一次（空元素靠被调方自己判空）。
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 8 · F_DrawSetAlpha（draw_set_alpha）
 * @func 0x11a9dc 0x11a9f4  size 24  6 条（无池字）
 * 符号: _Z14F_DrawSetAlphaR6RValueP9CInstanceS2_iPS_
 * 一句话: a=YYGetFloat(args,0) → 尾跳 YYGML_draw_set_alpha(a)；后者把 0..1 映射成 0..255 并同时更新
 *         Draw_Alpha 与 Draw_Color 两个全局。result 不写。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 8.1 帧 + 取 float + 尾跳（0x11a9dc..0x11a9f0）─────────────────────────
 *   push {r3,lr}(8) ⇒ args [sp,#0x8]；下标 0 走 **YYGetFloat**（不是 Int32），pop 后 `b 0x169dc4`。
 *   ⇒ 三个 draw_set_* 里只有 alpha 走 float，颜色与字体都走 int32。
 */
/* @0x11a9dc push {r3, lr} */
/* @0x11a9e0 mov r1, #0 */
/* @0x11a9e4 ldr r0, [sp, #0x8] */
/* @0x11a9e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11a9ec pop {r3, lr} */
/* @0x11a9f0 b 0x169dc4 <_Z20YYGML_draw_set_alphaf> */
/*
 * ── 8.2 被调方：量纲与两个全局的同步（旁证 0x169dc4, 112 B）────────────────────
 *   b = (a > 1.0f) ? 255 : (a < 0 ? 0 : (uint)(a * 255.0f))
 *     （0x169dd0 vcmpe 1.0 + movgt #255；0x169e08 vcmpe #0 + vldrpl 255.0f（常数 0x437f0000）+ vmulpl + vcvtpl.u32.f32）。
 *   *Draw_Alpha(0x3f23cc) = b；随后 GR_D3DColor_Change_Alpha(*Draw_Color, b) → *Draw_Color(0x3f23d0)。
 *   ⇒ 写 alpha 会**连带重算颜色字**（ARGB 的 A 通道和 Draw_Alpha 不会脱钩）。
 *   · NaN 走 pl 分支（VCMP unordered 时 N=0）→ NaN*255 → vcvt.u32 得 0，属 ISA 规则推出、未实测（open）。
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 9 · F_DrawSetColor（draw_set_color）
 * @func 0x11a9c4 0x11a9ec  size 40  10 条（无池字）
 * 符号: _Z14F_DrawSetColorR6RValueP9CInstanceS2_iPS_
 * 一句话: c=YYGetInt32(args,0) → 尾跳 YYGML_draw_set_colour(c)；后者把 c 的低 24 位与 Draw_Alpha 拼成 ARGB
 *         写进 Draw_Color。result 不写。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 9.1 帧 + 取 int + 尾跳（0x11a9c4..0x11a9d8）───────────────────────────
 *   push {r3,lr}(8) ⇒ args [sp,#0x8]；下标 0 走 **YYGetInt32**，pop 后 `b 0x169d98`。
 *   符号名是 colour（英式），GML 名是 draw_set_color —— 同一个入口（GOT 0x3ee704）。
 */
/* @0x11a9c4 push {r3, lr} */
/* @0x11a9c8 mov r1, #0 */
/* @0x11a9cc ldr r0, [sp, #0x8] */
/* @0x11a9d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11a9d4 pop {r3, lr} */
/* @0x11a9d8 b 0x169d98 <_Z21YYGML_draw_set_colourj> */
/*
 * ── 9.2 被调方：只保留 RGB，alpha 来自全局（旁证 0x169d98, 44 B）────────────────
 *   0x169d9c `bic r0,r0,#0xFF000000`（objdump 写作 #-16777216）⇒ **入参的高 8 位被丢弃**，不做 clamp；
 *   0x169dac 读 *Draw_Alpha(0x3f23cc)，0x169db0 `orr r0,r0,r3,lsl #24` 拼成 ARGB，0x169db4 写回 *Draw_Color。
 *   ⇒ draw_set_color(0xFF123456) 与 draw_set_color(0x00123456) 等价；透明度只能用 draw_set_alpha 改。
 *   ⇒ 两个内建互为「同一个 32 位字的两半」：color 写 RGB、alpha 写 A 并反算颜色字。
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 10 · F_DrawSetFont（draw_set_font）
 * @func 0x11bd58 0x11bd70  size 24  6 条（无池字）
 * 符号: _Z13F_DrawSetFontR6RValueP9CInstanceS2_iPS_
 * 一句话: f=YYGetInt32(args,0) → 尾跳 GR_Text_Set_Font(f)；合法则 fontid=f，否则 fontid=-1（必要时先建默认字体）。
 *         result 不写。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 10.1 帧 + 取 int + 尾跳（0x11bd58..0x11bd6c）──────────────────────────
 *   push {r3,lr}(8) ⇒ args [sp,#0x8]；下标 0 走 YYGetInt32，pop 后 `b 0x172ac8`。
 */
/* @0x11bd58 push {r3, lr} */
/* @0x11bd5c mov r1, #0 */
/* @0x11bd60 ldr r0, [sp, #0x8] */
/* @0x11bd64 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11bd68 pop {r3, lr} */
/* @0x11bd6c b 0x172ac8 <_Z16GR_Text_Set_Fonti> */
/*
 * ── 10.2 被调方：两档出口（旁证 0x172ac8, 104 B）─────────────────────────────
 *   Font_Exists(f)（0x172ad0）！=0 → *fontid = f（0x172b14）；==0 → 读 deffont(0x48ffd8)，
 *   为 0 就先 MakeDefaultFont()（0x172b1c），然后把 *fontid 写 **-1**（0x172b04）。
 *   fontid 的地址 = 0x3f2410（.data 里 0x3f02a8 存放该地址，两级访问），初值 -1。
 *   ⇒ 设一个不存在的字体不会报错，只会把当前字体置 -1（后续绘制走默认字体或失败，取决于 GR_Text 侧）。
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 11 · F_ActionCurrentRoom（action_current_room）
 * @func 0x13e6d0 0x13e6d8  size 8  2 条（无池字、无栈帧）
 * 符号: _Z19F_ActionCurrentRoomR6RValueP9CInstanceS2_iPS_
 * 一句话: mov r0,#0 → 尾跳 Command_CurrentRoom(0) → Command_GotoRoom(*Current_Room, 0)。
 *         ⇒ 与 room_restart 同义（重开当前房），只是少了「先读 *Transition_Kind」那一步。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 11.1 两条指令（0x13e6d0..0x13e6d4）──────────────────────────────────
 *   0x13e6d0 的 `mov r0,#0` 只占第二实参的位置（命令层不读它）；第一个实参在 0x1c9f44 由
 *   `ldr r0,[r3]` 从 Current_Room 取出，所以「当前房间」不是从 GML 传的，而是命令层自己读全局。
 *   ⇒ action_current_room 的 GML 形态无参；result 不写。
 */
/* @0x13e6d0 mov r0, #0 */
/* @0x13e6d4 b 0x1c9f38 <_Z19Command_CurrentRoomi> */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 12 · F_ActionKillObject（action_kill_object）
 * @func 0x141af8 0x141b00  size 8  2 条（无池字、无栈帧）
 * 符号: _Z18F_ActionKillObjectR6RValueP9CInstanceS2_iPS_
 * 一句话: mov r0,r1（self）→ 尾跳 YYGML_action_kill_object(self)：跑事件 1、12，置 +0x68，
 *         ++CInstance::ms_markedCount。result 不写。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 12.1 两条指令（0x141af8..0x141afc）──────────────────────────────────
 *   `mov r0,r1` 把 self 顶到第一个实参；YYGML_action_kill_object 的签名是 (CInstance*)，只有 1 个参数。
 *   ⇒ other/argc/args 一个都不看。
 */
/* @0x141af8 mov r0, r1 */
/* @0x141afc b 0x141a98 <_Z24YYGML_action_kill_objectP9CInstance> */
/*
 * ── 12.2 被调方逐条（旁证 0x141a98, 96 B / 24 条）────────────────────────────
 *   if (inst->[0x6a]) return;                       // 0x141aa0..0x141aa8 —— **只看 +0x6a**
 *   inst->[0x6a] = 1;                               // 0x141ab4
 *   Perform_Event(inst, inst, 1, 0);                // 0x141ac0
 *   Perform_Event(inst, inst, 12, 0);               // 0x141ad4
 *   （事件号 1/12 的名字按 cards/DoDestroy.c open 的推断读作 Destroy / CleanUp，本卡未独立证明编号含义）
 *   inst->[0x68] = 1;                               // 0x141adc
 *   ++*(uint32_t*)0x536d7c;                         // 0x141ae8/0x141aec，GOT 0x3ee0bc
 *   0x536d7c 在 .dynsym 里是 **CInstance::ms_markedCount**（4 B）—— cards/DoDestroy.c 当时记作「无符号名的
 *   本地静态计数器」，本卡补上名字：两条销毁路（DoDestroy 软/硬、action_kill_object）共用同一个计数。
 *   ⇒ 与 DoDestroy 的差别是**少了两道闸**：不查 +0x68 / +0x69，只查 +0x6a。所以 +0x68 已置 1 的实例，
 *     action_kill_object 仍会再跑一遍事件 1/12 并再计数一次（DoDestroy 会直接返回）。
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 13 · F_DrawSelf（draw_self）
 * @func 0x123134 0x12313c  size 8  2 条（无池字、无栈帧）
 * 符号: _Z10F_DrawSelfR6RValueP9CInstanceS2_iPS_
 * 一句话: mov r0,r1（self）→ 尾跳 YYGML_draw_self(self)：按实例自身的 sprite/变换/混合画一次；
 *         没有 sprite 就报 "Trying to draw non-existing sprite."。result 不写。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/*
 * ── 13.1 两条指令（0x123134..0x123138）──────────────────────────────────
 *   `mov r0,r1`；被调方签名 (CInstance*) —— 只有 1 个参数，与 action_kill_object 同形。
 */
/* @0x123134 mov r0, r1 */
/* @0x123138 b 0x123088 <_Z15YYGML_draw_selfP9CInstance> */
/*
 * ── 13.2 被调方（旁证 0x123088, 172 B）──────────────────────────────────────
 *   cs = Sprite_Data(inst+0x8c)；cs==0 → Error_Show_Action("Trying to draw non-existing sprite.", false)
 *     （字符串在 0x339fbc，0x123128 尾跳）—— 只报错、不抛异常。
 *   cs!=0 → CSkeletonSprite::ms_drawInstance(0x479cac, GOT 0x3ed93c) = inst（0x1230b4）；
 *     CSprite::Draw(cs, (int)floor(inst+0x90), inst+0xb4, inst+0xb8,
 *                   inst+0x98, inst+0x9c, inst+0xa0, inst+0xa8, inst+0xa4)（0x123100）；
 *     然后把 ms_drawInstance 清 0（0x123108）。
 *   字段名按 cards/CInstance_ctor.c：+0x8c sprite_index、+0x90 image_index、+0x98 xscale、+0x9c yscale、
 *     +0xa0 angle、+0xa4 image_alpha、+0xa8 image_blend ⇒ 栈上第 8 个实参是 blend、第 9 个是 alpha，
 *     与 cards/CSprite_Draw.c 的 (this,i,x,y,xs,ys,rot,colour,alpha) 实参表互证。
 *   ⇒ draw_self 的全部输入都来自实例字段，不读 GML 实参、也不读全局绘制状态（Draw_Color/Alpha 不被它用）。
 */
/*
 * ═══════════════════════════════════════════════════════════════════════════
 * 节 14 · F_GameRestart（game_restart）
 * @func 0x109c00 0x109c04  size 4  1 条（无池字、无栈帧）
 * 符号: _Z13F_GameRestartR6RValueP9CInstanceS2_iPS_
 * 一句话: 一条 `b Command_RestartGame`。命令层只做两件事：*New_Room = **-200**、必要时打一条
 *         "Game restarted" 日志；真正的重启由 SingleStep 看到 -200 后执行。
 * ═══════════════════════════════════════════════════════════════════════════
 */
/* @0x109c00 b 0x1c9f54 <_Z19Command_RestartGamev> */
/*
 * ── 14.1 命令层逐条（旁证 0x1c9f54, 88 B / 22 条）────────────────────────────
 *   r2 = g_isZeus(0x5428e8) 字节；r3 = &New_Room(0x542954)；
 *   0x1c9f58 `mvn r1,#199` = **0xFFFFFF38 = -200**；0x1c9f6c `str r1,[r3]` ⇒ New_Room = -200。
 *   if (g_isZeus == 0) return;                     // 0x1c9f70/0x1c9f74
 *   if (g_DebugBuild(0x544c38) != 0) return;       // 0x1c9f84/0x1c9f88
 *   Debug_AddTag(2, "Game restarted")（0x1c9f8c..0x1c9f98；串在 0x350ce8）。
 *   ⇒ 本内建**不重置任何状态**：不调 Run_EndGame、不重载房间、不 exit。
 *     重启动在 SingleStep 0x1d4e78：Run_EndGame() → GamePadRestart() → StartGame() → srand48(2101988)。
 *   ⚠ 与既存 claims-batchAJ 的 CEG-003 冲突：该条把 0x1c9f54 记成「208 字节、写 -201」。本卡 22 条锚点 +
 *     池字实测是 **size 88、写 -200**；且全 .text 里搜不到 -201 的立即数写者（movw #0xff37 与 mvn #200 两类写法各 0 条）。
 *     208 B / -201 对应的是 Command_Change 卡附注里的 Command_EndGame，而 Command_EndGame 0x1c9f50 只有
 *     4 字节（bx lr）。建议按本卡回改 CEG-003（本卡不改别人的文件）。
 */
/*
 * ── 跨函数已证事实（14 节合并；括号里是节号与地址）───────────────────────────
 *  1. **14/14 不写 result**，且 14/14 以 `b` 尾跳结束（清单见头部）。argc 与 other 各 0 次读，
 *     self 只在 4 个里读（两个 move_bounce 的 mov r4,r1；action_kill_object / draw_self 的 mov r0,r1）。
 *     ⇒ 这一批是纯「参数整形 + 转发」，没有任何一个带返回值处理。
 *  2. 栈帧只有两种：8 字节的 6 个（两个 move_bounce 用 {r4,lr}，room_goto 与三个 draw_set 用 {r3,lr}），
 *     其余 8 个**完全不建帧**（RoomRestart / Audio×3 / Action×2 / DrawSelf / GameRestart）。
 *     这也是「门命中时用 bxne lr 直接返回」能成立的原因（无帧可拆）。
 *  3. room 链只有一个汇点：Command_GotoRoom(0x1c9e08)。本卡的 room_goto / room_restart / action_current_room
 *     以及 cards 外的 SV_Room(0x1fa7d4) 四条入口全部尾跳它；它写 New_Room、清 Transition_Kind、过 Room_Exists。
 *     **第二实参 kind 是死参**（21 条指令里 r1 不出现）⇒ room_goto 与 room_restart 传进去的 *Transition_Kind 都被丢弃。
 *  4. New_Room 的消费端是 SingleStep 0x1d4dd8（不在本卡锚点）：-1 无操作 / -200 重开游戏 / -300 读档 /
 *     -100 与 -400 清 Run_Running / 其余走 SwitchRoom → EndRoom(0)+StartRoom(idx,0) → New_Room 回 -1。
 *     game_restart 写的是 -200，room_goto 写的是房间号，room_goto 失败写 -400 —— 三个内建分别喂三档。
 *  5. 两处「借来的实参」都不是显式常量：audio_stop_sound 的下标 r1 = 0x134de8 的 ldrb（门字节），
 *     audio_stop_all 的 bool r0 = 0x133668 的 ldrb（门字节）。两条路径上它们必为 0，
 *     所以「参数从哪来」不能靠看函数签名，只能逐条读。
 *  6. draw_set_* 三个写点互不重叠：Draw_Color(0x3f23d0) / Draw_Alpha(0x3f23cc) / Graphics_Text::fontid(0x3f2410)。
 *     前两个互为「同一个 ARGB 字的两半」（设 color 保留 alpha、设 alpha 反算 color），字体与它们无关。
 *     初值：Draw_Color=0xFF000000、Draw_Alpha=0xFF、fontid=-1（全部 .data 实测）。
 *  7. action 三招打的是三层不同的东西：action_bounce → Command_Bounce（物理谓词 + 翻转/扫描）、
 *     action_current_room → Command_CurrentRoom → Command_GotoRoom（房间请求）、
 *     action_kill_object → YYGML_action_kill_object（事件 1/12 + +0x68 + ms_markedCount）。
 *     三者没有一个写 result，也没有一个读 argc。
 *
 * ── open ────────────────────────────────────────────────────────────────
 *  1. Command_Bounce(0x1cafa0, 660 B) 的内部只到边界：四向命中的 8 种组合各对应翻转 hspeed / vspeed /
 *     两者 / 都不翻，精确判据（0x1cb174..0x1cb1e8 的 eor/and/tst 序列）与 35 步扫描的步长、终止条件未逐条展开。
 *  2. SwitchRoom(0x1d4450) → StartRoom 的负索引行为（New_Room < -200 且不是 -300/-400 时会走到这里）未展开；
 *     本 build 里没有 -201 的写者，所以这条路径静态不可达（除非别的 .so 或 JNI 写 New_Room）。
 *  3. claims-batchAJ CEG-003 与本卡 §14 冲突（-201/208 B vs -200/88 B）：本卡有 22 条锚点 + 池字实测支持
 *     -200/88 B，建议回改该 claim；未改别人的文件（见 §14 末）。
 *  4. draw_set_alpha 的 NaN 行为（→ b=0）是按 VCMP/vcvt 的 ISA 规则推的，未在 harness 里实测。
 *  5. fontid = -1 之后 GR_Text_* 的行为（回落到 deffont 还是直接失败）未追；MakeDefaultFont 0x172468 的内容
 *     也只到「造一个默认字体」这一步。
 *  6. CSkeletonSprite::ms_drawInstance(0x479cac) 在绘制期间被谁读未追（draw_self 只负责置位/清零）。
 *  7. Run_Running(0x54297a) 的语义按符号名读作「运行中」；本卡只证到 SingleStep 在 -100/-400 时把它清 0，
 *     以及它是 .bss 单字节、没有其它写点在本卡范围内。
 */
