/* cally 逆向卡：Builtins_Draw2（原版 libyoyo.so，armv7）—— 5 个绘制 / 3D / IAP 内建
 * 节: 5 个 @func 小节，顺序 = draw_sprite / draw_text / d3d_set_fog / iap_acquire /
 *     iap_purchase_details（= 索引文件的段落顺序，不是 GML 字典序，也不是地址序）
 * 索引: asm/index-builtins_draw2_all.tsv —— 208 条，5 段互不连续的区间，覆盖 5 个函数
 *   段A 0x122748..0x1227bc  30 条  F_DrawSprite
 *   段B 0x121d70..0x121dd8  27 条  F_DrawText
 *   段C 0x143ba8..0x143c04  24 条  F_D3DSetFog
 *   段D 0x155070..0x1551ec  94 条  F_IAP_Acquire（86 指令 + 8 池字 0x1551d0..0x1551ec）
 *   段E 0x153450..0x1534d0  33 条  F_IAP_PurchaseDetails（31 指令 + 2 池字 0x1534cc/0x1534d0）
 * 级别: 正文（五个函数的形参落位、取值下标、调用/尾跳的实参映射、ret 写入点全部逐条落锚；
 *      被调的绘制层 / JNI 层内部不展开 —— 本卡只证「调用了谁、按什么顺序传了什么、返回值写到哪」，
 *      不证像素/裁剪/混合，也不证 Java 侧的方法名）
 *      正文的边界：段A/B/C 已到「可改写为等价 C」的程度；段D/段E 的函数体同样逐条复原，但被调的
 *      五个静态助手（0x15327c / 0x153020 / 0x1533a0 / 0x154a70 / 0x153acc）只钉到本卡用到的行为
 *      （入参、返回值、写入点、失败分支），它们自己的其余分支不展开。
 * 符号: 五个都取到 .dynsym 的完整签名（size 取自 asm/functions.tsv）
 *   F_DrawSprite         0x122748  size 120  _Z12F_DrawSpriteR6RValueP9CInstanceS2_iPS_
 *   F_DrawText           0x121d70  size 108  _Z10F_DrawTextR6RValueP9CInstanceS2_iPS_
 *   F_D3DSetFog          0x143ba8  size  96  _Z11F_D3DSetFogR6RValueP9CInstanceS2_iPS_
 *   F_IAP_Acquire        0x155070  size 384  _Z13F_IAP_AcquireR6RValueP9CInstanceS2_iPS_
 *   F_IAP_PurchaseDetails 0x153450 size 132  _Z21F_IAP_PurchaseDetailsR6RValueP9CInstanceS2_iPS_
 *
 * ── 统一调用约定（五个函数一致，逐节各自落锚）────────────────────────────
 *   void F(r0 = RValue& ret, r1 = CInstance* self, r2 = CInstance* other,
 *          r3 = int argc, 入口 [sp+0..3] = RValue* args)
 *   RValue 16 字节：+0x0 载荷低字、+0x4 载荷高字、+0xc tag（0 = real/double、1 = string —
 *     由本节 §1 的 GetSpriteIndices 与 §4 的 id 查表两处 tag 分支互证）；
 *     &args[i] = args + i*16。
 *   args 在函数体内从 [sp + (push 字节 + sub 字节)] 取，五个函数各不相同：
 *     0x122748 → [sp+0x20]（push 20 + sub 12）
 *     0x121d70 → [sp+0x20]（push 12 + sub 20）
 *     0x143ba8 → [sp+0x18]（push 24，无 sub）
 *     0x155070 → [sp+0x60]（push 36 + sub 60）
 *     0x153450 → [sp+0x10]（push 16，无 sub）
 *
 * ── 四条跨函数硬事实 ─────────────────────────────────────────────────
 *   1. **五个函数一次都没读 argc**：r3 在被用到之前就被覆盖 ——
 *      draw_sprite 用 `add r3, sp, #4` 换成第 4 个出参、draw_text/d3d_set_fog 用
 *      `mov r3, r12` / `sxth r3, r0` 换成实参、iap_acquire 用 `mov r3, r2` 清零、
 *      iap_purchase_details 用 `ldr r3, [pc, #0x48]` 换成 GOT 偏移。
 *      缺参不由被调方兜：少传参 = 直接越界读 args[]，靠「调用点 argc == 内建表登记值」保证。
 *   2. **三个 draw/3D 内建一次都没写 ret**：draw_sprite 与 d3d_set_fog 全函数 **0 条 store**；
 *      draw_text 的 2 条 store 全落在自己的栈帧（清 buf 槽、传出第 5 个实参）。
 *      ret 由 VM 派发层预置 —— 与 Builtins_Draw.c 的五个 draw_* 完全一致。
 *   3. **两个 IAP 内建反过来一定写 ret，而且写两次**：进场先把 ret 预置成失败值
 *      （acquire = -1.0、purchase_details = 0.0，tag 一律 0），成功路径再改写成
 *      (real)槽号 / 1.0。这是本批 5 个里唯一「有返回值」的一类。
 *   4. **IAP 内建不碰 JNI**：iap_acquire 的 6 条 bl 全是 GameMaker 侧符号（YYGetString、
 *      两个静态助手、YYStrDup、CDS_Map 装配器、状态分派器），iap_purchase_details 的 3 条 bl 同理；
 *      两函数体内 0 处 getJNIEnv / _JNIEnv::* / 0x29c / 0x5c。acquire 的错误路径上有一条 blx，
 *      但那是「单例->vt[3]」—— 若是 JNIEnv 表，第 3 项是 GetVersion（无参、返回 int），
 *      与「传两个串」不符，故不是 JNI 调用。真 JNI 在三跳之后（见文末跨节块）。
 *
 * ── open ─────────────────────────────────────────────────────────────
 *   1. .rodata 串只给地址不给内容：0x346130 / 0x346138 / 0x346140 / 0x346150（acquire 的 4 个
 *      map 键）、0x3462c0（acquire 的错误/日志格式串）、0x346158（0x153acc 的日志串）、
 *      0x339fbc（GetSpriteIndices 在 Sprite_Exists 返回 0 时传给 Error_Show_Action 的串）。本 worktree 只有索引与指令流，
 *      没有 libyoyo.so 本体也没有 rodata 转储，无法读出字面量 ⇒ 本节不写串内容。
 *   2. 4 个相邻 GOT 槽 0x3efad0 / 0x3efad4 / 0x3efad8 / 0x3efadc（外加 0x3efacc、0x3ef948）
 *      的槽内容（→ .bss 地址）未解析，因此商品表 / 状态表 / IAP 状态字都没有正式名。
 *   3. 段D 的 vldr 目标 0x1551c8 不在索引区间（索引在 0x1551c4 的 nop 之后直接跳到 0x1551d0），
 *      该池字值未知；但它只喂给两条随后被字符串覆盖的记录，不进最终 map。
 *   4. 0x153acc 的状态字取值域（-2..2，跳表五格）与「单例 vt+0xc」被调方法的语义未定。
 *   5. 0x15327c 用槽 0x3efad8 的第 0 字当查表边界，iap_acquire 却用槽 0x3efadc 的第 0 字当
 *      越界边界 —— 两槽是否指向同一对象未定。若不同，则同一次调用里两条边界可能不一致。
 *   6. draw_sprite 在 GetSpriteIndices（内部已 Sprite_Exists）之后又 Sprite_Data 一次，
 *      这次重复查表的动机静态不可见，只证「调了两次」。
 *   7. 0x15327c 的非字符串/非数值 tag 路（0x153378）以 `mov r1, #0` 当作 strcmp 的第二参，
 *      即拿 NULL 去比 —— 是否为不可达死代码未定。
 */

