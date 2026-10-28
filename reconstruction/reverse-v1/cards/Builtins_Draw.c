/* cally 逆向卡：Builtins_Draw（原版 libyoyo.so，armv7）—— 5 个 GML 绘制内建
 * 节: 5 个 @func 小节，顺序 = draw_background / draw_background_ext / draw_healthbar /
 *     draw_sprite_ext / draw_text_color（= 索引文件的段落顺序，不是 GML 字典序）
 * 索引: asm/index-builtins_draw_all.tsv —— 331 条，4 段互不连续的区间，覆盖 5 个函数
 *   段A 0x11db10..0x11dd6c  152 条  F_DrawBackground(49) + F_DrawBackgroundExt(103)：两函数在内存里首尾相接、
 *                                      中间无填充，故合成一段；分界在 0x11dbd4（dynsym 给出的 size 边界）
 *   段B 0x11b2e4..0x11b3f4   69 条  F_DrawHealthbar
 *   段C 0x1227c0..0x1228a0   57 条  F_DrawSpriteExt
 *   段D 0x121fd8..0x1220a8   53 条  F_DrawTextColor
 * 级别: 正文（五个函数的形参落位、取值下标、尾跳/调用的实参映射、错误串、两条资产路的开关全部逐条落锚；
 *       Graphics 层内部不展开 —— 本卡只证「调用了谁、按什么顺序传了什么」，不证像素/裁剪/混合）
 * 符号: 五个都取到 .dynsym 的完整签名。本 .so 的 .dynsym 有 11,745 项、8,926 个带地址 FUNC
 *       （并非 fully stripped）；README 里 asm/functions.tsv 的 9,623 函数是按 .text 自底向上切出的匿名视图，
 *       两者不冲突：本卡用的是符号视图，锚点仍来自 asm_index.py 的指令流。
 *   F_DrawBackground    0x11db10  size 196  _Z16F_DrawBackgroundR6RValueP9CInstanceS2_iPS_
 *   F_DrawBackgroundExt 0x11dbd4  size 412  _Z19F_DrawBackgroundExtR6RValueP9CInstanceS2_iPS_
 *   F_DrawHealthbar     0x11b2e4  size 276  _Z15F_DrawHealthbarR6RValueP9CInstanceS2_iPS_
 *   F_DrawSpriteExt     0x1227c0  size 228  _Z15F_DrawSpriteExtR6RValueP9CInstanceS2_iPS_
 *   F_DrawTextColor     0x121fd8  size 212  _Z15F_DrawTextColorR6RValueP9CInstanceS2_iPS_
 *
 * ── 统一调用约定（五个函数一致，逐节各自落锚）────────────────────────────
 *   void F(r0 = RValue& ret, r1 = CInstance* self, r2 = CInstance* other,
 *          r3 = int argc, 入口 [sp+0] = RValue* args)
 *   RValue 16 字节；&args[i] = args + i*16（draw_background_ext 里 args+0x10 的逐级推进可证）。
 *   args 在函数体内从 [sp + (push 字节 + sub 字节)] 取，五个函数各不相同：
 *     0x11db10 → [sp+0x10]（push 16）
 *     0x11dbd4 → [sp+0x40]（push 36 + sub 28）
 *     0x11b2e4 → [sp+0x58]（push 36 + sub 52）
 *     0x1227c0 → [sp+0x50]（push 36 + sub 44）
 *     0x121fd8 → [sp+0x48]（push 36 + sub 36）
 *   YYGetInt32 / YYGetFloat / YYGetBool(RValue* a, int i) 只取第 i 个元素的数据字，
 *   类型转换在 YYGet* 内部按 tag 做；本卡不再展开。
 *
 * ── 三条跨函数硬事实 ─────────────────────────────────────────────────
 *   1. **五个函数一次都没读 argc**：r3 要么在第一条指令就被别的常量覆盖（两条 background 是
 *      ldr r3,[pc,#imm] 取 GOT 偏移），要么在第一次用到 r3 之前已被 mov 覆盖（其余三个）。
 *      缺参不由被调方兜：少传参 = 直接越界读 args[]，靠编译器「调用点 argc == 内建表登记值」保证。
 *   2. **五个函数一次都没写 ret**：没有一条 st* 通过入口 r0 落地，r0 入口即被挪作他用。
 *      draw_* 在 GML 里没有返回值，ret 由 VM 派发层预置。
 *   3. draw_background / draw_background_ext 共用同一个「资产类型开关」：
 *      .bss 字节 **0x5428e8**（GOT 槽 0x3ed92c，R_ARM_RELATIVE，槽内预置该地址）。
 *      非 0 → Sprite_Data(arg0) 按精灵号解析成 CSprite；0 → Background_Data(arg0) 按背景号解析成 CBackground。
 *      两条路的失败串是同一条：.rodata 0x33a1dc "Trying to draw non-existing background."。
 *      ⚠ 同一个字节在 DoBreak 卡里读作 g_isZeus、在 Instance_Animate 卡里读作 image_index 推进模式
 *      ⇒ 三张卡三种读法，正式名未定（open 1）。
 *
 * ── open ─────────────────────────────────────────────────────────────
 *   1. 0x5428e8 的正式名与写入点（本卡只证「读一个字节、两路分叉」）。
 *   2. Graphics 层：CSprite::DrawSimple/Draw、CBackground::DrawSimple/Draw、GR_Draw_Healthbar、
 *      GR_Text_Draw_Color 的内部（本卡只给签名与实参映射）。
 *   3. F_DrawSpriteExt 的 arg0/arg1 由 GetSpriteIndices（0x1226c4, size 132）解释成 (sprite, subimg)，
 *      其内部形态（对象号/精灵号双形态）不在本卡范围。
 *   4. draw_background 的 sprite 路为什么把 subimg 硬编码 0（0x11db64）——静态只证常量。
 */

