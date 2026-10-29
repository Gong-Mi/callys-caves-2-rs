/* cally 逆向卡：All_68 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 1245 个函数｜锚点 3832 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/1245 F_MpGridClearAll(RValue&, CInstance*, CInstance*, int, RValue*)  0x108c88  size 24  6 条（0x108c88..0x108ca0）
 * @func 0x108c88 0x108ca0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x108c88 push {r3, lr}
 *   @0x108c8c mov r1, #0
 *   @0x108c90 ldr r0, [sp, #0x8]
 *   @0x108c94 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108c98 pop {r3, lr}
 *   @0x108c9c b 0x19a1d4 <_Z20Motion_Grid_ClearAlli>
 *
 * ══ §2/1245 F_MpGridDraw(RValue&, CInstance*, CInstance*, int, RValue*)  0x108f34  size 24  6 条（0x108f34..0x108f4c）
 * @func 0x108f34 0x108f4c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x108f34 push {r3, lr}
 *   @0x108f38 mov r1, #0
 *   @0x108f3c ldr r0, [sp, #0x8]
 *   @0x108f40 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x108f44 pop {r3, lr}
 *   @0x108f48 b 0x19c1ac <_Z16Motion_Grid_Drawi>
 *
 * ══ §3/1245 F_GameLoad(RValue&, CInstance*, CInstance*, int, RValue*)  0x109c04  size 24  6 条（0x109c04..0x109c1c）
 * @func 0x109c04 0x109c2c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x109c04 push {r3, lr}
 *   @0x109c08 mov r1, #0
 *   @0x109c0c ldr r0, [sp, #0x8]
 *   @0x109c10 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x109c14 pop {r3, lr}
 *   @0x109c18 b 0x1d14fc <_Z16Command_LoadGamePKc>
 *
 * ══ §4/1245 F_GameSave(RValue&, CInstance*, CInstance*, int, RValue*)  0x109c1c  size 24  6 条（0x109c1c..0x109c34）
 * @func 0x109c1c 0x109c44  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x109c1c push {r3, lr}
 *   @0x109c20 mov r1, #0
 *   @0x109c24 ldr r0, [sp, #0x8]
 *   @0x109c28 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x109c2c pop {r3, lr}
 *   @0x109c30 b 0x1d1468 <_Z16Command_SaveGamePKc>
 *
 * ══ §5/1245 F_GameSaveBuffer(RValue&, CInstance*, CInstance*, int, RValue*)  0x109c34  size 24  6 条（0x109c34..0x109c4c）
 * @func 0x109c34 0x109c5c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x109c34 push {r3, lr}
 *   @0x109c38 mov r1, #0
 *   @0x109c3c ldr r0, [sp, #0x8]
 *   @0x109c40 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x109c44 pop {r3, lr}
 *   @0x109c48 b 0x1d07c8 <_Z16Command_SaveGamei>
 *
 * ══ §6/1245 F_GameLoadBuffer(RValue&, CInstance*, CInstance*, int, RValue*)  0x109c4c  size 24  6 条（0x109c4c..0x109c64）
 * @func 0x109c4c 0x109c64  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x109c4c push {r3, lr}
 *   @0x109c50 mov r1, #0
 *   @0x109c54 ldr r0, [sp, #0x8]
 *   @0x109c58 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x109c5c pop {r3, lr}
 *   @0x109c60 b 0x1d0dd8 <_Z16Command_LoadGamei>
 *
 * ══ §7/1245 F_WindowSetFullscreen(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a304  size 24  6 条（0x11a304..0x11a31c）
 * @func 0x11a304 0x11a31c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a304 push {r3, lr}
 *   @0x11a308 mov r1, #0
 *   @0x11a30c ldr r0, [sp, #0x8]
 *   @0x11a310 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11a314 pop {r3, lr}
 *   @0x11a318 b 0x17af10 <_Z24GR_Window_Set_FullScreenb>
 *
 * ══ §8/1245 F_WindowSetMinWidth(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a368  size 24  6 条（0x11a368..0x11a380）
 * @func 0x11a368 0x11a390  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a368 push {r3, lr}
 *   @0x11a36c mov r1, #0
 *   @0x11a370 ldr r0, [sp, #0x8]
 *   @0x11a374 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a378 pop {r3, lr}
 *   @0x11a37c b 0x1799b0 <_Z23GR_Window_Set_Min_Widthi>
 *
 * ══ §9/1245 F_WindowSetMaxWidth(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a380  size 24  6 条（0x11a380..0x11a398）
 * @func 0x11a380 0x11a3a8  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a380 push {r3, lr}
 *   @0x11a384 mov r1, #0
 *   @0x11a388 ldr r0, [sp, #0x8]
 *   @0x11a38c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a390 pop {r3, lr}
 *   @0x11a394 b 0x1799c4 <_Z23GR_Window_Set_Max_Widthi>
 *
 * ══ §10/1245 F_WindowSetMinHeight(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a398  size 24  6 条（0x11a398..0x11a3b0）
 * @func 0x11a398 0x11a3c0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a398 push {r3, lr}
 *   @0x11a39c mov r1, #0
 *   @0x11a3a0 ldr r0, [sp, #0x8]
 *   @0x11a3a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a3a8 pop {r3, lr}
 *   @0x11a3ac b 0x1799d8 <_Z24GR_Window_Set_Min_Heighti>
 *
 * ══ §11/1245 F_WindowSetMaxHeight(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a3b0  size 24  6 条（0x11a3b0..0x11a3c8）
 * @func 0x11a3b0 0x11a3c8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a3b0 push {r3, lr}
 *   @0x11a3b4 mov r1, #0
 *   @0x11a3b8 ldr r0, [sp, #0x8]
 *   @0x11a3bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a3c0 pop {r3, lr}
 *   @0x11a3c4 b 0x1799ec <_Z24GR_Window_Set_Max_Heighti>
 *
 * ══ §12/1245 F_WindowSetCursor(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a3e4  size 24  6 条（0x11a3e4..0x11a3fc）
 * @func 0x11a3e4 0x11a3fc  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a3e4 push {r3, lr}
 *   @0x11a3e8 mov r1, #0
 *   @0x11a3ec ldr r0, [sp, #0x8]
 *   @0x11a3f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a3f4 pop {r3, lr}
 *   @0x11a3f8 b 0x17af8c <_Z20GR_Window_Set_Cursori>
 *
 * ══ §13/1245 F_WindowSetColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a42c  size 24  6 条（0x11a42c..0x11a444）
 * @func 0x11a42c 0x11a444  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a42c push {r3, lr}
 *   @0x11a430 mov r1, #0
 *   @0x11a434 ldr r0, [sp, #0x8]
 *   @0x11a438 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11a43c pop {r3, lr}
 *   @0x11a440 b 0x17ae08 <_Z19GR_Window_Set_Colorj>
 *
 * ══ §14/1245 F_DrawSetBlendMode(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ac08  size 24  6 条（0x11ac08..0x11ac20）
 * @func 0x11ac08 0x11ac20  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ac08 push {r3, lr}
 *   @0x11ac0c mov r1, #0
 *   @0x11ac10 ldr r0, [sp, #0x8]
 *   @0x11ac14 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ac18 pop {r3, lr}
 *   @0x11ac1c b 0x168360 <_Z16GR_D3D_Set_Blendi>
 *
 * ══ §15/1245 F_DrawSetAlphaTest(RValue&, CInstance*, CInstance*, int, RValue*)  0x11acb0  size 24  6 条（0x11acb0..0x11acc8）
 * @func 0x11acb0 0x11acc8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11acb0 push {r3, lr}
 *   @0x11acb4 mov r1, #0
 *   @0x11acb8 ldr r0, [sp, #0x8]
 *   @0x11acbc bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11acc0 pop {r3, lr}
 *   @0x11acc4 b 0x168664 <_Z28GR_D3D_Set_Alpha_Test_Enableb>
 *
 * ══ §16/1245 F_DrawSetAlphaTestRefValue(RValue&, CInstance*, CInstance*, int, RValue*)  0x11acf8  size 24  6 条（0x11acf8..0x11ad10）
 * @func 0x11acf8 0x11ad10  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11acf8 push {r3, lr}
 *   @0x11acfc mov r1, #0
 *   @0x11ad00 ldr r0, [sp, #0x8]
 *   @0x11ad04 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11ad08 pop {r3, lr}
 *   @0x11ad0c b 0x1686b8 <_Z25GR_D3D_Set_Alpha_Test_Refj>
 *
 * ══ §17/1245 F_DrawSetCirclePrecision(RValue&, CInstance*, CInstance*, int, RValue*)  0x11b9c0  size 24  6 条（0x11b9c0..0x11b9d8）
 * @func 0x11b9c0 0x11b9d8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11b9c0 push {r3, lr}
 *   @0x11b9c4 mov r1, #0
 *   @0x11b9c8 ldr r0, [sp, #0x8]
 *   @0x11b9cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11b9d0 pop {r3, lr}
 *   @0x11b9d4 b 0x16ae64 <_Z24GR_Draw_Circle_Precisioni>
 *
 * ══ §18/1245 F_TextureSetInterpolation(RValue&, CInstance*, CInstance*, int, RValue*)  0x11bc5c  size 24  6 条（0x11bc5c..0x11bc74）
 * @func 0x11bc5c 0x11bc74  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11bc5c push {r3, lr}
 *   @0x11bc60 mov r1, #0
 *   @0x11bc64 ldr r0, [sp, #0x8]
 *   @0x11bc68 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11bc6c pop {r3, lr}
 *   @0x11bc70 b 0x168710 <_Z32GR_D3D_Set_Texture_Interpolationb>
 *
 * ══ §19/1245 F_TextureSetBlending(RValue&, CInstance*, CInstance*, int, RValue*)  0x11bca8  size 24  6 条（0x11bca8..0x11bcc0）
 * @func 0x11bca8 0x11bcd0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11bca8 push {r3, lr}
 *   @0x11bcac mov r1, #0
 *   @0x11bcb0 ldr r0, [sp, #0x8]
 *   @0x11bcb4 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11bcb8 pop {r3, lr}
 *   @0x11bcbc b 0x1689c8 <_Z27GR_D3D_Set_Texture_Blendingb>
 *
 * ══ §20/1245 F_TextureSetRepeat(RValue&, CInstance*, CInstance*, int, RValue*)  0x11bcc0  size 24  6 条（0x11bcc0..0x11bcd8）
 * @func 0x11bcc0 0x11bcd8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11bcc0 push {r3, lr}
 *   @0x11bcc4 mov r1, #0
 *   @0x11bcc8 ldr r0, [sp, #0x8]
 *   @0x11bccc bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x11bcd0 pop {r3, lr}
 *   @0x11bcd4 b 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb>
 *
 * ══ §21/1245 F_TexturePreload(RValue&, CInstance*, CInstance*, int, RValue*)  0x11bd0c  size 24  6 条（0x11bd0c..0x11bd24）
 * @func 0x11bd0c 0x11bd24  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetPtrOrInt(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11bd0c push {r3, lr}
 *   @0x11bd10 mov r1, #0
 *   @0x11bd14 ldr r0, [sp, #0x8]
 *   @0x11bd18 bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei>
 *   @0x11bd1c pop {r3, lr}
 *   @0x11bd20 b 0x174288 <_Z18GR_Texture_Preloadi>
 *
 * ══ §22/1245 F_DrawSetHAlign(RValue&, CInstance*, CInstance*, int, RValue*)  0x11bd70  size 24  6 条（0x11bd70..0x11bd88）
 * @func 0x11bd70 0x11bd98  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11bd70 push {r3, lr}
 *   @0x11bd74 mov r1, #0
 *   @0x11bd78 ldr r0, [sp, #0x8]
 *   @0x11bd7c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11bd80 pop {r3, lr}
 *   @0x11bd84 b 0x172b30 <_Z18GR_Text_Set_HAligni>
 *
 * ══ §23/1245 F_DrawSetVAlign(RValue&, CInstance*, CInstance*, int, RValue*)  0x11bd88  size 24  6 条（0x11bd88..0x11bda0）
 * @func 0x11bd88 0x11bda0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11bd88 push {r3, lr}
 *   @0x11bd8c mov r1, #0
 *   @0x11bd90 ldr r0, [sp, #0x8]
 *   @0x11bd94 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x11bd98 pop {r3, lr}
 *   @0x11bd9c b 0x172b7c <_Z18GR_Text_Set_VAligni>
 *
 * ══ §24/1245 F_PartTypeDestroy(RValue&, CInstance*, CInstance*, int, RValue*)  0x128f70  size 24  6 条（0x128f70..0x128f88）
 * @func 0x128f70 0x128f88  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x128f70 push {r3, lr}
 *   @0x128f74 mov r1, #0
 *   @0x128f78 ldr r0, [sp, #0x8]
 *   @0x128f7c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x128f80 pop {r3, lr}
 *   @0x128f84 b 0x1a3160 <_Z20ParticleType_Destroyi>
 *
 * ══ §25/1245 F_PartTypeClear(RValue&, CInstance*, CInstance*, int, RValue*)  0x128fc4  size 24  6 条（0x128fc4..0x128fdc）
 * @func 0x128fc4 0x128fdc  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x128fc4 push {r3, lr}
 *   @0x128fc8 mov r1, #0
 *   @0x128fcc ldr r0, [sp, #0x8]
 *   @0x128fd0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x128fd4 pop {r3, lr}
 *   @0x128fd8 b 0x1a2f7c <_Z18ParticleType_Cleari>
 *
 * ══ §26/1245 F_PartSystemDestroy(RValue&, CInstance*, CInstance*, int, RValue*)  0x1298f8  size 24  6 条（0x1298f8..0x129910）
 * @func 0x1298f8 0x129910  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1298f8 push {r3, lr}
 *   @0x1298fc mov r1, #0
 *   @0x129900 ldr r0, [sp, #0x8]
 *   @0x129904 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129908 pop {r3, lr}
 *   @0x12990c b 0x1a454c <_Z22ParticleSystem_Destroyi>
 *
 * ══ §27/1245 F_PartSystemClear(RValue&, CInstance*, CInstance*, int, RValue*)  0x12994c  size 24  6 条（0x12994c..0x129964）
 * @func 0x12994c 0x129964  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12994c push {r3, lr}
 *   @0x129950 mov r1, #0
 *   @0x129954 ldr r0, [sp, #0x8]
 *   @0x129958 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12995c pop {r3, lr}
 *   @0x129960 b 0x1a4180 <_Z20ParticleSystem_Cleari>
 *
 * ══ §28/1245 F_PartSystemUpdate(RValue&, CInstance*, CInstance*, int, RValue*)  0x129a7c  size 24  6 条（0x129a7c..0x129a94）
 * @func 0x129a7c 0x129aa4  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129a7c push {r3, lr}
 *   @0x129a80 mov r1, #0
 *   @0x129a84 ldr r0, [sp, #0x8]
 *   @0x129a88 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129a8c pop {r3, lr}
 *   @0x129a90 b 0x1a4f18 <_Z21ParticleSystem_Updatei>
 *
 * ══ §29/1245 F_PartSystemDrawIt(RValue&, CInstance*, CInstance*, int, RValue*)  0x129a94  size 24  6 条（0x129a94..0x129aac）
 * @func 0x129a94 0x129aac  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129a94 push {r3, lr}
 *   @0x129a98 mov r1, #0
 *   @0x129a9c ldr r0, [sp, #0x8]
 *   @0x129aa0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129aa4 pop {r3, lr}
 *   @0x129aa8 b 0x1a56ac <_Z19ParticleSystem_Drawi>
 *
 * ══ §30/1245 F_PartParticlesClear(RValue&, CInstance*, CInstance*, int, RValue*)  0x129ba8  size 24  6 条（0x129ba8..0x129bc0）
 * @func 0x129ba8 0x129bc0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129ba8 push {r3, lr}
 *   @0x129bac mov r1, #0
 *   @0x129bb0 ldr r0, [sp, #0x8]
 *   @0x129bb4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129bb8 pop {r3, lr}
 *   @0x129bbc b 0x1a40d4 <_Z30ParticleSystem_Particles_Cleari>
 *
 * ══ §31/1245 F_PartEmitterDestroyAll(RValue&, CInstance*, CInstance*, int, RValue*)  0x129c6c  size 24  6 条（0x129c6c..0x129c84）
 * @func 0x129c6c 0x129c84  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129c6c push {r3, lr}
 *   @0x129c70 mov r1, #0
 *   @0x129c74 ldr r0, [sp, #0x8]
 *   @0x129c78 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x129c7c pop {r3, lr}
 *   @0x129c80 b 0x1a37b8 <_Z33ParticleSystem_Emitter_DestroyAlli>
 *
 * ══ §32/1245 F_CDSetPosition(RValue&, CInstance*, CInstance*, int, RValue*)  0x1338b8  size 24  6 条（0x1338b8..0x1338d0）
 * @func 0x1338b8 0x1338e0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1338b8 push {r3, lr}
 *   @0x1338bc mov r1, #0
 *   @0x1338c0 ldr r0, [sp, #0x8]
 *   @0x1338c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1338c8 pop {r3, lr}
 *   @0x1338cc b 0x2148b4 <_Z14CD_SetPositioni>
 *
 * ══ §33/1245 F_CDSetTrackPosition(RValue&, CInstance*, CInstance*, int, RValue*)  0x1338d0  size 24  6 条（0x1338d0..0x1338e8）
 * @func 0x1338d0 0x1338f0  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1338d0 push {r3, lr}
 *   @0x1338d4 mov r1, #0
 *   @0x1338d8 ldr r0, [sp, #0x8]
 *   @0x1338dc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1338e0 pop {r3, lr}
 *   @0x1338e4 b 0x2148b8 <_Z19CD_SetTrackPositioni>
 *
 * ══ §34/1245 F_SoundPlay(RValue&, CInstance*, CInstance*, int, RValue*)  0x136690  size 24  6 条（0x136690..0x1366a8）
 * @func 0x136690 0x1366a8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x136690 push {r3, lr}
 *   @0x136694 mov r1, #0
 *   @0x136698 ldr r0, [sp, #0x8]
 *   @0x13669c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1366a0 pop {r3, lr}
 *   @0x1366a4 b 0x1365f0 <_Z16YYGML_sound_playi>
 *
 * ══ §35/1245 F_SoundStop(RValue&, CInstance*, CInstance*, int, RValue*)  0x136714  size 24  6 条（0x136714..0x13672c）
 * @func 0x136714 0x13672c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x136714 push {r3, lr}
 *   @0x136718 mov r1, #0
 *   @0x13671c ldr r0, [sp, #0x8]
 *   @0x136720 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x136724 pop {r3, lr}
 *   @0x136728 b 0x1366a8 <_Z16YYGML_sound_stopi>
 *
 * ══ §36/1245 GetSecure()  0x13c488  size 24  6 条（0x13c488..0x13c4a0）
 * @func 0x13c488 0x13c4a0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13c488 ldr r3, [pc, #0xc]
 *   @0x13c48c mov r2, #0
 *   @0x13c490 ldr r3, [pc, r3]
 *   @0x13c494 strb r2, [r3]
 *   @0x13c498 bx lr
 *   @0x13c49c eoreq r2, r11, r8, lsl lr
 *
 * ══ §37/1245 F_ActionSaveGame(RValue&, CInstance*, CInstance*, int, RValue*)  0x13ec54  size 24  6 条（0x13ec54..0x13ec6c）
 * @func 0x13ec54 0x13ec7c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13ec54 push {r3, lr}
 *   @0x13ec58 mov r1, #0
 *   @0x13ec5c ldr r0, [sp, #0x8]
 *   @0x13ec60 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13ec64 pop {r3, lr}
 *   @0x13ec68 b 0x1d1468 <_Z16Command_SaveGamePKc>
 *
 * ══ §38/1245 F_ActionLoadGame(RValue&, CInstance*, CInstance*, int, RValue*)  0x13ec6c  size 24  6 条（0x13ec6c..0x13ec84）
 * @func 0x13ec6c 0x13ec84  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13ec6c push {r3, lr}
 *   @0x13ec70 mov r1, #0
 *   @0x13ec74 ldr r0, [sp, #0x8]
 *   @0x13ec78 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13ec7c pop {r3, lr}
 *   @0x13ec80 b 0x1d14fc <_Z16Command_LoadGamePKc>
 *
 * ══ §39/1245 F_ActionColor(RValue&, CInstance*, CInstance*, int, RValue*)  0x1409b0  size 24  6 条（0x1409b0..0x1409c8）
 * @func 0x1409b0 0x1409c8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1409b0 push {r3, lr}
 *   @0x1409b4 mov r1, #0
 *   @0x1409b8 ldr r0, [sp, #0x8]
 *   @0x1409bc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1409c0 pop {r3, lr}
 *   @0x1409c4 b 0x169d98 <_Z21YYGML_draw_set_colourj>
 *
 * ══ §40/1245 F_ActionSnapshot(RValue&, CInstance*, CInstance*, int, RValue*)  0x1409f4  size 24  6 条（0x1409f4..0x140a0c）
 * @func 0x1409f4 0x140a0c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1409f4 push {r3, lr}
 *   @0x1409f8 mov r1, #0
 *   @0x1409fc ldr r0, [sp, #0x8]
 *   @0x140a00 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x140a04 pop {r3, lr}
 *   @0x140a08 b 0x1c9fac <_Z18Command_ScreenShotPKc>
 *
 * ══ §41/1245 F_ActionEndSound(RValue&, CInstance*, CInstance*, int, RValue*)  0x141c14  size 24  6 条（0x141c14..0x141c2c）
 * @func 0x141c14 0x141c34  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141c14 push {r3, lr}
 *   @0x141c18 mov r1, #0
 *   @0x141c1c ldr r0, [sp, #0x8]
 *   @0x141c20 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x141c24 pop {r3, lr}
 *   @0x141c28 b 0x141bb8 <_Z22YYGML_action_end_soundi>
 *
 * ══ §42/1245 F_ActionFullScreen(RValue&, CInstance*, CInstance*, int, RValue*)  0x141e1c  size 24  6 条（0x141e1c..0x141e34）
 * @func 0x141e1c 0x141e44  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141e1c push {r3, lr}
 *   @0x141e20 mov r1, #0
 *   @0x141e24 ldr r0, [sp, #0x8]
 *   @0x141e28 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x141e2c pop {r3, lr}
 *   @0x141e30 b 0x141ddc <_Z23YYGML_action_fullscreeni>
 *
 * ══ §43/1245 F_ActionSetRelative(RValue&, CInstance*, CInstance*, int, RValue*)  0x141e48  size 24  6 条（0x141e48..0x141e60）
 * @func 0x141e48 0x141e60  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141e48 push {r3, lr}
 *   @0x141e4c mov r1, #0
 *   @0x141e50 ldr r0, [sp, #0x8]
 *   @0x141e54 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x141e58 pop {r3, lr}
 *   @0x141e5c b 0x141e34 <_Z25YYGML_action_set_relativeb>
 *
 * ══ §44/1245 F_D3DSetPerspective(RValue&, CInstance*, CInstance*, int, RValue*)  0x143b20  size 24  6 条（0x143b20..0x143b38）
 * @func 0x143b20 0x143b48  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143b20 push {r3, lr}
 *   @0x143b24 mov r1, #0
 *   @0x143b28 ldr r0, [sp, #0x8]
 *   @0x143b2c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x143b30 pop {r3, lr}
 *   @0x143b34 b 0x1682f0 <_Z22GR_D3D_Set_Perspectiveb>
 *
 * ══ §45/1245 F_D3DSetHidden(RValue&, CInstance*, CInstance*, int, RValue*)  0x143b38  size 24  6 条（0x143b38..0x143b50）
 * @func 0x143b38 0x143b60  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143b38 push {r3, lr}
 *   @0x143b3c mov r1, #0
 *   @0x143b40 ldr r0, [sp, #0x8]
 *   @0x143b44 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x143b48 pop {r3, lr}
 *   @0x143b4c b 0x16841c <_Z10SetZBufferb>
 *
 * ══ §46/1245 F_D3DSetDepth(RValue&, CInstance*, CInstance*, int, RValue*)  0x143b50  size 24  6 条（0x143b50..0x143b68）
 * @func 0x143b50 0x143b68  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143b50 push {r3, lr}
 *   @0x143b54 mov r1, #0
 *   @0x143b58 ldr r0, [sp, #0x8]
 *   @0x143b5c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x143b60 pop {r3, lr}
 *   @0x143b64 b 0x1631dc <_Z15GR_3D_Set_Depthf>
 *
 * ══ §47/1245 F_D3DSetShading(RValue&, CInstance*, CInstance*, int, RValue*)  0x143b90  size 24  6 条（0x143b90..0x143ba8）
 * @func 0x143b90 0x143ba8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143b90 push {r3, lr}
 *   @0x143b94 mov r1, #0
 *   @0x143b98 ldr r0, [sp, #0x8]
 *   @0x143b9c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x143ba0 pop {r3, lr}
 *   @0x143ba4 b 0x16849c <_Z18GR_D3D_Set_Shadingb>
 *
 * ══ §48/1245 F_D3DSetCulling(RValue&, CInstance*, CInstance*, int, RValue*)  0x143c08  size 24  6 条（0x143c08..0x143c20）
 * @func 0x143c08 0x143c30  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143c08 push {r3, lr}
 *   @0x143c0c mov r1, #0
 *   @0x143c10 ldr r0, [sp, #0x8]
 *   @0x143c14 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x143c18 pop {r3, lr}
 *   @0x143c1c b 0x1683e8 <_Z18GR_D3D_Set_Cullingb>
 *
 * ══ §49/1245 F_D3DSetZWriteEnable(RValue&, CInstance*, CInstance*, int, RValue*)  0x143c20  size 24  6 条（0x143c20..0x143c38）
 * @func 0x143c20 0x143c38  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143c20 push {r3, lr}
 *   @0x143c24 mov r1, #0
 *   @0x143c28 ldr r0, [sp, #0x8]
 *   @0x143c2c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x143c30 pop {r3, lr}
 *   @0x143c34 b 0x16864c <_Z25GR_D3D_Set_Z_Write_Enableb>
 *
 * ══ §50/1245 F_D3DTransformSetRotationX(RValue&, CInstance*, CInstance*, int, RValue*)  0x144ee4  size 24  6 条（0x144ee4..0x144efc）
 * @func 0x144ee4 0x144f0c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x144ee4 push {r3, lr}
 *   @0x144ee8 mov r1, #0
 *   @0x144eec ldr r0, [sp, #0x8]
 *   @0x144ef0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144ef4 pop {r3, lr}
 *   @0x144ef8 b 0x1637d4 <_Z30GR_3D_Transform_Set_Rotation_Xf>
 *
 * ══ §51/1245 F_D3DTransformSetRotationY(RValue&, CInstance*, CInstance*, int, RValue*)  0x144efc  size 24  6 条（0x144efc..0x144f14）
 * @func 0x144efc 0x144f24  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x144efc push {r3, lr}
 *   @0x144f00 mov r1, #0
 *   @0x144f04 ldr r0, [sp, #0x8]
 *   @0x144f08 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144f0c pop {r3, lr}
 *   @0x144f10 b 0x163800 <_Z30GR_3D_Transform_Set_Rotation_Yf>
 *
 * ══ §52/1245 F_D3DTransformSetRotationZ(RValue&, CInstance*, CInstance*, int, RValue*)  0x144f14  size 24  6 条（0x144f14..0x144f2c）
 * @func 0x144f14 0x144f2c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x144f14 push {r3, lr}
 *   @0x144f18 mov r1, #0
 *   @0x144f1c ldr r0, [sp, #0x8]
 *   @0x144f20 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x144f24 pop {r3, lr}
 *   @0x144f28 b 0x16382c <_Z30GR_3D_Transform_Set_Rotation_Zf>
 *
 * ══ §53/1245 F_D3DTransformAddRotationX(RValue&, CInstance*, CInstance*, int, RValue*)  0x145018  size 24  6 条（0x145018..0x145030）
 * @func 0x145018 0x145040  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145018 push {r3, lr}
 *   @0x14501c mov r1, #0
 *   @0x145020 ldr r0, [sp, #0x8]
 *   @0x145024 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145028 pop {r3, lr}
 *   @0x14502c b 0x1639ac <_Z30GR_3D_Transform_Add_Rotation_Xf>
 *
 * ══ §54/1245 F_D3DTransformAddRotationY(RValue&, CInstance*, CInstance*, int, RValue*)  0x145030  size 24  6 条（0x145030..0x145048）
 * @func 0x145030 0x145058  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145030 push {r3, lr}
 *   @0x145034 mov r1, #0
 *   @0x145038 ldr r0, [sp, #0x8]
 *   @0x14503c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145040 pop {r3, lr}
 *   @0x145044 b 0x1639fc <_Z30GR_3D_Transform_Add_Rotation_Yf>
 *
 * ══ §55/1245 F_D3DTransformAddRotationZ(RValue&, CInstance*, CInstance*, int, RValue*)  0x145048  size 24  6 条（0x145048..0x145060）
 * @func 0x145048 0x145060  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145048 push {r3, lr}
 *   @0x14504c mov r1, #0
 *   @0x145050 ldr r0, [sp, #0x8]
 *   @0x145054 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x145058 pop {r3, lr}
 *   @0x14505c b 0x163a4c <_Z30GR_3D_Transform_Add_Rotation_Zf>
 *
 * ══ §56/1245 F_D3DModelDestroy(RValue&, CInstance*, CInstance*, int, RValue*)  0x145208  size 24  6 条（0x145208..0x145220）
 * @func 0x145208 0x145230  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145208 push {r3, lr}
 *   @0x14520c mov r1, #0
 *   @0x145210 ldr r0, [sp, #0x8]
 *   @0x145214 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x145218 pop {r3, lr}
 *   @0x14521c b 0x1651b0 <_Z14GR_3DM_Destroyi>
 *
 * ══ §57/1245 F_D3DModelClear(RValue&, CInstance*, CInstance*, int, RValue*)  0x145220  size 24  6 条（0x145220..0x145238）
 * @func 0x145220 0x145238  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x145220 push {r3, lr}
 *   @0x145224 mov r1, #0
 *   @0x145228 ldr r0, [sp, #0x8]
 *   @0x14522c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x145230 pop {r3, lr}
 *   @0x145234 b 0x165210 <_Z12GR_3DM_Cleari>
 *
 * ══ §58/1245 F_D3DModelPrimitiveEnd(RValue&, CInstance*, CInstance*, int, RValue*)  0x1454e4  size 24  6 条（0x1454e4..0x1454fc）
 * @func 0x1454e4 0x1454fc  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1454e4 push {r3, lr}
 *   @0x1454e8 mov r1, #0
 *   @0x1454ec ldr r0, [sp, #0x8]
 *   @0x1454f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1454f4 pop {r3, lr}
 *   @0x1454f8 b 0x1658d0 <_Z20GR_3DM_Primitive_Endi>
 *
 * ══ §59/1245 F_PhysicsDeleteFixture(RValue&, CInstance*, CInstance*, int, RValue*)  0x14badc  size 24  6 条（0x14badc..0x14baf4）
 * @func 0x14badc 0x14baf4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14badc push {r3, lr}
 *   @0x14bae0 mov r1, #0
 *   @0x14bae4 ldr r0, [sp, #0x8]
 *   @0x14bae8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14baec pop {r3, lr}
 *   @0x14baf0 b 0x236648 <_ZN22CPhysicsFixtureFactory14DestroyFixtureEj>
 *
 * ══ §60/1245 F_YoYo_Achievement_GetPic(RValue&, CInstance*, CInstance*, int, RValue*)  0x156610  size 24  6 条（0x156610..0x156628）
 * @func 0x156610 0x156628  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156610 push {r3, lr}
 *   @0x156614 mov r1, #0
 *   @0x156618 ldr r0, [sp, #0x8]
 *   @0x15661c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x156620 pop {r3, lr}
 *   @0x156624 b 0x161168 <_Z20Achievement_Load_PicPc>
 *
 * ══ §61/1245 F_YoYoAdsSetup(RValue&, CInstance*, CInstance*, int, RValue*)  0x156e58  size 24  6 条（0x156e58..0x156e70）
 * @func 0x156e58 0x156e80  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156e58 push {r3, lr}
 *   @0x156e5c mov r1, #0
 *   @0x156e60 ldr r0, [sp, #0x8]
 *   @0x156e64 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x156e68 pop {r3, lr}
 *   @0x156e6c b 0x15e2f0 <_Z8AdsSetupPc>
 *
 * ══ §62/1245 F_YoYo_AdsPreload(RValue&, CInstance*, CInstance*, int, RValue*)  0x156e70  size 24  6 条（0x156e70..0x156e88）
 * @func 0x156e70 0x156e98  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156e70 push {r3, lr}
 *   @0x156e74 mov r1, #0
 *   @0x156e78 ldr r0, [sp, #0x8]
 *   @0x156e7c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x156e80 pop {r3, lr}
 *   @0x156e84 b 0x15e478 <_Z10AdsPreloadPc>
 *
 * ══ §63/1245 F_YoYo_AdsEvent(RValue&, CInstance*, CInstance*, int, RValue*)  0x156e88  size 24  6 条（0x156e88..0x156ea0）
 * @func 0x156e88 0x156ea0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156e88 push {r3, lr}
 *   @0x156e8c mov r1, #0
 *   @0x156e90 ldr r0, [sp, #0x8]
 *   @0x156e94 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x156e98 pop {r3, lr}
 *   @0x156e9c b 0x15e428 <_Z8AdsEventPc>
 *
 * ══ §64/1245 F_YoYo_OF_SendInvite(RValue&, CInstance*, CInstance*, int, RValue*)  0x157114  size 24  6 条（0x157114..0x15712c）
 * @func 0x157114 0x15712c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157114 push {r3, lr}
 *   @0x157118 mov r1, #0
 *   @0x15711c ldr r0, [sp, #0x8]
 *   @0x157120 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x157124 pop {r3, lr}
 *   @0x157128 b 0x1616e4 <_Z18YoYo_OF_SendInvitePKc>
 *
 * ══ §65/1245 F_YoYo_OF_SetURL(RValue&, CInstance*, CInstance*, int, RValue*)  0x157174  size 24  6 条（0x157174..0x15718c）
 * @func 0x157174 0x15718c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157174 push {r3, lr}
 *   @0x157178 mov r1, #0
 *   @0x15717c ldr r0, [sp, #0x8]
 *   @0x157180 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x157184 pop {r3, lr}
 *   @0x157188 b 0x1616ec <_Z14YoYo_OF_SetURLPKc>
 *
 * ══ §66/1245 F_YoYo_PowersaveEnable(RValue&, CInstance*, CInstance*, int, RValue*)  0x158340  size 24  6 条（0x158340..0x158358）
 * @func 0x158340 0x158368  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x158340 push {r3, lr}
 *   @0x158344 mov r1, #0
 *   @0x158348 ldr r0, [sp, #0x8]
 *   @0x15834c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x158350 pop {r3, lr}
 *   @0x158354 b 0x15f2a4 <_Z17YYPowersaveEnableb>
 *
 * ══ §67/1245 F_YoYo_AnalyticsEvent(RValue&, CInstance*, CInstance*, int, RValue*)  0x158358  size 24  6 条（0x158358..0x158370）
 * @func 0x158358 0x158370  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x158358 push {r3, lr}
 *   @0x15835c mov r1, #0
 *   @0x158360 ldr r0, [sp, #0x8]
 *   @0x158364 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x158368 pop {r3, lr}
 *   @0x15836c b 0x15f380 <_Z16YYAnalyticsEventPKc>
 *
 * ══ §68/1245 RaiseOSPauseEvent  0x159d44  size 24  6 条（0x159d44..0x159d5c）
 * @func 0x159d44 0x159d5c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159d44 ldr r3, [pc, #0xc]
 *   @0x159d48 mov r2, #1
 *   @0x159d4c ldr r3, [pc, r3]
 *   @0x159d50 strb r2, [r3]
 *   @0x159d54 bx lr
 *   @0x159d58 mlaeq r9, r12, lr, r5
 *
 * ══ §69/1245 F_Steam_GetSteamID(RValue&, CInstance*, CInstance*, int, RValue*)  0x161ec0  size 24  6 条（0x161ec0..0x161ed8）
 * @func 0x161ec0 0x161ed8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161ec0 mvn r3, #0
 *   @0x161ec4 mov r2, #10
 *   @0x161ec8 str r3, [r0]
 *   @0x161ecc str r2, [r0, #0xc]
 *   @0x161ed0 str r3, [r0, #0x4]
 *   @0x161ed4 bx lr
 *
 * ══ §70/1245 GR_3D_Transform_Stack_Clear()  0x163b00  size 24  6 条（0x163b00..0x163b18）
 * @func 0x163b00 0x163b28  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x163b00 ldr r3, [pc, #0xc]
 *   @0x163b04 mvn r2, #0
 *   @0x163b08 ldr r3, [pc, r3]
 *   @0x163b0c str r2, [r3]
 *   @0x163b10 bx lr
 *   @0x163b14 .word 0x0028c5dc
 *
 * ══ §71/1245 GR_3D_Transform_Stack_Empty()  0x163b18  size 24  6 条（0x163b18..0x163b30）
 * @func 0x163b18 0x163b30  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x163b18 ldr r3, [pc, #0xc]
 *   @0x163b1c ldr r3, [pc, r3]
 *   @0x163b20 ldr r0, [r3]
 *   @0x163b24 lsr r0, r0, #31
 *   @0x163b28 bx lr
 *   @0x163b2c eoreq r12, r8, r8, asr #11
 *
 * ══ §72/1245 GR_D3D_Set_Lighting(bool)  0x168484  size 24  6 条（0x168484..0x16849c）
 * @func 0x168484 0x16849c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168484 ldr r3, [pc, #0xc]
 *   @0x168488 mov r2, r0
 *   @0x16848c mov r1, #21
 *   @0x168490 ldr r0, [pc, r3]
 *   @0x168494 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x168498 eoreq r5, r8, r8, ror #16
 *
 * ══ §73/1245 GR_D3D_Set_Z_Write_Enable(bool)  0x16864c  size 24  6 条（0x16864c..0x168664）
 * @func 0x16864c 0x168664  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16864c ldr r3, [pc, #0xc]
 *   @0x168650 mov r2, r0
 *   @0x168654 mov r1, #4
 *   @0x168658 ldr r0, [pc, r3]
 *   @0x16865c b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x168660 eoreq r5, r8, r0, lsr #13
 *
 * ══ §74/1245 GR_D3D_Set_Alpha_Test_Ref(unsigned int)  0x1686b8  size 24  6 条（0x1686b8..0x1686d0）
 * @func 0x1686b8 0x1686e0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1686b8 ldr r3, [pc, #0xc]
 *   @0x1686bc mov r2, r0
 *   @0x1686c0 mov r1, #10
 *   @0x1686c4 ldr r0, [pc, r3]
 *   @0x1686c8 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1686cc eoreq r5, r8, r4, lsr r6
 *
 * ══ §75/1245 GR_D3D_Set_Alpha_Test_Func(unsigned int)  0x1686e4  size 24  6 条（0x1686e4..0x1686fc）
 * @func 0x1686e4 0x16870c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1686e4 ldr r3, [pc, #0xc]
 *   @0x1686e8 mov r2, r0
 *   @0x1686ec mov r1, #11
 *   @0x1686f0 ldr r0, [pc, r3]
 *   @0x1686f4 b 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x1686f8 eoreq r5, r8, r8, lsl #12
 *
 * ══ §76/1245 GR_D3D_Set_Texture_Blending(bool)  0x1689c8  size 24  6 条（0x1689c8..0x1689e0）
 * @func 0x1689c8 0x1689f0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::Flush()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1689c8 push {r4, lr}
 *   @0x1689cc mov r4, r0
 *   @0x1689d0 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x1689d4 mov r0, r4
 *   @0x1689d8 pop {r4, lr}
 *   @0x1689dc b 0x1836d8 <_ZN8Graphics18SetTextureBlendingEb>
 *
 * ══ §77/1245 GR_D3D_Refresh()  0x169b1c  size 24  6 条（0x169b1c..0x169b34）
 * @func 0x169b1c 0x169b34  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::SceneBegin() / Graphics::SceneEnd() / Graphics::Flip()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x169b1c push {r3, lr}
 *   @0x169b20 bl 0x17dd58 <_ZN8Graphics10SceneBeginEv>
 *   @0x169b24 bl 0x17de74 <_ZN8Graphics8SceneEndEv>
 *   @0x169b28 bl 0x17df14 <_ZN8Graphics4FlipEv>
 *   @0x169b2c mov r0, #1
 *   @0x169b30 pop {r3, pc}
 *
 * ══ §78/1245 GR_Draw_Create_Color(int, int, int)  0x169d80  size 24  6 条（0x169d80..0x169d98）
 * @func 0x169d80 0x169d98  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x169d80 lsl r1, r1, #8
 *   @0x169d84 uxtb r2, r2
 *   @0x169d88 uxth r1, r1
 *   @0x169d8c add r1, r1, r2, lsl #16
 *   @0x169d90 uxtab r0, r1, r0
 *   @0x169d94 bx lr
 *
 * ══ §79/1245 GR_Window_Set_Color(unsigned int)  0x17ae08  size 24  6 条（0x17ae08..0x17ae20）
 * @func 0x17ae08 0x17ae20  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17ae08 ldr r3, [pc, #0xc]
 *   @0x17ae0c orr r0, r0, #-16777216
 *   @0x17ae10 ldr r3, [pc, r3]
 *   @0x17ae14 str r0, [r3]
 *   @0x17ae18 bx lr
 *   @0x17ae1c eoreq r5, r7, r12, lsl #10
 *
 * ══ §80/1245 IO_Key_Current_Set(int)  0x18bed0  size 24  6 条（0x18bed0..0x18bee8）
 * @func 0x18bed0 0x18bee8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18bed0 cmp r0, #255
 *   @0x18bed4 ldrls r3, [pc, #0x8]
 *   @0x18bed8 ldrls r3, [pc, r3]
 *   @0x18bedc strls r0, [r3]
 *   @0x18bee0 bx lr
 *   @0x18bee4 eoreq r4, r6, r4, lsl #14
 *
 * ══ §81/1245 IO_Keymap_Set(int, int)  0x18c2fc  size 24  6 条（0x18c2fc..0x18c314）
 * @func 0x18c2fc 0x18c314  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c2fc cmp r0, #255
 *   @0x18c300 ldrls r3, [pc, #0x8]
 *   @0x18c304 ldrls r3, [pc, r3]
 *   @0x18c308 strls r1, [r3, r0, lsl #2]
 *   @0x18c30c bx lr
 *   @0x18c310 eoreq r4, r6, r12, lsl #6
 *
 * ══ §82/1245 CInstanceBase::~CInstanceBase()  0x190bb0  size 24  6 条（0x190bb0..0x190bc8）
 * @func 0x190bb0 0x190bc8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x190bb0 ldr r3, [pc, #0xc]
 *   @0x190bb4 ldr r3, [pc, r3]
 *   @0x190bb8 add r3, r3, #8
 *   @0x190bbc str r3, [r0]
 *   @0x190bc0 bx lr
 *   @0x190bc4 .word 0x0025fab8
 *
 * ══ §83/1245 IYYFont::~IYYFont()  0x1a8534  size 24  6 条（0x1a8534..0x1a854c）
 * @func 0x1a8534 0x1a855c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8534 ldr r3, [pc, #0xc]
 *   @0x1a8538 ldr r3, [pc, r3]
 *   @0x1a853c add r3, r3, #8
 *   @0x1a8540 str r3, [r0]
 *   @0x1a8544 bx lr
 *   @0x1a8548 mlaeq r4, r12, r2, r8
 *
 * ══ §84/1245 IBitmap::~IBitmap()  0x1a88c4  size 24  6 条（0x1a88c4..0x1a88dc）
 * @func 0x1a88c4 0x1a88ec  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a88c4 ldr r3, [pc, #0xc]
 *   @0x1a88c8 ldr r3, [pc, r3]
 *   @0x1a88cc add r3, r3, #8
 *   @0x1a88d0 str r3, [r0]
 *   @0x1a88d4 bx lr
 *   @0x1a88d8 eoreq r7, r4, r0, lsr pc
 *
 * ══ §85/1245 IBitmapLoader::~IBitmapLoader()  0x1a88dc  size 24  6 条（0x1a88dc..0x1a88f4）
 * @func 0x1a88dc 0x1a88fc  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a88dc ldr r3, [pc, #0xc]
 *   @0x1a88e0 ldr r3, [pc, r3]
 *   @0x1a88e4 add r3, r3, #8
 *   @0x1a88e8 str r3, [r0]
 *   @0x1a88ec bx lr
 *   @0x1a88f0 eoreq r7, r4, r12, lsl pc
 *
 * ══ §86/1245 F_LayerResetTargetRoom(RValue&, CInstance*, CInstance*, int, RValue*)  0x1b5ecc  size 24  6 条（0x1b5ecc..0x1b5ee4）
 * @func 0x1b5ecc 0x1b5ee4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b5ecc ldr r3, [pc, #0xc]
 *   @0x1b5ed0 mvn r2, #0
 *   @0x1b5ed4 ldr r3, [pc, r3]
 *   @0x1b5ed8 str r2, [r3]
 *   @0x1b5edc bx lr
 *   @0x1b5ee0 eoreq r10, r3, r0, lsl #19
 *
 * ══ §87/1245 CLayerManager::GetLayerDepth(CRoom*, int)  0x1b8930  size 24  6 条（0x1b8930..0x1b8948）
 * @func 0x1b8930 0x1b8948  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetLayerFromID(CRoom*, int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b8930 push {r3, lr}
 *   @0x1b8934 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1b8938 cmp r0, #0
 *   @0x1b893c ldrne r0, [r0, #0x4]
 *   @0x1b8940 mvneq r0, #0
 *   @0x1b8944 pop {r3, pc}
 *
 * ══ §88/1245 Run_ResizeEvent(int, int)  0x1d3164  size 24  6 条（0x1d3164..0x1d317c）
 * @func 0x1d3164 0x1d317c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d3164 ldr r3, [pc, #0xc]
 *   @0x1d3168 mov r2, #1
 *   @0x1d316c add r3, pc, r3
 *   @0x1d3170 strb r2, [r3]
 *   @0x1d3174 bx lr
 *   @0x1d3178 eorseq pc, r6, r12, asr r8
 *
 * ══ §89/1245 Run_Pause()  0x1d378c  size 24  6 条（0x1d378c..0x1d37a4）
 * @func 0x1d378c 0x1d37a4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d378c ldr r3, [pc, #0xc]
 *   @0x1d3790 mov r2, #1
 *   @0x1d3794 ldr r3, [pc, r3]
 *   @0x1d3798 strb r2, [r3]
 *   @0x1d379c bx lr
 *   @0x1d37a0 eoreq r12, r1, r12, asr r4
 *
 * ══ §90/1245 TimeLine_Number()  0x1f2b00  size 24  6 条（0x1f2b00..0x1f2b18）
 * @func 0x1f2b00 0x1f2b18  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f2b00 ldr r3, [pc, #0xc]
 *   @0x1f2b04 add r3, pc, r3
 *   @0x1f2b08 ldr r3, [r3]
 *   @0x1f2b0c ldr r0, [r3]
 *   @0x1f2b10 bx lr
 *   @0x1f2b14 subseq r0, r6, r8, ror #11
 *
 * ══ §91/1245 GV_TransitionSteps(CInstance*, int, RValue*)  0x1f7a6c  size 24  6 条（0x1f7a6c..0x1f7a84）
 * @func 0x1f7a6c 0x1f7a84  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7a6c mov r3, #0
 *   @0x1f7a70 mov r0, #1
 *   @0x1f7a74 str r3, [r2, #0xc]
 *   @0x1f7a78 str r3, [r2]
 *   @0x1f7a7c str r3, [r2, #0x4]
 *   @0x1f7a80 bx lr
 *
 * ══ §92/1245 GV_SecureMode(CInstance*, int, RValue*)  0x1f89d4  size 24  6 条（0x1f89d4..0x1f89ec）
 * @func 0x1f89d4 0x1f89ec  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f89d4 mov r3, #0
 *   @0x1f89d8 mov r0, #1
 *   @0x1f89dc str r3, [r2, #0xc]
 *   @0x1f89e0 str r3, [r2]
 *   @0x1f89e4 str r3, [r2, #0x4]
 *   @0x1f89e8 bx lr
 *
 * ══ §93/1245 GV_GameGuId(CInstance*, int, RValue*)  0x1f9c5c  size 24  6 条（0x1f9c5c..0x1f9c74）
 * @func 0x1f9c5c 0x1f9c74  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYCreateString(RValue*, char const*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f9c5c mov r0, r2
 *   @0x1f9c60 mov r1, #0
 *   @0x1f9c64 push {r3, lr}
 *   @0x1f9c68 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x1f9c6c mov r0, #1
 *   @0x1f9c70 pop {r3, pc}
 *
 * ══ §94/1245 IntToHex(int)  0x202498  size 24  6 条（0x202498..0x2024b0）
 * @func 0x202498 0x2024b0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202498 ldr r3, [pc, #0xc]
 *   @0x20249c and r0, r0, #15
 *   @0x2024a0 add r3, pc, r3
 *   @0x2024a4 ldrb r0, [r3, r0]
 *   @0x2024a8 bx lr
 *   @0x2024ac ldrsheq r1, [r5], -r4
 *
 * ══ §95/1245 CDS_Queue::Head()  0x202fa8  size 24  6 条（0x202fa8..0x202fc0）
 * @func 0x202fa8 0x202fc0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202fa8 ldmib r0, {r2, r3}
 *   @0x202fac cmp r3, r2
 *   @0x202fb0 ldrne r0, [r0, #0x10]
 *   @0x202fb4 addne r0, r0, r3, lsl #4
 *   @0x202fb8 moveq r0, #0
 *   @0x202fbc bx lr
 *
 * ══ §96/1245 CDS_Queue::Empty()  0x202fe0  size 24  6 条（0x202fe0..0x202ff8）
 * @func 0x202fe0 0x202ff8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202fe0 ldr r2, [r0, #0x4]
 *   @0x202fe4 ldr r0, [r0, #0x8]
 *   @0x202fe8 subs r3, r2, r0
 *   @0x202fec rsbs r0, r3, #0
 *   @0x202ff0 adcs r0, r0, r3
 *   @0x202ff4 bx lr
 *
 * ══ §97/1245 EnvironmentGetVariable(char*)  0x215284  size 24  6 条（0x215284..0x21529c）
 * @func 0x215284 0x21529c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6a24
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215284 push {r3, lr}
 *   @0x215288 bl 0xb6a24 <getenv@plt>
 *   @0x21528c cmp r0, #0
 *   @0x215290 popeq {r3, pc}
 *   @0x215294 pop {r3, lr}
 *   @0x215298 b 0xdb8c8 <_Z8YYStrDupPKc>
 *
 * ══ §98/1245 Audio_Name(int)  0x21730c  size 24  6 条（0x21730c..0x217324）
 * @func 0x21730c 0x217324  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4c×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21730c ldr r3, [pc, #0xc]
 *   @0x217310 add r3, pc, r3
 *   @0x217314 ldr r3, [r3, #0x4c]
 *   @0x217318 ldr r0, [r3, r0, lsl #2]
 *   @0x21731c bx lr
 *   @0x217320 subseq sp, r3, r4, lsl #31
 *
 * ══ §99/1245 SND_Set_Global_Volume(float)  0x21eb60  size 24  6 条（0x21eb60..0x21eb78）
 * @func 0x21eb60 0x21eb7c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21eb60 ldr r3, [pc, #0xc]
 *   @0x21eb64 mov r1, r0
 *   @0x21eb68 add r3, pc, r3
 *   @0x21eb6c ldr r0, [r3]
 *   @0x21eb70 b 0x220884 <_ZN13SoundHardware15SetMasterVolumeEf>
 *   @0x21eb74 ldrheq r6, [r3], #-124
 *
 * ══ §100/1245 COggAudio::Unsuspend()  0x226100  size 24  6 条（0x226100..0x226118）
 * @func 0x226100 0x226118  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x226100 ldr r3, [pc, #0xc]
 *   @0x226104 mov r2, #0
 *   @0x226108 ldr r3, [pc, r3]
 *   @0x22610c strb r2, [r3]
 *   @0x226110 bx lr
 *   @0x226114 andseq r11, r12, r0, ror r3
 *
 * ══ §101/1245 ov_raw_tell  0x232cd4  size 24  6 条（0x232cd4..0x232cec）
 * @func 0x232cd4 0x232cfc  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x232cd4 ldr r3, [r0, #0x58]
 *   @0x232cd8 cmp r3, #1
 *   @0x232cdc ldrdgt r0, r1, [r0, #8]
 *   @0x232ce0 mvnle r0, #130
 *   @0x232ce4 mvnle r1, #0
 *   @0x232ce8 bx lr
 *
 * ══ §102/1245 ov_pcm_tell  0x232cec  size 24  6 条（0x232cec..0x232d04）
 * @func 0x232cec 0x232d04  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x232cec ldr r3, [r0, #0x58]
 *   @0x232cf0 cmp r3, #1
 *   @0x232cf4 ldrdgt r0, r1, [r0, #80]
 *   @0x232cf8 mvnle r0, #130
 *   @0x232cfc mvnle r1, #0
 *   @0x232d00 bx lr
 *
 * ══ §103/1245 oggpack_writealign  0x233538  size 24  6 条（0x233538..0x233550）
 * @func 0x233538 0x233550  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233538 ldr r2, [r0, #0x4]
 *   @0x23353c rsb r2, r2, #8
 *   @0x233540 cmp r2, #7
 *   @0x233544 bxgt lr
 *   @0x233548 mov r1, #0
 *   @0x23354c b 0x2333c8 <oggpack_write>
 *
 * ══ §104/1245 oggpackB_writealign  0x2336c8  size 24  6 条（0x2336c8..0x2336e0）
 * @func 0x2336c8 0x2336e0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2336c8 ldr r2, [r0, #0x4]
 *   @0x2336cc rsb r2, r2, #8
 *   @0x2336d0 cmp r2, #7
 *   @0x2336d4 bxgt lr
 *   @0x2336d8 mov r1, #0
 *   @0x2336dc b 0x233550 <oggpackB_write>
 *
 * ══ §105/1245 b2Shape::~b2Shape()  0x2363c4  size 24  6 条（0x2363c4..0x2363dc）
 * @func 0x2363c4 0x2363dc  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2363c4 ldr r3, [pc, #0xc]
 *   @0x2363c8 ldr r3, [pc, r3]
 *   @0x2363cc add r3, r3, #8
 *   @0x2363d0 str r3, [r0]
 *   @0x2363d4 bx lr
 *   @0x2363d8 ldrsbeq r11, [r11], -r8
 *
 * ══ §106/1245 b2ContactListener::~b2ContactListener()  0x237ab4  size 24  6 条（0x237ab4..0x237acc）
 * @func 0x237ab4 0x237adc  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237ab4 ldr r3, [pc, #0xc]
 *   @0x237ab8 ldr r3, [pc, r3]
 *   @0x237abc add r3, r3, #8
 *   @0x237ac0 str r3, [r0]
 *   @0x237ac4 bx lr
 *   @0x237ac8 andseq r9, r11, r8, lsl #20
 *
 * ══ §107/1245 CPhysicsWorld::GetParticleGroupFlags(int)  0x23a230  size 24  6 条（0x23a230..0x23a248）
 * @func 0x23a230 0x23a248  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetParticleGroup(int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23a230 push {r3, lr}
 *   @0x23a234 bl 0x239dc0 <_ZN13CPhysicsWorld16GetParticleGroupEi>
 *   @0x23a238 cmp r0, #0
 *   @0x23a23c popeq {r3, pc}
 *   @0x23a240 pop {r3, lr}
 *   @0x23a244 b 0x2d4604 <_ZNK15b2ParticleGroup13GetGroupFlagsEv>
 *
 * ══ §108/1245 CRunnerContactListener::~CRunnerContactListener()  0x23be54  size 24  6 条（0x23be54..0x23be6c）
 * @func 0x23be54 0x23be6c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23be54 ldr r3, [pc, #0xc]
 *   @0x23be58 ldr r3, [pc, r3]
 *   @0x23be5c add r3, r3, #8
 *   @0x23be60 str r3, [r0]
 *   @0x23be64 bx lr
 *   @0x23be68 andseq r5, r11, r8, ror #12
 *
 * ══ §109/1245 b2Draw::~b2Draw()  0x23c148  size 24  6 条（0x23c148..0x23c160）
 * @func 0x23c148 0x23c170  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c148 ldr r3, [pc, #0xc]
 *   @0x23c14c ldr r3, [pc, r3]
 *   @0x23c150 add r3, r3, #8
 *   @0x23c154 str r3, [r0]
 *   @0x23c158 bx lr
 *   @0x23c15c andseq r5, r11, r0, lsr #7
 *
 * ══ §110/1245 CPhysicsDebugRender::~CPhysicsDebugRender()  0x23c160  size 24  6 条（0x23c160..0x23c178）
 * @func 0x23c160 0x23c178  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c160 ldr r3, [pc, #0xc]
 *   @0x23c164 ldr r3, [pc, r3]
 *   @0x23c168 add r3, r3, #8
 *   @0x23c16c str r3, [r0]
 *   @0x23c170 bx lr
 *   @0x23c174 andseq r5, r11, r8, lsl #7
 *
 * ══ §111/1245 COwnedObject::~COwnedObject()  0x23c634  size 24  6 条（0x23c634..0x23c64c）
 * @func 0x23c634 0x23c65c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c634 ldr r3, [pc, #0xc]
 *   @0x23c638 ldr r3, [pc, r3]
 *   @0x23c63c add r3, r3, #8
 *   @0x23c640 str r3, [r0]
 *   @0x23c644 bx lr
 *   @0x23c648 ldrheq r4, [r11], -r8
 *
 * ══ §112/1245 F_JSNull(RValue&, CInstance*, CInstance*, int, RValue*)  0x23c65c  size 24  6 条（0x23c65c..0x23c674）
 * @func 0x23c65c 0x23c684  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c65c mov r3, #0
 *   @0x23c660 mov r2, #12
 *   @0x23c664 str r3, [r0]
 *   @0x23c668 str r2, [r0, #0xc]
 *   @0x23c66c str r3, [r0, #0x4]
 *   @0x23c670 bx lr
 *
 * ══ §113/1245 F_JSError(RValue&, CInstance*, CInstance*, int, RValue*)  0x23ca6c  size 24  6 条（0x23ca6c..0x23ca84）
 * @func 0x23ca6c 0x23ca84  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23ca6c push {r3, lr}
 *   @0x23ca70 mov r1, #0
 *   @0x23ca74 ldr r0, [sp, #0x8]
 *   @0x23ca78 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x23ca7c pop {r3, lr}
 *   @0x23ca80 b 0xd547c <_Z7YYErrorPKcz>
 *
 * ══ §114/1245 operator new[](unsigned int, char const*, int)  0x27d164  size 24  6 条（0x27d164..0x27d17c）
 * @func 0x27d164 0x27d17c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27d164 ldr r1, [pc, #0xc]
 *   @0x27d168 movw r2, #0x531
 *   @0x27d16c mov r3, #1
 *   @0x27d170 add r1, pc, r1
 *   @0x27d174 b 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x27d178 andeq r10, sp, r0, ror r0
 *
 * ══ §115/1245 operator new[](unsigned int, std::nothrow_t const&)  0x27d1ac  size 24  6 条（0x27d1ac..0x27d1c4）
 * @func 0x27d1ac 0x27d1c4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27d1ac ldr r1, [pc, #0xc]
 *   @0x27d1b0 movw r2, #0x544
 *   @0x27d1b4 mov r3, #1
 *   @0x27d1b8 add r1, pc, r1
 *   @0x27d1bc b 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x27d1c0 andeq r10, sp, r8, lsr #32
 *
 * ══ §116/1245 Mutex::~Mutex()  0x27e020  size 24  6 条（0x27e020..0x27e038）
 * @func 0x27e020 0x27e038  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c94
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e020 push {r4, lr}
 *   @0x27e024 mov r4, r0
 *   @0x27e028 add r0, r0, #4
 *   @0x27e02c bl 0xb6c94 <pthread_mutex_destroy@plt>
 *   @0x27e030 mov r0, r4
 *   @0x27e034 pop {r4, pc}
 *
 * ══ §117/1245 anon_27e0a4  0x27e0a4  size 24  6 条（0x27e0a4..0x27e0bc）
 * @func 0x27e0a4 0x27e0bc  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1 / 0x9×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e0a4 push {r4, lr}
 *   @0x27e0a8 mov r4, r0
 *   @0x27e0ac ldr r3, [r0, #0x10]
 *   @0x27e0b0 blx r3
 *   @0x27e0b4 mov r3, #0
 *   @0x27e0b8 strb r3, [r4, #0x9]
 *
 * ══ §118/1245 array_list_get_idx  0x27e200  size 24  6 条（0x27e200..0x27e218）
 * @func 0x27e200 0x27e218  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e200 ldr r3, [r0, #0x4]
 *   @0x27e204 cmp r3, r1
 *   @0x27e208 ldrgt r3, [r0]
 *   @0x27e20c ldrgt r0, [r3, r1, lsl #2]
 *   @0x27e210 movle r0, #0
 *   @0x27e214 bx lr
 *
 * ══ §119/1245 _spCurveTimeline_deinit  0x28171c  size 24  6 条（0x28171c..0x281734）
 * @func 0x28171c 0x281734  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spTimeline_deinit
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28171c push {r4, lr}
 *   @0x281720 mov r4, r0
 *   @0x281724 bl 0x281364 <_spTimeline_deinit>
 *   @0x281728 ldr r0, [r4, #0x8]
 *   @0x28172c pop {r4, lr}
 *   @0x281730 b 0x285c80 <_free>
 *
 * ══ §120/1245 spCurveTimeline_setLinear  0x2817a8  size 24  6 条（0x2817a8..0x2817c0）
 * @func 0x2817a8 0x2817d0  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2817a8 ldr r3, [r0, #0x8]
 *   @0x2817ac mov r2, #76
 *   @0x2817b0 mov r0, #0
 *   @0x2817b4 mla r1, r2, r1, r3
 *   @0x2817b8 str r0, [r1]
 *   @0x2817bc bx lr
 *
 * ══ §121/1245 spCurveTimeline_setStepped  0x2817c0  size 24  6 条（0x2817c0..0x2817d8）
 * @func 0x2817c0 0x2817d8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2817c0 ldr r3, [r0, #0x8]
 *   @0x2817c4 mov r2, #76
 *   @0x2817c8 mov r12, #1065353216
 *   @0x2817cc mla r1, r2, r1, r3
 *   @0x2817d0 str r12, [r1]
 *   @0x2817d4 bx lr
 *
 * ══ §122/1245 spRotateTimeline_create  0x282a90  size 24  6 条（0x282a90..0x282aa8）
 * @func 0x282a90 0x282ab8  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282a90 ldr r3, [pc, #0xc]
 *   @0x282a94 mov r1, #1
 *   @0x282a98 mov r2, #2
 *   @0x282a9c ldr r3, [pc, r3]
 *   @0x282aa0 b 0x282a10 <_spBaseTimeline_create>
 *   @0x282aa4 andseq lr, r6, r8, lsl #28
 *
 * ══ §123/1245 spTranslateTimeline_create  0x282abc  size 24  6 条（0x282abc..0x282ad4）
 * @func 0x282abc 0x282ad4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282abc ldr r3, [pc, #0xc]
 *   @0x282ac0 mov r1, #2
 *   @0x282ac4 mov r2, #3
 *   @0x282ac8 ldr r3, [pc, r3]
 *   @0x282acc b 0x282a10 <_spBaseTimeline_create>
 *   @0x282ad0 andseq lr, r6, r0, ror #27
 *
 * ══ §124/1245 spScaleTimeline_create  0x282b04  size 24  6 条（0x282b04..0x282b1c）
 * @func 0x282b04 0x282b2c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282b04 ldr r3, [pc, #0xc]
 *   @0x282b08 mov r1, #0
 *   @0x282b0c mov r2, #3
 *   @0x282b10 ldr r3, [pc, r3]
 *   @0x282b14 b 0x282a10 <_spBaseTimeline_create>
 *   @0x282b18 mulseq r6, r12, sp
 *
 * ══ §125/1245 spShearTimeline_create  0x282b20  size 24  6 条（0x282b20..0x282b38）
 * @func 0x282b20 0x282b48  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282b20 ldr r3, [pc, #0xc]
 *   @0x282b24 mov r1, #3
 *   @0x282b28 mov r2, r1
 *   @0x282b2c ldr r3, [pc, r3]
 *   @0x282b30 b 0x282a10 <_spBaseTimeline_create>
 *   @0x282b34 andseq lr, r6, r4, lsl #27
 *
 * ══ §126/1245 spColorTimeline_create  0x282b3c  size 24  6 条（0x282b3c..0x282b54）
 * @func 0x282b3c 0x282b54  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282b3c ldr r3, [pc, #0xc]
 *   @0x282b40 mov r1, #4
 *   @0x282b44 mov r2, #5
 *   @0x282b48 ldr r3, [pc, r3]
 *   @0x282b4c b 0x282a10 <_spBaseTimeline_create>
 *   @0x282b50 andseq lr, r6, r12, ror #26
 *
 * ══ §127/1245 spIkConstraintTimeline_create  0x282f74  size 24  6 条（0x282f74..0x282f8c）
 * @func 0x282f74 0x282f8c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282f74 ldr r3, [pc, #0xc]
 *   @0x282f78 mov r1, #9
 *   @0x282f7c mov r2, #3
 *   @0x282f80 ldr r3, [pc, r3]
 *   @0x282f84 b 0x282a10 <_spBaseTimeline_create>
 *   @0x282f88 andseq lr, r6, r8, asr r9
 *
 * ══ §128/1245 spTransformConstraintTimeline_create  0x282fb8  size 24  6 条（0x282fb8..0x282fd0）
 * @func 0x282fb8 0x282fd0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282fb8 ldr r3, [pc, #0xc]
 *   @0x282fbc mov r1, #10
 *   @0x282fc0 mov r2, #5
 *   @0x282fc4 ldr r3, [pc, r3]
 *   @0x282fc8 b 0x282a10 <_spBaseTimeline_create>
 *   @0x282fcc andseq lr, r6, r8, lsl r9
 *
 * ══ §129/1245 spPathConstraintPositionTimeline_create  0x283010  size 24  6 条（0x283010..0x283028）
 * @func 0x283010 0x283038  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x283010 ldr r3, [pc, #0xc]
 *   @0x283014 mov r1, #11
 *   @0x283018 mov r2, #2
 *   @0x28301c ldr r3, [pc, r3]
 *   @0x283020 b 0x282a10 <_spBaseTimeline_create>
 *   @0x283024 andseq lr, r6, r4, asr #17
 *
 * ══ §130/1245 spPathConstraintSpacingTimeline_create  0x28303c  size 24  6 条（0x28303c..0x283054）
 * @func 0x28303c 0x283064  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28303c ldr r3, [pc, #0xc]
 *   @0x283040 mov r1, #12
 *   @0x283044 mov r2, #2
 *   @0x283048 ldr r3, [pc, r3]
 *   @0x28304c b 0x282a10 <_spBaseTimeline_create>
 *   @0x283050 mulseq r6, r12, r8
 *
 * ══ §131/1245 spPathConstraintMixTimeline_create  0x283068  size 24  6 条（0x283068..0x283080）
 * @func 0x283068 0x283080  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x283068 ldr r3, [pc, #0xc]
 *   @0x28306c mov r1, #13
 *   @0x283070 mov r2, #3
 *   @0x283074 ldr r3, [pc, r3]
 *   @0x283078 b 0x282a10 <_spBaseTimeline_create>
 *   @0x28307c andseq lr, r6, r4, ror r8
 *
 * ══ §132/1245 spAnimationState_getCurrent  0x283aac  size 24  6 条（0x283aac..0x283ac4）
 * @func 0x283aac 0x283ac4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x283aac ldr r3, [r0, #0xc]
 *   @0x283ab0 cmp r3, r1
 *   @0x283ab4 ldrgt r3, [r0, #0x10]
 *   @0x283ab8 ldrgt r0, [r3, r1, lsl #2]
 *   @0x283abc movle r0, #0
 *   @0x283ac0 bx lr
 *
 * ══ §133/1245 _spBoundingBoxAttachment_dispose  0x285ae0  size 24  6 条（0x285ae0..0x285af8）
 * @func 0x285ae0 0x285af8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spVertexAttachment_deinit
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285ae0 push {r4, lr}
 *   @0x285ae4 mov r4, r0
 *   @0x285ae8 bl 0x28f62c <_spVertexAttachment_deinit>
 *   @0x285aec mov r0, r4
 *   @0x285af0 pop {r4, lr}
 *   @0x285af4 b 0x285c80 <_free>
 *
 * ══ §134/1245 spSkeleton_setToSetupPose  0x28a0b0  size 24  6 条（0x28a0b0..0x28a0c8）
 * @func 0x28a0b0 0x28a0c8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spSkeleton_setBonesToSetupPose
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28a0b0 push {r4, lr}
 *   @0x28a0b4 mov r4, r0
 *   @0x28a0b8 bl 0x289f70 <spSkeleton_setBonesToSetupPose>
 *   @0x28a0bc mov r0, r4
 *   @0x28a0c0 pop {r4, lr}
 *   @0x28a0c4 b 0x28a064 <spSkeleton_setSlotsToSetupPose>
 *
 * ══ §135/1245 spSkeletonJson_create  0x28b734  size 24  6 条（0x28b734..0x28b74c）
 * @func 0x28b734 0x28b74c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spAtlasAttachmentLoader_create / spSkeletonJson_createWithLoader
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28b734 push {r3, lr}
 *   @0x28b738 bl 0x284bb4 <spAtlasAttachmentLoader_create>
 *   @0x28b73c bl 0x28b700 <spSkeletonJson_createWithLoader>
 *   @0x28b740 mov r3, #1
 *   @0x28b744 str r3, [r0, #0xc]
 *   @0x28b748 pop {r3, pc}
 *
 * ══ §136/1245 setJNIEnv  0x290614  size 24  6 条（0x290614..0x29062c）
 * @func 0x290614 0x29062c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x290614 ldr r3, [pc, #0xc]
 *   @0x290618 mov r1, r0
 *   @0x29061c ldr r3, [pc, r3]
 *   @0x290620 ldr r0, [r3]
 *   @0x290624 b 0xb6d3c <pthread_setspecific@plt>
 *   @0x290628 andseq r1, r6, r8, lsl #6
 *
 * ══ §137/1245 Java_com_yoyogames_runner_RunnerJNILib_IAPStoreLoadEvent  0x294ac0  size 24  6 条（0x294ac0..0x294ad8）
 * @func 0x294ac0 0x294ad8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x294ac0 push {r4, lr}
 *   @0x294ac4 mov r4, r2
 *   @0x294ac8 bl 0x290614 <setJNIEnv>
 *   @0x294acc mov r0, r4
 *   @0x294ad0 pop {r4, lr}
 *   @0x294ad4 b 0x155630 <_Z19YYIAPStoreLoadEventi>
 *
 * ══ §138/1245 Java_com_yoyogames_runner_RunnerJNILib_IAPRestoreEvent  0x294be0  size 24  6 条（0x294be0..0x294bf8）
 * @func 0x294be0 0x294c08  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x294be0 push {r4, lr}
 *   @0x294be4 mov r4, r2
 *   @0x294be8 bl 0x290614 <setJNIEnv>
 *   @0x294bec mov r0, r4
 *   @0x294bf0 pop {r4, lr}
 *   @0x294bf4 b 0x1556a8 <_Z17YYIAPRestoreEventi>
 *
 * ══ §139/1245 F_NETWORK_Destroy_Socket(RValue&, CInstance*, CInstance*, int, RValue*)  0x29937c  size 24  6 条（0x29937c..0x299394）
 * @func 0x29937c 0x299394  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29937c push {r3, lr}
 *   @0x299380 mov r1, #0
 *   @0x299384 ldr r0, [sp, #0x8]
 *   @0x299388 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x29938c pop {r3, lr}
 *   @0x299390 b 0x299244 <_Z10FreeSocketi>
 *
 * ══ §140/1245 Debug_SetBreakPoint(unsigned int*, bool, unsigned int, unsigned char*)  0x29c870  size 24  6 条（0x29c870..0x29c888）
 * @func 0x29c870 0x29c888  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29c870 cmp r1, #0
 *   @0x29c874 bne 0x29c87c <_Z19Debug_SetBreakPointPjbjPh+0xc>
 *   @0x29c878 b 0xd832c <_ZN2VM15ClearBreakpointEPj>
 *   @0x29c87c mov r1, r2
 *   @0x29c880 mov r2, r3
 *   @0x29c884 b 0xd8270 <_ZN2VM13SetBreakpointEPjjPh>
 *
 * ══ §141/1245 png_calloc  0x2a6cd8  size 24  6 条（0x2a6cd8..0x2a6cf0）
 * @func 0x2a6cd8 0x2a6cfc  size 36  9 条
 * 部分覆盖: 本节 9/16 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 8/14 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 7/12 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_malloc / 0xb65b0
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6cd8 push {r3, r4, r5, lr}
 *   @0x2a6cdc bl 0x2a6ca0 <png_malloc>
 *   @0x2a6ce0 mov r4, r0
 *   @0x2a6ce4 movs r1, #0x0
 *   @0x2a6ce8 blx 0xb65b0 <memset@plt>
 *   @0x2a6cec mov r0, r4
 *
 * ══ §142/1245 png_set_oFFs  0x2aeb0a  size 24  6 条（0x2aeb0a..0x2aeb22）
 * @func 0x2aeb0a 0x2aeb22  size 24  6 条
 * 部分覆盖: 本节 6/11 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x68×1 / 0x64×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2aeb0a cbz r0, 0x2aeb20 <png_set_oFFs+0x16>
 *   @0x2aeb0e str r3, [r1, #0x68]
 *   @0x2aeb12 str r2, [r1, #0x64]
 *   @0x2aeb16 stmvs r11, {r2, r3, r5, r6, r12, sp}
 *   @0x2aeb1a orr r3, r3, #0x100
 *   @0x2aeb1e str r3, [r1, #0x8]
 *
 * ══ §143/1245 png_set_pHYs  0x2aec6a  size 24  6 条（0x2aec6a..0x2aec82）
 * @func 0x2aec6a 0x2aec82  size 24  6 条
 * 部分覆盖: 本节 6/11 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x74×1 / 0x70×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2aec6a cbz r0, 0x2aec80 <png_set_pHYs+0x16>
 *   @0x2aec6e str r3, [r1, #0x74]
 *   @0x2aec72 str r2, [r1, #0x70]
 *   @0x2aec76 stmvs r11, {r3, r4, r5, r6, r12, sp}
 *   @0x2aec7a orr r3, r3, #0x80
 *   @0x2aec7e str r3, [r1, #0x8]
 *
 * ══ §144/1245 png_set_sBIT  0x2aed1c  size 24  6 条（0x2aed1c..0x2aed34）
 * @func 0x2aed1c 0x2aed44  size 40  10 条
 * 部分覆盖: 本节 10/19 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 9/17 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 8/15 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 7/13 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2aed1c cbz r0, 0x2aed32 <png_set_sBIT+0x16>
 *   @0x2aed20 ldr r3, [r2]
 *   @0x2aed24 ldrb r3, [r2, #0x4]
 *   @0x2aed28 stmvs r11, {r3, r6, r12, sp}
 *   @0x2aed2c orr r3, r3, #0x2
 *   @0x2aed30 str r3, [r1, #0x8]
 *
 * ══ §145/1245 png_set_swap  0x2af748  size 24  6 条（0x2af748..0x2af760）
 * @func 0x2af748 0x2af760  size 24  6 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x6bbf00
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af748 cbz r0, 0x2af75e <png_set_swap+0x16>
 *   @0x2af74c blhs 0x6bbf00 <g_SWFlinevertbuff+0x68e38>
 *   @0x2af750 bne 0x2af75e <png_set_swap+0x16>
 *   @0x2af754 .word 0xf0433134
 *   @0x2af758 .word 0xf8c00310
 *   @0x2af75c .word 0x47703134
 *
 * ══ §146/1245 png_set_packswap  0x2af77e  size 24  6 条（0x2af77e..0x2af796）
 * @func 0x2af77e 0x2af796  size 24  6 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x47bf36
 * 字段偏移 top8: 无
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af77e cbz r0, 0x2af794 <png_set_packswap+0x16>
 *   @0x2af782 blhs 0x47bf36 <targetStr+0xcf6>
 *   @0x2af786 bhi 0x2af794 <png_set_packswap+0x16>
 *   @0x2af78a vst4.8 {d19, d21, d23, d25}, [r3:256], r4
 *   @0x2af78e .word 0xf8c03380
 *   @0x2af792 .word 0x47703134
 *
 * ══ §147/1245 png_set_add_alpha  0x2af812  size 24  6 条（0x2af812..0x2af82a）
 * @func 0x2af812 0x2af83a  size 40  10 条
 * 部分覆盖: 本节 10/20 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 9/18 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 8/16 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 7/14 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af812 push {r4, lr}
 *   @0x2af816 cbz r0, 0x2af828 <png_set_add_alpha+0x16>
 *   @0x2af81a .word 0xf8d4ffd9
 *   @0x2af81e .word 0xf0433134
 *   @0x2af822 .word 0xf8c47380
 *   @0x2af826 ldclt p1, c3, [r0, #-208]
 *
 * ══ §148/1245 b2ChainShape::ComputeMass(b2MassData*, float) const  0x2c4940  size 24  6 条（0x2c4940..0x2c4958）
 * @func 0x2c4940 0x2c4958  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c4940 mov r3, #0
 *   @0x2c4944 str r3, [r1]
 *   @0x2c4948 str r3, [r1, #0x4]
 *   @0x2c494c str r3, [r1, #0x8]
 *   @0x2c4950 str r3, [r1, #0xc]
 *   @0x2c4954 bx lr
 *
 * ══ §149/1245 b2CircleShape::~b2CircleShape()  0x2c4e5c  size 24  6 条（0x2c4e5c..0x2c4e74）
 * @func 0x2c4e5c 0x2c4e74  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c4e5c ldr r3, [pc, #0xc]
 *   @0x2c4e60 ldr r3, [pc, r3]
 *   @0x2c4e64 add r3, r3, #8
 *   @0x2c4e68 str r3, [r0]
 *   @0x2c4e6c bx lr
 *   @0x2c4e70 andseq r12, r2, r0, asr #12
 *
 * ══ §150/1245 b2EdgeShape::~b2EdgeShape()  0x2c5240  size 24  6 条（0x2c5240..0x2c5258）
 * @func 0x2c5240 0x2c5258  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c5240 ldr r3, [pc, #0xc]
 *   @0x2c5244 ldr r3, [pc, r3]
 *   @0x2c5248 add r3, r3, #8
 *   @0x2c524c str r3, [r0]
 *   @0x2c5250 bx lr
 *   @0x2c5254 andseq r12, r2, r12, asr r2
 *
 * ══ §151/1245 b2PolygonShape::~b2PolygonShape()  0x2c5b90  size 24  6 条（0x2c5b90..0x2c5ba8）
 * @func 0x2c5b90 0x2c5ba8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c5b90 ldr r3, [pc, #0xc]
 *   @0x2c5b94 ldr r3, [pc, r3]
 *   @0x2c5b98 add r3, r3, #8
 *   @0x2c5b9c str r3, [r0]
 *   @0x2c5ba0 bx lr
 *   @0x2c5ba4 andseq r11, r2, r12, lsl #18
 *
 * ══ §152/1245 b2ContactFilter::~b2ContactFilter()  0x2c7810  size 24  6 条（0x2c7810..0x2c7828）
 * @func 0x2c7810 0x2c7828  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c7810 ldr r3, [pc, #0xc]
 *   @0x2c7814 ldr r3, [pc, r3]
 *   @0x2c7818 add r3, r3, #8
 *   @0x2c781c str r3, [r0]
 *   @0x2c7820 bx lr
 *   @0x2c7824 andseq r10, r2, r12, asr #5
 *
 * ══ §153/1245 b2Contact::~b2Contact()  0x2cbe0c  size 24  6 条（0x2cbe0c..0x2cbe24）
 * @func 0x2cbe0c 0x2cbe24  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cbe0c ldr r3, [pc, #0xc]
 *   @0x2cbe10 ldr r3, [pc, r3]
 *   @0x2cbe14 add r3, r3, #8
 *   @0x2cbe18 str r3, [r0]
 *   @0x2cbe1c bx lr
 *   @0x2cbe20 ldrsheq r5, [r2], -r0
 *
 * ══ §154/1245 b2EdgeAndCircleContact::~b2EdgeAndCircleContact()  0x2cc480  size 24  6 条（0x2cc480..0x2cc498）
 * @func 0x2cc480 0x2cc498  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc480 ldr r3, [pc, #0xc]
 *   @0x2cc484 ldr r3, [pc, r3]
 *   @0x2cc488 add r3, r3, #8
 *   @0x2cc48c str r3, [r0]
 *   @0x2cc490 bx lr
 *   @0x2cc494 andseq r5, r2, r12, ror r6
 *
 * ══ §155/1245 b2EdgeAndPolygonContact::~b2EdgeAndPolygonContact()  0x2cc590  size 24  6 条（0x2cc590..0x2cc5a8）
 * @func 0x2cc590 0x2cc5a8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc590 ldr r3, [pc, #0xc]
 *   @0x2cc594 ldr r3, [pc, r3]
 *   @0x2cc598 add r3, r3, #8
 *   @0x2cc59c str r3, [r0]
 *   @0x2cc5a0 bx lr
 *   @0x2cc5a4 andseq r5, r2, r12, ror #10
 *
 * ══ §156/1245 b2PolygonAndCircleContact::~b2PolygonAndCircleContact()  0x2cc6a0  size 24  6 条（0x2cc6a0..0x2cc6b8）
 * @func 0x2cc6a0 0x2cc6b8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc6a0 ldr r3, [pc, #0xc]
 *   @0x2cc6a4 ldr r3, [pc, r3]
 *   @0x2cc6a8 add r3, r3, #8
 *   @0x2cc6ac str r3, [r0]
 *   @0x2cc6b0 bx lr
 *   @0x2cc6b4 andseq r5, r2, r12, asr r4
 *
 * ══ §157/1245 b2PolygonContact::~b2PolygonContact()  0x2cc7b0  size 24  6 条（0x2cc7b0..0x2cc7c8）
 * @func 0x2cc7b0 0x2cc7c8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc7b0 ldr r3, [pc, #0xc]
 *   @0x2cc7b4 ldr r3, [pc, r3]
 *   @0x2cc7b8 add r3, r3, #8
 *   @0x2cc7bc str r3, [r0]
 *   @0x2cc7c0 bx lr
 *   @0x2cc7c4 andseq r5, r2, r12, asr #6
 *
 * ══ §158/1245 b2Joint::~b2Joint()  0x2cc8c4  size 24  6 条（0x2cc8c4..0x2cc8dc）
 * @func 0x2cc8c4 0x2cc8dc  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc8c4 ldr r3, [pc, #0xc]
 *   @0x2cc8c8 ldr r3, [pc, r3]
 *   @0x2cc8cc add r3, r3, #8
 *   @0x2cc8d0 str r3, [r0]
 *   @0x2cc8d4 bx lr
 *   @0x2cc8d8 andseq r5, r2, r12, lsl #5
 *
 * ══ §159/1245 b2DistanceJoint::~b2DistanceJoint()  0x2cca90  size 24  6 条（0x2cca90..0x2ccaa8）
 * @func 0x2cca90 0x2ccab8  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cca90 ldr r3, [pc, #0xc]
 *   @0x2cca94 ldr r3, [pc, r3]
 *   @0x2cca98 add r3, r3, #8
 *   @0x2cca9c str r3, [r0]
 *   @0x2ccaa0 bx lr
 *   @0x2ccaa4 andseq r5, r2, r0, asr #1
 *
 * ══ §160/1245 b2FrictionJoint::~b2FrictionJoint()  0x2cd3dc  size 24  6 条（0x2cd3dc..0x2cd3f4）
 * @func 0x2cd3dc 0x2cd3f4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cd3dc ldr r3, [pc, #0xc]
 *   @0x2cd3e0 ldr r3, [pc, r3]
 *   @0x2cd3e4 add r3, r3, #8
 *   @0x2cd3e8 str r3, [r0]
 *   @0x2cd3ec bx lr
 *   @0x2cd3f0 andseq r4, r2, r4, ror r7
 *
 * ══ §161/1245 b2MotorJoint::~b2MotorJoint()  0x2ce030  size 24  6 条（0x2ce030..0x2ce048）
 * @func 0x2ce030 0x2ce048  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ce030 ldr r3, [pc, #0xc]
 *   @0x2ce034 ldr r3, [pc, r3]
 *   @0x2ce038 add r3, r3, #8
 *   @0x2ce03c str r3, [r0]
 *   @0x2ce040 bx lr
 *   @0x2ce044 andseq r3, r2, r0, lsr #22
 *
 * ══ §162/1245 b2MouseJoint::GetAnchorA() const  0x2ce950  size 24  6 条（0x2ce950..0x2ce968）
 * @func 0x2ce950 0x2ce968  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ce950 add r1, r1, #76
 *   @0x2ce954 mov r3, r0
 *   @0x2ce958 ldm r1, {r0, r1}
 *   @0x2ce95c stm r3, {r0, r1}
 *   @0x2ce960 mov r0, r3
 *   @0x2ce964 bx lr
 *
 * ══ §163/1245 b2MouseJoint::GetReactionTorque(float) const  0x2ce9c8  size 24  6 条（0x2ce9c8..0x2ce9e0）
 * @func 0x2ce9c8 0x2ce9e0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ce9c8 vmov s14, r1
 *   @0x2ce9cc vldr s15, [pc, #8]
 *   @0x2ce9d0 vmul.f32 s14, s14, s15
 *   @0x2ce9d4 vmov r0, s14
 *   @0x2ce9d8 bx lr
 *   @0x2ce9dc andeq r0, r0, r0
 *
 * ══ §164/1245 b2MouseJoint::~b2MouseJoint()  0x2cea04  size 24  6 条（0x2cea04..0x2cea1c）
 * @func 0x2cea04 0x2cea2c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cea04 ldr r3, [pc, #0xc]
 *   @0x2cea08 ldr r3, [pc, r3]
 *   @0x2cea0c add r3, r3, #8
 *   @0x2cea10 str r3, [r0]
 *   @0x2cea14 bx lr
 *   @0x2cea18 andseq r3, r2, r12, asr #2
 *
 * ══ §165/1245 b2PrismaticJoint::~b2PrismaticJoint()  0x2cf194  size 24  6 条（0x2cf194..0x2cf1ac）
 * @func 0x2cf194 0x2cf1ac  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cf194 ldr r3, [pc, #0xc]
 *   @0x2cf198 ldr r3, [pc, r3]
 *   @0x2cf19c add r3, r3, #8
 *   @0x2cf1a0 str r3, [r0]
 *   @0x2cf1a4 bx lr
 *   @0x2cf1a8 ldrheq r2, [r2], -r12
 *
 * ══ §166/1245 b2PulleyJoint::~b2PulleyJoint()  0x2d071c  size 24  6 条（0x2d071c..0x2d0734）
 * @func 0x2d071c 0x2d0734  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d071c ldr r3, [pc, #0xc]
 *   @0x2d0720 ldr r3, [pc, r3]
 *   @0x2d0724 add r3, r3, #8
 *   @0x2d0728 str r3, [r0]
 *   @0x2d072c bx lr
 *   @0x2d0730 andseq r1, r2, r4, lsr r4
 *
 * ══ §167/1245 b2PulleyJoint::GetGroundAnchorA() const  0x2d1154  size 24  6 条（0x2d1154..0x2d116c）
 * @func 0x2d1154 0x2d117c  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d1154 add r1, r1, #68
 *   @0x2d1158 mov r3, r0
 *   @0x2d115c ldm r1, {r0, r1}
 *   @0x2d1160 stm r3, {r0, r1}
 *   @0x2d1164 mov r0, r3
 *   @0x2d1168 bx lr
 *
 * ══ §168/1245 b2PulleyJoint::GetGroundAnchorB() const  0x2d116c  size 24  6 条（0x2d116c..0x2d1184）
 * @func 0x2d116c 0x2d1194  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d116c add r1, r1, #76
 *   @0x2d1170 mov r3, r0
 *   @0x2d1174 ldm r1, {r0, r1}
 *   @0x2d1178 stm r3, {r0, r1}
 *   @0x2d117c mov r0, r3
 *   @0x2d1180 bx lr
 *
 * ══ §169/1245 b2RevoluteJoint::~b2RevoluteJoint()  0x2d1340  size 24  6 条（0x2d1340..0x2d1358）
 * @func 0x2d1340 0x2d1358  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d1340 ldr r3, [pc, #0xc]
 *   @0x2d1344 ldr r3, [pc, r3]
 *   @0x2d1348 add r3, r3, #8
 *   @0x2d134c str r3, [r0]
 *   @0x2d1350 bx lr
 *   @0x2d1354 andseq r0, r2, r0, lsl r8
 *
 * ══ §170/1245 b2RopeJoint::~b2RopeJoint()  0x2d251c  size 24  6 条（0x2d251c..0x2d2534）
 * @func 0x2d251c 0x2d2534  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d251c ldr r3, [pc, #0xc]
 *   @0x2d2520 ldr r3, [pc, r3]
 *   @0x2d2524 add r3, r3, #8
 *   @0x2d2528 str r3, [r0]
 *   @0x2d252c bx lr
 *   @0x2d2530 andseq pc, r1, r4, lsr r6
 *
 * ══ §171/1245 b2WeldJoint::~b2WeldJoint()  0x2d2e94  size 24  6 条（0x2d2e94..0x2d2eac）
 * @func 0x2d2e94 0x2d2eac  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2e94 ldr r3, [pc, #0xc]
 *   @0x2d2e98 ldr r3, [pc, r3]
 *   @0x2d2e9c add r3, r3, #8
 *   @0x2d2ea0 str r3, [r0]
 *   @0x2d2ea4 bx lr
 *   @0x2d2ea8 ldrheq lr, [r1], -r12
 *
 * ══ §172/1245 b2WheelJoint::~b2WheelJoint()  0x2d3a00  size 24  6 条（0x2d3a00..0x2d3a18）
 * @func 0x2d3a00 0x2d3a18  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d3a00 ldr r3, [pc, #0xc]
 *   @0x2d3a04 ldr r3, [pc, r3]
 *   @0x2d3a08 add r3, r3, #8
 *   @0x2d3a0c str r3, [r0]
 *   @0x2d3a10 bx lr
 *   @0x2d3a14 andseq lr, r1, r0, asr r1
 *
 * ══ §173/1245 b2QueryCallback::~b2QueryCallback()  0x2d48a0  size 24  6 条（0x2d48a0..0x2d48b8）
 * @func 0x2d48a0 0x2d48c0  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d48a0 ldr r3, [pc, #0xc]
 *   @0x2d48a4 ldr r3, [pc, r3]
 *   @0x2d48a8 add r3, r3, #8
 *   @0x2d48ac str r3, [r0]
 *   @0x2d48b0 bx lr
 *   @0x2d48b4 ldrsbeq sp, [r1], -r12
 *
 * ══ §174/1245 b2ParticleSystem::SetParticleDensity(float)  0x2d8294  size 24  6 条（0x2d8294..0x2d82ac）
 * @func 0x2d8294 0x2d82bc  size 40  10 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d8294 vmov.f32 s14, #1.000000e+00
 *   @0x2d8298 str r1, [r0, #0xc]
 *   @0x2d829c vmov s15, r1
 *   @0x2d82a0 vdiv.f32 s15, s14, s15
 *   @0x2d82a4 vstr s15, [r0, #16]
 *   @0x2d82a8 bx lr
 *
 * ══ §175/1245 b2ChainAndCircleContact::~b2ChainAndCircleContact()  0x2e1c68  size 24  6 条（0x2e1c68..0x2e1c80）
 * @func 0x2e1c68 0x2e1c80  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e1c68 ldr r3, [pc, #0xc]
 *   @0x2e1c6c ldr r3, [pc, r3]
 *   @0x2e1c70 add r3, r3, #8
 *   @0x2e1c74 str r3, [r0]
 *   @0x2e1c78 bx lr
 *   @0x2e1c7c mulseq r0, r4, lr
 *
 * ══ §176/1245 b2ChainAndPolygonContact::~b2ChainAndPolygonContact()  0x2e1df4  size 24  6 条（0x2e1df4..0x2e1e0c）
 * @func 0x2e1df4 0x2e1e0c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e1df4 ldr r3, [pc, #0xc]
 *   @0x2e1df8 ldr r3, [pc, r3]
 *   @0x2e1dfc add r3, r3, #8
 *   @0x2e1e00 str r3, [r0]
 *   @0x2e1e04 bx lr
 *   @0x2e1e08 andseq pc, r0, r8, lsl #26
 *
 * ══ §177/1245 b2CircleContact::~b2CircleContact()  0x2e1f80  size 24  6 条（0x2e1f80..0x2e1f98）
 * @func 0x2e1f80 0x2e1f98  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e1f80 ldr r3, [pc, #0xc]
 *   @0x2e1f84 ldr r3, [pc, r3]
 *   @0x2e1f88 add r3, r3, #8
 *   @0x2e1f8c str r3, [r0]
 *   @0x2e1f90 bx lr
 *   @0x2e1f94 andseq pc, r0, r12, ror r11
 *
 * ══ §178/1245 b2GearJoint::~b2GearJoint()  0x2e3af4  size 24  6 条（0x2e3af4..0x2e3b0c）
 * @func 0x2e3af4 0x2e3b0c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e3af4 ldr r3, [pc, #0xc]
 *   @0x2e3af8 ldr r3, [pc, r3]
 *   @0x2e3afc add r3, r3, #8
 *   @0x2e3b00 str r3, [r0]
 *   @0x2e3b04 bx lr
 *   @0x2e3b08 andseq lr, r0, r12, asr r0
 *
 * ══ §179/1245 FT_Activate_Size  0x2e5e1e  size 24  6 条（0x2e5e1e..0x2e5e36）
 * @func 0x2e5e1e 0x2e5e36  size 24  6 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5e1e cbz r0, 0x2e5e2e <FT_Activate_Size+0x10>
 *   @0x2e5e22 cbz r3, 0x2e5e32 <FT_Activate_Size+0x14>
 *   @0x2e5e26 cbz r2, 0x2e5e32 <FT_Activate_Size+0x14>
 *   @0x2e5e2a movs r0, #0x0
 *   @0x2e5e2e movs r0, #0x24
 *   @0x2e5e32 movs r0, #0x23
 *
 * ══ §180/1245 FT_Render_Glyph  0x2e5ed8  size 24  6 条（0x2e5ed8..0x2e5ef0）
 * @func 0x2e5ed8 0x2e5ef0  size 24  6 条
 * 部分覆盖: 本节 6/11 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5ed8 mov r2, r1
 *   @0x2e5edc cbz r0, 0x2e5eec <FT_Render_Glyph+0x14>
 *   @0x2e5ee0 cbz r0, 0x2e5eec <FT_Render_Glyph+0x14>
 *   @0x2e5ee4 ldr r0, [r1, #0x4]
 *   @0x2e5ee8 b.w 0x2e5e70 <FT_Render_Glyph_Internal>
 *   @0x2e5eec movs r0, #0x6
 *
 * ══ §181/1245 FT_Tan  0x2e6fac  size 24  6 条（0x2e6fac..0x2e6fc4）
 * @func 0x2e6fac 0x2e6fc4  size 24  6 条
 * 部分覆盖: 本节 6/11 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6fac push {r0, r1, r2, lr}
 *   @0x2e6fb0 mov r0, sp
 *   @0x2e6fb4 stmdals r1, {r0, r2, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2e6fb8 ldr r1, [sp]
 *   @0x2e6fbc andlt pc, r3, r12, ror pc
 *   @0x2e6fc0 ldr pc, [sp], #4
 *
 * ══ §182/1245 FT_Stream_ReleaseFrame  0x2e7e0a  size 24  6 条（0x2e7e0a..0x2e7e22）
 * @func 0x2e7e0a 0x2e7e22  size 24  6 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e7e0a push {r4, lr}
 *   @0x2e7e0e cbz r0, 0x2e7e1c <FT_Stream_ReleaseFrame+0x12>
 *   @0x2e7e12 cbz r3, 0x2e7e1c <FT_Stream_ReleaseFrame+0x12>
 *   @0x2e7e16 ldr r1, [r1]
 *   @0x2e7e1a movwhs pc, #0xa8d
 *   @0x2e7e1e str r3, [r4]
 *
 * ══ §183/1245 FT_List_Add  0x2e8920  size 24  6 条（0x2e8920..0x2e8938）
 * @func 0x2e8920 0x2e8938  size 24  6 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e8920 cbz r0, 0x2e8936 <FT_List_Add+0x16>
 *   @0x2e8924 ldr r3, [r0, #0x4]
 *   @0x2e8928 str r2, [r1, #0x4]
 *   @0x2e892c cbz r3, 0x2e8932 <FT_List_Add+0x12>
 *   @0x2e8930 b 0x2e8934 <FT_List_Add+0x14>
 *   @0x2e8934 str r1, [r0, #0x4]
 *
 * ══ §184/1245 FT_List_Insert  0x2e89da  size 24  6 条（0x2e89da..0x2e89f2）
 * @func 0x2e89da 0x2e89f2  size 24  6 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e89da cbz r0, 0x2e89f0 <FT_List_Insert+0x16>
 *   @0x2e89de ldr r3, [r0]
 *   @0x2e89e2 str r2, [r1]
 *   @0x2e89e6 cbnz r3, 0x2e89ec <FT_List_Insert+0x12>
 *   @0x2e89ea b 0x2e89ee <FT_List_Insert+0x14>
 *   @0x2e89ee str r1, [r0]
 *
 * ══ §185/1245 FT_Done_FreeType  0x2e9b62  size 24  6 条（0x2e9b62..0x2e9b7a）
 * @func 0x2e9b62 0x2e9b7a  size 24  6 条
 * 部分覆盖: 本节 6/11 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_Done_Memory
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e9b62 push {r4, lr}
 *   @0x2e9b66 ldr r4, [r0]
 *   @0x2e9b6a qadd16mi pc, r0, r0
 *   @0x2e9b6e bl 0x2e9c74 <FT_Done_Memory>
 *   @0x2e9b72 movs r0, #0x0
 *   @0x2e9b76 movs r0, #0x21
 *
 * ══ §186/1245 ft_lzwstate_reset  0x316e42  size 24  6 条（0x316e42..0x316e5a）
 * @func 0x316e42 0x316e5a  size 24  6 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x1c×1 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x316e42 movs r3, #0x0
 *   @0x316e46 str r3, [r0, #0x4]
 *   @0x316e4a str r3, [r0, #0x1c]
 *   @0x316e4e subvs r3, r3, #32
 *   @0x316e52 str r3, [r0, #0x5c]
 *   @0x316e56 str r3, [r0]
 *
 * ══ §187/1245 FT_Stream_ExtractFrame  0x2e7ea2  size 22  6 条（0x2e7ea2..0x2e7eb8）
 * @func 0x2e7ea2 0x2e7eba  size 24  6 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e7ea2 push {r3, r4, r5, lr}
 *   @0x2e7ea6 mov r5, r2
 *   @0x2e7eaa ldmdblt r8, {r0, r1, r3, r4, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2e7eae ldr r3, [r4, #0x20]
 *   @0x2e7eb2 str r0, [r4, #0x20]
 *   @0x2e7eb6 pop {r3, r4, r5, pc}
 *
 * ══ §188/1245 Code_Main_GET_Argument_Relative()  0xcef94  size 20  5 条（0xcef94..0xcefa8）
 * @func 0xcef94 0xcefa8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcef94 ldr r3, [pc, #0x8]
 *   @0xcef98 ldr r3, [pc, r3]
 *   @0xcef9c ldrb r0, [r3]
 *   @0xcefa0 bx lr
 *   @0xcefa4 eorseq lr, r1, r4, lsr #23
 *
 * ══ §189/1245 CBucket<32768u, 1048576u, false>::Init()  0xd338c  size 20  5 条（0xd338c..0xd33a0）
 * @func 0xd338c 0xd33a0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd338c mov r3, #0
 *   @0xd3390 str r3, [r0, #0x4]
 *   @0xd3394 str r3, [r0, #0x8]
 *   @0xd3398 str r3, [r0, #0xc]
 *   @0xd339c bx lr
 *
 * ══ §190/1245 SetCurrSlotTraversalMap(int)  0xd5ac0  size 20  5 条（0xd5ac0..0xd5ad4）
 * @func 0xd5ac0 0xd5ad4  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd5ac0 ldr r3, [pc, #0x8]
 *   @0xd5ac4 ldr r3, [pc, r3]
 *   @0xd5ac8 str r0, [r3]
 *   @0xd5acc bx lr
 *   @0xd5ad0 eorseq r8, r1, r12, lsl #3
 *
 * ══ §191/1245 VMWriteBuffer::AddVal(float)  0xec6fc  size 20  5 条（0xec6fc..0xec710）
 * @func 0xec6fc 0xec710  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xec6fc vmov s13, r1
 *   @0xec700 mov r1, #1
 *   @0xec704 vcvt.f64.f32 d7, s13
 *   @0xec708 vmov r2, r3, d7
 *   @0xec70c b 0xec674 <_ZN13VMWriteBuffer3AddEiz>
 *
 * ══ §192/1245 DPlay_Session_Mode(bool)  0xf2bd8  size 20  5 条（0xf2bd8..0xf2bec）
 * @func 0xf2bd8 0xf2bfc  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2bd8 ldr r3, [pc, #0x8]
 *   @0xf2bdc ldr r3, [pc, r3]
 *   @0xf2be0 strb r0, [r3]
 *   @0xf2be4 bx lr
 *   @0xf2be8 eoreq r11, pc, r8, lsr r2
 *
 * ══ §193/1245 CFontGM::GetShift(int)  0xf6e78  size 20  5 条（0xf6e78..0xf6e8c）
 * @func 0xf6e78 0xf6e8c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CFontGM::GetGlyph(int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf6e78 push {r3, lr}
 *   @0xf6e7c bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi>
 *   @0xf6e80 cmp r0, #0
 *   @0xf6e84 ldrshne r0, [r0, #10]
 *   @0xf6e88 pop {r3, pc}
 *
 * ══ §194/1245 CFontGM::CFont_Assign(void*, void*)  0xf948c  size 20  5 条（0xf948c..0xf94a0）
 * @func 0xf948c 0xf94a0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf948c cmp r0, #0
 *   @0xf9490 bxeq lr
 *   @0xf9494 cmp r1, #0
 *   @0xf9498 bxeq lr
 *   @0xf949c b 0xf7dfc <_ZN7CFontGM6AssignEPS_>
 *
 * ══ §195/1245 CFontGM::GetTexture()  0xf94e4  size 20  5 条（0xf94e4..0xf94f8）
 * @func 0xf94e4 0xf94f8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf94e4 ldr r3, [r0, #0x3c]
 *   @0xf94e8 cmp r3, #0
 *   @0xf94ec movne r0, r3
 *   @0xf94f0 ldreq r0, [r0, #0x38]
 *   @0xf94f4 bx lr
 *
 * ══ §196/1245 Font_Number()  0xfa294  size 20  5 条（0xfa294..0xfa2a8）
 * @func 0xfa294 0xfa2a8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfa294 ldr r3, [pc, #0x8]
 *   @0xfa298 ldr r3, [pc, r3]
 *   @0xfa29c ldr r0, [r3]
 *   @0xfa2a0 bx lr
 *   @0xfa2a4 eoreq r3, pc, r8, asr #23
 *
 * ══ §197/1245 F_RoomGotoPrevious(RValue&, CInstance*, CInstance*, int, RValue*)  0x109ae0  size 20  5 条（0x109ae0..0x109af4）
 * @func 0x109ae0 0x109b04  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x109ae0 ldr r3, [pc, #0x8]
 *   @0x109ae4 ldr r3, [pc, r3]
 *   @0x109ae8 ldr r0, [r3]
 *   @0x109aec b 0x1c9e68 <_Z20Command_PreviousRoomi>
 *   @0x109af0 eoreq r4, lr, r4, asr #11
 *
 * ══ §198/1245 F_RoomGotoNext(RValue&, CInstance*, CInstance*, int, RValue*)  0x109af4  size 20  5 条（0x109af4..0x109b08）
 * @func 0x109af4 0x109b08  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x109af4 ldr r3, [pc, #0x8]
 *   @0x109af8 ldr r3, [pc, r3]
 *   @0x109afc ldr r0, [r3]
 *   @0x109b00 b 0x1c9ed0 <_Z16Command_NextRoomi>
 *   @0x109b04 .word 0x002e45b0
 *
 * ══ §199/1245 YYGML_room_goto_previous()  0x10c2e4  size 20  5 条（0x10c2e4..0x10c2f8）
 * @func 0x10c2e4 0x10c308  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10c2e4 ldr r3, [pc, #0x8]
 *   @0x10c2e8 ldr r3, [pc, r3]
 *   @0x10c2ec ldr r0, [r3]
 *   @0x10c2f0 b 0x1c9e68 <_Z20Command_PreviousRoomi>
 *   @0x10c2f4 eoreq r1, lr, r0, asr #27
 *
 * ══ §200/1245 YYGML_room_goto_next()  0x10c2f8  size 20  5 条（0x10c2f8..0x10c30c）
 * @func 0x10c2f8 0x10c31c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10c2f8 ldr r3, [pc, #0x8]
 *   @0x10c2fc ldr r3, [pc, r3]
 *   @0x10c300 ldr r0, [r3]
 *   @0x10c304 b 0x1c9ed0 <_Z16Command_NextRoomi>
 *   @0x10c308 eoreq r1, lr, r12, lsr #27
 *
 * ══ §201/1245 YYGML_room_restart()  0x10c30c  size 20  5 条（0x10c30c..0x10c320）
 * @func 0x10c30c 0x10c320  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10c30c ldr r3, [pc, #0x8]
 *   @0x10c310 ldr r3, [pc, r3]
 *   @0x10c314 ldr r0, [r3]
 *   @0x10c318 b 0x1c9f38 <_Z19Command_CurrentRoomi>
 *   @0x10c31c mlaeq lr, r8, sp, r1
 *
 * ══ §202/1245 F_DrawGetWindowsVertexBufferMethod(RValue&, CInstance*, CInstance*, int, RValue*)  0x1199e4  size 20  5 条（0x1199e4..0x1199f8）
 * @func 0x1199e4 0x119a08  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1199e4 mov r3, #0
 *   @0x1199e8 str r3, [r0, #0xc]
 *   @0x1199ec str r3, [r0]
 *   @0x1199f0 str r3, [r0, #0x4]
 *   @0x1199f4 bx lr
 *
 * ══ §203/1245 F_DrawGetWindowsAlternateSync(RValue&, CInstance*, CInstance*, int, RValue*)  0x1199f8  size 20  5 条（0x1199f8..0x119a0c）
 * @func 0x1199f8 0x119a1c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1199f8 mov r3, #0
 *   @0x1199fc str r3, [r0, #0xc]
 *   @0x119a00 str r3, [r0]
 *   @0x119a04 str r3, [r0, #0x4]
 *   @0x119a08 bx lr
 *
 * ══ §204/1245 F_DrawSetWindowsVertexBufferMethod(RValue&, CInstance*, CInstance*, int, RValue*)  0x119a0c  size 20  5 条（0x119a0c..0x119a20）
 * @func 0x119a0c 0x119a30  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119a0c mov r3, #0
 *   @0x119a10 str r3, [r0, #0xc]
 *   @0x119a14 str r3, [r0]
 *   @0x119a18 str r3, [r0, #0x4]
 *   @0x119a1c bx lr
 *
 * ══ §205/1245 F_DrawSetWindowsAlternateSync(RValue&, CInstance*, CInstance*, int, RValue*)  0x119a20  size 20  5 条（0x119a20..0x119a34）
 * @func 0x119a20 0x119a34  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119a20 mov r3, #0
 *   @0x119a24 str r3, [r0, #0xc]
 *   @0x119a28 str r3, [r0]
 *   @0x119a2c str r3, [r0, #0x4]
 *   @0x119a30 bx lr
 *
 * ══ §206/1245 F_WindowGetShowborder(RValue&, CInstance*, CInstance*, int, RValue*)  0x119af8  size 20  5 条（0x119af8..0x119b0c）
 * @func 0x119af8 0x119b1c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119af8 mov r3, #0
 *   @0x119afc str r3, [r0, #0xc]
 *   @0x119b00 str r3, [r0]
 *   @0x119b04 str r3, [r0, #0x4]
 *   @0x119b08 bx lr
 *
 * ══ §207/1245 F_WindowGetShowicons(RValue&, CInstance*, CInstance*, int, RValue*)  0x119b10  size 20  5 条（0x119b10..0x119b24）
 * @func 0x119b10 0x119b34  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119b10 mov r3, #0
 *   @0x119b14 str r3, [r0, #0xc]
 *   @0x119b18 str r3, [r0]
 *   @0x119b1c str r3, [r0, #0x4]
 *   @0x119b20 bx lr
 *
 * ══ §208/1245 F_WindowGetStayontop(RValue&, CInstance*, CInstance*, int, RValue*)  0x119b28  size 20  5 条（0x119b28..0x119b3c）
 * @func 0x119b28 0x119b4c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119b28 mov r3, #0
 *   @0x119b2c str r3, [r0, #0xc]
 *   @0x119b30 str r3, [r0]
 *   @0x119b34 str r3, [r0, #0x4]
 *   @0x119b38 bx lr
 *
 * ══ §209/1245 F_WindowGetSizeable(RValue&, CInstance*, CInstance*, int, RValue*)  0x119b40  size 20  5 条（0x119b40..0x119b54）
 * @func 0x119b40 0x119b60  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119b40 mov r3, #0
 *   @0x119b44 str r3, [r0, #0xc]
 *   @0x119b48 str r3, [r0]
 *   @0x119b4c str r3, [r0, #0x4]
 *   @0x119b50 bx lr
 *
 * ══ §210/1245 F_FontSetCacheSize(RValue&, CInstance*, CInstance*, int, RValue*)  0x12aa60  size 20  5 条（0x12aa60..0x12aa74）
 * @func 0x12aa60 0x12aa84  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12aa60 mov r3, #0
 *   @0x12aa64 str r3, [r0, #0xc]
 *   @0x12aa68 str r3, [r0]
 *   @0x12aa6c str r3, [r0, #0x4]
 *   @0x12aa70 bx lr
 *
 * ══ §211/1245 F_SpriteSetCacheSize(RValue&, CInstance*, CInstance*, int, RValue*)  0x12aa74  size 20  5 条（0x12aa74..0x12aa88）
 * @func 0x12aa74 0x12aa98  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12aa74 mov r3, #0
 *   @0x12aa78 str r3, [r0, #0xc]
 *   @0x12aa7c str r3, [r0]
 *   @0x12aa80 str r3, [r0, #0x4]
 *   @0x12aa84 bx lr
 *
 * ══ §212/1245 F_SpriteSetCacheSizeExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x12aa88  size 20  5 条（0x12aa88..0x12aa9c）
 * @func 0x12aa88 0x12aaac  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12aa88 mov r3, #0
 *   @0x12aa8c str r3, [r0, #0xc]
 *   @0x12aa90 str r3, [r0]
 *   @0x12aa94 str r3, [r0, #0x4]
 *   @0x12aa98 bx lr
 *
 * ══ §213/1245 F_SpriteGetTPE(RValue&, CInstance*, CInstance*, int, RValue*)  0x12aa9c  size 20  5 条（0x12aa9c..0x12aab0）
 * @func 0x12aa9c 0x12aab0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12aa9c mov r3, #0
 *   @0x12aaa0 str r3, [r0, #0xc]
 *   @0x12aaa4 str r3, [r0]
 *   @0x12aaa8 str r3, [r0, #0x4]
 *   @0x12aaac bx lr
 *
 * ══ §214/1245 yyFindData::yyFindData()  0x13aaac  size 20  5 条（0x13aaac..0x13aac0）
 * @func 0x13aaac 0x13aac0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13aaac mov r2, #0
 *   @0x13aab0 str r2, [r0]
 *   @0x13aab4 str r2, [r0, #0x4]
 *   @0x13aab8 str r2, [r0, #0x8]
 *   @0x13aabc bx lr
 *
 * ══ §215/1245 ParamCount()  0x13c3ac  size 20  5 条（0x13c3ac..0x13c3c0）
 * @func 0x13c3ac 0x13c3c0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13c3ac ldr r3, [pc, #0x8]
 *   @0x13c3b0 ldr r3, [pc, r3]
 *   @0x13c3b4 ldr r0, [r3]
 *   @0x13c3b8 bx lr
 *   @0x13c3bc .word 0x002b2ef0
 *
 * ══ §216/1245 F_ActionTimelineStop(RValue&, CInstance*, CInstance*, int, RValue*)  0x13d64c  size 20  5 条（0x13d64c..0x13d660）
 * @func 0x13d64c 0x13d660  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x154×1 / 0x15c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13d64c mov r2, #0
 *   @0x13d650 mov r3, #0
 *   @0x13d654 str r2, [r1, #0x154]
 *   @0x13d658 strb r3, [r1, #0x15c]
 *   @0x13d65c bx lr
 *
 * ══ §217/1245 YYGML_action_set_relative(bool)  0x141e34  size 20  5 条（0x141e34..0x141e48）
 * @func 0x141e34 0x141e58  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141e34 ldr r3, [pc, #0x8]
 *   @0x141e38 ldr r3, [pc, r3]
 *   @0x141e3c strb r0, [r3]
 *   @0x141e40 bx lr
 *   @0x141e44 eoreq r11, r10, r4, lsl #26
 *
 * ══ §218/1245 F_YoYo_DrawFlush(RValue&, CInstance*, CInstance*, int, RValue*)  0x143aa4  size 20  5 条（0x143aa4..0x143ab8）
 * @func 0x143aa4 0x143ab8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143aa4 mov r3, #0
 *   @0x143aa8 str r3, [r0, #0xc]
 *   @0x143aac str r3, [r0]
 *   @0x143ab0 str r3, [r0, #0x4]
 *   @0x143ab4 b 0x1852ec <_ZN8Graphics5FlushEv>
 *
 * ══ §219/1245 anon_15149c  0x15149c  size 20  5 条（0x15149c..0x1514b0）
 * @func 0x15149c 0x1514b0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GamepadSupportedM()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15149c push {r3, lr}
 *   @0x1514a0 bl 0x190ac4 <_Z17GamepadSupportedMv>
 *   @0x1514a4 cmp r0, #0
 *   @0x1514a8 popne {r3, pc}
 *   @0x1514ac pop {r3, lr}
 *
 * ══ §220/1245 F_IAP_Deprecated(RValue&, CInstance*, CInstance*, int, RValue*)  0x153220  size 20  5 条（0x153220..0x153234）
 * @func 0x153220 0x153234  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x153220 ldr r0, [pc, #0x8]
 *   @0x153224 mov r1, #1
 *   @0x153228 add r0, pc, r0
 *   @0x15322c b 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x153230 andseq r2, pc, r0, asr #27
 *
 * ══ §221/1245 F_YoYo_AdsEngagementAvailable(RValue&, CInstance*, CInstance*, int, RValue*)  0x156080  size 20  5 条（0x156080..0x156094）
 * @func 0x156080 0x1560a4  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156080 mov r3, #0
 *   @0x156084 str r3, [r0, #0xc]
 *   @0x156088 str r3, [r0]
 *   @0x15608c str r3, [r0, #0x4]
 *   @0x156090 bx lr
 *
 * ══ §222/1245 F_YoYoAdsEngagementActive(RValue&, CInstance*, CInstance*, int, RValue*)  0x156094  size 20  5 条（0x156094..0x1560a8）
 * @func 0x156094 0x1560b8  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156094 mov r3, #0
 *   @0x156098 str r3, [r0, #0xc]
 *   @0x15609c str r3, [r0]
 *   @0x1560a0 str r3, [r0, #0x4]
 *   @0x1560a4 bx lr
 *
 * ══ §223/1245 F_YoYo_Ads_Interstitial_Available(RValue&, CInstance*, CInstance*, int, RValue*)  0x1560b0  size 20  5 条（0x1560b0..0x1560c4）
 * @func 0x1560b0 0x1560d4  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1560b0 mov r3, #0
 *   @0x1560b4 str r3, [r0, #0xc]
 *   @0x1560b8 str r3, [r0]
 *   @0x1560bc str r3, [r0, #0x4]
 *   @0x1560c0 bx lr
 *
 * ══ §224/1245 F_YoYo_Ads_Interstitial_Display(RValue&, CInstance*, CInstance*, int, RValue*)  0x1560c4  size 20  5 条（0x1560c4..0x1560d8）
 * @func 0x1560c4 0x1560d8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1560c4 mov r3, #0
 *   @0x1560c8 str r3, [r0, #0xc]
 *   @0x1560cc str r3, [r0]
 *   @0x1560d0 str r3, [r0, #0x4]
 *   @0x1560d4 bx lr
 *
 * ══ §225/1245 F_YoYo_GetSessionKey(RValue&, CInstance*, CInstance*, int, RValue*)  0x156184  size 20  5 条（0x156184..0x156198）
 * @func 0x156184 0x1561a8  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156184 mov r3, #0
 *   @0x156188 str r3, [r0, #0xc]
 *   @0x15618c str r3, [r0]
 *   @0x156190 str r3, [r0, #0x4]
 *   @0x156194 bx lr
 *
 * ══ §226/1245 F_YoYo_CheckSecurity(RValue&, CInstance*, CInstance*, int, RValue*)  0x156198  size 20  5 条（0x156198..0x1561ac）
 * @func 0x156198 0x1561bc  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156198 mov r3, #0
 *   @0x15619c str r3, [r0, #0xc]
 *   @0x1561a0 str r3, [r0]
 *   @0x1561a4 str r3, [r0, #0x4]
 *   @0x1561a8 bx lr
 *
 * ══ §227/1245 F_YoYo_FacebookNull(RValue&, CInstance*, CInstance*, int, RValue*)  0x1561ac  size 20  5 条（0x1561ac..0x1561c0）
 * @func 0x1561ac 0x1561c0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1561ac mov r3, #0
 *   @0x1561b0 str r3, [r0, #0xc]
 *   @0x1561b4 str r3, [r0]
 *   @0x1561b8 str r3, [r0, #0x4]
 *   @0x1561bc bx lr
 *
 * ══ §228/1245 F_CodeIsCompiled(RValue&, CInstance*, CInstance*, int, RValue*)  0x156210  size 20  5 条（0x156210..0x156224）
 * @func 0x156210 0x156224  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156210 mov r3, #0
 *   @0x156214 str r3, [r0, #0xc]
 *   @0x156218 str r3, [r0]
 *   @0x15621c str r3, [r0, #0x4]
 *   @0x156220 bx lr
 *
 * ══ §229/1245 F_ExtensionStubFuncReal(RValue&, CInstance*, CInstance*, int, RValue*)  0x15636c  size 20  5 条（0x15636c..0x156380）
 * @func 0x15636c 0x156380  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15636c mov r3, #0
 *   @0x156370 str r3, [r0, #0xc]
 *   @0x156374 str r3, [r0]
 *   @0x156378 str r3, [r0, #0x4]
 *   @0x15637c bx lr
 *
 * ══ §230/1245 F_YoYo_AchievementLoadProgress(RValue&, CInstance*, CInstance*, int, RValue*)  0x1566c0  size 20  5 条（0x1566c0..0x1566d4）
 * @func 0x1566c0 0x1566d4  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1566c0 mov r3, #0
 *   @0x1566c4 str r3, [r0, #0xc]
 *   @0x1566c8 str r3, [r0]
 *   @0x1566cc str r3, [r0, #0x4]
 *   @0x1566d0 b 0x161208 <_Z25Achievement_Load_Progressv>
 *
 * ══ §231/1245 F_YoYo_GetConfig(RValue&, CInstance*, CInstance*, int, RValue*)  0x156bb8  size 20  5 条（0x156bb8..0x156bcc）
 * @func 0x156bb8 0x156bdc  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156bb8 ldr r3, [pc, #0x8]
 *   @0x156bbc ldr r3, [pc, r3]
 *   @0x156bc0 ldr r1, [r3]
 *   @0x156bc4 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x156bc8 eoreq r8, r9, r0, lsr #31
 *
 * ══ §232/1245 F_PlayerGetLaunchArgs(RValue&, CInstance*, CInstance*, int, RValue*)  0x156bcc  size 20  5 条（0x156bcc..0x156be0）
 * @func 0x156bcc 0x156be8  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156bcc ldr r3, [pc, #0x8]
 *   @0x156bd0 ldr r3, [pc, r3]
 *   @0x156bd4 ldr r1, [r3]
 *   @0x156bd8 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x156bdc mlaeq r9, r0, pc, r8
 *
 * ══ §233/1245 Set_AchievementSystem(bool)  0x159a60  size 20  5 条（0x159a60..0x159a74）
 * @func 0x159a60 0x159a84  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159a60 ldr r3, [pc, #0x8]
 *   @0x159a64 ldr r3, [pc, r3]
 *   @0x159a68 strb r0, [r3]
 *   @0x159a6c bx lr
 *   @0x159a70 eoreq r6, r9, r12, asr #1
 *
 * ══ §234/1245 Get_AchievementSystem()  0x159a74  size 20  5 条（0x159a74..0x159a88）
 * @func 0x159a74 0x159a88  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x159a74 ldr r3, [pc, #0x8]
 *   @0x159a78 ldr r3, [pc, r3]
 *   @0x159a7c ldrb r0, [r3]
 *   @0x159a80 bx lr
 *   @0x159a84 strhteq r6, [r9], -r8
 *
 * ══ §235/1245 GetOrientation  0x15e288  size 20  5 条（0x15e288..0x15e29c）
 * @func 0x15e288 0x15e29c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e288 ldr r3, [pc, #0x8]
 *   @0x15e28c ldr r3, [pc, r3]
 *   @0x15e290 ldr r0, [r3]
 *   @0x15e294 bx lr
 *   @0x15e298 eoreq r1, r9, r0, ror #23
 *
 * ══ §236/1245 F_Steam_ActivateOverlayBrowser(RValue&, CInstance*, CInstance*, int, RValue*)  0x161cb8  size 20  5 条（0x161cb8..0x161ccc）
 * @func 0x161cb8 0x161cdc  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161cb8 mov r3, #0
 *   @0x161cbc str r3, [r0, #0xc]
 *   @0x161cc0 str r3, [r0]
 *   @0x161cc4 str r3, [r0, #0x4]
 *   @0x161cc8 bx lr
 *
 * ══ §237/1245 F_Steam_ActivateOverlayUser(RValue&, CInstance*, CInstance*, int, RValue*)  0x161ccc  size 20  5 条（0x161ccc..0x161ce0）
 * @func 0x161ccc 0x161cf0  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161ccc mov r3, #0
 *   @0x161cd0 str r3, [r0, #0xc]
 *   @0x161cd4 str r3, [r0]
 *   @0x161cd8 str r3, [r0, #0x4]
 *   @0x161cdc bx lr
 *
 * ══ §238/1245 F_Steam_ActivateOverlayStore(RValue&, CInstance*, CInstance*, int, RValue*)  0x161ce0  size 20  5 条（0x161ce0..0x161cf4）
 * @func 0x161ce0 0x161d04  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161ce0 mov r3, #0
 *   @0x161ce4 str r3, [r0, #0xc]
 *   @0x161ce8 str r3, [r0]
 *   @0x161cec str r3, [r0, #0x4]
 *   @0x161cf0 bx lr
 *
 * ══ §239/1245 F_Steam_GetUserPersonaName(RValue&, CInstance*, CInstance*, int, RValue*)  0x161cf4  size 20  5 条（0x161cf4..0x161d08）
 * @func 0x161cf4 0x161d18  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161cf4 mov r3, #0
 *   @0x161cf8 str r3, [r0, #0xc]
 *   @0x161cfc str r3, [r0]
 *   @0x161d00 str r3, [r0, #0x4]
 *   @0x161d04 bx lr
 *
 * ══ §240/1245 F_Steam_Initialised(RValue&, CInstance*, CInstance*, int, RValue*)  0x161d08  size 20  5 条（0x161d08..0x161d1c）
 * @func 0x161d08 0x161d1c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161d08 mov r3, #0
 *   @0x161d0c str r3, [r0, #0xc]
 *   @0x161d10 str r3, [r0]
 *   @0x161d14 str r3, [r0, #0x4]
 *   @0x161d18 bx lr
 *
 * ══ §241/1245 RenderStateManager::RenderStateManager()  0x167e50  size 20  5 条（0x167e50..0x167e64）
 * @func 0x167e50 0x167e64  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RenderStateManager::Reset()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x167e50 push {r4, lr}
 *   @0x167e54 mov r4, r0
 *   @0x167e58 bl 0x167c34 <_ZN18RenderStateManager5ResetEv>
 *   @0x167e5c mov r0, r4
 *   @0x167e60 pop {r4, pc}
 *
 * ══ §242/1245 GR_D3D_Get_Alpha_Test_Ref()  0x1686d0  size 20  5 条（0x1686d0..0x1686e4）
 * @func 0x1686d0 0x1686f4  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1686d0 ldr r0, [pc, #0x8]
 *   @0x1686d4 mov r1, #10
 *   @0x1686d8 ldr r0, [pc, r0]
 *   @0x1686dc b 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x1686e0 eoreq r5, r8, r0, lsr #12
 *
 * ══ §243/1245 GR_D3D_Get_Alpha_Test_Func()  0x1686fc  size 20  5 条（0x1686fc..0x168710）
 * @func 0x1686fc 0x168710  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1686fc ldr r0, [pc, #0x8]
 *   @0x168700 mov r1, #11
 *   @0x168704 ldr r0, [pc, r0]
 *   @0x168708 b 0x167f8c <_ZN18RenderStateManager14GetRenderStateE12eRenderState>
 *   @0x16870c .word 0x002855f4
 *
 * ══ §244/1245 GR_D3D_Get_Texture_Repeat()  0x1689e0  size 20  5 条（0x1689e0..0x1689f4）
 * @func 0x1689e0 0x168a04  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1689e0 ldr r3, [pc, #0x8]
 *   @0x1689e4 ldr r3, [pc, r3]
 *   @0x1689e8 ldrb r0, [r3]
 *   @0x1689ec bx lr
 *   @0x1689f0 eoreq r7, r8, r8, lsr #14
 *
 * ══ §245/1245 GR_D3D_Get_Texture_Interpolation()  0x1689f4  size 20  5 条（0x1689f4..0x168a08）
 * @func 0x1689f4 0x168a08  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1689f4 ldr r3, [pc, #0x8]
 *   @0x1689f8 ldr r3, [pc, r3]
 *   @0x1689fc ldrb r0, [r3]
 *   @0x168a00 bx lr
 *   @0x168a04 eoreq r7, r8, r0, lsl r7
 *
 * ══ §246/1245 GR_Draw_Get_Color()  0x169ecc  size 20  5 条（0x169ecc..0x169ee0）
 * @func 0x169ecc 0x169ef0  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x169ecc ldr r3, [pc, #0x8]
 *   @0x169ed0 ldr r3, [pc, r3]
 *   @0x169ed4 ldr r0, [r3]
 *   @0x169ed8 bx lr
 *   @0x169edc eoreq r3, r8, r12, lsr #28
 *
 * ══ §247/1245 GR_Draw_Get_Color_Red()  0x169ee0  size 20  5 条（0x169ee0..0x169ef4）
 * @func 0x169ee0 0x169f04  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x169ee0 ldr r3, [pc, #0x8]
 *   @0x169ee4 ldr r3, [pc, r3]
 *   @0x169ee8 ldrb r0, [r3, #0x2]
 *   @0x169eec bx lr
 *   @0x169ef0 eoreq r3, r8, r8, lsl lr
 *
 * ══ §248/1245 GR_Draw_Get_Color_Green()  0x169ef4  size 20  5 条（0x169ef4..0x169f08）
 * @func 0x169ef4 0x169f18  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x1×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x169ef4 ldr r3, [pc, #0x8]
 *   @0x169ef8 ldr r3, [pc, r3]
 *   @0x169efc ldrb r0, [r3, #0x1]
 *   @0x169f00 bx lr
 *   @0x169f04 eoreq r3, r8, r4, lsl #28
 *
 * ══ §249/1245 GR_Draw_Get_Color_Blue()  0x169f08  size 20  5 条（0x169f08..0x169f1c）
 * @func 0x169f08 0x169f1c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x169f08 ldr r3, [pc, #0x8]
 *   @0x169f0c ldr r3, [pc, r3]
 *   @0x169f10 ldrb r0, [r3]
 *   @0x169f14 bx lr
 *   @0x169f18 .word 0x00283df0
 *
 * ══ §250/1245 GR_Draw_Get_D3DColor()  0x169f44  size 20  5 条（0x169f44..0x169f58）
 * @func 0x169f44 0x169f58  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x169f44 ldr r3, [pc, #0x8]
 *   @0x169f48 ldr r3, [pc, r3]
 *   @0x169f4c ldr r0, [r3]
 *   @0x169f50 bx lr
 *   @0x169f54 .word 0x00283db4
 *
 * ══ §251/1245 GR_Window_Set_Min_Width(int)  0x1799b0  size 20  5 条（0x1799b0..0x1799c4）
 * @func 0x1799b0 0x1799d4  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1799b0 ldr r3, [pc, #0x8]
 *   @0x1799b4 ldr r3, [pc, r3]
 *   @0x1799b8 str r0, [r3]
 *   @0x1799bc b 0x17af14 <_Z24GR_Window_Set_Min_WidthMi>
 *   @0x1799c0 eoreq r6, r7, r12, lsr #18
 *
 * ══ §252/1245 GR_Window_Set_Max_Width(int)  0x1799c4  size 20  5 条（0x1799c4..0x1799d8）
 * @func 0x1799c4 0x1799e8  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1799c4 ldr r3, [pc, #0x8]
 *   @0x1799c8 ldr r3, [pc, r3]
 *   @0x1799cc str r0, [r3]
 *   @0x1799d0 b 0x17af18 <_Z24GR_Window_Set_Max_WidthMi>
 *   @0x1799d4 eoreq r6, r7, r12, lsl r9
 *
 * ══ §253/1245 GR_Window_Set_Min_Height(int)  0x1799d8  size 20  5 条（0x1799d8..0x1799ec）
 * @func 0x1799d8 0x1799fc  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1799d8 ldr r3, [pc, #0x8]
 *   @0x1799dc ldr r3, [pc, r3]
 *   @0x1799e0 str r0, [r3]
 *   @0x1799e4 b 0x17af1c <_Z25GR_Window_Set_Min_HeightMi>
 *   @0x1799e8 eoreq r6, r7, r12, lsl #18
 *
 * ══ §254/1245 GR_Window_Set_Max_Height(int)  0x1799ec  size 20  5 条（0x1799ec..0x179a00）
 * @func 0x1799ec 0x179a00  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1799ec ldr r3, [pc, #0x8]
 *   @0x1799f0 ldr r3, [pc, r3]
 *   @0x1799f4 str r0, [r3]
 *   @0x1799f8 b 0x17af20 <_Z25GR_Window_Set_Max_HeightMi>
 *   @0x1799fc .word 0x002768fc
 *
 * ══ §255/1245 GR_Window_Mouse_Get_X()  0x17aab4  size 20  5 条（0x17aab4..0x17aac8）
 * @func 0x17aab4 0x17aad8  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17aab4 ldr r3, [pc, #0x8]
 *   @0x17aab8 ldr r3, [pc, r3]
 *   @0x17aabc ldr r0, [r3]
 *   @0x17aac0 bx lr
 *   @0x17aac4 eoreq r5, r7, r4, ror #1
 *
 * ══ §256/1245 GR_Window_Mouse_Get_Y()  0x17aac8  size 20  5 条（0x17aac8..0x17aadc）
 * @func 0x17aac8 0x17aadc  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17aac8 ldr r3, [pc, #0x8]
 *   @0x17aacc ldr r3, [pc, r3]
 *   @0x17aad0 ldr r0, [r3]
 *   @0x17aad4 bx lr
 *   @0x17aad8 eoreq r5, r7, r12, asr #1
 *
 * ══ §257/1245 GR_Window_Get_Caption()  0x17aefc  size 20  5 条（0x17aefc..0x17af10）
 * @func 0x17aefc 0x17af20  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17aefc ldr r3, [pc, #0x8]
 *   @0x17af00 ldr r3, [pc, r3]
 *   @0x17af04 ldr r0, [r3]
 *   @0x17af08 bx lr
 *   @0x17af0c eoreq r3, r7, r0, lsl #23
 *
 * ══ §258/1245 GR_Window_Get_Width()  0x17af50  size 20  5 条（0x17af50..0x17af64）
 * @func 0x17af50 0x17af74  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17af50 ldr r3, [pc, #0x8]
 *   @0x17af54 ldr r3, [pc, r3]
 *   @0x17af58 ldr r0, [r3]
 *   @0x17af5c bx lr
 *   @0x17af60 eoreq r4, r7, r8, asr #30
 *
 * ══ §259/1245 GR_Window_Get_Height()  0x17af64  size 20  5 条（0x17af64..0x17af78）
 * @func 0x17af64 0x17af88  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17af64 ldr r3, [pc, #0x8]
 *   @0x17af68 ldr r3, [pc, r3]
 *   @0x17af6c ldr r0, [r3]
 *   @0x17af70 bx lr
 *   @0x17af74 eoreq r4, r7, r8, lsr pc
 *
 * ══ §260/1245 InitOGLResources()  0x17da94  size 20  5 条（0x17da94..0x17daa8）
 * @func 0x17da94 0x17daa8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: InitTextureResources() / InitShaderManagerResources()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17da94 push {r3, lr}
 *   @0x17da98 bl 0x183178 <_Z20InitTextureResourcesv>
 *   @0x17da9c bl 0x188144 <_Z26InitShaderManagerResourcesv>
 *   @0x17daa0 pop {r3, lr}
 *   @0x17daa4 b 0x183c80 <_Z26InitVertexBuilderResourcesv>
 *
 * ══ §261/1245 Graphics::SetVSync(bool)  0x17db0c  size 20  5 条（0x17db0c..0x17db20）
 * @func 0x17db0c 0x17db24  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17db0c ldr r3, [pc, #0x8]
 *   @0x17db10 ldr r3, [pc, r3]
 *   @0x17db14 strb r0, [r3]
 *   @0x17db18 bx lr
 *   @0x17db1c eoreq r2, r7, r0, lsr r9
 *
 * ══ §262/1245 DisplaySetFrequency(int)  0x17db78  size 20  5 条（0x17db78..0x17db8c）
 * @func 0x17db78 0x17db9c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17db78 mov r2, r0
 *   @0x17db7c mov r0, #0
 *   @0x17db80 mov r1, r0
 *   @0x17db84 mov r3, r0
 *   @0x17db88 b 0x17db64 <_Z10DisplaySetiiii>
 *
 * ══ §263/1245 DisplaySetColorDepth(int)  0x17db8c  size 20  5 条（0x17db8c..0x17dba0）
 * @func 0x17db8c 0x17dbb0  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17db8c mov r3, r0
 *   @0x17db90 mov r0, #0
 *   @0x17db94 mov r1, r0
 *   @0x17db98 mov r2, r0
 *   @0x17db9c b 0x17db64 <_Z10DisplaySetiiii>
 *
 * ══ §264/1245 FINALIZE_Graphics_Display()  0x17dbb8  size 20  5 条（0x17dbb8..0x17dbcc）
 * @func 0x17dbb8 0x17dbcc  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DisplayReset() / InvalidateOGLResources()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17dbb8 push {r3, lr}
 *   @0x17dbbc bl 0x17dba0 <_Z12DisplayResetv>
 *   @0x17dbc0 bl 0x17daa8 <_Z22InvalidateOGLResourcesv>
 *   @0x17dbc4 pop {r3, lr}
 *   @0x17dbc8 b 0x17dafc <_Z18DeleteOGLResourcesv>
 *
 * ══ §265/1245 Graphics::GetMaxTextureSize()  0x181374  size 20  5 条（0x181374..0x181388）
 * @func 0x181374 0x181388  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x181374 ldr r3, [pc, #0x8]
 *   @0x181378 ldr r3, [pc, r3]
 *   @0x18137c ldr r0, [r3]
 *   @0x181380 bx lr
 *   @0x181384 mlaeq r6, r8, r0, pc
 *
 * ══ §266/1245 Graphics::GetMaxDynamicVertexSpace()  0x185624  size 20  5 条（0x185624..0x185638）
 * @func 0x185624 0x185640  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::GetMaxDynamicVertexCount()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x185624 push {r3, lr}
 *   @0x185628 bl 0x18561c <_ZN8Graphics24GetMaxDynamicVertexCountEv>
 *   @0x18562c add r0, r0, r0, lsl #3
 *   @0x185630 lsl r0, r0, #2
 *   @0x185634 pop {r3, pc}
 *
 * ══ §267/1245 IO_Char_Last_Get()  0x18bd0c  size 20  5 条（0x18bd0c..0x18bd20）
 * @func 0x18bd0c 0x18bd30  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18bd0c ldr r3, [pc, #0x8]
 *   @0x18bd10 ldr r3, [pc, r3]
 *   @0x18bd14 ldrh r0, [r3]
 *   @0x18bd18 bx lr
 *   @0x18bd1c eoreq r4, r6, r0, asr #17
 *
 * ══ §268/1245 IO_Char_Last_Set(char)  0x18bd20  size 20  5 条（0x18bd20..0x18bd34）
 * @func 0x18bd20 0x18bd34  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18bd20 ldr r3, [pc, #0x8]
 *   @0x18bd24 ldr r3, [pc, r3]
 *   @0x18bd28 strh r0, [r3]
 *   @0x18bd2c bx lr
 *   @0x18bd30 eoreq r4, r6, r12, lsr #17
 *
 * ══ §269/1245 IO_Key_Last_Get()  0x18be94  size 20  5 条（0x18be94..0x18bea8）
 * @func 0x18be94 0x18beb8  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18be94 ldr r3, [pc, #0x8]
 *   @0x18be98 ldr r3, [pc, r3]
 *   @0x18be9c ldr r0, [r3]
 *   @0x18bea0 bx lr
 *   @0x18bea4 eoreq r4, r6, r0, asr #14
 *
 * ══ §270/1245 IO_Key_Current_Get()  0x18bea8  size 20  5 条（0x18bea8..0x18bebc）
 * @func 0x18bea8 0x18becc  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18bea8 ldr r3, [pc, #0x8]
 *   @0x18beac ldr r3, [pc, r3]
 *   @0x18beb0 ldr r0, [r3]
 *   @0x18beb4 bx lr
 *   @0x18beb8 eoreq r4, r6, r0, lsr r7
 *
 * ══ §271/1245 IO_Key_Last_Set(int)  0x18bebc  size 20  5 条（0x18bebc..0x18bed0）
 * @func 0x18bebc 0x18bee0  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18bebc ldr r3, [pc, #0x8]
 *   @0x18bec0 ldr r3, [pc, r3]
 *   @0x18bec4 str r0, [r3]
 *   @0x18bec8 bx lr
 *   @0x18becc eoreq r4, r6, r8, lsl r7
 *
 * ══ §272/1245 CBucket<16u, 1048576u, false>::Init()  0x190c40  size 20  5 条（0x190c40..0x190c54）
 * @func 0x190c40 0x190c54  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x190c40 mov r3, #0
 *   @0x190c44 str r3, [r0, #0x4]
 *   @0x190c48 str r3, [r0, #0x8]
 *   @0x190c4c str r3, [r0, #0xc]
 *   @0x190c50 bx lr
 *
 * ══ §273/1245 _RefFactory<void*>::Create(void*, int&)  0x199f34  size 20  5 条（0x199f34..0x199f48）
 * @func 0x199f34 0x199f50  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x199f34 cmp r0, #0
 *   @0x199f38 movne r3, #4
 *   @0x199f3c moveq r3, #0
 *   @0x199f40 str r3, [r1]
 *   @0x199f44 bx lr
 *
 * ══ §274/1245 CPath::SetKind(int)  0x1a6e64  size 20  5 条（0x1a6e64..0x1a6e78）
 * @func 0x1a6e64 0x1a6e80  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a6e64 cmp r1, #1
 *   @0x1a6e68 strls r1, [r0, #0x14]
 *   @0x1a6e6c movhi r3, #0
 *   @0x1a6e70 strhi r3, [r0, #0x14]
 *   @0x1a6e74 b 0x1a6e30 <_ZN5CPath15ComputeInternalEv>
 *
 * ══ §275/1245 CPath::~CPath()  0x1a6fe8  size 20  5 条（0x1a6fe8..0x1a6ffc）
 * @func 0x1a6fe8 0x1a6ffc  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::Clear()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a6fe8 push {r4, lr}
 *   @0x1a6fec mov r4, r0
 *   @0x1a6ff0 bl 0x1a6f98 <_ZN5CPath5ClearEv>
 *   @0x1a6ff4 mov r0, r4
 *   @0x1a6ff8 pop {r4, pc}
 *
 * ══ §276/1245 Path_Number()  0x1a7ff4  size 20  5 条（0x1a7ff4..0x1a8008）
 * @func 0x1a7ff4 0x1a8008  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a7ff4 ldr r3, [pc, #0x8]
 *   @0x1a7ff8 ldr r3, [pc, r3]
 *   @0x1a7ffc ldr r0, [r3]
 *   @0x1a8000 bx lr
 *   @0x1a8004 .word 0x002487d4
 *
 * ══ §277/1245 TBitmap::SetPixelFormat(TPixelFormat)  0x1a8cd8  size 20  5 条（0x1a8cd8..0x1a8cec）
 * @func 0x1a8cd8 0x1a8cfc  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×2 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8cd8 ldr r2, [r0, #0x28]
 *   @0x1a8cdc str r1, [r0, #0x14]
 *   @0x1a8ce0 add r2, r2, #1
 *   @0x1a8ce4 str r2, [r0, #0x28]
 *   @0x1a8ce8 b 0x1a8c3c <_ZN7TBitmap6CreateEv>
 *
 * ══ §278/1245 TBitmap::SetHeight(int)  0x1a8cec  size 20  5 条（0x1a8cec..0x1a8d00）
 * @func 0x1a8cec 0x1a8d10  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×2 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8cec ldr r2, [r0, #0x28]
 *   @0x1a8cf0 str r1, [r0, #0x1c]
 *   @0x1a8cf4 add r2, r2, #1
 *   @0x1a8cf8 str r2, [r0, #0x28]
 *   @0x1a8cfc b 0x1a8c3c <_ZN7TBitmap6CreateEv>
 *
 * ══ §279/1245 TBitmap::SetWidth(int)  0x1a8d00  size 20  5 条（0x1a8d00..0x1a8d14）
 * @func 0x1a8d00 0x1a8d14  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×2 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8d00 ldr r2, [r0, #0x28]
 *   @0x1a8d04 str r1, [r0, #0x18]
 *   @0x1a8d08 add r2, r2, #1
 *   @0x1a8d0c str r2, [r0, #0x28]
 *   @0x1a8d10 b 0x1a8c3c <_ZN7TBitmap6CreateEv>
 *
 * ══ §280/1245 Room_Get_maxid()  0x1b5e04  size 20  5 条（0x1b5e04..0x1b5e18）
 * @func 0x1b5e04 0x1b5e28  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b5e04 ldr r3, [pc, #0x8]
 *   @0x1b5e08 ldr r3, [pc, r3]
 *   @0x1b5e0c ldr r0, [r3]
 *   @0x1b5e10 bx lr
 *   @0x1b5e14 eoreq r10, r3, r4, lsl #20
 *
 * ══ §281/1245 Room_Set_maxid(int)  0x1b5e18  size 20  5 条（0x1b5e18..0x1b5e2c）
 * @func 0x1b5e18 0x1b5e3c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b5e18 ldr r3, [pc, #0x8]
 *   @0x1b5e1c ldr r3, [pc, r3]
 *   @0x1b5e20 str r0, [r3]
 *   @0x1b5e24 bx lr
 *   @0x1b5e28 .word 0x0023a9f0
 *
 * ══ §282/1245 Room_Get_maxtileid()  0x1b5e2c  size 20  5 条（0x1b5e2c..0x1b5e40）
 * @func 0x1b5e2c 0x1b5e50  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b5e2c ldr r3, [pc, #0x8]
 *   @0x1b5e30 ldr r3, [pc, r3]
 *   @0x1b5e34 ldr r0, [r3]
 *   @0x1b5e38 bx lr
 *   @0x1b5e3c eoreq r10, r3, r0, ror #19
 *
 * ══ §283/1245 Room_Set_maxtileid(int)  0x1b5e40  size 20  5 条（0x1b5e40..0x1b5e54）
 * @func 0x1b5e40 0x1b5e54  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b5e40 ldr r3, [pc, #0x8]
 *   @0x1b5e44 ldr r3, [pc, r3]
 *   @0x1b5e48 str r0, [r3]
 *   @0x1b5e4c bx lr
 *   @0x1b5e50 eoreq r10, r3, r12, asr #19
 *
 * ══ §284/1245 CLayerManager::SetLayerIndexWatermark(int)  0x1b79f0  size 20  5 条（0x1b79f0..0x1b7a04）
 * @func 0x1b79f0 0x1b7a04  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b79f0 ldr r3, [pc, #0x8]
 *   @0x1b79f4 ldr r3, [pc, r3]
 *   @0x1b79f8 str r0, [r3]
 *   @0x1b79fc bx lr
 *   @0x1b7a00 eoreq r8, r3, r12, lsl #29
 *
 * ══ §285/1245 CSingleFingerGesture::IsUsingTouch(int)  0x1d4fe0  size 20  5 条（0x1d4fe0..0x1d4ff4）
 * @func 0x1d4fe0 0x1d5004  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d4fe0 ldr r0, [r0, #0x28]
 *   @0x1d4fe4 subs r3, r0, r1
 *   @0x1d4fe8 rsbs r0, r3, #0
 *   @0x1d4fec adcs r0, r0, r3
 *   @0x1d4ff0 bx lr
 *
 * ══ §286/1245 Splash_Is_Shown_In_Main()  0x1dc78c  size 20  5 条（0x1dc78c..0x1dc7a0）
 * @func 0x1dc78c 0x1dc7a4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc78c ldr r3, [pc, #0x8]
 *   @0x1dc790 ldr r3, [pc, r3]
 *   @0x1dc794 ldrb r0, [r3]
 *   @0x1dc798 bx lr
 *   @0x1dc79c eoreq r4, r1, r12, lsl #10
 *
 * ══ §287/1245 YYPATCH(void*, void*)  0x1ddc6c  size 20  5 条（0x1ddc6c..0x1ddc80）
 * @func 0x1ddc6c 0x1ddc80  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ddc6c ldr r3, [r0]
 *   @0x1ddc70 cmp r3, #0
 *   @0x1ddc74 addne r3, r1, r3
 *   @0x1ddc78 str r3, [r0]
 *   @0x1ddc7c bx lr
 *
 * ══ §288/1245 VertexFormat::GetElementSizeInType(yyVertexType)  0x1e242c  size 20  5 条（0x1e242c..0x1e2440）
 * @func 0x1e242c 0x1e2440  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e242c sub r0, r0, #1
 *   @0x1e2430 cmp r0, #5
 *   @0x1e2434 movls r0, #4
 *   @0x1e2438 movhi r0, #0
 *   @0x1e243c bx lr
 *
 * ══ §289/1245 VertexFormatExists(int)  0x1e2d54  size 20  5 条（0x1e2d54..0x1e2d68）
 * @func 0x1e2d54 0x1e2d68  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GetVertexFormat(int)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e2d54 push {r3, lr}
 *   @0x1e2d58 bl 0x1e2cd0 <_Z15GetVertexFormati>
 *   @0x1e2d5c adds r0, r0, #0
 *   @0x1e2d60 movne r0, #1
 *   @0x1e2d64 pop {r3, pc}
 *
 * ══ §290/1245 VertexFormat_Set(VertexFormat*)  0x1e2fd4  size 20  5 条（0x1e2fd4..0x1e2fe8）
 * @func 0x1e2fd4 0x1e2fe8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e2fd4 ldr r3, [pc, #0x8]
 *   @0x1e2fd8 ldr r3, [pc, r3]
 *   @0x1e2fdc str r0, [r3]
 *   @0x1e2fe0 bx lr
 *   @0x1e2fe4 eoreq sp, r0, r8, asr #27
 *
 * ══ §291/1245 CStream::~CStream()  0x201328  size 20  5 条（0x201328..0x20133c）
 * @func 0x201328 0x20133c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::Clear()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201328 push {r4, lr}
 *   @0x20132c mov r4, r0
 *   @0x201330 bl 0x2012f0 <_ZN7CStream5ClearEv>
 *   @0x201334 mov r0, r4
 *   @0x201338 pop {r4, pc}
 *
 * ══ §292/1245 CStream::ReadBoolean()  0x2019b0  size 20  5 条（0x2019b0..0x2019c4）
 * @func 0x2019b0 0x2019c4  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadInteger()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2019b0 push {r3, lr}
 *   @0x2019b4 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x2019b8 adds r0, r0, #0
 *   @0x2019bc movne r0, #1
 *   @0x2019c0 pop {r3, pc}
 *
 * ══ §293/1245 Hex2Int(char)  0x20256c  size 20  5 条（0x20256c..0x202580）
 * @func 0x20256c 0x202580  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20256c ubfx r3, r0, #0x6, #0x1
 *   @0x202570 and r0, r0, #15
 *   @0x202574 add r0, r0, r3, lsl #3
 *   @0x202578 add r0, r0, r3
 *   @0x20257c bx lr
 *
 * ══ §294/1245 CDS_Map::Empty()  0x203a58  size 20  5 条（0x203a58..0x203a6c）
 * @func 0x203a58 0x203a7c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x203a58 ldr r3, [r0]
 *   @0x203a5c ldr r0, [r3, #0x8]
 *   @0x203a60 rsbs r0, r0, #1
 *   @0x203a64 movlo r0, #0
 *   @0x203a68 bx lr
 *
 * ══ §295/1245 CDS_Map::Exists(RValue*)  0x203a6c  size 20  5 条（0x203a6c..0x203a80）
 * @func 0x203a6c 0x203a80  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CDS_Map::Find(RValue*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x203a6c push {r3, lr}
 *   @0x203a70 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue>
 *   @0x203a74 adds r0, r0, #0
 *   @0x203a78 movne r0, #1
 *   @0x203a7c pop {r3, pc}
 *
 * ══ §296/1245 File_TempDir()  0x214dfc  size 20  5 条（0x214dfc..0x214e10）
 * @func 0x214dfc 0x214e1c  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214dfc ldr r3, [pc, #0x8]
 *   @0x214e00 ldr r3, [pc, r3]
 *   @0x214e04 ldr r0, [r3]
 *   @0x214e08 b 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x214e0c andseq r12, sp, r0, asr #11
 *
 * ══ §297/1245 CSound::~CSound()  0x215384  size 20  5 条（0x215384..0x215398）
 * @func 0x215384 0x215398  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSound::Clear()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215384 push {r4, lr}
 *   @0x215388 mov r4, r0
 *   @0x21538c bl 0x21529c <_ZN6CSound5ClearEv>
 *   @0x215390 mov r0, r4
 *   @0x215394 pop {r4, pc}
 *
 * ══ §298/1245 CListener::~CListener()  0x215b20  size 20  5 条（0x215b20..0x215b34）
 * @func 0x215b20 0x215b44  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CListener::Clear()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215b20 push {r4, lr}
 *   @0x215b24 mov r4, r0
 *   @0x215b28 bl 0x215b1c <_ZN9CListener5ClearEv>
 *   @0x215b2c mov r0, r4
 *   @0x215b30 pop {r4, pc}
 *
 * ══ §299/1245 Audio_Model()  0x216998  size 20  5 条（0x216998..0x2169ac）
 * @func 0x216998 0x2169ac  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x216998 ldr r3, [pc, #0x8]
 *   @0x21699c ldr r3, [pc, r3]
 *   @0x2169a0 ldrb r0, [r3]
 *   @0x2169a4 bx lr
 *   @0x2169a8 mulseq sp, r4, r3
 *
 * ══ §300/1245 Audio_Number()  0x2172f8  size 20  5 条（0x2172f8..0x21730c）
 * @func 0x2172f8 0x21731c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2172f8 ldr r3, [pc, #0x8]
 *   @0x2172fc add r3, pc, r3
 *   @0x217300 ldr r0, [r3, #0x48]
 *   @0x217304 bx lr
 *   @0x217308 .word 0x0053df98
 *
 * ══ §301/1245 Audio_GetListenerMask()  0x21857c  size 20  5 条（0x21857c..0x218590）
 * @func 0x21857c 0x2185a0  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21857c ldr r3, [pc, #0x8]
 *   @0x218580 ldr r3, [pc, r3]
 *   @0x218584 ldr r0, [r3]
 *   @0x218588 bx lr
 *   @0x21858c andseq r8, sp, r8, asr #28
 *
 * ══ §302/1245 Audio_SetListenerMask(unsigned int)  0x218590  size 20  5 条（0x218590..0x2185a4）
 * @func 0x218590 0x2185a4  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x218590 ldr r3, [pc, #0x8]
 *   @0x218594 ldr r3, [pc, r3]
 *   @0x218598 str r0, [r3]
 *   @0x21859c bx lr
 *   @0x2185a0 andseq r8, sp, r4, lsr lr
 *
 * ══ §303/1245 Audio_DestroySyncGroup(int)  0x21d3f8  size 20  5 条（0x21d3f8..0x21d40c）
 * @func 0x21d3f8 0x21d41c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21d3f8 mov r1, r0
 *   @0x21d3fc ldr r0, [pc, #0x4]
 *   @0x21d400 add r0, pc, r0
 *   @0x21d404 b 0x225f2c <_ZN9COggAudio17Delete_SyncThreadEi>
 *   @0x21d408 .word 0x00537e94
 *
 * ══ §304/1245 Audio_StartSyncGroup(int)  0x21d40c  size 20  5 条（0x21d40c..0x21d420）
 * @func 0x21d40c 0x21d430  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21d40c mov r1, r0
 *   @0x21d410 ldr r0, [pc, #0x4]
 *   @0x21d414 add r0, pc, r0
 *   @0x21d418 b 0x2261d4 <_ZN9COggAudio14StartSyncGroupEi>
 *   @0x21d41c subseq r7, r3, r0, lsl #29
 *
 * ══ §305/1245 Audio_StopSyncGroup(int)  0x21d420  size 20  5 条（0x21d420..0x21d434）
 * @func 0x21d420 0x21d434  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21d420 mov r1, r0
 *   @0x21d424 ldr r0, [pc, #0x4]
 *   @0x21d428 add r0, pc, r0
 *   @0x21d42c b 0x2261f4 <_ZN9COggAudio13StopSyncGroupEi>
 *   @0x21d430 subseq r7, r3, r12, ror #28
 *
 * ══ §306/1245 Audio_PauseSyncGroup(int)  0x21d604  size 20  5 条（0x21d604..0x21d618）
 * @func 0x21d604 0x21d628  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21d604 mov r1, r0
 *   @0x21d608 ldr r0, [pc, #0x4]
 *   @0x21d60c add r0, pc, r0
 *   @0x21d610 b 0x226214 <_ZN9COggAudio14PauseSyncGroupEi>
 *   @0x21d614 subseq r7, r3, r8, lsl #25
 *
 * ══ §307/1245 Audio_ResumeSyncGroup(int)  0x21d618  size 20  5 条（0x21d618..0x21d62c）
 * @func 0x21d618 0x21d63c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21d618 mov r1, r0
 *   @0x21d61c ldr r0, [pc, #0x4]
 *   @0x21d620 add r0, pc, r0
 *   @0x21d624 b 0x226234 <_ZN9COggAudio15ResumeSyncGroupEi>
 *   @0x21d628 subseq r7, r3, r4, ror r12
 *
 * ══ §308/1245 Audio_SyncGroupGetTrackPos(int)  0x21d62c  size 20  5 条（0x21d62c..0x21d640）
 * @func 0x21d62c 0x21d640  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21d62c mov r1, r0
 *   @0x21d630 ldr r0, [pc, #0x4]
 *   @0x21d634 add r0, pc, r0
 *   @0x21d638 b 0x226934 <_ZN9COggAudio20GetSyncGroupTrackPosEi>
 *   @0x21d63c subseq r7, r3, r0, ror #24
 *
 * ══ §309/1245 CNoise::~CNoise()  0x21db28  size 20  5 条（0x21db28..0x21db3c）
 * @func 0x21db28 0x21db4c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CNoise::Clear()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21db28 push {r4, lr}
 *   @0x21db2c mov r4, r0
 *   @0x21db30 bl 0x21db24 <_ZN6CNoise5ClearEv>
 *   @0x21db34 mov r0, r4
 *   @0x21db38 pop {r4, pc}
 *
 * ══ §310/1245 anon_21db3c  0x21db3c  size 20  5 条（0x21db3c..0x21db50）
 * @func 0x21db3c 0x21db50  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_PrepareGroup(int)
 * 字段偏移 top8: 0xc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21db3c push {r3, lr}
 *   @0x21db40 ldr r3, [r0, #0xc]
 *   @0x21db44 ldr r0, [r3, #0x4]
 *   @0x21db48 bl 0x219590 <_Z18Audio_PrepareGroupi>
 *   @0x21db4c mov r0, #0
 *
 * ══ §311/1245 ogg_zip_tell(void*)  0x2235e0  size 20  5 条（0x2235e0..0x2235f4）
 * @func 0x2235e0 0x2235f4  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2c8×1 / 0x2cc×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2235e0 ldr r2, [r0, #0x2c8]
 *   @0x2235e4 ldr r3, [r0, #0x2cc]
 *   @0x2235e8 ldr r0, [r2, #0x18]
 *   @0x2235ec rsb r0, r3, r0
 *   @0x2235f0 bx lr
 *
 * ══ §312/1245 vorbis_info_blocksize  0x22acd4  size 20  5 条（0x22acd4..0x22ace8）
 * @func 0x22acd4 0x22ace8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22acd4 ldr r3, [r0, #0x1c]
 *   @0x22acd8 cmp r3, #0
 *   @0x22acdc ldrne r0, [r3, r1, lsl #2]
 *   @0x22ace0 mvneq r0, #0
 *   @0x22ace4 bx lr
 *
 * ══ §313/1245 CBucket<8u, 131072u, true>::Init()  0x27b650  size 20  5 条（0x27b650..0x27b664）
 * @func 0x27b650 0x27b674  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b650 mov r3, #0
 *   @0x27b654 str r3, [r0, #0x4]
 *   @0x27b658 str r3, [r0, #0x8]
 *   @0x27b65c str r3, [r0, #0xc]
 *   @0x27b660 bx lr
 *
 * ══ §314/1245 CBucket<16u, 262144u, true>::Init()  0x27b664  size 20  5 条（0x27b664..0x27b678）
 * @func 0x27b664 0x27b688  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b664 mov r3, #0
 *   @0x27b668 str r3, [r0, #0x4]
 *   @0x27b66c str r3, [r0, #0x8]
 *   @0x27b670 str r3, [r0, #0xc]
 *   @0x27b674 bx lr
 *
 * ══ §315/1245 CBucket<32u, 262144u, true>::Init()  0x27b678  size 20  5 条（0x27b678..0x27b68c）
 * @func 0x27b678 0x27b69c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b678 mov r3, #0
 *   @0x27b67c str r3, [r0, #0x4]
 *   @0x27b680 str r3, [r0, #0x8]
 *   @0x27b684 str r3, [r0, #0xc]
 *   @0x27b688 bx lr
 *
 * ══ §316/1245 CBucket<64u, 524288u, true>::Init()  0x27b68c  size 20  5 条（0x27b68c..0x27b6a0）
 * @func 0x27b68c 0x27b6b0  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b68c mov r3, #0
 *   @0x27b690 str r3, [r0, #0x4]
 *   @0x27b694 str r3, [r0, #0x8]
 *   @0x27b698 str r3, [r0, #0xc]
 *   @0x27b69c bx lr
 *
 * ══ §317/1245 CBucket<128u, 524288u, true>::Init()  0x27b6a0  size 20  5 条（0x27b6a0..0x27b6b4）
 * @func 0x27b6a0 0x27b6c4  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b6a0 mov r3, #0
 *   @0x27b6a4 str r3, [r0, #0x4]
 *   @0x27b6a8 str r3, [r0, #0x8]
 *   @0x27b6ac str r3, [r0, #0xc]
 *   @0x27b6b0 bx lr
 *
 * ══ §318/1245 CBucket<256u, 1048576u, true>::Init()  0x27b6b4  size 20  5 条（0x27b6b4..0x27b6c8）
 * @func 0x27b6b4 0x27b6d8  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b6b4 mov r3, #0
 *   @0x27b6b8 str r3, [r0, #0x4]
 *   @0x27b6bc str r3, [r0, #0x8]
 *   @0x27b6c0 str r3, [r0, #0xc]
 *   @0x27b6c4 bx lr
 *
 * ══ §319/1245 CBucket<16384u, 262144u, true>::Init()  0x27b6c8  size 20  5 条（0x27b6c8..0x27b6dc）
 * @func 0x27b6c8 0x27b6dc  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x8×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b6c8 mov r3, #0
 *   @0x27b6cc str r3, [r0, #0x4]
 *   @0x27b6d0 str r3, [r0, #0x8]
 *   @0x27b6d4 str r3, [r0, #0xc]
 *   @0x27b6d8 bx lr
 *
 * ══ §320/1245 mc_set_debug  0x27e2e8  size 20  5 条（0x27e2e8..0x27e2fc）
 * @func 0x27e2e8 0x27e30c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e2e8 ldr r3, [pc, #0x8]
 *   @0x27e2ec add r3, pc, r3
 *   @0x27e2f0 str r0, [r3]
 *   @0x27e2f4 bx lr
 *   @0x27e2f8 subeq r8, sp, r4, asr #17
 *
 * ══ §321/1245 mc_set_syslog  0x27e30c  size 20  5 条（0x27e30c..0x27e320）
 * @func 0x27e30c 0x27e320  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e30c ldr r3, [pc, #0x8]
 *   @0x27e310 add r3, pc, r3
 *   @0x27e314 str r0, [r3, #0x4]
 *   @0x27e318 bx lr
 *   @0x27e31c subeq r8, sp, r0, lsr #17
 *
 * ══ §322/1245 json_object_is_type  0x27e814  size 20  5 条（0x27e814..0x27e828）
 * @func 0x27e814 0x27e828  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e814 ldr r0, [r0]
 *   @0x27e818 subs r3, r0, r1
 *   @0x27e81c rsbs r0, r3, #0
 *   @0x27e820 adcs r0, r0, r3
 *   @0x27e824 bx lr
 *
 * ══ §323/1245 lh_ptr_hash  0x280798  size 20  5 条（0x280798..0x2807ac）
 * @func 0x280798 0x2807bc  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x280798 mov r3, #1
 *   @0x28079c movt r3, #0x9e37
 *   @0x2807a0 mul r0, r3, r0
 *   @0x2807a4 lsr r0, r0, #4
 *   @0x2807a8 bx lr
 *
 * ══ §324/1245 lh_char_equal  0x2807fc  size 20  5 条（0x2807fc..0x280810）
 * @func 0x2807fc 0x280810  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6574
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2807fc push {r3, lr}
 *   @0x280800 bl 0xb6574 <strcmp@plt>
 *   @0x280804 rsbs r0, r0, #1
 *   @0x280808 movlo r0, #0
 *   @0x28080c pop {r3, pc}
 *
 * ══ §325/1245 lh_table_lookup  0x280bac  size 20  5 条（0x280bac..0x280bc0）
 * @func 0x280bac 0x280bc0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: lh_table_lookup_entry
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x280bac push {r3, lr}
 *   @0x280bb0 bl 0x280b1c <lh_table_lookup_entry>
 *   @0x280bb4 cmp r0, #0
 *   @0x280bb8 ldrne r0, [r0, #0x4]
 *   @0x280bbc pop {r3, pc}
 *
 * ══ §326/1245 spTimeline_dispose  0x281468  size 20  5 条（0x281468..0x28147c）
 * @func 0x281468 0x28147c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x281468 push {r3, lr}
 *   @0x28146c ldr r3, [r0, #0x4]
 *   @0x281470 ldr r3, [r3, #0x4]
 *   @0x281474 blx r3
 *   @0x281478 pop {r3, pc}
 *
 * ══ §327/1245 spRotateTimeline_setFrame  0x282aa8  size 20  5 条（0x282aa8..0x282abc）
 * @func 0x282aa8 0x282acc  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282aa8 ldr r0, [r0, #0x10]
 *   @0x282aac add r1, r0, r1, lsl #3
 *   @0x282ab0 str r2, [r1]
 *   @0x282ab4 str r3, [r1, #0x4]
 *   @0x282ab8 bx lr
 *
 * ══ §328/1245 spPathConstraintPositionTimeline_setFrame  0x283028  size 20  5 条（0x283028..0x28303c）
 * @func 0x283028 0x28304c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x283028 ldr r0, [r0, #0x10]
 *   @0x28302c add r12, r0, r1, lsl #3
 *   @0x283030 str r2, [r12]
 *   @0x283034 str r3, [r12, #0x4]
 *   @0x283038 bx lr
 *
 * ══ §329/1245 spPathConstraintSpacingTimeline_setFrame  0x283054  size 20  5 条（0x283054..0x283068）
 * @func 0x283054 0x283078  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x283054 ldr r0, [r0, #0x10]
 *   @0x283058 add r12, r0, r1, lsl #3
 *   @0x28305c str r2, [r12]
 *   @0x283060 str r3, [r12, #0x4]
 *   @0x283064 bx lr
 *
 * ══ §330/1245 _setDebugMalloc  0x285c9c  size 20  5 条（0x285c9c..0x285cb0）
 * @func 0x285c9c 0x285cc0  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285c9c ldr r3, [pc, #0x8]
 *   @0x285ca0 add r3, pc, r3
 *   @0x285ca4 str r0, [r3]
 *   @0x285ca8 bx lr
 *   @0x285cac subeq r0, sp, r12, lsl pc
 *
 * ══ §331/1245 _setMalloc  0x285cb0  size 20  5 条（0x285cb0..0x285cc4）
 * @func 0x285cb0 0x285cd4  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285cb0 ldr r3, [pc, #0x8]
 *   @0x285cb4 add r3, pc, r3
 *   @0x285cb8 str r0, [r3]
 *   @0x285cbc bx lr
 *   @0x285cc0 ldrsbeq r1, [r7], -r4
 *
 * ══ §332/1245 _setFree  0x285cc4  size 20  5 条（0x285cc4..0x285cd8）
 * @func 0x285cc4 0x285cd8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285cc4 ldr r3, [pc, #0x8]
 *   @0x285cc8 add r3, pc, r3
 *   @0x285ccc str r0, [r3, #0x4]
 *   @0x285cd0 bx lr
 *   @0x285cd4 andseq r1, r7, r0, asr #21
 *
 * ══ §333/1245 spSkeleton_update  0x28a558  size 20  5 条（0x28a558..0x28a56c）
 * @func 0x28a558 0x28a56c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28a558 vmov s14, r1
 *   @0x28a55c vldr s15, [r0, #76]
 *   @0x28a560 vadd.f32 s15, s15, s14
 *   @0x28a564 vstr s15, [r0, #76]
 *   @0x28a568 bx lr
 *
 * ══ §334/1245 GetExeName  0x28fe50  size 20  5 条（0x28fe50..0x28fe64）
 * @func 0x28fe50 0x28fe64  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28fe50 ldr r3, [pc, #0x8]
 *   @0x28fe54 ldr r3, [pc, r3]
 *   @0x28fe58 ldr r0, [r3]
 *   @0x28fe5c bx lr
 *   @0x28fe60 andseq r1, r6, r8, asr #21
 *
 * ══ §335/1245 Java_com_yoyogames_runner_RunnerJNILib_canFlip  0x294c38  size 20  5 条（0x294c38..0x294c4c）
 * @func 0x294c38 0x294c4c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x294c38 ldr r3, [pc, #0x8]
 *   @0x294c3c ldr r3, [pc, r3]
 *   @0x294c40 ldrb r0, [r3]
 *   @0x294c44 bx lr
 *   @0x294c48 andseq r11, r5, r8, lsl r8
 *
 * ══ §336/1245 yySocket::yySocket(eSocketType)  0x2970ac  size 20  5 条（0x2970ac..0x2970c0）
 * @func 0x2970ac 0x2970c0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yySocket::InitSocket(eSocketType)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2970ac push {r4, lr}
 *   @0x2970b0 mov r4, r0
 *   @0x2970b4 bl 0x297008 <_ZN8yySocket10InitSocketE11eSocketType>
 *   @0x2970b8 mov r0, r4
 *   @0x2970bc pop {r4, pc}
 *
 * ══ §337/1245 yyServer::SetSocketID(int)  0x297558  size 20  5 条（0x297558..0x29756c）
 * @func 0x297558 0x29756c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x297558 ldr r3, [r0]
 *   @0x29755c str r1, [r0, #0x18]
 *   @0x297560 cmp r3, #0
 *   @0x297564 strne r1, [r3, #0x68]
 *   @0x297568 bx lr
 *
 * ══ §338/1245 Debug_WriteProfileData(Buffer_Standard*)  0x29c148  size 20  5 条（0x29c148..0x29c15c）
 * @func 0x29c148 0x29c15c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29c148 ldr r3, [pc, #0x8]
 *   @0x29c14c mov r1, r0
 *   @0x29c150 ldr r0, [pc, r3]
 *   @0x29c154 b 0x2a0ae0 <_ZN9CProfiler16WriteProfileDataEP15Buffer_Standard>
 *   @0x29c158 andseq r1, r5, r12, lsl r10
 *
 * ══ §339/1245 SetLaunchedFromPlayer(char const*, bool)  0x2a2c28  size 20  5 条（0x2a2c28..0x2a2c3c）
 * @func 0x2a2c28 0x2a2c3c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a2c28 ldr r3, [pc, #0x8]
 *   @0x2a2c2c ldr r3, [pc, r3]
 *   @0x2a2c30 strb r1, [r3]
 *   @0x2a2c34 b 0x15f61c <_Z28SetAndroidLaunchedFromPlayerPKcb>
 *   @0x2a2c38 andseq r11, r4, r4
 *
 * ══ §340/1245 png_reset_crc  0x2a5af4  size 20  5 条（0x2a5af4..0x2a5b08）
 * @func 0x2a5af4 0x2a5b08  size 20  5 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5af4 push {r4, lr}
 *   @0x2a5af8 movs r0, #0x0
 *   @0x2a5afc mov r2, r0
 *   @0x2a5b00 .word 0xf8c4e9d2
 *   @0x2a5b04 ldclt p1, c0, [r0, #-848]
 *
 * ══ §341/1245 png_set_read_user_transform_fn  0x2a89a8  size 20  5 条（0x2a89a8..0x2a89bc）
 * @func 0x2a89a8 0x2a89bc  size 20  5 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a89a8 cbz r0, 0x2a89ba <png_set_read_user_transform_fn+0x12>
 *   @0x2a89ac .word 0xf8c03134
 *   @0x2a89b0 vst4.8 {d17, d19, d21, d23}, [r3:64], r12
 *   @0x2a89b4 .word 0xf8c01380
 *   @0x2a89b8 .word 0x47703134
 *
 * ══ §342/1245 png_set_compression_level  0x2b0886  size 20  5 条（0x2b0886..0x2b089a）
 * @func 0x2b0886 0x2b08aa  size 36  9 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b0886 cbz r0, 0x2b0898 <png_set_compression_level+0x12>
 *   @0x2b088a .word 0xf8c03130
 *   @0x2b088e .word 0xf0431178
 *   @0x2b0892 .word 0xf8c00302
 *   @0x2b0896 .word 0x47703130
 *
 * ══ §343/1245 png_set_compression_mem_level  0x2b089a  size 20  5 条（0x2b089a..0x2b08ae）
 * @func 0x2b089a 0x2b08be  size 36  9 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b089a cbz r0, 0x2b08ac <png_set_compression_mem_level+0x12>
 *   @0x2b089e .word 0xf8c03130
 *   @0x2b08a2 .word 0xf0431184
 *   @0x2b08a6 .word 0xf8c00304
 *   @0x2b08aa .word 0x47703130
 *
 * ══ §344/1245 png_set_compression_strategy  0x2b08ae  size 20  5 条（0x2b08ae..0x2b08c2）
 * @func 0x2b08ae 0x2b08c2  size 20  5 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b08ae cbz r0, 0x2b08c0 <png_set_compression_strategy+0x12>
 *   @0x2b08b2 .word 0xf8c03130
 *   @0x2b08b6 .word 0xf0431188
 *   @0x2b08ba .word 0xf8c00301
 *   @0x2b08be .word 0x47703130
 *
 * ══ §345/1245 png_set_write_user_transform_fn  0x2b0944  size 20  5 条（0x2b0944..0x2b0958）
 * @func 0x2b0944 0x2b0958  size 20  5 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b0944 cbz r0, 0x2b0956 <png_set_write_user_transform_fn+0x12>
 *   @0x2b0948 .word 0xf8c03134
 *   @0x2b094c vst4.8 {d17, d19, d21, d23}, [r3:128], r0
 *   @0x2b0950 .word 0xf8c01380
 *   @0x2b0954 .word 0x47703134
 *
 * ══ §346/1245 jdiv_round_up  0x2bc7ec  size 20  5 条（0x2bc7ec..0x2bc800）
 * @func 0x2bc7ec 0x2bc800  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2bc7ec add r0, r0, r1
 *   @0x2bc7f0 push {r3, lr}
 *   @0x2bc7f4 sub r0, r0, #1
 *   @0x2bc7f8 bl 0x318d10 <__divsi3>
 *   @0x2bc7fc pop {r3, pc}
 *
 * ══ §347/1245 jcopy_block_row  0x2bc854  size 20  5 条（0x2bc854..0x2bc868）
 * @func 0x2bc854 0x2bc874  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2bc854 mov r3, r0
 *   @0x2bc858 lsl r2, r2, #7
 *   @0x2bc85c mov r0, r1
 *   @0x2bc860 mov r1, r3
 *   @0x2bc864 b 0xb65bc <memcpy@plt>
 *
 * ══ §348/1245 b2FrictionJoint::GetReactionTorque(float) const  0x2cd3c8  size 20  5 条（0x2cd3c8..0x2cd3dc）
 * @func 0x2cd3c8 0x2cd3ec  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cd3c8 vmov s14, r1
 *   @0x2cd3cc vldr s15, [r0, #92]
 *   @0x2cd3d0 vmul.f32 s14, s14, s15
 *   @0x2cd3d4 vmov r0, s14
 *   @0x2cd3d8 bx lr
 *
 * ══ §349/1245 b2MotorJoint::GetReactionTorque(float) const  0x2ce01c  size 20  5 条（0x2ce01c..0x2ce030）
 * @func 0x2ce01c 0x2ce040  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ce01c vmov s14, r1
 *   @0x2ce020 vldr s15, [r0, #88]
 *   @0x2ce024 vmul.f32 s14, s14, s15
 *   @0x2ce028 vmov r0, s14
 *   @0x2ce02c bx lr
 *
 * ══ §350/1245 b2PrismaticJoint::GetReactionTorque(float) const  0x2cf180  size 20  5 条（0x2cf180..0x2cf194）
 * @func 0x2cf180 0x2cf1a4  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cf180 vmov s14, r1
 *   @0x2cf184 vldr s15, [r0, #108]
 *   @0x2cf188 vmul.f32 s14, s14, s15
 *   @0x2cf18c vmov r0, s14
 *   @0x2cf190 bx lr
 *
 * ══ §351/1245 b2PrismaticJoint::GetMotorForce(float) const  0x2d04fc  size 20  5 条（0x2d04fc..0x2d0510）
 * @func 0x2d04fc 0x2d0510  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d04fc vmov s14, r1
 *   @0x2d0500 vldr s15, [r0, #116]
 *   @0x2d0504 vmul.f32 s14, s14, s15
 *   @0x2d0508 vmov r0, s14
 *   @0x2d050c bx lr
 *
 * ══ §352/1245 b2RevoluteJoint::GetReactionTorque(float) const  0x2d132c  size 20  5 条（0x2d132c..0x2d1340）
 * @func 0x2d132c 0x2d1350  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d132c vmov s14, r1
 *   @0x2d1330 vldr s15, [r0, #92]
 *   @0x2d1334 vmul.f32 s14, s14, s15
 *   @0x2d1338 vmov r0, s14
 *   @0x2d133c bx lr
 *
 * ══ §353/1245 b2RevoluteJoint::GetMotorTorque(float) const  0x2d218c  size 20  5 条（0x2d218c..0x2d21a0）
 * @func 0x2d218c 0x2d21a0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d218c vmov s14, r1
 *   @0x2d2190 vldr s15, [r0, #96]
 *   @0x2d2194 vmul.f32 s14, s14, s15
 *   @0x2d2198 vmov r0, s14
 *   @0x2d219c bx lr
 *
 * ══ §354/1245 b2WeldJoint::GetReactionTorque(float) const  0x2d2e80  size 20  5 条（0x2d2e80..0x2d2e94）
 * @func 0x2d2e80 0x2d2ea4  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2e80 vmov s14, r1
 *   @0x2d2e84 vldr s15, [r0, #112]
 *   @0x2d2e88 vmul.f32 s14, s14, s15
 *   @0x2d2e8c vmov r0, s14
 *   @0x2d2e90 bx lr
 *
 * ══ §355/1245 b2WheelJoint::GetReactionTorque(float) const  0x2d39ec  size 20  5 条（0x2d39ec..0x2d3a00）
 * @func 0x2d39ec 0x2d3a10  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d39ec vmov s14, r1
 *   @0x2d39f0 vldr s15, [r0, #112]
 *   @0x2d39f4 vmul.f32 s14, s14, s15
 *   @0x2d39f8 vmov r0, s14
 *   @0x2d39fc bx lr
 *
 * ══ §356/1245 b2WheelJoint::GetMotorTorque(float) const  0x2d4464  size 20  5 条（0x2d4464..0x2d4478）
 * @func 0x2d4464 0x2d4478  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d4464 vmov s14, r1
 *   @0x2d4468 vldr s15, [r0, #112]
 *   @0x2d446c vmul.f32 s14, s14, s15
 *   @0x2d4470 vmov r0, s14
 *   @0x2d4474 bx lr
 *
 * ══ §357/1245 b2ParticleGroup::GetMass() const  0x2d4814  size 20  5 条（0x2d4814..0x2d4828）
 * @func 0x2d4814 0x2d4838  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleGroup::UpdateStatistics() const
 * 字段偏移 top8: 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d4814 push {r4, lr}
 *   @0x2d4818 mov r4, r0
 *   @0x2d481c bl 0x2d4644 <_ZNK15b2ParticleGroup16UpdateStatisticsEv>
 *   @0x2d4820 ldr r0, [r4, #0x20]
 *   @0x2d4824 pop {r4, pc}
 *
 * ══ §358/1245 b2ParticleGroup::GetInertia() const  0x2d4828  size 20  5 条（0x2d4828..0x2d483c）
 * @func 0x2d4828 0x2d483c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleGroup::UpdateStatistics() const
 * 字段偏移 top8: 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d4828 push {r4, lr}
 *   @0x2d482c mov r4, r0
 *   @0x2d4830 bl 0x2d4644 <_ZNK15b2ParticleGroup16UpdateStatisticsEv>
 *   @0x2d4834 ldr r0, [r4, #0x24]
 *   @0x2d4838 pop {r4, pc}
 *
 * ══ §359/1245 b2ParticleGroup::GetAngularVelocity() const  0x2d488c  size 20  5 条（0x2d488c..0x2d48a0）
 * @func 0x2d488c 0x2d48b0  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleGroup::UpdateStatistics() const
 * 字段偏移 top8: 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d488c push {r4, lr}
 *   @0x2d4890 mov r4, r0
 *   @0x2d4894 bl 0x2d4644 <_ZNK15b2ParticleGroup16UpdateStatisticsEv>
 *   @0x2d4898 ldr r0, [r4, #0x38]
 *   @0x2d489c pop {r4, pc}
 *
 * ══ §360/1245 b2ParticleSystem::GetParticleRadius() const  0x2d82d4  size 20  5 条（0x2d82d4..0x2d82e8）
 * @func 0x2d82d4 0x2d82e8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d82d4 vmov.f32 s15, #5.000000e-01
 *   @0x2d82d8 vldr s14, [r0, #24]
 *   @0x2d82dc vmul.f32 s15, s14, s15
 *   @0x2d82e0 vmov r0, s15
 *   @0x2d82e4 bx lr
 *
 * ══ §361/1245 ft_validator_init  0x2e5378  size 20  5 条（0x2e5378..0x2e538c）
 * @func 0x2e5378 0x2e539a  size 34  9 条
 * 部分覆盖: 本节 9/12 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 8/10 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 7/10 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 6/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5378 str.w r1, [r0, #0x100]
 *   @0x2e537c str.w r2, [r0, #0x104]
 *   @0x2e5380 str.w r3, [r0, #0x108]
 *   @0x2e5384 movs r3, #0x0
 *   @0x2e5388 ldrbmi r3, [r0, -r12, lsl #2]!
 *
 * ══ §362/1245 FT_Reference_Face  0x2e5410  size 20  5 条（0x2e5410..0x2e5424）
 * @func 0x2e5410 0x2e5424  size 20  5 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x40×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5410 cbz r0, 0x2e5420 <FT_Reference_Face+0x10>
 *   @0x2e5414 andhs r3, r0, r0, lsl #1
 *   @0x2e5418 ldr r2, [r3, #0x40]
 *   @0x2e541c str r2, [r3, #0x40]
 *   @0x2e5420 movs r0, #0x23
 *
 * ══ §363/1245 FT_Property_Set  0x2e5f82  size 20  5 条（0x2e5f82..0x2e5f96）
 * @func 0x2e5f82 0x2e5fa6  size 36  9 条
 * 部分覆盖: 本节 9/15 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 8/13 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 6/10 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2e490c+0x374
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5f82 push {r0, r1, r4, lr}
 *   @0x2e5f86 strhs r0, [r1], #-3584
 *   @0x2e5f8a stm.w sp, {r4, lr}
 *   @0x2e5f8e bl 0x2e4c80 <_ZNK11b2GearJoint8GetRatioEv+0x37c>
 *   @0x2e5f92 add sp, #0x8
 *
 * ══ §364/1245 FT_Reference_Library  0x2e5fb6  size 20  5 条（0x2e5fb6..0x2e5fca）
 * @func 0x2e5fb6 0x2e5fca  size 20  5 条
 * 部分覆盖: 本节 5/9 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5fb6 cbz r0, 0x2e5fc6 <FT_Reference_Library+0x10>
 *   @0x2e5fba movwlo r3, #0x10bc
 *   @0x2e5fbe str.w r3, [r0, #0xbc]
 *   @0x2e5fc2 movs r0, #0x0
 *   @0x2e5fc6 movs r0, #0x21
 *
 * ══ §365/1245 FT_Get_Sfnt_Name_Count  0x2e6876  size 20  5 条（0x2e6876..0x2e688a）
 * @func 0x2e6876 0x2e689a  size 36  9 条
 * 部分覆盖: 本节 6/11 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6876 cbz r0, 0x2e6888 <FT_Get_Sfnt_Name_Count+0x12>
 *   @0x2e687a ands r3, r3, #0x8
 *   @0x2e687e beq 0x2e6886 <FT_Get_Sfnt_Name_Count+0x10>
 *   @0x2e6882 .word 0x47700154
 *   @0x2e6886 mov r0, r3
 *
 * ══ §366/1245 FT_Stream_GetChar  0x2e69de  size 20  5 条（0x2e69de..0x2e69f2）
 * @func 0x2e69de 0x2e69f2  size 20  5 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e69de ldr r3, [r0, #0x20]
 *   @0x2e69e2 cmp r3, r2
 *   @0x2e69e6 addlo r2, r3, #0x1
 *   @0x2e69ea ldrblo r0, [r3]
 *   @0x2e69ee sxtb r0, r0
 *
 * ══ §367/1245 af_shaper_buf_create  0x30a6c0  size 20  5 条（0x30a6c0..0x30a6d4）
 * @func 0x30a6c0 0x30a6dc  size 28  7 条
 * 部分覆盖: 本节 6/11 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x64×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x30a6c0 push {r0, r1, r2, lr}
 *   @0x30a6c4 ldr r0, [r0, #0x64]
 *   @0x30a6c8 .word 0xf7dc0201
 *   @0x30a6cc andlt pc, r3, r12, lsr #26
 *   @0x30a6d0 ldr pc, [sp], #4
 *
 * ══ §368/1245 restore_core_regs  0x31a508  size 20  5 条（0x31a508..0x31a51c）
 * @func 0x31a508 0x31a51c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31a508 add r1, r0, #52
 *   @0x31a50c ldm r1, {r3, r4, r5}
 *   @0x31a510 push {r3, r4, r5}
 *   @0x31a514 ldm r0, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x31a518 ldm sp, {sp, lr, pc}
 *
 * ══ §369/1245 __aeabi_dcmpeq  0x31b06c  size 20  5 条（0x31b06c..0x31b080）
 * @func 0x31b06c 0x31b080  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_cdcmple
 * 字段偏移 top8: 0x-8×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31b06c str lr, [sp, #-0x8]!
 *   @0x31b070 bl 0x31b058 <__aeabi_cdcmple>
 *   @0x31b074 moveq r0, #1
 *   @0x31b078 movne r0, #0
 *   @0x31b07c ldr pc, [sp], #8
 *
 * ══ §370/1245 __aeabi_dcmple  0x31b094  size 20  5 条（0x31b094..0x31b0a8）
 * @func 0x31b094 0x31b0b8  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_cdcmple
 * 字段偏移 top8: 0x-8×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31b094 str lr, [sp, #-0x8]!
 *   @0x31b098 bl 0x31b058 <__aeabi_cdcmple>
 *   @0x31b09c movls r0, #1
 *   @0x31b0a0 movhi r0, #0
 *   @0x31b0a4 ldr pc, [sp], #8
 *
 * ══ §371/1245 __aeabi_dcmpge  0x31b0a8  size 20  5 条（0x31b0a8..0x31b0bc）
 * @func 0x31b0a8 0x31b0cc  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_cdrcmple
 * 字段偏移 top8: 0x-8×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31b0a8 str lr, [sp, #-0x8]!
 *   @0x31b0ac bl 0x31b03c <__aeabi_cdrcmple>
 *   @0x31b0b0 movls r0, #1
 *   @0x31b0b4 movhi r0, #0
 *   @0x31b0b8 ldr pc, [sp], #8
 *
 * ══ §372/1245 __aeabi_dcmpgt  0x31b0bc  size 20  5 条（0x31b0bc..0x31b0d0）
 * @func 0x31b0bc 0x31b0d0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_cdrcmple
 * 字段偏移 top8: 0x-8×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31b0bc str lr, [sp, #-0x8]!
 *   @0x31b0c0 bl 0x31b03c <__aeabi_cdrcmple>
 *   @0x31b0c4 movlo r0, #1
 *   @0x31b0c8 movhs r0, #0
 *   @0x31b0cc ldr pc, [sp], #8
 *
 * ══ §373/1245 __aeabi_fcmpeq  0x31b1bc  size 20  5 条（0x31b1bc..0x31b1d0）
 * @func 0x31b1bc 0x31b1d0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_cfcmple
 * 字段偏移 top8: 0x-8×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31b1bc str lr, [sp, #-0x8]!
 *   @0x31b1c0 bl 0x31b1a8 <__aeabi_cfcmple>
 *   @0x31b1c4 moveq r0, #1
 *   @0x31b1c8 movne r0, #0
 *   @0x31b1cc ldr pc, [sp], #8
 *
 * ══ §374/1245 __aeabi_fcmple  0x31b1e4  size 20  5 条（0x31b1e4..0x31b1f8）
 * @func 0x31b1e4 0x31b208  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_cfcmple
 * 字段偏移 top8: 0x-8×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31b1e4 str lr, [sp, #-0x8]!
 *   @0x31b1e8 bl 0x31b1a8 <__aeabi_cfcmple>
 *   @0x31b1ec movls r0, #1
 *   @0x31b1f0 movhi r0, #0
 *   @0x31b1f4 ldr pc, [sp], #8
 *
 * ══ §375/1245 __aeabi_fcmpge  0x31b1f8  size 20  5 条（0x31b1f8..0x31b20c）
 * @func 0x31b1f8 0x31b21c  size 36  9 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_cfrcmple
 * 字段偏移 top8: 0x-8×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31b1f8 str lr, [sp, #-0x8]!
 *   @0x31b1fc bl 0x31b198 <__aeabi_cfrcmple>
 *   @0x31b200 movls r0, #1
 *   @0x31b204 movhi r0, #0
 *   @0x31b208 ldr pc, [sp], #8
 *
 * ══ §376/1245 __aeabi_fcmpgt  0x31b20c  size 20  5 条（0x31b20c..0x31b220）
 * @func 0x31b20c 0x31b220  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_cfrcmple
 * 字段偏移 top8: 0x-8×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31b20c str lr, [sp, #-0x8]!
 *   @0x31b210 bl 0x31b198 <__aeabi_cfrcmple>
 *   @0x31b214 movlo r0, #1
 *   @0x31b218 movhs r0, #0
 *   @0x31b21c ldr pc, [sp], #8
 *
 * ══ §377/1245 _zip_read2(unsigned char**)  0x2a3ec0  size 18  5 条（0x2a3ec0..0x2a3ed2）
 * @func 0x2a3ec0 0x2a3ed4  size 20  5 条
 * 部分覆盖: 本节 5/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a3ec0 ldr r3, [r0]
 *   @0x2a3ec4 ldrb r2, [r3], #2
 *   @0x2a3ec8 add.w r2, r2, r1, lsl #8
 *   @0x2a3ecc str r3, [r0]
 *   @0x2a3ed0 bx lr
 *
 * ══ §378/1245 zip_get_archive_flag  0x2a48fc  size 18  5 条（0x2a48fc..0x2a490e）
 * @func 0x2a48fc 0x2a491a  size 30  8 条
 * 部分覆盖: 本节 6/11 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a48fc lsls r3, r2, #0x1c
 *   @0x2a4900 ldrmi r3, [r0, #0x18]
 *   @0x2a4904 tst r3, r1
 *   @0x2a4908 moveq r0, #0x0
 *   @0x2a490c bx lr
 *
 * ══ §379/1245 png_set_longjmp_fn  0x2a653c  size 18  5 条（0x2a653c..0x2a654e）
 * @func 0x2a653c 0x2a655e  size 34  9 条
 * 部分覆盖: 本节 6/10 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a653c cbz r0, 0x2a654c <png_set_longjmp_fn+0x10>
 *   @0x2a6540 smlabble r2, r0, pc, r7
 *   @0x2a6544 str.w r1, [r0, #0x100]
 *   @0x2a6548 bx lr
 *   @0x2a654c bx lr
 *
 * ══ §380/1245 png_create_read_struct  0x2a6fdc  size 18  5 条（0x2a6fdc..0x2a6fee）
 * @func 0x2a6fdc 0x2a6ff0  size 20  5 条
 * 部分覆盖: 本节 5/9 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6fdc push {r0, r1, r2, r3, r4, lr}
 *   @0x2a6fe0 str r4, [sp]
 *   @0x2a6fe4 str r4, [sp, #0x8]
 *   @0x2a6fe8 strhlt pc, [r4], -r1
 *   @0x2a6fec pop {r4, pc}
 *
 * ══ §381/1245 png_set_sRGB  0x2aed34  size 18  5 条（0x2aed34..0x2aed46）
 * @func 0x2aed34 0x2aed48  size 20  5 条
 * 部分覆盖: 本节 5/9 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2aed34 cbz r0, 0x2aed44 <png_set_sRGB+0x10>
 *   @0x2aed38 ldr r3, [r1, #0x8]
 *   @0x2aed3c vst4.8 {d18, d19, d20, d21}, [r3:128], r12
 *   @0x2aed40 addvs r6, r11, r0, lsl #6
 *   @0x2aed44 bx lr
 *
 * ══ §382/1245 png_create_write_struct  0x2b0364  size 18  5 条（0x2b0364..0x2b0376）
 * @func 0x2b0364 0x2b0378  size 20  5 条
 * 部分覆盖: 本节 5/9 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b0364 push {r0, r1, r2, r3, r4, lr}
 *   @0x2b0368 str r4, [sp]
 *   @0x2b036c str r4, [sp, #0x8]
 *   @0x2b0370 andlt pc, r4, r9, lsl #30
 *   @0x2b0374 pop {r4, pc}
 *
 * ══ §383/1245 FT_Set_Debug_Hook  0x2e5fe8  size 18  5 条（0x2e5fe8..0x2e5ffa）
 * @func 0x2e5fe8 0x2e5ffc  size 20  5 条
 * 部分覆盖: 本节 5/7 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5fe8 cbz r0, 0x2e5ff8 <FT_Set_Debug_Hook+0x10>
 *   @0x2e5fec cmp r1, #0x3
 *   @0x2e5ff0 addls.w r1, r0, r1, lsl #2
 *   @0x2e5ff4 strls.w r2, [r1, #0xac]
 *   @0x2e5ff8 bx lr
 *
 * ══ §384/1245 FT_Stream_Read  0x2e698e  size 18  5 条（0x2e698e..0x2e69a0）
 * @func 0x2e698e 0x2e69a2  size 20  5 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e698e push {r4, lr}
 *   @0x2e6992 mov r3, r2
 *   @0x2e6996 mov r2, r4
 *   @0x2e699a .word 0xf7ff4010
 *   @0x2e699e ldrblt r11, [r8, #0xfd2]!
 *
 * ══ §385/1245 FT_Cos  0x2e6f88  size 18  5 条（0x2e6f88..0x2e6f9a）
 * @func 0x2e6f88 0x2e6faa  size 34  9 条
 * 部分覆盖: 本节 6/11 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6f88 push {r0, r1, r2, lr}
 *   @0x2e6f8c mov r0, sp
 *   @0x2e6f90 stmdals r0, {r0, r1, r2, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2e6f94 add sp, #0xc
 *   @0x2e6f98 strlt pc, [r7, #-0xb04]
 *
 * ══ §386/1245 FT_Sin  0x2e6f9a  size 18  5 条（0x2e6f9a..0x2e6fac）
 * @func 0x2e6f9a 0x2e6fbc  size 34  9 条
 * 部分覆盖: 本节 6/11 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6f9a push {r0, r1, r2, lr}
 *   @0x2e6f9e mov r0, sp
 *   @0x2e6fa2 stmdals r1, {r1, r2, r3, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2e6fa6 add sp, #0xc
 *   @0x2e6faa strlt pc, [r7, #-0xb04]
 *
 * ══ §387/1245 FT_Hypot  0x2e707a  size 18  5 条（0x2e707a..0x2e708c）
 * @func 0x2e707a 0x2e708e  size 20  5 条
 * 部分覆盖: 本节 5/9 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_Vector_Length
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e707a push {r0, r1, r2, lr}
 *   @0x2e707e strbtmi r0, [r8], -r3
 *   @0x2e7082 bl 0x2e7028 <FT_Vector_Length>
 *   @0x2e7086 add sp, #0xc
 *   @0x2e708a ldrblt pc, [r7, #0xb04]!
 *
 * ══ §388/1245 FT_List_Find  0x2e890e  size 18  5 条（0x2e890e..0x2e8920）
 * @func 0x2e890e 0x2e8930  size 34  9 条
 * 部分覆盖: 本节 6/11 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e890e cbz r0, 0x2e891e <FT_List_Find+0x10>
 *   @0x2e8912 cbz r0, 0x2e891e <FT_List_Find+0x10>
 *   @0x2e8916 cmp r3, r1
 *   @0x2e891a ldr r0, [r0, #0x4]
 *   @0x2e891e bx lr
 *
 * ══ §389/1245 DPlay_Message_Name()  0xf2c7c  size 16  4 条（0xf2c7c..0xf2c8c）
 * @func 0xf2c7c 0xf2c9c  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2c7c ldr r0, [pc, #0x4]
 *   @0xf2c80 add r0, pc, r0
 *   @0xf2c84 bx lr
 *   @0xf2c88 eoreq r4, r4, r0, lsl #6
 *
 * ══ §390/1245 CExtensionConstant::Clear()  0xf47f4  size 16  4 条（0xf47f4..0xf4804）
 * @func 0xf47f4 0xf4804  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf47f4 mov r3, #0
 *   @0xf47f8 str r3, [r0, #0x4]
 *   @0xf47fc str r3, [r0, #0x8]
 *   @0xf4800 bx lr
 *
 * ══ §391/1245 CExtensionFunction::SetArgType(int, int)  0xf4988  size 16  4 条（0xf4988..0xf4998）
 * @func 0xf4988 0xf4998  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4988 cmp r1, #15
 *   @0xf498c addls r1, r1, #6
 *   @0xf4990 strls r2, [r0, r1, lsl #2]
 *   @0xf4994 bx lr
 *
 * ══ §392/1245 FINALIZE_Font_Main()  0xface8  size 16  4 条（0xface8..0xfacf8）
 * @func 0xface8 0xfacf8  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Font_FreeTextures()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xface8 push {r3, lr}
 *   @0xfacec bl 0xfac94 <_Z17Font_FreeTexturesv>
 *   @0xfacf0 pop {r3, lr}
 *   @0xfacf4 b 0xf9fb4 <_Z9Font_Initv>
 *
 * ══ §393/1245 YYGML_abs(double)  0x110fa8  size 16  4 条（0x110fa8..0x110fb8）
 * @func 0x110fa8 0x110fb8  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x110fa8 vmov d7, r0, r1
 *   @0x110fac vabs.f64 d7, d7
 *   @0x110fb0 vmov r0, r1, d7
 *   @0x110fb4 bx lr
 *
 * ══ §394/1245 F_IoClear(RValue&, CInstance*, CInstance*, int, RValue*)  0x1273c0  size 16  4 条（0x1273c0..0x1273d0）
 * @func 0x1273c0 0x1273d4  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ProcessMessages()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1273c0 push {r3, lr}
 *   @0x1273c4 bl 0x28fe64 <_Z15ProcessMessagesv>
 *   @0x1273c8 pop {r3, lr}
 *   @0x1273cc b 0x18c2c8 <_Z8IO_Clearv>
 *
 * ══ §395/1245 F_ActionReverseXDir(RValue&, CInstance*, CInstance*, int, RValue*)  0x13da80  size 16  4 条（0x13da80..0x13da90）
 * @func 0x13da80 0x13da90  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xe0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13da80 mov r0, r1
 *   @0x13da84 ldr r1, [r1, #0xe0]
 *   @0x13da88 eor r1, r1, #-2147483648
 *   @0x13da8c b 0x1930f4 <_ZN9CInstance9SetHspeedEf>
 *
 * ══ §396/1245 F_ActionReverseYDir(RValue&, CInstance*, CInstance*, int, RValue*)  0x13dae8  size 16  4 条（0x13dae8..0x13daf8）
 * @func 0x13dae8 0x13daf8  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xe4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13dae8 mov r0, r1
 *   @0x13daec ldr r1, [r1, #0xe4]
 *   @0x13daf0 eor r1, r1, #-2147483648
 *   @0x13daf4 b 0x193114 <_ZN9CInstance9SetVspeedEf>
 *
 * ══ §397/1245 F_ActionMoveStart(RValue&, CInstance*, CInstance*, int, RValue*)  0x13db80  size 16  4 条（0x13db80..0x13db90）
 * @func 0x13db80 0x13db90  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xbc×1 / 0xc0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13db80 mov r0, r1
 *   @0x13db84 ldr r1, [r1, #0xbc]
 *   @0x13db88 ldr r2, [r0, #0xc0]
 *   @0x13db8c b 0x193e7c <_ZN9CInstance11SetPositionEff>
 *
 * ══ §398/1245 F_GPUPushState(RValue&, CInstance*, CInstance*, int, RValue*)  0x146090  size 16  4 条（0x146090..0x1460a0）
 * @func 0x146090 0x1460b0  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x146090 ldr r0, [pc, #0x4]
 *   @0x146094 ldr r0, [pc, r0]
 *   @0x146098 b 0x167fcc <_ZN18RenderStateManager10SaveStatesEv>
 *   @0x14609c eoreq r7, r10, r4, ror #24
 *
 * ══ §399/1245 F_GPUPopState(RValue&, CInstance*, CInstance*, int, RValue*)  0x1460a0  size 16  4 条（0x1460a0..0x1460b0）
 * @func 0x1460a0 0x1460b0  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1460a0 ldr r0, [pc, #0x4]
 *   @0x1460a4 ldr r0, [pc, r0]
 *   @0x1460a8 b 0x168050 <_ZN18RenderStateManager13RestoreStatesEv>
 *   @0x1460ac eoreq r7, r10, r4, asr r12
 *
 * ══ §400/1245 F_YoYo_GetDomain(RValue&, CInstance*, CInstance*, int, RValue*)  0x156ba8  size 16  4 条（0x156ba8..0x156bb8）
 * @func 0x156ba8 0x156bc8  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156ba8 ldr r1, [pc, #0x4]
 *   @0x156bac add r1, pc, r1
 *   @0x156bb0 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x156bb4 andseq pc, lr, r8, asr r10
 *
 * ══ §401/1245 QuitYoYoFunctions()  0x15a0c0  size 16  4 条（0x15a0c0..0x15a0d0）
 * @func 0x15a0c0 0x15a0d0  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FlushAchievementCache()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15a0c0 push {r3, lr}
 *   @0x15a0c4 bl 0x159640 <_Z21FlushAchievementCachev>
 *   @0x15a0c8 pop {r3, lr}
 *   @0x15a0cc b 0x15e2a0 <_Z18QuitYoYoFunctionsMv>
 *
 * ══ §402/1245 InitYoYoFunctionsM()  0x15e2a8  size 16  4 条（0x15e2a8..0x15e2b8）
 * @func 0x15e2a8 0x15e2b8  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: AreOnlineAchievementsAvailable()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e2a8 push {r3, lr}
 *   @0x15e2ac bl 0x160f44 <_Z30AreOnlineAchievementsAvailablev>
 *   @0x15e2b0 pop {r3, lr}
 *   @0x15e2b4 b 0x159a60 <_Z21Set_AchievementSystemb>
 *
 * ══ §403/1245 YoYo_OF_AcceptChallenge()  0x1616f0  size 16  4 条（0x1616f0..0x161700）
 * @func 0x1616f0 0x161704  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1616f0 ldr r0, [pc, #0x4]
 *   @0x1616f4 add r0, pc, r0
 *   @0x1616f8 b 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1616fc andseq sp, r12, r2, asr #8
 *
 * ══ §404/1245 SetSteamHandle(RValue&, unsigned long long)  0x162494  size 16  4 条（0x162494..0x1624a4）
 * @func 0x162494 0x1624b4  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162494 mov r1, #10
 *   @0x162498 stm r0, {r2, r3}
 *   @0x16249c str r1, [r0, #0xc]
 *   @0x1624a0 bx lr
 *
 * ══ §405/1245 D3DXVector3(float, float, float, yyVector3&)  0x169d70  size 16  4 条（0x169d70..0x169d80）
 * @func 0x169d70 0x169d90  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x169d70 str r0, [r3]
 *   @0x169d74 str r1, [r3, #0x4]
 *   @0x169d78 str r2, [r3, #0x8]
 *   @0x169d7c bx lr
 *
 * ══ §406/1245 DeleteOGLResources()  0x17dafc  size 16  4 条（0x17dafc..0x17db0c）
 * @func 0x17dafc 0x17db1c  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DeleteVertexBuilderResources()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17dafc push {r3, lr}
 *   @0x17db00 bl 0x183d34 <_Z28DeleteVertexBuilderResourcesv>
 *   @0x17db04 pop {r3, lr}
 *   @0x17db08 b 0x18639c <_Z28DeleteShaderManagerResourcesv>
 *
 * ══ §407/1245 Graphics::Init()  0x17f38c  size 16  4 条（0x17f38c..0x17f39c）
 * @func 0x17f38c 0x17f39c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::GetTimerFreq()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17f38c push {r3, lr}
 *   @0x17f390 bl 0x17f368 <_ZN8Graphics12GetTimerFreqEv>
 *   @0x17f394 pop {r3, lr}
 *   @0x17f398 b 0x17afa0 <_ZN12GraphicsPerf4InitEv>
 *
 * ══ §408/1245 InitTextureResources()  0x183178  size 16  4 条（0x183178..0x183188）
 * @func 0x183178 0x183188  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FreeTextureResources()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x183178 push {r3, lr}
 *   @0x18317c bl 0x181190 <_Z20FreeTextureResourcesv>
 *   @0x183180 pop {r3, lr}
 *   @0x183184 b 0x1830dc <_Z17SetupBlankTexturev>
 *
 * ══ §409/1245 Graphics::UpdateTexture(Texture*)  0x18372c  size 16  4 条（0x18372c..0x18373c）
 * @func 0x18372c 0x18373c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18372c ldr r3, [r0, #0x10]
 *   @0x183730 bic r3, r3, #1
 *   @0x183734 str r3, [r0, #0x10]
 *   @0x183738 bx lr
 *
 * ══ §410/1245 PB_DSMap(HTTP_REQ_CONTEXT*, void*, int*)  0x18d714  size 16  4 条（0x18d714..0x18d724）
 * @func 0x18d714 0x18d724  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18d714 ldr r3, [r1]
 *   @0x18d718 str r3, [r2]
 *   @0x18d71c ldr r0, [r1, #0x4]
 *   @0x18d720 bx lr
 *
 * ══ §411/1245 INITIALIZE_Particle_Main()  0x1a5dd8  size 16  4 条（0x1a5dd8..0x1a5de8）
 * @func 0x1a5dd8 0x1a5de8  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ParticleType_DestroyAll()
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a5dd8 push {r3, lr}
 *   @0x1a5ddc bl 0x1a2d90 <_Z23ParticleType_DestroyAllv>
 *   @0x1a5de0 pop {r3, lr}
 *   @0x1a5de4 b 0x1a4590 <_Z25ParticleSystem_DestroyAllv>
 *
 * ══ §412/1245 Bounce_Test(CInstance*, float, float, bool)  0x1caf90  size 16  4 条（0x1caf90..0x1cafa0）
 * @func 0x1caf90 0x1cafa0  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1caf90 cmp r3, #0
 *   @0x1caf94 bne 0x1caf9c <_Z11Bounce_TestP9CInstanceffb+0xc>
 *   @0x1caf98 b 0x1cab94 <_Z14Command_IsFreeP9CInstanceff>
 *   @0x1caf9c b 0x1caa1c <_Z15Command_IsEmptyP9CInstanceff>
 *
 * ══ §413/1245 Get_SaveGameVersion()  0x1d038c  size 16  4 条（0x1d038c..0x1d039c）
 * @func 0x1d038c 0x1d039c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d038c ldr r3, [pc, #0x4]
 *   @0x1d0390 ldr r0, [pc, r3]
 *   @0x1d0394 bx lr
 *   @0x1d0398 eoreq r4, r2, r0, lsl #27
 *
 * ══ §414/1245 YYPATCH2(void*, void*)  0x1ddcd4  size 16  4 条（0x1ddcd4..0x1ddce4）
 * @func 0x1ddcd4 0x1ddce4  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ddcd4 ldr r0, [r0]
 *   @0x1ddcd8 cmp r0, #0
 *   @0x1ddcdc addne r0, r0, r1
 *   @0x1ddce0 bx lr
 *
 * ══ §415/1245 CStream::SetPosition(int)  0x201148  size 16  4 条（0x201148..0x201158）
 * @func 0x201148 0x201168  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201148 mov r3, #0
 *   @0x20114c str r1, [r0, #0x10]
 *   @0x201150 str r3, [r0, #0x14]
 *   @0x201154 bx lr
 *
 * ══ §416/1245 CDS_Stack::Empty()  0x202d40  size 16  4 条（0x202d40..0x202d50）
 * @func 0x202d40 0x202d50  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202d40 ldr r0, [r0, #0x4]
 *   @0x202d44 rsbs r0, r0, #1
 *   @0x202d48 movlo r0, #0
 *   @0x202d4c bx lr
 *
 * ══ §417/1245 CDS_Queue::GetSize()  0x202e20  size 16  4 条（0x202e20..0x202e30）
 * @func 0x202e20 0x202e30  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202e20 ldr r2, [r0, #0x4]
 *   @0x202e24 ldr r0, [r0, #0x8]
 *   @0x202e28 rsb r0, r0, r2
 *   @0x202e2c bx lr
 *
 * ══ §418/1245 CDS_List::Empty()  0x20317c  size 16  4 条（0x20317c..0x20318c）
 * @func 0x20317c 0x20318c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20317c ldr r0, [r0, #0x4]
 *   @0x203180 rsbs r0, r0, #1
 *   @0x203184 movlo r0, #0
 *   @0x203188 bx lr
 *
 * ══ §419/1245 CDS_Priority::Empty()  0x2040f8  size 16  4 条（0x2040f8..0x204108）
 * @func 0x2040f8 0x204108  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2040f8 ldr r0, [r0, #0x4]
 *   @0x2040fc rsbs r0, r0, #1
 *   @0x204100 movlo r0, #0
 *   @0x204104 bx lr
 *
 * ══ §420/1245 StringToFont(char const*, TFont&)  0x212e88  size 16  4 条（0x212e88..0x212e98）
 * @func 0x212e88 0x212ea0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x212e88 ldr r0, [pc, #0x4]
 *   @0x212e8c add r0, pc, r0
 *   @0x212e90 b 0xc4b0c <_Z11ShowMessagePKc>
 *   @0x212e94 ldrsbeq r0, [r4], -r8
 *
 * ══ §421/1245 OggAudioSyncDrawDebug()  0x215fc0  size 16  4 条（0x215fc0..0x215fd0）
 * @func 0x215fc0 0x215fd0  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215fc0 ldr r0, [pc, #0x4]
 *   @0x215fc4 add r0, pc, r0
 *   @0x215fc8 b 0x226a10 <_ZN9COggAudio13SyncDrawDebugEv>
 *   @0x215fcc ldrsbeq pc, [r3], #-32
 *
 * ══ §422/1245 CAudioGroupMan::CAudioGroupMan()  0x21de3c  size 16  4 条（0x21de3c..0x21de4c）
 * @func 0x21de3c 0x21de4c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21de3c mov r2, #0
 *   @0x21de40 str r2, [r0]
 *   @0x21de44 str r2, [r0, #0x4]
 *   @0x21de48 bx lr
 *
 * ══ §423/1245 _alutBufferDataDestroy  0x2213b8  size 16  4 条（0x2213b8..0x2213c8）
 * @func 0x2213b8 0x2213d8  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2213b8 push {r3, lr}
 *   @0x2213bc bl 0xb655c <free@plt>
 *   @0x2213c0 mov r0, #1
 *   @0x2213c4 pop {r3, pc}
 *
 * ══ §424/1245 ogg_zip_read(void*, unsigned int, unsigned int, void*)  0x223674  size 16  4 条（0x223674..0x223684）
 * @func 0x223674 0x22368c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2c8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223674 mul r2, r2, r1
 *   @0x223678 mov r1, r0
 *   @0x22367c ldr r0, [r3, #0x2c8]
 *   @0x223680 b 0x31ba7c <__udivdi3+0x3e4>
 *
 * ══ §425/1245 oggpack_bits  0x233e40  size 16  4 条（0x233e40..0x233e50）
 * @func 0x233e40 0x233e60  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233e40 ldr r2, [r0]
 *   @0x233e44 ldr r0, [r0, #0x4]
 *   @0x233e48 add r0, r0, r2, lsl #3
 *   @0x233e4c bx lr
 *
 * ══ §426/1245 IniFile::_sysWriteIniFile(char const*, char const*, int)  0x235d2c  size 16  4 条（0x235d2c..0x235d3c）
 * @func 0x235d2c 0x235d3c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x235d2c mov r0, r1
 *   @0x235d30 mov r1, r2
 *   @0x235d34 mov r2, r3
 *   @0x235d38 b 0x18fa3c <_ZN8LoadSave9WriteFileEPKcS1_i>
 *
 * ══ §427/1245 yoyo_b2relassert(bool, wchar_t const*)  0x237b78  size 16  4 条（0x237b78..0x237b88）
 * @func 0x237b78 0x237b88  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237b78 cmp r0, #0
 *   @0x237b7c bxne lr
 *   @0x237b80 mov r0, r1
 *   @0x237b84 b 0x237b04 <_ZN17b2ContactListenerD0Ev+0x28>
 *
 * ══ §428/1245 F_JSThis(RValue&, CInstance*, CInstance*, int, RValue*)  0x23c64c  size 16  4 条（0x23c64c..0x23c65c）
 * @func 0x23c64c 0x23c66c  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c64c mov r3, #6
 *   @0x23c650 str r1, [r0]
 *   @0x23c654 str r3, [r0, #0xc]
 *   @0x23c658 bx lr
 *
 * ══ §429/1245 F_JSOther(RValue&, CInstance*, CInstance*, int, RValue*)  0x23c674  size 16  4 条（0x23c674..0x23c684）
 * @func 0x23c674 0x23c684  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c674 mov r3, #6
 *   @0x23c678 str r2, [r0]
 *   @0x23c67c str r3, [r0, #0xc]
 *   @0x23c680 bx lr
 *
 * ══ §430/1245 F_JS_Object_prototype_valueOf(RValue&, CInstance*, CInstance*, int, RValue*)  0x23c6dc  size 16  4 条（0x23c6dc..0x23c6ec）
 * @func 0x23c6dc 0x23c6ec  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c6dc mov r3, #6
 *   @0x23c6e0 str r1, [r0]
 *   @0x23c6e4 str r3, [r0, #0xc]
 *   @0x23c6e8 bx lr
 *
 * ══ §431/1245 TimeWithinDay(double)  0x2449f8  size 16  4 条（0x2449f8..0x244a08）
 * @func 0x2449f8 0x244a08  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2449f8 movw r3, #0x9970
 *   @0x2449fc mov r2, #0
 *   @0x244a00 movt r3, #0x4194
 *   @0x244a04 b 0xb66ac <fmod@plt>
 *
 * ══ §432/1245 msFromTime(double)  0x2451c8  size 16  4 条（0x2451c8..0x2451d8）
 * @func 0x2451c8 0x2451d8  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2451c8 mov r3, #16384
 *   @0x2451cc mov r2, #0
 *   @0x2451d0 movt r3, #0x408f
 *   @0x2451d4 b 0xb66ac <fmod@plt>
 *
 * ══ §433/1245 F_JSThrowTypeError(RValue&, CInstance*, CInstance*, int, RValue*)  0x24eb28  size 16  4 条（0x24eb28..0x24eb38）
 * @func 0x24eb28 0x24eb38  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24eb28 ldr r0, [pc, #0x4]
 *   @0x24eb2c add r0, pc, r0
 *   @0x24eb30 b 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x24eb34 andseq r7, r0, r12, lsl r4
 *
 * ══ §434/1245 JS_Global_unimplemented(RValue&, CInstance*, CInstance*, int, RValue*)  0x254c20  size 16  4 条（0x254c20..0x254c30）
 * @func 0x254c20 0x254c30  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x254c20 ldr r0, [pc, #0x4]
 *   @0x254c24 add r0, pc, r0
 *   @0x254c28 b 0x254b04 <_Z21JSThrowReferenceErrorPKc>
 *   @0x254c2c ldrsbeq r1, [r0], -r12
 *
 * ══ §435/1245 pcre_version  0x266c9c  size 16  4 条（0x266c9c..0x266cac）
 * @func 0x266c9c 0x266cac  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x266c9c ldr r0, [pc, #0x4]
 *   @0x266ca0 add r0, pc, r0
 *   @0x266ca4 bx lr
 *   @0x266ca8 andeq r0, pc, r8, asr #7
 *
 * ══ §436/1245 mc_get_debug  0x27e2fc  size 16  4 条（0x27e2fc..0x27e30c）
 * @func 0x27e2fc 0x27e31c  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e2fc ldr r3, [pc, #0x4]
 *   @0x27e300 ldr r0, [pc, r3]
 *   @0x27e304 bx lr
 *   @0x27e308 strheq r8, [sp], #-128
 *
 * ══ §437/1245 lh_ptr_equal  0x2807ac  size 16  4 条（0x2807ac..0x2807bc）
 * @func 0x2807ac 0x2807bc  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2807ac subs r3, r1, r0
 *   @0x2807b0 rsbs r0, r3, #0
 *   @0x2807b4 adcs r0, r0, r3
 *   @0x2807b8 bx lr
 *
 * ══ §438/1245 spBone_isYDown  0x284eec  size 16  4 条（0x284eec..0x284efc）
 * @func 0x284eec 0x284efc  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x284eec ldr r3, [pc, #0x4]
 *   @0x284ef0 ldr r0, [pc, r3]
 *   @0x284ef4 bx lr
 *   @0x284ef8 subeq r1, sp, r8, asr #25
 *
 * ══ §439/1245 Json_getError  0x2872b8  size 16  4 条（0x2872b8..0x2872c8）
 * @func 0x2872b8 0x2872c8  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2872b8 ldr r3, [pc, #0x4]
 *   @0x2872bc ldr r0, [pc, r3]
 *   @0x2872c0 bx lr
 *   @0x2872c4 subeq pc, r12, r4, lsl #18
 *
 * ══ §440/1245 Java_com_yoyogames_runner_RunnerJNILib_dsMapCreate  0x292a98  size 16  4 条（0x292a98..0x292aa8）
 * @func 0x292a98 0x292ab8  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x292a98 push {r3, lr}
 *   @0x292a9c bl 0x290614 <setJNIEnv>
 *   @0x292aa0 pop {r3, lr}
 *   @0x292aa4 b 0x101818 <dsMapCreate>
 *
 * ══ §441/1245 Java_com_yoyogames_runner_RunnerJNILib_dsListCreate  0x292aa8  size 16  4 条（0x292aa8..0x292ab8）
 * @func 0x292aa8 0x292ab8  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: setJNIEnv
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x292aa8 push {r3, lr}
 *   @0x292aac bl 0x290614 <setJNIEnv>
 *   @0x292ab0 pop {r3, lr}
 *   @0x292ab4 b 0x101b9c <dsListCreate>
 *
 * ══ §442/1245 Java_com_yoyogames_runner_RunnerJNILib_iCadeEventDispatch  0x294bf8  size 16  4 条（0x294bf8..0x294c08）
 * @func 0x294bf8 0x294c18  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x294bf8 adds r1, r3, #0
 *   @0x294bfc mov r0, r2
 *   @0x294c00 movne r1, #1
 *   @0x294c04 b 0x1908f0 <_Z19iCadeSetButtonStateib>
 *
 * ══ §443/1245 Java_com_yoyogames_runner_RunnerJNILib_registerGamepadConnected  0x294c08  size 16  4 条（0x294c08..0x294c18）
 * @func 0x294c08 0x294c18  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x294c08 mov r0, r2
 *   @0x294c0c mov r1, r3
 *   @0x294c10 ldr r2, [sp]
 *   @0x294c14 b 0x190874 <_Z31RegisterAndroidGamepadConnectediii>
 *
 * ══ §444/1245 _zip_error_fini(zip_error*)  0x2a431e  size 16  4 条（0x2a431e..0x2a432e）
 * @func 0x2a431e 0x2a432e  size 16  4 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a431e push {r4, lr}
 *   @0x2a4322 ldr r0, [r0, #0x8]
 *   @0x2a4326 movwhs lr, #0x91a
 *   @0x2a432a str r3, [r4, #0x8]
 *
 * ══ §445/1245 png_reset_zstream  0x2a6026  size 16  4 条（0x2a6026..0x2a6036）
 * @func 0x2a6026 0x2a603e  size 24  6 条
 * 部分覆盖: 本节 5/9 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6026 cbz r0, 0x2a6030 <png_reset_zstream+0xa>
 *   @0x2a602a .word 0xf075709c
 *   @0x2a602e .word 0xf06fbd56
 *   @0x2a6032 ldrbmi r0, [r0, -r1]!
 *
 * ══ §446/1245 png_set_error_fn  0x2a654e  size 16  4 条（0x2a654e..0x2a655e）
 * @func 0x2a654e 0x2a656e  size 32  8 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a654e cbz r0, 0x2a655c <png_set_error_fn+0xe>
 *   @0x2a6552 .word 0xf8c0110c
 *   @0x2a6556 .word 0xf8c02104
 *   @0x2a655a ldrbmi r3, [r0, -r8, lsl #2]!
 *
 * ══ §447/1245 png_set_mem_fn  0x2a6d34  size 16  4 条（0x2a6d34..0x2a6d44）
 * @func 0x2a6d34 0x2a6d4c  size 24  6 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6d34 cbz r0, 0x2a6d42 <png_set_mem_fn+0xe>
 *   @0x2a6d38 .word 0xf8c012e8
 *   @0x2a6d3c .word 0xf8c022ec
 *   @0x2a6d40 .word 0x477032f0
 *
 * ══ §448/1245 png_start_read_image  0x2a7478  size 16  4 条（0x2a7478..0x2a7488）
 * @func 0x2a7478 0x2a7488  size 16  4 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a7478 cbz r0, 0x2a7486 <png_start_read_image+0xe>
 *   @0x2a747c uasxeq r3, r11, r0
 *   @0x2a7480 bmi 0x2a7486 <png_start_read_image+0xe>
 *   @0x2a7484 ldrbmi r11, [r0, -r7, lsl #16]!
 *
 * ══ §449/1245 png_set_strip_16  0x2a8184  size 16  4 条（0x2a8184..0x2a8194）
 * @func 0x2a8184 0x2a81a4  size 32  8 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a8184 cbz r0, 0x2a8192 <png_set_strip_16+0xe>
 *   @0x2a8188 vst4.8 {d19, d21, d23, d25}, [r3:256], r4
 *   @0x2a818c .word 0xf8c06380
 *   @0x2a8190 .word 0x47703134
 *
 * ══ §450/1245 png_set_strip_alpha  0x2a8194  size 16  4 条（0x2a8194..0x2a81a4）
 * @func 0x2a8194 0x2a81a4  size 16  4 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a8194 cbz r0, 0x2a81a2 <png_set_strip_alpha+0xe>
 *   @0x2a8198 vst4.8 {d19, d21, d23, d25}, [r3:256], r0
 *   @0x2a819c .word 0xf8c00380
 *   @0x2a81a0 .word 0x47703130
 *
 * ══ §451/1245 png_set_bgr  0x2af738  size 16  4 条（0x2af738..0x2af748）
 * @func 0x2af738 0x2af758  size 32  8 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af738 cbz r0, 0x2af746 <png_set_bgr+0xe>
 *   @0x2af73c .word 0xf0433134
 *   @0x2af740 .word 0xf8c00301
 *   @0x2af744 .word 0x47703134
 *
 * ══ §452/1245 png_set_swap_alpha  0x2af82a  size 16  4 条（0x2af82a..0x2af83a）
 * @func 0x2af82a 0x2af84a  size 32  8 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af82a cbz r0, 0x2af838 <png_set_swap_alpha+0xe>
 *   @0x2af82e vst4.8 {d19, d21, d23, d25}, [r3:256], r4
 *   @0x2af832 .word 0xf8c03300
 *   @0x2af836 .word 0x47703134
 *
 * ══ §453/1245 png_set_invert_alpha  0x2af83a  size 16  4 条（0x2af83a..0x2af84a）
 * @func 0x2af83a 0x2af85a  size 32  8 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af83a cbz r0, 0x2af848 <png_set_invert_alpha+0xe>
 *   @0x2af83e vst4.8 {d19, d21, d23, d25}, [r3:256], r4
 *   @0x2af842 .word 0xf8c02300
 *   @0x2af846 .word 0x47703134
 *
 * ══ §454/1245 png_set_invert_mono  0x2af84a  size 16  4 条（0x2af84a..0x2af85a）
 * @func 0x2af84a 0x2af85a  size 16  4 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af84a cbz r0, 0x2af858 <png_set_invert_mono+0xe>
 *   @0x2af84e .word 0xf0433134
 *   @0x2af852 .word 0xf8c00320
 *   @0x2af856 .word 0x47703134
 *
 * ══ §455/1245 png_set_user_transform_info  0x2afb9e  size 16  4 条（0x2afb9e..0x2afbae）
 * @func 0x2afb9e 0x2afbb6  size 24  6 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2afb9e cbz r0, 0x2afbac <png_set_user_transform_info+0xe>
 *   @0x2afba2 .word 0xf8801124
 *   @0x2afba6 .word 0xf8802128
 *   @0x2afbaa ldrbmi r3, [r0, -r9, lsr #2]!
 *
 * ══ §456/1245 png_save_uint_32  0x2b1124  size 16  4 条（0x2b1124..0x2b1134）
 * @func 0x2b1124 0x2b1140  size 28  7 条
 * 部分覆盖: 本节 5/9 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1×1 / 0x2×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b1124 lsrs r3, r1, #0x18
 *   @0x2b1128 strb r3, [r0]
 *   @0x2b112c strb r3, [r0, #0x1]
 *   @0x2b1130 strb r3, [r0, #0x2]
 *
 * ══ §457/1245 jpeg_mem_available  0x2c139c  size 16  4 条（0x2c139c..0x2c13ac）
 * @func 0x2c139c 0x2c13ac  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c139c ldr r2, [r0, #0x4]
 *   @0x2c13a0 ldr r0, [r2, #0x2c]
 *   @0x2c13a4 rsb r0, r3, r0
 *   @0x2c13a8 bx lr
 *
 * ══ §458/1245 b2Draw::AppendFlags(unsigned int)  0x2c67e8  size 16  4 条（0x2c67e8..0x2c67f8）
 * @func 0x2c67e8 0x2c6808  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c67e8 ldr r3, [r0, #0x4]
 *   @0x2c67ec orr r1, r3, r1
 *   @0x2c67f0 str r1, [r0, #0x4]
 *   @0x2c67f4 bx lr
 *
 * ══ §459/1245 b2Draw::ClearFlags(unsigned int)  0x2c67f8  size 16  4 条（0x2c67f8..0x2c6808）
 * @func 0x2c67f8 0x2c6808  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c67f8 ldr r3, [r0, #0x4]
 *   @0x2c67fc bic r1, r3, r1
 *   @0x2c6800 str r1, [r0, #0x4]
 *   @0x2c6804 bx lr
 *
 * ══ §460/1245 b2World::SetDestructionListener(b2DestructionListener*)  0x2c8ffc  size 16  4 条（0x2c8ffc..0x2c900c）
 * @func 0x2c8ffc 0x2c901c  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c8ffc movw r3, #0x9244
 *   @0x2c9000 movt r3, #0x1
 *   @0x2c9004 str r1, [r0, r3]
 *   @0x2c9008 bx lr
 *
 * ══ §461/1245 b2World::SetContactFilter(b2ContactFilter*)  0x2c900c  size 16  4 条（0x2c900c..0x2c901c）
 * @func 0x2c900c 0x2c901c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c900c movw r3, #0x921c
 *   @0x2c9010 movt r3, #0x1
 *   @0x2c9014 str r1, [r0, r3]
 *   @0x2c9018 bx lr
 *
 * ══ §462/1245 b2World::SetDebugDraw(b2Draw*)  0x2c902c  size 16  4 条（0x2c902c..0x2c903c）
 * @func 0x2c902c 0x2c903c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c902c movw r3, #0x9248
 *   @0x2c9030 movt r3, #0x1
 *   @0x2c9034 str r1, [r0, r3]
 *   @0x2c9038 bx lr
 *
 * ══ §463/1245 b2World::GetProxyCount() const  0x2cb104  size 16  4 条（0x2cb104..0x2cb114）
 * @func 0x2cb104 0x2cb124  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb104 movw r3, #0x91f4
 *   @0x2cb108 movt r3, #0x1
 *   @0x2cb10c ldr r0, [r0, r3]
 *   @0x2cb110 bx lr
 *
 * ══ §464/1245 b2World::GetParticleContacts()  0x2cb634  size 16  4 条（0x2cb634..0x2cb644）
 * @func 0x2cb634 0x2cb654  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb634 movw r3, #0x92f0
 *   @0x2cb638 movt r3, #0x1
 *   @0x2cb63c ldr r0, [r0, r3]
 *   @0x2cb640 bx lr
 *
 * ══ §465/1245 b2World::GetParticleContactCount()  0x2cb644  size 16  4 条（0x2cb644..0x2cb654）
 * @func 0x2cb644 0x2cb664  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb644 movw r3, #0x92e8
 *   @0x2cb648 movt r3, #0x1
 *   @0x2cb64c ldr r0, [r0, r3]
 *   @0x2cb650 bx lr
 *
 * ══ §466/1245 b2World::GetParticleBodyContacts()  0x2cb654  size 16  4 条（0x2cb654..0x2cb664）
 * @func 0x2cb654 0x2cb674  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb654 movw r3, #0x92fc
 *   @0x2cb658 movt r3, #0x1
 *   @0x2cb65c ldr r0, [r0, r3]
 *   @0x2cb660 bx lr
 *
 * ══ §467/1245 b2World::GetParticleBodyContactCount()  0x2cb664  size 16  4 条（0x2cb664..0x2cb674）
 * @func 0x2cb664 0x2cb680  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb664 movw r3, #0x92f4
 *   @0x2cb668 movt r3, #0x1
 *   @0x2cb66c ldr r0, [r0, r3]
 *   @0x2cb670 bx lr
 *
 * ══ §468/1245 b2Joint::Dump()  0x2ccaa8  size 16  4 条（0x2ccaa8..0x2ccab8）
 * @func 0x2ccaa8 0x2ccab8  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ccaa8 ldr r0, [pc, #0x4]
 *   @0x2ccaac add r0, pc, r0
 *   @0x2ccab0 b 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2ccab4 strheq pc, [r8], -r4
 *
 * ══ §469/1245 b2MouseJoint::Dump()  0x2cea1c  size 16  4 条（0x2cea1c..0x2cea2c）
 * @func 0x2cea1c 0x2cea2c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cea1c ldr r0, [pc, #0x4]
 *   @0x2cea20 add r0, pc, r0
 *   @0x2cea24 b 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2cea28 andeq sp, r8, r0, lsr #13
 *
 * ══ §470/1245 b2ParticleGroup::GetAngle() const  0x2d4624  size 16  4 条（0x2d4624..0x2d4634）
 * @func 0x2d4624 0x2d4644  size 32  8 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x44×1 / 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d4624 mov r3, r0
 *   @0x2d4628 ldr r0, [r0, #0x44]
 *   @0x2d462c ldr r1, [r3, #0x48]
 *   @0x2d4630 b 0xb6778 <atan2f@plt>
 *
 * ══ §471/1245 b2StackAllocator::GetMaxAllocation() const  0x2e1080  size 16  4 条（0x2e1080..0x2e1090）
 * @func 0x2e1080 0x2e1090  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e1080 movw r3, #0x9008
 *   @0x2e1084 movt r3, #0x1
 *   @0x2e1088 ldr r0, [r0, r3]
 *   @0x2e108c bx lr
 *
 * ══ §472/1245 FT_Property_Get  0x2e5f96  size 16  4 条（0x2e5f96..0x2e5fa6）
 * @func 0x2e5f96 0x2e5fb6  size 32  8 条
 * 部分覆盖: 本节 5/9 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2e490c+0x374
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5f96 push {r0, r1, r4, lr}
 *   @0x2e5f9a str r4, [sp]
 *   @0x2e5f9e bl 0x2e4c80 <_ZNK11b2GearJoint8GetRatioEv+0x37c>
 *   @0x2e5fa2 add sp, #0x8
 *
 * ══ §473/1245 ft_property_string_set  0x2e5fa6  size 16  4 条（0x2e5fa6..0x2e5fb6）
 * @func 0x2e5fa6 0x2e5fc6  size 32  8 条
 * 部分覆盖: 本节 5/9 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2e490c+0x374
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5fa6 push {r0, r1, r4, lr}
 *   @0x2e5faa str r4, [sp]
 *   @0x2e5fae bl 0x2e4c80 <_ZNK11b2GearJoint8GetRatioEv+0x37c>
 *   @0x2e5fb2 add sp, #0x8
 *
 * ══ §474/1245 FT_Stream_OpenMemory  0x2e688a  size 16  4 条（0x2e688a..0x2e689a）
 * @func 0x2e688a 0x2e68a6  size 28  7 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x20×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e688a movs r3, #0x0
 *   @0x2e688e addvs r0, r3, r6
 *   @0x2e6892 str r3, [r0, #0x20]
 *   @0x2e6896 str r3, [r0, #0x18]
 *
 * ══ §475/1245 FT_Stream_Skip  0x2e6930  size 16  4 条（0x2e6930..0x2e6940）
 * @func 0x2e6930 0x2e6944  size 20  5 条
 * 部分覆盖: 本节 5/9 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6930 cmp r1, #0x0
 *   @0x2e6934 ldr r3, [r0, #0x8]
 *   @0x2e6938 b.w 0x2e68a6 <FT_Stream_Seek>
 *   @0x2e693c movs r0, #0x55
 *
 * ══ §476/1245 FT_Vector_From_Polar  0x2e70ce  size 16  4 条（0x2e70ce..0x2e70de）
 * @func 0x2e70ce 0x2e70de  size 16  4 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e70ce cbz r0, 0x2e70dc <FT_Vector_From_Polar+0xe>
 *   @0x2e70d2 movs r1, #0x0
 *   @0x2e70d6 mov r1, r2
 *   @0x2e70da .word 0x4770bf74
 *
 * ══ §477/1245 __aeabi_ldiv0  0x319458  size 16  4 条（0x319458..0x319468）
 * @func 0x319458 0x319468  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6fb8
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x319458 push {r1, lr}
 *   @0x31945c mov r0, #8
 *   @0x319460 bl 0xb6fb8 <raise@plt>
 *   @0x319464 pop {r1, pc}
 *
 * ══ §478/1245 _Unwind_GetRegionStart  0x31aaf8  size 16  4 条（0x31aaf8..0x31ab08）
 * @func 0x31aaf8 0x31ab08  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x31a738
 * 字段偏移 top8: 0x48×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31aaf8 push {r3, lr}
 *   @0x31aafc bl 0x31a738 <___Unwind_Backtrace+0xac>
 *   @0x31ab00 ldr r0, [r0, #0x48]
 *   @0x31ab04 pop {r3, pc}
 *
 * ══ §479/1245 png_get_valid  0x2a6566  size 14  4 条（0x2a6566..0x2a6574）
 * @func 0x2a6566 0x2a6584  size 30  8 条
 * 部分覆盖: 本节 5/9 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6566 cbz r0, 0x2a6572 <png_get_valid+0xc>
 *   @0x2a656a ldr r0, [r1, #0x8]
 *   @0x2a656e bx lr
 *   @0x2a6572 bx lr
 *
 * ══ §480/1245 png_get_rows  0x2a6580  size 14  4 条（0x2a6580..0x2a658e）
 * @func 0x2a6580 0x2a659e  size 30  8 条
 * 部分覆盖: 本节 5/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6580 cbz r0, 0x2a658c <png_get_rows+0xc>
 *   @0x2a6584 ldr.w r0, [r1, #0xf8]
 *   @0x2a6588 bx lr
 *   @0x2a658c bx lr
 *
 * ══ §481/1245 png_get_signature  0x2a6708  size 14  4 条（0x2a6708..0x2a6716）
 * @func 0x2a6708 0x2a6718  size 16  4 条
 * 部分覆盖: 本节 4/7 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6708 cbz r0, 0x2a6714 <png_get_signature+0xc>
 *   @0x2a670c add.w r0, r1, #0x20
 *   @0x2a6710 bx lr
 *   @0x2a6714 bx lr
 *
 * ══ §482/1245 png_malloc_default  0x2a6c90  size 14  4 条（0x2a6c90..0x2a6c9e）
 * @func 0x2a6c90 0x2a6ca0  size 16  4 条
 * 部分覆盖: 本节 4/7 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6c90 cbz r0, 0x2a6c9a <png_malloc_default+0xa>
 *   @0x2a6c94 mov r0, r1
 *   @0x2a6c98 andhs r11, r0, r1, lsr pc
 *   @0x2a6c9c bx lr
 *
 * ══ §483/1245 png_permit_mng_features  0x2af452  size 14  4 条（0x2af452..0x2af460）
 * @func 0x2af452 0x2af462  size 16  4 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af452 cbz r0, 0x2af45e <png_permit_mng_features+0xc>
 *   @0x2af456 .word 0xf8c00105
 *   @0x2af45a .word 0x460812dc
 *   @0x2af45e bx lr
 *
 * ══ §484/1245 png_set_invalid  0x2af586  size 14  4 条（0x2af586..0x2af594）
 * @func 0x2af586 0x2af5a4  size 30  8 条
 * 部分覆盖: 本节 5/9 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af586 cbz r0, 0x2af592 <png_set_invalid+0xc>
 *   @0x2af58a ldr r3, [r1, #0x8]
 *   @0x2af58e addvs r0, r11, r2, lsl #6
 *   @0x2af592 bx lr
 *
 * ══ §485/1245 FT_RoundFix  0x2e4d1c  size 14  4 条（0x2e4d1c..0x2e4d2a）
 * @func 0x2e4d1c 0x2e4d3a  size 30  8 条
 * 部分覆盖: 本节 8/12 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 5/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e4d1c add.w r3, r0, #0x8000
 *   @0x2e4d20 sub.w r0, r3, r0, lsr #31
 *   @0x2e4d24 lsrs r0, r0, #0x10
 *   @0x2e4d28 bx lr
 *
 * ══ §486/1245 ft_hash_str_lookup  0x2e5336  size 14  4 条（0x2e5336..0x2e5344）
 * @func 0x2e5336 0x2e5354  size 30  8 条
 * 部分覆盖: 本节 5/9 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5336 push {r3, lr}
 *   @0x2e533a stmdavs r0, {r1, r2, r3, r4, r5, r8, r9, r11, r12, sp, lr, pc}
 *   @0x2e533e cbz r0, 0x2e5342 <ft_hash_str_lookup+0xc>
 *   @0x2e5342 pop {r3, pc}
 *
 * ══ §487/1245 ft_hash_num_lookup  0x2e5344  size 14  4 条（0x2e5344..0x2e5352）
 * @func 0x2e5344 0x2e5354  size 16  4 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5344 push {r3, lr}
 *   @0x2e5348 stmdavs r0, {r0, r1, r2, r4, r5, r8, r9, r11, r12, sp, lr, pc}
 *   @0x2e534c cbz r0, 0x2e5350 <ft_hash_num_lookup+0xc>
 *   @0x2e5350 pop {r3, pc}
 *
 * ══ §488/1245 FT_Get_Module_Interface  0x2e5f28  size 14  4 条（0x2e5f28..0x2e5f36）
 * @func 0x2e5f28 0x2e5f38  size 16  4 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5f28 push {r3, lr}
 *   @0x2e5f2c smlattlt r8, r1, pc, pc
 *   @0x2e5f30 ldr r3, [r0]
 *   @0x2e5f34 pop {r3, pc}
 *
 * ══ §489/1245 ft_glyphslot_set_bitmap  0x2e7554  size 14  4 条（0x2e7554..0x2e7562）
 * @func 0x2e7554 0x2e7564  size 16  4 条
 * 部分覆盖: 本节 4/7 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e7554 push {r3, r4, r5, lr}
 *   @0x2e7558 mov r5, r1
 *   @0x2e755c strvs pc, [r5, #0xfe2]!
 *   @0x2e7560 pop {r3, r4, r5, pc}
 *
 * ══ §490/1245 FT_Open_Face  0x2e9716  size 14  4 条（0x2e9716..0x2e9724）
 * @func 0x2e9716 0x2e9726  size 16  4 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e9716 push {r0, r1, r4, lr}
 *   @0x2e971a str r4, [sp]
 *   @0x2e971e andlt pc, r2, r12, lsl #21
 *   @0x2e9722 pop {r4, pc}
 *
 * ══ §491/1245 FT_Bitmap_Init  0x3149bc  size 14  4 条（0x3149bc..0x3149ca）
 * @func 0x3149bc 0x3149da  size 30  8 条
 * 部分覆盖: 本节 7/11 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 5/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x3149bc push {r3, lr}
 *   @0x3149c0 movs r1, #0x0
 *   @0x3149c4 blx 0xb65b0 <memset@plt>
 *   @0x3149c8 pop {r3, pc}
 *
 * ══ §492/1245 FT_Bitmap_New  0x3149ca  size 14  4 条（0x3149ca..0x3149d8）
 * @func 0x3149ca 0x3149da  size 16  4 条
 * 部分覆盖: 本节 4/7 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x3149ca push {r3, lr}
 *   @0x3149ce movs r1, #0x0
 *   @0x3149d2 blx 0xb65b0 <memset@plt>
 *   @0x3149d6 pop {r3, pc}
 *
 * ══ §493/1245 CFontGM::CFont_Free(void*)  0xf9414  size 12  3 条（0xf9414..0xf9420）
 * @func 0xf9414 0xf9430  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf9414 cmp r0, #0
 *   @0xf9418 bxeq lr
 *   @0xf941c b 0xf93ac <_ZN7CFontGM4FreeEv>
 *
 * ══ §494/1245 CFontGM::CFont_GetName(void*)  0xf9420  size 12  3 条（0xf9420..0xf942c）
 * @func 0xf9420 0xf9438  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf9420 cmp r0, #0
 *   @0xf9424 bxeq lr
 *   @0xf9428 b 0xf93c8 <_ZN7CFontGM7GetNameEv>
 *
 * ══ §495/1245 CFontGM::CFont_GetSize(void*)  0xf942c  size 12  3 条（0xf942c..0xf9438）
 * @func 0xf942c 0xf9438  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf942c cmp r0, #0
 *   @0xf9430 bxeq lr
 *   @0xf9434 b 0xf93d0 <_ZN7CFontGM7GetSizeEv>
 *
 * ══ §496/1245 CFontGM::CFont_GetFirst(void*)  0xf9470  size 12  3 条（0xf9470..0xf947c）
 * @func 0xf9470 0xf948c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf9470 cmp r0, #0
 *   @0xf9474 bxeq lr
 *   @0xf9478 b 0xf93e8 <_ZN7CFontGM8GetFirstEv>
 *
 * ══ §497/1245 CFontGM::CFont_GetLast(void*)  0xf947c  size 12  3 条（0xf947c..0xf9488）
 * @func 0xf947c 0xf9498  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf947c cmp r0, #0
 *   @0xf9480 bxeq lr
 *   @0xf9484 b 0xf93f0 <_ZN7CFontGM7GetLastEv>
 *
 * ══ §498/1245 CFontGM::CFont_InitTexture(void*)  0xf94cc  size 12  3 条（0xf94cc..0xf94d8）
 * @func 0xf94cc 0xf94e8  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf94cc cmp r0, #0
 *   @0xf94d0 bxeq lr
 *   @0xf94d4 b 0xf7db4 <_ZN7CFontGM11InitTextureEv>
 *
 * ══ §499/1245 CFontGM::CFont_FreeTexture(void*)  0xf94d8  size 12  3 条（0xf94d8..0xf94e4）
 * @func 0xf94d8 0xf94f4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf94d8 cmp r0, #0
 *   @0xf94dc bxeq lr
 *   @0xf94e0 b 0xf707c <_ZN7CFontGM11FreeTextureEv>
 *
 * ══ §500/1245 CFontGM::CFont_TextWidth(void*, unsigned short*)  0xf9568  size 12  3 条（0xf9568..0xf9574）
 * @func 0xf9568 0xf9580  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf9568 cmp r0, #0
 *   @0xf956c bxeq lr
 *   @0xf9570 b 0xf8b04 <_ZN7CFontGM9TextWidthEPt>
 *
 * ══ §501/1245 CFontGM::CFont_TextHeight(void*, unsigned short*)  0xf9574  size 12  3 条（0xf9574..0xf9580）
 * @func 0xf9574 0xf9580  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf9574 cmp r0, #0
 *   @0xf9578 bxeq lr
 *   @0xf957c b 0xf93a4 <_ZN7CFontGM10TextHeightEPt>
 *
 * ══ §502/1245 YYGML_make_color_rgb(int, int, int)  0x120ea4  size 12  3 条（0x120ea4..0x120eb0）
 * @func 0x120ea4 0x120eb4  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x120ea4 add r0, r0, r1, lsl #8
 *   @0x120ea8 add r0, r0, r2, lsl #16
 *   @0x120eac bx lr
 *
 * ══ §503/1245 YYGML_surface_set_target(int)  0x123260  size 12  3 条（0x123260..0x12326c）
 * @func 0x123260 0x12326c  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x123260 mov r1, r0
 *   @0x123264 mov r0, #0
 *   @0x123268 b 0x171574 <_Z28YYGML_surface_set_target_extii>
 *
 * ══ §504/1245 F_ActionTimelineStart(RValue&, CInstance*, CInstance*, int, RValue*)  0x13d634  size 12  3 条（0x13d634..0x13d640）
 * @func 0x13d634 0x13d650  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x15c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13d634 mov r3, #1
 *   @0x13d638 strb r3, [r1, #0x15c]
 *   @0x13d63c bx lr
 *
 * ══ §505/1245 F_ActionTimelinePause(RValue&, CInstance*, CInstance*, int, RValue*)  0x13d640  size 12  3 条（0x13d640..0x13d64c）
 * @func 0x13d640 0x13d65c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x15c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13d640 mov r3, #0
 *   @0x13d644 strb r3, [r1, #0x15c]
 *   @0x13d648 bx lr
 *
 * ══ §506/1245 YYGML_action_reverse_xdir(CInstance*)  0x141684  size 12  3 条（0x141684..0x141690）
 * @func 0x141684 0x14169c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xe0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141684 ldr r1, [r0, #0xe0]
 *   @0x141688 eor r1, r1, #-2147483648
 *   @0x14168c b 0x1930f4 <_ZN9CInstance9SetHspeedEf>
 *
 * ══ §507/1245 YYGML_action_reverse_ydir(CInstance*)  0x141690  size 12  3 条（0x141690..0x14169c）
 * @func 0x141690 0x14169c  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xe4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141690 ldr r1, [r0, #0xe4]
 *   @0x141694 eor r1, r1, #-2147483648
 *   @0x141698 b 0x193114 <_ZN9CInstance9SetVspeedEf>
 *
 * ══ §508/1245 F_YoYo_OpenURL_full(RValue&, CInstance*, CInstance*, int, RValue*)  0x156dc0  size 12  3 条（0x156dc0..0x156dcc）
 * @func 0x156dc0 0x156dd8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156dc0 cmp r3, #1
 *   @0x156dc4 movge r3, #1
 *   @0x156dc8 b 0x156be8 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_>
 *
 * ══ §509/1245 F_YoYo_OpenURL_ext(RValue&, CInstance*, CInstance*, int, RValue*)  0x156dcc  size 12  3 条（0x156dcc..0x156dd8）
 * @func 0x156dcc 0x156dd8  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156dcc cmp r3, #1
 *   @0x156dd0 movge r3, #1
 *   @0x156dd4 b 0x156be8 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_>
 *
 * ══ §510/1245 F_SteamUGC_CreateQueryUser(RValue&, CInstance*, CInstance*, int, RValue*)  0x1624a4  size 12  3 条（0x1624a4..0x1624b0）
 * @func 0x1624a4 0x1624c0  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1624a4 mvn r2, #0
 *   @0x1624a8 mvn r3, #0
 *   @0x1624ac b 0x162494 <_Z14SetSteamHandleR6RValuey>
 *
 * ══ §511/1245 F_SteamUGC_CreateQueryUserEx(RValue&, CInstance*, CInstance*, int, RValue*)  0x1624b0  size 12  3 条（0x1624b0..0x1624bc）
 * @func 0x1624b0 0x1624cc  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1624b0 mvn r2, #0
 *   @0x1624b4 mvn r3, #0
 *   @0x1624b8 b 0x162494 <_Z14SetSteamHandleR6RValuey>
 *
 * ══ §512/1245 F_SteamUGC_CreateQueryAll(RValue&, CInstance*, CInstance*, int, RValue*)  0x1624bc  size 12  3 条（0x1624bc..0x1624c8）
 * @func 0x1624bc 0x1624d4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1624bc mvn r2, #0
 *   @0x1624c0 mvn r3, #0
 *   @0x1624c4 b 0x162494 <_Z14SetSteamHandleR6RValuey>
 *
 * ══ §513/1245 F_SteamUGC_CreateQueryAllEx(RValue&, CInstance*, CInstance*, int, RValue*)  0x1624c8  size 12  3 条（0x1624c8..0x1624d4）
 * @func 0x1624c8 0x1624d4  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1624c8 mvn r2, #0
 *   @0x1624cc mvn r3, #0
 *   @0x1624d0 b 0x162494 <_Z14SetSteamHandleR6RValuey>
 *
 * ══ §514/1245 CCamera::SetViewDirty()  0x16d36c  size 12  3 条（0x16d36c..0x16d378）
 * @func 0x16d36c 0x16d378  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1b9×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d36c mov r3, #1
 *   @0x16d370 strb r3, [r0, #0x1b9]
 *   @0x16d374 bx lr
 *
 * ══ §515/1245 DisplaySetSize(int, int)  0x17db6c  size 12  3 条（0x17db6c..0x17db78）
 * @func 0x17db6c 0x17db88  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17db6c mov r2, #0
 *   @0x17db70 mov r3, r2
 *   @0x17db74 b 0x17db64 <_Z10DisplaySetiiii>
 *
 * ══ §516/1245 Graphics::GetTimerFreq()  0x17f368  size 12  3 条（0x17f368..0x17f374）
 * @func 0x17f368 0x17f384  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17f368 mov r0, #0
 *   @0x17f36c mov r1, #0
 *   @0x17f370 bx lr
 *
 * ══ §517/1245 Graphics::GetTimer()  0x17f374  size 12  3 条（0x17f374..0x17f380）
 * @func 0x17f374 0x17f390  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17f374 mov r0, #0
 *   @0x17f378 mov r1, #0
 *   @0x17f37c bx lr
 *
 * ══ §518/1245 FreeVirtualKey(SVirtualKeyDef*)  0x18c5fc  size 12  3 条（0x18c5fc..0x18c608）
 * @func 0x18c5fc 0x18c608  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18c5fc mov r3, #0
 *   @0x18c600 strh r3, [r0]
 *   @0x18c604 bx lr
 *
 * ══ §519/1245 LoadSave::ftell(_YYFILE*)  0x18de24  size 12  3 条（0x18de24..0x18de30）
 * @func 0x18de24 0x18de30  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18de24 ldr r3, [r0]
 *   @0x18de28 ldr r0, [r3, #0x1c]
 *   @0x18de2c bx lr
 *
 * ══ §520/1245 CLayerManager::BuildBackgroundElementRuntimeData(CRoom*, CLayer*, CLayerBackgroundElement*)  0x1b803c  size 12  3 条（0x1b803c..0x1b8048）
 * @func 0x1b803c 0x1b8048  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b803c mov r3, #1
 *   @0x1b8040 strb r3, [r2, #0x8]
 *   @0x1b8044 bx lr
 *
 * ══ §521/1245 CLayerManager::BuildSpriteElementRuntimeData(CRoom*, CLayer*, CLayerSpriteElement*)  0x1b81d0  size 12  3 条（0x1b81d0..0x1b81dc）
 * @func 0x1b81d0 0x1b81ec  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b81d0 mov r3, #1
 *   @0x1b81d4 strb r3, [r2, #0x8]
 *   @0x1b81d8 bx lr
 *
 * ══ §522/1245 CLayerManager::BuildTilemapElementRuntimeData(CRoom*, CLayer*, CLayerTilemapElement*)  0x1b81dc  size 12  3 条（0x1b81dc..0x1b81e8）
 * @func 0x1b81dc 0x1b81f8  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b81dc mov r3, #1
 *   @0x1b81e0 strb r3, [r2, #0x8]
 *   @0x1b81e4 bx lr
 *
 * ══ §523/1245 CLayerManager::BuildParticleElementRuntimeData(CRoom*, CLayer*, CLayerParticleElement*)  0x1b81e8  size 12  3 条（0x1b81e8..0x1b81f4）
 * @func 0x1b81e8 0x1b8200  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b81e8 mov r3, #1
 *   @0x1b81ec strb r3, [r2, #0x8]
 *   @0x1b81f0 bx lr
 *
 * ══ §524/1245 CLayerManager::BuildTileElementRuntimeData(CRoom*, CLayer*, CLayerTileElement*)  0x1b81f4  size 12  3 条（0x1b81f4..0x1b8200）
 * @func 0x1b81f4 0x1b8200  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b81f4 mov r3, #1
 *   @0x1b81f8 strb r3, [r2, #0x8]
 *   @0x1b81fc bx lr
 *
 * ══ §525/1245 CLayerManager::GetNumLayersInRoom(CRoom*)  0x1b89cc  size 12  3 条（0x1b89cc..0x1b89d8）
 * @func 0x1b89cc 0x1b89d8  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b89cc cmp r0, #0
 *   @0x1b89d0 ldrne r0, [r0, #0xdc]
 *   @0x1b89d4 bx lr
 *
 * ══ §526/1245 CDS_Map::Size()  0x2052c0  size 12  3 条（0x2052c0..0x2052cc）
 * @func 0x2052c0 0x2052d4  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2052c0 ldr r3, [r0]
 *   @0x2052c4 ldr r0, [r3, #0x8]
 *   @0x2052c8 bx lr
 *
 * ══ §527/1245 CListener::SetGain(float)  0x215b34  size 12  3 条（0x215b34..0x215b40）
 * @func 0x215b34 0x215b48  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215b34 str r1, [r0, #0x30]
 *   @0x215b38 movw r0, #0x100a
 *   @0x215b3c b 0xb6a30 <alListenerf@plt>
 *
 * ══ §528/1245 _alutBufferDataDetachData  0x2213d0  size 12  3 条（0x2213d0..0x2213dc）
 * @func 0x2213d0 0x2213ec  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2213d0 mov r3, #0
 *   @0x2213d4 str r3, [r0]
 *   @0x2213d8 bx lr
 *
 * ══ §529/1245 _alutOutputStreamGetLength  0x222924  size 12  3 条（0x222924..0x222930）
 * @func 0x222924 0x222930  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x222924 ldm r0, {r0, r2}
 *   @0x222928 rsb r0, r0, r2
 *   @0x22292c bx lr
 *
 * ══ §530/1245 COggThread::WaitForThreadExit()  0x223838  size 12  3 条（0x223838..0x223844）
 * @func 0x223838 0x223844  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223838 add r0, r0, #2064
 *   @0x22383c add r0, r0, #8
 *   @0x223840 b 0x27e108 <_ZN7CThread11WaitForExitEv>
 *
 * ══ §531/1245 COggSyncThread::WaitForThreadExit()  0x2248e8  size 12  3 条（0x2248e8..0x2248f4）
 * @func 0x2248e8 0x2248f4  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2248e8 add r0, r0, #2096
 *   @0x2248ec add r0, r0, #4
 *   @0x2248f0 b 0x27e108 <_ZN7CThread11WaitForExitEv>
 *
 * ══ §532/1245 ogg_stream_flush  0x234a04  size 12  3 条（0x234a04..0x234a10）
 * @func 0x234a04 0x234a1c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x234a04 mov r2, #1
 *   @0x234a08 mov r3, #4096
 *   @0x234a0c b 0x234434 <ogg_page_checksum_set+0xe0>
 *
 * ══ §533/1245 ogg_stream_flush_fill  0x234a10  size 12  3 条（0x234a10..0x234a1c）
 * @func 0x234a10 0x234a1c  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x234a10 mov r3, r2
 *   @0x234a14 mov r2, #1
 *   @0x234a18 b 0x234434 <ogg_page_checksum_set+0xe0>
 *
 * ══ §534/1245 CPhysicsWorld::DeleteParticle(int)  0x23999c  size 12  3 条（0x23999c..0x2399a8）
 * @func 0x23999c 0x2399a8  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23999c ldr r0, [r0, #0x10]
 *   @0x2399a0 mov r2, #0
 *   @0x2399a4 b 0x2cb4cc <_ZN7b2World15DestroyParticleEib>
 *
 * ══ §535/1245 JS_Function_prototype_Call(RValue&, CInstance*, CInstance*, int, RValue*)  0x23c6d0  size 12  3 条（0x23c6d0..0x23c6dc）
 * @func 0x23c6d0 0x23c6ec  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c6d0 mov r3, #5
 *   @0x23c6d4 str r3, [r0, #0xc]
 *   @0x23c6d8 bx lr
 *
 * ══ §536/1245 myispos(double)  0x243674  size 12  3 条（0x243674..0x243680）
 * @func 0x243674 0x243680  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x243674 mvn r0, r1
 *   @0x243678 lsr r0, r0, #31
 *   @0x24367c bx lr
 *
 * ══ §537/1245 JS_DefineOwnPropertyRV(YYObjectBase*, RValue*, RValue*, bool)  0x248610  size 12  3 条（0x248610..0x24861c）
 * @func 0x248610 0x24861c  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x248610 ldr r1, [r1]
 *   @0x248614 ldr r1, [r1]
 *   @0x248618 b 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb>
 *
 * ══ §538/1245 CThread::WaitForExit()  0x27e108  size 12  3 条（0x27e108..0x27e114）
 * @func 0x27e108 0x27e114  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e108 ldr r0, [r0]
 *   @0x27e10c mov r1, #0
 *   @0x27e110 b 0xb6ce8 <pthread_join@plt>
 *
 * ══ §539/1245 array_list_add  0x27e2d4  size 12  3 条（0x27e2d4..0x27e2e0）
 * @func 0x27e2d4 0x27e2f0  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e2d4 mov r2, r1
 *   @0x27e2d8 ldr r1, [r0, #0x4]
 *   @0x27e2dc b 0x27e218 <array_list_put_idx>
 *
 * ══ §540/1245 F_NETWORK_Create_Server(RValue&, CInstance*, CInstance*, int, RValue*)  0x29922c  size 12  3 条（0x29922c..0x299238）
 * @func 0x29922c 0x299244  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29922c ldr r1, [sp]
 *   @0x299230 mov r2, #0
 *   @0x299234 b 0x298fd0 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x13c>
 *
 * ══ §541/1245 F_NETWORK_Create_Server_Raw(RValue&, CInstance*, CInstance*, int, RValue*)  0x299238  size 12  3 条（0x299238..0x299244）
 * @func 0x299238 0x299244  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x299238 ldr r1, [sp]
 *   @0x29923c mov r2, #1
 *   @0x299240 b 0x298fd0 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x13c>
 *
 * ══ §542/1245 DbgServer::GetBufferSize()  0x29d06c  size 12  3 条（0x29d06c..0x29d078）
 * @func 0x29d06c 0x29d078  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29d06c ldr r3, [r0]
 *   @0x29d070 ldr r0, [r3, #0x10]
 *   @0x29d074 bx lr
 *
 * ══ §543/1245 DbgSocket::GetUserData()  0x29d9b0  size 12  3 条（0x29d9b0..0x29d9bc）
 * @func 0x29d9b0 0x29d9bc  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29d9b0 ldr r3, [r0]
 *   @0x29d9b4 ldr r0, [r3, #0x4c]
 *   @0x29d9b8 bx lr
 *
 * ══ §544/1245 CProfiler::CProfiler()  0x2a00a4  size 12  3 条（0x2a00a4..0x2a00b0）
 * @func 0x2a00a4 0x2a00b0  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a00a4 mov r2, #0
 *   @0x2a00a8 strb r2, [r0, #0x10]
 *   @0x2a00ac bx lr
 *
 * ══ §545/1245 zip_get_num_files  0x2a490e  size 12  3 条（0x2a490e..0x2a491a）
 * @func 0x2a490e 0x2a491a  size 12  3 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a490e cbz r0, 0x2a4914 <zip_get_num_files+0x6>
 *   @0x2a4912 bx lr
 *   @0x2a4916 .word 0x477030ff
 *
 * ══ §546/1245 png_get_copyright  0x2a5fb4  size 12  3 条（0x2a5fb4..0x2a5fc0）
 * @func 0x2a5fb4 0x2a5fd0  size 28  7 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5fb4 ldr r0, [pc, #0x4]
 *   @0x2a5fb8 bx lr
 *   @0x2a5fbc str r0, [r6, #0x2c]
 *
 * ══ §547/1245 png_get_libpng_ver  0x2a5fc0  size 12  3 条（0x2a5fc0..0x2a5fcc）
 * @func 0x2a5fc0 0x2a5fdc  size 28  7 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5fc0 ldr r0, [pc, #0x4]
 *   @0x2a5fc4 bx lr
 *   @0x2a5fc8 str r6, [r5, #0x38]
 *
 * ══ §548/1245 png_get_header_ver  0x2a5fcc  size 12  3 条（0x2a5fcc..0x2a5fd8）
 * @func 0x2a5fcc 0x2a5fe4  size 24  6 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5fcc ldr r0, [pc, #0x4]
 *   @0x2a5fd0 bx lr
 *   @0x2a5fd4 str r2, [r4, #0x38]
 *
 * ══ §549/1245 png_get_header_version  0x2a5fd8  size 12  3 条（0x2a5fd8..0x2a5fe4）
 * @func 0x2a5fd8 0x2a5fe4  size 12  3 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5fd8 ldr r0, [pc, #0x4]
 *   @0x2a5fdc bx lr
 *   @0x2a5fe0 str r5, [r3, #0x38]
 *
 * ══ §550/1245 png_get_rowbytes  0x2a6574  size 12  3 条（0x2a6574..0x2a6580）
 * @func 0x2a6574 0x2a6590  size 28  7 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6574 cbz r0, 0x2a657e <png_get_rowbytes+0xa>
 *   @0x2a6578 ldr r0, [r1, #0xc]
 *   @0x2a657c mov r0, r1
 *
 * ══ §551/1245 png_get_image_width  0x2a658e  size 12  3 条（0x2a658e..0x2a659a）
 * @func 0x2a658e 0x2a65aa  size 28  7 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a658e cbz r0, 0x2a6598 <png_get_image_width+0xa>
 *   @0x2a6592 ldr r0, [r1]
 *   @0x2a6596 mov r0, r1
 *
 * ══ §552/1245 png_get_image_height  0x2a659a  size 12  3 条（0x2a659a..0x2a65a6）
 * @func 0x2a659a 0x2a65b6  size 28  7 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a659a cbz r0, 0x2a65a4 <png_get_image_height+0xa>
 *   @0x2a659e ldr r0, [r1, #0x4]
 *   @0x2a65a2 mov r0, r1
 *
 * ══ §553/1245 png_get_bit_depth  0x2a65a6  size 12  3 条（0x2a65a6..0x2a65b2）
 * @func 0x2a65a6 0x2a65c2  size 28  7 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a65a6 cbz r0, 0x2a65b0 <png_get_bit_depth+0xa>
 *   @0x2a65aa ldrb r0, [r1, #0x18]
 *   @0x2a65ae mov r0, r1
 *
 * ══ §554/1245 png_get_color_type  0x2a65b2  size 12  3 条（0x2a65b2..0x2a65be）
 * @func 0x2a65b2 0x2a65ce  size 28  7 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x19×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a65b2 cbz r0, 0x2a65bc <png_get_color_type+0xa>
 *   @0x2a65b6 ldrb r0, [r1, #0x19]
 *   @0x2a65ba mov r0, r1
 *
 * ══ §555/1245 png_get_filter_type  0x2a65be  size 12  3 条（0x2a65be..0x2a65ca）
 * @func 0x2a65be 0x2a65da  size 28  7 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1b×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a65be cbz r0, 0x2a65c8 <png_get_filter_type+0xa>
 *   @0x2a65c2 ldrb r0, [r1, #0x1b]
 *   @0x2a65c6 mov r0, r1
 *
 * ══ §556/1245 png_get_interlace_type  0x2a65ca  size 12  3 条（0x2a65ca..0x2a65d6）
 * @func 0x2a65ca 0x2a65e2  size 24  6 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a65ca cbz r0, 0x2a65d4 <png_get_interlace_type+0xa>
 *   @0x2a65ce ldrb r0, [r1, #0x1c]
 *   @0x2a65d2 mov r0, r1
 *
 * ══ §557/1245 png_get_compression_type  0x2a65d6  size 12  3 条（0x2a65d6..0x2a65e2）
 * @func 0x2a65d6 0x2a65e2  size 12  3 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1a×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a65d6 cbz r0, 0x2a65e0 <png_get_compression_type+0xa>
 *   @0x2a65da ldrb r0, [r1, #0x1a]
 *   @0x2a65de mov r0, r1
 *
 * ══ §558/1245 png_get_channels  0x2a66fc  size 12  3 条（0x2a66fc..0x2a6708）
 * @func 0x2a66fc 0x2a6718  size 28  7 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1d×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a66fc cbz r0, 0x2a6706 <png_get_channels+0xa>
 *   @0x2a6700 ldrb r0, [r1, #0x1d]
 *   @0x2a6704 mov r0, r1
 *
 * ══ §559/1245 png_free_default  0x2a6cf0  size 12  3 条（0x2a6cf0..0x2a6cfc）
 * @func 0x2a6cf0 0x2a6cfc  size 12  3 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6cf0 cbz r0, 0x2a6cfa <png_free_default+0xa>
 *   @0x2a6cf4 mov r0, r1
 *   @0x2a6cf8 ldrbmi r11, [r0, -r1, ror #29]!
 *
 * ══ §560/1245 png_set_read_user_chunk_fn  0x2af520  size 12  3 条（0x2af520..0x2af52c）
 * @func 0x2af520 0x2af52c  size 12  3 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af520 cbz r0, 0x2af52a <png_set_read_user_chunk_fn+0xa>
 *   @0x2af524 .word 0xf8c022c8
 *   @0x2af528 ldrbmi r1, [r0, -r4, asr #5]!
 *
 * ══ §561/1245 png_set_user_limits  0x2af594  size 12  3 条（0x2af594..0x2af5a0）
 * @func 0x2af594 0x2af5b0  size 28  7 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af594 cbz r0, 0x2af59e <png_set_user_limits+0xa>
 *   @0x2af598 .word 0xf8c01308
 *   @0x2af59c ldrbmi r2, [r0, -r12, lsl #6]!
 *
 * ══ §562/1245 png_default_flush  0x2afbe4  size 12  3 条（0x2afbe4..0x2afbf0）
 * @func 0x2afbe4 0x2afbf0  size 12  3 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2afbe4 cbz r0, 0x2afbee <png_default_flush+0xa>
 *   @0x2afbe8 .word 0xf06b0118
 *   @0x2afbec .word 0x4770bf97
 *
 * ══ §563/1245 png_flush  0x2afc0c  size 12  3 条（0x2afc0c..0x2afc18）
 * @func 0x2afc0c 0x2afc18  size 12  3 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2afc0c push {r3, lr}
 *   @0x2afc10 .word 0xb1033210
 *   @0x2afc14 blx r3
 *
 * ══ §564/1245 png_set_flush  0x2b0546  size 12  3 条（0x2b0546..0x2b0552）
 * @func 0x2b0546 0x2b0552  size 12  3 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b0546 cbz r0, 0x2b0550 <png_set_flush+0xa>
 *   @0x2b054a .word 0xf8c071e1
 *   @0x2b054e .word 0x47701214
 *
 * ══ §565/1245 jzero_far  0x2bc868  size 12  3 条（0x2bc868..0x2bc874）
 * @func 0x2bc868 0x2bc874  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2bc868 mov r2, r1
 *   @0x2bc86c mov r1, #0
 *   @0x2bc870 b 0xb65b0 <memset@plt>
 *
 * ══ §566/1245 jpeg_mem_init  0x2c142c  size 12  3 条（0x2c142c..0x2c1438）
 * @func 0x2c142c 0x2c143c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c142c movw r0, #0x4240
 *   @0x2c1430 movt r0, #0xf
 *   @0x2c1434 bx lr
 *
 * ══ §567/1245 b2ChainShape::GetChildCount() const  0x2c4868  size 12  3 条（0x2c4868..0x2c4874）
 * @func 0x2c4868 0x2c487c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c4868 ldr r0, [r0, #0x10]
 *   @0x2c486c sub r0, r0, #1
 *   @0x2c4870 bx lr
 *
 * ══ §568/1245 b2Log(char const*, ...)  0x2c6a74  size 12  3 条（0x2c6a74..0x2c6a80）
 * @func 0x2c6a74 0x2c6a80  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c6a74 push {r0, r1, r2, r3}
 *   @0x2c6a78 add sp, sp, #16
 *   @0x2c6a7c bx lr
 *
 * ══ §569/1245 b2World::GetTreeHeight() const  0x2cb114  size 12  3 条（0x2cb114..0x2cb120）
 * @func 0x2cb114 0x2cb130  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb114 add r0, r0, #102400
 *   @0x2cb118 add r0, r0, #472
 *   @0x2cb11c b 0x2df778 <_ZNK13b2DynamicTree9GetHeightEv>
 *
 * ══ §570/1245 b2World::GetTreeBalance() const  0x2cb120  size 12  3 条（0x2cb120..0x2cb12c）
 * @func 0x2cb120 0x2cb138  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb120 add r0, r0, #102400
 *   @0x2cb124 add r0, r0, #472
 *   @0x2cb128 b 0x2df980 <_ZNK13b2DynamicTree13GetMaxBalanceEv>
 *
 * ══ §571/1245 b2World::GetTreeQuality() const  0x2cb12c  size 12  3 条（0x2cb12c..0x2cb138）
 * @func 0x2cb12c 0x2cb138  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb12c add r0, r0, #102400
 *   @0x2cb130 add r0, r0, #472
 *   @0x2cb134 b 0x2df798 <_ZNK13b2DynamicTree12GetAreaRatioEv>
 *
 * ══ §572/1245 b2World::GetParticleMaxCount() const  0x2cb42c  size 12  3 条（0x2cb42c..0x2cb438）
 * @func 0x2cb42c 0x2cb448  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb42c add r0, r0, #102400
 *   @0x2cb430 add r0, r0, #628
 *   @0x2cb434 b 0x2d98f4 <_ZNK16b2ParticleSystem19GetParticleMaxCountEv>
 *
 * ══ §573/1245 b2World::SetParticleMaxCount(int)  0x2cb438  size 12  3 条（0x2cb438..0x2cb444）
 * @func 0x2cb438 0x2cb454  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb438 add r0, r0, #102400
 *   @0x2cb43c add r0, r0, #628
 *   @0x2cb440 b 0x2d98fc <_ZN16b2ParticleSystem19SetParticleMaxCountEi>
 *
 * ══ §574/1245 b2World::SetParticleDensity(float)  0x2cb444  size 12  3 条（0x2cb444..0x2cb450）
 * @func 0x2cb444 0x2cb460  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb444 add r0, r0, #102400
 *   @0x2cb448 add r0, r0, #628
 *   @0x2cb44c b 0x2d8294 <_ZN16b2ParticleSystem18SetParticleDensityEf>
 *
 * ══ §575/1245 b2World::GetParticleDensity() const  0x2cb450  size 12  3 条（0x2cb450..0x2cb45c）
 * @func 0x2cb450 0x2cb46c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb450 add r0, r0, #102400
 *   @0x2cb454 add r0, r0, #628
 *   @0x2cb458 b 0x2d82ac <_ZNK16b2ParticleSystem18GetParticleDensityEv>
 *
 * ══ §576/1245 b2World::SetParticleGravityScale(float)  0x2cb45c  size 12  3 条（0x2cb45c..0x2cb468）
 * @func 0x2cb45c 0x2cb478  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb45c add r0, r0, #102400
 *   @0x2cb460 add r0, r0, #628
 *   @0x2cb464 b 0x2d82b4 <_ZN16b2ParticleSystem23SetParticleGravityScaleEf>
 *
 * ══ §577/1245 b2World::GetParticleGravityScale() const  0x2cb468  size 12  3 条（0x2cb468..0x2cb474）
 * @func 0x2cb468 0x2cb484  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb468 add r0, r0, #102400
 *   @0x2cb46c add r0, r0, #628
 *   @0x2cb470 b 0x2d82bc <_ZNK16b2ParticleSystem23GetParticleGravityScaleEv>
 *
 * ══ §578/1245 b2World::SetParticleDamping(float)  0x2cb474  size 12  3 条（0x2cb474..0x2cb480）
 * @func 0x2cb474 0x2cb490  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb474 add r0, r0, #102400
 *   @0x2cb478 add r0, r0, #628
 *   @0x2cb47c b 0x2d82c4 <_ZN16b2ParticleSystem18SetParticleDampingEf>
 *
 * ══ §579/1245 b2World::GetParticleDamping() const  0x2cb480  size 12  3 条（0x2cb480..0x2cb48c）
 * @func 0x2cb480 0x2cb49c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb480 add r0, r0, #102400
 *   @0x2cb484 add r0, r0, #628
 *   @0x2cb488 b 0x2d82cc <_ZNK16b2ParticleSystem18GetParticleDampingEv>
 *
 * ══ §580/1245 b2World::SetParticleRadius(float)  0x2cb48c  size 12  3 条（0x2cb48c..0x2cb498）
 * @func 0x2cb48c 0x2cb4a4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb48c add r0, r0, #102400
 *   @0x2cb490 add r0, r0, #628
 *   @0x2cb494 b 0x2d8270 <_ZN16b2ParticleSystem17SetParticleRadiusEf>
 *
 * ══ §581/1245 b2World::GetParticleRadius() const  0x2cb498  size 12  3 条（0x2cb498..0x2cb4a4）
 * @func 0x2cb498 0x2cb4a4  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb498 add r0, r0, #102400
 *   @0x2cb49c add r0, r0, #628
 *   @0x2cb4a0 b 0x2d82d4 <_ZNK16b2ParticleSystem17GetParticleRadiusEv>
 *
 * ══ §582/1245 b2World::DestroyParticle(int, bool)  0x2cb4cc  size 12  3 条（0x2cb4cc..0x2cb4d8）
 * @func 0x2cb4cc 0x2cb4d8  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb4cc add r0, r0, #102400
 *   @0x2cb4d0 add r0, r0, #628
 *   @0x2cb4d4 b 0x2d51c0 <_ZN16b2ParticleSystem15DestroyParticleEib>
 *
 * ══ §583/1245 b2World::GetParticleFlagsBuffer()  0x2cb568  size 12  3 条（0x2cb568..0x2cb574）
 * @func 0x2cb568 0x2cb584  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb568 add r0, r0, #102400
 *   @0x2cb56c add r0, r0, #628
 *   @0x2cb570 b 0x2d9864 <_ZN16b2ParticleSystem22GetParticleFlagsBufferEv>
 *
 * ══ §584/1245 b2World::GetParticlePositionBuffer()  0x2cb574  size 12  3 条（0x2cb574..0x2cb580）
 * @func 0x2cb574 0x2cb590  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb574 add r0, r0, #102400
 *   @0x2cb578 add r0, r0, #628
 *   @0x2cb57c b 0x2d986c <_ZN16b2ParticleSystem25GetParticlePositionBufferEv>
 *
 * ══ §585/1245 b2World::GetParticleVelocityBuffer()  0x2cb580  size 12  3 条（0x2cb580..0x2cb58c）
 * @func 0x2cb580 0x2cb59c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb580 add r0, r0, #102400
 *   @0x2cb584 add r0, r0, #628
 *   @0x2cb588 b 0x2d9874 <_ZN16b2ParticleSystem25GetParticleVelocityBufferEv>
 *
 * ══ §586/1245 b2World::GetParticleColorBuffer()  0x2cb58c  size 12  3 条（0x2cb58c..0x2cb598）
 * @func 0x2cb58c 0x2cb5a8  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb58c add r0, r0, #102400
 *   @0x2cb590 add r0, r0, #628
 *   @0x2cb594 b 0x2d987c <_ZN16b2ParticleSystem22GetParticleColorBufferEv>
 *
 * ══ §587/1245 b2World::GetParticleUserDataBuffer()  0x2cb598  size 12  3 条（0x2cb598..0x2cb5a4）
 * @func 0x2cb598 0x2cb5b4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb598 add r0, r0, #102400
 *   @0x2cb59c add r0, r0, #628
 *   @0x2cb5a0 b 0x2d98ac <_ZN16b2ParticleSystem25GetParticleUserDataBufferEv>
 *
 * ══ §588/1245 b2World::GetParticleFlagsBuffer() const  0x2cb5a4  size 12  3 条（0x2cb5a4..0x2cb5b0）
 * @func 0x2cb5a4 0x2cb5c0  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb5a4 add r0, r0, #102400
 *   @0x2cb5a8 add r0, r0, #628
 *   @0x2cb5ac b 0x2d9904 <_ZNK16b2ParticleSystem22GetParticleFlagsBufferEv>
 *
 * ══ §589/1245 b2World::GetParticlePositionBuffer() const  0x2cb5b0  size 12  3 条（0x2cb5b0..0x2cb5bc）
 * @func 0x2cb5b0 0x2cb5cc  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb5b0 add r0, r0, #102400
 *   @0x2cb5b4 add r0, r0, #628
 *   @0x2cb5b8 b 0x2d990c <_ZNK16b2ParticleSystem25GetParticlePositionBufferEv>
 *
 * ══ §590/1245 b2World::GetParticleVelocityBuffer() const  0x2cb5bc  size 12  3 条（0x2cb5bc..0x2cb5c8）
 * @func 0x2cb5bc 0x2cb5d8  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb5bc add r0, r0, #102400
 *   @0x2cb5c0 add r0, r0, #628
 *   @0x2cb5c4 b 0x2d9914 <_ZNK16b2ParticleSystem25GetParticleVelocityBufferEv>
 *
 * ══ §591/1245 b2World::GetParticleColorBuffer() const  0x2cb5c8  size 12  3 条（0x2cb5c8..0x2cb5d4）
 * @func 0x2cb5c8 0x2cb5e4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb5c8 add r0, r0, #102400
 *   @0x2cb5cc add r0, r0, #628
 *   @0x2cb5d0 b 0x2d991c <_ZNK16b2ParticleSystem22GetParticleColorBufferEv>
 *
 * ══ §592/1245 b2World::GetParticleGroupBuffer() const  0x2cb5d4  size 12  3 条（0x2cb5d4..0x2cb5e0）
 * @func 0x2cb5d4 0x2cb5f0  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb5d4 add r0, r0, #102400
 *   @0x2cb5d8 add r0, r0, #628
 *   @0x2cb5dc b 0x2d9920 <_ZNK16b2ParticleSystem22GetParticleGroupBufferEv>
 *
 * ══ §593/1245 b2World::GetParticleUserDataBuffer() const  0x2cb5e0  size 12  3 条（0x2cb5e0..0x2cb5ec）
 * @func 0x2cb5e0 0x2cb5fc  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb5e0 add r0, r0, #102400
 *   @0x2cb5e4 add r0, r0, #628
 *   @0x2cb5e8 b 0x2d9928 <_ZNK16b2ParticleSystem25GetParticleUserDataBufferEv>
 *
 * ══ §594/1245 b2World::SetParticleFlagsBuffer(unsigned int*, int)  0x2cb5ec  size 12  3 条（0x2cb5ec..0x2cb5f8）
 * @func 0x2cb5ec 0x2cb608  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb5ec add r0, r0, #102400
 *   @0x2cb5f0 add r0, r0, #628
 *   @0x2cb5f4 b 0x2d992c <_ZN16b2ParticleSystem22SetParticleFlagsBufferEPji>
 *
 * ══ §595/1245 b2World::SetParticlePositionBuffer(b2Vec2*, int)  0x2cb5f8  size 12  3 条（0x2cb5f8..0x2cb604）
 * @func 0x2cb5f8 0x2cb614  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb5f8 add r0, r0, #102400
 *   @0x2cb5fc add r0, r0, #628
 *   @0x2cb600 b 0x2d9968 <_ZN16b2ParticleSystem25SetParticlePositionBufferEP6b2Vec2i>
 *
 * ══ §596/1245 b2World::SetParticleVelocityBuffer(b2Vec2*, int)  0x2cb604  size 12  3 条（0x2cb604..0x2cb610）
 * @func 0x2cb604 0x2cb620  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb604 add r0, r0, #102400
 *   @0x2cb608 add r0, r0, #628
 *   @0x2cb60c b 0x2d99a4 <_ZN16b2ParticleSystem25SetParticleVelocityBufferEP6b2Vec2i>
 *
 * ══ §597/1245 b2World::SetParticleColorBuffer(b2ParticleColor*, int)  0x2cb610  size 12  3 条（0x2cb610..0x2cb61c）
 * @func 0x2cb610 0x2cb62c  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb610 add r0, r0, #102400
 *   @0x2cb614 add r0, r0, #628
 *   @0x2cb618 b 0x2d99e0 <_ZN16b2ParticleSystem22SetParticleColorBufferEP15b2ParticleColori>
 *
 * ══ §598/1245 b2World::GetParticleGroupBuffer()  0x2cb61c  size 12  3 条（0x2cb61c..0x2cb628）
 * @func 0x2cb61c 0x2cb638  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb61c add r0, r0, #102400
 *   @0x2cb620 add r0, r0, #628
 *   @0x2cb624 b 0x2d9a1c <_ZN16b2ParticleSystem22GetParticleGroupBufferEv>
 *
 * ══ §599/1245 b2World::SetParticleUserDataBuffer(void**, int)  0x2cb628  size 12  3 条（0x2cb628..0x2cb634）
 * @func 0x2cb628 0x2cb644  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb628 add r0, r0, #102400
 *   @0x2cb62c add r0, r0, #628
 *   @0x2cb630 b 0x2d9a24 <_ZN16b2ParticleSystem25SetParticleUserDataBufferEPPvi>
 *
 * ══ §600/1245 b2World::ComputeParticleCollisionEnergy() const  0x2cb674  size 12  3 条（0x2cb674..0x2cb680）
 * @func 0x2cb674 0x2cb680  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cb674 add r0, r0, #102400
 *   @0x2cb678 add r0, r0, #628
 *   @0x2cb67c b 0x2d9fe8 <_ZNK16b2ParticleSystem30ComputeParticleCollisionEnergyEv>
 *
 * ══ §601/1245 FT_CeilFix  0x2e4d2a  size 12  3 条（0x2e4d2a..0x2e4d36）
 * @func 0x2e4d2a 0x2e4d3e  size 20  5 条
 * 部分覆盖: 本节 4/7 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e4d2a add.w r0, r0, #0xff00
 *   @0x2e4d2e adds r0, #0xff
 *   @0x2e4d32 lsls r0, r0, #0x10
 *
 * ══ §602/1245 ft_validator_error  0x2e5392  size 12  3 条（0x2e5392..0x2e539e）
 * @func 0x2e5392 0x2e539e  size 12  3 条
 * 部分覆盖: 本节 3/4 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6f7c
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5392 str.w r1, [r0, #0x10c]
 *   @0x2e5396 movs r1, #0x1
 *   @0x2e539a blx 0xb6f7c <longjmp@plt>
 *
 * ══ §603/1245 FT_Stream_Close  0x2e689a  size 12  3 条（0x2e689a..0x2e68a6）
 * @func 0x2e689a 0x2e68a6  size 12  3 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e689a push {r3, lr}
 *   @0x2e689e ldr r3, [r0, #0x18]
 *   @0x2e68a2 blx r3
 *
 * ══ §604/1245 FT_Outline_Done  0x2e7dfe  size 12  3 条（0x2e7dfe..0x2e7e0a）
 * @func 0x2e7dfe 0x2e7e1a  size 28  7 条
 * 部分覆盖: 本节 4/7 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e7dfe cbz r0, 0x2e7e06 <FT_Outline_Done+0x8>
 *   @0x2e7e02 b.w 0x2e7dba <FT_Outline_Done_Internal>
 *   @0x2e7e06 movs r0, #0x21
 *
 * ══ §605/1245 FT_Outline_New  0x2e84a6  size 12  3 条（0x2e84a6..0x2e84b2）
 * @func 0x2e84a6 0x2e84b2  size 12  3 条
 * 部分覆盖: 本节 3/5 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e84a6 cbz r0, 0x2e84ae <FT_Outline_New+0x8>
 *   @0x2e84aa b.w 0x2e840a <FT_Outline_New_Internal>
 *   @0x2e84ae movs r0, #0x21
 *
 * ══ §606/1245 _zip_error_copy(zip_error*, zip_error*)  0x2a4314  size 10  3 条（0x2a4314..0x2a431e）
 * @func 0x2a4314 0x2a432e  size 26  7 条
 * 部分覆盖: 本节 4/7 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a4314 ldr r3, [r1]
 *   @0x2a4318 ldr r3, [r1, #0x4]
 *   @0x2a431c bx lr
 *
 * ══ §607/1245 _zip_error_init(zip_error*)  0x2a434e  size 10  3 条（0x2a434e..0x2a4358）
 * @func 0x2a434e 0x2a4360  size 18  5 条
 * 部分覆盖: 本节 4/7 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a434e movs r3, #0x0
 *   @0x2a4352 str r3, [r0, #0x4]
 *   @0x2a4356 bx lr
 *
 * ══ §608/1245 ft_mem_free  0x2e7336  size 10  3 条（0x2e7336..0x2e7340）
 * @func 0x2e7336 0x2e7342  size 12  3 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e7336 push {r3, lr}
 *   @0x2e733a ldr r3, [r0, #0x8]
 *   @0x2e733e pop {r3, pc}
 *
 * ══ §609/1245 CBackground::GetPreload()  0xc2d98  size 8  2 条（0xc2d98..0xc2da0）
 * @func 0xc2d98 0xc2da0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xa×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc2d98 ldrb r0, [r0, #0xa]
 *   @0xc2d9c bx lr
 *
 * ══ §610/1245 ASYNCFunc_BackgroundCleanup(HTTP_REQ_CONTEXT*)  0xc302c  size 8  2 条（0xc302c..0xc3034）
 * @func 0xc302c 0xc3034  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc302c ldr r0, [r0, #0x1c]
 *   @0xc3030 b 0x27d1d0 <_ZdlPv>
 *
 * ══ §611/1245 DummyConsole::Create(wchar_t const*, bool)  0xc4388  size 8  2 条（0xc4388..0xc4390）
 * @func 0xc4388 0xc4390  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4388 mov r0, #1
 *   @0xc438c bx lr
 *
 * ══ §612/1245 TConsole::Create(wchar_t const*, bool)  0xc4814  size 8  2 条（0xc4814..0xc481c）
 * @func 0xc4814 0xc481c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4814 mov r0, #1
 *   @0xc4818 bx lr
 *
 * ══ §613/1245 CCode::GetText()  0xcf470  size 8  2 条（0xcf470..0xcf478）
 * @func 0xcf470 0xcf478  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcf470 ldr r0, [r0, #0x10]
 *   @0xcf474 bx lr
 *
 * ══ §614/1245 TErrStreamConsole::Create(wchar_t const*, bool)  0xd323c  size 8  2 条（0xd323c..0xd3244）
 * @func 0xd323c 0xd3244  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd323c mov r0, #1
 *   @0xd3240 bx lr
 *
 * ══ §615/1245 CBucket<32768u, 1048576u, false>::GetSize()  0xd341c  size 8  2 条（0xd341c..0xd3424）
 * @func 0xd341c 0xd3424  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd341c mov r0, #32768
 *   @0xd3420 bx lr
 *
 * ══ §616/1245 InitDPlay()  0xf2bac  size 8  2 条（0xf2bac..0xf2bb4）
 * @func 0xf2bac 0xf2bc4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2bac mov r0, #0
 *   @0xf2bb0 bx lr
 *
 * ══ §617/1245 DPlay_Init_IPX()  0xf2bb4  size 8  2 条（0xf2bb4..0xf2bbc）
 * @func 0xf2bb4 0xf2bcc  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2bb4 mov r0, #0
 *   @0xf2bb8 bx lr
 *
 * ══ §618/1245 DPlay_Init_TCPIP(char const*)  0xf2bbc  size 8  2 条（0xf2bbc..0xf2bc4）
 * @func 0xf2bbc 0xf2bd4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2bbc mov r0, #0
 *   @0xf2bc0 bx lr
 *
 * ══ §619/1245 DPlay_Init_Modem(char const*, char const*)  0xf2bc4  size 8  2 条（0xf2bc4..0xf2bcc）
 * @func 0xf2bc4 0xf2bdc  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2bc4 mov r0, #0
 *   @0xf2bc8 bx lr
 *
 * ══ §620/1245 DPlay_Init_Serial(int, int, int, int, int)  0xf2bcc  size 8  2 条（0xf2bcc..0xf2bd4）
 * @func 0xf2bcc 0xf2be4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2bcc mov r0, #0
 *   @0xf2bd0 bx lr
 *
 * ══ §621/1245 DPlay_Session_Create(char const*, int, char const*)  0xf2bec  size 8  2 条（0xf2bec..0xf2bf4）
 * @func 0xf2bec 0xf2c04  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2bec mov r0, #0
 *   @0xf2bf0 bx lr
 *
 * ══ §622/1245 DPlay_Session_Find()  0xf2bf8  size 8  2 条（0xf2bf8..0xf2c00）
 * @func 0xf2bf8 0xf2c10  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2bf8 mov r0, #0
 *   @0xf2bfc bx lr
 *
 * ══ §623/1245 DPlay_Session_Name(int)  0xf2c00  size 8  2 条（0xf2c00..0xf2c08）
 * @func 0xf2c00 0xf2c18  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2c00 mov r0, #0
 *   @0xf2c04 bx lr
 *
 * ══ §624/1245 DPlay_Session_Join(int, char const*)  0xf2c08  size 8  2 条（0xf2c08..0xf2c10）
 * @func 0xf2c08 0xf2c20  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2c08 mov r0, #0
 *   @0xf2c0c bx lr
 *
 * ══ §625/1245 DPlay_Player_Find()  0xf2c10  size 8  2 条（0xf2c10..0xf2c18）
 * @func 0xf2c10 0xf2c28  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2c10 mov r0, #0
 *   @0xf2c14 bx lr
 *
 * ══ §626/1245 DPlay_Player_Name(int)  0xf2c18  size 8  2 条（0xf2c18..0xf2c20）
 * @func 0xf2c18 0xf2c30  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2c18 mov r0, #0
 *   @0xf2c1c bx lr
 *
 * ══ §627/1245 DPlay_Player_Id(int)  0xf2c20  size 8  2 条（0xf2c20..0xf2c28）
 * @func 0xf2c20 0xf2c38  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2c20 mov r0, #0
 *   @0xf2c24 bx lr
 *
 * ══ §628/1245 DPlay_Data_Write(int, RValue*)  0xf2c28  size 8  2 条（0xf2c28..0xf2c30）
 * @func 0xf2c28 0xf2c40  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2c28 mov r0, #0
 *   @0xf2c2c bx lr
 *
 * ══ §629/1245 DPlay_Message_Send(unsigned int, int, RValue*)  0xf2c38  size 8  2 条（0xf2c38..0xf2c40）
 * @func 0xf2c38 0xf2c50  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2c38 mov r0, #0
 *   @0xf2c3c bx lr
 *
 * ══ §630/1245 DPlay_Message_Send_Guaranteed(int, int, RValue*)  0xf2c40  size 8  2 条（0xf2c40..0xf2c48）
 * @func 0xf2c40 0xf2c58  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2c40 mov r0, #0
 *   @0xf2c44 bx lr
 *
 * ══ §631/1245 DPlay_Message_Send_Name(char const*, int, RValue*)  0xf2c48  size 8  2 条（0xf2c48..0xf2c50）
 * @func 0xf2c48 0xf2c60  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2c48 mov r0, #0
 *   @0xf2c4c bx lr
 *
 * ══ §632/1245 DPlay_Message_Send_Name_Guaranteed(char const*, int, RValue*)  0xf2c50  size 8  2 条（0xf2c50..0xf2c58）
 * @func 0xf2c50 0xf2c68  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2c50 mov r0, #0
 *   @0xf2c54 bx lr
 *
 * ══ §633/1245 DPlay_Message_Receive(int)  0xf2c58  size 8  2 条（0xf2c58..0xf2c60）
 * @func 0xf2c58 0xf2c70  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2c58 mov r0, #0
 *   @0xf2c5c bx lr
 *
 * ══ §634/1245 DPlay_Message_Receive_Name(char const*)  0xf2c60  size 8  2 条（0xf2c60..0xf2c68）
 * @func 0xf2c60 0xf2c78  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2c60 mov r0, #0
 *   @0xf2c64 bx lr
 *
 * ══ §635/1245 DPlay_Message_Id()  0xf2c68  size 8  2 条（0xf2c68..0xf2c70）
 * @func 0xf2c68 0xf2c80  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2c68 mov r0, #0
 *   @0xf2c6c bx lr
 *
 * ══ §636/1245 DPlay_Message_Player()  0xf2c74  size 8  2 条（0xf2c74..0xf2c7c）
 * @func 0xf2c74 0xf2c8c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2c74 mov r0, #0
 *   @0xf2c78 bx lr
 *
 * ══ §637/1245 DPlay_Message_Count(int)  0xf2c8c  size 8  2 条（0xf2c8c..0xf2c94）
 * @func 0xf2c8c 0xf2c9c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2c8c mov r0, #0
 *   @0xf2c90 bx lr
 *
 * ══ §638/1245 CExtensionFunction::GetName()  0xf4bb0  size 8  2 条（0xf4bb0..0xf4bb8）
 * @func 0xf4bb0 0xf4bb8  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4bb0 ldr r0, [r0, #0x4]
 *   @0xf4bb4 bx lr
 *
 * ══ §639/1245 CExtensionFunction::SetKind(int)  0xf4c20  size 8  2 条（0xf4c20..0xf4c28）
 * @func 0xf4c20 0xf4c28  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4c20 str r1, [r0, #0xc]
 *   @0xf4c24 bx lr
 *
 * ══ §640/1245 CExtensionFunction::SetId(int)  0xf4c30  size 8  2 条（0xf4c30..0xf4c38）
 * @func 0xf4c30 0xf4c38  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4c30 str r1, [r0, #0x10]
 *   @0xf4c34 bx lr
 *
 * ══ §641/1245 CExtensionFunction::SetArgCount(int)  0xf4c40  size 8  2 条（0xf4c40..0xf4c48）
 * @func 0xf4c40 0xf4c48  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4c40 str r1, [r0, #0x14]
 *   @0xf4c44 bx lr
 *
 * ══ §642/1245 CExtensionFunction::SetReturnType(int)  0xf4c50  size 8  2 条（0xf4c50..0xf4c58）
 * @func 0xf4c50 0xf4c60  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4c50 str r1, [r0, #0x58]
 *   @0xf4c54 bx lr
 *
 * ══ §643/1245 CExtensionFunction::GetScript()  0xf4c58  size 8  2 条（0xf4c58..0xf4c60）
 * @func 0xf4c58 0xf4c60  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4c58 ldr r0, [r0, #0x5c]
 *   @0xf4c5c bx lr
 *
 * ══ §644/1245 CExtensionFile::GetKind()  0xf4fe0  size 8  2 条（0xf4fe0..0xf4fe8）
 * @func 0xf4fe0 0xf4ff0  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4fe0 ldr r0, [r0, #0x8]
 *   @0xf4fe4 bx lr
 *
 * ══ §645/1245 CExtensionFile::SetKind(int)  0xf4fe8  size 8  2 条（0xf4fe8..0xf4ff0）
 * @func 0xf4fe8 0xf4ff0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf4fe8 str r1, [r0, #0x8]
 *   @0xf4fec bx lr
 *
 * ══ §646/1245 CExtensionFile::GetFunction_Final()  0xf5010  size 8  2 条（0xf5010..0xf5018）
 * @func 0xf5010 0xf5018  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5010 ldr r0, [r0, #0x10]
 *   @0xf5014 bx lr
 *
 * ══ §647/1245 CExtensionPackage::GetName()  0xf5594  size 8  2 条（0xf5594..0xf559c）
 * @func 0xf5594 0xf559c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5594 ldr r0, [r0, #0x4]
 *   @0xf5598 bx lr
 *
 * ══ §648/1245 CFontGM::TextHeight(unsigned short*)  0xf93a4  size 8  2 条（0xf93a4..0xf93ac）
 * @func 0xf93a4 0xf93ac  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf93a4 ldr r0, [r0, #0x2c]
 *   @0xf93a8 bx lr
 *
 * ══ §649/1245 CFontGM::GetName()  0xf93c8  size 8  2 条（0xf93c8..0xf93d0）
 * @func 0xf93c8 0xf93e0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf93c8 ldr r0, [r0, #0x4]
 *   @0xf93cc bx lr
 *
 * ══ §650/1245 CFontGM::GetSize()  0xf93d0  size 8  2 条（0xf93d0..0xf93d8）
 * @func 0xf93d0 0xf93e8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf93d0 ldr r0, [r0, #0x8]
 *   @0xf93d4 bx lr
 *
 * ══ §651/1245 CFontGM::GetBold()  0xf93d8  size 8  2 条（0xf93d8..0xf93e0）
 * @func 0xf93d8 0xf93f0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf93d8 ldrb r0, [r0, #0xc]
 *   @0xf93dc bx lr
 *
 * ══ §652/1245 CFontGM::GetItalic()  0xf93e0  size 8  2 条（0xf93e0..0xf93e8）
 * @func 0xf93e0 0xf93f8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xd×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf93e0 ldrb r0, [r0, #0xd]
 *   @0xf93e4 bx lr
 *
 * ══ §653/1245 CFontGM::GetFirst()  0xf93e8  size 8  2 条（0xf93e8..0xf93f0）
 * @func 0xf93e8 0xf93f8  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf93e8 ldr r0, [r0, #0x18]
 *   @0xf93ec bx lr
 *
 * ══ §654/1245 CFontGM::GetLast()  0xf93f0  size 8  2 条（0xf93f0..0xf93f8）
 * @func 0xf93f0 0xf93f8  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf93f0 ldr r0, [r0, #0x1c]
 *   @0xf93f4 bx lr
 *
 * ══ §655/1245 F_ShowDebugMessage(RValue&, CInstance*, CInstance*, int, RValue*)  0x1178b0  size 8  2 条（0x1178b0..0x1178b8）
 * @func 0x1178b0 0x1178b8  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1178b0 ldr r0, [sp]
 *   @0x1178b4 b 0x1176a8 <_Z24YYGML_show_debug_messageRK8YYRValue>
 *
 * ══ §656/1245 YYGML_window_set_caption(char const*)  0x120e9c  size 8  2 条（0x120e9c..0x120ea4）
 * @func 0x120e9c 0x120eb4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x120e9c mov r1, #0
 *   @0x120ea0 b 0x17ae38 <_Z21GR_Window_Set_CaptionPKcb>
 *
 * ══ §657/1245 F_ActionPreviousRoom(RValue&, CInstance*, CInstance*, int, RValue*)  0x13e6c0  size 8  2 条（0x13e6c0..0x13e6c8）
 * @func 0x13e6c0 0x13e6d0  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13e6c0 mov r0, #0
 *   @0x13e6c4 b 0x1c9e68 <_Z20Command_PreviousRoomi>
 *
 * ══ §658/1245 F_ActionNextRoom(RValue&, CInstance*, CInstance*, int, RValue*)  0x13e6c8  size 8  2 条（0x13e6c8..0x13e6d0）
 * @func 0x13e6c8 0x13e6d0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13e6c8 mov r0, #0
 *   @0x13e6cc b 0x1c9ed0 <_Z16Command_NextRoomi>
 *
 * ══ §659/1245 YYGML_action_next_room()  0x141c2c  size 8  2 条（0x141c2c..0x141c34）
 * @func 0x141c2c 0x141c34  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141c2c mov r0, #0
 *   @0x141c30 b 0x1c9ed0 <_Z16Command_NextRoomi>
 *
 * ══ §660/1245 F_ExtensionStubFuncString(RValue&, CInstance*, CInstance*, int, RValue*)  0x156be0  size 8  2 条（0x156be0..0x156be8）
 * @func 0x156be0 0x156be8  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156be0 mov r1, #0
 *   @0x156be4 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §661/1245 CheckAttrib(double)  0x160684  size 8  2 条（0x160684..0x16068c）
 * @func 0x160684 0x16068c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160684 mov r0, #1
 *   @0x160688 bx lr
 *
 * ══ §662/1245 YYGetFileAttributes(char const*, bool)  0x160ad8  size 8  2 条（0x160ad8..0x160ae0）
 * @func 0x160ad8 0x160ae8  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160ad8 mov r0, #0
 *   @0x160adc bx lr
 *
 * ══ §663/1245 YYGetOpenFileName(char*, char*, char*, char*)  0x160ec0  size 8  2 条（0x160ec0..0x160ec8）
 * @func 0x160ec0 0x160ed8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160ec0 mov r0, #0
 *   @0x160ec4 bx lr
 *
 * ══ §664/1245 YYGetSaveFileName(char*, char*, char*, char*)  0x160ec8  size 8  2 条（0x160ec8..0x160ed0）
 * @func 0x160ec8 0x160ee0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160ec8 mov r0, #0
 *   @0x160ecc bx lr
 *
 * ══ §665/1245 AreOnlineAchievementsAvailable()  0x160f44  size 8  2 条（0x160f44..0x160f4c）
 * @func 0x160f44 0x160f4c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160f44 mov r0, #1
 *   @0x160f48 bx lr
 *
 * ══ §666/1245 F_Steam_GetPersonalName(RValue&, CInstance*, CInstance*, int, RValue*)  0x162470  size 8  2 条（0x162470..0x162478）
 * @func 0x162470 0x162488  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162470 mov r1, #0
 *   @0x162474 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §667/1245 F_Steam_FileRead(RValue&, CInstance*, CInstance*, int, RValue*)  0x162478  size 8  2 条（0x162478..0x162480）
 * @func 0x162478 0x162490  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162478 mov r1, #0
 *   @0x16247c b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §668/1245 F_SteamCurrentGameLanguage(RValue&, CInstance*, CInstance*, int, RValue*)  0x162480  size 8  2 条（0x162480..0x162488）
 * @func 0x162480 0x162498  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162480 mov r1, #0
 *   @0x162484 b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §669/1245 F_SteamAvailableGameLanguages(RValue&, CInstance*, CInstance*, int, RValue*)  0x162488  size 8  2 条（0x162488..0x162490）
 * @func 0x162488 0x1624a0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162488 mov r1, #0
 *   @0x16248c b 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *
 * ══ §670/1245 CBitmap32::GetWidth()  0x167960  size 8  2 条（0x167960..0x167968）
 * @func 0x167960 0x167978  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x167960 ldr r0, [r0, #0x8]
 *   @0x167964 bx lr
 *
 * ══ §671/1245 CBitmap32::GetHeight()  0x167968  size 8  2 条（0x167968..0x167970）
 * @func 0x167968 0x167978  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x167968 ldr r0, [r0, #0xc]
 *   @0x16796c bx lr
 *
 * ══ §672/1245 CBitmap32::GetData()  0x167970  size 8  2 条（0x167970..0x167978）
 * @func 0x167970 0x167978  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x167970 add r0, r0, #16
 *   @0x167974 bx lr
 *
 * ══ §673/1245 INITIALIZE_Graphics_Draw()  0x16c2c0  size 8  2 条（0x16c2c0..0x16c2c8）
 * @func 0x16c2c0 0x16c2c8  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16c2c0 mov r0, #24
 *   @0x16c2c4 b 0x16ae64 <_Z24GR_Draw_Circle_Precisioni>
 *
 * ══ §674/1245 GR_Color_To_D3DColor(unsigned int, unsigned int)  0x16ca94  size 8  2 条（0x16ca94..0x16ca9c）
 * @func 0x16ca94 0x16caa8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16ca94 bfi r0, r1, #24, #8
 *   @0x16ca98 bx lr
 *
 * ══ §675/1245 GR_D3DColor_Change_Alpha(unsigned int, unsigned int)  0x16ca9c  size 8  2 条（0x16ca9c..0x16caa4）
 * @func 0x16ca9c 0x16caa8  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16ca9c bfi r0, r1, #24, #8
 *   @0x16caa0 bx lr
 *
 * ══ §676/1245 GR_Window_Get_FullScreen()  0x17af24  size 8  2 条（0x17af24..0x17af2c）
 * @func 0x17af24 0x17af3c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17af24 mov r0, #1
 *   @0x17af28 bx lr
 *
 * ══ §677/1245 GR_Window_Get_X()  0x17af40  size 8  2 条（0x17af40..0x17af48）
 * @func 0x17af40 0x17af58  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17af40 mov r0, #0
 *   @0x17af44 bx lr
 *
 * ══ §678/1245 GR_Window_Get_Y()  0x17af48  size 8  2 条（0x17af48..0x17af50）
 * @func 0x17af48 0x17af60  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17af48 mov r0, #0
 *   @0x17af4c bx lr
 *
 * ══ §679/1245 GR_Display_Get_Visible_Rects(double, double, double, double, double**)  0x17af78  size 8  2 条（0x17af78..0x17af80）
 * @func 0x17af78 0x17af8c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17af78 mov r0, #0
 *   @0x17af7c bx lr
 *
 * ══ §680/1245 GR_Window_Get_Cursor()  0x17af84  size 8  2 条（0x17af84..0x17af8c）
 * @func 0x17af84 0x17af8c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17af84 mov r0, #0
 *   @0x17af88 bx lr
 *
 * ══ §681/1245 Graphics::CheckDoFrameFirst()  0x17d230  size 8  2 条（0x17d230..0x17d238）
 * @func 0x17d230 0x17d238  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17d230 mov r0, #0
 *   @0x17d234 bx lr
 *
 * ══ §682/1245 DisplayFrequency()  0x17db4c  size 8  2 条（0x17db4c..0x17db54）
 * @func 0x17db4c 0x17db64  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17db4c mov r0, #60
 *   @0x17db50 bx lr
 *
 * ══ §683/1245 DisplayColorDepth()  0x17db54  size 8  2 条（0x17db54..0x17db5c）
 * @func 0x17db54 0x17db6c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17db54 mov r0, #32
 *   @0x17db58 bx lr
 *
 * ══ §684/1245 DisplayTest(int, int, int, int)  0x17db5c  size 8  2 条（0x17db5c..0x17db64）
 * @func 0x17db5c 0x17db74  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17db5c mov r0, #1
 *   @0x17db60 bx lr
 *
 * ══ §685/1245 DisplaySet(int, int, int, int)  0x17db64  size 8  2 条（0x17db64..0x17db6c）
 * @func 0x17db64 0x17db7c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17db64 mov r0, #1
 *   @0x17db68 bx lr
 *
 * ══ §686/1245 DisplayGetMouseX()  0x17dba4  size 8  2 条（0x17dba4..0x17dbac）
 * @func 0x17dba4 0x17dbbc  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17dba4 mov r0, #0
 *   @0x17dba8 bx lr
 *
 * ══ §687/1245 DisplayGetMouseY()  0x17dbac  size 8  2 条（0x17dbac..0x17dbb4）
 * @func 0x17dbac 0x17dbc4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17dbac mov r0, #0
 *   @0x17dbb0 bx lr
 *
 * ══ §688/1245 Graphics::GraphicsReset()  0x17dd48  size 8  2 条（0x17dd48..0x17dd50）
 * @func 0x17dd48 0x17dd58  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17dd48 mov r0, #1
 *   @0x17dd4c bx lr
 *
 * ══ §689/1245 Graphics::PickResolution(int, int)  0x17df30  size 8  2 条（0x17df30..0x17df38）
 * @func 0x17df30 0x17df38  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17df30 mov r0, #0
 *   @0x17df34 bx lr
 *
 * ══ §690/1245 Graphics::FogType()  0x17f360  size 8  2 条（0x17f360..0x17f368）
 * @func 0x17f360 0x17f378  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17f360 mov r0, #1
 *   @0x17f364 bx lr
 *
 * ══ §691/1245 Graphics::GetFVF(int)  0x1839a8  size 8  2 条（0x1839a8..0x1839b0）
 * @func 0x1839a8 0x1839b0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1839a8 mov r0, #0
 *   @0x1839ac bx lr
 *
 * ══ §692/1245 Graphics::AddVertexBuffer(int, int, bool)  0x184848  size 8  2 条（0x184848..0x184850）
 * @func 0x184848 0x184860  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x184848 mov r0, #0
 *   @0x18484c bx lr
 *
 * ══ §693/1245 Graphics::FVFSize(int)  0x184858  size 8  2 条（0x184858..0x184860）
 * @func 0x184858 0x184868  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x184858 mov r0, #0
 *   @0x18485c bx lr
 *
 * ══ §694/1245 Graphics::FindVBSpace(int, int)  0x184860  size 8  2 条（0x184860..0x184868）
 * @func 0x184860 0x184868  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x184860 mov r0, #0
 *   @0x184864 bx lr
 *
 * ══ §695/1245 Graphics::IsSupportedNativePrimtype(ePrimType)  0x185638  size 8  2 条（0x185638..0x185640）
 * @func 0x185638 0x185640  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x185638 mov r0, #1
 *   @0x18563c bx lr
 *
 * ══ §696/1245 IsFilenameInWhiteList(YYWhitelistFilename*, char const*)  0x18dafc  size 8  2 条（0x18dafc..0x18db04）
 * @func 0x18dafc 0x18db0c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18dafc mov r0, #0
 *   @0x18db00 bx lr
 *
 * ══ §697/1245 IsDirectoryInWhitelist(YYWhitelistFilename*, char const*)  0x18db04  size 8  2 条（0x18db04..0x18db0c）
 * @func 0x18db04 0x18db0c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18db04 mov r0, #0
 *   @0x18db08 bx lr
 *
 * ══ §698/1245 LoadSave::LoadData(int*)  0x18f6b4  size 8  2 条（0x18f6b4..0x18f6bc）
 * @func 0x18f6b4 0x18f6c0  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18f6b4 mov r0, #0
 *   @0x18f6b8 bx lr
 *
 * ══ §699/1245 GamepadSupportedM()  0x190ac4  size 8  2 条（0x190ac4..0x190acc）
 * @func 0x190ac4 0x190acc  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x190ac4 mov r0, #1
 *   @0x190ac8 bx lr
 *
 * ══ §700/1245 CBucket<16u, 1048576u, false>::GetSize()  0x190cd0  size 8  2 条（0x190cd0..0x190cd8）
 * @func 0x190cd0 0x190cd8  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x190cd0 mov r0, #16
 *   @0x190cd4 bx lr
 *
 * ══ §701/1245 unsigned int CHashMapCalculateHash<int>(int)  0x190f40  size 8  2 条（0x190f40..0x190f48）
 * @func 0x190f40 0x190f48  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x190f40 add r0, r0, #1
 *   @0x190f44 bx lr
 *
 * ══ §702/1245 _RefFactory<void*>::Destroy(void*)  0x199f48  size 8  2 条（0x199f48..0x199f50）
 * @func 0x199f48 0x199f50  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x199f48 mov r0, #0
 *   @0x199f4c bx lr
 *
 * ══ §703/1245 CPath::SetClosed(bool)  0x1a6e78  size 8  2 条（0x1a6e78..0x1a6e80）
 * @func 0x1a6e78 0x1a6e80  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a6e78 strb r1, [r0, #0x18]
 *   @0x1a6e7c b 0x1a6e30 <_ZN5CPath15ComputeInternalEv>
 *
 * ══ §704/1245 CPath::GetPathTime()  0x1a7bc0  size 8  2 条（0x1a7bc0..0x1a7bc8）
 * @func 0x1a7bc0 0x1a7bd8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x28×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a7bc0 ldr r0, [r0, #0x28]
 *   @0x1a7bc4 bx lr
 *
 * ══ §705/1245 CPath::GetCount()  0x1a7bc8  size 8  2 条（0x1a7bc8..0x1a7bd0）
 * @func 0x1a7bc8 0x1a7be0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a7bc8 ldr r0, [r0, #0x10]
 *   @0x1a7bcc bx lr
 *
 * ══ §706/1245 CPath::GetKind()  0x1a7bd0  size 8  2 条（0x1a7bd0..0x1a7bd8）
 * @func 0x1a7bd0 0x1a7be8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a7bd0 ldr r0, [r0, #0x14]
 *   @0x1a7bd4 bx lr
 *
 * ══ §707/1245 CPath::GetClosed()  0x1a7bd8  size 8  2 条（0x1a7bd8..0x1a7be0）
 * @func 0x1a7bd8 0x1a7be8  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a7bd8 ldrb r0, [r0, #0x18]
 *   @0x1a7bdc bx lr
 *
 * ══ §708/1245 CPath::GetPrecision()  0x1a7be0  size 8  2 条（0x1a7be0..0x1a7be8）
 * @func 0x1a7be0 0x1a7be8  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a7be0 ldr r0, [r0, #0x1c]
 *   @0x1a7be4 bx lr
 *
 * ══ §709/1245 TFont::GetColor()  0x1a854c  size 8  2 条（0x1a854c..0x1a8554）
 * @func 0x1a854c 0x1a8564  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a854c ldr r0, [r0, #0x4]
 *   @0x1a8550 bx lr
 *
 * ══ §710/1245 TFont::GetName()  0x1a8554  size 8  2 条（0x1a8554..0x1a855c）
 * @func 0x1a8554 0x1a856c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8554 ldr r0, [r0, #0x8]
 *   @0x1a8558 bx lr
 *
 * ══ §711/1245 TFont::GetSize()  0x1a855c  size 8  2 条（0x1a855c..0x1a8564）
 * @func 0x1a855c 0x1a8574  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a855c ldr r0, [r0, #0xc]
 *   @0x1a8560 bx lr
 *
 * ══ §712/1245 TFont::GetStyle()  0x1a8564  size 8  2 条（0x1a8564..0x1a856c）
 * @func 0x1a8564 0x1a8574  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8564 ldr r0, [r0, #0x10]
 *   @0x1a8568 bx lr
 *
 * ══ §713/1245 TFont::GetYYHandle()  0x1a856c  size 8  2 条（0x1a856c..0x1a8574）
 * @func 0x1a856c 0x1a8574  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a856c ldr r0, [r0, #0x14]
 *   @0x1a8570 bx lr
 *
 * ══ §714/1245 TFont::SetColor(unsigned int)  0x1a859c  size 8  2 条（0x1a859c..0x1a85a4）
 * @func 0x1a859c 0x1a85b4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a859c str r1, [r0, #0x4]
 *   @0x1a85a0 b 0x1a8850 <_ZN5TFont6CreateEv>
 *
 * ══ §715/1245 TFont::SetSize(int)  0x1a85a4  size 8  2 条（0x1a85a4..0x1a85ac）
 * @func 0x1a85a4 0x1a85b4  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a85a4 str r1, [r0, #0xc]
 *   @0x1a85a8 b 0x1a8850 <_ZN5TFont6CreateEv>
 *
 * ══ §716/1245 TFont::SetStyle(unsigned int)  0x1a85ac  size 8  2 条（0x1a85ac..0x1a85b4）
 * @func 0x1a85ac 0x1a85b4  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a85ac str r1, [r0, #0x10]
 *   @0x1a85b0 b 0x1a8850 <_ZN5TFont6CreateEv>
 *
 * ══ §717/1245 TBitmap::GetNative()  0x1a88f4  size 8  2 条（0x1a88f4..0x1a88fc）
 * @func 0x1a88f4 0x1a88fc  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a88f4 ldr r0, [r0, #0x8]
 *   @0x1a88f8 bx lr
 *
 * ══ §718/1245 TBitmap::GetPixelFormat()  0x1a893c  size 8  2 条（0x1a893c..0x1a8944）
 * @func 0x1a893c 0x1a8954  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a893c ldr r0, [r0, #0x14]
 *   @0x1a8940 bx lr
 *
 * ══ §719/1245 TBitmap::GetWidth()  0x1a8944  size 8  2 条（0x1a8944..0x1a894c）
 * @func 0x1a8944 0x1a895c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8944 ldr r0, [r0, #0x18]
 *   @0x1a8948 bx lr
 *
 * ══ §720/1245 TBitmap::GetHeight()  0x1a894c  size 8  2 条（0x1a894c..0x1a8954）
 * @func 0x1a894c 0x1a8964  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a894c ldr r0, [r0, #0x1c]
 *   @0x1a8950 bx lr
 *
 * ══ §721/1245 BitmapLoader::Animated()  0x1a8958  size 8  2 条（0x1a8958..0x1a8960）
 * @func 0x1a8958 0x1a8968  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8958 mov r0, #0
 *   @0x1a895c bx lr
 *
 * ══ §722/1245 BitmapLoader::GetFrameCount()  0x1a8960  size 8  2 条（0x1a8960..0x1a8968）
 * @func 0x1a8960 0x1a8968  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8960 ldr r0, [r0, #0x8]
 *   @0x1a8964 bx lr
 *
 * ══ §723/1245 CollisionIsRemoved(CInstance*)  0x1cc244  size 8  2 条（0x1cc244..0x1cc24c）
 * @func 0x1cc244 0x1cc24c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cc244 mov r0, #0
 *   @0x1cc248 bx lr
 *
 * ══ §724/1245 CSingleFingerGesture::IsUsingTouchUID(int)  0x1d4ff4  size 8  2 条（0x1d4ff4..0x1d4ffc）
 * @func 0x1d4ff4 0x1d500c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d4ff4 mov r0, #0
 *   @0x1d4ff8 bx lr
 *
 * ══ §725/1245 CSingleFingerGesture::NumUsedTouches()  0x1d4ffc  size 8  2 条（0x1d4ffc..0x1d5004）
 * @func 0x1d4ffc 0x1d5014  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d4ffc mov r0, #1
 *   @0x1d5000 bx lr
 *
 * ══ §726/1245 CGesturePinch::NumUsedTouches()  0x1d5004  size 8  2 条（0x1d5004..0x1d500c）
 * @func 0x1d5004 0x1d5014  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d5004 mov r0, #2
 *   @0x1d5008 bx lr
 *
 * ══ §727/1245 CGestureRotate::NumUsedTouches()  0x1d500c  size 8  2 条（0x1d500c..0x1d5014）
 * @func 0x1d500c 0x1d5014  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d500c mov r0, #2
 *   @0x1d5010 bx lr
 *
 * ══ §728/1245 Splash_Show_Movie(char const*, bool)  0x1dc774  size 8  2 条（0x1dc774..0x1dc77c）
 * @func 0x1dc774 0x1dc78c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc774 mov r0, #1
 *   @0x1dc778 bx lr
 *
 * ══ §729/1245 Splash_Show_Image(char const*, int)  0x1dc77c  size 8  2 条（0x1dc77c..0x1dc784）
 * @func 0x1dc77c 0x1dc794  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc77c mov r0, #1
 *   @0x1dc780 bx lr
 *
 * ══ §730/1245 Splash_Show_Text(char const*, int)  0x1dc784  size 8  2 条（0x1dc784..0x1dc78c）
 * @func 0x1dc784 0x1dc79c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc784 mov r0, #1
 *   @0x1dc788 bx lr
 *
 * ══ §731/1245 RunnerGetWADSize()  0x1dee3c  size 8  2 条（0x1dee3c..0x1dee44）
 * @func 0x1dee3c 0x1dee44  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dee3c mov r0, #0
 *   @0x1dee40 bx lr
 *
 * ══ §732/1245 YYGetFileName()  0x1dfb80  size 8  2 条（0x1dfb80..0x1dfb88）
 * @func 0x1dfb80 0x1dfb8c  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dfb80 mov r0, #0
 *   @0x1dfb84 bx lr
 *
 * ══ §733/1245 ASYNCFunc_SpriteCleanup(HTTP_REQ_CONTEXT*)  0x1ee770  size 8  2 条（0x1ee770..0x1ee778）
 * @func 0x1ee770 0x1ee778  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ee770 ldr r0, [r0, #0x1c]
 *   @0x1ee774 b 0x27d1d0 <_ZdlPv>
 *
 * ══ §734/1245 SV_TransitionSteps(CInstance*, int, RValue*)  0x1f8848  size 8  2 条（0x1f8848..0x1f8850）
 * @func 0x1f8848 0x1f8850  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f8848 mov r0, #1
 *   @0x1f884c bx lr
 *
 * ══ §735/1245 MyZFree(void*, void*)  0x2010e4  size 8  2 条（0x2010e4..0x2010ec）
 * @func 0x2010e4 0x2010ec  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2010e4 mov r0, r1
 *   @0x2010e8 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *
 * ══ §736/1245 CStream::GetMemory()  0x201158  size 8  2 条（0x201158..0x201160）
 * @func 0x201158 0x201170  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201158 ldr r0, [r0, #0x18]
 *   @0x20115c bx lr
 *
 * ══ §737/1245 CStream::GetPosition()  0x201160  size 8  2 条（0x201160..0x201168）
 * @func 0x201160 0x201170  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201160 ldr r0, [r0, #0x10]
 *   @0x201164 bx lr
 *
 * ══ §738/1245 CStream::GetSize()  0x201168  size 8  2 条（0x201168..0x201170）
 * @func 0x201168 0x201170  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201168 ldr r0, [r0, #0x8]
 *   @0x20116c bx lr
 *
 * ══ §739/1245 CStream::CheckSum()  0x202490  size 8  2 条（0x202490..0x202498）
 * @func 0x202490 0x2024a8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202490 mov r0, #0
 *   @0x202494 bx lr
 *
 * ══ §740/1245 CDS_Stack::Size()  0x2052ac  size 8  2 条（0x2052ac..0x2052b4）
 * @func 0x2052ac 0x2052b4  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2052ac ldr r0, [r0, #0x4]
 *   @0x2052b0 bx lr
 *
 * ══ §741/1245 CDS_List::Size()  0x2052b8  size 8  2 条（0x2052b8..0x2052c0）
 * @func 0x2052b8 0x2052d0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2052b8 ldr r0, [r0, #0x4]
 *   @0x2052bc bx lr
 *
 * ══ §742/1245 CDS_Priority::Size()  0x2052cc  size 8  2 条（0x2052cc..0x2052d4）
 * @func 0x2052cc 0x2052d4  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2052cc ldr r0, [r0, #0x4]
 *   @0x2052d0 bx lr
 *
 * ══ §743/1245 IsBigEndian()  0x212e98  size 8  2 条（0x212e98..0x212ea0）
 * @func 0x212e98 0x212ea0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x212e98 mov r0, #0
 *   @0x212e9c bx lr
 *
 * ══ §744/1245 CTimingSource::SetFrameRate(double)  0x214800  size 8  2 条（0x214800..0x214808）
 * @func 0x214800 0x214808  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214800 strd r2, r3, [r0, #24]
 *   @0x214804 b 0x214728 <_ZN13CTimingSource5ResetEv>
 *
 * ══ §745/1245 CD_Present()  0x21485c  size 8  2 条（0x21485c..0x214864）
 * @func 0x21485c 0x214874  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21485c mov r0, #1
 *   @0x214860 bx lr
 *
 * ══ §746/1245 CD_NumberOfTracks()  0x214864  size 8  2 条（0x214864..0x21486c）
 * @func 0x214864 0x21487c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214864 mov r0, #0
 *   @0x214868 bx lr
 *
 * ══ §747/1245 CD_Playing()  0x21486c  size 8  2 条（0x21486c..0x214874）
 * @func 0x21486c 0x214884  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21486c mov r0, #0
 *   @0x214870 bx lr
 *
 * ══ §748/1245 CD_Paused()  0x214874  size 8  2 条（0x214874..0x21487c）
 * @func 0x214874 0x21488c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214874 mov r0, #0
 *   @0x214878 bx lr
 *
 * ══ §749/1245 CD_Track()  0x21487c  size 8  2 条（0x21487c..0x214884）
 * @func 0x21487c 0x214894  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21487c mov r0, #0
 *   @0x214880 bx lr
 *
 * ══ §750/1245 CD_Length()  0x214884  size 8  2 条（0x214884..0x21488c）
 * @func 0x214884 0x21489c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214884 mov r0, #0
 *   @0x214888 bx lr
 *
 * ══ §751/1245 CD_TrackLength(int)  0x21488c  size 8  2 条（0x21488c..0x214894）
 * @func 0x21488c 0x2148a4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21488c mov r0, #0
 *   @0x214890 bx lr
 *
 * ══ §752/1245 CD_Position()  0x214894  size 8  2 条（0x214894..0x21489c）
 * @func 0x214894 0x2148ac  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214894 mov r0, #0
 *   @0x214898 bx lr
 *
 * ══ §753/1245 CD_TrackPosition()  0x21489c  size 8  2 条（0x21489c..0x2148a4）
 * @func 0x21489c 0x2148b4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21489c mov r0, #0
 *   @0x2148a0 bx lr
 *
 * ══ §754/1245 File_ShellExecute(char const*, char const*, char const*)  0x214ddc  size 8  2 条（0x214ddc..0x214de4）
 * @func 0x214ddc 0x214df4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214ddc mov r0, #0
 *   @0x214de0 bx lr
 *
 * ══ §755/1245 File_Execute(char const*, char const*, char const*, bool)  0x214de4  size 8  2 条（0x214de4..0x214dec）
 * @func 0x214de4 0x214dfc  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214de4 mov r0, #0
 *   @0x214de8 bx lr
 *
 * ══ §756/1245 CreateTempDir(char const*)  0x214dec  size 8  2 条（0x214dec..0x214df4）
 * @func 0x214dec 0x214e04  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214dec mov r0, #1
 *   @0x214df0 bx lr
 *
 * ══ §757/1245 CListener::GetGain()  0x215b40  size 8  2 条（0x215b40..0x215b48）
 * @func 0x215b40 0x215b48  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215b40 ldr r0, [r0, #0x30]
 *   @0x215b44 bx lr
 *
 * ══ §758/1245 Audio_GetListenerCount()  0x218638  size 8  2 条（0x218638..0x218640）
 * @func 0x218638 0x218640  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x218638 mov r0, #1
 *   @0x21863c bx lr
 *
 * ══ §759/1245 SND_AddFromFile(char const*, int)  0x21e9f0  size 8  2 条（0x21e9f0..0x21e9f8）
 * @func 0x21e9f0 0x21e9f8  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21e9f0 mvn r0, #0
 *   @0x21e9f4 bx lr
 *
 * ══ §760/1245 _alutBufferDataGetData  0x2213c8  size 8  2 条（0x2213c8..0x2213d0）
 * @func 0x2213c8 0x2213e0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2213c8 ldr r0, [r0]
 *   @0x2213cc bx lr
 *
 * ══ §761/1245 _alutBufferDataGetLength  0x2213dc  size 8  2 条（0x2213dc..0x2213e4）
 * @func 0x2213dc 0x2213ec  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2213dc ldr r0, [r0, #0x4]
 *   @0x2213e0 bx lr
 *
 * ══ §762/1245 _alutBufferDataGetSampleFrequency  0x2213e4  size 8  2 条（0x2213e4..0x2213ec）
 * @func 0x2213e4 0x2213ec  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2213e4 ldr r0, [r0, #0x10]
 *   @0x2213e8 bx lr
 *
 * ══ §763/1245 _alutInputGetData  0x221dc4  size 8  2 条（0x221dc4..0x221dcc）
 * @func 0x221dc4 0x221dcc  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221dc4 ldr r0, [r0, #0xc]
 *   @0x221dc8 bx lr
 *
 * ══ §764/1245 _alutInputStreamGetFileName  0x221e18  size 8  2 条（0x221e18..0x221e20）
 * @func 0x221e18 0x221e28  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221e18 ldr r0, [r0, #0x4]
 *   @0x221e1c bx lr
 *
 * ══ §765/1245 _alutInputStreamGetRemainingLength  0x221e20  size 8  2 条（0x221e20..0x221e28）
 * @func 0x221e20 0x221e28  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221e20 ldr r0, [r0, #0x8]
 *   @0x221e24 bx lr
 *
 * ══ §766/1245 alutUnloadWAV  0x22285c  size 8  2 条（0x22285c..0x222864）
 * @func 0x22285c 0x222864  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22285c mov r0, r1
 *   @0x222860 b 0xb655c <free@plt>
 *
 * ══ §767/1245 _alutOutputStreamGetData  0x22291c  size 8  2 条（0x22291c..0x222924）
 * @func 0x22291c 0x222930  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22291c ldr r0, [r0]
 *   @0x222920 bx lr
 *
 * ══ §768/1245 alutGetMajorVersion  0x222bc4  size 8  2 条（0x222bc4..0x222bcc）
 * @func 0x222bc4 0x222bd4  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x222bc4 mov r0, #1
 *   @0x222bc8 bx lr
 *
 * ══ §769/1245 alutGetMinorVersion  0x222bcc  size 8  2 条（0x222bcc..0x222bd4）
 * @func 0x222bcc 0x222bd4  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x222bcc mov r0, #1
 *   @0x222bd0 bx lr
 *
 * ══ §770/1245 ogg_close(void*)  0x223664  size 8  2 条（0x223664..0x22366c）
 * @func 0x223664 0x22367c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223664 mov r0, #0
 *   @0x223668 bx lr
 *
 * ══ §771/1245 ogg_tell(void*)  0x22366c  size 8  2 条（0x22366c..0x223674）
 * @func 0x22366c 0x223684  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2c0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22366c ldr r0, [r0, #0x2c0]
 *   @0x223670 bx lr
 *
 * ══ §772/1245 ogg_zip_close(void*)  0x223684  size 8  2 条（0x223684..0x22368c）
 * @func 0x223684 0x22368c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2c8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223684 ldr r0, [r0, #0x2c8]
 *   @0x223688 b 0x31ba8c <__udivdi3+0x3f4>
 *
 * ══ §773/1245 COggThread::Lock()  0x223a9c  size 8  2 条（0x223a9c..0x223aa4）
 * @func 0x223a9c 0x223aac  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x814×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223a9c ldr r0, [r0, #0x814]
 *   @0x223aa0 b 0x27e084 <_ZN5Mutex4LockEv>
 *
 * ══ §774/1245 COggThread::Unlock()  0x223aa4  size 8  2 条（0x223aa4..0x223aac）
 * @func 0x223aa4 0x223aac  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x814×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223aa4 ldr r0, [r0, #0x814]
 *   @0x223aa8 b 0x27e09c <_ZN5Mutex6UnlockEv>
 *
 * ══ §775/1245 COggSyncThread::Lock()  0x224c24  size 8  2 条（0x224c24..0x224c2c）
 * @func 0x224c24 0x224c34  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x830×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x224c24 ldr r0, [r0, #0x830]
 *   @0x224c28 b 0x27e084 <_ZN5Mutex4LockEv>
 *
 * ══ §776/1245 COggSyncThread::Unlock()  0x224c2c  size 8  2 条（0x224c2c..0x224c34）
 * @func 0x224c2c 0x224c34  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x830×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x224c2c ldr r0, [r0, #0x830]
 *   @0x224c30 b 0x27e09c <_ZN5Mutex6UnlockEv>
 *
 * ══ §777/1245 COggAudio::DebugSyncGroup(int)  0x22627c  size 8  2 条（0x22627c..0x226284）
 * @func 0x22627c 0x226284  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22627c str r1, [r0, #0x1c]
 *   @0x226280 bx lr
 *
 * ══ §778/1245 vorbis_synthesis_trackonly  0x22fc74  size 8  2 条（0x22fc74..0x22fc7c）
 * @func 0x22fc74 0x22fc7c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22fc74 mov r2, #0
 *   @0x22fc78 b 0x22fa78 <vorbis_book_init_decode+0x474>
 *
 * ══ §779/1245 ov_streams  0x231204  size 8  2 条（0x231204..0x23120c）
 * @func 0x231204 0x231214  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x231204 ldr r0, [r0, #0x34]
 *   @0x231208 bx lr
 *
 * ══ §780/1245 ov_seekable  0x23120c  size 8  2 条（0x23120c..0x231214）
 * @func 0x23120c 0x231214  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23120c ldr r0, [r0, #0x4]
 *   @0x231210 bx lr
 *
 * ══ §781/1245 oggpack_get_buffer  0x233e58  size 8  2 条（0x233e58..0x233e60）
 * @func 0x233e58 0x233e64  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233e58 ldr r0, [r0, #0x8]
 *   @0x233e5c bx lr
 *
 * ══ §782/1245 CRunnerContactListener::PostSolve(b2Contact*, b2ContactImpulse const*)  0x23be94  size 8  2 条（0x23be94..0x23be9c）
 * @func 0x23be94 0x23be9c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23be94 ldr r0, [r0, #0x4]
 *   @0x23be98 b 0x238204 <_ZN13CPhysicsWorld21RegisterContactResultEP9b2Contact>
 *
 * ══ §783/1245 pcre_jit_stack_alloc  0x25f6c8  size 8  2 条（0x25f6c8..0x25f6d0）
 * @func 0x25f6c8 0x25f6dc  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25f6c8 mov r0, #0
 *   @0x25f6cc bx lr
 *
 * ══ §784/1245 CBucket<16384u, 262144u, true>::GetSize()  0x27b758  size 8  2 条（0x27b758..0x27b760）
 * @func 0x27b758 0x27b760  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b758 mov r0, #16384
 *   @0x27b75c bx lr
 *
 * ══ §785/1245 CBucket<256u, 1048576u, true>::GetSize()  0x27b798  size 8  2 条（0x27b798..0x27b7a0）
 * @func 0x27b798 0x27b7a0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b798 mov r0, #256
 *   @0x27b79c bx lr
 *
 * ══ §786/1245 CBucket<128u, 524288u, true>::GetSize()  0x27b7d8  size 8  2 条（0x27b7d8..0x27b7e0）
 * @func 0x27b7d8 0x27b7e0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b7d8 mov r0, #128
 *   @0x27b7dc bx lr
 *
 * ══ §787/1245 CBucket<64u, 524288u, true>::GetSize()  0x27b818  size 8  2 条（0x27b818..0x27b820）
 * @func 0x27b818 0x27b820  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b818 mov r0, #64
 *   @0x27b81c bx lr
 *
 * ══ §788/1245 CBucket<32u, 262144u, true>::GetSize()  0x27b858  size 8  2 条（0x27b858..0x27b860）
 * @func 0x27b858 0x27b860  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b858 mov r0, #32
 *   @0x27b85c bx lr
 *
 * ══ §789/1245 CBucket<16u, 262144u, true>::GetSize()  0x27b898  size 8  2 条（0x27b898..0x27b8a0）
 * @func 0x27b898 0x27b8a0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b898 mov r0, #16
 *   @0x27b89c bx lr
 *
 * ══ §790/1245 CBucket<8u, 131072u, true>::GetSize()  0x27b8d8  size 8  2 条（0x27b8d8..0x27b8e0）
 * @func 0x27b8d8 0x27b8e0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b8d8 mov r0, #8
 *   @0x27b8dc bx lr
 *
 * ══ §791/1245 CalcCRC(char const*)  0x27df2c  size 8  2 条（0x27df2c..0x27df34）
 * @func 0x27df2c 0x27df34  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27df2c mvn r1, #0
 *   @0x27df30 b 0x27dec0 <_Z7CalcCRCPKcj>
 *
 * ══ §792/1245 array_list_length  0x27e2e0  size 8  2 条（0x27e2e0..0x27e2e8）
 * @func 0x27e2e0 0x27e2f8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e2e0 ldr r0, [r0, #0x4]
 *   @0x27e2e4 bx lr
 *
 * ══ §793/1245 json_object_object_get  0x27ea38  size 8  2 条（0x27ea38..0x27ea40）
 * @func 0x27ea38 0x27ea48  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27ea38 ldr r0, [r0, #0x18]
 *   @0x27ea3c b 0x280bac <lh_table_lookup>
 *
 * ══ §794/1245 json_object_object_del  0x27ea40  size 8  2 条（0x27ea40..0x27ea48）
 * @func 0x27ea40 0x27ea48  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27ea40 ldr r0, [r0, #0x18]
 *   @0x27ea44 b 0x280ca0 <lh_table_delete>
 *
 * ══ §795/1245 json_object_array_put_idx  0x27edf8  size 8  2 条（0x27edf8..0x27ee00）
 * @func 0x27edf8 0x27ee00  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27edf8 ldr r0, [r0, #0x18]
 *   @0x27edfc b 0x27e218 <array_list_put_idx>
 *
 * ══ §796/1245 _spTimeline_deinit  0x281364  size 8  2 条（0x281364..0x28136c）
 * @func 0x281364 0x28136c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x281364 ldr r0, [r0, #0x4]
 *   @0x281368 b 0x285c80 <_free>
 *
 * ══ §797/1245 sysGetFilePrePend  0x28fd4c  size 8  2 条（0x28fd4c..0x28fd54）
 * @func 0x28fd4c 0x28fd5c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28fd4c mov r0, #0
 *   @0x28fd50 bx lr
 *
 * ══ §798/1245 sysGetSavePrePend  0x28fd54  size 8  2 条（0x28fd54..0x28fd5c）
 * @func 0x28fd54 0x28fd5c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28fd54 mov r0, #0
 *   @0x28fd58 bx lr
 *
 * ══ §799/1245 ShouldDisplaySplash()  0x28fe44  size 8  2 条（0x28fe44..0x28fe4c）
 * @func 0x28fe44 0x28fe5c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28fe44 mov r0, #0
 *   @0x28fe48 bx lr
 *
 * ══ §800/1245 yySocket::Startup()  0x294d18  size 8  2 条（0x294d18..0x294d20）
 * @func 0x294d18 0x294d28  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x294d18 mov r0, #0
 *   @0x294d1c bx lr
 *
 * ══ §801/1245 yySocket::Init()  0x294ec8  size 8  2 条（0x294ec8..0x294ed0）
 * @func 0x294ec8 0x294ed4  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x294ec8 mov r0, #0
 *   @0x294ecc bx lr
 *
 * ══ §802/1245 DbgSocket::Write(void*, unsigned int)  0x29d9a8  size 8  2 条（0x29d9a8..0x29d9b0）
 * @func 0x29d9a8 0x29d9bc  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29d9a8 ldr r0, [r0]
 *   @0x29d9ac b 0x295464 <_ZN8yySocket5WriteEPvj>
 *
 * ══ §803/1245 _zip_error_clear(zip_error*)  0x2a430c  size 8  2 条（0x2a430c..0x2a4314）
 * @func 0x2a430c 0x2a4322  size 22  6 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a430c movs r3, #0x0
 *   @0x2a4310 str r3, [r0, #0x4]
 *
 * ══ §804/1245 _zip_error_set(zip_error*, int, int)  0x2a4358  size 8  2 条（0x2a4358..0x2a4360）
 * @func 0x2a4358 0x2a4360  size 8  2 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a4358 cbz r0, 0x2a435e <_Z14_zip_error_setP9zip_errorii+0x6>
 *   @0x2a435c ldrbmi r0, [r0, -r6]!
 *
 * ══ §805/1245 zip_get_name  0x2a4970  size 8  2 条（0x2a4970..0x2a4978）
 * @func 0x2a4970 0x2a4978  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a4970 add.w r3, r0, #0xc
 *   @0x2a4974 b.w 0x2a491a <_Z13_zip_get_nameP3zipiiP9zip_error>
 *
 * ══ §806/1245 zip_name_locate  0x2a4a58  size 8  2 条（0x2a4a58..0x2a4a60）
 * @func 0x2a4a58 0x2a4a60  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a4a58 add.w r3, r0, #0xc
 *   @0x2a4a5c b.w 0x2a49a4 <_Z16_zip_name_locateP3zipPKciP9zip_error>
 *
 * ══ §807/1245 png_get_io_ptr  0x2a5f20  size 8  2 条（0x2a5f20..0x2a5f28）
 * @func 0x2a5f20 0x2a5f30  size 16  4 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5f20 cbz r0, 0x2a5f26 <png_get_io_ptr+0x6>
 *   @0x2a5f24 .word 0x47700118
 *
 * ══ §808/1245 png_init_io  0x2a5f28  size 8  2 条（0x2a5f28..0x2a5f30）
 * @func 0x2a5f28 0x2a5f30  size 8  2 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5f28 cbz r0, 0x2a5f2e <png_init_io+0x6>
 *   @0x2a5f2c .word 0x47701118
 *
 * ══ §809/1245 png_get_error_ptr  0x2a655e  size 8  2 条（0x2a655e..0x2a6566）
 * @func 0x2a655e 0x2a6576  size 24  6 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a655e cbz r0, 0x2a6564 <png_get_error_ptr+0x6>
 *   @0x2a6562 ldrbmi r0, [r0, -r12, lsl #2]!
 *
 * ══ §810/1245 png_get_rgb_to_gray_status  0x2a6bbe  size 8  2 条（0x2a6bbe..0x2a6bc6）
 * @func 0x2a6bbe 0x2a6bd6  size 24  6 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6bbe cbz r0, 0x2a6bc4 <png_get_rgb_to_gray_status+0x6>
 *   @0x2a6bc2 .word 0x477002d4
 *
 * ══ §811/1245 png_get_user_chunk_ptr  0x2a6bc6  size 8  2 条（0x2a6bc6..0x2a6bce）
 * @func 0x2a6bc6 0x2a6bde  size 24  6 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6bc6 cbz r0, 0x2a6bcc <png_get_user_chunk_ptr+0x6>
 *   @0x2a6bca ldrbmi r0, [r0, -r4, asr #5]!
 *
 * ══ §812/1245 png_get_compression_buffer_size  0x2a6bce  size 8  2 条（0x2a6bce..0x2a6bd6）
 * @func 0x2a6bce 0x2a6be6  size 24  6 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6bce cbz r0, 0x2a6bd4 <png_get_compression_buffer_size+0x6>
 *   @0x2a6bd2 .word 0x47700174
 *
 * ══ §813/1245 png_get_user_width_max  0x2a6bd6  size 8  2 条（0x2a6bd6..0x2a6bde）
 * @func 0x2a6bd6 0x2a6bee  size 24  6 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6bd6 cbz r0, 0x2a6bdc <png_get_user_width_max+0x6>
 *   @0x2a6bda ldrbmi r0, [r0, -r8, lsl #6]!
 *
 * ══ §814/1245 png_get_user_height_max  0x2a6bde  size 8  2 条（0x2a6bde..0x2a6be6）
 * @func 0x2a6bde 0x2a6bf6  size 24  6 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6bde cbz r0, 0x2a6be4 <png_get_user_height_max+0x6>
 *   @0x2a6be2 ldrbmi r0, [r0, -r12, lsl #6]!
 *
 * ══ §815/1245 png_get_chunk_cache_max  0x2a6be6  size 8  2 条（0x2a6be6..0x2a6bee）
 * @func 0x2a6be6 0x2a6bfe  size 24  6 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6be6 cbz r0, 0x2a6bec <png_get_chunk_cache_max+0x6>
 *   @0x2a6bea .word 0x47700310
 *
 * ══ §816/1245 png_get_chunk_malloc_max  0x2a6bee  size 8  2 条（0x2a6bee..0x2a6bf6）
 * @func 0x2a6bee 0x2a6c04  size 22  6 条
 * 部分覆盖: 本节 6/9 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 3/5 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6bee cbz r0, 0x2a6bf4 <png_get_chunk_malloc_max+0x6>
 *   @0x2a6bf2 ldrbmi r0, [r0, -r0, lsr #3]!
 *
 * ══ §817/1245 png_create_struct  0x2a6c56  size 8  2 条（0x2a6c56..0x2a6c5e）
 * @func 0x2a6c56 0x2a6c5e  size 8  2 条
 * 部分覆盖: 本节 2/3 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6c56 movs r1, #0x0
 *   @0x2a6c5a b.w 0x2a6c02 <png_create_struct_2>
 *
 * ══ §818/1245 png_destroy_struct  0x2a6c88  size 8  2 条（0x2a6c88..0x2a6c90）
 * @func 0x2a6c88 0x2a6ca0  size 24  6 条
 * 部分覆盖: 本节 3/5 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6c88 movs r1, #0x0
 *   @0x2a6c8c b.w 0x2a6c5e <png_destroy_struct_2>
 *
 * ══ §819/1245 png_get_mem_ptr  0x2a6d44  size 8  2 条（0x2a6d44..0x2a6d4c）
 * @func 0x2a6d44 0x2a6d4c  size 8  2 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6d44 cbz r0, 0x2a6d4a <png_get_mem_ptr+0x6>
 *   @0x2a6d48 ldrbmi r0, [r0, -r8, ror #5]!
 *
 * ══ §820/1245 png_set_read_status_fn  0x2a7eb8  size 8  2 条（0x2a7eb8..0x2a7ec0）
 * @func 0x2a7eb8 0x2a7ec0  size 8  2 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a7eb8 cbz r0, 0x2a7ebe <png_set_read_status_fn+0x6>
 *   @0x2a7ebc .word 0x4770125c
 *
 * ══ §821/1245 png_set_chunk_cache_max  0x2af5a0  size 8  2 条（0x2af5a0..0x2af5a8）
 * @func 0x2af5a0 0x2af5b0  size 16  4 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af5a0 cbz r0, 0x2af5a6 <png_set_chunk_cache_max+0x6>
 *   @0x2af5a4 .word 0x47701310
 *
 * ══ §822/1245 png_set_chunk_malloc_max  0x2af5a8  size 8  2 条（0x2af5a8..0x2af5b0）
 * @func 0x2af5a8 0x2af5b0  size 8  2 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2af5a8 cbz r0, 0x2af5ae <png_set_chunk_malloc_max+0x6>
 *   @0x2af5ac ldrbmi r1, [r0, -r0, lsr #3]!
 *
 * ══ §823/1245 png_get_user_transform_ptr  0x2afbae  size 8  2 条（0x2afbae..0x2afbb6）
 * @func 0x2afbae 0x2afbb6  size 8  2 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2afbae cbz r0, 0x2afbb4 <png_get_user_transform_ptr+0x6>
 *   @0x2afbb2 ldrbmi r0, [r0, -r4, lsr #2]!
 *
 * ══ §824/1245 png_set_write_status_fn  0x2b093c  size 8  2 条（0x2b093c..0x2b0944）
 * @func 0x2b093c 0x2b0954  size 24  6 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b093c cbz r0, 0x2b0942 <png_set_write_status_fn+0x6>
 *   @0x2b0940 ldrbmi r1, [r0, -r0, ror #4]!
 *
 * ══ §825/1245 png_save_uint_16  0x2b1138  size 8  2 条（0x2b1138..0x2b1140）
 * @func 0x2b1138 0x2b1140  size 8  2 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b1138 lsrs r3, r1, #0x8
 *   @0x2b113c strb r3, [r0]
 *
 * ══ §826/1245 jpeg_get_small  0x2c137c  size 8  2 条（0x2c137c..0x2c1384）
 * @func 0x2c137c 0x2c1394  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c137c mov r0, r1
 *   @0x2c1380 b 0xb6544 <malloc@plt>
 *
 * ══ §827/1245 jpeg_free_small  0x2c1384  size 8  2 条（0x2c1384..0x2c138c）
 * @func 0x2c1384 0x2c139c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c1384 mov r0, r1
 *   @0x2c1388 b 0xb655c <free@plt>
 *
 * ══ §828/1245 jpeg_get_large  0x2c138c  size 8  2 条（0x2c138c..0x2c1394）
 * @func 0x2c138c 0x2c13a4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c138c mov r0, r1
 *   @0x2c1390 b 0xb6544 <malloc@plt>
 *
 * ══ §829/1245 jpeg_free_large  0x2c1394  size 8  2 条（0x2c1394..0x2c139c）
 * @func 0x2c1394 0x2c13ac  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c1394 mov r0, r1
 *   @0x2c1398 b 0xb655c <free@plt>
 *
 * ══ §830/1245 b2ChainShape::TestPoint(b2Transform const&, b2Vec2 const&) const  0x2c4874  size 8  2 条（0x2c4874..0x2c487c）
 * @func 0x2c4874 0x2c487c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c4874 mov r0, #0
 *   @0x2c4878 bx lr
 *
 * ══ §831/1245 b2CircleShape::GetChildCount() const  0x2c4d38  size 8  2 条（0x2c4d38..0x2c4d40）
 * @func 0x2c4d38 0x2c4d40  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c4d38 mov r0, #1
 *   @0x2c4d3c bx lr
 *
 * ══ §832/1245 b2EdgeShape::GetChildCount() const  0x2c5144  size 8  2 条（0x2c5144..0x2c514c）
 * @func 0x2c5144 0x2c5154  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c5144 mov r0, #1
 *   @0x2c5148 bx lr
 *
 * ══ §833/1245 b2EdgeShape::TestPoint(b2Transform const&, b2Vec2 const&) const  0x2c514c  size 8  2 条（0x2c514c..0x2c5154）
 * @func 0x2c514c 0x2c5154  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c514c mov r0, #0
 *   @0x2c5150 bx lr
 *
 * ══ §834/1245 b2PolygonShape::GetChildCount() const  0x2c5664  size 8  2 条（0x2c5664..0x2c566c）
 * @func 0x2c5664 0x2c566c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c5664 mov r0, #1
 *   @0x2c5668 bx lr
 *
 * ══ §835/1245 b2Draw::SetFlags(unsigned int)  0x2c67d8  size 8  2 条（0x2c67d8..0x2c67e0）
 * @func 0x2c67d8 0x2c67f0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c67d8 str r1, [r0, #0x4]
 *   @0x2c67dc bx lr
 *
 * ══ §836/1245 b2Draw::GetFlags() const  0x2c67e0  size 8  2 条（0x2c67e0..0x2c67e8）
 * @func 0x2c67e0 0x2c67f8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c67e0 ldr r0, [r0, #0x4]
 *   @0x2c67e4 bx lr
 *
 * ══ §837/1245 b2DistanceJoint::GetReactionTorque(float) const  0x2cca88  size 8  2 条（0x2cca88..0x2cca90）
 * @func 0x2cca88 0x2ccaa0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cca88 mov r0, #0
 *   @0x2cca8c bx lr
 *
 * ══ §838/1245 b2FrictionJoint::SolvePositionConstraints(b2SolverData const&)  0x2cd320  size 8  2 条（0x2cd320..0x2cd328）
 * @func 0x2cd320 0x2cd328  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cd320 mov r0, #1
 *   @0x2cd324 bx lr
 *
 * ══ §839/1245 b2FrictionJoint::GetMaxForce() const  0x2cdb18  size 8  2 条（0x2cdb18..0x2cdb20）
 * @func 0x2cdb18 0x2cdb20  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x60×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cdb18 ldr r0, [r0, #0x60]
 *   @0x2cdb1c bx lr
 *
 * ══ §840/1245 b2FrictionJoint::GetMaxTorque() const  0x2cdbb8  size 8  2 条（0x2cdbb8..0x2cdbc0）
 * @func 0x2cdbb8 0x2cdbc0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x64×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cdbb8 ldr r0, [r0, #0x64]
 *   @0x2cdbbc bx lr
 *
 * ══ §841/1245 b2MotorJoint::SolvePositionConstraints(b2SolverData const&)  0x2cdfbc  size 8  2 条（0x2cdfbc..0x2cdfc4）
 * @func 0x2cdfbc 0x2cdfc4  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cdfbc mov r0, #1
 *   @0x2cdfc0 bx lr
 *
 * ══ §842/1245 b2MotorJoint::GetMaxForce() const  0x2ce7c8  size 8  2 条（0x2ce7c8..0x2ce7d0）
 * @func 0x2ce7c8 0x2ce7d0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ce7c8 ldr r0, [r0, #0x5c]
 *   @0x2ce7cc bx lr
 *
 * ══ §843/1245 b2MotorJoint::GetMaxTorque() const  0x2ce868  size 8  2 条（0x2ce868..0x2ce870）
 * @func 0x2ce868 0x2ce870  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x60×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ce868 ldr r0, [r0, #0x60]
 *   @0x2ce86c bx lr
 *
 * ══ §844/1245 b2MotorJoint::GetLinearOffset() const  0x2ce8e4  size 8  2 条（0x2ce8e4..0x2ce8ec）
 * @func 0x2ce8e4 0x2ce8ec  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ce8e4 add r0, r0, #68
 *   @0x2ce8e8 bx lr
 *
 * ══ §845/1245 b2MotorJoint::GetAngularOffset() const  0x2ce940  size 8  2 条（0x2ce940..0x2ce948）
 * @func 0x2ce940 0x2ce958  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ce940 ldr r0, [r0, #0x4c]
 *   @0x2ce944 bx lr
 *
 * ══ §846/1245 b2MouseJoint::SolvePositionConstraints(b2SolverData const&)  0x2ce948  size 8  2 条（0x2ce948..0x2ce950）
 * @func 0x2ce948 0x2ce960  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ce948 mov r0, #1
 *   @0x2ce94c bx lr
 *
 * ══ §847/1245 b2MouseJoint::GetTarget() const  0x2cf080  size 8  2 条（0x2cf080..0x2cf088）
 * @func 0x2cf080 0x2cf098  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cf080 add r0, r0, #76
 *   @0x2cf084 bx lr
 *
 * ══ §848/1245 b2MouseJoint::SetMaxForce(float)  0x2cf088  size 8  2 条（0x2cf088..0x2cf090）
 * @func 0x2cf088 0x2cf0a0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cf088 str r1, [r0, #0x68]
 *   @0x2cf08c bx lr
 *
 * ══ §849/1245 b2MouseJoint::GetMaxForce() const  0x2cf090  size 8  2 条（0x2cf090..0x2cf098）
 * @func 0x2cf090 0x2cf0a8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cf090 ldr r0, [r0, #0x68]
 *   @0x2cf094 bx lr
 *
 * ══ §850/1245 b2MouseJoint::SetFrequency(float)  0x2cf098  size 8  2 条（0x2cf098..0x2cf0a0）
 * @func 0x2cf098 0x2cf0b0  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x54×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cf098 str r1, [r0, #0x54]
 *   @0x2cf09c bx lr
 *
 * ══ §851/1245 b2MouseJoint::GetFrequency() const  0x2cf0a0  size 8  2 条（0x2cf0a0..0x2cf0a8）
 * @func 0x2cf0a0 0x2cf0b8  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x54×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cf0a0 ldr r0, [r0, #0x54]
 *   @0x2cf0a4 bx lr
 *
 * ══ §852/1245 b2MouseJoint::SetDampingRatio(float)  0x2cf0a8  size 8  2 条（0x2cf0a8..0x2cf0b0）
 * @func 0x2cf0a8 0x2cf0b8  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cf0a8 str r1, [r0, #0x58]
 *   @0x2cf0ac bx lr
 *
 * ══ §853/1245 b2MouseJoint::GetDampingRatio() const  0x2cf0b0  size 8  2 条（0x2cf0b0..0x2cf0b8）
 * @func 0x2cf0b0 0x2cf0b8  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cf0b0 ldr r0, [r0, #0x58]
 *   @0x2cf0b4 bx lr
 *
 * ══ §854/1245 b2PrismaticJoint::IsLimitEnabled() const  0x2d0314  size 8  2 条（0x2d0314..0x2d031c）
 * @func 0x2d0314 0x2d031c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x88×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d0314 ldrb r0, [r0, #0x88]
 *   @0x2d0318 bx lr
 *
 * ══ §855/1245 b2PrismaticJoint::GetLowerLimit() const  0x2d0370  size 8  2 条（0x2d0370..0x2d0378）
 * @func 0x2d0370 0x2d0380  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x78×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d0370 ldr r0, [r0, #0x78]
 *   @0x2d0374 bx lr
 *
 * ══ §856/1245 b2PrismaticJoint::GetUpperLimit() const  0x2d0378  size 8  2 条（0x2d0378..0x2d0380）
 * @func 0x2d0378 0x2d0380  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x7c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d0378 ldr r0, [r0, #0x7c]
 *   @0x2d037c bx lr
 *
 * ══ §857/1245 b2PrismaticJoint::IsMotorEnabled() const  0x2d0434  size 8  2 条（0x2d0434..0x2d043c）
 * @func 0x2d0434 0x2d043c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x89×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d0434 ldrb r0, [r0, #0x89]
 *   @0x2d0438 bx lr
 *
 * ══ §858/1245 b2PulleyJoint::GetReactionTorque(float) const  0x2d06d0  size 8  2 条（0x2d06d0..0x2d06d8）
 * @func 0x2d06d0 0x2d06d8  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d06d0 mov r0, #0
 *   @0x2d06d4 bx lr
 *
 * ══ §859/1245 b2PulleyJoint::GetLengthA() const  0x2d1184  size 8  2 条（0x2d1184..0x2d118c）
 * @func 0x2d1184 0x2d119c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x54×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d1184 ldr r0, [r0, #0x54]
 *   @0x2d1188 bx lr
 *
 * ══ §860/1245 b2PulleyJoint::GetLengthB() const  0x2d118c  size 8  2 条（0x2d118c..0x2d1194）
 * @func 0x2d118c 0x2d119c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d118c ldr r0, [r0, #0x58]
 *   @0x2d1190 bx lr
 *
 * ══ §861/1245 b2PulleyJoint::GetRatio() const  0x2d1194  size 8  2 条（0x2d1194..0x2d119c）
 * @func 0x2d1194 0x2d119c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x70×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d1194 ldr r0, [r0, #0x70]
 *   @0x2d1198 bx lr
 *
 * ══ §862/1245 b2RevoluteJoint::IsMotorEnabled() const  0x2d2144  size 8  2 条（0x2d2144..0x2d214c）
 * @func 0x2d2144 0x2d214c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x64×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2144 ldrb r0, [r0, #0x64]
 *   @0x2d2148 bx lr
 *
 * ══ §863/1245 b2RevoluteJoint::IsLimitEnabled() const  0x2d2220  size 8  2 条（0x2d2220..0x2d2228）
 * @func 0x2d2220 0x2d2228  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x70×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2220 ldrb r0, [r0, #0x70]
 *   @0x2d2224 bx lr
 *
 * ══ §864/1245 b2RevoluteJoint::GetLowerLimit() const  0x2d227c  size 8  2 条（0x2d227c..0x2d2284）
 * @func 0x2d227c 0x2d228c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x78×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d227c ldr r0, [r0, #0x78]
 *   @0x2d2280 bx lr
 *
 * ══ §865/1245 b2RevoluteJoint::GetUpperLimit() const  0x2d2284  size 8  2 条（0x2d2284..0x2d228c）
 * @func 0x2d2284 0x2d228c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x7c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2284 ldr r0, [r0, #0x7c]
 *   @0x2d2288 bx lr
 *
 * ══ §866/1245 b2RopeJoint::GetReactionTorque(float) const  0x2d2514  size 8  2 条（0x2d2514..0x2d251c）
 * @func 0x2d2514 0x2d252c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2514 mov r0, #0
 *   @0x2d2518 bx lr
 *
 * ══ §867/1245 b2RopeJoint::GetMaxLength() const  0x2d2bb4  size 8  2 条（0x2d2bb4..0x2d2bbc）
 * @func 0x2d2bb4 0x2d2bc4  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x54×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2bb4 ldr r0, [r0, #0x54]
 *   @0x2d2bb8 bx lr
 *
 * ══ §868/1245 b2RopeJoint::GetLimitState() const  0x2d2bbc  size 8  2 条（0x2d2bbc..0x2d2bc4）
 * @func 0x2d2bbc 0x2d2bc4  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xa4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2bbc ldr r0, [r0, #0xa4]
 *   @0x2d2bc0 bx lr
 *
 * ══ §869/1245 b2WheelJoint::IsMotorEnabled() const  0x2d439c  size 8  2 条（0x2d439c..0x2d43a4）
 * @func 0x2d439c 0x2d43a4  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x80×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d439c ldrb r0, [r0, #0x80]
 *   @0x2d43a0 bx lr
 *
 * ══ §870/1245 b2ParticleGroup::GetBufferIndex() const  0x2d45fc  size 8  2 条（0x2d45fc..0x2d4604）
 * @func 0x2d45fc 0x2d4614  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d45fc ldr r0, [r0, #0x4]
 *   @0x2d4600 bx lr
 *
 * ══ §871/1245 b2ParticleGroup::GetGroupFlags() const  0x2d4604  size 8  2 条（0x2d4604..0x2d460c）
 * @func 0x2d4604 0x2d461c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d4604 ldr r0, [r0, #0xc]
 *   @0x2d4608 bx lr
 *
 * ══ §872/1245 b2ParticleGroup::SetGroupFlags(int)  0x2d460c  size 8  2 条（0x2d460c..0x2d4614）
 * @func 0x2d460c 0x2d4624  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d460c str r1, [r0, #0xc]
 *   @0x2d4610 bx lr
 *
 * ══ §873/1245 b2ParticleGroup::GetTransform() const  0x2d4614  size 8  2 条（0x2d4614..0x2d461c）
 * @func 0x2d4614 0x2d462c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d4614 add r0, r0, #60
 *   @0x2d4618 bx lr
 *
 * ══ §874/1245 b2ParticleGroup::GetPosition() const  0x2d461c  size 8  2 条（0x2d461c..0x2d4624）
 * @func 0x2d461c 0x2d4634  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d461c add r0, r0, #60
 *   @0x2d4620 bx lr
 *
 * ══ §875/1245 b2ParticleGroup::GetUserData() const  0x2d4634  size 8  2 条（0x2d4634..0x2d463c）
 * @func 0x2d4634 0x2d4644  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d4634 ldr r0, [r0, #0x50]
 *   @0x2d4638 bx lr
 *
 * ══ §876/1245 b2ParticleGroup::SetUserData(void*)  0x2d463c  size 8  2 条（0x2d463c..0x2d4644）
 * @func 0x2d463c 0x2d4644  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d463c str r1, [r0, #0x50]
 *   @0x2d4640 bx lr
 *
 * ══ §877/1245 b2QueryCallback::ReportParticle(int)  0x2d48b8  size 8  2 条（0x2d48b8..0x2d48c0）
 * @func 0x2d48b8 0x2d48c0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d48b8 mov r0, #0
 *   @0x2d48bc bx lr
 *
 * ══ §878/1245 b2ParticleSystem::GetParticleDensity() const  0x2d82ac  size 8  2 条（0x2d82ac..0x2d82b4）
 * @func 0x2d82ac 0x2d82c4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d82ac ldr r0, [r0, #0xc]
 *   @0x2d82b0 bx lr
 *
 * ══ §879/1245 b2ParticleSystem::SetParticleGravityScale(float)  0x2d82b4  size 8  2 条（0x2d82b4..0x2d82bc）
 * @func 0x2d82b4 0x2d82cc  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d82b4 str r1, [r0, #0x14]
 *   @0x2d82b8 bx lr
 *
 * ══ §880/1245 b2ParticleSystem::GetParticleGravityScale() const  0x2d82bc  size 8  2 条（0x2d82bc..0x2d82c4）
 * @func 0x2d82bc 0x2d82d4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d82bc ldr r0, [r0, #0x14]
 *   @0x2d82c0 bx lr
 *
 * ══ §881/1245 b2ParticleSystem::SetParticleDamping(float)  0x2d82c4  size 8  2 条（0x2d82c4..0x2d82cc）
 * @func 0x2d82c4 0x2d82dc  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xb0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d82c4 str r1, [r0, #0xb0]
 *   @0x2d82c8 bx lr
 *
 * ══ §882/1245 b2ParticleSystem::GetParticleDamping() const  0x2d82cc  size 8  2 条（0x2d82cc..0x2d82d4）
 * @func 0x2d82cc 0x2d82e4  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xb0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d82cc ldr r0, [r0, #0xb0]
 *   @0x2d82d0 bx lr
 *
 * ══ §883/1245 b2ParticleSystem::GetParticleFlagsBuffer()  0x2d9864  size 8  2 条（0x2d9864..0x2d986c）
 * @func 0x2d9864 0x2d987c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d9864 ldr r0, [r0, #0x30]
 *   @0x2d9868 bx lr
 *
 * ══ §884/1245 b2ParticleSystem::GetParticlePositionBuffer()  0x2d986c  size 8  2 条（0x2d986c..0x2d9874）
 * @func 0x2d986c 0x2d987c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d986c ldr r0, [r0, #0x38]
 *   @0x2d9870 bx lr
 *
 * ══ §885/1245 b2ParticleSystem::GetParticleVelocityBuffer()  0x2d9874  size 8  2 条（0x2d9874..0x2d987c）
 * @func 0x2d9874 0x2d987c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d9874 ldr r0, [r0, #0x40]
 *   @0x2d9878 bx lr
 *
 * ══ §886/1245 b2ParticleSystem::GetParticleMaxCount() const  0x2d98f4  size 8  2 条（0x2d98f4..0x2d98fc）
 * @func 0x2d98f4 0x2d990c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d98f4 ldr r0, [r0, #0x2c]
 *   @0x2d98f8 bx lr
 *
 * ══ §887/1245 b2ParticleSystem::SetParticleMaxCount(int)  0x2d98fc  size 8  2 条（0x2d98fc..0x2d9904）
 * @func 0x2d98fc 0x2d9914  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d98fc str r1, [r0, #0x2c]
 *   @0x2d9900 bx lr
 *
 * ══ §888/1245 b2ParticleSystem::GetParticleFlagsBuffer() const  0x2d9904  size 8  2 条（0x2d9904..0x2d990c）
 * @func 0x2d9904 0x2d991c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d9904 ldr r0, [r0, #0x30]
 *   @0x2d9908 bx lr
 *
 * ══ §889/1245 b2ParticleSystem::GetParticlePositionBuffer() const  0x2d990c  size 8  2 条（0x2d990c..0x2d9914）
 * @func 0x2d990c 0x2d9924  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d990c ldr r0, [r0, #0x38]
 *   @0x2d9910 bx lr
 *
 * ══ §890/1245 b2ParticleSystem::GetParticleVelocityBuffer() const  0x2d9914  size 8  2 条（0x2d9914..0x2d991c）
 * @func 0x2d9914 0x2d992c  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d9914 ldr r0, [r0, #0x40]
 *   @0x2d9918 bx lr
 *
 * ══ §891/1245 b2ParticleSystem::GetParticleGroupBuffer() const  0x2d9920  size 8  2 条（0x2d9920..0x2d9928）
 * @func 0x2d9920 0x2d992c  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d9920 ldr r0, [r0, #0x5c]
 *   @0x2d9924 bx lr
 *
 * ══ §892/1245 b2ParticleSystem::GetParticleGroupBuffer()  0x2d9a1c  size 8  2 条（0x2d9a1c..0x2d9a24）
 * @func 0x2d9a1c 0x2d9a24  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d9a1c ldr r0, [r0, #0x5c]
 *   @0x2d9a20 bx lr
 *
 * ══ §893/1245 b2DynamicTree::ComputeHeight() const  0x2df898  size 8  2 条（0x2df898..0x2df8a0）
 * @func 0x2df898 0x2df8a0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2df898 ldr r1, [r0]
 *   @0x2df89c b 0x2df84c <_ZNK13b2DynamicTree13ComputeHeightEi>
 *
 * ══ §894/1245 b2GearJoint::GetRatio() const  0x2e4904  size 8  2 条（0x2e4904..0x2e490c）
 * @func 0x2e4904 0x2e490c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x98×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e4904 ldr r0, [r0, #0x98]
 *   @0x2e4908 bx lr
 *
 * ══ §895/1245 ft_hash_str_insert  0x2e85a8  size 8  2 条（0x2e85a8..0x2e85b0）
 * @func 0x2e85a8 0x2e85b8  size 16  4 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e85a8 push {r3, lr}
 *   @0x2e85ac stclt p15, c15, [r8, #-644]
 *
 * ══ §896/1245 ft_hash_num_insert  0x2e85b0  size 8  2 条（0x2e85b0..0x2e85b8）
 * @func 0x2e85b0 0x2e85b8  size 8  2 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e85b0 push {r3, lr}
 *   @0x2e85b4 stclt p15, c15, [r8, #-628]
 *
 * ══ §897/1245 _Unwind_GetCFA  0x319a64  size 8  2 条（0x319a64..0x319a6c）
 * @func 0x319a64 0x319a6c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x44×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x319a64 ldr r0, [r0, #0x44]
 *   @0x319a68 bx lr
 *
 * ══ §898/1245 __aeabi_unwind_cpp_pr0  0x31a1a4  size 8  2 条（0x31a1a4..0x31a1ac）
 * @func 0x31a1a4 0x31a1bc  size 24  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31a1a4 mov r3, #0
 *   @0x31a1a8 b 0x319db4 <__gnu_Unwind_Backtrace+0xc4>
 *
 * ══ §899/1245 __aeabi_unwind_cpp_pr1  0x31a1ac  size 8  2 条（0x31a1ac..0x31a1b4）
 * @func 0x31a1ac 0x31a1bc  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31a1ac mov r3, #1
 *   @0x31a1b0 b 0x319db4 <__gnu_Unwind_Backtrace+0xc4>
 *
 * ══ §900/1245 __aeabi_unwind_cpp_pr2  0x31a1b4  size 8  2 条（0x31a1b4..0x31a1bc）
 * @func 0x31a1b4 0x31a1bc  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31a1b4 mov r3, #2
 *   @0x31a1b8 b 0x319db4 <__gnu_Unwind_Backtrace+0xc4>
 *
 * ══ §901/1245 _Unwind_GetDataRelBase  0x31ab24  size 8  2 条（0x31ab24..0x31ab2c）
 * @func 0x31ab24 0x31ab34  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c88
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31ab24 push {r3, lr}
 *   @0x31ab28 bl 0xb6c88 <abort@plt>
 *
 * ══ §902/1245 _Unwind_GetTextRelBase  0x31ab2c  size 8  2 条（0x31ab2c..0x31ab34）
 * @func 0x31ab2c 0x31ab34  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c88
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31ab2c push {r3, lr}
 *   @0x31ab30 bl 0xb6c88 <abort@plt>
 *
 * ══ §903/1245 zip_strerror  0x2a5764  size 6  2 条（0x2a5764..0x2a576a）
 * @func 0x2a5764 0x2a576c  size 8  2 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5764 adds r0, #0xc
 *   @0x2a5768 ldrlt r11, [r8, #-0x847]!
 *
 * ══ §904/1245 zip_file_error_get  0x2a58e8  size 6  2 条（0x2a58e8..0x2a58ee）
 * @func 0x2a58e8 0x2a58f0  size 8  2 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a58e8 adds r0, #0x4
 *   @0x2a58ec ldrblt r11, [r0, #0xd20]!
 *
 * ══ §905/1245 png_access_version_number  0x2a6036  size 6  2 条（0x2a6036..0x2a603c）
 * @func 0x2a6036 0x2a603e  size 8  2 条
 * 部分覆盖: 本节 2/3 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6036 movw r0, #0x28b3
 *   @0x2a603a bx lr
 *
 * ══ §906/1245 png_get_io_state  0x2a6bf6  size 6  2 条（0x2a6bf6..0x2a6bfc）
 * @func 0x2a6bf6 0x2a6c04  size 14  4 条
 * 部分覆盖: 本节 4/5 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6bf6 ldr.w r0, [r0, #0x334]
 *   @0x2a6bfa bx lr
 *
 * ══ §907/1245 png_get_io_chunk_name  0x2a6bfc  size 6  2 条（0x2a6bfc..0x2a6c02）
 * @func 0x2a6bfc 0x2a6c04  size 8  2 条
 * 部分覆盖: 本节 2/3 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a6bfc add.w r0, r0, #0x1e0
 *   @0x2a6c00 bx lr
 *
 * ══ §908/1245 FT_FloorFix  0x2e4d36  size 6  2 条（0x2e4d36..0x2e4d3c）
 * @func 0x2e4d36 0x2e4d3e  size 8  2 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e4d36 lsrs r0, r0, #0x10
 *   @0x2e4d3a bx lr
 *
 * ══ §909/1245 ft_validator_run  0x2e538c  size 6  2 条（0x2e538c..0x2e5392）
 * @func 0x2e538c 0x2e539e  size 18  5 条
 * 部分覆盖: 本节 4/5 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e538c mov.w r0, #0xffffffff
 *   @0x2e5390 bx lr
 *
 * ══ §910/1245 FT_Get_Renderer  0x2e5e68  size 6  2 条（0x2e5e68..0x2e5e6e）
 * @func 0x2e5e68 0x2e5e70  size 8  2 条
 * 部分覆盖: 本节 2/3 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e5e68 movs r2, #0x0
 *   @0x2e5e6c andeq r11, r0, r4, ror #31
 *
 * ══ §911/1245 FT_Outline_Embolden  0x2e6870  size 6  2 条（0x2e6870..0x2e6876）
 * @func 0x2e6870 0x2e6886  size 22  6 条
 * 部分覆盖: 本节 4/6 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 3/5 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6870 mov r2, r1
 *   @0x2e6874 ldrshlt r11, [r8, -sp]!
 *
 * ══ §912/1245 af_shaper_buf_destroy  0x30a6d4  size 6  2 条（0x30a6d4..0x30a6da）
 * @func 0x30a6d4 0x30a6dc  size 8  2 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x64×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x30a6d4 ldr r0, [r0, #0x64]
 *   @0x30a6d8 push {r1, r2, r3, r5, r9, r10, r11, r12, sp, pc}
 *
 * ══ §913/1245 Code_Error::Create()  0xf1c90  size 4  1 条（0xf1c90..0xf1c94）
 * @func 0xf1c90 0xf1c94  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf1c90 bx lr
 *
 * ══ §914/1245 DPlay_End()  0xf2bd4  size 4  1 条（0xf2bd4..0xf2bd8）
 * @func 0xf2bd4 0xf2be8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2bd4 bx lr
 *
 * ══ §915/1245 DPlay_Session_End()  0xf2bf4  size 4  1 条（0xf2bf4..0xf2bf8）
 * @func 0xf2bf4 0xf2c08  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2bf4 bx lr
 *
 * ══ §916/1245 DPlay_Data_Read(int, RValue*)  0xf2c30  size 4  1 条（0xf2c30..0xf2c34）
 * @func 0xf2c30 0xf2c44  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2c30 bx lr
 *
 * ══ §917/1245 DPlay_Data_Mode(bool)  0xf2c34  size 4  1 条（0xf2c34..0xf2c38）
 * @func 0xf2c34 0xf2c48  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2c34 bx lr
 *
 * ══ §918/1245 DPlay_Message_Value(RValue*)  0xf2c70  size 4  1 条（0xf2c70..0xf2c74）
 * @func 0xf2c70 0xf2c84  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2c70 bx lr
 *
 * ══ §919/1245 DPlay_Message_Clear(int)  0xf2c94  size 4  1 条（0xf2c94..0xf2c98）
 * @func 0xf2c94 0xf2c9c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2c94 bx lr
 *
 * ══ §920/1245 DPlay_IPaddress(char const*&)  0xf2c98  size 4  1 条（0xf2c98..0xf2c9c）
 * @func 0xf2c98 0xf2c9c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2c98 bx lr
 *
 * ══ §921/1245 CEvent::Clear()  0xf2d08  size 4  1 条（0xf2d08..0xf2d0c）
 * @func 0xf2d08 0xf2d0c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf2d08 bx lr
 *
 * ══ §922/1245 CExtensionFile::SetFunctionsCount(int)  0xf504c  size 4  1 条（0xf504c..0xf5050）
 * @func 0xf504c 0xf5050  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf504c b 0xf4cd8 <_ZN14CExtensionFile13SetCFunctionsEi>
 *
 * ══ §923/1245 CExtensionFile::SetFunctionsData(int, CExtensionFunction*)  0xf5054  size 4  1 条（0xf5054..0xf5058）
 * @func 0xf5054 0xf5058  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5054 b 0xf4cb4 <_ZN14CExtensionFile11SetFunctionEiP18CExtensionFunction>
 *
 * ══ §924/1245 CExtensionFile::SetConstantsCount(int)  0xf5060  size 4  1 条（0xf5060..0xf5064）
 * @func 0xf5060 0xf5064  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5060 b 0xf4dd4 <_ZN14CExtensionFile13SetCConstantsEi>
 *
 * ══ §925/1245 CExtensionFile::SetConstantsData(int, CExtensionConstant*)  0xf5394  size 4  1 条（0xf5394..0xf5398）
 * @func 0xf5394 0xf5398  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5394 b 0xf4db0 <_ZN14CExtensionFile11SetConstantEiP18CExtensionConstant>
 *
 * ══ §926/1245 CExtensionPackage::SetIncludesCount(int)  0xf5638  size 4  1 条（0xf5638..0xf563c）
 * @func 0xf5638 0xf563c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5638 b 0xf53e4 <_ZN17CExtensionPackage12SetCIncludesEi>
 *
 * ══ §927/1245 CExtensionPackage::SetIncludesFile(int, CExtensionFile*)  0xf5804  size 4  1 条（0xf5804..0xf5808）
 * @func 0xf5804 0xf5808  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf5804 b 0xf53c0 <_ZN17CExtensionPackage11SetIncludesEiP14CExtensionFile>
 *
 * ══ §928/1245 CFontGM::CFont_Clear(void*)  0xf9488  size 4  1 条（0xf9488..0xf948c）
 * @func 0xf9488 0xf949c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf9488 bx lr
 *
 * ══ §929/1245 F_GameEnd(RValue&, CInstance*, CInstance*, int, RValue*)  0x109bfc  size 4  1 条（0x109bfc..0x109c00）
 * @func 0x109bfc 0x109c00  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x109bfc b 0x1c9f50 <_Z15Command_EndGamev>
 *
 * ══ §930/1245 YYGML_place_free(CInstance*, float, float)  0x10ac74  size 4  1 条（0x10ac74..0x10ac78）
 * @func 0x10ac74 0x10ac7c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10ac74 b 0x1cab94 <_Z14Command_IsFreeP9CInstanceff>
 *
 * ══ §931/1245 YYGML_move_snap(CInstance*, float, float)  0x10ac78  size 4  1 条（0x10ac78..0x10ac7c）
 * @func 0x10ac78 0x10ac7c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10ac78 b 0x1c9594 <_Z12Command_SnapP9CInstanceff>
 *
 * ══ §932/1245 YYGML_instance_change(CInstance*, int, bool)  0x10b248  size 4  1 条（0x10b248..0x10b24c）
 * @func 0x10b248 0x10b24c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10b248 b 0x1c9bb4 <_Z14Command_ChangeP9CInstanceib>
 *
 * ══ §933/1245 YYGML_game_restart()  0x10c324  size 4  1 条（0x10c324..0x10c328）
 * @func 0x10c324 0x10c328  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10c324 b 0x1c9f54 <_Z19Command_RestartGamev>
 *
 * ══ §934/1245 F_Min3(RValue&, CInstance*, CInstance*, int, RValue*)  0x1135a4  size 4  1 条（0x1135a4..0x1135a8）
 * @func 0x1135a4 0x1135a8  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1135a4 b 0x1131d8 <_Z5F_MinR6RValueP9CInstanceS2_iPS_>
 *
 * ══ §935/1245 F_Max3(RValue&, CInstance*, CInstance*, int, RValue*)  0x113974  size 4  1 条（0x113974..0x113978）
 * @func 0x113974 0x113978  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x113974 b 0x1135a8 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_>
 *
 * ══ §936/1245 F_WindowSetVisible(RValue&, CInstance*, CInstance*, int, RValue*)  0x119abc  size 4  1 条（0x119abc..0x119ac0）
 * @func 0x119abc 0x119ac0  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119abc bx lr
 *
 * ══ §937/1245 F_WindowSetShowborder(RValue&, CInstance*, CInstance*, int, RValue*)  0x119af4  size 4  1 条（0x119af4..0x119af8）
 * @func 0x119af4 0x119b08  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119af4 bx lr
 *
 * ══ §938/1245 F_WindowSetShowicons(RValue&, CInstance*, CInstance*, int, RValue*)  0x119b0c  size 4  1 条（0x119b0c..0x119b10）
 * @func 0x119b0c 0x119b20  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119b0c bx lr
 *
 * ══ §939/1245 F_WindowSetStayontop(RValue&, CInstance*, CInstance*, int, RValue*)  0x119b24  size 4  1 条（0x119b24..0x119b28）
 * @func 0x119b24 0x119b38  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119b24 bx lr
 *
 * ══ §940/1245 F_WindowSetSizeable(RValue&, CInstance*, CInstance*, int, RValue*)  0x119b3c  size 4  1 条（0x119b3c..0x119b40）
 * @func 0x119b3c 0x119b50  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119b3c bx lr
 *
 * ══ §941/1245 F_WindowDefault(RValue&, CInstance*, CInstance*, int, RValue*)  0x119b54  size 4  1 条（0x119b54..0x119b58）
 * @func 0x119b54 0x119b60  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119b54 bx lr
 *
 * ══ §942/1245 F_WindowViewMouseSet(RValue&, CInstance*, CInstance*, int, RValue*)  0x119b58  size 4  1 条（0x119b58..0x119b5c）
 * @func 0x119b58 0x119b60  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119b58 bx lr
 *
 * ══ §943/1245 F_WindowViewsMouseSet(RValue&, CInstance*, CInstance*, int, RValue*)  0x119b5c  size 4  1 条（0x119b5c..0x119b60）
 * @func 0x119b5c 0x119b60  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x119b5c bx lr
 *
 * ══ §944/1245 F_WindowCenter(RValue&, CInstance*, CInstance*, int, RValue*)  0x11a538  size 4  1 条（0x11a538..0x11a53c）
 * @func 0x11a538 0x11a53c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11a538 b 0x17af34 <_Z16GR_Window_Centerv>
 *
 * ══ §945/1245 F_DrawPrimitiveEnd(RValue&, CInstance*, CInstance*, int, RValue*)  0x11ba28  size 4  1 条（0x11ba28..0x11ba2c）
 * @func 0x11ba28 0x11ba2c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x11ba28 b 0x16bdb0 <_Z21GR_Draw_Primitive_Endv>
 *
 * ══ §946/1245 YYGML_draw_set_blend_mode(int)  0x120eb0  size 4  1 条（0x120eb0..0x120eb4）
 * @func 0x120eb0 0x120eb4  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x120eb0 b 0x168360 <_Z16GR_D3D_Set_Blendi>
 *
 * ══ §947/1245 YYGML_draw_set_font(int)  0x121cd4  size 4  1 条（0x121cd4..0x121cd8）
 * @func 0x121cd4 0x121ce0  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x121cd4 b 0x172ac8 <_Z16GR_Text_Set_Fonti>
 *
 * ══ §948/1245 YYGML_draw_set_halign(int)  0x121cd8  size 4  1 条（0x121cd8..0x121cdc）
 * @func 0x121cd8 0x121ce0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x121cd8 b 0x172b30 <_Z18GR_Text_Set_HAligni>
 *
 * ══ §949/1245 YYGML_draw_set_valign(int)  0x121cdc  size 4  1 条（0x121cdc..0x121ce0）
 * @func 0x121cdc 0x121ce0  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x121cdc b 0x172b7c <_Z18GR_Text_Set_VAligni>
 *
 * ══ §950/1245 F_BrowserInputCapture(RValue&, CInstance*, CInstance*, int, RValue*)  0x125f58  size 4  1 条（0x125f58..0x125f5c）
 * @func 0x125f58 0x125f6c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x125f58 bx lr
 *
 * ══ §951/1245 F_GPIO_Set(RValue&, CInstance*, CInstance*, int, RValue*)  0x125f5c  size 4  1 条（0x125f5c..0x125f60）
 * @func 0x125f5c 0x125f70  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x125f5c bx lr
 *
 * ══ §952/1245 F_GPIO_Clear(RValue&, CInstance*, CInstance*, int, RValue*)  0x125f60  size 4  1 条（0x125f60..0x125f64）
 * @func 0x125f60 0x125f70  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x125f60 bx lr
 *
 * ══ §953/1245 F_GPIO_Get(RValue&, CInstance*, CInstance*, int, RValue*)  0x125f64  size 4  1 条（0x125f64..0x125f68）
 * @func 0x125f64 0x125f70  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x125f64 bx lr
 *
 * ══ §954/1245 F_GPIO_Set_Mode(RValue&, CInstance*, CInstance*, int, RValue*)  0x125f68  size 4  1 条（0x125f68..0x125f6c）
 * @func 0x125f68 0x125f70  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x125f68 bx lr
 *
 * ══ §955/1245 F_GPIO_Set_Function(RValue&, CInstance*, CInstance*, int, RValue*)  0x125f6c  size 4  1 条（0x125f6c..0x125f70）
 * @func 0x125f6c 0x125f70  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x125f6c bx lr
 *
 * ══ §956/1245 F_HighscoreClear(RValue&, CInstance*, CInstance*, int, RValue*)  0x12688c  size 4  1 条（0x12688c..0x126890）
 * @func 0x12688c 0x126890  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12688c b 0x1dc2d8 <_Z15HighScore_Clearv>
 *
 * ══ §957/1245 F_KeyboardUnsetMap(RValue&, CInstance*, CInstance*, int, RValue*)  0x1273bc  size 4  1 条（0x1273bc..0x1273c0）
 * @func 0x1273bc 0x1273d0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1273bc b 0x18c314 <_Z15IO_Keymap_Clearv>
 *
 * ══ §958/1245 F_IoHandle(RValue&, CInstance*, CInstance*, int, RValue*)  0x1273d0  size 4  1 条（0x1273d0..0x1273d4）
 * @func 0x1273d0 0x1273d4  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1273d0 b 0x28fe64 <_Z15ProcessMessagesv>
 *
 * ══ §959/1245 YYGML_keyboard_check_direct(int)  0x1278c0  size 4  1 条（0x1278c0..0x1278c4）
 * @func 0x1278c0 0x1278c4  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1278c0 b 0x1277f8 <_Z20YYGML_keyboard_checki>
 *
 * ══ §960/1245 F_EffectClear(RValue&, CInstance*, CInstance*, int, RValue*)  0x129f70  size 4  1 条（0x129f70..0x129f74）
 * @func 0x129f70 0x129f74  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129f70 b 0x1a277c <_Z12Effect_Clearv>
 *
 * ══ §961/1245 YYGML_sprite_set_cache_size(int, int)  0x130ff8  size 4  1 条（0x130ff8..0x130ffc）
 * @func 0x130ff8 0x130ffc  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x130ff8 bx lr
 *
 * ══ §962/1245 F_CDInit(RValue&, CInstance*, CInstance*, int, RValue*)  0x1336b8  size 4  1 条（0x1336b8..0x1336bc）
 * @func 0x1336b8 0x1336bc  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1336b8 b 0x214858 <_Z7CD_Initv>
 *
 * ══ §963/1245 F_CDStop(RValue&, CInstance*, CInstance*, int, RValue*)  0x1338ac  size 4  1 条（0x1338ac..0x1338b0）
 * @func 0x1338ac 0x1338c0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1338ac b 0x2148a8 <_Z7CD_Stopv>
 *
 * ══ §964/1245 F_CDPause(RValue&, CInstance*, CInstance*, int, RValue*)  0x1338b0  size 4  1 条（0x1338b0..0x1338b4）
 * @func 0x1338b0 0x1338c4  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1338b0 b 0x2148ac <_Z8CD_Pausev>
 *
 * ══ §965/1245 F_CDResume(RValue&, CInstance*, CInstance*, int, RValue*)  0x1338b4  size 4  1 条（0x1338b4..0x1338b8）
 * @func 0x1338b4 0x1338c8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1338b4 b 0x2148b0 <_Z9CD_Resumev>
 *
 * ══ §966/1245 F_CDOpenDoor(RValue&, CInstance*, CInstance*, int, RValue*)  0x1338e8  size 4  1 条（0x1338e8..0x1338ec）
 * @func 0x1338e8 0x1338f0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1338e8 b 0x2148bc <_Z11CD_OpenDoorv>
 *
 * ══ §967/1245 F_CDCloseDoor(RValue&, CInstance*, CInstance*, int, RValue*)  0x1338ec  size 4  1 条（0x1338ec..0x1338f0）
 * @func 0x1338ec 0x1338f0  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1338ec b 0x2148c0 <_Z12CD_CloseDoorv>
 *
 * ══ §968/1245 F_ActionUnknown(RValue&, CInstance*, CInstance*, int, RValue*)  0x13d630  size 4  1 条（0x13d630..0x13d634）
 * @func 0x13d630 0x13d644  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13d630 bx lr
 *
 * ══ §969/1245 F_ActionShowInfo(RValue&, CInstance*, CInstance*, int, RValue*)  0x13eb48  size 4  1 条（0x13eb48..0x13eb4c）
 * @func 0x13eb48 0x13eb4c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13eb48 b 0x18c2c8 <_Z8IO_Clearv>
 *
 * ══ §970/1245 F_ActionEndGame(RValue&, CInstance*, CInstance*, int, RValue*)  0x13ec4c  size 4  1 条（0x13ec4c..0x13ec50）
 * @func 0x13ec4c 0x13ec60  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13ec4c b 0x1c9f50 <_Z15Command_EndGamev>
 *
 * ══ §971/1245 F_ActionRestartGame(RValue&, CInstance*, CInstance*, int, RValue*)  0x13ec50  size 4  1 条（0x13ec50..0x13ec54）
 * @func 0x13ec50 0x13ec64  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13ec50 b 0x1c9f54 <_Z19Command_RestartGamev>
 *
 * ══ §972/1245 F_ActionHighscoreClear(RValue&, CInstance*, CInstance*, int, RValue*)  0x13f5a4  size 4  1 条（0x13f5a4..0x13f5a8）
 * @func 0x13f5a4 0x13f5a8  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13f5a4 b 0x1dc2d8 <_Z15HighScore_Clearv>
 *
 * ══ §973/1245 F_ActionCDStop(RValue&, CInstance*, CInstance*, int, RValue*)  0x140138  size 4  1 条（0x140138..0x14013c）
 * @func 0x140138 0x140144  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x140138 b 0x2148a8 <_Z7CD_Stopv>
 *
 * ══ §974/1245 F_ActionCDPause(RValue&, CInstance*, CInstance*, int, RValue*)  0x14013c  size 4  1 条（0x14013c..0x140140）
 * @func 0x14013c 0x140144  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14013c b 0x2148ac <_Z8CD_Pausev>
 *
 * ══ §975/1245 F_ActionCDResume(RValue&, CInstance*, CInstance*, int, RValue*)  0x140140  size 4  1 条（0x140140..0x140144）
 * @func 0x140140 0x140144  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x140140 b 0x2148b0 <_Z9CD_Resumev>
 *
 * ══ §976/1245 YYGML_action_change_object(CInstance*, int, bool)  0x141a94  size 4  1 条（0x141a94..0x141a98）
 * @func 0x141a94 0x141a98  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141a94 b 0x1c9bb4 <_Z14Command_ChangeP9CInstanceib>
 *
 * ══ §977/1245 YYGML_action_end_game()  0x141ca0  size 4  1 条（0x141ca0..0x141ca4）
 * @func 0x141ca0 0x141ca8  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141ca0 b 0x1c9f50 <_Z15Command_EndGamev>
 *
 * ══ §978/1245 YYGML_action_restart_game()  0x141ca4  size 4  1 条（0x141ca4..0x141ca8）
 * @func 0x141ca4 0x141ca8  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141ca4 b 0x1c9f54 <_Z19Command_RestartGamev>
 *
 * ══ §979/1245 F_D3DPrimitiveEnd(RValue&, CInstance*, CInstance*, int, RValue*)  0x143c88  size 4  1 条（0x143c88..0x143c8c）
 * @func 0x143c88 0x143c8c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x143c88 b 0x176ad0 <_Z19GR_3D_Primitive_Endv>
 *
 * ══ §980/1245 F_D3DTransformSetIdentity(RValue&, CInstance*, CInstance*, int, RValue*)  0x144e50  size 4  1 条（0x144e50..0x144e54）
 * @func 0x144e50 0x144e54  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x144e50 b 0x16369c <_Z28GR_3D_Transform_Set_Identityv>
 *
 * ══ §981/1245 F_D3DTransformStackClear(RValue&, CInstance*, CInstance*, int, RValue*)  0x1450bc  size 4  1 条（0x1450bc..0x1450c0）
 * @func 0x1450bc 0x1450c0  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1450bc b 0x163b00 <_Z27GR_3D_Transform_Stack_Clearv>
 *
 * ══ §982/1245 F_BE_AddButton(RValue&, CInstance*, CInstance*, int, RValue*)  0x156064  size 4  1 条（0x156064..0x156068）
 * @func 0x156064 0x156078  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156064 bx lr
 *
 * ══ §983/1245 F_BE_AddButtonExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x156068  size 4  1 条（0x156068..0x15606c）
 * @func 0x156068 0x15607c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156068 bx lr
 *
 * ══ §984/1245 F_BE_ChangeImage(RValue&, CInstance*, CInstance*, int, RValue*)  0x15606c  size 4  1 条（0x15606c..0x156070）
 * @func 0x15606c 0x156080  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15606c bx lr
 *
 * ══ §985/1245 F_BE_Change(RValue&, CInstance*, CInstance*, int, RValue*)  0x156070  size 4  1 条（0x156070..0x156074）
 * @func 0x156070 0x156084  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156070 bx lr
 *
 * ══ §986/1245 F_BE_DeleteButton(RValue&, CInstance*, CInstance*, int, RValue*)  0x156074  size 4  1 条（0x156074..0x156078）
 * @func 0x156074 0x156088  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156074 bx lr
 *
 * ══ §987/1245 F_BE_ExistsButton(RValue&, CInstance*, CInstance*, int, RValue*)  0x156078  size 4  1 条（0x156078..0x15607c）
 * @func 0x156078 0x15608c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156078 bx lr
 *
 * ══ §988/1245 F_BE_SetStyle(RValue&, CInstance*, CInstance*, int, RValue*)  0x15607c  size 4  1 条（0x15607c..0x156080）
 * @func 0x15607c 0x156090  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15607c bx lr
 *
 * ══ §989/1245 F_YoYoAdsEngagementLaunch(RValue&, CInstance*, CInstance*, int, RValue*)  0x1560a8  size 4  1 条（0x1560a8..0x1560ac）
 * @func 0x1560a8 0x1560bc  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1560a8 bx lr
 *
 * ══ §990/1245 F_YoYoAdsRewardCallback(RValue&, CInstance*, CInstance*, int, RValue*)  0x1560ac  size 4  1 条（0x1560ac..0x1560b0）
 * @func 0x1560ac 0x1560c0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1560ac bx lr
 *
 * ══ §991/1245 F_YoYo_LoginAchievements(RValue&, CInstance*, CInstance*, int, RValue*)  0x1565b4  size 4  1 条（0x1565b4..0x1565b8）
 * @func 0x1565b4 0x1565c0  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1565b4 b 0x160f7c <_Z17Achievement_Loginv>
 *
 * ══ §992/1245 F_YoYo_LogoutAchievements(RValue&, CInstance*, CInstance*, int, RValue*)  0x1565b8  size 4  1 条（0x1565b8..0x1565bc）
 * @func 0x1565b8 0x1565c0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1565b8 b 0x160fac <_Z18Achievement_Logoutv>
 *
 * ══ §993/1245 F_YoYo_AchievementsShowAchievements(RValue&, CInstance*, CInstance*, int, RValue*)  0x1565bc  size 4  1 条（0x1565bc..0x1565c0）
 * @func 0x1565bc 0x1565c0  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1565bc b 0x160fdc <_Z28Achievement_Show_Achievementv>
 *
 * ══ §994/1245 F_YoYo_AchievementsShowLeaderboards(RValue&, CInstance*, CInstance*, int, RValue*)  0x156608  size 4  1 条（0x156608..0x15660c）
 * @func 0x156608 0x15661c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156608 b 0x161280 <_Z28Achievement_Show_Leaderboardv>
 *
 * ══ §995/1245 F_YoYo_AchievementsLoadFriends(RValue&, CInstance*, CInstance*, int, RValue*)  0x15660c  size 4  1 条（0x15660c..0x156610）
 * @func 0x15660c 0x156620  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15660c b 0x161138 <_Z24Achievement_Load_Friendsv>
 *
 * ══ §996/1245 F_YoYo_AchievementGetChallenges(RValue&, CInstance*, CInstance*, int, RValue*)  0x156754  size 4  1 条（0x156754..0x156758）
 * @func 0x156754 0x156758  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156754 b 0x161074 <_Z26Achievement_Get_Challengesv>
 *
 * ══ §997/1245 F_YoYo_AchievementReset(RValue&, CInstance*, CInstance*, int, RValue*)  0x1567a0  size 4  1 条（0x1567a0..0x1567a4）
 * @func 0x1567a0 0x1567a4  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1567a0 b 0x16120c <_Z17Achievement_Resetv>
 *
 * ══ §998/1245 F_YoYo_OF_StartDashboard(RValue&, CInstance*, CInstance*, int, RValue*)  0x157094  size 4  1 条（0x157094..0x157098）
 * @func 0x157094 0x157098  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157094 b 0x1616d4 <_Z22YoYo_OF_StartDashboardv>
 *
 * ══ §999/1245 QuitYoYoFunctionsM()  0x15e2a0  size 4  1 条（0x15e2a0..0x15e2a4）
 * @func 0x15e2a0 0x15e2b4  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e2a0 bx lr
 *
 * ══ §1000/1245 InitYoYoConstantsM()  0x15e2a4  size 4  1 条（0x15e2a4..0x15e2a8）
 * @func 0x15e2a4 0x15e2b8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15e2a4 bx lr
 *
 * ══ §1001/1245 YYLockOrientation(bool)  0x15f37c  size 4  1 条（0x15f37c..0x15f380）
 * @func 0x15f37c 0x15f380  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15f37c bx lr
 *
 * ══ §1002/1245 F_KeyboardGetNumlock(RValue&, CInstance*, CInstance*, int, RValue*)  0x160ae0  size 4  1 条（0x160ae0..0x160ae4）
 * @func 0x160ae0 0x160ae8  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160ae0 bx lr
 *
 * ══ §1003/1245 F_KeyboardSetNumlock(RValue&, CInstance*, CInstance*, int, RValue*)  0x160ae4  size 4  1 条（0x160ae4..0x160ae8）
 * @func 0x160ae4 0x160ae8  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160ae4 bx lr
 *
 * ══ §1004/1245 F_CheckKeyDirect(RValue&, CInstance*, CInstance*, int, RValue*)  0x160b28  size 4  1 条（0x160b28..0x160b2c）
 * @func 0x160b28 0x160b2c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160b28 bx lr
 *
 * ══ §1005/1245 F_JoystickExists(RValue&, CInstance*, CInstance*, int, RValue*)  0x160e80  size 4  1 条（0x160e80..0x160e84）
 * @func 0x160e80 0x160e94  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160e80 bx lr
 *
 * ══ §1006/1245 F_JoystickDirection(RValue&, CInstance*, CInstance*, int, RValue*)  0x160e84  size 4  1 条（0x160e84..0x160e88）
 * @func 0x160e84 0x160e98  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160e84 bx lr
 *
 * ══ §1007/1245 F_JoystickName(RValue&, CInstance*, CInstance*, int, RValue*)  0x160e88  size 4  1 条（0x160e88..0x160e8c）
 * @func 0x160e88 0x160e9c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160e88 bx lr
 *
 * ══ §1008/1245 F_JoystickAxes(RValue&, CInstance*, CInstance*, int, RValue*)  0x160e8c  size 4  1 条（0x160e8c..0x160e90）
 * @func 0x160e8c 0x160ea0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160e8c bx lr
 *
 * ══ §1009/1245 F_JoystickButtons(RValue&, CInstance*, CInstance*, int, RValue*)  0x160e90  size 4  1 条（0x160e90..0x160e94）
 * @func 0x160e90 0x160ea4  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160e90 bx lr
 *
 * ══ §1010/1245 F_JoystickHasPov(RValue&, CInstance*, CInstance*, int, RValue*)  0x160e94  size 4  1 条（0x160e94..0x160e98）
 * @func 0x160e94 0x160ea8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160e94 bx lr
 *
 * ══ §1011/1245 F_JoystickCheckButton(RValue&, CInstance*, CInstance*, int, RValue*)  0x160e98  size 4  1 条（0x160e98..0x160e9c）
 * @func 0x160e98 0x160eac  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160e98 bx lr
 *
 * ══ §1012/1245 F_JoystickXpos(RValue&, CInstance*, CInstance*, int, RValue*)  0x160e9c  size 4  1 条（0x160e9c..0x160ea0）
 * @func 0x160e9c 0x160eb0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160e9c bx lr
 *
 * ══ §1013/1245 F_JoystickYpos(RValue&, CInstance*, CInstance*, int, RValue*)  0x160ea0  size 4  1 条（0x160ea0..0x160ea4）
 * @func 0x160ea0 0x160eb4  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160ea0 bx lr
 *
 * ══ §1014/1245 F_JoystickZpos(RValue&, CInstance*, CInstance*, int, RValue*)  0x160ea4  size 4  1 条（0x160ea4..0x160ea8）
 * @func 0x160ea4 0x160eb8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160ea4 bx lr
 *
 * ══ §1015/1245 F_JoystickRpos(RValue&, CInstance*, CInstance*, int, RValue*)  0x160ea8  size 4  1 条（0x160ea8..0x160eac）
 * @func 0x160ea8 0x160ebc  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160ea8 bx lr
 *
 * ══ §1016/1245 F_JoystickUpos(RValue&, CInstance*, CInstance*, int, RValue*)  0x160eac  size 4  1 条（0x160eac..0x160eb0）
 * @func 0x160eac 0x160ec0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160eac bx lr
 *
 * ══ §1017/1245 F_JoystickVpos(RValue&, CInstance*, CInstance*, int, RValue*)  0x160eb0  size 4  1 条（0x160eb0..0x160eb4）
 * @func 0x160eb0 0x160ec4  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160eb0 bx lr
 *
 * ══ §1018/1245 F_JoystickPov(RValue&, CInstance*, CInstance*, int, RValue*)  0x160eb4  size 4  1 条（0x160eb4..0x160eb8）
 * @func 0x160eb4 0x160ec8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160eb4 bx lr
 *
 * ══ §1019/1245 F_KeyboardWait(RValue&, CInstance*, CInstance*, int, RValue*)  0x160eb8  size 4  1 条（0x160eb8..0x160ebc）
 * @func 0x160eb8 0x160ecc  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160eb8 bx lr
 *
 * ══ §1020/1245 F_MouseWait(RValue&, CInstance*, CInstance*, int, RValue*)  0x160ebc  size 4  1 条（0x160ebc..0x160ec0）
 * @func 0x160ebc 0x160ed0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160ebc bx lr
 *
 * ══ §1021/1245 F_SetProgramPriority(RValue&, CInstance*, CInstance*, int, RValue*)  0x160ed0  size 4  1 条（0x160ed0..0x160ed4）
 * @func 0x160ed0 0x160ee4  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160ed0 bx lr
 *
 * ══ §1022/1245 F_SetApplicationTitle(RValue&, CInstance*, CInstance*, int, RValue*)  0x160ed4  size 4  1 条（0x160ed4..0x160ed8）
 * @func 0x160ed4 0x160ee8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160ed4 bx lr
 *
 * ══ §1023/1245 F_ClipboardHasText(RValue&, CInstance*, CInstance*, int, RValue*)  0x160ed8  size 4  1 条（0x160ed8..0x160edc）
 * @func 0x160ed8 0x160eec  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160ed8 bx lr
 *
 * ══ §1024/1245 F_ClipboardGetText(RValue&, CInstance*, CInstance*, int, RValue*)  0x160edc  size 4  1 条（0x160edc..0x160ee0）
 * @func 0x160edc 0x160eec  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160edc bx lr
 *
 * ══ §1025/1245 F_ClipboardSetText(RValue&, CInstance*, CInstance*, int, RValue*)  0x160ee0  size 4  1 条（0x160ee0..0x160ee4）
 * @func 0x160ee0 0x160eec  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160ee0 bx lr
 *
 * ══ §1026/1245 F_WindowHandle(RValue&, CInstance*, CInstance*, int, RValue*)  0x160ee4  size 4  1 条（0x160ee4..0x160ee8）
 * @func 0x160ee4 0x160eec  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160ee4 bx lr
 *
 * ══ §1027/1245 F_WindowD3DDevice(RValue&, CInstance*, CInstance*, int, RValue*)  0x160ee8  size 4  1 条（0x160ee8..0x160eec）
 * @func 0x160ee8 0x160eec  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x160ee8 bx lr
 *
 * ══ §1028/1245 Achievement_Show_Challenge_Notifications(int, int, int)  0x161070  size 4  1 条（0x161070..0x161074）
 * @func 0x161070 0x16107c  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161070 bx lr
 *
 * ══ §1029/1245 Achievement_Get_Challenges()  0x161074  size 4  1 条（0x161074..0x161078）
 * @func 0x161074 0x16107c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161074 bx lr
 *
 * ══ §1030/1245 Achievement_Send_Challenge(char*, char*, int, int, char*)  0x161078  size 4  1 条（0x161078..0x16107c）
 * @func 0x161078 0x16107c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161078 bx lr
 *
 * ══ §1031/1245 Achievement_Load_Progress()  0x161208  size 4  1 条（0x161208..0x16120c）
 * @func 0x161208 0x161210  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161208 bx lr
 *
 * ══ §1032/1245 Achievement_Reset()  0x16120c  size 4  1 条（0x16120c..0x161210）
 * @func 0x16120c 0x161210  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16120c bx lr
 *
 * ══ §1033/1245 YoYo_OF_StartDashboard()  0x1616d4  size 4  1 条（0x1616d4..0x1616d8）
 * @func 0x1616d4 0x1616e8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1616d4 bx lr
 *
 * ══ §1034/1245 YoYo_OF_AddAchievement(char const*, char const*)  0x1616d8  size 4  1 条（0x1616d8..0x1616dc）
 * @func 0x1616d8 0x1616ec  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1616d8 bx lr
 *
 * ══ §1035/1245 YoYo_OF_AddLeaderboard(char const*, char const*, eLeaderboardType)  0x1616dc  size 4  1 条（0x1616dc..0x1616e0）
 * @func 0x1616dc 0x1616f0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1616dc bx lr
 *
 * ══ §1036/1245 YoYo_OF_SendChallenge(char const*, char const*, char const*)  0x1616e0  size 4  1 条（0x1616e0..0x1616e4）
 * @func 0x1616e0 0x1616f4  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1616e0 bx lr
 *
 * ══ §1037/1245 YoYo_OF_SendInvite(char const*)  0x1616e4  size 4  1 条（0x1616e4..0x1616e8）
 * @func 0x1616e4 0x1616f8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1616e4 bx lr
 *
 * ══ §1038/1245 YoYo_OF_SendSocial(char const*, char const*, char const*)  0x1616e8  size 4  1 条（0x1616e8..0x1616ec）
 * @func 0x1616e8 0x1616fc  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1616e8 bx lr
 *
 * ══ §1039/1245 YoYo_OF_SetURL(char const*)  0x1616ec  size 4  1 条（0x1616ec..0x1616f0）
 * @func 0x1616ec 0x161700  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1616ec bx lr
 *
 * ══ §1040/1245 YoYo_OF_SendChallengeResult(eChallengeResult, char const*)  0x161700  size 4  1 条（0x161700..0x161704）
 * @func 0x161700 0x161704  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x161700 bx lr
 *
 * ══ §1041/1245 F_Steam_ResetAllStats(RValue&, CInstance*, CInstance*, int, RValue*)  0x16200c  size 4  1 条（0x16200c..0x162010）
 * @func 0x16200c 0x162014  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16200c bx lr
 *
 * ══ §1042/1245 F_Steam_ResetAllStatsAchievements(RValue&, CInstance*, CInstance*, int, RValue*)  0x162010  size 4  1 条（0x162010..0x162014）
 * @func 0x162010 0x162014  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162010 bx lr
 *
 * ══ §1043/1245 F_SteamUGC_StartItemUpdate(RValue&, CInstance*, CInstance*, int, RValue*)  0x162180  size 4  1 条（0x162180..0x162184）
 * @func 0x162180 0x162184  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162180 bx lr
 *
 * ══ §1044/1245 GetSteamHandle(RValue*, int)  0x162490  size 4  1 条（0x162490..0x162494）
 * @func 0x162490 0x1624a4  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x162490 b 0xcea30 <_Z10YYGetInt64PK6RValuei>
 *
 * ══ §1045/1245 GM_GetMatrix(eMatrix)  0x163cdc  size 4  1 条（0x163cdc..0x163ce0）
 * @func 0x163cdc 0x163ce0  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x163cdc bx lr
 *
 * ══ §1046/1245 GR_D3D_PartialReset()  0x168c20  size 4  1 条（0x168c20..0x168c24）
 * @func 0x168c20 0x168c24  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x168c20 b 0x17dd50 <_ZN8Graphics16UpdateWindowSizeEv>
 *
 * ══ §1047/1245 GR_D3DColor_To_Color(unsigned int)  0x16caa4  size 4  1 条（0x16caa4..0x16caa8）
 * @func 0x16caa4 0x16caa8  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16caa4 bx lr
 *
 * ══ §1048/1245 FINALIZE_Graphics_Texture()  0x1767cc  size 4  1 条（0x1767cc..0x1767d0）
 * @func 0x1767cc 0x1767d0  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1767cc b 0x1740e0 <_Z14GR_Texture_Endv>
 *
 * ══ §1049/1245 GR_Window_Set_FullScreen(bool)  0x17af10  size 4  1 条（0x17af10..0x17af14）
 * @func 0x17af10 0x17af24  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17af10 bx lr
 *
 * ══ §1050/1245 GR_Window_Set_Min_WidthM(int)  0x17af14  size 4  1 条（0x17af14..0x17af18）
 * @func 0x17af14 0x17af28  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17af14 bx lr
 *
 * ══ §1051/1245 GR_Window_Set_Max_WidthM(int)  0x17af18  size 4  1 条（0x17af18..0x17af1c）
 * @func 0x17af18 0x17af2c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17af18 bx lr
 *
 * ══ §1052/1245 GR_Window_Set_Min_HeightM(int)  0x17af1c  size 4  1 条（0x17af1c..0x17af20）
 * @func 0x17af1c 0x17af30  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17af1c bx lr
 *
 * ══ §1053/1245 GR_Window_Set_Max_HeightM(int)  0x17af20  size 4  1 条（0x17af20..0x17af24）
 * @func 0x17af20 0x17af34  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17af20 bx lr
 *
 * ══ §1054/1245 GR_Window_Set_CaptionM(char const*, bool)  0x17af2c  size 4  1 条（0x17af2c..0x17af30）
 * @func 0x17af2c 0x17af40  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17af2c bx lr
 *
 * ══ §1055/1245 GR_Window_Mouse_Set(int, int)  0x17af30  size 4  1 条（0x17af30..0x17af34）
 * @func 0x17af30 0x17af44  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17af30 bx lr
 *
 * ══ §1056/1245 GR_Window_Center()  0x17af34  size 4  1 条（0x17af34..0x17af38）
 * @func 0x17af34 0x17af48  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17af34 bx lr
 *
 * ══ §1057/1245 GR_Window_Set_Position(int, int)  0x17af38  size 4  1 条（0x17af38..0x17af3c）
 * @func 0x17af38 0x17af4c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17af38 bx lr
 *
 * ══ §1058/1245 GR_Window_Set_Size(int, int)  0x17af3c  size 4  1 条（0x17af3c..0x17af40）
 * @func 0x17af3c 0x17af50  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17af3c bx lr
 *
 * ══ §1059/1245 GameMaker_PaintEvent(void*)  0x17af80  size 4  1 条（0x17af80..0x17af84）
 * @func 0x17af80 0x17af8c  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17af80 b 0x169b1c <_Z14GR_D3D_Refreshv>
 *
 * ══ §1060/1245 GraphicsPerf::DisplayConsole()  0x17b8e0  size 4  1 条（0x17b8e0..0x17b8e4）
 * @func 0x17b8e0 0x17b8f0  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17b8e0 bx lr
 *
 * ══ §1061/1245 GraphicsPerf::DisplayAudio()  0x17b8e4  size 4  1 条（0x17b8e4..0x17b8e8）
 * @func 0x17b8e4 0x17b8f0  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17b8e4 b 0x21e384 <_Z16YYAudioDrawDebugv>
 *
 * ══ §1062/1245 GraphicsPerf::DisplayXBGameChat()  0x17b8e8  size 4  1 条（0x17b8e8..0x17b8ec）
 * @func 0x17b8e8 0x17b8f0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17b8e8 bx lr
 *
 * ══ §1063/1245 GraphicsPerf::DisplayAudioSync()  0x17b8ec  size 4  1 条（0x17b8ec..0x17b8f0）
 * @func 0x17b8ec 0x17b8f0  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17b8ec b 0x215fc0 <_Z21OggAudioSyncDrawDebugv>
 *
 * ══ §1064/1245 Graphics::SetMultiSample(int)  0x17db20  size 4  1 条（0x17db20..0x17db24）
 * @func 0x17db20 0x17db24  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17db20 bx lr
 *
 * ══ §1065/1245 DisplayReset()  0x17dba0  size 4  1 条（0x17dba0..0x17dba4）
 * @func 0x17dba0 0x17dbb4  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17dba0 bx lr
 *
 * ══ §1066/1245 DisplaySetMouse(int, int)  0x17dbb4  size 4  1 条（0x17dbb4..0x17dbb8）
 * @func 0x17dbb4 0x17dbc8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17dbb4 bx lr
 *
 * ══ §1067/1245 Graphics::EndInit()  0x17dd44  size 4  1 条（0x17dd44..0x17dd48）
 * @func 0x17dd44 0x17dd58  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17dd44 bx lr
 *
 * ══ §1068/1245 Graphics::UpdateWindowSize()  0x17dd50  size 4  1 条（0x17dd50..0x17dd54）
 * @func 0x17dd50 0x17dd58  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17dd50 bx lr
 *
 * ══ §1069/1245 Graphics::Quit()  0x17dd54  size 4  1 条（0x17dd54..0x17dd58）
 * @func 0x17dd54 0x17dd58  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17dd54 bx lr
 *
 * ══ §1070/1245 Graphics::GetTiming()  0x17f380  size 4  1 条（0x17f380..0x17f384）
 * @func 0x17f380 0x17f394  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17f380 bx lr
 *
 * ══ §1071/1245 Graphics::DrawNumber(float, float, float, int)  0x17f384  size 4  1 条（0x17f384..0x17f388）
 * @func 0x17f384 0x17f398  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17f384 bx lr
 *
 * ══ §1072/1245 Graphics::DrawChar(float, float, float, int)  0x17f388  size 4  1 条（0x17f388..0x17f38c）
 * @func 0x17f388 0x17f39c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17f388 bx lr
 *
 * ══ §1073/1245 Graphics::PushRenderStates()  0x17fc04  size 4  1 条（0x17fc04..0x17fc08）
 * @func 0x17fc04 0x17fc0c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17fc04 bx lr
 *
 * ══ §1074/1245 Graphics::PopRenderStates()  0x17fc08  size 4  1 条（0x17fc08..0x17fc0c）
 * @func 0x17fc08 0x17fc0c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17fc08 bx lr
 *
 * ══ §1075/1245 Graphics::SetSamplerStateEx(int, int, unsigned int)  0x17fcf4  size 4  1 条（0x17fcf4..0x17fcf8）
 * @func 0x17fcf4 0x17fcf8  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17fcf4 bx lr
 *
 * ══ §1076/1245 Graphics::SetRenderStateEx(int, unsigned int)  0x1804a8  size 4  1 条（0x1804a8..0x1804ac）
 * @func 0x1804a8 0x1804b0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1804a8 b 0x17fd24 <_ZN8Graphics14SetRenderStateE12eRenderStatej>
 *
 * ══ §1077/1245 Graphics::ResetBlends()  0x1804ac  size 4  1 条（0x1804ac..0x1804b0）
 * @func 0x1804ac 0x1804b0  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1804ac bx lr
 *
 * ══ §1078/1245 Graphics::PreLoadTexture(void*)  0x1833c4  size 4  1 条（0x1833c4..0x1833c8）
 * @func 0x1833c4 0x1833cc  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1833c4 bx lr
 *
 * ══ §1079/1245 Graphics::SetTexturePriority(void*, int)  0x1833c8  size 4  1 条（0x1833c8..0x1833cc）
 * @func 0x1833c8 0x1833cc  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1833c8 bx lr
 *
 * ══ §1080/1245 VertexBuffer::Lock()  0x183784  size 4  1 条（0x183784..0x183788）
 * @func 0x183784 0x18378c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x183784 bx lr
 *
 * ══ §1081/1245 VertexBuffer::Unlock()  0x183788  size 4  1 条（0x183788..0x18378c）
 * @func 0x183788 0x18378c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x183788 bx lr
 *
 * ══ §1082/1245 FreeVertexBuilderResources()  0x183d30  size 4  1 条（0x183d30..0x183d34）
 * @func 0x183d30 0x183d34  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x183d30 b 0xc8fe8 <_Z19InvalidateFrozenVBsv>
 *
 * ══ §1083/1245 Graphics::VBLinkLast(VertexBuffer*)  0x184850  size 4  1 条（0x184850..0x184854）
 * @func 0x184850 0x184864  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x184850 bx lr
 *
 * ══ §1084/1245 Graphics::VBUnLast(VertexBuffer*)  0x184854  size 4  1 条（0x184854..0x184858）
 * @func 0x184854 0x184868  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x184854 bx lr
 *
 * ══ §1085/1245 FreeAllVertexData()  0x1857d4  size 4  1 条（0x1857d4..0x1857d8）
 * @func 0x1857d4 0x1857d8  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1857d4 bx lr
 *
 * ══ §1086/1245 FreeShaderManagerResources()  0x187fa8  size 4  1 条（0x187fa8..0x187fac）
 * @func 0x187fa8 0x187fac  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x187fa8 b 0x187ed4 <_Z16Shader_Flush_Allv>
 *
 * ══ §1087/1245 GraphicsRecorder::Reset()  0x188ce8  size 4  1 条（0x188ce8..0x188cec）
 * @func 0x188ce8 0x188cec  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x188ce8 bx lr
 *
 * ══ §1088/1245 GMGamePad::SetColour(int, unsigned int)  0x18ed84  size 4  1 条（0x18ed84..0x18ed88）
 * @func 0x18ed84 0x18ed88  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18ed84 bx lr
 *
 * ══ §1089/1245 IO_Init_TForm(TForm*)  0x18f4cc  size 4  1 条（0x18f4cc..0x18f4d0）
 * @func 0x18f4cc 0x18f4d0  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18f4cc bx lr
 *
 * ══ §1090/1245 LoadSave::SaveData(char const*, int)  0x18f6b0  size 4  1 条（0x18f6b0..0x18f6b4）
 * @func 0x18f6b0 0x18f6c0  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18f6b0 bx lr
 *
 * ══ §1091/1245 LoadSave::SetUp(IniFile*)  0x18f6bc  size 4  1 条（0x18f6bc..0x18f6c0）
 * @func 0x18f6bc 0x18f6c0  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18f6bc bx lr
 *
 * ══ §1092/1245 GamepadReportFailureM()  0x1909f4  size 4  1 条（0x1909f4..0x1909f8）
 * @func 0x1909f4 0x1909f8  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1909f4 bx lr
 *
 * ══ §1093/1245 _RefFactory<void*>::Alloc(void*, int)  0x199f30  size 4  1 条（0x199f30..0x199f34）
 * @func 0x199f30 0x199f44  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x199f30 bx lr
 *
 * ══ §1094/1245 FINALIZE_Object_Class()  0x19e1c8  size 4  1 条（0x19e1c8..0x19e1cc）
 * @func 0x19e1c8 0x19e1cc  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19e1c8 bx lr
 *
 * ══ §1095/1245 Path_Init()  0x1a7ca8  size 4  1 条（0x1a7ca8..0x1a7cac）
 * @func 0x1a7ca8 0x1a7cac  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a7ca8 b 0x1a7be8 <_Z9Path_Quitv>
 *
 * ══ §1096/1245 TFont::Create()  0x1a8850  size 4  1 条（0x1a8850..0x1a8854）
 * @func 0x1a8850 0x1a8854  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8850 bx lr
 *
 * ══ §1097/1245 yyDestroyWindow(void*)  0x1a88c0  size 4  1 条（0x1a88c0..0x1a88c4）
 * @func 0x1a88c0 0x1a88d4  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a88c0 bx lr
 *
 * ══ §1098/1245 TBitmap::UnlockBits(void*)  0x1a8954  size 4  1 条（0x1a8954..0x1a8958）
 * @func 0x1a8954 0x1a8968  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a8954 bx lr
 *
 * ══ §1099/1245 Run_Score::Create()  0x1dbe94  size 4  1 条（0x1dbe94..0x1dbe98）
 * @func 0x1dbe94 0x1dbe98  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dbe94 bx lr
 *
 * ══ §1100/1245 HighScore_Show(int)  0x1dc2d4  size 4  1 条（0x1dc2d4..0x1dc2d8）
 * @func 0x1dc2d4 0x1dc2d8  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc2d4 bx lr
 *
 * ══ §1101/1245 HighScore_Value(int)  0x1dc310  size 4  1 条（0x1dc310..0x1dc314）
 * @func 0x1dc310 0x1dc318  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc310 b 0x1dc228 <_Z8GetScorei>
 *
 * ══ §1102/1245 HighScore_Name(char const*&, int)  0x1dc314  size 4  1 条（0x1dc314..0x1dc318）
 * @func 0x1dc314 0x1dc318  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc314 b 0x1dc1fc <_Z7GetNameRPKci>
 *
 * ══ §1103/1245 INITIALIZE_Score()  0x1dc3b8  size 4  1 条（0x1dc3b8..0x1dc3bc）
 * @func 0x1dc3b8 0x1dc3bc  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc3b8 b 0x1dc2d8 <_Z15HighScore_Clearv>
 *
 * ══ §1104/1245 Run_Score::ShowM()  0x1dc760  size 4  1 条（0x1dc760..0x1dc764）
 * @func 0x1dc760 0x1dc774  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc760 bx lr
 *
 * ══ §1105/1245 Run_Score::KeyPressM(void*, unsigned int)  0x1dc764  size 4  1 条（0x1dc764..0x1dc768）
 * @func 0x1dc764 0x1dc778  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc764 bx lr
 *
 * ══ §1106/1245 RenderPause()  0x1dc768  size 4  1 条（0x1dc768..0x1dc76c）
 * @func 0x1dc768 0x1dc77c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc768 bx lr
 *
 * ══ §1107/1245 AdaptWindow()  0x1dc76c  size 4  1 条（0x1dc76c..0x1dc770）
 * @func 0x1dc76c 0x1dc780  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc76c bx lr
 *
 * ══ §1108/1245 StopShow()  0x1dc770  size 4  1 条（0x1dc770..0x1dc774）
 * @func 0x1dc770 0x1dc784  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc770 bx lr
 *
 * ══ §1109/1245 Splash_Close_In_Main(short)  0x1dc7a0  size 4  1 条（0x1dc7a0..0x1dc7a4）
 * @func 0x1dc7a0 0x1dc7a4  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dc7a0 bx lr
 *
 * ══ §1110/1245 Misc_Setup(IniFile*)  0x1de97c  size 4  1 条（0x1de97c..0x1de980）
 * @func 0x1de97c 0x1de984  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1de97c bx lr
 *
 * ══ §1111/1245 Purchases_Setup(IniFile*)  0x1de980  size 4  1 条（0x1de980..0x1de984）
 * @func 0x1de980 0x1de984  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1de980 bx lr
 *
 * ══ §1112/1245 DecryptWad(char*, int)  0x1dfb7c  size 4  1 条（0x1dfb7c..0x1dfb80）
 * @func 0x1dfb7c 0x1dfb8c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dfb7c bx lr
 *
 * ══ §1113/1245 Platform_SetupM(IniFile*)  0x1dfb88  size 4  1 条（0x1dfb88..0x1dfb8c）
 * @func 0x1dfb88 0x1dfb8c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dfb88 bx lr
 *
 * ══ §1114/1245 FINALIZE_Script_Main()  0x1e0770  size 4  1 条（0x1e0770..0x1e0774）
 * @func 0x1e0770 0x1e0774  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e0770 b 0x1e0464 <_Z11Script_Freev>
 *
 * ══ §1115/1245 CSprite::ComputeCollisionMask()  0x1e56f8  size 4  1 条（0x1e56f8..0x1e56fc）
 * @func 0x1e56f8 0x1e56fc  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e56f8 b 0x1e3bcc <_ZN7CSprite10CreateMaskEv>
 *
 * ══ §1116/1245 CSprite::DrawShapeString(int, char const*, float, float, float, float, float, unsigned int, unsigned int, float)  0x1ee768  size 4  1 条（0x1ee768..0x1ee76c）
 * @func 0x1ee768 0x1ee778  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ee768 bx lr
 *
 * ══ §1117/1245 FINALIZE_Sprite_Class()  0x1ee76c  size 4  1 条（0x1ee76c..0x1ee770）
 * @func 0x1ee76c 0x1ee778  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ee76c bx lr
 *
 * ══ §1118/1245 CStream::WriteBuffer(void*, int)  0x201728  size 4  1 条（0x201728..0x20172c）
 * @func 0x201728 0x201730  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201728 b 0x2014c8 <_ZN7CStream5WriteEPvi>
 *
 * ══ §1119/1245 CStream::Read(void*, int)  0x20172c  size 4  1 条（0x20172c..0x201730）
 * @func 0x20172c 0x201730  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20172c b 0x2011e4 <_ZN7CStream10ReadBufferEPvi>
 *
 * ══ §1120/1245 CStream::WriteBoolean(bool)  0x201bb8  size 4  1 条（0x201bb8..0x201bbc）
 * @func 0x201bb8 0x201bbc  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201bb8 b 0x201a10 <_ZN7CStream12WriteIntegerEi>
 *
 * ══ §1121/1245 CStream::WriteStream(CStream*)  0x202480  size 4  1 条（0x202480..0x202484）
 * @func 0x202480 0x202494  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202480 bx lr
 *
 * ══ §1122/1245 CStream::WriteBitmap(IBitmap*)  0x202484  size 4  1 条（0x202484..0x202488）
 * @func 0x202484 0x202498  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202484 bx lr
 *
 * ══ §1123/1245 CStream::Encrypt(int, int, int)  0x202488  size 4  1 条（0x202488..0x20248c）
 * @func 0x202488 0x20249c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x202488 bx lr
 *
 * ══ §1124/1245 CStream::Encrypt2(int, int, int)  0x20248c  size 4  1 条（0x20248c..0x202490）
 * @func 0x20248c 0x2024a0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20248c bx lr
 *
 * ══ §1125/1245 FINALIZATION_Support_DLL()  0x212da0  size 4  1 条（0x212da0..0x212da4）
 * @func 0x212da0 0x212da4  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x212da0 b 0x212d18 <_Z12DLL_Free_Allv>
 *
 * ══ §1126/1245 CD_Init()  0x214858  size 4  1 条（0x214858..0x21485c）
 * @func 0x214858 0x21486c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214858 bx lr
 *
 * ══ §1127/1245 CD_Play(int, int)  0x2148a4  size 4  1 条（0x2148a4..0x2148a8）
 * @func 0x2148a4 0x2148b8  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2148a4 bx lr
 *
 * ══ §1128/1245 CD_Stop()  0x2148a8  size 4  1 条（0x2148a8..0x2148ac）
 * @func 0x2148a8 0x2148bc  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2148a8 bx lr
 *
 * ══ §1129/1245 CD_Pause()  0x2148ac  size 4  1 条（0x2148ac..0x2148b0）
 * @func 0x2148ac 0x2148c0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2148ac bx lr
 *
 * ══ §1130/1245 CD_Resume()  0x2148b0  size 4  1 条（0x2148b0..0x2148b4）
 * @func 0x2148b0 0x2148c4  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2148b0 bx lr
 *
 * ══ §1131/1245 CD_SetPosition(int)  0x2148b4  size 4  1 条（0x2148b4..0x2148b8）
 * @func 0x2148b4 0x2148c4  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2148b4 bx lr
 *
 * ══ §1132/1245 CD_SetTrackPosition(int)  0x2148b8  size 4  1 条（0x2148b8..0x2148bc）
 * @func 0x2148b8 0x2148c4  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2148b8 bx lr
 *
 * ══ §1133/1245 CD_OpenDoor()  0x2148bc  size 4  1 条（0x2148bc..0x2148c0）
 * @func 0x2148bc 0x2148c4  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2148bc bx lr
 *
 * ══ §1134/1245 CD_CloseDoor()  0x2148c0  size 4  1 条（0x2148c0..0x2148c4）
 * @func 0x2148c0 0x2148c4  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2148c0 bx lr
 *
 * ══ §1135/1245 DLL_Free(char const*)  0x214904  size 4  1 条（0x214904..0x214908）
 * @func 0x214904 0x214908  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214904 bx lr
 *
 * ══ §1136/1245 MakeTempDir()  0x214df4  size 4  1 条（0x214df4..0x214df8）
 * @func 0x214df4 0x214e08  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214df4 bx lr
 *
 * ══ §1137/1245 DestroyTempDir()  0x214df8  size 4  1 条（0x214df8..0x214dfc）
 * @func 0x214df8 0x214e0c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214df8 bx lr
 *
 * ══ §1138/1245 INITIALIZE_Support_File()  0x214e10  size 4  1 条（0x214e10..0x214e14）
 * @func 0x214e10 0x214e1c  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214e10 b 0x214df4 <_Z11MakeTempDirv>
 *
 * ══ §1139/1245 FINALIZE_Support_File()  0x214e14  size 4  1 条（0x214e14..0x214e18）
 * @func 0x214e14 0x214e1c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214e14 b 0x214df8 <_Z14DestroyTempDirv>
 *
 * ══ §1140/1245 DestroyDir(char const*)  0x214e18  size 4  1 条（0x214e18..0x214e1c）
 * @func 0x214e18 0x214e1c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214e18 bx lr
 *
 * ══ §1141/1245 ExtractFileDrive(char const*)  0x214fdc  size 4  1 条（0x214fdc..0x214fe0）
 * @func 0x214fdc 0x214fe0  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214fdc b 0xdb8c8 <_Z8YYStrDupPKc>
 *
 * ══ §1142/1245 CEmitter::Clear()  0x215808  size 4  1 条（0x215808..0x21580c）
 * @func 0x215808 0x21580c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215808 bx lr
 *
 * ══ §1143/1245 CListener::Clear()  0x215b1c  size 4  1 条（0x215b1c..0x215b20）
 * @func 0x215b1c 0x215b30  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x215b1c bx lr
 *
 * ══ §1144/1245 Audio_Clean()  0x216328  size 4  1 条（0x216328..0x21632c）
 * @func 0x216328 0x21632c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x216328 bx lr
 *
 * ══ §1145/1245 CNoise::Clear()  0x21db24  size 4  1 条（0x21db24..0x21db28）
 * @func 0x21db24 0x21db38  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21db24 bx lr
 *
 * ══ §1146/1245 SND_Set_Search_Directory(char const*)  0x21e9ec  size 4  1 条（0x21e9ec..0x21e9f0）
 * @func 0x21e9ec 0x21e9f8  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21e9ec bx lr
 *
 * ══ §1147/1245 SND_Delete(int)  0x21eadc  size 4  1 条（0x21eadc..0x21eae0）
 * @func 0x21eadc 0x21eae0  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21eadc bx lr
 *
 * ══ §1148/1245 SND_Set_Global_Tempo(double)  0x21eb78  size 4  1 条（0x21eb78..0x21eb7c）
 * @func 0x21eb78 0x21eb7c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21eb78 bx lr
 *
 * ══ §1149/1245 SND_Set_Panning(int, double)  0x21f11c  size 4  1 条（0x21f11c..0x21f120）
 * @func 0x21f11c 0x21f130  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f11c bx lr
 *
 * ══ §1150/1245 SND_Set_Effect(int, int)  0x21f120  size 4  1 条（0x21f120..0x21f124）
 * @func 0x21f120 0x21f134  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f120 bx lr
 *
 * ══ §1151/1245 SND_Set_Effect_Chorus(int, double, double, double, double, int, double, int)  0x21f124  size 4  1 条（0x21f124..0x21f128）
 * @func 0x21f124 0x21f138  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f124 bx lr
 *
 * ══ §1152/1245 SND_Get_Effect_Chorus(int, double*, double*, double*, double*, int*, double*, int*)  0x21f128  size 4  1 条（0x21f128..0x21f12c）
 * @func 0x21f128 0x21f13c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f128 bx lr
 *
 * ══ §1153/1245 SND_Set_Effect_Compressor(int, double, double, double, double, double, double)  0x21f12c  size 4  1 条（0x21f12c..0x21f130）
 * @func 0x21f12c 0x21f140  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f12c bx lr
 *
 * ══ §1154/1245 SND_Get_Effect_Compressor(int, double*, double*, double*, double*, double*, double*)  0x21f130  size 4  1 条（0x21f130..0x21f134）
 * @func 0x21f130 0x21f144  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f130 bx lr
 *
 * ══ §1155/1245 SND_Set_Effect_Echo(int, double, double, double, double, int)  0x21f134  size 4  1 条（0x21f134..0x21f138）
 * @func 0x21f134 0x21f148  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f134 bx lr
 *
 * ══ §1156/1245 SND_Get_Effect_Echo(int, double*, double*, double*, double*, int*)  0x21f138  size 4  1 条（0x21f138..0x21f13c）
 * @func 0x21f138 0x21f14c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f138 bx lr
 *
 * ══ §1157/1245 SND_Set_Effect_Flanger(int, double, double, double, double, int, double, int)  0x21f13c  size 4  1 条（0x21f13c..0x21f140）
 * @func 0x21f13c 0x21f150  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f13c bx lr
 *
 * ══ §1158/1245 SND_Get_Effect_Flanger(int, double*, double*, double*, double*, int*, double*, int*)  0x21f140  size 4  1 条（0x21f140..0x21f144）
 * @func 0x21f140 0x21f154  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f140 bx lr
 *
 * ══ §1159/1245 SND_Set_Effect_Gargle(int, int, int)  0x21f144  size 4  1 条（0x21f144..0x21f148）
 * @func 0x21f144 0x21f158  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f144 bx lr
 *
 * ══ §1160/1245 SND_Get_Effect_Gargle(int, int*, int*)  0x21f148  size 4  1 条（0x21f148..0x21f14c）
 * @func 0x21f148 0x21f15c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f148 bx lr
 *
 * ══ §1161/1245 SND_Set_Effect_Equalizer(int, double, double, double)  0x21f14c  size 4  1 条（0x21f14c..0x21f150）
 * @func 0x21f14c 0x21f160  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f14c bx lr
 *
 * ══ §1162/1245 SND_Get_Effect_Equalizer(int, double*, double*, double*)  0x21f150  size 4  1 条（0x21f150..0x21f154）
 * @func 0x21f150 0x21f164  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f150 bx lr
 *
 * ══ §1163/1245 SND_Set_Effect_Reverb(int, double, double, double, double)  0x21f154  size 4  1 条（0x21f154..0x21f158）
 * @func 0x21f154 0x21f168  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f154 bx lr
 *
 * ══ §1164/1245 SND_Get_Effect_Reverb(int, double*, double*, double*, double*)  0x21f158  size 4  1 条（0x21f158..0x21f15c）
 * @func 0x21f158 0x21f16c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f158 bx lr
 *
 * ══ §1165/1245 SND_Set_Effect_Distortion(int, double, double, double, double, double)  0x21f15c  size 4  1 条（0x21f15c..0x21f160）
 * @func 0x21f15c 0x21f170  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f15c bx lr
 *
 * ══ §1166/1245 SND_Get_Effect_Distortion(int, double*, double*, double*, double*, double*)  0x21f160  size 4  1 条（0x21f160..0x21f164）
 * @func 0x21f160 0x21f174  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f160 bx lr
 *
 * ══ §1167/1245 SND_Set_Effect_Environmental(int, int)  0x21f164  size 4  1 条（0x21f164..0x21f168）
 * @func 0x21f164 0x21f178  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f164 bx lr
 *
 * ══ §1168/1245 SND_Get_Effect_Environmental(int, int*)  0x21f168  size 4  1 条（0x21f168..0x21f16c）
 * @func 0x21f168 0x21f17c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f168 bx lr
 *
 * ══ §1169/1245 SND_3D_Set_Sound_Position(int, double, double, double)  0x21f16c  size 4  1 条（0x21f16c..0x21f170）
 * @func 0x21f16c 0x21f17c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f16c bx lr
 *
 * ══ §1170/1245 SND_3D_Set_Sound_Velocity(int, double, double, double)  0x21f170  size 4  1 条（0x21f170..0x21f174）
 * @func 0x21f170 0x21f17c  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f170 bx lr
 *
 * ══ §1171/1245 SND_3D_Set_Sound_Distance(int, double, double)  0x21f174  size 4  1 条（0x21f174..0x21f178）
 * @func 0x21f174 0x21f17c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f174 bx lr
 *
 * ══ §1172/1245 SND_3D_Set_Sound_Cone(int, double, double, double, int, int, double)  0x21f178  size 4  1 条（0x21f178..0x21f17c）
 * @func 0x21f178 0x21f17c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f178 bx lr
 *
 * ══ §1173/1245 INITIALIZE_Sound_DirectX()  0x21f210  size 4  1 条（0x21f210..0x21f214）
 * @func 0x21f210 0x21f218  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f210 bx lr
 *
 * ══ §1174/1245 FINALIZATION_Sound_DirectX()  0x21f214  size 4  1 条（0x21f214..0x21f218）
 * @func 0x21f214 0x21f218  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f214 bx lr
 *
 * ══ §1175/1245 SoundHardware::~SoundHardware()  0x220194  size 4  1 条（0x220194..0x220198）
 * @func 0x220194 0x220198  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x220194 bx lr
 *
 * ══ §1176/1245 Sound_Setup(IniFile*)  0x221374  size 4  1 条（0x221374..0x221378）
 * @func 0x221374 0x221378  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221374 b 0x2232e8 <_Z12OpenAL_SetupP7IniFile>
 *
 * ══ §1177/1245 _alutCodecLinear  0x221508  size 4  1 条（0x221508..0x22150c）
 * @func 0x221508 0x22150c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221508 b 0x221378 <_alutBufferDataConstruct>
 *
 * ══ §1178/1245 OpenAL_Tick()  0x2232d8  size 4  1 条（0x2232d8..0x2232dc）
 * @func 0x2232d8 0x2232e0  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2232d8 bx lr
 *
 * ══ §1179/1245 OpenAL_Close()  0x2232dc  size 4  1 条（0x2232dc..0x2232e0）
 * @func 0x2232dc 0x2232e0  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2232dc bx lr
 *
 * ══ §1180/1245 OpenAL_Quit()  0x2232e4  size 4  1 条（0x2232e4..0x2232e8）
 * @func 0x2232e4 0x2232e8  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2232e4 bx lr
 *
 * ══ §1181/1245 oggpackB_writeinit  0x23329c  size 4  1 条（0x23329c..0x2332a0）
 * @func 0x23329c 0x2332a0  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23329c b 0x233264 <oggpack_writeinit>
 *
 * ══ §1182/1245 oggpackB_writecheck  0x2332c8  size 4  1 条（0x2332c8..0x2332cc）
 * @func 0x2332c8 0x2332cc  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2332c8 b 0x2332a0 <oggpack_writecheck>
 *
 * ══ §1183/1245 oggpackB_reset  0x233398  size 4  1 条（0x233398..0x23339c）
 * @func 0x233398 0x23339c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233398 b 0x233370 <oggpack_reset>
 *
 * ══ §1184/1245 oggpackB_writeclear  0x233858  size 4  1 条（0x233858..0x23385c）
 * @func 0x233858 0x23385c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233858 b 0x23339c <oggpack_writeclear>
 *
 * ══ §1185/1245 oggpackB_readinit  0x233888  size 4  1 条（0x233888..0x23388c）
 * @func 0x233888 0x23388c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233888 b 0x23385c <oggpack_readinit>
 *
 * ══ §1186/1245 oggpackB_adv  0x233aec  size 4  1 条（0x233aec..0x233af0）
 * @func 0x233aec 0x233af0  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233aec b 0x233a7c <oggpack_adv>
 *
 * ══ §1187/1245 oggpackB_adv1  0x233b24  size 4  1 条（0x233b24..0x233b28）
 * @func 0x233b24 0x233b28  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233b24 b 0x233af0 <oggpack_adv1>
 *
 * ══ §1188/1245 oggpackB_bytes  0x233e50  size 4  1 条（0x233e50..0x233e54）
 * @func 0x233e50 0x233e64  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233e50 b 0x233e28 <oggpack_bytes>
 *
 * ══ §1189/1245 oggpackB_bits  0x233e54  size 4  1 条（0x233e54..0x233e58）
 * @func 0x233e54 0x233e64  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233e54 b 0x233e40 <oggpack_bits>
 *
 * ══ §1190/1245 oggpackB_get_buffer  0x233e60  size 4  1 条（0x233e60..0x233e64）
 * @func 0x233e60 0x233e64  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233e60 b 0x233e58 <oggpack_get_buffer>
 *
 * ══ §1191/1245 b2ContactListener::BeginContact(b2Contact*)  0x237acc  size 4  1 条（0x237acc..0x237ad0）
 * @func 0x237acc 0x237adc  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237acc bx lr
 *
 * ══ §1192/1245 b2ContactListener::EndContact(b2Contact*)  0x237ad0  size 4  1 条（0x237ad0..0x237ad4）
 * @func 0x237ad0 0x237adc  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237ad0 bx lr
 *
 * ══ §1193/1245 b2ContactListener::PreSolve(b2Contact*, b2Manifold const*)  0x237ad4  size 4  1 条（0x237ad4..0x237ad8）
 * @func 0x237ad4 0x237adc  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237ad4 bx lr
 *
 * ══ §1194/1245 b2ContactListener::PostSolve(b2Contact*, b2ContactImpulse const*)  0x237ad8  size 4  1 条（0x237ad8..0x237adc）
 * @func 0x237ad8 0x237adc  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237ad8 bx lr
 *
 * ══ §1195/1245 CPhysicsWorld::RegisterContactResult(b2Contact*)  0x238204  size 4  1 条（0x238204..0x238208）
 * @func 0x238204 0x238208  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x238204 b 0x23bec4 <_ZN13ContactsStack4PushEP9b2Contact>
 *
 * ══ §1196/1245 CRunnerContactListener::EndContact(b2Contact*)  0x23be4c  size 4  1 条（0x23be4c..0x23be50）
 * @func 0x23be4c 0x23be60  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23be4c bx lr
 *
 * ══ §1197/1245 CRunnerContactListener::PreSolve(b2Contact*, b2Manifold const*)  0x23be50  size 4  1 条（0x23be50..0x23be54）
 * @func 0x23be50 0x23be64  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23be50 bx lr
 *
 * ══ §1198/1245 F_JS_Function_constructor(RValue&, CInstance*, CInstance*, int, RValue*)  0x23c6cc  size 4  1 条（0x23c6cc..0x23c6d0）
 * @func 0x23c6cc 0x23c6e0  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23c6cc bx lr
 *
 * ══ §1199/1245 LocalTime(double)  0x245114  size 4  1 条（0x245114..0x245118）
 * @func 0x245114 0x24511c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x245114 bx lr
 *
 * ══ §1200/1245 UTC(double)  0x245118  size 4  1 条（0x245118..0x24511c）
 * @func 0x245118 0x24511c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x245118 bx lr
 *
 * ══ §1201/1245 F_JSRegExpCall(RValue&, CInstance*, CInstance*, int, RValue*)  0x25a3e8  size 4  1 条（0x25a3e8..0x25a3ec）
 * @func 0x25a3e8 0x25a3ec  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25a3e8 b 0x259ea8 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_>
 *
 * ══ §1202/1245 pcre_jit_stack_free  0x25f6d0  size 4  1 条（0x25f6d0..0x25f6d4）
 * @func 0x25f6d0 0x25f6dc  size 12  3 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25f6d0 bx lr
 *
 * ══ §1203/1245 pcre_assign_jit_stack  0x25f6d4  size 4  1 条（0x25f6d4..0x25f6d8）
 * @func 0x25f6d4 0x25f6dc  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25f6d4 bx lr
 *
 * ══ §1204/1245 pcre_jit_free_unused_memory  0x25f6d8  size 4  1 条（0x25f6d8..0x25f6dc）
 * @func 0x25f6d8 0x25f6dc  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25f6d8 bx lr
 *
 * ══ §1205/1245 MemoryManager::Quit()  0x27c288  size 4  1 条（0x27c288..0x27c28c）
 * @func 0x27c288 0x27c28c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27c288 bx lr
 *
 * ══ §1206/1245 operator delete[](void*, std::nothrow_t const&)  0x27d1c8  size 4  1 条（0x27d1c8..0x27d1cc）
 * @func 0x27d1c8 0x27d1cc  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27d1c8 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *
 * ══ §1207/1245 operator delete[](void*, char const*, int)  0x27d1d8  size 4  1 条（0x27d1d8..0x27d1dc）
 * @func 0x27d1d8 0x27d1dc  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27d1d8 b 0xb655c <free@plt>
 *
 * ══ §1208/1245 MemoryManager::CheckMemory()  0x27d238  size 4  1 条（0x27d238..0x27d23c）
 * @func 0x27d238 0x27d23c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27d238 bx lr
 *
 * ══ §1209/1245 FlushProfile()  0x27e144  size 4  1 条（0x27e144..0x27e148）
 * @func 0x27e144 0x27e14c  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e144 bx lr
 *
 * ══ §1210/1245 InitProfile()  0x27e148  size 4  1 条（0x27e148..0x27e14c）
 * @func 0x27e148 0x27e14c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e148 bx lr
 *
 * ══ §1211/1245 spScaleTimeline_setFrame  0x282b1c  size 4  1 条（0x282b1c..0x282b20）
 * @func 0x282b1c 0x282b30  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282b1c b 0x282ad4 <spTranslateTimeline_setFrame>
 *
 * ══ §1212/1245 spShearTimeline_setFrame  0x282b38  size 4  1 条（0x282b38..0x282b3c）
 * @func 0x282b38 0x282b4c  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x282b38 b 0x282ad4 <spTranslateTimeline_setFrame>
 *
 * ══ §1213/1245 _spAnimationState_createTrackEntry  0x2830f4  size 4  1 条（0x2830f4..0x2830f8）
 * @func 0x2830f4 0x2830f8  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2830f4 b 0x2830b0 <_spTrackEntry_create>
 *
 * ══ §1214/1245 _spAnimationState_disposeTrackEntry  0x283124  size 4  1 条（0x283124..0x283128）
 * @func 0x283124 0x283128  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x283124 b 0x2830f8 <_spTrackEntry_dispose>
 *
 * ══ §1215/1245 spBoundingBoxAttachment_computeWorldVertices  0x285b40  size 4  1 条（0x285b40..0x285b44）
 * @func 0x285b40 0x285b44  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x285b40 b 0x28fa08 <spVertexAttachment_computeWorldVertices>
 *
 * ══ §1216/1245 spPathAttachment_computeWorldVertices  0x28773c  size 4  1 条（0x28773c..0x287740）
 * @func 0x28773c 0x287740  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28773c b 0x28fa08 <spVertexAttachment_computeWorldVertices>
 *
 * ══ §1217/1245 DrawLogo(int)  0x28fe40  size 4  1 条（0x28fe40..0x28fe44）
 * @func 0x28fe40 0x28fe54  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28fe40 bx lr
 *
 * ══ §1218/1245 Terminate()  0x28fe4c  size 4  1 条（0x28fe4c..0x28fe50）
 * @func 0x28fe4c 0x28fe60  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28fe4c bx lr
 *
 * ══ §1219/1245 FINALIZE_PlatformSpecific()  0x28fe68  size 4  1 条（0x28fe68..0x28fe6c）
 * @func 0x28fe68 0x28fe70  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28fe68 bx lr
 *
 * ══ §1220/1245 INITIALIZE_PlatformSpecific()  0x28fe6c  size 4  1 条（0x28fe6c..0x28fe70）
 * @func 0x28fe6c 0x28fe70  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28fe6c bx lr
 *
 * ══ §1221/1245 yySocket::ShutDown()  0x294d20  size 4  1 条（0x294d20..0x294d24）
 * @func 0x294d20 0x294d28  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x294d20 bx lr
 *
 * ══ §1222/1245 yySocket::DumpError()  0x294d24  size 4  1 条（0x294d24..0x294d28）
 * @func 0x294d24 0x294d28  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x294d24 bx lr
 *
 * ══ §1223/1245 yySocket::Quit()  0x294ed0  size 4  1 条（0x294ed0..0x294ed4）
 * @func 0x294ed0 0x294ed4  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x294ed0 bx lr
 *
 * ══ §1224/1245 yyServer::Render()  0x2971dc  size 4  1 条（0x2971dc..0x2971e0）
 * @func 0x2971dc 0x2971e0  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2971dc bx lr
 *
 * ══ §1225/1245 yyServer::Quit()  0x2974d0  size 4  1 条（0x2974d0..0x2974d4）
 * @func 0x2974d0 0x2974d4  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2974d0 bx lr
 *
 * ══ §1226/1245 Debug_InitRemoteInterface()  0x29bfc8  size 4  1 条（0x29bfc8..0x29bfcc）
 * @func 0x29bfc8 0x29bfcc  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29bfc8 bx lr
 *
 * ══ §1227/1245 endian_swap(unsigned int)  0x29c3a4  size 4  1 条（0x29c3a4..0x29c3a8）
 * @func 0x29c3a4 0x29c3a8  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29c3a4 bx lr
 *
 * ══ §1228/1245 Debug_RestartTarget()  0x29c6bc  size 4  1 条（0x29c6bc..0x29c6c0）
 * @func 0x29c6bc 0x29c6c0  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29c6bc b 0x1c9f54 <_Z19Command_RestartGamev>
 *
 * ══ §1229/1245 Debug_DeleteALLBreakPoints()  0x29cacc  size 4  1 条（0x29cacc..0x29cad0）
 * @func 0x29cacc 0x29cad0  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29cacc b 0xd8374 <_ZN2VM16ResetBreakpointsEv>
 *
 * ══ §1230/1245 png_zfree  0x2a5af0  size 4  1 条（0x2a5af0..0x2a5af4）
 * @func 0x2a5af0 0x2a5b04  size 20  5 条
 * 部分覆盖: 本节 2/3 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a5af0 b.w 0x2a6cfc <png_free>
 *
 * ══ §1231/1245 png_save_int_32  0x2b1134  size 4  1 条（0x2b1134..0x2b1138）
 * @func 0x2b1134 0x2b1140  size 12  3 条
 * 部分覆盖: 本节 2/3 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b1134 b.w 0x2b1124 <png_save_uint_32>
 *
 * ══ §1232/1245 jpeg_destroy_decompress  0x2b2f00  size 4  1 条（0x2b2f00..0x2b2f04）
 * @func 0x2b2f00 0x2b2f08  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b2f00 b 0x2bc8b8 <jpeg_destroy>
 *
 * ══ §1233/1245 jpeg_abort_decompress  0x2b2f04  size 4  1 条（0x2b2f04..0x2b2f08）
 * @func 0x2b2f04 0x2b2f08  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b2f04 b 0x2bc874 <jpeg_abort>
 *
 * ══ §1234/1245 jpeg_mem_term  0x2c1438  size 4  1 条（0x2c1438..0x2c143c）
 * @func 0x2c1438 0x2c143c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c1438 bx lr
 *
 * ══ §1235/1245 _b2relassert(bool, wchar_t const*)  0x2c6a68  size 4  1 条（0x2c6a68..0x2c6a6c）
 * @func 0x2c6a68 0x2c6a6c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c6a68 bx lr
 *
 * ══ §1236/1245 b2Body::~b2Body()  0x2c6bfc  size 4  1 条（0x2c6bfc..0x2c6c00）
 * @func 0x2c6bfc 0x2c6c00  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c6bfc bx lr
 *
 * ══ §1237/1245 b2Joint::ShiftOrigin(b2Vec2 const&)  0x2cc8c0  size 4  1 条（0x2cc8c0..0x2cc8c4）
 * @func 0x2cc8c0 0x2cc8d4  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cc8c0 bx lr
 *
 * ══ §1238/1245 b2ParticleSystem::GetParticleColorBuffer() const  0x2d991c  size 4  1 条（0x2d991c..0x2d9920）
 * @func 0x2d991c 0x2d992c  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d991c b 0x2d987c <_ZN16b2ParticleSystem22GetParticleColorBufferEv>
 *
 * ══ §1239/1245 b2ParticleSystem::GetParticleUserDataBuffer() const  0x2d9928  size 4  1 条（0x2d9928..0x2d992c）
 * @func 0x2d9928 0x2d992c  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d9928 b 0x2d98ac <_ZN16b2ParticleSystem25GetParticleUserDataBufferEv>
 *
 * ══ §1240/1245 b2BroadPhase::TouchProxy(int)  0x2dc8e0  size 4  1 条（0x2dc8e0..0x2dc8e4）
 * @func 0x2dc8e0 0x2dc8e4  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2dc8e0 b 0x2dc81c <_ZN12b2BroadPhase10BufferMoveEi>
 *
 * ══ §1241/1245 FT_Stream_Pos  0x2e6940  size 4  1 条（0x2e6940..0x2e6944）
 * @func 0x2e6940 0x2e6944  size 4  1 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6940 ldr r0, [r0, #0x8]
 *
 * ══ §1242/1245 FT_Done_Memory  0x2e9c74  size 4  1 条（0x2e9c74..0x2e9c78）
 * @func 0x2e9c74 0x2e9c78  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e9c74 b.w 0x31babc <__udivdi3+0x424>
 *
 * ══ §1243/1245 af_shaper_get_coverage  0x309b04  size 4  1 条（0x309b04..0x309b08）
 * @func 0x309b04 0x309b08  size 4  1 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x309b04 movs r0, #0x0
 *
 * ══ §1244/1245 anon_318e0c  0x318e0c  size 4  1 条（0x318e0c..0x318e10）
 * @func 0x318e0c 0x318e10  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x318e0c eor r1, r1, #-2147483648
 *
 * ══ §1245/1245 _Unwind_Complete  0x319bc0  size 4  1 条（0x319bc0..0x319bc4）
 * @func 0x319bc0 0x319bc4  size 4  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x319bc0 bx lr
 */