/* ══ 1/5  F_DrawSprite  0x122748  size 120  30 条（全是指令，无 literal pool）
 * @func 0x122748 0x1227bc  size 120  30 条
 * 符号 _Z12F_DrawSpriteR6RValueP9CInstanceS2_iPS_   GML: draw_sprite(sprite, subimg, x, y)
 * 参数: args = [sp+0x20]（0x122758，push 20 + sub 12）。argc(r3) 在 0x122754 被 `add r3, sp, #4` 覆盖。
 *
 *   // 入口 r0 = &ret、r1 = self、r2 = other、r3 = argc
 *   int sprite, subimg;                                   // 两个出参就在本帧：sprite=sp、subimg=sp+4
 *   if (!GetSpriteIndices(self, args, &sprite, &subimg))  // 0x122764（r0=r1=self、r1=args、r2=sp、r3=sp+4）
 *       return;                                           // 0x122768/6c → 0x122770/74 直接 epilogue
 *   cs = Sprite_Data(sprite);                             // 0x122778 ldr r0,[sp] / 0x12277c bl
 *   x  = YYGetFloat(args, 2);                             // 0x122790 → r5（下标常量 2 在 0x122780 先装 r1）
 *   y  = YYGetFloat(args, 3);                             // 0x1227a0 → r0（下标常量 3 在 0x122794）
 *   CSprite::DrawSimple(cs, subimg, x, y);                // 0x1227b4 bl，返回后 0x1227b8/0x1227bc epilogue
 *   // 不写 ret（全函数 0 条 store），不读 argc
 *
 * ── 形参表（4 个 GML 位置参数，一个都不浪费）─────────────────────────
 *   args[0] sprite → GetSpriteIndices 内部 YYGetInt32(args, 0) → Sprite_Exists → Sprite_Data
 *   args[1] subimg → GetSpriteIndices 内部 YYGetInt32(args, 1)；< 0 时取调用者 image_index
 *   args[2] x      → YYGetFloat(args, 2) → DrawSimple 的 r2
 *   args[3] y      → YYGetFloat(args, 3) → DrawSimple 的 r3
 *   注意 subimg 与 sprite 不是本函数自己解析的，全部由 GetSpriteIndices（0x1226c4，size 132）代劳；
 *   本函数只把两个出参从栈里取回来（0x122778 ldr r0,[sp]、0x122784 ldr r6,[sp,#4]）。
 *
 * ── GetSpriteIndices 的两条硬事实（决定 draw_sprite 的失败行为）──────────
 *   a) subimg < 0 的默认值来自调用实例：vldr s15,[r7,#0x90]（CInstance+0x90 的 float）
 *      → vcvt.f64.f32 → floor → vcvt.s32.f64 → 写回出参（0x122724..0x122740）。
 *   b) sprite 不存在时它自己弹错误框：Sprite_Exists 返回 0 → Error_Show_Action(.rodata 0x339fbc,
 *      false)（0x12270c/0x122718，r1 = 0），然后返回 0。draw_sprite 收到 0 就静默 return ——
 *      **报错发生在被调方，出图失败这件事在本函数里没有任何日志**。
 *
 * ── CSprite 调用形 ────────────────────────────────────────────────
 *   调的是 CSprite::DrawSimple(int, float, float)（0x1ecab4，size 784），4 参 (this, subimg, x, y)，
 *   不是九参的 CSprite::Draw(this, subimg, x, y, xs, ys, rot, colour, alpha)。
 *   与 Builtins_Draw.c 里 draw_background 的 sprite 路同一个目标函数、同一种 r1/r2/r3 排法
 *   （r1 = 子图号、r2 = x、r3 = y），区别只有两处：那里 subimg 是常量 0 且走尾跳，
 *   这里 subimg 来自参数且是普通 bl。
 *   **Sprite_Data 的返回值不判 NULL**：0x12277c 之后没有 cmp/subs 也没有 beq，cs 直接当 this 传下去
 *   （draw_background 那条路是判了的）。GetSpriteIndices 已经 Sprite_Exists 过，
 *   所以「不存在」在上一段就被拦掉 —— 但 Sprite_Data 仍可能因别的原因返回 0，本函数不兜。
 */