/* ══ 1/5  F_DrawBackground  0x11db10  size 196  49 条  (0x11dbcc, 0x11dbd0 = 2 字 literal pool)
 * @func 0x11db10 0x11dbc8  size 196  49 条（47 条指令 + 2 个池字 0x11dbcc/0x11dbd0）
 * 符号 _Z16F_DrawBackgroundR6RValueP9CInstanceS2_iPS_   GML: draw_background(ind, x, y)
 * 参数: args = [sp+0x10]（0x11db1c）；mode = *(u8*)0x5428e8（0x11db10 取 GOT 偏移、0x11db18 取槽，0x11db20 ldrb）
 *
 *   if (mode != 0) {                                    // 0x11db24 cmp / 0x11db2c beq → 背景路
 *     cs = Sprite_Data(YYGetInt32(args,0));             // 0x11db34 bl YYGetInt32(idx 0) → 0x11db38 bl Sprite_Data
 *     if (!cs) goto err;                                // 0x11db3c subs / 0x11db40 beq → 0x11dbb8
 *     x = YYGetFloat(args,1);                           // 0x11db4c → r6
 *     y = YYGetFloat(args,2);                           // 0x11db5c → r3
 *     CSprite::DrawSimple(cs, 0, x, y);                 // 0x11db70 pop / 0x11db74 b 0x1ecab4（尾跳，不留帧）
 *   } else {
 *     cb = Background_Data(YYGetInt32(args,0));         // 0x11db78 bl YYGetInt32(0) → 0x11db7c bl Background_Data
 *     if (!cb) goto err;                                // 0x11db80 subs / 0x11db84 beq → 0x11dbb8
 *     x = YYGetFloat(args,1);  y = YYGetFloat(args,2);  // 0x11db90 → r6、0x11dba0 → r2
 *     CBackground::DrawSimple(cb, x, y);                // 0x11dbb0 pop / 0x11dbb4 b 0xc1fb4（尾跳）
 *   }
 * err:
 *   Error_Show_Action("Trying to draw non-existing background.", 0);   // 0x11dbb8..0x11dbc8（r1 = 0 = false）
 *   两条路都是尾跳（pop 全部 + b），所以本函数没有自己的 epilogue，也不写 ret。
 *   DrawSimple 的形参映射：sprite 路 r1=subimg(常量 0) r2=x r3=y；背景路 r1=x r2=y（少一个 subimg）。
 */

