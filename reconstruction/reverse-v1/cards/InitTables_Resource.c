/* cally 逆向卡：InitTables_Resource —— Init*Functions 的 GML 内建注册表（原版 libyoyo.so，armv7）
 * 本卡 3 节，逐节一个 @func；锚点来自 asm/instructions.jsonl（census），
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
 * 本卡节: §1 InitResourceFunctions 0x130ffc→222 条｜§2 InitParticlesFunctions 0x129f74→64 条｜§3 InitFileFunctions 0x13c4a0→73 条
 *
 * ══ §1/3 InitResourceFunctions  0x130ffc..0x132f70  size 8052  2013 条（1586 条指令 + 427 个池字）══
 * @func 0x130ffc 0x132f70  size 8052  2013 条
 * 注册 222 条｜唯一名 209｜唯一函数指针 197｜argc -1:1 0:6 1:107 2:48 3:17 4:10 5:8 6:6 7:6 8:4 9:4 10:1 11:1 12:2 16:1｜flag 0:83 1:138 ?:1
 * 首条 #0 sprite_name（0x131024）→ 末条 #221 sprite_get_speed（0x132f68）
 * 名字族（前 8）: sprite×55 background×35 path×34 room×25 object×24 font×20 timeline×11 sound×10
 * 游戏实际调用的 99 个内建里落在本表: 1 个（object_exists）
 * 条件跳转 7 处: 0x131310(blt), 0x131518(bne), 0x131624(blt), 0x132820(beq), 0x132b20(beq), 0x132c60(beq), 0x132ed8(beq)
 * 表: asm/init-tables/init-InitResourceFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: #217@0x132ef4(object_get_depth) —— 实参来自运行期全局值或共享尾未解，本卡不猜
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x130ffc push {r4, r5, r6, r7, r8, lr}
 *   @0x131000 mov r2, #1
 *   @0x131004 ldr r4, [pc, #0xff4]
 *   @0x131008 mov r3, #0
 *   @0x13100c ldr r1, [pc, #0xff0]
 *   @0x131010 add r4, pc, r4
 *   @0x131014 ldr r0, [pc, #0xfec]
 *   @0x131018 ldr r5, [r4, r1]
 *   @0x13101c add r0, pc, r0
 *   @0x131020 mov r1, r5
 *   @0x131024 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 sprite_name → F_SpriteGetName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131028 ldr r1, [pc, #0xfdc]
 *   @0x13102c ldr r0, [pc, #0xfdc]
 *   @0x131030 mov r2, #1
 *   @0x131034 mov r3, #0
 *   @0x131038 add r0, pc, r0
 *   @0x13103c ldr r1, [r4, r1]
 *   @0x131040 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 sprite_exists → F_SpriteExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131044 ldr r0, [pc, #0xfc8]
 *   @0x131048 mov r1, r5
 *   @0x13104c mov r2, #1
 *   @0x131050 add r0, pc, r0
 *   @0x131054 mov r3, #0
 *   @0x131058 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 sprite_get_name → F_SpriteGetName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13105c ldr r1, [pc, #0xfb4]
 *   @0x131060 ldr r0, [pc, #0xfb4]
 *   @0x131064 mov r2, #1
 *   @0x131068 mov r3, #0
 *   @0x13106c add r0, pc, r0
 *   @0x131070 ldr r1, [r4, r1]
 *   @0x131074 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 sprite_get_number → F_SpriteGetNumber(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131078 ldr r1, [pc, #0xfa0]
 *   @0x13107c ldr r0, [pc, #0xfa0]
 *   @0x131080 mov r2, #1
 *   @0x131084 mov r3, #0
 *   @0x131088 add r0, pc, r0
 *   @0x13108c ldr r1, [r4, r1]
 *   @0x131090 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #4 sprite_get_width → F_SpriteGetWidth(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131094 ldr r1, [pc, #0xf8c]
 *   @0x131098 ldr r0, [pc, #0xf8c]
 *   @0x13109c mov r2, #1
 *   @0x1310a0 mov r3, #0
 *   @0x1310a4 add r0, pc, r0
 *   @0x1310a8 ldr r1, [r4, r1]
 *   @0x1310ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #5 sprite_get_height → F_SpriteGetHeight(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1310b0 ldr r1, [pc, #0xf78]
 *   @0x1310b4 ldr r0, [pc, #0xf78]
 *   @0x1310b8 mov r2, #1
 *   @0x1310bc mov r3, #0
 *   @0x1310c0 add r0, pc, r0
 *   @0x1310c4 ldr r1, [r4, r1]
 *   @0x1310c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #6 sprite_get_transparent → F_SpriteGetTransparent(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1310cc ldr r1, [pc, #0xf64]
 *   @0x1310d0 ldr r0, [pc, #0xf64]
 *   @0x1310d4 mov r2, #1
 *   @0x1310d8 mov r3, #0
 *   @0x1310dc add r0, pc, r0
 *   @0x1310e0 ldr r1, [r4, r1]
 *   @0x1310e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #7 sprite_get_smooth → F_SpriteGetSmooth(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1310e8 ldr r1, [pc, #0xf50]
 *   @0x1310ec ldr r0, [pc, #0xf50]
 *   @0x1310f0 mov r2, #1
 *   @0x1310f4 mov r3, #0
 *   @0x1310f8 add r0, pc, r0
 *   @0x1310fc ldr r1, [r4, r1]
 *   @0x131100 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #8 sprite_get_preload → F_SpriteGetPreload(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131104 ldr r1, [pc, #0xf3c]
 *   @0x131108 ldr r0, [pc, #0xf3c]
 *   @0x13110c mov r2, #1
 *   @0x131110 mov r3, #0
 *   @0x131114 add r0, pc, r0
 *   @0x131118 ldr r1, [r4, r1]
 *   @0x13111c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #9 sprite_get_xoffset → F_SpriteGetXoffset(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131120 ldr r1, [pc, #0xf28]
 *   @0x131124 ldr r0, [pc, #0xf28]
 *   @0x131128 mov r2, #1
 *   @0x13112c mov r3, #0
 *   @0x131130 add r0, pc, r0
 *   @0x131134 ldr r1, [r4, r1]
 *   @0x131138 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #10 sprite_get_yoffset → F_SpriteGetYoffset(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13113c ldr r1, [pc, #0xf14]
 *   @0x131140 ldr r0, [pc, #0xf14]
 *   @0x131144 mov r2, #1
 *   @0x131148 mov r3, #0
 *   @0x13114c add r0, pc, r0
 *   @0x131150 ldr r1, [r4, r1]
 *   @0x131154 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #11 sprite_get_bbox_mode → F_SpriteGetBboxMode(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131158 ldr r1, [pc, #0xf00]
 *   @0x13115c ldr r0, [pc, #0xf00]
 *   @0x131160 mov r2, #1
 *   @0x131164 mov r3, #0
 *   @0x131168 add r0, pc, r0
 *   @0x13116c ldr r1, [r4, r1]
 *   @0x131170 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #12 sprite_get_bbox_left → F_SpriteGetBboxLeft(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131174 ldr r1, [pc, #0xeec]
 *   @0x131178 ldr r0, [pc, #0xeec]
 *   @0x13117c mov r2, #1
 *   @0x131180 mov r3, #0
 *   @0x131184 add r0, pc, r0
 *   @0x131188 ldr r1, [r4, r1]
 *   @0x13118c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #13 sprite_get_bbox_right → F_SpriteGetBboxRight(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131190 ldr r1, [pc, #0xed8]
 *   @0x131194 ldr r0, [pc, #0xed8]
 *   @0x131198 mov r2, #1
 *   @0x13119c mov r3, #0
 *   @0x1311a0 add r0, pc, r0
 *   @0x1311a4 ldr r1, [r4, r1]
 *   @0x1311a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #14 sprite_get_bbox_top → F_SpriteGetBboxTop(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1311ac ldr r1, [pc, #0xec4]
 *   @0x1311b0 ldr r0, [pc, #0xec4]
 *   @0x1311b4 mov r2, #1
 *   @0x1311b8 mov r3, #0
 *   @0x1311bc add r0, pc, r0
 *   @0x1311c0 ldr r1, [r4, r1]
 *   @0x1311c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #15 sprite_get_bbox_bottom → F_SpriteGetBboxBottom(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1311c8 ldr r1, [pc, #0xeb0]
 *   @0x1311cc ldr r0, [pc, #0xeb0]
 *   @0x1311d0 mov r2, #1
 *   @0x1311d4 mov r3, #0
 *   @0x1311d8 add r0, pc, r0
 *   @0x1311dc ldr r1, [r4, r1]
 *   @0x1311e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #16 sprite_get_precise → F_SpriteGetPrecise(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1311e4 ldr r1, [pc, #0xe9c]
 *   @0x1311e8 ldr r0, [pc, #0xe9c]
 *   @0x1311ec mov r2, #9
 *   @0x1311f0 mov r3, #0
 *   @0x1311f4 add r0, pc, r0
 *   @0x1311f8 ldr r1, [r4, r1]
 *   @0x1311fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #17 sprite_collision_mask → F_SpriteCollisionMask(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=0
 *   @0x131200 ldr r1, [pc, #0xe88]
 *   @0x131204 ldr r0, [pc, #0xe88]
 *   @0x131208 mov r2, #2
 *   @0x13120c mov r3, #0
 *   @0x131210 add r0, pc, r0
 *   @0x131214 ldr r1, [r4, r1]
 *   @0x131218 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #18 sprite_set_cache_size → F_SpriteSetCacheSize(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x13121c ldr r1, [pc, #0xe74]
 *   @0x131220 ldr r0, [pc, #0xe74]
 *   @0x131224 mov r2, #3
 *   @0x131228 mov r3, #0
 *   @0x13122c add r0, pc, r0
 *   @0x131230 ldr r1, [r4, r1]
 *   @0x131234 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #19 sprite_set_cache_size_ext → F_SpriteSetCacheSizeExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x131238 ldr r1, [pc, #0xe60]
 *   @0x13123c ldr r0, [pc, #0xe60]
 *   @0x131240 mov r2, #2
 *   @0x131244 mov r3, #0
 *   @0x131248 add r0, pc, r0
 *   @0x13124c ldr r1, [r4, r1]
 *   @0x131250 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #20 font_set_cache_size → F_FontSetCacheSize(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x131254 ldr r1, [pc, #0xe4c]
 *   @0x131258 ldr r0, [pc, #0xe4c]
 *   @0x13125c mov r2, #2
 *   @0x131260 mov r3, #0
 *   @0x131264 add r0, pc, r0
 *   @0x131268 ldr r1, [r4, r1]
 *   @0x13126c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #21 sprite_get_tpe → F_SpriteGetTPE(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x131270 ldr r1, [pc, #0xe38]
 *   @0x131274 ldr r0, [pc, #0xe38]
 *   @0x131278 mov r2, #3
 *   @0x13127c mov r3, #1
 *   @0x131280 add r0, pc, r0
 *   @0x131284 ldr r1, [r4, r1]
 *   @0x131288 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #22 sprite_set_offset → F_SpriteSetOffset(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x13128c ldr r1, [pc, #0xe24]
 *   @0x131290 ldr r0, [pc, #0xe24]
 *   @0x131294 mov r2, #2
 *   @0x131298 mov r3, #1
 *   @0x13129c add r0, pc, r0
 *   @0x1312a0 ldr r1, [r4, r1]
 *   @0x1312a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #23 sprite_set_bbox_mode → F_SpriteSetBboxMode(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1312a8 ldr r1, [pc, #0xe10]
 *   @0x1312ac ldr r0, [pc, #0xe10]
 *   @0x1312b0 mov r2, #5
 *   @0x1312b4 mov r3, #1
 *   @0x1312b8 add r0, pc, r0
 *   @0x1312bc ldr r1, [r4, r1]
 *   @0x1312c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #24 sprite_set_bbox → F_SpriteSetBbox(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x1312c4 ldr r1, [pc, #0xdfc]
 *   @0x1312c8 ldr r0, [pc, #0xdfc]
 *   @0x1312cc mov r2, #2
 *   @0x1312d0 mov r3, #1
 *   @0x1312d4 add r0, pc, r0
 *   @0x1312d8 ldr r1, [r4, r1]
 *   @0x1312dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #25 sprite_set_precise → F_SpriteSetPrecise(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1312e0 ldr r1, [pc, #0xde8]
 *   @0x1312e4 ldr r0, [pc, #0xde8]
 *   @0x1312e8 mov r3, #1
 *   @0x1312ec mov r2, #2
 *   @0x1312f0 ldr r1, [r4, r1]
 *   @0x1312f4 add r0, pc, r0
 *   @0x1312f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #26 sprite_set_alpha_from_sprite → F_SpriteSetAlphaFromSprite(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1312fc ldr r3, [pc, #0xdd4]
 *   @0x131300 ldr r1, [pc, #0xdd4]
 *   @0x131304 ldr r6, [r4, r3]
 *   @0x131308 ldr r3, [r6]
 *   @0x13130c cmp r3, #800
 *   @0x131310 blt 0x132cd8 <_Z21InitResourceFunctionsv+0x1cdc>   —— 条件跳转 → 0x132cd8
 *   @0x131314 ldr r0, [pc, #0xdc4]
 *   @0x131318 mov r2, #6
 *   @0x13131c mov r3, #1
 *   @0x131320 ldr r1, [r4, r1]
 *   @0x131324 add r0, pc, r0
 *   @0x131328 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #27 sprite_add → F_SpriteAdd(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x13132c ldr r1, [pc, #0xdb0]
 *   @0x131330 ldr r0, [pc, #0xdb0]
 *   @0x131334 mov r2, #8
 *   @0x131338 mov r3, #1
 *   @0x13133c add r0, pc, r0
 *   @0x131340 ldr r1, [r4, r1]
 *   @0x131344 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #28 sprite_create_from_screen → F_SpriteCreateFromScreen(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x131348 ldr r1, [pc, #0xd9c]
 *   @0x13134c ldr r0, [pc, #0xd9c]
 *   @0x131350 mov r2, #7
 *   @0x131354 mov r3, #1
 *   @0x131358 add r0, pc, r0
 *   @0x13135c ldr r1, [r4, r1]
 *   @0x131360 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #29 sprite_add_from_screen → F_SpriteAddFromScreen(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x131364 ldr r1, [pc, #0xd88]
 *   @0x131368 ldr r0, [pc, #0xd88]
 *   @0x13136c mov r2, #9
 *   @0x131370 mov r3, #1
 *   @0x131374 add r0, pc, r0
 *   @0x131378 ldr r1, [r4, r1]
 *   @0x13137c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #30 sprite_create_from_surface → F_SpriteCreateFromSurface(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x131380 ldr r1, [pc, #0xd74]
 *   @0x131384 ldr r0, [pc, #0xd74]
 *   @0x131388 mov r2, #8
 *   @0x13138c mov r3, #1
 *   @0x131390 add r0, pc, r0
 *   @0x131394 ldr r1, [r4, r1]
 *   @0x131398 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #31 sprite_add_from_surface → F_SpriteAddFromSurface(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x13139c ldr r1, [pc, #0xd60]
 *   @0x1313a0 ldr r0, [pc, #0xd60]
 *   @0x1313a4 mov r2, #7
 *   @0x1313a8 mov r3, #1
 *   @0x1313ac add r0, pc, r0
 *   @0x1313b0 ldr r1, [r4, r1]
 *   @0x1313b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #32 sprite_replace → F_SpriteReplace(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x1313b8 ldr r1, [pc, #0xd4c]
 *   @0x1313bc ldr r0, [pc, #0xd4c]
 *   @0x1313c0 mov r2, #1
 *   @0x1313c4 mov r3, r2
 *   @0x1313c8 add r0, pc, r0
 *   @0x1313cc ldr r1, [r4, r1]
 *   @0x1313d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #33 sprite_add_sprite → F_SpriteAddSprite(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1313d4 ldr r1, [pc, #0xd38]
 *   @0x1313d8 ldr r0, [pc, #0xd38]
 *   @0x1313dc mov r2, #2
 *   @0x1313e0 mov r3, #1
 *   @0x1313e4 add r0, pc, r0
 *   @0x1313e8 ldr r1, [r4, r1]
 *   @0x1313ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #34 sprite_replace_sprite → F_SpriteReplaceSprite(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1313f0 ldr r1, [pc, #0xd24]
 *   @0x1313f4 ldr r0, [pc, #0xd24]
 *   @0x1313f8 mov r2, #2
 *   @0x1313fc mov r3, #1
 *   @0x131400 add r0, pc, r0
 *   @0x131404 ldr r1, [r4, r1]
 *   @0x131408 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #35 sprite_save_strip → F_SpriteSaveStrip(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x13140c ldr r1, [pc, #0xd10]
 *   @0x131410 mov r2, #1
 *   @0x131414 ldr r0, [pc, #0xd0c]
 *   @0x131418 mov r3, r2
 *   @0x13141c add r0, pc, r0
 *   @0x131420 ldr r1, [r4, r1]
 *   @0x131424 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #36 sprite_delete → F_SpriteDelete(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x131428 ldr r1, [pc, #0xcfc]
 *   @0x13142c ldr r0, [pc, #0xcfc]
 *   @0x131430 mov r2, #1
 *   @0x131434 mov r3, r2
 *   @0x131438 add r0, pc, r0
 *   @0x13143c ldr r1, [r4, r1]
 *   @0x131440 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #37 sprite_duplicate → F_SpriteDuplicate(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x131444 ldr r1, [pc, #0xce8]
 *   @0x131448 ldr r0, [pc, #0xce8]
 *   @0x13144c mov r2, #2
 *   @0x131450 mov r3, #1
 *   @0x131454 add r0, pc, r0
 *   @0x131458 ldr r1, [r4, r1]
 *   @0x13145c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #38 sprite_assign → F_SpriteAssign(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x131460 ldr r1, [pc, #0xcd4]
 *   @0x131464 ldr r0, [pc, #0xcd4]
 *   @0x131468 mov r2, #2
 *   @0x13146c mov r3, #1
 *   @0x131470 add r0, pc, r0
 *   @0x131474 ldr r1, [r4, r1]
 *   @0x131478 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #39 sprite_merge → F_SpriteMerge(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x13147c ldr r1, [pc, #0xcc0]
 *   @0x131480 ldr r0, [pc, #0xcc0]
 *   @0x131484 mov r2, #3
 *   @0x131488 mov r3, #1
 *   @0x13148c add r0, pc, r0
 *   @0x131490 ldr r1, [r4, r1]
 *   @0x131494 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #40 sprite_save → F_SpriteSave(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x131498 ldr r1, [pc, #0xcac]
 *   @0x13149c ldr r0, [pc, #0xcac]
 *   @0x1314a0 mov r2, #1
 *   @0x1314a4 mov r3, r2
 *   @0x1314a8 add r0, pc, r0
 *   @0x1314ac ldr r1, [r4, r1]
 *   @0x1314b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #41 sprite_prefetch → F_SpritePrefetch(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1314b4 ldr r1, [pc, #0xc98]
 *   @0x1314b8 ldr r0, [pc, #0xc98]
 *   @0x1314bc mov r2, #1
 *   @0x1314c0 mov r3, r2
 *   @0x1314c4 add r0, pc, r0
 *   @0x1314c8 ldr r1, [r4, r1]
 *   @0x1314cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #42 sprite_prefetch_multi → F_SpritePrefetchMulti(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1314d0 ldr r1, [pc, #0xc84]
 *   @0x1314d4 ldr r0, [pc, #0xc84]
 *   @0x1314d8 mov r2, #1
 *   @0x1314dc mov r3, r2
 *   @0x1314e0 add r0, pc, r0
 *   @0x1314e4 ldr r1, [r4, r1]
 *   @0x1314e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #43 sprite_flush → F_SpriteFlush(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1314ec ldr r1, [pc, #0xc70]
 *   @0x1314f0 ldr r0, [pc, #0xc70]
 *   @0x1314f4 mov r2, #1
 *   @0x1314f8 mov r3, r2
 *   @0x1314fc add r0, pc, r0
 *   @0x131500 ldr r1, [r4, r1]
 *   @0x131504 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #44 sprite_flush_multi → F_SpriteFlushMulti(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x131508 ldr r3, [pc, #0xc5c]
 *   @0x13150c ldr r5, [r4, r3]
 *   @0x131510 ldrb r3, [r5]
 *   @0x131514 cmp r3, #0
 *   @0x131518 bne 0x132f18 <_Z21InitResourceFunctionsv+0x1f1c>   —— 条件跳转 → 0x132f18
 *   @0x13151c ldr r1, [pc, #0xc4c]
 *   @0x131520 mov r2, #1
 *   @0x131524 ldr r0, [pc, #0xc48]
 *   @0x131528 mov r3, #0
 *   @0x13152c ldr r7, [r4, r1]
 *   @0x131530 add r0, pc, r0
 *   @0x131534 mov r1, r7
 *   @0x131538 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #45 background_name → F_BackgroundGetName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13153c ldr r1, [pc, #0xc34]
 *   @0x131540 ldr r0, [pc, #0xc34]
 *   @0x131544 mov r2, #1
 *   @0x131548 mov r3, #0
 *   @0x13154c add r0, pc, r0
 *   @0x131550 ldr r1, [r4, r1]
 *   @0x131554 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #46 background_exists → F_BackgroundExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131558 ldr r0, [pc, #0xc20]
 *   @0x13155c mov r1, r7
 *   @0x131560 mov r2, #1
 *   @0x131564 add r0, pc, r0
 *   @0x131568 mov r3, #0
 *   @0x13156c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #47 background_get_name → F_BackgroundGetName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131570 ldr r1, [pc, #0xc0c]
 *   @0x131574 ldr r0, [pc, #0xc0c]
 *   @0x131578 mov r2, #1
 *   @0x13157c mov r3, #0
 *   @0x131580 add r0, pc, r0
 *   @0x131584 ldr r1, [r4, r1]
 *   @0x131588 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #48 background_get_width → F_BackgroundGetWidth(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13158c ldr r1, [pc, #0xbf8]
 *   @0x131590 ldr r0, [pc, #0xbf8]
 *   @0x131594 mov r2, #1
 *   @0x131598 mov r3, #0
 *   @0x13159c add r0, pc, r0
 *   @0x1315a0 ldr r1, [r4, r1]
 *   @0x1315a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #49 background_get_height → F_BackgroundGetHeight(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1315a8 ldr r1, [pc, #0xbe4]
 *   @0x1315ac ldr r0, [pc, #0xbe4]
 *   @0x1315b0 mov r2, #1
 *   @0x1315b4 mov r3, #0
 *   @0x1315b8 add r0, pc, r0
 *   @0x1315bc ldr r1, [r4, r1]
 *   @0x1315c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #50 background_get_transparent → F_BackgroundGetTransparent(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1315c4 ldr r1, [pc, #0xbd0]
 *   @0x1315c8 ldr r0, [pc, #0xbd0]
 *   @0x1315cc mov r2, #1
 *   @0x1315d0 mov r3, #0
 *   @0x1315d4 add r0, pc, r0
 *   @0x1315d8 ldr r1, [r4, r1]
 *   @0x1315dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #51 background_get_smooth → F_BackgroundGetSmooth(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1315e0 ldr r1, [pc, #0xbbc]
 *   @0x1315e4 ldr r0, [pc, #0xbbc]
 *   @0x1315e8 mov r2, #1
 *   @0x1315ec mov r3, #0
 *   @0x1315f0 add r0, pc, r0
 *   @0x1315f4 ldr r1, [r4, r1]
 *   @0x1315f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #52 background_get_preload → F_BackgroundGetPreload(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1315fc ldr r1, [pc, #0xba8]
 *   @0x131600 ldr r0, [pc, #0xba8]
 *   @0x131604 mov r3, #1
 *   @0x131608 mov r2, #2
 *   @0x13160c ldr r1, [r4, r1]
 *   @0x131610 add r0, pc, r0
 *   @0x131614 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #53 background_set_alpha_from_background → F_BackgroundSetAlphaFromBackground(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x131618 ldr r3, [r6]
 *   @0x13161c ldr r1, [pc, #0xb90]
 *   @0x131620 cmp r3, #800
 *   @0x131624 blt 0x132db8 <_Z21InitResourceFunctionsv+0x1dbc>   —— 条件跳转 → 0x132db8
 *   @0x131628 ldr r6, [r4, r1]
 *   @0x13162c mov r2, #3
 *   @0x131630 ldr r0, [pc, #0xb80]
 *   @0x131634 mov r3, #1
 *   @0x131638 add r0, pc, r0
 *   @0x13163c mov r1, r6
 *   @0x131640 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #54 background_create_color → F_BackgroundCreateColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x131644 ldr r0, [pc, #0xb70]
 *   @0x131648 mov r1, r6
 *   @0x13164c mov r2, #3
 *   @0x131650 add r0, pc, r0
 *   @0x131654 mov r3, #1
 *   @0x131658 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #55 background_create_colour → F_BackgroundCreateColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x13165c ldr r1, [pc, #0xfe0]
 *   @0x131660 ldr r0, [pc, #0xb58]
 *   @0x131664 mov r2, #4
 *   @0x131668 mov r3, #1
 *   @0x13166c add r0, pc, r0
 *   @0x131670 ldr r1, [r4, r1]
 *   @0x131674 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #56 background_replace → F_BackgroundReplace(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x131678 ldr r1, [pc, #0xfcc]
 *   @0x13167c ldr r0, [pc, #0xb40]
 *   @0x131680 mov r2, #6
 *   @0x131684 mov r3, #1
 *   @0x131688 add r0, pc, r0
 *   @0x13168c ldr r1, [r4, r1]
 *   @0x131690 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #57 background_create_from_screen → F_BackgroundCreateFromScreen(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x131694 ldr r1, [pc, #0xfb8]
 *   @0x131698 ldr r0, [pc, #0xb28]
 *   @0x13169c mov r2, #7
 *   @0x1316a0 mov r3, #1
 *   @0x1316a4 add r0, pc, r0
 *   @0x1316a8 ldr r1, [r4, r1]
 *   @0x1316ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #58 background_create_from_surface → F_BackgroundCreateFromSurface(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x1316b0 ldr r1, [pc, #0xfa4]
 *   @0x1316b4 ldr r0, [pc, #0xb10]
 *   @0x1316b8 mov r2, #5
 *   @0x1316bc mov r3, #1
 *   @0x1316c0 add r0, pc, r0
 *   @0x1316c4 ldr r1, [r4, r1]
 *   @0x1316c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #59 background_create_gradient → F_BackgroundCreateGradient(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x1316cc ldr r1, [pc, #0xf90]
 *   @0x1316d0 ldr r0, [pc, #0xaf8]
 *   @0x1316d4 mov r2, #3
 *   @0x1316d8 mov r3, #1
 *   @0x1316dc add r0, pc, r0
 *   @0x1316e0 ldr r1, [r4, r1]
 *   @0x1316e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #60 background_add → F_BackgroundAdd(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x1316e8 ldr r1, [pc, #0xae4]
 *   @0x1316ec ldr r0, [pc, #0xae4]
 *   @0x1316f0 mov r2, #1
 *   @0x1316f4 mov r3, r2
 *   @0x1316f8 add r0, pc, r0
 *   @0x1316fc ldr r1, [r4, r1]
 *   @0x131700 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #61 background_add_background → F_BackgroundAddBackground(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x131704 ldr r1, [pc, #0xad0]
 *   @0x131708 ldr r0, [pc, #0xad0]
 *   @0x13170c mov r2, #2
 *   @0x131710 mov r3, #1
 *   @0x131714 add r0, pc, r0
 *   @0x131718 ldr r1, [r4, r1]
 *   @0x13171c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #62 background_replace_background → F_BackgroundReplaceBackground(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x131720 ldr r1, [pc, #0xabc]
 *   @0x131724 mov r2, #1
 *   @0x131728 ldr r0, [pc, #0xab8]
 *   @0x13172c mov r3, r2
 *   @0x131730 add r0, pc, r0
 *   @0x131734 ldr r1, [r4, r1]
 *   @0x131738 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #63 background_delete → F_BackgroundDelete(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x13173c ldr r1, [pc, #0xaa8]
 *   @0x131740 ldr r0, [pc, #0xaa8]
 *   @0x131744 mov r2, #1
 *   @0x131748 mov r3, r2
 *   @0x13174c add r0, pc, r0
 *   @0x131750 ldr r1, [r4, r1]
 *   @0x131754 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #64 background_duplicate → F_BackgroundDuplicate(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x131758 ldr r1, [pc, #0xa94]
 *   @0x13175c ldr r0, [pc, #0xa94]
 *   @0x131760 mov r2, #2
 *   @0x131764 mov r3, #1
 *   @0x131768 add r0, pc, r0
 *   @0x13176c ldr r1, [r4, r1]
 *   @0x131770 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #65 background_assign → F_BackgroundAssign(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x131774 ldr r1, [pc, #0xa80]
 *   @0x131778 ldr r0, [pc, #0xa80]
 *   @0x13177c mov r2, #2
 *   @0x131780 mov r3, #1
 *   @0x131784 add r0, pc, r0
 *   @0x131788 ldr r1, [r4, r1]
 *   @0x13178c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #66 background_save → F_BackgroundSave(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x131790 ldr r1, [pc, #0xa6c]
 *   @0x131794 ldr r0, [pc, #0xa6c]
 *   @0x131798 mov r2, #1
 *   @0x13179c mov r3, r2
 *   @0x1317a0 add r0, pc, r0
 *   @0x1317a4 ldr r1, [r4, r1]
 *   @0x1317a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #67 background_prefetch → F_BackgroundPrefetch(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1317ac ldr r1, [pc, #0xa58]
 *   @0x1317b0 ldr r0, [pc, #0xa58]
 *   @0x1317b4 mov r2, #1
 *   @0x1317b8 mov r3, r2
 *   @0x1317bc add r0, pc, r0
 *   @0x1317c0 ldr r1, [r4, r1]
 *   @0x1317c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #68 background_prefetch_multi → F_BackgroundPrefetchMulti(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1317c8 ldr r1, [pc, #0xa44]
 *   @0x1317cc ldr r0, [pc, #0xa44]
 *   @0x1317d0 mov r2, #1
 *   @0x1317d4 mov r3, r2
 *   @0x1317d8 add r0, pc, r0
 *   @0x1317dc ldr r1, [r4, r1]
 *   @0x1317e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #69 background_flush → F_BackgroundFlush(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1317e4 ldr r1, [pc, #0xa30]
 *   @0x1317e8 ldr r0, [pc, #0xa30]
 *   @0x1317ec mov r2, #1
 *   @0x1317f0 mov r3, r2
 *   @0x1317f4 add r0, pc, r0
 *   @0x1317f8 ldr r1, [r4, r1]
 *   @0x1317fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #70 background_flush_multi → F_BackgroundFlushMulti(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x131800 ldr r1, [pc, #0xa1c]
 *   @0x131804 ldr r0, [pc, #0xa1c]
 *   @0x131808 mov r2, #1
 *   @0x13180c mov r3, #0
 *   @0x131810 ldr r6, [r4, r1]
 *   @0x131814 add r0, pc, r0
 *   @0x131818 mov r1, r6
 *   @0x13181c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #71 sound_name → F_SoundGetName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131820 ldr r1, [pc, #0xa04]
 *   @0x131824 ldr r0, [pc, #0xa04]
 *   @0x131828 mov r2, #1
 *   @0x13182c mov r3, #0
 *   @0x131830 add r0, pc, r0
 *   @0x131834 ldr r1, [r4, r1]
 *   @0x131838 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #72 sound_exists → F_SoundExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13183c ldr r0, [pc, #0x9f0]
 *   @0x131840 mov r1, r6
 *   @0x131844 mov r2, #1
 *   @0x131848 add r0, pc, r0
 *   @0x13184c mov r3, #0
 *   @0x131850 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #73 sound_get_name → F_SoundGetName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131854 ldr r1, [pc, #0x9dc]
 *   @0x131858 ldr r0, [pc, #0x9dc]
 *   @0x13185c mov r2, #1
 *   @0x131860 mov r3, #0
 *   @0x131864 add r0, pc, r0
 *   @0x131868 ldr r1, [r4, r1]
 *   @0x13186c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #74 sound_get_kind → F_SoundGetKind(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131870 ldr r1, [pc, #0x9c8]
 *   @0x131874 ldr r0, [pc, #0x9c8]
 *   @0x131878 mov r2, #1
 *   @0x13187c mov r3, #0
 *   @0x131880 add r0, pc, r0
 *   @0x131884 ldr r1, [r4, r1]
 *   @0x131888 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #75 sound_get_preload → F_SoundGetPreload(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13188c ldr r1, [pc, #0x9b4]
 *   @0x131890 ldr r0, [pc, #0x9b4]
 *   @0x131894 mov r2, #1
 *   @0x131898 mov r3, #0
 *   @0x13189c add r0, pc, r0
 *   @0x1318a0 ldr r1, [r4, r1]
 *   @0x1318a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #76 sound_discard → F_SoundDiscard(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1318a8 ldr r1, [pc, #0x9a0]
 *   @0x1318ac ldr r0, [pc, #0x9a0]
 *   @0x1318b0 mov r2, #1
 *   @0x1318b4 mov r3, #0
 *   @0x1318b8 add r0, pc, r0
 *   @0x1318bc ldr r1, [r4, r1]
 *   @0x1318c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #77 sound_restore → F_SoundRestore(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1318c4 ldr r1, [pc, #0x98c]
 *   @0x1318c8 ldr r0, [pc, #0x98c]
 *   @0x1318cc mov r2, #3
 *   @0x1318d0 mov r3, #1
 *   @0x1318d4 add r0, pc, r0
 *   @0x1318d8 ldr r1, [r4, r1]
 *   @0x1318dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #78 sound_add → F_SoundAdd(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x1318e0 ldr r1, [pc, #0x978]
 *   @0x1318e4 ldr r0, [pc, #0x978]
 *   @0x1318e8 mov r2, #4
 *   @0x1318ec mov r3, #1
 *   @0x1318f0 add r0, pc, r0
 *   @0x1318f4 ldr r1, [r4, r1]
 *   @0x1318f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #79 sound_replace → F_SoundReplace(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x1318fc ldr r1, [pc, #0x964]
 *   @0x131900 ldr r0, [pc, #0x964]
 *   @0x131904 mov r2, #1
 *   @0x131908 mov r3, r2
 *   @0x13190c ldr r6, [r4, r1]
 *   @0x131910 add r0, pc, r0
 *   @0x131914 mov r1, r6
 *   @0x131918 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #80 sound_delete → F_SoundDelete(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x13191c ldr r0, [pc, #0x94c]
 *   @0x131920 mov r2, #1
 *   @0x131924 mov r1, r6
 *   @0x131928 mov r3, r2
 *   @0x13192c add r0, pc, r0
 *   @0x131930 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #81 audio_delete → F_SoundDelete(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x131934 ldr r1, [pc, #0x938]
 *   @0x131938 ldr r0, [pc, #0x938]
 *   @0x13193c mov r2, #1
 *   @0x131940 mov r3, #0
 *   @0x131944 ldr r6, [r4, r1]
 *   @0x131948 add r0, pc, r0
 *   @0x13194c mov r1, r6
 *   @0x131950 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #82 font_name → F_FontGetName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131954 ldr r1, [pc, #0x920]
 *   @0x131958 ldr r0, [pc, #0x920]
 *   @0x13195c mov r2, #1
 *   @0x131960 mov r3, #0
 *   @0x131964 add r0, pc, r0
 *   @0x131968 ldr r1, [r4, r1]
 *   @0x13196c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #83 font_exists → F_FontExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131970 ldr r0, [pc, #0x90c]
 *   @0x131974 mov r1, r6
 *   @0x131978 mov r2, #1
 *   @0x13197c add r0, pc, r0
 *   @0x131980 mov r3, #0
 *   @0x131984 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #84 font_get_name → F_FontGetName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131988 ldr r1, [pc, #0x8f8]
 *   @0x13198c ldr r0, [pc, #0x8f8]
 *   @0x131990 mov r2, #1
 *   @0x131994 mov r3, #0
 *   @0x131998 add r0, pc, r0
 *   @0x13199c ldr r1, [r4, r1]
 *   @0x1319a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #85 font_get_fontname → F_FontGetFontName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1319a4 ldr r1, [pc, #0x8e4]
 *   @0x1319a8 ldr r0, [pc, #0x8e4]
 *   @0x1319ac mov r2, #1
 *   @0x1319b0 mov r3, #0
 *   @0x1319b4 add r0, pc, r0
 *   @0x1319b8 ldr r1, [r4, r1]
 *   @0x1319bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #86 font_get_size → F_FontGetSize(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1319c0 ldr r1, [pc, #0x8d0]
 *   @0x1319c4 ldr r0, [pc, #0x8d0]
 *   @0x1319c8 mov r2, #1
 *   @0x1319cc mov r3, #0
 *   @0x1319d0 add r0, pc, r0
 *   @0x1319d4 ldr r1, [r4, r1]
 *   @0x1319d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #87 font_get_bold → F_FontGetBold(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1319dc ldr r1, [pc, #0x8bc]
 *   @0x1319e0 ldr r0, [pc, #0x8bc]
 *   @0x1319e4 mov r2, #1
 *   @0x1319e8 mov r3, #0
 *   @0x1319ec add r0, pc, r0
 *   @0x1319f0 ldr r1, [r4, r1]
 *   @0x1319f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #88 font_get_italic → F_FontGetItalic(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1319f8 ldr r1, [pc, #0x8a8]
 *   @0x1319fc ldr r0, [pc, #0x8a8]
 *   @0x131a00 mov r2, #1
 *   @0x131a04 mov r3, #0
 *   @0x131a08 add r0, pc, r0
 *   @0x131a0c ldr r1, [r4, r1]
 *   @0x131a10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #89 font_get_first → F_FontGetFirst(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131a14 ldr r1, [pc, #0x894]
 *   @0x131a18 ldr r0, [pc, #0x894]
 *   @0x131a1c mov r2, #1
 *   @0x131a20 mov r3, #0
 *   @0x131a24 add r0, pc, r0
 *   @0x131a28 ldr r1, [r4, r1]
 *   @0x131a2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #90 font_get_last → F_FontGetLast(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131a30 ldr r1, [pc, #0x880]
 *   @0x131a34 ldr r0, [pc, #0x880]
 *   @0x131a38 mov r2, #1
 *   @0x131a3c mov r3, r2
 *   @0x131a40 add r0, pc, r0
 *   @0x131a44 ldr r1, [r4, r1]
 *   @0x131a48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #91 font_add_enable_aa → F_FontAddEnableAA(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x131a4c ldr r1, [pc, #0x86c]
 *   @0x131a50 ldr r0, [pc, #0x86c]
 *   @0x131a54 mov r2, #0
 *   @0x131a58 mov r3, #1
 *   @0x131a5c add r0, pc, r0
 *   @0x131a60 ldr r1, [r4, r1]
 *   @0x131a64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #92 font_add_get_enable_aa → F_FontAddGetEnableAA(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x131a68 ldr r1, [pc, #0x858]
 *   @0x131a6c ldr r0, [pc, #0x858]
 *   @0x131a70 mov r2, #6
 *   @0x131a74 mov r3, #1
 *   @0x131a78 add r0, pc, r0
 *   @0x131a7c ldr r1, [r4, r1]
 *   @0x131a80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #93 font_add → F_FontAdd(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x131a84 ldr r1, [pc, #0x844]
 *   @0x131a88 ldr r0, [pc, #0x844]
 *   @0x131a8c mov r2, #4
 *   @0x131a90 mov r3, #1
 *   @0x131a94 add r0, pc, r0
 *   @0x131a98 ldr r1, [r4, r1]
 *   @0x131a9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #94 font_add_sprite → F_FontAddSprite(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x131aa0 ldr r1, [pc, #0x830]
 *   @0x131aa4 ldr r0, [pc, #0x830]
 *   @0x131aa8 mov r2, #4
 *   @0x131aac mov r3, #1
 *   @0x131ab0 add r0, pc, r0
 *   @0x131ab4 ldr r1, [r4, r1]
 *   @0x131ab8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #95 font_add_sprite_ext → F_FontAddSpriteExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x131abc ldr r1, [pc, #0x81c]
 *   @0x131ac0 ldr r0, [pc, #0x81c]
 *   @0x131ac4 mov r2, #5
 *   @0x131ac8 mov r3, #1
 *   @0x131acc add r0, pc, r0
 *   @0x131ad0 ldr r1, [r4, r1]
 *   @0x131ad4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #96 font_replace_sprite → F_FontReplaceSprite(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x131ad8 ldr r1, [pc, #0x808]
 *   @0x131adc ldr r0, [pc, #0x808]
 *   @0x131ae0 mov r2, #5
 *   @0x131ae4 mov r3, #1
 *   @0x131ae8 add r0, pc, r0
 *   @0x131aec ldr r1, [r4, r1]
 *   @0x131af0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #97 font_replace_sprite_ext → F_FontReplaceSpriteExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x131af4 ldr r1, [pc, #0x7f4]
 *   @0x131af8 ldr r0, [pc, #0x7f4]
 *   @0x131afc mov r2, #1
 *   @0x131b00 mov r3, r2
 *   @0x131b04 add r0, pc, r0
 *   @0x131b08 ldr r1, [r4, r1]
 *   @0x131b0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #98 font_delete → F_FontDelete(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x131b10 ldr r1, [pc, #0x7e0]
 *   @0x131b14 ldr r0, [pc, #0x7e0]
 *   @0x131b18 mov r2, #1
 *   @0x131b1c mov r3, r2
 *   @0x131b20 add r0, pc, r0
 *   @0x131b24 ldr r1, [r4, r1]
 *   @0x131b28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #99 font_set_dynamic_texture_size → F_FontSetDynamicTextureSize(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x131b2c ldr r1, [pc, #0x7cc]
 *   @0x131b30 ldr r0, [pc, #0x7cc]
 *   @0x131b34 mov r2, #0
 *   @0x131b38 mov r3, #1
 *   @0x131b3c add r0, pc, r0
 *   @0x131b40 ldr r1, [r4, r1]
 *   @0x131b44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #100 font_get_dynamic_texture_size → F_FontGetDynamicTextureSize(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x131b48 ldr r1, [pc, #0x7b8]
 *   @0x131b4c ldr r0, [pc, #0x7b8]
 *   @0x131b50 mov r2, #1
 *   @0x131b54 mov r3, #0
 *   @0x131b58 ldr r6, [r4, r1]
 *   @0x131b5c add r0, pc, r0
 *   @0x131b60 mov r1, r6
 *   @0x131b64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #101 script_name → F_ScriptGetName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131b68 ldr r1, [pc, #0x7a0]
 *   @0x131b6c ldr r0, [pc, #0x7a0]
 *   @0x131b70 mov r2, #1
 *   @0x131b74 mov r3, #0
 *   @0x131b78 add r0, pc, r0
 *   @0x131b7c ldr r1, [r4, r1]
 *   @0x131b80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #102 script_exists → F_ScriptExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131b84 ldr r0, [pc, #0x78c]
 *   @0x131b88 mov r1, r6
 *   @0x131b8c mov r2, #1
 *   @0x131b90 add r0, pc, r0
 *   @0x131b94 mov r3, #0
 *   @0x131b98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #103 script_get_name → F_ScriptGetName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131b9c ldr r1, [pc, #0x778]
 *   @0x131ba0 ldr r0, [pc, #0x778]
 *   @0x131ba4 mov r2, #1
 *   @0x131ba8 mov r3, #0
 *   @0x131bac add r0, pc, r0
 *   @0x131bb0 ldr r1, [r4, r1]
 *   @0x131bb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #104 script_get_text → F_ScriptGetText(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131bb8 ldr r1, [pc, #0x764]
 *   @0x131bbc ldr r0, [pc, #0x764]
 *   @0x131bc0 mvn r2, #0
 *   @0x131bc4 mov r3, #0
 *   @0x131bc8 add r0, pc, r0
 *   @0x131bcc ldr r1, [r4, r1]
 *   @0x131bd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #105 script_execute → F_ScriptExecute(RValue&, CInstance*, CInstance*, int, RValue*) argc=-1 flag=0
 *   @0x131bd4 ldr r1, [pc, #0x750]
 *   @0x131bd8 ldr r0, [pc, #0x750]
 *   @0x131bdc mov r2, #1
 *   @0x131be0 mov r3, #0
 *   @0x131be4 ldr r6, [r4, r1]
 *   @0x131be8 add r0, pc, r0
 *   @0x131bec mov r1, r6
 *   @0x131bf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #106 path_name → F_PathGetName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131bf4 ldr r1, [pc, #0x738]
 *   @0x131bf8 ldr r0, [pc, #0x738]
 *   @0x131bfc mov r2, #1
 *   @0x131c00 mov r3, #0
 *   @0x131c04 add r0, pc, r0
 *   @0x131c08 ldr r1, [r4, r1]
 *   @0x131c0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #107 path_exists → F_PathExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131c10 ldr r0, [pc, #0x724]
 *   @0x131c14 mov r1, r6
 *   @0x131c18 mov r2, #1
 *   @0x131c1c add r0, pc, r0
 *   @0x131c20 mov r3, #0
 *   @0x131c24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #108 path_get_name → F_PathGetName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131c28 ldr r1, [pc, #0x710]
 *   @0x131c2c ldr r0, [pc, #0x710]
 *   @0x131c30 mov r2, #1
 *   @0x131c34 mov r3, #0
 *   @0x131c38 add r0, pc, r0
 *   @0x131c3c ldr r1, [r4, r1]
 *   @0x131c40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #109 path_get_length → F_PathGetLength(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131c44 ldr r1, [pc, #0x6fc]
 *   @0x131c48 ldr r0, [pc, #0x6fc]
 *   @0x131c4c mov r2, #2
 *   @0x131c50 mov r3, #0
 *   @0x131c54 add r0, pc, r0
 *   @0x131c58 ldr r1, [r4, r1]
 *   @0x131c5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #110 path_get_time → F_PathGetTime(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x131c60 ldr r1, [pc, #0x6e8]
 *   @0x131c64 ldr r0, [pc, #0x6e8]
 *   @0x131c68 mov r2, #1
 *   @0x131c6c mov r3, #0
 *   @0x131c70 add r0, pc, r0
 *   @0x131c74 ldr r1, [r4, r1]
 *   @0x131c78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #111 path_get_kind → F_PathGetKind(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131c7c ldr r1, [pc, #0x6d4]
 *   @0x131c80 ldr r0, [pc, #0x6d4]
 *   @0x131c84 mov r2, #1
 *   @0x131c88 mov r3, #0
 *   @0x131c8c add r0, pc, r0
 *   @0x131c90 ldr r1, [r4, r1]
 *   @0x131c94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #112 path_get_closed → F_PathGetClosed(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131c98 ldr r1, [pc, #0x6c0]
 *   @0x131c9c ldr r0, [pc, #0x6c0]
 *   @0x131ca0 mov r2, #1
 *   @0x131ca4 mov r3, #0
 *   @0x131ca8 add r0, pc, r0
 *   @0x131cac ldr r1, [r4, r1]
 *   @0x131cb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #113 path_get_precision → F_PathGetPrecision(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131cb4 ldr r1, [pc, #0x6ac]
 *   @0x131cb8 ldr r0, [pc, #0x6ac]
 *   @0x131cbc mov r2, #1
 *   @0x131cc0 mov r3, #0
 *   @0x131cc4 add r0, pc, r0
 *   @0x131cc8 ldr r1, [r4, r1]
 *   @0x131ccc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #114 path_get_number → F_PathGetNumber(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131cd0 ldr r1, [pc, #0x698]
 *   @0x131cd4 ldr r0, [pc, #0x698]
 *   @0x131cd8 mov r2, #2
 *   @0x131cdc mov r3, #0
 *   @0x131ce0 add r0, pc, r0
 *   @0x131ce4 ldr r1, [r4, r1]
 *   @0x131ce8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #115 path_get_point_x → F_PathGetPointX(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x131cec ldr r1, [pc, #0x684]
 *   @0x131cf0 ldr r0, [pc, #0x684]
 *   @0x131cf4 mov r2, #2
 *   @0x131cf8 mov r3, #0
 *   @0x131cfc add r0, pc, r0
 *   @0x131d00 ldr r1, [r4, r1]
 *   @0x131d04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #116 path_get_point_y → F_PathGetPointY(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x131d08 ldr r1, [pc, #0x670]
 *   @0x131d0c ldr r0, [pc, #0x670]
 *   @0x131d10 mov r2, #2
 *   @0x131d14 mov r3, #0
 *   @0x131d18 add r0, pc, r0
 *   @0x131d1c ldr r1, [r4, r1]
 *   @0x131d20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #117 path_get_point_speed → F_PathGetPointSpeed(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x131d24 ldr r1, [pc, #0x65c]
 *   @0x131d28 ldr r0, [pc, #0x65c]
 *   @0x131d2c mov r2, #2
 *   @0x131d30 mov r3, #0
 *   @0x131d34 add r0, pc, r0
 *   @0x131d38 ldr r1, [r4, r1]
 *   @0x131d3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #118 path_get_x → F_PathGetX(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x131d40 ldr r1, [pc, #0x648]
 *   @0x131d44 ldr r0, [pc, #0x648]
 *   @0x131d48 mov r2, #2
 *   @0x131d4c mov r3, #0
 *   @0x131d50 add r0, pc, r0
 *   @0x131d54 ldr r1, [r4, r1]
 *   @0x131d58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #119 path_get_y → F_PathGetY(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x131d5c ldr r1, [pc, #0x634]
 *   @0x131d60 ldr r0, [pc, #0x634]
 *   @0x131d64 mov r2, #2
 *   @0x131d68 mov r3, #0
 *   @0x131d6c add r0, pc, r0
 *   @0x131d70 ldr r1, [r4, r1]
 *   @0x131d74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #120 path_get_speed → F_PathGetSpeed(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x131d78 ldr r1, [pc, #0x620]
 *   @0x131d7c ldr r0, [pc, #0x620]
 *   @0x131d80 mov r2, #2
 *   @0x131d84 mov r3, #1
 *   @0x131d88 add r0, pc, r0
 *   @0x131d8c ldr r1, [r4, r1]
 *   @0x131d90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #121 path_set_kind → F_PathSetKind(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x131d94 ldr r1, [pc, #0x60c]
 *   @0x131d98 ldr r0, [pc, #0x60c]
 *   @0x131d9c mov r2, #2
 *   @0x131da0 mov r3, #1
 *   @0x131da4 add r0, pc, r0
 *   @0x131da8 ldr r1, [r4, r1]
 *   @0x131dac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #122 path_set_closed → F_PathSetClosed(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x131db0 ldr r1, [pc, #0x5f8]
 *   @0x131db4 ldr r0, [pc, #0x5f8]
 *   @0x131db8 mov r2, #2
 *   @0x131dbc mov r3, #1
 *   @0x131dc0 add r0, pc, r0
 *   @0x131dc4 ldr r1, [r4, r1]
 *   @0x131dc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #123 path_set_precision → F_PathSetPrecision(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x131dcc ldr r1, [pc, #0x5e4]
 *   @0x131dd0 ldr r0, [pc, #0x5e4]
 *   @0x131dd4 mov r2, #0
 *   @0x131dd8 mov r3, #1
 *   @0x131ddc add r0, pc, r0
 *   @0x131de0 ldr r1, [r4, r1]
 *   @0x131de4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #124 path_add → F_PathAdd(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x131de8 ldr r1, [pc, #0x5d0]
 *   @0x131dec ldr r0, [pc, #0x5d0]
 *   @0x131df0 mov r2, #1
 *   @0x131df4 mov r3, r2
 *   @0x131df8 add r0, pc, r0
 *   @0x131dfc ldr r1, [r4, r1]
 *   @0x131e00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #125 path_duplicate → F_PathDuplicate(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x131e04 ldr r1, [pc, #0x5bc]
 *   @0x131e08 ldr r0, [pc, #0x5bc]
 *   @0x131e0c mov r2, #2
 *   @0x131e10 mov r3, #1
 *   @0x131e14 add r0, pc, r0
 *   @0x131e18 ldr r1, [r4, r1]
 *   @0x131e1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #126 path_assign → F_PathAssign(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x131e20 ldr r1, [pc, #0x5a8]
 *   @0x131e24 ldr r0, [pc, #0x5a8]
 *   @0x131e28 mov r2, #2
 *   @0x131e2c mov r3, #1
 *   @0x131e30 add r0, pc, r0
 *   @0x131e34 ldr r1, [r4, r1]
 *   @0x131e38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #127 path_append → F_PathAppend(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x131e3c ldr r1, [pc, #0x594]
 *   @0x131e40 ldr r0, [pc, #0x594]
 *   @0x131e44 mov r2, #1
 *   @0x131e48 mov r3, r2
 *   @0x131e4c add r0, pc, r0
 *   @0x131e50 ldr r1, [r4, r1]
 *   @0x131e54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #128 path_delete → F_PathDelete(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x131e58 ldr r1, [pc, #0x580]
 *   @0x131e5c ldr r0, [pc, #0x580]
 *   @0x131e60 mov r2, #4
 *   @0x131e64 mov r3, #1
 *   @0x131e68 add r0, pc, r0
 *   @0x131e6c ldr r1, [r4, r1]
 *   @0x131e70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #129 path_add_point → F_PathAddPoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x131e74 ldr r1, [pc, #0x56c]
 *   @0x131e78 ldr r0, [pc, #0x56c]
 *   @0x131e7c mov r2, #5
 *   @0x131e80 mov r3, #1
 *   @0x131e84 add r0, pc, r0
 *   @0x131e88 ldr r1, [r4, r1]
 *   @0x131e8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #130 path_insert_point → F_PathInsertPoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x131e90 ldr r1, [pc, #0x558]
 *   @0x131e94 ldr r0, [pc, #0x558]
 *   @0x131e98 mov r2, #5
 *   @0x131e9c mov r3, #1
 *   @0x131ea0 add r0, pc, r0
 *   @0x131ea4 ldr r1, [r4, r1]
 *   @0x131ea8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #131 path_change_point → F_PathChangePoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x131eac ldr r1, [pc, #0x544]
 *   @0x131eb0 ldr r0, [pc, #0x544]
 *   @0x131eb4 mov r2, #2
 *   @0x131eb8 mov r3, #1
 *   @0x131ebc add r0, pc, r0
 *   @0x131ec0 ldr r1, [r4, r1]
 *   @0x131ec4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #132 path_delete_point → F_PathDeletePoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x131ec8 ldr r1, [pc, #0x530]
 *   @0x131ecc ldr r0, [pc, #0x530]
 *   @0x131ed0 mov r2, #1
 *   @0x131ed4 mov r3, r2
 *   @0x131ed8 add r0, pc, r0
 *   @0x131edc ldr r1, [r4, r1]
 *   @0x131ee0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #133 path_clear_points → F_PathClearPoints(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x131ee4 ldr r1, [pc, #0x51c]
 *   @0x131ee8 ldr r0, [pc, #0x51c]
 *   @0x131eec mov r2, #1
 *   @0x131ef0 mov r3, r2
 *   @0x131ef4 add r0, pc, r0
 *   @0x131ef8 ldr r1, [r4, r1]
 *   @0x131efc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #134 path_reverse → F_PathReverse(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x131f00 ldr r1, [pc, #0x508]
 *   @0x131f04 ldr r0, [pc, #0x508]
 *   @0x131f08 mov r2, #1
 *   @0x131f0c mov r3, r2
 *   @0x131f10 add r0, pc, r0
 *   @0x131f14 ldr r1, [r4, r1]
 *   @0x131f18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #135 path_mirror → F_PathMirror(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x131f1c ldr r1, [pc, #0x4f4]
 *   @0x131f20 ldr r0, [pc, #0x4f4]
 *   @0x131f24 mov r2, #1
 *   @0x131f28 mov r3, r2
 *   @0x131f2c add r0, pc, r0
 *   @0x131f30 ldr r1, [r4, r1]
 *   @0x131f34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #136 path_flip → F_PathFlip(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x131f38 ldr r1, [pc, #0x4e0]
 *   @0x131f3c ldr r0, [pc, #0x4e0]
 *   @0x131f40 mov r2, #2
 *   @0x131f44 mov r3, #1
 *   @0x131f48 add r0, pc, r0
 *   @0x131f4c ldr r1, [r4, r1]
 *   @0x131f50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #137 path_rotate → F_PathRotate(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x131f54 ldr r1, [pc, #0x4cc]
 *   @0x131f58 ldr r0, [pc, #0x4cc]
 *   @0x131f5c mov r2, #3
 *   @0x131f60 mov r3, #1
 *   @0x131f64 add r0, pc, r0
 *   @0x131f68 ldr r1, [r4, r1]
 *   @0x131f6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #138 path_rescale → F_PathReScale(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x131f70 ldr r1, [pc, #0x4b8]
 *   @0x131f74 ldr r0, [pc, #0x4b8]
 *   @0x131f78 mov r2, #3
 *   @0x131f7c mov r3, #1
 *   @0x131f80 add r0, pc, r0
 *   @0x131f84 ldr r1, [r4, r1]
 *   @0x131f88 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #139 path_shift → F_PathShift(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x131f8c ldr r1, [pc, #0x4a4]
 *   @0x131f90 ldr r0, [pc, #0x4a4]
 *   @0x131f94 mov r2, #1
 *   @0x131f98 mov r3, #0
 *   @0x131f9c ldr r6, [r4, r1]
 *   @0x131fa0 add r0, pc, r0
 *   @0x131fa4 mov r1, r6
 *   @0x131fa8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #140 timeline_name → F_TimeLineGetName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131fac ldr r1, [pc, #0x48c]
 *   @0x131fb0 ldr r0, [pc, #0x48c]
 *   @0x131fb4 mov r2, #1
 *   @0x131fb8 mov r3, #0
 *   @0x131fbc add r0, pc, r0
 *   @0x131fc0 ldr r1, [r4, r1]
 *   @0x131fc4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #141 timeline_exists → F_TimeLineExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131fc8 ldr r0, [pc, #0x478]
 *   @0x131fcc mov r1, r6
 *   @0x131fd0 mov r2, #1
 *   @0x131fd4 add r0, pc, r0
 *   @0x131fd8 mov r3, #0
 *   @0x131fdc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #142 timeline_get_name → F_TimeLineGetName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x131fe0 ldr r1, [pc, #0x464]
 *   @0x131fe4 ldr r0, [pc, #0x464]
 *   @0x131fe8 mov r2, #0
 *   @0x131fec mov r3, #1
 *   @0x131ff0 add r0, pc, r0
 *   @0x131ff4 ldr r1, [r4, r1]
 *   @0x131ff8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #143 timeline_add → F_TimeLineAdd(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x131ffc b 0x1326ac <_Z21InitResourceFunctionsv+0x16b0>
 *   @0x132000 eoreq r0, r12, r0, asr #24
 *   @0x132004 .word 0xffffd0e4
 *   @0x132008 .word 0x0020d3b4
 *   @0x13200c .word 0xffffd0e8
 *   @0x132010 eoreq sp, r0, r4, lsr #7
 *   @0x132014 mlaeq r0, r12, r3, sp
 *   @0x132018 .word 0xffffd0ec
 *   @0x13201c mlaeq r0, r0, r3, sp
 *   @0x132020 .word 0xffffd0f0
 *   @0x132024 eoreq sp, r0, r8, lsl #7
 *   @0x132028 .word 0xffffd0f4
 *   @0x13202c eoreq sp, r0, r0, lsl #7
 *   @0x132030 .word 0xffffd0f8
 *   @0x132034 eoreq sp, r0, r8, ror r3
 *   @0x132038 .word 0xffffd0fc
 *   @0x13203c eoreq sp, r0, r4, ror r3
 *   @0x132040 .word 0xffffd100
 *   @0x132044 eoreq sp, r0, r12, ror #6
 *   @0x132048 .word 0xffffd104
 *   @0x13204c eoreq sp, r0, r4, ror #6
 *   @0x132050 .word 0xffffd108
 *   @0x132054 eoreq sp, r0, r12, asr r3
 *   @0x132058 .word 0xffffd10c
 *   @0x13205c eoreq sp, r0, r4, asr r3
 *   @0x132060 .word 0xffffd110
 *   @0x132064 eoreq sp, r0, r0, asr r3
 *   @0x132068 .word 0xffffd114
 *   @0x13206c eoreq sp, r0, r12, asr #6
 *   @0x132070 .word 0xffffd118
 *   @0x132074 eoreq sp, r0, r8, asr #6
 *   @0x132078 .word 0xffffd11c
 *   @0x13207c eoreq sp, r0, r0, asr #6
 *   @0x132080 .word 0xffffd120
 *   @0x132084 eoreq sp, r0, r12, lsr r3
 *   @0x132088 .word 0xffffd124
 *   @0x13208c eoreq sp, r0, r4, lsr r3
 *   @0x132090 .word 0xffffd128
 *   @0x132094 eoreq sp, r0, r0, lsr r3
 *   @0x132098 .word 0xffffd12c
 *   @0x13209c eoreq sp, r0, r12, lsr #6
 *   @0x1320a0 .word 0xffffd130
 *   @0x1320a4 eoreq sp, r0, r12, lsr #6
 *   @0x1320a8 .word 0xffffd134
 *   @0x1320ac eoreq sp, r0, r4, lsr #6
 *   @0x1320b0 .word 0xffffd138
 *   @0x1320b4 eoreq sp, r0, r8, lsl r3
 *   @0x1320b8 .word 0xffffd13c
 *   @0x1320bc eoreq sp, r0, r0, lsl r3
 *   @0x1320c0 .word 0xffffd140
 *   @0x1320c4 eoreq sp, r0, r12, lsl #6
 *   @0x1320c8 .word 0xffffd144
 *   @0x1320cc eoreq sp, r0, r0, lsl #6
 *   @0x1320d0 .word 0xffffd148
 *   @0x1320d4 .word 0x0020d2f4
 *   @0x1320d8 .word 0xffffd14c
 *   @0x1320dc .word 0xffffd150
 *   @0x1320e0 eoreq sp, r0, r4, ror #5
 *   @0x1320e4 .word 0xffffd154
 *   @0x1320e8 .word 0x0020d2d8
 *   @0x1320ec .word 0xffffd158
 *   @0x1320f0 .word 0x0020d2d8
 *   @0x1320f4 .word 0xffffd15c
 *   @0x1320f8 .word 0x0020d2d4
 *   @0x1320fc .word 0xffffd160
 *   @0x132100 .word 0x0020d2d4
 *   @0x132104 .word 0xffffd164
 *   @0x132108 .word 0x0020d2d0
 *   @0x13210c .word 0xffffd168
 *   @0x132110 eoreq sp, r0, r4, asr #5
 *   @0x132114 .word 0xffffd16c
 *   @0x132118 .word 0x0020d2bc
 *   @0x13211c .word 0xffffd170
 *   @0x132120 .word 0x0020d2b8
 *   @0x132124 .word 0xffffd174
 *   @0x132128 .word 0x0020d2dc
 *   @0x13212c .word 0xffffd178
 *   @0x132130 .word 0x0020d2d0
 *   @0x132134 .word 0xffffd17c
 *   @0x132138 eoreq sp, r0, r8, asr #5
 *   @0x13213c .word 0xffffd180
 *   @0x132140 .word 0x0020d2bc
 *   @0x132144 .word 0xffffd184
 *   @0x132148 .word 0x0020d2b0
 *   @0x13214c .word 0xffffd188
 *   @0x132150 eoreq sp, r0, r0, lsr #5
 *   @0x132154 .word 0xffffd18c
 *   @0x132158 mlaeq r0, r4, r2, sp
 *   @0x13215c .word 0xffffd190
 *   @0x132160 mlaeq r0, r0, r2, sp
 *   @0x132164 .word 0xffffd194
 *   @0x132168 eoreq sp, r0, r4, lsl #5
 *   @0x13216c .word 0xffffbcd4
 *   @0x132170 .word 0xffffd198
 *   @0x132174 eoreq sp, r0, r4, lsr #5
 *   @0x132178 .word 0xffffd19c
 *   @0x13217c mlaeq r0, r8, r2, sp
 *   @0x132180 mlaeq r0, r4, r2, sp
 *   @0x132184 .word 0xffffd1a0
 *   @0x132188 eoreq sp, r0, r12, lsl #5
 *   @0x13218c .word 0xffffd1a4
 *   @0x132190 eoreq sp, r0, r8, lsl #5
 *   @0x132194 .word 0xffffd1a8
 *   @0x132198 eoreq sp, r0, r4, lsl #5
 *   @0x13219c .word 0xffffd1ac
 *   @0x1321a0 eoreq sp, r0, r4, lsl #5
 *   @0x1321a4 .word 0xffffd1b0
 *   @0x1321a8 eoreq sp, r0, r0, lsl #5
 *   @0x1321ac .word 0xffffd1b4
 *   @0x1321b0 eoreq sp, r0, r8, ror r2
 *   @0x1321b4 .word 0xffffd1b8
 *   @0x1321b8 eoreq sp, r0, r8, ror r2
 *   @0x1321bc eoreq sp, r0, r8, ror r2
 *   @0x1321c0 eoreq sp, r0, r8, ror r2
 *   @0x1321c4 eoreq sp, r0, r0, ror r2
 *   @0x1321c8 eoreq sp, r0, r4, ror r2
 *   @0x1321cc eoreq sp, r0, r8, ror r2
 *   @0x1321d0 eoreq sp, r0, r8, ror r2
 *   @0x1321d4 .word 0xffffd1bc
 *   @0x1321d8 eoreq sp, r0, r12, ror #4
 *   @0x1321dc .word 0xffffd1c0
 *   @0x1321e0 eoreq sp, r0, r12, ror #4
 *   @0x1321e4 .word 0xffffd1c4
 *   @0x1321e8 eoreq sp, r0, r4, lsr #5
 *   @0x1321ec .word 0xffffd1c8
 *   @0x1321f0 mlaeq r0, r12, r2, sp
 *   @0x1321f4 .word 0xffffd1cc
 *   @0x1321f8 mlaeq r0, r8, r2, sp
 *   @0x1321fc .word 0xffffd1d0
 *   @0x132200 mlaeq r0, r0, r2, sp
 *   @0x132204 .word 0xffffd1d4
 *   @0x132208 eoreq sp, r0, r4, lsl #5
 *   @0x13220c .word 0xffffd1d8
 *   @0x132210 eoreq sp, r0, r12, ror r2
 *   @0x132214 .word 0xffffd1dc
 *   @0x132218 eoreq sp, r0, r12, ror r2
 *   @0x13221c .word 0xffffd1e0
 *   @0x132220 eoreq sp, r0, r4, ror r2
 *   @0x132224 .word 0xffffd1e4
 *   @0x132228 eoreq sp, r0, r12, ror #4
 *   @0x13222c .word 0xffffd1e8
 *   @0x132230 eoreq sp, r0, r12, asr r2
 *   @0x132234 eoreq sp, r0, r4, asr r2
 *   @0x132238 .word 0xffffd1ec
 *   @0x13223c eoreq sp, r0, r8, asr #4
 *   @0x132240 .word 0xffffd1f0
 *   @0x132244 eoreq sp, r0, r12, lsr r2
 *   @0x132248 .word 0xffffd1f4
 *   @0x13224c eoreq sp, r0, r4, lsr r2
 *   @0x132250 .word 0xffffd1f8
 *   @0x132254 eoreq sp, r0, r8, lsr #4
 *   @0x132258 .word 0xffffd1fc
 *   @0x13225c eoreq sp, r0, r12, lsl r2
 *   @0x132260 .word 0xffffd200
 *   @0x132264 eoreq sp, r0, r12, lsl #4
 *   @0x132268 .word 0xffffd204
 *   @0x13226c .word 0x0020d1fc
 *   @0x132270 .word 0x0020d1f0
 *   @0x132274 .word 0xffffd208
 *   @0x132278 eoreq sp, r0, r4, ror #3
 *   @0x13227c .word 0xffffd20c
 *   @0x132280 .word 0x0020d1d4
 *   @0x132284 eoreq sp, r0, r8, asr #3
 *   @0x132288 .word 0xffffd210
 *   @0x13228c .word 0x0020d1bc
 *   @0x132290 .word 0xffffd214
 *   @0x132294 .word 0x0020d1b4
 *   @0x132298 .word 0xffffd218
 *   @0x13229c eoreq sp, r0, r8, lsr #3
 *   @0x1322a0 .word 0xffffd21c
 *   @0x1322a4 mlaeq r0, r12, r1, sp
 *   @0x1322a8 .word 0xffffd220
 *   @0x1322ac mlaeq r0, r0, r1, sp
 *   @0x1322b0 .word 0xffffd224
 *   @0x1322b4 eoreq sp, r0, r4, lsl #3
 *   @0x1322b8 .word 0xffffd228
 *   @0x1322bc eoreq sp, r0, r8, ror r1
 *   @0x1322c0 .word 0xffffd22c
 *   @0x1322c4 eoreq sp, r0, r0, ror r1
 *   @0x1322c8 .word 0xffffd230
 *   @0x1322cc eoreq sp, r0, r12, ror #2
 *   @0x1322d0 .word 0xffffd234
 *   @0x1322d4 eoreq sp, r0, r12, asr r1
 *   @0x1322d8 .word 0xffffd238
 *   @0x1322dc eoreq sp, r0, r0, asr r1
 *   @0x1322e0 .word 0xffffd23c
 *   @0x1322e4 eoreq sp, r0, r8, asr #2
 *   @0x1322e8 .word 0xffffd240
 *   @0x1322ec eoreq sp, r0, r0, asr #2
 *   @0x1322f0 .word 0xffffd244
 *   @0x1322f4 eoreq sp, r0, r12, lsr r1
 *   @0x1322f8 .word 0xffffd248
 *   @0x1322fc eoreq sp, r0, r12, lsr #2
 *   @0x132300 .word 0xffffd24c
 *   @0x132304 eoreq sp, r0, r0, lsr r1
 *   @0x132308 .word 0xffffd250
 *   @0x13230c eoreq sp, r0, r0, lsr r1
 *   @0x132310 .word 0xffffd254
 *   @0x132314 eoreq sp, r0, r0, lsr #2
 *   @0x132318 eoreq sp, r0, r8, lsl r1
 *   @0x13231c .word 0xffffd258
 *   @0x132320 eoreq sp, r0, r12, lsl #2
 *   @0x132324 .word 0xffffd25c
 *   @0x132328 eoreq r0, r0, r4, lsr #12
 *   @0x13232c .word 0xffffd260
 *   @0x132330 eoreq sp, r0, r0, ror #1
 *   @0x132334 .word 0xffffd264
 *   @0x132338 .word 0x0020d0d0
 *   @0x13233c eoreq sp, r0, r4, asr #1
 *   @0x132340 .word 0xffffd268
 *   @0x132344 strhteq sp, [r0], -r8
 *   @0x132348 .word 0xffffd26c
 *   @0x13234c eoreq sp, r0, r12, lsr #1
 *   @0x132350 .word 0xffffd270
 *   @0x132354 eoreq sp, r0, r0, lsr #1
 *   @0x132358 .word 0xffffd274
 *   @0x13235c mlaeq r0, r4, r0, sp
 *   @0x132360 .word 0xffffd278
 *   @0x132364 eoreq sp, r0, r8, lsl #1
 *   @0x132368 .word 0xffffd27c
 *   @0x13236c eoreq sp, r0, r0, lsl #1
 *   @0x132370 .word 0xffffd280
 *   @0x132374 eoreq sp, r0, r4, ror r0
 *   @0x132378 .word 0xffffd284
 *   @0x13237c eoreq sp, r0, r12, rrx
 *   @0x132380 .word 0xffffd288
 *   @0x132384 eoreq sp, r0, r4, rrx
 *   @0x132388 .word 0xffffd28c
 *   @0x13238c eoreq sp, r0, r0, rrx
 *   @0x132390 .word 0xffffd290
 *   @0x132394 eoreq sp, r0, r0, asr r0
 *   @0x132398 .word 0xffffd294
 *   @0x13239c eoreq sp, r0, r0, asr #32
 *   @0x1323a0 .word 0xffffd298
 *   @0x1323a4 eoreq sp, r0, r4, lsr r0
 *   @0x1323a8 .word 0xffffd29c
 *   @0x1323ac eoreq sp, r0, r8, lsr #32
 *   @0x1323b0 .word 0xffffd2a0
 *   @0x1323b4 eoreq sp, r0, r12, lsl r0
 *   @0x1323b8 .word 0xffffd2a4
 *   @0x1323bc eoreq sp, r0, r4, lsl r0
 *   @0x1323c0 .word 0xffffd2a8
 *   @0x1323c4 eoreq sp, r0, r4
 *   @0x1323c8 .word 0xffffd2ac
 *   @0x1323cc .word 0x0020cff8
 *   @0x1323d0 .word 0xffffd2b0
 *   @0x1323d4 eoreq r12, r0, r8, ror #31
 *   @0x1323d8 .word 0xffffd2b4
 *   @0x1323dc .word 0x0020cfd8
 *   @0x1323e0 .word 0xffffd2b8
 *   @0x1323e4 eoreq r12, r0, r8, asr #31
 *   @0x1323e8 .word 0xffffd2bc
 *   @0x1323ec .word 0x0020cfbc
 *   @0x1323f0 .word 0xffffd2c0
 *   @0x1323f4 .word 0x0020cfb4
 *   @0x1323f8 .word 0xffffd2c4
 *   @0x1323fc eoreq r12, r0, r12, lsr #31
 *   @0x132400 .word 0xffffd2c8
 *   @0x132404 eoreq r12, r0, r4, lsr #31
 *   @0x132408 .word 0xffffd2cc
 *   @0x13240c mlaeq r0, r12, pc, r12
 *   @0x132410 .word 0xffffd2d0
 *   @0x132414 mlaeq r0, r0, pc, r12
 *   @0x132418 .word 0xffffd2d4
 *   @0x13241c eoreq r12, r0, r0, lsl #31
 *   @0x132420 .word 0xffffd2d8
 *   @0x132424 eoreq r12, r0, r0, ror pc
 *   @0x132428 .word 0xffffd2dc
 *   @0x13242c eoreq r12, r0, r0, ror #30
 *   @0x132430 .word 0xffffd2e0
 *   @0x132434 eoreq r12, r0, r4, asr pc
 *   @0x132438 .word 0xffffd2e4
 *   @0x13243c eoreq r12, r0, r0, asr #30
 *   @0x132440 .word 0xffffd2e8
 *   @0x132444 eoreq r12, r0, r4, lsr pc
 *   @0x132448 eoreq r12, r0, r12, lsr #30
 *   @0x13244c .word 0xffffd2ec
 *   @0x132450 eoreq r12, r0, r4, lsr #30
 *   @0x132454 .word 0xffffd2f0
 *   @0x132458 eoreq r12, r0, r8, ror #16
 *   @0x13245c .word 0xffffd2f4
 *   @0x132460 eoreq r12, r0, r12, asr r8
 *   @0x132464 .word 0xffffd2f8
 *   @0x132468 eoreq r12, r0, r8, asr r8
 *   @0x13246c .word 0xffffd2fc
 *   @0x132470 eoreq r12, r0, r12, asr #16
 *   @0x132474 .word 0xffffd300
 *   @0x132478 eoreq r12, r0, r4, asr #16
 *   @0x13247c .word 0xffffd304
 *   @0x132480 eoreq r12, r0, r4, asr #16
 *   @0x132484 .word 0xffffd308
 *   @0x132488 eoreq r12, r0, r8, lsr r8
 *   @0x13248c .word 0xffffd30c
 *   @0x132490 eoreq r12, r0, r12, lsr #16
 *   @0x132494 .word 0xffffd310
 *   @0x132498 eoreq r12, r0, r12, lsl r8
 *   @0x13249c eoreq r12, r0, r4, lsl r8
 *   @0x1324a0 .word 0xffffd314
 *   @0x1324a4 eoreq r12, r0, r8, lsl #16
 *   @0x1324a8 .word 0xffffd318
 *   @0x1324ac eoreq r12, r0, r0, lsl #16
 *   @0x1324b0 .word 0xffffd31c
 *   @0x1324b4 .word 0x0020c7f8
 *   @0x1324b8 .word 0xffffd320
 *   @0x1324bc eoreq r12, r0, r12, lsl #16
 *   @0x1324c0 .word 0xffffd324
 *   @0x1324c4 eoreq r12, r0, r8, lsl #16
 *   @0x1324c8 .word 0xffffd328
 *   @0x1324cc .word 0x0020c7fc
 *   @0x1324d0 .word 0xffffd32c
 *   @0x1324d4 .word 0x0020c7f4
 *   @0x1324d8 .word 0xffffd330
 *   @0x1324dc eoreq r12, r0, r12, ror #15
 *   @0x1324e0 .word 0xffffd334
 *   @0x1324e4 eoreq r12, r0, r4, ror #15
 *   @0x1324e8 .word 0xffffd338
 *   @0x1324ec .word 0x0020c7dc
 *   @0x1324f0 .word 0xffffd33c
 *   @0x1324f4 .word 0x0020c7d4
 *   @0x1324f8 .word 0xffffd340
 *   @0x1324fc eoreq r12, r0, r12, asr #15
 *   @0x132500 .word 0xffffd344
 *   @0x132504 eoreq r12, r0, r8, asr #15
 *   @0x132508 .word 0xffffd348
 *   @0x13250c .word 0x0020c7bc
 *   @0x132510 .word 0xffffd34c
 *   @0x132514 .word 0x0020c7b4
 *   @0x132518 .word 0xffffd350
 *   @0x13251c .word 0x0020c7b0
 *   @0x132520 .word 0xffffd354
 *   @0x132524 eoreq r12, r0, r0, lsr #15
 *   @0x132528 .word 0xffffd358
 *   @0x13252c mlaeq r0, r4, r7, r12
 *   @0x132530 .word 0xffffd35c
 *   @0x132534 eoreq r12, r0, r12, lsl #15
 *   @0x132538 .word 0xffffd360
 *   @0x13253c eoreq r12, r0, r0, lsl #15
 *   @0x132540 .word 0xffffd364
 *   @0x132544 eoreq r12, r0, r0, ror r7
 *   @0x132548 eoreq r12, r0, r4, ror #14
 *   @0x13254c .word 0xffffd368
 *   @0x132550 eoreq r12, r0, r8, asr r7
 *   @0x132554 .word 0xffffd36c
 *   @0x132558 eoreq r12, r0, r12, asr #14
 *   @0x13255c .word 0xffffd370
 *   @0x132560 eoreq r12, r0, r0, asr #14
 *   @0x132564 .word 0xffffd374
 *   @0x132568 eoreq r12, r0, r8, lsr r7
 *   @0x13256c .word 0xffffd378
 *   @0x132570 eoreq r12, r0, r0, lsr r7
 *   @0x132574 .word 0xffffd37c
 *   @0x132578 eoreq r12, r0, r0, lsr #14
 *   @0x13257c eoreq r12, r0, r4, lsr #14
 *   @0x132580 .word 0xffffd380
 *   @0x132584 eoreq r12, r0, r4, lsr #14
 *   @0x132588 .word 0xffffd384
 *   @0x13258c eoreq r12, r0, r0, lsl r7
 *   @0x132590 .word 0xffffd388
 *   @0x132594 eoreq r12, r0, r8, lsl #14
 *   @0x132598 .word 0xffffd38c
 *   @0x13259c eoreq r12, r0, r0, lsl r7
 *   @0x1325a0 .word 0xffffd390
 *   @0x1325a4 eoreq r12, r0, r12, lsl #14
 *   @0x1325a8 .word 0xffffd394
 *   @0x1325ac .word 0x0020c6fc
 *   @0x1325b0 .word 0xffffd398
 *   @0x1325b4 .word 0x0020c6f0
 *   @0x1325b8 .word 0xffffd39c
 *   @0x1325bc eoreq r12, r0, r0, ror #13
 *   @0x1325c0 .word 0xffffd3a0
 *   @0x1325c4 .word 0x0020c6d8
 *   @0x1325c8 .word 0xffffd3a4
 *   @0x1325cc .word 0x0020c6d0
 *   @0x1325d0 .word 0xffffd3a8
 *   @0x1325d4 eoreq r12, r0, r4, asr #13
 *   @0x1325d8 .word 0xffffd3ac
 *   @0x1325dc .word 0x0020c6bc
 *   @0x1325e0 .word 0xffffd3b0
 *   @0x1325e4 eoreq r12, r0, r4, lsr #13
 *   @0x1325e8 .word 0xffffd3b4
 *   @0x1325ec mlaeq r0, r8, r6, r12
 *   @0x1325f0 .word 0xffffd3b8
 *   @0x1325f4 eoreq r12, r0, r8, lsl #13
 *   @0x1325f8 .word 0xffffd3bc
 *   @0x1325fc eoreq r12, r0, r12, ror r6
 *   @0x132600 eoreq r11, r0, r0, lsr #18
 *   @0x132604 .word 0xffffd154
 *   @0x132608 eoreq r11, r0, r0, lsl r9
 *   @0x13260c .word 0xffffd158
 *   @0x132610 eoreq r11, r0, r0, lsl r9
 *   @0x132614 .word 0xffffd15c
 *   @0x132618 eoreq r11, r0, r12, lsl #18
 *   @0x13261c .word 0xffffd160
 *   @0x132620 eoreq r11, r0, r12, lsl #18
 *   @0x132624 .word 0xffffd164
 *   @0x132628 eoreq r11, r0, r8, lsl #18
 *   @0x13262c .word 0xffffd3c0
 *   @0x132630 eoreq r11, r0, r12, lsr r9
 *   @0x132634 .word 0xffffd3c4
 *   @0x132638 eoreq r11, r0, r8, lsr r9
 *   @0x13263c eoreq r11, r0, r4, ror #21
 *   @0x132640 eoreq r11, r0, r8, ror #21
 *   @0x132644 .word 0xffffd3c8
 *   @0x132648 eoreq r11, r0, r4, ror #21
 *   @0x13264c .word 0xffffd3cc
 *   @0x132650 .word 0x0020badc
 *   @0x132654 .word 0xffffd3d0
 *   @0x132658 eoreq r11, r0, r0, ror #21
 *   @0x13265c .word 0xffffd3d4
 *   @0x132660 eoreq r11, r0, r4, ror #21
 *   @0x132664 .word 0xffffd3d8
 *   @0x132668 eoreq r11, r0, r4, ror #21
 *   @0x13266c .word 0xffffd3dc
 *   @0x132670 eoreq r11, r0, r4, lsl r11
 *   @0x132674 .word 0xffffd3e0
 *   @0x132678 eoreq r11, r0, r4, lsl r11
 *   @0x13267c .word 0xffffd3e4
 *   @0x132680 eoreq r12, r0, r8, lsr #7
 *   @0x132684 .word 0xffffd3e8
 *   @0x132688 eoreq r12, r0, r8, lsr #2
 *   @0x13268c .word 0xffffd3ec
 *   @0x132690 eoreq r12, r0, r4, lsr #2
 *   @0x132694 .word 0xffffd3f0
 *   @0x132698 eoreq r11, r0, r8, ror #16
 *   @0x13269c .word 0xffffd3f4
 *   @0x1326a0 eoreq r11, r0, r0, ror #16
 *   @0x1326a4 .word 0xffffd3f8
 *   @0x1326a8 eoreq r11, r0, r0, ror #16
 *   @0x1326ac ldr r1, [pc, #-0x260]
 *   @0x1326b0 ldr r0, [pc, #-0x260]
 *   @0x1326b4 mov r2, #1
 *   @0x1326b8 mov r3, r2
 *   @0x1326bc add r0, pc, r0
 *   @0x1326c0 ldr r1, [r4, r1]
 *   @0x1326c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #144 timeline_delete → F_TimeLineDelete(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1326c8 ldr r1, [pc, #-0x274]
 *   @0x1326cc ldr r0, [pc, #-0x274]
 *   @0x1326d0 mov r2, #2
 *   @0x1326d4 mov r3, #1
 *   @0x1326d8 add r0, pc, r0
 *   @0x1326dc ldr r1, [r4, r1]
 *   @0x1326e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #145 timeline_moment_clear → F_TimeLineMomentClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1326e4 ldr r1, [pc, #-0x288]
 *   @0x1326e8 ldr r0, [pc, #-0x288]
 *   @0x1326ec mov r2, #1
 *   @0x1326f0 mov r3, r2
 *   @0x1326f4 add r0, pc, r0
 *   @0x1326f8 ldr r1, [r4, r1]
 *   @0x1326fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #146 timeline_clear → F_TimeLineClearAll(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x132700 ldr r1, [pc, #-0x29c]
 *   @0x132704 ldr r0, [pc, #-0x29c]
 *   @0x132708 mov r2, #3
 *   @0x13270c mov r3, #1
 *   @0x132710 add r0, pc, r0
 *   @0x132714 ldr r1, [r4, r1]
 *   @0x132718 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #147 timeline_moment_add → F_TimeLineMomentAdd(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x13271c ldr r1, [pc, #-0x2b0]
 *   @0x132720 ldr r0, [pc, #-0x2b0]
 *   @0x132724 mov r2, #3
 *   @0x132728 mov r3, #1
 *   @0x13272c add r0, pc, r0
 *   @0x132730 ldr r1, [r4, r1]
 *   @0x132734 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #148 timeline_moment_add_script → F_TimeLineMomentAddScript(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x132738 ldr r1, [pc, #-0x2c4]
 *   @0x13273c ldr r0, [pc, #-0x2c4]
 *   @0x132740 mov r2, #1
 *   @0x132744 mov r3, r2
 *   @0x132748 add r0, pc, r0
 *   @0x13274c ldr r1, [r4, r1]
 *   @0x132750 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #149 timeline_size → F_TimeLineSize(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x132754 ldr r1, [pc, #-0x2d8]
 *   @0x132758 ldr r0, [pc, #-0x2d8]
 *   @0x13275c mov r2, #1
 *   @0x132760 mov r3, r2
 *   @0x132764 add r0, pc, r0
 *   @0x132768 ldr r1, [r4, r1]
 *   @0x13276c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #150 timeline_max_moment → F_TimeLineMaxMoment(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x132770 ldr r1, [pc, #-0x2ec]
 *   @0x132774 ldr r0, [pc, #-0x2ec]
 *   @0x132778 mov r2, #1
 *   @0x13277c mov r3, #0
 *   @0x132780 ldr r6, [r4, r1]
 *   @0x132784 add r0, pc, r0
 *   @0x132788 mov r1, r6
 *   @0x13278c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #151 object_name → F_ObjectGetName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x132790 ldr r1, [pc, #-0x304]
 *   @0x132794 ldr r0, [pc, #-0x304]
 *   @0x132798 mov r2, #1
 *   @0x13279c mov r3, #0
 *   @0x1327a0 add r0, pc, r0
 *   @0x1327a4 ldr r1, [r4, r1]
 *   @0x1327a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #152 object_exists → F_ObjectExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1327ac ldr r0, [pc, #-0x318]
 *   @0x1327b0 mov r1, r6
 *   @0x1327b4 mov r2, #1
 *   @0x1327b8 add r0, pc, r0
 *   @0x1327bc mov r3, #0
 *   @0x1327c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #153 object_get_name → F_ObjectGetName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1327c4 ldr r1, [pc, #-0x32c]
 *   @0x1327c8 ldr r0, [pc, #-0x32c]
 *   @0x1327cc mov r2, #1
 *   @0x1327d0 mov r3, #0
 *   @0x1327d4 add r0, pc, r0
 *   @0x1327d8 ldr r1, [r4, r1]
 *   @0x1327dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #154 object_get_sprite → F_ObjectGetSprite(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1327e0 ldr r1, [pc, #-0x340]
 *   @0x1327e4 ldr r0, [pc, #-0x340]
 *   @0x1327e8 mov r2, #1
 *   @0x1327ec mov r3, #0
 *   @0x1327f0 add r0, pc, r0
 *   @0x1327f4 ldr r1, [r4, r1]
 *   @0x1327f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #155 object_get_solid → F_ObjectGetSolid(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1327fc ldr r1, [pc, #-0x354]
 *   @0x132800 ldr r0, [pc, #-0x354]
 *   @0x132804 mov r3, #0
 *   @0x132808 mov r2, #1
 *   @0x13280c add r0, pc, r0
 *   @0x132810 ldr r1, [r4, r1]
 *   @0x132814 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #156 object_get_visible → F_ObjectGetVisible(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x132818 ldrb r3, [r5]
 *   @0x13281c cmp r3, #0
 *   @0x132820 beq 0x132ee0 <_Z21InitResourceFunctionsv+0x1ee4>   —— 条件跳转 → 0x132ee0
 *   @0x132824 ldr r1, [pc, #-0x374]
 *   @0x132828 mov r2, #1
 *   @0x13282c ldr r0, [pc, #-0x378]
 *   @0x132830 mov r3, #0
 *   @0x132834 add r0, pc, r0
 *   @0x132838 ldr r1, [r4, r1]
 *   @0x13283c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #157 object_get_persistent → F_ObjectGetPersistent(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x132840 ldr r1, [pc, #-0x388]
 *   @0x132844 ldr r0, [pc, #-0x388]
 *   @0x132848 mov r2, #1
 *   @0x13284c mov r3, #0
 *   @0x132850 add r0, pc, r0
 *   @0x132854 ldr r1, [r4, r1]
 *   @0x132858 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #158 object_get_mask → F_ObjectGetMask(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13285c ldr r1, [pc, #-0x39c]
 *   @0x132860 ldr r0, [pc, #-0x39c]
 *   @0x132864 mov r2, #1
 *   @0x132868 mov r3, #0
 *   @0x13286c add r0, pc, r0
 *   @0x132870 ldr r1, [r4, r1]
 *   @0x132874 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #159 object_get_parent → F_ObjectGetParent(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x132878 ldr r1, [pc, #-0x3b0]
 *   @0x13287c ldr r0, [pc, #-0x3b0]
 *   @0x132880 mov r2, #1
 *   @0x132884 mov r3, #0
 *   @0x132888 add r0, pc, r0
 *   @0x13288c ldr r1, [r4, r1]
 *   @0x132890 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #160 object_get_physics → F_ObjectGetPhysics(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x132894 ldr r1, [pc, #-0x3c4]
 *   @0x132898 ldr r0, [pc, #-0x3c4]
 *   @0x13289c mov r2, #2
 *   @0x1328a0 mov r3, #0
 *   @0x1328a4 add r0, pc, r0
 *   @0x1328a8 ldr r1, [r4, r1]
 *   @0x1328ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #161 object_is_ancestor → F_ObjectIsAncestor(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1328b0 ldr r1, [pc, #-0x3d8]
 *   @0x1328b4 ldr r0, [pc, #-0x3d8]
 *   @0x1328b8 mov r2, #2
 *   @0x1328bc mov r3, #1
 *   @0x1328c0 add r0, pc, r0
 *   @0x1328c4 ldr r1, [r4, r1]
 *   @0x1328c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #162 object_set_sprite → F_ObjectSetSprite(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1328cc ldr r1, [pc, #-0x3ec]
 *   @0x1328d0 ldr r0, [pc, #-0x3ec]
 *   @0x1328d4 mov r2, #2
 *   @0x1328d8 mov r3, #1
 *   @0x1328dc add r0, pc, r0
 *   @0x1328e0 ldr r1, [r4, r1]
 *   @0x1328e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #163 object_set_solid → F_ObjectSetSolid(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1328e8 ldr r1, [pc, #-0x400]
 *   @0x1328ec ldr r0, [pc, #-0x400]
 *   @0x1328f0 mov r2, #2
 *   @0x1328f4 mov r3, #1
 *   @0x1328f8 add r0, pc, r0
 *   @0x1328fc ldr r1, [r4, r1]
 *   @0x132900 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #164 object_set_visible → F_ObjectSetVisible(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x132904 ldr r1, [pc, #-0x414]
 *   @0x132908 ldr r0, [pc, #-0x414]
 *   @0x13290c mov r2, #2
 *   @0x132910 mov r3, #1
 *   @0x132914 add r0, pc, r0
 *   @0x132918 ldr r1, [r4, r1]
 *   @0x13291c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #165 object_set_persistent → F_ObjectSetPersistent(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x132920 ldr r1, [pc, #-0x428]
 *   @0x132924 ldr r0, [pc, #-0x428]
 *   @0x132928 mov r2, #2
 *   @0x13292c mov r3, #1
 *   @0x132930 add r0, pc, r0
 *   @0x132934 ldr r1, [r4, r1]
 *   @0x132938 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #166 object_set_mask → F_ObjectSetMask(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x13293c ldr r1, [pc, #-0x43c]
 *   @0x132940 ldr r0, [pc, #-0x43c]
 *   @0x132944 mov r2, #2
 *   @0x132948 mov r3, #1
 *   @0x13294c add r0, pc, r0
 *   @0x132950 ldr r1, [r4, r1]
 *   @0x132954 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #167 object_set_parent → F_ObjectSetParent(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x132958 ldr r1, [pc, #-0x450]
 *   @0x13295c ldr r0, [pc, #-0x450]
 *   @0x132960 mov r2, #2
 *   @0x132964 mov r3, #1
 *   @0x132968 add r0, pc, r0
 *   @0x13296c ldr r1, [r4, r1]
 *   @0x132970 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #168 object_set_collisions → F_ObjectSetCollisions(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x132974 ldr r1, [pc, #-0x464]
 *   @0x132978 ldr r0, [pc, #-0x464]
 *   @0x13297c mov r2, #0
 *   @0x132980 mov r3, #1
 *   @0x132984 add r0, pc, r0
 *   @0x132988 ldr r1, [r4, r1]
 *   @0x13298c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #169 object_add → F_ObjectAdd(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x132990 ldr r1, [pc, #-0x478]
 *   @0x132994 ldr r0, [pc, #-0x478]
 *   @0x132998 mov r2, #1
 *   @0x13299c mov r3, r2
 *   @0x1329a0 add r0, pc, r0
 *   @0x1329a4 ldr r1, [r4, r1]
 *   @0x1329a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #170 object_delete → F_ObjectDelete(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1329ac ldr r1, [pc, #-0x48c]
 *   @0x1329b0 ldr r0, [pc, #-0x48c]
 *   @0x1329b4 mov r2, #3
 *   @0x1329b8 mov r3, #1
 *   @0x1329bc add r0, pc, r0
 *   @0x1329c0 ldr r1, [r4, r1]
 *   @0x1329c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #171 object_event_clear → F_ObjectEventClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x1329c8 ldr r1, [pc, #-0x4a0]
 *   @0x1329cc ldr r0, [pc, #-0x4a0]
 *   @0x1329d0 mov r2, #4
 *   @0x1329d4 mov r3, #1
 *   @0x1329d8 add r0, pc, r0
 *   @0x1329dc ldr r1, [r4, r1]
 *   @0x1329e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #172 object_event_add → F_ObjectEventAdd(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x1329e4 ldr r1, [pc, #-0x4b4]
 *   @0x1329e8 ldr r0, [pc, #-0x4b4]
 *   @0x1329ec mov r2, #1
 *   @0x1329f0 mov r3, #0
 *   @0x1329f4 ldr r6, [r4, r1]
 *   @0x1329f8 add r0, pc, r0
 *   @0x1329fc mov r1, r6
 *   @0x132a00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #173 room_name → F_RoomGetName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x132a04 ldr r1, [pc, #-0x4cc]
 *   @0x132a08 ldr r0, [pc, #-0x4cc]
 *   @0x132a0c mov r2, #1
 *   @0x132a10 mov r3, #0
 *   @0x132a14 add r0, pc, r0
 *   @0x132a18 ldr r1, [r4, r1]
 *   @0x132a1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #174 room_exists → F_RoomExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x132a20 ldr r0, [pc, #-0x4e0]
 *   @0x132a24 mov r1, r6
 *   @0x132a28 mov r2, #1
 *   @0x132a2c add r0, pc, r0
 *   @0x132a30 mov r3, #0
 *   @0x132a34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #175 room_get_name → F_RoomGetName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x132a38 ldr r1, [pc, #-0x4f4]
 *   @0x132a3c ldr r0, [pc, #-0x4f4]
 *   @0x132a40 mov r2, #2
 *   @0x132a44 mov r3, #1
 *   @0x132a48 add r0, pc, r0
 *   @0x132a4c ldr r1, [r4, r1]
 *   @0x132a50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #176 room_set_width → F_RoomSetWidth(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x132a54 ldr r1, [pc, #-0x508]
 *   @0x132a58 ldr r0, [pc, #-0x508]
 *   @0x132a5c mov r2, #2
 *   @0x132a60 mov r3, #1
 *   @0x132a64 add r0, pc, r0
 *   @0x132a68 ldr r1, [r4, r1]
 *   @0x132a6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #177 room_set_height → F_RoomSetHeight(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x132a70 ldr r1, [pc, #-0x51c]
 *   @0x132a74 ldr r0, [pc, #-0x51c]
 *   @0x132a78 mov r2, #2
 *   @0x132a7c mov r3, #1
 *   @0x132a80 add r0, pc, r0
 *   @0x132a84 ldr r1, [r4, r1]
 *   @0x132a88 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #178 room_set_caption → F_RoomSetCaption(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x132a8c ldr r1, [pc, #-0x530]
 *   @0x132a90 ldr r0, [pc, #-0x530]
 *   @0x132a94 mov r2, #2
 *   @0x132a98 mov r3, #1
 *   @0x132a9c add r0, pc, r0
 *   @0x132aa0 ldr r1, [r4, r1]
 *   @0x132aa4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #179 room_set_persistent → F_RoomSetPersistent(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x132aa8 ldr r1, [pc, #-0x544]
 *   @0x132aac ldr r0, [pc, #-0x544]
 *   @0x132ab0 mov r2, #2
 *   @0x132ab4 mov r3, #1
 *   @0x132ab8 add r0, pc, r0
 *   @0x132abc ldr r1, [r4, r1]
 *   @0x132ac0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #180 room_set_code → F_RoomSetCode(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x132ac4 ldr r1, [pc, #-0x558]
 *   @0x132ac8 ldr r0, [pc, #-0x558]
 *   @0x132acc mov r2, #3
 *   @0x132ad0 mov r3, #1
 *   @0x132ad4 ldr r6, [r4, r1]
 *   @0x132ad8 add r0, pc, r0
 *   @0x132adc mov r1, r6
 *   @0x132ae0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #181 room_set_background_color → F_RoomSetBackgroundColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x132ae4 ldr r0, [pc, #-0x570]
 *   @0x132ae8 mov r1, r6
 *   @0x132aec mov r2, #3
 *   @0x132af0 add r0, pc, r0
 *   @0x132af4 mov r3, #1
 *   @0x132af8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #182 room_set_background_colour → F_RoomSetBackgroundColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x132afc ldr r1, [pc, #-0x584]
 *   @0x132b00 ldr r0, [pc, #-0x584]
 *   @0x132b04 mov r3, #1
 *   @0x132b08 mov r2, #12
 *   @0x132b0c add r0, pc, r0
 *   @0x132b10 ldr r1, [r4, r1]
 *   @0x132b14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #183 room_set_background → F_RoomSetBackground(RValue&, CInstance*, CInstance*, int, RValue*) argc=12 flag=1
 *   @0x132b18 ldrb r3, [r5]
 *   @0x132b1c cmp r3, #0
 *   @0x132b20 beq 0x132eb4 <_Z21InitResourceFunctionsv+0x1eb8>   —— 条件跳转 → 0x132eb4
 *   @0x132b24 ldr r1, [pc, #-0x5a4]
 *   @0x132b28 mov r2, #7
 *   @0x132b2c ldr r0, [pc, #-0x5a8]
 *   @0x132b30 mov r3, #1
 *   @0x132b34 add r0, pc, r0
 *   @0x132b38 ldr r1, [r4, r1]
 *   @0x132b3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #184 room_set_viewport → F_RoomSetViewport(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x132b40 ldr r1, [pc, #-0x5b8]
 *   @0x132b44 ldr r0, [pc, #-0x5b8]
 *   @0x132b48 mov r2, #2
 *   @0x132b4c mov r3, #1
 *   @0x132b50 add r0, pc, r0
 *   @0x132b54 ldr r1, [r4, r1]
 *   @0x132b58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #185 room_get_viewport → F_RoomGetViewport(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x132b5c ldr r1, [pc, #-0x5cc]
 *   @0x132b60 mov r2, #2
 *   @0x132b64 ldr r0, [pc, #-0x5d0]
 *   @0x132b68 mov r3, #1
 *   @0x132b6c add r0, pc, r0
 *   @0x132b70 ldr r1, [r4, r1]
 *   @0x132b74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #186 room_set_view_enabled → F_RoomSetViewEnabled(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x132b78 ldr r1, [pc, #-0x5e0]
 *   @0x132b7c ldr r0, [pc, #-0x5e0]
 *   @0x132b80 mov r2, #0
 *   @0x132b84 mov r3, #1
 *   @0x132b88 add r0, pc, r0
 *   @0x132b8c ldr r1, [r4, r1]
 *   @0x132b90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #187 room_add → F_RoomAdd(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x132b94 ldr r1, [pc, #-0x5f4]
 *   @0x132b98 ldr r0, [pc, #-0x5f4]
 *   @0x132b9c mov r2, #1
 *   @0x132ba0 mov r3, r2
 *   @0x132ba4 add r0, pc, r0
 *   @0x132ba8 ldr r1, [r4, r1]
 *   @0x132bac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #188 room_duplicate → F_RoomDuplicate(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x132bb0 ldr r1, [pc, #-0x608]
 *   @0x132bb4 ldr r0, [pc, #-0x608]
 *   @0x132bb8 mov r2, #2
 *   @0x132bbc mov r3, #1
 *   @0x132bc0 add r0, pc, r0
 *   @0x132bc4 ldr r1, [r4, r1]
 *   @0x132bc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #189 room_assign → F_RoomAssign(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x132bcc ldr r1, [pc, #-0x61c]
 *   @0x132bd0 ldr r0, [pc, #-0x61c]
 *   @0x132bd4 mov r2, #4
 *   @0x132bd8 mov r3, #1
 *   @0x132bdc add r0, pc, r0
 *   @0x132be0 ldr r1, [r4, r1]
 *   @0x132be4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #190 room_instance_add → F_RoomInstanceAdd(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x132be8 ldr r1, [pc, #-0x630]
 *   @0x132bec ldr r0, [pc, #-0x630]
 *   @0x132bf0 mov r2, #1
 *   @0x132bf4 mov r3, r2
 *   @0x132bf8 add r0, pc, r0
 *   @0x132bfc ldr r1, [r4, r1]
 *   @0x132c00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #191 room_instance_clear → F_RoomInstanceClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x132c04 ldr r1, [pc, #-0x644]
 *   @0x132c08 ldr r0, [pc, #-0x644]
 *   @0x132c0c mov r2, #9
 *   @0x132c10 mov r3, #1
 *   @0x132c14 add r0, pc, r0
 *   @0x132c18 ldr r1, [r4, r1]
 *   @0x132c1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #192 room_tile_add → F_RoomTileAdd(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x132c20 ldr r1, [pc, #-0x658]
 *   @0x132c24 ldr r0, [pc, #-0x658]
 *   @0x132c28 mov r2, #12
 *   @0x132c2c mov r3, #1
 *   @0x132c30 add r0, pc, r0
 *   @0x132c34 ldr r1, [r4, r1]
 *   @0x132c38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #193 room_tile_add_ext → F_RoomTileAddExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=12 flag=1
 *   @0x132c3c ldr r1, [pc, #-0x66c]
 *   @0x132c40 ldr r0, [pc, #-0x66c]
 *   @0x132c44 mov r2, #1
 *   @0x132c48 mov r3, r2
 *   @0x132c4c add r0, pc, r0
 *   @0x132c50 ldr r1, [r4, r1]
 *   @0x132c54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #194 room_tile_clear → F_RoomTileClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x132c58 ldrb r3, [r5]
 *   @0x132c5c cmp r3, #0
 *   @0x132c60 beq 0x132c9c <_Z21InitResourceFunctionsv+0x1ca0>   —— 条件跳转 → 0x132c9c
 *   @0x132c64 ldr r1, [pc, #-0x68c]
 *   @0x132c68 mov r2, #2
 *   @0x132c6c ldr r0, [pc, #-0x690]
 *   @0x132c70 mov r3, #1
 *   @0x132c74 add r0, pc, r0
 *   @0x132c78 ldr r1, [r4, r1]
 *   @0x132c7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #195 room_get_camera → F_RoomGetCamera(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x132c80 ldr r1, [pc, #-0x6a0]
 *   @0x132c84 ldr r0, [pc, #-0x6a0]
 *   @0x132c88 mov r2, #3
 *   @0x132c8c mov r3, #1
 *   @0x132c90 add r0, pc, r0
 *   @0x132c94 ldr r1, [r4, r1]
 *   @0x132c98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #196 room_set_camera → F_RoomSetCamera(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x132c9c ldr r1, [pc, #-0x6b4]
 *   @0x132ca0 mov r2, #1
 *   @0x132ca4 ldr r0, [pc, #-0x6b8]
 *   @0x132ca8 mov r3, r2
 *   @0x132cac ldr r1, [r4, r1]
 *   @0x132cb0 add r0, pc, r0
 *   @0x132cb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #197 asset_get_index → F_ResourceGetIndex(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x132cb8 ldr r1, [pc, #-0x6c8]
 *   @0x132cbc ldr r0, [pc, #-0x6c8]
 *   @0x132cc0 mov r2, #1
 *   @0x132cc4 mov r3, r2
 *   @0x132cc8 ldr r1, [r4, r1]
 *   @0x132ccc add r0, pc, r0
 *   @0x132cd0 pop {r4, r5, r6, r7, r8, lr}
 *   @0x132cd4 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #198 asset_get_type → F_ResourceGetType(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x132cd8 ldr r0, [pc, #-0x6e0]
 *   @0x132cdc mov r2, #8
 *   @0x132ce0 ldr r1, [r4, r1]
 *   @0x132ce4 mov r3, #1
 *   @0x132ce8 add r0, pc, r0
 *   @0x132cec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #199 sprite_add → F_SpriteAdd(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x132cf0 ldr r1, [pc, #-0x6f4]
 *   @0x132cf4 ldr r0, [pc, #-0x6f4]
 *   @0x132cf8 mov r2, #10
 *   @0x132cfc mov r3, #1
 *   @0x132d00 ldr r1, [r4, r1]
 *   @0x132d04 add r0, pc, r0
 *   @0x132d08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #200 sprite_create_from_screen → F_SpriteCreateFromScreen(RValue&, CInstance*, CInstance*, int, RValue*) argc=10 flag=1
 *   @0x132d0c ldr r1, [pc, #-0x708]
 *   @0x132d10 ldr r0, [pc, #-0x708]
 *   @0x132d14 mov r2, #5
 *   @0x132d18 mov r3, #1
 *   @0x132d1c ldr r1, [r4, r1]
 *   @0x132d20 add r0, pc, r0
 *   @0x132d24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #201 sprite_add_from_screen → F_SpriteAddFromScreen(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x132d28 ldr r1, [pc, #-0x71c]
 *   @0x132d2c ldr r0, [pc, #-0x71c]
 *   @0x132d30 mov r2, #11
 *   @0x132d34 mov r3, #1
 *   @0x132d38 ldr r1, [r4, r1]
 *   @0x132d3c add r0, pc, r0
 *   @0x132d40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #202 sprite_create_from_surface → F_SpriteCreateFromSurface(RValue&, CInstance*, CInstance*, int, RValue*) argc=11 flag=1
 *   @0x132d44 ldr r1, [pc, #-0x730]
 *   @0x132d48 ldr r0, [pc, #-0x730]
 *   @0x132d4c mov r2, #6
 *   @0x132d50 mov r3, #1
 *   @0x132d54 ldr r1, [r4, r1]
 *   @0x132d58 add r0, pc, r0
 *   @0x132d5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #203 sprite_add_from_surface → F_SpriteAddFromSurface(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x132d60 ldr r1, [pc, #-0x744]
 *   @0x132d64 ldr r0, [pc, #-0x744]
 *   @0x132d68 mov r2, #9
 *   @0x132d6c mov r3, #1
 *   @0x132d70 ldr r1, [r4, r1]
 *   @0x132d74 add r0, pc, r0
 *   @0x132d78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #204 sprite_replace → F_SpriteReplace(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x132d7c ldr r1, [pc, #-0x758]
 *   @0x132d80 ldr r0, [pc, #-0x758]
 *   @0x132d84 mov r2, #6
 *   @0x132d88 mov r3, #1
 *   @0x132d8c ldr r1, [r4, r1]
 *   @0x132d90 add r0, pc, r0
 *   @0x132d94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #205 sprite_add_alpha → F_SpriteAddAlpha(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x132d98 ldr r1, [pc, #-0x76c]
 *   @0x132d9c ldr r0, [pc, #-0x76c]
 *   @0x132da0 mov r2, #7
 *   @0x132da4 mov r3, #1
 *   @0x132da8 add r0, pc, r0
 *   @0x132dac ldr r1, [r4, r1]
 *   @0x132db0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #206 sprite_replace_alpha → F_SpriteReplaceAlpha(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x132db4 b 0x13140c <_Z21InitResourceFunctionsv+0x410>
 *   @0x132db8 ldr r6, [r4, r1]
 *   @0x132dbc mov r2, #4
 *   @0x132dc0 ldr r0, [pc, #-0x78c]
 *   @0x132dc4 mov r3, #1
 *   @0x132dc8 mov r1, r6
 *   @0x132dcc add r0, pc, r0
 *   @0x132dd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #207 background_create_color → F_BackgroundCreateColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x132dd4 ldr r0, [pc, #-0x79c]
 *   @0x132dd8 mov r1, r6
 *   @0x132ddc mov r2, #4
 *   @0x132de0 add r0, pc, r0
 *   @0x132de4 mov r3, #1
 *   @0x132de8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #208 background_create_colour → F_BackgroundCreateColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x132dec ldr r1, [pc, #-0x7b0]
 *   @0x132df0 ldr r0, [pc, #-0x7b0]
 *   @0x132df4 mov r2, #5
 *   @0x132df8 mov r3, #1
 *   @0x132dfc ldr r1, [r4, r1]
 *   @0x132e00 add r0, pc, r0
 *   @0x132e04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #209 background_replace → F_BackgroundReplace(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x132e08 ldr r1, [pc, #-0x7c4]
 *   @0x132e0c ldr r0, [pc, #-0x7c4]
 *   @0x132e10 mov r2, #7
 *   @0x132e14 mov r3, #1
 *   @0x132e18 ldr r1, [r4, r1]
 *   @0x132e1c add r0, pc, r0
 *   @0x132e20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #210 background_create_from_screen → F_BackgroundCreateFromScreen(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x132e24 ldr r1, [pc, #-0x7d8]
 *   @0x132e28 ldr r0, [pc, #-0x7d8]
 *   @0x132e2c mov r2, #8
 *   @0x132e30 mov r3, #1
 *   @0x132e34 ldr r1, [r4, r1]
 *   @0x132e38 add r0, pc, r0
 *   @0x132e3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #211 background_create_from_surface → F_BackgroundCreateFromSurface(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x132e40 ldr r1, [pc, #-0x7ec]
 *   @0x132e44 ldr r0, [pc, #-0x7ec]
 *   @0x132e48 mov r2, #6
 *   @0x132e4c mov r3, #1
 *   @0x132e50 ldr r1, [r4, r1]
 *   @0x132e54 add r0, pc, r0
 *   @0x132e58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #212 background_create_gradient → F_BackgroundCreateGradient(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x132e5c ldr r1, [pc, #-0x800]
 *   @0x132e60 ldr r0, [pc, #-0x800]
 *   @0x132e64 mov r2, #4
 *   @0x132e68 mov r3, #1
 *   @0x132e6c ldr r1, [r4, r1]
 *   @0x132e70 add r0, pc, r0
 *   @0x132e74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #213 background_add → F_BackgroundAdd(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x132e78 ldr r1, [pc, #-0x814]
 *   @0x132e7c ldr r0, [pc, #-0x814]
 *   @0x132e80 mov r2, #2
 *   @0x132e84 mov r3, #1
 *   @0x132e88 ldr r1, [r4, r1]
 *   @0x132e8c add r0, pc, r0
 *   @0x132e90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #214 background_add_alpha → F_BackgroundAddAlpha(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x132e94 ldr r1, [pc, #-0x828]
 *   @0x132e98 ldr r0, [pc, #-0x828]
 *   @0x132e9c mov r2, #3
 *   @0x132ea0 mov r3, #1
 *   @0x132ea4 add r0, pc, r0
 *   @0x132ea8 ldr r1, [r4, r1]
 *   @0x132eac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #215 background_replace_alpha → F_BackgroundReplaceAlpha(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x132eb0 b 0x131720 <_Z21InitResourceFunctionsv+0x724>
 *   @0x132eb4 ldr r1, [pc, #-0x840]
 *   @0x132eb8 mov r3, #1
 *   @0x132ebc ldr r0, [pc, #-0x844]
 *   @0x132ec0 mov r2, #16
 *   @0x132ec4 add r0, pc, r0
 *   @0x132ec8 ldr r1, [r4, r1]
 *   @0x132ecc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #216 room_set_view → F_RoomSetView(RValue&, CInstance*, CInstance*, int, RValue*) argc=16 flag=1
 *   @0x132ed0 ldrb r3, [r5]
 *   @0x132ed4 cmp r3, #0
 *   @0x132ed8 beq 0x132b5c <_Z21InitResourceFunctionsv+0x1b60>   —— 条件跳转 → 0x132b5c
 *   @0x132edc b 0x132b24 <_Z21InitResourceFunctionsv+0x1b28>
 *   @0x132ee0 ldr r1, [pc, #-0x864]
 *   @0x132ee4 mov r2, #1
 *   @0x132ee8 ldr r0, [pc, #-0x868]
 *   @0x132eec ldr r1, [r4, r1]
 *   @0x132ef0 add r0, pc, r0
 *   @0x132ef4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #217 object_get_depth → F_ObjectGetDepth(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=None ⚠ ?
 *   @0x132ef8 ldr r1, [pc, #-0x874]
 *   @0x132efc ldr r0, [pc, #-0x874]
 *   @0x132f00 mov r2, #2
 *   @0x132f04 mov r3, #1
 *   @0x132f08 add r0, pc, r0
 *   @0x132f0c ldr r1, [r4, r1]
 *   @0x132f10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #218 object_set_depth → F_ObjectSetDepth(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x132f14 b 0x132824 <_Z21InitResourceFunctionsv+0x1828>
 *   @0x132f18 ldr r1, [pc, #-0x88c]
 *   @0x132f1c mov r2, #3
 *   @0x132f20 ldr r0, [pc, #-0x890]
 *   @0x132f24 mov r3, #1
 *   @0x132f28 ldr r1, [r4, r1]
 *   @0x132f2c add r0, pc, r0
 *   @0x132f30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #219 sprite_set_speed → F_SpriteSetSpeed(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x132f34 ldr r1, [pc, #-0x8a0]
 *   @0x132f38 ldr r0, [pc, #-0x8a0]
 *   @0x132f3c mov r2, #1
 *   @0x132f40 mov r3, r2
 *   @0x132f44 ldr r1, [r4, r1]
 *   @0x132f48 add r0, pc, r0
 *   @0x132f4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #220 sprite_get_speed_type → F_SpriteGetSpeedType(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x132f50 ldr r1, [pc, #-0x8b4]
 *   @0x132f54 ldr r0, [pc, #-0x8b4]
 *   @0x132f58 mov r2, #1
 *   @0x132f5c mov r3, r2
 *   @0x132f60 add r0, pc, r0
 *   @0x132f64 ldr r1, [r4, r1]
 *   @0x132f68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #221 sprite_get_speed → F_SpriteGetSpeed(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x132f6c b 0x13151c <_Z21InitResourceFunctionsv+0x520>
 *
 * ══ §2/3 InitParticlesFunctions  0x129f74..0x12a870  size 2300  575 条（455 条指令 + 120 个池字）══
 * @func 0x129f74 0x12a870  size 2300  575 条
 * 注册 64 条｜唯一名 64｜唯一函数指针 54｜argc 0:3 1:13 2:14 3:11 4:8 5:7 6:3 7:4 8:1｜flag 1:64
 * 首条 #0 part_type_create（0x129f98）→ 末条 #63 effect_clear（0x12a68c）
 * 名字族（前 8）: part×61 effect×3
 * 游戏实际调用的 99 个内建里落在本表: 12 个（part_particles_create, part_system_create, part_type_alpha1, part_type_color2, part_type_create, part_type_direction, part_type_gravity, part_type_life, part_type_orientation, part_type_shape, part_type_size, part_type_speed）
 * 条件跳转 1 处: 0x12a474(beq)
 * 表: asm/init-tables/init-InitParticlesFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: 无（本函数每条注册的四实参全部解出，控制流全部走到）
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x129f74 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x129f78 mov r2, #0
 *   @0x129f7c ldr r4, [pc, #0x70c]
 *   @0x129f80 mov r3, #1
 *   @0x129f84 ldr r1, [pc, #0x708]
 *   @0x129f88 add r4, pc, r4
 *   @0x129f8c ldr r0, [pc, #0x704]
 *   @0x129f90 add r0, pc, r0
 *   @0x129f94 ldr r1, [r4, r1]
 *   @0x129f98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 part_type_create → F_PartTypeCreate(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x129f9c ldr r1, [pc, #0x6f8]
 *   @0x129fa0 ldr r0, [pc, #0x6f8]
 *   @0x129fa4 mov r2, #1
 *   @0x129fa8 mov r3, r2
 *   @0x129fac add r0, pc, r0
 *   @0x129fb0 ldr r1, [r4, r1]
 *   @0x129fb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 part_type_destroy → F_PartTypeDestroy(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x129fb8 ldr r1, [pc, #0x6e4]
 *   @0x129fbc ldr r0, [pc, #0x6e4]
 *   @0x129fc0 mov r2, #1
 *   @0x129fc4 mov r3, r2
 *   @0x129fc8 add r0, pc, r0
 *   @0x129fcc ldr r1, [r4, r1]
 *   @0x129fd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 part_type_exists → F_PartTypeExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x129fd4 ldr r1, [pc, #0x6d0]
 *   @0x129fd8 ldr r0, [pc, #0x6d0]
 *   @0x129fdc mov r2, #1
 *   @0x129fe0 mov r3, r2
 *   @0x129fe4 add r0, pc, r0
 *   @0x129fe8 ldr r1, [r4, r1]
 *   @0x129fec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 part_type_clear → F_PartTypeClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x129ff0 ldr r1, [pc, #0x6bc]
 *   @0x129ff4 ldr r0, [pc, #0x6bc]
 *   @0x129ff8 mov r2, #2
 *   @0x129ffc mov r3, #1
 *   @0x12a000 add r0, pc, r0
 *   @0x12a004 ldr r1, [r4, r1]
 *   @0x12a008 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #4 part_type_shape → F_PartTypeShape(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x12a00c ldr r1, [pc, #0x6a8]
 *   @0x12a010 ldr r0, [pc, #0x6a8]
 *   @0x12a014 mov r2, #5
 *   @0x12a018 mov r3, #1
 *   @0x12a01c add r0, pc, r0
 *   @0x12a020 ldr r1, [r4, r1]
 *   @0x12a024 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #5 part_type_sprite → F_PartTypeSprite(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x12a028 ldr r1, [pc, #0x694]
 *   @0x12a02c ldr r0, [pc, #0x694]
 *   @0x12a030 mov r2, #5
 *   @0x12a034 mov r3, #1
 *   @0x12a038 add r0, pc, r0
 *   @0x12a03c ldr r1, [r4, r1]
 *   @0x12a040 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #6 part_type_size → F_PartTypeSize(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x12a044 ldr r1, [pc, #0x680]
 *   @0x12a048 ldr r0, [pc, #0x680]
 *   @0x12a04c mov r2, #3
 *   @0x12a050 mov r3, #1
 *   @0x12a054 add r0, pc, r0
 *   @0x12a058 ldr r1, [r4, r1]
 *   @0x12a05c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #7 part_type_scale → F_PartTypeScale(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x12a060 ldr r1, [pc, #0x66c]
 *   @0x12a064 ldr r0, [pc, #0x66c]
 *   @0x12a068 mov r2, #3
 *   @0x12a06c mov r3, #1
 *   @0x12a070 add r0, pc, r0
 *   @0x12a074 ldr r1, [r4, r1]
 *   @0x12a078 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #8 part_type_life → F_PartTypeLife(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x12a07c ldr r1, [pc, #0x658]
 *   @0x12a080 ldr r0, [pc, #0x658]
 *   @0x12a084 mov r2, #3
 *   @0x12a088 mov r3, #1
 *   @0x12a08c add r0, pc, r0
 *   @0x12a090 ldr r1, [r4, r1]
 *   @0x12a094 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #9 part_type_step → F_PartTypeStep(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x12a098 ldr r1, [pc, #0x644]
 *   @0x12a09c ldr r0, [pc, #0x644]
 *   @0x12a0a0 mov r2, #3
 *   @0x12a0a4 mov r3, #1
 *   @0x12a0a8 add r0, pc, r0
 *   @0x12a0ac ldr r1, [r4, r1]
 *   @0x12a0b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #10 part_type_death → F_PartTypeDeath(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x12a0b4 ldr r1, [pc, #0x630]
 *   @0x12a0b8 ldr r0, [pc, #0x630]
 *   @0x12a0bc mov r2, #5
 *   @0x12a0c0 mov r3, #1
 *   @0x12a0c4 add r0, pc, r0
 *   @0x12a0c8 ldr r1, [r4, r1]
 *   @0x12a0cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #11 part_type_speed → F_PartTypeSpeed(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x12a0d0 ldr r1, [pc, #0x61c]
 *   @0x12a0d4 ldr r0, [pc, #0x61c]
 *   @0x12a0d8 mov r2, #5
 *   @0x12a0dc mov r3, #1
 *   @0x12a0e0 add r0, pc, r0
 *   @0x12a0e4 ldr r1, [r4, r1]
 *   @0x12a0e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #12 part_type_direction → F_PartTypeDirection(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x12a0ec ldr r1, [pc, #0x608]
 *   @0x12a0f0 ldr r0, [pc, #0x608]
 *   @0x12a0f4 mov r2, #6
 *   @0x12a0f8 mov r3, #1
 *   @0x12a0fc add r0, pc, r0
 *   @0x12a100 ldr r1, [r4, r1]
 *   @0x12a104 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #13 part_type_orientation → F_PartTypeOrientation(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x12a108 ldr r1, [pc, #0x5f4]
 *   @0x12a10c ldr r0, [pc, #0x5f4]
 *   @0x12a110 mov r2, #3
 *   @0x12a114 mov r3, #1
 *   @0x12a118 add r0, pc, r0
 *   @0x12a11c ldr r1, [r4, r1]
 *   @0x12a120 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #14 part_type_gravity → F_PartTypeGravity(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x12a124 ldr r1, [pc, #0x5e0]
 *   @0x12a128 ldr r0, [pc, #0x5e0]
 *   @0x12a12c mov r2, #3
 *   @0x12a130 mov r3, #1
 *   @0x12a134 ldr r10, [r4, r1]
 *   @0x12a138 add r0, pc, r0
 *   @0x12a13c mov r1, r10
 *   @0x12a140 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #15 part_type_color_mix → F_PartTypeColorMix(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x12a144 ldr r1, [pc, #0x5c8]
 *   @0x12a148 ldr r0, [pc, #0x5c8]
 *   @0x12a14c mov r2, #7
 *   @0x12a150 mov r3, #1
 *   @0x12a154 ldr r9, [r4, r1]
 *   @0x12a158 add r0, pc, r0
 *   @0x12a15c mov r1, r9
 *   @0x12a160 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #16 part_type_color_rgb → F_PartTypeColorRGB(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x12a164 ldr r1, [pc, #0x5b0]
 *   @0x12a168 ldr r0, [pc, #0x5b0]
 *   @0x12a16c mov r2, #7
 *   @0x12a170 mov r3, #1
 *   @0x12a174 ldr r8, [r4, r1]
 *   @0x12a178 add r0, pc, r0
 *   @0x12a17c mov r1, r8
 *   @0x12a180 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #17 part_type_color_hsv → F_PartTypeColorHSV(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x12a184 ldr r1, [pc, #0x598]
 *   @0x12a188 ldr r0, [pc, #0x598]
 *   @0x12a18c mov r2, #2
 *   @0x12a190 mov r3, #1
 *   @0x12a194 ldr r7, [r4, r1]
 *   @0x12a198 add r0, pc, r0
 *   @0x12a19c mov r1, r7
 *   @0x12a1a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #18 part_type_color1 → F_PartTypeColor1(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x12a1a4 ldr r1, [pc, #0x580]
 *   @0x12a1a8 ldr r0, [pc, #0x580]
 *   @0x12a1ac mov r2, #3
 *   @0x12a1b0 mov r3, #1
 *   @0x12a1b4 ldr r6, [r4, r1]
 *   @0x12a1b8 add r0, pc, r0
 *   @0x12a1bc mov r1, r6
 *   @0x12a1c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #19 part_type_color2 → F_PartTypeColor2(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x12a1c4 ldr r1, [pc, #0x568]
 *   @0x12a1c8 ldr r0, [pc, #0x568]
 *   @0x12a1cc mov r2, #4
 *   @0x12a1d0 mov r3, #1
 *   @0x12a1d4 ldr r5, [r4, r1]
 *   @0x12a1d8 add r0, pc, r0
 *   @0x12a1dc mov r1, r5
 *   @0x12a1e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #20 part_type_color3 → F_PartTypeColor3(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x12a1e4 ldr r0, [pc, #0x550]
 *   @0x12a1e8 mov r1, r5
 *   @0x12a1ec mov r2, #4
 *   @0x12a1f0 add r0, pc, r0
 *   @0x12a1f4 mov r3, #1
 *   @0x12a1f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #21 part_type_color → F_PartTypeColor3(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x12a1fc ldr r0, [pc, #0x53c]
 *   @0x12a200 mov r1, r10
 *   @0x12a204 mov r2, #3
 *   @0x12a208 add r0, pc, r0
 *   @0x12a20c mov r3, #1
 *   @0x12a210 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #22 part_type_colour_mix → F_PartTypeColorMix(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x12a214 ldr r0, [pc, #0x528]
 *   @0x12a218 mov r1, r9
 *   @0x12a21c mov r2, #7
 *   @0x12a220 add r0, pc, r0
 *   @0x12a224 mov r3, #1
 *   @0x12a228 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #23 part_type_colour_rgb → F_PartTypeColorRGB(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x12a22c ldr r0, [pc, #0x514]
 *   @0x12a230 mov r1, r8
 *   @0x12a234 mov r2, #7
 *   @0x12a238 add r0, pc, r0
 *   @0x12a23c mov r3, #1
 *   @0x12a240 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #24 part_type_colour_hsv → F_PartTypeColorHSV(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x12a244 ldr r0, [pc, #0x500]
 *   @0x12a248 mov r1, r7
 *   @0x12a24c mov r2, #2
 *   @0x12a250 add r0, pc, r0
 *   @0x12a254 mov r3, #1
 *   @0x12a258 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #25 part_type_colour1 → F_PartTypeColor1(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x12a25c ldr r0, [pc, #0x4ec]
 *   @0x12a260 mov r1, r6
 *   @0x12a264 mov r2, #3
 *   @0x12a268 add r0, pc, r0
 *   @0x12a26c mov r3, #1
 *   @0x12a270 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #26 part_type_colour2 → F_PartTypeColor2(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x12a274 ldr r0, [pc, #0x4d8]
 *   @0x12a278 mov r1, r5
 *   @0x12a27c mov r2, #4
 *   @0x12a280 add r0, pc, r0
 *   @0x12a284 mov r3, #1
 *   @0x12a288 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #27 part_type_colour3 → F_PartTypeColor3(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x12a28c ldr r0, [pc, #0x4c4]
 *   @0x12a290 mov r1, r5
 *   @0x12a294 mov r2, #4
 *   @0x12a298 add r0, pc, r0
 *   @0x12a29c mov r3, #1
 *   @0x12a2a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #28 part_type_colour → F_PartTypeColor3(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x12a2a4 ldr r1, [pc, #0x4b0]
 *   @0x12a2a8 ldr r0, [pc, #0x4b0]
 *   @0x12a2ac mov r2, #2
 *   @0x12a2b0 mov r3, #1
 *   @0x12a2b4 add r0, pc, r0
 *   @0x12a2b8 ldr r1, [r4, r1]
 *   @0x12a2bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #29 part_type_alpha1 → F_PartTypeAlpha1(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x12a2c0 ldr r1, [pc, #0x49c]
 *   @0x12a2c4 ldr r0, [pc, #0x49c]
 *   @0x12a2c8 mov r2, #3
 *   @0x12a2cc mov r3, #1
 *   @0x12a2d0 add r0, pc, r0
 *   @0x12a2d4 ldr r1, [r4, r1]
 *   @0x12a2d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #30 part_type_alpha2 → F_PartTypeAlpha2(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x12a2dc ldr r1, [pc, #0x488]
 *   @0x12a2e0 ldr r0, [pc, #0x488]
 *   @0x12a2e4 mov r2, #4
 *   @0x12a2e8 mov r3, #1
 *   @0x12a2ec ldr r5, [r4, r1]
 *   @0x12a2f0 add r0, pc, r0
 *   @0x12a2f4 mov r1, r5
 *   @0x12a2f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #31 part_type_alpha3 → F_PartTypeAlpha3(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x12a2fc ldr r0, [pc, #0x470]
 *   @0x12a300 mov r1, r5
 *   @0x12a304 mov r2, #4
 *   @0x12a308 add r0, pc, r0
 *   @0x12a30c mov r3, #1
 *   @0x12a310 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #32 part_type_alpha → F_PartTypeAlpha3(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x12a314 ldr r1, [pc, #0x45c]
 *   @0x12a318 ldr r0, [pc, #0x45c]
 *   @0x12a31c mov r2, #2
 *   @0x12a320 mov r3, #1
 *   @0x12a324 add r0, pc, r0
 *   @0x12a328 ldr r1, [r4, r1]
 *   @0x12a32c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #33 part_type_blend → F_PartTypeBlend(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x12a330 ldr r1, [pc, #0x448]
 *   @0x12a334 ldr r0, [pc, #0x448]
 *   @0x12a338 mov r2, #0
 *   @0x12a33c mov r3, #1
 *   @0x12a340 add r0, pc, r0
 *   @0x12a344 ldr r1, [r4, r1]
 *   @0x12a348 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #34 part_system_create → F_PartSystemCreate(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x12a34c ldr r1, [pc, #0x434]
 *   @0x12a350 ldr r0, [pc, #0x434]
 *   @0x12a354 mov r2, #1
 *   @0x12a358 mov r3, r2
 *   @0x12a35c add r0, pc, r0
 *   @0x12a360 ldr r1, [r4, r1]
 *   @0x12a364 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #35 part_system_destroy → F_PartSystemDestroy(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x12a368 ldr r1, [pc, #0x420]
 *   @0x12a36c ldr r0, [pc, #0x420]
 *   @0x12a370 mov r2, #1
 *   @0x12a374 mov r3, r2
 *   @0x12a378 add r0, pc, r0
 *   @0x12a37c ldr r1, [r4, r1]
 *   @0x12a380 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #36 part_system_exists → F_PartSystemExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x12a384 ldr r1, [pc, #0x40c]
 *   @0x12a388 ldr r0, [pc, #0x40c]
 *   @0x12a38c mov r2, #1
 *   @0x12a390 mov r3, r2
 *   @0x12a394 add r0, pc, r0
 *   @0x12a398 ldr r1, [r4, r1]
 *   @0x12a39c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #37 part_system_clear → F_PartSystemClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x12a3a0 ldr r1, [pc, #0x3f8]
 *   @0x12a3a4 ldr r0, [pc, #0x3f8]
 *   @0x12a3a8 mov r2, #2
 *   @0x12a3ac mov r3, #1
 *   @0x12a3b0 add r0, pc, r0
 *   @0x12a3b4 ldr r1, [r4, r1]
 *   @0x12a3b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #38 part_system_draw_order → F_PartSystemDrawOrder(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x12a3bc ldr r1, [pc, #0x3e4]
 *   @0x12a3c0 ldr r0, [pc, #0x3e4]
 *   @0x12a3c4 mov r2, #2
 *   @0x12a3c8 mov r3, #1
 *   @0x12a3cc add r0, pc, r0
 *   @0x12a3d0 ldr r1, [r4, r1]
 *   @0x12a3d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #39 part_system_depth → F_PartSystemDepth(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x12a3d8 ldr r1, [pc, #0x3d0]
 *   @0x12a3dc ldr r0, [pc, #0x3d0]
 *   @0x12a3e0 mov r2, #3
 *   @0x12a3e4 mov r3, #1
 *   @0x12a3e8 add r0, pc, r0
 *   @0x12a3ec ldr r1, [r4, r1]
 *   @0x12a3f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #40 part_system_position → F_PartSystemPosition(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x12a3f4 ldr r1, [pc, #0x3bc]
 *   @0x12a3f8 ldr r0, [pc, #0x3bc]
 *   @0x12a3fc mov r2, #2
 *   @0x12a400 mov r3, #1
 *   @0x12a404 add r0, pc, r0
 *   @0x12a408 ldr r1, [r4, r1]
 *   @0x12a40c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #41 part_system_automatic_update → F_PartSystemAutomaticUpdate(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x12a410 ldr r1, [pc, #0x3a8]
 *   @0x12a414 ldr r0, [pc, #0x3a8]
 *   @0x12a418 mov r2, #2
 *   @0x12a41c mov r3, #1
 *   @0x12a420 add r0, pc, r0
 *   @0x12a424 ldr r1, [r4, r1]
 *   @0x12a428 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #42 part_system_automatic_draw → F_PartSystemAutomaticDraw(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x12a42c ldr r1, [pc, #0x394]
 *   @0x12a430 ldr r0, [pc, #0x394]
 *   @0x12a434 mov r2, #1
 *   @0x12a438 mov r3, r2
 *   @0x12a43c add r0, pc, r0
 *   @0x12a440 ldr r1, [r4, r1]
 *   @0x12a444 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #43 part_system_update → F_PartSystemUpdate(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x12a448 ldr r1, [pc, #0x380]
 *   @0x12a44c ldr r0, [pc, #0x380]
 *   @0x12a450 mov r2, #1
 *   @0x12a454 mov r3, r2
 *   @0x12a458 add r0, pc, r0
 *   @0x12a45c ldr r1, [r4, r1]
 *   @0x12a460 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #44 part_system_drawit → F_PartSystemDrawIt(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x12a464 ldr r3, [pc, #0x36c]
 *   @0x12a468 ldr r3, [r4, r3]
 *   @0x12a46c ldrb r3, [r3]
 *   @0x12a470 cmp r3, #0
 *   @0x12a474 beq 0x12a4cc <_Z22InitParticlesFunctionsv+0x558>   —— 条件跳转 → 0x12a4cc
 *   @0x12a478 ldr r1, [pc, #0x35c]
 *   @0x12a47c mov r2, #2
 *   @0x12a480 ldr r0, [pc, #0x358]
 *   @0x12a484 mov r3, #1
 *   @0x12a488 add r0, pc, r0
 *   @0x12a48c ldr r1, [r4, r1]
 *   @0x12a490 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #45 part_system_create_layer → F_PartSystemCreateLayer(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x12a494 ldr r1, [pc, #0x348]
 *   @0x12a498 ldr r0, [pc, #0x348]
 *   @0x12a49c mov r2, #1
 *   @0x12a4a0 mov r3, r2
 *   @0x12a4a4 add r0, pc, r0
 *   @0x12a4a8 ldr r1, [r4, r1]
 *   @0x12a4ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #46 part_system_get_layer → F_PartSystemGetLayer(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x12a4b0 ldr r1, [pc, #0x334]
 *   @0x12a4b4 ldr r0, [pc, #0x334]
 *   @0x12a4b8 mov r2, #2
 *   @0x12a4bc mov r3, #1
 *   @0x12a4c0 add r0, pc, r0
 *   @0x12a4c4 ldr r1, [r4, r1]
 *   @0x12a4c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #47 part_system_layer → F_PartSystemLayer(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x12a4cc ldr r1, [pc, #0x320]
 *   @0x12a4d0 mov r2, #5
 *   @0x12a4d4 ldr r0, [pc, #0x31c]
 *   @0x12a4d8 mov r3, #1
 *   @0x12a4dc ldr r1, [r4, r1]
 *   @0x12a4e0 add r0, pc, r0
 *   @0x12a4e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #48 part_particles_create → F_PartParticlesCreate(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x12a4e8 ldr r1, [pc, #0x30c]
 *   @0x12a4ec ldr r0, [pc, #0x30c]
 *   @0x12a4f0 mov r2, #6
 *   @0x12a4f4 mov r3, #1
 *   @0x12a4f8 ldr r5, [r4, r1]
 *   @0x12a4fc add r0, pc, r0
 *   @0x12a500 mov r1, r5
 *   @0x12a504 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #49 part_particles_create_color → F_PartParticlesCreateColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x12a508 ldr r0, [pc, #0x2f4]
 *   @0x12a50c mov r1, r5
 *   @0x12a510 mov r2, #6
 *   @0x12a514 add r0, pc, r0
 *   @0x12a518 mov r3, #1
 *   @0x12a51c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #50 part_particles_create_colour → F_PartParticlesCreateColor(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x12a520 ldr r1, [pc, #0x2e0]
 *   @0x12a524 ldr r0, [pc, #0x2e0]
 *   @0x12a528 mov r2, #1
 *   @0x12a52c mov r3, r2
 *   @0x12a530 ldr r1, [r4, r1]
 *   @0x12a534 add r0, pc, r0
 *   @0x12a538 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #51 part_particles_clear → F_PartParticlesClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x12a53c ldr r1, [pc, #0x2cc]
 *   @0x12a540 ldr r0, [pc, #0x2cc]
 *   @0x12a544 mov r2, #1
 *   @0x12a548 mov r3, r2
 *   @0x12a54c ldr r1, [r4, r1]
 *   @0x12a550 add r0, pc, r0
 *   @0x12a554 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #52 part_particles_count → F_PartParticlesCount(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x12a558 ldr r1, [pc, #0x2b8]
 *   @0x12a55c ldr r0, [pc, #0x2b8]
 *   @0x12a560 mov r2, #1
 *   @0x12a564 mov r3, r2
 *   @0x12a568 ldr r1, [r4, r1]
 *   @0x12a56c add r0, pc, r0
 *   @0x12a570 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #53 part_emitter_create → F_PartEmitterCreate(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x12a574 ldr r1, [pc, #0x2a4]
 *   @0x12a578 ldr r0, [pc, #0x2a4]
 *   @0x12a57c mov r2, #2
 *   @0x12a580 mov r3, #1
 *   @0x12a584 ldr r1, [r4, r1]
 *   @0x12a588 add r0, pc, r0
 *   @0x12a58c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #54 part_emitter_destroy → F_PartEmitterDestroy(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x12a590 ldr r1, [pc, #0x290]
 *   @0x12a594 ldr r0, [pc, #0x290]
 *   @0x12a598 mov r2, #1
 *   @0x12a59c mov r3, r2
 *   @0x12a5a0 ldr r1, [r4, r1]
 *   @0x12a5a4 add r0, pc, r0
 *   @0x12a5a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #55 part_emitter_destroy_all → F_PartEmitterDestroyAll(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x12a5ac ldr r1, [pc, #0x27c]
 *   @0x12a5b0 ldr r0, [pc, #0x27c]
 *   @0x12a5b4 mov r2, #2
 *   @0x12a5b8 mov r3, #1
 *   @0x12a5bc ldr r1, [r4, r1]
 *   @0x12a5c0 add r0, pc, r0
 *   @0x12a5c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #56 part_emitter_exists → F_PartEmitterExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x12a5c8 ldr r1, [pc, #0x268]
 *   @0x12a5cc ldr r0, [pc, #0x268]
 *   @0x12a5d0 mov r2, #2
 *   @0x12a5d4 mov r3, #1
 *   @0x12a5d8 ldr r1, [r4, r1]
 *   @0x12a5dc add r0, pc, r0
 *   @0x12a5e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #57 part_emitter_clear → F_PartEmitterClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x12a5e4 ldr r1, [pc, #0x254]
 *   @0x12a5e8 ldr r0, [pc, #0x254]
 *   @0x12a5ec mov r2, #8
 *   @0x12a5f0 mov r3, #1
 *   @0x12a5f4 ldr r1, [r4, r1]
 *   @0x12a5f8 add r0, pc, r0
 *   @0x12a5fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #58 part_emitter_region → F_PartEmitterRegion(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x12a600 ldr r1, [pc, #0x240]
 *   @0x12a604 ldr r0, [pc, #0x240]
 *   @0x12a608 mov r2, #4
 *   @0x12a60c mov r3, #1
 *   @0x12a610 ldr r1, [r4, r1]
 *   @0x12a614 add r0, pc, r0
 *   @0x12a618 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #59 part_emitter_burst → F_PartEmitterBurst(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x12a61c ldr r1, [pc, #0x22c]
 *   @0x12a620 ldr r0, [pc, #0x22c]
 *   @0x12a624 mov r2, #4
 *   @0x12a628 mov r3, #1
 *   @0x12a62c ldr r1, [r4, r1]
 *   @0x12a630 add r0, pc, r0
 *   @0x12a634 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #60 part_emitter_stream → F_PartEmitterStream(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x12a638 ldr r1, [pc, #0x218]
 *   @0x12a63c ldr r0, [pc, #0x218]
 *   @0x12a640 mov r2, #5
 *   @0x12a644 mov r3, #1
 *   @0x12a648 ldr r1, [r4, r1]
 *   @0x12a64c add r0, pc, r0
 *   @0x12a650 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #61 effect_create_below → F_EffectCreateBelow(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x12a654 ldr r1, [pc, #0x204]
 *   @0x12a658 ldr r0, [pc, #0x204]
 *   @0x12a65c mov r2, #5
 *   @0x12a660 mov r3, #1
 *   @0x12a664 ldr r1, [r4, r1]
 *   @0x12a668 add r0, pc, r0
 *   @0x12a66c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #62 effect_create_above → F_EffectCreateAbove(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x12a670 ldr r1, [pc, #0x1f0]
 *   @0x12a674 ldr r0, [pc, #0x1f0]
 *   @0x12a678 mov r2, #0
 *   @0x12a67c mov r3, #1
 *   @0x12a680 ldr r1, [r4, r1]
 *   @0x12a684 add r0, pc, r0
 *   @0x12a688 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x12a68c b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #63 effect_clear → F_EffectClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x12a690 eoreq r7, r12, r8, asr #25
 *   @0x12a694 .word 0xffffd008
 *   @0x12a698 eoreq r2, r1, r12, ror #30
 *   @0x12a69c .word 0xffffd00c
 *   @0x12a6a0 eoreq r2, r1, r4, ror #30
 *   @0x12a6a4 .word 0xffffd010
 *   @0x12a6a8 eoreq r2, r1, r12, asr pc
 *   @0x12a6ac .word 0xffffd014
 *   @0x12a6b0 eoreq r2, r1, r4, asr pc
 *   @0x12a6b4 .word 0xffffd018
 *   @0x12a6b8 eoreq r2, r1, r8, asr #30
 *   @0x12a6bc .word 0xffffd01c
 *   @0x12a6c0 eoreq r2, r1, r12, lsr pc
 *   @0x12a6c4 .word 0xffffd020
 *   @0x12a6c8 eoreq r2, r1, r4, lsr pc
 *   @0x12a6cc .word 0xffffd024
 *   @0x12a6d0 eoreq r2, r1, r8, lsr #30
 *   @0x12a6d4 .word 0xffffd028
 *   @0x12a6d8 eoreq r2, r1, r12, lsl pc
 *   @0x12a6dc .word 0xffffd02c
 *   @0x12a6e0 eoreq r2, r1, r0, lsl pc
 *   @0x12a6e4 .word 0xffffd030
 *   @0x12a6e8 eoreq r2, r1, r4, lsl #30
 *   @0x12a6ec .word 0xffffd034
 *   @0x12a6f0 .word 0x00212ef8
 *   @0x12a6f4 .word 0xffffd038
 *   @0x12a6f8 eoreq r2, r1, r12, ror #29
 *   @0x12a6fc .word 0xffffd03c
 *   @0x12a700 eoreq r2, r1, r4, ror #29
 *   @0x12a704 .word 0xffffd040
 *   @0x12a708 eoreq r2, r1, r0, ror #29
 *   @0x12a70c .word 0xffffd044
 *   @0x12a710 .word 0x00212ed4
 *   @0x12a714 .word 0xffffd048
 *   @0x12a718 eoreq r2, r1, r8, asr #29
 *   @0x12a71c .word 0xffffd04c
 *   @0x12a720 .word 0x00212ebc
 *   @0x12a724 .word 0xffffd050
 *   @0x12a728 .word 0x00212eb0
 *   @0x12a72c .word 0xffffd054
 *   @0x12a730 eoreq r2, r1, r4, lsr #29
 *   @0x12a734 .word 0xffffd058
 *   @0x12a738 mlaeq r1, r8, lr, r2
 *   @0x12a73c mlaeq r1, r4, lr, r2
 *   @0x12a740 eoreq r2, r1, r12, lsl #29
 *   @0x12a744 eoreq r2, r1, r12, lsl #29
 *   @0x12a748 eoreq r2, r1, r12, lsl #29
 *   @0x12a74c eoreq r2, r1, r12, lsl #29
 *   @0x12a750 eoreq r2, r1, r8, lsl #29
 *   @0x12a754 eoreq r2, r1, r4, lsl #29
 *   @0x12a758 eoreq r2, r1, r0, lsl #29
 *   @0x12a75c .word 0xffffd05c
 *   @0x12a760 eoreq r2, r1, r8, ror lr
 *   @0x12a764 .word 0xffffd060
 *   @0x12a768 eoreq r2, r1, r0, ror lr
 *   @0x12a76c .word 0xffffd064
 *   @0x12a770 eoreq r2, r1, r4, ror #28
 *   @0x12a774 eoreq r2, r1, r0, ror #28
 *   @0x12a778 .word 0xffffd068
 *   @0x12a77c eoreq r2, r1, r4, asr lr
 *   @0x12a780 .word 0xffffd06c
 *   @0x12a784 eoreq r2, r1, r8, asr #28
 *   @0x12a788 .word 0xffffd070
 *   @0x12a78c eoreq r2, r1, r0, asr #28
 *   @0x12a790 .word 0xffffd074
 *   @0x12a794 eoreq r2, r1, r8, lsr lr
 *   @0x12a798 .word 0xffffd078
 *   @0x12a79c eoreq r2, r1, r0, lsr lr
 *   @0x12a7a0 .word 0xffffd07c
 *   @0x12a7a4 eoreq r2, r1, r8, lsr #28
 *   @0x12a7a8 .word 0xffffd080
 *   @0x12a7ac eoreq r2, r1, r4, lsr #28
 *   @0x12a7b0 .word 0xffffd084
 *   @0x12a7b4 eoreq r2, r1, r12, lsl lr
 *   @0x12a7b8 .word 0xffffd088
 *   @0x12a7bc eoreq r2, r1, r8, lsl lr
 *   @0x12a7c0 .word 0xffffd08c
 *   @0x12a7c4 eoreq r2, r1, r12, lsl lr
 *   @0x12a7c8 .word 0xffffd090
 *   @0x12a7cc eoreq r2, r1, r12, lsl lr
 *   @0x12a7d0 .word 0xffffd094
 *   @0x12a7d4 eoreq r2, r1, r4, lsl lr
 *   @0x12a7d8 .word 0xffffbcd4
 *   @0x12a7dc .word 0xffffd098
 *   @0x12a7e0 .word 0x00212df8
 *   @0x12a7e4 .word 0xffffd09c
 *   @0x12a7e8 .word 0x00212df8
 *   @0x12a7ec .word 0xffffd0a0
 *   @0x12a7f0 .word 0x00212df4
 *   @0x12a7f4 .word 0xffffd0a4
 *   @0x12a7f8 eoreq r2, r1, r8, ror #27
 *   @0x12a7fc .word 0xffffd0a8
 *   @0x12a800 eoreq r2, r1, r4, ror #27
 *   @0x12a804 eoreq r2, r1, r8, ror #27
 *   @0x12a808 .word 0xffffd0ac
 *   @0x12a80c eoreq r2, r1, r8, ror #27
 *   @0x12a810 .word 0xffffd0b0
 *   @0x12a814 eoreq r2, r1, r4, ror #27
 *   @0x12a818 .word 0xffffd0b4
 *   @0x12a81c eoreq r2, r1, r0, ror #27
 *   @0x12a820 .word 0xffffd0b8
 *   @0x12a824 .word 0x00212dd8
 *   @0x12a828 .word 0xffffd0bc
 *   @0x12a82c .word 0x00212dd4
 *   @0x12a830 .word 0xffffd0c0
 *   @0x12a834 .word 0x00212dd4
 *   @0x12a838 .word 0xffffd0c4
 *   @0x12a83c eoreq r2, r1, r12, asr #27
 *   @0x12a840 .word 0xffffd0c8
 *   @0x12a844 eoreq r2, r1, r4, asr #27
 *   @0x12a848 .word 0xffffd0cc
 *   @0x12a84c .word 0x00212dbc
 *   @0x12a850 .word 0xffffd0d0
 *   @0x12a854 .word 0x00212db4
 *   @0x12a858 .word 0xffffd0d4
 *   @0x12a85c eoreq r2, r1, r12, lsr #27
 *   @0x12a860 .word 0xffffd0d8
 *   @0x12a864 eoreq r2, r1, r4, lsr #27
 *   @0x12a868 .word 0xffffd0dc
 *   @0x12a86c mlaeq r1, r12, sp, r2
 *
 * ══ §3/3 InitFileFunctions  0x13c4a0..0x13cf04  size 2660  665 条（518 条指令 + 147 个池字）══
 * @func 0x13c4a0 0x13cf04  size 2660  665 条
 * 注册 73 条｜唯一名 73｜唯一函数指针 73｜argc 0:10 1:41 2:16 3:5 4:1｜flag 0:72 1:1
 * 首条 #0 file_bin_open（0x13c4d0）→ 末条 #72 load_csv（0x13ccb4）
 * 名字族（前 8）: file×40 ini×11 filename×6 http×4 directory×3 execute×2 parameter×2 json×2
 * 游戏实际调用的 99 个内建里落在本表: 6 个（file_delete, file_exists, ini_close, ini_open, ini_read_real, ini_write_real）
 * 表: asm/init-tables/init-InitFileFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: 无（本函数每条注册的四实参全部解出，控制流全部走到）
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13c4a0 push {r4, lr}
 *   @0x13c4a4 bl 0x13c488 <_Z9GetSecurev>   —— 调用 GetSecure()
 *   @0x13c4a8 ldr r4, [pc, #0x808]
 *   @0x13c4ac bl 0x13b830 <_Z12InitBinFilesv>   —— 调用 InitBinFiles()
 *   @0x13c4b0 bl 0x13b874 <_Z13InitTextFilesv>   —— 调用 InitTextFiles()
 *   @0x13c4b4 ldr r1, [pc, #0x800]
 *   @0x13c4b8 add r4, pc, r4
 *   @0x13c4bc ldr r0, [pc, #0x7fc]
 *   @0x13c4c0 mov r2, #2
 *   @0x13c4c4 mov r3, #0
 *   @0x13c4c8 ldr r1, [r4, r1]
 *   @0x13c4cc add r0, pc, r0
 *   @0x13c4d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 file_bin_open → F_FileBinOpen(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x13c4d4 ldr r1, [pc, #0x7e8]
 *   @0x13c4d8 ldr r0, [pc, #0x7e8]
 *   @0x13c4dc mov r2, #1
 *   @0x13c4e0 mov r3, #0
 *   @0x13c4e4 ldr r1, [r4, r1]
 *   @0x13c4e8 add r0, pc, r0
 *   @0x13c4ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 file_bin_rewrite → F_FileBinRewrite(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c4f0 ldr r1, [pc, #0x7d4]
 *   @0x13c4f4 ldr r0, [pc, #0x7d4]
 *   @0x13c4f8 mov r2, #1
 *   @0x13c4fc mov r3, #0
 *   @0x13c500 ldr r1, [r4, r1]
 *   @0x13c504 add r0, pc, r0
 *   @0x13c508 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 file_bin_close → F_FileBinClose(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c50c ldr r1, [pc, #0x7c0]
 *   @0x13c510 ldr r0, [pc, #0x7c0]
 *   @0x13c514 mov r2, #1
 *   @0x13c518 mov r3, #0
 *   @0x13c51c ldr r1, [r4, r1]
 *   @0x13c520 add r0, pc, r0
 *   @0x13c524 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 file_bin_position → F_FileBinPosition(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c528 ldr r1, [pc, #0x7ac]
 *   @0x13c52c ldr r0, [pc, #0x7ac]
 *   @0x13c530 mov r2, #1
 *   @0x13c534 mov r3, #0
 *   @0x13c538 ldr r1, [r4, r1]
 *   @0x13c53c add r0, pc, r0
 *   @0x13c540 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #4 file_bin_size → F_FileBinSize(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c544 ldr r1, [pc, #0x798]
 *   @0x13c548 ldr r0, [pc, #0x798]
 *   @0x13c54c mov r2, #2
 *   @0x13c550 mov r3, #0
 *   @0x13c554 ldr r1, [r4, r1]
 *   @0x13c558 add r0, pc, r0
 *   @0x13c55c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #5 file_bin_seek → F_FileBinSeek(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x13c560 ldr r1, [pc, #0x784]
 *   @0x13c564 ldr r0, [pc, #0x784]
 *   @0x13c568 mov r2, #1
 *   @0x13c56c mov r3, #0
 *   @0x13c570 ldr r1, [r4, r1]
 *   @0x13c574 add r0, pc, r0
 *   @0x13c578 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #6 file_bin_read_byte → F_FileBinReadByte(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c57c ldr r1, [pc, #0x770]
 *   @0x13c580 ldr r0, [pc, #0x770]
 *   @0x13c584 mov r2, #2
 *   @0x13c588 mov r3, #0
 *   @0x13c58c ldr r1, [r4, r1]
 *   @0x13c590 add r0, pc, r0
 *   @0x13c594 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #7 file_bin_write_byte → F_FileBinWriteByte(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x13c598 ldr r1, [pc, #0x75c]
 *   @0x13c59c ldr r0, [pc, #0x75c]
 *   @0x13c5a0 mov r2, #1
 *   @0x13c5a4 mov r3, #0
 *   @0x13c5a8 ldr r1, [r4, r1]
 *   @0x13c5ac add r0, pc, r0
 *   @0x13c5b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #8 file_text_open_from_string → F_FileTextSet(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c5b4 ldr r1, [pc, #0x748]
 *   @0x13c5b8 ldr r0, [pc, #0x748]
 *   @0x13c5bc mov r2, #1
 *   @0x13c5c0 mov r3, #0
 *   @0x13c5c4 ldr r1, [r4, r1]
 *   @0x13c5c8 add r0, pc, r0
 *   @0x13c5cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #9 file_text_open_read → F_FileTextOpenRead(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c5d0 ldr r1, [pc, #0x734]
 *   @0x13c5d4 ldr r0, [pc, #0x734]
 *   @0x13c5d8 mov r2, #1
 *   @0x13c5dc mov r3, #0
 *   @0x13c5e0 ldr r1, [r4, r1]
 *   @0x13c5e4 add r0, pc, r0
 *   @0x13c5e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #10 file_text_open_write → F_FileTextOpenWrite(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c5ec ldr r1, [pc, #0x720]
 *   @0x13c5f0 ldr r0, [pc, #0x720]
 *   @0x13c5f4 mov r2, #1
 *   @0x13c5f8 mov r3, #0
 *   @0x13c5fc ldr r1, [r4, r1]
 *   @0x13c600 add r0, pc, r0
 *   @0x13c604 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #11 file_text_open_append → F_FileTextOpenAppend(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c608 ldr r1, [pc, #0x70c]
 *   @0x13c60c ldr r0, [pc, #0x70c]
 *   @0x13c610 mov r2, #1
 *   @0x13c614 mov r3, #0
 *   @0x13c618 ldr r1, [r4, r1]
 *   @0x13c61c add r0, pc, r0
 *   @0x13c620 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #12 file_text_close → F_FileTextClose(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c624 ldr r1, [pc, #0x6f8]
 *   @0x13c628 ldr r0, [pc, #0x6f8]
 *   @0x13c62c mov r2, #1
 *   @0x13c630 mov r3, #0
 *   @0x13c634 ldr r1, [r4, r1]
 *   @0x13c638 add r0, pc, r0
 *   @0x13c63c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #13 file_text_read_string → F_FileTextReadString(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c640 ldr r1, [pc, #0x6e4]
 *   @0x13c644 ldr r0, [pc, #0x6e4]
 *   @0x13c648 mov r2, #1
 *   @0x13c64c mov r3, #0
 *   @0x13c650 ldr r1, [r4, r1]
 *   @0x13c654 add r0, pc, r0
 *   @0x13c658 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #14 file_text_read_real → F_FileTextReadReal(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c65c ldr r1, [pc, #0x6d0]
 *   @0x13c660 ldr r0, [pc, #0x6d0]
 *   @0x13c664 mov r2, #1
 *   @0x13c668 mov r3, #0
 *   @0x13c66c ldr r1, [r4, r1]
 *   @0x13c670 add r0, pc, r0
 *   @0x13c674 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #15 file_text_readln → F_FileTextReadLn(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c678 ldr r1, [pc, #0x6bc]
 *   @0x13c67c ldr r0, [pc, #0x6bc]
 *   @0x13c680 mov r2, #1
 *   @0x13c684 mov r3, #0
 *   @0x13c688 ldr r1, [r4, r1]
 *   @0x13c68c add r0, pc, r0
 *   @0x13c690 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #16 file_text_eof → F_FileTextEof(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c694 ldr r1, [pc, #0x6a8]
 *   @0x13c698 ldr r0, [pc, #0x6a8]
 *   @0x13c69c mov r2, #1
 *   @0x13c6a0 mov r3, #0
 *   @0x13c6a4 ldr r1, [r4, r1]
 *   @0x13c6a8 add r0, pc, r0
 *   @0x13c6ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #17 file_text_eoln → F_FileTextEoln(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c6b0 ldr r1, [pc, #0x694]
 *   @0x13c6b4 ldr r0, [pc, #0x694]
 *   @0x13c6b8 mov r2, #2
 *   @0x13c6bc mov r3, #0
 *   @0x13c6c0 ldr r1, [r4, r1]
 *   @0x13c6c4 add r0, pc, r0
 *   @0x13c6c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #18 file_text_write_string → F_FileTextWriteString(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x13c6cc ldr r1, [pc, #0x680]
 *   @0x13c6d0 ldr r0, [pc, #0x680]
 *   @0x13c6d4 mov r2, #2
 *   @0x13c6d8 mov r3, #0
 *   @0x13c6dc ldr r1, [r4, r1]
 *   @0x13c6e0 add r0, pc, r0
 *   @0x13c6e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #19 file_text_write_real → F_FileTextWriteReal(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x13c6e8 ldr r1, [pc, #0x66c]
 *   @0x13c6ec ldr r0, [pc, #0x66c]
 *   @0x13c6f0 mov r2, #1
 *   @0x13c6f4 mov r3, #0
 *   @0x13c6f8 ldr r1, [r4, r1]
 *   @0x13c6fc add r0, pc, r0
 *   @0x13c700 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #20 file_text_writeln → F_FileTextWriteLn(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c704 ldr r1, [pc, #0x658]
 *   @0x13c708 ldr r0, [pc, #0x658]
 *   @0x13c70c mov r2, #1
 *   @0x13c710 mov r3, #0
 *   @0x13c714 ldr r1, [r4, r1]
 *   @0x13c718 add r0, pc, r0
 *   @0x13c71c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #21 file_open_read → F_FileOpenRead(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c720 ldr r1, [pc, #0x644]
 *   @0x13c724 ldr r0, [pc, #0x644]
 *   @0x13c728 mov r2, #1
 *   @0x13c72c mov r3, #0
 *   @0x13c730 ldr r1, [r4, r1]
 *   @0x13c734 add r0, pc, r0
 *   @0x13c738 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #22 file_open_write → F_FileOpenWrite(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c73c ldr r1, [pc, #0x630]
 *   @0x13c740 ldr r0, [pc, #0x630]
 *   @0x13c744 mov r2, #1
 *   @0x13c748 mov r3, #0
 *   @0x13c74c ldr r1, [r4, r1]
 *   @0x13c750 add r0, pc, r0
 *   @0x13c754 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #23 file_open_append → F_FileOpenAppend(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c758 ldr r1, [pc, #0x61c]
 *   @0x13c75c ldr r0, [pc, #0x61c]
 *   @0x13c760 mov r2, #0
 *   @0x13c764 mov r3, r2
 *   @0x13c768 ldr r1, [r4, r1]
 *   @0x13c76c add r0, pc, r0
 *   @0x13c770 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #24 file_close → F_FileClose(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x13c774 ldr r1, [pc, #0x608]
 *   @0x13c778 ldr r0, [pc, #0x608]
 *   @0x13c77c mov r2, #0
 *   @0x13c780 mov r3, r2
 *   @0x13c784 ldr r1, [r4, r1]
 *   @0x13c788 add r0, pc, r0
 *   @0x13c78c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #25 file_read_string → F_FileReadString(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x13c790 ldr r1, [pc, #0x5f4]
 *   @0x13c794 ldr r0, [pc, #0x5f4]
 *   @0x13c798 mov r2, #0
 *   @0x13c79c mov r3, r2
 *   @0x13c7a0 ldr r1, [r4, r1]
 *   @0x13c7a4 add r0, pc, r0
 *   @0x13c7a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #26 file_read_real → F_FileReadReal(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x13c7ac ldr r1, [pc, #0x5e0]
 *   @0x13c7b0 ldr r0, [pc, #0x5e0]
 *   @0x13c7b4 mov r2, #0
 *   @0x13c7b8 mov r3, r2
 *   @0x13c7bc ldr r1, [r4, r1]
 *   @0x13c7c0 add r0, pc, r0
 *   @0x13c7c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #27 file_readln → F_FileReadLn(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x13c7c8 ldr r1, [pc, #0x5cc]
 *   @0x13c7cc ldr r0, [pc, #0x5cc]
 *   @0x13c7d0 mov r2, #0
 *   @0x13c7d4 mov r3, r2
 *   @0x13c7d8 ldr r1, [r4, r1]
 *   @0x13c7dc add r0, pc, r0
 *   @0x13c7e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #28 file_eof → F_FileEof(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x13c7e4 ldr r1, [pc, #0x5b8]
 *   @0x13c7e8 ldr r0, [pc, #0x5b8]
 *   @0x13c7ec mov r2, #1
 *   @0x13c7f0 mov r3, #0
 *   @0x13c7f4 ldr r1, [r4, r1]
 *   @0x13c7f8 add r0, pc, r0
 *   @0x13c7fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #29 file_write_string → F_FileWriteString(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c800 ldr r1, [pc, #0x5a4]
 *   @0x13c804 ldr r0, [pc, #0x5a4]
 *   @0x13c808 mov r2, #1
 *   @0x13c80c mov r3, #0
 *   @0x13c810 ldr r1, [r4, r1]
 *   @0x13c814 add r0, pc, r0
 *   @0x13c818 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #30 file_write_real → F_FileWriteReal(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c81c ldr r1, [pc, #0x590]
 *   @0x13c820 ldr r0, [pc, #0x590]
 *   @0x13c824 mov r2, #0
 *   @0x13c828 mov r3, r2
 *   @0x13c82c ldr r1, [r4, r1]
 *   @0x13c830 add r0, pc, r0
 *   @0x13c834 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #31 file_writeln → F_FileWriteLn(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x13c838 ldr r1, [pc, #0x57c]
 *   @0x13c83c ldr r0, [pc, #0x57c]
 *   @0x13c840 mov r2, #1
 *   @0x13c844 mov r3, #0
 *   @0x13c848 ldr r1, [r4, r1]
 *   @0x13c84c add r0, pc, r0
 *   @0x13c850 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #32 file_exists → F_FileExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c854 ldr r1, [pc, #0x568]
 *   @0x13c858 ldr r0, [pc, #0x568]
 *   @0x13c85c mov r2, #1
 *   @0x13c860 mov r3, #0
 *   @0x13c864 ldr r1, [r4, r1]
 *   @0x13c868 add r0, pc, r0
 *   @0x13c86c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #33 file_delete → F_FileDelete(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c870 ldr r1, [pc, #0x554]
 *   @0x13c874 ldr r0, [pc, #0x554]
 *   @0x13c878 mov r2, #2
 *   @0x13c87c mov r3, #0
 *   @0x13c880 ldr r1, [r4, r1]
 *   @0x13c884 add r0, pc, r0
 *   @0x13c888 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #34 file_rename → F_FileRename(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x13c88c ldr r1, [pc, #0x540]
 *   @0x13c890 ldr r0, [pc, #0x540]
 *   @0x13c894 mov r2, #2
 *   @0x13c898 mov r3, #0
 *   @0x13c89c ldr r1, [r4, r1]
 *   @0x13c8a0 add r0, pc, r0
 *   @0x13c8a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #35 file_copy → F_FileCopy(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x13c8a8 ldr r1, [pc, #0x52c]
 *   @0x13c8ac ldr r0, [pc, #0x52c]
 *   @0x13c8b0 mov r2, #1
 *   @0x13c8b4 mov r3, #0
 *   @0x13c8b8 ldr r1, [r4, r1]
 *   @0x13c8bc add r0, pc, r0
 *   @0x13c8c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #36 directory_exists → F_DirectoryExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c8c4 ldr r1, [pc, #0x518]
 *   @0x13c8c8 ldr r0, [pc, #0x518]
 *   @0x13c8cc mov r2, #1
 *   @0x13c8d0 mov r3, #0
 *   @0x13c8d4 ldr r1, [r4, r1]
 *   @0x13c8d8 add r0, pc, r0
 *   @0x13c8dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #37 directory_create → F_DirectoryCreate(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c8e0 ldr r1, [pc, #0x504]
 *   @0x13c8e4 ldr r0, [pc, #0x504]
 *   @0x13c8e8 mov r2, #1
 *   @0x13c8ec mov r3, #0
 *   @0x13c8f0 ldr r1, [r4, r1]
 *   @0x13c8f4 add r0, pc, r0
 *   @0x13c8f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #38 directory_destroy → F_DirectoryDelete(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c8fc ldr r1, [pc, #0x4f0]
 *   @0x13c900 ldr r0, [pc, #0x4f0]
 *   @0x13c904 mov r2, #2
 *   @0x13c908 mov r3, #0
 *   @0x13c90c ldr r1, [r4, r1]
 *   @0x13c910 add r0, pc, r0
 *   @0x13c914 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #39 file_find_first → F_FileFindFirst(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x13c918 ldr r1, [pc, #0x4dc]
 *   @0x13c91c ldr r0, [pc, #0x4dc]
 *   @0x13c920 mov r2, #0
 *   @0x13c924 mov r3, r2
 *   @0x13c928 ldr r1, [r4, r1]
 *   @0x13c92c add r0, pc, r0
 *   @0x13c930 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #40 file_find_next → F_FileFindNext(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x13c934 ldr r1, [pc, #0x4c8]
 *   @0x13c938 ldr r0, [pc, #0x4c8]
 *   @0x13c93c mov r2, #0
 *   @0x13c940 mov r3, r2
 *   @0x13c944 ldr r1, [r4, r1]
 *   @0x13c948 add r0, pc, r0
 *   @0x13c94c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #41 file_find_close → F_FileFindClose(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x13c950 ldr r1, [pc, #0x4b4]
 *   @0x13c954 ldr r0, [pc, #0x4b4]
 *   @0x13c958 mov r2, #2
 *   @0x13c95c mov r3, #0
 *   @0x13c960 ldr r1, [r4, r1]
 *   @0x13c964 add r0, pc, r0
 *   @0x13c968 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #42 file_attributes → F_FileAttributes(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x13c96c ldr r1, [pc, #0x4a0]
 *   @0x13c970 ldr r0, [pc, #0x4a0]
 *   @0x13c974 mov r2, #1
 *   @0x13c978 mov r3, #0
 *   @0x13c97c ldr r1, [r4, r1]
 *   @0x13c980 add r0, pc, r0
 *   @0x13c984 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #43 filename_name → F_FilenameName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c988 ldr r1, [pc, #0x48c]
 *   @0x13c98c ldr r0, [pc, #0x48c]
 *   @0x13c990 mov r2, #1
 *   @0x13c994 mov r3, #0
 *   @0x13c998 ldr r1, [r4, r1]
 *   @0x13c99c add r0, pc, r0
 *   @0x13c9a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #44 filename_path → F_FilenamePath(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c9a4 ldr r1, [pc, #0x478]
 *   @0x13c9a8 ldr r0, [pc, #0x478]
 *   @0x13c9ac mov r2, #1
 *   @0x13c9b0 mov r3, #0
 *   @0x13c9b4 ldr r1, [r4, r1]
 *   @0x13c9b8 add r0, pc, r0
 *   @0x13c9bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #45 filename_dir → F_FilenameDir(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c9c0 ldr r1, [pc, #0x464]
 *   @0x13c9c4 ldr r0, [pc, #0x464]
 *   @0x13c9c8 mov r2, #1
 *   @0x13c9cc mov r3, #0
 *   @0x13c9d0 ldr r1, [r4, r1]
 *   @0x13c9d4 add r0, pc, r0
 *   @0x13c9d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #46 filename_drive → F_FilenameDrive(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c9dc ldr r1, [pc, #0x450]
 *   @0x13c9e0 ldr r0, [pc, #0x450]
 *   @0x13c9e4 mov r2, #1
 *   @0x13c9e8 mov r3, #0
 *   @0x13c9ec ldr r1, [r4, r1]
 *   @0x13c9f0 add r0, pc, r0
 *   @0x13c9f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #47 filename_ext → F_FilenameExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13c9f8 ldr r1, [pc, #0x43c]
 *   @0x13c9fc ldr r0, [pc, #0x43c]
 *   @0x13ca00 mov r2, #2
 *   @0x13ca04 mov r3, #0
 *   @0x13ca08 ldr r1, [r4, r1]
 *   @0x13ca0c add r0, pc, r0
 *   @0x13ca10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #48 filename_change_ext → F_FilenameChangeExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x13ca14 ldr r1, [pc, #0x428]
 *   @0x13ca18 ldr r0, [pc, #0x428]
 *   @0x13ca1c mov r2, #3
 *   @0x13ca20 mov r3, #0
 *   @0x13ca24 ldr r1, [r4, r1]
 *   @0x13ca28 add r0, pc, r0
 *   @0x13ca2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #49 execute_program → F_ExecuteProgram(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x13ca30 ldr r1, [pc, #0x414]
 *   @0x13ca34 ldr r0, [pc, #0x414]
 *   @0x13ca38 mov r2, #2
 *   @0x13ca3c mov r3, #0
 *   @0x13ca40 ldr r1, [r4, r1]
 *   @0x13ca44 add r0, pc, r0
 *   @0x13ca48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #50 execute_shell → F_ExecuteShell(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x13ca4c ldr r1, [pc, #0x400]
 *   @0x13ca50 ldr r0, [pc, #0x400]
 *   @0x13ca54 mov r2, #0
 *   @0x13ca58 mov r3, r2
 *   @0x13ca5c ldr r1, [r4, r1]
 *   @0x13ca60 add r0, pc, r0
 *   @0x13ca64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #51 parameter_count → F_ParameterCount(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x13ca68 ldr r1, [pc, #0x3ec]
 *   @0x13ca6c ldr r0, [pc, #0x3ec]
 *   @0x13ca70 mov r2, #1
 *   @0x13ca74 mov r3, #0
 *   @0x13ca78 ldr r1, [r4, r1]
 *   @0x13ca7c add r0, pc, r0
 *   @0x13ca80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #52 parameter_string → F_ParameterString(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13ca84 ldr r1, [pc, #0x3d8]
 *   @0x13ca88 ldr r0, [pc, #0x3d8]
 *   @0x13ca8c mov r2, #1
 *   @0x13ca90 mov r3, #0
 *   @0x13ca94 ldr r1, [r4, r1]
 *   @0x13ca98 add r0, pc, r0
 *   @0x13ca9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #53 environment_get_variable → F_EnvironmentGetVariable(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13caa0 ldr r1, [pc, #0x3c4]
 *   @0x13caa4 ldr r0, [pc, #0x3c4]
 *   @0x13caa8 mov r2, #1
 *   @0x13caac mov r3, #0
 *   @0x13cab0 ldr r1, [r4, r1]
 *   @0x13cab4 add r0, pc, r0
 *   @0x13cab8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #54 ini_open_from_string → F_IniOpenFromString(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13cabc ldr r1, [pc, #0x3b0]
 *   @0x13cac0 ldr r0, [pc, #0x3b0]
 *   @0x13cac4 mov r2, #1
 *   @0x13cac8 mov r3, #0
 *   @0x13cacc ldr r1, [r4, r1]
 *   @0x13cad0 add r0, pc, r0
 *   @0x13cad4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #55 ini_open → F_IniOpen(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13cad8 ldr r1, [pc, #0x39c]
 *   @0x13cadc ldr r0, [pc, #0x39c]
 *   @0x13cae0 mov r2, #0
 *   @0x13cae4 mov r3, r2
 *   @0x13cae8 ldr r1, [r4, r1]
 *   @0x13caec add r0, pc, r0
 *   @0x13caf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #56 ini_close → F_IniClose(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x13caf4 ldr r1, [pc, #0x388]
 *   @0x13caf8 ldr r0, [pc, #0x388]
 *   @0x13cafc mov r2, #3
 *   @0x13cb00 mov r3, #0
 *   @0x13cb04 ldr r1, [r4, r1]
 *   @0x13cb08 add r0, pc, r0
 *   @0x13cb0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #57 ini_read_string → F_IniReadString(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x13cb10 ldr r1, [pc, #0x374]
 *   @0x13cb14 ldr r0, [pc, #0x374]
 *   @0x13cb18 mov r2, #3
 *   @0x13cb1c mov r3, #0
 *   @0x13cb20 ldr r1, [r4, r1]
 *   @0x13cb24 add r0, pc, r0
 *   @0x13cb28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #58 ini_read_real → F_IniReadReal(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x13cb2c ldr r1, [pc, #0x360]
 *   @0x13cb30 ldr r0, [pc, #0x360]
 *   @0x13cb34 mov r2, #3
 *   @0x13cb38 mov r3, #0
 *   @0x13cb3c ldr r1, [r4, r1]
 *   @0x13cb40 add r0, pc, r0
 *   @0x13cb44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #59 ini_write_string → F_IniWriteString(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x13cb48 ldr r1, [pc, #0x34c]
 *   @0x13cb4c ldr r0, [pc, #0x34c]
 *   @0x13cb50 mov r2, #3
 *   @0x13cb54 mov r3, #0
 *   @0x13cb58 ldr r1, [r4, r1]
 *   @0x13cb5c add r0, pc, r0
 *   @0x13cb60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #60 ini_write_real → F_IniWriteReal(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x13cb64 ldr r1, [pc, #0x338]
 *   @0x13cb68 ldr r0, [pc, #0x338]
 *   @0x13cb6c mov r2, #2
 *   @0x13cb70 mov r3, #0
 *   @0x13cb74 ldr r1, [r4, r1]
 *   @0x13cb78 add r0, pc, r0
 *   @0x13cb7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #61 ini_key_exists → F_IniKeyExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x13cb80 ldr r1, [pc, #0x324]
 *   @0x13cb84 ldr r0, [pc, #0x324]
 *   @0x13cb88 mov r2, #1
 *   @0x13cb8c mov r3, #0
 *   @0x13cb90 ldr r1, [r4, r1]
 *   @0x13cb94 add r0, pc, r0
 *   @0x13cb98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #62 ini_section_exists → F_IniSectionExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13cb9c ldr r1, [pc, #0x310]
 *   @0x13cba0 ldr r0, [pc, #0x310]
 *   @0x13cba4 mov r2, #2
 *   @0x13cba8 mov r3, #0
 *   @0x13cbac ldr r1, [r4, r1]
 *   @0x13cbb0 add r0, pc, r0
 *   @0x13cbb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #63 ini_key_delete → F_IniKeyDelete(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x13cbb8 ldr r1, [pc, #0x2fc]
 *   @0x13cbbc ldr r0, [pc, #0x2fc]
 *   @0x13cbc0 mov r2, #1
 *   @0x13cbc4 mov r3, #0
 *   @0x13cbc8 ldr r1, [r4, r1]
 *   @0x13cbcc add r0, pc, r0
 *   @0x13cbd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #64 ini_section_delete → F_IniSectionDelete(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13cbd4 ldr r1, [pc, #0x2e8]
 *   @0x13cbd8 ldr r0, [pc, #0x2e8]
 *   @0x13cbdc mov r2, #2
 *   @0x13cbe0 mov r3, #0
 *   @0x13cbe4 ldr r1, [r4, r1]
 *   @0x13cbe8 add r0, pc, r0
 *   @0x13cbec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #65 http_post_string → F_HttpPostString(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x13cbf0 ldr r1, [pc, #0x2d4]
 *   @0x13cbf4 ldr r0, [pc, #0x2d4]
 *   @0x13cbf8 mov r2, #1
 *   @0x13cbfc mov r3, #0
 *   @0x13cc00 ldr r1, [r4, r1]
 *   @0x13cc04 add r0, pc, r0
 *   @0x13cc08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #66 http_get → F_HttpGet(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13cc0c ldr r1, [pc, #0x2c0]
 *   @0x13cc10 ldr r0, [pc, #0x2c0]
 *   @0x13cc14 mov r2, #2
 *   @0x13cc18 mov r3, #0
 *   @0x13cc1c ldr r1, [r4, r1]
 *   @0x13cc20 add r0, pc, r0
 *   @0x13cc24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #67 http_get_file → F_HttpGetFile(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x13cc28 ldr r1, [pc, #0x2ac]
 *   @0x13cc2c ldr r0, [pc, #0x2ac]
 *   @0x13cc30 mov r2, #4
 *   @0x13cc34 mov r3, #0
 *   @0x13cc38 ldr r1, [r4, r1]
 *   @0x13cc3c add r0, pc, r0
 *   @0x13cc40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #68 http_request → F_HttpRequest(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x13cc44 ldr r1, [pc, #0x298]
 *   @0x13cc48 ldr r0, [pc, #0x298]
 *   @0x13cc4c mov r2, #1
 *   @0x13cc50 mov r3, #0
 *   @0x13cc54 ldr r1, [r4, r1]
 *   @0x13cc58 add r0, pc, r0
 *   @0x13cc5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #69 json_encode → F_JsonEncode(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13cc60 ldr r1, [pc, #0x284]
 *   @0x13cc64 ldr r0, [pc, #0x284]
 *   @0x13cc68 mov r2, #1
 *   @0x13cc6c mov r3, #0
 *   @0x13cc70 ldr r1, [r4, r1]
 *   @0x13cc74 add r0, pc, r0
 *   @0x13cc78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #70 json_decode → F_JsonDecode(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13cc7c ldr r1, [pc, #0x270]
 *   @0x13cc80 ldr r0, [pc, #0x270]
 *   @0x13cc84 mov r2, #2
 *   @0x13cc88 mov r3, #0
 *   @0x13cc8c ldr r1, [r4, r1]
 *   @0x13cc90 add r0, pc, r0
 *   @0x13cc94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #71 zip_unzip → F_ZipUnzip(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x13cc98 ldr r1, [pc, #0x25c]
 *   @0x13cc9c ldr r0, [pc, #0x25c]
 *   @0x13cca0 mov r2, #1
 *   @0x13cca4 mov r3, r2
 *   @0x13cca8 ldr r1, [r4, r1]
 *   @0x13ccac add r0, pc, r0
 *   @0x13ccb0 pop {r4, lr}
 *   @0x13ccb4 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #72 load_csv → F_LoadCSV(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x13ccb8 mlaeq r11, r8, r7, r5
 *   @0x13ccbc .word 0xffffd65c
 *   @0x13ccc0 eoreq r3, r0, r12, ror #29
 *   @0x13ccc4 .word 0xffffd660
 *   @0x13ccc8 eoreq r3, r0, r0, ror #29
 *   @0x13cccc .word 0xffffd664
 *   @0x13ccd0 .word 0x00203ed8
 *   @0x13ccd4 .word 0xffffd668
 *   @0x13ccd8 eoreq r3, r0, r12, asr #29
 *   @0x13ccdc .word 0xffffd66c
 *   @0x13cce0 eoreq r3, r0, r4, asr #29
 *   @0x13cce4 .word 0xffffd670
 *   @0x13cce8 .word 0x00203eb8
 *   @0x13ccec .word 0xffffd674
 *   @0x13ccf0 eoreq r3, r0, r12, lsr #29
 *   @0x13ccf4 .word 0xffffd678
 *   @0x13ccf8 eoreq r3, r0, r4, lsr #29
 *   @0x13ccfc .word 0xffffd67c
 *   @0x13cd00 mlaeq r0, r12, lr, r3
 *   @0x13cd04 .word 0xffffd680
 *   @0x13cd08 mlaeq r0, r12, lr, r3
 *   @0x13cd0c .word 0xffffd684
 *   @0x13cd10 mlaeq r0, r4, lr, r3
 *   @0x13cd14 .word 0xffffd688
 *   @0x13cd18 mlaeq r0, r0, lr, r3
 *   @0x13cd1c .word 0xffffd68c
 *   @0x13cd20 eoreq r3, r0, r12, lsl #29
 *   @0x13cd24 .word 0xffffd690
 *   @0x13cd28 eoreq r3, r0, r0, lsl #29
 *   @0x13cd2c .word 0xffffd694
 *   @0x13cd30 eoreq r3, r0, r12, ror lr
 *   @0x13cd34 .word 0xffffd698
 *   @0x13cd38 eoreq r3, r0, r4, ror lr
 *   @0x13cd3c .word 0xffffd69c
 *   @0x13cd40 eoreq r3, r0, r12, ror #28
 *   @0x13cd44 .word 0xffffd6a0
 *   @0x13cd48 eoreq r3, r0, r0, ror #28
 *   @0x13cd4c .word 0xffffd6a4
 *   @0x13cd50 eoreq r3, r0, r4, asr lr
 *   @0x13cd54 .word 0xffffd6a8
 *   @0x13cd58 eoreq r3, r0, r0, asr lr
 *   @0x13cd5c .word 0xffffd6ac
 *   @0x13cd60 eoreq r3, r0, r12, asr #28
 *   @0x13cd64 .word 0xffffd6b0
 *   @0x13cd68 eoreq r3, r0, r4, asr #28
 *   @0x13cd6c .word 0xffffd6b4
 *   @0x13cd70 eoreq r3, r0, r8, lsr lr
 *   @0x13cd74 .word 0xffffd6b8
 *   @0x13cd78 eoreq r3, r0, r12, lsr #28
 *   @0x13cd7c .word 0xffffd6bc
 *   @0x13cd80 eoreq r3, r0, r4, lsr #28
 *   @0x13cd84 .word 0xffffd6c0
 *   @0x13cd88 eoreq r3, r0, r4, lsl lr
 *   @0x13cd8c .word 0xffffd6c4
 *   @0x13cd90 eoreq r3, r0, r12, lsl #28
 *   @0x13cd94 .word 0xffffd6c8
 *   @0x13cd98 eoreq r3, r0, r0, lsl #28
 *   @0x13cd9c .word 0xffffd6cc
 *   @0x13cda0 .word 0x00203df0
 *   @0x13cda4 .word 0xffffd6d0
 *   @0x13cda8 eoreq r3, r0, r0, ror #27
 *   @0x13cdac .word 0xffffd6d4
 *   @0x13cdb0 .word 0x00203dd8
 *   @0x13cdb4 .word 0xffffd6d8
 *   @0x13cdb8 eoreq r3, r0, r12, asr #27
 *   @0x13cdbc .word 0xffffd6dc
 *   @0x13cdc0 eoreq r3, r0, r0, asr #27
 *   @0x13cdc4 .word 0xffffd6e0
 *   @0x13cdc8 .word 0x00203db0
 *   @0x13cdcc .word 0xffffd6e4
 *   @0x13cdd0 eoreq r3, r0, r0, lsr #27
 *   @0x13cdd4 .word 0xffffd6e8
 *   @0x13cdd8 mlaeq r0, r0, sp, r3
 *   @0x13cddc .word 0xffffd6ec
 *   @0x13cde0 eoreq r3, r0, r0, lsl #27
 *   @0x13cde4 .word 0xffffd6f0
 *   @0x13cde8 eoreq r3, r0, r8, ror sp
 *   @0x13cdec .word 0xffffd6f4
 *   @0x13cdf0 eoreq r3, r0, r0, ror sp
 *   @0x13cdf4 .word 0xffffd6f8
 *   @0x13cdf8 eoreq r3, r0, r8, ror #26
 *   @0x13cdfc .word 0xffffd6fc
 *   @0x13ce00 eoreq r3, r0, r12, asr sp
 *   @0x13ce04 .word 0xffffd700
 *   @0x13ce08 eoreq r3, r0, r0, asr sp
 *   @0x13ce0c .word 0xffffd704
 *   @0x13ce10 eoreq r3, r0, r4, asr #26
 *   @0x13ce14 .word 0xffffd708
 *   @0x13ce18 eoreq r3, r0, r8, lsr sp
 *   @0x13ce1c .word 0xffffd70c
 *   @0x13ce20 eoreq r3, r0, r12, lsr #26
 *   @0x13ce24 .word 0xffffd710
 *   @0x13ce28 eoreq r3, r0, r0, lsr #26
 *   @0x13ce2c .word 0xffffd714
 *   @0x13ce30 eoreq r3, r0, r4, lsl sp
 *   @0x13ce34 .word 0xffffd718
 *   @0x13ce38 eoreq r3, r0, r8, lsl #26
 *   @0x13ce3c .word 0xffffd71c
 *   @0x13ce40 .word 0x00203cfc
 *   @0x13ce44 .word 0xffffd720
 *   @0x13ce48 .word 0x00203cf4
 *   @0x13ce4c .word 0xffffd724
 *   @0x13ce50 eoreq r3, r0, r8, ror #25
 *   @0x13ce54 .word 0xffffd728
 *   @0x13ce58 .word 0x00203cdc
 *   @0x13ce5c .word 0xffffd72c
 *   @0x13ce60 .word 0x00203cd0
 *   @0x13ce64 .word 0xffffd730
 *   @0x13ce68 eoreq r3, r0, r8, asr #25
 *   @0x13ce6c .word 0xffffd734
 *   @0x13ce70 eoreq r3, r0, r8, asr #25
 *   @0x13ce74 .word 0xffffd738
 *   @0x13ce78 eoreq r3, r0, r4, asr #25
 *   @0x13ce7c .word 0xffffd73c
 *   @0x13ce80 .word 0x00203cb4
 *   @0x13ce84 .word 0xffffd740
 *   @0x13ce88 eoreq r3, r0, r4, lsr #25
 *   @0x13ce8c .word 0xffffd744
 *   @0x13ce90 mlaeq r0, r8, r12, r3
 *   @0x13ce94 .word 0xffffd748
 *   @0x13ce98 eoreq r3, r0, r12, lsl #25
 *   @0x13ce9c .word 0xffffd74c
 *   @0x13cea0 eoreq r3, r0, r4, lsl #25
 *   @0x13cea4 .word 0xffffd750
 *   @0x13cea8 eoreq r3, r0, r8, ror r12
 *   @0x13ceac .word 0xffffd754
 *   @0x13ceb0 eoreq r3, r0, r12, ror #24
 *   @0x13ceb4 .word 0xffffd758
 *   @0x13ceb8 eoreq r3, r0, r4, ror #24
 *   @0x13cebc .word 0xffffd75c
 *   @0x13cec0 eoreq r3, r0, r8, asr r12
 *   @0x13cec4 .word 0xffffd760
 *   @0x13cec8 eoreq r3, r0, r0, asr r12
 *   @0x13cecc .word 0xffffd764
 *   @0x13ced0 eoreq r3, r0, r8, asr #24
 *   @0x13ced4 .word 0xffffd768
 *   @0x13ced8 eoreq r3, r0, r8, lsr r12
 *   @0x13cedc .word 0xffffd76c
 *   @0x13cee0 eoreq r3, r0, r12, lsr #24
 *   @0x13cee4 .word 0xffffd770
 *   @0x13cee8 eoreq r3, r0, r0, lsr #24
 *   @0x13ceec .word 0xffffd774
 *   @0x13cef0 eoreq r3, r0, r0, lsl r12
 *   @0x13cef4 .word 0xffffd778
 *   @0x13cef8 eoreq r3, r0, r0, lsl #24
 *   @0x13cefc .word 0xffffd77c
 *   @0x13cf00 .word 0x00203bf0
 */