/* ---- 1/5 F_DrawSprite 代码 0x122748..0x1227bc ---- */
/* @0x122748 push {r4, r5, r6, r7, lr} */
/* @0x12274c sub sp, sp, #12 */
/* @0x122750 mov r0, r1 */
/* @0x122754 add r3, sp, #4 */
/* @0x122758 ldr r4, [sp, #0x20] */
/* @0x12275c mov r2, sp */
/* @0x122760 mov r1, r4 */
/* @0x122764 bl 0x1226c4 <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_> */
/* @0x122768 cmp r0, #0 */
/* @0x12276c bne 0x122778 <_Z12F_DrawSpriteR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x122770 add sp, sp, #12 */
/* @0x122774 pop {r4, r5, r6, r7, pc} */
/* @0x122778 ldr r0, [sp] */
/* @0x12277c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x122780 mov r1, #2 */
/* @0x122784 ldr r6, [sp, #0x4] */
/* @0x122788 mov r7, r0 */
/* @0x12278c mov r0, r4 */
/* @0x122790 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x122794 mov r1, #3 */
/* @0x122798 mov r5, r0 */
/* @0x12279c mov r0, r4 */
/* @0x1227a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1227a4 mov r1, r6 */
/* @0x1227a8 mov r2, r5 */
/* @0x1227ac mov r3, r0 */
/* @0x1227b0 mov r0, r7 */
/* @0x1227b4 bl 0x1ecab4 <_ZN7CSprite10DrawSimpleEiff> */
/* @0x1227b8 add sp, sp, #12 */
/* @0x1227bc pop {r4, r5, r6, r7, pc} */


/* ══ 2/5  F_DrawText  0x121d70  size 108  27 条（全是指令，无 literal pool）
 * @func 0x121d70 0x121dd8  size 108  27 条
 * 符号 _Z10F_DrawTextR6RValueP9CInstanceS2_iPS_   GML: draw_text(x, y, string)
 * 参数: args = [sp+0x20]（0x121d80，push 12 + sub 20）。argc(r3) 在 0x121db8 被 `mov r3, r12` 覆盖。
 *
 *   char* buf = NULL;                                    // 0x121d88 str r5,[r2,#-0x4]!（r2=sp+16 → 槽 sp+0xc）
 *   GetTextFromArg(&args[2], 1024, &buf);                // 0x121d8c add r0,r4,#32（args+0x20 = &args[2]）
 *                                                        // 0x121d90 bl；r1=1024 在 0x121d84、r2=&buf 在 0x121d78
 *   x = YYGetFloat(args, 0);                             // 0x121d9c → r5（下标常量 0 复用 r5=0，0x121d94）
 *   y = YYGetFloat(args, 1);                             // 0x121dac → r0（下标常量 1 在 0x121da0）
 *   GR_Text_Draw(x, y, buf, -1, -1);                     // 0x121dc8 bl；r3=-1（0x121db0 mvn r12,#0 → 0x121db8）
 *                                                        // 第 5 个 -1 走栈：[sp]（0x121dbc）、r2=buf（0x121db4）
 *   MemoryManager::Free(buf);                            // 0x121dcc ldr r0,[sp,#0xc] / 0x121dd0 bl
 *   // 不写 ret（2 条 store 全在本地帧），不读 argc
 *
 * ── 形参序是 (x, y, string)，不是 (string, x, y) ─────────────────────
 *   证据就是 `add r0, r4, #32`：RValue 16 字节，args+0x20 只能等于 &args[2]。
 *   这同时解释了为什么本函数不像第 1 节那样需要 GetSpriteIndices 式的双出参助手 ——
 *   字符串是第 3 个参数，直接按固定偏移取。**必须先取串再做两次 YYGetFloat**（顺序在锚点里可见），
 *   也就是说参数解析与字符串物化是同一次线性下降，没有 argc 驱动的循环。
 *
 * ── GetTextFromArg 的调用形（0x121ce0，size 144）────────────────────
 *   void GetTextFromArg(RValue const* arg, int size, char** out)
 *     1) p = MemoryManager::Alloc(size, file, 0x947, true)      // 0x121d0c，1024 字节
 *     2) p[0] = 0; STRING_RValue(&p, &end, &cap, arg)           // 0x121d34，把 RValue 摊成 C 串
 *     3) *out = MemoryManager::ReAlloc(p, end-p+1, file, 74, 0) // 0x121d58，缩到 长度+1
 *   所以 draw_text 拿到的 buf 是「精确长度」的堆块，用完自己 Free —— 谁分配谁释放，
 *   不是借用 RValue 内部指针。Alloc/ReAlloc 的 file/line 常量分别是 0x947(=2375) 与 74。
 *
 * ── 两个硬编码常量 ────────────────────────────────────────────────
 *   r3 = -1 与 [sp] = -1：颜色与 alpha 都传「-1」，即这两个参数本函数不接受、恒走默认。
 *   缓冲上限 1024 也是硬编码（不是参数）。
 */

