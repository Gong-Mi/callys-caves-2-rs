/* cally 逆向卡：两个门字节的消费面（0x5428e8 / 0x755363）—— 原版 libyoyo.so，armv7
 * 方法: scripts/gate_census.py —— 按每个函数序言的 GOT 基址把 `ldr rX,[pc,#imm]` 的池字还原成槽地址，
 *       再用 .rel.dyn 的 RELATIVE/GLOB_DAT 目标判定「这个槽指向哪个全局」，最后按加载后紧跟的
 *       ldr/str 形式分读写。不按变量名或用途猜。
 * 级别: 正文（每个消费点落在具体指令上）；变量语义仍 open —— 本卡只说「谁碰它、怎么碰」，不给它编名字。
 * 锚点: 只为本卡新主张的地址落锚；已有卡主张过的站点这里只给地址与归属（全库共享地址保持 0）。
 * 合计 83 个消费点。
 *
 * ══ §1 0x5428e8  消费点 52 个（read 37 / write 1 / 未分类 14）══
 * 涉及函数 50 个；槽 ['0x3ed92c']
 * 写点: 0x1dd844 in GetResolution(unsigned char*, int)+0x3d8
 * 读点函数: AddFunctionNames(Buffer_Standard*)+0x9c、Audio_SetGainForNoise(CNoise*, float, int)+0x84、Audio_SoundGain(int, float, int)+0x44、BeginToEnd()+0x2fc、CInstance::ChangeObjectIndex(int)+0xa4、CProfiler::Init(char const*, int)+0x24、CRoom::LoadFromChunk(YYRoom*, unsigned char*)+0x4ac、CRoom::LoadFromChunk(YYRoom*, unsigned char*)+0x768、CSkeletonInstance::GetFrames(char*) const+0x20、CSprite::Draw(int, float, float, float, float, float, unsigned int, float)+0x1f4、CSprite::DrawGeneral(int, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)+0x214、CSprite::DrawSimple(int, float, float)+0x164、Command_SaveGame(int)+0x53c、DoBreak(unsigned int, unsigned char, unsigned char*, unsigned char const*, VMExec*, bool)+0x54…
 * 未分类（加载后 0x20 字节内未见解引用/写回，可能只作指针传递）: 0x11e80c, 0x11f4a8, 0x11f650, 0x1281f0, 0x131508, 0x149f54, 0x19340c, 0x1a42ec, 0x1aeee8, 0x1af1a4, 0x1b3fd8, 0x1db838, 0x1dda68, 0x2a00d4
 * 未主张: 变量取值域、语义、写入时机 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc0948 subs r4, r0, #0
 *   @0xc094c beq 0xc09b4 <_ZNK17CSkeletonInstance9GetFramesEPc+0x84>
 *   @0xc0950 ldr r2, [pc, #0x8c]   —— read 0x5428e8（槽 0x3ed92c，在 CSkeletonInstance::GetFrames(char*) const+0x20）
 *   @0xc0954 ldr r2, [r3, r2]
 *   @0xc0958 ldrb r2, [r2]
 *   @0xc095c cmp r2, #0
 *   @0xc0960 bne 0xc0998 <_ZNK17CSkeletonInstance9GetFramesEPc+0x68>
 *   @0x114c54 ldr r3, [r4, r3]
 *   @0x114c58 strb r2, [r3]
 *   @0x114c5c ldr r3, [pc, #0x128]   —— read 0x5428e8（槽 0x3ed92c，在 F_DebugEvent(RValue&, CInstance*, CInstance*, int, RValue*)+0x68）
 *   @0x114c60 ldr r3, [r4, r3]
 *   @0x114c64 ldrb r3, [r3]
 *   @0x114c68 cmp r3, #0
 *   @0x114c6c popeq {r3, r4, r5, pc}
 *   @0x1177e4 mov r0, r10
 *   @0x1177e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1177ec ldr r3, [pc, #0xb0]   —— read 0x5428e8（槽 0x3ed92c，在 YYGML_show_debug_message(YYRValue const&)+0x144）
 *   @0x1177f0 ldr r3, [r9, r3]
 *   @0x1177f4 ldrb r3, [r3]
 *   @0x1177f8 cmp r3, #0
 *   @0x1177fc beq 0x117814 <_Z24YYGML_show_debug_messageRK8YYRValue+0x16c>
 *   @0x11e804 cmp r0, #0
 *   @0x11e808 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x11e80c ldr r2, [pc, #0xb8]   —— ? 0x5428e8（槽 0x3ed92c，在 F_SurfaceResize(RValue&, CInstance*, CInstance*, int, RValue*)+0x9c）
 *   @0x11e810 mov r3, #0
 *   @0x11e814 str r4, [r9]
 *   @0x11e818 movt r3, #0x3ff0
 *   @0x11e81c str r3, [r9, #0x4]
 *   @0x11f4a0 sub sp, sp, #44
 *   @0x11f4a4 ldr r4, [pc, #0x184]
 *   @0x11f4a8 ldr r3, [pc, #0x184]   —— ? 0x5428e8（槽 0x3ed92c，在 F_DrawBackgroundTiled(RValue&, CInstance*, CInstance*, int, RValue*)+0x10）
 *   @0x11f4ac add r4, pc, r4
 *   @0x11f4b0 ldr r5, [sp, #0x48]
 *   @0x11f4b4 ldr r3, [r4, r3]
 *   @0x11f4b8 mov r0, r5
 *   @0x11f648 sub sp, sp, #40
 *   @0x11f64c ldr r5, [pc, #0x1e8]
 *   @0x11f650 ldr r3, [pc, #0x1e8]   —— ? 0x5428e8（槽 0x3ed92c，在 F_DrawBackgroundTiledExt(RValue&, CInstance*, CInstance*, int, RValue*)+0x10）
 *   @0x11f654 add r5, pc, r5
 *   @0x11f658 ldr r4, [sp, #0x50]
 *   @0x11f65c ldr r3, [r5, r3]
 *   @0x11f660 mov r0, r4
 *   @0x1631dc ldr r3, [pc, #0x8c]
 *   @0x1631e0 vmov s15, r0
 *   @0x1631e4 ldr r2, [pc, #0x88]   —— read 0x5428e8（槽 0x3ed92c，在 GR_3D_Set_Depth(float)+0x8）
 *   @0x1631e8 add r3, pc, r3
 *   @0x1631ec ldr r2, [r3, r2]
 *   @0x1631f0 ldrb r2, [r2]
 *   @0x1631f4 cmp r2, #0
 *   @0x171734 bl 0x168cd8 <_Z20GR_D3D_Set_View_Portiiii>
 *   @0x171738 ldr r2, [r6, #0x8]
 *   @0x17173c ldr r3, [pc, #0xbc]   —— read 0x5428e8（槽 0x3ed92c，在 YYGML_surface_set_target_ext(int, int)+0x1c8）
 *   @0x171740 mov r1, #0
 *   @0x171744 mov r0, r1
 *   @0x171748 vmov s15, r2
 *   @0x17174c ldr r3, [r4, r3]
 *   @0x1719b0 ldr r2, [r6]
 *   @0x1719b4 bl 0x168cd8 <_Z20GR_D3D_Set_View_Portiiii>
 *   @0x1719b8 ldr r3, [pc, #0xcc]   —— read 0x5428e8（槽 0x3ed92c，在 YYGML_surface_reset_target()+0x1b0）
 *   @0x1719bc ldr r0, [r11]
 *   @0x1719c0 ldr r3, [r4, r3]
 *   @0x1719c4 ldrb r3, [r3]
 *   @0x1719c8 cmp r3, #0
 *   @0x17632c str r0, [sp, #0x38]
 *   @0x176330 beq 0x176308 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x58>
 *   @0x176334 ldr r3, [pc, #0x364]   —— read 0x5428e8（槽 0x3ed92c，在 GR_Texture_Draw_Tiled(YYTPageEntry*, float, float, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float)+0x84）
 *   @0x176338 ldr r12, [sp, #0x34]
 *   @0x17633c ldr r3, [r12, r3]
 *   @0x176340 ldrb r3, [r3]
 *   @0x176344 cmp r3, #0
 *   @0x17a4e4 mov r2, r8
 *   @0x17a4e8 bl 0x179d64 <_Z22GR_Window_View_ConvertiiiRiS_>
 *   @0x17a4ec ldr r3, [pc, #0x190]   —— read 0x5428e8（槽 0x3ed92c，在 GR_Window_Views_Get_ID(int, int)+0x134）
 *   @0x17a4f0 ldr r3, [r11, r3]
 *   @0x17a4f4 ldrb r3, [r3]
 *   @0x17a4f8 cmp r3, #0
 *   @0x17a4fc bne 0x17a568 <_Z22GR_Window_Views_Get_IDii+0x1b0>
 *   @0x17a7cc mov r2, r9
 *   @0x17a7d0 bl 0x179d64 <_Z22GR_Window_View_ConvertiiiRiS_>
 *   @0x17a7d4 ldr r3, [pc, #0x234]   —— read 0x5428e8（槽 0x3ed92c，在 GR_Window_Views_Convert(int, int, int&, int&)+0x134）
 *   @0x17a7d8 ldr r3, [r10, r3]
 *   @0x17a7dc ldrb r3, [r3]
 *   @0x17a7e0 cmp r3, #0
 *   @0x17a7e4 bne 0x17a8d4 <_Z23GR_Window_Views_ConvertiiRiS_+0x234>
 *   @0x1848b8 str r7, [sp, #0x18]
 *   @0x1848bc ldr r2, [pc, #0x894]
 *   @0x1848c0 ldr r3, [pc, #0x894]   —— read 0x5428e8（槽 0x3ed92c，在 _DrawArray(ePrimType, int, void*, int, void*)+0x58）
 *   @0x1848c4 ldr r1, [pc, #0x894]
 *   @0x1848c8 ldr r2, [r4, r2]
 *   @0x1848cc ldr r3, [r4, r3]
 *   @0x1848d0 ldr r1, [r4, r1]
 *   @0x193404 ldr r1, [r3, #0x10]
 *   @0x193408 mov r0, r4
 *   @0x19340c ldr r2, [pc, #0x154]   —— ? 0x5428e8（槽 0x3ed92c，在 CInstance::ChangeObjectIndex(int)+0xa4）
 *   @0x193410 str r1, [r4, #0xac]
 *   @0x193414 ldr r5, [r6, r2]
 *   @0x193418 ldr r1, [r3, #0x4]
 *   @0x19341c ldrb r2, [r5]
 *   @0x19ff6c push {r4, lr}
 *   @0x19ff70 ldr r4, [pc, #0xa4]
 *   @0x19ff74 ldr r3, [pc, #0xa4]   —— read 0x5428e8（槽 0x3ed92c，在 Speed_Factor()+0x8）
 *   @0x19ff78 add r4, pc, r4
 *   @0x19ff7c ldr r3, [r4, r3]
 *   @0x19ff80 ldrb r3, [r3]
 *   @0x19ff84 cmp r3, #0
 *   @0x1a2550 mvn r0, #0
 *   @0x1a2554 bl 0x1a42dc <_Z21ParticleSystem_Createib>
 *   @0x1a2558 ldr r3, [pc, #0x6c]   —— read 0x5428e8（槽 0x3ed92c，在 Eff_Check_Systems()+0x64）
 *   @0x1a255c str r0, [r5]
 *   @0x1a2560 ldr r3, [r4, r3]
 *   @0x1a2564 ldrb r3, [r3]
 *   @0x1a2568 cmp r3, #0
 *   @0x1a2588 mvn r0, #0
 *   @0x1a258c bl 0x1a42dc <_Z21ParticleSystem_Createib>
 *   @0x1a2590 ldr r3, [pc, #0x34]   —— read 0x5428e8（槽 0x3ed92c，在 Eff_Check_Systems()+0x9c）
 *   @0x1a2594 str r0, [r5]
 *   @0x1a2598 ldr r3, [r4, r3]
 *   @0x1a259c ldrb r3, [r3]
 *   @0x1a25a0 cmp r3, #0
 *   @0x1a42e4 ldr r5, [pc, #0x244]
 *   @0x1a42e8 sub sp, sp, #20
 *   @0x1a42ec ldr r3, [pc, #0x240]   —— ? 0x5428e8（槽 0x3ed92c，在 ParticleSystem_Create(int, bool)+0x10）
 *   @0x1a42f0 mov r11, r1
 *   @0x1a42f4 add r5, pc, r5
 *   @0x1a42f8 ldr r8, [r5, r3]
 *   @0x1a42fc ldrb r9, [r8]
 *   @0x1a5ba0 sub sp, sp, #12
 *   @0x1a5ba4 ldr r8, [pc, #0x11c]
 *   @0x1a5ba8 ldr r3, [pc, #0x11c]   —— read 0x5428e8（槽 0x3ed92c，在 ParticleSystem_AddAllToLayers()+0xc）
 *   @0x1a5bac add r8, pc, r8
 *   @0x1a5bb0 ldr r3, [r8, r3]
 *   @0x1a5bb4 ldrb r3, [r3]
 *   @0x1a5bb8 cmp r3, #0
 *   @0x1b01b0 cmp r3, #0
 *   @0x1b01b4 beq 0x1b01f4 <_Z11UpdateViewsv+0x90>
 *   @0x1b01b8 ldr r3, [pc, #0x3d8]   —— read 0x5428e8（槽 0x3ed92c，在 UpdateViews()+0x54）
 *   @0x1b01bc ldr r3, [r6, r3]
 *   @0x1b01c0 ldrb r3, [r3]
 *   @0x1b01c4 cmp r3, #0
 *   @0x1b01c8 beq 0x1b0374 <_Z11UpdateViewsv+0x210>
 *   @0x1d172c ldr r7, [pc, #0x3cc]
 *   @0x1d1730 sub sp, sp, #36
 *   @0x1d1734 ldr r3, [pc, #0x3c8]   —— read 0x5428e8（槽 0x3ed92c，在 EndRoom(bool)+0x10）
 *   @0x1d1738 add r7, pc, r7
 *   @0x1d173c ldr r3, [r7, r3]
 *   @0x1d1740 ldrb r3, [r3]
 *   @0x1d1744 cmp r3, #0
 *   @0x1d1d20 cmp r4, #0
 *   @0x1d1d24 beq 0x1d1da4 <_Z22HandleInstanceMovementb+0xb8>
 *   @0x1d1d28 ldr r2, [pc, #0x120]   —— read 0x5428e8（槽 0x3ed92c，在 HandleInstanceMovement(bool)+0x3c）
 *   @0x1d1d2c ldr r2, [r8, r2]
 *   @0x1d1d30 ldrb r2, [r2]
 *   @0x1d1d34 cmp r2, #0
 *   @0x1d1d38 ldreq r1, [r3, #0xc]
 *   @0x1d4500 sub sp, sp, #8
 *   @0x1d4504 ldr r6, [pc, #0x22c]
 *   @0x1d4508 ldr r3, [pc, #0x22c]   —— read 0x5428e8（槽 0x3ed92c，在 StartGame()+0xc）
 *   @0x1d450c add r6, pc, r6
 *   @0x1d4510 ldr r3, [r6, r3]
 *   @0x1d4514 ldrb r3, [r3]
 *   @0x1d4518 cmp r3, #0
 *   @0x1d47c0 cmp r0, r2
 *   @0x1d47c4 sbcs r12, r1, r3
 *   @0x1d47c8 ldr r3, [pc, #0x4e4]   —— read 0x5428e8（槽 0x3ed92c，在 MainLoop_Process()+0x50）
 *   @0x1d47cc strdlt r0, r1, [r6]
 *   @0x1d47d0 ldr r3, [r8, r3]
 *   @0x1d47d4 str r3, [sp, #0x4]
 *   @0x1d47d8 ldrb r3, [r3]
 *   @0x1db830 mov r0, #0
 *   @0x1db834 bl 0x17adb0 <_Z27GR_Window_Views_Mouse_Get_Yi>
 *   @0x1db838 ldr r3, [pc, #0x1cc]   —— ? 0x5428e8（槽 0x3ed92c，在 HandleMouse()+0x7c）
 *   @0x1db83c str r0, [r5, #0x4]
 *   @0x1db840 ldr r7, [r4, r3]
 *   @0x1db844 ldrb r3, [r7]
 *   @0x1db848 cmp r3, #0
 *   @0x1dd0dc cmp r12, #13
 *   @0x1dd0e0 ble 0x1dd3f8 <_Z11Header_LoadPhjS_+0x464>
 *   @0x1dd0e4 ldr r3, [pc, #0x36c]   —— read 0x5428e8（槽 0x3ed92c，在 Header_Load(unsigned char*, unsigned int, unsigned char*)+0x150）
 *   @0x1dd0e8 ldr r3, [r6, r3]
 *   @0x1dd0ec ldrb r3, [r3]
 *   @0x1dd0f0 cmp r3, #0
 *   @0x1dd0f4 beq 0x1dd3f8 <_Z11Header_LoadPhjS_+0x464>
 *   @0x1dd83c add r1, pc, r1
 *   @0x1dd840 blx r2
 *   @0x1dd844 ldr r3, [pc, #0x1c0]   —— write 0x5428e8（槽 0x3ed92c，在 GetResolution(unsigned char*, int)+0x3d8）
 *   @0x1dd848 ldr r2, [r8, #0x2c]
 *   @0x1dd84c ldr r3, [r4, r3]
 *   @0x1dd850 cmp r2, #1
 *   @0x1dd854 movle r2, #0
 *   @0x1dda60 str r0, [r9]
 *   @0x1dda64 ble 0x1ddba8 <_Z12Texture_LoadPhjS_+0x180>
 *   @0x1dda68 ldr r3, [pc, #0x1e4]   —— ? 0x5428e8（槽 0x3ed92c，在 Texture_Load(unsigned char*, unsigned int, unsigned char*)+0x40）
 *   @0x1dda6c mov r12, r0
 *   @0x1dda70 mov r4, #0
 *   @0x1dda74 mov r6, #1
 *   @0x1dda78 ldr r3, [r7, r3]
 *   @0x1e61b4 vpop {d8, d9, d10, d11}
 *   @0x1e61b8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1e61bc ldr r3, [pc, #0x124]   —— read 0x5428e8（槽 0x3ed92c，在 CSprite::DrawGeneral(int, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)+0x214）
 *   @0x1e61c0 ldr r3, [r4, r3]
 *   @0x1e61c4 ldrb r3, [r3]
 *   @0x1e61c8 cmp r3, #0
 *   @0x1e61cc beq 0x1e61b0 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x208>
 *   @0x2177d4 pop {r3, r4, r5, lr}
 *   @0x2177d8 b 0x217610 <_Z24setGainForNoiseImmediateP6CNoisef>
 *   @0x2177dc ldr r2, [pc, #0x9c]   —— read 0x5428e8（槽 0x3ed92c，在 Audio_SetGainForNoise(CNoise*, float, int)+0x84）
 *   @0x2177e0 ldr r2, [r3, r2]
 *   @0x2177e4 ldrb r2, [r2]
 *   @0x2177e8 cmp r2, #0
 *   @0x2177ec bne 0x217858 <_Z21Audio_SetGainForNoiseP6CNoisefi+0x100>
 *   @0x21792c cmp r3, #0
 *   @0x217930 beq 0x217a1c <_Z15Audio_SoundGainifi+0x12c>
 *   @0x217934 ldr r3, [pc, #0x134]   —— read 0x5428e8（槽 0x3ed92c，在 Audio_SoundGain(int, float, int)+0x44）
 *   @0x217938 ldr r3, [r4, r3]
 *   @0x21793c ldrb r3, [r3]
 *   @0x217940 cmp r3, #0
 *   @0x217944 bne 0x217a44 <_Z15Audio_SoundGainifi+0x154>
 *   @0x220c38 cmp r5, #0
 *   @0x220c3c beq 0x220ccc <_ZN13SoundHardware9SetVolumeEPvfi+0xec>
 *   @0x220c40 ldr r3, [pc, #0x120]   —— read 0x5428e8（槽 0x3ed92c，在 SoundHardware::SetVolume(void*, float, int)+0x60）
 *   @0x220c44 ldr r3, [r4, r3]
 *   @0x220c48 ldrb r3, [r3]
 *   @0x220c4c cmp r3, #0
 *   @0x220c50 bne 0x220d04 <_ZN13SoundHardware9SetVolumeEPvfi+0x124>
 *   @0x29d7e4 cmp r3, #0
 *   @0x29d7e8 bne 0x29d84c <_Z12TickDebuggerv+0xdc>
 *   @0x29d7ec ldr r3, [pc, #0x18c]   —— read 0x5428e8（槽 0x3ed92c，在 TickDebugger()+0x7c）
 *   @0x29d7f0 ldr r3, [r4, r3]
 *   @0x29d7f4 ldrb r3, [r3]
 *   @0x29d7f8 cmp r3, #0
 *   @0x29d7fc beq 0x29d8f8 <_Z12TickDebuggerv+0x188>
 *   @0x29f578 cmp r3, r5
 *   @0x29f57c bgt 0x29f55c <_Z16AddFunctionNamesP15Buffer_Standard+0x78>
 *   @0x29f580 ldr r3, [pc, #0x580]   —— read 0x5428e8（槽 0x3ed92c，在 AddFunctionNames(Buffer_Standard*)+0x9c）
 *   @0x29f584 ldr r4, [sp, #0x4]
 *   @0x29f588 ldr r3, [r4, r3]
 *   @0x29f58c str r3, [sp, #0xc]
 *   @0x29f590 ldrb r3, [r3]
 *   @0x2a00cc mov lr, #1
 *   @0x2a00d0 movne r1, #1
 *   @0x2a00d4 ldr r0, [pc, #0x26c]   —— ? 0x5428e8（槽 0x3ed92c，在 CProfiler::Init(char const*, int)+0x24）
 *   @0x2a00d8 ldr r8, [r10, r3]
 *   @0x2a00dc eor r12, r1, lr
 *   @0x2a00e0 strb r1, [r7, #0x15]
 *   @0x2a00e4 sub sp, sp, #1024
 *   @0x2a1b00 cmp r0, #0
 *   @0x2a1b04 beq 0x2a1b40 <_Z10BeginToEndv+0x334>
 *   @0x2a1b08 ldr r2, [pc, #0xec]   —— read 0x5428e8（槽 0x3ed92c，在 BeginToEnd()+0x2fc）
 *   @0x2a1b0c ldr r3, [pc, #0xec]
 *   @0x2a1b10 ldr r2, [r7, r2]
 *   @0x2a1b14 ldr r3, [r7, r3]
 *   @0x2a1b18 ldrb r2, [r2]
 * 已有卡主张的站点（本卡不重复落锚）: 0xd8488(read,DoBreak(unsigned int, unsigned char, unsigned char*, unsigned char const*, VMExec*, bool)+0x54), 0x10cde8(read,InitGameFunctions()+0x610), 0x1281f0(?,InitInteractionFunctions()+0x92c), 0x12a464(read,InitParticlesFunctions()+0x4f0), 0x131508(?,InitResourceFunctions()+0x50c), 0x149f54(?,Init3DFunctions()+0x8), 0x1aeee8(?,CRoom::LoadFromChunk(YYRoom*, unsigned char*)+0x4ac), 0x1af1a4(?,CRoom::LoadFromChunk(YYRoom*, unsigned char*)+0x768), 0x1b3bec(read,DrawTheRoom(tagYYRECT*)+0xdc), 0x1b3fd8(?,Draw_Room()+0x140), 0x1ce9b4(read,HandleOther()+0x420), 0x1d0d04(read,Command_SaveGame(int)+0x53c), 0x1d3a18(read,StartRoom(int, bool)+0x138), 0x1ddd4c(read,LoadGameData(void*, unsigned int)+0x68), 0x1ec914(read,CSprite::Draw(int, float, float, float, float, float, unsigned int, float)+0x1f4), 0x1ecc18(read,CSprite::DrawSimple(int, float, float)+0x164)
 *
 * ══ §2 0x755363  消费点 31 个（read 22 / write 0 / 未分类 9）══
 * 涉及函数 31 个；槽 ['0x3ef054']
 * 写点: **本普查未发现写点**（可能经非 GOT 路径写入，open）
 * 读点函数: Audio_GetSoundSourceToPlay(int, float)+0x14、Audio_Init(SoundHardware*)+0x14、Audio_PlayInSyncGroup(int, int)+0x1c、Audio_PlaySound(int, double, int)+0x14、Audio_PlaySoundAt(int, double, double, double, double, double, double, int, double)+0x14、Audio_PlaySoundOn(int, int, int, double)+0x14、Audio_QueueBufferSound(int, int, int, int)+0x10、Audio_SetGainForNoise(CNoise*, float, int)+0x14、Audio_SoundGain(int, float, int)+0x14、Audio_SoundPitch(int, float)+0x14、Audio_StopSoundNoise(CNoise*, bool)+0xc、CheckLicense+0x3c0、ProcessCommandLine(char*)+0x40、SND_IsPlaying(char const*, int)+0x10…
 * 未分类（加载后 0x20 字节内未见解引用/写回，可能只作指针传递）: 0x1d2760, 0x21776c, 0x21b2b0, 0x21b5ec, 0x21d0f0, 0x21d450, 0x21efe8, 0x220240, 0x2a1d30
 * 未主张: 变量取值域、语义、写入时机 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d2758 vstr d7, [sp]
 *   @0x1d275c bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1d2760 ldr r3, [pc, #0x6f0]   —— ? 0x755363（槽 0x3ef054，在 CheckLicense+0x3c0）
 *   @0x1d2764 ldr r4, [r6, r3]
 *   @0x1d2768 ldrb r3, [r4]
 *   @0x1d276c cmp r3, #0
 *   @0x1d2770 movne r2, #0
 *   @0x2166c8 ldr r2, [pc, #0xf4]
 *   @0x2166cc add r6, pc, r6
 *   @0x2166d0 ldr r3, [pc, #0xf0]   —— read 0x755363（槽 0x3ef054，在 Audio_Init(SoundHardware*)+0x14）
 *   @0x2166d4 ldr r2, [r6, r2]
 *   @0x2166d8 str r0, [r2]
 *   @0x2166dc ldr r3, [r6, r3]
 *   @0x2166e0 ldrb r3, [r3]
 *   @0x21746c ldr r5, [pc, #0x17c]
 *   @0x217470 vmov s16, r1
 *   @0x217474 ldr r3, [pc, #0x178]   —— read 0x755363（槽 0x3ef054，在 Audio_SoundPitch(int, float)+0x14）
 *   @0x217478 add r5, pc, r5
 *   @0x21747c ldr r3, [r5, r3]
 *   @0x217480 ldrb r3, [r3]
 *   @0x217484 cmp r3, #0
 *   @0x217764 ldr r3, [pc, #0x10c]
 *   @0x217768 mov r4, r0
 *   @0x21776c ldr r12, [pc, #0x108]   —— ? 0x755363（槽 0x3ef054，在 Audio_SetGainForNoise(CNoise*, float, int)+0x14）
 *   @0x217770 mov r5, r2
 *   @0x217774 add r3, pc, r3
 *   @0x217778 ldr r1, [r3, r12]
 *   @0x21777c ldrb r1, [r1]
 *   @0x2178fc ldr r4, [pc, #0x160]
 *   @0x217900 mov r6, r2
 *   @0x217904 ldr r3, [pc, #0x15c]   —— read 0x755363（槽 0x3ef054，在 Audio_SoundGain(int, float, int)+0x14）
 *   @0x217908 vmov s16, r1
 *   @0x21790c add r4, pc, r4
 *   @0x217910 ldr r3, [r4, r3]
 *   @0x217914 ldrb r3, [r3]
 *   @0x21a0b4 mov r4, r0
 *   @0x21a0b8 ldr r5, [pc, #0x138]
 *   @0x21a0bc ldr r3, [pc, #0x138]   —— read 0x755363（槽 0x3ef054，在 Audio_StopSoundNoise(CNoise*, bool)+0xc）
 *   @0x21a0c0 add r5, pc, r5
 *   @0x21a0c4 ldr r3, [r5, r3]
 *   @0x21a0c8 ldrb r3, [r3]
 *   @0x21a0cc cmp r3, #0
 *   @0x21ade8 ldr r11, [pc, #0x46c]
 *   @0x21adec sub sp, sp, #36
 *   @0x21adf0 ldr r3, [pc, #0x468]   —— read 0x755363（槽 0x3ef054，在 Audio_GetSoundSourceToPlay(int, float)+0x14）
 *   @0x21adf4 vmov s16, r1
 *   @0x21adf8 add r11, pc, r11
 *   @0x21adfc ldr r3, [r11, r3]
 *   @0x21ae00 ldrb r3, [r3]
 *   @0x21b2a8 ldr r4, [pc, #0x2f4]
 *   @0x21b2ac sub sp, sp, #8
 *   @0x21b2b0 ldr r1, [pc, #0x2f0]   —— ? 0x755363（槽 0x3ef054，在 Audio_PlaySoundAt(int, double, double, double, double, double, double, int, double)+0x14）
 *   @0x21b2b4 mov r9, r0
 *   @0x21b2b8 add r4, pc, r4
 *   @0x21b2bc ldr r3, [r4, r1]
 *   @0x21b2c0 ldrb r7, [r3]
 *   @0x21b5e4 ldr r5, [pc, #0x2a0]
 *   @0x21b5e8 sub sp, sp, #20
 *   @0x21b5ec ldr r1, [pc, #0x29c]   —— ? 0x755363（槽 0x3ef054，在 Audio_PlaySound(int, double, int)+0x14）
 *   @0x21b5f0 mov r7, r0
 *   @0x21b5f4 add r5, pc, r5
 *   @0x21b5f8 ldr r3, [r5, r1]
 *   @0x21b5fc ldrb r3, [r3]
 *   @0x21b8cc ldr r5, [pc, #0x324]
 *   @0x21b8d0 sub sp, sp, #8
 *   @0x21b8d4 ldr r3, [pc, #0x320]   —— read 0x755363（槽 0x3ef054，在 Audio_PlaySoundOn(int, int, int, double)+0x14）
 *   @0x21b8d8 mov r7, r1
 *   @0x21b8dc add r5, pc, r5
 *   @0x21b8e0 mov r10, r2
 *   @0x21b8e4 ldr r3, [r5, r3]
 *   @0x21d0e8 ldr r4, [pc, #0x2a0]
 *   @0x21d0ec sub sp, sp, #20
 *   @0x21d0f0 ldr r12, [pc, #0x29c]   —— ? 0x755363（槽 0x3ef054，在 Audio_QueueBufferSound(int, int, int, int)+0x10）
 *   @0x21d0f4 mov r0, r1
 *   @0x21d0f8 add r4, pc, r4
 *   @0x21d0fc mov r5, r3
 *   @0x21d100 ldr r12, [r4, r12]
 *   @0x21d448 mov r8, r0
 *   @0x21d44c add r4, pc, r4
 *   @0x21d450 ldr r2, [pc, #0x18c]   —— ? 0x755363（槽 0x3ef054，在 Audio_PlayInSyncGroup(int, int)+0x1c）
 *   @0x21d454 mov r7, r1
 *   @0x21d458 ldr r6, [r4, r3]
 *   @0x21d45c ldr r3, [r6]
 *   @0x21d460 str r3, [sp, #0x414]
 *   @0x21eb84 ldr r4, [pc, #0x148]
 *   @0x21eb88 mov r7, r2
 *   @0x21eb8c ldr r3, [pc, #0x144]   —— read 0x755363（槽 0x3ef054，在 SND_Play(char const*, int, bool)+0x10）
 *   @0x21eb90 mov r6, r0
 *   @0x21eb94 add r4, pc, r4
 *   @0x21eb98 ldr r3, [r4, r3]
 *   @0x21eb9c ldrb r3, [r3]
 *   @0x21ecfc ldr r4, [pc, #0xa0]
 *   @0x21ed00 mov r5, r1
 *   @0x21ed04 ldr r3, [pc, #0x9c]   —— read 0x755363（槽 0x3ef054，在 SND_Stop(char const*, int)+0x10）
 *   @0x21ed08 add r4, pc, r4
 *   @0x21ed0c ldr r3, [r4, r3]
 *   @0x21ed10 ldrb r3, [r3]
 *   @0x21ed14 cmp r3, #0
 *   @0x21edc8 ldr r4, [pc, #0xa4]
 *   @0x21edcc mov r5, r1
 *   @0x21edd0 ldr r3, [pc, #0xa0]   —— read 0x755363（槽 0x3ef054，在 SND_IsPlaying(char const*, int)+0x10）
 *   @0x21edd4 add r4, pc, r4
 *   @0x21edd8 ldr r3, [r4, r3]
 *   @0x21eddc ldrb r3, [r3]
 *   @0x21ede0 cmp r3, #0
 *   @0x21ef20 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x21ef24 ldr r3, [pc, #0x84]
 *   @0x21ef28 ldr r2, [pc, #0x84]   —— read 0x755363（槽 0x3ef054，在 SND_PlatformPause()+0x8）
 *   @0x21ef2c add r3, pc, r3
 *   @0x21ef30 ldr r2, [r3, r2]
 *   @0x21ef34 ldrb r2, [r2]
 *   @0x21ef38 cmp r2, #0
 *   @0x21efe0 cmp r2, #0
 *   @0x21efe4 popne {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x21efe8 ldr r2, [pc, #0x7c]   —— ? 0x755363（槽 0x3ef054，在 SND_PlatformResume()+0x20）
 *   @0x21efec ldr r2, [r3, r2]
 *   @0x21eff0 ldrb r4, [r2]
 *   @0x21eff4 cmp r4, #0
 *   @0x21eff8 popne {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x21f17c push {r3, r4, r5, lr}
 *   @0x21f180 ldr r4, [pc, #0x74]
 *   @0x21f184 ldr r3, [pc, #0x74]   —— read 0x755363（槽 0x3ef054，在 Sound_Tick()+0x8）
 *   @0x21f188 add r4, pc, r4
 *   @0x21f18c ldr r3, [r4, r3]
 *   @0x21f190 ldrb r3, [r3]
 *   @0x21f194 cmp r3, #0
 *   @0x220238 cmp r3, #0
 *   @0x22023c bne 0x2202cc <_ZN13SoundHardware4InitEv+0xb0>
 *   @0x220240 ldr r3, [pc, #0xb8]   —— ? 0x755363（槽 0x3ef054，在 SoundHardware::Init()+0x24）
 *   @0x220244 ldr r3, [r4, r3]
 *   @0x220248 ldrb r5, [r3]
 *   @0x22024c cmp r5, #0
 *   @0x220250 beq 0x220260 <_ZN13SoundHardware4InitEv+0x44>
 *   @0x22033c cmp r3, #0
 *   @0x220340 bne 0x2203a0 <_ZN13SoundHardware4QuitEv+0x7c>
 *   @0x220344 ldr r3, [pc, #0x94]   —— read 0x755363（槽 0x3ef054，在 SoundHardware::Quit()+0x20）
 *   @0x220348 ldr r3, [r4, r3]
 *   @0x22034c ldrb r3, [r3]
 *   @0x220350 cmp r3, #0
 *   @0x220354 popne {r4, pc}
 *   @0x220570 cmp r3, #0
 *   @0x220574 bne 0x2206a4 <_ZN13SoundHardware4LoadEPvii+0x158>
 *   @0x220578 ldr r3, [pc, #0x1c0]   —— read 0x755363（槽 0x3ef054，在 SoundHardware::Load(void*, int, int)+0x2c）
 *   @0x22057c ldr r3, [r4, r3]
 *   @0x220580 ldrb r3, [r3]
 *   @0x220584 cmp r3, #0
 *   @0x220588 bne 0x220698 <_ZN13SoundHardware4LoadEPvii+0x14c>
 *   @0x220788 cmp r3, #0
 *   @0x22078c bne 0x220834 <_ZN13SoundHardware4PlayEPvb+0xd0>
 *   @0x220790 ldr r3, [pc, #0xd4]   —— read 0x755363（槽 0x3ef054，在 SoundHardware::Play(void*, bool)+0x2c）
 *   @0x220794 ldr r3, [r4, r3]
 *   @0x220798 ldrb r3, [r3]
 *   @0x22079c cmp r3, #0
 *   @0x2207a0 popne {r3, r4, r5, r6, r7, pc}
 *   @0x220968 cmp r3, #0
 *   @0x22096c bne 0x2209ac <_ZN13SoundHardware9StopMusicEv+0x5c>
 *   @0x220970 ldr r3, [pc, #0x6c]   —— read 0x755363（槽 0x3ef054，在 SoundHardware::StopMusic()+0x20）
 *   @0x220974 ldr r3, [r4, r3]
 *   @0x220978 ldrb r3, [r3]
 *   @0x22097c cmp r3, #0
 *   @0x220980 popne {r4, pc}
 *   @0x220a20 cmp r3, #0
 *   @0x220a24 bne 0x220a80 <_ZN13SoundHardware7PlayMP3EPKcb+0x84>
 *   @0x220a28 ldr r3, [pc, #0x94]   —— read 0x755363（槽 0x3ef054，在 SoundHardware::PlayMP3(char const*, bool)+0x2c）
 *   @0x220a2c ldr r3, [r4, r3]
 *   @0x220a30 ldrb r3, [r3]
 *   @0x220a34 cmp r3, #0
 *   @0x220a38 popne {r3, r4, r5, r6, r7, pc}
 *   @0x220b00 cmp r3, #0
 *   @0x220b04 bne 0x220b84 <_ZN13SoundHardware8PlayMIDIEPKcb+0xa8>
 *   @0x220b08 ldr r3, [pc, #0xb8]   —— read 0x755363（槽 0x3ef054，在 SoundHardware::PlayMIDI(char const*, bool)+0x2c）
 *   @0x220b0c ldr r3, [r4, r3]
 *   @0x220b10 ldrb r3, [r3]
 *   @0x220b14 cmp r3, #0
 *   @0x220b18 popne {r3, r4, r5, r6, r7, pc}
 *   @0x220c08 cmp r2, #0
 *   @0x220c0c bne 0x220cd4 <_ZN13SoundHardware9SetVolumeEPvfi+0xf4>
 *   @0x220c10 ldr r2, [pc, #0x148]   —— read 0x755363（槽 0x3ef054，在 SoundHardware::SetVolume(void*, float, int)+0x30）
 *   @0x220c14 ldr r2, [r4, r2]
 *   @0x220c18 ldrb r2, [r2]
 *   @0x220c1c cmp r2, #0
 *   @0x220c20 bne 0x220ccc <_ZN13SoundHardware9SetVolumeEPvfi+0xec>
 *   @0x220dac cmp r3, #0
 *   @0x220db0 bne 0x220e18 <_ZN13SoundHardware4StopEPv+0x88>
 *   @0x220db4 ldr r3, [pc, #0x94]   —— read 0x755363（槽 0x3ef054，在 SoundHardware::Stop(void*)+0x24）
 *   @0x220db8 ldr r3, [r4, r3]
 *   @0x220dbc ldrb r3, [r3]
 *   @0x220dc0 cmp r3, #0
 *   @0x220dc4 popne {r3, r4, r5, pc}
 *   @0x220f00 cmp r3, #0
 *   @0x220f04 bne 0x220f90 <_ZN13SoundHardware7PlayingEPv+0xb0>
 *   @0x220f08 ldr r3, [pc, #0xc0]   —— read 0x755363（槽 0x3ef054，在 SoundHardware::Playing(void*)+0x28）
 *   @0x220f0c ldr r3, [r4, r3]
 *   @0x220f10 ldrb r3, [r3]
 *   @0x220f14 cmp r3, #0
 *   @0x220f18 bne 0x220f84 <_ZN13SoundHardware7PlayingEPv+0xa4>
 *   @0x221090 cmp r3, #0
 *   @0x221094 bne 0x2210dc <_ZN13SoundHardware10PlayingMP3Ev+0x64>
 *   @0x221098 ldr r3, [pc, #0x7c]   —— read 0x755363（槽 0x3ef054，在 SoundHardware::PlayingMP3()+0x20）
 *   @0x22109c ldr r3, [r4, r3]
 *   @0x2210a0 ldrb r3, [r3]
 *   @0x2210a4 cmp r3, #0
 *   @0x2210a8 bne 0x2210d4 <_ZN13SoundHardware10PlayingMP3Ev+0x5c>
 *   @0x221158 cmp r3, #0
 *   @0x22115c bne 0x2212f8 <_ZN13SoundHardware4TickEv+0x1c4>
 *   @0x221160 ldr r3, [pc, #0x1dc]   —— read 0x755363（槽 0x3ef054，在 SoundHardware::Tick()+0x2c）
 *   @0x221164 ldr r3, [r6, r3]
 *   @0x221168 ldrb r3, [r3]
 *   @0x22116c cmp r3, #0
 *   @0x221170 bne 0x2212c4 <_ZN13SoundHardware4TickEv+0x190>
 *   @0x2a1d28 strb r3, [r12]
 *   @0x2a1d2c ldr r1, [r5, r1]
 *   @0x2a1d30 ldr r12, [pc, #0x97c]   —— ? 0x755363（槽 0x3ef054，在 ProcessCommandLine(char*)+0x40）
 *   @0x2a1d34 ldr r0, [pc, #0x97c]
 *   @0x2a1d38 str r1, [sp, #0x8]
 *   @0x2a1d3c strb r3, [r1]
 *   @0x2a1d40 ldr r1, [r5, r8]
 */