/* ---- 1/5 F_DrawBackground 代码 0x11db10..0x11dbc8 ---- */
/* @0x11db10 ldr r3, [pc, #0xb4] */
/* @0x11db14 push {r4, r5, r6, lr} */
/* @0x11db18 ldr r3, [pc, r3] */
/* @0x11db1c ldr r4, [sp, #0x10] */
/* @0x11db20 ldrb r1, [r3] */
/* @0x11db24 cmp r1, #0 */
/* @0x11db28 mov r0, r4 */
/* @0x11db2c beq 0x11db78 <_Z16F_DrawBackgroundR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x11db30 mov r1, #0 */
/* @0x11db34 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11db38 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11db3c subs r5, r0, #0 */
/* @0x11db40 beq 0x11dbb8 <_Z16F_DrawBackgroundR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x11db44 mov r0, r4 */
/* @0x11db48 mov r1, #1 */
/* @0x11db4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11db50 mov r1, #2 */
/* @0x11db54 mov r6, r0 */
/* @0x11db58 mov r0, r4 */
/* @0x11db5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11db60 mov r2, r6 */
/* @0x11db64 mov r1, #0 */
/* @0x11db68 mov r3, r0 */
/* @0x11db6c mov r0, r5 */
/* @0x11db70 pop {r4, r5, r6, lr} */
/* @0x11db74 b 0x1ecab4 <_ZN7CSprite10DrawSimpleEiff> */
/* @0x11db78 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11db7c bl 0xc3794 <_Z15Background_Datai> */
/* @0x11db80 subs r5, r0, #0 */
/* @0x11db84 beq 0x11dbb8 <_Z16F_DrawBackgroundR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x11db88 mov r0, r4 */
/* @0x11db8c mov r1, #1 */
/* @0x11db90 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11db94 mov r1, #2 */
/* @0x11db98 mov r6, r0 */
/* @0x11db9c mov r0, r4 */
/* @0x11dba0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dba4 mov r1, r6 */
/* @0x11dba8 mov r2, r0 */
/* @0x11dbac mov r0, r5 */
/* @0x11dbb0 pop {r4, r5, r6, lr} */
/* @0x11dbb4 b 0xc1fb4 <_ZN11CBackground10DrawSimpleEff> */
/* @0x11dbb8 ldr r0, [pc, #0x10] */
/* @0x11dbbc mov r1, #0 */
/* @0x11dbc0 pop {r4, r5, r6, lr} */
/* @0x11dbc4 add r0, pc, r0 */
/* @0x11dbc8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* ---- literal pool：以下 2 字是池字（GOT 偏移 + 错误串偏移），非指令 ---- */
/* @0x11dbcc eoreq pc, r12, r12, lsl #28 */
/* @0x11dbd0 eoreq r12, r1, r0, lsl r6 */
/* ══ 2/5  F_DrawBackgroundExt  0x11dbd4  size 412  103 条  (0x11dd68, 0x11dd6c = 2 字 literal pool)
 * @func 0x11dbd4 0x11dd64  size 412  103 条（101 条指令 + 2 个池字 0x11dd68/0x11dd6c）
 * 符号 _Z19F_DrawBackgroundExtR6RValueP9CInstanceS2_iPS_
 * GML: draw_background_ext(ind, x, y, xs, ys, rot, colour, alpha)    —— 8 个位置参数
 * 参数: args = [sp+0x40]（0x11dbe8）；mode 仍是 *(u8*)0x5428e8（0x11dbd4/0x11dbdc/0x11dbe4 三次一条龙）
 *
 *   if (mode != 0) {                                             // 0x11dbec cmp / 0x11dbf4 beq → 背景路
 *     cs = Sprite_Data(YYGetInt32(args,0));                      // 0x11dbfc → 0x11dc00
 *     if (!cs) goto err;                                         // 0x11dc04 subs / 0x11dc08 beq → 0x11dd50
 *     x=YYGetFloat(1) r7, y=YYGetFloat(2) r6,                    // 0x11dc14 / 0x11dc24
 *     xs=YYGetFloat(3) r11, ys=YYGetFloat(4) r10,                // 0x11dc34 / 0x11dc44
 *     rot=YYGetFloat(5) r9, colour=YYGetInt32(6) r8,             // 0x11dc54 / 0x11dc64
 *     alpha=YYGetFloat(7) r0;                                    // 0x11dc74
 *     CSprite::Draw(cs, 0, x, y, xs, ys, rot, colour, alpha);     // 0x11dc9c bl 0x1ec720
 *       regs: r1=0(subimg) r2=x r3=y；栈实参 [sp]=xs 0x11dc78 [sp+4]=ys 0x11dc7c
 *             [sp+8]=rot 0x11dc84 [sp+0xc]=colour 0x11dc8c [sp+0x10]=alpha 0x11dc94
 *   } else {
 *     cb = Background_Data(YYGetInt32(args,0));                   // 0x11dca8 → 0x11dcac
 *     if (!cb) goto err;                                          // 0x11dcb0/0x11dcb4 → 0x11dd50
 *     x=YYGetFloat(1) r8, y=YYGetFloat(2) r7, xs=YYGetFloat(3) r6,// 0x11dcc0 / 0x11dcd0 / 0x11dce0
 *     ys=YYGetFloat(4) r11, rot=YYGetFloat(5) r10,                // 0x11dcf0 / 0x11dd00
 *     colour=YYGetInt32(6) r9, alpha=YYGetFloat(7) r0;            // 0x11dd10 / 0x11dd20
 *     CBackground::Draw(cb, x, y, xs, ys, rot, colour, alpha);     // 0x11dd44 bl 0xc1fd0
 *       regs: r1=x r2=y r3=xs；栈实参 [sp]=ys 0x11dd24 [sp+4]=rot 0x11dd28
 *             [sp+8]=colour 0x11dd30 [sp+0xc]=alpha 0x11dd3c
 *   }
 * err: Error_Show_Action("Trying to draw non-existing background.", 0);  // 0x11dd50..0x11dd64
 *
 * 装配细节（证明 8 个位置参数一一对应）：
 *   sprite 路把 x 放 r7、y 放 r6，而 CSprite::Draw 要 r2=x r3=y（0x11dc88/0x11dc90 显式搬）；
 *   背景路把 x 放 r8、y 放 r7、xs 放 r6，而 CBackground::Draw 要 r1=x r2=y r3=xs（0x11dd2c..0x11dd38）。
 *   两条路的 colour 都用 YYGetInt32（不是 Float）——颜色是 0x00BBGGRR 整数。
 *   背景路比 sprite 路少一个栈实参，正是 subimg 槽的缺口（8 参 vs 9 参）。
 */