/* ---- 2/5 F_DrawText 代码 0x121d70..0x121dd8 ---- */
/* @0x121d70 push {r4, r5, lr} */
/* @0x121d74 sub sp, sp, #20 */
/* @0x121d78 add r2, sp, #16 */
/* @0x121d7c mov r5, #0 */
/* @0x121d80 ldr r4, [sp, #0x20] */
/* @0x121d84 mov r1, #1024 */
/* @0x121d88 str r5, [r2, #-0x4]! */
/* @0x121d8c add r0, r4, #32 */
/* @0x121d90 bl 0x121ce0 <_Z14GetTextFromArgPK6RValueiPPc> */
/* @0x121d94 mov r1, r5 */
/* @0x121d98 mov r0, r4 */
/* @0x121d9c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x121da0 mov r1, #1 */
/* @0x121da4 mov r5, r0 */
/* @0x121da8 mov r0, r4 */
/* @0x121dac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x121db0 mvn r12, #0 */
/* @0x121db4 ldr r2, [sp, #0xc] */
/* @0x121db8 mov r3, r12 */
/* @0x121dbc str r12, [sp] */
/* @0x121dc0 mov r1, r0 */
/* @0x121dc4 mov r0, r5 */
/* @0x121dc8 bl 0x172df8 <_Z12GR_Text_DrawffPKcii> */
/* @0x121dcc ldr r0, [sp, #0xc] */
/* @0x121dd0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x121dd4 add sp, sp, #20 */
/* @0x121dd8 pop {r4, r5, pc} */


/* ══ 3/5  F_D3DSetFog  0x143ba8  size 96  24 条（全是指令，无 literal pool）
 * @func 0x143ba8 0x143c04  size 96  24 条
 * 符号 _Z11F_D3DSetFogR6RValueP9CInstanceS2_iPS_   GML: d3d_set_fog(enable, colour, start, end)
 * 参数: args = [sp+0x18]（0x143bb0，push 24，无 sub）。argc(r3) 在 0x143bf8 被 `sxth r3, r0` 覆盖。
 *
 *   bool  enable = YYGetBool(args, 0);                   // 0x143bb8（下标 0 在 0x143bac）→ r5
 *   int   colour = lrint(YYGetReal(args, 1));            // 0x143bc8 YYGetReal → 0x143bcc lrint@plt → r7
 *   short start  = (short)YYGetInt32(args, 2);           // 0x143bdc → r6 → 0x143bf4 sxth → r2
 *   short end    = (short)YYGetInt32(args, 3);           // 0x143bec → r0 → 0x143bf8 sxth → r3
 *   GR_D3D_Set_Fog(enable, colour, start, end);          // 0x143c00 pop / 0x143c04 b（尾跳 0x168520）
 *   // 不写 ret，不读 argc；全函数 0 条 store
 *
 * ── 四条取参通道各不相同（这张卡里唯一一个「四种取法都用上」的函数）──────
 *   args[0] → YYGetBool        布尔
 *   args[1] → YYGetReal+lrint  先当 double 再四舍五入成 int —— **不是** YYGetInt32
 *   args[2] → YYGetInt32+sxth  先当 int 再截到 16 位
 *   args[3] → 同上
 *   后果：colour 走的是浮点通道（GML 里写十六进制颜色常量也按 real 过来再 lrint）；
 *   start/end 超出 16 位会被 sxth 静默截断 —— GR_D3D_Set_Fog 的形参就是 short：
 *   _Z14GR_D3D_Set_Fogbjss 的四个字母 b/j/s/s = (bool, unsigned int, short, short)。签名与 4 个实参一一对上。
 *
 * ── 纯尾跳 ────────────────────────────────────────────────────────
 *   0x143c00 先把 r4..r8 与 lr 全部弹出，0x143c04 直接 b —— 本函数没有自己的 epilogue，
 *   也不可能有 ret 写入。这是 5 个里唯一一个「零本地副作用、纯转发」的内建
 *   （lrint 的舍入是唯一的运算）。
 */

/* ---- 3/5 F_D3DSetFog 代码 0x143ba8..0x143c04 ---- */
/* @0x143ba8 push {r4, r5, r6, r7, r8, lr} */
/* @0x143bac mov r1, #0 */
/* @0x143bb0 ldr r4, [sp, #0x18] */
/* @0x143bb4 mov r0, r4 */
/* @0x143bb8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x143bbc mov r1, #1 */
/* @0x143bc0 mov r5, r0 */
/* @0x143bc4 mov r0, r4 */
/* @0x143bc8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x143bcc bl 0xb66e8 <lrint@plt> */
/* @0x143bd0 mov r1, #2 */
/* @0x143bd4 mov r7, r0 */
/* @0x143bd8 mov r0, r4 */
/* @0x143bdc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x143be0 mov r1, #3 */
/* @0x143be4 mov r6, r0 */
/* @0x143be8 mov r0, r4 */
/* @0x143bec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x143bf0 mov r1, r7 */
/* @0x143bf4 sxth r2, r6 */
/* @0x143bf8 sxth r3, r0 */
/* @0x143bfc mov r0, r5 */
/* @0x143c00 pop {r4, r5, r6, r7, r8, lr} */
/* @0x143c04 b 0x168520 <_Z14GR_D3D_Set_Fogbjss> */


