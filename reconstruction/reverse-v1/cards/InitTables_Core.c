/* cally 逆向卡：InitTables_Core —— Init*Functions 的 GML 内建注册表（原版 libyoyo.so，armv7）
 * 本卡 4 节，逐节一个 @func；锚点来自 asm/instructions.jsonl（census），
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
 * 本卡节: §1 InitGMLFunctions 0x2a297c→0 条｜§2 InitDataStructuresFunctions 0x10057c→130 条｜§3 InitMathFunctions 0x111c5c→117 条｜§4 InitMiscFunctions 0x118720→96 条
 *
 * ══ §1/4 InitGMLFunctions  0x2a297c..0x2a2c28  size 684  171 条（150 条指令 + 21 个池字）══
 * @func 0x2a297c 0x2a2c28  size 684  171 条
 * 本函数不注册任何内建函数：它是 init 派发器（逐条 bl 下面列出的 Init*），注册全部由被调方完成。
 * 表: asm/init-tables/init-InitGMLFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: 无（本函数每条注册的四实参全部解出，控制流全部走到）
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a297c ldr r3, [pc, #0x250]
 *   @0x2a2980 push {r4, lr}
 *   @0x2a2984 ldr r3, [pc, r3]
 *   @0x2a2988 ldr r1, [pc, #0x248]
 *   @0x2a298c ldr r4, [r3]
 *   @0x2a2990 add r1, pc, r1
 *   @0x2a2994 ldr r3, [r4]
 *   @0x2a2998 mov r0, r4
 *   @0x2a299c ldr r3, [r3, #0xc]
 *   @0x2a29a0 blx r3
 *   @0x2a29a4 bl 0x1dc600 <_Z18HighScore_InitLoadv>   —— 调用 HighScore_InitLoad()
 *   @0x2a29a8 ldr r3, [r4]
 *   @0x2a29ac ldr r1, [pc, #0x228]
 *   @0x2a29b0 mov r0, r4
 *   @0x2a29b4 add r1, pc, r1
 *   @0x2a29b8 ldr r3, [r3, #0xc]
 *   @0x2a29bc blx r3
 *   @0x2a29c0 bl 0x10c7d8 <_Z17InitGameFunctionsv>   —— 调用 InitGameFunctions()
 *   @0x2a29c4 ldr r3, [r4]
 *   @0x2a29c8 ldr r1, [pc, #0x210]
 *   @0x2a29cc mov r0, r4
 *   @0x2a29d0 add r1, pc, r1
 *   @0x2a29d4 ldr r3, [r3, #0xc]
 *   @0x2a29d8 blx r3
 *   @0x2a29dc bl 0x111c5c <_Z17InitMathFunctionsv>   —— 调用 InitMathFunctions()
 *   @0x2a29e0 ldr r3, [r4]
 *   @0x2a29e4 ldr r1, [pc, #0x1f8]
 *   @0x2a29e8 mov r0, r4
 *   @0x2a29ec add r1, pc, r1
 *   @0x2a29f0 ldr r3, [r3, #0xc]
 *   @0x2a29f4 blx r3
 *   @0x2a29f8 bl 0x12326c <_Z20InitGraphicFunctionsv>   —— 调用 InitGraphicFunctions()
 *   @0x2a29fc ldr r3, [r4]
 *   @0x2a2a00 ldr r1, [pc, #0x1e0]
 *   @0x2a2a04 mov r0, r4
 *   @0x2a2a08 add r1, pc, r1
 *   @0x2a2a0c ldr r3, [r3, #0xc]
 *   @0x2a2a10 blx r3
 *   @0x2a2a14 bl 0x141e60 <_Z19InitActionFunctionsv>   —— 调用 InitActionFunctions()
 *   @0x2a2a18 ldr r3, [r4]
 *   @0x2a2a1c ldr r1, [pc, #0x1c8]
 *   @0x2a2a20 mov r0, r4
 *   @0x2a2a24 add r1, pc, r1
 *   @0x2a2a28 ldr r3, [r3, #0xc]
 *   @0x2a2a2c blx r3
 *   @0x2a2a30 bl 0x13c4a0 <_Z17InitFileFunctionsv>   —— 调用 InitFileFunctions()
 *   @0x2a2a34 ldr r3, [r4]
 *   @0x2a2a38 ldr r1, [pc, #0x1b0]
 *   @0x2a2a3c mov r0, r4
 *   @0x2a2a40 add r1, pc, r1
 *   @0x2a2a44 ldr r3, [r3, #0xc]
 *   @0x2a2a48 blx r3
 *   @0x2a2a4c bl 0x130ffc <_Z21InitResourceFunctionsv>   —— 调用 InitResourceFunctions()
 *   @0x2a2a50 ldr r3, [r4]
 *   @0x2a2a54 ldr r1, [pc, #0x198]
 *   @0x2a2a58 mov r0, r4
 *   @0x2a2a5c add r1, pc, r1
 *   @0x2a2a60 ldr r3, [r3, #0xc]
 *   @0x2a2a64 blx r3
 *   @0x2a2a68 bl 0x1278c4 <_Z24InitInteractionFunctionsv>   —— 调用 InitInteractionFunctions()
 *   @0x2a2a6c ldr r3, [r4]
 *   @0x2a2a70 ldr r1, [pc, #0x180]
 *   @0x2a2a74 mov r0, r4
 *   @0x2a2a78 add r1, pc, r1
 *   @0x2a2a7c ldr r3, [r3, #0xc]
 *   @0x2a2a80 blx r3
 *   @0x2a2a84 bl 0x149f4c <_Z15Init3DFunctionsv>   —— 调用 Init3DFunctions()
 *   @0x2a2a88 ldr r3, [r4]
 *   @0x2a2a8c ldr r1, [pc, #0x168]
 *   @0x2a2a90 mov r0, r4
 *   @0x2a2a94 add r1, pc, r1
 *   @0x2a2a98 ldr r3, [r3, #0xc]
 *   @0x2a2a9c blx r3
 *   @0x2a2aa0 bl 0x129f74 <_Z22InitParticlesFunctionsv>   —— 调用 InitParticlesFunctions()
 *   @0x2a2aa4 ldr r3, [r4]
 *   @0x2a2aa8 ldr r1, [pc, #0x150]
 *   @0x2a2aac mov r0, r4
 *   @0x2a2ab0 add r1, pc, r1
 *   @0x2a2ab4 ldr r3, [r3, #0xc]
 *   @0x2a2ab8 blx r3
 *   @0x2a2abc bl 0x118720 <_Z17InitMiscFunctionsv>   —— 调用 InitMiscFunctions()
 *   @0x2a2ac0 ldr r3, [r4]
 *   @0x2a2ac4 ldr r1, [pc, #0x138]
 *   @0x2a2ac8 mov r0, r4
 *   @0x2a2acc add r1, pc, r1
 *   @0x2a2ad0 ldr r3, [r3, #0xc]
 *   @0x2a2ad4 blx r3
 *   @0x2a2ad8 bl 0x10057c <_Z27InitDataStructuresFunctionsv>   —— 调用 InitDataStructuresFunctions()
 *   @0x2a2adc ldr r3, [r4]
 *   @0x2a2ae0 ldr r1, [pc, #0x120]
 *   @0x2a2ae4 mov r0, r4
 *   @0x2a2ae8 add r1, pc, r1
 *   @0x2a2aec ldr r3, [r3, #0xc]
 *   @0x2a2af0 blx r3
 *   @0x2a2af4 bl 0x13672c <_Z18InitSoundFunctionsv>   —— 调用 InitSoundFunctions()
 *   @0x2a2af8 ldr r3, [r4]
 *   @0x2a2afc ldr r1, [pc, #0x108]
 *   @0x2a2b00 mov r0, r4
 *   @0x2a2b04 add r1, pc, r1
 *   @0x2a2b08 ldr r3, [r3, #0xc]
 *   @0x2a2b0c blx r3
 *   @0x2a2b10 bl 0x150434 <InitPhysicsFunctions>   —— 调用 InitPhysicsFunctions
 *   @0x2a2b14 ldr r3, [r4]
 *   @0x2a2b18 ldr r1, [pc, #0xf0]
 *   @0x2a2b1c mov r0, r4
 *   @0x2a2b20 add r1, pc, r1
 *   @0x2a2b24 ldr r3, [r3, #0xc]
 *   @0x2a2b28 blx r3
 *   @0x2a2b2c bl 0x152c9c <_Z20InitGamepadFunctionsv>   —— 调用 InitGamepadFunctions()
 *   @0x2a2b30 ldr r3, [r4]
 *   @0x2a2b34 ldr r1, [pc, #0xd8]
 *   @0x2a2b38 mov r0, r4
 *   @0x2a2b3c add r1, pc, r1
 *   @0x2a2b40 ldr r3, [r3, #0xc]
 *   @0x2a2b44 blx r3
 *   @0x2a2b48 bl 0xc75fc <_Z19InitBufferFunctionsv>   —— 调用 InitBufferFunctions()
 *   @0x2a2b4c bl 0xca9a0 <_Z25InitBufferVertexFunctionsv>   —— 调用 InitBufferVertexFunctions()
 *   @0x2a2b50 ldr r3, [r4]
 *   @0x2a2b54 ldr r1, [pc, #0xbc]
 *   @0x2a2b58 mov r0, r4
 *   @0x2a2b5c add r1, pc, r1
 *   @0x2a2b60 ldr r3, [r3, #0xc]
 *   @0x2a2b64 blx r3
 *   @0x2a2b68 bl 0x299684 <_Z23InitNetworkingFunctionsv>   —— 调用 InitNetworkingFunctions()
 *   @0x2a2b6c ldr r3, [r4]
 *   @0x2a2b70 ldr r1, [pc, #0xa4]
 *   @0x2a2b74 mov r0, r4
 *   @0x2a2b78 add r1, pc, r1
 *   @0x2a2b7c ldr r3, [r3, #0xc]
 *   @0x2a2b80 blx r3
 *   @0x2a2b84 bl 0x1e2184 <_Z19InitShaderFunctionsv>   —— 调用 InitShaderFunctions()
 *   @0x2a2b88 bl 0x1e2fe8 <_Z17InitVertexFormatsv>   —— 调用 InitVertexFormats()
 *   @0x2a2b8c bl 0x16258c <_Z18InitSteamFunctionsv>   —— 调用 InitSteamFunctions()
 *   @0x2a2b90 bl 0x155ea0 <_Z17InitPushFunctionsv>   —— 调用 InitPushFunctions()
 *   @0x2a2b94 ldr r3, [r4]
 *   @0x2a2b98 ldr r1, [pc, #0x80]
 *   @0x2a2b9c mov r0, r4
 *   @0x2a2ba0 add r1, pc, r1
 *   @0x2a2ba4 ldr r3, [r3, #0xc]
 *   @0x2a2ba8 blx r3
 *   @0x2a2bac bl 0x15a0d0 <_Z17InitYoYoFunctionsv>   —— 调用 InitYoYoFunctions()
 *   @0x2a2bb0 bl 0x128b58 <_Z18InitMetroFunctionsv>   —— 调用 InitMetroFunctions()
 *   @0x2a2bb4 bl 0x1c1540 <_ZN13CLayerManager18InitLayerFunctionsEv>   —— 调用 CLayerManager::InitLayerFunctions()
 *   @0x2a2bb8 ldr r3, [r4]
 *   @0x2a2bbc ldr r1, [pc, #0x60]
 *   @0x2a2bc0 mov r0, r4
 *   @0x2a2bc4 add r1, pc, r1
 *   @0x2a2bc8 ldr r3, [r3, #0xc]
 *   @0x2a2bcc blx r3
 *   @0x2a2bd0 pop {r4, pc}
 *   @0x2a2bd4 mulseq r4, r8, r1
 *   @0x2a2bd8 andeq r7, r11, r4, lsl r10
 *   @0x2a2bdc strdeq r7, r8, [r11], -r12
 *   @0x2a2be0 andeq r7, r11, r8, ror #19
 *   @0x2a2be4 ldrdeq r7, r8, [r11], -r4
 *   @0x2a2be8 andeq r7, r11, r4, asr #19
 *   @0x2a2bec strheq r7, [r11], -r4
 *   @0x2a2bf0 andeq r7, r11, r0, lsr #19
 *   @0x2a2bf4 muleq r11, r0, r9
 *   @0x2a2bf8 andeq r7, r11, r4, lsl #19
 *   @0x2a2bfc andeq r7, r11, r0, ror r9
 *   @0x2a2c00 andeq r7, r11, r0, ror #18
 *   @0x2a2c04 andeq r7, r11, r12, asr #18
 *   @0x2a2c08 andeq r7, r11, r8, lsr r9
 *   @0x2a2c0c andeq r7, r11, r4, lsr #18
 *   @0x2a2c10 andeq r7, r11, r4, lsl r9
 *   @0x2a2c14 andeq r7, r11, r4, lsl #18
 *   @0x2a2c18 strdeq r7, r8, [r11], -r0
 *   @0x2a2c1c andeq r7, r11, r4, ror #17
 *   @0x2a2c20 andeq r7, r11, r8, asr #17
 *   @0x2a2c24 andeq r7, r11, r12, lsr #17
 *
 * ══ §2/4 InitDataStructuresFunctions  0x10057c..0x1017d8  size 4700  1175 条（914 条指令 + 261 个池字）══
 * @func 0x10057c 0x1017d8  size 4700  1175 条
 * 注册 130 条｜唯一名 130｜唯一函数指针 130｜argc -1:3 0:5 1:45 2:30 3:19 4:9 5:10 6:6 8:3｜flag 1:130
 * 首条 #0 ds_set_precision（0x1005a0）→ 末条 #129 ds_grid_sort（0x1013c0）
 * 名字族（前 8）: ds×130
 * 游戏实际调用的 99 个内建里落在本表: 5 个（ds_map_create, ds_map_destroy, ds_map_find_value, ds_map_replace, ds_map_secure_save）
 * 表: asm/init-tables/init-InitDataStructuresFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: 无（本函数每条注册的四实参全部解出，控制流全部走到）
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10057c push {r4, lr}
 *   @0x100580 mov r2, #1
 *   @0x100584 ldr r4, [pc, #0xe38]
 *   @0x100588 mov r3, r2
 *   @0x10058c ldr r1, [pc, #0xe34]
 *   @0x100590 add r4, pc, r4
 *   @0x100594 ldr r0, [pc, #0xe30]
 *   @0x100598 ldr r1, [r4, r1]
 *   @0x10059c add r0, pc, r0
 *   @0x1005a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 ds_set_precision → F_DsSetPrecision(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1005a4 ldr r1, [pc, #0xe24]
 *   @0x1005a8 ldr r0, [pc, #0xe24]
 *   @0x1005ac mov r2, #2
 *   @0x1005b0 mov r3, #1
 *   @0x1005b4 ldr r1, [r4, r1]
 *   @0x1005b8 add r0, pc, r0
 *   @0x1005bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 ds_exists → F_DsExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1005c0 ldr r1, [pc, #0xe10]
 *   @0x1005c4 ldr r0, [pc, #0xe10]
 *   @0x1005c8 mov r2, #0
 *   @0x1005cc mov r3, #1
 *   @0x1005d0 ldr r1, [r4, r1]
 *   @0x1005d4 add r0, pc, r0
 *   @0x1005d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 ds_stack_create → F_DsStackCreate(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x1005dc ldr r1, [pc, #0xdfc]
 *   @0x1005e0 ldr r0, [pc, #0xdfc]
 *   @0x1005e4 mov r2, #1
 *   @0x1005e8 mov r3, r2
 *   @0x1005ec ldr r1, [r4, r1]
 *   @0x1005f0 add r0, pc, r0
 *   @0x1005f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 ds_stack_destroy → F_DsStackDestroy(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1005f8 ldr r1, [pc, #0xde8]
 *   @0x1005fc ldr r0, [pc, #0xde8]
 *   @0x100600 mov r2, #1
 *   @0x100604 mov r3, r2
 *   @0x100608 ldr r1, [r4, r1]
 *   @0x10060c add r0, pc, r0
 *   @0x100610 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #4 ds_stack_clear → F_DsStackClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100614 ldr r1, [pc, #0xdd4]
 *   @0x100618 ldr r0, [pc, #0xdd4]
 *   @0x10061c mov r2, #2
 *   @0x100620 mov r3, #1
 *   @0x100624 ldr r1, [r4, r1]
 *   @0x100628 add r0, pc, r0
 *   @0x10062c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #5 ds_stack_copy → F_DsStackCopy(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x100630 ldr r1, [pc, #0xdc0]
 *   @0x100634 ldr r0, [pc, #0xdc0]
 *   @0x100638 mov r2, #1
 *   @0x10063c mov r3, r2
 *   @0x100640 ldr r1, [r4, r1]
 *   @0x100644 add r0, pc, r0
 *   @0x100648 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #6 ds_stack_size → F_DsStackSize(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x10064c ldr r1, [pc, #0xdac]
 *   @0x100650 ldr r0, [pc, #0xdac]
 *   @0x100654 mov r2, #1
 *   @0x100658 mov r3, r2
 *   @0x10065c ldr r1, [r4, r1]
 *   @0x100660 add r0, pc, r0
 *   @0x100664 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #7 ds_stack_empty → F_DsStackEmpty(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100668 ldr r1, [pc, #0xd98]
 *   @0x10066c ldr r0, [pc, #0xd98]
 *   @0x100670 mvn r2, #0
 *   @0x100674 mov r3, #1
 *   @0x100678 ldr r1, [r4, r1]
 *   @0x10067c add r0, pc, r0
 *   @0x100680 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #8 ds_stack_push → F_DsStackPush(RValue&, CInstance*, CInstance*, int, RValue*) argc=-1 flag=1
 *   @0x100684 ldr r1, [pc, #0xd84]
 *   @0x100688 ldr r0, [pc, #0xd84]
 *   @0x10068c mov r2, #1
 *   @0x100690 mov r3, r2
 *   @0x100694 ldr r1, [r4, r1]
 *   @0x100698 add r0, pc, r0
 *   @0x10069c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #9 ds_stack_pop → F_DsStackPop(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1006a0 ldr r1, [pc, #0xd70]
 *   @0x1006a4 ldr r0, [pc, #0xd70]
 *   @0x1006a8 mov r2, #1
 *   @0x1006ac mov r3, r2
 *   @0x1006b0 ldr r1, [r4, r1]
 *   @0x1006b4 add r0, pc, r0
 *   @0x1006b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #10 ds_stack_top → F_DsStackTop(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1006bc ldr r1, [pc, #0xd5c]
 *   @0x1006c0 ldr r0, [pc, #0xd5c]
 *   @0x1006c4 mov r2, #1
 *   @0x1006c8 mov r3, r2
 *   @0x1006cc ldr r1, [r4, r1]
 *   @0x1006d0 add r0, pc, r0
 *   @0x1006d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #11 ds_stack_write → F_DsStackWrite(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1006d8 ldr r1, [pc, #0xd48]
 *   @0x1006dc ldr r0, [pc, #0xd48]
 *   @0x1006e0 mov r2, #2
 *   @0x1006e4 mov r3, #1
 *   @0x1006e8 ldr r1, [r4, r1]
 *   @0x1006ec add r0, pc, r0
 *   @0x1006f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #12 ds_stack_read → F_DsStackRead(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1006f4 ldr r1, [pc, #0xd34]
 *   @0x1006f8 ldr r0, [pc, #0xd34]
 *   @0x1006fc mov r2, #0
 *   @0x100700 mov r3, #1
 *   @0x100704 ldr r1, [r4, r1]
 *   @0x100708 add r0, pc, r0
 *   @0x10070c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #13 ds_queue_create → F_DsQueueCreate(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x100710 ldr r1, [pc, #0xd20]
 *   @0x100714 ldr r0, [pc, #0xd20]
 *   @0x100718 mov r2, #1
 *   @0x10071c mov r3, r2
 *   @0x100720 ldr r1, [r4, r1]
 *   @0x100724 add r0, pc, r0
 *   @0x100728 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #14 ds_queue_destroy → F_DsQueueDestroy(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x10072c ldr r1, [pc, #0xd0c]
 *   @0x100730 ldr r0, [pc, #0xd0c]
 *   @0x100734 mov r2, #1
 *   @0x100738 mov r3, r2
 *   @0x10073c ldr r1, [r4, r1]
 *   @0x100740 add r0, pc, r0
 *   @0x100744 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #15 ds_queue_clear → F_DsQueueClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100748 ldr r1, [pc, #0xcf8]
 *   @0x10074c ldr r0, [pc, #0xcf8]
 *   @0x100750 mov r2, #2
 *   @0x100754 mov r3, #1
 *   @0x100758 ldr r1, [r4, r1]
 *   @0x10075c add r0, pc, r0
 *   @0x100760 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #16 ds_queue_copy → F_DsQueueCopy(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x100764 ldr r1, [pc, #0xce4]
 *   @0x100768 ldr r0, [pc, #0xce4]
 *   @0x10076c mov r2, #1
 *   @0x100770 mov r3, r2
 *   @0x100774 ldr r1, [r4, r1]
 *   @0x100778 add r0, pc, r0
 *   @0x10077c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #17 ds_queue_size → F_DsQueueSize(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100780 ldr r1, [pc, #0xcd0]
 *   @0x100784 ldr r0, [pc, #0xcd0]
 *   @0x100788 mov r2, #1
 *   @0x10078c mov r3, r2
 *   @0x100790 ldr r1, [r4, r1]
 *   @0x100794 add r0, pc, r0
 *   @0x100798 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #18 ds_queue_empty → F_DsQueueEmpty(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x10079c ldr r1, [pc, #0xcbc]
 *   @0x1007a0 ldr r0, [pc, #0xcbc]
 *   @0x1007a4 mvn r2, #0
 *   @0x1007a8 mov r3, #1
 *   @0x1007ac ldr r1, [r4, r1]
 *   @0x1007b0 add r0, pc, r0
 *   @0x1007b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #19 ds_queue_enqueue → F_DsQueueEnqueue(RValue&, CInstance*, CInstance*, int, RValue*) argc=-1 flag=1
 *   @0x1007b8 ldr r1, [pc, #0xca8]
 *   @0x1007bc ldr r0, [pc, #0xca8]
 *   @0x1007c0 mov r2, #1
 *   @0x1007c4 mov r3, r2
 *   @0x1007c8 ldr r1, [r4, r1]
 *   @0x1007cc add r0, pc, r0
 *   @0x1007d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #20 ds_queue_dequeue → F_DsQueueDequeue(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1007d4 ldr r1, [pc, #0xc94]
 *   @0x1007d8 ldr r0, [pc, #0xc94]
 *   @0x1007dc mov r2, #1
 *   @0x1007e0 mov r3, r2
 *   @0x1007e4 ldr r1, [r4, r1]
 *   @0x1007e8 add r0, pc, r0
 *   @0x1007ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #21 ds_queue_head → F_DsQueueHead(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1007f0 ldr r1, [pc, #0xc80]
 *   @0x1007f4 ldr r0, [pc, #0xc80]
 *   @0x1007f8 mov r2, #1
 *   @0x1007fc mov r3, r2
 *   @0x100800 ldr r1, [r4, r1]
 *   @0x100804 add r0, pc, r0
 *   @0x100808 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #22 ds_queue_tail → F_DsQueueTail(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x10080c ldr r1, [pc, #0xc6c]
 *   @0x100810 ldr r0, [pc, #0xc6c]
 *   @0x100814 mov r2, #1
 *   @0x100818 mov r3, r2
 *   @0x10081c ldr r1, [r4, r1]
 *   @0x100820 add r0, pc, r0
 *   @0x100824 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #23 ds_queue_write → F_DsQueueWrite(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100828 ldr r1, [pc, #0xc58]
 *   @0x10082c ldr r0, [pc, #0xc58]
 *   @0x100830 mov r2, #2
 *   @0x100834 mov r3, #1
 *   @0x100838 ldr r1, [r4, r1]
 *   @0x10083c add r0, pc, r0
 *   @0x100840 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #24 ds_queue_read → F_DsQueueRead(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x100844 ldr r1, [pc, #0xc44]
 *   @0x100848 ldr r0, [pc, #0xc44]
 *   @0x10084c mov r2, #0
 *   @0x100850 mov r3, #1
 *   @0x100854 ldr r1, [r4, r1]
 *   @0x100858 add r0, pc, r0
 *   @0x10085c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #25 ds_list_create → F_DsListCreate(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x100860 ldr r1, [pc, #0xc30]
 *   @0x100864 ldr r0, [pc, #0xc30]
 *   @0x100868 mov r2, #1
 *   @0x10086c mov r3, r2
 *   @0x100870 ldr r1, [r4, r1]
 *   @0x100874 add r0, pc, r0
 *   @0x100878 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #26 ds_list_destroy → F_DsListDestroy(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x10087c ldr r1, [pc, #0xc1c]
 *   @0x100880 ldr r0, [pc, #0xc1c]
 *   @0x100884 mov r2, #1
 *   @0x100888 mov r3, r2
 *   @0x10088c ldr r1, [r4, r1]
 *   @0x100890 add r0, pc, r0
 *   @0x100894 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #27 ds_list_clear → F_DsListClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100898 ldr r1, [pc, #0xc08]
 *   @0x10089c ldr r0, [pc, #0xc08]
 *   @0x1008a0 mov r2, #2
 *   @0x1008a4 mov r3, #1
 *   @0x1008a8 ldr r1, [r4, r1]
 *   @0x1008ac add r0, pc, r0
 *   @0x1008b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #28 ds_list_copy → F_DsListCopy(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1008b4 ldr r1, [pc, #0xbf4]
 *   @0x1008b8 ldr r0, [pc, #0xbf4]
 *   @0x1008bc mov r2, #1
 *   @0x1008c0 mov r3, r2
 *   @0x1008c4 ldr r1, [r4, r1]
 *   @0x1008c8 add r0, pc, r0
 *   @0x1008cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #29 ds_list_size → F_DsListSize(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1008d0 ldr r1, [pc, #0xbe0]
 *   @0x1008d4 ldr r0, [pc, #0xbe0]
 *   @0x1008d8 mov r2, #1
 *   @0x1008dc mov r3, r2
 *   @0x1008e0 ldr r1, [r4, r1]
 *   @0x1008e4 add r0, pc, r0
 *   @0x1008e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #30 ds_list_empty → F_DsListEmpty(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1008ec ldr r1, [pc, #0xbcc]
 *   @0x1008f0 ldr r0, [pc, #0xbcc]
 *   @0x1008f4 mvn r2, #0
 *   @0x1008f8 mov r3, #1
 *   @0x1008fc ldr r1, [r4, r1]
 *   @0x100900 add r0, pc, r0
 *   @0x100904 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #31 ds_list_add → F_DsListAdd(RValue&, CInstance*, CInstance*, int, RValue*) argc=-1 flag=1
 *   @0x100908 ldr r1, [pc, #0xbb8]
 *   @0x10090c ldr r0, [pc, #0xbb8]
 *   @0x100910 mov r2, #3
 *   @0x100914 mov r3, #1
 *   @0x100918 ldr r1, [r4, r1]
 *   @0x10091c add r0, pc, r0
 *   @0x100920 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #32 ds_list_insert → F_DsListInsert(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x100924 ldr r1, [pc, #0xba4]
 *   @0x100928 ldr r0, [pc, #0xba4]
 *   @0x10092c mov r2, #3
 *   @0x100930 mov r3, #1
 *   @0x100934 ldr r1, [r4, r1]
 *   @0x100938 add r0, pc, r0
 *   @0x10093c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #33 ds_list_replace → F_DsListReplace(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x100940 ldr r1, [pc, #0xb90]
 *   @0x100944 ldr r0, [pc, #0xb90]
 *   @0x100948 mov r2, #2
 *   @0x10094c mov r3, #1
 *   @0x100950 ldr r1, [r4, r1]
 *   @0x100954 add r0, pc, r0
 *   @0x100958 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #34 ds_list_delete → F_DsListDelete(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x10095c ldr r1, [pc, #0xb7c]
 *   @0x100960 ldr r0, [pc, #0xb7c]
 *   @0x100964 mov r2, #2
 *   @0x100968 mov r3, #1
 *   @0x10096c ldr r1, [r4, r1]
 *   @0x100970 add r0, pc, r0
 *   @0x100974 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #35 ds_list_find_index → F_DsListFindIndex(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x100978 ldr r1, [pc, #0xb68]
 *   @0x10097c ldr r0, [pc, #0xb68]
 *   @0x100980 mov r2, #2
 *   @0x100984 mov r3, #1
 *   @0x100988 ldr r1, [r4, r1]
 *   @0x10098c add r0, pc, r0
 *   @0x100990 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #36 ds_list_find_value → F_DsListFindValue(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x100994 ldr r1, [pc, #0xb54]
 *   @0x100998 ldr r0, [pc, #0xb54]
 *   @0x10099c mov r2, #2
 *   @0x1009a0 mov r3, #1
 *   @0x1009a4 ldr r1, [r4, r1]
 *   @0x1009a8 add r0, pc, r0
 *   @0x1009ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #37 ds_list_mark_as_list → F_DsListMarkAsList(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1009b0 ldr r1, [pc, #0xb40]
 *   @0x1009b4 ldr r0, [pc, #0xb40]
 *   @0x1009b8 mov r2, #2
 *   @0x1009bc mov r3, #1
 *   @0x1009c0 ldr r1, [r4, r1]
 *   @0x1009c4 add r0, pc, r0
 *   @0x1009c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #38 ds_list_mark_as_map → F_DsListMarkAsMap(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1009cc ldr r1, [pc, #0xb2c]
 *   @0x1009d0 ldr r0, [pc, #0xb2c]
 *   @0x1009d4 mov r2, #2
 *   @0x1009d8 mov r3, #1
 *   @0x1009dc ldr r1, [r4, r1]
 *   @0x1009e0 add r0, pc, r0
 *   @0x1009e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #39 ds_list_sort → F_DsListSort(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1009e8 ldr r1, [pc, #0xb18]
 *   @0x1009ec ldr r0, [pc, #0xb18]
 *   @0x1009f0 mov r2, #1
 *   @0x1009f4 mov r3, r2
 *   @0x1009f8 ldr r1, [r4, r1]
 *   @0x1009fc add r0, pc, r0
 *   @0x100a00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #40 ds_list_shuffle → F_DsListShuffle(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100a04 ldr r1, [pc, #0xb04]
 *   @0x100a08 ldr r0, [pc, #0xb04]
 *   @0x100a0c mov r2, #1
 *   @0x100a10 mov r3, r2
 *   @0x100a14 ldr r1, [r4, r1]
 *   @0x100a18 add r0, pc, r0
 *   @0x100a1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #41 ds_list_write → F_DsListWrite(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100a20 ldr r1, [pc, #0xaf0]
 *   @0x100a24 ldr r0, [pc, #0xaf0]
 *   @0x100a28 mov r2, #2
 *   @0x100a2c mov r3, #1
 *   @0x100a30 ldr r1, [r4, r1]
 *   @0x100a34 add r0, pc, r0
 *   @0x100a38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #42 ds_list_read → F_DsListRead(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x100a3c ldr r1, [pc, #0xadc]
 *   @0x100a40 ldr r0, [pc, #0xadc]
 *   @0x100a44 mov r2, #3
 *   @0x100a48 mov r3, #1
 *   @0x100a4c ldr r1, [r4, r1]
 *   @0x100a50 add r0, pc, r0
 *   @0x100a54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #43 ds_list_set → F_DsListSet(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x100a58 ldr r1, [pc, #0xac8]
 *   @0x100a5c ldr r0, [pc, #0xac8]
 *   @0x100a60 mov r2, #3
 *   @0x100a64 mov r3, #1
 *   @0x100a68 ldr r1, [r4, r1]
 *   @0x100a6c add r0, pc, r0
 *   @0x100a70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #44 ds_list_set_post → F_DsListSetPost(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x100a74 ldr r1, [pc, #0xab4]
 *   @0x100a78 ldr r0, [pc, #0xab4]
 *   @0x100a7c mov r2, #3
 *   @0x100a80 mov r3, #1
 *   @0x100a84 ldr r1, [r4, r1]
 *   @0x100a88 add r0, pc, r0
 *   @0x100a8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #45 ds_list_set_pre → F_DsListSetPre(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x100a90 ldr r1, [pc, #0xaa0]
 *   @0x100a94 ldr r0, [pc, #0xaa0]
 *   @0x100a98 mov r2, #0
 *   @0x100a9c mov r3, #1
 *   @0x100aa0 ldr r1, [r4, r1]
 *   @0x100aa4 add r0, pc, r0
 *   @0x100aa8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #46 ds_map_create → F_DsMapCreate(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x100aac ldr r1, [pc, #0xa8c]
 *   @0x100ab0 ldr r0, [pc, #0xa8c]
 *   @0x100ab4 mov r2, #1
 *   @0x100ab8 mov r3, r2
 *   @0x100abc ldr r1, [r4, r1]
 *   @0x100ac0 add r0, pc, r0
 *   @0x100ac4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #47 ds_map_destroy → F_DsMapDestroy(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100ac8 ldr r1, [pc, #0xa78]
 *   @0x100acc ldr r0, [pc, #0xa78]
 *   @0x100ad0 mov r2, #1
 *   @0x100ad4 mov r3, r2
 *   @0x100ad8 ldr r1, [r4, r1]
 *   @0x100adc add r0, pc, r0
 *   @0x100ae0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #48 ds_map_clear → F_DsMapClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100ae4 ldr r1, [pc, #0xa64]
 *   @0x100ae8 ldr r0, [pc, #0xa64]
 *   @0x100aec mov r2, #2
 *   @0x100af0 mov r3, #1
 *   @0x100af4 ldr r1, [r4, r1]
 *   @0x100af8 add r0, pc, r0
 *   @0x100afc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #49 ds_map_copy → F_DsMapCopy(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x100b00 ldr r1, [pc, #0xa50]
 *   @0x100b04 ldr r0, [pc, #0xa50]
 *   @0x100b08 mov r2, #1
 *   @0x100b0c mov r3, r2
 *   @0x100b10 ldr r1, [r4, r1]
 *   @0x100b14 add r0, pc, r0
 *   @0x100b18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #50 ds_map_size → F_DsMapSize(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100b1c ldr r1, [pc, #0xa3c]
 *   @0x100b20 ldr r0, [pc, #0xa3c]
 *   @0x100b24 mov r2, #1
 *   @0x100b28 mov r3, r2
 *   @0x100b2c ldr r1, [r4, r1]
 *   @0x100b30 add r0, pc, r0
 *   @0x100b34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #51 ds_map_empty → F_DsMapEmpty(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100b38 ldr r1, [pc, #0xa28]
 *   @0x100b3c ldr r0, [pc, #0xa28]
 *   @0x100b40 mov r2, #3
 *   @0x100b44 mov r3, #1
 *   @0x100b48 ldr r1, [r4, r1]
 *   @0x100b4c add r0, pc, r0
 *   @0x100b50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #52 ds_map_add → F_DsMapAdd(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x100b54 ldr r1, [pc, #0xa14]
 *   @0x100b58 ldr r0, [pc, #0xa14]
 *   @0x100b5c mov r2, #3
 *   @0x100b60 mov r3, #1
 *   @0x100b64 ldr r1, [r4, r1]
 *   @0x100b68 add r0, pc, r0
 *   @0x100b6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #53 ds_map_set → F_DsMapSet(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x100b70 ldr r1, [pc, #0xa00]
 *   @0x100b74 ldr r0, [pc, #0xa00]
 *   @0x100b78 mov r2, #3
 *   @0x100b7c mov r3, #1
 *   @0x100b80 ldr r1, [r4, r1]
 *   @0x100b84 add r0, pc, r0
 *   @0x100b88 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #54 ds_map_set_pre → F_DsMapSetPre(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x100b8c ldr r1, [pc, #0x9ec]
 *   @0x100b90 ldr r0, [pc, #0x9ec]
 *   @0x100b94 mov r2, #3
 *   @0x100b98 mov r3, #1
 *   @0x100b9c ldr r1, [r4, r1]
 *   @0x100ba0 add r0, pc, r0
 *   @0x100ba4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #55 ds_map_set_post → F_DsMapSetPost(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x100ba8 ldr r1, [pc, #0x9d8]
 *   @0x100bac ldr r0, [pc, #0x9d8]
 *   @0x100bb0 mov r2, #3
 *   @0x100bb4 mov r3, #1
 *   @0x100bb8 ldr r1, [r4, r1]
 *   @0x100bbc add r0, pc, r0
 *   @0x100bc0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #56 ds_map_add_list → F_DsMapAddList(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x100bc4 ldr r1, [pc, #0x9c4]
 *   @0x100bc8 ldr r0, [pc, #0x9c4]
 *   @0x100bcc mov r2, #3
 *   @0x100bd0 mov r3, #1
 *   @0x100bd4 ldr r1, [r4, r1]
 *   @0x100bd8 add r0, pc, r0
 *   @0x100bdc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #57 ds_map_add_map → F_DsMapAddMap(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x100be0 ldr r1, [pc, #0x9b0]
 *   @0x100be4 ldr r0, [pc, #0x9b0]
 *   @0x100be8 mov r2, #3
 *   @0x100bec mov r3, #1
 *   @0x100bf0 ldr r1, [r4, r1]
 *   @0x100bf4 add r0, pc, r0
 *   @0x100bf8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #58 ds_map_replace → F_DsMapReplace(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x100bfc ldr r1, [pc, #0x99c]
 *   @0x100c00 ldr r0, [pc, #0x99c]
 *   @0x100c04 mov r2, #3
 *   @0x100c08 mov r3, #1
 *   @0x100c0c ldr r1, [r4, r1]
 *   @0x100c10 add r0, pc, r0
 *   @0x100c14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #59 ds_map_replace_list → F_DsMapReplaceList(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x100c18 ldr r1, [pc, #0x988]
 *   @0x100c1c ldr r0, [pc, #0x988]
 *   @0x100c20 mov r2, #3
 *   @0x100c24 mov r3, #1
 *   @0x100c28 ldr r1, [r4, r1]
 *   @0x100c2c add r0, pc, r0
 *   @0x100c30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #60 ds_map_replace_map → F_DsMapReplaceMap(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x100c34 ldr r1, [pc, #0x974]
 *   @0x100c38 ldr r0, [pc, #0x974]
 *   @0x100c3c mov r2, #2
 *   @0x100c40 mov r3, #1
 *   @0x100c44 ldr r1, [r4, r1]
 *   @0x100c48 add r0, pc, r0
 *   @0x100c4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #61 ds_map_delete → F_DsMapDelete(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x100c50 ldr r1, [pc, #0x960]
 *   @0x100c54 ldr r0, [pc, #0x960]
 *   @0x100c58 mov r2, #2
 *   @0x100c5c mov r3, #1
 *   @0x100c60 ldr r1, [r4, r1]
 *   @0x100c64 add r0, pc, r0
 *   @0x100c68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #62 ds_map_exists → F_DsMapExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x100c6c ldr r1, [pc, #0x94c]
 *   @0x100c70 ldr r0, [pc, #0x94c]
 *   @0x100c74 mov r2, #2
 *   @0x100c78 mov r3, #1
 *   @0x100c7c ldr r1, [r4, r1]
 *   @0x100c80 add r0, pc, r0
 *   @0x100c84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #63 ds_map_find_value → F_DsMapFindValue(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x100c88 ldr r1, [pc, #0x938]
 *   @0x100c8c ldr r0, [pc, #0x938]
 *   @0x100c90 mov r2, #2
 *   @0x100c94 mov r3, #1
 *   @0x100c98 ldr r1, [r4, r1]
 *   @0x100c9c add r0, pc, r0
 *   @0x100ca0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #64 ds_map_find_previous → F_DsMapFindPrevious(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x100ca4 ldr r1, [pc, #0x924]
 *   @0x100ca8 ldr r0, [pc, #0x924]
 *   @0x100cac mov r2, #2
 *   @0x100cb0 mov r3, #1
 *   @0x100cb4 ldr r1, [r4, r1]
 *   @0x100cb8 add r0, pc, r0
 *   @0x100cbc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #65 ds_map_find_next → F_DsMapFindNext(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x100cc0 ldr r1, [pc, #0x910]
 *   @0x100cc4 ldr r0, [pc, #0x910]
 *   @0x100cc8 mov r2, #1
 *   @0x100ccc mov r3, r2
 *   @0x100cd0 ldr r1, [r4, r1]
 *   @0x100cd4 add r0, pc, r0
 *   @0x100cd8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #66 ds_map_find_first → F_DsMapFindFirst(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100cdc ldr r1, [pc, #0x8fc]
 *   @0x100ce0 ldr r0, [pc, #0x8fc]
 *   @0x100ce4 mov r2, #1
 *   @0x100ce8 mov r3, r2
 *   @0x100cec ldr r1, [r4, r1]
 *   @0x100cf0 add r0, pc, r0
 *   @0x100cf4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #67 ds_map_find_last → F_DsMapFindLast(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100cf8 ldr r1, [pc, #0x8e8]
 *   @0x100cfc ldr r0, [pc, #0x8e8]
 *   @0x100d00 mov r2, #1
 *   @0x100d04 mov r3, r2
 *   @0x100d08 ldr r1, [r4, r1]
 *   @0x100d0c add r0, pc, r0
 *   @0x100d10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #68 ds_map_write → F_DsMapWrite(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100d14 ldr r1, [pc, #0x8d4]
 *   @0x100d18 ldr r0, [pc, #0x8d4]
 *   @0x100d1c mov r2, #2
 *   @0x100d20 mov r3, #1
 *   @0x100d24 ldr r1, [r4, r1]
 *   @0x100d28 add r0, pc, r0
 *   @0x100d2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #69 ds_map_read → F_DsMapRead(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x100d30 ldr r1, [pc, #0x8c0]
 *   @0x100d34 ldr r0, [pc, #0x8c0]
 *   @0x100d38 mov r2, #2
 *   @0x100d3c mov r3, #1
 *   @0x100d40 ldr r1, [r4, r1]
 *   @0x100d44 add r0, pc, r0
 *   @0x100d48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #70 ds_map_secure_save → F_DsMapSecureSave(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x100d4c ldr r1, [pc, #0x8ac]
 *   @0x100d50 ldr r0, [pc, #0x8ac]
 *   @0x100d54 mov r2, #1
 *   @0x100d58 mov r3, r2
 *   @0x100d5c ldr r1, [r4, r1]
 *   @0x100d60 add r0, pc, r0
 *   @0x100d64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #71 ds_map_secure_load → F_DsMapSecureLoad(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100d68 ldr r1, [pc, #0x898]
 *   @0x100d6c ldr r0, [pc, #0x898]
 *   @0x100d70 mov r2, #1
 *   @0x100d74 mov r3, r2
 *   @0x100d78 ldr r1, [r4, r1]
 *   @0x100d7c add r0, pc, r0
 *   @0x100d80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #72 ds_map_secure_load_buffer → F_DsMapSecureLoadBuffer(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100d84 ldr r1, [pc, #0x884]
 *   @0x100d88 ldr r0, [pc, #0x884]
 *   @0x100d8c mov r2, #2
 *   @0x100d90 mov r3, #1
 *   @0x100d94 ldr r1, [r4, r1]
 *   @0x100d98 add r0, pc, r0
 *   @0x100d9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #73 ds_map_secure_save_buffer → F_DsMapSecureSaveBuffer(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x100da0 ldr r1, [pc, #0x870]
 *   @0x100da4 ldr r0, [pc, #0x870]
 *   @0x100da8 mov r2, #0
 *   @0x100dac mov r3, #1
 *   @0x100db0 ldr r1, [r4, r1]
 *   @0x100db4 add r0, pc, r0
 *   @0x100db8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #74 ds_priority_create → F_DsPriorityCreate(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x100dbc ldr r1, [pc, #0x85c]
 *   @0x100dc0 ldr r0, [pc, #0x85c]
 *   @0x100dc4 mov r2, #1
 *   @0x100dc8 mov r3, r2
 *   @0x100dcc ldr r1, [r4, r1]
 *   @0x100dd0 add r0, pc, r0
 *   @0x100dd4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #75 ds_priority_destroy → F_DsPriorityDestroy(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100dd8 ldr r1, [pc, #0x848]
 *   @0x100ddc ldr r0, [pc, #0x848]
 *   @0x100de0 mov r2, #1
 *   @0x100de4 mov r3, r2
 *   @0x100de8 ldr r1, [r4, r1]
 *   @0x100dec add r0, pc, r0
 *   @0x100df0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #76 ds_priority_clear → F_DsPriorityClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100df4 ldr r1, [pc, #0x834]
 *   @0x100df8 ldr r0, [pc, #0x834]
 *   @0x100dfc mov r2, #2
 *   @0x100e00 mov r3, #1
 *   @0x100e04 ldr r1, [r4, r1]
 *   @0x100e08 add r0, pc, r0
 *   @0x100e0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #77 ds_priority_copy → F_DsPriorityCopy(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x100e10 ldr r1, [pc, #0x820]
 *   @0x100e14 ldr r0, [pc, #0x820]
 *   @0x100e18 mov r2, #1
 *   @0x100e1c mov r3, r2
 *   @0x100e20 ldr r1, [r4, r1]
 *   @0x100e24 add r0, pc, r0
 *   @0x100e28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #78 ds_priority_size → F_DsPrioritySize(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100e2c ldr r1, [pc, #0x80c]
 *   @0x100e30 ldr r0, [pc, #0x80c]
 *   @0x100e34 mov r2, #1
 *   @0x100e38 mov r3, r2
 *   @0x100e3c ldr r1, [r4, r1]
 *   @0x100e40 add r0, pc, r0
 *   @0x100e44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #79 ds_priority_empty → F_DsPriorityEmpty(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100e48 ldr r1, [pc, #0x7f8]
 *   @0x100e4c ldr r0, [pc, #0x7f8]
 *   @0x100e50 mov r2, #3
 *   @0x100e54 mov r3, #1
 *   @0x100e58 ldr r1, [r4, r1]
 *   @0x100e5c add r0, pc, r0
 *   @0x100e60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #80 ds_priority_add → F_DsPriorityAdd(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x100e64 ldr r1, [pc, #0x7e4]
 *   @0x100e68 ldr r0, [pc, #0x7e4]
 *   @0x100e6c mov r2, #3
 *   @0x100e70 mov r3, #1
 *   @0x100e74 ldr r1, [r4, r1]
 *   @0x100e78 add r0, pc, r0
 *   @0x100e7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #81 ds_priority_change_priority → F_DsPriorityChangePriority(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x100e80 ldr r1, [pc, #0x7d0]
 *   @0x100e84 ldr r0, [pc, #0x7d0]
 *   @0x100e88 mov r2, #2
 *   @0x100e8c mov r3, #1
 *   @0x100e90 ldr r1, [r4, r1]
 *   @0x100e94 add r0, pc, r0
 *   @0x100e98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #82 ds_priority_find_priority → F_DsPriorityFindPriority(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x100e9c ldr r1, [pc, #0x7bc]
 *   @0x100ea0 ldr r0, [pc, #0x7bc]
 *   @0x100ea4 mov r2, #2
 *   @0x100ea8 mov r3, #1
 *   @0x100eac ldr r1, [r4, r1]
 *   @0x100eb0 add r0, pc, r0
 *   @0x100eb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #83 ds_priority_delete_value → F_DsPriorityDeleteValue(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x100eb8 ldr r1, [pc, #0x7a8]
 *   @0x100ebc ldr r0, [pc, #0x7a8]
 *   @0x100ec0 mov r2, #1
 *   @0x100ec4 mov r3, r2
 *   @0x100ec8 ldr r1, [r4, r1]
 *   @0x100ecc add r0, pc, r0
 *   @0x100ed0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #84 ds_priority_delete_min → F_DsPriorityDeleteMin(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100ed4 ldr r1, [pc, #0x794]
 *   @0x100ed8 ldr r0, [pc, #0x794]
 *   @0x100edc mov r2, #1
 *   @0x100ee0 mov r3, r2
 *   @0x100ee4 ldr r1, [r4, r1]
 *   @0x100ee8 add r0, pc, r0
 *   @0x100eec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #85 ds_priority_find_min → F_DsPriorityFindMin(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100ef0 ldr r1, [pc, #0x780]
 *   @0x100ef4 ldr r0, [pc, #0x780]
 *   @0x100ef8 mov r2, #1
 *   @0x100efc mov r3, r2
 *   @0x100f00 ldr r1, [r4, r1]
 *   @0x100f04 add r0, pc, r0
 *   @0x100f08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #86 ds_priority_delete_max → F_DsPriorityDeleteMax(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100f0c ldr r1, [pc, #0x76c]
 *   @0x100f10 ldr r0, [pc, #0x76c]
 *   @0x100f14 mov r2, #1
 *   @0x100f18 mov r3, r2
 *   @0x100f1c ldr r1, [r4, r1]
 *   @0x100f20 add r0, pc, r0
 *   @0x100f24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #87 ds_priority_find_max → F_DsPriorityFindMax(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100f28 ldr r1, [pc, #0x758]
 *   @0x100f2c ldr r0, [pc, #0x758]
 *   @0x100f30 mov r2, #1
 *   @0x100f34 mov r3, r2
 *   @0x100f38 ldr r1, [r4, r1]
 *   @0x100f3c add r0, pc, r0
 *   @0x100f40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #88 ds_priority_write → F_DsPriorityWrite(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100f44 ldr r1, [pc, #0x744]
 *   @0x100f48 ldr r0, [pc, #0x744]
 *   @0x100f4c mov r2, #2
 *   @0x100f50 mov r3, #1
 *   @0x100f54 ldr r1, [r4, r1]
 *   @0x100f58 add r0, pc, r0
 *   @0x100f5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #89 ds_priority_read → F_DsPriorityRead(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x100f60 ldr r1, [pc, #0x730]
 *   @0x100f64 ldr r0, [pc, #0x730]
 *   @0x100f68 mov r2, #2
 *   @0x100f6c mov r3, #1
 *   @0x100f70 ldr r1, [r4, r1]
 *   @0x100f74 add r0, pc, r0
 *   @0x100f78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #90 ds_grid_create → F_DsGridCreate(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x100f7c ldr r1, [pc, #0x71c]
 *   @0x100f80 ldr r0, [pc, #0x71c]
 *   @0x100f84 mov r2, #1
 *   @0x100f88 mov r3, r2
 *   @0x100f8c ldr r1, [r4, r1]
 *   @0x100f90 add r0, pc, r0
 *   @0x100f94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #91 ds_grid_destroy → F_DsGridDestroy(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100f98 ldr r1, [pc, #0x708]
 *   @0x100f9c ldr r0, [pc, #0x708]
 *   @0x100fa0 mov r2, #2
 *   @0x100fa4 mov r3, #1
 *   @0x100fa8 ldr r1, [r4, r1]
 *   @0x100fac add r0, pc, r0
 *   @0x100fb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #92 ds_grid_copy → F_DsGridCopy(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x100fb4 ldr r1, [pc, #0x6f4]
 *   @0x100fb8 ldr r0, [pc, #0x6f4]
 *   @0x100fbc mov r2, #3
 *   @0x100fc0 mov r3, #1
 *   @0x100fc4 ldr r1, [r4, r1]
 *   @0x100fc8 add r0, pc, r0
 *   @0x100fcc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #93 ds_grid_resize → F_DsGridResize(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x100fd0 ldr r1, [pc, #0x6e0]
 *   @0x100fd4 ldr r0, [pc, #0x6e0]
 *   @0x100fd8 mov r2, #1
 *   @0x100fdc mov r3, r2
 *   @0x100fe0 ldr r1, [r4, r1]
 *   @0x100fe4 add r0, pc, r0
 *   @0x100fe8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #94 ds_grid_width → F_DsGridWidth(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x100fec ldr r1, [pc, #0x6cc]
 *   @0x100ff0 ldr r0, [pc, #0x6cc]
 *   @0x100ff4 mov r2, #1
 *   @0x100ff8 mov r3, r2
 *   @0x100ffc ldr r1, [r4, r1]
 *   @0x101000 add r0, pc, r0
 *   @0x101004 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #95 ds_grid_height → F_DsGridHeight(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x101008 ldr r1, [pc, #0x6b8]
 *   @0x10100c ldr r0, [pc, #0x6b8]
 *   @0x101010 mov r2, #2
 *   @0x101014 mov r3, #1
 *   @0x101018 ldr r1, [r4, r1]
 *   @0x10101c add r0, pc, r0
 *   @0x101020 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #96 ds_grid_clear → F_DsGridClear(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x101024 ldr r1, [pc, #0x6a4]
 *   @0x101028 ldr r0, [pc, #0x6a4]
 *   @0x10102c mov r2, #4
 *   @0x101030 mov r3, #1
 *   @0x101034 ldr r1, [r4, r1]
 *   @0x101038 add r0, pc, r0
 *   @0x10103c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #97 ds_grid_set → F_DsGridSet_debug(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x101040 ldr r1, [pc, #0x690]
 *   @0x101044 ldr r0, [pc, #0x690]
 *   @0x101048 mov r2, #4
 *   @0x10104c mov r3, #1
 *   @0x101050 ldr r1, [r4, r1]
 *   @0x101054 add r0, pc, r0
 *   @0x101058 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #98 ds_grid_set_pre → F_DsGridSetPre(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x10105c ldr r1, [pc, #0x67c]
 *   @0x101060 ldr r0, [pc, #0x67c]
 *   @0x101064 mov r2, #4
 *   @0x101068 mov r3, #1
 *   @0x10106c ldr r1, [r4, r1]
 *   @0x101070 add r0, pc, r0
 *   @0x101074 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #99 ds_grid_set_post → F_DsGridSetPost(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x101078 ldr r1, [pc, #0x668]
 *   @0x10107c ldr r0, [pc, #0x668]
 *   @0x101080 mov r2, #4
 *   @0x101084 mov r3, #1
 *   @0x101088 ldr r1, [r4, r1]
 *   @0x10108c add r0, pc, r0
 *   @0x101090 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #100 ds_grid_add → F_DsGridAdd(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x101094 ldr r1, [pc, #0x654]
 *   @0x101098 ldr r0, [pc, #0x654]
 *   @0x10109c mov r2, #4
 *   @0x1010a0 mov r3, #1
 *   @0x1010a4 ldr r1, [r4, r1]
 *   @0x1010a8 add r0, pc, r0
 *   @0x1010ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #101 ds_grid_multiply → F_DsGridMultiply(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x1010b0 ldr r1, [pc, #0x640]
 *   @0x1010b4 ldr r0, [pc, #0x640]
 *   @0x1010b8 mov r2, #6
 *   @0x1010bc mov r3, #1
 *   @0x1010c0 ldr r1, [r4, r1]
 *   @0x1010c4 add r0, pc, r0
 *   @0x1010c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #102 ds_grid_set_region → F_DsGridSetRegion(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x1010cc ldr r1, [pc, #0x62c]
 *   @0x1010d0 ldr r0, [pc, #0x62c]
 *   @0x1010d4 mov r2, #6
 *   @0x1010d8 mov r3, #1
 *   @0x1010dc ldr r1, [r4, r1]
 *   @0x1010e0 add r0, pc, r0
 *   @0x1010e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #103 ds_grid_add_region → F_DsGridAddRegion(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x1010e8 ldr r1, [pc, #0x618]
 *   @0x1010ec ldr r0, [pc, #0x618]
 *   @0x1010f0 mov r2, #6
 *   @0x1010f4 mov r3, #1
 *   @0x1010f8 ldr r1, [r4, r1]
 *   @0x1010fc add r0, pc, r0
 *   @0x101100 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #104 ds_grid_multiply_region → F_DsGridMultiplyRegion(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x101104 ldr r1, [pc, #0x604]
 *   @0x101108 ldr r0, [pc, #0x604]
 *   @0x10110c mov r2, #5
 *   @0x101110 mov r3, #1
 *   @0x101114 ldr r1, [r4, r1]
 *   @0x101118 add r0, pc, r0
 *   @0x10111c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #105 ds_grid_set_disk → F_DsGridSetDisk(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x101120 ldr r1, [pc, #0x5f0]
 *   @0x101124 ldr r0, [pc, #0x5f0]
 *   @0x101128 mov r2, #5
 *   @0x10112c mov r3, #1
 *   @0x101130 ldr r1, [r4, r1]
 *   @0x101134 add r0, pc, r0
 *   @0x101138 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #106 ds_grid_add_disk → F_DsGridAddDisk(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x10113c ldr r1, [pc, #0x5dc]
 *   @0x101140 ldr r0, [pc, #0x5dc]
 *   @0x101144 mov r2, #5
 *   @0x101148 mov r3, #1
 *   @0x10114c ldr r1, [r4, r1]
 *   @0x101150 add r0, pc, r0
 *   @0x101154 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #107 ds_grid_multiply_disk → F_DsGridMultiplyDisk(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x101158 ldr r1, [pc, #0x5c8]
 *   @0x10115c ldr r0, [pc, #0x5c8]
 *   @0x101160 mov r2, #8
 *   @0x101164 mov r3, #1
 *   @0x101168 ldr r1, [r4, r1]
 *   @0x10116c add r0, pc, r0
 *   @0x101170 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #108 ds_grid_set_grid_region → F_DsGridSetGridRegion(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x101174 ldr r1, [pc, #0x5b4]
 *   @0x101178 ldr r0, [pc, #0x5b4]
 *   @0x10117c mov r2, #8
 *   @0x101180 mov r3, #1
 *   @0x101184 ldr r1, [r4, r1]
 *   @0x101188 add r0, pc, r0
 *   @0x10118c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #109 ds_grid_add_grid_region → F_DsGridAddGridRegion(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x101190 ldr r1, [pc, #0x5a0]
 *   @0x101194 ldr r0, [pc, #0x5a0]
 *   @0x101198 mov r2, #8
 *   @0x10119c mov r3, #1
 *   @0x1011a0 ldr r1, [r4, r1]
 *   @0x1011a4 add r0, pc, r0
 *   @0x1011a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #110 ds_grid_multiply_grid_region → F_DsGridMultiplyGridRegion(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x1011ac ldr r1, [pc, #0x58c]
 *   @0x1011b0 ldr r0, [pc, #0x58c]
 *   @0x1011b4 mov r2, #3
 *   @0x1011b8 mov r3, #1
 *   @0x1011bc ldr r1, [r4, r1]
 *   @0x1011c0 add r0, pc, r0
 *   @0x1011c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #111 ds_grid_get → F_DsGridGet_debug(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x1011c8 ldr r1, [pc, #0x578]
 *   @0x1011cc ldr r0, [pc, #0x578]
 *   @0x1011d0 mov r2, #5
 *   @0x1011d4 mov r3, #1
 *   @0x1011d8 ldr r1, [r4, r1]
 *   @0x1011dc add r0, pc, r0
 *   @0x1011e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #112 ds_grid_get_sum → F_DsGridGetSum(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x1011e4 ldr r1, [pc, #0x564]
 *   @0x1011e8 ldr r0, [pc, #0x564]
 *   @0x1011ec mov r2, #5
 *   @0x1011f0 mov r3, #1
 *   @0x1011f4 ldr r1, [r4, r1]
 *   @0x1011f8 add r0, pc, r0
 *   @0x1011fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #113 ds_grid_get_max → F_DsGridGetMax(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x101200 ldr r1, [pc, #0x550]
 *   @0x101204 ldr r0, [pc, #0x550]
 *   @0x101208 mov r2, #5
 *   @0x10120c mov r3, #1
 *   @0x101210 ldr r1, [r4, r1]
 *   @0x101214 add r0, pc, r0
 *   @0x101218 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #114 ds_grid_get_min → F_DsGridGetMin(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x10121c ldr r1, [pc, #0x53c]
 *   @0x101220 ldr r0, [pc, #0x53c]
 *   @0x101224 mov r2, #5
 *   @0x101228 mov r3, #1
 *   @0x10122c ldr r1, [r4, r1]
 *   @0x101230 add r0, pc, r0
 *   @0x101234 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #115 ds_grid_get_mean → F_DsGridGetMean(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x101238 ldr r1, [pc, #0x528]
 *   @0x10123c ldr r0, [pc, #0x528]
 *   @0x101240 mov r2, #4
 *   @0x101244 mov r3, #1
 *   @0x101248 ldr r1, [r4, r1]
 *   @0x10124c add r0, pc, r0
 *   @0x101250 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #116 ds_grid_get_disk_sum → F_DsGridGetDiskSum(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x101254 ldr r1, [pc, #0x514]
 *   @0x101258 ldr r0, [pc, #0x514]
 *   @0x10125c mov r2, #4
 *   @0x101260 mov r3, #1
 *   @0x101264 ldr r1, [r4, r1]
 *   @0x101268 add r0, pc, r0
 *   @0x10126c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #117 ds_grid_get_disk_max → F_DsGridGetDiskMax(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x101270 ldr r1, [pc, #0x500]
 *   @0x101274 ldr r0, [pc, #0x500]
 *   @0x101278 mov r2, #4
 *   @0x10127c mov r3, #1
 *   @0x101280 ldr r1, [r4, r1]
 *   @0x101284 add r0, pc, r0
 *   @0x101288 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #118 ds_grid_get_disk_min → F_DsGridGetDiskMin(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x10128c ldr r1, [pc, #0x4ec]
 *   @0x101290 ldr r0, [pc, #0x4ec]
 *   @0x101294 mov r2, #4
 *   @0x101298 mov r3, #1
 *   @0x10129c ldr r1, [r4, r1]
 *   @0x1012a0 add r0, pc, r0
 *   @0x1012a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #119 ds_grid_get_disk_mean → F_DsGridGetDiskMean(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x1012a8 ldr r1, [pc, #0x4d8]
 *   @0x1012ac ldr r0, [pc, #0x4d8]
 *   @0x1012b0 mov r2, #6
 *   @0x1012b4 mov r3, #1
 *   @0x1012b8 ldr r1, [r4, r1]
 *   @0x1012bc add r0, pc, r0
 *   @0x1012c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #120 ds_grid_value_exists → F_DsGridValueExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x1012c4 ldr r1, [pc, #0x4c4]
 *   @0x1012c8 ldr r0, [pc, #0x4c4]
 *   @0x1012cc mov r2, #6
 *   @0x1012d0 mov r3, #1
 *   @0x1012d4 ldr r1, [r4, r1]
 *   @0x1012d8 add r0, pc, r0
 *   @0x1012dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #121 ds_grid_value_x → F_DsGridValueX(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x1012e0 ldr r1, [pc, #0x4b0]
 *   @0x1012e4 ldr r0, [pc, #0x4b0]
 *   @0x1012e8 mov r2, #6
 *   @0x1012ec mov r3, #1
 *   @0x1012f0 ldr r1, [r4, r1]
 *   @0x1012f4 add r0, pc, r0
 *   @0x1012f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #122 ds_grid_value_y → F_DsGridValueY(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x1012fc ldr r1, [pc, #0x49c]
 *   @0x101300 ldr r0, [pc, #0x49c]
 *   @0x101304 mov r2, #5
 *   @0x101308 mov r3, #1
 *   @0x10130c ldr r1, [r4, r1]
 *   @0x101310 add r0, pc, r0
 *   @0x101314 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #123 ds_grid_value_disk_exists → F_DsGridValueDiskExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x101318 ldr r1, [pc, #0x488]
 *   @0x10131c ldr r0, [pc, #0x488]
 *   @0x101320 mov r2, #5
 *   @0x101324 mov r3, #1
 *   @0x101328 ldr r1, [r4, r1]
 *   @0x10132c add r0, pc, r0
 *   @0x101330 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #124 ds_grid_value_disk_x → F_DsGridValueDiskX(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x101334 ldr r1, [pc, #0x474]
 *   @0x101338 ldr r0, [pc, #0x474]
 *   @0x10133c mov r2, #5
 *   @0x101340 mov r3, #1
 *   @0x101344 ldr r1, [r4, r1]
 *   @0x101348 add r0, pc, r0
 *   @0x10134c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #125 ds_grid_value_disk_y → F_DsGridValueDiskY(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x101350 ldr r1, [pc, #0x460]
 *   @0x101354 ldr r0, [pc, #0x460]
 *   @0x101358 mov r2, #1
 *   @0x10135c mov r3, r2
 *   @0x101360 ldr r1, [r4, r1]
 *   @0x101364 add r0, pc, r0
 *   @0x101368 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #126 ds_grid_shuffle → F_DsGridShuffle(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x10136c ldr r1, [pc, #0x44c]
 *   @0x101370 ldr r0, [pc, #0x44c]
 *   @0x101374 mov r2, #1
 *   @0x101378 mov r3, r2
 *   @0x10137c ldr r1, [r4, r1]
 *   @0x101380 add r0, pc, r0
 *   @0x101384 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #127 ds_grid_write → F_DsGridWrite(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x101388 ldr r1, [pc, #0x438]
 *   @0x10138c ldr r0, [pc, #0x438]
 *   @0x101390 mov r2, #2
 *   @0x101394 mov r3, #1
 *   @0x101398 ldr r1, [r4, r1]
 *   @0x10139c add r0, pc, r0
 *   @0x1013a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #128 ds_grid_read → F_DsGridRead(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1013a4 ldr r1, [pc, #0x424]
 *   @0x1013a8 ldr r0, [pc, #0x424]
 *   @0x1013ac mov r2, #3
 *   @0x1013b0 mov r3, #1
 *   @0x1013b4 ldr r1, [r4, r1]
 *   @0x1013b8 add r0, pc, r0
 *   @0x1013bc pop {r4, lr}
 *   @0x1013c0 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #129 ds_grid_sort → F_DsGridSort(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x1013c4 eoreq r1, pc, r0, asr #13
 *   @0x1013c8 .word 0xffffc254
 *   @0x1013cc .word 0x002377b4
 *   @0x1013d0 .word 0xffffc258
 *   @0x1013d4 eoreq r7, r3, r12, lsr #15
 *   @0x1013d8 .word 0xffffc25c
 *   @0x1013dc mlaeq r3, r12, r7, r7
 *   @0x1013e0 .word 0xffffc260
 *   @0x1013e4 mlaeq r3, r0, r7, r7
 *   @0x1013e8 .word 0xffffc264
 *   @0x1013ec eoreq r7, r3, r8, lsl #15
 *   @0x1013f0 .word 0xffffc268
 *   @0x1013f4 eoreq r7, r3, r12, ror r7
 *   @0x1013f8 .word 0xffffc26c
 *   @0x1013fc eoreq r7, r3, r0, ror r7
 *   @0x101400 .word 0xffffc270
 *   @0x101404 eoreq r7, r3, r4, ror #14
 *   @0x101408 .word 0xffffc274
 *   @0x10140c eoreq r7, r3, r8, asr r7
 *   @0x101410 .word 0xffffc278
 *   @0x101414 eoreq r7, r3, r12, asr #14
 *   @0x101418 .word 0xffffc27c
 *   @0x10141c eoreq r7, r3, r0, asr #14
 *   @0x101420 .word 0xffffc280
 *   @0x101424 eoreq r7, r3, r4, lsr r7
 *   @0x101428 .word 0xffffc284
 *   @0x10142c eoreq r7, r3, r8, lsr #14
 *   @0x101430 .word 0xffffc288
 *   @0x101434 eoreq r7, r3, r12, lsl r7
 *   @0x101438 .word 0xffffc28c
 *   @0x10143c eoreq r7, r3, r0, lsl r7
 *   @0x101440 .word 0xffffc290
 *   @0x101444 eoreq r7, r3, r8, lsl #14
 *   @0x101448 .word 0xffffc294
 *   @0x10144c .word 0x002376fc
 *   @0x101450 .word 0xffffc298
 *   @0x101454 .word 0x002376f0
 *   @0x101458 .word 0xffffc29c
 *   @0x10145c eoreq r7, r3, r4, ror #13
 *   @0x101460 .word 0xffffc2a0
 *   @0x101464 .word 0x002376d8
 *   @0x101468 .word 0xffffc2a4
 *   @0x10146c .word 0x002376d0
 *   @0x101470 .word 0xffffc2a8
 *   @0x101474 eoreq r7, r3, r8, asr #13
 *   @0x101478 .word 0xffffc2ac
 *   @0x10147c .word 0x002376bc
 *   @0x101480 .word 0xffffc2b0
 *   @0x101484 .word 0x002376b0
 *   @0x101488 .word 0xffffc2b4
 *   @0x10148c eoreq r7, r3, r4, lsr #13
 *   @0x101490 .word 0xffffc2b8
 *   @0x101494 mlaeq r3, r8, r6, r7
 *   @0x101498 .word 0xffffc2bc
 *   @0x10149c eoreq r7, r3, r12, lsl #13
 *   @0x1014a0 .word 0xffffc2c0
 *   @0x1014a4 eoreq r7, r3, r0, lsl #13
 *   @0x1014a8 .word 0xffffc2c4
 *   @0x1014ac eoreq r7, r3, r4, ror r6
 *   @0x1014b0 .word 0xffffc2c8
 *   @0x1014b4 eoreq r7, r3, r8, ror #12
 *   @0x1014b8 .word 0xffffc2cc
 *   @0x1014bc eoreq r7, r3, r12, asr r6
 *   @0x1014c0 .word 0xffffc2d0
 *   @0x1014c4 eoreq r7, r3, r0, asr r6
 *   @0x1014c8 .word 0xffffc2d4
 *   @0x1014cc eoreq r7, r3, r0, asr #12
 *   @0x1014d0 .word 0xffffc2d8
 *   @0x1014d4 eoreq r7, r3, r4, lsr r6
 *   @0x1014d8 .word 0xffffc2dc
 *   @0x1014dc eoreq r7, r3, r8, lsr #12
 *   @0x1014e0 .word 0xffffc2e0
 *   @0x1014e4 eoreq r7, r3, r12, lsl r6
 *   @0x1014e8 .word 0xffffc2e4
 *   @0x1014ec eoreq r7, r3, r4, lsl r6
 *   @0x1014f0 .word 0xffffc2e8
 *   @0x1014f4 eoreq r7, r3, r12, lsl #12
 *   @0x1014f8 .word 0xffffc2ec
 *   @0x1014fc eoreq r7, r3, r8, lsl #12
 *   @0x101500 .word 0xffffc2f0
 *   @0x101504 eoreq r7, r3, r0, lsl #12
 *   @0x101508 .word 0xffffc2f4
 *   @0x10150c .word 0x002375f4
 *   @0x101510 .word 0xffffc2f8
 *   @0x101514 eoreq r7, r3, r8, ror #11
 *   @0x101518 .word 0xffffc2fc
 *   @0x10151c .word 0x002375dc
 *   @0x101520 .word 0xffffc300
 *   @0x101524 .word 0x002375d0
 *   @0x101528 .word 0xffffc304
 *   @0x10152c eoreq r7, r3, r0, asr #11
 *   @0x101530 .word 0xffffc308
 *   @0x101534 .word 0x002375b8
 *   @0x101538 .word 0xffffc30c
 *   @0x10153c eoreq r7, r3, r12, lsr #11
 *   @0x101540 .word 0xffffc310
 *   @0x101544 eoreq r7, r3, r0, lsr #11
 *   @0x101548 .word 0xffffc314
 *   @0x10154c mlaeq r3, r4, r5, r7
 *   @0x101550 .word 0xffffc318
 *   @0x101554 eoreq r7, r3, r8, lsl #11
 *   @0x101558 .word 0xffffc31c
 *   @0x10155c eoreq r7, r3, r8, ror r5
 *   @0x101560 .word 0xffffc320
 *   @0x101564 eoreq r7, r3, r8, ror #10
 *   @0x101568 .word 0xffffc324
 *   @0x10156c eoreq r7, r3, r12, asr r5
 *   @0x101570 .word 0xffffc328
 *   @0x101574 eoreq r7, r3, r12, asr #10
 *   @0x101578 .word 0xffffc32c
 *   @0x10157c eoreq r7, r3, r12, lsr r5
 *   @0x101580 .word 0xffffc330
 *   @0x101584 eoreq r7, r3, r0, lsr r5
 *   @0x101588 .word 0xffffc334
 *   @0x10158c eoreq r7, r3, r4, lsr #10
 *   @0x101590 .word 0xffffc338
 *   @0x101594 eoreq r7, r3, r8, lsl r5
 *   @0x101598 .word 0xffffc33c
 *   @0x10159c eoreq r7, r3, r12, lsl #10
 *   @0x1015a0 .word 0xffffc340
 *   @0x1015a4 eoreq r7, r3, r0, lsl #10
 *   @0x1015a8 .word 0xffffc344
 *   @0x1015ac .word 0x002374f8
 *   @0x1015b0 .word 0xffffc348
 *   @0x1015b4 .word 0x002374f0
 *   @0x1015b8 .word 0xffffc34c
 *   @0x1015bc eoreq r7, r3, r4, ror #9
 *   @0x1015c0 .word 0xffffc350
 *   @0x1015c4 .word 0x002374d8
 *   @0x1015c8 .word 0xffffc354
 *   @0x1015cc .word 0x002374d0
 *   @0x1015d0 .word 0xffffc358
 *   @0x1015d4 eoreq r7, r3, r12, asr #9
 *   @0x1015d8 .word 0xffffc35c
 *   @0x1015dc eoreq r7, r3, r4, asr #9
 *   @0x1015e0 .word 0xffffc360
 *   @0x1015e4 .word 0x002374bc
 *   @0x1015e8 .word 0xffffc364
 *   @0x1015ec .word 0x002374b4
 *   @0x1015f0 .word 0xffffc368
 *   @0x1015f4 eoreq r7, r3, r8, lsr #9
 *   @0x1015f8 .word 0xffffc36c
 *   @0x1015fc mlaeq r3, r8, r4, r7
 *   @0x101600 .word 0xffffc370
 *   @0x101604 mlaeq r3, r0, r4, r7
 *   @0x101608 .word 0xffffc374
 *   @0x10160c eoreq r7, r3, r8, lsl #9
 *   @0x101610 .word 0xffffc378
 *   @0x101614 eoreq r7, r3, r8, lsl #9
 *   @0x101618 .word 0xffffc37c
 *   @0x10161c eoreq r7, r3, r8, lsl #9
 *   @0x101620 .word 0xffffc380
 *   @0x101624 eoreq r7, r3, r0, lsl #9
 *   @0x101628 .word 0xffffc384
 *   @0x10162c eoreq r7, r3, r8, ror r4
 *   @0x101630 .word 0xffffc388
 *   @0x101634 eoreq r7, r3, r0, ror r4
 *   @0x101638 .word 0xffffc38c
 *   @0x10163c eoreq r7, r3, r8, ror #8
 *   @0x101640 .word 0xffffc390
 *   @0x101644 eoreq r7, r3, r0, ror #8
 *   @0x101648 .word 0xffffc394
 *   @0x10164c eoreq r7, r3, r8, asr r4
 *   @0x101650 .word 0xffffc398
 *   @0x101654 eoreq r7, r3, r12, asr #8
 *   @0x101658 .word 0xffffc39c
 *   @0x10165c eoreq r7, r3, r12, asr #8
 *   @0x101660 .word 0xffffc3a0
 *   @0x101664 eoreq r7, r3, r12, asr #8
 *   @0x101668 .word 0xffffc3a4
 *   @0x10166c eoreq r7, r3, r12, asr #8
 *   @0x101670 .word 0xffffc3a8
 *   @0x101674 eoreq r7, r3, r8, asr #8
 *   @0x101678 .word 0xffffc3ac
 *   @0x10167c eoreq r7, r3, r4, asr #8
 *   @0x101680 .word 0xffffc3b0
 *   @0x101684 eoreq r7, r3, r0, asr #8
 *   @0x101688 .word 0xffffc3b4
 *   @0x10168c eoreq r7, r3, r12, lsr r4
 *   @0x101690 .word 0xffffc3b8
 *   @0x101694 eoreq r7, r3, r4, lsr r4
 *   @0x101698 .word 0xffffc3bc
 *   @0x10169c eoreq r7, r3, r12, lsr #8
 *   @0x1016a0 .word 0xffffc3c0
 *   @0x1016a4 eoreq r7, r3, r0, lsr #8
 *   @0x1016a8 .word 0xffffc3c4
 *   @0x1016ac eoreq r7, r3, r4, lsl r4
 *   @0x1016b0 .word 0xffffc3c8
 *   @0x1016b4 eoreq r7, r3, r8, lsl #8
 *   @0x1016b8 .word 0xffffc3cc
 *   @0x1016bc .word 0x002373fc
 *   @0x1016c0 .word 0xffffc3d0
 *   @0x1016c4 .word 0x002373f0
 *   @0x1016c8 .word 0xffffc3d4
 *   @0x1016cc eoreq r7, r3, r4, ror #7
 *   @0x1016d0 .word 0xffffc24c
 *   @0x1016d4 eoreq r6, r3, r0, lsl #26
 *   @0x1016d8 .word 0xffffc3d8
 *   @0x1016dc .word 0x002373bc
 *   @0x1016e0 .word 0xffffc3dc
 *   @0x1016e4 .word 0x002373b0
 *   @0x1016e8 .word 0xffffc3e0
 *   @0x1016ec eoreq r7, r3, r8, lsr #7
 *   @0x1016f0 .word 0xffffc3e4
 *   @0x1016f4 mlaeq r3, r8, r3, r7
 *   @0x1016f8 .word 0xffffc3e8
 *   @0x1016fc mlaeq r3, r0, r3, r7
 *   @0x101700 .word 0xffffc3ec
 *   @0x101704 eoreq r7, r3, r8, lsl #7
 *   @0x101708 .word 0xffffc3f0
 *   @0x10170c eoreq r7, r3, r0, lsl #7
 *   @0x101710 .word 0xffffc3f4
 *   @0x101714 eoreq r7, r3, r12, ror r3
 *   @0x101718 .word 0xffffc3f8
 *   @0x10171c eoreq r7, r3, r4, ror r3
 *   @0x101720 .word 0xffffc3fc
 *   @0x101724 eoreq r7, r3, r12, ror #6
 *   @0x101728 .word 0xffffc400
 *   @0x10172c eoreq r7, r3, r8, ror #6
 *   @0x101730 .word 0xffffc404
 *   @0x101734 eoreq r7, r3, r4, ror #6
 *   @0x101738 .word 0xffffc408
 *   @0x10173c eoreq r7, r3, r0, ror #6
 *   @0x101740 .word 0xffffc250
 *   @0x101744 eoreq r6, r3, r4, lsl #23
 *   @0x101748 .word 0xffffc40c
 *   @0x10174c eoreq r7, r3, r8, asr #6
 *   @0x101750 .word 0xffffc410
 *   @0x101754 eoreq r7, r3, r12, lsr r3
 *   @0x101758 .word 0xffffc414
 *   @0x10175c eoreq r7, r3, r0, lsr r3
 *   @0x101760 .word 0xffffc418
 *   @0x101764 eoreq r7, r3, r4, lsr #6
 *   @0x101768 .word 0xffffc41c
 *   @0x10176c eoreq r7, r3, r12, lsl r3
 *   @0x101770 .word 0xffffc420
 *   @0x101774 eoreq r7, r3, r8, lsl r3
 *   @0x101778 .word 0xffffc424
 *   @0x10177c eoreq r7, r3, r4, lsl r3
 *   @0x101780 .word 0xffffc428
 *   @0x101784 eoreq r7, r3, r0, lsl r3
 *   @0x101788 .word 0xffffc42c
 *   @0x10178c eoreq r7, r3, r12, lsl #6
 *   @0x101790 .word 0xffffc430
 *   @0x101794 eoreq r7, r3, r8, lsl #6
 *   @0x101798 .word 0xffffc434
 *   @0x10179c .word 0x002372fc
 *   @0x1017a0 .word 0xffffc438
 *   @0x1017a4 .word 0x002372f0
 *   @0x1017a8 .word 0xffffc43c
 *   @0x1017ac .word 0x002372f0
 *   @0x1017b0 .word 0xffffc440
 *   @0x1017b4 eoreq r7, r3, r12, ror #5
 *   @0x1017b8 .word 0xffffc444
 *   @0x1017bc eoreq r7, r3, r8, ror #5
 *   @0x1017c0 .word 0xffffc448
 *   @0x1017c4 .word 0x002372dc
 *   @0x1017c8 .word 0xffffc44c
 *   @0x1017cc .word 0x002372d0
 *   @0x1017d0 .word 0xffffc450
 *   @0x1017d4 eoreq r7, r3, r4, asr #5
 *
 * ══ §3/4 InitMathFunctions  0x111c5c..0x112cd8  size 4220  1055 条（823 条指令 + 232 个池字）══
 * @func 0x111c5c 0x112cd8  size 4220  1055 条
 * 注册 117 条｜唯一名 117｜唯一函数指针 114｜argc -1:6 0:4 1:62 2:18 3:17 4:5 5:1 6:4｜flag 0:115 1:2
 * 首条 #0 is_bool（0x111c80）→ 末条 #116 angle_difference（0x112934）
 * 名字族（前 8）: string×22 array×14 is×11 dot×6 random×5 point×3 irandom×2 lengthdir×2
 * 游戏实际调用的 99 个内建里落在本表: 12 个（choose, irandom_range, max, min, point_direction, random, random_range, randomize, sign, string, string_digits, string_format）
 * 表: asm/init-tables/init-InitMathFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: 无（本函数每条注册的四实参全部解出，控制流全部走到）
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x111c5c push {r4, r5, r6, lr}
 *   @0x111c60 mov r2, #1
 *   @0x111c64 ldr r4, [pc, #0xccc]
 *   @0x111c68 mov r3, #0
 *   @0x111c6c ldr r1, [pc, #0xcc8]
 *   @0x111c70 add r4, pc, r4
 *   @0x111c74 ldr r0, [pc, #0xcc4]
 *   @0x111c78 ldr r1, [r4, r1]
 *   @0x111c7c add r0, pc, r0
 *   @0x111c80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 is_bool → F_IsBool(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x111c84 ldr r1, [pc, #0xcb8]
 *   @0x111c88 ldr r0, [pc, #0xcb8]
 *   @0x111c8c mov r2, #1
 *   @0x111c90 mov r3, #0
 *   @0x111c94 ldr r1, [r4, r1]
 *   @0x111c98 add r0, pc, r0
 *   @0x111c9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 is_real → F_IsReal(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x111ca0 ldr r1, [pc, #0xca4]
 *   @0x111ca4 ldr r0, [pc, #0xca4]
 *   @0x111ca8 mov r2, #1
 *   @0x111cac mov r3, #0
 *   @0x111cb0 ldr r1, [r4, r1]
 *   @0x111cb4 add r0, pc, r0
 *   @0x111cb8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 is_string → F_IsString(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x111cbc ldr r1, [pc, #0xc90]
 *   @0x111cc0 ldr r0, [pc, #0xc90]
 *   @0x111cc4 mov r2, #1
 *   @0x111cc8 mov r3, #0
 *   @0x111ccc ldr r1, [r4, r1]
 *   @0x111cd0 add r0, pc, r0
 *   @0x111cd4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 is_array → F_IsArray(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x111cd8 ldr r1, [pc, #0xc7c]
 *   @0x111cdc ldr r0, [pc, #0xc7c]
 *   @0x111ce0 mov r2, #1
 *   @0x111ce4 mov r3, #0
 *   @0x111ce8 ldr r1, [r4, r1]
 *   @0x111cec add r0, pc, r0
 *   @0x111cf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #4 is_undefined → F_IsUndefined(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x111cf4 ldr r1, [pc, #0xc68]
 *   @0x111cf8 ldr r0, [pc, #0xc68]
 *   @0x111cfc mov r2, #1
 *   @0x111d00 mov r3, #0
 *   @0x111d04 ldr r1, [r4, r1]
 *   @0x111d08 add r0, pc, r0
 *   @0x111d0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #5 is_int32 → F_IsInt32(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x111d10 ldr r1, [pc, #0xc54]
 *   @0x111d14 ldr r0, [pc, #0xc54]
 *   @0x111d18 mov r2, #1
 *   @0x111d1c mov r3, #0
 *   @0x111d20 ldr r1, [r4, r1]
 *   @0x111d24 add r0, pc, r0
 *   @0x111d28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #6 is_int64 → F_IsInt64(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x111d2c ldr r1, [pc, #0xc40]
 *   @0x111d30 ldr r0, [pc, #0xc40]
 *   @0x111d34 mov r2, #1
 *   @0x111d38 mov r3, #0
 *   @0x111d3c ldr r1, [r4, r1]
 *   @0x111d40 add r0, pc, r0
 *   @0x111d44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #7 is_ptr → F_IsPtr(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x111d48 ldr r1, [pc, #0xc2c]
 *   @0x111d4c ldr r0, [pc, #0xc2c]
 *   @0x111d50 mov r2, #1
 *   @0x111d54 mov r3, #0
 *   @0x111d58 ldr r1, [r4, r1]
 *   @0x111d5c add r0, pc, r0
 *   @0x111d60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #8 is_vec3 → F_IsVec3(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x111d64 ldr r1, [pc, #0xc18]
 *   @0x111d68 ldr r0, [pc, #0xc18]
 *   @0x111d6c mov r2, #1
 *   @0x111d70 mov r3, #0
 *   @0x111d74 ldr r1, [r4, r1]
 *   @0x111d78 add r0, pc, r0
 *   @0x111d7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #9 is_vec4 → F_IsVec4(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x111d80 ldr r1, [pc, #0xc04]
 *   @0x111d84 ldr r0, [pc, #0xc04]
 *   @0x111d88 mov r2, #1
 *   @0x111d8c mov r3, #0
 *   @0x111d90 ldr r1, [r4, r1]
 *   @0x111d94 add r0, pc, r0
 *   @0x111d98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #10 is_matrix → F_IsMatrix(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x111d9c ldr r1, [pc, #0xbf0]
 *   @0x111da0 ldr r0, [pc, #0xbf0]
 *   @0x111da4 mov r2, #1
 *   @0x111da8 mov r3, #0
 *   @0x111dac ldr r1, [r4, r1]
 *   @0x111db0 add r0, pc, r0
 *   @0x111db4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #11 typeof → F_Typeof(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x111db8 ldr r1, [pc, #0xbdc]
 *   @0x111dbc ldr r0, [pc, #0xbdc]
 *   @0x111dc0 mov r2, #1
 *   @0x111dc4 mov r3, #0
 *   @0x111dc8 ldr r1, [r4, r1]
 *   @0x111dcc add r0, pc, r0
 *   @0x111dd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #12 array_length_1d → F_ArrayLength1D(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x111dd4 ldr r1, [pc, #0xbc8]
 *   @0x111dd8 ldr r0, [pc, #0xbc8]
 *   @0x111ddc mov r2, #2
 *   @0x111de0 mov r3, #0
 *   @0x111de4 ldr r1, [r4, r1]
 *   @0x111de8 add r0, pc, r0
 *   @0x111dec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #13 array_length_2d → F_ArrayLength2D(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x111df0 ldr r1, [pc, #0xbb4]
 *   @0x111df4 ldr r0, [pc, #0xbb4]
 *   @0x111df8 mov r2, #1
 *   @0x111dfc mov r3, #0
 *   @0x111e00 ldr r1, [r4, r1]
 *   @0x111e04 add r0, pc, r0
 *   @0x111e08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #14 array_height_2d → F_ArrayHeight2D(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x111e0c ldr r1, [pc, #0xba0]
 *   @0x111e10 ldr r0, [pc, #0xba0]
 *   @0x111e14 mov r2, #2
 *   @0x111e18 mov r3, #0
 *   @0x111e1c ldr r1, [r4, r1]
 *   @0x111e20 add r0, pc, r0
 *   @0x111e24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #15 array_get → F_ArrayGet(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x111e28 ldr r1, [pc, #0xb8c]
 *   @0x111e2c ldr r0, [pc, #0xb8c]
 *   @0x111e30 mov r2, #3
 *   @0x111e34 mov r3, #0
 *   @0x111e38 ldr r1, [r4, r1]
 *   @0x111e3c add r0, pc, r0
 *   @0x111e40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #16 array_set → F_ArraySet(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x111e44 ldr r1, [pc, #0xb78]
 *   @0x111e48 ldr r0, [pc, #0xb78]
 *   @0x111e4c mov r2, #3
 *   @0x111e50 mov r3, #0
 *   @0x111e54 ldr r1, [r4, r1]
 *   @0x111e58 add r0, pc, r0
 *   @0x111e5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #17 array_set_pre → F_ArraySetPre(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x111e60 ldr r1, [pc, #0xb64]
 *   @0x111e64 ldr r0, [pc, #0xb64]
 *   @0x111e68 mov r2, #3
 *   @0x111e6c mov r3, #0
 *   @0x111e70 ldr r1, [r4, r1]
 *   @0x111e74 add r0, pc, r0
 *   @0x111e78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #18 array_set_post → F_ArraySetPost(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x111e7c ldr r1, [pc, #0xb50]
 *   @0x111e80 ldr r0, [pc, #0xb50]
 *   @0x111e84 mov r2, #2
 *   @0x111e88 mov r3, #0
 *   @0x111e8c ldr r1, [r4, r1]
 *   @0x111e90 add r0, pc, r0
 *   @0x111e94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #19 array_get_2D → F_ArrayGet2D(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x111e98 ldr r1, [pc, #0xb3c]
 *   @0x111e9c ldr r0, [pc, #0xb3c]
 *   @0x111ea0 mov r2, #3
 *   @0x111ea4 mov r3, #0
 *   @0x111ea8 ldr r1, [r4, r1]
 *   @0x111eac add r0, pc, r0
 *   @0x111eb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #20 array_set_2D → F_ArraySet2D(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x111eb4 ldr r1, [pc, #0xb28]
 *   @0x111eb8 ldr r0, [pc, #0xb28]
 *   @0x111ebc mov r2, #3
 *   @0x111ec0 mov r3, #0
 *   @0x111ec4 ldr r1, [r4, r1]
 *   @0x111ec8 add r0, pc, r0
 *   @0x111ecc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #21 array_set_2D_pre → F_ArraySet2DPre(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x111ed0 ldr r1, [pc, #0xb14]
 *   @0x111ed4 ldr r0, [pc, #0xb14]
 *   @0x111ed8 mov r2, #3
 *   @0x111edc mov r3, #0
 *   @0x111ee0 ldr r1, [r4, r1]
 *   @0x111ee4 add r0, pc, r0
 *   @0x111ee8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #22 array_set_2D_post → F_ArraySet2DPost(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x111eec ldr r1, [pc, #0xb00]
 *   @0x111ef0 ldr r0, [pc, #0xb00]
 *   @0x111ef4 mov r2, #2
 *   @0x111ef8 mov r3, #0
 *   @0x111efc ldr r1, [r4, r1]
 *   @0x111f00 add r0, pc, r0
 *   @0x111f04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #23 array_equals → F_ArrayEquals(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x111f08 ldr r1, [pc, #0xaec]
 *   @0x111f0c ldr r0, [pc, #0xaec]
 *   @0x111f10 mvn r2, #0
 *   @0x111f14 mov r3, #0
 *   @0x111f18 ldr r1, [r4, r1]
 *   @0x111f1c add r0, pc, r0
 *   @0x111f20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #24 array_create → F_ArrayCreate(RValue&, CInstance*, CInstance*, int, RValue*) argc=-1 flag=0
 *   @0x111f24 ldr r1, [pc, #0xad8]
 *   @0x111f28 ldr r0, [pc, #0xad8]
 *   @0x111f2c mov r2, #5
 *   @0x111f30 mov r3, #0
 *   @0x111f34 ldr r1, [r4, r1]
 *   @0x111f38 add r0, pc, r0
 *   @0x111f3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #25 array_copy → F_ArrayCopy(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0x111f40 ldr r1, [pc, #0xac4]
 *   @0x111f44 ldr r0, [pc, #0xac4]
 *   @0x111f48 mov r2, #1
 *   @0x111f4c mov r3, #0
 *   @0x111f50 ldr r1, [r4, r1]
 *   @0x111f54 add r0, pc, r0
 *   @0x111f58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #26 random → F_Random(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x111f5c ldr r1, [pc, #0xab0]
 *   @0x111f60 ldr r0, [pc, #0xab0]
 *   @0x111f64 mov r2, #2
 *   @0x111f68 mov r3, #0
 *   @0x111f6c ldr r1, [r4, r1]
 *   @0x111f70 add r0, pc, r0
 *   @0x111f74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #27 random_range → F_RandomRange(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x111f78 ldr r1, [pc, #0xa9c]
 *   @0x111f7c ldr r0, [pc, #0xa9c]
 *   @0x111f80 mov r2, #1
 *   @0x111f84 mov r3, #0
 *   @0x111f88 ldr r1, [r4, r1]
 *   @0x111f8c add r0, pc, r0
 *   @0x111f90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #28 irandom → F_IRandom(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x111f94 ldr r1, [pc, #0xa88]
 *   @0x111f98 ldr r0, [pc, #0xa88]
 *   @0x111f9c mov r2, #2
 *   @0x111fa0 mov r3, #0
 *   @0x111fa4 ldr r1, [r4, r1]
 *   @0x111fa8 add r0, pc, r0
 *   @0x111fac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #29 irandom_range → F_IRandomRange(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x111fb0 ldr r1, [pc, #0xa74]
 *   @0x111fb4 ldr r0, [pc, #0xa74]
 *   @0x111fb8 mov r2, #1
 *   @0x111fbc mov r3, #0
 *   @0x111fc0 ldr r1, [r4, r1]
 *   @0x111fc4 add r0, pc, r0
 *   @0x111fc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #30 random_use_old_version → F_RandomUseOldVersion(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x111fcc ldr r1, [pc, #0xa60]
 *   @0x111fd0 ldr r0, [pc, #0xa60]
 *   @0x111fd4 mov r2, #1
 *   @0x111fd8 mov r3, #0
 *   @0x111fdc ldr r1, [r4, r1]
 *   @0x111fe0 add r0, pc, r0
 *   @0x111fe4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #31 random_set_seed → F_RandomSetSeed(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x111fe8 ldr r1, [pc, #0xa4c]
 *   @0x111fec ldr r0, [pc, #0xa4c]
 *   @0x111ff0 mov r2, #0
 *   @0x111ff4 mov r3, r2
 *   @0x111ff8 ldr r1, [r4, r1]
 *   @0x111ffc add r0, pc, r0
 *   @0x112000 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #32 random_get_seed → F_RandomGetSeed(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x112004 ldr r1, [pc, #0xa38]
 *   @0x112008 ldr r0, [pc, #0xa38]
 *   @0x11200c mov r2, #0
 *   @0x112010 mov r3, r2
 *   @0x112014 ldr r5, [r4, r1]
 *   @0x112018 add r0, pc, r0
 *   @0x11201c mov r1, r5
 *   @0x112020 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #33 randomize → F_Randomize(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x112024 ldr r0, [pc, #0xa20]
 *   @0x112028 mov r2, #0
 *   @0x11202c mov r1, r5
 *   @0x112030 mov r3, r2
 *   @0x112034 add r0, pc, r0
 *   @0x112038 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #34 randomise → F_Randomize(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x11203c ldr r1, [pc, #0xa0c]
 *   @0x112040 ldr r0, [pc, #0xa0c]
 *   @0x112044 mov r2, #1
 *   @0x112048 mov r3, #0
 *   @0x11204c ldr r1, [r4, r1]
 *   @0x112050 add r0, pc, r0
 *   @0x112054 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #35 abs → F_Abs(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x112058 ldr r1, [pc, #0x9f8]
 *   @0x11205c ldr r0, [pc, #0x9f8]
 *   @0x112060 mov r2, #1
 *   @0x112064 mov r3, #0
 *   @0x112068 ldr r1, [r4, r1]
 *   @0x11206c add r0, pc, r0
 *   @0x112070 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #36 round → F_Round(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x112074 ldr r1, [pc, #0x9e4]
 *   @0x112078 ldr r0, [pc, #0x9e4]
 *   @0x11207c mov r2, #1
 *   @0x112080 mov r3, #0
 *   @0x112084 ldr r1, [r4, r1]
 *   @0x112088 add r0, pc, r0
 *   @0x11208c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #37 floor → F_Floor(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x112090 ldr r1, [pc, #0x9d0]
 *   @0x112094 ldr r0, [pc, #0x9d0]
 *   @0x112098 mov r2, #1
 *   @0x11209c mov r3, #0
 *   @0x1120a0 ldr r1, [r4, r1]
 *   @0x1120a4 add r0, pc, r0
 *   @0x1120a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #38 ceil → F_Ceil(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1120ac ldr r1, [pc, #0x9bc]
 *   @0x1120b0 ldr r0, [pc, #0x9bc]
 *   @0x1120b4 mov r2, #1
 *   @0x1120b8 mov r3, #0
 *   @0x1120bc ldr r1, [r4, r1]
 *   @0x1120c0 add r0, pc, r0
 *   @0x1120c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #39 sign → F_Sign(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1120c8 ldr r1, [pc, #0x9a8]
 *   @0x1120cc ldr r0, [pc, #0x9a8]
 *   @0x1120d0 mov r2, #1
 *   @0x1120d4 mov r3, #0
 *   @0x1120d8 ldr r1, [r4, r1]
 *   @0x1120dc add r0, pc, r0
 *   @0x1120e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #40 frac → F_Frac(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1120e4 ldr r1, [pc, #0x994]
 *   @0x1120e8 ldr r0, [pc, #0x994]
 *   @0x1120ec mov r2, #1
 *   @0x1120f0 mov r3, #0
 *   @0x1120f4 ldr r1, [r4, r1]
 *   @0x1120f8 add r0, pc, r0
 *   @0x1120fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #41 sqrt → F_Sqrt(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x112100 ldr r1, [pc, #0x980]
 *   @0x112104 ldr r0, [pc, #0x980]
 *   @0x112108 mov r2, #1
 *   @0x11210c mov r3, #0
 *   @0x112110 ldr r1, [r4, r1]
 *   @0x112114 add r0, pc, r0
 *   @0x112118 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #42 sqr → F_Sqr(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x11211c ldr r1, [pc, #0x96c]
 *   @0x112120 ldr r0, [pc, #0x96c]
 *   @0x112124 mov r2, #1
 *   @0x112128 mov r3, #0
 *   @0x11212c ldr r1, [r4, r1]
 *   @0x112130 add r0, pc, r0
 *   @0x112134 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #43 exp → F_Exp(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x112138 ldr r1, [pc, #0x958]
 *   @0x11213c ldr r0, [pc, #0x958]
 *   @0x112140 mov r2, #1
 *   @0x112144 mov r3, #0
 *   @0x112148 ldr r1, [r4, r1]
 *   @0x11214c add r0, pc, r0
 *   @0x112150 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #44 ln → F_Ln(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x112154 ldr r1, [pc, #0x944]
 *   @0x112158 ldr r0, [pc, #0x944]
 *   @0x11215c mov r2, #1
 *   @0x112160 mov r3, #0
 *   @0x112164 ldr r1, [r4, r1]
 *   @0x112168 add r0, pc, r0
 *   @0x11216c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #45 log2 → F_Log2(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x112170 ldr r1, [pc, #0x930]
 *   @0x112174 ldr r0, [pc, #0x930]
 *   @0x112178 mov r2, #1
 *   @0x11217c mov r3, #0
 *   @0x112180 ldr r1, [r4, r1]
 *   @0x112184 add r0, pc, r0
 *   @0x112188 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #46 log10 → F_Log10(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x11218c ldr r1, [pc, #0x91c]
 *   @0x112190 ldr r0, [pc, #0x91c]
 *   @0x112194 mov r2, #1
 *   @0x112198 mov r3, #0
 *   @0x11219c ldr r1, [r4, r1]
 *   @0x1121a0 add r0, pc, r0
 *   @0x1121a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #47 sin → F_Sin(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1121a8 ldr r1, [pc, #0x908]
 *   @0x1121ac ldr r0, [pc, #0x908]
 *   @0x1121b0 mov r2, #1
 *   @0x1121b4 mov r3, #0
 *   @0x1121b8 ldr r1, [r4, r1]
 *   @0x1121bc add r0, pc, r0
 *   @0x1121c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #48 cos → F_Cos(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1121c4 ldr r1, [pc, #0x8f4]
 *   @0x1121c8 ldr r0, [pc, #0x8f4]
 *   @0x1121cc mov r2, #1
 *   @0x1121d0 mov r3, #0
 *   @0x1121d4 ldr r1, [r4, r1]
 *   @0x1121d8 add r0, pc, r0
 *   @0x1121dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #49 tan → F_Tan(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1121e0 ldr r1, [pc, #0x8e0]
 *   @0x1121e4 ldr r0, [pc, #0x8e0]
 *   @0x1121e8 mov r2, #1
 *   @0x1121ec mov r3, #0
 *   @0x1121f0 ldr r1, [r4, r1]
 *   @0x1121f4 add r0, pc, r0
 *   @0x1121f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #50 arcsin → F_ArcSin(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1121fc ldr r1, [pc, #0x8cc]
 *   @0x112200 ldr r0, [pc, #0x8cc]
 *   @0x112204 mov r2, #1
 *   @0x112208 mov r3, #0
 *   @0x11220c ldr r1, [r4, r1]
 *   @0x112210 add r0, pc, r0
 *   @0x112214 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #51 arccos → F_ArcCos(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x112218 ldr r1, [pc, #0x8b8]
 *   @0x11221c ldr r0, [pc, #0x8b8]
 *   @0x112220 mov r2, #1
 *   @0x112224 mov r3, #0
 *   @0x112228 ldr r1, [r4, r1]
 *   @0x11222c add r0, pc, r0
 *   @0x112230 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #52 arctan → F_ArcTan(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x112234 ldr r1, [pc, #0x8a4]
 *   @0x112238 ldr r0, [pc, #0x8a4]
 *   @0x11223c mov r2, #2
 *   @0x112240 mov r3, #0
 *   @0x112244 ldr r1, [r4, r1]
 *   @0x112248 add r0, pc, r0
 *   @0x11224c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #53 arctan2 → F_ArcTan2(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x112250 ldr r1, [pc, #0x890]
 *   @0x112254 ldr r0, [pc, #0x890]
 *   @0x112258 mov r2, #1
 *   @0x11225c mov r3, #0
 *   @0x112260 ldr r1, [r4, r1]
 *   @0x112264 add r0, pc, r0
 *   @0x112268 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #54 dsin → F_DSin(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x11226c ldr r1, [pc, #0x87c]
 *   @0x112270 ldr r0, [pc, #0x87c]
 *   @0x112274 mov r2, #1
 *   @0x112278 mov r3, #0
 *   @0x11227c ldr r1, [r4, r1]
 *   @0x112280 add r0, pc, r0
 *   @0x112284 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #55 dcos → F_DCos(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x112288 ldr r1, [pc, #0x868]
 *   @0x11228c ldr r0, [pc, #0x868]
 *   @0x112290 mov r2, #1
 *   @0x112294 mov r3, #0
 *   @0x112298 ldr r1, [r4, r1]
 *   @0x11229c add r0, pc, r0
 *   @0x1122a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #56 dtan → F_DTan(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1122a4 ldr r1, [pc, #0x854]
 *   @0x1122a8 ldr r0, [pc, #0x854]
 *   @0x1122ac mov r2, #1
 *   @0x1122b0 mov r3, #0
 *   @0x1122b4 ldr r1, [r4, r1]
 *   @0x1122b8 add r0, pc, r0
 *   @0x1122bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #57 darcsin → F_DArcSin(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1122c0 ldr r1, [pc, #0x840]
 *   @0x1122c4 ldr r0, [pc, #0x840]
 *   @0x1122c8 mov r2, #1
 *   @0x1122cc mov r3, #0
 *   @0x1122d0 ldr r1, [r4, r1]
 *   @0x1122d4 add r0, pc, r0
 *   @0x1122d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #58 darccos → F_DArcCos(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1122dc ldr r1, [pc, #0x82c]
 *   @0x1122e0 ldr r0, [pc, #0x82c]
 *   @0x1122e4 mov r2, #1
 *   @0x1122e8 mov r3, #0
 *   @0x1122ec ldr r1, [r4, r1]
 *   @0x1122f0 add r0, pc, r0
 *   @0x1122f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #59 darctan → F_DArcTan(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1122f8 ldr r1, [pc, #0x818]
 *   @0x1122fc ldr r0, [pc, #0x818]
 *   @0x112300 mov r2, #2
 *   @0x112304 mov r3, #0
 *   @0x112308 ldr r1, [r4, r1]
 *   @0x11230c add r0, pc, r0
 *   @0x112310 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #60 darctan2 → F_DArcTan2(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x112314 ldr r1, [pc, #0x804]
 *   @0x112318 ldr r0, [pc, #0x804]
 *   @0x11231c mov r2, #1
 *   @0x112320 mov r3, #0
 *   @0x112324 ldr r1, [r4, r1]
 *   @0x112328 add r0, pc, r0
 *   @0x11232c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #61 degtorad → F_DegToRad(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x112330 ldr r1, [pc, #0x7f0]
 *   @0x112334 ldr r0, [pc, #0x7f0]
 *   @0x112338 mov r2, #1
 *   @0x11233c mov r3, #0
 *   @0x112340 ldr r1, [r4, r1]
 *   @0x112344 add r0, pc, r0
 *   @0x112348 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #62 radtodeg → F_RadToDeg(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x11234c ldr r1, [pc, #0x7dc]
 *   @0x112350 ldr r0, [pc, #0x7dc]
 *   @0x112354 mov r2, #2
 *   @0x112358 mov r3, #0
 *   @0x11235c ldr r1, [r4, r1]
 *   @0x112360 add r0, pc, r0
 *   @0x112364 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #63 power → F_Power(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x112368 ldr r1, [pc, #0x7c8]
 *   @0x11236c ldr r0, [pc, #0x7c8]
 *   @0x112370 mov r2, #2
 *   @0x112374 mov r3, #0
 *   @0x112378 ldr r1, [r4, r1]
 *   @0x11237c add r0, pc, r0
 *   @0x112380 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #64 logn → F_Logn(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x112384 ldr r1, [pc, #0x7b4]
 *   @0x112388 ldr r0, [pc, #0x7b4]
 *   @0x11238c mvn r2, #0
 *   @0x112390 mov r3, #0
 *   @0x112394 ldr r1, [r4, r1]
 *   @0x112398 add r0, pc, r0
 *   @0x11239c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #65 min → F_Min(RValue&, CInstance*, CInstance*, int, RValue*) argc=-1 flag=0
 *   @0x1123a0 ldr r1, [pc, #0x7a0]
 *   @0x1123a4 ldr r0, [pc, #0x7a0]
 *   @0x1123a8 mvn r2, #0
 *   @0x1123ac mov r3, #0
 *   @0x1123b0 ldr r1, [r4, r1]
 *   @0x1123b4 add r0, pc, r0
 *   @0x1123b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #66 max → F_Max(RValue&, CInstance*, CInstance*, int, RValue*) argc=-1 flag=0
 *   @0x1123bc ldr r1, [pc, #0x78c]
 *   @0x1123c0 ldr r0, [pc, #0x78c]
 *   @0x1123c4 mov r2, #3
 *   @0x1123c8 mov r3, #0
 *   @0x1123cc ldr r1, [r4, r1]
 *   @0x1123d0 add r0, pc, r0
 *   @0x1123d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #67 min3 → F_Min3(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x1123d8 ldr r1, [pc, #0x778]
 *   @0x1123dc ldr r0, [pc, #0x778]
 *   @0x1123e0 mov r2, #3
 *   @0x1123e4 mov r3, #0
 *   @0x1123e8 ldr r1, [r4, r1]
 *   @0x1123ec add r0, pc, r0
 *   @0x1123f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #68 max3 → F_Max3(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x1123f4 ldr r1, [pc, #0x764]
 *   @0x1123f8 ldr r0, [pc, #0x764]
 *   @0x1123fc mvn r2, #0
 *   @0x112400 mov r3, #0
 *   @0x112404 ldr r1, [r4, r1]
 *   @0x112408 add r0, pc, r0
 *   @0x11240c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #69 mean → F_Mean(RValue&, CInstance*, CInstance*, int, RValue*) argc=-1 flag=0
 *   @0x112410 ldr r1, [pc, #0x750]
 *   @0x112414 ldr r0, [pc, #0x750]
 *   @0x112418 mvn r2, #0
 *   @0x11241c mov r3, #0
 *   @0x112420 ldr r1, [r4, r1]
 *   @0x112424 add r0, pc, r0
 *   @0x112428 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #70 median → F_Median(RValue&, CInstance*, CInstance*, int, RValue*) argc=-1 flag=0
 *   @0x11242c ldr r1, [pc, #0x73c]
 *   @0x112430 ldr r0, [pc, #0x73c]
 *   @0x112434 mvn r2, #0
 *   @0x112438 mov r3, #0
 *   @0x11243c ldr r1, [r4, r1]
 *   @0x112440 add r0, pc, r0
 *   @0x112444 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #71 choose → F_Choose(RValue&, CInstance*, CInstance*, int, RValue*) argc=-1 flag=0
 *   @0x112448 ldr r1, [pc, #0x728]
 *   @0x11244c ldr r0, [pc, #0x728]
 *   @0x112450 mov r2, #3
 *   @0x112454 mov r3, #1
 *   @0x112458 ldr r1, [r4, r1]
 *   @0x11245c add r0, pc, r0
 *   @0x112460 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #72 clamp → F_Clamp(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x112464 ldr r1, [pc, #0x714]
 *   @0x112468 ldr r0, [pc, #0x714]
 *   @0x11246c mov r2, #3
 *   @0x112470 mov r3, #1
 *   @0x112474 ldr r1, [r4, r1]
 *   @0x112478 add r0, pc, r0
 *   @0x11247c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #73 lerp → F_Lerp(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x112480 ldr r1, [pc, #0x700]
 *   @0x112484 ldr r0, [pc, #0x700]
 *   @0x112488 mov r2, #1
 *   @0x11248c mov r3, #0
 *   @0x112490 ldr r1, [r4, r1]
 *   @0x112494 add r0, pc, r0
 *   @0x112498 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #74 real → F_Real(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x11249c ldr r1, [pc, #0x6ec]
 *   @0x1124a0 ldr r0, [pc, #0x6ec]
 *   @0x1124a4 mov r2, #1
 *   @0x1124a8 mov r3, #0
 *   @0x1124ac ldr r1, [r4, r1]
 *   @0x1124b0 add r0, pc, r0
 *   @0x1124b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #75 bool → F_Bool(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1124b8 ldr r1, [pc, #0x6d8]
 *   @0x1124bc ldr r0, [pc, #0x6d8]
 *   @0x1124c0 mov r2, #1
 *   @0x1124c4 mov r3, #0
 *   @0x1124c8 ldr r1, [r4, r1]
 *   @0x1124cc add r0, pc, r0
 *   @0x1124d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #76 string → F_String(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1124d4 ldr r1, [pc, #0x6c4]
 *   @0x1124d8 ldr r0, [pc, #0x6c4]
 *   @0x1124dc mov r2, #1
 *   @0x1124e0 mov r3, #0
 *   @0x1124e4 ldr r1, [r4, r1]
 *   @0x1124e8 add r0, pc, r0
 *   @0x1124ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #77 int64 → F_Int64(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1124f0 ldr r1, [pc, #0x6b0]
 *   @0x1124f4 ldr r0, [pc, #0x6b0]
 *   @0x1124f8 mov r2, #1
 *   @0x1124fc mov r3, #0
 *   @0x112500 ldr r1, [r4, r1]
 *   @0x112504 add r0, pc, r0
 *   @0x112508 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #78 ptr → F_Ptr(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x11250c ldr r1, [pc, #0x69c]
 *   @0x112510 ldr r0, [pc, #0x69c]
 *   @0x112514 mov r2, #3
 *   @0x112518 mov r3, #0
 *   @0x11251c ldr r1, [r4, r1]
 *   @0x112520 add r0, pc, r0
 *   @0x112524 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #79 string_format → F_StringFormat(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x112528 ldr r1, [pc, #0x688]
 *   @0x11252c ldr r0, [pc, #0x688]
 *   @0x112530 mov r2, #1
 *   @0x112534 mov r3, #0
 *   @0x112538 ldr r1, [r4, r1]
 *   @0x11253c add r0, pc, r0
 *   @0x112540 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #80 chr → F_Chr(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x112544 ldr r1, [pc, #0x674]
 *   @0x112548 ldr r0, [pc, #0x674]
 *   @0x11254c mov r2, #1
 *   @0x112550 mov r3, #0
 *   @0x112554 ldr r1, [r4, r1]
 *   @0x112558 add r0, pc, r0
 *   @0x11255c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #81 ansi_char → F_AnsiChar(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x112560 ldr r1, [pc, #0x660]
 *   @0x112564 ldr r0, [pc, #0x660]
 *   @0x112568 mov r2, #1
 *   @0x11256c mov r3, #0
 *   @0x112570 ldr r1, [r4, r1]
 *   @0x112574 add r0, pc, r0
 *   @0x112578 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #82 ord → F_Ord(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x11257c ldr r1, [pc, #0x64c]
 *   @0x112580 ldr r0, [pc, #0x64c]
 *   @0x112584 mov r2, #1
 *   @0x112588 mov r3, #0
 *   @0x11258c ldr r1, [r4, r1]
 *   @0x112590 add r0, pc, r0
 *   @0x112594 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #83 string_length → F_StringLength(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x112598 ldr r1, [pc, #0x638]
 *   @0x11259c ldr r0, [pc, #0x638]
 *   @0x1125a0 mov r2, #2
 *   @0x1125a4 mov r3, #0
 *   @0x1125a8 ldr r1, [r4, r1]
 *   @0x1125ac add r0, pc, r0
 *   @0x1125b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #84 string_pos → F_StringPos(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1125b4 ldr r1, [pc, #0x624]
 *   @0x1125b8 ldr r0, [pc, #0x624]
 *   @0x1125bc mov r2, #3
 *   @0x1125c0 mov r3, #0
 *   @0x1125c4 ldr r1, [r4, r1]
 *   @0x1125c8 add r0, pc, r0
 *   @0x1125cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #85 string_copy → F_StringCopy(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x1125d0 ldr r1, [pc, #0x610]
 *   @0x1125d4 ldr r0, [pc, #0x610]
 *   @0x1125d8 mov r2, #2
 *   @0x1125dc mov r3, #0
 *   @0x1125e0 ldr r1, [r4, r1]
 *   @0x1125e4 add r0, pc, r0
 *   @0x1125e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #86 string_char_at → F_StringCharAt(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1125ec ldr r1, [pc, #0x5fc]
 *   @0x1125f0 ldr r0, [pc, #0x5fc]
 *   @0x1125f4 mov r2, #2
 *   @0x1125f8 mov r3, #0
 *   @0x1125fc ldr r1, [r4, r1]
 *   @0x112600 add r0, pc, r0
 *   @0x112604 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #87 string_ord_at → F_StringOrdAt(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x112608 ldr r1, [pc, #0x5e8]
 *   @0x11260c ldr r0, [pc, #0x5e8]
 *   @0x112610 mov r2, #1
 *   @0x112614 mov r3, #0
 *   @0x112618 ldr r1, [r4, r1]
 *   @0x11261c add r0, pc, r0
 *   @0x112620 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #88 string_byte_length → F_StringByteLength(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x112624 ldr r1, [pc, #0x5d4]
 *   @0x112628 ldr r0, [pc, #0x5d4]
 *   @0x11262c mov r2, #2
 *   @0x112630 mov r3, #0
 *   @0x112634 ldr r1, [r4, r1]
 *   @0x112638 add r0, pc, r0
 *   @0x11263c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #89 string_byte_at → F_StringByteAt(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x112640 ldr r1, [pc, #0x5c0]
 *   @0x112644 ldr r0, [pc, #0x5c0]
 *   @0x112648 mov r2, #3
 *   @0x11264c mov r3, #0
 *   @0x112650 ldr r1, [r4, r1]
 *   @0x112654 add r0, pc, r0
 *   @0x112658 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #90 string_set_byte_at → F_StringSetByteAt(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x11265c ldr r1, [pc, #0x5ac]
 *   @0x112660 ldr r0, [pc, #0x5ac]
 *   @0x112664 mov r2, #3
 *   @0x112668 mov r3, #0
 *   @0x11266c ldr r1, [r4, r1]
 *   @0x112670 add r0, pc, r0
 *   @0x112674 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #91 string_delete → F_StringDelete(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x112678 ldr r1, [pc, #0x598]
 *   @0x11267c ldr r0, [pc, #0x598]
 *   @0x112680 mov r2, #3
 *   @0x112684 mov r3, #0
 *   @0x112688 ldr r1, [r4, r1]
 *   @0x11268c add r0, pc, r0
 *   @0x112690 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #92 string_insert → F_StringInsert(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x112694 ldr r1, [pc, #0x584]
 *   @0x112698 ldr r0, [pc, #0x584]
 *   @0x11269c mov r2, #1
 *   @0x1126a0 mov r3, #0
 *   @0x1126a4 ldr r1, [r4, r1]
 *   @0x1126a8 add r0, pc, r0
 *   @0x1126ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #93 string_lower → F_StringLower(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1126b0 ldr r1, [pc, #0x570]
 *   @0x1126b4 ldr r0, [pc, #0x570]
 *   @0x1126b8 mov r2, #1
 *   @0x1126bc mov r3, #0
 *   @0x1126c0 ldr r1, [r4, r1]
 *   @0x1126c4 add r0, pc, r0
 *   @0x1126c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #94 string_upper → F_StringUpper(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1126cc ldr r1, [pc, #0x55c]
 *   @0x1126d0 ldr r0, [pc, #0x55c]
 *   @0x1126d4 mov r2, #2
 *   @0x1126d8 mov r3, #0
 *   @0x1126dc ldr r1, [r4, r1]
 *   @0x1126e0 add r0, pc, r0
 *   @0x1126e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #95 string_repeat → F_StringRepeat(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1126e8 ldr r1, [pc, #0x548]
 *   @0x1126ec ldr r0, [pc, #0x548]
 *   @0x1126f0 mov r2, #1
 *   @0x1126f4 mov r3, #0
 *   @0x1126f8 ldr r1, [r4, r1]
 *   @0x1126fc add r0, pc, r0
 *   @0x112700 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #96 string_letters → F_StringLetters(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x112704 ldr r1, [pc, #0x534]
 *   @0x112708 ldr r0, [pc, #0x534]
 *   @0x11270c mov r2, #1
 *   @0x112710 mov r3, #0
 *   @0x112714 ldr r1, [r4, r1]
 *   @0x112718 add r0, pc, r0
 *   @0x11271c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #97 string_digits → F_StringDigits(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x112720 ldr r1, [pc, #0x520]
 *   @0x112724 ldr r0, [pc, #0x520]
 *   @0x112728 mov r2, #1
 *   @0x11272c mov r3, #0
 *   @0x112730 ldr r1, [r4, r1]
 *   @0x112734 add r0, pc, r0
 *   @0x112738 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #98 string_lettersdigits → F_StringLettersDigits(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x11273c ldr r1, [pc, #0x50c]
 *   @0x112740 ldr r0, [pc, #0x50c]
 *   @0x112744 mov r2, #3
 *   @0x112748 mov r3, #0
 *   @0x11274c ldr r1, [r4, r1]
 *   @0x112750 add r0, pc, r0
 *   @0x112754 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #99 string_replace → F_StringReplace(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x112758 ldr r1, [pc, #0x4f8]
 *   @0x11275c ldr r0, [pc, #0x4f8]
 *   @0x112760 mov r2, #3
 *   @0x112764 mov r3, #0
 *   @0x112768 ldr r1, [r4, r1]
 *   @0x11276c add r0, pc, r0
 *   @0x112770 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #100 string_replace_all → F_StringReplaceAll(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x112774 ldr r1, [pc, #0x4e4]
 *   @0x112778 ldr r0, [pc, #0x4e4]
 *   @0x11277c mov r2, #2
 *   @0x112780 mov r3, #0
 *   @0x112784 ldr r1, [r4, r1]
 *   @0x112788 add r0, pc, r0
 *   @0x11278c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #101 string_count → F_StringCount(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x112790 ldr r1, [pc, #0x4d0]
 *   @0x112794 ldr r0, [pc, #0x4d0]
 *   @0x112798 mov r2, #1
 *   @0x11279c mov r3, #0
 *   @0x1127a0 ldr r1, [r4, r1]
 *   @0x1127a4 add r0, pc, r0
 *   @0x1127a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #102 string_hash_to_newline → F_StringHashToNewline(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1127ac ldr r1, [pc, #0x4bc]
 *   @0x1127b0 ldr r0, [pc, #0x4bc]
 *   @0x1127b4 mov r2, #4
 *   @0x1127b8 mov r3, #0
 *   @0x1127bc ldr r1, [r4, r1]
 *   @0x1127c0 add r0, pc, r0
 *   @0x1127c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #103 point_distance → F_PointDistance(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x1127c8 ldr r1, [pc, #0x4a8]
 *   @0x1127cc ldr r0, [pc, #0x4a8]
 *   @0x1127d0 mov r2, #4
 *   @0x1127d4 mov r3, #0
 *   @0x1127d8 ldr r1, [r4, r1]
 *   @0x1127dc add r0, pc, r0
 *   @0x1127e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #104 point_direction → F_PointDirection(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x1127e4 ldr r1, [pc, #0x494]
 *   @0x1127e8 ldr r0, [pc, #0x494]
 *   @0x1127ec mov r2, #2
 *   @0x1127f0 mov r3, #0
 *   @0x1127f4 ldr r1, [r4, r1]
 *   @0x1127f8 add r0, pc, r0
 *   @0x1127fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #105 lengthdir_x → F_LengthDirX(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x112800 ldr r1, [pc, #0x480]
 *   @0x112804 ldr r0, [pc, #0x480]
 *   @0x112808 mov r2, #2
 *   @0x11280c mov r3, #0
 *   @0x112810 ldr r1, [r4, r1]
 *   @0x112814 add r0, pc, r0
 *   @0x112818 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #106 lengthdir_y → F_LengthDirY(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x11281c ldr r1, [pc, #0x46c]
 *   @0x112820 ldr r0, [pc, #0x46c]
 *   @0x112824 mov r2, #6
 *   @0x112828 mov r3, #0
 *   @0x11282c ldr r1, [r4, r1]
 *   @0x112830 add r0, pc, r0
 *   @0x112834 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #107 point_distance_3d → F_PointDistance_3D(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=0
 *   @0x112838 ldr r1, [pc, #0x458]
 *   @0x11283c ldr r0, [pc, #0x458]
 *   @0x112840 mov r2, #4
 *   @0x112844 mov r3, #0
 *   @0x112848 ldr r1, [r4, r1]
 *   @0x11284c add r0, pc, r0
 *   @0x112850 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #108 dot_product → F_DotProduct(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x112854 ldr r1, [pc, #0x444]
 *   @0x112858 ldr r0, [pc, #0x444]
 *   @0x11285c mov r2, #4
 *   @0x112860 mov r3, #0
 *   @0x112864 ldr r5, [r4, r1]
 *   @0x112868 add r0, pc, r0
 *   @0x11286c mov r1, r5
 *   @0x112870 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #109 dot_product_normalised → F_DotProduct_Normalised(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x112874 ldr r0, [pc, #0x42c]
 *   @0x112878 mov r1, r5
 *   @0x11287c mov r2, #4
 *   @0x112880 add r0, pc, r0
 *   @0x112884 mov r3, #0
 *   @0x112888 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #110 dot_product_normalized → F_DotProduct_Normalised(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x11288c ldr r1, [pc, #0x418]
 *   @0x112890 ldr r0, [pc, #0x418]
 *   @0x112894 mov r2, #6
 *   @0x112898 mov r3, #0
 *   @0x11289c ldr r1, [r4, r1]
 *   @0x1128a0 add r0, pc, r0
 *   @0x1128a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #111 dot_product_3d → F_DotProduct_3D(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=0
 *   @0x1128a8 ldr r1, [pc, #0x404]
 *   @0x1128ac ldr r0, [pc, #0x404]
 *   @0x1128b0 mov r2, #6
 *   @0x1128b4 mov r3, #0
 *   @0x1128b8 ldr r5, [r4, r1]
 *   @0x1128bc add r0, pc, r0
 *   @0x1128c0 mov r1, r5
 *   @0x1128c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #112 dot_product_3d_normalised → F_DotProduct_3D_Normalised(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=0
 *   @0x1128c8 ldr r0, [pc, #0x3ec]
 *   @0x1128cc mov r1, r5
 *   @0x1128d0 mov r2, #6
 *   @0x1128d4 add r0, pc, r0
 *   @0x1128d8 mov r3, #0
 *   @0x1128dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #113 dot_product_3d_normalized → F_DotProduct_3D_Normalised(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=0
 *   @0x1128e0 ldr r1, [pc, #0x3d8]
 *   @0x1128e4 ldr r0, [pc, #0x3d8]
 *   @0x1128e8 mov r2, #1
 *   @0x1128ec mov r3, #0
 *   @0x1128f0 ldr r1, [r4, r1]
 *   @0x1128f4 add r0, pc, r0
 *   @0x1128f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #114 math_set_epsilon → F_MathSetEpsilon(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1128fc ldr r1, [pc, #0x3c4]
 *   @0x112900 ldr r0, [pc, #0x3c4]
 *   @0x112904 mov r2, #0
 *   @0x112908 mov r3, r2
 *   @0x11290c ldr r1, [r4, r1]
 *   @0x112910 add r0, pc, r0
 *   @0x112914 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #115 math_get_epsilon → F_MathGetEpsilon(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x112918 ldr r1, [pc, #0x3b0]
 *   @0x11291c ldr r0, [pc, #0x3b0]
 *   @0x112920 mov r2, #1
 *   @0x112924 mov r3, #0
 *   @0x112928 ldr r1, [r4, r1]
 *   @0x11292c add r0, pc, r0
 *   @0x112930 pop {r4, r5, r6, lr}
 *   @0x112934 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #116 angle_difference → F_MathAngleDifference(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x112938 eoreq pc, sp, r0, ror #31
 *   @0x11293c .word 0xffffc604
 *   @0x112940 eoreq r7, r2, r8, lsr #8
 *   @0x112944 .word 0xffffc608
 *   @0x112948 eoreq r7, r2, r4, lsl r4
 *   @0x11294c .word 0xffffc60c
 *   @0x112950 eoreq r7, r2, r0, lsl #8
 *   @0x112954 .word 0xffffc610
 *   @0x112958 .word 0x002273f0
 *   @0x11295c .word 0xffffc614
 *   @0x112960 eoreq r7, r2, r0, ror #7
 *   @0x112964 .word 0xffffc618
 *   @0x112968 .word 0x002273d4
 *   @0x11296c .word 0xffffc61c
 *   @0x112970 eoreq r7, r2, r4, asr #7
 *   @0x112974 .word 0xffffc620
 *   @0x112978 .word 0x002273b4
 *   @0x11297c .word 0xffffc624
 *   @0x112980 eoreq r7, r2, r0, lsr #7
 *   @0x112984 .word 0xffffc628
 *   @0x112988 eoreq r7, r2, r12, lsl #7
 *   @0x11298c .word 0xffffc62c
 *   @0x112990 eoreq r7, r2, r8, ror r3
 *   @0x112994 .word 0xffffc630
 *   @0x112998 eoreq r7, r2, r8, ror #6
 *   @0x11299c .word 0xffffc634
 *   @0x1129a0 eoreq r7, r2, r4, asr r3
 *   @0x1129a4 .word 0xffffc638
 *   @0x1129a8 eoreq r7, r2, r8, asr #6
 *   @0x1129ac .word 0xffffc63c
 *   @0x1129b0 eoreq r7, r2, r12, lsr r3
 *   @0x1129b4 .word 0xffffc640
 *   @0x1129b8 eoreq r7, r2, r0, lsr r3
 *   @0x1129bc .word 0xffffc644
 *   @0x1129c0 eoreq r7, r2, r0, lsr #6
 *   @0x1129c4 .word 0xffffc648
 *   @0x1129c8 eoreq r7, r2, r0, lsl r3
 *   @0x1129cc .word 0xffffc64c
 *   @0x1129d0 eoreq r7, r2, r4, lsl #6
 *   @0x1129d4 .word 0xffffc650
 *   @0x1129d8 .word 0x002272f8
 *   @0x1129dc .word 0xffffc654
 *   @0x1129e0 eoreq r7, r2, r12, ror #5
 *   @0x1129e4 .word 0xffffc658
 *   @0x1129e8 eoreq r7, r2, r0, ror #5
 *   @0x1129ec .word 0xffffc65c
 *   @0x1129f0 .word 0x002272d8
 *   @0x1129f4 .word 0xffffc660
 *   @0x1129f8 .word 0x002272d0
 *   @0x1129fc .word 0xffffc664
 *   @0x112a00 eoreq r7, r2, r4, asr #5
 *   @0x112a04 .word 0xffffc668
 *   @0x112a08 .word 0x002272b8
 *   @0x112a0c .word 0xffffc66c
 *   @0x112a10 eoreq r7, r2, r8, lsr #5
 *   @0x112a14 .word 0xffffc670
 *   @0x112a18 mlaeq r2, r4, r2, r7
 *   @0x112a1c .word 0xffffc674
 *   @0x112a20 eoreq r7, r2, r8, lsl #5
 *   @0x112a24 .word 0xffffc678
 *   @0x112a28 eoreq r7, r2, r4, ror r2
 *   @0x112a2c .word 0xffffc67c
 *   @0x112a30 eoreq r7, r2, r8, ror #4
 *   @0x112a34 .word 0xffffc680
 *   @0x112a38 eoreq r7, r2, r4, ror #4
 *   @0x112a3c .word 0xffffc684
 *   @0x112a40 eoreq r7, r2, r8, asr r2
 *   @0x112a44 .word 0xffffc688
 *   @0x112a48 eoreq r7, r2, r12, asr #4
 *   @0x112a4c eoreq r7, r2, r12, lsr r2
 *   @0x112a50 .word 0xffffc68c
 *   @0x112a54 eoreq r7, r2, r12, lsr #4
 *   @0x112a58 .word 0xffffc690
 *   @0x112a5c eoreq r7, r2, r4, lsl r2
 *   @0x112a60 .word 0xffffc694
 *   @0x112a64 eoreq r7, r2, r0, lsl #4
 *   @0x112a68 .word 0xffffc698
 *   @0x112a6c eoreq r7, r2, r12, ror #3
 *   @0x112a70 .word 0xffffc69c
 *   @0x112a74 .word 0x002271d8
 *   @0x112a78 .word 0xffffc6a0
 *   @0x112a7c eoreq r7, r2, r4, asr #3
 *   @0x112a80 .word 0xffffc6a4
 *   @0x112a84 .word 0x002271b0
 *   @0x112a88 .word 0xffffc6a8
 *   @0x112a8c mlaeq r2, r12, r1, r7
 *   @0x112a90 .word 0xffffc6ac
 *   @0x112a94 eoreq r7, r2, r4, lsl #3
 *   @0x112a98 .word 0xffffc6b0
 *   @0x112a9c eoreq r7, r2, r12, ror #2
 *   @0x112aa0 .word 0xffffc6b4
 *   @0x112aa4 eoreq r7, r2, r4, asr r1
 *   @0x112aa8 .word 0xffffc6b8
 *   @0x112aac eoreq r7, r2, r0, asr #2
 *   @0x112ab0 .word 0xffffc6bc
 *   @0x112ab4 eoreq r7, r2, r12, lsr #2
 *   @0x112ab8 .word 0xffffc6c0
 *   @0x112abc eoreq r7, r2, r4, lsl r1
 *   @0x112ac0 .word 0xffffc6c4
 *   @0x112ac4 .word 0x002270fc
 *   @0x112ac8 .word 0xffffc6c8
 *   @0x112acc eoreq r7, r2, r4, ror #1
 *   @0x112ad0 .word 0xffffc6cc
 *   @0x112ad4 .word 0x002270d0
 *   @0x112ad8 .word 0xffffc6d0
 *   @0x112adc strhteq r7, [r2], -r12
 *   @0x112ae0 .word 0xffffc6d4
 *   @0x112ae4 eoreq r7, r2, r8, lsr #1
 *   @0x112ae8 .word 0xffffc6d8
 *   @0x112aec mlaeq r2, r4, r0, r7
 *   @0x112af0 .word 0xffffc6dc
 *   @0x112af4 eoreq r7, r2, r0, lsl #1
 *   @0x112af8 .word 0xffffc6e0
 *   @0x112afc eoreq r7, r2, r12, rrx
 *   @0x112b00 .word 0xffffc6e4
 *   @0x112b04 eoreq r7, r2, r8, asr r0
 *   @0x112b08 .word 0xffffc6e8
 *   @0x112b0c eoreq r7, r2, r4, asr #32
 *   @0x112b10 .word 0xffffc6ec
 *   @0x112b14 eoreq r7, r2, r0, lsr r0
 *   @0x112b18 .word 0xffffc6f0
 *   @0x112b1c eoreq r7, r2, r12, lsl r0
 *   @0x112b20 .word 0xffffc6f4
 *   @0x112b24 eoreq r7, r2, r12
 *   @0x112b28 .word 0xffffc6f8
 *   @0x112b2c .word 0x00226ffc
 *   @0x112b30 .word 0xffffc6fc
 *   @0x112b34 eoreq r6, r2, r12, ror #31
 *   @0x112b38 .word 0xffffc700
 *   @0x112b3c .word 0x00226fd8
 *   @0x112b40 .word 0xffffc704
 *   @0x112b44 eoreq r6, r2, r4, asr #31
 *   @0x112b48 .word 0xffffc708
 *   @0x112b4c eoreq r6, r2, r12, lsr #31
 *   @0x112b50 .word 0xffffc70c
 *   @0x112b54 mlaeq r2, r4, pc, r6
 *   @0x112b58 .word 0xffffc710
 *   @0x112b5c eoreq r6, r2, r0, lsl #31
 *   @0x112b60 .word 0xffffc714
 *   @0x112b64 eoreq r6, r2, r12, ror #30
 *   @0x112b68 .word 0xffffc718
 *   @0x112b6c eoreq r6, r2, r8, asr pc
 *   @0x112b70 .word 0xffffc71c
 *   @0x112b74 eoreq r6, r2, r4, asr #30
 *   @0x112b78 .word 0xffffc720
 *   @0x112b7c eoreq r6, r2, r0, lsr pc
 *   @0x112b80 .word 0xffffc724
 *   @0x112b84 eoreq r6, r2, r12, lsl pc
 *   @0x112b88 .word 0xffffc728
 *   @0x112b8c eoreq r6, r2, r8, lsl #30
 *   @0x112b90 .word 0xffffc72c
 *   @0x112b94 eoreq pc, r1, r0, asr #27
 *   @0x112b98 .word 0xffffc730
 *   @0x112b9c eoreq lr, r1, r12, asr r3
 *   @0x112ba0 .word 0xffffc734
 *   @0x112ba4 mlaeq r1, r0, sp, pc
 *   @0x112ba8 .word 0xffffc738
 *   @0x112bac eoreq pc, r1, r8, ror #26
 *   @0x112bb0 .word 0xffffc73c
 *   @0x112bb4 eoreq r6, r2, r4, lsl #29
 *   @0x112bb8 .word 0xffffc740
 *   @0x112bbc eoreq r6, r2, r8, ror lr
 *   @0x112bc0 .word 0xffffc744
 *   @0x112bc4 eoreq r6, r2, r0, ror #28
 *   @0x112bc8 .word 0xffffc748
 *   @0x112bcc eoreq r6, r2, r0, asr lr
 *   @0x112bd0 .word 0xffffc74c
 *   @0x112bd4 eoreq r6, r2, r8, lsr lr
 *   @0x112bd8 .word 0xffffc750
 *   @0x112bdc eoreq r6, r2, r12, lsr #28
 *   @0x112be0 .word 0xffffc754
 *   @0x112be4 eoreq r6, r2, r12, lsl lr
 *   @0x112be8 .word 0xffffc758
 *   @0x112bec eoreq r6, r2, r12, lsl #28
 *   @0x112bf0 .word 0xffffc75c
 *   @0x112bf4 eoreq r6, r2, r0, lsl #28
 *   @0x112bf8 .word 0xffffc760
 *   @0x112bfc .word 0x00226df4
 *   @0x112c00 .word 0xffffc764
 *   @0x112c04 eoreq r6, r2, r12, ror #27
 *   @0x112c08 .word 0xffffc768
 *   @0x112c0c eoreq r6, r2, r0, ror #27
 *   @0x112c10 .word 0xffffc76c
 *   @0x112c14 .word 0x00226dd8
 *   @0x112c18 .word 0xffffc770
 *   @0x112c1c eoreq r6, r2, r12, asr #27
 *   @0x112c20 .word 0xffffc774
 *   @0x112c24 eoreq r6, r2, r0, asr #27
 *   @0x112c28 .word 0xffffc778
 *   @0x112c2c .word 0x00226db4
 *   @0x112c30 .word 0xffffc77c
 *   @0x112c34 eoreq r6, r2, r8, lsr #27
 *   @0x112c38 .word 0xffffc780
 *   @0x112c3c mlaeq r2, r12, sp, r6
 *   @0x112c40 .word 0xffffc784
 *   @0x112c44 mlaeq r2, r0, sp, r6
 *   @0x112c48 .word 0xffffc788
 *   @0x112c4c eoreq r6, r2, r4, lsl #27
 *   @0x112c50 .word 0xffffc78c
 *   @0x112c54 eoreq r6, r2, r0, lsl #27
 *   @0x112c58 .word 0xffffc790
 *   @0x112c5c eoreq r6, r2, r4, ror sp
 *   @0x112c60 .word 0xffffc794
 *   @0x112c64 eoreq r6, r2, r12, ror #26
 *   @0x112c68 .word 0xffffc798
 *   @0x112c6c eoreq r6, r2, r0, ror #26
 *   @0x112c70 .word 0xffffc79c
 *   @0x112c74 eoreq r6, r2, r12, asr sp
 *   @0x112c78 .word 0xffffc7a0
 *   @0x112c7c eoreq r6, r2, r0, asr sp
 *   @0x112c80 .word 0xffffc7a4
 *   @0x112c84 eoreq r6, r2, r4, asr #26
 *   @0x112c88 .word 0xffffc7a8
 *   @0x112c8c eoreq r6, r2, r4, lsr sp
 *   @0x112c90 .word 0xffffc7ac
 *   @0x112c94 eoreq r6, r2, r4, lsr #26
 *   @0x112c98 .word 0xffffc7b0
 *   @0x112c9c eoreq r6, r2, r12, lsl sp
 *   @0x112ca0 .word 0xffffc7b4
 *   @0x112ca4 eoreq r6, r2, r12, lsl #26
 *   @0x112ca8 eoreq r6, r2, r12, lsl #26
 *   @0x112cac .word 0xffffc7b8
 *   @0x112cb0 eoreq r6, r2, r4, lsl #26
 *   @0x112cb4 .word 0xffffc7bc
 *   @0x112cb8 .word 0x00226cf8
 *   @0x112cbc .word 0x00226cfc
 *   @0x112cc0 .word 0xffffc7c0
 *   @0x112cc4 .word 0x00226cf8
 *   @0x112cc8 .word 0xffffc7c4
 *   @0x112ccc .word 0x00226cf0
 *   @0x112cd0 .word 0xffffc7c8
 *   @0x112cd4 eoreq r6, r2, r8, ror #25
 *
 * ══ §4/4 InitMiscFunctions  0x118720..0x1194cc  size 3500  875 条（681 条指令 + 194 个池字）══
 * @func 0x118720 0x1194cc  size 3500  875 条
 * 注册 96 条｜唯一名 96｜唯一函数指针 96｜argc -1:2 0:10 1:35 2:25 3:12 4:2 5:2 6:4 7:2 8:1 9:1｜flag 0:73 1:23
 * 首条 #0 event_inherited（0x118744）→ 末条 #95 game_get_speed（0x1191c0）
 * 名字族（前 8）: date×49 external×21 variable×7 event×4 clipboard×3 window×2 show×2 debug×2
 * 游戏实际调用的 99 个内建里落在本表: 0 个
 * 条件跳转 1 处: 0x1187ac(bne)
 * 表: asm/init-tables/init-InitMiscFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: 无（本函数每条注册的四实参全部解出，控制流全部走到）
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x118720 push {r4, lr}
 *   @0x118724 mov r2, #0
 *   @0x118728 ldr r4, [pc, #0xa94]
 *   @0x11872c mov r3, r2
 *   @0x118730 ldr r1, [pc, #0xa90]
 *   @0x118734 add r4, pc, r4
 *   @0x118738 ldr r0, [pc, #0xa8c]
 *   @0x11873c add r0, pc, r0
 *   @0x118740 ldr r1, [r4, r1]
 *   @0x118744 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 event_inherited → F_EventInherited(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x118748 ldr r1, [pc, #0xa80]
 *   @0x11874c ldr r0, [pc, #0xa80]
 *   @0x118750 mov r2, #2
 *   @0x118754 mov r3, #0
 *   @0x118758 add r0, pc, r0
 *   @0x11875c ldr r1, [r4, r1]
 *   @0x118760 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 event_perform → F_EventPerform(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x118764 ldr r1, [pc, #0xa6c]
 *   @0x118768 ldr r0, [pc, #0xa6c]
 *   @0x11876c mov r2, #1
 *   @0x118770 mov r3, #0
 *   @0x118774 add r0, pc, r0
 *   @0x118778 ldr r1, [r4, r1]
 *   @0x11877c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 event_user → F_EventUser(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118780 ldr r1, [pc, #0xa58]
 *   @0x118784 ldr r0, [pc, #0xa58]
 *   @0x118788 mov r3, #0
 *   @0x11878c mov r2, #3
 *   @0x118790 add r0, pc, r0
 *   @0x118794 ldr r1, [r4, r1]
 *   @0x118798 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 event_perform_object → F_EventObject(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x11879c ldr r3, [pc, #0xa44]
 *   @0x1187a0 ldr r3, [r4, r3]
 *   @0x1187a4 ldrb r3, [r3]
 *   @0x1187a8 cmp r3, #0
 *   @0x1187ac bne 0x1189fc <_Z17InitMiscFunctionsv+0x2dc>   —— 条件跳转 → 0x1189fc
 *   @0x1187b0 ldr r1, [pc, #0xa34]
 *   @0x1187b4 mvn r2, #0
 *   @0x1187b8 ldr r0, [pc, #0xa30]
 *   @0x1187bc mov r3, #1
 *   @0x1187c0 add r0, pc, r0
 *   @0x1187c4 ldr r1, [r4, r1]
 *   @0x1187c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #4 external_define → F_ExternalDefine(RValue&, CInstance*, CInstance*, int, RValue*) argc=-1 flag=1
 *   @0x1187cc ldr r1, [pc, #0xa20]
 *   @0x1187d0 ldr r0, [pc, #0xa20]
 *   @0x1187d4 mvn r2, #0
 *   @0x1187d8 mov r3, #1
 *   @0x1187dc add r0, pc, r0
 *   @0x1187e0 ldr r1, [r4, r1]
 *   @0x1187e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #5 external_call → F_ExternalCall(RValue&, CInstance*, CInstance*, int, RValue*) argc=-1 flag=1
 *   @0x1187e8 ldr r1, [pc, #0xa0c]
 *   @0x1187ec ldr r0, [pc, #0xa0c]
 *   @0x1187f0 mov r2, #1
 *   @0x1187f4 mov r3, r2
 *   @0x1187f8 add r0, pc, r0
 *   @0x1187fc ldr r1, [r4, r1]
 *   @0x118800 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #6 external_free → F_ExternalFree(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x118804 ldr r1, [pc, #0x9f8]
 *   @0x118808 ldr r0, [pc, #0x9f8]
 *   @0x11880c mov r2, #3
 *   @0x118810 mov r3, #1
 *   @0x118814 add r0, pc, r0
 *   @0x118818 ldr r1, [r4, r1]
 *   @0x11881c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #7 external_define0 → F_ExternalDefine0(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x118820 ldr r1, [pc, #0x9e4]
 *   @0x118824 ldr r0, [pc, #0x9e4]
 *   @0x118828 mov r2, #1
 *   @0x11882c mov r3, r2
 *   @0x118830 add r0, pc, r0
 *   @0x118834 ldr r1, [r4, r1]
 *   @0x118838 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #8 external_call0 → F_ExternalCall0(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x11883c ldr r1, [pc, #0x9d0]
 *   @0x118840 ldr r0, [pc, #0x9d0]
 *   @0x118844 mov r2, #4
 *   @0x118848 mov r3, #1
 *   @0x11884c add r0, pc, r0
 *   @0x118850 ldr r1, [r4, r1]
 *   @0x118854 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #9 external_define1 → F_ExternalDefine1(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x118858 ldr r1, [pc, #0x9bc]
 *   @0x11885c ldr r0, [pc, #0x9bc]
 *   @0x118860 mov r2, #2
 *   @0x118864 mov r3, #1
 *   @0x118868 add r0, pc, r0
 *   @0x11886c ldr r1, [r4, r1]
 *   @0x118870 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #10 external_call1 → F_ExternalCall1(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x118874 ldr r1, [pc, #0x9a8]
 *   @0x118878 ldr r0, [pc, #0x9a8]
 *   @0x11887c mov r2, #5
 *   @0x118880 mov r3, #1
 *   @0x118884 add r0, pc, r0
 *   @0x118888 ldr r1, [r4, r1]
 *   @0x11888c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #11 external_define2 → F_ExternalDefine2(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x118890 ldr r1, [pc, #0x994]
 *   @0x118894 ldr r0, [pc, #0x994]
 *   @0x118898 mov r2, #3
 *   @0x11889c mov r3, #1
 *   @0x1188a0 add r0, pc, r0
 *   @0x1188a4 ldr r1, [r4, r1]
 *   @0x1188a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #12 external_call2 → F_ExternalCall2(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x1188ac ldr r1, [pc, #0x980]
 *   @0x1188b0 ldr r0, [pc, #0x980]
 *   @0x1188b4 mov r2, #6
 *   @0x1188b8 mov r3, #1
 *   @0x1188bc add r0, pc, r0
 *   @0x1188c0 ldr r1, [r4, r1]
 *   @0x1188c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #13 external_define3 → F_ExternalDefine3(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x1188c8 ldr r1, [pc, #0x96c]
 *   @0x1188cc ldr r0, [pc, #0x96c]
 *   @0x1188d0 mov r2, #4
 *   @0x1188d4 mov r3, #1
 *   @0x1188d8 add r0, pc, r0
 *   @0x1188dc ldr r1, [r4, r1]
 *   @0x1188e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #14 external_call3 → F_ExternalCall3(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x1188e4 ldr r1, [pc, #0x958]
 *   @0x1188e8 ldr r0, [pc, #0x958]
 *   @0x1188ec mov r2, #7
 *   @0x1188f0 mov r3, #1
 *   @0x1188f4 add r0, pc, r0
 *   @0x1188f8 ldr r1, [r4, r1]
 *   @0x1188fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #15 external_define4 → F_ExternalDefine4(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x118900 ldr r1, [pc, #0x944]
 *   @0x118904 ldr r0, [pc, #0x944]
 *   @0x118908 mov r2, #5
 *   @0x11890c mov r3, #1
 *   @0x118910 add r0, pc, r0
 *   @0x118914 ldr r1, [r4, r1]
 *   @0x118918 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #16 external_call4 → F_ExternalCall4(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x11891c ldr r1, [pc, #0x930]
 *   @0x118920 ldr r0, [pc, #0x930]
 *   @0x118924 mov r2, #3
 *   @0x118928 mov r3, #1
 *   @0x11892c add r0, pc, r0
 *   @0x118930 ldr r1, [r4, r1]
 *   @0x118934 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #17 external_define5 → F_ExternalDefine5(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x118938 ldr r1, [pc, #0x91c]
 *   @0x11893c ldr r0, [pc, #0x91c]
 *   @0x118940 mov r2, #6
 *   @0x118944 mov r3, #1
 *   @0x118948 add r0, pc, r0
 *   @0x11894c ldr r1, [r4, r1]
 *   @0x118950 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #18 external_call5 → F_ExternalCall5(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x118954 ldr r1, [pc, #0x908]
 *   @0x118958 ldr r0, [pc, #0x908]
 *   @0x11895c mov r2, #3
 *   @0x118960 mov r3, #1
 *   @0x118964 add r0, pc, r0
 *   @0x118968 ldr r1, [r4, r1]
 *   @0x11896c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #19 external_define6 → F_ExternalDefine6(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x118970 ldr r1, [pc, #0x8f4]
 *   @0x118974 ldr r0, [pc, #0x8f4]
 *   @0x118978 mov r2, #7
 *   @0x11897c mov r3, #1
 *   @0x118980 add r0, pc, r0
 *   @0x118984 ldr r1, [r4, r1]
 *   @0x118988 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #20 external_call6 → F_ExternalCall6(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x11898c ldr r1, [pc, #0x8e0]
 *   @0x118990 ldr r0, [pc, #0x8e0]
 *   @0x118994 mov r2, #3
 *   @0x118998 mov r3, #1
 *   @0x11899c add r0, pc, r0
 *   @0x1189a0 ldr r1, [r4, r1]
 *   @0x1189a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #21 external_define7 → F_ExternalDefine7(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x1189a8 ldr r1, [pc, #0x8cc]
 *   @0x1189ac ldr r0, [pc, #0x8cc]
 *   @0x1189b0 mov r2, #8
 *   @0x1189b4 mov r3, #1
 *   @0x1189b8 add r0, pc, r0
 *   @0x1189bc ldr r1, [r4, r1]
 *   @0x1189c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #22 external_call7 → F_ExternalCall7(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x1189c4 ldr r1, [pc, #0x8b8]
 *   @0x1189c8 ldr r0, [pc, #0x8b8]
 *   @0x1189cc mov r2, #3
 *   @0x1189d0 mov r3, #1
 *   @0x1189d4 add r0, pc, r0
 *   @0x1189d8 ldr r1, [r4, r1]
 *   @0x1189dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #23 external_define8 → F_ExternalDefine8(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x1189e0 ldr r1, [pc, #0x8a4]
 *   @0x1189e4 ldr r0, [pc, #0x8a4]
 *   @0x1189e8 mov r2, #9
 *   @0x1189ec mov r3, #1
 *   @0x1189f0 add r0, pc, r0
 *   @0x1189f4 ldr r1, [r4, r1]
 *   @0x1189f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #24 external_call8 → F_ExternalCall8(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x1189fc ldr r1, [pc, #0x890]
 *   @0x118a00 mov r2, #0
 *   @0x118a04 ldr r0, [pc, #0x88c]
 *   @0x118a08 mov r3, r2
 *   @0x118a0c ldr r1, [r4, r1]
 *   @0x118a10 add r0, pc, r0
 *   @0x118a14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #25 window_handle → F_WindowHandle(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x118a18 ldr r1, [pc, #0x87c]
 *   @0x118a1c ldr r0, [pc, #0x87c]
 *   @0x118a20 mov r2, #0
 *   @0x118a24 mov r3, r2
 *   @0x118a28 ldr r1, [r4, r1]
 *   @0x118a2c add r0, pc, r0
 *   @0x118a30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #26 window_device → F_WindowD3DDevice(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x118a34 ldr r1, [pc, #0x868]
 *   @0x118a38 ldr r0, [pc, #0x868]
 *   @0x118a3c mov r2, #1
 *   @0x118a40 mov r3, #0
 *   @0x118a44 ldr r1, [r4, r1]
 *   @0x118a48 add r0, pc, r0
 *   @0x118a4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #27 show_debug_message → F_ShowDebugMessage(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118a50 ldr r1, [pc, #0x854]
 *   @0x118a54 ldr r0, [pc, #0x854]
 *   @0x118a58 mov r2, #1
 *   @0x118a5c mov r3, #0
 *   @0x118a60 ldr r1, [r4, r1]
 *   @0x118a64 add r0, pc, r0
 *   @0x118a68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #28 show_debug_overlay → F_ShowDebugOverlay(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118a6c ldr r1, [pc, #0x840]
 *   @0x118a70 ldr r0, [pc, #0x840]
 *   @0x118a74 mov r2, #1
 *   @0x118a78 mov r3, #0
 *   @0x118a7c ldr r1, [r4, r1]
 *   @0x118a80 add r0, pc, r0
 *   @0x118a84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #29 debug_event → F_DebugEvent(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118a88 ldr r1, [pc, #0x82c]
 *   @0x118a8c ldr r0, [pc, #0x82c]
 *   @0x118a90 mov r2, #0
 *   @0x118a94 mov r3, r2
 *   @0x118a98 ldr r1, [r4, r1]
 *   @0x118a9c add r0, pc, r0
 *   @0x118aa0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #30 debug_get_callstack → F_VMGetCallStack(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x118aa4 ldr r1, [pc, #0x818]
 *   @0x118aa8 ldr r0, [pc, #0x818]
 *   @0x118aac mov r2, #1
 *   @0x118ab0 mov r3, #0
 *   @0x118ab4 ldr r1, [r4, r1]
 *   @0x118ab8 add r0, pc, r0
 *   @0x118abc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #31 set_program_priority → F_SetProgramPriority(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118ac0 ldr r1, [pc, #0x804]
 *   @0x118ac4 ldr r0, [pc, #0x804]
 *   @0x118ac8 mov r2, #1
 *   @0x118acc mov r3, #0
 *   @0x118ad0 ldr r1, [r4, r1]
 *   @0x118ad4 add r0, pc, r0
 *   @0x118ad8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #32 set_application_title → F_SetApplicationTitle(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118adc ldr r1, [pc, #0x7f0]
 *   @0x118ae0 ldr r0, [pc, #0x7f0]
 *   @0x118ae4 mov r2, #2
 *   @0x118ae8 mov r3, #0
 *   @0x118aec ldr r1, [r4, r1]
 *   @0x118af0 add r0, pc, r0
 *   @0x118af4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #33 alarm_set → F_AlarmSet(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x118af8 ldr r1, [pc, #0x7dc]
 *   @0x118afc ldr r0, [pc, #0x7dc]
 *   @0x118b00 mov r2, #1
 *   @0x118b04 mov r3, #0
 *   @0x118b08 ldr r1, [r4, r1]
 *   @0x118b0c add r0, pc, r0
 *   @0x118b10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #34 alarm_get → F_AlarmGet(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118b14 ldr r1, [pc, #0x7c8]
 *   @0x118b18 ldr r0, [pc, #0x7c8]
 *   @0x118b1c mov r2, #1
 *   @0x118b20 mov r3, #0
 *   @0x118b24 ldr r1, [r4, r1]
 *   @0x118b28 add r0, pc, r0
 *   @0x118b2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #35 variable_global_exists → F_VariableGlobalExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118b30 ldr r1, [pc, #0x7b4]
 *   @0x118b34 ldr r0, [pc, #0x7b4]
 *   @0x118b38 mov r2, #1
 *   @0x118b3c mov r3, #0
 *   @0x118b40 ldr r1, [r4, r1]
 *   @0x118b44 add r0, pc, r0
 *   @0x118b48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #36 variable_global_get → F_VariableGlobalGet(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118b4c ldr r1, [pc, #0x7a0]
 *   @0x118b50 ldr r0, [pc, #0x7a0]
 *   @0x118b54 mov r2, #2
 *   @0x118b58 mov r3, #0
 *   @0x118b5c ldr r1, [r4, r1]
 *   @0x118b60 add r0, pc, r0
 *   @0x118b64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #37 variable_global_set → F_VariableGlobalSet(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x118b68 ldr r1, [pc, #0x78c]
 *   @0x118b6c ldr r0, [pc, #0x78c]
 *   @0x118b70 mov r2, #2
 *   @0x118b74 mov r3, #0
 *   @0x118b78 ldr r1, [r4, r1]
 *   @0x118b7c add r0, pc, r0
 *   @0x118b80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #38 variable_instance_exists → F_VariableInstanceExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x118b84 ldr r1, [pc, #0x778]
 *   @0x118b88 ldr r0, [pc, #0x778]
 *   @0x118b8c mov r2, #2
 *   @0x118b90 mov r3, #0
 *   @0x118b94 ldr r1, [r4, r1]
 *   @0x118b98 add r0, pc, r0
 *   @0x118b9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #39 variable_instance_get → F_VariableInstanceGet(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x118ba0 ldr r1, [pc, #0x764]
 *   @0x118ba4 ldr r0, [pc, #0x764]
 *   @0x118ba8 mov r2, #3
 *   @0x118bac mov r3, #0
 *   @0x118bb0 ldr r1, [r4, r1]
 *   @0x118bb4 add r0, pc, r0
 *   @0x118bb8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #40 variable_instance_set → F_VariableInstanceSet(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x118bbc ldr r1, [pc, #0x750]
 *   @0x118bc0 ldr r0, [pc, #0x750]
 *   @0x118bc4 mov r2, #1
 *   @0x118bc8 mov r3, #0
 *   @0x118bcc ldr r1, [r4, r1]
 *   @0x118bd0 add r0, pc, r0
 *   @0x118bd4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #41 variable_instance_get_names → F_VariableInstanceGetNames(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118bd8 ldr r1, [pc, #0x73c]
 *   @0x118bdc ldr r0, [pc, #0x73c]
 *   @0x118be0 mov r2, #0
 *   @0x118be4 mov r3, r2
 *   @0x118be8 ldr r1, [r4, r1]
 *   @0x118bec add r0, pc, r0
 *   @0x118bf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #42 clipboard_has_text → F_ClipboardHasText(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x118bf4 ldr r1, [pc, #0x728]
 *   @0x118bf8 ldr r0, [pc, #0x728]
 *   @0x118bfc mov r2, #1
 *   @0x118c00 mov r3, #0
 *   @0x118c04 ldr r1, [r4, r1]
 *   @0x118c08 add r0, pc, r0
 *   @0x118c0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #43 clipboard_set_text → F_ClipboardSetText(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118c10 ldr r1, [pc, #0x714]
 *   @0x118c14 ldr r0, [pc, #0x714]
 *   @0x118c18 mov r2, #0
 *   @0x118c1c mov r3, r2
 *   @0x118c20 ldr r1, [r4, r1]
 *   @0x118c24 add r0, pc, r0
 *   @0x118c28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #44 clipboard_get_text → F_ClipboardGetText(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x118c2c ldr r1, [pc, #0x700]
 *   @0x118c30 ldr r0, [pc, #0x700]
 *   @0x118c34 mov r2, #0
 *   @0x118c38 mov r3, r2
 *   @0x118c3c ldr r1, [r4, r1]
 *   @0x118c40 add r0, pc, r0
 *   @0x118c44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #45 date_current_datetime → F_DateCurrentDateTime(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x118c48 ldr r1, [pc, #0x6ec]
 *   @0x118c4c ldr r0, [pc, #0x6ec]
 *   @0x118c50 mov r2, #0
 *   @0x118c54 mov r3, r2
 *   @0x118c58 ldr r1, [r4, r1]
 *   @0x118c5c add r0, pc, r0
 *   @0x118c60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #46 date_current_date → F_DateCurrentDate(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x118c64 ldr r1, [pc, #0x6d8]
 *   @0x118c68 ldr r0, [pc, #0x6d8]
 *   @0x118c6c mov r2, #0
 *   @0x118c70 mov r3, r2
 *   @0x118c74 ldr r1, [r4, r1]
 *   @0x118c78 add r0, pc, r0
 *   @0x118c7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #47 date_current_time → F_DateCurrentTime(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x118c80 ldr r1, [pc, #0x6c4]
 *   @0x118c84 ldr r0, [pc, #0x6c4]
 *   @0x118c88 mov r2, #6
 *   @0x118c8c mov r3, #0
 *   @0x118c90 ldr r1, [r4, r1]
 *   @0x118c94 add r0, pc, r0
 *   @0x118c98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #48 date_create_datetime → F_DateCreateDateTime(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=0
 *   @0x118c9c ldr r1, [pc, #0x6b0]
 *   @0x118ca0 ldr r0, [pc, #0x6b0]
 *   @0x118ca4 mov r2, #3
 *   @0x118ca8 mov r3, #0
 *   @0x118cac ldr r1, [r4, r1]
 *   @0x118cb0 add r0, pc, r0
 *   @0x118cb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #49 date_create_date → F_DateCreateDate(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x118cb8 ldr r1, [pc, #0x69c]
 *   @0x118cbc ldr r0, [pc, #0x69c]
 *   @0x118cc0 mov r2, #3
 *   @0x118cc4 mov r3, #0
 *   @0x118cc8 ldr r1, [r4, r1]
 *   @0x118ccc add r0, pc, r0
 *   @0x118cd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #50 date_create_time → F_DateCreateTime(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x118cd4 ldr r1, [pc, #0x688]
 *   @0x118cd8 ldr r0, [pc, #0x688]
 *   @0x118cdc mov r2, #6
 *   @0x118ce0 mov r3, #0
 *   @0x118ce4 ldr r1, [r4, r1]
 *   @0x118ce8 add r0, pc, r0
 *   @0x118cec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #51 date_valid_datetime → F_DateValidDateTime(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=0
 *   @0x118cf0 ldr r1, [pc, #0x674]
 *   @0x118cf4 ldr r0, [pc, #0x674]
 *   @0x118cf8 mov r2, #3
 *   @0x118cfc mov r3, #0
 *   @0x118d00 ldr r1, [r4, r1]
 *   @0x118d04 add r0, pc, r0
 *   @0x118d08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #52 date_valid_date → F_DateValidDate(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x118d0c ldr r1, [pc, #0x660]
 *   @0x118d10 ldr r0, [pc, #0x660]
 *   @0x118d14 mov r2, #3
 *   @0x118d18 mov r3, #0
 *   @0x118d1c ldr r1, [r4, r1]
 *   @0x118d20 add r0, pc, r0
 *   @0x118d24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #53 date_valid_time → F_DateValidTime(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x118d28 ldr r1, [pc, #0x64c]
 *   @0x118d2c ldr r0, [pc, #0x64c]
 *   @0x118d30 mov r2, #2
 *   @0x118d34 mov r3, #0
 *   @0x118d38 ldr r1, [r4, r1]
 *   @0x118d3c add r0, pc, r0
 *   @0x118d40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #54 date_inc_year → F_DateIncYear(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x118d44 ldr r1, [pc, #0x638]
 *   @0x118d48 ldr r0, [pc, #0x638]
 *   @0x118d4c mov r2, #2
 *   @0x118d50 mov r3, #0
 *   @0x118d54 ldr r1, [r4, r1]
 *   @0x118d58 add r0, pc, r0
 *   @0x118d5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #55 date_inc_month → F_DateIncMonth(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x118d60 ldr r1, [pc, #0x624]
 *   @0x118d64 ldr r0, [pc, #0x624]
 *   @0x118d68 mov r2, #2
 *   @0x118d6c mov r3, #0
 *   @0x118d70 ldr r1, [r4, r1]
 *   @0x118d74 add r0, pc, r0
 *   @0x118d78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #56 date_inc_week → F_DateIncWeek(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x118d7c ldr r1, [pc, #0x610]
 *   @0x118d80 ldr r0, [pc, #0x610]
 *   @0x118d84 mov r2, #2
 *   @0x118d88 mov r3, #0
 *   @0x118d8c ldr r1, [r4, r1]
 *   @0x118d90 add r0, pc, r0
 *   @0x118d94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #57 date_inc_day → F_DateIncDay(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x118d98 ldr r1, [pc, #0x5fc]
 *   @0x118d9c ldr r0, [pc, #0x5fc]
 *   @0x118da0 mov r2, #2
 *   @0x118da4 mov r3, #0
 *   @0x118da8 ldr r1, [r4, r1]
 *   @0x118dac add r0, pc, r0
 *   @0x118db0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #58 date_inc_hour → F_DateIncHour(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x118db4 ldr r1, [pc, #0x5e8]
 *   @0x118db8 ldr r0, [pc, #0x5e8]
 *   @0x118dbc mov r2, #2
 *   @0x118dc0 mov r3, #0
 *   @0x118dc4 ldr r1, [r4, r1]
 *   @0x118dc8 add r0, pc, r0
 *   @0x118dcc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #59 date_inc_minute → F_DateIncMinute(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x118dd0 ldr r1, [pc, #0x5d4]
 *   @0x118dd4 ldr r0, [pc, #0x5d4]
 *   @0x118dd8 mov r2, #2
 *   @0x118ddc mov r3, #0
 *   @0x118de0 ldr r1, [r4, r1]
 *   @0x118de4 add r0, pc, r0
 *   @0x118de8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #60 date_inc_second → F_DateIncSecond(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x118dec ldr r1, [pc, #0x5c0]
 *   @0x118df0 ldr r0, [pc, #0x5c0]
 *   @0x118df4 mov r2, #1
 *   @0x118df8 mov r3, #0
 *   @0x118dfc ldr r1, [r4, r1]
 *   @0x118e00 add r0, pc, r0
 *   @0x118e04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #61 date_get_year → F_DateGetYear(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118e08 ldr r1, [pc, #0x5ac]
 *   @0x118e0c ldr r0, [pc, #0x5ac]
 *   @0x118e10 mov r2, #1
 *   @0x118e14 mov r3, #0
 *   @0x118e18 ldr r1, [r4, r1]
 *   @0x118e1c add r0, pc, r0
 *   @0x118e20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #62 date_get_month → F_DateGetMonth(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118e24 ldr r1, [pc, #0x598]
 *   @0x118e28 ldr r0, [pc, #0x598]
 *   @0x118e2c mov r2, #1
 *   @0x118e30 mov r3, #0
 *   @0x118e34 ldr r1, [r4, r1]
 *   @0x118e38 add r0, pc, r0
 *   @0x118e3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #63 date_get_week → F_DateGetWeek(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118e40 ldr r1, [pc, #0x584]
 *   @0x118e44 ldr r0, [pc, #0x584]
 *   @0x118e48 mov r2, #1
 *   @0x118e4c mov r3, #0
 *   @0x118e50 ldr r1, [r4, r1]
 *   @0x118e54 add r0, pc, r0
 *   @0x118e58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #64 date_get_day → F_DateGetDay(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118e5c ldr r1, [pc, #0x570]
 *   @0x118e60 ldr r0, [pc, #0x570]
 *   @0x118e64 mov r2, #1
 *   @0x118e68 mov r3, #0
 *   @0x118e6c ldr r1, [r4, r1]
 *   @0x118e70 add r0, pc, r0
 *   @0x118e74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #65 date_get_hour → F_DateGetHour(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118e78 ldr r1, [pc, #0x55c]
 *   @0x118e7c ldr r0, [pc, #0x55c]
 *   @0x118e80 mov r2, #1
 *   @0x118e84 mov r3, #0
 *   @0x118e88 ldr r1, [r4, r1]
 *   @0x118e8c add r0, pc, r0
 *   @0x118e90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #66 date_get_minute → F_DateGetMinute(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118e94 ldr r1, [pc, #0x548]
 *   @0x118e98 ldr r0, [pc, #0x548]
 *   @0x118e9c mov r2, #1
 *   @0x118ea0 mov r3, #0
 *   @0x118ea4 ldr r1, [r4, r1]
 *   @0x118ea8 add r0, pc, r0
 *   @0x118eac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #67 date_get_second → F_DateGetSecond(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118eb0 ldr r1, [pc, #0x534]
 *   @0x118eb4 ldr r0, [pc, #0x534]
 *   @0x118eb8 mov r2, #1
 *   @0x118ebc mov r3, #0
 *   @0x118ec0 ldr r1, [r4, r1]
 *   @0x118ec4 add r0, pc, r0
 *   @0x118ec8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #68 date_get_weekday → F_DateGetWeekday(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118ecc ldr r1, [pc, #0x520]
 *   @0x118ed0 ldr r0, [pc, #0x520]
 *   @0x118ed4 mov r2, #1
 *   @0x118ed8 mov r3, #0
 *   @0x118edc ldr r1, [r4, r1]
 *   @0x118ee0 add r0, pc, r0
 *   @0x118ee4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #69 date_get_day_of_year → F_DateGetDayOfYear(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118ee8 ldr r1, [pc, #0x50c]
 *   @0x118eec ldr r0, [pc, #0x50c]
 *   @0x118ef0 mov r2, #1
 *   @0x118ef4 mov r3, #0
 *   @0x118ef8 ldr r1, [r4, r1]
 *   @0x118efc add r0, pc, r0
 *   @0x118f00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #70 date_get_hour_of_year → F_DateGetHourOfYear(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118f04 ldr r1, [pc, #0x4f8]
 *   @0x118f08 ldr r0, [pc, #0x4f8]
 *   @0x118f0c mov r2, #1
 *   @0x118f10 mov r3, #0
 *   @0x118f14 ldr r1, [r4, r1]
 *   @0x118f18 add r0, pc, r0
 *   @0x118f1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #71 date_get_minute_of_year → F_DateGetMinuteOfYear(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118f20 ldr r1, [pc, #0x4e4]
 *   @0x118f24 ldr r0, [pc, #0x4e4]
 *   @0x118f28 mov r2, #1
 *   @0x118f2c mov r3, #0
 *   @0x118f30 ldr r1, [r4, r1]
 *   @0x118f34 add r0, pc, r0
 *   @0x118f38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #72 date_get_second_of_year → F_DateGetSecondOfYear(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x118f3c ldr r1, [pc, #0x4d0]
 *   @0x118f40 ldr r0, [pc, #0x4d0]
 *   @0x118f44 mov r2, #2
 *   @0x118f48 mov r3, #0
 *   @0x118f4c ldr r1, [r4, r1]
 *   @0x118f50 add r0, pc, r0
 *   @0x118f54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #73 date_year_span → F_DateYearSpan(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x118f58 ldr r1, [pc, #0x4bc]
 *   @0x118f5c ldr r0, [pc, #0x4bc]
 *   @0x118f60 mov r2, #2
 *   @0x118f64 mov r3, #0
 *   @0x118f68 ldr r1, [r4, r1]
 *   @0x118f6c add r0, pc, r0
 *   @0x118f70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #74 date_month_span → F_DateMonthSpan(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x118f74 ldr r1, [pc, #0x4a8]
 *   @0x118f78 ldr r0, [pc, #0x4a8]
 *   @0x118f7c mov r2, #2
 *   @0x118f80 mov r3, #0
 *   @0x118f84 ldr r1, [r4, r1]
 *   @0x118f88 add r0, pc, r0
 *   @0x118f8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #75 date_week_span → F_DateWeekSpan(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x118f90 ldr r1, [pc, #0x494]
 *   @0x118f94 ldr r0, [pc, #0x494]
 *   @0x118f98 mov r2, #2
 *   @0x118f9c mov r3, #0
 *   @0x118fa0 ldr r1, [r4, r1]
 *   @0x118fa4 add r0, pc, r0
 *   @0x118fa8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #76 date_day_span → F_DateDaySpan(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x118fac ldr r1, [pc, #0x480]
 *   @0x118fb0 ldr r0, [pc, #0x480]
 *   @0x118fb4 mov r2, #2
 *   @0x118fb8 mov r3, #0
 *   @0x118fbc ldr r1, [r4, r1]
 *   @0x118fc0 add r0, pc, r0
 *   @0x118fc4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #77 date_hour_span → F_DateHourSpan(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x118fc8 ldr r1, [pc, #0x46c]
 *   @0x118fcc ldr r0, [pc, #0x46c]
 *   @0x118fd0 mov r2, #2
 *   @0x118fd4 mov r3, #0
 *   @0x118fd8 ldr r1, [r4, r1]
 *   @0x118fdc add r0, pc, r0
 *   @0x118fe0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #78 date_minute_span → F_DateMinuteSpan(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x118fe4 ldr r1, [pc, #0x458]
 *   @0x118fe8 ldr r0, [pc, #0x458]
 *   @0x118fec mov r2, #2
 *   @0x118ff0 mov r3, #0
 *   @0x118ff4 ldr r1, [r4, r1]
 *   @0x118ff8 add r0, pc, r0
 *   @0x118ffc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #79 date_second_span → F_DateSecondSpan(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x119000 ldr r1, [pc, #0x444]
 *   @0x119004 ldr r0, [pc, #0x444]
 *   @0x119008 mov r2, #2
 *   @0x11900c mov r3, #0
 *   @0x119010 ldr r1, [r4, r1]
 *   @0x119014 add r0, pc, r0
 *   @0x119018 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #80 date_compare_datetime → F_DateCompareDateTime(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x11901c ldr r1, [pc, #0x430]
 *   @0x119020 ldr r0, [pc, #0x430]
 *   @0x119024 mov r2, #2
 *   @0x119028 mov r3, #0
 *   @0x11902c ldr r1, [r4, r1]
 *   @0x119030 add r0, pc, r0
 *   @0x119034 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #81 date_compare_date → F_DateCompareDate(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x119038 ldr r1, [pc, #0x41c]
 *   @0x11903c ldr r0, [pc, #0x41c]
 *   @0x119040 mov r2, #2
 *   @0x119044 mov r3, #0
 *   @0x119048 ldr r1, [r4, r1]
 *   @0x11904c add r0, pc, r0
 *   @0x119050 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #82 date_compare_time → F_DateCompareTime(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x119054 ldr r1, [pc, #0x408]
 *   @0x119058 ldr r0, [pc, #0x408]
 *   @0x11905c mov r2, #1
 *   @0x119060 mov r3, #0
 *   @0x119064 ldr r1, [r4, r1]
 *   @0x119068 add r0, pc, r0
 *   @0x11906c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #83 date_date_of → F_DateDateOf(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x119070 ldr r1, [pc, #0x3f4]
 *   @0x119074 ldr r0, [pc, #0x3f4]
 *   @0x119078 mov r2, #1
 *   @0x11907c mov r3, #0
 *   @0x119080 ldr r1, [r4, r1]
 *   @0x119084 add r0, pc, r0
 *   @0x119088 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #84 date_time_of → F_DateTimeOf(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x11908c ldr r1, [pc, #0x3e0]
 *   @0x119090 ldr r0, [pc, #0x3e0]
 *   @0x119094 mov r2, #1
 *   @0x119098 mov r3, #0
 *   @0x11909c ldr r1, [r4, r1]
 *   @0x1190a0 add r0, pc, r0
 *   @0x1190a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #85 date_datetime_string → F_DateDateTimeString(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1190a8 ldr r1, [pc, #0x3cc]
 *   @0x1190ac ldr r0, [pc, #0x3cc]
 *   @0x1190b0 mov r2, #1
 *   @0x1190b4 mov r3, #0
 *   @0x1190b8 ldr r1, [r4, r1]
 *   @0x1190bc add r0, pc, r0
 *   @0x1190c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #86 date_date_string → F_DateDateString(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1190c4 ldr r1, [pc, #0x3b8]
 *   @0x1190c8 ldr r0, [pc, #0x3b8]
 *   @0x1190cc mov r2, #1
 *   @0x1190d0 mov r3, #0
 *   @0x1190d4 ldr r1, [r4, r1]
 *   @0x1190d8 add r0, pc, r0
 *   @0x1190dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #87 date_time_string → F_DateTimeString(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1190e0 ldr r1, [pc, #0x3a4]
 *   @0x1190e4 ldr r0, [pc, #0x3a4]
 *   @0x1190e8 mov r2, #1
 *   @0x1190ec mov r3, #0
 *   @0x1190f0 ldr r1, [r4, r1]
 *   @0x1190f4 add r0, pc, r0
 *   @0x1190f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #88 date_days_in_month → F_DateDaysInMonth(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1190fc ldr r1, [pc, #0x390]
 *   @0x119100 ldr r0, [pc, #0x390]
 *   @0x119104 mov r2, #1
 *   @0x119108 mov r3, #0
 *   @0x11910c ldr r1, [r4, r1]
 *   @0x119110 add r0, pc, r0
 *   @0x119114 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #89 date_days_in_year → F_DateDaysInYear(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x119118 ldr r1, [pc, #0x37c]
 *   @0x11911c ldr r0, [pc, #0x37c]
 *   @0x119120 mov r2, #1
 *   @0x119124 mov r3, #0
 *   @0x119128 ldr r1, [r4, r1]
 *   @0x11912c add r0, pc, r0
 *   @0x119130 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #90 date_leap_year → F_DateLeapYear(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x119134 ldr r1, [pc, #0x368]
 *   @0x119138 ldr r0, [pc, #0x368]
 *   @0x11913c mov r2, #1
 *   @0x119140 mov r3, #0
 *   @0x119144 ldr r1, [r4, r1]
 *   @0x119148 add r0, pc, r0
 *   @0x11914c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #91 date_is_today → F_DateIsToday(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x119150 ldr r1, [pc, #0x354]
 *   @0x119154 ldr r0, [pc, #0x354]
 *   @0x119158 mov r2, #1
 *   @0x11915c mov r3, #0
 *   @0x119160 ldr r1, [r4, r1]
 *   @0x119164 add r0, pc, r0
 *   @0x119168 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #92 date_set_timezone → F_DateSetTimezone(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x11916c ldr r1, [pc, #0x340]
 *   @0x119170 ldr r0, [pc, #0x340]
 *   @0x119174 mov r2, #0
 *   @0x119178 mov r3, r2
 *   @0x11917c ldr r1, [r4, r1]
 *   @0x119180 add r0, pc, r0
 *   @0x119184 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #93 date_get_timezone → F_DateGetTimezone(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x119188 ldr r1, [pc, #0x32c]
 *   @0x11918c ldr r0, [pc, #0x32c]
 *   @0x119190 mov r2, #2
 *   @0x119194 mov r3, #1
 *   @0x119198 ldr r1, [r4, r1]
 *   @0x11919c add r0, pc, r0
 *   @0x1191a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #94 game_set_speed → F_GameSetSpeed(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1191a4 ldr r1, [pc, #0x318]
 *   @0x1191a8 ldr r0, [pc, #0x318]
 *   @0x1191ac mov r2, #2
 *   @0x1191b0 mov r3, #1
 *   @0x1191b4 ldr r1, [r4, r1]
 *   @0x1191b8 add r0, pc, r0
 *   @0x1191bc pop {r4, lr}
 *   @0x1191c0 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #95 game_get_speed → F_GameGetSpeed(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1191c4 eoreq r9, sp, r12, lsl r5
 *   @0x1191c8 .word 0xffffc7e0
 *   @0x1191cc .word 0x002210f8
 *   @0x1191d0 .word 0xffffc7e4
 *   @0x1191d4 eoreq r1, r2, r12, ror #1
 *   @0x1191d8 .word 0xffffc7e8
 *   @0x1191dc eoreq r1, r2, r0, ror #1
 *   @0x1191e0 .word 0xffffc7ec
 *   @0x1191e4 .word 0x002210d0
 *   @0x1191e8 .word 0xffffc180
 *   @0x1191ec .word 0xffffc7f0
 *   @0x1191f0 strhteq r1, [r2], -r8
 *   @0x1191f4 .word 0xffffc7f4
 *   @0x1191f8 eoreq r1, r2, r12, lsr #1
 *   @0x1191fc .word 0xffffc7f8
 *   @0x119200 eoreq r1, r2, r0, lsr #1
 *   @0x119204 .word 0xffffc7fc
 *   @0x119208 mlaeq r2, r4, r0, r1
 *   @0x11920c .word 0xffffc800
 *   @0x119210 eoreq r1, r2, r12, lsl #1
 *   @0x119214 .word 0xffffc804
 *   @0x119218 eoreq r1, r2, r0, lsl #1
 *   @0x11921c .word 0xffffc808
 *   @0x119220 eoreq r1, r2, r8, ror r0
 *   @0x119224 .word 0xffffc80c
 *   @0x119228 eoreq r1, r2, r12, rrx
 *   @0x11922c .word 0xffffc810
 *   @0x119230 eoreq r1, r2, r4, rrx
 *   @0x119234 .word 0xffffc814
 *   @0x119238 eoreq r1, r2, r8, asr r0
 *   @0x11923c .word 0xffffc818
 *   @0x119240 eoreq r1, r2, r0, asr r0
 *   @0x119244 .word 0xffffc81c
 *   @0x119248 eoreq r1, r2, r4, asr #32
 *   @0x11924c .word 0xffffc820
 *   @0x119250 eoreq r1, r2, r12, lsr r0
 *   @0x119254 .word 0xffffc824
 *   @0x119258 eoreq r1, r2, r0, lsr r0
 *   @0x11925c .word 0xffffc828
 *   @0x119260 eoreq r1, r2, r8, lsr #32
 *   @0x119264 .word 0xffffc82c
 *   @0x119268 eoreq r1, r2, r12, lsl r0
 *   @0x11926c .word 0xffffc830
 *   @0x119270 eoreq r1, r2, r4, lsl r0
 *   @0x119274 .word 0xffffc834
 *   @0x119278 eoreq r1, r2, r8
 *   @0x11927c .word 0xffffc838
 *   @0x119280 eoreq r1, r2, r0
 *   @0x119284 .word 0xffffc83c
 *   @0x119288 .word 0x00220ff4
 *   @0x11928c .word 0xffffc840
 *   @0x119290 eoreq r0, r2, r12, ror #31
 *   @0x119294 .word 0xffffc844
 *   @0x119298 .word 0x00220fdc
 *   @0x11929c .word 0xffffc848
 *   @0x1192a0 .word 0x00220fd0
 *   @0x1192a4 .word 0xffffc84c
 *   @0x1192a8 eoreq r0, r2, r4, asr #31
 *   @0x1192ac .word 0xffffc850
 *   @0x1192b0 .word 0x00220fbc
 *   @0x1192b4 .word 0xffffc854
 *   @0x1192b8 .word 0x00220fb4
 *   @0x1192bc .word 0xffffc858
 *   @0x1192c0 eoreq r0, r2, r4, lsr #31
 *   @0x1192c4 .word 0xffffc85c
 *   @0x1192c8 mlaeq r2, r12, pc, r0
 *   @0x1192cc .word 0xffffc860
 *   @0x1192d0 mlaeq r2, r8, pc, r0
 *   @0x1192d4 .word 0xffffc864
 *   @0x1192d8 mlaeq r2, r4, pc, r0
 *   @0x1192dc .word 0xffffc868
 *   @0x1192e0 eoreq r0, r2, r4, lsl #31
 *   @0x1192e4 .word 0xffffc86c
 *   @0x1192e8 eoreq r0, r2, r4, ror pc
 *   @0x1192ec .word 0xffffc870
 *   @0x1192f0 eoreq r0, r2, r0, ror pc
 *   @0x1192f4 .word 0xffffc874
 *   @0x1192f8 eoreq r0, r2, r8, ror #30
 *   @0x1192fc .word 0xffffc878
 *   @0x119300 eoreq r0, r2, r0, ror #30
 *   @0x119304 .word 0xffffc87c
 *   @0x119308 eoreq r0, r2, r0, ror #30
 *   @0x11930c .word 0xffffc880
 *   @0x119310 eoreq r0, r2, r12, asr pc
 *   @0x119314 .word 0xffffc884
 *   @0x119318 eoreq r0, r2, r8, asr pc
 *   @0x11931c .word 0xffffc888
 *   @0x119320 eoreq r0, r2, r8, asr pc
 *   @0x119324 .word 0xffffc88c
 *   @0x119328 eoreq r0, r2, r0, asr pc
 *   @0x11932c .word 0xffffc890
 *   @0x119330 eoreq r0, r2, r8, asr #30
 *   @0x119334 .word 0xffffc894
 *   @0x119338 eoreq r0, r2, r0, asr #30
 *   @0x11933c .word 0xffffc898
 *   @0x119340 eoreq r0, r2, r12, lsr pc
 *   @0x119344 .word 0xffffc89c
 *   @0x119348 eoreq r0, r2, r4, lsr pc
 *   @0x11934c .word 0xffffc8a0
 *   @0x119350 eoreq r0, r2, r12, lsr #30
 *   @0x119354 .word 0xffffc8a4
 *   @0x119358 eoreq r0, r2, r8, lsr #30
 *   @0x11935c .word 0xffffc8a8
 *   @0x119360 eoreq r0, r2, r0, lsr #30
 *   @0x119364 .word 0xffffc8ac
 *   @0x119368 eoreq r0, r2, r8, lsl pc
 *   @0x11936c .word 0xffffc8b0
 *   @0x119370 eoreq r0, r2, r0, lsl pc
 *   @0x119374 .word 0xffffc8b4
 *   @0x119378 eoreq r0, r2, r4, lsl #30
 *   @0x11937c .word 0xffffc8b8
 *   @0x119380 .word 0x00220ef8
 *   @0x119384 .word 0xffffc8bc
 *   @0x119388 eoreq r0, r2, r12, ror #29
 *   @0x11938c .word 0xffffc8c0
 *   @0x119390 eoreq r0, r2, r0, ror #29
 *   @0x119394 .word 0xffffc8c4
 *   @0x119398 .word 0x00220ed4
 *   @0x11939c .word 0xffffc8c8
 *   @0x1193a0 eoreq r0, r2, r8, asr #29
 *   @0x1193a4 .word 0xffffc8cc
 *   @0x1193a8 .word 0x00220ebc
 *   @0x1193ac .word 0xffffc8d0
 *   @0x1193b0 .word 0x00220eb0
 *   @0x1193b4 .word 0xffffc8d4
 *   @0x1193b8 eoreq r0, r2, r4, lsr #29
 *   @0x1193bc .word 0xffffc8d8
 *   @0x1193c0 mlaeq r2, r8, lr, r0
 *   @0x1193c4 .word 0xffffc8dc
 *   @0x1193c8 eoreq r0, r2, r12, lsl #29
 *   @0x1193cc .word 0xffffc8e0
 *   @0x1193d0 eoreq r0, r2, r0, lsl #29
 *   @0x1193d4 .word 0xffffc8e4
 *   @0x1193d8 eoreq r0, r2, r4, ror lr
 *   @0x1193dc .word 0xffffc8e8
 *   @0x1193e0 eoreq r0, r2, r8, ror #28
 *   @0x1193e4 .word 0xffffc8ec
 *   @0x1193e8 eoreq r0, r2, r12, asr lr
 *   @0x1193ec .word 0xffffc8f0
 *   @0x1193f0 eoreq r0, r2, r0, asr lr
 *   @0x1193f4 .word 0xffffc8f4
 *   @0x1193f8 eoreq r0, r2, r8, asr #28
 *   @0x1193fc .word 0xffffc8f8
 *   @0x119400 eoreq r0, r2, r4, asr #28
 *   @0x119404 .word 0xffffc8fc
 *   @0x119408 eoreq r0, r2, r0, asr #28
 *   @0x11940c .word 0xffffc900
 *   @0x119410 eoreq r0, r2, r12, lsr lr
 *   @0x119414 .word 0xffffc904
 *   @0x119418 eoreq r0, r2, r8, lsr lr
 *   @0x11941c .word 0xffffc908
 *   @0x119420 eoreq r0, r2, r12, lsr #28
 *   @0x119424 .word 0xffffc90c
 *   @0x119428 eoreq r0, r2, r0, lsr #28
 *   @0x11942c .word 0xffffc910
 *   @0x119430 eoreq r0, r2, r4, lsl lr
 *   @0x119434 .word 0xffffc914
 *   @0x119438 eoreq r0, r2, r8, lsl #28
 *   @0x11943c .word 0xffffc918
 *   @0x119440 .word 0x00220dfc
 *   @0x119444 .word 0xffffc91c
 *   @0x119448 .word 0x00220df4
 *   @0x11944c .word 0xffffc920
 *   @0x119450 eoreq r0, r2, r12, ror #27
 *   @0x119454 .word 0xffffc924
 *   @0x119458 eoreq r0, r2, r8, ror #27
 *   @0x11945c .word 0xffffc928
 *   @0x119460 eoreq r0, r2, r0, ror #27
 *   @0x119464 .word 0xffffc92c
 *   @0x119468 .word 0x00220dd8
 *   @0x11946c .word 0xffffc930
 *   @0x119470 eoreq r0, r2, r12, asr #27
 *   @0x119474 .word 0xffffc934
 *   @0x119478 eoreq r0, r2, r0, asr #27
 *   @0x11947c .word 0xffffc938
 *   @0x119480 .word 0x00220dbc
 *   @0x119484 .word 0xffffc93c
 *   @0x119488 .word 0x00220db4
 *   @0x11948c .word 0xffffc940
 *   @0x119490 eoreq r0, r2, r12, lsr #27
 *   @0x119494 .word 0xffffc944
 *   @0x119498 eoreq r0, r2, r4, lsr #27
 *   @0x11949c .word 0xffffc948
 *   @0x1194a0 mlaeq r2, r12, sp, r0
 *   @0x1194a4 .word 0xffffc94c
 *   @0x1194a8 mlaeq r2, r0, sp, r0
 *   @0x1194ac .word 0xffffc950
 *   @0x1194b0 eoreq r0, r2, r4, lsl #27
 *   @0x1194b4 .word 0xffffc954
 *   @0x1194b8 eoreq r0, r2, r12, ror sp
 *   @0x1194bc .word 0xffffc958
 *   @0x1194c0 eoreq r0, r2, r4, ror sp
 *   @0x1194c4 .word 0xffffc95c
 *   @0x1194c8 eoreq r0, r2, r8, ror #26
 */