/* ---- 2/5 F_DrawBackgroundExt 代码 0x11dbd4..0x11dd64 ---- */
/* @0x11dbd4 ldr r3, [pc, #0x18c] */
/* @0x11dbd8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11dbdc ldr r3, [pc, r3] */
/* @0x11dbe0 sub sp, sp, #28 */
/* @0x11dbe4 ldrb r1, [r3] */
/* @0x11dbe8 ldr r4, [sp, #0x40] */
/* @0x11dbec cmp r1, #0 */
/* @0x11dbf0 mov r0, r4 */
/* @0x11dbf4 beq 0x11dca8 <_Z19F_DrawBackgroundExtR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x11dbf8 mov r1, #0 */
/* @0x11dbfc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11dc00 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x11dc04 subs r5, r0, #0 */
/* @0x11dc08 beq 0x11dd50 <_Z19F_DrawBackgroundExtR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x11dc0c mov r0, r4 */
/* @0x11dc10 mov r1, #1 */
/* @0x11dc14 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dc18 mov r1, #2 */
/* @0x11dc1c mov r7, r0 */
/* @0x11dc20 mov r0, r4 */
/* @0x11dc24 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dc28 mov r1, #3 */
/* @0x11dc2c mov r6, r0 */
/* @0x11dc30 mov r0, r4 */
/* @0x11dc34 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dc38 mov r1, #4 */
/* @0x11dc3c mov r11, r0 */
/* @0x11dc40 mov r0, r4 */
/* @0x11dc44 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dc48 mov r1, #5 */
/* @0x11dc4c mov r10, r0 */
/* @0x11dc50 mov r0, r4 */
/* @0x11dc54 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dc58 mov r1, #6 */
/* @0x11dc5c mov r9, r0 */
/* @0x11dc60 mov r0, r4 */
/* @0x11dc64 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11dc68 mov r1, #7 */
/* @0x11dc6c mov r8, r0 */
/* @0x11dc70 mov r0, r4 */
/* @0x11dc74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dc78 str r11, [sp] */
/* @0x11dc7c str r10, [sp, #0x4] */
/* @0x11dc80 mov r1, #0 */
/* @0x11dc84 str r9, [sp, #0x8] */
/* @0x11dc88 mov r2, r7 */
/* @0x11dc8c str r8, [sp, #0xc] */
/* @0x11dc90 mov r3, r6 */
/* @0x11dc94 str r0, [sp, #0x10] */
/* @0x11dc98 mov r0, r5 */
/* @0x11dc9c bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf> */
/* @0x11dca0 add sp, sp, #28 */
/* @0x11dca4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11dca8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11dcac bl 0xc3794 <_Z15Background_Datai> */
/* @0x11dcb0 subs r5, r0, #0 */
/* @0x11dcb4 beq 0x11dd50 <_Z19F_DrawBackgroundExtR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x11dcb8 mov r0, r4 */
/* @0x11dcbc mov r1, #1 */
/* @0x11dcc0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dcc4 mov r1, #2 */
/* @0x11dcc8 mov r8, r0 */
/* @0x11dccc mov r0, r4 */
/* @0x11dcd0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dcd4 mov r1, #3 */
/* @0x11dcd8 mov r7, r0 */
/* @0x11dcdc mov r0, r4 */
/* @0x11dce0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dce4 mov r1, #4 */
/* @0x11dce8 mov r6, r0 */
/* @0x11dcec mov r0, r4 */
/* @0x11dcf0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dcf4 mov r1, #5 */
/* @0x11dcf8 mov r11, r0 */
/* @0x11dcfc mov r0, r4 */
/* @0x11dd00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dd04 mov r1, #6 */
/* @0x11dd08 mov r10, r0 */
/* @0x11dd0c mov r0, r4 */
/* @0x11dd10 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11dd14 mov r1, #7 */
/* @0x11dd18 mov r9, r0 */
/* @0x11dd1c mov r0, r4 */
/* @0x11dd20 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11dd24 str r11, [sp] */
/* @0x11dd28 str r10, [sp, #0x4] */
/* @0x11dd2c mov r1, r8 */
/* @0x11dd30 str r9, [sp, #0x8] */
/* @0x11dd34 mov r2, r7 */
/* @0x11dd38 mov r3, r6 */
/* @0x11dd3c str r0, [sp, #0xc] */
/* @0x11dd40 mov r0, r5 */
/* @0x11dd44 bl 0xc1fd0 <_ZN11CBackground4DrawEfffffjf> */
/* @0x11dd48 add sp, sp, #28 */
/* @0x11dd4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11dd50 ldr r0, [pc, #0x14] */
/* @0x11dd54 mov r1, #0 */
/* @0x11dd58 add r0, pc, r0 */
/* @0x11dd5c add sp, sp, #28 */
/* @0x11dd60 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11dd64 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* ---- literal pool：2 字（GOT 偏移 + 错误串偏移），非指令 ---- */
/* @0x11dd68 eoreq pc, r12, r8, asr #26 */
/* @0x11dd6c eoreq r12, r1, r12, ror r4 */
/* ══ 3/5  F_DrawHealthbar  0x11b2e4  size 276  69 条（无 literal pool、无全局、无错误路）
 * @func 0x11b2e4 0x11b3f4  size 276  69 条（69 条指令，无池）
 * 符号 _Z15F_DrawHealthbarR6RValueP9CInstanceS2_iPS_
 * GML: draw_healthbar(x1, y1, x2, y2, amount, backcol, col1, col2, direction, showback, showborder)
 * 参数: args = [sp+0x58]（0x11b2f0）。11 个位置参数全读，顺序 0→10，一个都不跳：
 *   arg0 → r7   0x11b2f8   arg1 → r9   0x11b308   arg2 → r8   0x11b318
 *   arg3 → [sp+0x24] 0x11b328/0x11b338   arg4 → [sp+0x28] 0x11b33c/0x11b34c
 *   arg5 → [sp+0x2c] 0x11b350/0x11b358（Int32）   arg6 → r6 0x11b360（Int32）
 *   arg7 → r5 0x11b370（Int32）   arg8 → r11 0x11b380（Int32）
 *   arg9 → r10 0x11b390（Bool）   arg10 → r4 0x11b3a0（Bool）
 *
 *   merged = Color_Merge(col1, col2, 0.5f);      // 0x11b3a4 mov r1,r5 / 0x11b3a8 mov r2,#0x3F000000
 *                                                // / 0x11b3b0 mov r0,r6 / 0x11b3b4 bl 0x20ffb8
 *   GR_Draw_Healthbar(x1, y1, x2, y2, amount, backcol, col1, merged, col2, direction, showback, showborder);
 *                                                // 0x11b3ec bl 0x16c0d8，12 个实参
 *
 * 12 个实参的落位（证明「中间插了一个 50% 混合色」）：
 *   regs r0=x1(r7) 0x11b3e8, r1=y1(r9) 0x11b3c0, r2=x2(r8) 0x11b3cc, r3=y2([sp+0x24]) 0x11b3e0
 *   栈   [sp]   = arg4 amount(float)  0x11b3d0
 *        [sp+4] = arg5 backcol(int)   0x11b3c8 的 stmib（连同下一字一次写两个）
 *        [sp+8] = arg6 col1(int)
 *        [sp+0xc] = merged（Color_Merge 的返回值，r0）  0x11b3e4
 *        [sp+0x10] = arg7 col2(int)   0x11b3c4
 *        [sp+0x14] = arg8 direction   0x11b3d4
 *        [sp+0x18] = arg9 showback    0x11b3d8
 *        [sp+0x1c] = arg10 showborder 0x11b3dc
 *   签名 _Z17GR_Draw_Healthbarfffffjjjjibb 与落位互证：5 个 float（x1,y1,x2,y2,amount）+ 4 个 unsigned
 *   （backcol,col1,merged,col2）+ 1 个 int（direction）+ 2 个 bool。Color_Merge 的 0x3F000000 = 0.5f，
 *   所以 merged 是 col1→col2 的 50% 中点色 —— 原版把三色渐变的中点预先算好传进去，而不是在 Graphics 层算
 *   （这条只能证「传了什么」，为什么这么传见 open 2）。
 * 本函数没有资产解析、没有空指针检查、没有错误串：它只画矩形，参数全是标量。
 */