/* ══ 4/5  F_IAP_Acquire  0x155070  size 384  94 条（86 条指令 + 8 个池字 0x1551d0..0x1551ec）
 * @func 0x155070 0x1551c0  size 384  94 条（86 条指令 + 8 个池字 0x1551d0/0x1551d4/0x1551d8/
 *       0x1551dc/0x1551e0/0x1551e4/0x1551e8/0x1551ec）
 * 符号 _Z13F_IAP_AcquireR6RValueP9CInstanceS2_iPS_   GML: iap_acquire(...)
 * 参数: args = [sp+0x60]（0x155080，push 36 + sub 60）。argc(r3) 在 0x155084 被 `mov r3, r2` 覆盖。
 *
 *   // ── ① 预置失败值：ret = -1.0（tag 0 = real）────────────────────────
 *   ret.tag = 0;                                        // 0x15508c str r3,[r0,#0xc]（r3 = 0，0x155084）
 *   ret.hi  = 0xbff00000;                               // 0x155090 movt r2,#0xbff0 / 0x155094 str r2,[r0,#4]
 *   ret.lo  = 0;                                        // 0x155098 str r3,[r6]（r6 = ret，0x155078）
 *   // 0xBFF00000_00000000 = -1.0。tag 只在这里写一次，全函数再没有第二次写 tag ⇒ 恒为 0
 *
 *   // ── ② 两个参数 ────────────────────────────────────────────────
 *   pid = YYGetString(args, 1);                         // 0x1550a0（下标 1 在 0x155088）→ r7
 *   idx = 0x15327c(args);                               // 0x1550ac → 按 args[0] 查商品表，返回下标或 -1
 *   if (idx < 0) goto err;                              // 0x1550b4 blt → 0x1550cc
 *   if (idx >= (*[GOT 0x3efadc])[0]) goto err;          // 0x1550b8/0x1550bc/0x1550c0/0x1550c4/0x1550c8
 *
 *   // ── ③ 商品名 + 状态槽 ─────────────────────────────────────────
 *   name = ((char**)((*[GOT 0x3efadc])[4]))[idx][0];    // 0x1550f8 [r3,#4] / 0x1550fc 下标 / 0x155100 ldr r8,[r3]
 *   slot = 0x153020();                                  // 0x155104 → 状态槽分配（见下）
 *   st   = ((void**)((*[GOT 0x3efad4])[4]))[slot];      // 0x155108/0x15510c/0x155110/0x155114 → r9
 *   r4   = slot;                                        // 0x155118
 *   if (st[1]) YYFree(st[1]);                           // 0x15511c/0x155120/0x155124/0x155128
 *   st[1] = YYStrDup(name);                             // 0x15512c/0x155134 → 0x155174 str r0,[r9,#4]
 *
 *   // ── ④ 装 4 条记录的 CDS_Map（0x154a70：new(4) + CDS_Map::CDS_Map + 4× Add）──
 *   d = (double)slot;                                   // 0x155138 vmov s15,r4 / 0x155144 vcvt.f64.s32
 *   map = 0x154a70(4, rec0, rec1, rec2, rec3);          // 0x155188 mov r0,#4 … 0x1551a4 bl
 *   // recN 是 16 字节记录 {char* key; double value; char* str}，4 条跨 r1..r3 与栈实参连续铺开：
 *   //   rec0 = { .rodata 0x346130, 1.0,            NULL }        r1 + (r2=0, r3=0x3ff00000) + [sp+0]
 *   //   rec1 = { .rodata 0x346138, 池字 0x1551c8,  name }        [sp+4] + vstr d7,[sp,#8] + [sp+0x10]=r8
 *   //   rec2 = { .rodata 0x346150, 池字 0x1551c8,  pid  }        [sp+0x14] + vstr d7,[sp,#24] + [sp+0x20]=r7
 *   //   rec3 = { .rodata 0x346140, (double)slot,   NULL }        [sp+0x24] + strd r4,r5,[sp,#40] + [sp+0x30]=0
 *   // 装配器对每条记录做两件事：YYSetString(keyRValue, key)；valueRValue ← double，
 *   // 若记录的 str 非空就用 YYSetString 把 valueRValue 覆盖成字符串，最后 CDS_Map::Add(&key,&value)。
 *   // ⇒ 4 条 map 项的值类型是 real, string, string, real（rec1/rec2 的池字 double 被覆盖，故其值不影响结果）。
 *
 *   // ── ⑤ 分派 + 回写 ret ─────────────────────────────────────────
 *   0x153acc(map, 1);                                   // 0x1551a8 mov r1,#1 / 0x1551ac bl（状态分派，见下）
 *   ret.lo = r4; ret.hi = r5;                           // 0x1551b0/0x1551b4/0x1551b8 stm r6,{r2,r3}
 *   return;                                             // 0x1551bc/0x1551c0（ret = (real)slot）
 * err:                                                  // 0x1550cc..0x1550f4，ret 保持 -1.0
 *   obj = *(*[GOT 0x3ef948]);                           // 0x1550cc/0x1550d8/0x1550e0
 *   obj->vt[3](obj, .rodata 0x3462c0, pid);             // 0x1550d4 ldr r1,[pc,#0xfc] → 0x1550dc add r1,pc,r1
 *                                                       // 0x1550e0/0x1550e4/0x1550e8/0x1550ec → blx r3
 *
 * ── 三个被调静态助手（在 .text 里都没有独立符号，objdump 用「前一个全局符号+偏移」显示）──
 *   0x15327c（117 条）「按 args[0] 查表」：
 *     tag = args[0].tag；
 *     tag == 0        → i = YYGetInt32(args, 0)；i < 0 或 i >= 槽 0x3efad8 的第 0 字 → -1，否则返回 i
 *                       （0x153304 bl、0x15330c blt、0x153310..0x153320 取边界并 mvnge -1）
 *     tag&0xffffff==1 → 用 [[args[0]]]（CString→char*）与每条 entry[0] strcmp，命中返回下标（0x15332c 起）
 *     其它             → -1（0x1532bc/0x1532f8）
 *     边界用槽 0x3efad8 的第 0 字、数组用槽 0x3efadc 的 +4（0x153294/0x1532a8）。
 *   0x153020（128 条）「状态槽分配」：拿槽 0x3efad0 的计数与槽 0x3efad4 的容器（[+0] 容量、[+4] 数组）；
 *     有容量就在数组里找空位、满了就 MemoryManager::SetLength(&容器[4], n*4, file, 190) 扩
 *     （0x153128 mov r3,#190 / 0x153130 bl，行号 190）；每个槽 new(32)，
 *     逐字清 0 但 **+0x1c 置 -1**（0x1530ac/0x1530f4 mvn r12,#1），返回槽号。
 *   0x1533a0（0x1533a0..0x15344c）「按 args[0] 查购买记录」：tag==0 → 尾调 YYGetInt32(args,0)，**完全不做
 *     边界检查**（0x153440 pop + b，返回什么就用什么）；tag 非 0 非 1 → -1（0x1533bc）；字符串 → 与 entry[0]
 *     strcmp，边界与数组都用槽 0x3efad0 / 0x3efad4，与 iap_purchase_details 本体的两道门同源
 *     （0x1533e0/0x1533f4 解出 0x3efad0 / 0x3efad4）。
 *
 * ── 0x153acc「状态分派」（0x153acc..0x153b3c，状态字取自 GOT 槽 0x3efacc 的第 0 字）──────
 *   入口 r0 = map、r1 = flag（iap_acquire 恒传 1）。跳表 0x153afc..0x153b0c，索引 = state+2，
 *   只有 state ∈ [-2,2] 落在表内；表外直接 0x153b38 返回（什么都不做）。
 *     case -2, -1: (0x153b10) r1 != 0 → 单例->vt[3](单例, 串) 后返回；r1 == 0 → 0x153b48 直接派发
 *     case  0,  2: (0x153b58) 先无条件调 单例->vt[3](单例, 串)（另一条串），再取队列句柄：
 *                  句柄 == -1 → DsQueueCreate() 并回写；然后 DsQueueEnqueue(句柄, 1, 0, 0, map)
 *                  5 个实参按 r0..r3 + [sp] 传（0x153b8c str r4,[sp]），最后返回
 *     case  1:    (0x153b40) r1 == 0 → 0x153ba8 打日志后返回；r1 != 0 → 0x153b48 tail 0x153710(map)
 *     default:    (0x153b38) 直接返回
 *   ⇒ 对 iap_acquire 而言（r1 恒 1）：state 0/2 = 入队、state 1 = 同步走真派发、state -2/-1 = 只打日志、
 *     其余 = 静默返回。也就是说 **acquire 的请求未必当场发出**，也未必发得出去。
 *   注意 state -2/-1 与 state 1 的 r1 分支方向相反（前者 r1 非 0 才打日志，后者 r1 为 0 才打日志），
 *   这不是笔误 —— 两条路的 cmp/beq 目标在锚点里是反的。
 */

