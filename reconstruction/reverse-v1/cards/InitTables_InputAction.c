/* cally 逆向卡：InitTables_InputAction —— Init*Functions 的 GML 内建注册表（原版 libyoyo.so，armv7）
 * 本卡 6 节，逐节一个 @func；锚点来自 asm/instructions.jsonl（census），
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
 * 本卡节: §1 InitInteractionFunctions 0x1278c4→108 条｜§2 InitActionFunctions 0x141e60→136 条｜§3 InitGamepadFunctions 0x152c9c→21 条｜§4 InitMetroFunctions 0x128b58→35 条｜§5 InitPushFunctions 0x155ea0→4 条｜§6 InitIAPFunctions 0x1534d4→15 条
 *
 * ══ §1/6 InitInteractionFunctions  0x1278c4..0x128884  size 4032  1008 条（787 条指令 + 221 个池字）══
 * @func 0x1278c4 0x128884  size 4032  1008 条
 * 注册 108 条｜唯一名 108｜唯一函数指针 108｜argc 0:12 1:58 2:23 3:5 4:9 7:1｜flag 0:75 1:19 ?:14
 * 首条 #0 splash_set_caption（0x12792c）→ 末条 #107 joystick_pov（0x128508）
 * 名字族（前 8）: splash×16 joystick×14 keyboard×13 show×12 highscore×12 get×12 message×11 mouse×7
 * 游戏实际调用的 99 个内建里落在本表: 3 个（device_mouse_dbclick_enable, mouse_check_button_pressed, mouse_clear）
 * 条件跳转 1 处: 0x128200(beq)
 * 表: asm/init-tables/init-InitInteractionFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: #94@0x12839c(joystick_exists), #95@0x1283b8(joystick_direction), #96@0x1283d4(joystick_name), #97@0x1283f0(joystick_axes), #98@0x12840c(joystick_buttons), #99@0x128428(joystick_has_pov), #100@0x128444(joystick_check_button), #101@0x128460(joystick_xpos), #102@0x12847c(joystick_ypos), #103@0x128498(joystick_zpos), #104@0x1284b4(joystick_rpos), #105@0x1284d0(joystick_upos) 等 14 条 —— 实参来自运行期全局值或共享尾未解，本卡不猜
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1278c4 push {r4, r5, r6, lr}
 *   @0x1278c8 ldr r4, [pc, #0xc40]
 *   @0x1278cc ldr r3, [pc, #0xc40]
 *   @0x1278d0 add r4, pc, r4
 *   @0x1278d4 ldr r5, [r4, r3]
 *   @0x1278d8 ldr r0, [r5]
 *   @0x1278dc bl 0xb6538 <strlen@plt>   —— 调用 0xb6538
 *   @0x1278e0 mov r3, #1
 *   @0x1278e4 ldr r1, [pc, #0xc2c]
 *   @0x1278e8 movw r2, #0x6e8
 *   @0x1278ec add r1, pc, r1
 *   @0x1278f0 add r6, r0, r3
 *   @0x1278f4 mov r0, r6
 *   @0x1278f8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>   —— 调用 MemoryManager::Alloc(unsigned int, char const*, int, bool)
 *   @0x1278fc ldr r3, [pc, #0xc18]
 *   @0x127900 mov r2, r6
 *   @0x127904 ldr r1, [r5]
 *   @0x127908 ldr r3, [r4, r3]
 *   @0x12790c str r0, [r3]
 *   @0x127910 bl 0xb65bc <memcpy@plt>   —— 调用 0xb65bc
 *   @0x127914 ldr r1, [pc, #0xc04]
 *   @0x127918 mov r2, #1
 *   @0x12791c ldr r0, [pc, #0xc00]
 *   @0x127920 mov r3, r2
 *   @0x127924 add r0, pc, r0
 *   @0x127928 ldr r1, [r4, r1]
 *   @0x12792c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 splash_set_caption → F_SplashSetCaption(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x127930 ldr r1, [pc, #0xbf0]
 *   @0x127934 ldr r0, [pc, #0xbf0]
 *   @0x127938 mov r2, #1
 *   @0x12793c mov r3, r2
 *   @0x127940 add r0, pc, r0
 *   @0x127944 ldr r1, [r4, r1]
 *   @0x127948 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 splash_set_fullscreen → F_SplashSetFullscreen(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x12794c ldr r1, [pc, #0xbdc]
 *   @0x127950 ldr r0, [pc, #0xbdc]
 *   @0x127954 mov r2, #1
 *   @0x127958 mov r3, r2
 *   @0x12795c add r0, pc, r0
 *   @0x127960 ldr r1, [r4, r1]
 *   @0x127964 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 splash_set_border → F_SplashSetBorder(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x127968 ldr r1, [pc, #0xbc8]
 *   @0x12796c ldr r0, [pc, #0xbc8]
 *   @0x127970 mov r2, #2
 *   @0x127974 mov r3, #1
 *   @0x127978 add r0, pc, r0
 *   @0x12797c ldr r1, [r4, r1]
 *   @0x127980 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 splash_set_size → F_SplashSetSize(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x127984 ldr r1, [pc, #0xbb4]
 *   @0x127988 ldr r0, [pc, #0xbb4]
 *   @0x12798c mov r2, #1
 *   @0x127990 mov r3, r2
 *   @0x127994 add r0, pc, r0
 *   @0x127998 ldr r1, [r4, r1]
 *   @0x12799c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #4 splash_set_adapt → F_SplashSetAdapt(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1279a0 ldr r1, [pc, #0xba0]
 *   @0x1279a4 ldr r0, [pc, #0xba0]
 *   @0x1279a8 mov r2, #1
 *   @0x1279ac mov r3, r2
 *   @0x1279b0 add r0, pc, r0
 *   @0x1279b4 ldr r1, [r4, r1]
 *   @0x1279b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #5 splash_set_top → F_SplashSetTop(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1279bc ldr r1, [pc, #0xb8c]
 *   @0x1279c0 ldr r0, [pc, #0xb8c]
 *   @0x1279c4 mov r2, #1
 *   @0x1279c8 mov r3, r2
 *   @0x1279cc add r0, pc, r0
 *   @0x1279d0 ldr r1, [r4, r1]
 *   @0x1279d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #6 splash_set_color → F_SplashSetColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1279d8 ldr r1, [pc, #0xb78]
 *   @0x1279dc ldr r0, [pc, #0xb78]
 *   @0x1279e0 mov r2, #1
 *   @0x1279e4 mov r3, r2
 *   @0x1279e8 add r0, pc, r0
 *   @0x1279ec ldr r1, [r4, r1]
 *   @0x1279f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #7 splash_set_main → F_SplashSetMain(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1279f4 ldr r1, [pc, #0xb64]
 *   @0x1279f8 ldr r0, [pc, #0xb64]
 *   @0x1279fc mov r2, #1
 *   @0x127a00 mov r3, r2
 *   @0x127a04 add r0, pc, r0
 *   @0x127a08 ldr r1, [r4, r1]
 *   @0x127a0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #8 splash_set_scale → F_SplashSetScale(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x127a10 ldr r1, [pc, #0xb50]
 *   @0x127a14 ldr r0, [pc, #0xb50]
 *   @0x127a18 mov r2, #1
 *   @0x127a1c mov r3, r2
 *   @0x127a20 add r0, pc, r0
 *   @0x127a24 ldr r1, [r4, r1]
 *   @0x127a28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #9 splash_set_cursor → F_SplashSetCursor(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x127a2c ldr r1, [pc, #0xb3c]
 *   @0x127a30 ldr r0, [pc, #0xb3c]
 *   @0x127a34 mov r2, #1
 *   @0x127a38 mov r3, r2
 *   @0x127a3c add r0, pc, r0
 *   @0x127a40 ldr r1, [r4, r1]
 *   @0x127a44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #10 splash_set_interrupt → F_SplashSetInterrupt(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x127a48 ldr r1, [pc, #0xb28]
 *   @0x127a4c ldr r0, [pc, #0xb28]
 *   @0x127a50 mov r2, #1
 *   @0x127a54 mov r3, r2
 *   @0x127a58 add r0, pc, r0
 *   @0x127a5c ldr r1, [r4, r1]
 *   @0x127a60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #11 splash_set_stop_key → F_SplashSetStopKey(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x127a64 ldr r1, [pc, #0xb14]
 *   @0x127a68 ldr r0, [pc, #0xb14]
 *   @0x127a6c mov r2, #1
 *   @0x127a70 mov r3, r2
 *   @0x127a74 add r0, pc, r0
 *   @0x127a78 ldr r1, [r4, r1]
 *   @0x127a7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #12 splash_set_stop_mouse → F_SplashSetStopMouse(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x127a80 ldr r1, [pc, #0xb00]
 *   @0x127a84 ldr r0, [pc, #0xb00]
 *   @0x127a88 mov r2, #2
 *   @0x127a8c mov r3, #1
 *   @0x127a90 add r0, pc, r0
 *   @0x127a94 ldr r1, [r4, r1]
 *   @0x127a98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #13 splash_show_video → F_SplashShowVideo(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x127a9c ldr r1, [pc, #0xaec]
 *   @0x127aa0 ldr r0, [pc, #0xaec]
 *   @0x127aa4 mov r2, #2
 *   @0x127aa8 mov r3, #1
 *   @0x127aac add r0, pc, r0
 *   @0x127ab0 ldr r1, [r4, r1]
 *   @0x127ab4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #14 splash_show_image → F_SplashShowImage(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x127ab8 ldr r1, [pc, #0xad8]
 *   @0x127abc ldr r0, [pc, #0xad8]
 *   @0x127ac0 mov r2, #2
 *   @0x127ac4 mov r3, #1
 *   @0x127ac8 add r0, pc, r0
 *   @0x127acc ldr r1, [r4, r1]
 *   @0x127ad0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #15 splash_show_text → F_SplashShowText(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x127ad4 ldr r1, [pc, #0xac4]
 *   @0x127ad8 ldr r0, [pc, #0xac4]
 *   @0x127adc mov r2, #3
 *   @0x127ae0 mov r3, #1
 *   @0x127ae4 add r0, pc, r0
 *   @0x127ae8 ldr r1, [r4, r1]
 *   @0x127aec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #16 show_image → F_ShowImage(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x127af0 ldr r1, [pc, #0xab0]
 *   @0x127af4 ldr r0, [pc, #0xab0]
 *   @0x127af8 mov r2, #3
 *   @0x127afc mov r3, #1
 *   @0x127b00 add r0, pc, r0
 *   @0x127b04 ldr r1, [r4, r1]
 *   @0x127b08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #17 show_video → F_ShowVideo(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x127b0c ldr r1, [pc, #0xa9c]
 *   @0x127b10 ldr r0, [pc, #0xa9c]
 *   @0x127b14 mov r2, #4
 *   @0x127b18 mov r3, #1
 *   @0x127b1c add r0, pc, r0
 *   @0x127b20 ldr r1, [r4, r1]
 *   @0x127b24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #18 show_text → F_ShowText(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x127b28 ldr r1, [pc, #0xa88]
 *   @0x127b2c ldr r0, [pc, #0xa88]
 *   @0x127b30 mov r2, #1
 *   @0x127b34 mov r3, #0
 *   @0x127b38 add r0, pc, r0
 *   @0x127b3c ldr r1, [r4, r1]
 *   @0x127b40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #19 show_message → F_ShowMessage(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x127b44 ldr r1, [pc, #0xa74]
 *   @0x127b48 ldr r0, [pc, #0xa74]
 *   @0x127b4c mov r2, #1
 *   @0x127b50 mov r3, #0
 *   @0x127b54 add r0, pc, r0
 *   @0x127b58 ldr r1, [r4, r1]
 *   @0x127b5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #20 show_question → F_ShowQuestion(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x127b60 ldr r1, [pc, #0xa60]
 *   @0x127b64 ldr r0, [pc, #0xa60]
 *   @0x127b68 mov r2, #1
 *   @0x127b6c mov r3, #0
 *   @0x127b70 add r0, pc, r0
 *   @0x127b74 ldr r1, [r4, r1]
 *   @0x127b78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #21 show_message_async → F_ShowMessageASync(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x127b7c ldr r1, [pc, #0xa4c]
 *   @0x127b80 ldr r0, [pc, #0xa4c]
 *   @0x127b84 mov r2, #1
 *   @0x127b88 mov r3, #0
 *   @0x127b8c add r0, pc, r0
 *   @0x127b90 ldr r1, [r4, r1]
 *   @0x127b94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #22 show_question_async → F_ShowQuestionASync(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x127b98 ldr r1, [pc, #0xa38]
 *   @0x127b9c ldr r0, [pc, #0xa38]
 *   @0x127ba0 mov r2, #2
 *   @0x127ba4 mov r3, #0
 *   @0x127ba8 add r0, pc, r0
 *   @0x127bac ldr r1, [r4, r1]
 *   @0x127bb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #23 show_error → F_ShowError(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x127bb4 ldr r1, [pc, #0xa24]
 *   @0x127bb8 ldr r0, [pc, #0xa24]
 *   @0x127bbc mov r2, #0
 *   @0x127bc0 mov r3, r2
 *   @0x127bc4 add r0, pc, r0
 *   @0x127bc8 ldr r1, [r4, r1]
 *   @0x127bcc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #24 show_info → F_ShowInfo(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x127bd0 ldr r1, [pc, #0xa10]
 *   @0x127bd4 ldr r0, [pc, #0xa10]
 *   @0x127bd8 mov r2, #1
 *   @0x127bdc mov r3, #0
 *   @0x127be0 add r0, pc, r0
 *   @0x127be4 ldr r1, [r4, r1]
 *   @0x127be8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #25 load_info → F_LoadInfo(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x127bec ldr r1, [pc, #0x9fc]
 *   @0x127bf0 ldr r0, [pc, #0x9fc]
 *   @0x127bf4 mov r2, #1
 *   @0x127bf8 mov r3, #0
 *   @0x127bfc add r0, pc, r0
 *   @0x127c00 ldr r1, [r4, r1]
 *   @0x127c04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #26 highscore_show → F_HighscoreShow(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x127c08 ldr r1, [pc, #0x9e8]
 *   @0x127c0c ldr r0, [pc, #0x9e8]
 *   @0x127c10 mov r2, #1
 *   @0x127c14 mov r3, #0
 *   @0x127c18 add r0, pc, r0
 *   @0x127c1c ldr r1, [r4, r1]
 *   @0x127c20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #27 highscore_set_background → F_HighscoreSetBackground(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x127c24 ldr r1, [pc, #0x9d4]
 *   @0x127c28 ldr r0, [pc, #0x9d4]
 *   @0x127c2c mov r2, #1
 *   @0x127c30 mov r3, #0
 *   @0x127c34 add r0, pc, r0
 *   @0x127c38 ldr r1, [r4, r1]
 *   @0x127c3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #28 highscore_set_border → F_HighscoreSetBorder(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x127c40 ldr r1, [pc, #0x9c0]
 *   @0x127c44 ldr r0, [pc, #0x9c0]
 *   @0x127c48 mov r2, #3
 *   @0x127c4c mov r3, #0
 *   @0x127c50 add r0, pc, r0
 *   @0x127c54 ldr r1, [r4, r1]
 *   @0x127c58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #29 highscore_set_font → F_HighscoreSetFont(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x127c5c ldr r1, [pc, #0x9ac]
 *   @0x127c60 ldr r0, [pc, #0x9ac]
 *   @0x127c64 mov r2, #3
 *   @0x127c68 mov r3, #0
 *   @0x127c6c add r0, pc, r0
 *   @0x127c70 ldr r1, [r4, r1]
 *   @0x127c74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #30 highscore_set_strings → F_HighscoreSetStrings(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x127c78 ldr r1, [pc, #0x998]
 *   @0x127c7c ldr r0, [pc, #0x998]
 *   @0x127c80 mov r2, #3
 *   @0x127c84 mov r3, #0
 *   @0x127c88 add r0, pc, r0
 *   @0x127c8c ldr r1, [r4, r1]
 *   @0x127c90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #31 highscore_set_colors → F_HighscoreSetColors(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x127c94 ldr r1, [pc, #0x984]
 *   @0x127c98 ldr r0, [pc, #0x984]
 *   @0x127c9c mov r2, #7
 *   @0x127ca0 mov r3, #0
 *   @0x127ca4 add r0, pc, r0
 *   @0x127ca8 ldr r1, [r4, r1]
 *   @0x127cac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #32 highscore_show_ext → F_HighscoreShowExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=0
 *   @0x127cb0 ldr r1, [pc, #0x970]
 *   @0x127cb4 ldr r0, [pc, #0x970]
 *   @0x127cb8 mov r2, #0
 *   @0x127cbc mov r3, r2
 *   @0x127cc0 add r0, pc, r0
 *   @0x127cc4 ldr r1, [r4, r1]
 *   @0x127cc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #33 highscore_clear → F_HighscoreClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x127ccc ldr r1, [pc, #0x95c]
 *   @0x127cd0 ldr r0, [pc, #0x95c]
 *   @0x127cd4 mov r2, #2
 *   @0x127cd8 mov r3, #0
 *   @0x127cdc add r0, pc, r0
 *   @0x127ce0 ldr r1, [r4, r1]
 *   @0x127ce4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #34 highscore_add → F_HighscoreAdd(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x127ce8 ldr r1, [pc, #0x948]
 *   @0x127cec ldr r0, [pc, #0x948]
 *   @0x127cf0 mov r2, #0
 *   @0x127cf4 mov r3, r2
 *   @0x127cf8 add r0, pc, r0
 *   @0x127cfc ldr r1, [r4, r1]
 *   @0x127d00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #35 highscore_add_current → F_HighscoreAddCurrent(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x127d04 ldr r1, [pc, #0x934]
 *   @0x127d08 ldr r0, [pc, #0x934]
 *   @0x127d0c mov r2, #1
 *   @0x127d10 mov r3, #0
 *   @0x127d14 add r0, pc, r0
 *   @0x127d18 ldr r1, [r4, r1]
 *   @0x127d1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #36 highscore_value → F_HighscoreValue(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x127d20 ldr r1, [pc, #0x920]
 *   @0x127d24 ldr r0, [pc, #0x920]
 *   @0x127d28 mov r2, #1
 *   @0x127d2c mov r3, #0
 *   @0x127d30 add r0, pc, r0
 *   @0x127d34 ldr r1, [r4, r1]
 *   @0x127d38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #37 highscore_name → F_HighscoreName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x127d3c ldr r1, [pc, #0x90c]
 *   @0x127d40 ldr r0, [pc, #0x90c]
 *   @0x127d44 mov r2, #4
 *   @0x127d48 mov r3, #0
 *   @0x127d4c add r0, pc, r0
 *   @0x127d50 ldr r1, [r4, r1]
 *   @0x127d54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #38 draw_highscore → F_DrawHighscore(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x127d58 ldr r1, [pc, #0x8f8]
 *   @0x127d5c ldr r0, [pc, #0x8f8]
 *   @0x127d60 mov r2, #4
 *   @0x127d64 mov r3, #0
 *   @0x127d68 add r0, pc, r0
 *   @0x127d6c ldr r1, [r4, r1]
 *   @0x127d70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #39 show_message_ext → F_ShowMessageExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x127d74 ldr r1, [pc, #0x8e4]
 *   @0x127d78 ldr r0, [pc, #0x8e4]
 *   @0x127d7c mov r2, #1
 *   @0x127d80 mov r3, #0
 *   @0x127d84 add r0, pc, r0
 *   @0x127d88 ldr r1, [r4, r1]
 *   @0x127d8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #40 message_background → F_MessageBackground(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x127d90 ldr r1, [pc, #0x8d0]
 *   @0x127d94 ldr r0, [pc, #0x8d0]
 *   @0x127d98 mov r2, #1
 *   @0x127d9c mov r3, #0
 *   @0x127da0 add r0, pc, r0
 *   @0x127da4 ldr r1, [r4, r1]
 *   @0x127da8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #41 message_button → F_MessageButton(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x127dac ldr r1, [pc, #0x8bc]
 *   @0x127db0 ldr r0, [pc, #0x8bc]
 *   @0x127db4 mov r2, #1
 *   @0x127db8 mov r3, #0
 *   @0x127dbc add r0, pc, r0
 *   @0x127dc0 ldr r1, [r4, r1]
 *   @0x127dc4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #42 message_alpha → F_MessageAlpha(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x127dc8 ldr r1, [pc, #0x8a8]
 *   @0x127dcc ldr r0, [pc, #0x8a8]
 *   @0x127dd0 mov r2, #4
 *   @0x127dd4 mov r3, #0
 *   @0x127dd8 add r0, pc, r0
 *   @0x127ddc ldr r1, [r4, r1]
 *   @0x127de0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #43 message_text_font → F_MessageTextFont(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x127de4 ldr r1, [pc, #0x894]
 *   @0x127de8 ldr r0, [pc, #0x894]
 *   @0x127dec mov r2, #4
 *   @0x127df0 mov r3, #0
 *   @0x127df4 add r0, pc, r0
 *   @0x127df8 ldr r1, [r4, r1]
 *   @0x127dfc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #44 message_button_font → F_MessageButtonFont(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x127e00 ldr r1, [pc, #0x880]
 *   @0x127e04 ldr r0, [pc, #0x880]
 *   @0x127e08 mov r2, #4
 *   @0x127e0c mov r3, #0
 *   @0x127e10 add r0, pc, r0
 *   @0x127e14 ldr r1, [r4, r1]
 *   @0x127e18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #45 message_input_font → F_MessageInputFont(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x127e1c ldr r1, [pc, #0x86c]
 *   @0x127e20 ldr r0, [pc, #0x86c]
 *   @0x127e24 mov r2, #1
 *   @0x127e28 mov r3, #0
 *   @0x127e2c add r0, pc, r0
 *   @0x127e30 ldr r1, [r4, r1]
 *   @0x127e34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #46 message_mouse_color → F_MessageMouseColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x127e38 ldr r1, [pc, #0x858]
 *   @0x127e3c ldr r0, [pc, #0x858]
 *   @0x127e40 mov r2, #1
 *   @0x127e44 mov r3, #0
 *   @0x127e48 add r0, pc, r0
 *   @0x127e4c ldr r1, [r4, r1]
 *   @0x127e50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #47 message_input_color → F_MessageInputColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x127e54 ldr r1, [pc, #0x844]
 *   @0x127e58 ldr r0, [pc, #0x844]
 *   @0x127e5c mov r2, #2
 *   @0x127e60 mov r3, #0
 *   @0x127e64 add r0, pc, r0
 *   @0x127e68 ldr r1, [r4, r1]
 *   @0x127e6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #48 message_position → F_MessagePosition(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x127e70 ldr r1, [pc, #0x830]
 *   @0x127e74 ldr r0, [pc, #0x830]
 *   @0x127e78 mov r2, #2
 *   @0x127e7c mov r3, #0
 *   @0x127e80 add r0, pc, r0
 *   @0x127e84 ldr r1, [r4, r1]
 *   @0x127e88 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #49 message_size → F_MessageSize(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x127e8c ldr r1, [pc, #0x81c]
 *   @0x127e90 ldr r0, [pc, #0x81c]
 *   @0x127e94 mov r2, #2
 *   @0x127e98 mov r3, #0
 *   @0x127e9c add r0, pc, r0
 *   @0x127ea0 ldr r1, [r4, r1]
 *   @0x127ea4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #50 message_caption → F_MessageCaption(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x127ea8 ldr r1, [pc, #0x808]
 *   @0x127eac ldr r0, [pc, #0x808]
 *   @0x127eb0 mov r2, #2
 *   @0x127eb4 mov r3, #0
 *   @0x127eb8 add r0, pc, r0
 *   @0x127ebc ldr r1, [r4, r1]
 *   @0x127ec0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #51 show_menu → F_ShowMenu(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x127ec4 ldr r1, [pc, #0x7f4]
 *   @0x127ec8 ldr r0, [pc, #0x7f4]
 *   @0x127ecc mov r2, #4
 *   @0x127ed0 mov r3, #0
 *   @0x127ed4 add r0, pc, r0
 *   @0x127ed8 ldr r1, [r4, r1]
 *   @0x127edc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #52 show_menu_pos → F_ShowMenuPos(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x127ee0 ldr r1, [pc, #0x7e0]
 *   @0x127ee4 ldr r0, [pc, #0x7e0]
 *   @0x127ee8 mov r2, #2
 *   @0x127eec mov r3, #0
 *   @0x127ef0 add r0, pc, r0
 *   @0x127ef4 ldr r1, [r4, r1]
 *   @0x127ef8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #53 get_integer → F_GetInteger(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x127efc ldr r1, [pc, #0x7cc]
 *   @0x127f00 ldr r0, [pc, #0x7cc]
 *   @0x127f04 mov r2, #2
 *   @0x127f08 mov r3, #0
 *   @0x127f0c add r0, pc, r0
 *   @0x127f10 ldr r1, [r4, r1]
 *   @0x127f14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #54 get_integer_async → F_GetIntegerAsync(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x127f18 ldr r1, [pc, #0x7b8]
 *   @0x127f1c ldr r0, [pc, #0x7b8]
 *   @0x127f20 mov r2, #2
 *   @0x127f24 mov r3, #0
 *   @0x127f28 add r0, pc, r0
 *   @0x127f2c ldr r1, [r4, r1]
 *   @0x127f30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #55 get_string → F_GetString(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x127f34 ldr r1, [pc, #0x7a4]
 *   @0x127f38 ldr r0, [pc, #0x7a4]
 *   @0x127f3c mov r2, #2
 *   @0x127f40 mov r3, #0
 *   @0x127f44 add r0, pc, r0
 *   @0x127f48 ldr r1, [r4, r1]
 *   @0x127f4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #56 get_string_async → F_GetStringAsync(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x127f50 ldr r1, [pc, #0x790]
 *   @0x127f54 ldr r0, [pc, #0x790]
 *   @0x127f58 mov r2, #2
 *   @0x127f5c mov r3, #0
 *   @0x127f60 add r0, pc, r0
 *   @0x127f64 ldr r1, [r4, r1]
 *   @0x127f68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #57 get_login_async → F_GetLoginAsync(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x127f6c ldr r1, [pc, #0x77c]
 *   @0x127f70 ldr r0, [pc, #0x77c]
 *   @0x127f74 mov r2, #1
 *   @0x127f78 mov r3, #0
 *   @0x127f7c add r0, pc, r0
 *   @0x127f80 ldr r1, [r4, r1]
 *   @0x127f84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #58 get_color → F_GetColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x127f88 ldr r1, [pc, #0x768]
 *   @0x127f8c ldr r0, [pc, #0x768]
 *   @0x127f90 mov r2, #2
 *   @0x127f94 mov r3, #0
 *   @0x127f98 add r0, pc, r0
 *   @0x127f9c ldr r1, [r4, r1]
 *   @0x127fa0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #59 get_open_filename → F_GetOpenFileName(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x127fa4 ldr r1, [pc, #0x754]
 *   @0x127fa8 ldr r0, [pc, #0x754]
 *   @0x127fac mov r2, #2
 *   @0x127fb0 mov r3, #0
 *   @0x127fb4 add r0, pc, r0
 *   @0x127fb8 ldr r1, [r4, r1]
 *   @0x127fbc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #60 get_save_filename → F_GetSaveFileName(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x127fc0 ldr r1, [pc, #0x740]
 *   @0x127fc4 ldr r0, [pc, #0x740]
 *   @0x127fc8 mov r2, #4
 *   @0x127fcc mov r3, #0
 *   @0x127fd0 add r0, pc, r0
 *   @0x127fd4 ldr r1, [r4, r1]
 *   @0x127fd8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #61 get_open_filename_ext → F_GetOpenFileNameExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x127fdc ldr r1, [pc, #0x72c]
 *   @0x127fe0 ldr r0, [pc, #0x72c]
 *   @0x127fe4 mov r2, #4
 *   @0x127fe8 mov r3, #0
 *   @0x127fec add r0, pc, r0
 *   @0x127ff0 ldr r1, [r4, r1]
 *   @0x127ff4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #62 get_save_filename_ext → F_GetSaveFileNameExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x127ff8 ldr r1, [pc, #0x718]
 *   @0x127ffc ldr r0, [pc, #0x718]
 *   @0x128000 mov r2, #1
 *   @0x128004 mov r3, #0
 *   @0x128008 add r0, pc, r0
 *   @0x12800c ldr r1, [r4, r1]
 *   @0x128010 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #63 get_directory → F_GetDirectory(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x128014 ldr r1, [pc, #0x704]
 *   @0x128018 ldr r0, [pc, #0x704]
 *   @0x12801c mov r2, #2
 *   @0x128020 mov r3, #0
 *   @0x128024 add r0, pc, r0
 *   @0x128028 ldr r1, [r4, r1]
 *   @0x12802c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #64 get_directory_alt → F_GetDirectoryAlt(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x128030 ldr r1, [pc, #0x6f0]
 *   @0x128034 ldr r0, [pc, #0x6f0]
 *   @0x128038 mov r2, #0
 *   @0x12803c mov r3, r2
 *   @0x128040 add r0, pc, r0
 *   @0x128044 ldr r1, [r4, r1]
 *   @0x128048 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #65 keyboard_get_numlock → F_KeyboardGetNumlock(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x12804c ldr r1, [pc, #0x6dc]
 *   @0x128050 ldr r0, [pc, #0x6dc]
 *   @0x128054 mov r2, #1
 *   @0x128058 mov r3, #0
 *   @0x12805c add r0, pc, r0
 *   @0x128060 ldr r1, [r4, r1]
 *   @0x128064 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #66 keyboard_set_numlock → F_KeyboardSetNumlock(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x128068 ldr r1, [pc, #0x6c8]
 *   @0x12806c ldr r0, [pc, #0x6c8]
 *   @0x128070 mov r2, #1
 *   @0x128074 mov r3, #0
 *   @0x128078 add r0, pc, r0
 *   @0x12807c ldr r1, [r4, r1]
 *   @0x128080 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #67 keyboard_key_press → F_KeyboardKeyPress(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x128084 ldr r1, [pc, #0x6b4]
 *   @0x128088 ldr r0, [pc, #0x6b4]
 *   @0x12808c mov r2, #1
 *   @0x128090 mov r3, #0
 *   @0x128094 add r0, pc, r0
 *   @0x128098 ldr r1, [r4, r1]
 *   @0x12809c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #68 keyboard_key_release → F_KeyboardKeyRelease(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1280a0 ldr r1, [pc, #0x6a0]
 *   @0x1280a4 ldr r0, [pc, #0x6a0]
 *   @0x1280a8 mov r2, #2
 *   @0x1280ac mov r3, #0
 *   @0x1280b0 add r0, pc, r0
 *   @0x1280b4 ldr r1, [r4, r1]
 *   @0x1280b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #69 keyboard_set_map → F_KeyboardSetMap(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1280bc ldr r1, [pc, #0x68c]
 *   @0x1280c0 ldr r0, [pc, #0x68c]
 *   @0x1280c4 mov r2, #1
 *   @0x1280c8 mov r3, #0
 *   @0x1280cc add r0, pc, r0
 *   @0x1280d0 ldr r1, [r4, r1]
 *   @0x1280d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #70 keyboard_get_map → F_KeyboardGetMap(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1280d8 ldr r1, [pc, #0x678]
 *   @0x1280dc ldr r0, [pc, #0x678]
 *   @0x1280e0 mov r2, #0
 *   @0x1280e4 mov r3, r2
 *   @0x1280e8 add r0, pc, r0
 *   @0x1280ec ldr r1, [r4, r1]
 *   @0x1280f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #71 keyboard_unset_map → F_KeyboardUnsetMap(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1280f4 ldr r1, [pc, #0x664]
 *   @0x1280f8 ldr r0, [pc, #0x664]
 *   @0x1280fc mov r2, #1
 *   @0x128100 mov r3, #0
 *   @0x128104 add r0, pc, r0
 *   @0x128108 ldr r1, [r4, r1]
 *   @0x12810c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #72 keyboard_check → F_CheckKey(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x128110 ldr r1, [pc, #0x650]
 *   @0x128114 ldr r0, [pc, #0x650]
 *   @0x128118 mov r2, #1
 *   @0x12811c mov r3, #0
 *   @0x128120 add r0, pc, r0
 *   @0x128124 ldr r1, [r4, r1]
 *   @0x128128 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #73 keyboard_check_pressed → F_CheckKeyPressed(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x12812c ldr r1, [pc, #0x63c]
 *   @0x128130 ldr r0, [pc, #0x63c]
 *   @0x128134 mov r2, #1
 *   @0x128138 mov r3, #0
 *   @0x12813c add r0, pc, r0
 *   @0x128140 ldr r1, [r4, r1]
 *   @0x128144 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #74 keyboard_check_released → F_CheckKeyReleased(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x128148 ldr r1, [pc, #0x628]
 *   @0x12814c ldr r0, [pc, #0x628]
 *   @0x128150 mov r2, #1
 *   @0x128154 mov r3, #0
 *   @0x128158 add r0, pc, r0
 *   @0x12815c ldr r1, [r4, r1]
 *   @0x128160 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #75 keyboard_check_direct → F_CheckKeyDirect(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x128164 ldr r1, [pc, #0x614]
 *   @0x128168 ldr r0, [pc, #0x614]
 *   @0x12816c mov r2, #1
 *   @0x128170 mov r3, #0
 *   @0x128174 add r0, pc, r0
 *   @0x128178 ldr r1, [r4, r1]
 *   @0x12817c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #76 mouse_check_button → F_CheckMouseButton(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x128180 ldr r1, [pc, #0x600]
 *   @0x128184 ldr r0, [pc, #0x600]
 *   @0x128188 mov r2, #1
 *   @0x12818c mov r3, #0
 *   @0x128190 add r0, pc, r0
 *   @0x128194 ldr r1, [r4, r1]
 *   @0x128198 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #77 mouse_check_button_pressed → F_CheckMouseButtonPressed(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x12819c ldr r1, [pc, #0x5ec]
 *   @0x1281a0 ldr r0, [pc, #0x5ec]
 *   @0x1281a4 mov r2, #1
 *   @0x1281a8 mov r3, #0
 *   @0x1281ac add r0, pc, r0
 *   @0x1281b0 ldr r1, [r4, r1]
 *   @0x1281b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #78 mouse_check_button_released → F_CheckMouseButtonReleased(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1281b8 ldr r1, [pc, #0x5d8]
 *   @0x1281bc ldr r0, [pc, #0x5d8]
 *   @0x1281c0 mov r2, #0
 *   @0x1281c4 mov r3, r2
 *   @0x1281c8 add r0, pc, r0
 *   @0x1281cc ldr r1, [r4, r1]
 *   @0x1281d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #79 mouse_wheel_up → F_MouseWheelUp(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1281d4 ldr r1, [pc, #0x5c4]
 *   @0x1281d8 ldr r0, [pc, #0x5c4]
 *   @0x1281dc mov r2, #0
 *   @0x1281e0 mov r3, r2
 *   @0x1281e4 add r0, pc, r0
 *   @0x1281e8 ldr r1, [r4, r1]
 *   @0x1281ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #80 mouse_wheel_down → F_MouseWheelDown(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1281f0 ldr r3, [pc, #0x5b0]
 *   @0x1281f4 ldr r6, [r4, r3]
 *   @0x1281f8 ldrb r5, [r6]
 *   @0x1281fc cmp r5, #0
 *   @0x128200 beq 0x128384 <_Z24InitInteractionFunctionsv+0xac0>   —— 条件跳转 → 0x128384
 *   @0x128204 ldr r1, [pc, #0x5a0]
 *   @0x128208 mov r2, #1
 *   @0x12820c ldr r0, [pc, #0x59c]
 *   @0x128210 mov r3, #0
 *   @0x128214 add r0, pc, r0
 *   @0x128218 ldr r1, [r4, r1]
 *   @0x12821c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #81 keyboard_clear → F_KeyboardClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x128220 ldr r1, [pc, #0x58c]
 *   @0x128224 ldr r0, [pc, #0x58c]
 *   @0x128228 mov r2, #1
 *   @0x12822c mov r3, #0
 *   @0x128230 add r0, pc, r0
 *   @0x128234 ldr r1, [r4, r1]
 *   @0x128238 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #82 mouse_clear → F_MouseClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x12823c ldr r1, [pc, #0x578]
 *   @0x128240 ldr r0, [pc, #0x578]
 *   @0x128244 mov r2, #0
 *   @0x128248 mov r3, r2
 *   @0x12824c add r0, pc, r0
 *   @0x128250 ldr r1, [r4, r1]
 *   @0x128254 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #83 io_clear → F_IoClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x128258 ldr r1, [pc, #0x564]
 *   @0x12825c ldr r0, [pc, #0x564]
 *   @0x128260 mov r2, #0
 *   @0x128264 mov r3, r2
 *   @0x128268 add r0, pc, r0
 *   @0x12826c ldr r1, [r4, r1]
 *   @0x128270 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #84 io_handle → F_IoHandle(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x128274 ldr r1, [pc, #0x550]
 *   @0x128278 ldr r0, [pc, #0x550]
 *   @0x12827c mov r2, #0
 *   @0x128280 mov r3, r2
 *   @0x128284 add r0, pc, r0
 *   @0x128288 ldr r1, [r4, r1]
 *   @0x12828c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #85 device_mouse_dbclick_enable → F_IoEnableDbClickAsMbRight(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x128290 ldr r1, [pc, #0x53c]
 *   @0x128294 ldr r0, [pc, #0x53c]
 *   @0x128298 mov r2, #0
 *   @0x12829c mov r3, r2
 *   @0x1282a0 add r0, pc, r0
 *   @0x1282a4 ldr r1, [r4, r1]
 *   @0x1282a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #86 keyboard_wait → F_KeyboardWait(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1282ac ldr r1, [pc, #0x528]
 *   @0x1282b0 ldr r0, [pc, #0x528]
 *   @0x1282b4 mov r2, #0
 *   @0x1282b8 mov r3, r2
 *   @0x1282bc add r0, pc, r0
 *   @0x1282c0 ldr r1, [r4, r1]
 *   @0x1282c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #87 mouse_wait → F_MouseWait(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1282c8 ldr r1, [pc, #0x514]
 *   @0x1282cc ldr r0, [pc, #0x514]
 *   @0x1282d0 mov r2, #1
 *   @0x1282d4 mov r3, #0
 *   @0x1282d8 add r0, pc, r0
 *   @0x1282dc ldr r1, [r4, r1]
 *   @0x1282e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #88 browser_input_capture → F_BrowserInputCapture(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1282e4 ldr r1, [pc, #0x500]
 *   @0x1282e8 ldr r0, [pc, #0x500]
 *   @0x1282ec mov r2, #2
 *   @0x1282f0 mov r3, #0
 *   @0x1282f4 add r0, pc, r0
 *   @0x1282f8 ldr r1, [r4, r1]
 *   @0x1282fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #89 gpio_set → F_GPIO_Set(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x128300 ldr r1, [pc, #0x4ec]
 *   @0x128304 ldr r0, [pc, #0x4ec]
 *   @0x128308 mov r2, #1
 *   @0x12830c mov r3, #0
 *   @0x128310 add r0, pc, r0
 *   @0x128314 ldr r1, [r4, r1]
 *   @0x128318 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #90 gpio_clear → F_GPIO_Clear(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x12831c ldr r1, [pc, #0x4d8]
 *   @0x128320 ldr r0, [pc, #0x4d8]
 *   @0x128324 mov r2, #1
 *   @0x128328 mov r3, #0
 *   @0x12832c add r0, pc, r0
 *   @0x128330 ldr r1, [r4, r1]
 *   @0x128334 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #91 gpio_get → F_GPIO_Get(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x128338 ldr r1, [pc, #0x4c4]
 *   @0x12833c ldr r0, [pc, #0x4c4]
 *   @0x128340 mov r2, #2
 *   @0x128344 mov r3, #0
 *   @0x128348 add r0, pc, r0
 *   @0x12834c ldr r1, [r4, r1]
 *   @0x128350 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #92 gpio_set_mode → F_GPIO_Set_Mode(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x128354 ldr r1, [pc, #0x4b0]
 *   @0x128358 ldr r0, [pc, #0x4b0]
 *   @0x12835c mov r3, #0
 *   @0x128360 mov r2, #2
 *   @0x128364 add r0, pc, r0
 *   @0x128368 ldr r1, [r4, r1]
 *   @0x12836c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #93 F_GPIO_Set_Function → F_GPIO_Set_Function(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x128370 ldrb r3, [r6]
 *   @0x128374 cmp r3, #0
 *   @0x128378 popeq {r4, r5, r6, pc}
 *   @0x12837c pop {r4, r5, r6, lr}
 *   @0x128380 b 0x1dbb30 <_Z19AddGestureFunctionsv>
 *   @0x128384 ldr r1, [pc, #0x488]
 *   @0x128388 mov r3, r5
 *   @0x12838c ldr r0, [pc, #0x484]
 *   @0x128390 mov r2, #1
 *   @0x128394 ldr r1, [r4, r1]
 *   @0x128398 add r0, pc, r0
 *   @0x12839c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #94 joystick_exists → F_JoystickExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=None ⚠ ?
 *   @0x1283a0 ldr r1, [pc, #0x474]
 *   @0x1283a4 ldr r0, [pc, #0x474]
 *   @0x1283a8 mov r3, r5
 *   @0x1283ac mov r2, #1
 *   @0x1283b0 ldr r1, [r4, r1]
 *   @0x1283b4 add r0, pc, r0
 *   @0x1283b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #95 joystick_direction → F_JoystickDirection(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=None ⚠ ?
 *   @0x1283bc ldr r1, [pc, #0x460]
 *   @0x1283c0 ldr r0, [pc, #0x460]
 *   @0x1283c4 mov r3, r5
 *   @0x1283c8 mov r2, #1
 *   @0x1283cc ldr r1, [r4, r1]
 *   @0x1283d0 add r0, pc, r0
 *   @0x1283d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #96 joystick_name → F_JoystickName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=None ⚠ ?
 *   @0x1283d8 ldr r1, [pc, #0x44c]
 *   @0x1283dc ldr r0, [pc, #0x44c]
 *   @0x1283e0 mov r3, r5
 *   @0x1283e4 mov r2, #1
 *   @0x1283e8 ldr r1, [r4, r1]
 *   @0x1283ec add r0, pc, r0
 *   @0x1283f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #97 joystick_axes → F_JoystickAxes(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=None ⚠ ?
 *   @0x1283f4 ldr r1, [pc, #0x438]
 *   @0x1283f8 ldr r0, [pc, #0x438]
 *   @0x1283fc mov r3, r5
 *   @0x128400 mov r2, #1
 *   @0x128404 ldr r1, [r4, r1]
 *   @0x128408 add r0, pc, r0
 *   @0x12840c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #98 joystick_buttons → F_JoystickButtons(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=None ⚠ ?
 *   @0x128410 ldr r1, [pc, #0x424]
 *   @0x128414 ldr r0, [pc, #0x424]
 *   @0x128418 mov r3, r5
 *   @0x12841c mov r2, #1
 *   @0x128420 ldr r1, [r4, r1]
 *   @0x128424 add r0, pc, r0
 *   @0x128428 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #99 joystick_has_pov → F_JoystickHasPov(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=None ⚠ ?
 *   @0x12842c ldr r1, [pc, #0x410]
 *   @0x128430 ldr r0, [pc, #0x410]
 *   @0x128434 mov r3, r5
 *   @0x128438 mov r2, #2
 *   @0x12843c ldr r1, [r4, r1]
 *   @0x128440 add r0, pc, r0
 *   @0x128444 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #100 joystick_check_button → F_JoystickCheckButton(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=None ⚠ ?
 *   @0x128448 ldr r1, [pc, #0x3fc]
 *   @0x12844c ldr r0, [pc, #0x3fc]
 *   @0x128450 mov r3, r5
 *   @0x128454 mov r2, #1
 *   @0x128458 ldr r1, [r4, r1]
 *   @0x12845c add r0, pc, r0
 *   @0x128460 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #101 joystick_xpos → F_JoystickXpos(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=None ⚠ ?
 *   @0x128464 ldr r1, [pc, #0x3e8]
 *   @0x128468 ldr r0, [pc, #0x3e8]
 *   @0x12846c mov r3, r5
 *   @0x128470 mov r2, #1
 *   @0x128474 ldr r1, [r4, r1]
 *   @0x128478 add r0, pc, r0
 *   @0x12847c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #102 joystick_ypos → F_JoystickYpos(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=None ⚠ ?
 *   @0x128480 ldr r1, [pc, #0x3d4]
 *   @0x128484 ldr r0, [pc, #0x3d4]
 *   @0x128488 mov r3, r5
 *   @0x12848c mov r2, #1
 *   @0x128490 ldr r1, [r4, r1]
 *   @0x128494 add r0, pc, r0
 *   @0x128498 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #103 joystick_zpos → F_JoystickZpos(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=None ⚠ ?
 *   @0x12849c ldr r1, [pc, #0x3c0]
 *   @0x1284a0 ldr r0, [pc, #0x3c0]
 *   @0x1284a4 mov r3, r5
 *   @0x1284a8 mov r2, #1
 *   @0x1284ac ldr r1, [r4, r1]
 *   @0x1284b0 add r0, pc, r0
 *   @0x1284b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #104 joystick_rpos → F_JoystickRpos(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=None ⚠ ?
 *   @0x1284b8 ldr r1, [pc, #0x3ac]
 *   @0x1284bc ldr r0, [pc, #0x3ac]
 *   @0x1284c0 mov r3, r5
 *   @0x1284c4 mov r2, #1
 *   @0x1284c8 ldr r1, [r4, r1]
 *   @0x1284cc add r0, pc, r0
 *   @0x1284d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #105 joystick_upos → F_JoystickUpos(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=None ⚠ ?
 *   @0x1284d4 ldr r1, [pc, #0x398]
 *   @0x1284d8 ldr r0, [pc, #0x398]
 *   @0x1284dc mov r3, r5
 *   @0x1284e0 mov r2, #1
 *   @0x1284e4 ldr r1, [r4, r1]
 *   @0x1284e8 add r0, pc, r0
 *   @0x1284ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #106 joystick_vpos → F_JoystickVpos(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=None ⚠ ?
 *   @0x1284f0 ldr r1, [pc, #0x384]
 *   @0x1284f4 ldr r0, [pc, #0x384]
 *   @0x1284f8 mov r3, r5
 *   @0x1284fc mov r2, #1
 *   @0x128500 add r0, pc, r0
 *   @0x128504 ldr r1, [r4, r1]
 *   @0x128508 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #107 joystick_pov → F_JoystickPov(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=None ⚠ ?
 *   @0x12850c b 0x128204 <_Z24InitInteractionFunctionsv+0x940>
 *   @0x128510 eoreq r10, r12, r0, lsl #7
 *   @0x128514 .word 0xffffce44
 *   @0x128518 eoreq r4, r1, r8, asr #18
 *   @0x12851c .word 0xffffce30
 *   @0x128520 .word 0xffffce48
 *   @0x128524 .word 0x002149d4
 *   @0x128528 .word 0xffffce4c
 *   @0x12852c eoreq r4, r1, r12, asr #19
 *   @0x128530 .word 0xffffce50
 *   @0x128534 eoreq r4, r1, r8, asr #19
 *   @0x128538 .word 0xffffce54
 *   @0x12853c eoreq r4, r1, r0, asr #19
 *   @0x128540 .word 0xffffce58
 *   @0x128544 .word 0x002149b4
 *   @0x128548 .word 0xffffce5c
 *   @0x12854c eoreq r4, r1, r12, lsr #19
 *   @0x128550 .word 0xffffce60
 *   @0x128554 eoreq r4, r1, r0, lsr #19
 *   @0x128558 .word 0xffffce64
 *   @0x12855c mlaeq r1, r8, r9, r4
 *   @0x128560 .word 0xffffce68
 *   @0x128564 eoreq r4, r1, r12, lsl #19
 *   @0x128568 .word 0xffffce6c
 *   @0x12856c eoreq r4, r1, r4, lsl #19
 *   @0x128570 .word 0xffffce70
 *   @0x128574 eoreq r4, r1, r12, ror r9
 *   @0x128578 .word 0xffffce74
 *   @0x12857c eoreq r4, r1, r8, ror r9
 *   @0x128580 .word 0xffffce78
 *   @0x128584 eoreq r4, r1, r0, ror r9
 *   @0x128588 .word 0xffffce7c
 *   @0x12858c eoreq r4, r1, r12, ror #18
 *   @0x128590 .word 0xffffce80
 *   @0x128594 eoreq r4, r1, r4, ror #18
 *   @0x128598 .word 0xffffce84
 *   @0x12859c eoreq r4, r1, r12, asr r9
 *   @0x1285a0 .word 0xffffce88
 *   @0x1285a4 eoreq r4, r1, r4, asr r9
 *   @0x1285a8 .word 0xffffce8c
 *   @0x1285ac eoreq r4, r1, r4, asr #18
 *   @0x1285b0 .word 0xffffce90
 *   @0x1285b4 eoreq r4, r1, r4, lsr r9
 *   @0x1285b8 .word 0xffffce94
 *   @0x1285bc eoreq r4, r1, r4, lsr #18
 *   @0x1285c0 .word 0xffffce98
 *   @0x1285c4 eoreq r4, r1, r8, lsl r9
 *   @0x1285c8 .word 0xffffce9c
 *   @0x1285cc eoreq r4, r1, r12, lsl #18
 *   @0x1285d0 .word 0xffffcea0
 *   @0x1285d4 eoreq r4, r1, r4, lsl #18
 *   @0x1285d8 .word 0xffffcea4
 *   @0x1285dc .word 0x002148fc
 *   @0x1285e0 .word 0xffffcea8
 *   @0x1285e4 eoreq r4, r1, r12, ror #17
 *   @0x1285e8 .word 0xffffceac
 *   @0x1285ec .word 0x002148dc
 *   @0x1285f0 .word 0xffffceb0
 *   @0x1285f4 eoreq r4, r1, r12, asr #17
 *   @0x1285f8 .word 0xffffceb4
 *   @0x1285fc eoreq r4, r1, r0, asr #17
 *   @0x128600 .word 0xffffceb8
 *   @0x128604 eoreq r4, r1, r0, asr #17
 *   @0x128608 .word 0xffffcebc
 *   @0x12860c .word 0x002148bc
 *   @0x128610 .word 0xffffcec0
 *   @0x128614 .word 0x002148b4
 *   @0x128618 .word 0xffffcec4
 *   @0x12861c .word 0x002148b0
 *   @0x128620 .word 0xffffcec8
 *   @0x128624 eoreq r4, r1, r12, lsr #17
 *   @0x128628 .word 0xffffcecc
 *   @0x12862c eoreq r4, r1, r4, lsr #17
 *   @0x128630 .word 0xffffced0
 *   @0x128634 mlaeq r1, r8, r8, r4
 *   @0x128638 .word 0xffffced4
 *   @0x12863c eoreq r4, r1, r12, lsl #17
 *   @0x128640 .word 0xffffced8
 *   @0x128644 eoreq r4, r1, r8, lsl #17
 *   @0x128648 .word 0xffffcedc
 *   @0x12864c eoreq r4, r1, r12, ror r8
 *   @0x128650 .word 0xffffcee0
 *   @0x128654 eoreq r4, r1, r0, ror r8
 *   @0x128658 .word 0xffffcee4
 *   @0x12865c eoreq r4, r1, r4, ror #16
 *   @0x128660 .word 0xffffcee8
 *   @0x128664 eoreq r4, r1, r12, asr r8
 *   @0x128668 .word 0xffffceec
 *   @0x12866c eoreq r4, r1, r4, asr r8
 *   @0x128670 .word 0xffffcef0
 *   @0x128674 eoreq r4, r1, r8, asr #16
 *   @0x128678 .word 0xffffcef4
 *   @0x12867c eoreq r4, r1, r12, lsr r8
 *   @0x128680 .word 0xffffcef8
 *   @0x128684 eoreq r4, r1, r4, lsr r8
 *   @0x128688 .word 0xffffcefc
 *   @0x12868c eoreq r4, r1, r12, lsr #16
 *   @0x128690 .word 0xffffcf00
 *   @0x128694 eoreq r4, r1, r4, lsr #16
 *   @0x128698 .word 0xffffcf04
 *   @0x12869c eoreq r4, r1, r12, lsl r8
 *   @0x1286a0 .word 0xffffcf08
 *   @0x1286a4 eoreq r4, r1, r4, lsl r8
 *   @0x1286a8 .word 0xffffcf0c
 *   @0x1286ac eoreq r4, r1, r12, lsl #16
 *   @0x1286b0 .word 0xffffcf10
 *   @0x1286b4 eoreq r4, r1, r0, lsl #16
 *   @0x1286b8 .word 0xffffcf14
 *   @0x1286bc .word 0x002147f4
 *   @0x1286c0 .word 0xffffcf18
 *   @0x1286c4 eoreq r4, r1, r4, ror #15
 *   @0x1286c8 .word 0xffffcf1c
 *   @0x1286cc .word 0x002147d8
 *   @0x1286d0 .word 0xffffcf20
 *   @0x1286d4 eoreq r4, r1, r8, asr #15
 *   @0x1286d8 .word 0xffffcf24
 *   @0x1286dc eoreq r4, r1, r0, asr #15
 *   @0x1286e0 .word 0xffffcf28
 *   @0x1286e4 .word 0x002147b0
 *   @0x1286e8 .word 0xffffcf2c
 *   @0x1286ec eoreq r4, r1, r8, lsr #15
 *   @0x1286f0 .word 0xffffcf30
 *   @0x1286f4 mlaeq r1, r12, r7, r4
 *   @0x1286f8 .word 0xffffcf34
 *   @0x1286fc eoreq r4, r1, r12, lsl #15
 *   @0x128700 .word 0xffffcf38
 *   @0x128704 eoreq r4, r1, r4, lsl #15
 *   @0x128708 .word 0xffffcf3c
 *   @0x12870c eoreq r4, r1, r12, ror r7
 *   @0x128710 .word 0xffffcf40
 *   @0x128714 eoreq r4, r1, r8, ror r7
 *   @0x128718 .word 0xffffcf44
 *   @0x12871c eoreq r4, r1, r4, ror r7
 *   @0x128720 .word 0xffffcf48
 *   @0x128724 eoreq r4, r1, r8, ror #14
 *   @0x128728 .word 0xffffcf4c
 *   @0x12872c eoreq r4, r1, r0, ror #14
 *   @0x128730 .word 0xffffcf50
 *   @0x128734 eoreq r4, r1, r12, asr r7
 *   @0x128738 .word 0xffffcf54
 *   @0x12873c eoreq r4, r1, r8, asr r7
 *   @0x128740 .word 0xffffcf58
 *   @0x128744 eoreq r4, r1, r0, asr r7
 *   @0x128748 .word 0xffffcf5c
 *   @0x12874c eoreq r4, r1, r12, asr #14
 *   @0x128750 .word 0xffffcf60
 *   @0x128754 eoreq r4, r1, r4, asr #14
 *   @0x128758 .word 0xffffcf64
 *   @0x12875c eoreq r4, r1, r12, lsr r7
 *   @0x128760 .word 0xffffcf68
 *   @0x128764 eoreq r4, r1, r4, lsr r7
 *   @0x128768 .word 0xffffcf6c
 *   @0x12876c eoreq r4, r1, r8, lsr #14
 *   @0x128770 .word 0xffffcf70
 *   @0x128774 eoreq r4, r1, r4, lsr #14
 *   @0x128778 .word 0xffffcf74
 *   @0x12877c eoreq r4, r1, r0, lsr #14
 *   @0x128780 .word 0xffffcf78
 *   @0x128784 eoreq r4, r1, r12, lsl r7
 *   @0x128788 .word 0xffffcf7c
 *   @0x12878c eoreq r4, r1, r4, lsl r7
 *   @0x128790 .word 0xffffcf80
 *   @0x128794 eoreq r4, r1, r4, lsl r7
 *   @0x128798 .word 0xffffcf84
 *   @0x12879c eoreq r4, r1, r4, lsl r7
 *   @0x1287a0 .word 0xffffcf88
 *   @0x1287a4 eoreq r4, r1, r8, lsl #14
 *   @0x1287a8 .word 0xffffbcd4
 *   @0x1287ac .word 0xffffcf8c
 *   @0x1287b0 eoreq r4, r1, r0, ror #15
 *   @0x1287b4 .word 0xffffcf90
 *   @0x1287b8 .word 0x002147d4
 *   @0x1287bc .word 0xffffcf94
 *   @0x1287c0 eoreq r4, r1, r4, asr #15
 *   @0x1287c4 .word 0xffffcf98
 *   @0x1287c8 .word 0x002147b4
 *   @0x1287cc .word 0xffffcf9c
 *   @0x1287d0 eoreq r4, r1, r4, lsr #15
 *   @0x1287d4 .word 0xffffcfa0
 *   @0x1287d8 eoreq r4, r1, r4, lsr #15
 *   @0x1287dc .word 0xffffcfa4
 *   @0x1287e0 mlaeq r1, r8, r7, r4
 *   @0x1287e4 .word 0xffffcfa8
 *   @0x1287e8 eoreq r4, r1, r8, lsl #15
 *   @0x1287ec .word 0xffffcfac
 *   @0x1287f0 eoreq r4, r1, r4, lsl #15
 *   @0x1287f4 .word 0xffffcfb0
 *   @0x1287f8 eoreq r4, r1, r4, ror r7
 *   @0x1287fc .word 0xffffcfb4
 *   @0x128800 eoreq r4, r1, r4, ror #14
 *   @0x128804 .word 0xffffcfb8
 *   @0x128808 eoreq r4, r1, r4, asr r7
 *   @0x12880c .word 0xffffcfbc
 *   @0x128810 eoreq r4, r1, r8, asr #14
 *   @0x128814 .word 0xffffcfc0
 *   @0x128818 eoreq r4, r1, r8, ror #10
 *   @0x12881c .word 0xffffcfc4
 *   @0x128820 eoreq r4, r1, r12, asr r5
 *   @0x128824 .word 0xffffcfc8
 *   @0x128828 eoreq r4, r1, r4, asr r5
 *   @0x12882c .word 0xffffcfcc
 *   @0x128830 eoreq r4, r1, r8, asr #10
 *   @0x128834 .word 0xffffcfd0
 *   @0x128838 eoreq r4, r1, r12, lsr r5
 *   @0x12883c .word 0xffffcfd4
 *   @0x128840 eoreq r4, r1, r4, lsr r5
 *   @0x128844 .word 0xffffcfd8
 *   @0x128848 eoreq r4, r1, r12, lsr #10
 *   @0x12884c .word 0xffffcfdc
 *   @0x128850 eoreq r4, r1, r8, lsr #10
 *   @0x128854 .word 0xffffcfe0
 *   @0x128858 eoreq r4, r1, r12, lsl r5
 *   @0x12885c .word 0xffffcfe4
 *   @0x128860 eoreq r4, r1, r0, lsl r5
 *   @0x128864 .word 0xffffcfe8
 *   @0x128868 eoreq r4, r1, r4, lsl #10
 *   @0x12886c .word 0xffffcfec
 *   @0x128870 .word 0x002144f8
 *   @0x128874 .word 0xffffcff0
 *   @0x128878 eoreq r4, r1, r12, ror #9
 *   @0x12887c .word 0xffffcff4
 *   @0x128880 eoreq r4, r1, r4, ror #9
 *
 * ══ §2/6 InitActionFunctions  0x141e60..0x14319c  size 4924  1231 条（965 条指令 + 266 个池字）══
 * @func 0x141e60 0x14319c  size 4924  1231 条
 * 注册 136 条｜唯一名 136｜唯一函数指针 126｜argc 0:26 1:34 2:25 3:21 4:8 5:5 6:16 11:1｜flag 0:100 1:36
 * 首条 #0 action_path_old（0x141ec4）→ 末条 #135 action_effect（0x142d70）
 * 名字族（前 8）: action×136
 * 游戏实际调用的 99 个内建里落在本表: 3 个（action_bounce, action_current_room, action_kill_object）
 * 表: asm/init-tables/init-InitActionFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: 无（本函数每条注册的四实参全部解出，控制流全部走到）
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x141e60 push {r4, r5, r6, lr}
 *   @0x141e64 mov r5, #64
 *   @0x141e68 ldr r4, [pc, #0xf04]
 *   @0x141e6c mvn r12, #0
 *   @0x141e70 ldr r0, [pc, #0xf00]
 *   @0x141e74 mov r2, r5
 *   @0x141e78 add r4, pc, r4
 *   @0x141e7c ldr r3, [pc, #0xef8]
 *   @0x141e80 mov r1, #0
 *   @0x141e84 ldr r0, [r4, r0]
 *   @0x141e88 str r12, [r0]
 *   @0x141e8c ldr r0, [r4, r3]
 *   @0x141e90 bl 0xb65b0 <memset@plt>   —— 调用 0xb65b0
 *   @0x141e94 ldr r3, [pc, #0xee4]
 *   @0x141e98 mov r2, r5
 *   @0x141e9c mov r1, #0
 *   @0x141ea0 ldr r0, [r4, r3]
 *   @0x141ea4 bl 0xb65b0 <memset@plt>   —— 调用 0xb65b0
 *   @0x141ea8 ldr r1, [pc, #0xed4]
 *   @0x141eac ldr r0, [pc, #0xed4]
 *   @0x141eb0 mov r2, #3
 *   @0x141eb4 mov r3, #0
 *   @0x141eb8 ldr r5, [r4, r1]
 *   @0x141ebc add r0, pc, r0
 *   @0x141ec0 mov r1, r5
 *   @0x141ec4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 action_path_old → F_ActionUnknown(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x141ec8 ldr r1, [pc, #0xebc]
 *   @0x141ecc ldr r0, [pc, #0xebc]
 *   @0x141ed0 mov r2, #2
 *   @0x141ed4 mov r3, #0
 *   @0x141ed8 ldr r1, [r4, r1]
 *   @0x141edc add r0, pc, r0
 *   @0x141ee0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 action_set_sprite → F_ActionSetSprite(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x141ee4 ldr r0, [pc, #0xea8]
 *   @0x141ee8 mov r1, r5
 *   @0x141eec mov r2, #1
 *   @0x141ef0 add r0, pc, r0
 *   @0x141ef4 mov r3, #0
 *   @0x141ef8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 action_draw_font → F_ActionUnknown(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x141efc ldr r0, [pc, #0xe94]
 *   @0x141f00 mov r1, r5
 *   @0x141f04 mov r2, #6
 *   @0x141f08 add r0, pc, r0
 *   @0x141f0c mov r3, #0
 *   @0x141f10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 action_draw_font_old → F_ActionUnknown(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=0
 *   @0x141f14 ldr r0, [pc, #0xe80]
 *   @0x141f18 mov r1, r5
 *   @0x141f1c mov r2, #1
 *   @0x141f20 add r0, pc, r0
 *   @0x141f24 mov r3, #0
 *   @0x141f28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #4 action_fill_color → F_ActionUnknown(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x141f2c ldr r0, [pc, #0xe6c]
 *   @0x141f30 mov r1, r5
 *   @0x141f34 mov r2, #1
 *   @0x141f38 add r0, pc, r0
 *   @0x141f3c mov r3, #0
 *   @0x141f40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #5 action_fill_colour → F_ActionUnknown(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x141f44 ldr r0, [pc, #0xe58]
 *   @0x141f48 mov r1, r5
 *   @0x141f4c mov r2, #1
 *   @0x141f50 add r0, pc, r0
 *   @0x141f54 mov r3, #0
 *   @0x141f58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #6 action_line_color → F_ActionUnknown(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x141f5c ldr r0, [pc, #0xe44]
 *   @0x141f60 mov r1, r5
 *   @0x141f64 mov r2, #1
 *   @0x141f68 add r0, pc, r0
 *   @0x141f6c mov r3, #0
 *   @0x141f70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #7 action_line_colour → F_ActionUnknown(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x141f74 ldr r0, [pc, #0xe30]
 *   @0x141f78 mov r2, #0
 *   @0x141f7c mov r1, r5
 *   @0x141f80 mov r3, r2
 *   @0x141f84 add r0, pc, r0
 *   @0x141f88 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #8 action_highscore → F_ActionUnknown(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x141f8c ldr r1, [pc, #0xe1c]
 *   @0x141f90 ldr r0, [pc, #0xe1c]
 *   @0x141f94 mov r2, #1
 *   @0x141f98 mov r3, #0
 *   @0x141f9c ldr r1, [r4, r1]
 *   @0x141fa0 add r0, pc, r0
 *   @0x141fa4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #9 action_set_relative → F_ActionSetRelative(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x141fa8 ldr r1, [pc, #0xe08]
 *   @0x141fac ldr r0, [pc, #0xe08]
 *   @0x141fb0 mov r2, #2
 *   @0x141fb4 mov r3, #0
 *   @0x141fb8 ldr r1, [r4, r1]
 *   @0x141fbc add r0, pc, r0
 *   @0x141fc0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #10 action_move → F_ActionMove(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x141fc4 ldr r1, [pc, #0xdf4]
 *   @0x141fc8 ldr r0, [pc, #0xdf4]
 *   @0x141fcc mov r2, #2
 *   @0x141fd0 mov r3, #0
 *   @0x141fd4 ldr r1, [r4, r1]
 *   @0x141fd8 add r0, pc, r0
 *   @0x141fdc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #11 action_set_motion → F_ActionSetMotion(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x141fe0 ldr r1, [pc, #0xde0]
 *   @0x141fe4 ldr r0, [pc, #0xde0]
 *   @0x141fe8 mov r2, #1
 *   @0x141fec mov r3, #0
 *   @0x141ff0 ldr r1, [r4, r1]
 *   @0x141ff4 add r0, pc, r0
 *   @0x141ff8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #12 action_set_hspeed → F_ActionSetHspeed(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x141ffc ldr r1, [pc, #0xdcc]
 *   @0x142000 ldr r0, [pc, #0xdcc]
 *   @0x142004 mov r2, #1
 *   @0x142008 mov r3, #0
 *   @0x14200c ldr r1, [r4, r1]
 *   @0x142010 add r0, pc, r0
 *   @0x142014 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #13 action_set_vspeed → F_ActionSetVspeed(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x142018 ldr r1, [pc, #0xdb8]
 *   @0x14201c ldr r0, [pc, #0xdb8]
 *   @0x142020 mov r2, #2
 *   @0x142024 mov r3, #0
 *   @0x142028 ldr r1, [r4, r1]
 *   @0x14202c add r0, pc, r0
 *   @0x142030 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #14 action_set_gravity → F_ActionSetGravity(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x142034 ldr r1, [pc, #0xda4]
 *   @0x142038 ldr r0, [pc, #0xda4]
 *   @0x14203c mov r2, #1
 *   @0x142040 mov r3, #0
 *   @0x142044 ldr r1, [r4, r1]
 *   @0x142048 add r0, pc, r0
 *   @0x14204c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #15 action_set_friction → F_ActionSetFriction(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x142050 ldr r1, [pc, #0xd90]
 *   @0x142054 ldr r0, [pc, #0xd90]
 *   @0x142058 mov r2, #3
 *   @0x14205c mov r3, #0
 *   @0x142060 ldr r1, [r4, r1]
 *   @0x142064 add r0, pc, r0
 *   @0x142068 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #16 action_move_point → F_ActionMovePoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x14206c ldr r1, [pc, #0xd7c]
 *   @0x142070 ldr r0, [pc, #0xd7c]
 *   @0x142074 mov r2, #2
 *   @0x142078 mov r3, #0
 *   @0x14207c ldr r1, [r4, r1]
 *   @0x142080 add r0, pc, r0
 *   @0x142084 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #17 action_move_to → F_ActionMoveTo(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x142088 ldr r1, [pc, #0xd68]
 *   @0x14208c ldr r0, [pc, #0xd68]
 *   @0x142090 mov r2, #0
 *   @0x142094 mov r3, r2
 *   @0x142098 ldr r1, [r4, r1]
 *   @0x14209c add r0, pc, r0
 *   @0x1420a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #18 action_move_start → F_ActionMoveStart(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1420a4 ldr r1, [pc, #0xd54]
 *   @0x1420a8 ldr r0, [pc, #0xd54]
 *   @0x1420ac mov r2, #2
 *   @0x1420b0 mov r3, #0
 *   @0x1420b4 ldr r1, [r4, r1]
 *   @0x1420b8 add r0, pc, r0
 *   @0x1420bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #19 action_move_random → F_ActionMoveRandom(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1420c0 ldr r1, [pc, #0xd40]
 *   @0x1420c4 ldr r0, [pc, #0xd40]
 *   @0x1420c8 mov r2, #2
 *   @0x1420cc mov r3, #0
 *   @0x1420d0 ldr r1, [r4, r1]
 *   @0x1420d4 add r0, pc, r0
 *   @0x1420d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #20 action_snap → F_ActionSnap(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1420dc ldr r1, [pc, #0xd2c]
 *   @0x1420e0 ldr r0, [pc, #0xd2c]
 *   @0x1420e4 mov r2, #1
 *   @0x1420e8 mov r3, #0
 *   @0x1420ec ldr r1, [r4, r1]
 *   @0x1420f0 add r0, pc, r0
 *   @0x1420f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #21 action_wrap → F_ActionWrap(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1420f8 ldr r1, [pc, #0xd18]
 *   @0x1420fc ldr r0, [pc, #0xd18]
 *   @0x142100 mov r2, #0
 *   @0x142104 mov r3, r2
 *   @0x142108 ldr r1, [r4, r1]
 *   @0x14210c add r0, pc, r0
 *   @0x142110 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #22 action_reverse_xdir → F_ActionReverseXDir(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x142114 ldr r1, [pc, #0xd04]
 *   @0x142118 ldr r0, [pc, #0xd04]
 *   @0x14211c mov r2, #0
 *   @0x142120 mov r3, r2
 *   @0x142124 ldr r1, [r4, r1]
 *   @0x142128 add r0, pc, r0
 *   @0x14212c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #23 action_reverse_ydir → F_ActionReverseYDir(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x142130 ldr r1, [pc, #0xcf0]
 *   @0x142134 ldr r0, [pc, #0xcf0]
 *   @0x142138 mov r2, #3
 *   @0x14213c mov r3, #0
 *   @0x142140 ldr r1, [r4, r1]
 *   @0x142144 add r0, pc, r0
 *   @0x142148 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #24 action_move_contact → F_ActionMoveContact(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x14214c ldr r1, [pc, #0xcdc]
 *   @0x142150 ldr r0, [pc, #0xcdc]
 *   @0x142154 mov r2, #2
 *   @0x142158 mov r3, #0
 *   @0x14215c ldr r1, [r4, r1]
 *   @0x142160 add r0, pc, r0
 *   @0x142164 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #25 action_bounce → F_ActionBounce(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x142168 ldr r1, [pc, #0xcc8]
 *   @0x14216c ldr r0, [pc, #0xcc8]
 *   @0x142170 mov r2, #4
 *   @0x142174 mov r3, #0
 *   @0x142178 ldr r1, [r4, r1]
 *   @0x14217c add r0, pc, r0
 *   @0x142180 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #26 action_path → F_ActionPath(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x142184 ldr r1, [pc, #0xcb4]
 *   @0x142188 ldr r0, [pc, #0xcb4]
 *   @0x14218c mov r2, #0
 *   @0x142190 mov r3, r2
 *   @0x142194 ldr r1, [r4, r1]
 *   @0x142198 add r0, pc, r0
 *   @0x14219c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #27 action_path_end → F_ActionPathEnd(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1421a0 ldr r1, [pc, #0xca0]
 *   @0x1421a4 ldr r0, [pc, #0xca0]
 *   @0x1421a8 mov r2, #1
 *   @0x1421ac mov r3, #0
 *   @0x1421b0 ldr r1, [r4, r1]
 *   @0x1421b4 add r0, pc, r0
 *   @0x1421b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #28 action_path_position → F_ActionPathPosition(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1421bc ldr r1, [pc, #0xc8c]
 *   @0x1421c0 ldr r0, [pc, #0xc8c]
 *   @0x1421c4 mov r2, #1
 *   @0x1421c8 mov r3, #0
 *   @0x1421cc ldr r1, [r4, r1]
 *   @0x1421d0 add r0, pc, r0
 *   @0x1421d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #29 action_path_speed → F_ActionPathSpeed(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1421d8 ldr r1, [pc, #0xc78]
 *   @0x1421dc ldr r0, [pc, #0xc78]
 *   @0x1421e0 mov r2, #4
 *   @0x1421e4 mov r3, #0
 *   @0x1421e8 ldr r1, [r4, r1]
 *   @0x1421ec add r0, pc, r0
 *   @0x1421f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #30 action_linear_step → F_ActionLinearStep(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x1421f4 ldr r1, [pc, #0xc64]
 *   @0x1421f8 ldr r0, [pc, #0xc64]
 *   @0x1421fc mov r2, #4
 *   @0x142200 mov r3, #0
 *   @0x142204 ldr r1, [r4, r1]
 *   @0x142208 add r0, pc, r0
 *   @0x14220c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #31 action_potential_step → F_ActionPotentialStep(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x142210 ldr r1, [pc, #0xc50]
 *   @0x142214 ldr r0, [pc, #0xc50]
 *   @0x142218 mov r2, #0
 *   @0x14221c mov r3, r2
 *   @0x142220 ldr r1, [r4, r1]
 *   @0x142224 add r0, pc, r0
 *   @0x142228 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #32 action_kill_object → F_ActionKillObject(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x14222c ldr r1, [pc, #0xc3c]
 *   @0x142230 ldr r0, [pc, #0xc3c]
 *   @0x142234 mov r2, #3
 *   @0x142238 mov r3, #0
 *   @0x14223c ldr r1, [r4, r1]
 *   @0x142240 add r0, pc, r0
 *   @0x142244 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #33 action_create_object → F_ActionCreateObject(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x142248 ldr r1, [pc, #0xc28]
 *   @0x14224c ldr r0, [pc, #0xc28]
 *   @0x142250 mov r2, #5
 *   @0x142254 mov r3, #0
 *   @0x142258 ldr r1, [r4, r1]
 *   @0x14225c add r0, pc, r0
 *   @0x142260 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #34 action_create_object_motion → F_ActionCreateObjectMotion(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0x142264 ldr r1, [pc, #0xc14]
 *   @0x142268 ldr r0, [pc, #0xc14]
 *   @0x14226c mov r2, #6
 *   @0x142270 mov r3, #0
 *   @0x142274 ldr r1, [r4, r1]
 *   @0x142278 add r0, pc, r0
 *   @0x14227c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #35 action_create_object_random → F_ActionCreateObjectRandom(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=0
 *   @0x142280 ldr r1, [pc, #0xc00]
 *   @0x142284 ldr r0, [pc, #0xc00]
 *   @0x142288 mov r2, #2
 *   @0x14228c mov r3, #0
 *   @0x142290 ldr r1, [r4, r1]
 *   @0x142294 add r0, pc, r0
 *   @0x142298 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #36 action_change_object → F_ActionChangeObject(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x14229c ldr r1, [pc, #0xbec]
 *   @0x1422a0 ldr r0, [pc, #0xbec]
 *   @0x1422a4 mov r2, #2
 *   @0x1422a8 mov r3, #0
 *   @0x1422ac ldr r1, [r4, r1]
 *   @0x1422b0 add r0, pc, r0
 *   @0x1422b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #37 action_kill_position → F_ActionKillPosition(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1422b8 ldr r1, [pc, #0xbd8]
 *   @0x1422bc ldr r0, [pc, #0xbd8]
 *   @0x1422c0 mov r2, #3
 *   @0x1422c4 mov r3, #0
 *   @0x1422c8 ldr r1, [r4, r1]
 *   @0x1422cc add r0, pc, r0
 *   @0x1422d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #38 action_sprite_set → F_ActionSpriteSet(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x1422d4 ldr r1, [pc, #0xbc4]
 *   @0x1422d8 ldr r0, [pc, #0xbc4]
 *   @0x1422dc mov r2, #4
 *   @0x1422e0 mov r3, #1
 *   @0x1422e4 ldr r1, [r4, r1]
 *   @0x1422e8 add r0, pc, r0
 *   @0x1422ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #39 action_sprite_transform → F_ActionSpriteTransform(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x1422f0 ldr r1, [pc, #0xbb0]
 *   @0x1422f4 ldr r0, [pc, #0xbb0]
 *   @0x1422f8 mov r2, #2
 *   @0x1422fc mov r3, #1
 *   @0x142300 ldr r5, [r4, r1]
 *   @0x142304 add r0, pc, r0
 *   @0x142308 mov r1, r5
 *   @0x14230c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #40 action_sprite_color → F_ActionSpriteColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x142310 ldr r0, [pc, #0xb98]
 *   @0x142314 mov r1, r5
 *   @0x142318 mov r2, #2
 *   @0x14231c add r0, pc, r0
 *   @0x142320 mov r3, #1
 *   @0x142324 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #41 action_sprite_colour → F_ActionSpriteColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x142328 ldr r1, [pc, #0xb84]
 *   @0x14232c ldr r0, [pc, #0xb84]
 *   @0x142330 mov r2, #2
 *   @0x142334 mov r3, #0
 *   @0x142338 ldr r1, [r4, r1]
 *   @0x14233c add r0, pc, r0
 *   @0x142340 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #42 action_sound → F_ActionSound(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x142344 ldr r1, [pc, #0xb70]
 *   @0x142348 ldr r0, [pc, #0xb70]
 *   @0x14234c mov r2, #1
 *   @0x142350 mov r3, #0
 *   @0x142354 ldr r1, [r4, r1]
 *   @0x142358 add r0, pc, r0
 *   @0x14235c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #43 action_end_sound → F_ActionEndSound(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x142360 ldr r1, [pc, #0xb5c]
 *   @0x142364 ldr r0, [pc, #0xb5c]
 *   @0x142368 mov r2, #1
 *   @0x14236c mov r3, #0
 *   @0x142370 ldr r1, [r4, r1]
 *   @0x142374 add r0, pc, r0
 *   @0x142378 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #44 action_if_sound → F_ActionIfSound(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x14237c ldr r1, [pc, #0xb48]
 *   @0x142380 ldr r0, [pc, #0xb48]
 *   @0x142384 mov r2, #1
 *   @0x142388 mov r3, #0
 *   @0x14238c ldr r1, [r4, r1]
 *   @0x142390 add r0, pc, r0
 *   @0x142394 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #45 action_another_room → F_ActionAnotherRoom(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x142398 ldr r1, [pc, #0xb34]
 *   @0x14239c ldr r0, [pc, #0xb34]
 *   @0x1423a0 mov r2, #0
 *   @0x1423a4 mov r3, r2
 *   @0x1423a8 ldr r1, [r4, r1]
 *   @0x1423ac add r0, pc, r0
 *   @0x1423b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #46 action_current_room → F_ActionCurrentRoom(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1423b4 ldr r1, [pc, #0xb20]
 *   @0x1423b8 ldr r0, [pc, #0xb20]
 *   @0x1423bc mov r2, #0
 *   @0x1423c0 mov r3, r2
 *   @0x1423c4 ldr r1, [r4, r1]
 *   @0x1423c8 add r0, pc, r0
 *   @0x1423cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #47 action_previous_room → F_ActionPreviousRoom(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1423d0 ldr r1, [pc, #0xb0c]
 *   @0x1423d4 ldr r0, [pc, #0xb0c]
 *   @0x1423d8 mov r2, #0
 *   @0x1423dc mov r3, r2
 *   @0x1423e0 ldr r1, [r4, r1]
 *   @0x1423e4 add r0, pc, r0
 *   @0x1423e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #48 action_next_room → F_ActionNextRoom(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1423ec ldr r1, [pc, #0xaf8]
 *   @0x1423f0 ldr r0, [pc, #0xaf8]
 *   @0x1423f4 mov r2, #0
 *   @0x1423f8 mov r3, r2
 *   @0x1423fc ldr r1, [r4, r1]
 *   @0x142400 add r0, pc, r0
 *   @0x142404 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #49 action_if_previous_room → F_ActionIfPreviousRoom(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x142408 ldr r1, [pc, #0xae4]
 *   @0x14240c ldr r0, [pc, #0xae4]
 *   @0x142410 mov r2, #0
 *   @0x142414 mov r3, r2
 *   @0x142418 ldr r1, [r4, r1]
 *   @0x14241c add r0, pc, r0
 *   @0x142420 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #50 action_if_next_room → F_ActionIfNextRoom(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x142424 ldr r1, [pc, #0xad0]
 *   @0x142428 ldr r0, [pc, #0xad0]
 *   @0x14242c mov r2, #2
 *   @0x142430 mov r3, #0
 *   @0x142434 ldr r1, [r4, r1]
 *   @0x142438 add r0, pc, r0
 *   @0x14243c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #51 action_set_alarm → F_ActionSetAlarm(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x142440 ldr r1, [pc, #0xabc]
 *   @0x142444 ldr r0, [pc, #0xabc]
 *   @0x142448 mov r2, #2
 *   @0x14244c mov r3, #0
 *   @0x142450 ldr r1, [r4, r1]
 *   @0x142454 add r0, pc, r0
 *   @0x142458 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #52 action_sleep → F_ActionSleep(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x14245c ldr r1, [pc, #0xaa8]
 *   @0x142460 ldr r0, [pc, #0xaa8]
 *   @0x142464 mov r2, #2
 *   @0x142468 mov r3, #0
 *   @0x14246c ldr r1, [r4, r1]
 *   @0x142470 add r0, pc, r0
 *   @0x142474 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #53 action_set_timeline → F_ActionSetTimeline(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x142478 ldr r1, [pc, #0xa94]
 *   @0x14247c ldr r0, [pc, #0xa94]
 *   @0x142480 mov r2, #1
 *   @0x142484 mov r3, #0
 *   @0x142488 ldr r1, [r4, r1]
 *   @0x14248c add r0, pc, r0
 *   @0x142490 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #54 action_set_timeline_position → F_ActionSetTimelinePosition(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x142494 ldr r1, [pc, #0xa80]
 *   @0x142498 ldr r0, [pc, #0xa80]
 *   @0x14249c mov r2, #1
 *   @0x1424a0 mov r3, #0
 *   @0x1424a4 ldr r1, [r4, r1]
 *   @0x1424a8 add r0, pc, r0
 *   @0x1424ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #55 action_set_timeline_speed → F_ActionSetTimelineSpeed(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1424b0 ldr r1, [pc, #0xa6c]
 *   @0x1424b4 ldr r0, [pc, #0xa6c]
 *   @0x1424b8 mov r2, #4
 *   @0x1424bc mov r3, #0
 *   @0x1424c0 ldr r1, [r4, r1]
 *   @0x1424c4 add r0, pc, r0
 *   @0x1424c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #56 action_timeline_set → F_ActionTimelineSet(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x1424cc ldr r1, [pc, #0xa58]
 *   @0x1424d0 ldr r0, [pc, #0xa58]
 *   @0x1424d4 mov r2, #0
 *   @0x1424d8 mov r3, r2
 *   @0x1424dc ldr r1, [r4, r1]
 *   @0x1424e0 add r0, pc, r0
 *   @0x1424e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #57 action_timeline_start → F_ActionTimelineStart(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1424e8 ldr r1, [pc, #0xa44]
 *   @0x1424ec ldr r0, [pc, #0xa44]
 *   @0x1424f0 mov r2, #0
 *   @0x1424f4 mov r3, r2
 *   @0x1424f8 ldr r1, [r4, r1]
 *   @0x1424fc add r0, pc, r0
 *   @0x142500 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #58 action_timeline_pause → F_ActionTimelinePause(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x142504 ldr r1, [pc, #0xa30]
 *   @0x142508 ldr r0, [pc, #0xa30]
 *   @0x14250c mov r2, #0
 *   @0x142510 mov r3, r2
 *   @0x142514 ldr r1, [r4, r1]
 *   @0x142518 add r0, pc, r0
 *   @0x14251c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #59 action_timeline_stop → F_ActionTimelineStop(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x142520 ldr r1, [pc, #0xa1c]
 *   @0x142524 ldr r0, [pc, #0xa1c]
 *   @0x142528 mov r2, #1
 *   @0x14252c mov r3, #0
 *   @0x142530 ldr r1, [r4, r1]
 *   @0x142534 add r0, pc, r0
 *   @0x142538 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #60 action_message → F_ActionMessage(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x14253c ldr r1, [pc, #0xa08]
 *   @0x142540 ldr r0, [pc, #0xa08]
 *   @0x142544 mov r2, #0
 *   @0x142548 mov r3, r2
 *   @0x14254c ldr r1, [r4, r1]
 *   @0x142550 add r0, pc, r0
 *   @0x142554 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #61 action_show_info → F_ActionShowInfo(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x142558 ldr r1, [pc, #0x9f4]
 *   @0x14255c ldr r0, [pc, #0x9f4]
 *   @0x142560 mov r2, #3
 *   @0x142564 mov r3, #1
 *   @0x142568 ldr r1, [r4, r1]
 *   @0x14256c add r0, pc, r0
 *   @0x142570 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #62 action_show_video → F_ActionShowVideo(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x142574 ldr r1, [pc, #0x9e0]
 *   @0x142578 ldr r0, [pc, #0x9e0]
 *   @0x14257c mov r2, #0
 *   @0x142580 mov r3, r2
 *   @0x142584 ldr r1, [r4, r1]
 *   @0x142588 add r0, pc, r0
 *   @0x14258c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #63 action_end_game → F_ActionEndGame(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x142590 ldr r1, [pc, #0x9cc]
 *   @0x142594 ldr r0, [pc, #0x9cc]
 *   @0x142598 mov r2, #0
 *   @0x14259c mov r3, r2
 *   @0x1425a0 ldr r1, [r4, r1]
 *   @0x1425a4 add r0, pc, r0
 *   @0x1425a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #64 action_restart_game → F_ActionRestartGame(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1425ac ldr r1, [pc, #0x9b8]
 *   @0x1425b0 ldr r0, [pc, #0x9b8]
 *   @0x1425b4 mov r2, #1
 *   @0x1425b8 mov r3, #0
 *   @0x1425bc ldr r1, [r4, r1]
 *   @0x1425c0 add r0, pc, r0
 *   @0x1425c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #65 action_save_game → F_ActionSaveGame(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1425c8 ldr r1, [pc, #0x9a4]
 *   @0x1425cc ldr r0, [pc, #0x9a4]
 *   @0x1425d0 mov r2, #1
 *   @0x1425d4 mov r3, #0
 *   @0x1425d8 ldr r1, [r4, r1]
 *   @0x1425dc add r0, pc, r0
 *   @0x1425e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #66 action_load_game → F_ActionLoadGame(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1425e4 ldr r1, [pc, #0x990]
 *   @0x1425e8 ldr r0, [pc, #0x990]
 *   @0x1425ec mov r2, #3
 *   @0x1425f0 mov r3, #1
 *   @0x1425f4 ldr r1, [r4, r1]
 *   @0x1425f8 add r0, pc, r0
 *   @0x1425fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #67 action_replace_sprite → F_ActionReplaceSprite(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x142600 ldr r1, [pc, #0x97c]
 *   @0x142604 ldr r0, [pc, #0x97c]
 *   @0x142608 mov r2, #2
 *   @0x14260c mov r3, #1
 *   @0x142610 ldr r1, [r4, r1]
 *   @0x142614 add r0, pc, r0
 *   @0x142618 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #68 action_replace_sound → F_ActionReplaceSound(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x14261c ldr r1, [pc, #0x968]
 *   @0x142620 ldr r0, [pc, #0x968]
 *   @0x142624 mov r2, #2
 *   @0x142628 mov r3, #1
 *   @0x14262c ldr r1, [r4, r1]
 *   @0x142630 add r0, pc, r0
 *   @0x142634 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #69 action_replace_background → F_ActionReplaceBackground(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x142638 ldr r1, [pc, #0x954]
 *   @0x14263c ldr r0, [pc, #0x954]
 *   @0x142640 mov r2, #3
 *   @0x142644 mov r3, #0
 *   @0x142648 ldr r1, [r4, r1]
 *   @0x14264c add r0, pc, r0
 *   @0x142650 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #70 action_if_empty → F_ActionIfEmpty(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x142654 ldr r1, [pc, #0x940]
 *   @0x142658 ldr r0, [pc, #0x940]
 *   @0x14265c mov r2, #3
 *   @0x142660 mov r3, #0
 *   @0x142664 ldr r1, [r4, r1]
 *   @0x142668 add r0, pc, r0
 *   @0x14266c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #71 action_if_collision → F_ActionIfCollision(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x142670 ldr r1, [pc, #0x92c]
 *   @0x142674 ldr r0, [pc, #0x92c]
 *   @0x142678 mov r2, #1
 *   @0x14267c mov r3, #0
 *   @0x142680 ldr r1, [r4, r1]
 *   @0x142684 add r0, pc, r0
 *   @0x142688 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #72 action_if → F_ActionIf(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x14268c ldr r1, [pc, #0x918]
 *   @0x142690 ldr r0, [pc, #0x918]
 *   @0x142694 mov r2, #3
 *   @0x142698 mov r3, #0
 *   @0x14269c ldr r1, [r4, r1]
 *   @0x1426a0 add r0, pc, r0
 *   @0x1426a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #73 action_if_number → F_ActionIfNumber(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x1426a8 ldr r1, [pc, #0x904]
 *   @0x1426ac ldr r0, [pc, #0x904]
 *   @0x1426b0 mov r2, #3
 *   @0x1426b4 mov r3, #0
 *   @0x1426b8 ldr r1, [r4, r1]
 *   @0x1426bc add r0, pc, r0
 *   @0x1426c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #74 action_if_object → F_ActionIfObject(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x1426c4 ldr r1, [pc, #0x8f0]
 *   @0x1426c8 ldr r0, [pc, #0x8f0]
 *   @0x1426cc mov r2, #1
 *   @0x1426d0 mov r3, #0
 *   @0x1426d4 ldr r1, [r4, r1]
 *   @0x1426d8 add r0, pc, r0
 *   @0x1426dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #75 action_if_question → F_ActionIfQuestion(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1426e0 ldr r1, [pc, #0x8dc]
 *   @0x1426e4 ldr r0, [pc, #0x8dc]
 *   @0x1426e8 mov r2, #1
 *   @0x1426ec mov r3, #0
 *   @0x1426f0 ldr r1, [r4, r1]
 *   @0x1426f4 add r0, pc, r0
 *   @0x1426f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #76 action_if_dice → F_ActionIfDice(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1426fc ldr r1, [pc, #0x8c8]
 *   @0x142700 ldr r0, [pc, #0x8c8]
 *   @0x142704 mov r2, #1
 *   @0x142708 mov r3, #0
 *   @0x14270c ldr r1, [r4, r1]
 *   @0x142710 add r0, pc, r0
 *   @0x142714 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #77 action_if_mouse → F_ActionIfMouse(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x142718 ldr r1, [pc, #0x8b4]
 *   @0x14271c ldr r0, [pc, #0x8b4]
 *   @0x142720 mov r2, #2
 *   @0x142724 mov r3, #0
 *   @0x142728 ldr r1, [r4, r1]
 *   @0x14272c add r0, pc, r0
 *   @0x142730 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #78 action_if_aligned → F_ActionIfAligned(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x142734 ldr r1, [pc, #0x8a0]
 *   @0x142738 ldr r0, [pc, #0x8a0]
 *   @0x14273c mov r2, #6
 *   @0x142740 mov r3, #0
 *   @0x142744 ldr r1, [r4, r1]
 *   @0x142748 add r0, pc, r0
 *   @0x14274c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #79 action_execute_script → F_ActionExecuteScript(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=0
 *   @0x142750 ldr r1, [pc, #0x88c]
 *   @0x142754 ldr r0, [pc, #0x88c]
 *   @0x142758 mov r2, #0
 *   @0x14275c mov r3, r2
 *   @0x142760 ldr r1, [r4, r1]
 *   @0x142764 add r0, pc, r0
 *   @0x142768 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #80 action_inherited → F_ActionInherited(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x14276c ldr r1, [pc, #0x878]
 *   @0x142770 ldr r0, [pc, #0x878]
 *   @0x142774 mov r2, #3
 *   @0x142778 mov r3, #0
 *   @0x14277c ldr r1, [r4, r1]
 *   @0x142780 add r0, pc, r0
 *   @0x142784 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #81 action_if_variable → F_ActionIfVariable(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x142788 ldr r1, [pc, #0x864]
 *   @0x14278c ldr r0, [pc, #0x864]
 *   @0x142790 mov r2, #3
 *   @0x142794 mov r3, #0
 *   @0x142798 ldr r1, [r4, r1]
 *   @0x14279c add r0, pc, r0
 *   @0x1427a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #82 action_draw_variable → F_ActionDrawVariable(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x1427a4 ldr r1, [pc, #0x850]
 *   @0x1427a8 ldr r0, [pc, #0x850]
 *   @0x1427ac mov r2, #1
 *   @0x1427b0 mov r3, #0
 *   @0x1427b4 ldr r1, [r4, r1]
 *   @0x1427b8 add r0, pc, r0
 *   @0x1427bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #83 action_set_score → F_ActionSetScore(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1427c0 ldr r1, [pc, #0x83c]
 *   @0x1427c4 ldr r0, [pc, #0x83c]
 *   @0x1427c8 mov r2, #2
 *   @0x1427cc mov r3, #0
 *   @0x1427d0 ldr r1, [r4, r1]
 *   @0x1427d4 add r0, pc, r0
 *   @0x1427d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #84 action_if_score → F_ActionIfScore(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1427dc ldr r1, [pc, #0x828]
 *   @0x1427e0 ldr r0, [pc, #0x828]
 *   @0x1427e4 mov r2, #3
 *   @0x1427e8 mov r3, #0
 *   @0x1427ec ldr r1, [r4, r1]
 *   @0x1427f0 add r0, pc, r0
 *   @0x1427f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #85 action_draw_score → F_ActionDrawScore(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x1427f8 ldr r1, [pc, #0x814]
 *   @0x1427fc ldr r0, [pc, #0x814]
 *   @0x142800 mov r2, #11
 *   @0x142804 mov r3, #0
 *   @0x142808 ldr r1, [r4, r1]
 *   @0x14280c add r0, pc, r0
 *   @0x142810 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #86 action_highscore_show → F_ActionHighscoreShow(RValue&, CInstance*, CInstance*, int, RValue*) argc=11 flag=0
 *   @0x142814 ldr r1, [pc, #0x800]
 *   @0x142818 ldr r0, [pc, #0x800]
 *   @0x14281c mov r2, #0
 *   @0x142820 mov r3, r2
 *   @0x142824 ldr r1, [r4, r1]
 *   @0x142828 add r0, pc, r0
 *   @0x14282c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #87 action_highscore_clear → F_ActionHighscoreClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x142830 ldr r1, [pc, #0x7ec]
 *   @0x142834 ldr r0, [pc, #0x7ec]
 *   @0x142838 mov r2, #1
 *   @0x14283c mov r3, #0
 *   @0x142840 ldr r1, [r4, r1]
 *   @0x142844 add r0, pc, r0
 *   @0x142848 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #88 action_set_life → F_ActionSetLife(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x14284c ldr r1, [pc, #0x7d8]
 *   @0x142850 ldr r0, [pc, #0x7d8]
 *   @0x142854 mov r2, #2
 *   @0x142858 mov r3, #0
 *   @0x14285c ldr r1, [r4, r1]
 *   @0x142860 add r0, pc, r0
 *   @0x142864 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #89 action_if_life → F_ActionIfLife(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x142868 ldr r1, [pc, #0x7c4]
 *   @0x14286c ldr r0, [pc, #0x7c4]
 *   @0x142870 mov r2, #3
 *   @0x142874 mov r3, #0
 *   @0x142878 ldr r1, [r4, r1]
 *   @0x14287c add r0, pc, r0
 *   @0x142880 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #90 action_draw_life → F_ActionDrawLife(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x142884 ldr r1, [pc, #0x7b0]
 *   @0x142888 ldr r0, [pc, #0x7b0]
 *   @0x14288c mov r2, #3
 *   @0x142890 mov r3, #0
 *   @0x142894 ldr r1, [r4, r1]
 *   @0x142898 add r0, pc, r0
 *   @0x14289c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #91 action_draw_life_images → F_ActionDrawLifeImages(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x1428a0 ldr r1, [pc, #0x79c]
 *   @0x1428a4 ldr r0, [pc, #0x79c]
 *   @0x1428a8 mov r2, #1
 *   @0x1428ac mov r3, #0
 *   @0x1428b0 ldr r1, [r4, r1]
 *   @0x1428b4 add r0, pc, r0
 *   @0x1428b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #92 action_set_health → F_ActionSetHealth(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1428bc ldr r1, [pc, #0x788]
 *   @0x1428c0 ldr r0, [pc, #0x788]
 *   @0x1428c4 mov r2, #2
 *   @0x1428c8 mov r3, #0
 *   @0x1428cc ldr r1, [r4, r1]
 *   @0x1428d0 add r0, pc, r0
 *   @0x1428d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #93 action_if_health → F_ActionIfHealth(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1428d8 ldr r1, [pc, #0x774]
 *   @0x1428dc ldr r0, [pc, #0x774]
 *   @0x1428e0 mov r2, #6
 *   @0x1428e4 mov r3, #0
 *   @0x1428e8 ldr r1, [r4, r1]
 *   @0x1428ec add r0, pc, r0
 *   @0x1428f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #94 action_draw_health → F_ActionDrawHealth(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=0
 *   @0x1428f4 ldr r1, [pc, #0x760]
 *   @0x1428f8 ldr r0, [pc, #0x760]
 *   @0x1428fc mov r2, #6
 *   @0x142900 mov r3, #0
 *   @0x142904 ldr r1, [r4, r1]
 *   @0x142908 add r0, pc, r0
 *   @0x14290c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #95 action_set_caption → F_ActionSetCaption(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=0
 *   @0x142910 ldr r1, [pc, #0x74c]
 *   @0x142914 ldr r0, [pc, #0x74c]
 *   @0x142918 mov r2, #1
 *   @0x14291c mov r3, r2
 *   @0x142920 ldr r1, [r4, r1]
 *   @0x142924 add r0, pc, r0
 *   @0x142928 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #96 action_partsyst_create → F_ActionPartSystCreate(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x14292c ldr r1, [pc, #0x738]
 *   @0x142930 ldr r0, [pc, #0x738]
 *   @0x142934 mov r2, #0
 *   @0x142938 mov r3, #1
 *   @0x14293c ldr r1, [r4, r1]
 *   @0x142940 add r0, pc, r0
 *   @0x142944 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #97 action_partsyst_destroy → F_ActionPartSystDestroy(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x142948 ldr r1, [pc, #0x724]
 *   @0x14294c ldr r0, [pc, #0x724]
 *   @0x142950 mov r2, #0
 *   @0x142954 mov r3, #1
 *   @0x142958 ldr r1, [r4, r1]
 *   @0x14295c add r0, pc, r0
 *   @0x142960 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #98 action_partsyst_clear → F_ActionPartSystClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x142964 ldr r1, [pc, #0x710]
 *   @0x142968 ldr r0, [pc, #0x710]
 *   @0x14296c mov r2, #6
 *   @0x142970 mov r3, #1
 *   @0x142974 ldr r1, [r4, r1]
 *   @0x142978 add r0, pc, r0
 *   @0x14297c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #99 action_parttype_create_old → F_ActionPartTypeCreateOld(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x142980 ldr r1, [pc, #0x6fc]
 *   @0x142984 ldr r0, [pc, #0x6fc]
 *   @0x142988 mov r2, #6
 *   @0x14298c mov r3, #1
 *   @0x142990 ldr r1, [r4, r1]
 *   @0x142994 add r0, pc, r0
 *   @0x142998 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #100 action_parttype_create → F_ActionPartTypeCreate(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x14299c ldr r1, [pc, #0x6e8]
 *   @0x1429a0 ldr r0, [pc, #0x6e8]
 *   @0x1429a4 mov r2, #6
 *   @0x1429a8 mov r3, #1
 *   @0x1429ac ldr r5, [r4, r1]
 *   @0x1429b0 add r0, pc, r0
 *   @0x1429b4 mov r1, r5
 *   @0x1429b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #101 action_parttype_color → F_ActionPartTypeColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x1429bc ldr r0, [pc, #0x6d0]
 *   @0x1429c0 mov r1, r5
 *   @0x1429c4 mov r2, #6
 *   @0x1429c8 add r0, pc, r0
 *   @0x1429cc mov r3, #1
 *   @0x1429d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #102 action_parttype_colour → F_ActionPartTypeColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x1429d4 ldr r1, [pc, #0x6bc]
 *   @0x1429d8 ldr r0, [pc, #0x6bc]
 *   @0x1429dc mov r2, #3
 *   @0x1429e0 mov r3, #1
 *   @0x1429e4 ldr r1, [r4, r1]
 *   @0x1429e8 add r0, pc, r0
 *   @0x1429ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #103 action_parttype_life → F_ActionPartTypeLife(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x1429f0 ldr r1, [pc, #0x6a8]
 *   @0x1429f4 ldr r0, [pc, #0x6a8]
 *   @0x1429f8 mov r2, #6
 *   @0x1429fc mov r3, #1
 *   @0x142a00 ldr r1, [r4, r1]
 *   @0x142a04 add r0, pc, r0
 *   @0x142a08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #104 action_parttype_speed → F_ActionPartTypeSpeed(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x142a0c ldr r1, [pc, #0x694]
 *   @0x142a10 ldr r0, [pc, #0x694]
 *   @0x142a14 mov r2, #3
 *   @0x142a18 mov r3, #1
 *   @0x142a1c ldr r1, [r4, r1]
 *   @0x142a20 add r0, pc, r0
 *   @0x142a24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #105 action_parttype_gravity → F_ActionPartTypeGravity(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x142a28 ldr r1, [pc, #0x680]
 *   @0x142a2c ldr r0, [pc, #0x680]
 *   @0x142a30 mov r2, #5
 *   @0x142a34 mov r3, #1
 *   @0x142a38 ldr r1, [r4, r1]
 *   @0x142a3c add r0, pc, r0
 *   @0x142a40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #106 action_parttype_secondary → F_ActionPartTypeSecondary(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x142a44 ldr r1, [pc, #0x66c]
 *   @0x142a48 ldr r0, [pc, #0x66c]
 *   @0x142a4c mov r2, #6
 *   @0x142a50 mov r3, #1
 *   @0x142a54 ldr r1, [r4, r1]
 *   @0x142a58 add r0, pc, r0
 *   @0x142a5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #107 action_partemit_create → F_ActionPartEmitCreate(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x142a60 ldr r1, [pc, #0x658]
 *   @0x142a64 ldr r0, [pc, #0x658]
 *   @0x142a68 mov r2, #1
 *   @0x142a6c mov r3, r2
 *   @0x142a70 ldr r1, [r4, r1]
 *   @0x142a74 add r0, pc, r0
 *   @0x142a78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #108 action_partemit_destroy → F_ActionPartEmitDestroy(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x142a7c ldr r1, [pc, #0x644]
 *   @0x142a80 ldr r0, [pc, #0x644]
 *   @0x142a84 mov r2, #3
 *   @0x142a88 mov r3, #1
 *   @0x142a8c ldr r1, [r4, r1]
 *   @0x142a90 add r0, pc, r0
 *   @0x142a94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #109 action_partemit_burst → F_ActionPartEmitBurst(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x142a98 ldr r1, [pc, #0x630]
 *   @0x142a9c ldr r0, [pc, #0x630]
 *   @0x142aa0 mov r2, #3
 *   @0x142aa4 mov r3, #1
 *   @0x142aa8 ldr r1, [r4, r1]
 *   @0x142aac add r0, pc, r0
 *   @0x142ab0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #110 action_partemit_stream → F_ActionPartEmitStream(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x142ab4 ldr r1, [pc, #0x61c]
 *   @0x142ab8 ldr r0, [pc, #0x61c]
 *   @0x142abc mov r2, #2
 *   @0x142ac0 mov r3, #1
 *   @0x142ac4 ldr r1, [r4, r1]
 *   @0x142ac8 add r0, pc, r0
 *   @0x142acc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #111 action_cd_play → F_ActionCDPlay(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x142ad0 ldr r1, [pc, #0x608]
 *   @0x142ad4 ldr r0, [pc, #0x608]
 *   @0x142ad8 mov r2, #0
 *   @0x142adc mov r3, #1
 *   @0x142ae0 ldr r1, [r4, r1]
 *   @0x142ae4 add r0, pc, r0
 *   @0x142ae8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #112 action_cd_stop → F_ActionCDStop(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x142aec ldr r1, [pc, #0x5f4]
 *   @0x142af0 ldr r0, [pc, #0x5f4]
 *   @0x142af4 mov r2, #0
 *   @0x142af8 mov r3, #1
 *   @0x142afc ldr r1, [r4, r1]
 *   @0x142b00 add r0, pc, r0
 *   @0x142b04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #113 action_cd_pause → F_ActionCDPause(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x142b08 ldr r1, [pc, #0x5e0]
 *   @0x142b0c ldr r0, [pc, #0x5e0]
 *   @0x142b10 mov r2, #0
 *   @0x142b14 mov r3, #1
 *   @0x142b18 ldr r1, [r4, r1]
 *   @0x142b1c add r0, pc, r0
 *   @0x142b20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #114 action_cd_resume → F_ActionCDResume(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x142b24 ldr r1, [pc, #0x5cc]
 *   @0x142b28 ldr r0, [pc, #0x5cc]
 *   @0x142b2c mov r2, #0
 *   @0x142b30 mov r3, #1
 *   @0x142b34 ldr r1, [r4, r1]
 *   @0x142b38 add r0, pc, r0
 *   @0x142b3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #115 action_cd_present → F_ActionCDPresent(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x142b40 ldr r1, [pc, #0x5b8]
 *   @0x142b44 ldr r0, [pc, #0x5b8]
 *   @0x142b48 mov r2, #0
 *   @0x142b4c mov r3, #1
 *   @0x142b50 ldr r1, [r4, r1]
 *   @0x142b54 add r0, pc, r0
 *   @0x142b58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #116 action_cd_playing → F_ActionCDPlaying(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x142b5c ldr r1, [pc, #0x5a4]
 *   @0x142b60 ldr r0, [pc, #0x5a4]
 *   @0x142b64 mov r2, #2
 *   @0x142b68 mov r3, #1
 *   @0x142b6c ldr r1, [r4, r1]
 *   @0x142b70 add r0, pc, r0
 *   @0x142b74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #117 action_set_cursor → F_ActionSetCursor(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x142b78 ldr r1, [pc, #0x590]
 *   @0x142b7c ldr r0, [pc, #0x590]
 *   @0x142b80 mov r2, #1
 *   @0x142b84 mov r3, r2
 *   @0x142b88 ldr r1, [r4, r1]
 *   @0x142b8c add r0, pc, r0
 *   @0x142b90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #118 action_webpage → F_ActionWebpage(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x142b94 ldr r1, [pc, #0x57c]
 *   @0x142b98 ldr r0, [pc, #0x57c]
 *   @0x142b9c mov r2, #4
 *   @0x142ba0 mov r3, #0
 *   @0x142ba4 ldr r1, [r4, r1]
 *   @0x142ba8 add r0, pc, r0
 *   @0x142bac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #119 action_draw_sprite → F_ActionDrawSprite(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x142bb0 ldr r1, [pc, #0x568]
 *   @0x142bb4 ldr r0, [pc, #0x568]
 *   @0x142bb8 mov r2, #4
 *   @0x142bbc mov r3, #0
 *   @0x142bc0 ldr r1, [r4, r1]
 *   @0x142bc4 add r0, pc, r0
 *   @0x142bc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #120 action_draw_background → F_ActionDrawBackground(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x142bcc ldr r1, [pc, #0x554]
 *   @0x142bd0 ldr r0, [pc, #0x554]
 *   @0x142bd4 mov r2, #3
 *   @0x142bd8 mov r3, #0
 *   @0x142bdc ldr r1, [r4, r1]
 *   @0x142be0 add r0, pc, r0
 *   @0x142be4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #121 action_draw_text → F_ActionDrawText(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x142be8 ldr r1, [pc, #0x540]
 *   @0x142bec ldr r0, [pc, #0x540]
 *   @0x142bf0 mov r2, #6
 *   @0x142bf4 mov r3, #1
 *   @0x142bf8 ldr r1, [r4, r1]
 *   @0x142bfc add r0, pc, r0
 *   @0x142c00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #122 action_draw_text_transformed → F_ActionDrawTextTransformed(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x142c04 ldr r1, [pc, #0x52c]
 *   @0x142c08 ldr r0, [pc, #0x52c]
 *   @0x142c0c mov r2, #5
 *   @0x142c10 mov r3, #0
 *   @0x142c14 ldr r1, [r4, r1]
 *   @0x142c18 add r0, pc, r0
 *   @0x142c1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #123 action_draw_rectangle → F_ActionDrawRectangle(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0x142c20 ldr r1, [pc, #0x518]
 *   @0x142c24 ldr r0, [pc, #0x518]
 *   @0x142c28 mov r2, #6
 *   @0x142c2c mov r3, #1
 *   @0x142c30 ldr r1, [r4, r1]
 *   @0x142c34 add r0, pc, r0
 *   @0x142c38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #124 action_draw_gradient_hor → F_ActionDrawGradientHor(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x142c3c ldr r1, [pc, #0x504]
 *   @0x142c40 ldr r0, [pc, #0x504]
 *   @0x142c44 mov r2, #6
 *   @0x142c48 mov r3, #1
 *   @0x142c4c ldr r1, [r4, r1]
 *   @0x142c50 add r0, pc, r0
 *   @0x142c54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #125 action_draw_gradient_vert → F_ActionDrawGradientVert(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x142c58 ldr r1, [pc, #0x4f0]
 *   @0x142c5c ldr r0, [pc, #0x4f0]
 *   @0x142c60 mov r2, #5
 *   @0x142c64 mov r3, #0
 *   @0x142c68 ldr r1, [r4, r1]
 *   @0x142c6c add r0, pc, r0
 *   @0x142c70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #126 action_draw_ellipse → F_ActionDrawEllipse(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0x142c74 ldr r1, [pc, #0x4dc]
 *   @0x142c78 ldr r0, [pc, #0x4dc]
 *   @0x142c7c mov r2, #6
 *   @0x142c80 mov r3, #1
 *   @0x142c84 ldr r1, [r4, r1]
 *   @0x142c88 add r0, pc, r0
 *   @0x142c8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #127 action_draw_ellipse_gradient → F_ActionDrawEllipseGradient(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x142c90 ldr r1, [pc, #0x4c8]
 *   @0x142c94 ldr r0, [pc, #0x4c8]
 *   @0x142c98 mov r2, #4
 *   @0x142c9c mov r3, #0
 *   @0x142ca0 ldr r1, [r4, r1]
 *   @0x142ca4 add r0, pc, r0
 *   @0x142ca8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #128 action_draw_line → F_ActionDrawLine(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x142cac ldr r1, [pc, #0x4b4]
 *   @0x142cb0 ldr r0, [pc, #0x4b4]
 *   @0x142cb4 mov r2, #5
 *   @0x142cb8 mov r3, #0
 *   @0x142cbc ldr r1, [r4, r1]
 *   @0x142cc0 add r0, pc, r0
 *   @0x142cc4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #129 action_draw_arrow → F_ActionDrawArrow(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0x142cc8 ldr r1, [pc, #0x4a0]
 *   @0x142ccc ldr r0, [pc, #0x4a0]
 *   @0x142cd0 mov r2, #1
 *   @0x142cd4 mov r3, #0
 *   @0x142cd8 ldr r5, [r4, r1]
 *   @0x142cdc add r0, pc, r0
 *   @0x142ce0 mov r1, r5
 *   @0x142ce4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #130 action_color → F_ActionColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x142ce8 ldr r0, [pc, #0x488]
 *   @0x142cec mov r1, r5
 *   @0x142cf0 mov r2, #1
 *   @0x142cf4 add r0, pc, r0
 *   @0x142cf8 mov r3, #0
 *   @0x142cfc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #131 action_colour → F_ActionColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x142d00 ldr r1, [pc, #0x474]
 *   @0x142d04 ldr r0, [pc, #0x474]
 *   @0x142d08 mov r2, #2
 *   @0x142d0c mov r3, #0
 *   @0x142d10 ldr r1, [r4, r1]
 *   @0x142d14 add r0, pc, r0
 *   @0x142d18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #132 action_font → F_ActionFont(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x142d1c ldr r1, [pc, #0x460]
 *   @0x142d20 ldr r0, [pc, #0x460]
 *   @0x142d24 mov r2, #1
 *   @0x142d28 mov r3, #0
 *   @0x142d2c ldr r1, [r4, r1]
 *   @0x142d30 add r0, pc, r0
 *   @0x142d34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #133 action_fullscreen → F_ActionFullScreen(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x142d38 ldr r1, [pc, #0x44c]
 *   @0x142d3c ldr r0, [pc, #0x44c]
 *   @0x142d40 mov r2, #1
 *   @0x142d44 mov r3, r2
 *   @0x142d48 ldr r1, [r4, r1]
 *   @0x142d4c add r0, pc, r0
 *   @0x142d50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #134 action_snapshot → F_ActionSnapshot(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x142d54 ldr r1, [pc, #0x438]
 *   @0x142d58 ldr r0, [pc, #0x438]
 *   @0x142d5c mov r2, #6
 *   @0x142d60 mov r3, #1
 *   @0x142d64 ldr r1, [r4, r1]
 *   @0x142d68 add r0, pc, r0
 *   @0x142d6c pop {r4, r5, r6, lr}
 *   @0x142d70 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #135 action_effect → F_ActionEffect(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x142d74 .word 0x002afdd8
 *   @0x142d78 .word 0xffffd78c
 *   @0x142d7c .word 0xffffd790
 *   @0x142d80 .word 0xffffd794
 *   @0x142d84 .word 0xffffd7a0
 *   @0x142d88 andseq lr, pc, r8, ror #23
 *   @0x142d8c .word 0xffffd7a4
 *   @0x142d90 ldrsbeq lr, [pc], -r8
 *   @0x142d94 ldrsbeq lr, [pc], -r8
 *   @0x142d98 ldrsbeq lr, [pc], -r4
 *   @0x142d9c ldrsbeq lr, [pc], -r4
 *   @0x142da0 ldrsbeq lr, [pc], -r0
 *   @0x142da4 andseq lr, pc, r12, asr #23
 *   @0x142da8 andseq lr, pc, r8, asr #23
 *   @0x142dac andseq lr, pc, r0, asr #23
 *   @0x142db0 .word 0xffffd7a8
 *   @0x142db4 ldrheq lr, [pc], -r8
 *   @0x142db8 .word 0xffffd7ac
 *   @0x142dbc ldrheq lr, [pc], -r0
 *   @0x142dc0 .word 0xffffd7b0
 *   @0x142dc4 andseq lr, pc, r0, lsr #23
 *   @0x142dc8 .word 0xffffd7b4
 *   @0x142dcc mulseq pc, r8, r11
 *   @0x142dd0 .word 0xffffd7b8
 *   @0x142dd4 mulseq pc, r0, r11
 *   @0x142dd8 .word 0xffffd7bc
 *   @0x142ddc andseq lr, pc, r8, lsl #23
 *   @0x142de0 .word 0xffffd7c0
 *   @0x142de4 andseq lr, pc, r0, lsl #23
 *   @0x142de8 .word 0xffffd7c4
 *   @0x142dec andseq lr, pc, r8, ror r11
 *   @0x142df0 .word 0xffffd7c8
 *   @0x142df4 andseq lr, pc, r0, ror r11
 *   @0x142df8 .word 0xffffd7cc
 *   @0x142dfc andseq lr, pc, r4, ror #22
 *   @0x142e00 .word 0xffffd7d0
 *   @0x142e04 andseq lr, pc, r12, asr r11
 *   @0x142e08 .word 0xffffd7d4
 *   @0x142e0c andseq lr, pc, r4, asr r11
 *   @0x142e10 .word 0xffffd7d8
 *   @0x142e14 andseq lr, pc, r4, asr #22
 *   @0x142e18 .word 0xffffd7dc
 *   @0x142e1c andseq lr, pc, r4, lsr r11
 *   @0x142e20 .word 0xffffd7e0
 *   @0x142e24 andseq lr, pc, r12, lsr #22
 *   @0x142e28 .word 0xffffd7e4
 *   @0x142e2c andseq lr, pc, r4, lsr #22
 *   @0x142e30 .word 0xffffd7e8
 *   @0x142e34 andseq lr, pc, r12, lsl r11
 *   @0x142e38 .word 0xffffd7ec
 *   @0x142e3c andseq lr, pc, r0, lsl r11
 *   @0x142e40 .word 0xffffd7f0
 *   @0x142e44 andseq lr, pc, r0, lsl #22
 *   @0x142e48 .word 0xffffd7f4
 *   @0x142e4c ldrsheq lr, [pc], -r4
 *   @0x142e50 .word 0xffffd7f8
 *   @0x142e54 ldrsheq lr, [pc], -r0
 *   @0x142e58 .word 0xffffd7fc
 *   @0x142e5c andseq lr, pc, r8, ror #21
 *   @0x142e60 .word 0xffffd800
 *   @0x142e64 andseq lr, pc, r0, ror #21
 *   @0x142e68 .word 0xffffd804
 *   @0x142e6c ldrsbeq lr, [pc], -r12
 *   @0x142e70 .word 0xffffd808
 *   @0x142e74 ldrsbeq lr, [pc], -r4
 *   @0x142e78 .word 0xffffd80c
 *   @0x142e7c ldrsbeq lr, [pc], -r0
 *   @0x142e80 .word 0xffffd810
 *   @0x142e84 ldrsbeq lr, [pc], -r0
 *   @0x142e88 .word 0xffffd814
 *   @0x142e8c ldrsbeq lr, [pc], -r0
 *   @0x142e90 .word 0xffffd818
 *   @0x142e94 andseq lr, pc, r12, asr #21
 *   @0x142e98 .word 0xffffd81c
 *   @0x142e9c andseq lr, pc, r8, asr #21
 *   @0x142ea0 .word 0xffffd820
 *   @0x142ea4 andseq lr, pc, r0, asr #21
 *   @0x142ea8 .word 0xffffd824
 *   @0x142eac ldrheq lr, [pc], -r12
 *   @0x142eb0 ldrheq lr, [pc], -r8
 *   @0x142eb4 .word 0xffffd828
 *   @0x142eb8 ldrheq lr, [pc], -r0
 *   @0x142ebc .word 0xffffd82c
 *   @0x142ec0 andseq lr, pc, r4, lsr #21
 *   @0x142ec4 .word 0xffffd830
 *   @0x142ec8 mulseq pc, r12, r10
 *   @0x142ecc .word 0xffffd834
 *   @0x142ed0 mulseq pc, r0, r10
 *   @0x142ed4 .word 0xffffd838
 *   @0x142ed8 andseq lr, pc, r8, lsl #21
 *   @0x142edc .word 0xffffd83c
 *   @0x142ee0 andseq lr, pc, r0, lsl #21
 *   @0x142ee4 .word 0xffffd840
 *   @0x142ee8 andseq lr, pc, r12, ror r10
 *   @0x142eec .word 0xffffd844
 *   @0x142ef0 andseq lr, pc, r4, ror r10
 *   @0x142ef4 .word 0xffffd848
 *   @0x142ef8 andseq lr, pc, r0, ror r10
 *   @0x142efc .word 0xffffd84c
 *   @0x142f00 andseq lr, pc, r8, ror #20
 *   @0x142f04 .word 0xffffd850
 *   @0x142f08 andseq lr, pc, r0, ror #20
 *   @0x142f0c .word 0xffffd854
 *   @0x142f10 andseq lr, pc, r4, asr r10
 *   @0x142f14 .word 0xffffd858
 *   @0x142f18 andseq lr, pc, r12, asr #20
 *   @0x142f1c .word 0xffffd85c
 *   @0x142f20 andseq lr, pc, r0, asr r10
 *   @0x142f24 .word 0xffffd860
 *   @0x142f28 andseq lr, pc, r0, asr r10
 *   @0x142f2c .word 0xffffd864
 *   @0x142f30 andseq lr, pc, r8, asr #20
 *   @0x142f34 .word 0xffffd868
 *   @0x142f38 andseq lr, pc, r4, asr #20
 *   @0x142f3c .word 0xffffd86c
 *   @0x142f40 andseq lr, pc, r0, asr #20
 *   @0x142f44 .word 0xffffd870
 *   @0x142f48 andseq lr, pc, r12, lsr r10
 *   @0x142f4c .word 0xffffd874
 *   @0x142f50 andseq lr, pc, r0, lsr r10
 *   @0x142f54 .word 0xffffd878
 *   @0x142f58 andseq lr, pc, r8, lsr #20
 *   @0x142f5c .word 0xffffd87c
 *   @0x142f60 andseq lr, pc, r0, lsr #20
 *   @0x142f64 .word 0xffffd880
 *   @0x142f68 andseq lr, pc, r4, lsl r10
 *   @0x142f6c .word 0xffffd884
 *   @0x142f70 andseq lr, pc, r12, lsl #20
 *   @0x142f74 .word 0xffffd888
 *   @0x142f78 andseq lr, pc, r4, lsl #20
 *   @0x142f7c .word 0xffffd88c
 *   @0x142f80 ldrsheq lr, [pc], -r12
 *   @0x142f84 .word 0xffffd890
 *   @0x142f88 ldrsheq lr, [pc], -r8
 *   @0x142f8c .word 0xffffd894
 *   @0x142f90 ldrsheq lr, [pc], -r4
 *   @0x142f94 .word 0xffffd898
 *   @0x142f98 ldrsheq lr, [pc], -r4
 *   @0x142f9c .word 0xffffd89c
 *   @0x142fa0 andseq lr, pc, r8, ror #19
 *   @0x142fa4 .word 0xffffd8a0
 *   @0x142fa8 andseq lr, pc, r0, ror #19
 *   @0x142fac .word 0xffffd8a4
 *   @0x142fb0 ldrsbeq lr, [pc], -r0
 *   @0x142fb4 .word 0xffffd8a8
 *   @0x142fb8 andseq lr, pc, r8, asr #19
 *   @0x142fbc .word 0xffffd8ac
 *   @0x142fc0 andseq lr, pc, r0, asr #19
 *   @0x142fc4 .word 0xffffd8b0
 *   @0x142fc8 ldrheq lr, [pc], -r8
 *   @0x142fcc .word 0xffffd8b4
 *   @0x142fd0 andseq lr, pc, r12, lsr #19
 *   @0x142fd4 .word 0xffffd8b8
 *   @0x142fd8 andseq lr, pc, r0, lsr #19
 *   @0x142fdc .word 0xffffd8bc
 *   @0x142fe0 mulseq pc, r8, r9
 *   @0x142fe4 .word 0xffffd8c0
 *   @0x142fe8 mulseq pc, r4, r9
 *   @0x142fec .word 0xffffd8c4
 *   @0x142ff0 andseq lr, pc, r12, lsl #19
 *   @0x142ff4 .word 0xffffd8c8
 *   @0x142ff8 andseq lr, pc, r4, lsl #19
 *   @0x142ffc .word 0xffffd8cc
 *   @0x143000 andseq lr, pc, r0, lsl #19
 *   @0x143004 .word 0xffffd8d0
 *   @0x143008 andseq lr, pc, r8, ror r9
 *   @0x14300c .word 0xffffd8d4
 *   @0x143010 andseq lr, pc, r12, ror #18
 *   @0x143014 .word 0xffffd8d8
 *   @0x143018 andseq lr, pc, r4, ror #18
 *   @0x14301c .word 0xffffd8dc
 *   @0x143020 andseq lr, pc, r0, ror #18
 *   @0x143024 .word 0xffffd8e0
 *   @0x143028 andseq lr, pc, r12, asr r9
 *   @0x14302c .word 0xffffd8e4
 *   @0x143030 andseq lr, pc, r0, asr r9
 *   @0x143034 .word 0xffffd8e8
 *   @0x143038 andseq lr, pc, r4, asr #18
 *   @0x14303c .word 0xffffd8ec
 *   @0x143040 andseq lr, pc, r12, lsr r9
 *   @0x143044 .word 0xffffd8f0
 *   @0x143048 andseq lr, pc, r8, lsr r9
 *   @0x14304c .word 0xffffd8f4
 *   @0x143050 andseq lr, pc, r0, lsr r9
 *   @0x143054 .word 0xffffd8f8
 *   @0x143058 andseq lr, pc, r8, lsr #18
 *   @0x14305c .word 0xffffd8fc
 *   @0x143060 andseq lr, pc, r0, lsr #18
 *   @0x143064 .word 0xffffd900
 *   @0x143068 andseq lr, pc, r8, lsl r9
 *   @0x14306c .word 0xffffd904
 *   @0x143070 andseq lr, pc, r4, lsl r9
 *   @0x143074 .word 0xffffd908
 *   @0x143078 andseq lr, pc, r0, lsl r9
 *   @0x14307c .word 0xffffd90c
 *   @0x143080 andseq lr, pc, r12, lsl #18
 *   @0x143084 .word 0xffffd910
 *   @0x143088 andseq lr, pc, r12, lsl #18
 *   @0x14308c .word 0xffffd914
 *   @0x143090 andseq lr, pc, r8, lsl #18
 *   @0x143094 andseq lr, pc, r8, lsl #18
 *   @0x143098 .word 0xffffd918
 *   @0x14309c andseq lr, pc, r0, lsl #18
 *   @0x1430a0 .word 0xffffd91c
 *   @0x1430a4 ldrsheq lr, [pc], -r12
 *   @0x1430a8 .word 0xffffd920
 *   @0x1430ac ldrsheq lr, [pc], -r8
 *   @0x1430b0 .word 0xffffd924
 *   @0x1430b4 ldrsheq lr, [pc], -r4
 *   @0x1430b8 .word 0xffffd928
 *   @0x1430bc ldrsheq lr, [pc], -r4
 *   @0x1430c0 .word 0xffffd92c
 *   @0x1430c4 ldrsheq lr, [pc], -r0
 *   @0x1430c8 .word 0xffffd930
 *   @0x1430cc andseq lr, pc, r12, ror #17
 *   @0x1430d0 .word 0xffffd934
 *   @0x1430d4 andseq lr, pc, r8, ror #17
 *   @0x1430d8 .word 0xffffd938
 *   @0x1430dc andseq lr, pc, r4, ror #17
 *   @0x1430e0 .word 0xffffd93c
 *   @0x1430e4 ldrsbeq lr, [pc], -r8
 *   @0x1430e8 .word 0xffffd940
 *   @0x1430ec andseq lr, pc, r12, asr #17
 *   @0x1430f0 .word 0xffffd944
 *   @0x1430f4 andseq lr, pc, r0, asr #17
 *   @0x1430f8 .word 0xffffd948
 *   @0x1430fc ldrheq lr, [pc], -r8
 *   @0x143100 .word 0xffffd94c
 *   @0x143104 ldrheq lr, [pc], -r0
 *   @0x143108 .word 0xffffd950
 *   @0x14310c andseq lr, pc, r8, lsr #17
 *   @0x143110 .word 0xffffd954
 *   @0x143114 andseq lr, pc, r0, lsr #17
 *   @0x143118 .word 0xffffd958
 *   @0x14311c mulseq pc, r4, r8
 *   @0x143120 .word 0xffffd95c
 *   @0x143124 andseq lr, pc, r12, lsl #17
 *   @0x143128 .word 0xffffd960
 *   @0x14312c andseq lr, pc, r8, lsl #17
 *   @0x143130 .word 0xffffd964
 *   @0x143134 andseq lr, pc, r0, lsl #17
 *   @0x143138 .word 0xffffd968
 *   @0x14313c andseq lr, pc, r4, lsl #17
 *   @0x143140 .word 0xffffd96c
 *   @0x143144 andseq lr, pc, r0, lsl #17
 *   @0x143148 .word 0xffffd970
 *   @0x14314c andseq lr, pc, r0, lsl #17
 *   @0x143150 .word 0xffffd974
 *   @0x143154 andseq lr, pc, r0, lsl #17
 *   @0x143158 .word 0xffffd978
 *   @0x14315c andseq lr, pc, r8, ror r8
 *   @0x143160 .word 0xffffd97c
 *   @0x143164 andseq lr, pc, r12, ror r8
 *   @0x143168 .word 0xffffd980
 *   @0x14316c andseq lr, pc, r4, ror r8
 *   @0x143170 .word 0xffffd984
 *   @0x143174 andseq lr, pc, r12, ror #16
 *   @0x143178 andseq lr, pc, r4, ror #16
 *   @0x14317c .word 0xffffd988
 *   @0x143180 andseq lr, pc, r4, asr r8
 *   @0x143184 .word 0xffffd98c
 *   @0x143188 andseq lr, pc, r4, asr #16
 *   @0x14318c .word 0xffffd990
 *   @0x143190 andseq lr, pc, r12, lsr r8
 *   @0x143194 .word 0xffffd994
 *   @0x143198 andseq lr, pc, r0, lsr r8
 *
 * ══ §3/6 InitGamepadFunctions  0x152c9c..0x152ff4  size 856  214 条（169 条指令 + 45 个池字）══
 * @func 0x152c9c 0x152ff4  size 856  214 条
 * 注册 21 条｜唯一名 21｜唯一函数指针 20｜argc 0:3 1:8 2:9 3:1｜flag 1:21
 * 首条 #0 gamepad_is_supported（0x152cc0）→ 末条 #20 gamepad_set_colour（0x152ef0）
 * 名字族（前 8）: gamepad×21
 * 游戏实际调用的 99 个内建里落在本表: 0 个
 * 条件跳转 1 处: 0x152f30(beq)
 * 表: asm/init-tables/init-InitGamepadFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: 无（本函数每条注册的四实参全部解出，控制流全部走到）
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x152c9c push {r3, r4, r5, lr}
 *   @0x152ca0 mov r2, #0
 *   @0x152ca4 ldr r4, [pc, #0x294]
 *   @0x152ca8 mov r3, #1
 *   @0x152cac ldr r1, [pc, #0x290]
 *   @0x152cb0 add r4, pc, r4
 *   @0x152cb4 ldr r0, [pc, #0x28c]
 *   @0x152cb8 ldr r1, [r4, r1]
 *   @0x152cbc add r0, pc, r0
 *   @0x152cc0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 gamepad_is_supported → F_GamepadSupported(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x152cc4 ldr r1, [pc, #0x280]
 *   @0x152cc8 ldr r0, [pc, #0x280]
 *   @0x152ccc mov r2, #0
 *   @0x152cd0 mov r3, #1
 *   @0x152cd4 ldr r1, [r4, r1]
 *   @0x152cd8 add r0, pc, r0
 *   @0x152cdc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 gamepad_get_device_count → F_GamepadGetDeviceCount(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x152ce0 ldr r1, [pc, #0x26c]
 *   @0x152ce4 ldr r0, [pc, #0x26c]
 *   @0x152ce8 mov r2, #1
 *   @0x152cec mov r3, r2
 *   @0x152cf0 ldr r1, [r4, r1]
 *   @0x152cf4 add r0, pc, r0
 *   @0x152cf8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 gamepad_is_connected → F_GamepadConnected(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x152cfc ldr r1, [pc, #0x258]
 *   @0x152d00 ldr r0, [pc, #0x258]
 *   @0x152d04 mov r2, #1
 *   @0x152d08 mov r3, r2
 *   @0x152d0c ldr r1, [r4, r1]
 *   @0x152d10 add r0, pc, r0
 *   @0x152d14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 gamepad_get_description → F_GamepadGetDescription(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x152d18 ldr r1, [pc, #0x244]
 *   @0x152d1c ldr r0, [pc, #0x244]
 *   @0x152d20 mov r2, #1
 *   @0x152d24 mov r3, r2
 *   @0x152d28 ldr r1, [r4, r1]
 *   @0x152d2c add r0, pc, r0
 *   @0x152d30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #4 gamepad_get_button_threshold → F_GamepadGetButtonThreshold(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x152d34 ldr r1, [pc, #0x230]
 *   @0x152d38 ldr r0, [pc, #0x230]
 *   @0x152d3c mov r2, #2
 *   @0x152d40 mov r3, #1
 *   @0x152d44 ldr r1, [r4, r1]
 *   @0x152d48 add r0, pc, r0
 *   @0x152d4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #5 gamepad_set_button_threshold → F_GamepadSetButtonThreshold(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x152d50 ldr r1, [pc, #0x21c]
 *   @0x152d54 ldr r0, [pc, #0x21c]
 *   @0x152d58 mov r2, #1
 *   @0x152d5c mov r3, r2
 *   @0x152d60 ldr r1, [r4, r1]
 *   @0x152d64 add r0, pc, r0
 *   @0x152d68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #6 gamepad_get_axis_deadzone → F_GamepadGetAxisDeadzone(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x152d6c ldr r1, [pc, #0x208]
 *   @0x152d70 ldr r0, [pc, #0x208]
 *   @0x152d74 mov r2, #2
 *   @0x152d78 mov r3, #1
 *   @0x152d7c ldr r1, [r4, r1]
 *   @0x152d80 add r0, pc, r0
 *   @0x152d84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #7 gamepad_set_axis_deadzone → F_GamepadSetAxisDeadzone(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x152d88 ldr r1, [pc, #0x1f4]
 *   @0x152d8c ldr r0, [pc, #0x1f4]
 *   @0x152d90 mov r2, #1
 *   @0x152d94 mov r3, r2
 *   @0x152d98 ldr r1, [r4, r1]
 *   @0x152d9c add r0, pc, r0
 *   @0x152da0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #8 gamepad_button_count → F_GamepadButtonCount(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x152da4 ldr r1, [pc, #0x1e0]
 *   @0x152da8 ldr r0, [pc, #0x1e0]
 *   @0x152dac mov r2, #2
 *   @0x152db0 mov r3, #1
 *   @0x152db4 ldr r1, [r4, r1]
 *   @0x152db8 add r0, pc, r0
 *   @0x152dbc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #9 gamepad_button_check → F_GamepadButtonCheck(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x152dc0 ldr r1, [pc, #0x1cc]
 *   @0x152dc4 ldr r0, [pc, #0x1cc]
 *   @0x152dc8 mov r2, #2
 *   @0x152dcc mov r3, #1
 *   @0x152dd0 ldr r1, [r4, r1]
 *   @0x152dd4 add r0, pc, r0
 *   @0x152dd8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #10 gamepad_button_check_pressed → F_GamepadButtonCheckPressed(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x152ddc ldr r1, [pc, #0x1b8]
 *   @0x152de0 ldr r0, [pc, #0x1b8]
 *   @0x152de4 mov r2, #2
 *   @0x152de8 mov r3, #1
 *   @0x152dec ldr r1, [r4, r1]
 *   @0x152df0 add r0, pc, r0
 *   @0x152df4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #11 gamepad_button_check_released → F_GamepadButtonCheckReleased(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x152df8 ldr r1, [pc, #0x1a4]
 *   @0x152dfc ldr r0, [pc, #0x1a4]
 *   @0x152e00 mov r2, #2
 *   @0x152e04 mov r3, #1
 *   @0x152e08 ldr r1, [r4, r1]
 *   @0x152e0c add r0, pc, r0
 *   @0x152e10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #12 gamepad_button_value → F_GamepadButtonValue(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x152e14 ldr r1, [pc, #0x190]
 *   @0x152e18 ldr r0, [pc, #0x190]
 *   @0x152e1c mov r2, #1
 *   @0x152e20 mov r3, r2
 *   @0x152e24 ldr r1, [r4, r1]
 *   @0x152e28 add r0, pc, r0
 *   @0x152e2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #13 gamepad_axis_count → F_GamepadAxisCount(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x152e30 ldr r1, [pc, #0x17c]
 *   @0x152e34 ldr r0, [pc, #0x17c]
 *   @0x152e38 mov r2, #2
 *   @0x152e3c mov r3, #1
 *   @0x152e40 ldr r1, [r4, r1]
 *   @0x152e44 add r0, pc, r0
 *   @0x152e48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #14 gamepad_axis_value → F_GamepadAxisValue(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x152e4c ldr r1, [pc, #0x168]
 *   @0x152e50 ldr r0, [pc, #0x168]
 *   @0x152e54 mov r2, #3
 *   @0x152e58 mov r3, #1
 *   @0x152e5c ldr r1, [r4, r1]
 *   @0x152e60 add r0, pc, r0
 *   @0x152e64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #15 gamepad_set_vibration → F_GamepadSetVibration(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x152e68 ldr r1, [pc, #0x154]
 *   @0x152e6c ldr r0, [pc, #0x154]
 *   @0x152e70 mov r2, #1
 *   @0x152e74 mov r3, r2
 *   @0x152e78 ldr r1, [r4, r1]
 *   @0x152e7c add r0, pc, r0
 *   @0x152e80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #16 gamepad_add_hardware_mapping_from_string → F_GamepadAddMappingFromString(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x152e84 ldr r1, [pc, #0x140]
 *   @0x152e88 ldr r0, [pc, #0x140]
 *   @0x152e8c mov r2, #1
 *   @0x152e90 mov r3, r2
 *   @0x152e94 ldr r1, [r4, r1]
 *   @0x152e98 add r0, pc, r0
 *   @0x152e9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #17 gamepad_add_hardware_mapping_from_file → F_GamepadAddMappingFromFile(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x152ea0 ldr r1, [pc, #0x12c]
 *   @0x152ea4 ldr r0, [pc, #0x12c]
 *   @0x152ea8 mov r2, #0
 *   @0x152eac mov r3, #1
 *   @0x152eb0 ldr r1, [r4, r1]
 *   @0x152eb4 add r0, pc, r0
 *   @0x152eb8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #18 gamepad_get_hardware_mappings → F_GamepadGetDatabase(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x152ebc ldr r1, [pc, #0x118]
 *   @0x152ec0 ldr r0, [pc, #0x118]
 *   @0x152ec4 mov r2, #2
 *   @0x152ec8 mov r3, #1
 *   @0x152ecc ldr r5, [r4, r1]
 *   @0x152ed0 add r0, pc, r0
 *   @0x152ed4 mov r1, r5
 *   @0x152ed8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #19 gamepad_set_color → F_GamepadSetColour(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x152edc ldr r0, [pc, #0x100]
 *   @0x152ee0 mov r2, #2
 *   @0x152ee4 mov r1, r5
 *   @0x152ee8 add r0, pc, r0
 *   @0x152eec mov r3, #1
 *   @0x152ef0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #20 gamepad_set_colour → F_GamepadSetColour(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x152ef4 ldr r3, [pc, #0xec]
 *   @0x152ef8 ldr r3, [r4, r3]
 *   @0x152efc ldr r4, [r3]
 *   @0x152f00 mov r0, r4
 *   @0x152f04 bl 0xb6538 <strlen@plt>   —— 调用 0xb6538
 *   @0x152f08 mov r1, r0
 *   @0x152f0c mov r0, r4
 *   @0x152f10 bl 0x1529e0 <_ZN15SGamepadMapping22CreateFromFileAsStringEPhi>   —— 调用 SGamepadMapping::CreateFromFileAsString(unsigned char*, int)
 *   @0x152f14 ldr r0, [pc, #0xd0]
 *   @0x152f18 add r0, pc, r0
 *   @0x152f1c bl 0x152b14 <_ZN15SGamepadMapping14CreateFromFileEPKc>   —— 调用 SGamepadMapping::CreateFromFile(char const*)
 *   @0x152f20 ldr r0, [pc, #0xc8]
 *   @0x152f24 add r0, pc, r0
 *   @0x152f28 bl 0x215284 <_Z22EnvironmentGetVariablePc>   —— 调用 EnvironmentGetVariable(char*)
 *   @0x152f2c cmp r0, #0
 *   @0x152f30 beq 0x152f38 <_Z20InitGamepadFunctionsv+0x29c>   —— 条件跳转 → 0x152f38
 *   @0x152f34 bl 0x152790 <_ZN15SGamepadMapping16CreateFromStringEPKc>   —— 调用 SGamepadMapping::CreateFromString(char const*)
 *   @0x152f38 pop {r3, r4, r5, lr}
 *   @0x152f3c b 0x190014 <_Z12GamepadInitMv>
 *   @0x152f40 eoreq lr, r9, r0, lsr #31
 *   @0x152f44 .word 0xffffde20
 *   @0x152f48 ldrheq r2, [pc], -r12
 *   @0x152f4c .word 0xffffde24
 *   @0x152f50 ldrheq r2, [pc], -r8
 *   @0x152f54 .word 0xffffde28
 *   @0x152f58 ldrheq r2, [pc], -r8
 *   @0x152f5c .word 0xffffde2c
 *   @0x152f60 ldrheq r2, [pc], -r4
 *   @0x152f64 .word 0xffffde30
 *   @0x152f68 ldrheq r2, [pc], -r0
 *   @0x152f6c .word 0xffffde34
 *   @0x152f70 ldrheq r2, [pc], -r4
 *   @0x152f74 .word 0xffffde38
 *   @0x152f78 ldrheq r2, [pc], -r8
 *   @0x152f7c .word 0xffffde3c
 *   @0x152f80 ldrheq r2, [pc], -r8
 *   @0x152f84 .word 0xffffde40
 *   @0x152f88 ldrheq r2, [pc], -r8
 *   @0x152f8c .word 0xffffde44
 *   @0x152f90 ldrheq r2, [pc], -r4
 *   @0x152f94 .word 0xffffde48
 *   @0x152f98 ldrheq r2, [pc], -r0
 *   @0x152f9c .word 0xffffde4c
 *   @0x152fa0 ldrheq r2, [pc], -r4
 *   @0x152fa4 .word 0xffffde50
 *   @0x152fa8 ldrheq r2, [pc], -r8
 *   @0x152fac .word 0xffffde54
 *   @0x152fb0 ldrheq r2, [pc], -r4
 *   @0x152fb4 .word 0xffffde58
 *   @0x152fb8 andseq r2, pc, r12, lsr #31
 *   @0x152fbc .word 0xffffde5c
 *   @0x152fc0 andseq r2, pc, r4, lsr #31
 *   @0x152fc4 .word 0xffffde60
 *   @0x152fc8 andseq r2, pc, r0, lsr #31
 *   @0x152fcc .word 0xffffde64
 *   @0x152fd0 ldrheq r2, [pc], -r0
 *   @0x152fd4 .word 0xffffde68
 *   @0x152fd8 ldrheq r2, [pc], -r12
 *   @0x152fdc .word 0xffffde6c
 *   @0x152fe0 andseq r2, pc, r0, asr #31
 *   @0x152fe4 ldrheq r2, [pc], -r12
 *   @0x152fe8 .word 0xffffde70
 *   @0x152fec andseq r2, pc, r0, lsr #31
 *   @0x152ff0 andseq r2, pc, r12, lsr #31
 *
 * ══ §4/6 InitMetroFunctions  0x128b58..0x128f40  size 1000  250 条（214 条指令 + 36 个池字）══
 * @func 0x128b58 0x128f40  size 1000  250 条
 * 注册 35 条｜唯一名 35｜唯一函数指针 1｜argc 0:6 1:14 2:4 3:6 4:3 6:1 8:1｜flag 0:35
 * 首条 #0 win8_livetile_tile_notification（0x128b78）→ 末条 #34 win8_livetile_notification_end（0x128eac）
 * 名字族（前 8）: win8×35
 * 游戏实际调用的 99 个内建里落在本表: 0 个
 * 表: asm/init-tables/init-InitMetroFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: 无（本函数每条注册的四实参全部解出，控制流全部走到）
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x128b58 push {r4, lr}
 *   @0x128b5c mov r2, #4
 *   @0x128b60 ldr r4, [pc, #0x348]
 *   @0x128b64 mov r3, #0
 *   @0x128b68 ldr r0, [pc, #0x344]
 *   @0x128b6c ldr r4, [pc, r4]
 *   @0x128b70 add r0, pc, r0
 *   @0x128b74 mov r1, r4
 *   @0x128b78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 win8_livetile_tile_notification → 0xe1a01004 argc=4 flag=0
 *   @0x128b7c ldr r0, [pc, #0x334]
 *   @0x128b80 mov r2, #0
 *   @0x128b84 mov r1, r4
 *   @0x128b88 mov r3, r2
 *   @0x128b8c add r0, pc, r0
 *   @0x128b90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 win8_livetile_tile_clear → 0xe1a01004 argc=0 flag=0
 *   @0x128b94 ldr r0, [pc, #0x320]
 *   @0x128b98 mov r1, r4
 *   @0x128b9c mov r2, #1
 *   @0x128ba0 add r0, pc, r0
 *   @0x128ba4 mov r3, #0
 *   @0x128ba8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 win8_livetile_badge_notification → 0xe1a01004 argc=1 flag=0
 *   @0x128bac ldr r0, [pc, #0x30c]
 *   @0x128bb0 mov r2, #0
 *   @0x128bb4 mov r1, r4
 *   @0x128bb8 mov r3, r2
 *   @0x128bbc add r0, pc, r0
 *   @0x128bc0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 win8_livetile_badge_clear → 0xe1a01004 argc=0 flag=0
 *   @0x128bc4 ldr r0, [pc, #0x2f8]
 *   @0x128bc8 mov r1, r4
 *   @0x128bcc mov r2, #1
 *   @0x128bd0 add r0, pc, r0
 *   @0x128bd4 mov r3, #0
 *   @0x128bd8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #4 win8_livetile_queue_enable → 0xe1a01004 argc=1 flag=0
 *   @0x128bdc ldr r0, [pc, #0x2e4]
 *   @0x128be0 mov r1, r4
 *   @0x128be4 mov r2, #1
 *   @0x128be8 add r0, pc, r0
 *   @0x128bec mov r3, #0
 *   @0x128bf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #5 win8_appbar_enable → 0xe1a01004 argc=1 flag=0
 *   @0x128bf4 ldr r0, [pc, #0x2d0]
 *   @0x128bf8 mov r1, r4
 *   @0x128bfc mov r2, #6
 *   @0x128c00 add r0, pc, r0
 *   @0x128c04 mov r3, #0
 *   @0x128c08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #6 win8_appbar_add_element → 0xe1a01004 argc=6 flag=0
 *   @0x128c0c ldr r0, [pc, #0x2bc]
 *   @0x128c10 mov r1, r4
 *   @0x128c14 mov r2, #1
 *   @0x128c18 add r0, pc, r0
 *   @0x128c1c mov r3, #0
 *   @0x128c20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #7 win8_appbar_remove_element → 0xe1a01004 argc=1 flag=0
 *   @0x128c24 ldr r0, [pc, #0x2a8]
 *   @0x128c28 mov r1, r4
 *   @0x128c2c mov r2, #3
 *   @0x128c30 add r0, pc, r0
 *   @0x128c34 mov r3, #0
 *   @0x128c38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #8 win8_share_image → 0xe1a01004 argc=3 flag=0
 *   @0x128c3c ldr r0, [pc, #0x294]
 *   @0x128c40 mov r1, r4
 *   @0x128c44 mov r2, #2
 *   @0x128c48 add r0, pc, r0
 *   @0x128c4c mov r3, #0
 *   @0x128c50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #9 win8_share_screenshot → 0xe1a01004 argc=2 flag=0
 *   @0x128c54 ldr r0, [pc, #0x280]
 *   @0x128c58 mov r1, r4
 *   @0x128c5c mov r2, #3
 *   @0x128c60 add r0, pc, r0
 *   @0x128c64 mov r3, #0
 *   @0x128c68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #10 win8_share_file → 0xe1a01004 argc=3 flag=0
 *   @0x128c6c ldr r0, [pc, #0x26c]
 *   @0x128c70 mov r1, r4
 *   @0x128c74 mov r2, #3
 *   @0x128c78 add r0, pc, r0
 *   @0x128c7c mov r3, #0
 *   @0x128c80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #11 win8_share_url → 0xe1a01004 argc=3 flag=0
 *   @0x128c84 ldr r0, [pc, #0x258]
 *   @0x128c88 mov r1, r4
 *   @0x128c8c mov r2, #3
 *   @0x128c90 add r0, pc, r0
 *   @0x128c94 mov r3, #0
 *   @0x128c98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #12 win8_share_text → 0xe1a01004 argc=3 flag=0
 *   @0x128c9c ldr r0, [pc, #0x244]
 *   @0x128ca0 mov r1, r4
 *   @0x128ca4 mov r2, #2
 *   @0x128ca8 add r0, pc, r0
 *   @0x128cac mov r3, #0
 *   @0x128cb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #13 win8_settingscharm_add_entry → 0xe1a01004 argc=2 flag=0
 *   @0x128cb4 ldr r0, [pc, #0x230]
 *   @0x128cb8 mov r1, r4
 *   @0x128cbc mov r2, #3
 *   @0x128cc0 add r0, pc, r0
 *   @0x128cc4 mov r3, #0
 *   @0x128cc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #14 win8_settingscharm_add_html_entry → 0xe1a01004 argc=3 flag=0
 *   @0x128ccc ldr r0, [pc, #0x21c]
 *   @0x128cd0 mov r1, r4
 *   @0x128cd4 mov r2, #4
 *   @0x128cd8 add r0, pc, r0
 *   @0x128cdc mov r3, #0
 *   @0x128ce0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #15 win8_settingscharm_add_xaml_entry → 0xe1a01004 argc=4 flag=0
 *   @0x128ce4 ldr r0, [pc, #0x208]
 *   @0x128ce8 mov r1, r4
 *   @0x128cec mov r2, #4
 *   @0x128cf0 add r0, pc, r0
 *   @0x128cf4 mov r3, #0
 *   @0x128cf8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #16 win8_settingscharm_set_xaml_property → 0xe1a01004 argc=4 flag=0
 *   @0x128cfc ldr r0, [pc, #0x1f4]
 *   @0x128d00 mov r1, r4
 *   @0x128d04 mov r2, #3
 *   @0x128d08 add r0, pc, r0
 *   @0x128d0c mov r3, #0
 *   @0x128d10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #17 win8_settingscharm_get_xaml_property → 0xe1a01004 argc=3 flag=0
 *   @0x128d14 ldr r0, [pc, #0x1e0]
 *   @0x128d18 mov r1, r4
 *   @0x128d1c mov r2, #1
 *   @0x128d20 add r0, pc, r0
 *   @0x128d24 mov r3, #0
 *   @0x128d28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #18 win8_settingscharm_remove_entry → 0xe1a01004 argc=1 flag=0
 *   @0x128d2c ldr r0, [pc, #0x1cc]
 *   @0x128d30 mov r1, r4
 *   @0x128d34 mov r2, #1
 *   @0x128d38 add r0, pc, r0
 *   @0x128d3c mov r3, #0
 *   @0x128d40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #19 win8_search_enable → 0xe1a01004 argc=1 flag=0
 *   @0x128d44 ldr r0, [pc, #0x1b8]
 *   @0x128d48 mov r2, #0
 *   @0x128d4c mov r1, r4
 *   @0x128d50 mov r3, r2
 *   @0x128d54 add r0, pc, r0
 *   @0x128d58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #20 win8_search_disable → 0xe1a01004 argc=0 flag=0
 *   @0x128d5c ldr r0, [pc, #0x1a4]
 *   @0x128d60 mov r1, r4
 *   @0x128d64 mov r2, #1
 *   @0x128d68 add r0, pc, r0
 *   @0x128d6c mov r3, #0
 *   @0x128d70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #21 win8_search_add_suggestions → 0xe1a01004 argc=1 flag=0
 *   @0x128d74 ldr r0, [pc, #0x190]
 *   @0x128d78 mov r2, #0
 *   @0x128d7c mov r1, r4
 *   @0x128d80 mov r3, r2
 *   @0x128d84 add r0, pc, r0
 *   @0x128d88 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #22 win8_device_touchscreen_available → 0xe1a01004 argc=0 flag=0
 *   @0x128d8c ldr r0, [pc, #0x17c]
 *   @0x128d90 mov r1, r4
 *   @0x128d94 mov r2, #8
 *   @0x128d98 add r0, pc, r0
 *   @0x128d9c mov r3, #0
 *   @0x128da0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #23 win8_secondarytile_pin → 0xe1a01004 argc=8 flag=0
 *   @0x128da4 ldr r0, [pc, #0x168]
 *   @0x128da8 mov r1, r4
 *   @0x128dac mov r2, #1
 *   @0x128db0 add r0, pc, r0
 *   @0x128db4 mov r3, #0
 *   @0x128db8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #24 win8_secondarytile_delete → 0xe1a01004 argc=1 flag=0
 *   @0x128dbc ldr r0, [pc, #0x154]
 *   @0x128dc0 mov r1, r4
 *   @0x128dc4 mov r2, #2
 *   @0x128dc8 add r0, pc, r0
 *   @0x128dcc mov r3, #0
 *   @0x128dd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #25 win8_secondarytile_badge_notification → 0xe1a01004 argc=2 flag=0
 *   @0x128dd4 ldr r0, [pc, #0x140]
 *   @0x128dd8 mov r1, r4
 *   @0x128ddc mov r2, #1
 *   @0x128de0 add r0, pc, r0
 *   @0x128de4 mov r3, #0
 *   @0x128de8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #26 win8_license_initialize_sandbox → 0xe1a01004 argc=1 flag=0
 *   @0x128dec ldr r0, [pc, #0x12c]
 *   @0x128df0 mov r2, #0
 *   @0x128df4 mov r1, r4
 *   @0x128df8 mov r3, r2
 *   @0x128dfc add r0, pc, r0
 *   @0x128e00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #27 win8_license_trial_version → 0xe1a01004 argc=0 flag=0
 *   @0x128e04 ldr r0, [pc, #0x118]
 *   @0x128e08 mov r1, r4
 *   @0x128e0c mov r2, #1
 *   @0x128e10 add r0, pc, r0
 *   @0x128e14 mov r3, #0
 *   @0x128e18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #28 win8_livetile_notification_begin → 0xe1a01004 argc=1 flag=0
 *   @0x128e1c ldr r0, [pc, #0x104]
 *   @0x128e20 mov r1, r4
 *   @0x128e24 mov r2, #2
 *   @0x128e28 add r0, pc, r0
 *   @0x128e2c mov r3, #0
 *   @0x128e30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #29 win8_livetile_notification_secondary_begin → 0xe1a01004 argc=2 flag=0
 *   @0x128e34 ldr r0, [pc, #0xf0]
 *   @0x128e38 mov r1, r4
 *   @0x128e3c mov r2, #1
 *   @0x128e40 add r0, pc, r0
 *   @0x128e44 mov r3, #0
 *   @0x128e48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #30 win8_livetile_notification_expiry → 0xe1a01004 argc=1 flag=0
 *   @0x128e4c ldr r0, [pc, #0xdc]
 *   @0x128e50 mov r1, r4
 *   @0x128e54 mov r2, #1
 *   @0x128e58 add r0, pc, r0
 *   @0x128e5c mov r3, #0
 *   @0x128e60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #31 win8_livetile_notification_tag → 0xe1a01004 argc=1 flag=0
 *   @0x128e64 ldr r0, [pc, #0xc8]
 *   @0x128e68 mov r1, r4
 *   @0x128e6c mov r2, #1
 *   @0x128e70 add r0, pc, r0
 *   @0x128e74 mov r3, #0
 *   @0x128e78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #32 win8_livetile_notification_text_add → 0xe1a01004 argc=1 flag=0
 *   @0x128e7c ldr r0, [pc, #0xb4]
 *   @0x128e80 mov r1, r4
 *   @0x128e84 mov r2, #1
 *   @0x128e88 add r0, pc, r0
 *   @0x128e8c mov r3, #0
 *   @0x128e90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #33 win8_livetile_notification_image_add → 0xe1a01004 argc=1 flag=0
 *   @0x128e94 ldr r0, [pc, #0xa0]
 *   @0x128e98 mov r2, #0
 *   @0x128e9c mov r1, r4
 *   @0x128ea0 mov r3, r2
 *   @0x128ea4 add r0, pc, r0
 *   @0x128ea8 pop {r4, lr}
 *   @0x128eac b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #34 win8_livetile_notification_end → 0xe1a01004 argc=0 flag=0
 *   @0x128eb0 eoreq r6, r12, r8, ror #1
 *   @0x128eb4 eoreq r3, r1, r8, ror pc
 *   @0x128eb8 eoreq r3, r1, r12, ror pc
 *   @0x128ebc eoreq r3, r1, r4, lsl #31
 *   @0x128ec0 eoreq r3, r1, r12, lsl #31
 *   @0x128ec4 mlaeq r1, r4, pc, r3
 *   @0x128ec8 mlaeq r1, r8, pc, r3
 *   @0x128ecc mlaeq r1, r4, pc, r3
 *   @0x128ed0 mlaeq r1, r4, pc, r3
 *   @0x128ed4 mlaeq r1, r8, pc, r3
 *   @0x128ed8 mlaeq r1, r4, pc, r3
 *   @0x128edc mlaeq r1, r4, pc, r3
 *   @0x128ee0 eoreq r3, r1, r12, lsl #31
 *   @0x128ee4 eoreq r3, r1, r4, lsl #31
 *   @0x128ee8 eoreq r3, r1, r12, ror pc
 *   @0x128eec eoreq r3, r1, r4, lsl #31
 *   @0x128ef0 mlaeq r1, r0, pc, r3
 *   @0x128ef4 mlaeq r1, r12, pc, r3
 *   @0x128ef8 eoreq r3, r1, r12, lsr #31
 *   @0x128efc .word 0x00213fbc
 *   @0x128f00 eoreq r3, r1, r4, asr #31
 *   @0x128f04 .word 0x00213fbc
 *   @0x128f08 .word 0x00213fbc
 *   @0x128f0c .word 0x00213fbc
 *   @0x128f10 eoreq r3, r1, r12, asr #31
 *   @0x128f14 eoreq r3, r1, r12, asr #31
 *   @0x128f18 .word 0x00213fd0
 *   @0x128f1c eoreq r3, r1, r0, ror #31
 *   @0x128f20 eoreq r3, r1, r4, ror #31
 *   @0x128f24 eoreq r3, r1, r12, ror #31
 *   @0x128f28 .word 0x00213ff8
 *   @0x128f2c eoreq r4, r1, r12
 *   @0x128f30 eoreq r4, r1, r8, lsl r0
 *   @0x128f34 eoreq r4, r1, r0, lsr #32
 *   @0x128f38 eoreq r4, r1, r12, lsr #32
 *   @0x128f3c eoreq r4, r1, r8, lsr r0
 *
 * ══ §5/6 InitPushFunctions  0x155ea0..0x155f84  size 228  57 条（45 条指令 + 12 个池字）══
 * @func 0x155ea0 0x155f84  size 228  57 条
 * 注册 4 条｜唯一名 4｜唯一函数指针 4｜argc 1:3 4:1｜flag 0:4
 * 首条 #0 push_local_notification（0x155ef8）→ 末条 #3 push_cancel_local_notification（0x155f50）
 * 名字族（前 8）: push×4
 * 游戏实际调用的 99 个内建里落在本表: 0 个
 * 表: asm/init-tables/init-InitPushFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: 无（本函数每条注册的四实参全部解出，控制流全部走到）
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x155ea0 push {r4, r5, r6, lr}
 *   @0x155ea4 mov r5, #1
 *   @0x155ea8 ldr r4, [pc, #0xa4]
 *   @0x155eac ldr r3, [pc, #0xa4]
 *   @0x155eb0 add r4, pc, r4
 *   @0x155eb4 ldr r1, [pc, #0xa0]
 *   @0x155eb8 ldr r3, [r4, r3]
 *   @0x155ebc add r1, pc, r1
 *   @0x155ec0 ldr r0, [r3]
 *   @0x155ec4 ldr r3, [r0]
 *   @0x155ec8 ldr r3, [r3, #0xc]
 *   @0x155ecc blx r3
 *   @0x155ed0 ldr r3, [pc, #0x88]
 *   @0x155ed4 ldr r3, [r4, r3]
 *   @0x155ed8 strb r5, [r3]
 *   @0x155edc bl 0x155ba0 <_Z14Push_InitQueuev>   —— 调用 Push_InitQueue()
 *   @0x155ee0 ldr r1, [pc, #0x7c]
 *   @0x155ee4 mov r2, #4
 *   @0x155ee8 ldr r0, [pc, #0x78]
 *   @0x155eec mov r3, #0
 *   @0x155ef0 ldr r1, [r4, r1]
 *   @0x155ef4 add r0, pc, r0
 *   @0x155ef8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 push_local_notification → F_Push_LocalNotification(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x155efc ldr r1, [pc, #0x68]
 *   @0x155f00 ldr r0, [pc, #0x68]
 *   @0x155f04 mov r2, r5
 *   @0x155f08 mov r3, #0
 *   @0x155f0c ldr r1, [r4, r1]
 *   @0x155f10 add r0, pc, r0
 *   @0x155f14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 push_get_first_local_notification → F_Push_GetFirstLocalNotification(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x155f18 ldr r1, [pc, #0x54]
 *   @0x155f1c ldr r0, [pc, #0x54]
 *   @0x155f20 mov r2, r5
 *   @0x155f24 mov r3, #0
 *   @0x155f28 ldr r1, [r4, r1]
 *   @0x155f2c add r0, pc, r0
 *   @0x155f30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 push_get_next_local_notification → F_Push_GetNextLocalNotification(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x155f34 ldr r1, [pc, #0x40]
 *   @0x155f38 ldr r0, [pc, #0x40]
 *   @0x155f3c mov r2, r5
 *   @0x155f40 mov r3, #0
 *   @0x155f44 ldr r1, [r4, r1]
 *   @0x155f48 add r0, pc, r0
 *   @0x155f4c pop {r4, r5, r6, lr}
 *   @0x155f50 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 push_cancel_local_notification → F_Push_CancelLocalNotification(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x155f54 eoreq r11, r9, r0, lsr #27
 *   @0x155f58 .word 0xffffdecc
 *   @0x155f5c andseq r0, pc, r8, lsl #11
 *   @0x155f60 .word 0xffffdec0
 *   @0x155f64 .word 0xffffded0
 *   @0x155f68 andseq r0, pc, r8, ror #10
 *   @0x155f6c .word 0xffffded4
 *   @0x155f70 andseq r0, pc, r4, ror #10
 *   @0x155f74 .word 0xffffded8
 *   @0x155f78 andseq r0, pc, r12, ror #10
 *   @0x155f7c .word 0xffffdedc
 *   @0x155f80 andseq r0, pc, r4, ror r5
 *
 * ══ §6/6 InitIAPFunctions  0x1534d4..0x153710  size 572  143 条（115 条指令 + 28 个池字）══
 * @func 0x1534d4 0x153710  size 572  143 条
 * 注册 15 条｜唯一名 15｜唯一函数指针 10｜argc 0:5 1:6 2:4｜flag 0:15
 * 首条 #0 iap_activate（0x15351c）→ 末条 #14 iap_files_purchased（0x15369c）
 * 名字族（前 8）: iap×15
 * 游戏实际调用的 99 个内建里落在本表: 2 个（iap_acquire, iap_purchase_details）
 * 表: asm/init-tables/init-InitIAPFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: 无（本函数每条注册的四实参全部解出，控制流全部走到）
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1534d4 push {r4, r5, r6, lr}
 *   @0x1534d8 mov r0, #8
 *   @0x1534dc bl 0x27c524 <_Znwj>   —— 调用 operator new(unsigned int)
 *   @0x1534e0 ldr r1, [pc, #0x1b8]
 *   @0x1534e4 ldr r4, [pc, #0x1b8]
 *   @0x1534e8 add r1, pc, r1
 *   @0x1534ec add r4, pc, r4
 *   @0x1534f0 mov r5, r0
 *   @0x1534f4 bl 0x27e070 <_ZN5MutexC2EPKc>   —— 调用 Mutex::Mutex(char const*)
 *   @0x1534f8 ldr r12, [pc, #0x1a8]
 *   @0x1534fc mov r2, #1
 *   @0x153500 ldr r1, [pc, #0x1a4]
 *   @0x153504 mov r3, #0
 *   @0x153508 add r12, pc, r12
 *   @0x15350c ldr r0, [pc, #0x19c]
 *   @0x153510 str r5, [r12]
 *   @0x153514 add r0, pc, r0
 *   @0x153518 ldr r1, [r4, r1]
 *   @0x15351c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 iap_activate → F_IAP_Activate(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x153520 ldr r1, [pc, #0x18c]
 *   @0x153524 ldr r0, [pc, #0x18c]
 *   @0x153528 mov r2, #0
 *   @0x15352c mov r3, r2
 *   @0x153530 ldr r5, [r4, r1]
 *   @0x153534 add r0, pc, r0
 *   @0x153538 mov r1, r5
 *   @0x15353c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 iap_status → F_IAP_StoreState(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x153540 ldr r1, [pc, #0x174]
 *   @0x153544 ldr r0, [pc, #0x174]
 *   @0x153548 mov r2, #2
 *   @0x15354c mov r3, #0
 *   @0x153550 ldr r1, [r4, r1]
 *   @0x153554 add r0, pc, r0
 *   @0x153558 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 iap_acquire → F_IAP_Acquire(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x15355c ldr r1, [pc, #0x160]
 *   @0x153560 ldr r0, [pc, #0x160]
 *   @0x153564 mov r2, #1
 *   @0x153568 mov r3, #0
 *   @0x15356c ldr r1, [r4, r1]
 *   @0x153570 add r0, pc, r0
 *   @0x153574 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 iap_consume → F_IAP_Consume(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x153578 ldr r1, [pc, #0x14c]
 *   @0x15357c ldr r0, [pc, #0x14c]
 *   @0x153580 mov r2, #1
 *   @0x153584 mov r3, #0
 *   @0x153588 ldr r1, [r4, r1]
 *   @0x15358c add r0, pc, r0
 *   @0x153590 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #4 iap_is_purchased → F_IAP_ProductPurchased(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x153594 ldr r1, [pc, #0x138]
 *   @0x153598 ldr r0, [pc, #0x138]
 *   @0x15359c mov r2, #1
 *   @0x1535a0 mov r3, #0
 *   @0x1535a4 ldr r1, [r4, r1]
 *   @0x1535a8 add r0, pc, r0
 *   @0x1535ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #5 iap_enumerate_products → F_IAP_EnumerateProducts(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1535b0 ldr r1, [pc, #0x124]
 *   @0x1535b4 ldr r0, [pc, #0x124]
 *   @0x1535b8 mov r2, #0
 *   @0x1535bc mov r3, r2
 *   @0x1535c0 ldr r1, [r4, r1]
 *   @0x1535c4 add r0, pc, r0
 *   @0x1535c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #6 iap_restore_all → F_IAP_RestoreAll(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1535cc ldr r1, [pc, #0x110]
 *   @0x1535d0 ldr r0, [pc, #0x110]
 *   @0x1535d4 mov r2, #2
 *   @0x1535d8 mov r3, #0
 *   @0x1535dc ldr r1, [r4, r1]
 *   @0x1535e0 add r0, pc, r0
 *   @0x1535e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #7 iap_product_details → F_IAP_ProductDetails(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1535e8 ldr r1, [pc, #0xfc]
 *   @0x1535ec ldr r0, [pc, #0xfc]
 *   @0x1535f0 mov r2, #2
 *   @0x1535f4 mov r3, #0
 *   @0x1535f8 ldr r1, [r4, r1]
 *   @0x1535fc add r0, pc, r0
 *   @0x153600 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #8 iap_purchase_details → F_IAP_PurchaseDetails(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x153604 ldr r0, [pc, #0xe8]
 *   @0x153608 mov r2, #0
 *   @0x15360c mov r1, r5
 *   @0x153610 mov r3, r2
 *   @0x153614 add r0, pc, r0
 *   @0x153618 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #9 iap_store_status → F_IAP_StoreState(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x15361c ldr r1, [pc, #0xd4]
 *   @0x153620 ldr r0, [pc, #0xd4]
 *   @0x153624 mov r2, #0
 *   @0x153628 mov r3, r2
 *   @0x15362c ldr r4, [r4, r1]
 *   @0x153630 add r0, pc, r0
 *   @0x153634 mov r1, r4
 *   @0x153638 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #10 iap_event_queue → F_IAP_Deprecated(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x15363c ldr r0, [pc, #0xbc]
 *   @0x153640 mov r1, r4
 *   @0x153644 mov r2, #1
 *   @0x153648 add r0, pc, r0
 *   @0x15364c mov r3, #0
 *   @0x153650 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #11 iap_product_status → F_IAP_Deprecated(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x153654 ldr r0, [pc, #0xa8]
 *   @0x153658 mov r1, r4
 *   @0x15365c mov r2, #1
 *   @0x153660 add r0, pc, r0
 *   @0x153664 mov r3, #0
 *   @0x153668 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #12 iap_is_downloaded → F_IAP_Deprecated(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x15366c ldr r0, [pc, #0x94]
 *   @0x153670 mov r1, r4
 *   @0x153674 mov r2, #2
 *   @0x153678 add r0, pc, r0
 *   @0x15367c mov r3, #0
 *   @0x153680 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #13 iap_product_files → F_IAP_Deprecated(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x153684 ldr r0, [pc, #0x80]
 *   @0x153688 mov r2, #0
 *   @0x15368c mov r1, r4
 *   @0x153690 mov r3, r2
 *   @0x153694 add r0, pc, r0
 *   @0x153698 pop {r4, r5, r6, lr}
 *   @0x15369c b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #14 iap_files_purchased → F_IAP_Deprecated(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1536a0 andseq r2, pc, r0, lsr #22
 *   @0x1536a4 eoreq lr, r9, r4, ror #14
 *   @0x1536a8 eorseq r1, r3, r8, lsr r5
 *   @0x1536ac .word 0xffffde88
 *   @0x1536b0 andseq r2, pc, r4, lsl #22
 *   @0x1536b4 .word 0xffffde8c
 *   @0x1536b8 ldrsheq r2, [pc], -r4
 *   @0x1536bc .word 0xffffde90
 *   @0x1536c0 andseq r2, pc, r0, ror #21
 *   @0x1536c4 .word 0xffffde94
 *   @0x1536c8 ldrsbeq r2, [pc], -r0
 *   @0x1536cc .word 0xffffde98
 *   @0x1536d0 andseq r2, pc, r0, asr #21
 *   @0x1536d4 .word 0xffffde9c
 *   @0x1536d8 ldrheq r2, [pc], -r8
 *   @0x1536dc .word 0xffffdea0
 *   @0x1536e0 ldrheq r2, [pc], -r4
 *   @0x1536e4 .word 0xffffdea4
 *   @0x1536e8 andseq r2, pc, r8, lsr #21
 *   @0x1536ec .word 0xffffdea8
 *   @0x1536f0 andseq r2, pc, r0, lsr #21
 *   @0x1536f4 andseq r2, pc, r0, lsr #21
 *   @0x1536f8 .word 0xffffdeac
 *   @0x1536fc mulseq pc, r8, r10
 *   @0x153700 mulseq pc, r0, r10
 *   @0x153704 andseq r2, pc, r12, lsl #21
 *   @0x153708 andseq r2, pc, r8, lsl #21
 *   @0x15370c andseq r2, pc, r0, lsl #21
 */