/* ---- 3/5 F_DrawHealthbar 0x11b2e4..0x11b3f4（无池） ---- */
/* @0x11b2e4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x11b2e8 sub sp, sp, #52 */
/* @0x11b2ec mov r1, #0 */
/* @0x11b2f0 ldr r4, [sp, #0x58] */
/* @0x11b2f4 mov r0, r4 */
/* @0x11b2f8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b2fc mov r1, #1 */
/* @0x11b300 mov r7, r0 */
/* @0x11b304 mov r0, r4 */
/* @0x11b308 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b30c mov r1, #2 */
/* @0x11b310 mov r9, r0 */
/* @0x11b314 mov r0, r4 */
/* @0x11b318 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b31c mov r1, #3 */
/* @0x11b320 mov r8, r0 */
/* @0x11b324 mov r0, r4 */
/* @0x11b328 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b32c mov r1, #4 */
/* @0x11b330 mov r3, r0 */
/* @0x11b334 mov r0, r4 */
/* @0x11b338 str r3, [sp, #0x24] */
/* @0x11b33c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x11b340 mov r1, #5 */
/* @0x11b344 mov r12, r0 */
/* @0x11b348 mov r0, r4 */
/* @0x11b34c str r12, [sp, #0x28] */
/* @0x11b350 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b354 mov r1, #6 */
/* @0x11b358 str r0, [sp, #0x2c] */
/* @0x11b35c mov r0, r4 */
/* @0x11b360 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b364 mov r1, #7 */
/* @0x11b368 mov r6, r0 */
/* @0x11b36c mov r0, r4 */
/* @0x11b370 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b374 mov r1, #8 */
/* @0x11b378 mov r5, r0 */
/* @0x11b37c mov r0, r4 */
/* @0x11b380 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x11b384 mov r1, #9 */
/* @0x11b388 mov r11, r0 */
/* @0x11b38c mov r0, r4 */
/* @0x11b390 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11b394 mov r1, #10 */
/* @0x11b398 mov r10, r0 */
/* @0x11b39c mov r0, r4 */
/* @0x11b3a0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x11b3a4 mov r1, r5 */
/* @0x11b3a8 mov r2, #1056964608 */
/* @0x11b3ac mov r4, r0 */
/* @0x11b3b0 mov r0, r6 */
/* @0x11b3b4 bl 0x20ffb8 <_Z11Color_Mergejjf> */
/* @0x11b3b8 ldr r2, [sp, #0x2c] */
/* @0x11b3bc ldr r12, [sp, #0x28] */
/* @0x11b3c0 mov r1, r9 */
/* @0x11b3c4 str r5, [sp, #0x10] */
/* @0x11b3c8 stmib sp, {r2, r6} */
/* @0x11b3cc mov r2, r8 */
/* @0x11b3d0 str r12, [sp] */
/* @0x11b3d4 str r11, [sp, #0x14] */
/* @0x11b3d8 str r10, [sp, #0x18] */
/* @0x11b3dc str r4, [sp, #0x1c] */
/* @0x11b3e0 ldr r3, [sp, #0x24] */
/* @0x11b3e4 str r0, [sp, #0xc] */
/* @0x11b3e8 mov r0, r7 */
/* @0x11b3ec bl 0x16c0d8 <_Z17GR_Draw_Healthbarfffffjjjjibb> */
/* @0x11b3f0 add sp, sp, #52 */
/* @0x11b3f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ══ 4/5  F_DrawSpriteExt  0x1227c0  size 228  57 条（无 literal pool）
 * @func 0x1227c0 0x1228a0  size 228  57 条（57 条指令，无池）
 * 符号 _Z15F_DrawSpriteExtR6RValueP9CInstanceS2_iPS_
 * GML: draw_sprite_ext(sprite, subimg, x, y, xs, ys, rot, colour, alpha)   —— 9 个位置参数
 * 参数: args = [sp+0x50]（0x1227d0：push 36 + sub 44）
 *
 *   if (!GetSpriteIndices(self, args, &spr（[sp+0x20]）、&sub（[sp+0x24]）)) return;   // 0x1227dc
 *        //  r0 = self（0x1227c8 mov r0,r1）、r1 = args、r2 = sp+32、r3 = sp+36
 *        //  返回 0 → 0x1227e8 add sp / 0x1227ec pop，ret 不写、不报错
 *   cs = Sprite_Data(spr);                            // 0x1227f0 ldr r0,[sp,#0x20] / 0x1227f4 bl
 *        //  ⚠ 这里**没有空指针检查**（对照 draw_background 的 0x11db3c subs/beq）
 *   sub = [sp+0x24] → r8;                             // 0x1227fc
 *   x=YYGetFloat(2) r7, y=YYGetFloat(3) r6,           // 0x122808 / 0x122818
 *   xs=YYGetFloat(4) [sp+0x1c], ys=YYGetFloat(5) r11, // 0x122828/0x122838 / 0x12283c
 *   rot=YYGetFloat(6) r10, colour=YYGetInt32(7) r9,   // 0x12284c / 0x12285c
 *   alpha=YYGetFloat(8) r0;                           // 0x12286c
 *   CSprite::Draw(cs, sub, x, y, xs, ys, rot, colour, alpha);   // 0x122898 bl 0x1ec720
 *     栈实参 [sp]=xs 0x122884 [sp+4]=ys 0x122874 [sp+8]=rot 0x12287c
 *            [sp+0xc]=colour 0x12288c [sp+0x10]=alpha 0x122890
 *     寄存器 r1=sub(r8) 0x122878、r2=x(r7) 0x122880、r3=y(r6) 0x122888
 *
 * 与前一张卡的 draw_background_ext 精灵路逐字同构：实参下标只差 2（本函数 arg0/arg1 被
 * GetSpriteIndices 吃掉，x 从 arg2 起），栈实参顺序、寄存器映射、colour 走 Int32 全部一致 ——
 * 两处独立落锚，互证 CSprite::Draw 的实参表：(this, subimg, x, y, xs, ys, rot, colour, alpha)。
 */