/* ---- 4/5 F_IAP_Acquire 代码 0x155070..0x1551ec ---- */
/* @0x155070 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x155074 sub sp, sp, #60 */
/* @0x155078 mov r6, r0 */
/* @0x15507c mov r2, #0 */
/* @0x155080 ldr r4, [sp, #0x60] */
/* @0x155084 mov r3, r2 */
/* @0x155088 mov r1, #1 */
/* @0x15508c str r3, [r0, #0xc] */
/* @0x155090 movt r2, #0xbff0 */
/* @0x155094 str r2, [r0, #0x4] */
/* @0x155098 str r3, [r6] */
/* @0x15509c mov r0, r4 */
/* @0x1550a0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1550a4 mov r7, r0 */
/* @0x1550a8 mov r0, r4 */
/* @0x1550ac bl 0x15327c <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1550b0 cmp r0, #0 */
/* @0x1550b4 blt 0x1550cc <_Z13F_IAP_AcquireR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x1550b8 ldr r3, [pc, #0x110] */
/* @0x1550bc ldr r3, [pc, r3] */
/* @0x1550c0 ldr r2, [r3] */
/* @0x1550c4 cmp r0, r2 */
/* @0x1550c8 blt 0x1550f8 <_Z13F_IAP_AcquireR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x1550cc ldr r3, [pc, #0x100] */
/* @0x1550d0 mov r2, r7 */
/* @0x1550d4 ldr r1, [pc, #0xfc] */
/* @0x1550d8 ldr r3, [pc, r3] */
/* @0x1550dc add r1, pc, r1 */
/* @0x1550e0 ldr r0, [r3] */
/* @0x1550e4 ldr r3, [r0] */
/* @0x1550e8 ldr r3, [r3, #0xc] */
/* @0x1550ec blx r3 */
/* @0x1550f0 add sp, sp, #60 */
/* @0x1550f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1550f8 ldr r3, [r3, #0x4] */
/* @0x1550fc ldr r3, [r3, r0, lsl #2] */
/* @0x155100 ldr r8, [r3] */
/* @0x155104 bl 0x153020 <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x155108 ldr r3, [pc, #0xcc] */
/* @0x15510c ldr r3, [pc, r3] */
/* @0x155110 ldr r3, [r3, #0x4] */
/* @0x155114 ldr r9, [r3, r0, lsl #2] */
/* @0x155118 mov r4, r0 */
/* @0x15511c ldr r0, [r9, #0x4] */
/* @0x155120 cmp r0, #0 */
/* @0x155124 beq 0x15512c <_Z13F_IAP_AcquireR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x155128 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x15512c mov r0, r8 */
/* @0x155130 ldr r11, [pc, #0xa8] */
/* @0x155134 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x155138 vmov s15, r4 */
/* @0x15513c ldr r10, [pc, #0xa0] */
/* @0x155140 mov r12, #0 */
/* @0x155144 vcvt.f64.s32 d7, s15 */
/* @0x155148 ldr lr, [pc, #0x98] */
/* @0x15514c ldr r1, [pc, #0x98] */
/* @0x155150 mov r2, #0 */
/* @0x155154 add lr, pc, lr */
/* @0x155158 add r11, pc, r11 */
/* @0x15515c add r10, pc, r10 */
/* @0x155160 add r1, pc, r1 */
/* @0x155164 mov r3, #0 */
/* @0x155168 movt r3, #0x3ff0 */
/* @0x15516c vmov r4, r5, d7 */
/* @0x155170 vldr d7, [pc, #80] */
/* @0x155174 str r0, [r9, #0x4] */
/* @0x155178 vstr d7, [sp, #8] */
/* @0x15517c vstr d7, [sp, #24] */
/* @0x155180 str lr, [sp, #0x24] */
/* @0x155184 str r12, [sp] */
/* @0x155188 mov r0, #4 */
/* @0x15518c str r12, [sp, #0x30] */
/* @0x155190 strd r4, r5, [sp, #40] */
/* @0x155194 str r8, [sp, #0x10] */
/* @0x155198 str r7, [sp, #0x20] */
/* @0x15519c str r11, [sp, #0x4] */
/* @0x1551a0 str r10, [sp, #0x14] */
/* @0x1551a4 bl 0x154a70 <_Z19YYIAPEventsDispatchv+0xe88> */
/* @0x1551a8 mov r1, #1 */
/* @0x1551ac bl 0x153acc <_Z16InitIAPFunctionsv+0x5f8> */
/* @0x1551b0 mov r2, r4 */
/* @0x1551b4 mov r3, r5 */
/* @0x1551b8 stm r6, {r2, r3} */
/* @0x1551bc add sp, sp, #60 */
/* @0x1551c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1551c4 nop  */
/* ---- literal pool：以下 8 字是池字（3 个 GOT 偏移 0x29aa18/0x298868/0x29a9c0 + 5 个 rodata 偏移 0x1f11dc/0x1f0fd8/0x1f0fec/0x1f0fe4/0x1f0fc8），非指令 ---- */
/* @0x1551d0 eoreq r10, r9, r8, lsl r10 */
/* @0x1551d4 eoreq r8, r9, r8, ror #16 */
/* @0x1551d8 ldrsbeq r1, [pc], -r12 */
/* @0x1551dc eoreq r10, r9, r0, asr #19 */
/* @0x1551e0 ldrsbeq r0, [pc], -r8 */
/* @0x1551e4 andseq r0, pc, r12, ror #31 */
/* @0x1551e8 andseq r0, pc, r4, ror #31 */
/* @0x1551ec andseq r0, pc, r8, asr #31 */


