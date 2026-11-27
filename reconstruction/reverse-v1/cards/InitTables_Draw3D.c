/* cally 逆向卡：InitTables_Draw3D —— Init*Functions 的 GML 内建注册表（原版 libyoyo.so，armv7）
 * 本卡 5 节，逐节一个 @func；锚点来自 asm/instructions.jsonl（census），
 * 注册表来自 scripts/init_table_extract.py：CFG 走指令流，池字按 Align(PC,4)+imm 读，
 * GOT 槽按 .rel.dyn 的 RELATIVE/GLOB_DAT 解析，名字串按 r0 指针读，函数指针查 asm/functions.tsv。
 * 级别: 正文（每个函数的注册条数、名字、函数指针、argc、flag 与控制流分支逐条落锚；
 *        个别实参来自运行期全局字节的行在本节 open 里点名，不填猜值）
 * 表: reconstruction/reverse-v1/asm/init-tables/init-<Func>.tsv
 *
 * ── 控件（生成器每次重跑都先验这三条，不合即拒绝出卡）──
 *   InitYoYoFunctions       385 条 / 152 个函数指针 / flag 1:202 0:183  ← cards/InitYoYoFunctions.c
 *   InitDataStructures      130 条 / argc 1:45 2:30 3:19 5:10 4:9 6:6 0:5 8:3 -1:3 / flag 全 1 ← OPS-NOTES.md
 *   InitMath                117 条 / argc 1:62 2:18 3:17 -1:6 4:5 6:4 0:4 5:1 ← OPS-NOTES.md
 *
 * 本卡节: §1 InitGraphicFunctions 0x12326c→306 条｜§2 Init3DFunctions 0x149f4c→193 条｜§3 InitBufferFunctions 0xc75fc→37 条｜§4 InitBufferVertexFunctions 0xca9a0→23 条｜§5 InitShaderFunctions 0x1e2184→16 条
 *
 * ══ §1/5 InitGraphicFunctions  0x12326c..0x125d04  size 10904  2726 条（2145 条指令 + 581 个池字）══
 * @func 0x12326c 0x125d04  size 10904  2726 条
 * 注册 306 条｜唯一名 306｜唯一函数指针 274｜argc 0:46 1:102 2:42 3:29 4:16 5:12 6:9 7:15 8:10 9:5 10:5 11:9 12:1 13:2 15:2 16:1｜flag 0:163 1:143
 * 首条 #0 display_get_width（0x123290）→ 末条 #305 draw_get_swf_aa_level（0x125c90）
 * 名字族（前 8）: draw×113 window×43 tile×35 skeleton×26 display×23 surface×20 texture×12 make×6
 * 游戏实际调用的 99 个内建里落在本表: 15 个（display_get_height, display_get_width, draw_background, draw_background_ext, draw_healthbar, draw_self, draw_set_alpha, draw_set_color, draw_set_font, draw_sprite, draw_sprite_ext, draw_text, draw_text_color, window_get_height, window_get_width）
 * 表: asm/init-tables/init-InitGraphicFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: 无（本函数每条注册的四实参全部解出，控制流全部走到）
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12326c push {r4, r5, r6, lr}
 *   @0x123270 mov r2, #0
 *   @0x123274 ldr r4, [pc, #0xff4]
 *   @0x123278 mov r3, r2
 *   @0x12327c ldr r1, [pc, #0xff0]
 *   @0x123280 add r4, pc, r4
 *   @0x123284 ldr r0, [pc, #0xfec]
 *   @0x123288 ldr r1, [r4, r1]
 *   @0x12328c add r0, pc, r0
 *   @0x123290 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 display_get_width → F_DisplayGetWidth(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x123294 ldr r1, [pc, #0xfe0]
 *   @0x123298 ldr r0, [pc, #0xfe0]
 *   @0x12329c mov r2, #0
 *   @0x1232a0 mov r3, r2
 *   @0x1232a4 ldr r1, [r4, r1]
 *   @0x1232a8 add r0, pc, r0
 *   @0x1232ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 display_get_height → F_DisplayGetHeight(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1232b0 ldr r1, [pc, #0xfcc]
 *   @0x1232b4 ldr r0, [pc, #0xfcc]
 *   @0x1232b8 mov r2, #0
 *   @0x1232bc mov r3, r2
 *   @0x1232c0 ldr r1, [r4, r1]
 *   @0x1232c4 add r0, pc, r0
 *   @0x1232c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 display_get_colordepth → F_DisplayGetColordepth(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1232cc ldr r1, [pc, #0xfb8]
 *   @0x1232d0 ldr r0, [pc, #0xfb8]
 *   @0x1232d4 mov r2, #0
 *   @0x1232d8 mov r3, r2
 *   @0x1232dc ldr r1, [r4, r1]
 *   @0x1232e0 add r0, pc, r0
 *   @0x1232e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 display_get_frequency → F_DisplayGetFrequency(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1232e8 ldr r1, [pc, #0xfa4]
 *   @0x1232ec ldr r0, [pc, #0xfa4]
 *   @0x1232f0 mov r2, #0
 *   @0x1232f4 mov r3, r2
 *   @0x1232f8 ldr r1, [r4, r1]
 *   @0x1232fc add r0, pc, r0
 *   @0x123300 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #4 display_get_orientation → F_DisplayGetOrientation(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x123304 ldr r1, [pc, #0xf90]
 *   @0x123308 ldr r0, [pc, #0xf90]
 *   @0x12330c mov r2, #2
 *   @0x123310 mov r3, #1
 *   @0x123314 ldr r1, [r4, r1]
 *   @0x123318 add r0, pc, r0
 *   @0x12331c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #5 display_set_size → F_DisplaySetSize(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x123320 ldr r1, [pc, #0xf7c]
 *   @0x123324 ldr r0, [pc, #0xf7c]
 *   @0x123328 mov r2, #1
 *   @0x12332c mov r3, r2
 *   @0x123330 ldr r1, [r4, r1]
 *   @0x123334 add r0, pc, r0
 *   @0x123338 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #6 display_set_colordepth → F_DisplaySetColordepth(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x12333c ldr r1, [pc, #0xf68]
 *   @0x123340 ldr r0, [pc, #0xf68]
 *   @0x123344 mov r2, #1
 *   @0x123348 mov r3, r2
 *   @0x12334c ldr r1, [r4, r1]
 *   @0x123350 add r0, pc, r0
 *   @0x123354 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #7 display_set_frequency → F_DisplaySetFrequency(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x123358 ldr r1, [pc, #0xf54]
 *   @0x12335c ldr r0, [pc, #0xf54]
 *   @0x123360 mov r2, #4
 *   @0x123364 mov r3, #1
 *   @0x123368 ldr r1, [r4, r1]
 *   @0x12336c add r0, pc, r0
 *   @0x123370 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #8 display_set_all → F_DisplaySetAll(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x123374 ldr r1, [pc, #0xf40]
 *   @0x123378 ldr r0, [pc, #0xf40]
 *   @0x12337c mov r2, #4
 *   @0x123380 mov r3, #1
 *   @0x123384 ldr r1, [r4, r1]
 *   @0x123388 add r0, pc, r0
 *   @0x12338c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #9 display_test_all → F_DisplayTestAll(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x123390 ldr r1, [pc, #0xf2c]
 *   @0x123394 ldr r0, [pc, #0xf2c]
 *   @0x123398 mov r2, #1
 *   @0x12339c mov r3, r2
 *   @0x1233a0 ldr r1, [r4, r1]
 *   @0x1233a4 add r0, pc, r0
 *   @0x1233a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #10 display_reset → F_DisplayReset(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1233ac ldr r1, [pc, #0xf18]
 *   @0x1233b0 ldr r0, [pc, #0xf18]
 *   @0x1233b4 mov r2, #0
 *   @0x1233b8 mov r3, r2
 *   @0x1233bc ldr r1, [r4, r1]
 *   @0x1233c0 add r0, pc, r0
 *   @0x1233c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #11 display_mouse_get_x → F_DisplayMouseGetX(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1233c8 ldr r1, [pc, #0xf04]
 *   @0x1233cc ldr r0, [pc, #0xf04]
 *   @0x1233d0 mov r2, #0
 *   @0x1233d4 mov r3, r2
 *   @0x1233d8 ldr r1, [r4, r1]
 *   @0x1233dc add r0, pc, r0
 *   @0x1233e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #12 display_mouse_get_y → F_DisplayMouseGetY(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1233e4 ldr r1, [pc, #0xef0]
 *   @0x1233e8 ldr r0, [pc, #0xef0]
 *   @0x1233ec mov r2, #2
 *   @0x1233f0 mov r3, #0
 *   @0x1233f4 ldr r1, [r4, r1]
 *   @0x1233f8 add r0, pc, r0
 *   @0x1233fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #13 display_mouse_set → F_DisplayMouseSet(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x123400 ldr r1, [pc, #0xedc]
 *   @0x123404 ldr r0, [pc, #0xedc]
 *   @0x123408 mov r2, #1
 *   @0x12340c mov r3, #0
 *   @0x123410 ldr r1, [r4, r1]
 *   @0x123414 add r0, pc, r0
 *   @0x123418 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #14 draw_enable_drawevent → F_DrawEnableDrawEvent(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x12341c ldr r1, [pc, #0xec8]
 *   @0x123420 ldr r0, [pc, #0xec8]
 *   @0x123424 mov r2, #0
 *   @0x123428 mov r3, r2
 *   @0x12342c ldr r1, [r4, r1]
 *   @0x123430 add r0, pc, r0
 *   @0x123434 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #15 display_get_windows_vertex_buffer_method → F_DrawGetWindowsVertexBufferMethod(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x123438 ldr r1, [pc, #0xeb4]
 *   @0x12343c ldr r0, [pc, #0xeb4]
 *   @0x123440 mov r2, #0
 *   @0x123444 mov r3, r2
 *   @0x123448 ldr r1, [r4, r1]
 *   @0x12344c add r0, pc, r0
 *   @0x123450 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #16 display_get_windows_alternate_sync → F_DrawGetWindowsAlternateSync(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x123454 ldr r1, [pc, #0xea0]
 *   @0x123458 ldr r0, [pc, #0xea0]
 *   @0x12345c mov r2, #1
 *   @0x123460 mov r3, #0
 *   @0x123464 ldr r1, [r4, r1]
 *   @0x123468 add r0, pc, r0
 *   @0x12346c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #17 display_set_windows_vertex_buffer_method → F_DrawSetWindowsVertexBufferMethod(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123470 ldr r1, [pc, #0xe8c]
 *   @0x123474 ldr r0, [pc, #0xe8c]
 *   @0x123478 mov r2, #1
 *   @0x12347c mov r3, #0
 *   @0x123480 ldr r1, [r4, r1]
 *   @0x123484 add r0, pc, r0
 *   @0x123488 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #18 display_set_windows_alternate_sync → F_DrawSetWindowsAlternateSync(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x12348c ldr r1, [pc, #0xe78]
 *   @0x123490 ldr r0, [pc, #0xe78]
 *   @0x123494 mov r2, #1
 *   @0x123498 mov r3, #0
 *   @0x12349c ldr r1, [r4, r1]
 *   @0x1234a0 add r0, pc, r0
 *   @0x1234a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #19 display_set_ui_visibility → F_DisplaySetUIVisibility(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1234a8 ldr r1, [pc, #0xe64]
 *   @0x1234ac ldr r0, [pc, #0xe64]
 *   @0x1234b0 mov r2, #1
 *   @0x1234b4 mov r3, #0
 *   @0x1234b8 ldr r1, [r4, r1]
 *   @0x1234bc add r0, pc, r0
 *   @0x1234c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #20 display_set_timing_method → F_DisplaySetTimingMethod(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1234c4 ldr r1, [pc, #0xe50]
 *   @0x1234c8 ldr r0, [pc, #0xe50]
 *   @0x1234cc mov r2, #0
 *   @0x1234d0 mov r3, r2
 *   @0x1234d4 ldr r1, [r4, r1]
 *   @0x1234d8 add r0, pc, r0
 *   @0x1234dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #21 display_get_timing_method → F_DisplayGetTimingMethod(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1234e0 ldr r1, [pc, #0xe3c]
 *   @0x1234e4 ldr r0, [pc, #0xe3c]
 *   @0x1234e8 mov r2, #1
 *   @0x1234ec mov r3, #0
 *   @0x1234f0 ldr r1, [r4, r1]
 *   @0x1234f4 add r0, pc, r0
 *   @0x1234f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #22 display_set_sleep_margin → F_DisplaySetSleepMargin(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1234fc ldr r1, [pc, #0xe28]
 *   @0x123500 ldr r0, [pc, #0xe28]
 *   @0x123504 mov r2, #0
 *   @0x123508 mov r3, r2
 *   @0x12350c ldr r1, [r4, r1]
 *   @0x123510 add r0, pc, r0
 *   @0x123514 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #23 display_get_sleep_margin → F_DisplayGetSleepMargin(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x123518 ldr r1, [pc, #0xe14]
 *   @0x12351c ldr r0, [pc, #0xe14]
 *   @0x123520 mov r2, #1
 *   @0x123524 mov r3, #0
 *   @0x123528 ldr r1, [r4, r1]
 *   @0x12352c add r0, pc, r0
 *   @0x123530 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #24 window_set_visible → F_WindowSetVisible(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123534 ldr r1, [pc, #0xe00]
 *   @0x123538 ldr r0, [pc, #0xe00]
 *   @0x12353c mov r2, #0
 *   @0x123540 mov r3, r2
 *   @0x123544 ldr r1, [r4, r1]
 *   @0x123548 add r0, pc, r0
 *   @0x12354c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #25 window_get_visible → F_WindowGetVisible(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x123550 ldr r1, [pc, #0xdec]
 *   @0x123554 ldr r0, [pc, #0xdec]
 *   @0x123558 mov r2, #1
 *   @0x12355c mov r3, #0
 *   @0x123560 ldr r1, [r4, r1]
 *   @0x123564 add r0, pc, r0
 *   @0x123568 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #26 window_set_fullscreen → F_WindowSetFullscreen(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x12356c ldr r1, [pc, #0xdd8]
 *   @0x123570 ldr r0, [pc, #0xdd8]
 *   @0x123574 mov r2, #0
 *   @0x123578 mov r3, r2
 *   @0x12357c ldr r1, [r4, r1]
 *   @0x123580 add r0, pc, r0
 *   @0x123584 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #27 window_get_fullscreen → F_WindowGetFullscreen(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x123588 ldr r1, [pc, #0xdc4]
 *   @0x12358c ldr r0, [pc, #0xdc4]
 *   @0x123590 mov r2, #1
 *   @0x123594 mov r3, #0
 *   @0x123598 ldr r1, [r4, r1]
 *   @0x12359c add r0, pc, r0
 *   @0x1235a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #28 window_set_showborder → F_WindowSetShowborder(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1235a4 ldr r1, [pc, #0xdb0]
 *   @0x1235a8 ldr r0, [pc, #0xdb0]
 *   @0x1235ac mov r2, #0
 *   @0x1235b0 mov r3, r2
 *   @0x1235b4 ldr r1, [r4, r1]
 *   @0x1235b8 add r0, pc, r0
 *   @0x1235bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #29 window_get_showborder → F_WindowGetShowborder(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1235c0 ldr r1, [pc, #0xd9c]
 *   @0x1235c4 ldr r0, [pc, #0xd9c]
 *   @0x1235c8 mov r2, #1
 *   @0x1235cc mov r3, #0
 *   @0x1235d0 ldr r1, [r4, r1]
 *   @0x1235d4 add r0, pc, r0
 *   @0x1235d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #30 window_set_showicons → F_WindowSetShowicons(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1235dc ldr r1, [pc, #0xd88]
 *   @0x1235e0 ldr r0, [pc, #0xd88]
 *   @0x1235e4 mov r2, #0
 *   @0x1235e8 mov r3, r2
 *   @0x1235ec ldr r1, [r4, r1]
 *   @0x1235f0 add r0, pc, r0
 *   @0x1235f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #31 window_get_showicons → F_WindowGetShowicons(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1235f8 ldr r1, [pc, #0xd74]
 *   @0x1235fc ldr r0, [pc, #0xd74]
 *   @0x123600 mov r2, #1
 *   @0x123604 mov r3, #0
 *   @0x123608 ldr r1, [r4, r1]
 *   @0x12360c add r0, pc, r0
 *   @0x123610 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #32 window_set_stayontop → F_WindowSetStayontop(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123614 ldr r1, [pc, #0xd60]
 *   @0x123618 ldr r0, [pc, #0xd60]
 *   @0x12361c mov r2, #0
 *   @0x123620 mov r3, r2
 *   @0x123624 ldr r1, [r4, r1]
 *   @0x123628 add r0, pc, r0
 *   @0x12362c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #33 window_get_stayontop → F_WindowGetStayontop(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x123630 ldr r1, [pc, #0xd4c]
 *   @0x123634 ldr r0, [pc, #0xd4c]
 *   @0x123638 mov r2, #1
 *   @0x12363c mov r3, #0
 *   @0x123640 ldr r1, [r4, r1]
 *   @0x123644 add r0, pc, r0
 *   @0x123648 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #34 window_set_sizeable → F_WindowSetSizeable(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x12364c ldr r1, [pc, #0xd38]
 *   @0x123650 ldr r0, [pc, #0xd38]
 *   @0x123654 mov r2, #0
 *   @0x123658 mov r3, r2
 *   @0x12365c ldr r1, [r4, r1]
 *   @0x123660 add r0, pc, r0
 *   @0x123664 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #35 window_get_sizeable → F_WindowGetSizeable(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x123668 ldr r1, [pc, #0xd24]
 *   @0x12366c ldr r0, [pc, #0xd24]
 *   @0x123670 mov r2, #1
 *   @0x123674 mov r3, #0
 *   @0x123678 ldr r1, [r4, r1]
 *   @0x12367c add r0, pc, r0
 *   @0x123680 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #36 window_set_caption → F_WindowSetCaption(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123684 ldr r1, [pc, #0xd10]
 *   @0x123688 ldr r0, [pc, #0xd10]
 *   @0x12368c mov r2, #0
 *   @0x123690 mov r3, r2
 *   @0x123694 ldr r1, [r4, r1]
 *   @0x123698 add r0, pc, r0
 *   @0x12369c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #37 window_get_caption → F_WindowGetCaption(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1236a0 ldr r1, [pc, #0xcfc]
 *   @0x1236a4 ldr r0, [pc, #0xcfc]
 *   @0x1236a8 mov r2, #1
 *   @0x1236ac mov r3, #0
 *   @0x1236b0 ldr r1, [r4, r1]
 *   @0x1236b4 add r0, pc, r0
 *   @0x1236b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #38 window_set_cursor → F_WindowSetCursor(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1236bc ldr r1, [pc, #0xce8]
 *   @0x1236c0 ldr r0, [pc, #0xce8]
 *   @0x1236c4 mov r2, #0
 *   @0x1236c8 mov r3, r2
 *   @0x1236cc ldr r1, [r4, r1]
 *   @0x1236d0 add r0, pc, r0
 *   @0x1236d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #39 window_get_cursor → F_WindowGetCursor(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1236d8 ldr r1, [pc, #0xcd4]
 *   @0x1236dc ldr r0, [pc, #0xcd4]
 *   @0x1236e0 mov r2, #1
 *   @0x1236e4 mov r3, #0
 *   @0x1236e8 ldr r5, [r4, r1]
 *   @0x1236ec add r0, pc, r0
 *   @0x1236f0 mov r1, r5
 *   @0x1236f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #40 window_set_color → F_WindowSetColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1236f8 ldr r0, [pc, #0xcbc]
 *   @0x1236fc mov r1, r5
 *   @0x123700 mov r2, #1
 *   @0x123704 add r0, pc, r0
 *   @0x123708 mov r3, #0
 *   @0x12370c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #41 window_set_colour → F_WindowSetColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123710 ldr r1, [pc, #0xca8]
 *   @0x123714 ldr r0, [pc, #0xca8]
 *   @0x123718 mov r2, #0
 *   @0x12371c mov r3, r2
 *   @0x123720 ldr r5, [r4, r1]
 *   @0x123724 add r0, pc, r0
 *   @0x123728 mov r1, r5
 *   @0x12372c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #42 window_get_color → F_WindowGetColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x123730 ldr r0, [pc, #0xc90]
 *   @0x123734 mov r2, #0
 *   @0x123738 mov r1, r5
 *   @0x12373c mov r3, r2
 *   @0x123740 add r0, pc, r0
 *   @0x123744 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #43 window_get_colour → F_WindowGetColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x123748 ldr r1, [pc, #0xc7c]
 *   @0x12374c ldr r0, [pc, #0xc7c]
 *   @0x123750 mov r2, #1
 *   @0x123754 mov r3, #0
 *   @0x123758 ldr r1, [r4, r1]
 *   @0x12375c add r0, pc, r0
 *   @0x123760 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #44 window_set_min_width → F_WindowSetMinWidth(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123764 ldr r1, [pc, #0xc68]
 *   @0x123768 ldr r0, [pc, #0xc68]
 *   @0x12376c mov r2, #1
 *   @0x123770 mov r3, #0
 *   @0x123774 ldr r1, [r4, r1]
 *   @0x123778 add r0, pc, r0
 *   @0x12377c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #45 window_set_max_width → F_WindowSetMaxWidth(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123780 ldr r1, [pc, #0xc54]
 *   @0x123784 ldr r0, [pc, #0xc54]
 *   @0x123788 mov r2, #1
 *   @0x12378c mov r3, #0
 *   @0x123790 ldr r1, [r4, r1]
 *   @0x123794 add r0, pc, r0
 *   @0x123798 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #46 window_set_min_height → F_WindowSetMinHeight(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x12379c ldr r1, [pc, #0xc40]
 *   @0x1237a0 ldr r0, [pc, #0xc40]
 *   @0x1237a4 mov r2, #1
 *   @0x1237a8 mov r3, #0
 *   @0x1237ac ldr r1, [r4, r1]
 *   @0x1237b0 add r0, pc, r0
 *   @0x1237b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #47 window_set_max_height → F_WindowSetMaxHeight(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1237b8 ldr r1, [pc, #0xc2c]
 *   @0x1237bc ldr r0, [pc, #0xc2c]
 *   @0x1237c0 mov r2, #2
 *   @0x1237c4 mov r3, #0
 *   @0x1237c8 ldr r1, [r4, r1]
 *   @0x1237cc add r0, pc, r0
 *   @0x1237d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #48 window_set_position → F_WindowSetPosition(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1237d4 ldr r1, [pc, #0xc18]
 *   @0x1237d8 ldr r0, [pc, #0xc18]
 *   @0x1237dc mov r2, #2
 *   @0x1237e0 mov r3, #0
 *   @0x1237e4 ldr r1, [r4, r1]
 *   @0x1237e8 add r0, pc, r0
 *   @0x1237ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #49 window_set_size → F_WindowSetSize(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1237f0 ldr r1, [pc, #0xc04]
 *   @0x1237f4 ldr r0, [pc, #0xc04]
 *   @0x1237f8 mov r2, #4
 *   @0x1237fc mov r3, #0
 *   @0x123800 ldr r1, [r4, r1]
 *   @0x123804 add r0, pc, r0
 *   @0x123808 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #50 window_set_rectangle → F_WindowSetRectangle(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x12380c ldr r1, [pc, #0xbf0]
 *   @0x123810 ldr r0, [pc, #0xbf0]
 *   @0x123814 mov r2, #0
 *   @0x123818 mov r3, r2
 *   @0x12381c ldr r1, [r4, r1]
 *   @0x123820 add r0, pc, r0
 *   @0x123824 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #51 window_center → F_WindowCenter(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x123828 ldr r1, [pc, #0xbdc]
 *   @0x12382c ldr r0, [pc, #0xbdc]
 *   @0x123830 mov r2, #0
 *   @0x123834 mov r3, r2
 *   @0x123838 ldr r1, [r4, r1]
 *   @0x12383c add r0, pc, r0
 *   @0x123840 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #52 window_default → F_WindowDefault(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x123844 ldr r1, [pc, #0xbc8]
 *   @0x123848 ldr r0, [pc, #0xbc8]
 *   @0x12384c mov r2, #0
 *   @0x123850 mov r3, r2
 *   @0x123854 ldr r1, [r4, r1]
 *   @0x123858 add r0, pc, r0
 *   @0x12385c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #53 window_get_x → F_WindowGetX(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x123860 ldr r1, [pc, #0xbb4]
 *   @0x123864 ldr r0, [pc, #0xbb4]
 *   @0x123868 mov r2, #0
 *   @0x12386c mov r3, r2
 *   @0x123870 ldr r1, [r4, r1]
 *   @0x123874 add r0, pc, r0
 *   @0x123878 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #54 window_get_y → F_WindowGetY(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x12387c ldr r1, [pc, #0xba0]
 *   @0x123880 ldr r0, [pc, #0xba0]
 *   @0x123884 mov r2, #0
 *   @0x123888 mov r3, r2
 *   @0x12388c ldr r1, [r4, r1]
 *   @0x123890 add r0, pc, r0
 *   @0x123894 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #55 window_get_width → F_WindowGetWidth(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x123898 ldr r1, [pc, #0xb8c]
 *   @0x12389c ldr r0, [pc, #0xb8c]
 *   @0x1238a0 mov r2, #0
 *   @0x1238a4 mov r3, r2
 *   @0x1238a8 ldr r1, [r4, r1]
 *   @0x1238ac add r0, pc, r0
 *   @0x1238b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #56 window_get_height → F_WindowGetHeight(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1238b4 ldr r1, [pc, #0xb78]
 *   @0x1238b8 ldr r0, [pc, #0xb78]
 *   @0x1238bc mov r2, #4
 *   @0x1238c0 mov r3, #0
 *   @0x1238c4 ldr r1, [r4, r1]
 *   @0x1238c8 add r0, pc, r0
 *   @0x1238cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #57 window_get_visible_rects → F_DisplayGetVisibleRects(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x1238d0 ldr r1, [pc, #0xb64]
 *   @0x1238d4 ldr r0, [pc, #0xb64]
 *   @0x1238d8 mov r2, #0
 *   @0x1238dc mov r3, r2
 *   @0x1238e0 ldr r1, [r4, r1]
 *   @0x1238e4 add r0, pc, r0
 *   @0x1238e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #58 window_mouse_get_x → F_WindowMouseGetX(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1238ec ldr r1, [pc, #0xb50]
 *   @0x1238f0 ldr r0, [pc, #0xb50]
 *   @0x1238f4 mov r2, #0
 *   @0x1238f8 mov r3, r2
 *   @0x1238fc ldr r1, [r4, r1]
 *   @0x123900 add r0, pc, r0
 *   @0x123904 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #59 window_mouse_get_y → F_WindowMouseGetY(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x123908 ldr r1, [pc, #0xb3c]
 *   @0x12390c ldr r0, [pc, #0xb3c]
 *   @0x123910 mov r2, #2
 *   @0x123914 mov r3, #0
 *   @0x123918 ldr r1, [r4, r1]
 *   @0x12391c add r0, pc, r0
 *   @0x123920 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #60 window_mouse_set → F_WindowMouseSet(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x123924 ldr r1, [pc, #0xb28]
 *   @0x123928 ldr r0, [pc, #0xb28]
 *   @0x12392c mov r2, #1
 *   @0x123930 mov r3, #0
 *   @0x123934 ldr r1, [r4, r1]
 *   @0x123938 add r0, pc, r0
 *   @0x12393c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #61 window_view_mouse_get_x → F_WindowViewMouseGetX(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123940 ldr r1, [pc, #0xb14]
 *   @0x123944 ldr r0, [pc, #0xb14]
 *   @0x123948 mov r2, #1
 *   @0x12394c mov r3, #0
 *   @0x123950 ldr r1, [r4, r1]
 *   @0x123954 add r0, pc, r0
 *   @0x123958 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #62 window_view_mouse_get_y → F_WindowViewMouseGetY(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x12395c ldr r1, [pc, #0xb00]
 *   @0x123960 ldr r0, [pc, #0xb00]
 *   @0x123964 mov r2, #3
 *   @0x123968 mov r3, #0
 *   @0x12396c ldr r1, [r4, r1]
 *   @0x123970 add r0, pc, r0
 *   @0x123974 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #63 window_view_mouse_set → F_WindowViewMouseSet(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x123978 ldr r1, [pc, #0xaec]
 *   @0x12397c ldr r0, [pc, #0xaec]
 *   @0x123980 mov r2, #0
 *   @0x123984 mov r3, r2
 *   @0x123988 ldr r1, [r4, r1]
 *   @0x12398c add r0, pc, r0
 *   @0x123990 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #64 window_views_mouse_get_x → F_WindowViewsMouseGetX(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x123994 ldr r1, [pc, #0xad8]
 *   @0x123998 ldr r0, [pc, #0xad8]
 *   @0x12399c mov r2, #0
 *   @0x1239a0 mov r3, r2
 *   @0x1239a4 ldr r1, [r4, r1]
 *   @0x1239a8 add r0, pc, r0
 *   @0x1239ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #65 window_views_mouse_get_y → F_WindowViewsMouseGetY(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1239b0 ldr r1, [pc, #0xac4]
 *   @0x1239b4 ldr r0, [pc, #0xac4]
 *   @0x1239b8 mov r2, #2
 *   @0x1239bc mov r3, #0
 *   @0x1239c0 ldr r1, [r4, r1]
 *   @0x1239c4 add r0, pc, r0
 *   @0x1239c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #66 window_views_mouse_set → F_WindowViewsMouseSet(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1239cc ldr r1, [pc, #0xab0]
 *   @0x1239d0 ldr r0, [pc, #0xab0]
 *   @0x1239d4 mov r2, #1
 *   @0x1239d8 mov r3, #0
 *   @0x1239dc ldr r1, [r4, r1]
 *   @0x1239e0 add r0, pc, r0
 *   @0x1239e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #67 screen_save → F_ScreenSave(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1239e8 ldr r1, [pc, #0xa9c]
 *   @0x1239ec ldr r0, [pc, #0xa9c]
 *   @0x1239f0 mov r2, #5
 *   @0x1239f4 mov r3, #0
 *   @0x1239f8 ldr r1, [r4, r1]
 *   @0x1239fc add r0, pc, r0
 *   @0x123a00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #68 screen_save_part → F_ScreenSavePart(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0x123a04 ldr r1, [pc, #0xa88]
 *   @0x123a08 ldr r0, [pc, #0xa88]
 *   @0x123a0c mov r2, #2
 *   @0x123a10 mov r3, #0
 *   @0x123a14 ldr r1, [r4, r1]
 *   @0x123a18 add r0, pc, r0
 *   @0x123a1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #69 draw_getpixel → F_DrawGetPixel(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x123a20 ldr r1, [pc, #0xa74]
 *   @0x123a24 ldr r0, [pc, #0xa74]
 *   @0x123a28 mov r2, #2
 *   @0x123a2c mov r3, #0
 *   @0x123a30 ldr r1, [r4, r1]
 *   @0x123a34 add r0, pc, r0
 *   @0x123a38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #70 draw_getpixel_ext → F_DrawGetPixelExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x123a3c ldr r1, [pc, #0xa60]
 *   @0x123a40 ldr r0, [pc, #0xa60]
 *   @0x123a44 mov r2, #1
 *   @0x123a48 mov r3, #0
 *   @0x123a4c ldr r5, [r4, r1]
 *   @0x123a50 add r0, pc, r0
 *   @0x123a54 mov r1, r5
 *   @0x123a58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #71 draw_set_color → F_DrawSetColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123a5c ldr r0, [pc, #0xa48]
 *   @0x123a60 mov r1, r5
 *   @0x123a64 mov r2, #1
 *   @0x123a68 add r0, pc, r0
 *   @0x123a6c mov r3, #0
 *   @0x123a70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #72 draw_set_colour → F_DrawSetColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123a74 ldr r1, [pc, #0xa34]
 *   @0x123a78 ldr r0, [pc, #0xa34]
 *   @0x123a7c mov r2, #1
 *   @0x123a80 mov r3, #0
 *   @0x123a84 ldr r1, [r4, r1]
 *   @0x123a88 add r0, pc, r0
 *   @0x123a8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #73 draw_set_alpha → F_DrawSetAlpha(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123a90 ldr r1, [pc, #0xa20]
 *   @0x123a94 ldr r0, [pc, #0xa20]
 *   @0x123a98 mov r2, #0
 *   @0x123a9c mov r3, r2
 *   @0x123aa0 ldr r5, [r4, r1]
 *   @0x123aa4 add r0, pc, r0
 *   @0x123aa8 mov r1, r5
 *   @0x123aac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #74 draw_get_color → F_DrawGetColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x123ab0 ldr r0, [pc, #0xa08]
 *   @0x123ab4 mov r2, #0
 *   @0x123ab8 mov r1, r5
 *   @0x123abc mov r3, r2
 *   @0x123ac0 add r0, pc, r0
 *   @0x123ac4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #75 draw_get_colour → F_DrawGetColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x123ac8 ldr r1, [pc, #0x9f4]
 *   @0x123acc ldr r0, [pc, #0x9f4]
 *   @0x123ad0 mov r2, #0
 *   @0x123ad4 mov r3, r2
 *   @0x123ad8 ldr r1, [r4, r1]
 *   @0x123adc add r0, pc, r0
 *   @0x123ae0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #76 draw_get_alpha → F_DrawGetAlpha(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x123ae4 ldr r1, [pc, #0x9e0]
 *   @0x123ae8 ldr r0, [pc, #0x9e0]
 *   @0x123aec mov r2, #3
 *   @0x123af0 mov r3, #0
 *   @0x123af4 ldr r5, [r4, r1]
 *   @0x123af8 add r0, pc, r0
 *   @0x123afc mov r1, r5
 *   @0x123b00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #77 make_color → F_MakeColorRGB(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x123b04 ldr r0, [pc, #0x9c8]
 *   @0x123b08 mov r1, r5
 *   @0x123b0c mov r2, #3
 *   @0x123b10 add r0, pc, r0
 *   @0x123b14 mov r3, #0
 *   @0x123b18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #78 make_colour → F_MakeColorRGB(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x123b1c ldr r0, [pc, #0x9b4]
 *   @0x123b20 mov r1, r5
 *   @0x123b24 mov r2, #3
 *   @0x123b28 add r0, pc, r0
 *   @0x123b2c mov r3, #0
 *   @0x123b30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #79 make_color_rgb → F_MakeColorRGB(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x123b34 ldr r0, [pc, #0x9a0]
 *   @0x123b38 mov r1, r5
 *   @0x123b3c mov r2, #3
 *   @0x123b40 add r0, pc, r0
 *   @0x123b44 mov r3, #0
 *   @0x123b48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #80 make_colour_rgb → F_MakeColorRGB(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x123b4c ldr r1, [pc, #0x98c]
 *   @0x123b50 ldr r0, [pc, #0x98c]
 *   @0x123b54 mov r2, #3
 *   @0x123b58 mov r3, #0
 *   @0x123b5c ldr r5, [r4, r1]
 *   @0x123b60 add r0, pc, r0
 *   @0x123b64 mov r1, r5
 *   @0x123b68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #81 make_color_hsv → F_MakeColorHSV(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x123b6c ldr r0, [pc, #0x974]
 *   @0x123b70 mov r1, r5
 *   @0x123b74 mov r2, #3
 *   @0x123b78 add r0, pc, r0
 *   @0x123b7c mov r3, #0
 *   @0x123b80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #82 make_colour_hsv → F_MakeColorHSV(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x123b84 ldr r1, [pc, #0x960]
 *   @0x123b88 ldr r0, [pc, #0x960]
 *   @0x123b8c mov r2, #1
 *   @0x123b90 mov r3, #0
 *   @0x123b94 ldr r5, [r4, r1]
 *   @0x123b98 add r0, pc, r0
 *   @0x123b9c mov r1, r5
 *   @0x123ba0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #83 color_get_red → F_ColorGetRed(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123ba4 ldr r0, [pc, #0x948]
 *   @0x123ba8 mov r1, r5
 *   @0x123bac mov r2, #1
 *   @0x123bb0 add r0, pc, r0
 *   @0x123bb4 mov r3, #0
 *   @0x123bb8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #84 colour_get_red → F_ColorGetRed(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123bbc ldr r1, [pc, #0x934]
 *   @0x123bc0 ldr r0, [pc, #0x934]
 *   @0x123bc4 mov r2, #1
 *   @0x123bc8 mov r3, #0
 *   @0x123bcc ldr r5, [r4, r1]
 *   @0x123bd0 add r0, pc, r0
 *   @0x123bd4 mov r1, r5
 *   @0x123bd8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #85 color_get_green → F_ColorGetGreen(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123bdc ldr r0, [pc, #0x91c]
 *   @0x123be0 mov r1, r5
 *   @0x123be4 mov r2, #1
 *   @0x123be8 add r0, pc, r0
 *   @0x123bec mov r3, #0
 *   @0x123bf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #86 colour_get_green → F_ColorGetGreen(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123bf4 ldr r1, [pc, #0x908]
 *   @0x123bf8 ldr r0, [pc, #0x908]
 *   @0x123bfc mov r2, #1
 *   @0x123c00 mov r3, #0
 *   @0x123c04 ldr r5, [r4, r1]
 *   @0x123c08 add r0, pc, r0
 *   @0x123c0c mov r1, r5
 *   @0x123c10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #87 color_get_blue → F_ColorGetBlue(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123c14 ldr r0, [pc, #0x8f0]
 *   @0x123c18 mov r1, r5
 *   @0x123c1c mov r2, #1
 *   @0x123c20 add r0, pc, r0
 *   @0x123c24 mov r3, #0
 *   @0x123c28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #88 colour_get_blue → F_ColorGetBlue(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123c2c ldr r1, [pc, #0x8dc]
 *   @0x123c30 ldr r0, [pc, #0x8dc]
 *   @0x123c34 mov r2, #1
 *   @0x123c38 mov r3, #0
 *   @0x123c3c ldr r5, [r4, r1]
 *   @0x123c40 add r0, pc, r0
 *   @0x123c44 mov r1, r5
 *   @0x123c48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #89 color_get_hue → F_ColorGetHue(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123c4c ldr r0, [pc, #0x8c4]
 *   @0x123c50 mov r1, r5
 *   @0x123c54 mov r2, #1
 *   @0x123c58 add r0, pc, r0
 *   @0x123c5c mov r3, #0
 *   @0x123c60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #90 colour_get_hue → F_ColorGetHue(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123c64 ldr r1, [pc, #0x8b0]
 *   @0x123c68 ldr r0, [pc, #0x8b0]
 *   @0x123c6c mov r2, #1
 *   @0x123c70 mov r3, #0
 *   @0x123c74 ldr r5, [r4, r1]
 *   @0x123c78 add r0, pc, r0
 *   @0x123c7c mov r1, r5
 *   @0x123c80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #91 color_get_saturation → F_ColorGetSaturation(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123c84 ldr r0, [pc, #0x898]
 *   @0x123c88 mov r1, r5
 *   @0x123c8c mov r2, #1
 *   @0x123c90 add r0, pc, r0
 *   @0x123c94 mov r3, #0
 *   @0x123c98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #92 colour_get_saturation → F_ColorGetSaturation(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123c9c ldr r1, [pc, #0x884]
 *   @0x123ca0 ldr r0, [pc, #0x884]
 *   @0x123ca4 mov r2, #1
 *   @0x123ca8 mov r3, #0
 *   @0x123cac ldr r5, [r4, r1]
 *   @0x123cb0 add r0, pc, r0
 *   @0x123cb4 mov r1, r5
 *   @0x123cb8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #93 color_get_value → F_ColorGetValue(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123cbc ldr r0, [pc, #0x86c]
 *   @0x123cc0 mov r1, r5
 *   @0x123cc4 mov r2, #1
 *   @0x123cc8 add r0, pc, r0
 *   @0x123ccc mov r3, #0
 *   @0x123cd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #94 colour_get_value → F_ColorGetValue(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123cd4 ldr r1, [pc, #0x858]
 *   @0x123cd8 ldr r0, [pc, #0x858]
 *   @0x123cdc mov r2, #3
 *   @0x123ce0 mov r3, #0
 *   @0x123ce4 ldr r5, [r4, r1]
 *   @0x123ce8 add r0, pc, r0
 *   @0x123cec mov r1, r5
 *   @0x123cf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #95 merge_color → F_MergeColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x123cf4 ldr r0, [pc, #0x840]
 *   @0x123cf8 mov r1, r5
 *   @0x123cfc mov r2, #3
 *   @0x123d00 add r0, pc, r0
 *   @0x123d04 mov r3, #0
 *   @0x123d08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #96 merge_colour → F_MergeColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x123d0c ldr r1, [pc, #0x82c]
 *   @0x123d10 ldr r0, [pc, #0x82c]
 *   @0x123d14 mov r2, #1
 *   @0x123d18 mov r3, r2
 *   @0x123d1c ldr r1, [r4, r1]
 *   @0x123d20 add r0, pc, r0
 *   @0x123d24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #97 draw_set_blend_mode → F_DrawSetBlendMode(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x123d28 ldr r1, [pc, #0x818]
 *   @0x123d2c ldr r0, [pc, #0x818]
 *   @0x123d30 mov r2, #2
 *   @0x123d34 mov r3, #1
 *   @0x123d38 ldr r1, [r4, r1]
 *   @0x123d3c add r0, pc, r0
 *   @0x123d40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #98 draw_set_blend_mode_ext → F_DrawSetBlendModeExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x123d44 ldr r1, [pc, #0x804]
 *   @0x123d48 ldr r0, [pc, #0x804]
 *   @0x123d4c mov r2, #4
 *   @0x123d50 mov r3, #1
 *   @0x123d54 ldr r5, [r4, r1]
 *   @0x123d58 add r0, pc, r0
 *   @0x123d5c mov r1, r5
 *   @0x123d60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #99 draw_set_color_write_enable → F_DrawSetColorWriteEnable(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x123d64 ldr r0, [pc, #0x7ec]
 *   @0x123d68 mov r1, r5
 *   @0x123d6c mov r2, #4
 *   @0x123d70 add r0, pc, r0
 *   @0x123d74 mov r3, #1
 *   @0x123d78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #100 draw_set_colour_write_enable → F_DrawSetColorWriteEnable(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x123d7c ldr r1, [pc, #0x7d8]
 *   @0x123d80 ldr r0, [pc, #0x7d8]
 *   @0x123d84 mov r2, #1
 *   @0x123d88 mov r3, #0
 *   @0x123d8c ldr r1, [r4, r1]
 *   @0x123d90 add r0, pc, r0
 *   @0x123d94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #101 draw_set_alpha_test → F_DrawSetAlphaTest(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123d98 ldr r1, [pc, #0x7c4]
 *   @0x123d9c ldr r0, [pc, #0x7c4]
 *   @0x123da0 mov r2, #1
 *   @0x123da4 mov r3, #0
 *   @0x123da8 ldr r1, [r4, r1]
 *   @0x123dac add r0, pc, r0
 *   @0x123db0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #102 draw_set_alpha_test_ref_value → F_DrawSetAlphaTestRefValue(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123db4 ldr r1, [pc, #0x7b0]
 *   @0x123db8 ldr r0, [pc, #0x7b0]
 *   @0x123dbc mov r2, #0
 *   @0x123dc0 mov r3, r2
 *   @0x123dc4 ldr r1, [r4, r1]
 *   @0x123dc8 add r0, pc, r0
 *   @0x123dcc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #103 draw_get_alpha_test → F_DrawGetAlphaTest(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x123dd0 ldr r1, [pc, #0x79c]
 *   @0x123dd4 ldr r0, [pc, #0x79c]
 *   @0x123dd8 mov r2, #0
 *   @0x123ddc mov r3, r2
 *   @0x123de0 ldr r1, [r4, r1]
 *   @0x123de4 add r0, pc, r0
 *   @0x123de8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #104 draw_get_alpha_test_ref_value → F_DrawGetAlphaTestRefValue(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x123dec ldr r1, [pc, #0x788]
 *   @0x123df0 ldr r0, [pc, #0x788]
 *   @0x123df4 mov r2, #1
 *   @0x123df8 mov r3, #0
 *   @0x123dfc ldr r1, [r4, r1]
 *   @0x123e00 add r0, pc, r0
 *   @0x123e04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #105 draw_clear → F_DrawClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x123e08 ldr r1, [pc, #0x774]
 *   @0x123e0c ldr r0, [pc, #0x774]
 *   @0x123e10 mov r2, #2
 *   @0x123e14 mov r3, #0
 *   @0x123e18 ldr r1, [r4, r1]
 *   @0x123e1c add r0, pc, r0
 *   @0x123e20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #106 draw_clear_alpha → F_DrawClearAlpha(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x123e24 ldr r1, [pc, #0x760]
 *   @0x123e28 ldr r0, [pc, #0x760]
 *   @0x123e2c mov r2, #2
 *   @0x123e30 mov r3, #0
 *   @0x123e34 ldr r1, [r4, r1]
 *   @0x123e38 add r0, pc, r0
 *   @0x123e3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #107 draw_point → F_DrawPoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x123e40 ldr r1, [pc, #0x74c]
 *   @0x123e44 ldr r0, [pc, #0x74c]
 *   @0x123e48 mov r2, #4
 *   @0x123e4c mov r3, #0
 *   @0x123e50 ldr r1, [r4, r1]
 *   @0x123e54 add r0, pc, r0
 *   @0x123e58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #108 draw_line → F_DrawLine(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x123e5c ldr r1, [pc, #0x738]
 *   @0x123e60 ldr r0, [pc, #0x738]
 *   @0x123e64 mov r2, #5
 *   @0x123e68 mov r3, #0
 *   @0x123e6c ldr r1, [r4, r1]
 *   @0x123e70 add r0, pc, r0
 *   @0x123e74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #109 draw_line_width → F_DrawLineWidth(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0x123e78 ldr r1, [pc, #0x724]
 *   @0x123e7c ldr r0, [pc, #0x724]
 *   @0x123e80 mov r2, #5
 *   @0x123e84 mov r3, #0
 *   @0x123e88 ldr r1, [r4, r1]
 *   @0x123e8c add r0, pc, r0
 *   @0x123e90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #110 draw_rectangle → F_DrawRectangle(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0x123e94 ldr r1, [pc, #0x710]
 *   @0x123e98 ldr r0, [pc, #0x710]
 *   @0x123e9c mov r2, #5
 *   @0x123ea0 mov r3, #0
 *   @0x123ea4 ldr r1, [r4, r1]
 *   @0x123ea8 add r0, pc, r0
 *   @0x123eac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #111 draw_roundrect → F_DrawRoundRect(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0x123eb0 ldr r1, [pc, #0x6fc]
 *   @0x123eb4 ldr r0, [pc, #0x6fc]
 *   @0x123eb8 mov r2, #5
 *   @0x123ebc mov r3, #0
 *   @0x123ec0 ldr r1, [r4, r1]
 *   @0x123ec4 add r0, pc, r0
 *   @0x123ec8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #112 draw_roundrect_ext → F_DrawRoundRect_EXT(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0x123ecc ldr r1, [pc, #0x6e8]
 *   @0x123ed0 ldr r0, [pc, #0x6e8]
 *   @0x123ed4 mov r2, #7
 *   @0x123ed8 mov r3, #0
 *   @0x123edc ldr r1, [r4, r1]
 *   @0x123ee0 add r0, pc, r0
 *   @0x123ee4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #113 draw_triangle → F_DrawTriangle(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=0
 *   @0x123ee8 ldr r1, [pc, #0x6d4]
 *   @0x123eec ldr r0, [pc, #0x6d4]
 *   @0x123ef0 mov r2, #4
 *   @0x123ef4 mov r3, #0
 *   @0x123ef8 ldr r1, [r4, r1]
 *   @0x123efc add r0, pc, r0
 *   @0x123f00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #114 draw_circle → F_DrawCircle(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x123f04 ldr r1, [pc, #0x6c0]
 *   @0x123f08 ldr r0, [pc, #0x6c0]
 *   @0x123f0c mov r2, #5
 *   @0x123f10 mov r3, #0
 *   @0x123f14 ldr r1, [r4, r1]
 *   @0x123f18 add r0, pc, r0
 *   @0x123f1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #115 draw_ellipse → F_DrawEllipse(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0x123f20 ldr r1, [pc, #0x6ac]
 *   @0x123f24 ldr r0, [pc, #0x6ac]
 *   @0x123f28 mov r2, #5
 *   @0x123f2c mov r3, #0
 *   @0x123f30 ldr r1, [r4, r1]
 *   @0x123f34 add r0, pc, r0
 *   @0x123f38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #116 draw_arrow → F_DrawArrow(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0x123f3c ldr r1, [pc, #0x698]
 *   @0x123f40 ldr r0, [pc, #0x698]
 *   @0x123f44 mov r2, #5
 *   @0x123f48 mov r3, #0
 *   @0x123f4c ldr r1, [r4, r1]
 *   @0x123f50 add r0, pc, r0
 *   @0x123f54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #117 draw_button → F_DrawButton(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0x123f58 ldr r1, [pc, #0x684]
 *   @0x123f5c ldr r0, [pc, #0x684]
 *   @0x123f60 mov r2, #11
 *   @0x123f64 mov r3, #0
 *   @0x123f68 ldr r1, [r4, r1]
 *   @0x123f6c add r0, pc, r0
 *   @0x123f70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #118 draw_healthbar → F_DrawHealthbar(RValue&, CInstance*, CInstance*, int, RValue*) argc=11 flag=0
 *   @0x123f74 ldr r1, [pc, #0x670]
 *   @0x123f78 ldr r0, [pc, #0x670]
 *   @0x123f7c mov r2, #4
 *   @0x123f80 mov r3, #0
 *   @0x123f84 ldr r1, [r4, r1]
 *   @0x123f88 add r0, pc, r0
 *   @0x123f8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #119 draw_path → F_DrawPath(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x123f90 ldr r1, [pc, #0x65c]
 *   @0x123f94 ldr r0, [pc, #0x65c]
 *   @0x123f98 mov r2, #3
 *   @0x123f9c mov r3, #1
 *   @0x123fa0 ldr r5, [r4, r1]
 *   @0x123fa4 add r0, pc, r0
 *   @0x123fa8 mov r1, r5
 *   @0x123fac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #120 draw_point_color → F_DrawPointExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x123fb0 ldr r0, [pc, #0x644]
 *   @0x123fb4 mov r1, r5
 *   @0x123fb8 mov r2, #3
 *   @0x123fbc add r0, pc, r0
 *   @0x123fc0 mov r3, #1
 *   @0x123fc4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #121 draw_point_colour → F_DrawPointExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x123fc8 ldr r1, [pc, #0x630]
 *   @0x123fcc ldr r0, [pc, #0x630]
 *   @0x123fd0 mov r2, #6
 *   @0x123fd4 mov r3, #1
 *   @0x123fd8 ldr r5, [r4, r1]
 *   @0x123fdc add r0, pc, r0
 *   @0x123fe0 mov r1, r5
 *   @0x123fe4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #122 draw_line_color → F_DrawLineExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x123fe8 ldr r0, [pc, #0x618]
 *   @0x123fec mov r1, r5
 *   @0x123ff0 mov r2, #6
 *   @0x123ff4 add r0, pc, r0
 *   @0x123ff8 mov r3, #1
 *   @0x123ffc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #123 draw_line_colour → F_DrawLineExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x124000 ldr r1, [pc, #0x604]
 *   @0x124004 ldr r0, [pc, #0x604]
 *   @0x124008 mov r2, #7
 *   @0x12400c mov r3, #1
 *   @0x124010 ldr r5, [r4, r1]
 *   @0x124014 add r0, pc, r0
 *   @0x124018 mov r1, r5
 *   @0x12401c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #124 draw_line_width_color → F_DrawLineWidthExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x124020 ldr r0, [pc, #0x5ec]
 *   @0x124024 mov r1, r5
 *   @0x124028 mov r2, #7
 *   @0x12402c add r0, pc, r0
 *   @0x124030 mov r3, #1
 *   @0x124034 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #125 draw_line_width_colour → F_DrawLineWidthExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x124038 ldr r1, [pc, #0x5d8]
 *   @0x12403c ldr r0, [pc, #0x5d8]
 *   @0x124040 mov r2, #9
 *   @0x124044 mov r3, #1
 *   @0x124048 ldr r5, [r4, r1]
 *   @0x12404c add r0, pc, r0
 *   @0x124050 mov r1, r5
 *   @0x124054 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #126 draw_rectangle_color → F_DrawRectangleExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x124058 ldr r0, [pc, #0x5c0]
 *   @0x12405c mov r1, r5
 *   @0x124060 mov r2, #9
 *   @0x124064 add r0, pc, r0
 *   @0x124068 mov r3, #1
 *   @0x12406c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #127 draw_rectangle_colour → F_DrawRectangleExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x124070 ldr r1, [pc, #0x5ac]
 *   @0x124074 ldr r0, [pc, #0x5ac]
 *   @0x124078 mov r2, #7
 *   @0x12407c mov r3, #1
 *   @0x124080 ldr r5, [r4, r1]
 *   @0x124084 add r0, pc, r0
 *   @0x124088 mov r1, r5
 *   @0x12408c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #128 draw_roundrect_color → F_DrawRoundRectColour(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x124090 ldr r0, [pc, #0x594]
 *   @0x124094 mov r1, r5
 *   @0x124098 mov r2, #7
 *   @0x12409c add r0, pc, r0
 *   @0x1240a0 mov r3, #1
 *   @0x1240a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #129 draw_roundrect_colour → F_DrawRoundRectColour(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x1240a8 ldr r1, [pc, #0x580]
 *   @0x1240ac ldr r0, [pc, #0x580]
 *   @0x1240b0 mov r2, #7
 *   @0x1240b4 mov r3, #1
 *   @0x1240b8 ldr r5, [r4, r1]
 *   @0x1240bc add r0, pc, r0
 *   @0x1240c0 mov r1, r5
 *   @0x1240c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #130 draw_roundrect_color_ext → F_DrawRoundRectColour_EXT(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x1240c8 ldr r0, [pc, #0x568]
 *   @0x1240cc mov r1, r5
 *   @0x1240d0 mov r2, #7
 *   @0x1240d4 add r0, pc, r0
 *   @0x1240d8 mov r3, #1
 *   @0x1240dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #131 draw_roundrect_colour_ext → F_DrawRoundRectColour_EXT(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x1240e0 ldr r1, [pc, #0x554]
 *   @0x1240e4 ldr r0, [pc, #0x554]
 *   @0x1240e8 mov r2, #10
 *   @0x1240ec mov r3, #1
 *   @0x1240f0 ldr r5, [r4, r1]
 *   @0x1240f4 add r0, pc, r0
 *   @0x1240f8 mov r1, r5
 *   @0x1240fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #132 draw_triangle_color → F_DrawTriangleExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=10 flag=1
 *   @0x124100 ldr r0, [pc, #0x53c]
 *   @0x124104 mov r1, r5
 *   @0x124108 mov r2, #10
 *   @0x12410c add r0, pc, r0
 *   @0x124110 mov r3, #1
 *   @0x124114 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #133 draw_triangle_colour → F_DrawTriangleExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=10 flag=1
 *   @0x124118 ldr r1, [pc, #0x528]
 *   @0x12411c ldr r0, [pc, #0x528]
 *   @0x124120 mov r2, #6
 *   @0x124124 mov r3, #1
 *   @0x124128 ldr r5, [r4, r1]
 *   @0x12412c add r0, pc, r0
 *   @0x124130 mov r1, r5
 *   @0x124134 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #134 draw_circle_color → F_DrawCircleExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x124138 ldr r0, [pc, #0x510]
 *   @0x12413c mov r1, r5
 *   @0x124140 mov r2, #6
 *   @0x124144 add r0, pc, r0
 *   @0x124148 mov r3, #1
 *   @0x12414c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #135 draw_circle_colour → F_DrawCircleExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x124150 ldr r1, [pc, #0x4fc]
 *   @0x124154 ldr r0, [pc, #0x4fc]
 *   @0x124158 mov r2, #7
 *   @0x12415c mov r3, #1
 *   @0x124160 ldr r5, [r4, r1]
 *   @0x124164 add r0, pc, r0
 *   @0x124168 mov r1, r5
 *   @0x12416c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #136 draw_ellipse_color → F_DrawEllipseExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x124170 ldr r0, [pc, #0x4e4]
 *   @0x124174 mov r1, r5
 *   @0x124178 mov r2, #7
 *   @0x12417c add r0, pc, r0
 *   @0x124180 mov r3, #1
 *   @0x124184 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #137 draw_ellipse_colour → F_DrawEllipseExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x124188 ldr r1, [pc, #0x4d0]
 *   @0x12418c ldr r0, [pc, #0x4d0]
 *   @0x124190 mov r2, #1
 *   @0x124194 mov r3, r2
 *   @0x124198 ldr r1, [r4, r1]
 *   @0x12419c add r0, pc, r0
 *   @0x1241a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #138 draw_set_circle_precision → F_DrawSetCirclePrecision(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1241a4 ldr r1, [pc, #0x4bc]
 *   @0x1241a8 ldr r0, [pc, #0x4bc]
 *   @0x1241ac mov r2, #1
 *   @0x1241b0 mov r3, r2
 *   @0x1241b4 ldr r1, [r4, r1]
 *   @0x1241b8 add r0, pc, r0
 *   @0x1241bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #139 draw_primitive_begin → F_DrawPrimitiveBegin(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1241c0 ldr r1, [pc, #0x4a8]
 *   @0x1241c4 ldr r0, [pc, #0x4a8]
 *   @0x1241c8 mov r2, #2
 *   @0x1241cc mov r3, #1
 *   @0x1241d0 ldr r1, [r4, r1]
 *   @0x1241d4 add r0, pc, r0
 *   @0x1241d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #140 draw_primitive_begin_texture → F_DrawPrimitiveBeginTexture(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1241dc ldr r1, [pc, #0x494]
 *   @0x1241e0 ldr r0, [pc, #0x494]
 *   @0x1241e4 mov r2, #0
 *   @0x1241e8 mov r3, #1
 *   @0x1241ec ldr r1, [r4, r1]
 *   @0x1241f0 add r0, pc, r0
 *   @0x1241f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #141 draw_primitive_end → F_DrawPrimitiveEnd(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x1241f8 ldr r1, [pc, #0x480]
 *   @0x1241fc ldr r0, [pc, #0x480]
 *   @0x124200 mov r2, #2
 *   @0x124204 mov r3, #1
 *   @0x124208 ldr r1, [r4, r1]
 *   @0x12420c add r0, pc, r0
 *   @0x124210 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #142 draw_vertex → F_DrawVertex(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x124214 ldr r1, [pc, #0x46c]
 *   @0x124218 ldr r0, [pc, #0x46c]
 *   @0x12421c mov r2, #4
 *   @0x124220 mov r3, #1
 *   @0x124224 ldr r5, [r4, r1]
 *   @0x124228 add r0, pc, r0
 *   @0x12422c mov r1, r5
 *   @0x124230 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #143 draw_vertex_color → F_DrawVertexColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x124234 ldr r0, [pc, #0x454]
 *   @0x124238 mov r1, r5
 *   @0x12423c mov r2, #4
 *   @0x124240 add r0, pc, r0
 *   @0x124244 mov r3, #1
 *   @0x124248 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #144 draw_vertex_colour → F_DrawVertexColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x12424c ldr r1, [pc, #0x440]
 *   @0x124250 ldr r0, [pc, #0x440]
 *   @0x124254 mov r2, #4
 *   @0x124258 mov r3, #1
 *   @0x12425c ldr r1, [r4, r1]
 *   @0x124260 add r0, pc, r0
 *   @0x124264 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #145 draw_vertex_texture → F_DrawVertexTexture(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x124268 ldr r1, [pc, #0x42c]
 *   @0x12426c b 0x124b14 <_Z20InitGraphicFunctionsv+0x18a8>
 *   @0x124270 .word 0x002ce9d0
 *   @0x124274 .word 0xffffc998
 *   @0x124278 eoreq r7, r1, r8, asr r3
 *   @0x12427c .word 0xffffc99c
 *   @0x124280 eoreq r7, r1, r0, asr r3
 *   @0x124284 .word 0xffffc9a0
 *   @0x124288 eoreq r7, r1, r8, asr #6
 *   @0x12428c .word 0xffffc9a4
 *   @0x124290 eoreq r7, r1, r4, asr #6
 *   @0x124294 .word 0xffffc9a8
 *   @0x124298 eoreq r7, r1, r0, asr #6
 *   @0x12429c .word 0xffffc9ac
 *   @0x1242a0 eoreq r7, r1, r12, lsr r3
 *   @0x1242a4 .word 0xffffc9b0
 *   @0x1242a8 eoreq r7, r1, r4, lsr r3
 *   @0x1242ac .word 0xffffc9b4
 *   @0x1242b0 eoreq r7, r1, r0, lsr r3
 *   @0x1242b4 .word 0xffffc9b8
 *   @0x1242b8 eoreq r7, r1, r12, lsr #6
 *   @0x1242bc .word 0xffffc9bc
 *   @0x1242c0 eoreq r7, r1, r0, lsr #6
 *   @0x1242c4 .word 0xffffc9c0
 *   @0x1242c8 eoreq r7, r1, r8, lsl r3
 *   @0x1242cc .word 0xffffc9c4
 *   @0x1242d0 eoreq r7, r1, r12, lsl #6
 *   @0x1242d4 .word 0xffffc9c8
 *   @0x1242d8 eoreq r7, r1, r4, lsl #6
 *   @0x1242dc .word 0xffffc9cc
 *   @0x1242e0 .word 0x002172fc
 *   @0x1242e4 .word 0xffffc9d0
 *   @0x1242e8 .word 0x002172f4
 *   @0x1242ec .word 0xffffc9d4
 *   @0x1242f0 .word 0x002172f0
 *   @0x1242f4 .word 0xffffc9d8
 *   @0x1242f8 eoreq r7, r1, r0, lsl #6
 *   @0x1242fc .word 0xffffc9dc
 *   @0x124300 eoreq r7, r1, r8, lsl #6
 *   @0x124304 .word 0xffffc9e0
 *   @0x124308 eoreq r7, r1, r8, lsl r3
 *   @0x12430c .word 0xffffc9e4
 *   @0x124310 eoreq r7, r1, r0, lsr #6
 *   @0x124314 .word 0xffffc9e8
 *   @0x124318 eoreq r7, r1, r0, lsr #6
 *   @0x12431c .word 0xffffc9ec
 *   @0x124320 eoreq r7, r1, r0, lsr #6
 *   @0x124324 .word 0xffffc9f0
 *   @0x124328 eoreq r7, r1, r0, lsr #6
 *   @0x12432c .word 0xffffc9f4
 *   @0x124330 eoreq r7, r1, r0, lsr #6
 *   @0x124334 .word 0xffffc9f8
 *   @0x124338 eoreq r7, r1, r0, lsr #6
 *   @0x12433c .word 0xffffc9fc
 *   @0x124340 eoreq r7, r1, r8, lsl r3
 *   @0x124344 .word 0xffffca00
 *   @0x124348 eoreq r7, r1, r0, lsl r3
 *   @0x12434c .word 0xffffca04
 *   @0x124350 eoreq r7, r1, r12, lsl #6
 *   @0x124354 .word 0xffffca08
 *   @0x124358 eoreq r7, r1, r8, lsl #6
 *   @0x12435c .word 0xffffca0c
 *   @0x124360 eoreq r7, r1, r4, lsl #6
 *   @0x124364 .word 0xffffca10
 *   @0x124368 eoreq r7, r1, r0, lsl #6
 *   @0x12436c .word 0xffffca14
 *   @0x124370 .word 0x002172fc
 *   @0x124374 .word 0xffffca18
 *   @0x124378 .word 0x002172f8
 *   @0x12437c .word 0xffffca1c
 *   @0x124380 .word 0x002172f4
 *   @0x124384 .word 0xffffca20
 *   @0x124388 .word 0x002172f0
 *   @0x12438c .word 0xffffca24
 *   @0x124390 eoreq r7, r1, r8, ror #5
 *   @0x124394 .word 0xffffca28
 *   @0x124398 eoreq r7, r1, r0, ror #5
 *   @0x12439c .word 0xffffca2c
 *   @0x1243a0 .word 0x002172d8
 *   @0x1243a4 .word 0xffffca30
 *   @0x1243a8 .word 0x002172d0
 *   @0x1243ac .word 0xffffca34
 *   @0x1243b0 eoreq r7, r1, r8, asr #5
 *   @0x1243b4 .word 0xffffca38
 *   @0x1243b8 eoreq r7, r1, r0, asr #5
 *   @0x1243bc .word 0x002172bc
 *   @0x1243c0 .word 0xffffca3c
 *   @0x1243c4 .word 0x002172b0
 *   @0x1243c8 eoreq r7, r1, r8, lsr #5
 *   @0x1243cc .word 0xffffca40
 *   @0x1243d0 eoreq r7, r1, r0, lsr #5
 *   @0x1243d4 .word 0xffffca44
 *   @0x1243d8 mlaeq r1, r12, r2, r7
 *   @0x1243dc .word 0xffffca48
 *   @0x1243e0 mlaeq r1, r8, r2, r7
 *   @0x1243e4 .word 0xffffca4c
 *   @0x1243e8 mlaeq r1, r4, r2, r7
 *   @0x1243ec .word 0xffffca50
 *   @0x1243f0 mlaeq r1, r0, r2, r7
 *   @0x1243f4 .word 0xffffca54
 *   @0x1243f8 eoreq r7, r1, r8, lsl #5
 *   @0x1243fc .word 0xffffca58
 *   @0x124400 eoreq r7, r1, r12, ror r2
 *   @0x124404 .word 0xffffca5c
 *   @0x124408 eoreq r7, r1, r8, ror r2
 *   @0x12440c .word 0xffffca60
 *   @0x124410 eoreq r7, r1, r12, ror #4
 *   @0x124414 .word 0xffffca64
 *   @0x124418 eoreq r7, r1, r0, ror #4
 *   @0x12441c .word 0xffffca68
 *   @0x124420 eoreq r7, r1, r4, asr r2
 *   @0x124424 .word 0xffffca6c
 *   @0x124428 eoreq r7, r1, r8, asr #4
 *   @0x12442c .word 0xffffca70
 *   @0x124430 eoreq r7, r1, r0, asr #4
 *   @0x124434 .word 0xffffca74
 *   @0x124438 eoreq r7, r1, r8, lsr r2
 *   @0x12443c .word 0xffffca78
 *   @0x124440 eoreq r7, r1, r8, lsr r2
 *   @0x124444 .word 0xffffca7c
 *   @0x124448 eoreq r7, r1, r0, lsr r2
 *   @0x12444c .word 0xffffca80
 *   @0x124450 eoreq r7, r1, r8, lsr #4
 *   @0x124454 .word 0xffffca84
 *   @0x124458 eoreq r7, r1, r0, lsr #4
 *   @0x12445c .word 0xffffca88
 *   @0x124460 eoreq r7, r1, r12, lsl r2
 *   @0x124464 .word 0xffffca8c
 *   @0x124468 eoreq r7, r1, r8, lsl r2
 *   @0x12446c .word 0xffffca90
 *   @0x124470 eoreq r7, r1, r4, lsl r2
 *   @0x124474 .word 0xffffca94
 *   @0x124478 eoreq r7, r1, r4, lsl r2
 *   @0x12447c .word 0xffffca98
 *   @0x124480 eoreq r7, r1, r4, lsl r2
 *   @0x124484 .word 0xffffca9c
 *   @0x124488 eoreq r7, r1, r0, lsl r2
 *   @0x12448c .word 0xffffcaa0
 *   @0x124490 eoreq r7, r1, r0, lsl #4
 *   @0x124494 .word 0xffffcaa4
 *   @0x124498 .word 0x002171f8
 *   @0x12449c .word 0xffffcaa8
 *   @0x1244a0 eoreq r7, r1, r12, ror #3
 *   @0x1244a4 .word 0xffffcaac
 *   @0x1244a8 eoreq r7, r1, r4, ror #3
 *   @0x1244ac .word 0x002171dc
 *   @0x1244b0 .word 0xffffcab0
 *   @0x1244b4 eoreq r7, r1, r12, asr #3
 *   @0x1244b8 .word 0xffffcab4
 *   @0x1244bc eoreq r7, r1, r0, asr #3
 *   @0x1244c0 .word 0x002171b4
 *   @0x1244c4 .word 0xffffcab8
 *   @0x1244c8 eoreq r7, r1, r8, lsr #3
 *   @0x1244cc .word 0xffffcabc
 *   @0x1244d0 mlaeq r1, r12, r1, r7
 *   @0x1244d4 mlaeq r1, r0, r1, r7
 *   @0x1244d8 eoreq r7, r1, r4, lsl #3
 *   @0x1244dc eoreq r7, r1, r12, ror r1
 *   @0x1244e0 .word 0xffffcac0
 *   @0x1244e4 eoreq r7, r1, r12, ror #2
 *   @0x1244e8 eoreq r7, r1, r4, ror #2
 *   @0x1244ec .word 0xffffcac4
 *   @0x1244f0 eoreq r7, r1, r4, asr r1
 *   @0x1244f4 eoreq r7, r1, r12, asr #2
 *   @0x1244f8 .word 0xffffcac8
 *   @0x1244fc eoreq r7, r1, r12, lsr r1
 *   @0x124500 eoreq r7, r1, r4, lsr r1
 *   @0x124504 .word 0xffffcacc
 *   @0x124508 eoreq r7, r1, r8, lsr #2
 *   @0x12450c eoreq r7, r1, r0, lsr #2
 *   @0x124510 .word 0xffffcad0
 *   @0x124514 eoreq r7, r1, r0, lsl r1
 *   @0x124518 eoreq r7, r1, r8, lsl #2
 *   @0x12451c .word 0xffffcad4
 *   @0x124520 .word 0x002170f8
 *   @0x124524 .word 0x002170f8
 *   @0x124528 .word 0xffffcad8
 *   @0x12452c .word 0x002170f0
 *   @0x124530 eoreq r7, r1, r8, ror #1
 *   @0x124534 .word 0xffffcadc
 *   @0x124538 .word 0x002170dc
 *   @0x12453c .word 0x002170d0
 *   @0x124540 .word 0xffffcae0
 *   @0x124544 eoreq r7, r1, r0, asr #1
 *   @0x124548 .word 0xffffcae4
 *   @0x12454c strhteq r7, [r1], -r8
 *   @0x124550 .word 0xffffcae8
 *   @0x124554 strhteq r7, [r1], -r4
 *   @0x124558 strhteq r7, [r1], -r8
 *   @0x12455c .word 0xffffcaec
 *   @0x124560 strhteq r7, [r1], -r8
 *   @0x124564 .word 0xffffcaf0
 *   @0x124568 strhteq r7, [r1], -r0
 *   @0x12456c .word 0xffffcaf4
 *   @0x124570 strhteq r7, [r1], -r4
 *   @0x124574 .word 0xffffcaf8
 *   @0x124578 eoreq r7, r1, r12, lsr #1
 *   @0x12457c .word 0xffffcafc
 *   @0x124580 strhteq r7, [r1], -r0
 *   @0x124584 .word 0xffffcb00
 *   @0x124588 eoreq r7, r1, r0, lsr #1
 *   @0x12458c .word 0xffffcb04
 *   @0x124590 mlaeq r1, r8, r0, r7
 *   @0x124594 .word 0xffffcb08
 *   @0x124598 eoreq r7, r1, r8, lsl #1
 *   @0x12459c .word 0xffffcb0c
 *   @0x1245a0 eoreq r7, r1, r8, ror r0
 *   @0x1245a4 .word 0xffffcb10
 *   @0x1245a8 eoreq r7, r1, r12, rrx
 *   @0x1245ac .word 0xffffcb14
 *   @0x1245b0 eoreq r7, r1, r0, rrx
 *   @0x1245b4 .word 0xffffcb18
 *   @0x1245b8 eoreq r7, r1, r4, asr r0
 *   @0x1245bc .word 0xffffcb1c
 *   @0x1245c0 eoreq r7, r1, r12, asr #32
 *   @0x1245c4 .word 0xffffcb20
 *   @0x1245c8 eoreq r7, r1, r0, asr #32
 *   @0x1245cc .word 0xffffcb24
 *   @0x1245d0 eoreq r7, r1, r0, lsr r0
 *   @0x1245d4 .word 0xffffcb28
 *   @0x1245d8 eoreq r7, r1, r4, lsr #32
 *   @0x1245dc .word 0xffffcb2c
 *   @0x1245e0 eoreq r7, r1, r4, lsl r0
 *   @0x1245e4 .word 0xffffcb30
 *   @0x1245e8 eoreq r7, r1, r4
 *   @0x1245ec .word 0xffffcb34
 *   @0x1245f0 .word 0x00216ff8
 *   @0x1245f4 .word 0xffffcb38
 *   @0x1245f8 eoreq r6, r1, r8, ror #31
 *   @0x1245fc eoreq r6, r1, r4, ror #31
 *   @0x124600 .word 0xffffcb3c
 *   @0x124604 .word 0x00216fd8
 *   @0x124608 .word 0x00216fd0
 *   @0x12460c .word 0xffffcb40
 *   @0x124610 eoreq r6, r1, r4, asr #31
 *   @0x124614 eoreq r6, r1, r4, asr #31
 *   @0x124618 .word 0xffffcb44
 *   @0x12461c .word 0x00216fbc
 *   @0x124620 .word 0x00216fbc
 *   @0x124624 .word 0xffffcb48
 *   @0x124628 .word 0x00216fb4
 *   @0x12462c .word 0x00216fb4
 *   @0x124630 .word 0xffffcb4c
 *   @0x124634 eoreq r6, r1, r12, lsr #31
 *   @0x124638 .word 0x00216fb0
 *   @0x12463c .word 0xffffcb50
 *   @0x124640 eoreq r6, r1, r12, lsr #31
 *   @0x124644 eoreq r6, r1, r8, lsr #31
 *   @0x124648 .word 0xffffcb54
 *   @0x12464c eoreq r6, r1, r0, lsr #31
 *   @0x124650 mlaeq r1, r12, pc, r6
 *   @0x124654 .word 0xffffcb58
 *   @0x124658 mlaeq r1, r0, pc, r6
 *   @0x12465c eoreq r6, r1, r12, lsl #31
 *   @0x124660 .word 0xffffcb5c
 *   @0x124664 eoreq r6, r1, r0, lsl #31
 *   @0x124668 .word 0xffffcb60
 *   @0x12466c eoreq r6, r1, r0, lsl #31
 *   @0x124670 .word 0xffffcb64
 *   @0x124674 eoreq r6, r1, r12, ror pc
 *   @0x124678 .word 0xffffcb68
 *   @0x12467c eoreq r6, r1, r0, lsl #31
 *   @0x124680 .word 0xffffcb6c
 *   @0x124684 eoreq r6, r1, r8, ror pc
 *   @0x124688 .word 0xffffcb70
 *   @0x12468c eoreq r6, r1, r8, ror #30
 *   @0x124690 eoreq r6, r1, r4, ror #30
 *   @0x124694 .word 0xffffcb74
 *   @0x124698 eoreq r6, r1, r8, asr pc
 *   @0x12469c .word 0xffffcb78
 *   @0x1246a0 eoreq r6, r1, r8, lsr #13
 *   @0x1246a4 eoreq r6, r1, r12, lsr #13
 *   @0x1246a8 .word 0xffffcb7c
 *   @0x1246ac eoreq r6, r1, r8, lsr #13
 *   @0x1246b0 .word 0xffffcb80
 *   @0x1246b4 mlaeq r1, r12, r6, r6
 *   @0x1246b8 .word 0xffffcb84
 *   @0x1246bc mlaeq r1, r4, r6, r6
 *   @0x1246c0 .word 0xffffcb88
 *   @0x1246c4 eoreq r6, r1, r8, lsl #13
 *   @0x1246c8 .word 0xffffcb8c
 *   @0x1246cc eoreq r6, r1, r0, lsl #13
 *   @0x1246d0 .word 0xffffcb90
 *   @0x1246d4 eoreq r6, r1, r12, ror r6
 *   @0x1246d8 .word 0xffffcb94
 *   @0x1246dc eoreq r6, r1, r4, ror r6
 *   @0x1246e0 .word 0xffffcb98
 *   @0x1246e4 eoreq r6, r1, r8, ror #12
 *   @0x1246e8 .word 0xffffcb9c
 *   @0x1246ec eoreq r6, r1, r8, ror #12
 *   @0x1246f0 .word 0xffffcba0
 *   @0x1246f4 eoreq r6, r1, r12, ror #12
 *   @0x1246f8 .word 0xffffcba4
 *   @0x1246fc eoreq r6, r1, r8, ror #12
 *   @0x124700 .word 0xffffcba8
 *   @0x124704 eoreq r6, r1, r0, ror #12
 *   @0x124708 .word 0xffffcbac
 *   @0x12470c eoreq r6, r1, r12, asr r6
 *   @0x124710 .word 0xffffcbb0
 *   @0x124714 eoreq r6, r1, r4, asr r6
 *   @0x124718 .word 0xffffcbb4
 *   @0x12471c eoreq r6, r1, r12, asr #12
 *   @0x124720 .word 0xffffcbb8
 *   @0x124724 eoreq r6, r1, r0, asr #12
 *   @0x124728 .word 0xffffcbbc
 *   @0x12472c eoreq r6, r1, r12, lsr r6
 *   @0x124730 .word 0xffffcbc0
 *   @0x124734 eoreq r6, r1, r8, lsr r6
 *   @0x124738 .word 0xffffcbc4
 *   @0x12473c eoreq r6, r1, r12, lsr #12
 *   @0x124740 .word 0xffffcbc8
 *   @0x124744 eoreq r6, r1, r0, lsr #12
 *   @0x124748 .word 0xffffcbcc
 *   @0x12474c eoreq r6, r1, r4, lsl r6
 *   @0x124750 .word 0xffffcbd0
 *   @0x124754 eoreq r6, r1, r8, lsl #12
 *   @0x124758 .word 0xffffcbd4
 *   @0x12475c .word 0x002165fc
 *   @0x124760 .word 0xffffcbd8
 *   @0x124764 .word 0x002165f0
 *   @0x124768 .word 0xffffcbdc
 *   @0x12476c eoreq r6, r1, r8, ror #11
 *   @0x124770 .word 0xffffcbe0
 *   @0x124774 eoreq r6, r1, r0, ror #11
 *   @0x124778 .word 0xffffcbe4
 *   @0x12477c .word 0x002165d0
 *   @0x124780 .word 0xffffcbe8
 *   @0x124784 eoreq r6, r1, r4, asr #11
 *   @0x124788 .word 0xffffcbec
 *   @0x12478c eoreq r6, r1, r0, asr #11
 *   @0x124790 .word 0xffffcbf0
 *   @0x124794 eoreq r6, r1, r0, asr #11
 *   @0x124798 .word 0x002165b8
 *   @0x12479c .word 0xffffcbf4
 *   @0x1247a0 eoreq r6, r1, r12, lsr #11
 *   @0x1247a4 .word 0x002165b0
 *   @0x1247a8 .word 0xffffcbf8
 *   @0x1247ac .word 0x002165b0
 *   @0x1247b0 eoreq r6, r1, r12, lsr #11
 *   @0x1247b4 .word 0xffffcbfc
 *   @0x1247b8 eoreq r6, r1, r4, lsr #11
 *   @0x1247bc eoreq r6, r1, r12, lsr #11
 *   @0x1247c0 .word 0xffffcc00
 *   @0x1247c4 .word 0x002165b0
 *   @0x1247c8 .word 0xffffcc04
 *   @0x1247cc eoreq r6, r1, r4, lsr #11
 *   @0x1247d0 .word 0xffffcc08
 *   @0x1247d4 mlaeq r1, r4, r5, r6
 *   @0x1247d8 .word 0xffffcc0c
 *   @0x1247dc eoreq r6, r1, r4, lsl #11
 *   @0x1247e0 .word 0xffffcc10
 *   @0x1247e4 eoreq r6, r1, r4, ror r5
 *   @0x1247e8 .word 0xffffcc14
 *   @0x1247ec eoreq r6, r1, r12, ror #10
 *   @0x1247f0 .word 0xffffcc18
 *   @0x1247f4 eoreq r6, r1, r0, ror #10
 *   @0x1247f8 .word 0xffffcc1c
 *   @0x1247fc eoreq r6, r1, r4, asr r5
 *   @0x124800 .word 0xffffcc20
 *   @0x124804 eoreq r6, r1, r0, asr r5
 *   @0x124808 .word 0xffffcc24
 *   @0x12480c eoreq r6, r1, r0, asr r5
 *   @0x124810 .word 0xffffcc28
 *   @0x124814 eoreq r6, r1, r8, asr #10
 *   @0x124818 .word 0xffffcc2c
 *   @0x12481c eoreq r6, r1, r4, asr #10
 *   @0x124820 .word 0xffffcc30
 *   @0x124824 eoreq r6, r1, r12, lsr r5
 *   @0x124828 .word 0xffffcc34
 *   @0x12482c eoreq r6, r1, r4, lsr r5
 *   @0x124830 .word 0xffffcc38
 *   @0x124834 eoreq r6, r1, r0, lsr r5
 *   @0x124838 .word 0xffffcc3c
 *   @0x12483c eoreq r6, r1, r4, lsr #10
 *   @0x124840 .word 0xffffcc40
 *   @0x124844 eoreq r6, r1, r12, lsl r5
 *   @0x124848 .word 0xffffcc44
 *   @0x12484c eoreq r6, r1, r12, lsl r5
 *   @0x124850 .word 0xffffcc48
 *   @0x124854 eoreq r6, r1, r0, lsr #10
 *   @0x124858 .word 0xffffcc4c
 *   @0x12485c eoreq r6, r1, r12, lsl r5
 *   @0x124860 .word 0xffffcc50
 *   @0x124864 eoreq r6, r1, r12, lsl r5
 *   @0x124868 .word 0xffffcc54
 *   @0x12486c eoreq r6, r1, r8, lsl r5
 *   @0x124870 .word 0xffffcc58
 *   @0x124874 eoreq r6, r1, r4, lsl r5
 *   @0x124878 .word 0xffffcc5c
 *   @0x12487c eoreq r6, r1, r4, lsl r5
 *   @0x124880 .word 0xffffcc60
 *   @0x124884 eoreq r6, r1, r0, lsl r5
 *   @0x124888 .word 0xffffcc64
 *   @0x12488c eoreq r6, r1, r0, lsl #10
 *   @0x124890 .word 0xffffcc68
 *   @0x124894 .word 0x002164f0
 *   @0x124898 .word 0xffffcc6c
 *   @0x12489c eoreq r6, r1, r4, ror #9
 *   @0x1248a0 .word 0xffffcc70
 *   @0x1248a4 .word 0x002164d8
 *   @0x1248a8 .word 0xffffcc74
 *   @0x1248ac eoreq r6, r1, r12, asr #9
 *   @0x1248b0 .word 0xffffcc78
 *   @0x1248b4 eoreq r6, r1, r0, asr #9
 *   @0x1248b8 .word 0xffffcc7c
 *   @0x1248bc .word 0x002164b4
 *   @0x1248c0 .word 0xffffcc80
 *   @0x1248c4 eoreq r6, r1, r12, lsr #9
 *   @0x1248c8 .word 0xffffcc84
 *   @0x1248cc eoreq r6, r1, r0, lsr #9
 *   @0x1248d0 .word 0xffffcc88
 *   @0x1248d4 mlaeq r1, r4, r4, r6
 *   @0x1248d8 .word 0xffffcc8c
 *   @0x1248dc eoreq r6, r1, r8, lsl #9
 *   @0x1248e0 .word 0xffffcc90
 *   @0x1248e4 eoreq r6, r1, r12, ror r4
 *   @0x1248e8 .word 0xffffcc94
 *   @0x1248ec eoreq r6, r1, r4, ror r4
 *   @0x1248f0 .word 0xffffcc98
 *   @0x1248f4 eoreq r6, r1, r12, ror #8
 *   @0x1248f8 .word 0xffffcc9c
 *   @0x1248fc eoreq r6, r1, r4, ror #8
 *   @0x124900 .word 0xffffcca0
 *   @0x124904 eoreq r6, r1, r8, asr r4
 *   @0x124908 .word 0xffffcca4
 *   @0x12490c eoreq r6, r1, r0, asr r4
 *   @0x124910 .word 0xffffcca8
 *   @0x124914 eoreq r6, r1, r4, asr #8
 *   @0x124918 .word 0xffffccac
 *   @0x12491c eoreq r6, r1, r8, lsr r4
 *   @0x124920 .word 0xffffccb0
 *   @0x124924 eoreq r6, r1, r12, lsr #8
 *   @0x124928 .word 0xffffccb4
 *   @0x12492c eoreq r6, r1, r0, lsr #8
 *   @0x124930 .word 0xffffccb8
 *   @0x124934 eoreq r6, r1, r4, lsl r4
 *   @0x124938 .word 0xffffccbc
 *   @0x12493c eoreq r6, r1, r4, lsl #8
 *   @0x124940 .word 0xffffccc0
 *   @0x124944 .word 0x002163f8
 *   @0x124948 .word 0xffffccc4
 *   @0x12494c .word 0x002163f4
 *   @0x124950 .word 0xffffccc8
 *   @0x124954 eoreq r6, r1, r4, ror #7
 *   @0x124958 .word 0xffffcccc
 *   @0x12495c .word 0x002163d4
 *   @0x124960 .word 0xffffccd0
 *   @0x124964 eoreq r6, r1, r4, asr #7
 *   @0x124968 .word 0xffffccd4
 *   @0x12496c .word 0x002163b8
 *   @0x124970 .word 0xffffccd8
 *   @0x124974 eoreq r6, r1, r12, lsr #7
 *   @0x124978 .word 0xffffccdc
 *   @0x12497c eoreq r6, r1, r4, lsr #7
 *   @0x124980 .word 0xffffcce0
 *   @0x124984 mlaeq r1, r12, r3, r6
 *   @0x124988 .word 0xffffcce4
 *   @0x12498c mlaeq r1, r0, r3, r6
 *   @0x124990 .word 0xffffcce8
 *   @0x124994 eoreq r6, r1, r12, lsl #7
 *   @0x124998 .word 0xffffccec
 *   @0x12499c eoreq r6, r1, r4, lsl #7
 *   @0x1249a0 .word 0xffffccf0
 *   @0x1249a4 eoreq r6, r1, r8, ror r3
 *   @0x1249a8 .word 0xffffccf4
 *   @0x1249ac eoreq r6, r1, r0, ror r3
 *   @0x1249b0 .word 0xffffccf8
 *   @0x1249b4 eoreq r6, r1, r12, ror #6
 *   @0x1249b8 .word 0xffffccfc
 *   @0x1249bc eoreq r6, r1, r0, ror #6
 *   @0x1249c0 .word 0xffffcd00
 *   @0x1249c4 eoreq r6, r1, r4, asr r3
 *   @0x1249c8 .word 0xffffcd04
 *   @0x1249cc eoreq r6, r1, r8, asr #6
 *   @0x1249d0 .word 0xffffcd08
 *   @0x1249d4 eoreq r6, r1, r0, asr #6
 *   @0x1249d8 .word 0xffffcd0c
 *   @0x1249dc eoreq r6, r1, r8, lsr r3
 *   @0x1249e0 .word 0xffffcd10
 *   @0x1249e4 eoreq r6, r1, r0, lsr r3
 *   @0x1249e8 .word 0xffffcd14
 *   @0x1249ec eoreq r6, r1, r8, lsr #6
 *   @0x1249f0 .word 0xffffcd18
 *   @0x1249f4 eoreq r6, r1, r4, lsr #6
 *   @0x1249f8 .word 0xffffcd1c
 *   @0x1249fc eoreq r6, r1, r0, lsr #6
 *   @0x124a00 .word 0xffffcd20
 *   @0x124a04 eoreq r6, r1, r12, lsl r3
 *   @0x124a08 .word 0xffffcd24
 *   @0x124a0c eoreq r6, r1, r12, lsl r3
 *   @0x124a10 .word 0xffffcd28
 *   @0x124a14 eoreq r6, r1, r0, lsl r3
 *   @0x124a18 .word 0xffffcd2c
 *   @0x124a1c eoreq r6, r1, r8, lsl #6
 *   @0x124a20 .word 0xffffcd30
 *   @0x124a24 eoreq r6, r1, r4, lsl #6
 *   @0x124a28 .word 0xffffcd34
 *   @0x124a2c eoreq r6, r1, r4, lsl #6
 *   @0x124a30 .word 0xffffcd38
 *   @0x124a34 .word 0x002162fc
 *   @0x124a38 .word 0xffffcd3c
 *   @0x124a3c .word 0x002162f8
 *   @0x124a40 .word 0xffffcd40
 *   @0x124a44 .word 0x002162f4
 *   @0x124a48 .word 0xffffcd44
 *   @0x124a4c eoreq r6, r1, r12, ror #5
 *   @0x124a50 .word 0xffffcd48
 *   @0x124a54 eoreq r6, r1, r8, ror #5
 *   @0x124a58 .word 0xffffcd4c
 *   @0x124a5c .word 0x002162dc
 *   @0x124a60 .word 0xffffcd50
 *   @0x124a64 .word 0x002162d4
 *   @0x124a68 .word 0xffffcd54
 *   @0x124a6c eoreq r6, r1, r12, asr #5
 *   @0x124a70 .word 0xffffcd58
 *   @0x124a74 eoreq r6, r1, r8, asr #5
 *   @0x124a78 .word 0xffffcd5c
 *   @0x124a7c .word 0x002162bc
 *   @0x124a80 .word 0xffffcd60
 *   @0x124a84 .word 0x002162b4
 *   @0x124a88 .word 0xffffcd64
 *   @0x124a8c .word 0x002162b0
 *   @0x124a90 .word 0xffffcd68
 *   @0x124a94 eoreq r6, r1, r8, lsr #5
 *   @0x124a98 .word 0xffffcd6c
 *   @0x124a9c eoreq r6, r1, r4, lsr #5
 *   @0x124aa0 eoreq r6, r1, r8, lsr #5
 *   @0x124aa4 .word 0xffffcd70
 *   @0x124aa8 eoreq r6, r1, r8, lsr #5
 *   @0x124aac .word 0xffffcd74
 *   @0x124ab0 eoreq r6, r1, r12, lsr #5
 *   @0x124ab4 .word 0xffffcd78
 *   @0x124ab8 .word 0x002162b0
 *   @0x124abc .word 0xffffcd7c
 *   @0x124ac0 .word 0x002162b0
 *   @0x124ac4 .word 0xffffcd80
 *   @0x124ac8 eoreq r6, r1, r8, lsr #5
 *   @0x124acc .word 0xffffcd84
 *   @0x124ad0 eoreq r6, r1, r0, lsr #5
 *   @0x124ad4 .word 0xffffcd88
 *   @0x124ad8 mlaeq r1, r12, r2, r6
 *   @0x124adc .word 0xffffcd8c
 *   @0x124ae0 mlaeq r1, r8, r2, r6
 *   @0x124ae4 .word 0xffffcd90
 *   @0x124ae8 mlaeq r1, r8, r2, r6
 *   @0x124aec .word 0xffffcd94
 *   @0x124af0 mlaeq r1, r8, r2, r6
 *   @0x124af4 .word 0xffffcd98
 *   @0x124af8 mlaeq r1, r4, r2, r6
 *   @0x124afc .word 0xffffcd9c
 *   @0x124b00 mlaeq r1, r0, r2, r6
 *   @0x124b04 .word 0xffffcda0
 *   @0x124b08 eoreq r6, r1, r12, lsl #5
 *   @0x124b0c .word 0xffffcda4
 *   @0x124b10 eoreq r6, r1, r8, lsl #5
 *   @0x124b14 ldr r0, [pc, #-0x47c]
 *   @0x124b18 mov r2, #6
 *   @0x124b1c mov r3, #1
 *   @0x124b20 ldr r5, [r4, r1]
 *   @0x124b24 add r0, pc, r0
 *   @0x124b28 mov r1, r5
 *   @0x124b2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #146 draw_vertex_texture_color → F_DrawVertexTextureColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x124b30 ldr r0, [pc, #-0x494]
 *   @0x124b34 mov r1, r5
 *   @0x124b38 mov r2, #6
 *   @0x124b3c add r0, pc, r0
 *   @0x124b40 mov r3, #1
 *   @0x124b44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #147 draw_vertex_texture_colour → F_DrawVertexTextureColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x124b48 ldr r1, [pc, #-0x4a8]
 *   @0x124b4c ldr r0, [pc, #-0x4a8]
 *   @0x124b50 mov r2, #2
 *   @0x124b54 mov r3, #1
 *   @0x124b58 ldr r1, [r4, r1]
 *   @0x124b5c add r0, pc, r0
 *   @0x124b60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #148 sprite_get_uvs → F_SpriteGetBaseUV(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x124b64 ldr r1, [pc, #-0x4bc]
 *   @0x124b68 ldr r0, [pc, #-0x4bc]
 *   @0x124b6c mov r2, #2
 *   @0x124b70 mov r3, #1
 *   @0x124b74 ldr r1, [r4, r1]
 *   @0x124b78 add r0, pc, r0
 *   @0x124b7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #149 background_get_uvs → F_BackgroundGetBaseUV(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x124b80 ldr r1, [pc, #-0x4d0]
 *   @0x124b84 ldr r0, [pc, #-0x4d0]
 *   @0x124b88 mov r2, #2
 *   @0x124b8c mov r3, #1
 *   @0x124b90 ldr r1, [r4, r1]
 *   @0x124b94 add r0, pc, r0
 *   @0x124b98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #150 font_get_uvs → F_FontGetBaseUV(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x124b9c ldr r1, [pc, #-0x4e4]
 *   @0x124ba0 ldr r0, [pc, #-0x4e4]
 *   @0x124ba4 mov r2, #2
 *   @0x124ba8 mov r3, #1
 *   @0x124bac ldr r1, [r4, r1]
 *   @0x124bb0 add r0, pc, r0
 *   @0x124bb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #151 sprite_get_texture → F_SpriteGetTexture(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x124bb8 ldr r1, [pc, #-0x4f8]
 *   @0x124bbc ldr r0, [pc, #-0x4f8]
 *   @0x124bc0 mov r2, #1
 *   @0x124bc4 mov r3, r2
 *   @0x124bc8 ldr r1, [r4, r1]
 *   @0x124bcc add r0, pc, r0
 *   @0x124bd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #152 background_get_texture → F_BackgroundGetTexture(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x124bd4 ldr r1, [pc, #-0x50c]
 *   @0x124bd8 ldr r0, [pc, #-0x50c]
 *   @0x124bdc mov r2, #1
 *   @0x124be0 mov r3, r2
 *   @0x124be4 ldr r1, [r4, r1]
 *   @0x124be8 add r0, pc, r0
 *   @0x124bec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #153 font_get_texture → F_FontGetTexture(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x124bf0 ldr r1, [pc, #-0x520]
 *   @0x124bf4 ldr r0, [pc, #-0x520]
 *   @0x124bf8 mov r2, #1
 *   @0x124bfc mov r3, r2
 *   @0x124c00 ldr r1, [r4, r1]
 *   @0x124c04 add r0, pc, r0
 *   @0x124c08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #154 texture_exists → F_TextureExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x124c0c ldr r1, [pc, #-0x534]
 *   @0x124c10 ldr r0, [pc, #-0x534]
 *   @0x124c14 mov r2, #1
 *   @0x124c18 mov r3, r2
 *   @0x124c1c ldr r1, [r4, r1]
 *   @0x124c20 add r0, pc, r0
 *   @0x124c24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #155 texture_set_interpolation → F_TextureSetInterpolation(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x124c28 ldr r1, [pc, #-0x548]
 *   @0x124c2c ldr r0, [pc, #-0x548]
 *   @0x124c30 mov r2, #2
 *   @0x124c34 mov r3, #1
 *   @0x124c38 ldr r1, [r4, r1]
 *   @0x124c3c add r0, pc, r0
 *   @0x124c40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #156 texture_set_interpolation_ext → F_TextureSetInterpolationExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x124c44 ldr r1, [pc, #-0x55c]
 *   @0x124c48 ldr r0, [pc, #-0x55c]
 *   @0x124c4c mov r2, #1
 *   @0x124c50 mov r3, r2
 *   @0x124c54 ldr r1, [r4, r1]
 *   @0x124c58 add r0, pc, r0
 *   @0x124c5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #157 texture_set_blending → F_TextureSetBlending(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x124c60 ldr r1, [pc, #-0x570]
 *   @0x124c64 ldr r0, [pc, #-0x570]
 *   @0x124c68 mov r2, #1
 *   @0x124c6c mov r3, r2
 *   @0x124c70 ldr r1, [r4, r1]
 *   @0x124c74 add r0, pc, r0
 *   @0x124c78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #158 texture_set_repeat → F_TextureSetRepeat(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x124c7c ldr r1, [pc, #-0x584]
 *   @0x124c80 ldr r0, [pc, #-0x584]
 *   @0x124c84 mov r2, #2
 *   @0x124c88 mov r3, #1
 *   @0x124c8c ldr r1, [r4, r1]
 *   @0x124c90 add r0, pc, r0
 *   @0x124c94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #159 texture_set_repeat_ext → F_TextureSetRepeatExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x124c98 ldr r1, [pc, #-0x598]
 *   @0x124c9c ldr r0, [pc, #-0x598]
 *   @0x124ca0 mov r2, #1
 *   @0x124ca4 mov r3, r2
 *   @0x124ca8 ldr r1, [r4, r1]
 *   @0x124cac add r0, pc, r0
 *   @0x124cb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #160 texture_get_width → F_TextureGetWidth(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x124cb4 ldr r1, [pc, #-0x5ac]
 *   @0x124cb8 ldr r0, [pc, #-0x5ac]
 *   @0x124cbc mov r2, #1
 *   @0x124cc0 mov r3, r2
 *   @0x124cc4 ldr r1, [r4, r1]
 *   @0x124cc8 add r0, pc, r0
 *   @0x124ccc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #161 texture_get_height → F_TextureGetHeight(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x124cd0 ldr r1, [pc, #-0x5c0]
 *   @0x124cd4 ldr r0, [pc, #-0x5c0]
 *   @0x124cd8 mov r2, #1
 *   @0x124cdc mov r3, r2
 *   @0x124ce0 ldr r1, [r4, r1]
 *   @0x124ce4 add r0, pc, r0
 *   @0x124ce8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #162 texture_preload → F_TexturePreload(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x124cec ldr r1, [pc, #-0x5d4]
 *   @0x124cf0 ldr r0, [pc, #-0x5d4]
 *   @0x124cf4 mov r2, #2
 *   @0x124cf8 mov r3, #1
 *   @0x124cfc ldr r1, [r4, r1]
 *   @0x124d00 add r0, pc, r0
 *   @0x124d04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #163 texture_set_priority → F_TextureSetPriority(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x124d08 ldr r1, [pc, #-0x5e8]
 *   @0x124d0c ldr r0, [pc, #-0x5e8]
 *   @0x124d10 mov r2, #1
 *   @0x124d14 mov r3, r2
 *   @0x124d18 ldr r1, [r4, r1]
 *   @0x124d1c add r0, pc, r0
 *   @0x124d20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #164 texture_global_scale → F_TextureGlobalScale(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x124d24 ldr r1, [pc, #-0x5fc]
 *   @0x124d28 ldr r0, [pc, #-0x5fc]
 *   @0x124d2c mov r2, #1
 *   @0x124d30 mov r3, r2
 *   @0x124d34 ldr r1, [r4, r1]
 *   @0x124d38 add r0, pc, r0
 *   @0x124d3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #165 texture_get_uvs → F_TextureGetUVs(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x124d40 ldr r1, [pc, #-0x610]
 *   @0x124d44 ldr r0, [pc, #-0x610]
 *   @0x124d48 mov r2, #1
 *   @0x124d4c mov r3, #0
 *   @0x124d50 ldr r1, [r4, r1]
 *   @0x124d54 add r0, pc, r0
 *   @0x124d58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #166 draw_set_font → F_DrawSetFont(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x124d5c ldr r1, [pc, #-0x624]
 *   @0x124d60 ldr r0, [pc, #-0x624]
 *   @0x124d64 mov r2, #1
 *   @0x124d68 mov r3, #0
 *   @0x124d6c ldr r1, [r4, r1]
 *   @0x124d70 add r0, pc, r0
 *   @0x124d74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #167 draw_set_halign → F_DrawSetHAlign(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x124d78 ldr r1, [pc, #-0x638]
 *   @0x124d7c ldr r0, [pc, #-0x638]
 *   @0x124d80 mov r2, #1
 *   @0x124d84 mov r3, #0
 *   @0x124d88 ldr r1, [r4, r1]
 *   @0x124d8c add r0, pc, r0
 *   @0x124d90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #168 draw_set_valign → F_DrawSetVAlign(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x124d94 ldr r1, [pc, #-0x64c]
 *   @0x124d98 ldr r0, [pc, #-0x64c]
 *   @0x124d9c mov r2, #1
 *   @0x124da0 mov r3, #0
 *   @0x124da4 ldr r1, [r4, r1]
 *   @0x124da8 add r0, pc, r0
 *   @0x124dac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #169 string_width → F_StringWidth(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x124db0 ldr r1, [pc, #-0x660]
 *   @0x124db4 ldr r0, [pc, #-0x660]
 *   @0x124db8 mov r2, #1
 *   @0x124dbc mov r3, #0
 *   @0x124dc0 ldr r1, [r4, r1]
 *   @0x124dc4 add r0, pc, r0
 *   @0x124dc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #170 string_height → F_StringHeight(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x124dcc ldr r1, [pc, #-0x674]
 *   @0x124dd0 ldr r0, [pc, #-0x674]
 *   @0x124dd4 mov r2, #3
 *   @0x124dd8 mov r3, #0
 *   @0x124ddc ldr r1, [r4, r1]
 *   @0x124de0 add r0, pc, r0
 *   @0x124de4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #171 string_width_ext → F_StringWidthExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x124de8 ldr r1, [pc, #-0x688]
 *   @0x124dec ldr r0, [pc, #-0x688]
 *   @0x124df0 mov r2, #3
 *   @0x124df4 mov r3, #0
 *   @0x124df8 ldr r1, [r4, r1]
 *   @0x124dfc add r0, pc, r0
 *   @0x124e00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #172 string_height_ext → F_StringHeightExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x124e04 ldr r1, [pc, #-0x69c]
 *   @0x124e08 ldr r0, [pc, #-0x69c]
 *   @0x124e0c mov r2, #3
 *   @0x124e10 mov r3, #0
 *   @0x124e14 ldr r1, [r4, r1]
 *   @0x124e18 add r0, pc, r0
 *   @0x124e1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #173 draw_text → F_DrawText(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x124e20 ldr r1, [pc, #-0x6b0]
 *   @0x124e24 ldr r0, [pc, #-0x6b0]
 *   @0x124e28 mov r2, #5
 *   @0x124e2c mov r3, #0
 *   @0x124e30 ldr r1, [r4, r1]
 *   @0x124e34 add r0, pc, r0
 *   @0x124e38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #174 draw_text_ext → F_DrawTextExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0x124e3c ldr r1, [pc, #-0x6c4]
 *   @0x124e40 ldr r0, [pc, #-0x6c4]
 *   @0x124e44 mov r2, #6
 *   @0x124e48 mov r3, #1
 *   @0x124e4c ldr r1, [r4, r1]
 *   @0x124e50 add r0, pc, r0
 *   @0x124e54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #175 draw_text_transformed → F_DrawTextTransformed(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x124e58 ldr r1, [pc, #-0x6d8]
 *   @0x124e5c ldr r0, [pc, #-0x6d8]
 *   @0x124e60 mov r2, #8
 *   @0x124e64 mov r3, #1
 *   @0x124e68 ldr r1, [r4, r1]
 *   @0x124e6c add r0, pc, r0
 *   @0x124e70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #176 draw_text_ext_transformed → F_DrawTextExtTransformed(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x124e74 ldr r1, [pc, #-0x6ec]
 *   @0x124e78 ldr r0, [pc, #-0x6ec]
 *   @0x124e7c mov r2, #8
 *   @0x124e80 mov r3, #1
 *   @0x124e84 ldr r5, [r4, r1]
 *   @0x124e88 add r0, pc, r0
 *   @0x124e8c mov r1, r5
 *   @0x124e90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #177 draw_text_color → F_DrawTextColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x124e94 ldr r0, [pc, #-0x704]
 *   @0x124e98 mov r1, r5
 *   @0x124e9c mov r2, #8
 *   @0x124ea0 add r0, pc, r0
 *   @0x124ea4 mov r3, #1
 *   @0x124ea8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #178 draw_text_colour → F_DrawTextColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x124eac ldr r1, [pc, #-0x718]
 *   @0x124eb0 ldr r0, [pc, #-0x718]
 *   @0x124eb4 mov r2, #11
 *   @0x124eb8 mov r3, #1
 *   @0x124ebc ldr r5, [r4, r1]
 *   @0x124ec0 add r0, pc, r0
 *   @0x124ec4 mov r1, r5
 *   @0x124ec8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #179 draw_text_transformed_color → F_DrawTextTransformedColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=11 flag=1
 *   @0x124ecc ldr r0, [pc, #-0x730]
 *   @0x124ed0 mov r1, r5
 *   @0x124ed4 mov r2, #11
 *   @0x124ed8 add r0, pc, r0
 *   @0x124edc mov r3, #1
 *   @0x124ee0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #180 draw_text_transformed_colour → F_DrawTextTransformedColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=11 flag=1
 *   @0x124ee4 ldr r1, [pc, #-0x744]
 *   @0x124ee8 ldr r0, [pc, #-0x744]
 *   @0x124eec mov r2, #10
 *   @0x124ef0 mov r3, #1
 *   @0x124ef4 ldr r5, [r4, r1]
 *   @0x124ef8 add r0, pc, r0
 *   @0x124efc mov r1, r5
 *   @0x124f00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #181 draw_text_ext_color → F_DrawTextExtColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=10 flag=1
 *   @0x124f04 ldr r0, [pc, #-0x75c]
 *   @0x124f08 mov r1, r5
 *   @0x124f0c mov r2, #10
 *   @0x124f10 add r0, pc, r0
 *   @0x124f14 mov r3, #1
 *   @0x124f18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #182 draw_text_ext_colour → F_DrawTextExtColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=10 flag=1
 *   @0x124f1c ldr r1, [pc, #-0x770]
 *   @0x124f20 ldr r0, [pc, #-0x770]
 *   @0x124f24 mov r2, #13
 *   @0x124f28 mov r3, #1
 *   @0x124f2c ldr r5, [r4, r1]
 *   @0x124f30 add r0, pc, r0
 *   @0x124f34 mov r1, r5
 *   @0x124f38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #183 draw_text_ext_transformed_color → F_DrawTextExtTransformedColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=13 flag=1
 *   @0x124f3c ldr r0, [pc, #-0x788]
 *   @0x124f40 mov r1, r5
 *   @0x124f44 mov r2, #13
 *   @0x124f48 add r0, pc, r0
 *   @0x124f4c mov r3, #1
 *   @0x124f50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #184 draw_text_ext_transformed_colour → F_DrawTextExtTransformedColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=13 flag=1
 *   @0x124f54 ldr r1, [pc, #-0x79c]
 *   @0x124f58 ldr r0, [pc, #-0x79c]
 *   @0x124f5c mov r2, #9
 *   @0x124f60 mov r3, #1
 *   @0x124f64 ldr r1, [r4, r1]
 *   @0x124f68 add r0, pc, r0
 *   @0x124f6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #185 collision_shape → F_CollisionShape(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x124f70 ldr r1, [pc, #-0x7b0]
 *   @0x124f74 ldr r0, [pc, #-0x7b0]
 *   @0x124f78 mov r2, #0
 *   @0x124f7c mov r3, r2
 *   @0x124f80 ldr r1, [r4, r1]
 *   @0x124f84 add r0, pc, r0
 *   @0x124f88 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #186 draw_self → F_DrawSelf(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x124f8c ldr r1, [pc, #-0x7c4]
 *   @0x124f90 ldr r0, [pc, #-0x7c4]
 *   @0x124f94 mov r2, #4
 *   @0x124f98 mov r3, #0
 *   @0x124f9c ldr r1, [r4, r1]
 *   @0x124fa0 add r0, pc, r0
 *   @0x124fa4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #187 draw_sprite → F_DrawSprite(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x124fa8 ldr r1, [pc, #-0x7d8]
 *   @0x124fac ldr r0, [pc, #-0x7d8]
 *   @0x124fb0 mov r2, #11
 *   @0x124fb4 mov r3, #1
 *   @0x124fb8 ldr r1, [r4, r1]
 *   @0x124fbc add r0, pc, r0
 *   @0x124fc0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #188 draw_shape → F_DrawShape(RValue&, CInstance*, CInstance*, int, RValue*) argc=11 flag=1
 *   @0x124fc4 ldr r1, [pc, #-0x7ec]
 *   @0x124fc8 ldr r0, [pc, #-0x7ec]
 *   @0x124fcc mov r2, #10
 *   @0x124fd0 mov r3, #1
 *   @0x124fd4 ldr r1, [r4, r1]
 *   @0x124fd8 add r0, pc, r0
 *   @0x124fdc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #189 draw_shape_string → F_DrawShapeString(RValue&, CInstance*, CInstance*, int, RValue*) argc=10 flag=1
 *   @0x124fe0 ldr r1, [pc, #-0x800]
 *   @0x124fe4 ldr r0, [pc, #-0x800]
 *   @0x124fe8 mov r2, #9
 *   @0x124fec mov r3, #1
 *   @0x124ff0 ldr r1, [r4, r1]
 *   @0x124ff4 add r0, pc, r0
 *   @0x124ff8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #190 draw_sprite_ext → F_DrawSpriteExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x124ffc ldr r1, [pc, #-0x814]
 *   @0x125000 ldr r0, [pc, #-0x814]
 *   @0x125004 mov r2, #11
 *   @0x125008 mov r3, #0
 *   @0x12500c ldr r1, [r4, r1]
 *   @0x125010 add r0, pc, r0
 *   @0x125014 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #191 draw_sprite_pos → F_DrawSpritePos(RValue&, CInstance*, CInstance*, int, RValue*) argc=11 flag=0
 *   @0x125018 ldr r1, [pc, #-0x828]
 *   @0x12501c ldr r0, [pc, #-0x828]
 *   @0x125020 mov r2, #6
 *   @0x125024 mov r3, #0
 *   @0x125028 ldr r1, [r4, r1]
 *   @0x12502c add r0, pc, r0
 *   @0x125030 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #192 draw_sprite_stretched → F_DrawSpriteStretched(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=0
 *   @0x125034 ldr r1, [pc, #-0x83c]
 *   @0x125038 ldr r0, [pc, #-0x83c]
 *   @0x12503c mov r2, #8
 *   @0x125040 mov r3, #1
 *   @0x125044 ldr r1, [r4, r1]
 *   @0x125048 add r0, pc, r0
 *   @0x12504c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #193 draw_sprite_stretched_ext → F_DrawSpriteStretchedExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x125050 ldr r1, [pc, #-0x850]
 *   @0x125054 ldr r0, [pc, #-0x850]
 *   @0x125058 mov r2, #8
 *   @0x12505c mov r3, #0
 *   @0x125060 ldr r1, [r4, r1]
 *   @0x125064 add r0, pc, r0
 *   @0x125068 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #194 draw_sprite_part → F_DrawSpritePart(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=0
 *   @0x12506c ldr r1, [pc, #-0x864]
 *   @0x125070 ldr r0, [pc, #-0x864]
 *   @0x125074 mov r2, #12
 *   @0x125078 mov r3, #1
 *   @0x12507c ldr r1, [r4, r1]
 *   @0x125080 add r0, pc, r0
 *   @0x125084 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #195 draw_sprite_part_ext → F_DrawSpritePartExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=12 flag=1
 *   @0x125088 ldr r1, [pc, #-0x878]
 *   @0x12508c ldr r0, [pc, #-0x878]
 *   @0x125090 mov r2, #16
 *   @0x125094 mov r3, #1
 *   @0x125098 ldr r1, [r4, r1]
 *   @0x12509c add r0, pc, r0
 *   @0x1250a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #196 draw_sprite_general → F_DrawSpriteGeneral(RValue&, CInstance*, CInstance*, int, RValue*) argc=16 flag=1
 *   @0x1250a4 ldr r1, [pc, #-0x88c]
 *   @0x1250a8 ldr r0, [pc, #-0x88c]
 *   @0x1250ac mov r2, #4
 *   @0x1250b0 mov r3, #0
 *   @0x1250b4 ldr r1, [r4, r1]
 *   @0x1250b8 add r0, pc, r0
 *   @0x1250bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #197 draw_sprite_tiled → F_DrawSpriteTiled(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x1250c0 ldr r1, [pc, #-0x8a0]
 *   @0x1250c4 ldr r0, [pc, #-0x8a0]
 *   @0x1250c8 mov r2, #8
 *   @0x1250cc mov r3, #1
 *   @0x1250d0 ldr r1, [r4, r1]
 *   @0x1250d4 add r0, pc, r0
 *   @0x1250d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #198 draw_sprite_tiled_ext → F_DrawSpriteTiledExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x1250dc ldr r1, [pc, #-0x8b4]
 *   @0x1250e0 ldr r0, [pc, #-0x8b4]
 *   @0x1250e4 mov r2, #3
 *   @0x1250e8 mov r3, #0
 *   @0x1250ec ldr r1, [r4, r1]
 *   @0x1250f0 add r0, pc, r0
 *   @0x1250f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #199 draw_background → F_DrawBackground(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x1250f8 ldr r1, [pc, #-0x8c8]
 *   @0x1250fc ldr r0, [pc, #-0x8c8]
 *   @0x125100 mov r2, #8
 *   @0x125104 mov r3, #1
 *   @0x125108 ldr r1, [r4, r1]
 *   @0x12510c add r0, pc, r0
 *   @0x125110 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #200 draw_background_ext → F_DrawBackgroundExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x125114 ldr r1, [pc, #-0x8dc]
 *   @0x125118 ldr r0, [pc, #-0x8dc]
 *   @0x12511c mov r2, #5
 *   @0x125120 mov r3, #0
 *   @0x125124 ldr r1, [r4, r1]
 *   @0x125128 add r0, pc, r0
 *   @0x12512c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #201 draw_background_stretched → F_DrawBackgroundStretched(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0x125130 ldr r1, [pc, #-0x8f0]
 *   @0x125134 ldr r0, [pc, #-0x8f0]
 *   @0x125138 mov r2, #7
 *   @0x12513c mov r3, #1
 *   @0x125140 ldr r1, [r4, r1]
 *   @0x125144 add r0, pc, r0
 *   @0x125148 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #202 draw_background_stretched_ext → F_DrawBackgroundStretchedExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x12514c ldr r1, [pc, #-0x904]
 *   @0x125150 ldr r0, [pc, #-0x904]
 *   @0x125154 mov r2, #7
 *   @0x125158 mov r3, #0
 *   @0x12515c ldr r1, [r4, r1]
 *   @0x125160 add r0, pc, r0
 *   @0x125164 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #203 draw_background_part → F_DrawBackgroundPart(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=0
 *   @0x125168 ldr r1, [pc, #-0x918]
 *   @0x12516c ldr r0, [pc, #-0x918]
 *   @0x125170 mov r2, #11
 *   @0x125174 mov r3, #1
 *   @0x125178 ldr r1, [r4, r1]
 *   @0x12517c add r0, pc, r0
 *   @0x125180 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #204 draw_background_part_ext → F_DrawBackgroundPartExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=11 flag=1
 *   @0x125184 ldr r1, [pc, #-0x92c]
 *   @0x125188 ldr r0, [pc, #-0x92c]
 *   @0x12518c mov r2, #15
 *   @0x125190 mov r3, #1
 *   @0x125194 ldr r1, [r4, r1]
 *   @0x125198 add r0, pc, r0
 *   @0x12519c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #205 draw_background_general → F_DrawBackgroundGeneral(RValue&, CInstance*, CInstance*, int, RValue*) argc=15 flag=1
 *   @0x1251a0 ldr r1, [pc, #-0x940]
 *   @0x1251a4 ldr r0, [pc, #-0x940]
 *   @0x1251a8 mov r2, #3
 *   @0x1251ac mov r3, #0
 *   @0x1251b0 ldr r1, [r4, r1]
 *   @0x1251b4 add r0, pc, r0
 *   @0x1251b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #206 draw_background_tiled → F_DrawBackgroundTiled(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x1251bc ldr r1, [pc, #-0x954]
 *   @0x1251c0 ldr r0, [pc, #-0x954]
 *   @0x1251c4 mov r2, #7
 *   @0x1251c8 mov r3, #1
 *   @0x1251cc ldr r1, [r4, r1]
 *   @0x1251d0 add r0, pc, r0
 *   @0x1251d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #207 draw_background_tiled_ext → F_DrawBackgroundTiledExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x1251d8 ldr r1, [pc, #-0x968]
 *   @0x1251dc ldr r0, [pc, #-0x968]
 *   @0x1251e0 mov r2, #1
 *   @0x1251e4 mov r3, r2
 *   @0x1251e8 ldr r1, [r4, r1]
 *   @0x1251ec add r0, pc, r0
 *   @0x1251f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #208 shader_enable_corner_id → F_DrawEnableCornerID(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1251f4 ldr r1, [pc, #-0x97c]
 *   @0x1251f8 ldr r0, [pc, #-0x97c]
 *   @0x1251fc mov r2, #1
 *   @0x125200 mov r3, #0
 *   @0x125204 ldr r1, [r4, r1]
 *   @0x125208 add r0, pc, r0
 *   @0x12520c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #209 tile_get_x → F_TileGetX(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x125210 ldr r1, [pc, #-0x990]
 *   @0x125214 ldr r0, [pc, #-0x990]
 *   @0x125218 mov r2, #1
 *   @0x12521c mov r3, #0
 *   @0x125220 ldr r1, [r4, r1]
 *   @0x125224 add r0, pc, r0
 *   @0x125228 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #210 tile_get_y → F_TileGetY(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x12522c ldr r1, [pc, #-0x9a4]
 *   @0x125230 ldr r0, [pc, #-0x9a4]
 *   @0x125234 mov r2, #1
 *   @0x125238 mov r3, #0
 *   @0x12523c ldr r1, [r4, r1]
 *   @0x125240 add r0, pc, r0
 *   @0x125244 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #211 tile_get_left → F_TileGetLeft(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x125248 ldr r1, [pc, #-0x9b8]
 *   @0x12524c ldr r0, [pc, #-0x9b8]
 *   @0x125250 mov r2, #1
 *   @0x125254 mov r3, #0
 *   @0x125258 ldr r1, [r4, r1]
 *   @0x12525c add r0, pc, r0
 *   @0x125260 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #212 tile_get_top → F_TileGetTop(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x125264 ldr r1, [pc, #-0x9cc]
 *   @0x125268 ldr r0, [pc, #-0x9cc]
 *   @0x12526c mov r2, #1
 *   @0x125270 mov r3, #0
 *   @0x125274 ldr r1, [r4, r1]
 *   @0x125278 add r0, pc, r0
 *   @0x12527c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #213 tile_get_width → F_TileGetWidth(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x125280 ldr r1, [pc, #-0x9e0]
 *   @0x125284 ldr r0, [pc, #-0x9e0]
 *   @0x125288 mov r2, #1
 *   @0x12528c mov r3, #0
 *   @0x125290 ldr r1, [r4, r1]
 *   @0x125294 add r0, pc, r0
 *   @0x125298 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #214 tile_get_height → F_TileGetHeight(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x12529c ldr r1, [pc, #-0x9f4]
 *   @0x1252a0 ldr r0, [pc, #-0x9f4]
 *   @0x1252a4 mov r2, #1
 *   @0x1252a8 mov r3, #0
 *   @0x1252ac ldr r1, [r4, r1]
 *   @0x1252b0 add r0, pc, r0
 *   @0x1252b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #215 tile_get_depth → F_TileGetDepth(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1252b8 ldr r1, [pc, #-0xa08]
 *   @0x1252bc ldr r0, [pc, #-0xa08]
 *   @0x1252c0 mov r2, #1
 *   @0x1252c4 mov r3, #0
 *   @0x1252c8 ldr r1, [r4, r1]
 *   @0x1252cc add r0, pc, r0
 *   @0x1252d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #216 tile_get_visible → F_TileGetVisible(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1252d4 ldr r1, [pc, #-0xa1c]
 *   @0x1252d8 ldr r0, [pc, #-0xa1c]
 *   @0x1252dc mov r2, #1
 *   @0x1252e0 mov r3, #0
 *   @0x1252e4 ldr r1, [r4, r1]
 *   @0x1252e8 add r0, pc, r0
 *   @0x1252ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #217 tile_get_xscale → F_TileGetXscale(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1252f0 ldr r1, [pc, #-0xa30]
 *   @0x1252f4 ldr r0, [pc, #-0xa30]
 *   @0x1252f8 mov r2, #1
 *   @0x1252fc mov r3, #0
 *   @0x125300 ldr r1, [r4, r1]
 *   @0x125304 add r0, pc, r0
 *   @0x125308 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #218 tile_get_yscale → F_TileGetYscale(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x12530c ldr r1, [pc, #-0xa44]
 *   @0x125310 ldr r0, [pc, #-0xa44]
 *   @0x125314 mov r2, #1
 *   @0x125318 mov r3, #0
 *   @0x12531c ldr r1, [r4, r1]
 *   @0x125320 add r0, pc, r0
 *   @0x125324 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #219 tile_get_blend → F_TileGetBlend(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x125328 ldr r1, [pc, #-0xa58]
 *   @0x12532c ldr r0, [pc, #-0xa58]
 *   @0x125330 mov r2, #1
 *   @0x125334 mov r3, #0
 *   @0x125338 ldr r1, [r4, r1]
 *   @0x12533c add r0, pc, r0
 *   @0x125340 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #220 tile_get_alpha → F_TileGetAlpha(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x125344 ldr r1, [pc, #-0xa6c]
 *   @0x125348 ldr r0, [pc, #-0xa6c]
 *   @0x12534c mov r2, #1
 *   @0x125350 mov r3, #0
 *   @0x125354 ldr r1, [r4, r1]
 *   @0x125358 add r0, pc, r0
 *   @0x12535c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #221 tile_get_background → F_TileGetBackground(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x125360 ldr r1, [pc, #-0xa80]
 *   @0x125364 ldr r0, [pc, #-0xa80]
 *   @0x125368 mov r2, #2
 *   @0x12536c mov r3, #0
 *   @0x125370 ldr r1, [r4, r1]
 *   @0x125374 add r0, pc, r0
 *   @0x125378 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #222 tile_set_visible → F_TileSetVisible(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x12537c ldr r1, [pc, #-0xa94]
 *   @0x125380 ldr r0, [pc, #-0xa94]
 *   @0x125384 mov r2, #2
 *   @0x125388 mov r3, #0
 *   @0x12538c ldr r1, [r4, r1]
 *   @0x125390 add r0, pc, r0
 *   @0x125394 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #223 tile_set_background → F_TileSetBackground(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x125398 ldr r1, [pc, #-0xaa8]
 *   @0x12539c ldr r0, [pc, #-0xaa8]
 *   @0x1253a0 mov r2, #5
 *   @0x1253a4 mov r3, #0
 *   @0x1253a8 ldr r1, [r4, r1]
 *   @0x1253ac add r0, pc, r0
 *   @0x1253b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #224 tile_set_region → F_TileSetRegion(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0x1253b4 ldr r1, [pc, #-0xabc]
 *   @0x1253b8 ldr r0, [pc, #-0xabc]
 *   @0x1253bc mov r2, #3
 *   @0x1253c0 mov r3, #0
 *   @0x1253c4 ldr r1, [r4, r1]
 *   @0x1253c8 add r0, pc, r0
 *   @0x1253cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #225 tile_set_position → F_TileSetPosition(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x1253d0 ldr r1, [pc, #-0xad0]
 *   @0x1253d4 ldr r0, [pc, #-0xad0]
 *   @0x1253d8 mov r2, #2
 *   @0x1253dc mov r3, #0
 *   @0x1253e0 ldr r1, [r4, r1]
 *   @0x1253e4 add r0, pc, r0
 *   @0x1253e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #226 tile_set_depth → F_TileSetDepth(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1253ec ldr r1, [pc, #-0xae4]
 *   @0x1253f0 ldr r0, [pc, #-0xae4]
 *   @0x1253f4 mov r2, #3
 *   @0x1253f8 mov r3, #0
 *   @0x1253fc ldr r1, [r4, r1]
 *   @0x125400 add r0, pc, r0
 *   @0x125404 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #227 tile_set_scale → F_TileSetScale(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x125408 ldr r1, [pc, #-0xaf8]
 *   @0x12540c ldr r0, [pc, #-0xaf8]
 *   @0x125410 mov r2, #2
 *   @0x125414 mov r3, #1
 *   @0x125418 ldr r1, [r4, r1]
 *   @0x12541c add r0, pc, r0
 *   @0x125420 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #228 tile_set_blend → F_TileSetBlend(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x125424 ldr r1, [pc, #-0xb0c]
 *   @0x125428 ldr r0, [pc, #-0xb0c]
 *   @0x12542c mov r2, #2
 *   @0x125430 mov r3, #0
 *   @0x125434 ldr r1, [r4, r1]
 *   @0x125438 add r0, pc, r0
 *   @0x12543c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #229 tile_set_alpha → F_TileSetAlpha(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x125440 ldr r1, [pc, #-0xb20]
 *   @0x125444 ldr r0, [pc, #-0xb20]
 *   @0x125448 mov r2, #0
 *   @0x12544c mov r3, r2
 *   @0x125450 ldr r1, [r4, r1]
 *   @0x125454 add r0, pc, r0
 *   @0x125458 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #230 tile_get_count → F_TileCount(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x12545c ldr r1, [pc, #-0xb34]
 *   @0x125460 ldr r0, [pc, #-0xb34]
 *   @0x125464 mov r2, #1
 *   @0x125468 mov r3, #0
 *   @0x12546c ldr r1, [r4, r1]
 *   @0x125470 add r0, pc, r0
 *   @0x125474 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #231 tile_get_id → F_TileGetID(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x125478 ldr r1, [pc, #-0xb48]
 *   @0x12547c ldr r0, [pc, #-0xb48]
 *   @0x125480 mov r2, #0
 *   @0x125484 mov r3, r2
 *   @0x125488 ldr r1, [r4, r1]
 *   @0x12548c add r0, pc, r0
 *   @0x125490 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #232 tile_get_ids → F_TileGetIDs(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x125494 ldr r1, [pc, #-0xb5c]
 *   @0x125498 ldr r0, [pc, #-0xb5c]
 *   @0x12549c mov r2, #1
 *   @0x1254a0 mov r3, #0
 *   @0x1254a4 ldr r1, [r4, r1]
 *   @0x1254a8 add r0, pc, r0
 *   @0x1254ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #233 tile_get_ids_at_depth → F_TileGetIDsAtDepth(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1254b0 ldr r1, [pc, #-0xb70]
 *   @0x1254b4 ldr r0, [pc, #-0xb70]
 *   @0x1254b8 mov r2, #8
 *   @0x1254bc mov r3, #0
 *   @0x1254c0 ldr r1, [r4, r1]
 *   @0x1254c4 add r0, pc, r0
 *   @0x1254c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #234 tile_add → F_TileAdd(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=0
 *   @0x1254cc ldr r1, [pc, #-0xb84]
 *   @0x1254d0 ldr r0, [pc, #-0xb84]
 *   @0x1254d4 mov r2, #1
 *   @0x1254d8 mov r3, #0
 *   @0x1254dc ldr r1, [r4, r1]
 *   @0x1254e0 add r0, pc, r0
 *   @0x1254e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #235 tile_exists → F_TileExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1254e8 ldr r1, [pc, #-0xb98]
 *   @0x1254ec ldr r0, [pc, #-0xb98]
 *   @0x1254f0 mov r2, #1
 *   @0x1254f4 mov r3, #0
 *   @0x1254f8 ldr r1, [r4, r1]
 *   @0x1254fc add r0, pc, r0
 *   @0x125500 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #236 tile_delete → F_TileDelete(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x125504 ldr r1, [pc, #-0xbac]
 *   @0x125508 ldr r0, [pc, #-0xbac]
 *   @0x12550c mov r2, #1
 *   @0x125510 mov r3, #0
 *   @0x125514 ldr r1, [r4, r1]
 *   @0x125518 add r0, pc, r0
 *   @0x12551c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #237 tile_layer_hide → F_TileLayerHide(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x125520 ldr r1, [pc, #-0xbc0]
 *   @0x125524 ldr r0, [pc, #-0xbc0]
 *   @0x125528 mov r2, #1
 *   @0x12552c mov r3, #0
 *   @0x125530 ldr r1, [r4, r1]
 *   @0x125534 add r0, pc, r0
 *   @0x125538 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #238 tile_layer_show → F_TileLayerShow(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x12553c ldr r1, [pc, #-0xbd4]
 *   @0x125540 ldr r0, [pc, #-0xbd4]
 *   @0x125544 mov r2, #1
 *   @0x125548 mov r3, #0
 *   @0x12554c ldr r1, [r4, r1]
 *   @0x125550 add r0, pc, r0
 *   @0x125554 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #239 tile_layer_delete → F_TileLayerDelete(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x125558 ldr r1, [pc, #-0xbe8]
 *   @0x12555c ldr r0, [pc, #-0xbe8]
 *   @0x125560 mov r2, #3
 *   @0x125564 mov r3, #0
 *   @0x125568 ldr r1, [r4, r1]
 *   @0x12556c add r0, pc, r0
 *   @0x125570 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #240 tile_layer_shift → F_TileLayerShift(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x125574 ldr r1, [pc, #-0xbfc]
 *   @0x125578 ldr r0, [pc, #-0xbfc]
 *   @0x12557c mov r2, #3
 *   @0x125580 mov r3, #0
 *   @0x125584 ldr r1, [r4, r1]
 *   @0x125588 add r0, pc, r0
 *   @0x12558c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #241 tile_layer_find → F_TileLayerFind(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x125590 ldr r1, [pc, #-0xc10]
 *   @0x125594 ldr r0, [pc, #-0xc10]
 *   @0x125598 mov r2, #3
 *   @0x12559c mov r3, #0
 *   @0x1255a0 ldr r1, [r4, r1]
 *   @0x1255a4 add r0, pc, r0
 *   @0x1255a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #242 tile_layer_delete_at → F_TileLayerDeleteAt(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x1255ac ldr r1, [pc, #-0xc24]
 *   @0x1255b0 ldr r0, [pc, #-0xc24]
 *   @0x1255b4 mov r2, #2
 *   @0x1255b8 mov r3, #0
 *   @0x1255bc ldr r1, [r4, r1]
 *   @0x1255c0 add r0, pc, r0
 *   @0x1255c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #243 tile_layer_depth → F_TileLayerDepth(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1255c8 ldr r1, [pc, #-0xc38]
 *   @0x1255cc ldr r0, [pc, #-0xc38]
 *   @0x1255d0 mov r2, #2
 *   @0x1255d4 mov r3, #1
 *   @0x1255d8 ldr r1, [r4, r1]
 *   @0x1255dc add r0, pc, r0
 *   @0x1255e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #244 surface_create → F_SurfaceCreate(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1255e4 ldr r1, [pc, #-0xc4c]
 *   @0x1255e8 ldr r0, [pc, #-0xc4c]
 *   @0x1255ec mov r2, #3
 *   @0x1255f0 mov r3, #1
 *   @0x1255f4 ldr r1, [r4, r1]
 *   @0x1255f8 add r0, pc, r0
 *   @0x1255fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #245 surface_create_ext → F_SurfaceCreateEmpty(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x125600 ldr r1, [pc, #-0xc60]
 *   @0x125604 ldr r0, [pc, #-0xc60]
 *   @0x125608 mov r2, #3
 *   @0x12560c mov r3, #1
 *   @0x125610 ldr r1, [r4, r1]
 *   @0x125614 add r0, pc, r0
 *   @0x125618 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #246 surface_create_special → F_SurfaceCreateSpecial(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x12561c ldr r1, [pc, #-0xc74]
 *   @0x125620 ldr r0, [pc, #-0xc74]
 *   @0x125624 mov r2, #3
 *   @0x125628 mov r3, #1
 *   @0x12562c ldr r1, [r4, r1]
 *   @0x125630 add r0, pc, r0
 *   @0x125634 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #247 surface_resize → F_SurfaceResize(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x125638 ldr r1, [pc, #-0xc88]
 *   @0x12563c ldr r0, [pc, #-0xc88]
 *   @0x125640 mov r2, #1
 *   @0x125644 mov r3, r2
 *   @0x125648 ldr r1, [r4, r1]
 *   @0x12564c add r0, pc, r0
 *   @0x125650 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #248 surface_free → F_SurfaceFree(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x125654 ldr r1, [pc, #-0xc9c]
 *   @0x125658 ldr r0, [pc, #-0xc9c]
 *   @0x12565c mov r2, #1
 *   @0x125660 mov r3, r2
 *   @0x125664 ldr r1, [r4, r1]
 *   @0x125668 add r0, pc, r0
 *   @0x12566c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #249 surface_exists → F_SurfaceExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x125670 ldr r1, [pc, #-0xcb0]
 *   @0x125674 ldr r0, [pc, #-0xcb0]
 *   @0x125678 mov r2, #1
 *   @0x12567c mov r3, r2
 *   @0x125680 ldr r1, [r4, r1]
 *   @0x125684 add r0, pc, r0
 *   @0x125688 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #250 surface_get_width → F_SurfaceGetWidth(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x12568c ldr r1, [pc, #-0xcc4]
 *   @0x125690 ldr r0, [pc, #-0xcc4]
 *   @0x125694 mov r2, #1
 *   @0x125698 mov r3, r2
 *   @0x12569c ldr r1, [r4, r1]
 *   @0x1256a0 add r0, pc, r0
 *   @0x1256a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #251 surface_get_height → F_SurfaceGetHeight(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1256a8 ldr r1, [pc, #-0xcd8]
 *   @0x1256ac ldr r0, [pc, #-0xcd8]
 *   @0x1256b0 mov r2, #1
 *   @0x1256b4 mov r3, r2
 *   @0x1256b8 ldr r1, [r4, r1]
 *   @0x1256bc add r0, pc, r0
 *   @0x1256c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #252 surface_get_texture → F_SurfaceGetTexture(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1256c4 ldr r1, [pc, #-0xcec]
 *   @0x1256c8 ldr r0, [pc, #-0xcec]
 *   @0x1256cc mov r2, #1
 *   @0x1256d0 mov r3, r2
 *   @0x1256d4 ldr r1, [r4, r1]
 *   @0x1256d8 add r0, pc, r0
 *   @0x1256dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #253 surface_set_target → F_SurfaceSetTarget(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1256e0 ldr r1, [pc, #-0xd00]
 *   @0x1256e4 ldr r0, [pc, #-0xd00]
 *   @0x1256e8 mov r2, #2
 *   @0x1256ec mov r3, #1
 *   @0x1256f0 ldr r1, [r4, r1]
 *   @0x1256f4 add r0, pc, r0
 *   @0x1256f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #254 surface_set_target_ext → F_SurfaceSetTargetExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1256fc ldr r1, [pc, #-0xd14]
 *   @0x125700 ldr r0, [pc, #-0xd14]
 *   @0x125704 mov r2, #0
 *   @0x125708 mov r3, #1
 *   @0x12570c ldr r1, [r4, r1]
 *   @0x125710 add r0, pc, r0
 *   @0x125714 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #255 surface_reset_target → F_SurfaceResetTarget(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x125718 ldr r1, [pc, #-0xd28]
 *   @0x12571c ldr r0, [pc, #-0xd28]
 *   @0x125720 mov r2, #1
 *   @0x125724 mov r3, r2
 *   @0x125728 ldr r1, [r4, r1]
 *   @0x12572c add r0, pc, r0
 *   @0x125730 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #256 surface_depth_disable → F_SurfaceDepthDisable(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x125734 ldr r1, [pc, #-0xd3c]
 *   @0x125738 ldr r0, [pc, #-0xd3c]
 *   @0x12573c mov r2, #0
 *   @0x125740 mov r3, #1
 *   @0x125744 ldr r1, [r4, r1]
 *   @0x125748 add r0, pc, r0
 *   @0x12574c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #257 surface_get_depth_disable → F_SurfaceGetDepthDisable(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x125750 ldr r1, [pc, #-0xd50]
 *   @0x125754 ldr r0, [pc, #-0xd50]
 *   @0x125758 mov r2, #3
 *   @0x12575c mov r3, #1
 *   @0x125760 ldr r1, [r4, r1]
 *   @0x125764 add r0, pc, r0
 *   @0x125768 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #258 draw_surface → F_DrawSurface(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x12576c ldr r1, [pc, #-0xd64]
 *   @0x125770 ldr r0, [pc, #-0xd64]
 *   @0x125774 mov r2, #8
 *   @0x125778 mov r3, #1
 *   @0x12577c ldr r1, [r4, r1]
 *   @0x125780 add r0, pc, r0
 *   @0x125784 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #259 draw_surface_ext → F_DrawSurfaceExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x125788 ldr r1, [pc, #-0xd78]
 *   @0x12578c ldr r0, [pc, #-0xd78]
 *   @0x125790 mov r2, #5
 *   @0x125794 mov r3, #1
 *   @0x125798 ldr r1, [r4, r1]
 *   @0x12579c add r0, pc, r0
 *   @0x1257a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #260 draw_surface_stretched → F_DrawSurfaceStretched(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x1257a4 ldr r1, [pc, #-0xd8c]
 *   @0x1257a8 ldr r0, [pc, #-0xd8c]
 *   @0x1257ac mov r2, #7
 *   @0x1257b0 mov r3, #1
 *   @0x1257b4 ldr r1, [r4, r1]
 *   @0x1257b8 add r0, pc, r0
 *   @0x1257bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #261 draw_surface_stretched_ext → F_DrawSurfaceStretchedExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x1257c0 ldr r1, [pc, #-0xda0]
 *   @0x1257c4 ldr r0, [pc, #-0xda0]
 *   @0x1257c8 mov r2, #7
 *   @0x1257cc mov r3, #1
 *   @0x1257d0 ldr r1, [r4, r1]
 *   @0x1257d4 add r0, pc, r0
 *   @0x1257d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #262 draw_surface_part → F_DrawSurfacePart(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x1257dc ldr r1, [pc, #-0xdb4]
 *   @0x1257e0 ldr r0, [pc, #-0xdb4]
 *   @0x1257e4 mov r2, #11
 *   @0x1257e8 mov r3, #1
 *   @0x1257ec ldr r1, [r4, r1]
 *   @0x1257f0 add r0, pc, r0
 *   @0x1257f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #263 draw_surface_part_ext → F_DrawSurfacePartExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=11 flag=1
 *   @0x1257f8 ldr r1, [pc, #-0xdc8]
 *   @0x1257fc ldr r0, [pc, #-0xdc8]
 *   @0x125800 mov r2, #15
 *   @0x125804 mov r3, #1
 *   @0x125808 ldr r1, [r4, r1]
 *   @0x12580c add r0, pc, r0
 *   @0x125810 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #264 draw_surface_general → F_DrawSurfaceGeneral(RValue&, CInstance*, CInstance*, int, RValue*) argc=15 flag=1
 *   @0x125814 ldr r1, [pc, #-0xddc]
 *   @0x125818 ldr r0, [pc, #-0xddc]
 *   @0x12581c mov r2, #3
 *   @0x125820 mov r3, #1
 *   @0x125824 ldr r1, [r4, r1]
 *   @0x125828 add r0, pc, r0
 *   @0x12582c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #265 draw_surface_tiled → F_DrawSurfaceTiled(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x125830 ldr r1, [pc, #-0xdf0]
 *   @0x125834 ldr r0, [pc, #-0xdf0]
 *   @0x125838 mov r2, #7
 *   @0x12583c mov r3, #1
 *   @0x125840 ldr r1, [r4, r1]
 *   @0x125844 add r0, pc, r0
 *   @0x125848 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #266 draw_surface_tiled_ext → F_DrawSurfaceTiledExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x12584c ldr r1, [pc, #-0xe04]
 *   @0x125850 ldr r0, [pc, #-0xe04]
 *   @0x125854 mov r2, #2
 *   @0x125858 mov r3, #1
 *   @0x12585c ldr r1, [r4, r1]
 *   @0x125860 add r0, pc, r0
 *   @0x125864 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #267 surface_save → F_SurfaceSave(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x125868 ldr r1, [pc, #-0xe18]
 *   @0x12586c ldr r0, [pc, #-0xe18]
 *   @0x125870 mov r2, #6
 *   @0x125874 mov r3, #1
 *   @0x125878 ldr r1, [r4, r1]
 *   @0x12587c add r0, pc, r0
 *   @0x125880 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #268 surface_save_part → F_SurfaceSavePart(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x125884 ldr r1, [pc, #-0xe2c]
 *   @0x125888 ldr r0, [pc, #-0xe2c]
 *   @0x12588c mov r2, #3
 *   @0x125890 mov r3, #1
 *   @0x125894 ldr r1, [r4, r1]
 *   @0x125898 add r0, pc, r0
 *   @0x12589c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #269 surface_getpixel → F_SurfaceGetPixel(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x1258a0 ldr r1, [pc, #-0xe40]
 *   @0x1258a4 ldr r0, [pc, #-0xe40]
 *   @0x1258a8 mov r2, #3
 *   @0x1258ac mov r3, #1
 *   @0x1258b0 ldr r1, [r4, r1]
 *   @0x1258b4 add r0, pc, r0
 *   @0x1258b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #270 surface_getpixel_ext → F_SurfaceGetPixelExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x1258bc ldr r1, [pc, #-0xe54]
 *   @0x1258c0 ldr r0, [pc, #-0xe54]
 *   @0x1258c4 mov r2, #4
 *   @0x1258c8 mov r3, #1
 *   @0x1258cc ldr r1, [r4, r1]
 *   @0x1258d0 add r0, pc, r0
 *   @0x1258d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #271 surface_copy → F_SurfaceCopy(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x1258d8 ldr r1, [pc, #-0xe68]
 *   @0x1258dc ldr r0, [pc, #-0xe68]
 *   @0x1258e0 mov r2, #8
 *   @0x1258e4 mov r3, #1
 *   @0x1258e8 ldr r1, [r4, r1]
 *   @0x1258ec add r0, pc, r0
 *   @0x1258f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #272 surface_copy_part → F_SurfaceCopyPart(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x1258f4 ldr r1, [pc, #-0xe7c]
 *   @0x1258f8 ldr r0, [pc, #-0xe7c]
 *   @0x1258fc mov r2, #1
 *   @0x125900 mov r3, r2
 *   @0x125904 ldr r1, [r4, r1]
 *   @0x125908 add r0, pc, r0
 *   @0x12590c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #273 skeleton_animation_set → F_SkeletonSetAnimation(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x125910 ldr r1, [pc, #-0xe90]
 *   @0x125914 ldr r0, [pc, #-0xe90]
 *   @0x125918 mov r2, #0
 *   @0x12591c mov r3, #1
 *   @0x125920 ldr r5, [r4, r1]
 *   @0x125924 add r0, pc, r0
 *   @0x125928 mov r1, r5
 *   @0x12592c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #274 skeleton_animation_get → F_SkeletonGetAnimation(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x125930 ldr r1, [pc, #-0xea8]
 *   @0x125934 ldr r0, [pc, #-0xea8]
 *   @0x125938 mov r2, #3
 *   @0x12593c mov r3, #1
 *   @0x125940 ldr r1, [r4, r1]
 *   @0x125944 add r0, pc, r0
 *   @0x125948 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #275 skeleton_animation_mix → F_SkeletonAnimationMix(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x12594c ldr r1, [pc, #-0xebc]
 *   @0x125950 ldr r0, [pc, #-0xebc]
 *   @0x125954 mov r2, #2
 *   @0x125958 mov r3, #1
 *   @0x12595c ldr r1, [r4, r1]
 *   @0x125960 add r0, pc, r0
 *   @0x125964 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #276 skeleton_animation_set_ext → F_SkeletonSetAnimationExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x125968 ldr r0, [pc, #-0xed0]
 *   @0x12596c mov r2, #1
 *   @0x125970 mov r1, r5
 *   @0x125974 mov r3, r2
 *   @0x125978 add r0, pc, r0
 *   @0x12597c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #277 skeleton_animation_get_ext → F_SkeletonGetAnimation(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x125980 ldr r1, [pc, #-0xee4]
 *   @0x125984 ldr r0, [pc, #-0xee4]
 *   @0x125988 mov r2, #1
 *   @0x12598c mov r3, r2
 *   @0x125990 ldr r1, [r4, r1]
 *   @0x125994 add r0, pc, r0
 *   @0x125998 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #278 skeleton_animation_get_duration → F_SkeletonGetDuration(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x12599c ldr r1, [pc, #-0xef8]
 *   @0x1259a0 ldr r0, [pc, #-0xef8]
 *   @0x1259a4 mov r2, #1
 *   @0x1259a8 mov r3, r2
 *   @0x1259ac ldr r1, [r4, r1]
 *   @0x1259b0 add r0, pc, r0
 *   @0x1259b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #279 skeleton_animation_get_frames → F_SkeletonGetFrames(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1259b8 ldr r1, [pc, #-0xf0c]
 *   @0x1259bc ldr r0, [pc, #-0xf0c]
 *   @0x1259c0 mov r2, #1
 *   @0x1259c4 mov r3, r2
 *   @0x1259c8 ldr r1, [r4, r1]
 *   @0x1259cc add r0, pc, r0
 *   @0x1259d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #280 skeleton_animation_clear → F_SkeletonClearAnimation(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1259d4 ldr r1, [pc, #-0xf20]
 *   @0x1259d8 ldr r0, [pc, #-0xf20]
 *   @0x1259dc mov r2, #2
 *   @0x1259e0 mov r3, #1
 *   @0x1259e4 ldr r1, [r4, r1]
 *   @0x1259e8 add r0, pc, r0
 *   @0x1259ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #281 skeleton_skin_set → F_SkeletonSetSkin(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1259f0 ldr r1, [pc, #-0xf34]
 *   @0x1259f4 ldr r0, [pc, #-0xf34]
 *   @0x1259f8 mov r2, #2
 *   @0x1259fc mov r3, #1
 *   @0x125a00 ldr r1, [r4, r1]
 *   @0x125a04 add r0, pc, r0
 *   @0x125a08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #282 skeleton_skin_get → F_SkeletonGetSkin(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x125a0c ldr r1, [pc, #-0xf48]
 *   @0x125a10 ldr r0, [pc, #-0xf48]
 *   @0x125a14 mov r2, #2
 *   @0x125a18 mov r3, #1
 *   @0x125a1c ldr r1, [r4, r1]
 *   @0x125a20 add r0, pc, r0
 *   @0x125a24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #283 skeleton_attachment_set → F_SkeletonSetAttachment(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x125a28 ldr r1, [pc, #-0xf5c]
 *   @0x125a2c ldr r0, [pc, #-0xf5c]
 *   @0x125a30 mov r2, #2
 *   @0x125a34 mov r3, #1
 *   @0x125a38 ldr r1, [r4, r1]
 *   @0x125a3c add r0, pc, r0
 *   @0x125a40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #284 skeleton_attachment_get → F_SkeletonGetAttachment(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x125a44 ldr r1, [pc, #-0xf70]
 *   @0x125a48 ldr r0, [pc, #-0xf70]
 *   @0x125a4c mov r2, #1
 *   @0x125a50 mov r3, r2
 *   @0x125a54 ldr r1, [r4, r1]
 *   @0x125a58 add r0, pc, r0
 *   @0x125a5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #285 skeleton_attachment_create → F_SkeletonCreateAttachment(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x125a60 ldr r1, [pc, #-0xf84]
 *   @0x125a64 ldr r0, [pc, #-0xf84]
 *   @0x125a68 mov r2, #1
 *   @0x125a6c mov r3, r2
 *   @0x125a70 ldr r1, [r4, r1]
 *   @0x125a74 add r0, pc, r0
 *   @0x125a78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #286 skeleton_collision_draw_set → F_SkeletonSetDrawCollision(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x125a7c ldr r1, [pc, #-0xf98]
 *   @0x125a80 ldr r0, [pc, #-0xf98]
 *   @0x125a84 mov r2, #2
 *   @0x125a88 mov r3, #1
 *   @0x125a8c ldr r1, [r4, r1]
 *   @0x125a90 add r0, pc, r0
 *   @0x125a94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #287 skeleton_bone_data_get → F_SkeletonGetBoneData(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x125a98 ldr r1, [pc, #-0xfac]
 *   @0x125a9c ldr r0, [pc, #-0xfac]
 *   @0x125aa0 mov r2, #2
 *   @0x125aa4 mov r3, #1
 *   @0x125aa8 ldr r1, [r4, r1]
 *   @0x125aac add r0, pc, r0
 *   @0x125ab0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #288 skeleton_bone_data_set → F_SkeletonSetBoneData(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x125ab4 ldr r1, [pc, #-0xfc0]
 *   @0x125ab8 ldr r0, [pc, #-0xfc0]
 *   @0x125abc mov r2, #2
 *   @0x125ac0 mov r3, #1
 *   @0x125ac4 ldr r1, [r4, r1]
 *   @0x125ac8 add r0, pc, r0
 *   @0x125acc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #289 skeleton_bone_state_get → F_SkeletonGetBoneState(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x125ad0 ldr r1, [pc, #-0xfd4]
 *   @0x125ad4 ldr r0, [pc, #-0xfd4]
 *   @0x125ad8 mov r2, #2
 *   @0x125adc mov r3, #1
 *   @0x125ae0 ldr r1, [r4, r1]
 *   @0x125ae4 add r0, pc, r0
 *   @0x125ae8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #290 skeleton_bone_state_set → F_SkeletonSetBoneState(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x125aec ldr r1, [pc, #-0xfe8]
 *   @0x125af0 ldr r0, [pc, #-0xfe8]
 *   @0x125af4 mov r2, #11
 *   @0x125af8 mov r3, #1
 *   @0x125afc ldr r1, [r4, r1]
 *   @0x125b00 add r0, pc, r0
 *   @0x125b04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #291 draw_skeleton → F_SkeletonDraw(RValue&, CInstance*, CInstance*, int, RValue*) argc=11 flag=1
 *   @0x125b08 ldr r1, [pc, #0x184]
 *   @0x125b0c ldr r0, [pc, #0x184]
 *   @0x125b10 mov r2, #11
 *   @0x125b14 mov r3, #1
 *   @0x125b18 ldr r1, [r4, r1]
 *   @0x125b1c add r0, pc, r0
 *   @0x125b20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #292 draw_skeleton_time → F_SkeletonDrawTime(RValue&, CInstance*, CInstance*, int, RValue*) argc=11 flag=1
 *   @0x125b24 ldr r1, [pc, #0x170]
 *   @0x125b28 ldr r0, [pc, #0x170]
 *   @0x125b2c mov r2, #4
 *   @0x125b30 mov r3, #1
 *   @0x125b34 ldr r1, [r4, r1]
 *   @0x125b38 add r0, pc, r0
 *   @0x125b3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #293 draw_skeleton_instance → F_SkeletonDrawInstance(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x125b40 ldr r1, [pc, #0x15c]
 *   @0x125b44 ldr r0, [pc, #0x15c]
 *   @0x125b48 mov r2, #9
 *   @0x125b4c mov r3, #1
 *   @0x125b50 ldr r1, [r4, r1]
 *   @0x125b54 add r0, pc, r0
 *   @0x125b58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #294 draw_skeleton_collision → F_SkeletonDrawCollision(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x125b5c ldr r1, [pc, #0x148]
 *   @0x125b60 ldr r0, [pc, #0x148]
 *   @0x125b64 mov r2, #2
 *   @0x125b68 mov r3, #1
 *   @0x125b6c ldr r1, [r4, r1]
 *   @0x125b70 add r0, pc, r0
 *   @0x125b74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #295 skeleton_animation_list → F_SkeletonAnimationList(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x125b78 ldr r1, [pc, #0x134]
 *   @0x125b7c ldr r0, [pc, #0x134]
 *   @0x125b80 mov r2, #2
 *   @0x125b84 mov r3, #1
 *   @0x125b88 ldr r1, [r4, r1]
 *   @0x125b8c add r0, pc, r0
 *   @0x125b90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #296 skeleton_skin_list → F_SkeletonSkinList(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x125b94 ldr r1, [pc, #0x120]
 *   @0x125b98 ldr r0, [pc, #0x120]
 *   @0x125b9c mov r2, #2
 *   @0x125ba0 mov r3, #1
 *   @0x125ba4 ldr r1, [r4, r1]
 *   @0x125ba8 add r0, pc, r0
 *   @0x125bac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #297 skeleton_slot_data → F_SkeletonSlotData(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x125bb0 ldr r1, [pc, #0x10c]
 *   @0x125bb4 ldr r0, [pc, #0x10c]
 *   @0x125bb8 mov r2, #1
 *   @0x125bbc mov r3, r2
 *   @0x125bc0 ldr r1, [r4, r1]
 *   @0x125bc4 add r0, pc, r0
 *   @0x125bc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #298 skeleton_animation_get_frame → F_SkeletonAnimationGetFrame(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x125bcc ldr r1, [pc, #0xf8]
 *   @0x125bd0 ldr r0, [pc, #0xf8]
 *   @0x125bd4 mov r2, #2
 *   @0x125bd8 mov r3, #1
 *   @0x125bdc ldr r1, [r4, r1]
 *   @0x125be0 add r0, pc, r0
 *   @0x125be4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #299 skeleton_animation_set_frame → F_SkeletonAnimationSetFrame(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x125be8 ldr r1, [pc, #0xe4]
 *   @0x125bec ldr r0, [pc, #0xe4]
 *   @0x125bf0 mov r2, #0
 *   @0x125bf4 mov r3, #1
 *   @0x125bf8 ldr r1, [r4, r1]
 *   @0x125bfc add r0, pc, r0
 *   @0x125c00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #300 skeleton_get_minmax → F_SkeletonGetMinmax(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x125c04 ldr r1, [pc, #0xd0]
 *   @0x125c08 ldr r0, [pc, #0xd0]
 *   @0x125c0c mov r2, #0
 *   @0x125c10 mov r3, #1
 *   @0x125c14 ldr r1, [r4, r1]
 *   @0x125c18 add r0, pc, r0
 *   @0x125c1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #301 skeleton_get_num_bounds → F_SkeletonGetNumBounds(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x125c20 ldr r1, [pc, #0xbc]
 *   @0x125c24 ldr r0, [pc, #0xbc]
 *   @0x125c28 mov r2, #1
 *   @0x125c2c mov r3, r2
 *   @0x125c30 ldr r1, [r4, r1]
 *   @0x125c34 add r0, pc, r0
 *   @0x125c38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #302 skeleton_get_bounds → F_SkeletonGetBounds(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x125c3c ldr r1, [pc, #0xa8]
 *   @0x125c40 ldr r0, [pc, #0xa8]
 *   @0x125c44 mov r2, #1
 *   @0x125c48 mov r3, r2
 *   @0x125c4c ldr r1, [r4, r1]
 *   @0x125c50 add r0, pc, r0
 *   @0x125c54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #303 draw_enable_swf_aa → F_DrawEnableSWFAA(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x125c58 ldr r1, [pc, #0x94]
 *   @0x125c5c ldr r0, [pc, #0x94]
 *   @0x125c60 mov r2, #1
 *   @0x125c64 mov r3, r2
 *   @0x125c68 ldr r1, [r4, r1]
 *   @0x125c6c add r0, pc, r0
 *   @0x125c70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #304 draw_set_swf_aa_level → F_DrawSetSWFAAlevel(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x125c74 ldr r1, [pc, #0x80]
 *   @0x125c78 ldr r0, [pc, #0x80]
 *   @0x125c7c mov r2, #0
 *   @0x125c80 mov r3, #1
 *   @0x125c84 ldr r1, [r4, r1]
 *   @0x125c88 add r0, pc, r0
 *   @0x125c8c pop {r4, r5, r6, lr}
 *   @0x125c90 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #305 draw_get_swf_aa_level → F_DrawGetSWFAAlevel(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x125c94 .word 0xffffcda8
 *   @0x125c98 eoreq r6, r1, r12, ror r2
 *   @0x125c9c .word 0xffffcdac
 *   @0x125ca0 eoreq r6, r1, r4, ror r2
 *   @0x125ca4 .word 0xffffcdb0
 *   @0x125ca8 eoreq r6, r1, r0, ror r2
 *   @0x125cac .word 0xffffcdb4
 *   @0x125cb0 eoreq r6, r1, r12, ror #4
 *   @0x125cb4 .word 0xffffcdb8
 *   @0x125cb8 eoreq r6, r1, r8, ror #4
 *   @0x125cbc .word 0xffffcdbc
 *   @0x125cc0 eoreq r6, r1, r0, ror #4
 *   @0x125cc4 .word 0xffffcdc0
 *   @0x125cc8 eoreq r6, r1, r8, asr r2
 *   @0x125ccc .word 0xffffcdc4
 *   @0x125cd0 eoreq r6, r1, r12, asr r2
 *   @0x125cd4 .word 0xffffcdc8
 *   @0x125cd8 eoreq r6, r1, r0, ror #4
 *   @0x125cdc .word 0xffffcdcc
 *   @0x125ce0 eoreq r6, r1, r8, asr r2
 *   @0x125ce4 .word 0xffffcdd0
 *   @0x125ce8 eoreq r6, r1, r4, asr r2
 *   @0x125cec .word 0xffffcdd4
 *   @0x125cf0 eoreq r6, r1, r12, asr #4
 *   @0x125cf4 .word 0xffffcdd8
 *   @0x125cf8 eoreq r6, r1, r4, asr #4
 *   @0x125cfc .word 0xffffcddc
 *   @0x125d00 eoreq r6, r1, r0, asr #4
 *
 * ══ §2/5 Init3DFunctions  0x149f4c..0x14bab0  size 7012  1753 条（1388 条指令 + 365 个池字）══
 * @func 0x149f4c 0x14bab0  size 7012  1753 条
 * 注册 193 条｜唯一名 193｜唯一函数指针 168｜argc -1:5 0:41 1:55 2:21 3:6 4:9 5:8 6:6 7:3 8:5 9:12 10:4 11:6 13:1 ?:11｜flag 0:2 1:189 ?:2
 * 首条 #0 matrix_get（0x149f84）→ 末条 #192 draw_enable_alphablend（0x14baa8）
 * 名字族（前 8）: d3d×87 gpu×76 matrix×16 draw×11 frustum×2 YoYo×1
 * 游戏实际调用的 99 个内建里落在本表: 1 个（d3d_set_fog）
 * 条件跳转 1 处: 0x149f68(beq)
 * 表: asm/init-tables/init-Init3DFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: #104@0x14b108(d3d_start), #105@0x14b124(d3d_end), #115@0x14b23c(d3d_primitive_end), #138@0x14b4c0(d3d_transform_set_identity), #151@0x14b62c(d3d_transform_stack_clear), #152@0x14b648(d3d_transform_stack_empty), #153@0x14b664(d3d_transform_stack_push), #154@0x14b680(d3d_transform_stack_pop), #155@0x14b69c(d3d_transform_stack_top), #156@0x14b6b8(d3d_transform_stack_discard), #158@0x14b6f0(d3d_model_create), #191@0x14ba90(YoYo_EnableAlphaBlend) 等 13 条 —— 实参来自运行期全局值或共享尾未解，本卡不猜
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x149f4c push {r4, r5, r6, r7, r8, lr}
 *   @0x149f50 ldr r4, [pc, #0xbe4]
 *   @0x149f54 ldr r3, [pc, #0xbe4]
 *   @0x149f58 add r4, pc, r4
 *   @0x149f5c ldr r6, [r4, r3]
 *   @0x149f60 ldrb r5, [r6]
 *   @0x149f64 cmp r5, #0
 *   @0x149f68 beq 0x14b0f0 <_Z15Init3DFunctionsv+0x11a4>   —— 条件跳转 → 0x14b0f0
 *   @0x149f6c ldr r1, [pc, #0xbd0]
 *   @0x149f70 mov r2, #1
 *   @0x149f74 ldr r0, [pc, #0xbcc]
 *   @0x149f78 mov r3, r2
 *   @0x149f7c add r0, pc, r0
 *   @0x149f80 ldr r1, [r4, r1]
 *   @0x149f84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 matrix_get → F_D3DGetMatrix(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x149f88 ldr r1, [pc, #0xbbc]
 *   @0x149f8c ldr r0, [pc, #0xbbc]
 *   @0x149f90 mov r2, #2
 *   @0x149f94 mov r3, #1
 *   @0x149f98 add r0, pc, r0
 *   @0x149f9c ldr r1, [r4, r1]
 *   @0x149fa0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 matrix_set → F_D3DSetMatrix(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x149fa4 ldr r1, [pc, #0xba8]
 *   @0x149fa8 ldr r0, [pc, #0xba8]
 *   @0x149fac mov r2, #0
 *   @0x149fb0 mov r3, #1
 *   @0x149fb4 add r0, pc, r0
 *   @0x149fb8 ldr r1, [r4, r1]
 *   @0x149fbc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 matrix_build_identity → F_D3DBuildMatrixIdentity(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x149fc0 ldr r1, [pc, #0xb94]
 *   @0x149fc4 ldr r0, [pc, #0xb94]
 *   @0x149fc8 mov r2, #9
 *   @0x149fcc mov r3, #1
 *   @0x149fd0 add r0, pc, r0
 *   @0x149fd4 ldr r1, [r4, r1]
 *   @0x149fd8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 matrix_build → F_D3DBuildMatrix(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x149fdc ldr r1, [pc, #0xb80]
 *   @0x149fe0 ldr r0, [pc, #0xb80]
 *   @0x149fe4 mov r2, #9
 *   @0x149fe8 mov r3, #1
 *   @0x149fec add r0, pc, r0
 *   @0x149ff0 ldr r1, [r4, r1]
 *   @0x149ff4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #4 matrix_build_lookat → F_D3DBuildMatrixLookat(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x149ff8 ldr r1, [pc, #0xb6c]
 *   @0x149ffc ldr r0, [pc, #0xb6c]
 *   @0x14a000 mov r2, #4
 *   @0x14a004 mov r3, #1
 *   @0x14a008 add r0, pc, r0
 *   @0x14a00c ldr r1, [r4, r1]
 *   @0x14a010 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #5 matrix_build_projection_ortho → F_D3DBuildMatrixProjOrtho(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x14a014 ldr r1, [pc, #0xb58]
 *   @0x14a018 ldr r0, [pc, #0xb58]
 *   @0x14a01c mov r2, #4
 *   @0x14a020 mov r3, #1
 *   @0x14a024 add r0, pc, r0
 *   @0x14a028 ldr r1, [r4, r1]
 *   @0x14a02c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #6 matrix_build_projection_perspective → F_D3DBuildMatrixProjPersp(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x14a030 ldr r1, [pc, #0xb44]
 *   @0x14a034 ldr r0, [pc, #0xb44]
 *   @0x14a038 mov r2, #4
 *   @0x14a03c mov r3, #1
 *   @0x14a040 add r0, pc, r0
 *   @0x14a044 ldr r1, [r4, r1]
 *   @0x14a048 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #7 matrix_build_projection_perspective_fov → F_D3DBuildMatrixProjPerspFov(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x14a04c ldr r1, [pc, #0xb30]
 *   @0x14a050 ldr r0, [pc, #0xb30]
 *   @0x14a054 mov r2, #2
 *   @0x14a058 mov r3, #1
 *   @0x14a05c add r0, pc, r0
 *   @0x14a060 ldr r1, [r4, r1]
 *   @0x14a064 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #8 matrix_multiply → F_D3DMatrixMultiply(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x14a068 ldr r1, [pc, #0xb1c]
 *   @0x14a06c ldr r0, [pc, #0xb1c]
 *   @0x14a070 mov r2, #4
 *   @0x14a074 mov r3, #1
 *   @0x14a078 add r0, pc, r0
 *   @0x14a07c ldr r1, [r4, r1]
 *   @0x14a080 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #9 matrix_transform_vertex → F_D3DMatrixTransformVertex(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x14a084 ldr r1, [pc, #0xb08]
 *   @0x14a088 ldr r0, [pc, #0xb08]
 *   @0x14a08c mov r2, #0
 *   @0x14a090 mov r3, #1
 *   @0x14a094 add r0, pc, r0
 *   @0x14a098 ldr r1, [r4, r1]
 *   @0x14a09c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #10 frustum_build → F_D3DBuildFrustum(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a0a0 ldr r1, [pc, #0xaf4]
 *   @0x14a0a4 ldr r0, [pc, #0xaf4]
 *   @0x14a0a8 mov r2, #4
 *   @0x14a0ac mov r3, #1
 *   @0x14a0b0 add r0, pc, r0
 *   @0x14a0b4 ldr r1, [r4, r1]
 *   @0x14a0b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #11 frustum_test_sphere → F_D3DFrustumTestSphere(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x14a0bc ldr r1, [pc, #0xae0]
 *   @0x14a0c0 ldr r0, [pc, #0xae0]
 *   @0x14a0c4 mov r2, #0
 *   @0x14a0c8 mov r3, r2
 *   @0x14a0cc add r0, pc, r0
 *   @0x14a0d0 ldr r1, [r4, r1]
 *   @0x14a0d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #12 draw_texture_flush → F_YoYo_DrawTextureFlush(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x14a0d8 ldr r1, [pc, #0xacc]
 *   @0x14a0dc ldr r0, [pc, #0xacc]
 *   @0x14a0e0 mov r2, #0
 *   @0x14a0e4 mov r3, r2
 *   @0x14a0e8 add r0, pc, r0
 *   @0x14a0ec ldr r1, [r4, r1]
 *   @0x14a0f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #13 draw_flush → F_YoYo_DrawFlush(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x14a0f4 ldrb r3, [r6]
 *   @0x14a0f8 cmp r3, #0
 *   @0x14a0fc popeq {r4, r5, r6, r7, r8, pc}
 *   @0x14a100 ldr r12, [pc, #0xaac]
 *   @0x14a104 mvn r5, #0
 *   @0x14a108 ldr r1, [pc, #0xaa8]
 *   @0x14a10c mov r2, #0
 *   @0x14a110 ldr r0, [pc, #0xaa4]
 *   @0x14a114 mov r3, #1
 *   @0x14a118 ldr r12, [r4, r12]
 *   @0x14a11c add r0, pc, r0
 *   @0x14a120 str r5, [r12]
 *   @0x14a124 ldr r1, [r4, r1]
 *   @0x14a128 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #14 matrix_stack_push → F_D3DMatrixStackPush(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a12c ldr r1, [pc, #0xa8c]
 *   @0x14a130 ldr r0, [pc, #0xa8c]
 *   @0x14a134 mov r2, #0
 *   @0x14a138 mov r3, #1
 *   @0x14a13c add r0, pc, r0
 *   @0x14a140 ldr r1, [r4, r1]
 *   @0x14a144 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #15 matrix_stack_pop → F_D3DMatrixStackPop(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a148 ldr r1, [pc, #0xa78]
 *   @0x14a14c ldr r0, [pc, #0xa78]
 *   @0x14a150 mov r2, #1
 *   @0x14a154 mov r3, r2
 *   @0x14a158 add r0, pc, r0
 *   @0x14a15c ldr r1, [r4, r1]
 *   @0x14a160 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #16 matrix_stack_set → F_D3DMatrixStackSet(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a164 ldr r1, [pc, #0xa64]
 *   @0x14a168 ldr r0, [pc, #0xa64]
 *   @0x14a16c mov r2, #0
 *   @0x14a170 mov r3, #1
 *   @0x14a174 add r0, pc, r0
 *   @0x14a178 ldr r1, [r4, r1]
 *   @0x14a17c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #17 matrix_stack_clear → F_D3DMatrixStackClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a180 ldr r1, [pc, #0xa50]
 *   @0x14a184 ldr r0, [pc, #0xa50]
 *   @0x14a188 mov r2, #0
 *   @0x14a18c mov r3, #1
 *   @0x14a190 add r0, pc, r0
 *   @0x14a194 ldr r1, [r4, r1]
 *   @0x14a198 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #18 matrix_stack_top → F_D3DMatrixStackTop(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a19c ldr r1, [pc, #0xa3c]
 *   @0x14a1a0 ldr r0, [pc, #0xa3c]
 *   @0x14a1a4 mov r2, #0
 *   @0x14a1a8 mov r3, #1
 *   @0x14a1ac add r0, pc, r0
 *   @0x14a1b0 ldr r1, [r4, r1]
 *   @0x14a1b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #19 matrix_stack_is_empty → F_D3DMatrixStackIsEmpty(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a1b8 ldr r1, [pc, #0xa28]
 *   @0x14a1bc ldr r0, [pc, #0xa28]
 *   @0x14a1c0 mov r2, #1
 *   @0x14a1c4 mov r3, r2
 *   @0x14a1c8 add r0, pc, r0
 *   @0x14a1cc ldr r1, [r4, r1]
 *   @0x14a1d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #20 gpu_set_blendenable → F_GPUSetBlendEnable(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a1d4 ldr r1, [pc, #0xa14]
 *   @0x14a1d8 ldr r0, [pc, #0xa14]
 *   @0x14a1dc mov r2, #1
 *   @0x14a1e0 mov r3, r2
 *   @0x14a1e4 add r0, pc, r0
 *   @0x14a1e8 ldr r1, [r4, r1]
 *   @0x14a1ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #21 gpu_set_ztestenable → F_GPUSetZTestEnable(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a1f0 ldr r1, [pc, #0xa00]
 *   @0x14a1f4 ldr r0, [pc, #0xa00]
 *   @0x14a1f8 mov r2, #1
 *   @0x14a1fc mov r3, r2
 *   @0x14a200 add r0, pc, r0
 *   @0x14a204 ldr r1, [r4, r1]
 *   @0x14a208 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #22 gpu_set_zfunc → F_GPUSetZFunc(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a20c ldr r1, [pc, #0x9ec]
 *   @0x14a210 ldr r0, [pc, #0x9ec]
 *   @0x14a214 mov r2, #1
 *   @0x14a218 mov r3, r2
 *   @0x14a21c add r0, pc, r0
 *   @0x14a220 ldr r1, [r4, r1]
 *   @0x14a224 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #23 gpu_set_zwriteenable → F_GPUSetZWriteEnable(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a228 ldr r1, [pc, #0x9d8]
 *   @0x14a22c ldr r0, [pc, #0x9d8]
 *   @0x14a230 mov r2, r5
 *   @0x14a234 mov r3, #1
 *   @0x14a238 add r0, pc, r0
 *   @0x14a23c ldr r1, [r4, r1]
 *   @0x14a240 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #24 gpu_set_fog → F_GPUSetFog(RValue&, CInstance*, CInstance*, int, RValue*) argc=-1 flag=1
 *   @0x14a244 ldr r1, [pc, #0x9c4]
 *   @0x14a248 ldr r0, [pc, #0x9c4]
 *   @0x14a24c mov r2, #1
 *   @0x14a250 mov r3, r2
 *   @0x14a254 add r0, pc, r0
 *   @0x14a258 ldr r1, [r4, r1]
 *   @0x14a25c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #25 gpu_set_cullmode → F_GPUSetCullmode(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a260 ldr r1, [pc, #0x9b0]
 *   @0x14a264 ldr r0, [pc, #0x9b0]
 *   @0x14a268 mov r2, #1
 *   @0x14a26c mov r3, r2
 *   @0x14a270 add r0, pc, r0
 *   @0x14a274 ldr r1, [r4, r1]
 *   @0x14a278 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #26 gpu_set_blendmode → F_GPUSetBlendMode(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a27c ldr r1, [pc, #0x99c]
 *   @0x14a280 ldr r0, [pc, #0x99c]
 *   @0x14a284 mov r2, r5
 *   @0x14a288 mov r3, #1
 *   @0x14a28c add r0, pc, r0
 *   @0x14a290 ldr r1, [r4, r1]
 *   @0x14a294 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #27 gpu_set_blendmode_ext → F_GPUSetBlendModeExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=-1 flag=1
 *   @0x14a298 ldr r1, [pc, #0x988]
 *   @0x14a29c ldr r0, [pc, #0x988]
 *   @0x14a2a0 mov r2, r5
 *   @0x14a2a4 mov r3, #1
 *   @0x14a2a8 add r0, pc, r0
 *   @0x14a2ac ldr r1, [r4, r1]
 *   @0x14a2b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #28 gpu_set_blendmode_ext_sepalpha → F_GPUSetBlendModeExtSepAlpha(RValue&, CInstance*, CInstance*, int, RValue*) argc=-1 flag=1
 *   @0x14a2b4 ldr r1, [pc, #0x974]
 *   @0x14a2b8 ldr r0, [pc, #0x974]
 *   @0x14a2bc mov r2, r5
 *   @0x14a2c0 mov r3, #1
 *   @0x14a2c4 ldr r6, [r4, r1]
 *   @0x14a2c8 add r0, pc, r0
 *   @0x14a2cc mov r1, r6
 *   @0x14a2d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #29 gpu_set_colorwriteenable → F_GPUSetColourWriteEnable(RValue&, CInstance*, CInstance*, int, RValue*) argc=-1 flag=1
 *   @0x14a2d4 ldr r0, [pc, #0x95c]
 *   @0x14a2d8 mov r1, r6
 *   @0x14a2dc mov r2, r5
 *   @0x14a2e0 add r0, pc, r0
 *   @0x14a2e4 mov r3, #1
 *   @0x14a2e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #30 gpu_set_colourwriteenable → F_GPUSetColourWriteEnable(RValue&, CInstance*, CInstance*, int, RValue*) argc=-1 flag=1
 *   @0x14a2ec ldr r1, [pc, #0x948]
 *   @0x14a2f0 ldr r0, [pc, #0x948]
 *   @0x14a2f4 mov r2, #1
 *   @0x14a2f8 mov r3, r2
 *   @0x14a2fc add r0, pc, r0
 *   @0x14a300 ldr r1, [r4, r1]
 *   @0x14a304 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #31 gpu_set_alphatestenable → F_GPUSetAlphaTestEnable(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a308 ldr r1, [pc, #0x934]
 *   @0x14a30c ldr r0, [pc, #0x934]
 *   @0x14a310 mov r2, #1
 *   @0x14a314 mov r3, r2
 *   @0x14a318 add r0, pc, r0
 *   @0x14a31c ldr r1, [r4, r1]
 *   @0x14a320 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #32 gpu_set_alphatestref → F_GPUSetAlphaTestRef(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a324 ldr r1, [pc, #0x920]
 *   @0x14a328 ldr r0, [pc, #0x920]
 *   @0x14a32c mov r2, #1
 *   @0x14a330 mov r3, r2
 *   @0x14a334 add r0, pc, r0
 *   @0x14a338 ldr r1, [r4, r1]
 *   @0x14a33c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #33 gpu_set_alphatestfunc → F_GPUSetAlphaTestFunc(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a340 ldr r1, [pc, #0x90c]
 *   @0x14a344 ldr r0, [pc, #0x90c]
 *   @0x14a348 mov r2, #1
 *   @0x14a34c mov r3, r2
 *   @0x14a350 ldr r8, [r4, r1]
 *   @0x14a354 add r0, pc, r0
 *   @0x14a358 mov r1, r8
 *   @0x14a35c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #34 gpu_set_texfilter → F_GPUSetTexFilter(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a360 ldr r1, [pc, #0x8f4]
 *   @0x14a364 ldr r0, [pc, #0x8f4]
 *   @0x14a368 mov r2, #2
 *   @0x14a36c mov r3, #1
 *   @0x14a370 ldr r7, [r4, r1]
 *   @0x14a374 add r0, pc, r0
 *   @0x14a378 mov r1, r7
 *   @0x14a37c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #35 gpu_set_texfilter_ext → F_GPUSetTexFilterExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x14a380 ldr r1, [pc, #0x8dc]
 *   @0x14a384 ldr r0, [pc, #0x8dc]
 *   @0x14a388 mov r2, #1
 *   @0x14a38c mov r3, r2
 *   @0x14a390 ldr r6, [r4, r1]
 *   @0x14a394 add r0, pc, r0
 *   @0x14a398 mov r1, r6
 *   @0x14a39c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #36 gpu_set_texrepeat → F_GPUSetTexRepeat(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a3a0 ldr r1, [pc, #0x8c4]
 *   @0x14a3a4 ldr r0, [pc, #0x8c4]
 *   @0x14a3a8 mov r2, #2
 *   @0x14a3ac mov r3, #1
 *   @0x14a3b0 ldr r5, [r4, r1]
 *   @0x14a3b4 add r0, pc, r0
 *   @0x14a3b8 mov r1, r5
 *   @0x14a3bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #37 gpu_set_texrepeat_ext → F_GPUSetTexRepeatExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x14a3c0 ldr r0, [pc, #0x8ac]
 *   @0x14a3c4 mov r2, #1
 *   @0x14a3c8 mov r1, r8
 *   @0x14a3cc mov r3, r2
 *   @0x14a3d0 add r0, pc, r0
 *   @0x14a3d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #38 gpu_set_tex_filter → F_GPUSetTexFilter(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a3d8 ldr r0, [pc, #0x898]
 *   @0x14a3dc mov r1, r7
 *   @0x14a3e0 mov r2, #2
 *   @0x14a3e4 add r0, pc, r0
 *   @0x14a3e8 mov r3, #1
 *   @0x14a3ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #39 gpu_set_tex_filter_ext → F_GPUSetTexFilterExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x14a3f0 ldr r0, [pc, #0x884]
 *   @0x14a3f4 mov r2, #1
 *   @0x14a3f8 mov r1, r6
 *   @0x14a3fc mov r3, r2
 *   @0x14a400 add r0, pc, r0
 *   @0x14a404 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #40 gpu_set_tex_repeat → F_GPUSetTexRepeat(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a408 ldr r0, [pc, #0x870]
 *   @0x14a40c mov r1, r5
 *   @0x14a410 mov r2, #2
 *   @0x14a414 add r0, pc, r0
 *   @0x14a418 mov r3, #1
 *   @0x14a41c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #41 gpu_set_tex_repeat_ext → F_GPUSetTexRepeatExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x14a420 ldr r1, [pc, #0x85c]
 *   @0x14a424 ldr r0, [pc, #0x85c]
 *   @0x14a428 mov r2, #1
 *   @0x14a42c mov r3, r2
 *   @0x14a430 add r0, pc, r0
 *   @0x14a434 ldr r1, [r4, r1]
 *   @0x14a438 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #42 gpu_set_tex_mip_filter → F_GPUSetTexMipFilter(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a43c ldr r1, [pc, #0x848]
 *   @0x14a440 ldr r0, [pc, #0x848]
 *   @0x14a444 mov r2, #2
 *   @0x14a448 mov r3, #1
 *   @0x14a44c add r0, pc, r0
 *   @0x14a450 ldr r1, [r4, r1]
 *   @0x14a454 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #43 gpu_set_tex_mip_filter_ext → F_GPUSetTexMipFilterExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x14a458 ldr r1, [pc, #0x834]
 *   @0x14a45c ldr r0, [pc, #0x834]
 *   @0x14a460 mov r2, #1
 *   @0x14a464 mov r3, r2
 *   @0x14a468 add r0, pc, r0
 *   @0x14a46c ldr r1, [r4, r1]
 *   @0x14a470 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #44 gpu_set_tex_mip_bias → F_GPUSetTexMipBias(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a474 ldr r1, [pc, #0x820]
 *   @0x14a478 ldr r0, [pc, #0x820]
 *   @0x14a47c mov r2, #2
 *   @0x14a480 mov r3, #1
 *   @0x14a484 add r0, pc, r0
 *   @0x14a488 ldr r1, [r4, r1]
 *   @0x14a48c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #45 gpu_set_tex_mip_bias_ext → F_GPUSetTexMipBiasExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x14a490 ldr r1, [pc, #0x80c]
 *   @0x14a494 ldr r0, [pc, #0x80c]
 *   @0x14a498 mov r2, #1
 *   @0x14a49c mov r3, r2
 *   @0x14a4a0 add r0, pc, r0
 *   @0x14a4a4 ldr r1, [r4, r1]
 *   @0x14a4a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #46 gpu_set_tex_min_mip → F_GPUSetTexMinMip(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a4ac ldr r1, [pc, #0x7f8]
 *   @0x14a4b0 ldr r0, [pc, #0x7f8]
 *   @0x14a4b4 mov r2, #2
 *   @0x14a4b8 mov r3, #1
 *   @0x14a4bc add r0, pc, r0
 *   @0x14a4c0 ldr r1, [r4, r1]
 *   @0x14a4c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #47 gpu_set_tex_min_mip_ext → F_GPUSetTexMinMipExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x14a4c8 ldr r1, [pc, #0x7e4]
 *   @0x14a4cc ldr r0, [pc, #0x7e4]
 *   @0x14a4d0 mov r2, #1
 *   @0x14a4d4 mov r3, r2
 *   @0x14a4d8 add r0, pc, r0
 *   @0x14a4dc ldr r1, [r4, r1]
 *   @0x14a4e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #48 gpu_set_tex_max_mip → F_GPUSetTexMaxMip(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a4e4 ldr r1, [pc, #0x7d0]
 *   @0x14a4e8 ldr r0, [pc, #0x7d0]
 *   @0x14a4ec mov r2, #2
 *   @0x14a4f0 mov r3, #1
 *   @0x14a4f4 add r0, pc, r0
 *   @0x14a4f8 ldr r1, [r4, r1]
 *   @0x14a4fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #49 gpu_set_tex_max_mip_ext → F_GPUSetTexMaxMipExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x14a500 ldr r1, [pc, #0x7bc]
 *   @0x14a504 ldr r0, [pc, #0x7bc]
 *   @0x14a508 mov r2, #1
 *   @0x14a50c mov r3, r2
 *   @0x14a510 add r0, pc, r0
 *   @0x14a514 ldr r1, [r4, r1]
 *   @0x14a518 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #50 gpu_set_tex_max_aniso → F_GPUSetTexMaxAniso(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a51c ldr r1, [pc, #0x7a8]
 *   @0x14a520 ldr r0, [pc, #0x7a8]
 *   @0x14a524 mov r2, #2
 *   @0x14a528 mov r3, #1
 *   @0x14a52c add r0, pc, r0
 *   @0x14a530 ldr r1, [r4, r1]
 *   @0x14a534 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #51 gpu_set_tex_max_aniso_ext → F_GPUSetTexMaxAnisoExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x14a538 ldr r1, [pc, #0x794]
 *   @0x14a53c ldr r0, [pc, #0x794]
 *   @0x14a540 mov r2, #1
 *   @0x14a544 mov r3, r2
 *   @0x14a548 ldr r5, [r4, r1]
 *   @0x14a54c add r0, pc, r0
 *   @0x14a550 mov r1, r5
 *   @0x14a554 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #52 gpu_set_tex_mip_enable → F_GPUSetTexMipEnable(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a558 ldr r0, [pc, #0x77c]
 *   @0x14a55c mov r1, r5
 *   @0x14a560 mov r2, #2
 *   @0x14a564 add r0, pc, r0
 *   @0x14a568 mov r3, #1
 *   @0x14a56c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #53 gpu_set_tex_mip_enable_ext → F_GPUSetTexMipEnable(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x14a570 ldr r1, [pc, #0x768]
 *   @0x14a574 ldr r0, [pc, #0x768]
 *   @0x14a578 mov r2, #0
 *   @0x14a57c mov r3, #1
 *   @0x14a580 add r0, pc, r0
 *   @0x14a584 ldr r1, [r4, r1]
 *   @0x14a588 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #54 gpu_get_blendenable → F_GPUGetBlendEnable(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a58c ldr r1, [pc, #0x754]
 *   @0x14a590 ldr r0, [pc, #0x754]
 *   @0x14a594 mov r2, #0
 *   @0x14a598 mov r3, #1
 *   @0x14a59c add r0, pc, r0
 *   @0x14a5a0 ldr r1, [r4, r1]
 *   @0x14a5a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #55 gpu_get_ztestenable → F_GPUGetZTestEnable(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a5a8 ldr r1, [pc, #0x740]
 *   @0x14a5ac ldr r0, [pc, #0x740]
 *   @0x14a5b0 mov r2, #0
 *   @0x14a5b4 mov r3, #1
 *   @0x14a5b8 add r0, pc, r0
 *   @0x14a5bc ldr r1, [r4, r1]
 *   @0x14a5c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #56 gpu_get_zfunc → F_GPUGetZFunc(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a5c4 ldr r1, [pc, #0x72c]
 *   @0x14a5c8 ldr r0, [pc, #0x72c]
 *   @0x14a5cc mov r2, #0
 *   @0x14a5d0 mov r3, #1
 *   @0x14a5d4 add r0, pc, r0
 *   @0x14a5d8 ldr r1, [r4, r1]
 *   @0x14a5dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #57 gpu_get_zwriteenable → F_GPUGetZWriteEnable(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a5e0 ldr r1, [pc, #0x718]
 *   @0x14a5e4 ldr r0, [pc, #0x718]
 *   @0x14a5e8 mov r2, #0
 *   @0x14a5ec mov r3, #1
 *   @0x14a5f0 add r0, pc, r0
 *   @0x14a5f4 ldr r1, [r4, r1]
 *   @0x14a5f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #58 gpu_get_fog → F_GPUGetFog(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a5fc ldr r1, [pc, #0x704]
 *   @0x14a600 ldr r0, [pc, #0x704]
 *   @0x14a604 mov r2, #0
 *   @0x14a608 mov r3, #1
 *   @0x14a60c add r0, pc, r0
 *   @0x14a610 ldr r1, [r4, r1]
 *   @0x14a614 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #59 gpu_get_cullmode → F_GPUGetCullmode(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a618 ldr r1, [pc, #0x6f0]
 *   @0x14a61c ldr r0, [pc, #0x6f0]
 *   @0x14a620 mov r2, #0
 *   @0x14a624 mov r3, #1
 *   @0x14a628 add r0, pc, r0
 *   @0x14a62c ldr r1, [r4, r1]
 *   @0x14a630 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #60 gpu_get_blendmode → F_GPUGetBlendMode(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a634 ldr r1, [pc, #0x6dc]
 *   @0x14a638 ldr r0, [pc, #0x6dc]
 *   @0x14a63c mov r2, #0
 *   @0x14a640 mov r3, #1
 *   @0x14a644 add r0, pc, r0
 *   @0x14a648 ldr r1, [r4, r1]
 *   @0x14a64c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #61 gpu_get_blendmode_ext → F_GPUGetBlendModeExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a650 ldr r1, [pc, #0x6c8]
 *   @0x14a654 ldr r0, [pc, #0x6c8]
 *   @0x14a658 mov r2, #0
 *   @0x14a65c mov r3, #1
 *   @0x14a660 add r0, pc, r0
 *   @0x14a664 ldr r1, [r4, r1]
 *   @0x14a668 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #62 gpu_get_blendmode_ext_sepalpha → F_GPUGetBlendModeExtSepAlpha(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a66c ldr r1, [pc, #0x6b4]
 *   @0x14a670 ldr r0, [pc, #0x6b4]
 *   @0x14a674 mov r2, #0
 *   @0x14a678 mov r3, #1
 *   @0x14a67c add r0, pc, r0
 *   @0x14a680 ldr r1, [r4, r1]
 *   @0x14a684 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #63 gpu_get_blendmode_src → F_GPUGetBlendModeSrc(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a688 ldr r1, [pc, #0x6a0]
 *   @0x14a68c ldr r0, [pc, #0x6a0]
 *   @0x14a690 mov r2, #0
 *   @0x14a694 mov r3, #1
 *   @0x14a698 add r0, pc, r0
 *   @0x14a69c ldr r1, [r4, r1]
 *   @0x14a6a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #64 gpu_get_blendmode_dest → F_GPUGetBlendModeDest(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a6a4 ldr r1, [pc, #0x68c]
 *   @0x14a6a8 ldr r0, [pc, #0x68c]
 *   @0x14a6ac mov r2, #0
 *   @0x14a6b0 mov r3, #1
 *   @0x14a6b4 add r0, pc, r0
 *   @0x14a6b8 ldr r1, [r4, r1]
 *   @0x14a6bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #65 gpu_get_blendmode_srcalpha → F_GPUGetBlendModeSrcAlpha(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a6c0 ldr r1, [pc, #0x678]
 *   @0x14a6c4 ldr r0, [pc, #0x678]
 *   @0x14a6c8 mov r2, #0
 *   @0x14a6cc mov r3, #1
 *   @0x14a6d0 add r0, pc, r0
 *   @0x14a6d4 ldr r1, [r4, r1]
 *   @0x14a6d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #66 gpu_get_blendmode_destalpha → F_GPUGetBlendModeDestAlpha(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a6dc ldr r1, [pc, #0x664]
 *   @0x14a6e0 ldr r0, [pc, #0x664]
 *   @0x14a6e4 mov r2, #0
 *   @0x14a6e8 mov r3, #1
 *   @0x14a6ec ldr r5, [r4, r1]
 *   @0x14a6f0 add r0, pc, r0
 *   @0x14a6f4 mov r1, r5
 *   @0x14a6f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #67 gpu_get_colorwriteenable → F_GPUGetColourWriteEnable(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a6fc ldr r0, [pc, #0x64c]
 *   @0x14a700 mov r1, r5
 *   @0x14a704 mov r2, #0
 *   @0x14a708 add r0, pc, r0
 *   @0x14a70c mov r3, #1
 *   @0x14a710 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #68 gpu_get_colourwriteenable → F_GPUGetColourWriteEnable(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a714 ldr r1, [pc, #0x638]
 *   @0x14a718 ldr r0, [pc, #0x638]
 *   @0x14a71c mov r2, #0
 *   @0x14a720 mov r3, #1
 *   @0x14a724 add r0, pc, r0
 *   @0x14a728 ldr r1, [r4, r1]
 *   @0x14a72c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #69 gpu_get_alphatestenable → F_GPUGetAlphaTestEnable(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a730 ldr r1, [pc, #0x624]
 *   @0x14a734 ldr r0, [pc, #0x624]
 *   @0x14a738 mov r2, #0
 *   @0x14a73c mov r3, #1
 *   @0x14a740 add r0, pc, r0
 *   @0x14a744 ldr r1, [r4, r1]
 *   @0x14a748 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #70 gpu_get_alphatestref → F_GPUGetAlphaTestRef(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a74c ldr r1, [pc, #0x610]
 *   @0x14a750 ldr r0, [pc, #0x610]
 *   @0x14a754 mov r2, #0
 *   @0x14a758 mov r3, #1
 *   @0x14a75c add r0, pc, r0
 *   @0x14a760 ldr r1, [r4, r1]
 *   @0x14a764 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #71 gpu_get_alphatestfunc → F_GPUGetAlphaTestFunc(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a768 ldr r1, [pc, #0x5fc]
 *   @0x14a76c ldr r0, [pc, #0x5fc]
 *   @0x14a770 mov r2, #0
 *   @0x14a774 mov r3, #1
 *   @0x14a778 ldr r8, [r4, r1]
 *   @0x14a77c add r0, pc, r0
 *   @0x14a780 mov r1, r8
 *   @0x14a784 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #72 gpu_get_texfilter → F_GPUGetTexFilter(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a788 ldr r1, [pc, #0x5e4]
 *   @0x14a78c ldr r0, [pc, #0x5e4]
 *   @0x14a790 mov r2, #1
 *   @0x14a794 mov r3, r2
 *   @0x14a798 ldr r7, [r4, r1]
 *   @0x14a79c add r0, pc, r0
 *   @0x14a7a0 mov r1, r7
 *   @0x14a7a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #73 gpu_get_texfilter_ext → F_GPUGetTexFilterExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a7a8 ldr r1, [pc, #0x5cc]
 *   @0x14a7ac ldr r0, [pc, #0x5cc]
 *   @0x14a7b0 mov r2, #0
 *   @0x14a7b4 mov r3, #1
 *   @0x14a7b8 ldr r6, [r4, r1]
 *   @0x14a7bc add r0, pc, r0
 *   @0x14a7c0 mov r1, r6
 *   @0x14a7c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #74 gpu_get_texrepeat → F_GPUGetTexRepeat(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a7c8 ldr r1, [pc, #0x5b4]
 *   @0x14a7cc ldr r0, [pc, #0x5b4]
 *   @0x14a7d0 mov r2, #1
 *   @0x14a7d4 mov r3, r2
 *   @0x14a7d8 ldr r5, [r4, r1]
 *   @0x14a7dc add r0, pc, r0
 *   @0x14a7e0 mov r1, r5
 *   @0x14a7e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #75 gpu_get_texrepeat_ext → F_GPUGetTexRepeatExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a7e8 ldr r0, [pc, #0x59c]
 *   @0x14a7ec mov r1, r8
 *   @0x14a7f0 mov r2, #0
 *   @0x14a7f4 add r0, pc, r0
 *   @0x14a7f8 mov r3, #1
 *   @0x14a7fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #76 gpu_get_tex_filter → F_GPUGetTexFilter(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a800 ldr r0, [pc, #0x588]
 *   @0x14a804 mov r2, #1
 *   @0x14a808 mov r1, r7
 *   @0x14a80c mov r3, r2
 *   @0x14a810 add r0, pc, r0
 *   @0x14a814 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #77 gpu_get_tex_filter_ext → F_GPUGetTexFilterExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a818 ldr r0, [pc, #0x574]
 *   @0x14a81c mov r1, r6
 *   @0x14a820 mov r2, #0
 *   @0x14a824 add r0, pc, r0
 *   @0x14a828 mov r3, #1
 *   @0x14a82c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #78 gpu_get_tex_repeat → F_GPUGetTexRepeat(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a830 ldr r0, [pc, #0x560]
 *   @0x14a834 mov r2, #1
 *   @0x14a838 mov r1, r5
 *   @0x14a83c mov r3, r2
 *   @0x14a840 add r0, pc, r0
 *   @0x14a844 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #79 gpu_get_tex_repeat_ext → F_GPUGetTexRepeatExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a848 ldr r1, [pc, #0x54c]
 *   @0x14a84c ldr r0, [pc, #0x54c]
 *   @0x14a850 mov r2, #0
 *   @0x14a854 mov r3, #1
 *   @0x14a858 add r0, pc, r0
 *   @0x14a85c ldr r1, [r4, r1]
 *   @0x14a860 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #80 gpu_get_tex_mip_filter → F_GPUGetTexMipFilter(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a864 ldr r1, [pc, #0x538]
 *   @0x14a868 ldr r0, [pc, #0x538]
 *   @0x14a86c mov r2, #1
 *   @0x14a870 mov r3, r2
 *   @0x14a874 add r0, pc, r0
 *   @0x14a878 ldr r1, [r4, r1]
 *   @0x14a87c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #81 gpu_get_tex_mip_filter_ext → F_GPUGetTexMipFilterExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a880 ldr r1, [pc, #0x524]
 *   @0x14a884 ldr r0, [pc, #0x524]
 *   @0x14a888 mov r2, #0
 *   @0x14a88c mov r3, #1
 *   @0x14a890 add r0, pc, r0
 *   @0x14a894 ldr r1, [r4, r1]
 *   @0x14a898 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #82 gpu_get_tex_mip_bias → F_GPUGetTexMipBias(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a89c ldr r1, [pc, #0x510]
 *   @0x14a8a0 ldr r0, [pc, #0x510]
 *   @0x14a8a4 mov r2, #1
 *   @0x14a8a8 mov r3, r2
 *   @0x14a8ac add r0, pc, r0
 *   @0x14a8b0 ldr r1, [r4, r1]
 *   @0x14a8b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #83 gpu_get_tex_mip_bias_ext → F_GPUGetTexMipBiasExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a8b8 ldr r1, [pc, #0x4fc]
 *   @0x14a8bc ldr r0, [pc, #0x4fc]
 *   @0x14a8c0 mov r2, #0
 *   @0x14a8c4 mov r3, #1
 *   @0x14a8c8 add r0, pc, r0
 *   @0x14a8cc ldr r1, [r4, r1]
 *   @0x14a8d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #84 gpu_get_tex_min_mip → F_GPUGetTexMinMip(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a8d4 ldr r1, [pc, #0x4e8]
 *   @0x14a8d8 ldr r0, [pc, #0x4e8]
 *   @0x14a8dc mov r2, #1
 *   @0x14a8e0 mov r3, r2
 *   @0x14a8e4 add r0, pc, r0
 *   @0x14a8e8 ldr r1, [r4, r1]
 *   @0x14a8ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #85 gpu_get_tex_min_mip_ext → F_GPUGetTexMinMipExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a8f0 ldr r1, [pc, #0x4d4]
 *   @0x14a8f4 ldr r0, [pc, #0x4d4]
 *   @0x14a8f8 mov r2, #0
 *   @0x14a8fc mov r3, #1
 *   @0x14a900 add r0, pc, r0
 *   @0x14a904 ldr r1, [r4, r1]
 *   @0x14a908 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #86 gpu_get_tex_max_mip → F_GPUGetTexMaxMip(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a90c ldr r1, [pc, #0x4c0]
 *   @0x14a910 ldr r0, [pc, #0x4c0]
 *   @0x14a914 mov r2, #1
 *   @0x14a918 mov r3, r2
 *   @0x14a91c add r0, pc, r0
 *   @0x14a920 ldr r1, [r4, r1]
 *   @0x14a924 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #87 gpu_get_tex_max_mip_ext → F_GPUGetTexMaxMipExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a928 ldr r1, [pc, #0x4ac]
 *   @0x14a92c ldr r0, [pc, #0x4ac]
 *   @0x14a930 mov r2, #1
 *   @0x14a934 mov r3, r2
 *   @0x14a938 add r0, pc, r0
 *   @0x14a93c ldr r1, [r4, r1]
 *   @0x14a940 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #88 gpu_get_tex_max_aniso → F_GPUGetTexMaxAniso(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a944 ldr r1, [pc, #0x498]
 *   @0x14a948 ldr r0, [pc, #0x498]
 *   @0x14a94c mov r2, #2
 *   @0x14a950 mov r3, #1
 *   @0x14a954 add r0, pc, r0
 *   @0x14a958 ldr r1, [r4, r1]
 *   @0x14a95c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #89 gpu_get_tex_max_aniso_ext → F_GPUGetTexMaxAnisoExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x14a960 ldr r1, [pc, #0x484]
 *   @0x14a964 ldr r0, [pc, #0x484]
 *   @0x14a968 mov r2, #0
 *   @0x14a96c mov r3, #1
 *   @0x14a970 add r0, pc, r0
 *   @0x14a974 ldr r1, [r4, r1]
 *   @0x14a978 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #90 gpu_get_tex_mip_enable → F_GPUGetTexMipEnable(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a97c ldr r1, [pc, #0x470]
 *   @0x14a980 ldr r0, [pc, #0x470]
 *   @0x14a984 mov r2, #1
 *   @0x14a988 mov r3, r2
 *   @0x14a98c add r0, pc, r0
 *   @0x14a990 ldr r1, [r4, r1]
 *   @0x14a994 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #91 gpu_get_tex_mip_enable_ext → F_GPUGetTexMipEnableExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14a998 ldr r1, [pc, #0x45c]
 *   @0x14a99c ldr r0, [pc, #0x45c]
 *   @0x14a9a0 mov r2, #0
 *   @0x14a9a4 mov r3, #1
 *   @0x14a9a8 add r0, pc, r0
 *   @0x14a9ac ldr r1, [r4, r1]
 *   @0x14a9b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #92 gpu_push_state → F_GPUPushState(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a9b4 ldr r1, [pc, #0x448]
 *   @0x14a9b8 ldr r0, [pc, #0x448]
 *   @0x14a9bc mov r2, #0
 *   @0x14a9c0 mov r3, #1
 *   @0x14a9c4 add r0, pc, r0
 *   @0x14a9c8 ldr r1, [r4, r1]
 *   @0x14a9cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #93 gpu_pop_state → F_GPUPopState(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a9d0 ldr r1, [pc, #0x434]
 *   @0x14a9d4 ldr r0, [pc, #0x434]
 *   @0x14a9d8 mov r2, #0
 *   @0x14a9dc mov r3, #1
 *   @0x14a9e0 add r0, pc, r0
 *   @0x14a9e4 ldr r1, [r4, r1]
 *   @0x14a9e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #94 gpu_get_state → F_GPUGetState(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14a9ec ldr r1, [pc, #0x420]
 *   @0x14a9f0 ldr r0, [pc, #0x420]
 *   @0x14a9f4 mov r2, #1
 *   @0x14a9f8 mov r3, r2
 *   @0x14a9fc add r0, pc, r0
 *   @0x14aa00 ldr r1, [r4, r1]
 *   @0x14aa04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #95 gpu_set_state → F_GPUSetState(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14aa08 ldr r1, [pc, #0x6ac]
 *   @0x14aa0c ldr r0, [pc, #0x408]
 *   @0x14aa10 mov r2, #1
 *   @0x14aa14 mov r3, r2
 *   @0x14aa18 add r0, pc, r0
 *   @0x14aa1c ldr r1, [r4, r1]
 *   @0x14aa20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #96 draw_light_define_ambient → F_D3DLightSetAmbient(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14aa24 ldr r1, [pc, #0x698]
 *   @0x14aa28 ldr r0, [pc, #0x3f0]
 *   @0x14aa2c mov r2, #5
 *   @0x14aa30 mov r3, #1
 *   @0x14aa34 add r0, pc, r0
 *   @0x14aa38 ldr r1, [r4, r1]
 *   @0x14aa3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #97 draw_light_define_direction → F_D3DLightDefineDirection(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x14aa40 ldr r1, [pc, #0x684]
 *   @0x14aa44 ldr r0, [pc, #0x3d8]
 *   @0x14aa48 mov r2, #6
 *   @0x14aa4c mov r3, #1
 *   @0x14aa50 add r0, pc, r0
 *   @0x14aa54 ldr r1, [r4, r1]
 *   @0x14aa58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #98 draw_light_define_point → F_D3DLightDefinePoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x14aa5c ldr r1, [pc, #0x670]
 *   @0x14aa60 ldr r0, [pc, #0x3c0]
 *   @0x14aa64 mov r2, #2
 *   @0x14aa68 mov r3, #1
 *   @0x14aa6c add r0, pc, r0
 *   @0x14aa70 ldr r1, [r4, r1]
 *   @0x14aa74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #99 draw_light_enable → F_D3DLightEnable(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x14aa78 ldr r1, [pc, #0x65c]
 *   @0x14aa7c ldr r0, [pc, #0x3a8]
 *   @0x14aa80 mov r2, #1
 *   @0x14aa84 mov r3, r2
 *   @0x14aa88 add r0, pc, r0
 *   @0x14aa8c ldr r1, [r4, r1]
 *   @0x14aa90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #100 draw_set_lighting → F_D3DSetLighting(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14aa94 ldr r1, [pc, #0x394]
 *   @0x14aa98 ldr r0, [pc, #0x394]
 *   @0x14aa9c mov r2, #0
 *   @0x14aaa0 mov r3, #1
 *   @0x14aaa4 add r0, pc, r0
 *   @0x14aaa8 ldr r1, [r4, r1]
 *   @0x14aaac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #101 draw_light_get_ambient → F_D3DLightGetAmbient(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14aab0 ldr r1, [pc, #0x380]
 *   @0x14aab4 ldr r0, [pc, #0x380]
 *   @0x14aab8 mov r2, #1
 *   @0x14aabc mov r3, r2
 *   @0x14aac0 add r0, pc, r0
 *   @0x14aac4 ldr r1, [r4, r1]
 *   @0x14aac8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #102 draw_light_get → F_D3DLightGet(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14aacc ldr r1, [pc, #0x36c]
 *   @0x14aad0 ldr r0, [pc, #0x36c]
 *   @0x14aad4 mov r2, #0
 *   @0x14aad8 mov r3, #1
 *   @0x14aadc ldr r1, [r4, r1]
 *   @0x14aae0 add r0, pc, r0
 *   @0x14aae4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #103 draw_get_lighting → F_D3DGetLighting(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x14aae8 ldr r3, [pc, #0x358]
 *   @0x14aaec mov r2, #0
 *   @0x14aaf0 mov r1, #1065353216
 *   @0x14aaf4 ldr r3, [r4, r3]
 *   @0x14aaf8 str r2, [r3, #0x38]
 *   @0x14aafc str r2, [r3, #0x34]
 *   @0x14ab00 str r2, [r3, #0x30]
 *   @0x14ab04 str r2, [r3, #0x2c]
 *   @0x14ab08 str r2, [r3, #0x24]
 *   @0x14ab0c str r2, [r3, #0x20]
 *   @0x14ab10 str r2, [r3, #0x1c]
 *   @0x14ab14 str r2, [r3, #0x18]
 *   @0x14ab18 str r2, [r3, #0x10]
 *   @0x14ab1c str r2, [r3, #0xc]
 *   @0x14ab20 str r2, [r3, #0x8]
 *   @0x14ab24 str r1, [r3, #0x3c]
 *   @0x14ab28 str r1, [r3, #0x28]
 *   @0x14ab2c str r1, [r3, #0x14]
 *   @0x14ab30 str r1, [r3]
 *   @0x14ab34 str r2, [r3, #0x4]
 *   @0x14ab38 pop {r4, r5, r6, r7, r8, pc}
 *   @0x14ab3c .word 0x002a7cf8
 *   @0x14ab40 .word 0xffffbcd4
 *   @0x14ab44 .word 0xffffd9e8
 *   @0x14ab48 andseq r9, pc, r0, lsr #7
 *   @0x14ab4c .word 0xffffd9ec
 *   @0x14ab50 mulseq pc, r0, r3
 *   @0x14ab54 .word 0xffffd9f0
 *   @0x14ab58 andseq r9, pc, r0, lsl #7
 *   @0x14ab5c .word 0xffffd9f4
 *   @0x14ab60 andseq r9, pc, r12, ror r3
 *   @0x14ab64 .word 0xffffd9f8
 *   @0x14ab68 andseq r9, pc, r0, ror r3
 *   @0x14ab6c .word 0xffffd9fc
 *   @0x14ab70 andseq r9, pc, r8, ror #6
 *   @0x14ab74 .word 0xffffda00
 *   @0x14ab78 andseq r9, pc, r12, ror #6
 *   @0x14ab7c .word 0xffffda04
 *   @0x14ab80 andseq r9, pc, r4, ror r3
 *   @0x14ab84 .word 0xffffda08
 *   @0x14ab88 andseq r9, pc, r0, lsl #7
 *   @0x14ab8c .word 0xffffda0c
 *   @0x14ab90 andseq r9, pc, r4, ror r3
 *   @0x14ab94 .word 0xffffda10
 *   @0x14ab98 andseq r9, pc, r0, ror r3
 *   @0x14ab9c .word 0xffffda14
 *   @0x14aba0 andseq r9, pc, r4, ror #6
 *   @0x14aba4 .word 0xffffda18
 *   @0x14aba8 andseq r9, pc, r12, asr r3
 *   @0x14abac .word 0xffffda1c
 *   @0x14abb0 andseq r9, pc, r4, asr r3
 *   @0x14abb4 .word 0xffffc0ac
 *   @0x14abb8 .word 0xffffda20
 *   @0x14abbc andseq r9, pc, r12, lsr #6
 *   @0x14abc0 .word 0xffffda24
 *   @0x14abc4 andseq r9, pc, r0, lsr #6
 *   @0x14abc8 .word 0xffffda28
 *   @0x14abcc andseq r9, pc, r8, lsl r3
 *   @0x14abd0 .word 0xffffda2c
 *   @0x14abd4 andseq r9, pc, r0, lsl r3
 *   @0x14abd8 .word 0xffffda30
 *   @0x14abdc andseq r9, pc, r8, lsl #6
 *   @0x14abe0 .word 0xffffda34
 *   @0x14abe4 andseq r9, pc, r0, lsl #6
 *   @0x14abe8 .word 0xffffda38
 *   @0x14abec ldrsheq r9, [pc], -r12
 *   @0x14abf0 .word 0xffffda3c
 *   @0x14abf4 ldrsheq r9, [pc], -r4
 *   @0x14abf8 .word 0xffffda40
 *   @0x14abfc andseq r9, pc, r12, ror #5
 *   @0x14ac00 .word 0xffffda44
 *   @0x14ac04 andseq r9, pc, r0, ror #5
 *   @0x14ac08 .word 0xffffda48
 *   @0x14ac0c ldrsbeq r9, [pc], -r12
 *   @0x14ac10 .word 0xffffda4c
 *   @0x14ac14 andseq r9, pc, r12, asr #5
 *   @0x14ac18 .word 0xffffda50
 *   @0x14ac1c andseq r9, pc, r4, asr #5
 *   @0x14ac20 .word 0xffffda54
 *   @0x14ac24 ldrheq r9, [pc], -r12
 *   @0x14ac28 .word 0xffffda58
 *   @0x14ac2c ldrheq r9, [pc], -r8
 *   @0x14ac30 .word 0xffffda5c
 *   @0x14ac34 ldrheq r9, [pc], -r8
 *   @0x14ac38 ldrheq r9, [pc], -r12
 *   @0x14ac3c .word 0xffffda60
 *   @0x14ac40 ldrheq r9, [pc], -r12
 *   @0x14ac44 .word 0xffffda64
 *   @0x14ac48 ldrheq r9, [pc], -r8
 *   @0x14ac4c .word 0xffffda68
 *   @0x14ac50 ldrheq r9, [pc], -r4
 *   @0x14ac54 .word 0xffffda6c
 *   @0x14ac58 andseq r9, pc, r12, lsr #5
 *   @0x14ac5c .word 0xffffda70
 *   @0x14ac60 andseq r9, pc, r0, lsr #5
 *   @0x14ac64 .word 0xffffda74
 *   @0x14ac68 mulseq pc, r8, r2
 *   @0x14ac6c .word 0xffffda78
 *   @0x14ac70 andseq r9, pc, r12, lsl #5
 *   @0x14ac74 andseq r9, pc, r8, lsl #5
 *   @0x14ac78 andseq r9, pc, r8, lsl #5
 *   @0x14ac7c andseq r9, pc, r4, lsl #5
 *   @0x14ac80 andseq r9, pc, r4, lsl #5
 *   @0x14ac84 .word 0xffffda7c
 *   @0x14ac88 andseq r9, pc, r0, lsl #5
 *   @0x14ac8c .word 0xffffda80
 *   @0x14ac90 andseq r9, pc, r12, ror r2
 *   @0x14ac94 .word 0xffffda84
 *   @0x14ac98 andseq r9, pc, r12, ror r2
 *   @0x14ac9c .word 0xffffda88
 *   @0x14aca0 andseq r9, pc, r8, ror r2
 *   @0x14aca4 .word 0xffffda8c
 *   @0x14aca8 andseq r9, pc, r8, ror r2
 *   @0x14acac .word 0xffffda90
 *   @0x14acb0 andseq r9, pc, r0, ror r2
 *   @0x14acb4 .word 0xffffda94
 *   @0x14acb8 andseq r9, pc, r12, ror #4
 *   @0x14acbc .word 0xffffda98
 *   @0x14acc0 andseq r9, pc, r4, ror #4
 *   @0x14acc4 .word 0xffffda9c
 *   @0x14acc8 andseq r9, pc, r0, ror #4
 *   @0x14accc .word 0xffffdaa0
 *   @0x14acd0 andseq r9, pc, r12, asr r2
 *   @0x14acd4 .word 0xffffdaa4
 *   @0x14acd8 andseq r9, pc, r8, asr r2
 *   @0x14acdc andseq r9, pc, r8, asr r2
 *   @0x14ace0 .word 0xffffdaa8
 *   @0x14ace4 andseq r9, pc, r8, asr r2
 *   @0x14ace8 .word 0xffffdaac
 *   @0x14acec andseq r9, pc, r0, asr r2
 *   @0x14acf0 .word 0xffffdab0
 *   @0x14acf4 andseq r9, pc, r8, asr #4
 *   @0x14acf8 .word 0xffffdab4
 *   @0x14acfc andseq r9, pc, r12, lsr r2
 *   @0x14ad00 .word 0xffffdab8
 *   @0x14ad04 andseq r9, pc, r8, lsr r2
 *   @0x14ad08 .word 0xffffdabc
 *   @0x14ad0c andseq r9, pc, r8, lsr #4
 *   @0x14ad10 .word 0xffffdac0
 *   @0x14ad14 andseq r9, pc, r0, lsr #4
 *   @0x14ad18 .word 0xffffdac4
 *   @0x14ad1c andseq r9, pc, r8, lsl r2
 *   @0x14ad20 .word 0xffffdac8
 *   @0x14ad24 andseq r9, pc, r4, lsl r2
 *   @0x14ad28 .word 0xffffdacc
 *   @0x14ad2c andseq r9, pc, r8, lsl r2
 *   @0x14ad30 .word 0xffffdad0
 *   @0x14ad34 andseq r9, pc, r4, lsl r2
 *   @0x14ad38 .word 0xffffdad4
 *   @0x14ad3c andseq r9, pc, r0, lsl r2
 *   @0x14ad40 .word 0xffffdad8
 *   @0x14ad44 andseq r9, pc, r0, lsl r2
 *   @0x14ad48 .word 0xffffdadc
 *   @0x14ad4c andseq r9, pc, r12, lsl #4
 *   @0x14ad50 andseq r9, pc, r0, lsl r2
 *   @0x14ad54 .word 0xffffdae0
 *   @0x14ad58 andseq r9, pc, r0, lsl r2
 *   @0x14ad5c .word 0xffffdae4
 *   @0x14ad60 andseq r9, pc, r12, lsl #4
 *   @0x14ad64 .word 0xffffdae8
 *   @0x14ad68 andseq r9, pc, r8, lsl #4
 *   @0x14ad6c .word 0xffffdaec
 *   @0x14ad70 andseq r9, pc, r0, lsl #4
 *   @0x14ad74 .word 0xffffdaf0
 *   @0x14ad78 ldrsheq r9, [pc], -r4
 *   @0x14ad7c .word 0xffffdaf4
 *   @0x14ad80 andseq r9, pc, r12, ror #3
 *   @0x14ad84 .word 0xffffdaf8
 *   @0x14ad88 andseq r9, pc, r0, ror #3
 *   @0x14ad8c andseq r9, pc, r0, ror #3
 *   @0x14ad90 ldrsbeq r9, [pc], -r8
 *   @0x14ad94 ldrsbeq r9, [pc], -r12
 *   @0x14ad98 ldrsbeq r9, [pc], -r4
 *   @0x14ad9c .word 0xffffdafc
 *   @0x14ada0 ldrsbeq r9, [pc], -r4
 *   @0x14ada4 .word 0xffffdb00
 *   @0x14ada8 ldrsbeq r9, [pc], -r0
 *   @0x14adac .word 0xffffdb04
 *   @0x14adb0 ldrsbeq r9, [pc], -r0
 *   @0x14adb4 .word 0xffffdb08
 *   @0x14adb8 andseq r9, pc, r12, asr #3
 *   @0x14adbc .word 0xffffdb0c
 *   @0x14adc0 andseq r9, pc, r12, asr #3
 *   @0x14adc4 .word 0xffffdb10
 *   @0x14adc8 andseq r9, pc, r4, asr #3
 *   @0x14adcc .word 0xffffdb14
 *   @0x14add0 andseq r9, pc, r0, asr #3
 *   @0x14add4 .word 0xffffdb18
 *   @0x14add8 ldrheq r9, [pc], -r8
 *   @0x14addc .word 0xffffdb1c
 *   @0x14ade0 ldrheq r9, [pc], -r4
 *   @0x14ade4 .word 0xffffdb20
 *   @0x14ade8 ldrheq r9, [pc], -r0
 *   @0x14adec .word 0xffffdb24
 *   @0x14adf0 ldrheq r9, [pc], -r0
 *   @0x14adf4 .word 0xffffdb28
 *   @0x14adf8 andseq r9, pc, r12, lsr #3
 *   @0x14adfc .word 0xffffdb2c
 *   @0x14ae00 andseq r9, pc, r12, lsr #3
 *   @0x14ae04 .word 0xffffdb30
 *   @0x14ae08 andseq r9, pc, r0, lsr #3
 *   @0x14ae0c .word 0xffffdb34
 *   @0x14ae10 mulseq pc, r4, r1
 *   @0x14ae14 .word 0xffffdb38
 *   @0x14ae18 andseq r9, pc, r8, lsl #3
 *   @0x14ae1c andseq r9, pc, r12, ror r1
 *   @0x14ae20 andseq r9, pc, r12, ror r1
 *   @0x14ae24 andseq r9, pc, r12, ror r1
 *   @0x14ae28 andseq r9, pc, r8, ror r1
 *   @0x14ae2c andseq r9, pc, r0, ror r1
 *   @0x14ae30 .word 0xffffdb3c
 *   @0x14ae34 andseq r9, pc, r8, ror #2
 *   @0x14ae38 .word 0xffffdb40
 *   @0x14ae3c andseq r9, pc, r4, ror #2
 *   @0x14ae40 .word 0xffffdb44
 *   @0x14ae44 andseq r9, pc, r4, asr r1
 *   @0x14ae48 .word 0xffffd9b8
 *   @0x14ae4c .word 0xffffdb48
 *   @0x14ae50 andseq r7, pc, r0, asr #19
 *   @0x14ae54 .word 0xffffdb4c
 *   @0x14ae58 ldrheq r7, [pc], -r0
 *   @0x14ae5c .word 0xffffdb50
 *   @0x14ae60 mulseq pc, r12, r9
 *   @0x14ae64 .word 0xffffdb54
 *   @0x14ae68 mulseq pc, r4, r9
 *   @0x14ae6c .word 0xffffdb58
 *   @0x14ae70 andseq r7, pc, r8, lsl #19
 *   @0x14ae74 .word 0xffffdb5c
 *   @0x14ae78 andseq r7, pc, r12, ror r9
 *   @0x14ae7c .word 0xffffdb60
 *   @0x14ae80 andseq r7, pc, r0, ror r9
 *   @0x14ae84 .word 0xffffdb64
 *   @0x14ae88 andseq r7, pc, r0, ror #18
 *   @0x14ae8c .word 0xffffdb68
 *   @0x14ae90 andseq r7, pc, r4, asr r9
 *   @0x14ae94 .word 0xffffdb6c
 *   @0x14ae98 andseq r7, pc, r0, asr r9
 *   @0x14ae9c .word 0xffffdb70
 *   @0x14aea0 andseq r7, pc, r8, asr #18
 *   @0x14aea4 .word 0xffffdb74
 *   @0x14aea8 andseq r7, pc, r8, asr #18
 *   @0x14aeac .word 0xffffdb78
 *   @0x14aeb0 andseq r7, pc, r0, asr #18
 *   @0x14aeb4 .word 0xffffdb7c
 *   @0x14aeb8 andseq r7, pc, r0, lsr r9
 *   @0x14aebc andseq r7, pc, r12, lsr #18
 *   @0x14aec0 .word 0xffffdb80
 *   @0x14aec4 andseq r7, pc, r0, lsr #18
 *   @0x14aec8 .word 0xffffdb84
 *   @0x14aecc andseq r7, pc, r8, lsl r9
 *   @0x14aed0 andseq r7, pc, r12, lsl r9
 *   @0x14aed4 .word 0xffffdb88
 *   @0x14aed8 andseq r7, pc, r8, lsl r9
 *   @0x14aedc .word 0xffffdb8c
 *   @0x14aee0 andseq r7, pc, r0, lsl r9
 *   @0x14aee4 andseq r7, pc, r0, lsl r9
 *   @0x14aee8 .word 0xffffdb90
 *   @0x14aeec andseq r7, pc, r12, lsl #18
 *   @0x14aef0 .word 0xffffdb94
 *   @0x14aef4 andseq r7, pc, r12, lsl #18
 *   @0x14aef8 andseq r7, pc, r4, lsl r9
 *   @0x14aefc .word 0xffffdb98
 *   @0x14af00 andseq r7, pc, r8, lsl r9
 *   @0x14af04 .word 0xffffdb9c
 *   @0x14af08 andseq r7, pc, r12, lsl #18
 *   @0x14af0c .word 0xffffdba0
 *   @0x14af10 andseq r7, pc, r4, lsl #18
 *   @0x14af14 .word 0xffffdba4
 *   @0x14af18 ldrsheq r7, [pc], -r8
 *   @0x14af1c .word 0xffffdba8
 *   @0x14af20 ldrsheq r7, [pc], -r0
 *   @0x14af24 .word 0xffffdbac
 *   @0x14af28 andseq r7, pc, r4, ror #17
 *   @0x14af2c .word 0xffffdbb0
 *   @0x14af30 ldrsbeq r7, [pc], -r8
 *   @0x14af34 .word 0xffffdbb4
 *   @0x14af38 ldrsbeq r7, [pc], -r0
 *   @0x14af3c .word 0xffffdbb8
 *   @0x14af40 andseq r7, pc, r12, asr #17
 *   @0x14af44 .word 0xffffdbbc
 *   @0x14af48 andseq r7, pc, r12, asr #17
 *   @0x14af4c .word 0xffffdbc0
 *   @0x14af50 ldrsbeq r7, [pc], -r0
 *   @0x14af54 .word 0xffffdbc4
 *   @0x14af58 ldrsbeq r7, [pc], -r0
 *   @0x14af5c .word 0xffffdbc8
 *   @0x14af60 ldrsbeq r7, [pc], -r4
 *   @0x14af64 .word 0xffffdbcc
 *   @0x14af68 ldrsbeq r7, [pc], -r4
 *   @0x14af6c .word 0xffffdbd0
 *   @0x14af70 ldrsbeq r7, [pc], -r8
 *   @0x14af74 .word 0xffffdbd4
 *   @0x14af78 ldrsbeq r7, [pc], -r12
 *   @0x14af7c .word 0xffffdbd8
 *   @0x14af80 andseq r7, pc, r0, ror #17
 *   @0x14af84 .word 0xffffdbdc
 *   @0x14af88 andseq r7, pc, r4, ror #17
 *   @0x14af8c .word 0xffffdbe0
 *   @0x14af90 andseq r7, pc, r8, ror #17
 *   @0x14af94 .word 0xffffdbe4
 *   @0x14af98 andseq r7, pc, r8, ror #17
 *   @0x14af9c .word 0xffffdbe8
 *   @0x14afa0 andseq r7, pc, r12, ror #17
 *   @0x14afa4 .word 0xffffdbec
 *   @0x14afa8 ldrsheq r7, [pc], -r0
 *   @0x14afac .word 0xffffdbf0
 *   @0x14afb0 ldrsheq r7, [pc], -r4
 *   @0x14afb4 .word 0xffffdbf4
 *   @0x14afb8 ldrsheq r7, [pc], -r8
 *   @0x14afbc .word 0xffffdbf8
 *   @0x14afc0 ldrsheq r7, [pc], -r8
 *   @0x14afc4 .word 0xffffdbfc
 *   @0x14afc8 ldrsheq r7, [pc], -r8
 *   @0x14afcc .word 0xffffdc00
 *   @0x14afd0 ldrsheq r7, [pc], -r8
 *   @0x14afd4 .word 0xffffdc04
 *   @0x14afd8 ldrsheq r7, [pc], -r4
 *   @0x14afdc .word 0xffffdc08
 *   @0x14afe0 ldrsheq r7, [pc], -r0
 *   @0x14afe4 .word 0xffffdc0c
 *   @0x14afe8 ldrsheq r7, [pc], -r0
 *   @0x14afec .word 0xffffdc10
 *   @0x14aff0 andseq r7, pc, r12, ror #17
 *   @0x14aff4 .word 0xffffdc14
 *   @0x14aff8 andseq r7, pc, r4, ror #17
 *   @0x14affc .word 0xffffdc18
 *   @0x14b000 ldrsbeq r7, [pc], -r12
 *   @0x14b004 .word 0xffffdc1c
 *   @0x14b008 ldrsbeq r7, [pc], -r0
 *   @0x14b00c .word 0xffffdc20
 *   @0x14b010 andseq r7, pc, r4, asr #17
 *   @0x14b014 .word 0xffffdc24
 *   @0x14b018 ldrheq r7, [pc], -r8
 *   @0x14b01c .word 0xffffdc28
 *   @0x14b020 ldrheq r7, [pc], -r4
 *   @0x14b024 .word 0xffffdc2c
 *   @0x14b028 ldrheq r7, [pc], -r0
 *   @0x14b02c .word 0xffffdc30
 *   @0x14b030 andseq r7, pc, r4, lsr #17
 *   @0x14b034 .word 0xffffdc34
 *   @0x14b038 andseq r7, pc, r4, lsr #17
 *   @0x14b03c .word 0xffffdc38
 *   @0x14b040 andseq r7, pc, r0, lsr #17
 *   @0x14b044 .word 0xffffdc3c
 *   @0x14b048 mulseq pc, r8, r8
 *   @0x14b04c mulseq pc, r8, r8
 *   @0x14b050 .word 0xffffdc40
 *   @0x14b054 mulseq pc, r0, r8
 *   @0x14b058 .word 0xffffdc44
 *   @0x14b05c mulseq pc, r0, r8
 *   @0x14b060 mulseq pc, r8, r8
 *   @0x14b064 .word 0xffffdc48
 *   @0x14b068 mulseq pc, r8, r8
 *   @0x14b06c .word 0xffffdc4c
 *   @0x14b070 mulseq pc, r4, r8
 *   @0x14b074 mulseq pc, r12, r8
 *   @0x14b078 .word 0xffffdc50
 *   @0x14b07c mulseq pc, r12, r8
 *   @0x14b080 .word 0xffffdc54
 *   @0x14b084 andseq r7, pc, r0, lsr #17
 *   @0x14b088 ldrheq r7, [pc], -r0
 *   @0x14b08c .word 0xffffdc58
 *   @0x14b090 ldrheq r7, [pc], -r8
 *   @0x14b094 .word 0xffffdc5c
 *   @0x14b098 andseq r7, pc, r12, lsr #17
 *   @0x14b09c .word 0xffffdc60
 *   @0x14b0a0 andseq r7, pc, r4, lsr #17
 *   @0x14b0a4 .word 0xffffdc64
 *   @0x14b0a8 mulseq pc, r8, r8
 *   @0x14b0ac .word 0xffffdc68
 *   @0x14b0b0 mulseq pc, r0, r8
 *   @0x14b0b4 .word 0xffffdc6c
 *   @0x14b0b8 andseq r7, pc, r4, lsl #17
 *   @0x14b0bc .word 0xffffdc70
 *   @0x14b0c0 andseq r7, pc, r8, ror r8
 *   @0x14b0c4 .word 0xffffdc74
 *   @0x14b0c8 andseq r7, pc, r8, ror r8
 *   @0x14b0cc .word 0xffffdc78
 *   @0x14b0d0 andseq r7, pc, r8, ror r8
 *   @0x14b0d4 .word 0xffffdc7c
 *   @0x14b0d8 andseq r7, pc, r4, ror r8
 *   @0x14b0dc .word 0xffffdc80
 *   @0x14b0e0 andseq r7, pc, r12, ror #16
 *   @0x14b0e4 .word 0xffffdc84
 *   @0x14b0e8 andseq r7, pc, r4, ror #16
 *   @0x14b0ec andseq r7, pc, r4, ror #16
 *   @0x14b0f0 ldr r1, [pc, #-0x2ac]
 *   @0x14b0f4 mov r2, r5
 *   @0x14b0f8 ldr r0, [pc, #-0x2b0]
 *   @0x14b0fc mov r3, #1
 *   @0x14b100 ldr r1, [r4, r1]
 *   @0x14b104 add r0, pc, r0
 *   @0x14b108 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #104 d3d_start → F_D3DStart(RValue&, CInstance*, CInstance*, int, RValue*) argc=None flag=1 ⚠ ?
 *   @0x14b10c ldr r1, [pc, #-0x2c0]
 *   @0x14b110 ldr r0, [pc, #-0x2c0]
 *   @0x14b114 mov r2, r5
 *   @0x14b118 mov r3, #1
 *   @0x14b11c ldr r1, [r4, r1]
 *   @0x14b120 add r0, pc, r0
 *   @0x14b124 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #105 d3d_end → F_D3DEnd(RValue&, CInstance*, CInstance*, int, RValue*) argc=None flag=1 ⚠ ?
 *   @0x14b128 ldr r1, [pc, #-0x2d4]
 *   @0x14b12c ldr r0, [pc, #-0x2d4]
 *   @0x14b130 mov r2, #1
 *   @0x14b134 mov r3, r2
 *   @0x14b138 ldr r1, [r4, r1]
 *   @0x14b13c add r0, pc, r0
 *   @0x14b140 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #106 d3d_set_perspective → F_D3DSetPerspective(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14b144 ldr r1, [pc, #-0x2e8]
 *   @0x14b148 ldr r0, [pc, #-0x2e8]
 *   @0x14b14c mov r2, #1
 *   @0x14b150 mov r3, r2
 *   @0x14b154 ldr r1, [r4, r1]
 *   @0x14b158 add r0, pc, r0
 *   @0x14b15c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #107 d3d_set_hidden → F_D3DSetHidden(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14b160 ldr r1, [pc, #-0x2fc]
 *   @0x14b164 ldr r0, [pc, #-0x2fc]
 *   @0x14b168 mov r2, #1
 *   @0x14b16c mov r3, r2
 *   @0x14b170 ldr r1, [r4, r1]
 *   @0x14b174 add r0, pc, r0
 *   @0x14b178 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #108 d3d_set_depth → F_D3DSetDepth(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14b17c ldr r1, [pc, #-0x310]
 *   @0x14b180 ldr r0, [pc, #-0x310]
 *   @0x14b184 mov r2, #1
 *   @0x14b188 mov r3, r2
 *   @0x14b18c ldr r1, [r4, r1]
 *   @0x14b190 add r0, pc, r0
 *   @0x14b194 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #109 d3d_set_shading → F_D3DSetShading(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14b198 ldr r1, [pc, #-0x324]
 *   @0x14b19c ldr r0, [pc, #-0x324]
 *   @0x14b1a0 mov r2, #4
 *   @0x14b1a4 mov r3, #1
 *   @0x14b1a8 ldr r1, [r4, r1]
 *   @0x14b1ac add r0, pc, r0
 *   @0x14b1b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #110 d3d_set_fog → F_D3DSetFog(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x14b1b4 ldr r1, [pc, #-0x338]
 *   @0x14b1b8 ldr r0, [pc, #-0x338]
 *   @0x14b1bc mov r2, #1
 *   @0x14b1c0 mov r3, r2
 *   @0x14b1c4 ldr r1, [r4, r1]
 *   @0x14b1c8 add r0, pc, r0
 *   @0x14b1cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #111 d3d_set_culling → F_D3DSetCulling(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14b1d0 ldr r1, [pc, #-0x34c]
 *   @0x14b1d4 ldr r0, [pc, #-0x34c]
 *   @0x14b1d8 mov r2, #1
 *   @0x14b1dc mov r3, r2
 *   @0x14b1e0 ldr r1, [r4, r1]
 *   @0x14b1e4 add r0, pc, r0
 *   @0x14b1e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #112 d3d_set_zwriteenable → F_D3DSetZWriteEnable(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14b1ec ldr r1, [pc, #-0x360]
 *   @0x14b1f0 ldr r0, [pc, #-0x360]
 *   @0x14b1f4 mov r2, #1
 *   @0x14b1f8 mov r3, r2
 *   @0x14b1fc ldr r1, [r4, r1]
 *   @0x14b200 add r0, pc, r0
 *   @0x14b204 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #113 d3d_primitive_begin → F_D3DPrimitiveBegin(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14b208 ldr r1, [pc, #-0x374]
 *   @0x14b20c ldr r0, [pc, #-0x374]
 *   @0x14b210 mov r2, #2
 *   @0x14b214 mov r3, #1
 *   @0x14b218 ldr r1, [r4, r1]
 *   @0x14b21c add r0, pc, r0
 *   @0x14b220 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #114 d3d_primitive_begin_texture → F_D3DPrimitiveBeginTexture(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x14b224 ldr r1, [pc, #-0x388]
 *   @0x14b228 ldr r0, [pc, #-0x388]
 *   @0x14b22c mov r2, r5
 *   @0x14b230 mov r3, #1
 *   @0x14b234 ldr r1, [r4, r1]
 *   @0x14b238 add r0, pc, r0
 *   @0x14b23c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #115 d3d_primitive_end → F_D3DPrimitiveEnd(RValue&, CInstance*, CInstance*, int, RValue*) argc=None flag=1 ⚠ ?
 *   @0x14b240 ldr r1, [pc, #-0x39c]
 *   @0x14b244 ldr r0, [pc, #-0x39c]
 *   @0x14b248 mov r2, #3
 *   @0x14b24c mov r3, #1
 *   @0x14b250 ldr r1, [r4, r1]
 *   @0x14b254 add r0, pc, r0
 *   @0x14b258 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #116 d3d_vertex → F_D3DVertex(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x14b25c ldr r1, [pc, #-0x3b0]
 *   @0x14b260 ldr r0, [pc, #-0x3b0]
 *   @0x14b264 mov r2, #5
 *   @0x14b268 mov r3, #1
 *   @0x14b26c ldr r7, [r4, r1]
 *   @0x14b270 add r0, pc, r0
 *   @0x14b274 mov r1, r7
 *   @0x14b278 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #117 d3d_vertex_color → F_D3DVertexColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x14b27c ldr r0, [pc, #-0x3c8]
 *   @0x14b280 mov r1, r7
 *   @0x14b284 mov r2, #5
 *   @0x14b288 add r0, pc, r0
 *   @0x14b28c mov r3, #1
 *   @0x14b290 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #118 d3d_vertex_colour → F_D3DVertexColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x14b294 ldr r1, [pc, #-0x3dc]
 *   @0x14b298 ldr r0, [pc, #-0x3dc]
 *   @0x14b29c mov r2, #5
 *   @0x14b2a0 mov r3, #1
 *   @0x14b2a4 ldr r1, [r4, r1]
 *   @0x14b2a8 add r0, pc, r0
 *   @0x14b2ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #119 d3d_vertex_texture → F_D3DVertexTexture(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x14b2b0 ldr r1, [pc, #-0x3f0]
 *   @0x14b2b4 ldr r0, [pc, #-0x3f0]
 *   @0x14b2b8 mov r2, #7
 *   @0x14b2bc mov r3, #1
 *   @0x14b2c0 ldr r7, [r4, r1]
 *   @0x14b2c4 add r0, pc, r0
 *   @0x14b2c8 mov r1, r7
 *   @0x14b2cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #120 d3d_vertex_texture_color → F_D3DVertexTextureColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x14b2d0 ldr r0, [pc, #-0x408]
 *   @0x14b2d4 mov r1, r7
 *   @0x14b2d8 mov r2, #7
 *   @0x14b2dc add r0, pc, r0
 *   @0x14b2e0 mov r3, #1
 *   @0x14b2e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #121 d3d_vertex_texture_colour → F_D3DVertexTextureColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x14b2e8 ldr r1, [pc, #-0x41c]
 *   @0x14b2ec ldr r0, [pc, #-0x41c]
 *   @0x14b2f0 mov r2, #6
 *   @0x14b2f4 mov r3, #1
 *   @0x14b2f8 ldr r1, [r4, r1]
 *   @0x14b2fc add r0, pc, r0
 *   @0x14b300 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #122 d3d_vertex_normal → F_D3DVertexNormal(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x14b304 ldr r1, [pc, #-0x430]
 *   @0x14b308 ldr r0, [pc, #-0x430]
 *   @0x14b30c mov r2, #8
 *   @0x14b310 mov r3, #1
 *   @0x14b314 ldr r7, [r4, r1]
 *   @0x14b318 add r0, pc, r0
 *   @0x14b31c mov r1, r7
 *   @0x14b320 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #123 d3d_vertex_normal_color → F_D3DVertexNormalColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x14b324 ldr r0, [pc, #-0x448]
 *   @0x14b328 mov r1, r7
 *   @0x14b32c mov r2, #8
 *   @0x14b330 add r0, pc, r0
 *   @0x14b334 mov r3, #1
 *   @0x14b338 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #124 d3d_vertex_normal_colour → F_D3DVertexNormalColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x14b33c ldr r1, [pc, #-0x45c]
 *   @0x14b340 ldr r0, [pc, #-0x45c]
 *   @0x14b344 mov r2, #8
 *   @0x14b348 mov r3, #1
 *   @0x14b34c ldr r1, [r4, r1]
 *   @0x14b350 add r0, pc, r0
 *   @0x14b354 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #125 d3d_vertex_normal_texture → F_D3DVertexNormalTexture(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x14b358 ldr r1, [pc, #-0x470]
 *   @0x14b35c ldr r0, [pc, #-0x470]
 *   @0x14b360 mov r2, #10
 *   @0x14b364 mov r3, #1
 *   @0x14b368 ldr r7, [r4, r1]
 *   @0x14b36c add r0, pc, r0
 *   @0x14b370 mov r1, r7
 *   @0x14b374 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #126 d3d_vertex_normal_texture_color → F_D3DVertexNormalTextureColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=10 flag=1
 *   @0x14b378 ldr r0, [pc, #-0x488]
 *   @0x14b37c mov r1, r7
 *   @0x14b380 mov r2, #10
 *   @0x14b384 add r0, pc, r0
 *   @0x14b388 mov r3, #1
 *   @0x14b38c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #127 d3d_vertex_normal_texture_colour → F_D3DVertexNormalTextureColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=10 flag=1
 *   @0x14b390 ldr r1, [pc, #-0x49c]
 *   @0x14b394 ldr r0, [pc, #-0x49c]
 *   @0x14b398 mov r2, #9
 *   @0x14b39c mov r3, #1
 *   @0x14b3a0 ldr r1, [r4, r1]
 *   @0x14b3a4 add r0, pc, r0
 *   @0x14b3a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #128 d3d_draw_block → F_D3DDrawBlock(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x14b3ac ldr r1, [pc, #-0x4b0]
 *   @0x14b3b0 ldr r0, [pc, #-0x4b0]
 *   @0x14b3b4 mov r2, #11
 *   @0x14b3b8 mov r3, #1
 *   @0x14b3bc ldr r1, [r4, r1]
 *   @0x14b3c0 add r0, pc, r0
 *   @0x14b3c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #129 d3d_draw_cylinder → F_D3DDrawCylinder(RValue&, CInstance*, CInstance*, int, RValue*) argc=11 flag=1
 *   @0x14b3c8 ldr r1, [pc, #-0x4c4]
 *   @0x14b3cc ldr r0, [pc, #-0x4c4]
 *   @0x14b3d0 mov r2, #11
 *   @0x14b3d4 mov r3, #1
 *   @0x14b3d8 ldr r1, [r4, r1]
 *   @0x14b3dc add r0, pc, r0
 *   @0x14b3e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #130 d3d_draw_cone → F_D3DDrawCone(RValue&, CInstance*, CInstance*, int, RValue*) argc=11 flag=1
 *   @0x14b3e4 ldr r1, [pc, #-0x4d8]
 *   @0x14b3e8 ldr r0, [pc, #-0x4d8]
 *   @0x14b3ec mov r2, #10
 *   @0x14b3f0 mov r3, #1
 *   @0x14b3f4 ldr r1, [r4, r1]
 *   @0x14b3f8 add r0, pc, r0
 *   @0x14b3fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #131 d3d_draw_ellipsoid → F_D3DDrawEllipsoid(RValue&, CInstance*, CInstance*, int, RValue*) argc=10 flag=1
 *   @0x14b400 ldr r1, [pc, #-0x4ec]
 *   @0x14b404 ldr r0, [pc, #-0x4ec]
 *   @0x14b408 mov r2, #9
 *   @0x14b40c mov r3, #1
 *   @0x14b410 ldr r1, [r4, r1]
 *   @0x14b414 add r0, pc, r0
 *   @0x14b418 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #132 d3d_draw_wall → F_D3DDrawWall(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x14b41c ldr r1, [pc, #-0x500]
 *   @0x14b420 ldr r0, [pc, #-0x500]
 *   @0x14b424 mov r2, #9
 *   @0x14b428 mov r3, #1
 *   @0x14b42c ldr r1, [r4, r1]
 *   @0x14b430 add r0, pc, r0
 *   @0x14b434 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #133 d3d_draw_floor → F_D3DDrawFloor(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x14b438 ldr r1, [pc, #-0x514]
 *   @0x14b43c ldr r0, [pc, #-0x514]
 *   @0x14b440 mov r2, #9
 *   @0x14b444 mov r3, #1
 *   @0x14b448 ldr r1, [r4, r1]
 *   @0x14b44c add r0, pc, r0
 *   @0x14b450 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #134 d3d_set_projection → F_D3DSetProjection(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x14b454 ldr r1, [pc, #-0x528]
 *   @0x14b458 ldr r0, [pc, #-0x528]
 *   @0x14b45c mov r2, #13
 *   @0x14b460 mov r3, #1
 *   @0x14b464 ldr r1, [r4, r1]
 *   @0x14b468 add r0, pc, r0
 *   @0x14b46c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #135 d3d_set_projection_ext → F_D3DSetProjectionExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=13 flag=1
 *   @0x14b470 ldr r1, [pc, #-0x53c]
 *   @0x14b474 ldr r0, [pc, #-0x53c]
 *   @0x14b478 mov r2, #5
 *   @0x14b47c mov r3, #1
 *   @0x14b480 ldr r1, [r4, r1]
 *   @0x14b484 add r0, pc, r0
 *   @0x14b488 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #136 d3d_set_projection_ortho → F_D3DSetProjectionOrtho(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x14b48c ldr r1, [pc, #-0x550]
 *   @0x14b490 ldr r0, [pc, #-0x550]
 *   @0x14b494 mov r2, #5
 *   @0x14b498 mov r3, #1
 *   @0x14b49c ldr r1, [r4, r1]
 *   @0x14b4a0 add r0, pc, r0
 *   @0x14b4a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #137 d3d_set_projection_perspective → F_D3DSetProjectionPerspective(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x14b4a8 ldr r1, [pc, #-0x564]
 *   @0x14b4ac ldr r0, [pc, #-0x564]
 *   @0x14b4b0 mov r2, r5
 *   @0x14b4b4 mov r3, #1
 *   @0x14b4b8 ldr r1, [r4, r1]
 *   @0x14b4bc add r0, pc, r0
 *   @0x14b4c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #138 d3d_transform_set_identity → F_D3DTransformSetIdentity(RValue&, CInstance*, CInstance*, int, RValue*) argc=None flag=1 ⚠ ?
 *   @0x14b4c4 ldr r1, [pc, #-0x578]
 *   @0x14b4c8 ldr r0, [pc, #-0x578]
 *   @0x14b4cc mov r2, #3
 *   @0x14b4d0 mov r3, #1
 *   @0x14b4d4 ldr r1, [r4, r1]
 *   @0x14b4d8 add r0, pc, r0
 *   @0x14b4dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #139 d3d_transform_set_translation → F_D3DTransformSetTranslation(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x14b4e0 ldr r1, [pc, #-0x58c]
 *   @0x14b4e4 ldr r0, [pc, #-0x58c]
 *   @0x14b4e8 mov r2, #3
 *   @0x14b4ec mov r3, #1
 *   @0x14b4f0 ldr r1, [r4, r1]
 *   @0x14b4f4 add r0, pc, r0
 *   @0x14b4f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #140 d3d_transform_set_scaling → F_D3DTransformSetScaling(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x14b4fc ldr r1, [pc, #-0x5a0]
 *   @0x14b500 ldr r0, [pc, #-0x5a0]
 *   @0x14b504 mov r2, #1
 *   @0x14b508 mov r3, r2
 *   @0x14b50c ldr r1, [r4, r1]
 *   @0x14b510 add r0, pc, r0
 *   @0x14b514 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #141 d3d_transform_set_rotation_x → F_D3DTransformSetRotationX(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14b518 ldr r1, [pc, #-0x5b4]
 *   @0x14b51c ldr r0, [pc, #-0x5b4]
 *   @0x14b520 mov r2, #1
 *   @0x14b524 mov r3, r2
 *   @0x14b528 ldr r1, [r4, r1]
 *   @0x14b52c add r0, pc, r0
 *   @0x14b530 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #142 d3d_transform_set_rotation_y → F_D3DTransformSetRotationY(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14b534 ldr r1, [pc, #-0x5c8]
 *   @0x14b538 ldr r0, [pc, #-0x5c8]
 *   @0x14b53c mov r2, #1
 *   @0x14b540 mov r3, r2
 *   @0x14b544 ldr r1, [r4, r1]
 *   @0x14b548 add r0, pc, r0
 *   @0x14b54c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #143 d3d_transform_set_rotation_z → F_D3DTransformSetRotationZ(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14b550 ldr r1, [pc, #-0x5dc]
 *   @0x14b554 ldr r0, [pc, #-0x5dc]
 *   @0x14b558 mov r2, #4
 *   @0x14b55c mov r3, #1
 *   @0x14b560 ldr r1, [r4, r1]
 *   @0x14b564 add r0, pc, r0
 *   @0x14b568 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #144 d3d_transform_set_rotation_axis → F_D3DTransformSetRotationAxis(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x14b56c ldr r1, [pc, #-0x5f0]
 *   @0x14b570 ldr r0, [pc, #-0x5f0]
 *   @0x14b574 mov r2, #3
 *   @0x14b578 mov r3, #1
 *   @0x14b57c ldr r1, [r4, r1]
 *   @0x14b580 add r0, pc, r0
 *   @0x14b584 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #145 d3d_transform_add_translation → F_D3DTransformAddTranslation(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x14b588 ldr r1, [pc, #-0x604]
 *   @0x14b58c ldr r0, [pc, #-0x604]
 *   @0x14b590 mov r2, #3
 *   @0x14b594 mov r3, #1
 *   @0x14b598 ldr r1, [r4, r1]
 *   @0x14b59c add r0, pc, r0
 *   @0x14b5a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #146 d3d_transform_add_scaling → F_D3DTransformAddScaling(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x14b5a4 ldr r1, [pc, #-0x618]
 *   @0x14b5a8 ldr r0, [pc, #-0x618]
 *   @0x14b5ac mov r2, #1
 *   @0x14b5b0 mov r3, r2
 *   @0x14b5b4 ldr r1, [r4, r1]
 *   @0x14b5b8 add r0, pc, r0
 *   @0x14b5bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #147 d3d_transform_add_rotation_x → F_D3DTransformAddRotationX(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14b5c0 ldr r1, [pc, #-0x62c]
 *   @0x14b5c4 ldr r0, [pc, #-0x62c]
 *   @0x14b5c8 mov r2, #1
 *   @0x14b5cc mov r3, r2
 *   @0x14b5d0 ldr r1, [r4, r1]
 *   @0x14b5d4 add r0, pc, r0
 *   @0x14b5d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #148 d3d_transform_add_rotation_y → F_D3DTransformAddRotationY(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14b5dc ldr r1, [pc, #-0x640]
 *   @0x14b5e0 ldr r0, [pc, #-0x640]
 *   @0x14b5e4 mov r2, #1
 *   @0x14b5e8 mov r3, r2
 *   @0x14b5ec ldr r1, [r4, r1]
 *   @0x14b5f0 add r0, pc, r0
 *   @0x14b5f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #149 d3d_transform_add_rotation_z → F_D3DTransformAddRotationZ(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14b5f8 ldr r1, [pc, #-0x654]
 *   @0x14b5fc ldr r0, [pc, #-0x654]
 *   @0x14b600 mov r2, #4
 *   @0x14b604 mov r3, #1
 *   @0x14b608 ldr r1, [r4, r1]
 *   @0x14b60c add r0, pc, r0
 *   @0x14b610 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #150 d3d_transform_add_rotation_axis → F_D3DTransformAddRotationAxis(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x14b614 ldr r1, [pc, #-0x668]
 *   @0x14b618 ldr r0, [pc, #-0x668]
 *   @0x14b61c mov r2, r5
 *   @0x14b620 mov r3, #1
 *   @0x14b624 ldr r1, [r4, r1]
 *   @0x14b628 add r0, pc, r0
 *   @0x14b62c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #151 d3d_transform_stack_clear → F_D3DTransformStackClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=None flag=1 ⚠ ?
 *   @0x14b630 ldr r1, [pc, #-0x67c]
 *   @0x14b634 ldr r0, [pc, #-0x67c]
 *   @0x14b638 mov r2, r5
 *   @0x14b63c mov r3, #1
 *   @0x14b640 ldr r1, [r4, r1]
 *   @0x14b644 add r0, pc, r0
 *   @0x14b648 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #152 d3d_transform_stack_empty → F_D3DTransformStackEmpty(RValue&, CInstance*, CInstance*, int, RValue*) argc=None flag=1 ⚠ ?
 *   @0x14b64c ldr r1, [pc, #-0x690]
 *   @0x14b650 ldr r0, [pc, #-0x690]
 *   @0x14b654 mov r2, r5
 *   @0x14b658 mov r3, #1
 *   @0x14b65c ldr r1, [r4, r1]
 *   @0x14b660 add r0, pc, r0
 *   @0x14b664 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #153 d3d_transform_stack_push → F_D3DTransformStackPush(RValue&, CInstance*, CInstance*, int, RValue*) argc=None flag=1 ⚠ ?
 *   @0x14b668 ldr r1, [pc, #-0x6a4]
 *   @0x14b66c ldr r0, [pc, #-0x6a4]
 *   @0x14b670 mov r2, r5
 *   @0x14b674 mov r3, #1
 *   @0x14b678 ldr r1, [r4, r1]
 *   @0x14b67c add r0, pc, r0
 *   @0x14b680 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #154 d3d_transform_stack_pop → F_D3DTransformStackPop(RValue&, CInstance*, CInstance*, int, RValue*) argc=None flag=1 ⚠ ?
 *   @0x14b684 ldr r1, [pc, #-0x6b8]
 *   @0x14b688 ldr r0, [pc, #-0x6b8]
 *   @0x14b68c mov r2, r5
 *   @0x14b690 mov r3, #1
 *   @0x14b694 ldr r1, [r4, r1]
 *   @0x14b698 add r0, pc, r0
 *   @0x14b69c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #155 d3d_transform_stack_top → F_D3DTransformStackTop(RValue&, CInstance*, CInstance*, int, RValue*) argc=None flag=1 ⚠ ?
 *   @0x14b6a0 ldr r1, [pc, #-0x6cc]
 *   @0x14b6a4 ldr r0, [pc, #-0x6cc]
 *   @0x14b6a8 mov r2, r5
 *   @0x14b6ac mov r3, #1
 *   @0x14b6b0 ldr r1, [r4, r1]
 *   @0x14b6b4 add r0, pc, r0
 *   @0x14b6b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #156 d3d_transform_stack_discard → F_D3DTransformStackDiscard(RValue&, CInstance*, CInstance*, int, RValue*) argc=None flag=1 ⚠ ?
 *   @0x14b6bc ldr r1, [pc, #-0x6e0]
 *   @0x14b6c0 ldr r0, [pc, #-0x6e0]
 *   @0x14b6c4 mov r2, #3
 *   @0x14b6c8 mov r3, #1
 *   @0x14b6cc ldr r1, [r4, r1]
 *   @0x14b6d0 add r0, pc, r0
 *   @0x14b6d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #157 d3d_transform_vertex → F_D3DTransformVertex(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x14b6d8 ldr r1, [pc, #-0x6f4]
 *   @0x14b6dc ldr r0, [pc, #-0x6f4]
 *   @0x14b6e0 mov r2, r5
 *   @0x14b6e4 mov r3, #1
 *   @0x14b6e8 ldr r1, [r4, r1]
 *   @0x14b6ec add r0, pc, r0
 *   @0x14b6f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #158 d3d_model_create → F_D3DModelCreate(RValue&, CInstance*, CInstance*, int, RValue*) argc=None flag=1 ⚠ ?
 *   @0x14b6f4 ldr r1, [pc, #-0x708]
 *   @0x14b6f8 ldr r0, [pc, #-0x708]
 *   @0x14b6fc mov r2, #1
 *   @0x14b700 mov r3, r2
 *   @0x14b704 ldr r1, [r4, r1]
 *   @0x14b708 add r0, pc, r0
 *   @0x14b70c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #159 d3d_model_destroy → F_D3DModelDestroy(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14b710 ldr r1, [pc, #-0x71c]
 *   @0x14b714 ldr r0, [pc, #-0x71c]
 *   @0x14b718 mov r2, #1
 *   @0x14b71c mov r3, r2
 *   @0x14b720 ldr r1, [r4, r1]
 *   @0x14b724 add r0, pc, r0
 *   @0x14b728 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #160 d3d_model_clear → F_D3DModelClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14b72c ldr r1, [pc, #-0x730]
 *   @0x14b730 ldr r0, [pc, #-0x730]
 *   @0x14b734 mov r2, #2
 *   @0x14b738 mov r3, #1
 *   @0x14b73c ldr r1, [r4, r1]
 *   @0x14b740 add r0, pc, r0
 *   @0x14b744 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #161 d3d_model_load → F_D3DModelLoad(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x14b748 ldr r1, [pc, #-0x744]
 *   @0x14b74c ldr r0, [pc, #-0x744]
 *   @0x14b750 mov r2, #2
 *   @0x14b754 mov r3, #1
 *   @0x14b758 ldr r1, [r4, r1]
 *   @0x14b75c add r0, pc, r0
 *   @0x14b760 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #162 d3d_model_save → F_D3DModelSave(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x14b764 ldr r1, [pc, #-0x758]
 *   @0x14b768 ldr r0, [pc, #-0x758]
 *   @0x14b76c mov r2, #2
 *   @0x14b770 mov r3, #1
 *   @0x14b774 ldr r1, [r4, r1]
 *   @0x14b778 add r0, pc, r0
 *   @0x14b77c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #163 d3d_model_load_buffer → F_D3DModelLoadBuffer(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x14b780 ldr r1, [pc, #-0x76c]
 *   @0x14b784 ldr r0, [pc, #-0x76c]
 *   @0x14b788 mov r2, #2
 *   @0x14b78c mov r3, #1
 *   @0x14b790 ldr r1, [r4, r1]
 *   @0x14b794 add r0, pc, r0
 *   @0x14b798 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #164 d3d_model_save_buffer → F_D3DModelSaveBuffer(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x14b79c ldr r1, [pc, #-0x780]
 *   @0x14b7a0 ldr r0, [pc, #-0x780]
 *   @0x14b7a4 mov r2, #5
 *   @0x14b7a8 mov r3, #1
 *   @0x14b7ac ldr r1, [r4, r1]
 *   @0x14b7b0 add r0, pc, r0
 *   @0x14b7b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #165 d3d_model_draw → F_D3DModelDraw(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x14b7b8 ldr r1, [pc, #-0x794]
 *   @0x14b7bc ldr r0, [pc, #-0x794]
 *   @0x14b7c0 mov r2, #2
 *   @0x14b7c4 mov r3, #1
 *   @0x14b7c8 ldr r1, [r4, r1]
 *   @0x14b7cc add r0, pc, r0
 *   @0x14b7d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #166 d3d_model_primitive_begin → F_D3DModelPrimitiveBegin(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x14b7d4 ldr r1, [pc, #-0x7a8]
 *   @0x14b7d8 ldr r0, [pc, #-0x7a8]
 *   @0x14b7dc mov r2, #1
 *   @0x14b7e0 mov r3, r2
 *   @0x14b7e4 ldr r1, [r4, r1]
 *   @0x14b7e8 add r0, pc, r0
 *   @0x14b7ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #167 d3d_model_primitive_end → F_D3DModelPrimitiveEnd(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14b7f0 ldr r1, [pc, #-0x7bc]
 *   @0x14b7f4 ldr r0, [pc, #-0x7bc]
 *   @0x14b7f8 mov r2, #4
 *   @0x14b7fc mov r3, #1
 *   @0x14b800 ldr r1, [r4, r1]
 *   @0x14b804 add r0, pc, r0
 *   @0x14b808 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #168 d3d_model_vertex → F_D3DModelVertex(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x14b80c ldr r1, [pc, #-0x7d0]
 *   @0x14b810 ldr r0, [pc, #-0x7d0]
 *   @0x14b814 mov r2, #6
 *   @0x14b818 mov r3, #1
 *   @0x14b81c ldr r7, [r4, r1]
 *   @0x14b820 add r0, pc, r0
 *   @0x14b824 mov r1, r7
 *   @0x14b828 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #169 d3d_model_vertex_color → F_D3DModelVertexColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x14b82c ldr r0, [pc, #-0x7e8]
 *   @0x14b830 mov r1, r7
 *   @0x14b834 mov r2, #6
 *   @0x14b838 add r0, pc, r0
 *   @0x14b83c mov r3, #1
 *   @0x14b840 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #170 d3d_model_vertex_colour → F_D3DModelVertexColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x14b844 ldr r1, [pc, #-0x7fc]
 *   @0x14b848 ldr r0, [pc, #-0x7fc]
 *   @0x14b84c mov r2, #6
 *   @0x14b850 mov r3, #1
 *   @0x14b854 ldr r1, [r4, r1]
 *   @0x14b858 add r0, pc, r0
 *   @0x14b85c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #171 d3d_model_vertex_texture → F_D3DModelVertexTexture(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x14b860 ldr r1, [pc, #-0x810]
 *   @0x14b864 ldr r0, [pc, #-0x810]
 *   @0x14b868 mov r2, #8
 *   @0x14b86c mov r3, #1
 *   @0x14b870 ldr r7, [r4, r1]
 *   @0x14b874 add r0, pc, r0
 *   @0x14b878 mov r1, r7
 *   @0x14b87c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #172 d3d_model_vertex_texture_color → F_D3DModelVertexTextureColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x14b880 ldr r0, [pc, #-0x828]
 *   @0x14b884 mov r1, r7
 *   @0x14b888 mov r2, #8
 *   @0x14b88c add r0, pc, r0
 *   @0x14b890 mov r3, #1
 *   @0x14b894 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #173 d3d_model_vertex_texture_colour → F_D3DModelVertexTextureColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x14b898 ldr r1, [pc, #-0x83c]
 *   @0x14b89c ldr r0, [pc, #-0x83c]
 *   @0x14b8a0 mov r2, #7
 *   @0x14b8a4 mov r3, #1
 *   @0x14b8a8 ldr r1, [r4, r1]
 *   @0x14b8ac add r0, pc, r0
 *   @0x14b8b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #174 d3d_model_vertex_normal → F_D3DModelVertexNormal(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x14b8b4 ldr r1, [pc, #-0x850]
 *   @0x14b8b8 ldr r0, [pc, #-0x850]
 *   @0x14b8bc mov r2, #9
 *   @0x14b8c0 mov r3, #1
 *   @0x14b8c4 ldr r7, [r4, r1]
 *   @0x14b8c8 add r0, pc, r0
 *   @0x14b8cc mov r1, r7
 *   @0x14b8d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #175 d3d_model_vertex_normal_color → F_D3DModelVertexNormalColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x14b8d4 ldr r0, [pc, #-0x868]
 *   @0x14b8d8 mov r1, r7
 *   @0x14b8dc mov r2, #9
 *   @0x14b8e0 add r0, pc, r0
 *   @0x14b8e4 mov r3, #1
 *   @0x14b8e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #176 d3d_model_vertex_normal_colour → F_D3DModelVertexNormalColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x14b8ec ldr r1, [pc, #-0x87c]
 *   @0x14b8f0 ldr r0, [pc, #-0x87c]
 *   @0x14b8f4 mov r2, #9
 *   @0x14b8f8 mov r3, #1
 *   @0x14b8fc ldr r1, [r4, r1]
 *   @0x14b900 add r0, pc, r0
 *   @0x14b904 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #177 d3d_model_vertex_normal_texture → F_D3DModelVertexNormalTexture(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x14b908 ldr r1, [pc, #-0x890]
 *   @0x14b90c ldr r0, [pc, #-0x890]
 *   @0x14b910 mov r2, #11
 *   @0x14b914 mov r3, #1
 *   @0x14b918 ldr r7, [r4, r1]
 *   @0x14b91c add r0, pc, r0
 *   @0x14b920 mov r1, r7
 *   @0x14b924 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #178 d3d_model_vertex_normal_texture_color → F_D3DModelVertexNormalTextureColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=11 flag=1
 *   @0x14b928 ldr r0, [pc, #-0x8a8]
 *   @0x14b92c mov r1, r7
 *   @0x14b930 mov r2, #11
 *   @0x14b934 add r0, pc, r0
 *   @0x14b938 mov r3, #1
 *   @0x14b93c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #179 d3d_model_vertex_normal_texture_colour → F_D3DModelVertexNormalTextureColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=11 flag=1
 *   @0x14b940 ldr r1, [pc, #-0x8bc]
 *   @0x14b944 ldr r0, [pc, #-0x8bc]
 *   @0x14b948 mov r2, #9
 *   @0x14b94c mov r3, #1
 *   @0x14b950 ldr r1, [r4, r1]
 *   @0x14b954 add r0, pc, r0
 *   @0x14b958 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #180 d3d_model_block → F_D3DModelBlock(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x14b95c ldr r1, [pc, #-0x8d0]
 *   @0x14b960 ldr r0, [pc, #-0x8d0]
 *   @0x14b964 mov r2, #11
 *   @0x14b968 mov r3, #1
 *   @0x14b96c ldr r1, [r4, r1]
 *   @0x14b970 add r0, pc, r0
 *   @0x14b974 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #181 d3d_model_cylinder → F_D3DModelCylinder(RValue&, CInstance*, CInstance*, int, RValue*) argc=11 flag=1
 *   @0x14b978 ldr r1, [pc, #-0x8e4]
 *   @0x14b97c ldr r0, [pc, #-0x8e4]
 *   @0x14b980 mov r2, #11
 *   @0x14b984 mov r3, #1
 *   @0x14b988 ldr r1, [r4, r1]
 *   @0x14b98c add r0, pc, r0
 *   @0x14b990 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #182 d3d_model_cone → F_D3DModelCone(RValue&, CInstance*, CInstance*, int, RValue*) argc=11 flag=1
 *   @0x14b994 ldr r1, [pc, #-0x8f8]
 *   @0x14b998 ldr r0, [pc, #-0x8f8]
 *   @0x14b99c mov r2, #10
 *   @0x14b9a0 mov r3, #1
 *   @0x14b9a4 ldr r1, [r4, r1]
 *   @0x14b9a8 add r0, pc, r0
 *   @0x14b9ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #183 d3d_model_ellipsoid → F_D3DModelEllipsoid(RValue&, CInstance*, CInstance*, int, RValue*) argc=10 flag=1
 *   @0x14b9b0 ldr r1, [pc, #-0x90c]
 *   @0x14b9b4 ldr r0, [pc, #-0x90c]
 *   @0x14b9b8 mov r2, #9
 *   @0x14b9bc mov r3, #1
 *   @0x14b9c0 ldr r1, [r4, r1]
 *   @0x14b9c4 add r0, pc, r0
 *   @0x14b9c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #184 d3d_model_wall → F_D3DModelWall(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x14b9cc ldr r1, [pc, #-0x920]
 *   @0x14b9d0 ldr r0, [pc, #-0x920]
 *   @0x14b9d4 mov r2, #9
 *   @0x14b9d8 mov r3, #1
 *   @0x14b9dc ldr r1, [r4, r1]
 *   @0x14b9e0 add r0, pc, r0
 *   @0x14b9e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #185 d3d_model_floor → F_D3DModelFloor(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x14b9e8 ldr r1, [pc, #-0x934]
 *   @0x14b9ec ldr r0, [pc, #-0x934]
 *   @0x14b9f0 mov r2, #1
 *   @0x14b9f4 mov r3, r2
 *   @0x14b9f8 ldr r1, [r4, r1]
 *   @0x14b9fc add r0, pc, r0
 *   @0x14ba00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #186 d3d_light_define_ambient → F_D3DLightSetAmbient(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14ba04 ldr r1, [pc, #-0x948]
 *   @0x14ba08 ldr r0, [pc, #-0x948]
 *   @0x14ba0c mov r2, #5
 *   @0x14ba10 mov r3, #1
 *   @0x14ba14 ldr r1, [r4, r1]
 *   @0x14ba18 add r0, pc, r0
 *   @0x14ba1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #187 d3d_light_define_direction → F_D3DLightDefineDirection(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x14ba20 ldr r1, [pc, #-0x95c]
 *   @0x14ba24 ldr r0, [pc, #-0x95c]
 *   @0x14ba28 mov r2, #6
 *   @0x14ba2c mov r3, #1
 *   @0x14ba30 ldr r1, [r4, r1]
 *   @0x14ba34 add r0, pc, r0
 *   @0x14ba38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #188 d3d_light_define_point → F_D3DLightDefinePoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x14ba3c ldr r1, [pc, #-0x970]
 *   @0x14ba40 ldr r0, [pc, #-0x970]
 *   @0x14ba44 mov r2, #2
 *   @0x14ba48 mov r3, #1
 *   @0x14ba4c ldr r1, [r4, r1]
 *   @0x14ba50 add r0, pc, r0
 *   @0x14ba54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #189 d3d_light_enable → F_D3DLightEnable(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x14ba58 ldr r1, [pc, #-0x984]
 *   @0x14ba5c ldr r0, [pc, #-0x984]
 *   @0x14ba60 mov r2, #1
 *   @0x14ba64 mov r3, r2
 *   @0x14ba68 ldr r1, [r4, r1]
 *   @0x14ba6c add r0, pc, r0
 *   @0x14ba70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #190 d3d_set_lighting → F_D3DSetLighting(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14ba74 ldr r1, [pc, #-0x998]
 *   @0x14ba78 ldr r0, [pc, #-0x998]
 *   @0x14ba7c mov r3, r5
 *   @0x14ba80 mov r2, #1
 *   @0x14ba84 ldr r7, [r4, r1]
 *   @0x14ba88 add r0, pc, r0
 *   @0x14ba8c mov r1, r7
 *   @0x14ba90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #191 YoYo_EnableAlphaBlend → F_YoYo_EnableAlphaBlend(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=None ⚠ ?
 *   @0x14ba94 ldr r0, [pc, #-0x9b0]
 *   @0x14ba98 mov r1, r7
 *   @0x14ba9c mov r3, r5
 *   @0x14baa0 add r0, pc, r0
 *   @0x14baa4 mov r2, #1
 *   @0x14baa8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #192 draw_enable_alphablend → F_YoYo_EnableAlphaBlend(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=None ⚠ ?
 *   @0x14baac b 0x149f6c <_Z15Init3DFunctionsv+0x20>
 *
 * ══ §3/5 InitBufferFunctions  0xc75fc..0xc7b44  size 1352  338 条（263 条指令 + 75 个池字）══
 * @func 0xc75fc 0xc7b44  size 1352  338 条
 * 注册 37 条｜唯一名 37｜唯一函数指针 37｜argc 0:1 1:11 2:4 3:10 4:4 5:7｜flag 0:37
 * 首条 #0 buffer_create（0xc7620）→ 末条 #36 buffer_copy_from_vertex_buffer（0xc7a14）
 * 名字族（前 8）: buffer×37
 * 游戏实际调用的 99 个内建里落在本表: 0 个
 * 表: asm/init-tables/init-InitBufferFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: 无（本函数每条注册的四实参全部解出，控制流全部走到）
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc75fc push {r4, lr}
 *   @0xc7600 mov r2, #3
 *   @0xc7604 ldr r4, [pc, #0x40c]
 *   @0xc7608 mov r3, #0
 *   @0xc760c ldr r1, [pc, #0x408]
 *   @0xc7610 add r4, pc, r4
 *   @0xc7614 ldr r0, [pc, #0x404]
 *   @0xc7618 ldr r1, [r4, r1]
 *   @0xc761c add r0, pc, r0
 *   @0xc7620 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 buffer_create → F_BUFFER_Create(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0xc7624 ldr r1, [pc, #0x3f8]
 *   @0xc7628 ldr r0, [pc, #0x3f8]
 *   @0xc762c mov r2, #1
 *   @0xc7630 mov r3, #0
 *   @0xc7634 ldr r1, [r4, r1]
 *   @0xc7638 add r0, pc, r0
 *   @0xc763c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 buffer_delete → F_BUFFER_Delete(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0xc7640 ldr r1, [pc, #0x3e4]
 *   @0xc7644 ldr r0, [pc, #0x3e4]
 *   @0xc7648 mov r2, #3
 *   @0xc764c mov r3, #0
 *   @0xc7650 ldr r1, [r4, r1]
 *   @0xc7654 add r0, pc, r0
 *   @0xc7658 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 buffer_write → F_BUFFER_Write(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0xc765c ldr r1, [pc, #0x3d0]
 *   @0xc7660 ldr r0, [pc, #0x3d0]
 *   @0xc7664 mov r2, #2
 *   @0xc7668 mov r3, #0
 *   @0xc766c ldr r1, [r4, r1]
 *   @0xc7670 add r0, pc, r0
 *   @0xc7674 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 buffer_read → F_BUFFER_Read(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0xc7678 ldr r1, [pc, #0x3bc]
 *   @0xc767c ldr r0, [pc, #0x3bc]
 *   @0xc7680 mov r2, #4
 *   @0xc7684 mov r3, #0
 *   @0xc7688 ldr r1, [r4, r1]
 *   @0xc768c add r0, pc, r0
 *   @0xc7690 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #4 buffer_poke → F_BUFFER_Poke(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0xc7694 ldr r1, [pc, #0x3a8]
 *   @0xc7698 ldr r0, [pc, #0x3a8]
 *   @0xc769c mov r2, #3
 *   @0xc76a0 mov r3, #0
 *   @0xc76a4 ldr r1, [r4, r1]
 *   @0xc76a8 add r0, pc, r0
 *   @0xc76ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #5 buffer_peek → F_BUFFER_Peek(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0xc76b0 ldr r1, [pc, #0x394]
 *   @0xc76b4 ldr r0, [pc, #0x394]
 *   @0xc76b8 mov r2, #3
 *   @0xc76bc mov r3, #0
 *   @0xc76c0 ldr r1, [r4, r1]
 *   @0xc76c4 add r0, pc, r0
 *   @0xc76c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #6 buffer_seek → F_BUFFER_Seek(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0xc76cc ldr r1, [pc, #0x380]
 *   @0xc76d0 ldr r0, [pc, #0x380]
 *   @0xc76d4 mov r2, #2
 *   @0xc76d8 mov r3, #0
 *   @0xc76dc ldr r1, [r4, r1]
 *   @0xc76e0 add r0, pc, r0
 *   @0xc76e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #7 buffer_save → F_BUFFER_Save(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0xc76e8 ldr r1, [pc, #0x36c]
 *   @0xc76ec ldr r0, [pc, #0x36c]
 *   @0xc76f0 mov r2, #4
 *   @0xc76f4 mov r3, #0
 *   @0xc76f8 ldr r1, [r4, r1]
 *   @0xc76fc add r0, pc, r0
 *   @0xc7700 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #8 buffer_save_ext → F_BUFFER_Save_Ext(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0xc7704 ldr r1, [pc, #0x358]
 *   @0xc7708 ldr r0, [pc, #0x358]
 *   @0xc770c mov r2, #1
 *   @0xc7710 mov r3, #0
 *   @0xc7714 ldr r1, [r4, r1]
 *   @0xc7718 add r0, pc, r0
 *   @0xc771c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #9 buffer_load → F_BUFFER_Load(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0xc7720 ldr r1, [pc, #0x344]
 *   @0xc7724 ldr r0, [pc, #0x344]
 *   @0xc7728 mov r2, #3
 *   @0xc772c mov r3, #0
 *   @0xc7730 ldr r1, [r4, r1]
 *   @0xc7734 add r0, pc, r0
 *   @0xc7738 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #10 buffer_load_ext → F_BUFFER_Load_Ext(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0xc773c ldr r1, [pc, #0x330]
 *   @0xc7740 ldr r0, [pc, #0x330]
 *   @0xc7744 mov r2, #5
 *   @0xc7748 mov r3, #0
 *   @0xc774c ldr r1, [r4, r1]
 *   @0xc7750 add r0, pc, r0
 *   @0xc7754 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #11 buffer_load_partial → F_BUFFER_Load_Partial(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0xc7758 ldr r1, [pc, #0x31c]
 *   @0xc775c ldr r0, [pc, #0x31c]
 *   @0xc7760 mov r2, #4
 *   @0xc7764 mov r3, #0
 *   @0xc7768 ldr r1, [r4, r1]
 *   @0xc776c add r0, pc, r0
 *   @0xc7770 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #12 buffer_save_async → F_BUFFER_Save_Async(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0xc7774 ldr r1, [pc, #0x308]
 *   @0xc7778 ldr r0, [pc, #0x308]
 *   @0xc777c mov r2, #4
 *   @0xc7780 mov r3, #0
 *   @0xc7784 ldr r1, [r4, r1]
 *   @0xc7788 add r0, pc, r0
 *   @0xc778c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #13 buffer_load_async → F_BUFFER_Load_Async(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0xc7790 ldr r1, [pc, #0x2f4]
 *   @0xc7794 ldr r0, [pc, #0x2f4]
 *   @0xc7798 mov r2, #1
 *   @0xc779c mov r3, #0
 *   @0xc77a0 ldr r1, [r4, r1]
 *   @0xc77a4 add r0, pc, r0
 *   @0xc77a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #14 buffer_async_group_begin → F_BUFFER_Async_Group_Begin(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0xc77ac ldr r1, [pc, #0x2e0]
 *   @0xc77b0 ldr r0, [pc, #0x2e0]
 *   @0xc77b4 mov r2, #0
 *   @0xc77b8 mov r3, r2
 *   @0xc77bc ldr r1, [r4, r1]
 *   @0xc77c0 add r0, pc, r0
 *   @0xc77c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #15 buffer_async_group_end → F_BUFFER_Async_Group_End(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0xc77c8 ldr r1, [pc, #0x2cc]
 *   @0xc77cc ldr r0, [pc, #0x2cc]
 *   @0xc77d0 mov r2, #2
 *   @0xc77d4 mov r3, #0
 *   @0xc77d8 ldr r1, [r4, r1]
 *   @0xc77dc add r0, pc, r0
 *   @0xc77e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #16 buffer_async_group_option → F_BUFFER_Async_Group_Option(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0xc77e4 ldr r1, [pc, #0x2b8]
 *   @0xc77e8 ldr r0, [pc, #0x2b8]
 *   @0xc77ec mov r2, #5
 *   @0xc77f0 mov r3, #0
 *   @0xc77f4 ldr r1, [r4, r1]
 *   @0xc77f8 add r0, pc, r0
 *   @0xc77fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #17 buffer_copy → F_BUFFER_Copy(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0xc7800 ldr r1, [pc, #0x2a4]
 *   @0xc7804 ldr r0, [pc, #0x2a4]
 *   @0xc7808 mov r2, #1
 *   @0xc780c mov r3, #0
 *   @0xc7810 ldr r1, [r4, r1]
 *   @0xc7814 add r0, pc, r0
 *   @0xc7818 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #18 buffer_exists → F_BUFFER_Exists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0xc781c ldr r1, [pc, #0x290]
 *   @0xc7820 ldr r0, [pc, #0x290]
 *   @0xc7824 mov r2, #1
 *   @0xc7828 mov r3, #0
 *   @0xc782c ldr r1, [r4, r1]
 *   @0xc7830 add r0, pc, r0
 *   @0xc7834 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #19 buffer_get_type → F_BUFFER_Get_Type(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0xc7838 ldr r1, [pc, #0x27c]
 *   @0xc783c ldr r0, [pc, #0x27c]
 *   @0xc7840 mov r2, #1
 *   @0xc7844 mov r3, #0
 *   @0xc7848 ldr r1, [r4, r1]
 *   @0xc784c add r0, pc, r0
 *   @0xc7850 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #20 buffer_get_alignment → F_BUFFER_Get_Alignment(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0xc7854 ldr r1, [pc, #0x268]
 *   @0xc7858 ldr r0, [pc, #0x268]
 *   @0xc785c mov r2, #5
 *   @0xc7860 mov r3, #0
 *   @0xc7864 ldr r1, [r4, r1]
 *   @0xc7868 add r0, pc, r0
 *   @0xc786c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #21 buffer_fill → F_BUFFER_Fill(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0xc7870 ldr r1, [pc, #0x254]
 *   @0xc7874 ldr r0, [pc, #0x254]
 *   @0xc7878 mov r2, #1
 *   @0xc787c mov r3, #0
 *   @0xc7880 ldr r1, [r4, r1]
 *   @0xc7884 add r0, pc, r0
 *   @0xc7888 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #22 buffer_get_size → F_BUFFER_Get_Size(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0xc788c ldr r1, [pc, #0x240]
 *   @0xc7890 ldr r0, [pc, #0x240]
 *   @0xc7894 mov r2, #1
 *   @0xc7898 mov r3, #0
 *   @0xc789c ldr r1, [r4, r1]
 *   @0xc78a0 add r0, pc, r0
 *   @0xc78a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #23 buffer_tell → F_BUFFER_Tell(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0xc78a8 ldr r1, [pc, #0x22c]
 *   @0xc78ac ldr r0, [pc, #0x22c]
 *   @0xc78b0 mov r2, #2
 *   @0xc78b4 mov r3, #0
 *   @0xc78b8 ldr r1, [r4, r1]
 *   @0xc78bc add r0, pc, r0
 *   @0xc78c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #24 buffer_resize → F_BUFFER_Resize(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0xc78c4 ldr r1, [pc, #0x218]
 *   @0xc78c8 ldr r0, [pc, #0x218]
 *   @0xc78cc mov r2, #3
 *   @0xc78d0 mov r3, #0
 *   @0xc78d4 ldr r1, [r4, r1]
 *   @0xc78d8 add r0, pc, r0
 *   @0xc78dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #25 buffer_md5 → F_BUFFER_MD5(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0xc78e0 ldr r1, [pc, #0x204]
 *   @0xc78e4 ldr r0, [pc, #0x204]
 *   @0xc78e8 mov r2, #3
 *   @0xc78ec mov r3, #0
 *   @0xc78f0 ldr r1, [r4, r1]
 *   @0xc78f4 add r0, pc, r0
 *   @0xc78f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #26 buffer_sha1 → F_BUFFER_SHA1(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0xc78fc ldr r1, [pc, #0x1f0]
 *   @0xc7900 ldr r0, [pc, #0x1f0]
 *   @0xc7904 mov r2, #3
 *   @0xc7908 mov r3, #0
 *   @0xc790c ldr r1, [r4, r1]
 *   @0xc7910 add r0, pc, r0
 *   @0xc7914 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #27 buffer_base64_encode → F_BUFFER_Base64_Encode(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0xc7918 ldr r1, [pc, #0x1dc]
 *   @0xc791c ldr r0, [pc, #0x1dc]
 *   @0xc7920 mov r2, #1
 *   @0xc7924 mov r3, #0
 *   @0xc7928 ldr r1, [r4, r1]
 *   @0xc792c add r0, pc, r0
 *   @0xc7930 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #28 buffer_base64_decode → F_BUFFER_Base64_Decode(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0xc7934 ldr r1, [pc, #0x1c8]
 *   @0xc7938 ldr r0, [pc, #0x1c8]
 *   @0xc793c mov r2, #3
 *   @0xc7940 mov r3, #0
 *   @0xc7944 ldr r1, [r4, r1]
 *   @0xc7948 add r0, pc, r0
 *   @0xc794c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #29 buffer_base64_decode_ext → F_BUFFER_Base64_Decode_Ext(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0xc7950 ldr r1, [pc, #0x1b4]
 *   @0xc7954 ldr r0, [pc, #0x1b4]
 *   @0xc7958 mov r2, #1
 *   @0xc795c mov r3, #0
 *   @0xc7960 ldr r1, [r4, r1]
 *   @0xc7964 add r0, pc, r0
 *   @0xc7968 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #30 buffer_sizeof → F_BUFFER_SizeOf(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0xc796c ldr r1, [pc, #0x1a0]
 *   @0xc7970 ldr r0, [pc, #0x1a0]
 *   @0xc7974 mov r2, #1
 *   @0xc7978 mov r3, #0
 *   @0xc797c ldr r1, [r4, r1]
 *   @0xc7980 add r0, pc, r0
 *   @0xc7984 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #31 buffer_get_address → F_BUFFER_GetAddress(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0xc7988 ldr r1, [pc, #0x18c]
 *   @0xc798c ldr r0, [pc, #0x18c]
 *   @0xc7990 mov r2, #5
 *   @0xc7994 mov r3, #0
 *   @0xc7998 ldr r1, [r4, r1]
 *   @0xc799c add r0, pc, r0
 *   @0xc79a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #32 buffer_get_surface → F_BUFFER_GetSurface(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0xc79a4 ldr r1, [pc, #0x178]
 *   @0xc79a8 ldr r0, [pc, #0x178]
 *   @0xc79ac mov r2, #5
 *   @0xc79b0 mov r3, #0
 *   @0xc79b4 ldr r1, [r4, r1]
 *   @0xc79b8 add r0, pc, r0
 *   @0xc79bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #33 buffer_set_surface → F_BUFFER_SetSurface(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0xc79c0 ldr r1, [pc, #0x164]
 *   @0xc79c4 ldr r0, [pc, #0x164]
 *   @0xc79c8 mov r2, #3
 *   @0xc79cc mov r3, #0
 *   @0xc79d0 ldr r1, [r4, r1]
 *   @0xc79d4 add r0, pc, r0
 *   @0xc79d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #34 buffer_create_from_vertex_buffer → F_BUFFER_Create_From_Vertex_Buffer(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0xc79dc ldr r1, [pc, #0x150]
 *   @0xc79e0 ldr r0, [pc, #0x150]
 *   @0xc79e4 mov r2, #5
 *   @0xc79e8 mov r3, #0
 *   @0xc79ec ldr r1, [r4, r1]
 *   @0xc79f0 add r0, pc, r0
 *   @0xc79f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #35 buffer_create_from_vertex_buffer_ext → F_BUFFER_Create_From_Vertex_Buffer_Ext(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0xc79f8 ldr r1, [pc, #0x13c]
 *   @0xc79fc ldr r0, [pc, #0x13c]
 *   @0xc7a00 mov r2, #5
 *   @0xc7a04 mov r3, #0
 *   @0xc7a08 ldr r1, [r4, r1]
 *   @0xc7a0c add r0, pc, r0
 *   @0xc7a10 pop {r4, lr}
 *   @0xc7a14 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #36 buffer_copy_from_vertex_buffer → F_BUFFER_Copy_From_Vertex_Buffer(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0xc7a18 eorseq r10, r2, r0, asr #12
 *   @0xc7a1c .word 0xffffbd98
 *   @0xc7a20 eoreq r9, r6, r0, asr #31
 *   @0xc7a24 .word 0xffffbd9c
 *   @0xc7a28 .word 0x00269fb4
 *   @0xc7a2c .word 0xffffbda0
 *   @0xc7a30 eoreq r9, r6, r8, lsr #31
 *   @0xc7a34 .word 0xffffbda4
 *   @0xc7a38 mlaeq r6, r12, pc, r9
 *   @0xc7a3c .word 0xffffbda8
 *   @0xc7a40 eoreq r9, r6, r12, lsl #31
 *   @0xc7a44 .word 0xffffbdac
 *   @0xc7a48 eoreq r9, r6, r12, ror pc
 *   @0xc7a4c .word 0xffffbdb0
 *   @0xc7a50 eoreq r9, r6, r12, ror #30
 *   @0xc7a54 .word 0xffffbdb4
 *   @0xc7a58 eoreq r9, r6, r12, asr pc
 *   @0xc7a5c .word 0xffffbdb8
 *   @0xc7a60 eoreq r9, r6, r12, asr #30
 *   @0xc7a64 .word 0xffffbdbc
 *   @0xc7a68 eoreq r9, r6, r0, asr #30
 *   @0xc7a6c .word 0xffffbdc0
 *   @0xc7a70 eoreq r9, r6, r0, lsr pc
 *   @0xc7a74 .word 0xffffbdc4
 *   @0xc7a78 eoreq r9, r6, r4, lsr #30
 *   @0xc7a7c .word 0xffffbdc8
 *   @0xc7a80 eoreq r9, r6, r12, lsl pc
 *   @0xc7a84 .word 0xffffbdcc
 *   @0xc7a88 eoreq r9, r6, r4, lsl pc
 *   @0xc7a8c .word 0xffffbdd0
 *   @0xc7a90 eoreq r9, r6, r12, lsl #30
 *   @0xc7a94 .word 0xffffbdd4
 *   @0xc7a98 eoreq r9, r6, r12, lsl #30
 *   @0xc7a9c .word 0xffffbdd8
 *   @0xc7aa0 eoreq r9, r6, r8, lsl #30
 *   @0xc7aa4 .word 0xffffbddc
 *   @0xc7aa8 eoreq r9, r6, r8, lsl #30
 *   @0xc7aac .word 0xffffbde0
 *   @0xc7ab0 .word 0x00269ef8
 *   @0xc7ab4 .word 0xffffbde4
 *   @0xc7ab8 eoreq r9, r6, r12, ror #29
 *   @0xc7abc .word 0xffffbde8
 *   @0xc7ac0 eoreq r9, r6, r0, ror #29
 *   @0xc7ac4 .word 0xffffbdec
 *   @0xc7ac8 .word 0x00269edc
 *   @0xc7acc .word 0xffffbdf0
 *   @0xc7ad0 eoreq r9, r6, r12, asr #29
 *   @0xc7ad4 .word 0xffffbdf4
 *   @0xc7ad8 eoreq r9, r6, r0, asr #29
 *   @0xc7adc .word 0xffffbdf8
 *   @0xc7ae0 .word 0x00269eb0
 *   @0xc7ae4 .word 0xffffbdfc
 *   @0xc7ae8 eoreq r9, r6, r4, lsr #29
 *   @0xc7aec .word 0xffffbe00
 *   @0xc7af0 mlaeq r6, r4, lr, r9
 *   @0xc7af4 .word 0xffffbe04
 *   @0xc7af8 eoreq r9, r6, r4, lsl #29
 *   @0xc7afc .word 0xffffbe08
 *   @0xc7b00 eoreq r9, r6, r0, lsl #29
 *   @0xc7b04 .word 0xffffbe0c
 *   @0xc7b08 eoreq r9, r6, r12, ror lr
 *   @0xc7b0c .word 0xffffbe10
 *   @0xc7b10 eoreq r9, r6, r12, ror lr
 *   @0xc7b14 .word 0xffffbe14
 *   @0xc7b18 eoreq r9, r6, r0, ror lr
 *   @0xc7b1c .word 0xffffbe18
 *   @0xc7b20 eoreq r9, r6, r8, ror #28
 *   @0xc7b24 .word 0xffffbe1c
 *   @0xc7b28 eoreq r9, r6, r0, ror #28
 *   @0xc7b2c .word 0xffffbe20
 *   @0xc7b30 eoreq r9, r6, r8, asr lr
 *   @0xc7b34 .word 0xffffbe24
 *   @0xc7b38 eoreq r9, r6, r0, ror #28
 *   @0xc7b3c .word 0xffffbe28
 *   @0xc7b40 eoreq r9, r6, r12, ror #28
 *
 * ══ §4/5 InitBufferVertexFunctions  0xca9a0..0xcacec  size 844  211 条（165 条指令 + 46 个池字）══
 * @func 0xca9a0 0xcacec  size 844  211 条
 * 注册 23 条｜唯一名 23｜唯一函数指针 22｜argc 0:1 1:6 2:4 3:6 4:4 5:2｜flag 0:23
 * 首条 #0 vertex_create_buffer（0xca9c4）→ 末条 #22 vertex_create_buffer_from_buffer_ext（0xcac30）
 * 名字族（前 8）: vertex×23
 * 游戏实际调用的 99 个内建里落在本表: 0 个
 * 表: asm/init-tables/init-InitBufferVertexFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: 无（本函数每条注册的四实参全部解出，控制流全部走到）
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xca9a0 push {r4, r5, r6, lr}
 *   @0xca9a4 mov r2, #0
 *   @0xca9a8 ldr r4, [pc, #0x284]
 *   @0xca9ac mov r3, r2
 *   @0xca9b0 ldr r1, [pc, #0x280]
 *   @0xca9b4 add r4, pc, r4
 *   @0xca9b8 ldr r0, [pc, #0x27c]
 *   @0xca9bc ldr r1, [r4, r1]
 *   @0xca9c0 add r0, pc, r0
 *   @0xca9c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 vertex_create_buffer → F_Vertex_Create_Buffer_debug(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0xca9c8 ldr r1, [pc, #0x270]
 *   @0xca9cc ldr r0, [pc, #0x270]
 *   @0xca9d0 mov r2, #1
 *   @0xca9d4 mov r3, #0
 *   @0xca9d8 ldr r1, [r4, r1]
 *   @0xca9dc add r0, pc, r0
 *   @0xca9e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 vertex_create_buffer_ext → F_Vertex_Create_Buffer_Ext_debug(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0xca9e4 ldr r1, [pc, #0x25c]
 *   @0xca9e8 ldr r0, [pc, #0x25c]
 *   @0xca9ec mov r2, #1
 *   @0xca9f0 mov r3, #0
 *   @0xca9f4 ldr r1, [r4, r1]
 *   @0xca9f8 add r0, pc, r0
 *   @0xca9fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 vertex_delete_buffer → F_Vertex_Delete_Buffer_debug(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0xcaa00 ldr r1, [pc, #0x248]
 *   @0xcaa04 ldr r0, [pc, #0x248]
 *   @0xcaa08 mov r2, #2
 *   @0xcaa0c mov r3, #0
 *   @0xcaa10 ldr r1, [r4, r1]
 *   @0xcaa14 add r0, pc, r0
 *   @0xcaa18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 vertex_begin → F_Vertex_Begin_debug(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0xcaa1c ldr r1, [pc, #0x234]
 *   @0xcaa20 ldr r0, [pc, #0x234]
 *   @0xcaa24 mov r2, #1
 *   @0xcaa28 mov r3, #0
 *   @0xcaa2c ldr r1, [r4, r1]
 *   @0xcaa30 add r0, pc, r0
 *   @0xcaa34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #4 vertex_end → F_Vertex_End_debug(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0xcaa38 ldr r1, [pc, #0x220]
 *   @0xcaa3c ldr r0, [pc, #0x220]
 *   @0xcaa40 mov r2, #3
 *   @0xcaa44 mov r3, #0
 *   @0xcaa48 ldr r1, [r4, r1]
 *   @0xcaa4c add r0, pc, r0
 *   @0xcaa50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #5 vertex_position → F_Vertex_Position_debug(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0xcaa54 ldr r1, [pc, #0x20c]
 *   @0xcaa58 ldr r0, [pc, #0x20c]
 *   @0xcaa5c mov r2, #4
 *   @0xcaa60 mov r3, #0
 *   @0xcaa64 ldr r1, [r4, r1]
 *   @0xcaa68 add r0, pc, r0
 *   @0xcaa6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #6 vertex_position_3d → F_Vertex_Position_3d_debug(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0xcaa70 ldr r1, [pc, #0x1f8]
 *   @0xcaa74 ldr r0, [pc, #0x1f8]
 *   @0xcaa78 mov r2, #3
 *   @0xcaa7c mov r3, #0
 *   @0xcaa80 ldr r5, [r4, r1]
 *   @0xcaa84 add r0, pc, r0
 *   @0xcaa88 mov r1, r5
 *   @0xcaa8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #7 vertex_colour → F_Vertex_Colour_debug(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0xcaa90 ldr r0, [pc, #0x1e0]
 *   @0xcaa94 mov r1, r5
 *   @0xcaa98 mov r2, #3
 *   @0xcaa9c add r0, pc, r0
 *   @0xcaaa0 mov r3, #0
 *   @0xcaaa4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #8 vertex_color → F_Vertex_Colour_debug(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0xcaaa8 ldr r1, [pc, #0x1cc]
 *   @0xcaaac ldr r0, [pc, #0x1cc]
 *   @0xcaab0 mov r2, #2
 *   @0xcaab4 mov r3, #0
 *   @0xcaab8 ldr r1, [r4, r1]
 *   @0xcaabc add r0, pc, r0
 *   @0xcaac0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #9 vertex_argb → F_Vertex_ARGB_debug(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0xcaac4 ldr r1, [pc, #0x1b8]
 *   @0xcaac8 ldr r0, [pc, #0x1b8]
 *   @0xcaacc mov r2, #3
 *   @0xcaad0 mov r3, #0
 *   @0xcaad4 ldr r1, [r4, r1]
 *   @0xcaad8 add r0, pc, r0
 *   @0xcaadc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #10 vertex_texcoord → F_Vertex_TexCoord_debug(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0xcaae0 ldr r1, [pc, #0x1a4]
 *   @0xcaae4 ldr r0, [pc, #0x1a4]
 *   @0xcaae8 mov r2, #4
 *   @0xcaaec mov r3, #0
 *   @0xcaaf0 ldr r1, [r4, r1]
 *   @0xcaaf4 add r0, pc, r0
 *   @0xcaaf8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #11 vertex_normal → F_Vertex_Normal_debug(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0xcaafc ldr r1, [pc, #0x190]
 *   @0xcab00 ldr r0, [pc, #0x190]
 *   @0xcab04 mov r2, #2
 *   @0xcab08 mov r3, #0
 *   @0xcab0c ldr r1, [r4, r1]
 *   @0xcab10 add r0, pc, r0
 *   @0xcab14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #12 vertex_float1 → F_Vertex_Float1_debug(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0xcab18 ldr r1, [pc, #0x17c]
 *   @0xcab1c ldr r0, [pc, #0x17c]
 *   @0xcab20 mov r2, #3
 *   @0xcab24 mov r3, #0
 *   @0xcab28 ldr r1, [r4, r1]
 *   @0xcab2c add r0, pc, r0
 *   @0xcab30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #13 vertex_float2 → F_Vertex_Float2_debug(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0xcab34 ldr r1, [pc, #0x168]
 *   @0xcab38 ldr r0, [pc, #0x168]
 *   @0xcab3c mov r2, #4
 *   @0xcab40 mov r3, #0
 *   @0xcab44 ldr r1, [r4, r1]
 *   @0xcab48 add r0, pc, r0
 *   @0xcab4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #14 vertex_float3 → F_Vertex_Float3_debug(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0xcab50 ldr r1, [pc, #0x154]
 *   @0xcab54 ldr r0, [pc, #0x154]
 *   @0xcab58 mov r2, #5
 *   @0xcab5c mov r3, #0
 *   @0xcab60 ldr r1, [r4, r1]
 *   @0xcab64 add r0, pc, r0
 *   @0xcab68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #15 vertex_float4 → F_Vertex_Float4_debug(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0xcab6c ldr r1, [pc, #0x140]
 *   @0xcab70 ldr r0, [pc, #0x140]
 *   @0xcab74 mov r2, #5
 *   @0xcab78 mov r3, #0
 *   @0xcab7c ldr r1, [r4, r1]
 *   @0xcab80 add r0, pc, r0
 *   @0xcab84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #16 vertex_ubyte4 → F_Vertex_ubyte4_debug(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0xcab88 ldr r1, [pc, #0x12c]
 *   @0xcab8c ldr r0, [pc, #0x12c]
 *   @0xcab90 mov r2, #3
 *   @0xcab94 mov r3, #0
 *   @0xcab98 ldr r1, [r4, r1]
 *   @0xcab9c add r0, pc, r0
 *   @0xcaba0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #17 vertex_submit → F_Vertex_Submit_debug(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0xcaba4 ldr r1, [pc, #0x118]
 *   @0xcaba8 ldr r0, [pc, #0x118]
 *   @0xcabac mov r2, #1
 *   @0xcabb0 mov r3, #0
 *   @0xcabb4 ldr r1, [r4, r1]
 *   @0xcabb8 add r0, pc, r0
 *   @0xcabbc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #18 vertex_freeze → F_Vertex_Freeze_debug(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0xcabc0 ldr r1, [pc, #0x104]
 *   @0xcabc4 ldr r0, [pc, #0x104]
 *   @0xcabc8 mov r2, #1
 *   @0xcabcc mov r3, #0
 *   @0xcabd0 ldr r1, [r4, r1]
 *   @0xcabd4 add r0, pc, r0
 *   @0xcabd8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #19 vertex_get_number → F_Vertex_Get_Number_debug(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0xcabdc ldr r1, [pc, #0xf0]
 *   @0xcabe0 ldr r0, [pc, #0xf0]
 *   @0xcabe4 mov r2, #1
 *   @0xcabe8 mov r3, #0
 *   @0xcabec ldr r1, [r4, r1]
 *   @0xcabf0 add r0, pc, r0
 *   @0xcabf4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #20 vertex_get_buffer_size → F_Vertex_Get_Buffer_Size(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0xcabf8 ldr r1, [pc, #0xdc]
 *   @0xcabfc ldr r0, [pc, #0xdc]
 *   @0xcac00 mov r2, #2
 *   @0xcac04 mov r3, #0
 *   @0xcac08 ldr r1, [r4, r1]
 *   @0xcac0c add r0, pc, r0
 *   @0xcac10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #21 vertex_create_buffer_from_buffer → F_Vertex_Create_Buffer_From_Buffer(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0xcac14 ldr r1, [pc, #0xc8]
 *   @0xcac18 ldr r0, [pc, #0xc8]
 *   @0xcac1c mov r2, #4
 *   @0xcac20 mov r3, #0
 *   @0xcac24 ldr r1, [r4, r1]
 *   @0xcac28 add r0, pc, r0
 *   @0xcac2c pop {r4, r5, r6, lr}
 *   @0xcac30 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #22 vertex_create_buffer_from_buffer_ext → F_Vertex_Create_Buffer_From_Buffer_Ext(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0xcac34 mlaseq r2, r12, r2, r7
 *   @0xcac38 .word 0xffffbe94
 *   @0xcac3c mlaeq r6, r4, r6, r7
 *   @0xcac40 .word 0xffffbe98
 *   @0xcac44 mlaeq r6, r0, r6, r7
 *   @0xcac48 .word 0xffffbe9c
 *   @0xcac4c mlaeq r6, r0, r6, r7
 *   @0xcac50 .word 0xffffbea0
 *   @0xcac54 eoreq r7, r6, r12, lsl #13
 *   @0xcac58 .word 0xffffbea4
 *   @0xcac5c eoreq r7, r6, r0, lsl #13
 *   @0xcac60 .word 0xffffbe60
 *   @0xcac64 eoreq r7, r6, r8, lsr #10
 *   @0xcac68 .word 0xffffbe64
 *   @0xcac6c eoreq r7, r6, r12, lsl r5
 *   @0xcac70 .word 0xffffbe68
 *   @0xcac74 eoreq r7, r6, r4, lsl r5
 *   @0xcac78 eoreq r7, r6, r12, lsl #10
 *   @0xcac7c .word 0xffffbe6c
 *   @0xcac80 .word 0x002674fc
 *   @0xcac84 .word 0xffffbe70
 *   @0xcac88 eoreq r7, r6, r12, ror #9
 *   @0xcac8c .word 0xffffbe74
 *   @0xcac90 eoreq r7, r6, r0, ror #9
 *   @0xcac94 .word 0xffffbe78
 *   @0xcac98 .word 0x002674d4
 *   @0xcac9c .word 0xffffbe7c
 *   @0xcaca0 eoreq r7, r6, r8, asr #9
 *   @0xcaca4 .word 0xffffbe80
 *   @0xcaca8 .word 0x002674bc
 *   @0xcacac .word 0xffffbe84
 *   @0xcacb0 .word 0x002674b0
 *   @0xcacb4 .word 0xffffbe88
 *   @0xcacb8 eoreq r7, r6, r4, lsr #9
 *   @0xcacbc .word 0xffffbe8c
 *   @0xcacc0 mlaeq r6, r8, r4, r7
 *   @0xcacc4 .word 0xffffbe90
 *   @0xcacc8 eoreq r7, r6, r12, lsl #9
 *   @0xcaccc .word 0xffffbea8
 *   @0xcacd0 eoreq r7, r6, r8, ror #9
 *   @0xcacd4 .word 0xffffbeac
 *   @0xcacd8 eoreq r7, r6, r0, ror #9
 *   @0xcacdc .word 0xffffbeb0
 *   @0xcace0 .word 0x002674dc
 *   @0xcace4 .word 0xffffbeb4
 *   @0xcace8 eoreq r7, r6, r4, ror #9
 *
 * ══ §5/5 InitShaderFunctions  0x1e2184..0x1e23d8  size 596  149 条（116 条指令 + 33 个池字）══
 * @func 0x1e2184 0x1e23d8  size 596  149 条
 * 注册 16 条｜唯一名 16｜唯一函数指针 16｜argc -1:2 0:2 1:6 2:6｜flag 0:16
 * 首条 #0 shader_set（0x1e21a8）→ 末条 #15 texture_get_texel_height（0x1e2350）
 * 名字族（前 8）: shader×12 texture×3 shaders×1
 * 游戏实际调用的 99 个内建里落在本表: 0 个
 * 表: asm/init-tables/init-InitShaderFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: 无（本函数每条注册的四实参全部解出，控制流全部走到）
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e2184 push {r4, lr}
 *   @0x1e2188 mov r2, #1
 *   @0x1e218c ldr r4, [pc, #0x1c0]
 *   @0x1e2190 mov r3, #0
 *   @0x1e2194 ldr r1, [pc, #0x1bc]
 *   @0x1e2198 add r4, pc, r4
 *   @0x1e219c ldr r0, [pc, #0x1b8]
 *   @0x1e21a0 ldr r1, [r4, r1]
 *   @0x1e21a4 add r0, pc, r0
 *   @0x1e21a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 shader_set → F_Shader_Set(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1e21ac ldr r1, [pc, #0x1ac]
 *   @0x1e21b0 ldr r0, [pc, #0x1ac]
 *   @0x1e21b4 mov r2, #1
 *   @0x1e21b8 mov r3, #0
 *   @0x1e21bc ldr r1, [r4, r1]
 *   @0x1e21c0 add r0, pc, r0
 *   @0x1e21c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 shader_reset → F_Shader_Reset(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1e21c8 ldr r1, [pc, #0x198]
 *   @0x1e21cc ldr r0, [pc, #0x198]
 *   @0x1e21d0 mov r2, #0
 *   @0x1e21d4 mov r3, r2
 *   @0x1e21d8 ldr r1, [r4, r1]
 *   @0x1e21dc add r0, pc, r0
 *   @0x1e21e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 shader_current → F_Shader_Current(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1e21e4 ldr r1, [pc, #0x184]
 *   @0x1e21e8 ldr r0, [pc, #0x184]
 *   @0x1e21ec mov r2, #2
 *   @0x1e21f0 mov r3, #0
 *   @0x1e21f4 ldr r1, [r4, r1]
 *   @0x1e21f8 add r0, pc, r0
 *   @0x1e21fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 shader_get_uniform → F_Shader_Get_Uniform(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1e2200 ldr r1, [pc, #0x170]
 *   @0x1e2204 ldr r0, [pc, #0x170]
 *   @0x1e2208 mov r2, #2
 *   @0x1e220c mov r3, #0
 *   @0x1e2210 ldr r1, [r4, r1]
 *   @0x1e2214 add r0, pc, r0
 *   @0x1e2218 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #4 shader_get_sampler_index → F_Shader_Get_Sampler_Index(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1e221c ldr r1, [pc, #0x15c]
 *   @0x1e2220 ldr r0, [pc, #0x15c]
 *   @0x1e2224 mvn r2, #0
 *   @0x1e2228 mov r3, #0
 *   @0x1e222c ldr r1, [r4, r1]
 *   @0x1e2230 add r0, pc, r0
 *   @0x1e2234 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #5 shader_set_uniform_i → F_Shader_Set_Uniform_I(RValue&, CInstance*, CInstance*, int, RValue*) argc=-1 flag=0
 *   @0x1e2238 ldr r1, [pc, #0x148]
 *   @0x1e223c ldr r0, [pc, #0x148]
 *   @0x1e2240 mov r2, #2
 *   @0x1e2244 mov r3, #0
 *   @0x1e2248 ldr r1, [r4, r1]
 *   @0x1e224c add r0, pc, r0
 *   @0x1e2250 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #6 shader_set_uniform_i_array → F_Shader_Set_Uniform_I_Array(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1e2254 ldr r1, [pc, #0x134]
 *   @0x1e2258 ldr r0, [pc, #0x134]
 *   @0x1e225c mvn r2, #0
 *   @0x1e2260 mov r3, #0
 *   @0x1e2264 ldr r1, [r4, r1]
 *   @0x1e2268 add r0, pc, r0
 *   @0x1e226c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #7 shader_set_uniform_f → F_Shader_Set_Uniform_F(RValue&, CInstance*, CInstance*, int, RValue*) argc=-1 flag=0
 *   @0x1e2270 ldr r1, [pc, #0x120]
 *   @0x1e2274 ldr r0, [pc, #0x120]
 *   @0x1e2278 mov r2, #2
 *   @0x1e227c mov r3, #0
 *   @0x1e2280 ldr r1, [r4, r1]
 *   @0x1e2284 add r0, pc, r0
 *   @0x1e2288 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #8 shader_set_uniform_f_array → F_Shader_Set_Uniform_F_Array(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1e228c ldr r1, [pc, #0x10c]
 *   @0x1e2290 ldr r0, [pc, #0x10c]
 *   @0x1e2294 mov r2, #1
 *   @0x1e2298 mov r3, #0
 *   @0x1e229c ldr r1, [r4, r1]
 *   @0x1e22a0 add r0, pc, r0
 *   @0x1e22a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #9 shader_set_uniform_matrix → F_Shader_Set_Uniform_Matrix(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1e22a8 ldr r1, [pc, #0xf8]
 *   @0x1e22ac ldr r0, [pc, #0xf8]
 *   @0x1e22b0 mov r2, #2
 *   @0x1e22b4 mov r3, #0
 *   @0x1e22b8 ldr r1, [r4, r1]
 *   @0x1e22bc add r0, pc, r0
 *   @0x1e22c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #10 shader_set_uniform_matrix_array → F_Shader_Set_Uniform_Matrix_Array(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1e22c4 ldr r1, [pc, #0xe4]
 *   @0x1e22c8 ldr r0, [pc, #0xe4]
 *   @0x1e22cc mov r2, #1
 *   @0x1e22d0 mov r3, #0
 *   @0x1e22d4 ldr r1, [r4, r1]
 *   @0x1e22d8 add r0, pc, r0
 *   @0x1e22dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #11 shader_is_compiled → F_Shader_Is_Compiled(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1e22e0 ldr r1, [pc, #0xd0]
 *   @0x1e22e4 ldr r0, [pc, #0xd0]
 *   @0x1e22e8 mov r2, #0
 *   @0x1e22ec mov r3, r2
 *   @0x1e22f0 ldr r1, [r4, r1]
 *   @0x1e22f4 add r0, pc, r0
 *   @0x1e22f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #12 shaders_are_supported → F_Shaders_Are_Supported(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1e22fc ldr r1, [pc, #0xbc]
 *   @0x1e2300 ldr r0, [pc, #0xbc]
 *   @0x1e2304 mov r2, #2
 *   @0x1e2308 mov r3, #0
 *   @0x1e230c ldr r1, [r4, r1]
 *   @0x1e2310 add r0, pc, r0
 *   @0x1e2314 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #13 texture_set_stage → F_Shader_Set_Texture(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1e2318 ldr r1, [pc, #0xa8]
 *   @0x1e231c ldr r0, [pc, #0xa8]
 *   @0x1e2320 mov r2, #1
 *   @0x1e2324 mov r3, #0
 *   @0x1e2328 ldr r1, [r4, r1]
 *   @0x1e232c add r0, pc, r0
 *   @0x1e2330 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #14 texture_get_texel_width → F_Texture_Get_Texel_Width(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1e2334 ldr r1, [pc, #0x94]
 *   @0x1e2338 ldr r0, [pc, #0x94]
 *   @0x1e233c mov r2, #1
 *   @0x1e2340 mov r3, #0
 *   @0x1e2344 ldr r1, [r4, r1]
 *   @0x1e2348 add r0, pc, r0
 *   @0x1e234c pop {r4, lr}
 *   @0x1e2350 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #15 texture_get_texel_height → F_Texture_Get_Texel_Height(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1e2354 .word 0x0020fab8
 *   @0x1e2358 .word 0xfffff100
 *   @0x1e235c andseq pc, r6, r4, lsr #25
 *   @0x1e2360 .word 0xfffff104
 *   @0x1e2364 mulseq r6, r4, r12
 *   @0x1e2368 .word 0xfffff108
 *   @0x1e236c andseq pc, r6, r8, lsl #25
 *   @0x1e2370 .word 0xfffff10c
 *   @0x1e2374 andseq pc, r6, r12, ror r12
 *   @0x1e2378 .word 0xfffff110
 *   @0x1e237c andseq pc, r6, r4, ror r12
 *   @0x1e2380 .word 0xfffff114
 *   @0x1e2384 andseq pc, r6, r4, ror r12
 *   @0x1e2388 .word 0xfffff118
 *   @0x1e238c andseq pc, r6, r0, ror r12
 *   @0x1e2390 .word 0xfffff11c
 *   @0x1e2394 andseq pc, r6, r0, ror r12
 *   @0x1e2398 .word 0xfffff120
 *   @0x1e239c andseq pc, r6, r12, ror #24
 *   @0x1e23a0 .word 0xfffff124
 *   @0x1e23a4 andseq pc, r6, r12, ror #24
 *   @0x1e23a8 .word 0xfffff128
 *   @0x1e23ac andseq pc, r6, r12, ror #24
 *   @0x1e23b0 .word 0xfffff12c
 *   @0x1e23b4 andseq pc, r6, r0, ror r12
 *   @0x1e23b8 .word 0xfffff130
 *   @0x1e23bc andseq pc, r6, r8, ror #24
 *   @0x1e23c0 .word 0xfffff134
 *   @0x1e23c4 andseq pc, r6, r4, ror #24
 *   @0x1e23c8 .word 0xfffff138
 *   @0x1e23cc andseq pc, r6, r12, asr r12
 *   @0x1e23d0 .word 0xfffff13c
 *   @0x1e23d4 andseq pc, r6, r8, asr r12
 */