/* ---- 4/5 F_DrawSpriteExt 0x1227c0..0x1228a0（无池） ---- */
/* @0x1227c0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1227c4 sub sp, sp, #44 */
/* @0x1227c8 mov r0, r1 */
/* @0x1227cc add r2, sp, #32 */
/* @0x1227d0 ldr r4, [sp, #0x50] */
/* @0x1227d4 add r3, sp, #36 */
/* @0x1227d8 mov r1, r4 */
/* @0x1227dc bl 0x1226c4 <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_> */
/* @0x1227e0 cmp r0, #0 */
/* @0x1227e4 bne 0x1227f0 <_Z15F_DrawSpriteExtR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x1227e8 add sp, sp, #44 */
/* @0x1227ec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1227f0 ldr r0, [sp, #0x20] */
/* @0x1227f4 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1227f8 mov r1, #2 */
/* @0x1227fc ldr r8, [sp, #0x24] */
/* @0x122800 mov r5, r0 */
/* @0x122804 mov r0, r4 */
/* @0x122808 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12280c mov r1, #3 */
/* @0x122810 mov r7, r0 */
/* @0x122814 mov r0, r4 */
/* @0x122818 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12281c mov r1, #4 */
/* @0x122820 mov r6, r0 */
/* @0x122824 mov r0, r4 */
/* @0x122828 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12282c mov r1, #5 */
/* @0x122830 mov r3, r0 */
/* @0x122834 mov r0, r4 */
/* @0x122838 str r3, [sp, #0x1c] */
/* @0x12283c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122840 mov r1, #6 */
/* @0x122844 mov r11, r0 */
/* @0x122848 mov r0, r4 */
/* @0x12284c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122850 mov r1, #7 */
/* @0x122854 mov r10, r0 */
/* @0x122858 mov r0, r4 */
/* @0x12285c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x122860 mov r1, #8 */
/* @0x122864 mov r9, r0 */
/* @0x122868 mov r0, r4 */
/* @0x12286c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122870 ldr r3, [sp, #0x1c] */
/* @0x122874 str r11, [sp, #0x4] */
/* @0x122878 mov r1, r8 */
/* @0x12287c str r10, [sp, #0x8] */
/* @0x122880 mov r2, r7 */
/* @0x122884 str r3, [sp] */
/* @0x122888 mov r3, r6 */
/* @0x12288c str r9, [sp, #0xc] */
/* @0x122890 str r0, [sp, #0x10] */
/* @0x122894 mov r0, r5 */
/* @0x122898 bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf> */
/* @0x12289c add sp, sp, #44 */
/* @0x1228a0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ══ 5/5  F_DrawTextColor  0x121fd8  size 212  53 条（无 literal pool）
 * @func 0x121fd8 0x1220a8  size 212  53 条（53 条指令，无池）
 * 符号 _Z15F_DrawTextColorR6RValueP9CInstanceS2_iPS_
 * GML: draw_text_colour(x, y, string, col1, col2, col3, col4, alpha)   —— 8 个位置参数
 * 参数: args = [sp+0x48]（0x121fe8：push 36 + sub 36）；局部槽 [sp+0x1c] = 文本指针，先清 0
 *       （0x121fe4 mov r5,#0 / 0x121ff0 str r5,[r2,#-0x4]!，r2 = sp+32 → 落 [sp+0x1c]）
 *
 *   GetTextFromArg(&args[2], 1024, &text);            // 0x121ff4 add r0,r4,#32（32 = 2*16）
 *                                                     // 0x121ff8 bl 0x121ce0
 *   x = YYGetFloat(0);  y = YYGetFloat(1);             // 0x122004 → r5、0x122014 → r6
 *   text = [sp+0x1c] → r10;                            // 0x12201c
 *   col1 = YYGetInt32(3) → r11;                        // 0x122028
 *   col2 = YYGetInt32(4) → r9;                         // 0x122038
 *   col3 = YYGetInt32(5) → r8;                         // 0x122048
 *   col4 = YYGetInt32(6) → r7;                         // 0x122058
 *   alpha = YYGetFloat(7) → r0;                        // 0x122068
 *   GR_Text_Draw_Color(x, y, text, -1, -1, col1, col2, col3, col4, alpha);   // 0x122098 bl 0x173338
 *      r0=x(r5) 0x122094, r1=y(r6) 0x122078, r2=text(r10) 0x122070,
 *      r3 = -1（0x12206c mvn r12,#0 → 0x122074 mov r3,r12），
 *      [sp] = -1（0x12207c str r12,[sp]）、[sp+4]=col1 0x122080、[sp+8]=col2 0x122084、
 *      [sp+0xc]=col3 0x122088、[sp+0x10]=col4 0x12208c、[sp+0x14]=alpha 0x122090
 *   签名 _Z18GR_Text_Draw_ColorffPKciijjjjf 与落位互证：x,y,text + 两个 i（都被填 -1，是 sep/间距类
 *   的独立参数）+ 四个 j（四色）+ alpha。
 *   MemoryManager::Free(text);                         // 0x1220a0/0x1220a4（GetTextFromArg 每次都给新缓冲）
 *
 * 下标 2 被「跳过」不是遗漏：0/1 = x,y，**2 = 文本**（由 GetTextFromArg 单独取，args+32），3..6 = 四色，
 * 7 = alpha。同族的 draw_text(0x121d70)、draw_text_transformed(0x121ddc)、draw_text_ext(0x121e84)、
 * draw_text_ext_transformed(0x121f10) 用同一 helper、同一 1024 长度、同一 Free —— 五兄弟同一模板。
 * GetTextFromArg 内部是 Alloc(1024) → STRING_RValue 追加 → ReAlloc 到精确长度，所以 text 恒非 NULL
 * （非字符串实参得到空串），Free 前无需判空。
 */