/* ══ 5/5  F_IAP_PurchaseDetails  0x153450  size 132  33 条（31 条指令 + 2 个池字 0x1534cc/0x1534d0）
 * @func 0x153450 0x1534c8  size 132  33 条（31 条指令 + 2 个池字 0x1534cc/0x1534d0）
 * 符号 _Z21F_IAP_PurchaseDetailsR6RValueP9CInstanceS2_iPS_   GML: iap_purchase_details(...)
 * 参数: args = [sp+0x10]（0x153458，push 16，无 sub）。argc(r3) 在 0x15347c 被 `ldr r3, [pc, #0x48]` 覆盖。
 *
 *   // ── ① 预置成功值 0.0（tag 0 = real），失败就不动它 ──────────────────
 *   ret.tag = 0; ret.lo = 0; ret.hi = 0;                // 0x153460 / 0x153464 / 0x153468（r5 = 0，0x153454）
 *
 *   // ── ② 两道门，都是早退（ret 保持 0.0，无任何日志）─────────────────
 *   idx = 0x1533a0(args);                               // 0x153470 → 按 args[0] 查购买记录
 *   if (idx < 0) return;                                // 0x153474 subs / 0x153478 poplt
 *   if (idx >= (*[GOT 0x3efad0])[0]) return;            // 0x15347c/0x153480/0x153484/0x153488/0x15348c popge
 *
 *   // ── ③ 取记录 → 把第 args[1] 号 ds_map 填满 ───────────────────────
 *   p = ((void**)((*[GOT 0x3efad4])[4]))[idx];          // 0x153490/0x15349c/0x1534a0/0x1534a4 → r6
 *   CIAPPurchase::PopulateMap(p, YYGetInt32(args, 1));  // 0x1534a8（下标 1 在 0x153498）/ 0x1534b4
 *
 *   // ── ④ 成功后 ret = 1.0 ───────────────────────────────────────
 *   ret.lo = 0; ret.hi = 0x3ff00000;                    // 0x1534bc str r5,[r4] / 0x1534c0 movt r3,#0x3ff0
 *                                                       // / 0x1534c4 str r3,[r4,#4]
 *   return;                                             // 0x1534c8（ret = 1.0，tag 仍是 0）
 *
 * ── 形参表：两个参数，第二个是 ds_map 的 id ──────────────────────────
 *   args[0] 商品/购买标识 → 0x1533a0 解析：tag==0 直接 YYGetInt32 当下标（不查边界）；
 *            tag&0xffffff==1 用 [[args[0]]] 与每条 entry[0] strcmp；其它 → -1。
 *   args[1] ds_map id（int）→ 原样交给 CIAPPurchase::PopulateMap(int)。
 *   证据链：PopulateMap 一进场就 vcvt.f64.s32 把这个 int 变成 double 塞进一个临时 RValue，
 *   再以 argc=1 调 F_DsMapClear（0x18ae7c）与 8 次 F_DsMapAdd（键值对逐条写）——
 *   能当「map 句柄」被 GameMaker 自己的 ds_map 内建消费的，只能是 ds_map 的 id。
 *   故本题的返回值**不是**详情本身：详情写进调用者给的 map，函数只回 real 1.0/0.0。
 *
 * ── 与 iap_acquire 的三处不对称（都是静态可见的）──────────────────────
 *   1. 失败时**完全静默**：acquire 走单例 vt+0xc 打日志，purchase_details 两条早退直接 pop。
 *   2. 两道门同源：本体 0x15347c 的计数槽与助手 0x1533e0 的计数槽都是 0x3efad0，
 *      所以第二道边界在静态上是冗余的（acquire 那边的两道门用的是 0x3efad8 / 0x3efadc 两个不同槽）。
 *   3. 返回值语义相反：0.0 = 失败 / 1.0 = 成功（acquire 是 -1.0 = 失败 / 槽号 = 成功）。
 */