/* ---- 5/5 F_DrawTextColor 0x121fd8..0x1220a8（无池） ---- */
/* @0x121fd8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x121fdc sub sp, sp, #36 */
/* @0x121fe0 add r2, sp, #32 */
/* @0x121fe4 mov r5, #0 */
/* @0x121fe8 ldr r4, [sp, #0x48] */
/* @0x121fec mov r1, #1024 */
/* @0x121ff0 str r5, [r2, #-0x4]! */
/* @0x121ff4 add r0, r4, #32 */
/* @0x121ff8 bl 0x121ce0 <_Z14GetTextFromArgPK6RValueiPPc> */
/* @0x121ffc mov r1, r5 */
/* @0x122000 mov r0, r4 */
/* @0x122004 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122008 mov r1, #1 */
/* @0x12200c mov r5, r0 */
/* @0x122010 mov r0, r4 */
/* @0x122014 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122018 mov r1, #3 */
/* @0x12201c ldr r10, [sp, #0x1c] */
/* @0x122020 mov r6, r0 */
/* @0x122024 mov r0, r4 */
/* @0x122028 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12202c mov r1, #4 */
/* @0x122030 mov r11, r0 */
/* @0x122034 mov r0, r4 */
/* @0x122038 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12203c mov r1, #5 */
/* @0x122040 mov r9, r0 */
/* @0x122044 mov r0, r4 */
/* @0x122048 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12204c mov r1, #6 */
/* @0x122050 mov r8, r0 */
/* @0x122054 mov r0, r4 */
/* @0x122058 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12205c mov r1, #7 */
/* @0x122060 mov r7, r0 */
/* @0x122064 mov r0, r4 */
/* @0x122068 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x12206c mvn r12, #0 */
/* @0x122070 mov r2, r10 */
/* @0x122074 mov r3, r12 */
/* @0x122078 mov r1, r6 */
/* @0x12207c str r12, [sp] */
/* @0x122080 str r11, [sp, #0x4] */
/* @0x122084 str r9, [sp, #0x8] */
/* @0x122088 str r8, [sp, #0xc] */
/* @0x12208c str r7, [sp, #0x10] */
/* @0x122090 str r0, [sp, #0x14] */
/* @0x122094 mov r0, r5 */
/* @0x122098 bl 0x173338 <_Z18GR_Text_Draw_ColorffPKciijjjjf> */
/* @0x12209c ldr r0, [sp, #0x1c] */
/* @0x1220a0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1220a4 add sp, sp, #36 */
/* @0x1220a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