/* ---- 5/5 F_IAP_PurchaseDetails 代码 0x153450..0x1534d0 ---- */
/* @0x153450 push {r4, r5, r6, lr} */
/* @0x153454 mov r5, #0 */
/* @0x153458 ldr r6, [sp, #0x10] */
/* @0x15345c mov r4, r0 */
/* @0x153460 str r5, [r0, #0xc] */
/* @0x153464 str r5, [r0] */
/* @0x153468 str r5, [r0, #0x4] */
/* @0x15346c mov r0, r6 */
/* @0x153470 bl 0x1533a0 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x153474 subs r2, r0, #0 */
/* @0x153478 poplt {r4, r5, r6, pc} */
/* @0x15347c ldr r3, [pc, #0x48] */
/* @0x153480 ldr r3, [pc, r3] */
/* @0x153484 ldr r3, [r3] */
/* @0x153488 cmp r2, r3 */
/* @0x15348c popge {r4, r5, r6, pc} */
/* @0x153490 ldr r3, [pc, #0x38] */
/* @0x153494 mov r0, r6 */
/* @0x153498 mov r1, #1 */
/* @0x15349c ldr r3, [pc, r3] */
/* @0x1534a0 ldr r3, [r3, #0x4] */
/* @0x1534a4 ldr r6, [r3, r2, lsl #2] */
/* @0x1534a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1534ac mov r1, r0 */
/* @0x1534b0 mov r0, r6 */
/* @0x1534b4 bl 0x18ae38 <_ZN12CIAPPurchase11PopulateMapEi> */
/* @0x1534b8 mov r3, r5 */
/* @0x1534bc str r5, [r4] */
/* @0x1534c0 movt r3, #0x3ff0 */
/* @0x1534c4 str r3, [r4, #0x4] */
/* @0x1534c8 pop {r4, r5, r6, pc} */
/* ---- literal pool：以下 2 字是池字（2 个 GOT 偏移 0x29c648/0x29c630），非指令 ---- */
/* @0x1534cc eoreq r12, r9, r8, asr #12 */
/* @0x1534d0 eoreq r12, r9, r0, lsr r6 */


/* ── 跨节：IAP 到 JNI 的三跳（本节不在锚点范围，只给调用形；行内地址全部可在 asm/functions.tsv 复核）──
 *
 *   第一跳  iap_acquire(0x155070) 只做「装 CDS_Map + 请求状态分派」，两处落点：
 *             state ∈ {0,2} → DsQueueEnqueue(map)            （0x153b58..0x153b9c）
 *             state == 1    → tail 0x153710(map)             （0x153b48..0x153b54）
 *           另一条来路是 HandleAsyncEvents(0x1ce398) → YYIAPEventsDispatch(0x153be8) → 0x153f9c。
 *   第二跳  0x153710（anon，size 1240）是 JNI 派发器：它按事件类型调
 *             IAP_ActivateM(0x16173c) / IAP_RestoreM(0x16186c) / IAP_AcquireM(0x16189c) /
 *             IAP_ConsumeM(0x161940) / IAP_GetProductDetailM(0x161ae8)
 *           调用点：0x1537c8 / 0x153800 / 0x153944 / 0x1539c4 / 0x153a44（都在 0x153710..0x153be4 内）。
 *   第三跳  IAP_AcquireM(char const* pid, char const* extra, int flags) 才是 JNI（41 条）：
 *             env = getJNIEnv()                            0x1618b0
 *             (*env)->v[0x29c](env, pid)   → jstr1         0x1618b8/0x1618bc/0x1618c0
 *             (*env)->v[0x29c](env, extra) → jstr2         0x1618c8..0x1618d8
 *             jclass = *GOT[..]; jmethodID = *GOT[..]      0x1618e4..0x1618fc
 *             _JNIEnv::CallStaticVoidMethod(jclass, jmethodID, jstr1, jstr2, flags)
 *                                                         0x161900 stm sp,{r4,r6} + 0x161904 bl 0xc4ad4
 *             (*env)->v[0x5c](env, jstr1)  → DeleteLocalRef 0x161908..0x161918
 *             (*env)->v[0x5c](env, jstr2)  → DeleteLocalRef 0x16191c..0x16192c
 *           IAP_GetProductDetailM(char const* pid)（25 条）同形，只 1 个 jstring：
 *             0x161af0 getJNIEnv → 0x161af8/0x161afc NewStringUTF → 0x161b28 CallStaticVoidMethod(cls,mid,jstr)
 *             → 0x161b2c/0x161b38 DeleteLocalRef
 *
 *   两个偏移量的含义（级别：narrowed —— _JNIEnv 的访问器符号没导出，无法用符号反证）：
 *     v[0x29c] = JNIEnv 函数表第 167 项 = NewStringUTF；v[0x5c] = 第 23 项 = DeleteLocalRef。
 *     与 JNI 规范表序逐项对齐（167*4 = 0x29c、23*4 = 0x5c），且三次调用都成对出现
 *     （建 1~2 个 local ref、调完就删），语义自洽。CallStaticVoidMethod 本身是真符号（0xc4ad4，size 56），
 *     它是变参 C++ 包装，后两个实参由调用方压栈（stm sp,{r4,r6}）。
 *
 *   结论：**本卡两个 IAP 内建里一个 JNI 符号都没有**（acquire 错误路径那条 blx 是单例虚调用，
 *   若按 JNIEnv 表解释会落在第 3 项 GetVersion 上，参数不符 ⇒ 不是 JNI）。内建层只跟 RValue/表/队列打交道，
 *   JNI 只在「事件派发器 → IAP_*M」这一层出现；acquire 的 JNI 参数只有 (商品号, 附加串, int 标志) 三项，
 *   且商品号与附加串都是 NewStringUTF 现场造的 local ref，出函数前必定双双 DeleteLocalRef。
 *   即：这一层的 Java 方法签名形如 static void m(String, String, int) / static void m(String)，
 *   但方法名与类名要靠 GOT 槽里的 jclass/jmethodID 才能定 —— 本卡不猜（open 1）。
 */
