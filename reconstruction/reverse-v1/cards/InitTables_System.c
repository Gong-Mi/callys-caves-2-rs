/* cally 逆向卡：InitTables_System —— Init*Functions 的 GML 内建注册表（原版 libyoyo.so，armv7）
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
 * 本卡节: §1 InitSoundFunctions 0x13672c→135 条｜§2 InitSteamFunctions 0x16258c→84 条｜§3 InitNetworkingFunctions 0x299684→15 条｜§4 InitJavaScriptFunctions 0x246fe0→26 条｜§5 InitPhysicsFunctions 0x150434→98 条｜§6 InitGameFunctions 0x10c7d8→95 条
 *
 * ══ §1/6 InitSoundFunctions  0x13672c..0x137a3c  size 4880  1220 条（949 条指令 + 271 个池字）══
 * @func 0x13672c 0x137a3c  size 4880  1220 条
 * 注册 135 条｜唯一名 135｜唯一函数指针 135｜argc 0:29 1:63 2:13 3:9 4:11 5:1 6:3 7:3 8:2 9:1｜flag 0:41 1:94
 * 首条 #0 sound_play（0x136750）→ 末条 #134 audio_debug（0x1375fc）
 * 名字族（前 8）: audio×93 sound×23 cd×18 MCI×1
 * 游戏实际调用的 99 个内建里落在本表: 7 个（audio_is_playing, audio_pause_all, audio_play_sound, audio_resume_all, audio_sound_gain, audio_stop_all, audio_stop_sound）
 * 表: asm/init-tables/init-InitSoundFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: 无（本函数每条注册的四实参全部解出，控制流全部走到）
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13672c push {r4, lr}
 *   @0x136730 mov r2, #1
 *   @0x136734 ldr r4, [pc, #0xec4]
 *   @0x136738 mov r3, #0
 *   @0x13673c ldr r1, [pc, #0xec0]
 *   @0x136740 add r4, pc, r4
 *   @0x136744 ldr r0, [pc, #0xebc]
 *   @0x136748 ldr r1, [r4, r1]
 *   @0x13674c add r0, pc, r0
 *   @0x136750 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 sound_play → F_SoundPlay(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x136754 ldr r1, [pc, #0xeb0]
 *   @0x136758 ldr r0, [pc, #0xeb0]
 *   @0x13675c mov r2, #1
 *   @0x136760 mov r3, #0
 *   @0x136764 ldr r1, [r4, r1]
 *   @0x136768 add r0, pc, r0
 *   @0x13676c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 sound_loop → F_SoundLoop(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x136770 ldr r1, [pc, #0xe9c]
 *   @0x136774 ldr r0, [pc, #0xe9c]
 *   @0x136778 mov r2, #1
 *   @0x13677c mov r3, #0
 *   @0x136780 ldr r1, [r4, r1]
 *   @0x136784 add r0, pc, r0
 *   @0x136788 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 sound_stop → F_SoundStop(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13678c ldr r1, [pc, #0xe88]
 *   @0x136790 ldr r0, [pc, #0xe88]
 *   @0x136794 mov r2, #0
 *   @0x136798 mov r3, r2
 *   @0x13679c ldr r1, [r4, r1]
 *   @0x1367a0 add r0, pc, r0
 *   @0x1367a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 sound_stop_all → F_SoundStopAll(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1367a8 ldr r1, [pc, #0xe74]
 *   @0x1367ac ldr r0, [pc, #0xe74]
 *   @0x1367b0 mov r2, #1
 *   @0x1367b4 mov r3, #0
 *   @0x1367b8 ldr r1, [r4, r1]
 *   @0x1367bc add r0, pc, r0
 *   @0x1367c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #4 sound_isplaying → F_SoundIsPlaying(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1367c4 ldr r1, [pc, #0xe60]
 *   @0x1367c8 ldr r0, [pc, #0xe60]
 *   @0x1367cc mov r2, #2
 *   @0x1367d0 mov r3, #0
 *   @0x1367d4 ldr r1, [r4, r1]
 *   @0x1367d8 add r0, pc, r0
 *   @0x1367dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #5 sound_volume → F_SoundVolume(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1367e0 ldr r1, [pc, #0xe4c]
 *   @0x1367e4 ldr r0, [pc, #0xe4c]
 *   @0x1367e8 mov r2, #3
 *   @0x1367ec mov r3, #0
 *   @0x1367f0 ldr r1, [r4, r1]
 *   @0x1367f4 add r0, pc, r0
 *   @0x1367f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #6 sound_fade → F_SoundFade(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x1367fc ldr r1, [pc, #0xe38]
 *   @0x136800 ldr r0, [pc, #0xe38]
 *   @0x136804 mov r2, #2
 *   @0x136808 mov r3, #0
 *   @0x13680c ldr r1, [r4, r1]
 *   @0x136810 add r0, pc, r0
 *   @0x136814 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #7 sound_pan → F_SoundPan(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x136818 ldr r1, [pc, #0xe24]
 *   @0x13681c ldr r0, [pc, #0xe24]
 *   @0x136820 mov r2, #1
 *   @0x136824 mov r3, #0
 *   @0x136828 ldr r1, [r4, r1]
 *   @0x13682c add r0, pc, r0
 *   @0x136830 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #8 sound_background_tempo → F_SoundBackgroundTempo(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x136834 ldr r1, [pc, #0xe10]
 *   @0x136838 ldr r0, [pc, #0xe10]
 *   @0x13683c mov r2, #1
 *   @0x136840 mov r3, #0
 *   @0x136844 ldr r1, [r4, r1]
 *   @0x136848 add r0, pc, r0
 *   @0x13684c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #9 sound_global_volume → F_SoundGlobalVolume(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x136850 ldr r1, [pc, #0xdfc]
 *   @0x136854 ldr r0, [pc, #0xdfc]
 *   @0x136858 mov r2, #1
 *   @0x13685c mov r3, #0
 *   @0x136860 ldr r1, [r4, r1]
 *   @0x136864 add r0, pc, r0
 *   @0x136868 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #10 sound_set_search_directory → F_SoundSetSearchDirectory(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13686c ldr r1, [pc, #0xde8]
 *   @0x136870 ldr r0, [pc, #0xde8]
 *   @0x136874 mov r2, #2
 *   @0x136878 mov r3, #1
 *   @0x13687c ldr r1, [r4, r1]
 *   @0x136880 add r0, pc, r0
 *   @0x136884 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #11 sound_effect_set → F_SoundEffectSet(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x136888 ldr r1, [pc, #0xdd4]
 *   @0x13688c ldr r0, [pc, #0xdd4]
 *   @0x136890 mov r2, #8
 *   @0x136894 mov r3, #1
 *   @0x136898 ldr r1, [r4, r1]
 *   @0x13689c add r0, pc, r0
 *   @0x1368a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #12 sound_effect_chorus → F_SoundEffectChorus(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x1368a4 ldr r1, [pc, #0xdc0]
 *   @0x1368a8 ldr r0, [pc, #0xdc0]
 *   @0x1368ac mov r2, #7
 *   @0x1368b0 mov r3, #1
 *   @0x1368b4 ldr r1, [r4, r1]
 *   @0x1368b8 add r0, pc, r0
 *   @0x1368bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #13 sound_effect_compressor → F_SoundEffectCompressor(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x1368c0 ldr r1, [pc, #0xdac]
 *   @0x1368c4 ldr r0, [pc, #0xdac]
 *   @0x1368c8 mov r2, #6
 *   @0x1368cc mov r3, #1
 *   @0x1368d0 ldr r1, [r4, r1]
 *   @0x1368d4 add r0, pc, r0
 *   @0x1368d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #14 sound_effect_echo → F_SoundEffectEcho(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x1368dc ldr r1, [pc, #0xd98]
 *   @0x1368e0 ldr r0, [pc, #0xd98]
 *   @0x1368e4 mov r2, #8
 *   @0x1368e8 mov r3, #1
 *   @0x1368ec ldr r1, [r4, r1]
 *   @0x1368f0 add r0, pc, r0
 *   @0x1368f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #15 sound_effect_flanger → F_SoundEffectFlanger(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x1368f8 ldr r1, [pc, #0xd84]
 *   @0x1368fc ldr r0, [pc, #0xd84]
 *   @0x136900 mov r2, #3
 *   @0x136904 mov r3, #1
 *   @0x136908 ldr r1, [r4, r1]
 *   @0x13690c add r0, pc, r0
 *   @0x136910 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #16 sound_effect_gargle → F_SoundEffectGargle(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x136914 ldr r1, [pc, #0xd70]
 *   @0x136918 ldr r0, [pc, #0xd70]
 *   @0x13691c mov r2, #4
 *   @0x136920 mov r3, #1
 *   @0x136924 ldr r1, [r4, r1]
 *   @0x136928 add r0, pc, r0
 *   @0x13692c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #17 sound_effect_equalizer → F_SoundEffectEqualizer(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x136930 ldr r1, [pc, #0xd5c]
 *   @0x136934 ldr r0, [pc, #0xd5c]
 *   @0x136938 mov r2, #5
 *   @0x13693c mov r3, #1
 *   @0x136940 ldr r1, [r4, r1]
 *   @0x136944 add r0, pc, r0
 *   @0x136948 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #18 sound_effect_reverb → F_SoundEffectReverb(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x13694c ldr r1, [pc, #0xd48]
 *   @0x136950 ldr r0, [pc, #0xd48]
 *   @0x136954 mov r2, #4
 *   @0x136958 mov r3, #1
 *   @0x13695c ldr r1, [r4, r1]
 *   @0x136960 add r0, pc, r0
 *   @0x136964 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #19 sound_3d_set_sound_position → F_Sound3DSetSoundPosition(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x136968 ldr r1, [pc, #0xd34]
 *   @0x13696c ldr r0, [pc, #0xd34]
 *   @0x136970 mov r2, #4
 *   @0x136974 mov r3, #1
 *   @0x136978 ldr r1, [r4, r1]
 *   @0x13697c add r0, pc, r0
 *   @0x136980 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #20 sound_3d_set_sound_velocity → F_Sound3DSetSoundVelocity(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x136984 ldr r1, [pc, #0xd20]
 *   @0x136988 ldr r0, [pc, #0xd20]
 *   @0x13698c mov r2, #3
 *   @0x136990 mov r3, #1
 *   @0x136994 ldr r1, [r4, r1]
 *   @0x136998 add r0, pc, r0
 *   @0x13699c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #21 sound_3d_set_sound_distance → F_Sound3DSetSoundDistance(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x1369a0 ldr r1, [pc, #0xd0c]
 *   @0x1369a4 ldr r0, [pc, #0xd0c]
 *   @0x1369a8 mov r2, #7
 *   @0x1369ac mov r3, #1
 *   @0x1369b0 ldr r1, [r4, r1]
 *   @0x1369b4 add r0, pc, r0
 *   @0x1369b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #22 sound_3d_set_sound_cone → F_Sound3DSetSoundCone(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x1369bc ldr r1, [pc, #0xcf8]
 *   @0x1369c0 ldr r0, [pc, #0xcf8]
 *   @0x1369c4 mov r2, #0
 *   @0x1369c8 mov r3, #1
 *   @0x1369cc ldr r1, [r4, r1]
 *   @0x1369d0 add r0, pc, r0
 *   @0x1369d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #23 cd_init → F_CDInit(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x1369d8 ldr r1, [pc, #0xce4]
 *   @0x1369dc ldr r0, [pc, #0xce4]
 *   @0x1369e0 mov r2, #0
 *   @0x1369e4 mov r3, #1
 *   @0x1369e8 ldr r1, [r4, r1]
 *   @0x1369ec add r0, pc, r0
 *   @0x1369f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #24 cd_present → F_CDPresent(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x1369f4 ldr r1, [pc, #0xcd0]
 *   @0x1369f8 ldr r0, [pc, #0xcd0]
 *   @0x1369fc mov r2, #0
 *   @0x136a00 mov r3, #1
 *   @0x136a04 ldr r1, [r4, r1]
 *   @0x136a08 add r0, pc, r0
 *   @0x136a0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #25 cd_number → F_CDNumber(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x136a10 ldr r1, [pc, #0xcbc]
 *   @0x136a14 ldr r0, [pc, #0xcbc]
 *   @0x136a18 mov r2, #0
 *   @0x136a1c mov r3, #1
 *   @0x136a20 ldr r1, [r4, r1]
 *   @0x136a24 add r0, pc, r0
 *   @0x136a28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #26 cd_playing → F_CDPlaying(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x136a2c ldr r1, [pc, #0xca8]
 *   @0x136a30 ldr r0, [pc, #0xca8]
 *   @0x136a34 mov r2, #0
 *   @0x136a38 mov r3, #1
 *   @0x136a3c ldr r1, [r4, r1]
 *   @0x136a40 add r0, pc, r0
 *   @0x136a44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #27 cd_paused → F_CDPaused(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x136a48 ldr r1, [pc, #0xc94]
 *   @0x136a4c ldr r0, [pc, #0xc94]
 *   @0x136a50 mov r2, #0
 *   @0x136a54 mov r3, #1
 *   @0x136a58 ldr r1, [r4, r1]
 *   @0x136a5c add r0, pc, r0
 *   @0x136a60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #28 cd_track → F_CDTrack(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x136a64 ldr r1, [pc, #0xc80]
 *   @0x136a68 ldr r0, [pc, #0xc80]
 *   @0x136a6c mov r2, #0
 *   @0x136a70 mov r3, #1
 *   @0x136a74 ldr r1, [r4, r1]
 *   @0x136a78 add r0, pc, r0
 *   @0x136a7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #29 cd_length → F_CDLength(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x136a80 ldr r1, [pc, #0xc6c]
 *   @0x136a84 ldr r0, [pc, #0xc6c]
 *   @0x136a88 mov r2, #1
 *   @0x136a8c mov r3, r2
 *   @0x136a90 ldr r1, [r4, r1]
 *   @0x136a94 add r0, pc, r0
 *   @0x136a98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #30 cd_track_length → F_CDTrackLength(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x136a9c ldr r1, [pc, #0xc58]
 *   @0x136aa0 ldr r0, [pc, #0xc58]
 *   @0x136aa4 mov r2, #0
 *   @0x136aa8 mov r3, #1
 *   @0x136aac ldr r1, [r4, r1]
 *   @0x136ab0 add r0, pc, r0
 *   @0x136ab4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #31 cd_position → F_CDPosition(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x136ab8 ldr r1, [pc, #0xc44]
 *   @0x136abc ldr r0, [pc, #0xc44]
 *   @0x136ac0 mov r2, #0
 *   @0x136ac4 mov r3, #1
 *   @0x136ac8 ldr r1, [r4, r1]
 *   @0x136acc add r0, pc, r0
 *   @0x136ad0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #32 cd_track_position → F_CDTrackPosition(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x136ad4 ldr r1, [pc, #0xc30]
 *   @0x136ad8 ldr r0, [pc, #0xc30]
 *   @0x136adc mov r2, #2
 *   @0x136ae0 mov r3, #1
 *   @0x136ae4 ldr r1, [r4, r1]
 *   @0x136ae8 add r0, pc, r0
 *   @0x136aec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #33 cd_play → F_CDPlay(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x136af0 ldr r1, [pc, #0xc1c]
 *   @0x136af4 ldr r0, [pc, #0xc1c]
 *   @0x136af8 mov r2, #0
 *   @0x136afc mov r3, #1
 *   @0x136b00 ldr r1, [r4, r1]
 *   @0x136b04 add r0, pc, r0
 *   @0x136b08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #34 cd_stop → F_CDStop(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x136b0c ldr r1, [pc, #0xc08]
 *   @0x136b10 ldr r0, [pc, #0xc08]
 *   @0x136b14 mov r2, #0
 *   @0x136b18 mov r3, #1
 *   @0x136b1c ldr r1, [r4, r1]
 *   @0x136b20 add r0, pc, r0
 *   @0x136b24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #35 cd_pause → F_CDPause(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x136b28 ldr r1, [pc, #0xbf4]
 *   @0x136b2c ldr r0, [pc, #0xbf4]
 *   @0x136b30 mov r2, #0
 *   @0x136b34 mov r3, #1
 *   @0x136b38 ldr r1, [r4, r1]
 *   @0x136b3c add r0, pc, r0
 *   @0x136b40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #36 cd_resume → F_CDResume(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x136b44 ldr r1, [pc, #0xbe0]
 *   @0x136b48 ldr r0, [pc, #0xbe0]
 *   @0x136b4c mov r2, #1
 *   @0x136b50 mov r3, r2
 *   @0x136b54 ldr r1, [r4, r1]
 *   @0x136b58 add r0, pc, r0
 *   @0x136b5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #37 cd_set_position → F_CDSetPosition(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x136b60 ldr r1, [pc, #0xbcc]
 *   @0x136b64 ldr r0, [pc, #0xbcc]
 *   @0x136b68 mov r2, #1
 *   @0x136b6c mov r3, r2
 *   @0x136b70 ldr r1, [r4, r1]
 *   @0x136b74 add r0, pc, r0
 *   @0x136b78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #38 cd_set_track_position → F_CDSetTrackPosition(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x136b7c ldr r1, [pc, #0xbb8]
 *   @0x136b80 ldr r0, [pc, #0xbb8]
 *   @0x136b84 mov r2, #0
 *   @0x136b88 mov r3, #1
 *   @0x136b8c ldr r1, [r4, r1]
 *   @0x136b90 add r0, pc, r0
 *   @0x136b94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #39 cd_open_door → F_CDOpenDoor(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x136b98 ldr r1, [pc, #0xba4]
 *   @0x136b9c ldr r0, [pc, #0xba4]
 *   @0x136ba0 mov r2, #0
 *   @0x136ba4 mov r3, #1
 *   @0x136ba8 ldr r1, [r4, r1]
 *   @0x136bac add r0, pc, r0
 *   @0x136bb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #40 cd_close_door → F_CDCloseDoor(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x136bb4 ldr r1, [pc, #0xb90]
 *   @0x136bb8 ldr r0, [pc, #0xb90]
 *   @0x136bbc mov r2, #1
 *   @0x136bc0 mov r3, r2
 *   @0x136bc4 ldr r1, [r4, r1]
 *   @0x136bc8 add r0, pc, r0
 *   @0x136bcc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #41 MCI_command → F_MCICommand(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x136bd0 ldr r1, [pc, #0xb7c]
 *   @0x136bd4 ldr r0, [pc, #0xb7c]
 *   @0x136bd8 mov r2, #3
 *   @0x136bdc mov r3, #1
 *   @0x136be0 ldr r1, [r4, r1]
 *   @0x136be4 add r0, pc, r0
 *   @0x136be8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #42 audio_listener_position → F_AudioSetListenerPosition(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x136bec ldr r1, [pc, #0xb68]
 *   @0x136bf0 ldr r0, [pc, #0xb68]
 *   @0x136bf4 mov r2, #3
 *   @0x136bf8 mov r3, #1
 *   @0x136bfc ldr r1, [r4, r1]
 *   @0x136c00 add r0, pc, r0
 *   @0x136c04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #43 audio_listener_velocity → F_AudioSetListenerVelocity(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x136c08 ldr r1, [pc, #0xb54]
 *   @0x136c0c ldr r0, [pc, #0xb54]
 *   @0x136c10 mov r2, #6
 *   @0x136c14 mov r3, #1
 *   @0x136c18 ldr r1, [r4, r1]
 *   @0x136c1c add r0, pc, r0
 *   @0x136c20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #44 audio_listener_orientation → F_AudioSetListenerOrientation(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x136c24 ldr r1, [pc, #0xb40]
 *   @0x136c28 ldr r0, [pc, #0xb40]
 *   @0x136c2c mov r2, #4
 *   @0x136c30 mov r3, #1
 *   @0x136c34 ldr r1, [r4, r1]
 *   @0x136c38 add r0, pc, r0
 *   @0x136c3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #45 audio_emitter_position → F_AudioSetEmitterPosition(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x136c40 ldr r1, [pc, #0xb2c]
 *   @0x136c44 ldr r0, [pc, #0xb2c]
 *   @0x136c48 mov r2, #4
 *   @0x136c4c mov r3, #1
 *   @0x136c50 ldr r1, [r4, r1]
 *   @0x136c54 add r0, pc, r0
 *   @0x136c58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #46 audio_emitter_velocity → F_AudioSetEmitterVelocity(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x136c5c ldr r1, [pc, #0xb18]
 *   @0x136c60 ldr r0, [pc, #0xb18]
 *   @0x136c64 mov r2, #0
 *   @0x136c68 mov r3, #1
 *   @0x136c6c ldr r1, [r4, r1]
 *   @0x136c70 add r0, pc, r0
 *   @0x136c74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #47 audio_system → F_AudioSystem(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x136c78 ldr r1, [pc, #0xb04]
 *   @0x136c7c ldr r0, [pc, #0xb04]
 *   @0x136c80 mov r2, #0
 *   @0x136c84 mov r3, #1
 *   @0x136c88 ldr r1, [r4, r1]
 *   @0x136c8c add r0, pc, r0
 *   @0x136c90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #48 audio_emitter_create → F_AudioCreateEmitter(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x136c94 ldr r1, [pc, #0xaf0]
 *   @0x136c98 ldr r0, [pc, #0xaf0]
 *   @0x136c9c mov r2, #1
 *   @0x136ca0 mov r3, r2
 *   @0x136ca4 ldr r1, [r4, r1]
 *   @0x136ca8 add r0, pc, r0
 *   @0x136cac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #49 audio_emitter_free → F_AudioReleaseEmitter(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x136cb0 ldr r1, [pc, #0xadc]
 *   @0x136cb4 ldr r0, [pc, #0xadc]
 *   @0x136cb8 mov r2, #3
 *   @0x136cbc mov r3, #1
 *   @0x136cc0 ldr r1, [r4, r1]
 *   @0x136cc4 add r0, pc, r0
 *   @0x136cc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #50 audio_play_sound → F_AudioPlaySound(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x136ccc ldr r1, [pc, #0xac8]
 *   @0x136cd0 ldr r0, [pc, #0xac8]
 *   @0x136cd4 mov r2, #4
 *   @0x136cd8 mov r3, #1
 *   @0x136cdc ldr r1, [r4, r1]
 *   @0x136ce0 add r0, pc, r0
 *   @0x136ce4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #51 audio_play_sound_on → F_AudioPlaySoundOn(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x136ce8 ldr r1, [pc, #0xab4]
 *   @0x136cec ldr r0, [pc, #0xab4]
 *   @0x136cf0 mov r2, #9
 *   @0x136cf4 mov r3, #1
 *   @0x136cf8 ldr r1, [r4, r1]
 *   @0x136cfc add r0, pc, r0
 *   @0x136d00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #52 audio_play_sound_at → F_AudioPlaySoundAt(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x136d04 ldr r1, [pc, #0xaa0]
 *   @0x136d08 ldr r0, [pc, #0xaa0]
 *   @0x136d0c mov r2, #1
 *   @0x136d10 mov r3, r2
 *   @0x136d14 ldr r1, [r4, r1]
 *   @0x136d18 add r0, pc, r0
 *   @0x136d1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #53 audio_falloff_set_model → F_Audio_SetFalloff(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x136d20 ldr r1, [pc, #0xa8c]
 *   @0x136d24 ldr r0, [pc, #0xa8c]
 *   @0x136d28 mov r2, #1
 *   @0x136d2c mov r3, r2
 *   @0x136d30 ldr r1, [r4, r1]
 *   @0x136d34 add r0, pc, r0
 *   @0x136d38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #54 audio_stop_sound → F_AudioStopSound(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x136d3c ldr r1, [pc, #0xa78]
 *   @0x136d40 ldr r0, [pc, #0xa78]
 *   @0x136d44 mov r2, #1
 *   @0x136d48 mov r3, r2
 *   @0x136d4c ldr r1, [r4, r1]
 *   @0x136d50 add r0, pc, r0
 *   @0x136d54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #55 audio_pause_sound → F_AudioPauseSound(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x136d58 ldr r1, [pc, #0xa64]
 *   @0x136d5c ldr r0, [pc, #0xa64]
 *   @0x136d60 mov r2, #1
 *   @0x136d64 mov r3, r2
 *   @0x136d68 ldr r1, [r4, r1]
 *   @0x136d6c add r0, pc, r0
 *   @0x136d70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #56 audio_resume_sound → F_AudioResumeSound(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x136d74 ldr r1, [pc, #0xa50]
 *   @0x136d78 ldr r0, [pc, #0xa50]
 *   @0x136d7c mov r2, #0
 *   @0x136d80 mov r3, #1
 *   @0x136d84 ldr r1, [r4, r1]
 *   @0x136d88 add r0, pc, r0
 *   @0x136d8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #57 audio_pause_all → F_AudioPauseAll(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x136d90 ldr r1, [pc, #0xa3c]
 *   @0x136d94 ldr r0, [pc, #0xa3c]
 *   @0x136d98 mov r2, #0
 *   @0x136d9c mov r3, #1
 *   @0x136da0 ldr r1, [r4, r1]
 *   @0x136da4 add r0, pc, r0
 *   @0x136da8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #58 audio_resume_all → F_AudioResumeAll(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x136dac ldr r1, [pc, #0xa28]
 *   @0x136db0 ldr r0, [pc, #0xa28]
 *   @0x136db4 mov r2, #1
 *   @0x136db8 mov r3, r2
 *   @0x136dbc ldr r1, [r4, r1]
 *   @0x136dc0 add r0, pc, r0
 *   @0x136dc4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #59 audio_is_playing → F_AudioIsPlaying(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x136dc8 ldr r1, [pc, #0xa14]
 *   @0x136dcc ldr r0, [pc, #0xa14]
 *   @0x136dd0 mov r2, #1
 *   @0x136dd4 mov r3, r2
 *   @0x136dd8 ldr r1, [r4, r1]
 *   @0x136ddc add r0, pc, r0
 *   @0x136de0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #60 audio_is_paused → F_AudioIsPaused(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x136de4 ldr r1, [pc, #0xa00]
 *   @0x136de8 ldr r0, [pc, #0xa00]
 *   @0x136dec mov r2, #1
 *   @0x136df0 mov r3, r2
 *   @0x136df4 ldr r1, [r4, r1]
 *   @0x136df8 add r0, pc, r0
 *   @0x136dfc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #61 audio_exists → F_AudioExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x136e00 ldr r1, [pc, #0x9ec]
 *   @0x136e04 ldr r0, [pc, #0x9ec]
 *   @0x136e08 mov r2, #1
 *   @0x136e0c mov r3, r2
 *   @0x136e10 ldr r1, [r4, r1]
 *   @0x136e14 add r0, pc, r0
 *   @0x136e18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #62 audio_master_gain → F_AudioSetMasterGain(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x136e1c ldr r1, [pc, #0x9d8]
 *   @0x136e20 ldr r0, [pc, #0x9d8]
 *   @0x136e24 mov r2, #1
 *   @0x136e28 mov r3, r2
 *   @0x136e2c ldr r1, [r4, r1]
 *   @0x136e30 add r0, pc, r0
 *   @0x136e34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #63 audio_emitter_exists → F_AudioEmitterExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x136e38 ldr r1, [pc, #0x9c4]
 *   @0x136e3c ldr r0, [pc, #0x9c4]
 *   @0x136e40 mov r2, #1
 *   @0x136e44 mov r3, r2
 *   @0x136e48 ldr r1, [r4, r1]
 *   @0x136e4c add r0, pc, r0
 *   @0x136e50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #64 audio_get_type → F_AudioGetType(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x136e54 ldr r1, [pc, #0x9b0]
 *   @0x136e58 ldr r0, [pc, #0x9b0]
 *   @0x136e5c mov r2, #2
 *   @0x136e60 mov r3, #1
 *   @0x136e64 ldr r1, [r4, r1]
 *   @0x136e68 add r0, pc, r0
 *   @0x136e6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #65 audio_emitter_gain → F_AudioSetEmitterGain(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x136e70 ldr r1, [pc, #0x99c]
 *   @0x136e74 ldr r0, [pc, #0x99c]
 *   @0x136e78 mov r2, #2
 *   @0x136e7c mov r3, #1
 *   @0x136e80 ldr r1, [r4, r1]
 *   @0x136e84 add r0, pc, r0
 *   @0x136e88 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #66 audio_emitter_pitch → F_AudioSetEmitterPitch(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x136e8c ldr r1, [pc, #0x988]
 *   @0x136e90 ldr r0, [pc, #0x988]
 *   @0x136e94 mov r2, #4
 *   @0x136e98 mov r3, #1
 *   @0x136e9c ldr r1, [r4, r1]
 *   @0x136ea0 add r0, pc, r0
 *   @0x136ea4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #67 audio_emitter_falloff → F_AudioSetEmitterFalloff(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x136ea8 ldr r1, [pc, #0x974]
 *   @0x136eac ldr r0, [pc, #0x974]
 *   @0x136eb0 mov r2, #1
 *   @0x136eb4 mov r3, r2
 *   @0x136eb8 ldr r1, [r4, r1]
 *   @0x136ebc add r0, pc, r0
 *   @0x136ec0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #68 audio_channel_num → F_AudioSetNumChannels(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x136ec4 ldr r1, [pc, #0x960]
 *   @0x136ec8 ldr r0, [pc, #0x960]
 *   @0x136ecc mov r2, #2
 *   @0x136ed0 mov r3, #0
 *   @0x136ed4 ldr r1, [r4, r1]
 *   @0x136ed8 add r0, pc, r0
 *   @0x136edc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #69 audio_play_music → F_AudioPlayMusic(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x136ee0 ldr r1, [pc, #0x94c]
 *   @0x136ee4 ldr r0, [pc, #0x94c]
 *   @0x136ee8 mov r2, #0
 *   @0x136eec mov r3, #1
 *   @0x136ef0 ldr r1, [r4, r1]
 *   @0x136ef4 add r0, pc, r0
 *   @0x136ef8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #70 audio_stop_music → F_AudioStopMusic(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x136efc ldr r1, [pc, #0x938]
 *   @0x136f00 ldr r0, [pc, #0x938]
 *   @0x136f04 mov r2, #0
 *   @0x136f08 mov r3, #1
 *   @0x136f0c ldr r1, [r4, r1]
 *   @0x136f10 add r0, pc, r0
 *   @0x136f14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #71 audio_pause_music → F_AudioPauseMusic(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x136f18 ldr r1, [pc, #0x924]
 *   @0x136f1c ldr r0, [pc, #0x924]
 *   @0x136f20 mov r2, #0
 *   @0x136f24 mov r3, #1
 *   @0x136f28 ldr r1, [r4, r1]
 *   @0x136f2c add r0, pc, r0
 *   @0x136f30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #72 audio_resume_music → F_AudioResumeMusic(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x136f34 ldr r1, [pc, #0x910]
 *   @0x136f38 ldr r0, [pc, #0x910]
 *   @0x136f3c mov r2, #0
 *   @0x136f40 mov r3, #1
 *   @0x136f44 ldr r1, [r4, r1]
 *   @0x136f48 add r0, pc, r0
 *   @0x136f4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #73 audio_music_is_playing → F_AudioMusicIsPlaying(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x136f50 ldr r1, [pc, #0x8fc]
 *   @0x136f54 ldr r0, [pc, #0x8fc]
 *   @0x136f58 mov r2, #2
 *   @0x136f5c mov r3, #1
 *   @0x136f60 ldr r1, [r4, r1]
 *   @0x136f64 add r0, pc, r0
 *   @0x136f68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #74 audio_music_gain → F_AudioMusicGain(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x136f6c ldr r1, [pc, #0x8e8]
 *   @0x136f70 ldr r0, [pc, #0x8e8]
 *   @0x136f74 mov r2, #3
 *   @0x136f78 mov r3, #1
 *   @0x136f7c ldr r1, [r4, r1]
 *   @0x136f80 add r0, pc, r0
 *   @0x136f84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #75 audio_sound_gain → F_AudioSoundGain(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x136f88 ldr r1, [pc, #0x8d4]
 *   @0x136f8c ldr r0, [pc, #0x8d4]
 *   @0x136f90 mov r2, #2
 *   @0x136f94 mov r3, #1
 *   @0x136f98 ldr r1, [r4, r1]
 *   @0x136f9c add r0, pc, r0
 *   @0x136fa0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #76 audio_sound_pitch → F_AudioSoundPitch(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x136fa4 ldr r1, [pc, #0x8c0]
 *   @0x136fa8 ldr r0, [pc, #0x8c0]
 *   @0x136fac mov r2, #0
 *   @0x136fb0 mov r3, #1
 *   @0x136fb4 ldr r1, [r4, r1]
 *   @0x136fb8 add r0, pc, r0
 *   @0x136fbc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #77 audio_stop_all → F_AudioStopAll(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x136fc0 ldr r1, [pc, #0x8ac]
 *   @0x136fc4 ldr r0, [pc, #0x8ac]
 *   @0x136fc8 mov r2, #1
 *   @0x136fcc mov r3, r2
 *   @0x136fd0 ldr r1, [r4, r1]
 *   @0x136fd4 add r0, pc, r0
 *   @0x136fd8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #78 audio_sound_length → F_AudioSoundLength(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x136fdc ldr r1, [pc, #0x898]
 *   @0x136fe0 ldr r0, [pc, #0x898]
 *   @0x136fe4 mov r2, #1
 *   @0x136fe8 mov r3, r2
 *   @0x136fec ldr r1, [r4, r1]
 *   @0x136ff0 add r0, pc, r0
 *   @0x136ff4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #79 audio_emitter_get_gain → F_AudioGetEmitterGain(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x136ff8 ldr r1, [pc, #0x884]
 *   @0x136ffc ldr r0, [pc, #0x884]
 *   @0x137000 mov r2, #1
 *   @0x137004 mov r3, r2
 *   @0x137008 ldr r1, [r4, r1]
 *   @0x13700c add r0, pc, r0
 *   @0x137010 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #80 audio_emitter_get_pitch → F_AudioGetEmitterPitch(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x137014 ldr r1, [pc, #0x870]
 *   @0x137018 ldr r0, [pc, #0x870]
 *   @0x13701c mov r2, #1
 *   @0x137020 mov r3, r2
 *   @0x137024 ldr r1, [r4, r1]
 *   @0x137028 add r0, pc, r0
 *   @0x13702c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #81 audio_emitter_get_x → F_AudioGetEmitterPositionX(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x137030 ldr r1, [pc, #0x85c]
 *   @0x137034 ldr r0, [pc, #0x85c]
 *   @0x137038 mov r2, #1
 *   @0x13703c mov r3, r2
 *   @0x137040 ldr r1, [r4, r1]
 *   @0x137044 add r0, pc, r0
 *   @0x137048 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #82 audio_emitter_get_y → F_AudioGetEmitterPositionY(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x13704c ldr r1, [pc, #0x848]
 *   @0x137050 ldr r0, [pc, #0x848]
 *   @0x137054 mov r2, #1
 *   @0x137058 mov r3, r2
 *   @0x13705c ldr r1, [r4, r1]
 *   @0x137060 add r0, pc, r0
 *   @0x137064 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #83 audio_emitter_get_z → F_AudioGetEmitterPositionZ(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x137068 ldr r1, [pc, #0x834]
 *   @0x13706c ldr r0, [pc, #0x834]
 *   @0x137070 mov r2, #1
 *   @0x137074 mov r3, r2
 *   @0x137078 ldr r1, [r4, r1]
 *   @0x13707c add r0, pc, r0
 *   @0x137080 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #84 audio_emitter_get_vx → F_AudioGetEmitterVelocityX(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x137084 ldr r1, [pc, #0x820]
 *   @0x137088 ldr r0, [pc, #0x820]
 *   @0x13708c mov r2, #1
 *   @0x137090 mov r3, r2
 *   @0x137094 ldr r1, [r4, r1]
 *   @0x137098 add r0, pc, r0
 *   @0x13709c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #85 audio_emitter_get_vy → F_AudioGetEmitterVelocityY(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1370a0 ldr r1, [pc, #0x80c]
 *   @0x1370a4 ldr r0, [pc, #0x80c]
 *   @0x1370a8 mov r2, #1
 *   @0x1370ac mov r3, r2
 *   @0x1370b0 ldr r1, [r4, r1]
 *   @0x1370b4 add r0, pc, r0
 *   @0x1370b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #86 audio_emitter_get_vz → F_AudioGetEmitterVelocityZ(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1370bc ldr r1, [pc, #0x7f8]
 *   @0x1370c0 ldr r0, [pc, #0x7f8]
 *   @0x1370c4 mov r2, #4
 *   @0x1370c8 mov r3, #1
 *   @0x1370cc ldr r1, [r4, r1]
 *   @0x1370d0 add r0, pc, r0
 *   @0x1370d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #87 audio_listener_set_position → F_AudioSetListenerPositionN(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x1370d8 ldr r1, [pc, #0x7e4]
 *   @0x1370dc ldr r0, [pc, #0x7e4]
 *   @0x1370e0 mov r2, #4
 *   @0x1370e4 mov r3, #1
 *   @0x1370e8 ldr r1, [r4, r1]
 *   @0x1370ec add r0, pc, r0
 *   @0x1370f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #88 audio_listener_set_velocity → F_AudioSetListenerVelocityN(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x1370f4 ldr r1, [pc, #0x7d0]
 *   @0x1370f8 ldr r0, [pc, #0x7d0]
 *   @0x1370fc mov r2, #7
 *   @0x137100 mov r3, #1
 *   @0x137104 ldr r1, [r4, r1]
 *   @0x137108 add r0, pc, r0
 *   @0x13710c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #89 audio_listener_set_orientation → F_AudioSetListenerOrientationN(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x137110 ldr r1, [pc, #0x7bc]
 *   @0x137114 ldr r0, [pc, #0x7bc]
 *   @0x137118 mov r2, #1
 *   @0x13711c mov r3, r2
 *   @0x137120 ldr r1, [r4, r1]
 *   @0x137124 add r0, pc, r0
 *   @0x137128 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #90 audio_listener_get_data → F_AudioGetListenerData(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x13712c ldr r1, [pc, #0x7a8]
 *   @0x137130 ldr r0, [pc, #0x7a8]
 *   @0x137134 mov r2, #2
 *   @0x137138 mov r3, #1
 *   @0x13713c ldr r1, [r4, r1]
 *   @0x137140 add r0, pc, r0
 *   @0x137144 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #91 audio_set_master_gain → F_AudioSetMasterGainN(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x137148 ldr r1, [pc, #0x794]
 *   @0x13714c ldr r0, [pc, #0x794]
 *   @0x137150 mov r2, #1
 *   @0x137154 mov r3, r2
 *   @0x137158 ldr r1, [r4, r1]
 *   @0x13715c add r0, pc, r0
 *   @0x137160 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #92 audio_get_master_gain → F_AudioGetMasterGainN(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x137164 ldr r1, [pc, #0x780]
 *   @0x137168 ldr r0, [pc, #0x780]
 *   @0x13716c mov r2, #1
 *   @0x137170 mov r3, r2
 *   @0x137174 ldr r1, [r4, r1]
 *   @0x137178 add r0, pc, r0
 *   @0x13717c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #93 audio_sound_get_gain → F_AudioGetSoundGain(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x137180 ldr r1, [pc, #0x76c]
 *   @0x137184 ldr r0, [pc, #0x76c]
 *   @0x137188 mov r2, #1
 *   @0x13718c mov r3, r2
 *   @0x137190 ldr r1, [r4, r1]
 *   @0x137194 add r0, pc, r0
 *   @0x137198 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #94 audio_sound_get_pitch → F_AudioGetSoundPitch(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x13719c ldr r1, [pc, #0x758]
 *   @0x1371a0 ldr r0, [pc, #0x758]
 *   @0x1371a4 mov r2, #1
 *   @0x1371a8 mov r3, r2
 *   @0x1371ac ldr r1, [r4, r1]
 *   @0x1371b0 add r0, pc, r0
 *   @0x1371b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #95 audio_get_name → F_AudioGetName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1371b8 ldr r1, [pc, #0x744]
 *   @0x1371bc ldr r0, [pc, #0x744]
 *   @0x1371c0 mov r2, #2
 *   @0x1371c4 mov r3, #1
 *   @0x1371c8 ldr r1, [r4, r1]
 *   @0x1371cc add r0, pc, r0
 *   @0x1371d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #96 audio_sound_set_track_position → F_AudioSetTrackPos(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1371d4 ldr r1, [pc, #0x730]
 *   @0x1371d8 ldr r0, [pc, #0x730]
 *   @0x1371dc mov r2, #1
 *   @0x1371e0 mov r3, r2
 *   @0x1371e4 ldr r1, [r4, r1]
 *   @0x1371e8 add r0, pc, r0
 *   @0x1371ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #97 audio_sound_get_track_position → F_AudioGetTrackPos(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1371f0 ldr r1, [pc, #0x71c]
 *   @0x1371f4 ldr r0, [pc, #0x71c]
 *   @0x1371f8 mov r2, #1
 *   @0x1371fc mov r3, #0
 *   @0x137200 ldr r1, [r4, r1]
 *   @0x137204 add r0, pc, r0
 *   @0x137208 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #98 audio_group_load → F_Audio_LoadGroup(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13720c ldr r1, [pc, #0x708]
 *   @0x137210 ldr r0, [pc, #0x708]
 *   @0x137214 mov r2, #1
 *   @0x137218 mov r3, #0
 *   @0x13721c ldr r1, [r4, r1]
 *   @0x137220 add r0, pc, r0
 *   @0x137224 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #99 audio_group_unload → F_Audio_UnloadGroup(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x137228 ldr r1, [pc, #0x6f4]
 *   @0x13722c ldr r0, [pc, #0x6f4]
 *   @0x137230 mov r2, #1
 *   @0x137234 mov r3, #0
 *   @0x137238 ldr r1, [r4, r1]
 *   @0x13723c add r0, pc, r0
 *   @0x137240 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #100 audio_group_is_loaded → F_Audio_GroupIsLoaded(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x137244 ldr r1, [pc, #0x6e0]
 *   @0x137248 ldr r0, [pc, #0x6e0]
 *   @0x13724c mov r2, #1
 *   @0x137250 mov r3, #0
 *   @0x137254 ldr r1, [r4, r1]
 *   @0x137258 add r0, pc, r0
 *   @0x13725c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #101 audio_group_load_progress → F_Audio_GroupLoadProgress(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x137260 ldr r1, [pc, #0x6cc]
 *   @0x137264 ldr r0, [pc, #0x6cc]
 *   @0x137268 mov r2, #1
 *   @0x13726c mov r3, #0
 *   @0x137270 ldr r1, [r4, r1]
 *   @0x137274 add r0, pc, r0
 *   @0x137278 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #102 audio_group_name → F_Audio_GroupName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13727c ldr r1, [pc, #0x6b8]
 *   @0x137280 ldr r0, [pc, #0x6b8]
 *   @0x137284 mov r2, #1
 *   @0x137288 mov r3, #0
 *   @0x13728c ldr r1, [r4, r1]
 *   @0x137290 add r0, pc, r0
 *   @0x137294 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #103 audio_group_stop_all → F_Audio_GroupStopAll(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x137298 ldr r1, [pc, #0x6a4]
 *   @0x13729c ldr r0, [pc, #0x6a4]
 *   @0x1372a0 mov r2, #3
 *   @0x1372a4 mov r3, #0
 *   @0x1372a8 ldr r1, [r4, r1]
 *   @0x1372ac add r0, pc, r0
 *   @0x1372b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #104 audio_group_set_gain → F_Audio_GroupSetGain(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x1372b4 ldr r1, [pc, #0x690]
 *   @0x1372b8 ldr r0, [pc, #0x690]
 *   @0x1372bc mov r2, #6
 *   @0x1372c0 mov r3, #0
 *   @0x1372c4 ldr r1, [r4, r1]
 *   @0x1372c8 add r0, pc, r0
 *   @0x1372cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #105 audio_create_buffer_sound → F_Audio_CreateBufferSound(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=0
 *   @0x1372d0 ldr r1, [pc, #0x67c]
 *   @0x1372d4 ldr r0, [pc, #0x67c]
 *   @0x1372d8 mov r2, #1
 *   @0x1372dc mov r3, #0
 *   @0x1372e0 ldr r1, [r4, r1]
 *   @0x1372e4 add r0, pc, r0
 *   @0x1372e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #106 audio_free_buffer_sound → F_Audio_FreeBufferSound(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1372ec ldr r1, [pc, #0x668]
 *   @0x1372f0 ldr r0, [pc, #0x668]
 *   @0x1372f4 mov r2, #3
 *   @0x1372f8 mov r3, #0
 *   @0x1372fc ldr r1, [r4, r1]
 *   @0x137300 add r0, pc, r0
 *   @0x137304 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #107 audio_create_play_queue → F_Audio_CreatePlayQueue(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x137308 ldr r1, [pc, #0x654]
 *   @0x13730c ldr r0, [pc, #0x654]
 *   @0x137310 mov r2, #0
 *   @0x137314 mov r3, r2
 *   @0x137318 ldr r1, [r4, r1]
 *   @0x13731c add r0, pc, r0
 *   @0x137320 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #108 audio_free_play_queue → F_Audio_FreePlayQueue(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x137324 ldr r1, [pc, #0x640]
 *   @0x137328 ldr r0, [pc, #0x640]
 *   @0x13732c mov r2, #4
 *   @0x137330 mov r3, #0
 *   @0x137334 ldr r1, [r4, r1]
 *   @0x137338 add r0, pc, r0
 *   @0x13733c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #109 audio_queue_sound → F_Audio_QueueSound(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x137340 ldr r1, [pc, #0x62c]
 *   @0x137344 ldr r0, [pc, #0x62c]
 *   @0x137348 mov r2, #1
 *   @0x13734c mov r3, #0
 *   @0x137350 ldr r1, [r4, r1]
 *   @0x137354 add r0, pc, r0
 *   @0x137358 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #110 audio_start_recording → F_Audio_StartRecording(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13735c ldr r1, [pc, #0x618]
 *   @0x137360 ldr r0, [pc, #0x618]
 *   @0x137364 mov r2, #1
 *   @0x137368 mov r3, #0
 *   @0x13736c ldr r1, [r4, r1]
 *   @0x137370 add r0, pc, r0
 *   @0x137374 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #111 audio_stop_recording → F_Audio_StopRecording(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x137378 ldr r1, [pc, #0x604]
 *   @0x13737c ldr r0, [pc, #0x604]
 *   @0x137380 mov r2, #0
 *   @0x137384 mov r3, r2
 *   @0x137388 ldr r1, [r4, r1]
 *   @0x13738c add r0, pc, r0
 *   @0x137390 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #112 audio_get_recorder_count → F_Audio_GetRecorderCount(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x137394 ldr r1, [pc, #0x5f0]
 *   @0x137398 ldr r0, [pc, #0x5f0]
 *   @0x13739c mov r2, #1
 *   @0x1373a0 mov r3, #0
 *   @0x1373a4 ldr r1, [r4, r1]
 *   @0x1373a8 add r0, pc, r0
 *   @0x1373ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #113 audio_get_recorder_info → F_Audio_GetRecorderInfo(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1373b0 ldr r1, [pc, #0x5dc]
 *   @0x1373b4 ldr r0, [pc, #0x5dc]
 *   @0x1373b8 mov r2, #1
 *   @0x1373bc mov r3, r2
 *   @0x1373c0 ldr r1, [r4, r1]
 *   @0x1373c4 add r0, pc, r0
 *   @0x1373c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #114 audio_sound_get_listener_mask → F_AudioSoundGetListenerMask(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1373cc ldr r1, [pc, #0x5c8]
 *   @0x1373d0 ldr r0, [pc, #0x5c8]
 *   @0x1373d4 mov r2, #2
 *   @0x1373d8 mov r3, #1
 *   @0x1373dc ldr r1, [r4, r1]
 *   @0x1373e0 add r0, pc, r0
 *   @0x1373e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #115 audio_sound_set_listener_mask → F_AudioSoundSetListenerMask(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1373e8 ldr r1, [pc, #0x5b4]
 *   @0x1373ec ldr r0, [pc, #0x5b4]
 *   @0x1373f0 mov r2, #1
 *   @0x1373f4 mov r3, r2
 *   @0x1373f8 ldr r1, [r4, r1]
 *   @0x1373fc add r0, pc, r0
 *   @0x137400 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #116 audio_emitter_get_listener_mask → F_AudioEmitterGetListenerMask(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x137404 ldr r1, [pc, #0x5a0]
 *   @0x137408 ldr r0, [pc, #0x5a0]
 *   @0x13740c mov r2, #2
 *   @0x137410 mov r3, #1
 *   @0x137414 ldr r1, [r4, r1]
 *   @0x137418 add r0, pc, r0
 *   @0x13741c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #117 audio_emitter_set_listener_mask → F_AudioEmitterSetListenerMask(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x137420 ldr r1, [pc, #0x58c]
 *   @0x137424 ldr r0, [pc, #0x58c]
 *   @0x137428 mov r2, #0
 *   @0x13742c mov r3, #1
 *   @0x137430 ldr r1, [r4, r1]
 *   @0x137434 add r0, pc, r0
 *   @0x137438 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #118 audio_get_listener_mask → F_AudioGetListenerMask(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x13743c ldr r1, [pc, #0x578]
 *   @0x137440 ldr r0, [pc, #0x578]
 *   @0x137444 mov r2, #1
 *   @0x137448 mov r3, r2
 *   @0x13744c ldr r1, [r4, r1]
 *   @0x137450 add r0, pc, r0
 *   @0x137454 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #119 audio_set_listener_mask → F_AudioSetListenerMask(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x137458 ldr r1, [pc, #0x564]
 *   @0x13745c ldr r0, [pc, #0x564]
 *   @0x137460 mov r2, #0
 *   @0x137464 mov r3, #1
 *   @0x137468 ldr r1, [r4, r1]
 *   @0x13746c add r0, pc, r0
 *   @0x137470 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #120 audio_get_listener_info → F_AudioGetListenerInfo(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x137474 ldr r1, [pc, #0x550]
 *   @0x137478 ldr r0, [pc, #0x550]
 *   @0x13747c mov r2, #0
 *   @0x137480 mov r3, #1
 *   @0x137484 ldr r1, [r4, r1]
 *   @0x137488 add r0, pc, r0
 *   @0x13748c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #121 audio_get_listener_count → F_AudioGetListenerCount(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x137490 ldr r1, [pc, #0x53c]
 *   @0x137494 ldr r0, [pc, #0x53c]
 *   @0x137498 mov r2, #1
 *   @0x13749c mov r3, #0
 *   @0x1374a0 ldr r1, [r4, r1]
 *   @0x1374a4 add r0, pc, r0
 *   @0x1374a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #122 audio_create_sync_group → F_AudioCreateSyncGroup(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1374ac ldr r1, [pc, #0x528]
 *   @0x1374b0 ldr r0, [pc, #0x528]
 *   @0x1374b4 mov r2, #1
 *   @0x1374b8 mov r3, #0
 *   @0x1374bc ldr r1, [r4, r1]
 *   @0x1374c0 add r0, pc, r0
 *   @0x1374c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #123 audio_destroy_sync_group → F_AudioDestroySyncGroup(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1374c8 ldr r1, [pc, #0x514]
 *   @0x1374cc ldr r0, [pc, #0x514]
 *   @0x1374d0 mov r2, #4
 *   @0x1374d4 mov r3, #0
 *   @0x1374d8 ldr r1, [r4, r1]
 *   @0x1374dc add r0, pc, r0
 *   @0x1374e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #124 audio_play_in_sync_group → F_AudioPlayInSyncGroup(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x1374e4 ldr r1, [pc, #0x500]
 *   @0x1374e8 ldr r0, [pc, #0x500]
 *   @0x1374ec mov r2, #1
 *   @0x1374f0 mov r3, #0
 *   @0x1374f4 ldr r1, [r4, r1]
 *   @0x1374f8 add r0, pc, r0
 *   @0x1374fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #125 audio_start_sync_group → F_AudioStartSyncGroup(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x137500 ldr r1, [pc, #0x4ec]
 *   @0x137504 ldr r0, [pc, #0x4ec]
 *   @0x137508 mov r2, #1
 *   @0x13750c mov r3, #0
 *   @0x137510 ldr r1, [r4, r1]
 *   @0x137514 add r0, pc, r0
 *   @0x137518 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #126 audio_pause_sync_group → F_AudioPauseSyncGroup(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13751c ldr r1, [pc, #0x4d8]
 *   @0x137520 ldr r0, [pc, #0x4d8]
 *   @0x137524 mov r2, #1
 *   @0x137528 mov r3, #0
 *   @0x13752c ldr r1, [r4, r1]
 *   @0x137530 add r0, pc, r0
 *   @0x137534 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #127 audio_resume_sync_group → F_AudioResumeSyncGroup(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x137538 ldr r1, [pc, #0x4c4]
 *   @0x13753c ldr r0, [pc, #0x4c4]
 *   @0x137540 mov r2, #1
 *   @0x137544 mov r3, #0
 *   @0x137548 ldr r1, [r4, r1]
 *   @0x13754c add r0, pc, r0
 *   @0x137550 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #128 audio_stop_sync_group → F_AudioStopSyncGroup(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x137554 ldr r1, [pc, #0x4b0]
 *   @0x137558 ldr r0, [pc, #0x4b0]
 *   @0x13755c mov r2, #1
 *   @0x137560 mov r3, #0
 *   @0x137564 ldr r1, [r4, r1]
 *   @0x137568 add r0, pc, r0
 *   @0x13756c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #129 audio_sync_group_get_track_pos → F_AudioSyncGroupGetTrackPos(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x137570 ldr r1, [pc, #0x49c]
 *   @0x137574 ldr r0, [pc, #0x49c]
 *   @0x137578 mov r2, #1
 *   @0x13757c mov r3, #0
 *   @0x137580 ldr r1, [r4, r1]
 *   @0x137584 add r0, pc, r0
 *   @0x137588 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #130 audio_sync_group_debug → F_AudioSyncGroupDebug(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x13758c ldr r1, [pc, #0x488]
 *   @0x137590 ldr r0, [pc, #0x488]
 *   @0x137594 mov r2, #1
 *   @0x137598 mov r3, #0
 *   @0x13759c ldr r1, [r4, r1]
 *   @0x1375a0 add r0, pc, r0
 *   @0x1375a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #131 audio_sync_group_is_playing → F_AudioSyncGroupIsPlaying(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1375a8 ldr r1, [pc, #0x474]
 *   @0x1375ac ldr r0, [pc, #0x474]
 *   @0x1375b0 mov r2, #1
 *   @0x1375b4 mov r3, #0
 *   @0x1375b8 ldr r1, [r4, r1]
 *   @0x1375bc add r0, pc, r0
 *   @0x1375c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #132 audio_create_stream → F_AudioCreateStream(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1375c4 ldr r1, [pc, #0x460]
 *   @0x1375c8 ldr r0, [pc, #0x460]
 *   @0x1375cc mov r2, #1
 *   @0x1375d0 mov r3, #0
 *   @0x1375d4 ldr r1, [r4, r1]
 *   @0x1375d8 add r0, pc, r0
 *   @0x1375dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #133 audio_destroy_stream → F_AudioDestroyStream(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1375e0 ldr r1, [pc, #0x44c]
 *   @0x1375e4 ldr r0, [pc, #0x44c]
 *   @0x1375e8 mov r2, #1
 *   @0x1375ec mov r3, #0
 *   @0x1375f0 ldr r1, [r4, r1]
 *   @0x1375f4 add r0, pc, r0
 *   @0x1375f8 pop {r4, lr}
 *   @0x1375fc b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #134 audio_debug → F_AudioDebug(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x137600 eoreq r11, r11, r0, lsl r5
 *   @0x137604 .word 0xffffd404
 *   @0x137608 eoreq r8, r0, r8, asr sp
 *   @0x13760c .word 0xffffd408
 *   @0x137610 eoreq r8, r0, r8, asr #26
 *   @0x137614 .word 0xffffd40c
 *   @0x137618 eoreq r8, r0, r8, lsr sp
 *   @0x13761c .word 0xffffd410
 *   @0x137620 eoreq r8, r0, r8, lsr #26
 *   @0x137624 .word 0xffffd414
 *   @0x137628 eoreq r8, r0, r12, lsl sp
 *   @0x13762c .word 0xffffd418
 *   @0x137630 eoreq r8, r0, r0, lsl sp
 *   @0x137634 .word 0xffffd41c
 *   @0x137638 eoreq r8, r0, r4, lsl #26
 *   @0x13763c .word 0xffffd420
 *   @0x137640 .word 0x00208cf4
 *   @0x137644 .word 0xffffd424
 *   @0x137648 eoreq r8, r0, r4, ror #25
 *   @0x13764c .word 0xffffd428
 *   @0x137650 eoreq r8, r0, r0, ror #25
 *   @0x137654 .word 0xffffd42c
 *   @0x137658 .word 0x00208cd8
 *   @0x13765c .word 0xffffd430
 *   @0x137660 .word 0x00208cd8
 *   @0x137664 .word 0xffffd434
 *   @0x137668 .word 0x00208cd0
 *   @0x13766c .word 0xffffd438
 *   @0x137670 eoreq r8, r0, r8, asr #25
 *   @0x137674 .word 0xffffd43c
 *   @0x137678 eoreq r8, r0, r4, asr #25
 *   @0x13767c .word 0xffffd440
 *   @0x137680 .word 0x00208cbc
 *   @0x137684 .word 0xffffd444
 *   @0x137688 .word 0x00208cb8
 *   @0x13768c .word 0xffffd448
 *   @0x137690 .word 0x00208cb0
 *   @0x137694 .word 0xffffd44c
 *   @0x137698 eoreq r8, r0, r12, lsr #25
 *   @0x13769c .word 0xffffd450
 *   @0x1376a0 eoreq r8, r0, r4, lsr #25
 *   @0x1376a4 .word 0xffffd454
 *   @0x1376a8 eoreq r8, r0, r4, lsr #25
 *   @0x1376ac .word 0xffffd458
 *   @0x1376b0 eoreq r8, r0, r4, lsr #25
 *   @0x1376b4 .word 0xffffd45c
 *   @0x1376b8 eoreq r8, r0, r4, lsr #25
 *   @0x1376bc .word 0xffffd460
 *   @0x1376c0 eoreq r8, r0, r0, lsr #25
 *   @0x1376c4 .word 0xffffd464
 *   @0x1376c8 eoreq r8, r0, r12, lsl #25
 *   @0x1376cc .word 0xffffd468
 *   @0x1376d0 eoreq r8, r0, r12, ror r12
 *   @0x1376d4 .word 0xffffd46c
 *   @0x1376d8 eoreq r8, r0, r12, ror #24
 *   @0x1376dc .word 0xffffd470
 *   @0x1376e0 eoreq r8, r0, r12, asr r12
 *   @0x1376e4 .word 0xffffd474
 *   @0x1376e8 eoreq r8, r0, r12, asr #24
 *   @0x1376ec .word 0xffffd478
 *   @0x1376f0 eoreq r8, r0, r12, lsr r12
 *   @0x1376f4 .word 0xffffd47c
 *   @0x1376f8 eoreq r8, r0, r12, lsr #24
 *   @0x1376fc .word 0xffffd480
 *   @0x137700 eoreq r8, r0, r0, lsr #24
 *   @0x137704 .word 0xffffd484
 *   @0x137708 eoreq r8, r0, r0, lsl r12
 *   @0x13770c .word 0xffffd488
 *   @0x137710 eoreq r8, r0, r8, lsl #24
 *   @0x137714 .word 0xffffd48c
 *   @0x137718 .word 0x00208bf4
 *   @0x13771c .word 0xffffd490
 *   @0x137720 eoreq r8, r0, r0, ror #23
 *   @0x137724 .word 0xffffd494
 *   @0x137728 .word 0x00208bd0
 *   @0x13772c .word 0xffffd498
 *   @0x137730 eoreq r8, r0, r0, asr #23
 *   @0x137734 .word 0xffffd49c
 *   @0x137738 .word 0x00208bb4
 *   @0x13773c .word 0xffffd4a0
 *   @0x137740 .word 0x00208bb0
 *   @0x137744 .word 0xffffd4a4
 *   @0x137748 eoreq r8, r0, r4, lsr #23
 *   @0x13774c .word 0xffffd4a8
 *   @0x137750 mlaeq r0, r8, r11, r8
 *   @0x137754 .word 0xffffd4ac
 *   @0x137758 eoreq r8, r0, r8, lsl #23
 *   @0x13775c .word 0xffffd4b0
 *   @0x137760 eoreq r8, r0, r4, lsl #23
 *   @0x137764 .word 0xffffd4b4
 *   @0x137768 eoreq r8, r0, r0, lsl #23
 *   @0x13776c .word 0xffffd4b8
 *   @0x137770 eoreq r8, r0, r0, lsl #23
 *   @0x137774 .word 0xffffd4bc
 *   @0x137778 eoreq r8, r0, r12, ror r11
 *   @0x13777c .word 0xffffd4c0
 *   @0x137780 eoreq r8, r0, r8, ror r11
 *   @0x137784 .word 0xffffd4c4
 *   @0x137788 eoreq r8, r0, r12, ror #22
 *   @0x13778c .word 0xffffd4c8
 *   @0x137790 eoreq r8, r0, r8, ror #22
 *   @0x137794 .word 0xffffd4cc
 *   @0x137798 eoreq r8, r0, r0, ror #22
 *   @0x13779c .word 0xffffd4d0
 *   @0x1377a0 eoreq r8, r0, r8, asr r11
 *   @0x1377a4 .word 0xffffd4d4
 *   @0x1377a8 eoreq r8, r0, r0, asr r11
 *   @0x1377ac .word 0xffffd4d8
 *   @0x1377b0 eoreq r8, r0, r8, asr #22
 *   @0x1377b4 .word 0xffffd4dc
 *   @0x1377b8 eoreq r8, r0, r4, asr #22
 *   @0x1377bc .word 0xffffd4e0
 *   @0x1377c0 eoreq r8, r0, r12, lsr r11
 *   @0x1377c4 .word 0xffffd4e4
 *   @0x1377c8 eoreq r8, r0, r4, lsr r11
 *   @0x1377cc .word 0xffffd4e8
 *   @0x1377d0 eoreq r8, r0, r12, lsr #22
 *   @0x1377d4 .word 0xffffd4ec
 *   @0x1377d8 eoreq r8, r0, r0, lsr #22
 *   @0x1377dc .word 0xffffd4f0
 *   @0x1377e0 eoreq r8, r0, r8, lsl r11
 *   @0x1377e4 .word 0xffffd4f4
 *   @0x1377e8 eoreq r8, r0, r0, lsl r11
 *   @0x1377ec .word 0xffffd4f8
 *   @0x1377f0 eoreq r8, r0, r4, lsl #22
 *   @0x1377f4 .word 0xffffd4fc
 *   @0x1377f8 .word 0x00208af8
 *   @0x1377fc .word 0xffffd500
 *   @0x137800 .word 0x00208af0
 *   @0x137804 .word 0xffffd504
 *   @0x137808 eoreq r8, r0, r12, ror #21
 *   @0x13780c .word 0xffffd508
 *   @0x137810 eoreq r8, r0, r0, ror #21
 *   @0x137814 .word 0xffffd50c
 *   @0x137818 .word 0x00208ad8
 *   @0x13781c .word 0xffffd510
 *   @0x137820 .word 0x00208ad0
 *   @0x137824 .word 0xffffd514
 *   @0x137828 eoreq r8, r0, r12, asr #21
 *   @0x13782c .word 0xffffd518
 *   @0x137830 eoreq r8, r0, r4, asr #21
 *   @0x137834 .word 0xffffd51c
 *   @0x137838 .word 0x00208abc
 *   @0x13783c .word 0xffffd520
 *   @0x137840 .word 0x00208ab4
 *   @0x137844 .word 0xffffd524
 *   @0x137848 eoreq r8, r0, r12, lsr #21
 *   @0x13784c .word 0xffffd528
 *   @0x137850 eoreq r8, r0, r4, lsr #21
 *   @0x137854 .word 0xffffd52c
 *   @0x137858 eoreq r8, r0, r0, lsr #21
 *   @0x13785c .word 0xffffd530
 *   @0x137860 mlaeq r0, r8, r10, r8
 *   @0x137864 .word 0xffffd534
 *   @0x137868 mlaeq r0, r0, r10, r8
 *   @0x13786c .word 0xffffd538
 *   @0x137870 eoreq r8, r0, r8, lsl #21
 *   @0x137874 .word 0xffffd53c
 *   @0x137878 eoreq r8, r0, r12, ror r10
 *   @0x13787c .word 0xffffd540
 *   @0x137880 eoreq r8, r0, r4, ror r10
 *   @0x137884 .word 0xffffd544
 *   @0x137888 eoreq r8, r0, r0, ror r10
 *   @0x13788c .word 0xffffd548
 *   @0x137890 eoreq r8, r0, r12, ror #20
 *   @0x137894 .word 0xffffd54c
 *   @0x137898 eoreq r8, r0, r4, ror #20
 *   @0x13789c .word 0xffffd550
 *   @0x1378a0 eoreq r8, r0, r12, asr r10
 *   @0x1378a4 .word 0xffffd554
 *   @0x1378a8 eoreq r8, r0, r4, asr r10
 *   @0x1378ac .word 0xffffd558
 *   @0x1378b0 eoreq r8, r0, r0, asr r10
 *   @0x1378b4 .word 0xffffd55c
 *   @0x1378b8 eoreq r8, r0, r12, asr #20
 *   @0x1378bc .word 0xffffd560
 *   @0x1378c0 eoreq r8, r0, r8, asr #20
 *   @0x1378c4 .word 0xffffd564
 *   @0x1378c8 eoreq r8, r0, r8, asr #20
 *   @0x1378cc .word 0xffffd568
 *   @0x1378d0 eoreq r8, r0, r8, asr #20
 *   @0x1378d4 .word 0xffffd56c
 *   @0x1378d8 eoreq r8, r0, r12, asr #20
 *   @0x1378dc .word 0xffffd570
 *   @0x1378e0 eoreq r8, r0, r8, asr #20
 *   @0x1378e4 .word 0xffffd574
 *   @0x1378e8 eoreq r8, r0, r4, asr #20
 *   @0x1378ec .word 0xffffd578
 *   @0x1378f0 eoreq r8, r0, r0, asr #20
 *   @0x1378f4 .word 0xffffd57c
 *   @0x1378f8 eoreq r8, r0, r12, lsr r10
 *   @0x1378fc .word 0xffffd580
 *   @0x137900 eoreq r8, r0, r8, lsr r10
 *   @0x137904 .word 0xffffd584
 *   @0x137908 eoreq r8, r0, r12, lsr #20
 *   @0x13790c .word 0xffffd588
 *   @0x137910 eoreq r8, r0, r0, lsr r10
 *   @0x137914 .word 0xffffd58c
 *   @0x137918 eoreq r8, r0, r4, lsr r10
 *   @0x13791c .word 0xffffd590
 *   @0x137920 eoreq r8, r0, r12, lsr #20
 *   @0x137924 .word 0xffffd594
 *   @0x137928 eoreq r8, r0, r4, lsr #20
 *   @0x13792c .word 0xffffd598
 *   @0x137930 eoreq r8, r0, r0, lsr #20
 *   @0x137934 .word 0xffffd59c
 *   @0x137938 eoreq r8, r0, r0, lsr #20
 *   @0x13793c .word 0xffffd5a0
 *   @0x137940 eoreq r8, r0, r8, lsl r10
 *   @0x137944 .word 0xffffd5a4
 *   @0x137948 eoreq r8, r0, r4, lsl r10
 *   @0x13794c .word 0xffffd5a8
 *   @0x137950 eoreq r8, r0, r0, lsl r10
 *   @0x137954 .word 0xffffd5ac
 *   @0x137958 eoreq r8, r0, r0, lsl r10
 *   @0x13795c .word 0xffffd5b0
 *   @0x137960 eoreq r8, r0, r12, lsl #20
 *   @0x137964 .word 0xffffd5b4
 *   @0x137968 eoreq r8, r0, r8, lsl #20
 *   @0x13796c .word 0xffffd5b8
 *   @0x137970 eoreq r8, r0, r4, lsl #20
 *   @0x137974 .word 0xffffd5bc
 *   @0x137978 .word 0x002089fc
 *   @0x13797c .word 0xffffd5c0
 *   @0x137980 .word 0x002089f8
 *   @0x137984 .word 0xffffd5c4
 *   @0x137988 .word 0x002089f4
 *   @0x13798c .word 0xffffd5c8
 *   @0x137990 .word 0x002089f4
 *   @0x137994 .word 0xffffd5cc
 *   @0x137998 .word 0x002089f0
 *   @0x13799c .word 0xffffd5d0
 *   @0x1379a0 .word 0x002089f4
 *   @0x1379a4 .word 0xffffd5d4
 *   @0x1379a8 .word 0x002089f8
 *   @0x1379ac .word 0xffffd5d8
 *   @0x1379b0 .word 0x002089fc
 *   @0x1379b4 .word 0xffffd5dc
 *   @0x1379b8 eoreq r8, r0, r0, lsl #20
 *   @0x1379bc .word 0xffffd5e0
 *   @0x1379c0 .word 0x002089fc
 *   @0x1379c4 .word 0xffffd5e4
 *   @0x1379c8 .word 0x002089f8
 *   @0x1379cc .word 0xffffd5e8
 *   @0x1379d0 .word 0x002089f4
 *   @0x1379d4 .word 0xffffd5ec
 *   @0x1379d8 .word 0x002089f4
 *   @0x1379dc .word 0xffffd5f0
 *   @0x1379e0 .word 0x002089f0
 *   @0x1379e4 .word 0xffffd5f4
 *   @0x1379e8 .word 0x002089f0
 *   @0x1379ec .word 0xffffd5f8
 *   @0x1379f0 .word 0x002089f0
 *   @0x1379f4 .word 0xffffd5fc
 *   @0x1379f8 eoreq r8, r0, r12, ror #19
 *   @0x1379fc .word 0xffffd600
 *   @0x137a00 eoreq r8, r0, r8, ror #19
 *   @0x137a04 .word 0xffffd604
 *   @0x137a08 eoreq r8, r0, r4, ror #19
 *   @0x137a0c .word 0xffffd608
 *   @0x137a10 eoreq r8, r0, r0, ror #19
 *   @0x137a14 .word 0xffffd60c
 *   @0x137a18 eoreq r8, r0, r4, ror #19
 *   @0x137a1c .word 0xffffd610
 *   @0x137a20 eoreq r8, r0, r0, ror #19
 *   @0x137a24 .word 0xffffd614
 *   @0x137a28 eoreq r8, r0, r0, ror #19
 *   @0x137a2c .word 0xffffd618
 *   @0x137a30 .word 0x002089d8
 *   @0x137a34 .word 0xffffd61c
 *   @0x137a38 .word 0x002089d4
 *
 * ══ §2/6 InitSteamFunctions  0x16258c..0x163170  size 3044  761 条（592 条指令 + 169 个池字）══
 * @func 0x16258c 0x163170  size 3044  761 条
 * 注册 84 条｜唯一名 84｜唯一函数指针 84｜argc 0:17 1:26 2:27 3:9 4:3 5:1 7:1｜flag 0:84
 * 首条 #0 steam_activate_overlay（0x1625b0）→ 末条 #83 steam_ugc_send_query（0x162ec8）
 * 名字族（前 8）: steam×84
 * 游戏实际调用的 99 个内建里落在本表: 0 个
 * 表: asm/init-tables/init-InitSteamFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: 无（本函数每条注册的四实参全部解出，控制流全部走到）
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16258c push {r4, lr}
 *   @0x162590 mov r2, #1
 *   @0x162594 ldr r4, [pc, #0x930]
 *   @0x162598 mov r3, #0
 *   @0x16259c ldr r1, [pc, #0x92c]
 *   @0x1625a0 add r4, pc, r4
 *   @0x1625a4 ldr r0, [pc, #0x928]
 *   @0x1625a8 ldr r1, [r4, r1]
 *   @0x1625ac add r0, pc, r0
 *   @0x1625b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 steam_activate_overlay → F_Steam_ActivateOverlay(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1625b4 ldr r1, [pc, #0x91c]
 *   @0x1625b8 ldr r0, [pc, #0x91c]
 *   @0x1625bc mov r2, #0
 *   @0x1625c0 mov r3, r2
 *   @0x1625c4 ldr r1, [r4, r1]
 *   @0x1625c8 add r0, pc, r0
 *   @0x1625cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 steam_is_overlay_enabled → F_Steam_OverlayEnabled(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1625d0 ldr r1, [pc, #0x908]
 *   @0x1625d4 ldr r0, [pc, #0x908]
 *   @0x1625d8 mov r2, #0
 *   @0x1625dc mov r3, r2
 *   @0x1625e0 ldr r1, [r4, r1]
 *   @0x1625e4 add r0, pc, r0
 *   @0x1625e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 steam_is_overlay_activated → F_Steam_OverlayActive(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1625ec ldr r1, [pc, #0x8f4]
 *   @0x1625f0 ldr r0, [pc, #0x8f4]
 *   @0x1625f4 mov r2, #0
 *   @0x1625f8 mov r3, r2
 *   @0x1625fc ldr r1, [r4, r1]
 *   @0x162600 add r0, pc, r0
 *   @0x162604 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 steam_get_persona_name → F_Steam_GetPersonalName(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x162608 ldr r1, [pc, #0x8e0]
 *   @0x16260c ldr r0, [pc, #0x8e0]
 *   @0x162610 mov r2, #0
 *   @0x162614 mov r3, r2
 *   @0x162618 ldr r1, [r4, r1]
 *   @0x16261c add r0, pc, r0
 *   @0x162620 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #4 steam_initialised → F_Steam_Initialised(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x162624 ldr r1, [pc, #0x8cc]
 *   @0x162628 ldr r0, [pc, #0x8cc]
 *   @0x16262c mov r2, #0
 *   @0x162630 mov r3, r2
 *   @0x162634 ldr r1, [r4, r1]
 *   @0x162638 add r0, pc, r0
 *   @0x16263c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #5 steam_is_cloud_enabled_for_app → F_Steam_IsCloudEnabledForApp(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x162640 ldr r1, [pc, #0x8b8]
 *   @0x162644 ldr r0, [pc, #0x8b8]
 *   @0x162648 mov r2, #0
 *   @0x16264c mov r3, r2
 *   @0x162650 ldr r1, [r4, r1]
 *   @0x162654 add r0, pc, r0
 *   @0x162658 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #6 steam_is_cloud_enabled_for_account → F_Steam_IsCloudEnabledForAccount(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x16265c ldr r1, [pc, #0x8a4]
 *   @0x162660 ldr r0, [pc, #0x8a4]
 *   @0x162664 mov r2, #1
 *   @0x162668 mov r3, #0
 *   @0x16266c ldr r1, [r4, r1]
 *   @0x162670 add r0, pc, r0
 *   @0x162674 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #7 steam_file_persisted → F_Steam_FilePersisted(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x162678 ldr r1, [pc, #0x890]
 *   @0x16267c ldr r0, [pc, #0x890]
 *   @0x162680 mov r2, #0
 *   @0x162684 mov r3, r2
 *   @0x162688 ldr r1, [r4, r1]
 *   @0x16268c add r0, pc, r0
 *   @0x162690 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #8 steam_get_quota_total → F_Steam_GetQuotaTotal(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x162694 ldr r1, [pc, #0x87c]
 *   @0x162698 ldr r0, [pc, #0x87c]
 *   @0x16269c mov r2, #0
 *   @0x1626a0 mov r3, r2
 *   @0x1626a4 ldr r1, [r4, r1]
 *   @0x1626a8 add r0, pc, r0
 *   @0x1626ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #9 steam_get_quota_free → F_Steam_GetQuotaFree(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1626b0 ldr r1, [pc, #0x868]
 *   @0x1626b4 ldr r0, [pc, #0x868]
 *   @0x1626b8 mov r2, #3
 *   @0x1626bc mov r3, #0
 *   @0x1626c0 ldr r1, [r4, r1]
 *   @0x1626c4 add r0, pc, r0
 *   @0x1626c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #10 steam_file_write → F_Steam_FileWrite(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x1626cc ldr r1, [pc, #0x854]
 *   @0x1626d0 ldr r0, [pc, #0x854]
 *   @0x1626d4 mov r2, #2
 *   @0x1626d8 mov r3, #0
 *   @0x1626dc ldr r1, [r4, r1]
 *   @0x1626e0 add r0, pc, r0
 *   @0x1626e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #11 steam_file_write_file → F_Steam_FileWriteFile(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1626e8 ldr r1, [pc, #0x840]
 *   @0x1626ec ldr r0, [pc, #0x840]
 *   @0x1626f0 mov r2, #1
 *   @0x1626f4 mov r3, #0
 *   @0x1626f8 ldr r1, [r4, r1]
 *   @0x1626fc add r0, pc, r0
 *   @0x162700 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #12 steam_file_read → F_Steam_FileRead(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x162704 ldr r1, [pc, #0x82c]
 *   @0x162708 ldr r0, [pc, #0x82c]
 *   @0x16270c mov r2, #1
 *   @0x162710 mov r3, #0
 *   @0x162714 ldr r1, [r4, r1]
 *   @0x162718 add r0, pc, r0
 *   @0x16271c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #13 steam_file_delete → F_Steam_FileDelete(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x162720 ldr r1, [pc, #0x818]
 *   @0x162724 ldr r0, [pc, #0x818]
 *   @0x162728 mov r2, #1
 *   @0x16272c mov r3, #0
 *   @0x162730 ldr r1, [r4, r1]
 *   @0x162734 add r0, pc, r0
 *   @0x162738 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #14 steam_file_exists → F_Steam_FileExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x16273c ldr r1, [pc, #0x804]
 *   @0x162740 ldr r0, [pc, #0x804]
 *   @0x162744 mov r2, #1
 *   @0x162748 mov r3, #0
 *   @0x16274c ldr r1, [r4, r1]
 *   @0x162750 add r0, pc, r0
 *   @0x162754 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #15 steam_file_size → F_Steam_FileSize(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x162758 ldr r1, [pc, #0x7f0]
 *   @0x16275c ldr r0, [pc, #0x7f0]
 *   @0x162760 mov r2, #1
 *   @0x162764 mov r3, #0
 *   @0x162768 ldr r1, [r4, r1]
 *   @0x16276c add r0, pc, r0
 *   @0x162770 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #16 steam_file_share → F_Steam_FileShare(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x162774 ldr r1, [pc, #0x7dc]
 *   @0x162778 ldr r0, [pc, #0x7dc]
 *   @0x16277c mov r2, #4
 *   @0x162780 mov r3, #0
 *   @0x162784 ldr r1, [r4, r1]
 *   @0x162788 add r0, pc, r0
 *   @0x16278c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #17 steam_publish_workshop_file → F_Steam_PublishWorkshopFile(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x162790 ldr r1, [pc, #0x7c8]
 *   @0x162794 ldr r0, [pc, #0x7c8]
 *   @0x162798 mov r2, #0
 *   @0x16279c mov r3, r2
 *   @0x1627a0 ldr r1, [r4, r1]
 *   @0x1627a4 add r0, pc, r0
 *   @0x1627a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #18 steam_is_screenshot_requested → F_Steam_IsScreenshotRequested(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1627ac ldr r1, [pc, #0x7b4]
 *   @0x1627b0 ldr r0, [pc, #0x7b4]
 *   @0x1627b4 mov r2, #3
 *   @0x1627b8 mov r3, #0
 *   @0x1627bc ldr r1, [r4, r1]
 *   @0x1627c0 add r0, pc, r0
 *   @0x1627c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #19 steam_send_screenshot → F_Steam_SendScreenshotToSteam(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x1627c8 ldr r1, [pc, #0x7a0]
 *   @0x1627cc ldr r0, [pc, #0x7a0]
 *   @0x1627d0 mov r2, #0
 *   @0x1627d4 mov r3, r2
 *   @0x1627d8 ldr r1, [r4, r1]
 *   @0x1627dc add r0, pc, r0
 *   @0x1627e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #20 steam_is_user_logged_on → F_Steam_IsLoggedOn(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1627e4 ldr r1, [pc, #0x78c]
 *   @0x1627e8 ldr r0, [pc, #0x78c]
 *   @0x1627ec mov r2, #0
 *   @0x1627f0 mov r3, r2
 *   @0x1627f4 ldr r1, [r4, r1]
 *   @0x1627f8 add r0, pc, r0
 *   @0x1627fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #21 steam_get_user_steam_id → F_Steam_GetSteamID(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x162800 ldr r1, [pc, #0x778]
 *   @0x162804 ldr r0, [pc, #0x778]
 *   @0x162808 mov r2, #1
 *   @0x16280c mov r3, #0
 *   @0x162810 ldr r1, [r4, r1]
 *   @0x162814 add r0, pc, r0
 *   @0x162818 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #22 steam_user_owns_dlc → F_Steam_DoesUserOwnDLC(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x16281c ldr r1, [pc, #0x764]
 *   @0x162820 ldr r0, [pc, #0x764]
 *   @0x162824 mov r2, #1
 *   @0x162828 mov r3, #0
 *   @0x16282c ldr r1, [r4, r1]
 *   @0x162830 add r0, pc, r0
 *   @0x162834 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #23 steam_user_installed_dlc → F_Steam_HasUserInstalledDLC(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x162838 ldr r1, [pc, #0x750]
 *   @0x16283c ldr r0, [pc, #0x750]
 *   @0x162840 mov r2, #1
 *   @0x162844 mov r3, #0
 *   @0x162848 ldr r1, [r4, r1]
 *   @0x16284c add r0, pc, r0
 *   @0x162850 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #24 steam_current_game_language → F_SteamCurrentGameLanguage(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x162854 ldr r1, [pc, #0x73c]
 *   @0x162858 ldr r0, [pc, #0x73c]
 *   @0x16285c mov r2, #1
 *   @0x162860 mov r3, #0
 *   @0x162864 ldr r1, [r4, r1]
 *   @0x162868 add r0, pc, r0
 *   @0x16286c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #25 steam_available_languages → F_SteamAvailableGameLanguages(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x162870 ldr r1, [pc, #0x728]
 *   @0x162874 ldr r0, [pc, #0x728]
 *   @0x162878 mov r2, #1
 *   @0x16287c mov r3, #0
 *   @0x162880 ldr r1, [r4, r1]
 *   @0x162884 add r0, pc, r0
 *   @0x162888 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #26 steam_activate_overlay_browser → F_Steam_ActivateOverlayBrowser(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x16288c ldr r1, [pc, #0x714]
 *   @0x162890 ldr r0, [pc, #0x714]
 *   @0x162894 mov r2, #2
 *   @0x162898 mov r3, #0
 *   @0x16289c ldr r1, [r4, r1]
 *   @0x1628a0 add r0, pc, r0
 *   @0x1628a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #27 steam_activate_overlay_user → F_Steam_ActivateOverlayUser(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x1628a8 ldr r1, [pc, #0x700]
 *   @0x1628ac ldr r0, [pc, #0x700]
 *   @0x1628b0 mov r2, #1
 *   @0x1628b4 mov r3, #0
 *   @0x1628b8 ldr r1, [r4, r1]
 *   @0x1628bc add r0, pc, r0
 *   @0x1628c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #28 steam_activate_overlay_store → F_Steam_ActivateOverlayStore(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1628c4 ldr r1, [pc, #0x6ec]
 *   @0x1628c8 ldr r0, [pc, #0x6ec]
 *   @0x1628cc mov r2, #1
 *   @0x1628d0 mov r3, #0
 *   @0x1628d4 ldr r1, [r4, r1]
 *   @0x1628d8 add r0, pc, r0
 *   @0x1628dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #29 steam_get_user_persona_name → F_Steam_GetUserPersonaName(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1628e0 ldr r1, [pc, #0x6d8]
 *   @0x1628e4 ldr r0, [pc, #0x6d8]
 *   @0x1628e8 mov r2, #1
 *   @0x1628ec mov r3, #0
 *   @0x1628f0 ldr r1, [r4, r1]
 *   @0x1628f4 add r0, pc, r0
 *   @0x1628f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #30 steam_set_achievement → F_Steam_SetAchievement(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1628fc ldr r1, [pc, #0x6c4]
 *   @0x162900 ldr r0, [pc, #0x6c4]
 *   @0x162904 mov r2, #1
 *   @0x162908 mov r3, #0
 *   @0x16290c ldr r1, [r4, r1]
 *   @0x162910 add r0, pc, r0
 *   @0x162914 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #31 steam_get_achievement → F_Steam_GetAchievement(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x162918 ldr r1, [pc, #0x6b0]
 *   @0x16291c ldr r0, [pc, #0x6b0]
 *   @0x162920 mov r2, #1
 *   @0x162924 mov r3, #0
 *   @0x162928 ldr r1, [r4, r1]
 *   @0x16292c add r0, pc, r0
 *   @0x162930 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #32 steam_clear_achievement → F_Steam_ClearAchievement(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x162934 ldr r1, [pc, #0x69c]
 *   @0x162938 ldr r0, [pc, #0x69c]
 *   @0x16293c mov r2, #2
 *   @0x162940 mov r3, #0
 *   @0x162944 ldr r1, [r4, r1]
 *   @0x162948 add r0, pc, r0
 *   @0x16294c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #33 steam_set_stat_int → F_Steam_SetStatInt(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162950 ldr r1, [pc, #0x688]
 *   @0x162954 ldr r0, [pc, #0x688]
 *   @0x162958 mov r2, #2
 *   @0x16295c mov r3, #0
 *   @0x162960 ldr r1, [r4, r1]
 *   @0x162964 add r0, pc, r0
 *   @0x162968 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #34 steam_set_stat_float → F_Steam_SetStatFloat(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x16296c ldr r1, [pc, #0x674]
 *   @0x162970 ldr r0, [pc, #0x674]
 *   @0x162974 mov r2, #3
 *   @0x162978 mov r3, #0
 *   @0x16297c ldr r1, [r4, r1]
 *   @0x162980 add r0, pc, r0
 *   @0x162984 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #35 steam_set_stat_avg_rate → F_Steam_SetStatAvgRate(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x162988 ldr r1, [pc, #0x660]
 *   @0x16298c ldr r0, [pc, #0x660]
 *   @0x162990 mov r2, #1
 *   @0x162994 mov r3, #0
 *   @0x162998 ldr r1, [r4, r1]
 *   @0x16299c add r0, pc, r0
 *   @0x1629a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #36 steam_get_stat_int → F_Steam_GetStatInt(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1629a4 ldr r1, [pc, #0x64c]
 *   @0x1629a8 ldr r0, [pc, #0x64c]
 *   @0x1629ac mov r2, #1
 *   @0x1629b0 mov r3, #0
 *   @0x1629b4 ldr r1, [r4, r1]
 *   @0x1629b8 add r0, pc, r0
 *   @0x1629bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #37 steam_get_stat_float → F_Steam_GetStatFloat(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1629c0 ldr r1, [pc, #0x638]
 *   @0x1629c4 ldr r0, [pc, #0x638]
 *   @0x1629c8 mov r2, #1
 *   @0x1629cc mov r3, #0
 *   @0x1629d0 ldr r1, [r4, r1]
 *   @0x1629d4 add r0, pc, r0
 *   @0x1629d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #38 steam_get_stat_avg_rate → F_Steam_GetStatAvgRate(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x1629dc ldr r1, [pc, #0x624]
 *   @0x1629e0 ldr r0, [pc, #0x624]
 *   @0x1629e4 mov r2, #0
 *   @0x1629e8 mov r3, r2
 *   @0x1629ec ldr r1, [r4, r1]
 *   @0x1629f0 add r0, pc, r0
 *   @0x1629f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #39 steam_reset_all_stats → F_Steam_ResetAllStats(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x1629f8 ldr r1, [pc, #0x610]
 *   @0x1629fc ldr r0, [pc, #0x610]
 *   @0x162a00 mov r2, #0
 *   @0x162a04 mov r3, r2
 *   @0x162a08 ldr r1, [r4, r1]
 *   @0x162a0c add r0, pc, r0
 *   @0x162a10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #40 steam_reset_all_stats_achievements → F_Steam_ResetAllStatsAchievements(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x162a14 ldr r1, [pc, #0x5fc]
 *   @0x162a18 ldr r0, [pc, #0x5fc]
 *   @0x162a1c mov r2, #0
 *   @0x162a20 mov r3, r2
 *   @0x162a24 ldr r1, [r4, r1]
 *   @0x162a28 add r0, pc, r0
 *   @0x162a2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #41 steam_stats_ready → F_Steam_StatsReady(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x162a30 ldr r1, [pc, #0x5e8]
 *   @0x162a34 ldr r0, [pc, #0x5e8]
 *   @0x162a38 mov r2, #3
 *   @0x162a3c mov r3, #0
 *   @0x162a40 ldr r1, [r4, r1]
 *   @0x162a44 add r0, pc, r0
 *   @0x162a48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #42 steam_create_leaderboard → F_Steam_CreateLeaderboard(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x162a4c ldr r1, [pc, #0x5d4]
 *   @0x162a50 ldr r0, [pc, #0x5d4]
 *   @0x162a54 mov r2, #2
 *   @0x162a58 mov r3, #0
 *   @0x162a5c ldr r1, [r4, r1]
 *   @0x162a60 add r0, pc, r0
 *   @0x162a64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #43 steam_upload_score → F_Steam_UploadScore(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162a68 ldr r1, [pc, #0x5c0]
 *   @0x162a6c ldr r0, [pc, #0x5c0]
 *   @0x162a70 mov r2, #3
 *   @0x162a74 mov r3, #0
 *   @0x162a78 ldr r1, [r4, r1]
 *   @0x162a7c add r0, pc, r0
 *   @0x162a80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #44 steam_download_scores_around_user → F_Steam_DownloadScoresUserRange(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x162a84 ldr r1, [pc, #0x5ac]
 *   @0x162a88 ldr r0, [pc, #0x5ac]
 *   @0x162a8c mov r2, #3
 *   @0x162a90 mov r3, #0
 *   @0x162a94 ldr r1, [r4, r1]
 *   @0x162a98 add r0, pc, r0
 *   @0x162a9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #45 steam_download_scores → F_Steam_DownloadScores(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x162aa0 ldr r1, [pc, #0x598]
 *   @0x162aa4 ldr r0, [pc, #0x598]
 *   @0x162aa8 mov r2, #1
 *   @0x162aac mov r3, #0
 *   @0x162ab0 ldr r1, [r4, r1]
 *   @0x162ab4 add r0, pc, r0
 *   @0x162ab8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #46 steam_download_friends_scores → F_Steam_DownloadFriendsScores(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x162abc ldr r1, [pc, #0x584]
 *   @0x162ac0 ldr r0, [pc, #0x584]
 *   @0x162ac4 mov r2, #3
 *   @0x162ac8 mov r3, #0
 *   @0x162acc ldr r1, [r4, r1]
 *   @0x162ad0 add r0, pc, r0
 *   @0x162ad4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #47 steam_upload_score_buffer → F_Steam_UploadScoreBuffer(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x162ad8 ldr r1, [pc, #0x570]
 *   @0x162adc ldr r0, [pc, #0x570]
 *   @0x162ae0 mov r2, #3
 *   @0x162ae4 mov r3, #0
 *   @0x162ae8 ldr r1, [r4, r1]
 *   @0x162aec add r0, pc, r0
 *   @0x162af0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #48 steam_upload_score_ext → F_Steam_UploadScoreExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x162af4 ldr r1, [pc, #0x55c]
 *   @0x162af8 ldr r0, [pc, #0x55c]
 *   @0x162afc mov r2, #4
 *   @0x162b00 mov r3, #0
 *   @0x162b04 ldr r1, [r4, r1]
 *   @0x162b08 add r0, pc, r0
 *   @0x162b0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #49 steam_upload_score_buffer_ext → F_Steam_UploadScoreBufferExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x162b10 ldr r1, [pc, #0x548]
 *   @0x162b14 ldr r0, [pc, #0x548]
 *   @0x162b18 mov r2, #0
 *   @0x162b1c mov r3, r2
 *   @0x162b20 ldr r1, [r4, r1]
 *   @0x162b24 add r0, pc, r0
 *   @0x162b28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #50 steam_get_app_id → F_Steam_GetAppId(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x162b2c ldr r1, [pc, #0x534]
 *   @0x162b30 ldr r0, [pc, #0x534]
 *   @0x162b34 mov r2, #0
 *   @0x162b38 mov r3, r2
 *   @0x162b3c ldr r1, [r4, r1]
 *   @0x162b40 add r0, pc, r0
 *   @0x162b44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #51 steam_get_user_account_id → F_Steam_GetUserAccountId(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x162b48 ldr r1, [pc, #0x520]
 *   @0x162b4c ldr r0, [pc, #0x520]
 *   @0x162b50 mov r2, #2
 *   @0x162b54 mov r3, #0
 *   @0x162b58 ldr r1, [r4, r1]
 *   @0x162b5c add r0, pc, r0
 *   @0x162b60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #52 steam_ugc_download → F_Steam_UGCDownload(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162b64 ldr r1, [pc, #0x50c]
 *   @0x162b68 ldr r0, [pc, #0x50c]
 *   @0x162b6c mov r2, #2
 *   @0x162b70 mov r3, #0
 *   @0x162b74 ldr r1, [r4, r1]
 *   @0x162b78 add r0, pc, r0
 *   @0x162b7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #53 steam_ugc_create_item → F_SteamUGC_CreateItem(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162b80 ldr r1, [pc, #0x4f8]
 *   @0x162b84 ldr r0, [pc, #0x4f8]
 *   @0x162b88 mov r2, #2
 *   @0x162b8c mov r3, #0
 *   @0x162b90 ldr r1, [r4, r1]
 *   @0x162b94 add r0, pc, r0
 *   @0x162b98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #54 steam_ugc_start_item_update → F_SteamUGC_StartItemUpdate(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162b9c ldr r1, [pc, #0x4e4]
 *   @0x162ba0 ldr r0, [pc, #0x4e4]
 *   @0x162ba4 mov r2, #2
 *   @0x162ba8 mov r3, #0
 *   @0x162bac ldr r1, [r4, r1]
 *   @0x162bb0 add r0, pc, r0
 *   @0x162bb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #55 steam_ugc_set_item_title → F_SteamUGC_SetItemTitle(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162bb8 ldr r1, [pc, #0x4d0]
 *   @0x162bbc ldr r0, [pc, #0x4d0]
 *   @0x162bc0 mov r2, #2
 *   @0x162bc4 mov r3, #0
 *   @0x162bc8 ldr r1, [r4, r1]
 *   @0x162bcc add r0, pc, r0
 *   @0x162bd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #56 steam_ugc_set_item_description → F_SteamUGC_SetItemDesc(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162bd4 ldr r1, [pc, #0x4bc]
 *   @0x162bd8 ldr r0, [pc, #0x4bc]
 *   @0x162bdc mov r2, #2
 *   @0x162be0 mov r3, #0
 *   @0x162be4 ldr r1, [r4, r1]
 *   @0x162be8 add r0, pc, r0
 *   @0x162bec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #57 steam_ugc_set_item_visibility → F_SteamUGC_SetItemVis(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162bf0 ldr r1, [pc, #0x4a8]
 *   @0x162bf4 ldr r0, [pc, #0x4a8]
 *   @0x162bf8 mov r2, #2
 *   @0x162bfc mov r3, #0
 *   @0x162c00 ldr r1, [r4, r1]
 *   @0x162c04 add r0, pc, r0
 *   @0x162c08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #58 steam_ugc_set_item_tags → F_SteamUGC_SetItemTags(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162c0c ldr r1, [pc, #0x494]
 *   @0x162c10 ldr r0, [pc, #0x494]
 *   @0x162c14 mov r2, #2
 *   @0x162c18 mov r3, #0
 *   @0x162c1c ldr r1, [r4, r1]
 *   @0x162c20 add r0, pc, r0
 *   @0x162c24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #59 steam_ugc_set_item_content → F_SteamUGC_SetItemContent(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162c28 ldr r1, [pc, #0x480]
 *   @0x162c2c ldr r0, [pc, #0x480]
 *   @0x162c30 mov r2, #2
 *   @0x162c34 mov r3, #0
 *   @0x162c38 ldr r1, [r4, r1]
 *   @0x162c3c add r0, pc, r0
 *   @0x162c40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #60 steam_ugc_set_item_preview → F_SteamUGC_SetItemPreview(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162c44 ldr r1, [pc, #0x46c]
 *   @0x162c48 ldr r0, [pc, #0x46c]
 *   @0x162c4c mov r2, #2
 *   @0x162c50 mov r3, #0
 *   @0x162c54 ldr r1, [r4, r1]
 *   @0x162c58 add r0, pc, r0
 *   @0x162c5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #61 steam_ugc_submit_item_update → F_SteamUGC_SubmitItemUpdate(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162c60 ldr r1, [pc, #0x458]
 *   @0x162c64 ldr r0, [pc, #0x458]
 *   @0x162c68 mov r2, #1
 *   @0x162c6c mov r3, #0
 *   @0x162c70 ldr r1, [r4, r1]
 *   @0x162c74 add r0, pc, r0
 *   @0x162c78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #62 steam_ugc_get_item_update_progress → F_SteamUGC_GetItemUpdateProgress(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x162c7c ldr r1, [pc, #0x444]
 *   @0x162c80 ldr r0, [pc, #0x444]
 *   @0x162c84 mov r2, #1
 *   @0x162c88 mov r3, #0
 *   @0x162c8c ldr r1, [r4, r1]
 *   @0x162c90 add r0, pc, r0
 *   @0x162c94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #63 steam_ugc_subscribe_item → F_SteamUGC_SubscribeItem(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x162c98 ldr r1, [pc, #0x430]
 *   @0x162c9c ldr r0, [pc, #0x430]
 *   @0x162ca0 mov r2, #1
 *   @0x162ca4 mov r3, #0
 *   @0x162ca8 ldr r1, [r4, r1]
 *   @0x162cac add r0, pc, r0
 *   @0x162cb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #64 steam_ugc_unsubscribe_item → F_SteamUGC_UnsubscribeItem(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x162cb4 ldr r1, [pc, #0x41c]
 *   @0x162cb8 ldr r0, [pc, #0x41c]
 *   @0x162cbc mov r2, #0
 *   @0x162cc0 mov r3, r2
 *   @0x162cc4 ldr r1, [r4, r1]
 *   @0x162cc8 add r0, pc, r0
 *   @0x162ccc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #65 steam_ugc_num_subscribed_items → F_SteamUGC_GetNumSubscribedItems(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x162cd0 ldr r1, [pc, #0x408]
 *   @0x162cd4 ldr r0, [pc, #0x408]
 *   @0x162cd8 mov r2, #1
 *   @0x162cdc mov r3, #0
 *   @0x162ce0 ldr r1, [r4, r1]
 *   @0x162ce4 add r0, pc, r0
 *   @0x162ce8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #66 steam_ugc_get_subscribed_items → F_SteamUGC_GetSubscribedItems(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x162cec ldr r1, [pc, #0x3f4]
 *   @0x162cf0 ldr r0, [pc, #0x3f4]
 *   @0x162cf4 mov r2, #2
 *   @0x162cf8 mov r3, #0
 *   @0x162cfc ldr r1, [r4, r1]
 *   @0x162d00 add r0, pc, r0
 *   @0x162d04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #67 steam_ugc_get_item_install_info → F_SteamUGC_GetItemInstallInfo(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162d08 ldr r1, [pc, #0x3e0]
 *   @0x162d0c ldr r0, [pc, #0x3e0]
 *   @0x162d10 mov r2, #2
 *   @0x162d14 mov r3, #0
 *   @0x162d18 ldr r1, [r4, r1]
 *   @0x162d1c add r0, pc, r0
 *   @0x162d20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #68 steam_ugc_get_item_update_info → F_SteamUGC_GetItemUpdateInfo(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162d24 ldr r1, [pc, #0x3cc]
 *   @0x162d28 ldr r0, [pc, #0x3cc]
 *   @0x162d2c mov r2, #2
 *   @0x162d30 mov r3, #0
 *   @0x162d34 ldr r1, [r4, r1]
 *   @0x162d38 add r0, pc, r0
 *   @0x162d3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #69 steam_ugc_request_item_details → F_SteamUGC_RequestItemDetails(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162d40 ldr r1, [pc, #0x3b8]
 *   @0x162d44 ldr r0, [pc, #0x3b8]
 *   @0x162d48 mov r2, #4
 *   @0x162d4c mov r3, #0
 *   @0x162d50 ldr r1, [r4, r1]
 *   @0x162d54 add r0, pc, r0
 *   @0x162d58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #70 steam_ugc_create_query_user → F_SteamUGC_CreateQueryUser(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x162d5c ldr r1, [pc, #0x3a4]
 *   @0x162d60 ldr r0, [pc, #0x3a4]
 *   @0x162d64 mov r2, #7
 *   @0x162d68 mov r3, #0
 *   @0x162d6c ldr r1, [r4, r1]
 *   @0x162d70 add r0, pc, r0
 *   @0x162d74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #71 steam_ugc_create_query_user_ex → F_SteamUGC_CreateQueryUserEx(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=0
 *   @0x162d78 ldr r1, [pc, #0x390]
 *   @0x162d7c ldr r0, [pc, #0x390]
 *   @0x162d80 mov r2, #3
 *   @0x162d84 mov r3, #0
 *   @0x162d88 ldr r1, [r4, r1]
 *   @0x162d8c add r0, pc, r0
 *   @0x162d90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #72 steam_ugc_create_query_all → F_SteamUGC_CreateQueryAll(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x162d94 ldr r1, [pc, #0x37c]
 *   @0x162d98 ldr r0, [pc, #0x37c]
 *   @0x162d9c mov r2, #5
 *   @0x162da0 mov r3, #0
 *   @0x162da4 ldr r1, [r4, r1]
 *   @0x162da8 add r0, pc, r0
 *   @0x162dac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #73 steam_ugc_create_query_all_ex → F_SteamUGC_CreateQueryAllEx(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0x162db0 ldr r1, [pc, #0x368]
 *   @0x162db4 ldr r0, [pc, #0x368]
 *   @0x162db8 mov r2, #2
 *   @0x162dbc mov r3, #0
 *   @0x162dc0 ldr r1, [r4, r1]
 *   @0x162dc4 add r0, pc, r0
 *   @0x162dc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #74 steam_ugc_query_set_cloud_filename_filter → F_SteamUGC_QuerySetCloudFilenameFilter(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162dcc ldr r1, [pc, #0x354]
 *   @0x162dd0 ldr r0, [pc, #0x354]
 *   @0x162dd4 mov r2, #2
 *   @0x162dd8 mov r3, #0
 *   @0x162ddc ldr r1, [r4, r1]
 *   @0x162de0 add r0, pc, r0
 *   @0x162de4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #75 steam_ugc_query_set_match_any_tag → F_SteamUGC_QuerySetMatchAnyTag(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162de8 ldr r1, [pc, #0x340]
 *   @0x162dec ldr r0, [pc, #0x340]
 *   @0x162df0 mov r2, #2
 *   @0x162df4 mov r3, #0
 *   @0x162df8 ldr r1, [r4, r1]
 *   @0x162dfc add r0, pc, r0
 *   @0x162e00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #76 steam_ugc_query_set_search_text → F_SteamUGC_QuerySetSearchText(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162e04 ldr r1, [pc, #0x32c]
 *   @0x162e08 ldr r0, [pc, #0x32c]
 *   @0x162e0c mov r2, #2
 *   @0x162e10 mov r3, #0
 *   @0x162e14 ldr r1, [r4, r1]
 *   @0x162e18 add r0, pc, r0
 *   @0x162e1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #77 steam_ugc_query_set_ranked_by_trend_days → F_SteamUGC_QuerySetRankedByTrendDays(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162e20 ldr r1, [pc, #0x318]
 *   @0x162e24 ldr r0, [pc, #0x318]
 *   @0x162e28 mov r2, #2
 *   @0x162e2c mov r3, #0
 *   @0x162e30 ldr r1, [r4, r1]
 *   @0x162e34 add r0, pc, r0
 *   @0x162e38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #78 steam_ugc_query_add_required_tag → F_SteamUGC_QueryAddRequiredTag(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162e3c ldr r1, [pc, #0x304]
 *   @0x162e40 ldr r0, [pc, #0x304]
 *   @0x162e44 mov r2, #2
 *   @0x162e48 mov r3, #0
 *   @0x162e4c ldr r1, [r4, r1]
 *   @0x162e50 add r0, pc, r0
 *   @0x162e54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #79 steam_ugc_query_add_excluded_tag → F_SteamUGC_QueryAddExcludedTag(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162e58 ldr r1, [pc, #0x2f0]
 *   @0x162e5c ldr r0, [pc, #0x2f0]
 *   @0x162e60 mov r2, #2
 *   @0x162e64 mov r3, #0
 *   @0x162e68 ldr r1, [r4, r1]
 *   @0x162e6c add r0, pc, r0
 *   @0x162e70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #80 steam_ugc_query_set_return_long_description → F_SteamUGC_SetReturnLongDesc(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162e74 ldr r1, [pc, #0x2dc]
 *   @0x162e78 ldr r0, [pc, #0x2dc]
 *   @0x162e7c mov r2, #2
 *   @0x162e80 mov r3, #0
 *   @0x162e84 ldr r1, [r4, r1]
 *   @0x162e88 add r0, pc, r0
 *   @0x162e8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #81 steam_ugc_query_set_return_total_only → F_SteamUGC_QuerySetReturnTotalOnly(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162e90 ldr r1, [pc, #0x2c8]
 *   @0x162e94 ldr r0, [pc, #0x2c8]
 *   @0x162e98 mov r2, #2
 *   @0x162e9c mov r3, #0
 *   @0x162ea0 ldr r1, [r4, r1]
 *   @0x162ea4 add r0, pc, r0
 *   @0x162ea8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #82 steam_ugc_query_set_allow_cached_response → F_SteamUGC_QuerySetAllowCachedResponse(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x162eac ldr r1, [pc, #0x2b4]
 *   @0x162eb0 ldr r0, [pc, #0x2b4]
 *   @0x162eb4 mov r2, #1
 *   @0x162eb8 mov r3, #0
 *   @0x162ebc ldr r1, [r4, r1]
 *   @0x162ec0 add r0, pc, r0
 *   @0x162ec4 pop {r4, lr}
 *   @0x162ec8 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #83 steam_ugc_send_query → F_SteamUGC_SendQuery(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x162ecc .word 0x0028f6b0
 *   @0x162ed0 .word 0xffffe330
 *   @0x162ed4 andseq r7, lr, r0, asr #12
 *   @0x162ed8 .word 0xffffe334
 *   @0x162edc andseq r7, lr, r12, lsr r6
 *   @0x162ee0 .word 0xffffe338
 *   @0x162ee4 andseq r7, lr, r12, lsr r6
 *   @0x162ee8 .word 0xffffe33c
 *   @0x162eec andseq r7, lr, r12, lsr r6
 *   @0x162ef0 .word 0xffffe340
 *   @0x162ef4 andseq r7, lr, r8, lsr r6
 *   @0x162ef8 .word 0xffffe344
 *   @0x162efc andseq r7, lr, r0, lsr r6
 *   @0x162f00 .word 0xffffe348
 *   @0x162f04 andseq r7, lr, r4, lsr r6
 *   @0x162f08 .word 0xffffe34c
 *   @0x162f0c andseq r7, lr, r12, lsr r6
 *   @0x162f10 .word 0xffffe350
 *   @0x162f14 andseq r7, lr, r8, lsr r6
 *   @0x162f18 .word 0xffffe354
 *   @0x162f1c andseq r7, lr, r4, lsr r6
 *   @0x162f20 .word 0xffffe358
 *   @0x162f24 andseq r7, lr, r0, lsr r6
 *   @0x162f28 .word 0xffffe35c
 *   @0x162f2c andseq r7, lr, r8, lsr #12
 *   @0x162f30 .word 0xffffe360
 *   @0x162f34 andseq r7, lr, r4, lsr #12
 *   @0x162f38 .word 0xffffe364
 *   @0x162f3c andseq r7, lr, r8, lsl r6
 *   @0x162f40 .word 0xffffe368
 *   @0x162f44 andseq r7, lr, r0, lsl r6
 *   @0x162f48 .word 0xffffe36c
 *   @0x162f4c andseq r7, lr, r8, lsl #12
 *   @0x162f50 .word 0xffffe370
 *   @0x162f54 ldrsheq r7, [lr], -r12
 *   @0x162f58 .word 0xffffe374
 *   @0x162f5c ldrsheq r7, [lr], -r4
 *   @0x162f60 .word 0xffffe378
 *   @0x162f64 ldrsheq r7, [lr], -r4
 *   @0x162f68 .word 0xffffe37c
 *   @0x162f6c ldrsheq r7, [lr], -r8
 *   @0x162f70 .word 0xffffe380
 *   @0x162f74 ldrsheq r7, [lr], -r4
 *   @0x162f78 .word 0xffffe384
 *   @0x162f7c ldrsheq r7, [lr], -r0
 *   @0x162f80 .word 0xffffe388
 *   @0x162f84 andseq r7, lr, r12, ror #11
 *   @0x162f88 .word 0xffffe38c
 *   @0x162f8c andseq r7, lr, r4, ror #11
 *   @0x162f90 .word 0xffffe390
 *   @0x162f94 andseq r7, lr, r4, ror #11
 *   @0x162f98 .word 0xffffe394
 *   @0x162f9c andseq r7, lr, r4, ror #11
 *   @0x162fa0 .word 0xffffe398
 *   @0x162fa4 andseq r7, lr, r4, ror #11
 *   @0x162fa8 .word 0xffffe39c
 *   @0x162fac andseq r7, lr, r8, ror #11
 *   @0x162fb0 .word 0xffffe3a0
 *   @0x162fb4 andseq r7, lr, r8, ror #11
 *   @0x162fb8 .word 0xffffe3a4
 *   @0x162fbc andseq r7, lr, r12, ror #11
 *   @0x162fc0 .word 0xffffe3a8
 *   @0x162fc4 andseq r7, lr, r12, ror #11
 *   @0x162fc8 .word 0xffffe3ac
 *   @0x162fcc andseq r7, lr, r8, ror #11
 *   @0x162fd0 .word 0xffffe3b0
 *   @0x162fd4 andseq r7, lr, r4, ror #11
 *   @0x162fd8 .word 0xffffe3b4
 *   @0x162fdc andseq r7, lr, r0, ror #11
 *   @0x162fe0 .word 0xffffe3b8
 *   @0x162fe4 ldrsbeq r7, [lr], -r8
 *   @0x162fe8 .word 0xffffe3bc
 *   @0x162fec ldrsbeq r7, [lr], -r4
 *   @0x162ff0 .word 0xffffe3c0
 *   @0x162ff4 ldrsbeq r7, [lr], -r0
 *   @0x162ff8 .word 0xffffe3c4
 *   @0x162ffc andseq r7, lr, r8, asr #11
 *   @0x163000 .word 0xffffe3c8
 *   @0x163004 andseq r7, lr, r4, asr #11
 *   @0x163008 .word 0xffffe3cc
 *   @0x16300c andseq r7, lr, r0, asr #11
 *   @0x163010 .word 0xffffe3d0
 *   @0x163014 ldrheq r7, [lr], -r12
 *   @0x163018 .word 0xffffe3d4
 *   @0x16301c andseq r7, lr, r4, asr #11
 *   @0x163020 .word 0xffffe3d8
 *   @0x163024 ldrheq r7, [lr], -r12
 *   @0x163028 .word 0xffffe3dc
 *   @0x16302c ldrheq r7, [lr], -r12
 *   @0x163030 .word 0xffffe3e0
 *   @0x163034 ldrheq r7, [lr], -r4
 *   @0x163038 .word 0xffffe3e4
 *   @0x16303c ldrheq r7, [lr], -r12
 *   @0x163040 .word 0xffffe3e8
 *   @0x163044 ldrheq r7, [lr], -r8
 *   @0x163048 .word 0xffffe3ec
 *   @0x16304c ldrheq r7, [lr], -r12
 *   @0x163050 .word 0xffffe3f0
 *   @0x163054 ldrheq r7, [lr], -r12
 *   @0x163058 .word 0xffffe3f4
 *   @0x16305c ldrheq r7, [lr], -r8
 *   @0x163060 .word 0xffffe3f8
 *   @0x163064 ldrheq r7, [lr], -r12
 *   @0x163068 .word 0xffffe3fc
 *   @0x16306c ldrheq r7, [lr], -r4
 *   @0x163070 .word 0xffffe400
 *   @0x163074 ldrheq r7, [lr], -r4
 *   @0x163078 .word 0xffffe404
 *   @0x16307c andseq r7, lr, r12, lsr #11
 *   @0x163080 .word 0xffffe408
 *   @0x163084 andseq r7, lr, r8, lsr #11
 *   @0x163088 .word 0xffffe40c
 *   @0x16308c andseq r7, lr, r8, lsr #11
 *   @0x163090 .word 0xffffe410
 *   @0x163094 andseq r7, lr, r8, lsr #11
 *   @0x163098 .word 0xffffe414
 *   @0x16309c andseq r7, lr, r12, lsr #11
 *   @0x1630a0 .word 0xffffe418
 *   @0x1630a4 ldrheq r7, [lr], -r0
 *   @0x1630a8 .word 0xffffe41c
 *   @0x1630ac andseq r7, lr, r12, lsr #11
 *   @0x1630b0 .word 0xffffe420
 *   @0x1630b4 andseq r7, lr, r12, lsr #11
 *   @0x1630b8 .word 0xffffe424
 *   @0x1630bc andseq r7, lr, r12, lsr #11
 *   @0x1630c0 .word 0xffffe428
 *   @0x1630c4 ldrheq r7, [lr], -r0
 *   @0x1630c8 .word 0xffffe42c
 *   @0x1630cc ldrheq r7, [lr], -r8
 *   @0x1630d0 .word 0xffffe430
 *   @0x1630d4 ldrheq r7, [lr], -r8
 *   @0x1630d8 .word 0xffffe434
 *   @0x1630dc ldrheq r7, [lr], -r8
 *   @0x1630e0 .word 0xffffe438
 *   @0x1630e4 ldrheq r7, [lr], -r12
 *   @0x1630e8 .word 0xffffe43c
 *   @0x1630ec andseq r7, lr, r0, asr #11
 *   @0x1630f0 .word 0xffffe440
 *   @0x1630f4 andseq r7, lr, r4, asr #11
 *   @0x1630f8 .word 0xffffe444
 *   @0x1630fc andseq r7, lr, r8, asr #11
 *   @0x163100 .word 0xffffe448
 *   @0x163104 andseq r7, lr, r12, asr #11
 *   @0x163108 .word 0xffffe44c
 *   @0x16310c andseq r7, lr, r12, asr #11
 *   @0x163110 .word 0xffffe450
 *   @0x163114 ldrsbeq r7, [lr], -r0
 *   @0x163118 .word 0xffffe454
 *   @0x16311c ldrsbeq r7, [lr], -r0
 *   @0x163120 .word 0xffffe458
 *   @0x163124 ldrsbeq r7, [lr], -r4
 *   @0x163128 .word 0xffffe45c
 *   @0x16312c andseq r7, lr, r4, ror #11
 *   @0x163130 .word 0xffffe460
 *   @0x163134 andseq r7, lr, r12, ror #11
 *   @0x163138 .word 0xffffe464
 *   @0x16313c ldrsheq r7, [lr], -r0
 *   @0x163140 .word 0xffffe468
 *   @0x163144 andseq r7, lr, r0, lsl #12
 *   @0x163148 .word 0xffffe46c
 *   @0x16314c andseq r7, lr, r8, lsl #12
 *   @0x163150 .word 0xffffe470
 *   @0x163154 andseq r7, lr, r0, lsl r6
 *   @0x163158 .word 0xffffe474
 *   @0x16315c andseq r7, lr, r0, lsr #12
 *   @0x163160 .word 0xffffe478
 *   @0x163164 andseq r7, lr, r12, lsr #12
 *   @0x163168 .word 0xffffe47c
 *   @0x16316c andseq r7, lr, r12, lsr r6
 *
 * ══ §3/6 InitNetworkingFunctions  0x299684..0x2998b8  size 564  141 条（110 条指令 + 31 个池字）══
 * @func 0x299684 0x2998b8  size 564  141 条
 * 注册 15 条｜唯一名 15｜唯一函数指针 15｜argc 1:3 2:2 3:8 5:2｜flag 0:15
 * 首条 #0 network_create_socket（0x2996ac）→ 末条 #14 network_set_config（0x299838）
 * 名字族（前 8）: network×15
 * 游戏实际调用的 99 个内建里落在本表: 0 个
 * 表: asm/init-tables/init-InitNetworkingFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: 无（本函数每条注册的四实参全部解出，控制流全部走到）
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x299684 push {r4, lr}
 *   @0x299688 bl 0x298df4 <_Z14InitNetworkingv>   —— 调用 InitNetworking()
 *   @0x29968c mov r2, #1
 *   @0x299690 ldr r4, [pc, #0x1a4]
 *   @0x299694 mov r3, #0
 *   @0x299698 ldr r1, [pc, #0x1a0]
 *   @0x29969c add r4, pc, r4
 *   @0x2996a0 ldr r0, [pc, #0x19c]
 *   @0x2996a4 ldr r1, [r4, r1]
 *   @0x2996a8 add r0, pc, r0
 *   @0x2996ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 network_create_socket → F_NETWORK_Create_Socket(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x2996b0 ldr r1, [pc, #0x190]
 *   @0x2996b4 ldr r0, [pc, #0x190]
 *   @0x2996b8 mov r2, #2
 *   @0x2996bc mov r3, #0
 *   @0x2996c0 ldr r1, [r4, r1]
 *   @0x2996c4 add r0, pc, r0
 *   @0x2996c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 network_create_socket_ext → F_NETWORK_Create_Socket_Ext(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x2996cc ldr r1, [pc, #0x17c]
 *   @0x2996d0 ldr r0, [pc, #0x17c]
 *   @0x2996d4 mov r2, #3
 *   @0x2996d8 mov r3, #0
 *   @0x2996dc ldr r1, [r4, r1]
 *   @0x2996e0 add r0, pc, r0
 *   @0x2996e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 network_create_server → F_NETWORK_Create_Server(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x2996e8 ldr r1, [pc, #0x168]
 *   @0x2996ec ldr r0, [pc, #0x168]
 *   @0x2996f0 mov r2, #3
 *   @0x2996f4 mov r3, #0
 *   @0x2996f8 ldr r1, [r4, r1]
 *   @0x2996fc add r0, pc, r0
 *   @0x299700 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 network_create_server_raw → F_NETWORK_Create_Server_Raw(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x299704 ldr r1, [pc, #0x154]
 *   @0x299708 ldr r0, [pc, #0x154]
 *   @0x29970c mov r2, #3
 *   @0x299710 mov r3, #0
 *   @0x299714 ldr r1, [r4, r1]
 *   @0x299718 add r0, pc, r0
 *   @0x29971c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #4 network_connect → F_NETWORK_Connect(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x299720 ldr r1, [pc, #0x140]
 *   @0x299724 ldr r0, [pc, #0x140]
 *   @0x299728 mov r2, #3
 *   @0x29972c mov r3, #0
 *   @0x299730 ldr r1, [r4, r1]
 *   @0x299734 add r0, pc, r0
 *   @0x299738 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #5 network_connect_raw → F_NETWORK_Connect_ex(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x29973c ldr r1, [pc, #0x12c]
 *   @0x299740 ldr r0, [pc, #0x12c]
 *   @0x299744 mov r2, #3
 *   @0x299748 mov r3, #0
 *   @0x29974c ldr r1, [r4, r1]
 *   @0x299750 add r0, pc, r0
 *   @0x299754 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #6 network_send_packet → F_NETWORK_Send_Packet(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x299758 ldr r1, [pc, #0x118]
 *   @0x29975c ldr r0, [pc, #0x118]
 *   @0x299760 mov r2, #3
 *   @0x299764 mov r3, #0
 *   @0x299768 ldr r1, [r4, r1]
 *   @0x29976c add r0, pc, r0
 *   @0x299770 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #7 network_send_raw → F_NETWORK_Send_Raw(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x299774 ldr r1, [pc, #0x104]
 *   @0x299778 ldr r0, [pc, #0x104]
 *   @0x29977c mov r2, #3
 *   @0x299780 mov r3, #0
 *   @0x299784 ldr r1, [r4, r1]
 *   @0x299788 add r0, pc, r0
 *   @0x29978c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #8 network_send_broadcast → F_NETWORK_Send_Broadcast(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x299790 ldr r1, [pc, #0xf0]
 *   @0x299794 ldr r0, [pc, #0xf0]
 *   @0x299798 mov r2, #5
 *   @0x29979c mov r3, #0
 *   @0x2997a0 ldr r1, [r4, r1]
 *   @0x2997a4 add r0, pc, r0
 *   @0x2997a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #9 network_send_udp → F_NETWORK_Send_UDP(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0x2997ac ldr r1, [pc, #0xdc]
 *   @0x2997b0 ldr r0, [pc, #0xdc]
 *   @0x2997b4 mov r2, #5
 *   @0x2997b8 mov r3, #0
 *   @0x2997bc ldr r1, [r4, r1]
 *   @0x2997c0 add r0, pc, r0
 *   @0x2997c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #10 network_send_udp_raw → F_NETWORK_Send_UDP_Raw(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0x2997c8 ldr r1, [pc, #0xc8]
 *   @0x2997cc ldr r0, [pc, #0xc8]
 *   @0x2997d0 mov r2, #1
 *   @0x2997d4 mov r3, #0
 *   @0x2997d8 ldr r1, [r4, r1]
 *   @0x2997dc add r0, pc, r0
 *   @0x2997e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #11 network_resolve → F_NETWORK_Resolve(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x2997e4 ldr r1, [pc, #0xb4]
 *   @0x2997e8 ldr r0, [pc, #0xb4]
 *   @0x2997ec mov r2, #1
 *   @0x2997f0 mov r3, #0
 *   @0x2997f4 ldr r1, [r4, r1]
 *   @0x2997f8 add r0, pc, r0
 *   @0x2997fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #12 network_destroy → F_NETWORK_Destroy_Socket(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x299800 ldr r1, [pc, #0xa0]
 *   @0x299804 ldr r0, [pc, #0xa0]
 *   @0x299808 mov r2, #3
 *   @0x29980c mov r3, #0
 *   @0x299810 ldr r1, [r4, r1]
 *   @0x299814 add r0, pc, r0
 *   @0x299818 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #13 network_set_timeout → F_NETWORK_Set_Timeout(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x29981c ldr r1, [pc, #0x8c]
 *   @0x299820 ldr r0, [pc, #0x8c]
 *   @0x299824 mov r2, #2
 *   @0x299828 mov r3, #0
 *   @0x29982c ldr r1, [r4, r1]
 *   @0x299830 add r0, pc, r0
 *   @0x299834 pop {r4, lr}
 *   @0x299838 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #14 network_set_config → F_NETWORK_Set_Config(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x29983c ldrheq r8, [r5], -r4
 *   @0x299840 .word 0xfffffd5c
 *   @0x299844 andeq r0, r12, r0, lsl r1
 *   @0x299848 .word 0xfffffd60
 *   @0x29984c andeq r0, r12, r12, lsl #2
 *   @0x299850 .word 0xfffffd64
 *   @0x299854 andeq r0, r12, r12, lsl #2
 *   @0x299858 .word 0xfffffd68
 *   @0x29985c andeq r0, r12, r8, lsl #2
 *   @0x299860 .word 0xfffffd6c
 *   @0x299864 andeq r0, r12, r8, lsl #2
 *   @0x299868 .word 0xfffffd70
 *   @0x29986c strdeq r0, r1, [r12], -r12
 *   @0x299870 .word 0xfffffd74
 *   @0x299874 strdeq r0, r1, [r12], -r4
 *   @0x299878 .word 0xfffffd78
 *   @0x29987c andeq r0, r12, r12, ror #1
 *   @0x299880 .word 0xfffffd7c
 *   @0x299884 andeq r0, r12, r4, ror #1
 *   @0x299888 .word 0xfffffd80
 *   @0x29988c andeq r0, r12, r0, ror #1
 *   @0x299890 .word 0xfffffd84
 *   @0x299894 ldrdeq r0, r1, [r12], -r8
 *   @0x299898 .word 0xfffffd88
 *   @0x29989c ldrdeq r0, r1, [r12], -r4
 *   @0x2998a0 .word 0xfffffd8c
 *   @0x2998a4 andeq r0, r12, r8, asr #1
 *   @0x2998a8 .word 0xfffffd90
 *   @0x2998ac strheq r0, [r12], -r12
 *   @0x2998b0 .word 0xfffffd94
 *   @0x2998b4 strheq r0, [r12], -r4
 *
 * ══ §4/6 InitJavaScriptFunctions  0x246fe0..0x247388  size 936  234 条（184 条指令 + 50 个池字）══
 * @func 0x246fe0 0x247388  size 936  234 条
 * 注册 26 条｜唯一名 26｜唯一函数指针 23｜argc 0:15 1:9 2:2｜flag 1:26
 * 首条 #0 $PRINT（0x247004）→ 末条 #25 @@ForInIteratorDelete@@（0x2472bc）
 * 名字族（前 8）: @@try×2 @@finish×2 $PRINT×1 $FAIL×1 $ERROR×1 ERROR×1 testFailed×1 @@typeof@@×1
 * 游戏实际调用的 99 个内建里落在本表: 0 个
 * 表: asm/init-tables/init-InitJavaScriptFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: 无（本函数每条注册的四实参全部解出，控制流全部走到）
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x246fe0 push {r4, r5, r6, lr}
 *   @0x246fe4 mov r2, #1
 *   @0x246fe8 ldr r4, [pc, #0x2d0]
 *   @0x246fec mov r3, r2
 *   @0x246ff0 ldr r1, [pc, #0x2cc]
 *   @0x246ff4 add r4, pc, r4
 *   @0x246ff8 ldr r0, [pc, #0x2c8]
 *   @0x246ffc ldr r1, [r4, r1]
 *   @0x247000 add r0, pc, r0
 *   @0x247004 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 $PRINT → F_JSPrint(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x247008 ldr r1, [pc, #0x2bc]
 *   @0x24700c ldr r0, [pc, #0x2bc]
 *   @0x247010 mov r2, #1
 *   @0x247014 mov r3, r2
 *   @0x247018 ldr r5, [r4, r1]
 *   @0x24701c add r0, pc, r0
 *   @0x247020 mov r1, r5
 *   @0x247024 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 $FAIL → F_JSError(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x247028 ldr r0, [pc, #0x2a4]
 *   @0x24702c mov r2, #1
 *   @0x247030 mov r1, r5
 *   @0x247034 mov r3, r2
 *   @0x247038 add r0, pc, r0
 *   @0x24703c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 $ERROR → F_JSError(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x247040 ldr r0, [pc, #0x290]
 *   @0x247044 mov r2, #1
 *   @0x247048 mov r1, r5
 *   @0x24704c mov r3, r2
 *   @0x247050 add r0, pc, r0
 *   @0x247054 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 ERROR → F_JSError(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x247058 ldr r0, [pc, #0x27c]
 *   @0x24705c mov r2, #1
 *   @0x247060 mov r1, r5
 *   @0x247064 mov r3, r2
 *   @0x247068 add r0, pc, r0
 *   @0x24706c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #4 testFailed → F_JSError(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x247070 ldr r1, [pc, #0x268]
 *   @0x247074 ldr r0, [pc, #0x268]
 *   @0x247078 mov r2, #1
 *   @0x24707c mov r3, r2
 *   @0x247080 ldr r1, [r4, r1]
 *   @0x247084 add r0, pc, r0
 *   @0x247088 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #5 @@typeof@@ → F_JSTypeof(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x24708c ldr r1, [pc, #0x254]
 *   @0x247090 ldr r0, [pc, #0x254]
 *   @0x247094 mov r2, #1
 *   @0x247098 mov r3, r2
 *   @0x24709c ldr r1, [r4, r1]
 *   @0x2470a0 add r0, pc, r0
 *   @0x2470a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #6 @@new@@ → F_JSNew(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x2470a8 ldr r1, [pc, #0x240]
 *   @0x2470ac ldr r0, [pc, #0x240]
 *   @0x2470b0 mov r2, #1
 *   @0x2470b4 mov r3, r2
 *   @0x2470b8 ldr r1, [r4, r1]
 *   @0x2470bc add r0, pc, r0
 *   @0x2470c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #7 @@delete@@ → F_JSDelete(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x2470c4 ldr r1, [pc, #0x22c]
 *   @0x2470c8 ldr r0, [pc, #0x22c]
 *   @0x2470cc mov r2, #2
 *   @0x2470d0 mov r3, #1
 *   @0x2470d4 ldr r1, [r4, r1]
 *   @0x2470d8 add r0, pc, r0
 *   @0x2470dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #8 @@try_hook@@ → F_JSTryHook(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x2470e0 ldr r1, [pc, #0x218]
 *   @0x2470e4 ldr r0, [pc, #0x218]
 *   @0x2470e8 mov r2, #0
 *   @0x2470ec mov r3, #1
 *   @0x2470f0 ldr r1, [r4, r1]
 *   @0x2470f4 add r0, pc, r0
 *   @0x2470f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #9 @@try_unhook@@ → F_JSTryUnHook(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x2470fc ldr r1, [pc, #0x204]
 *   @0x247100 ldr r0, [pc, #0x204]
 *   @0x247104 mov r2, #1
 *   @0x247108 mov r3, r2
 *   @0x24710c ldr r1, [r4, r1]
 *   @0x247110 add r0, pc, r0
 *   @0x247114 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #10 @@throw@@ → F_JSThrow(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x247118 ldr r1, [pc, #0x1f0]
 *   @0x24711c ldr r0, [pc, #0x1f0]
 *   @0x247120 mov r2, #0
 *   @0x247124 mov r3, #1
 *   @0x247128 ldr r1, [r4, r1]
 *   @0x24712c add r0, pc, r0
 *   @0x247130 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #11 @@finish_catch@@ → F_JSFinishCatch(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x247134 ldr r1, [pc, #0x1dc]
 *   @0x247138 ldr r0, [pc, #0x1dc]
 *   @0x24713c mov r2, #0
 *   @0x247140 mov r3, #1
 *   @0x247144 ldr r1, [r4, r1]
 *   @0x247148 add r0, pc, r0
 *   @0x24714c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #12 @@finish_finally@@ → F_JSFinishFinally(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x247150 ldr r1, [pc, #0x1c8]
 *   @0x247154 ldr r0, [pc, #0x1c8]
 *   @0x247158 mov r2, #0
 *   @0x24715c mov r3, #1
 *   @0x247160 ldr r1, [r4, r1]
 *   @0x247164 add r0, pc, r0
 *   @0x247168 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #13 @@script_ref@@ → F_JSScriptRef(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x24716c ldr r1, [pc, #0x1b4]
 *   @0x247170 ldr r0, [pc, #0x1b4]
 *   @0x247174 mov r2, #2
 *   @0x247178 mov r3, #1
 *   @0x24717c ldr r1, [r4, r1]
 *   @0x247180 add r0, pc, r0
 *   @0x247184 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #14 @@instanceof@@ → F_JSInstanceOf(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x247188 ldr r1, [pc, #0x1a0]
 *   @0x24718c ldr r0, [pc, #0x1a0]
 *   @0x247190 mov r2, #0
 *   @0x247194 mov r3, #1
 *   @0x247198 ldr r1, [r4, r1]
 *   @0x24719c add r0, pc, r0
 *   @0x2471a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #15 @@This@@ → F_JSThis(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x2471a4 ldr r1, [pc, #0x18c]
 *   @0x2471a8 ldr r0, [pc, #0x18c]
 *   @0x2471ac mov r2, #0
 *   @0x2471b0 mov r3, #1
 *   @0x2471b4 ldr r1, [r4, r1]
 *   @0x2471b8 add r0, pc, r0
 *   @0x2471bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #16 @@Null@@ → F_JSNull(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x2471c0 ldr r1, [pc, #0x178]
 *   @0x2471c4 ldr r0, [pc, #0x178]
 *   @0x2471c8 mov r2, #0
 *   @0x2471cc mov r3, #1
 *   @0x2471d0 ldr r1, [r4, r1]
 *   @0x2471d4 add r0, pc, r0
 *   @0x2471d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #17 @@Other@@ → F_JSOther(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x2471dc ldr r1, [pc, #0x164]
 *   @0x2471e0 ldr r0, [pc, #0x164]
 *   @0x2471e4 mov r2, #0
 *   @0x2471e8 mov r3, #1
 *   @0x2471ec ldr r1, [r4, r1]
 *   @0x2471f0 add r0, pc, r0
 *   @0x2471f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #18 @@GlobalScope@@ → F_JSGlobalScope(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x2471f8 ldr r1, [pc, #0x150]
 *   @0x2471fc ldr r0, [pc, #0x150]
 *   @0x247200 mov r2, #0
 *   @0x247204 mov r3, #1
 *   @0x247208 ldr r1, [r4, r1]
 *   @0x24720c add r0, pc, r0
 *   @0x247210 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #19 @@NewGMLArray@@ → F_NewGMLArray(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x247214 ldr r1, [pc, #0x13c]
 *   @0x247218 ldr r0, [pc, #0x13c]
 *   @0x24721c mov r2, #0
 *   @0x247220 mov r3, #1
 *   @0x247224 ldr r1, [r4, r1]
 *   @0x247228 add r0, pc, r0
 *   @0x24722c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #20 @@NewArray@@ → F_JSNewArray(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x247230 ldr r1, [pc, #0x128]
 *   @0x247234 ldr r0, [pc, #0x128]
 *   @0x247238 mov r2, #0
 *   @0x24723c mov r3, #1
 *   @0x247240 ldr r1, [r4, r1]
 *   @0x247244 add r0, pc, r0
 *   @0x247248 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #21 @@NewObject@@ → F_JSNewObject(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x24724c ldr r1, [pc, #0x114]
 *   @0x247250 ldr r0, [pc, #0x114]
 *   @0x247254 mov r2, #0
 *   @0x247258 mov r3, #1
 *   @0x24725c ldr r1, [r4, r1]
 *   @0x247260 add r0, pc, r0
 *   @0x247264 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #22 @@NewProperty@@ → F_JSNewProperty(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x247268 ldr r1, [pc, #0x100]
 *   @0x24726c ldr r0, [pc, #0x100]
 *   @0x247270 mov r2, #0
 *   @0x247274 mov r3, #1
 *   @0x247278 ldr r1, [r4, r1]
 *   @0x24727c add r0, pc, r0
 *   @0x247280 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #23 @@ForInIterator@@ → F_JSForInIterator(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x247284 ldr r1, [pc, #0xec]
 *   @0x247288 ldr r0, [pc, #0xec]
 *   @0x24728c mov r2, #0
 *   @0x247290 mov r3, #1
 *   @0x247294 ldr r1, [r4, r1]
 *   @0x247298 add r0, pc, r0
 *   @0x24729c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #24 @@ForInIteratorGetNext@@ → F_JSForInIteratorGetNext(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x2472a0 ldr r1, [pc, #0xd8]
 *   @0x2472a4 ldr r0, [pc, #0xd8]
 *   @0x2472a8 mov r2, #0
 *   @0x2472ac mov r3, #1
 *   @0x2472b0 ldr r1, [r4, r1]
 *   @0x2472b4 add r0, pc, r0
 *   @0x2472b8 pop {r4, r5, r6, lr}
 *   @0x2472bc b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #25 @@ForInIteratorDelete@@ → F_JSForInIteratorDelete(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x2472c0 andseq r10, r10, r12, asr r12
 *   @0x2472c4 .word 0xfffffb1c
 *   @0x2472c8 andseq lr, r0, r8, asr r12
 *   @0x2472cc .word 0xfffffb20
 *   @0x2472d0 andseq lr, r0, r4, asr #24
 *   @0x2472d4 andseq lr, r0, r0, lsr r12
 *   @0x2472d8 andeq r11, lr, r12, lsr r5
 *   @0x2472dc andseq lr, r0, r8, lsl #24
 *   @0x2472e0 .word 0xfffffb24
 *   @0x2472e4 ldrsheq lr, [r0], -r8
 *   @0x2472e8 .word 0xfffffb28
 *   @0x2472ec andseq lr, r0, r8, ror #23
 *   @0x2472f0 .word 0xfffffb2c
 *   @0x2472f4 ldrsbeq lr, [r0], -r4
 *   @0x2472f8 .word 0xfffffb30
 *   @0x2472fc andseq lr, r0, r4, asr #23
 *   @0x247300 .word 0xfffffb34
 *   @0x247304 ldrheq lr, [r0], -r8
 *   @0x247308 .word 0xfffffb38
 *   @0x24730c andseq lr, r0, r12, lsr #23
 *   @0x247310 .word 0xfffffb3c
 *   @0x247314 mulseq r0, r12, r11
 *   @0x247318 .word 0xfffffb40
 *   @0x24731c mulseq r0, r4, r11
 *   @0x247320 .word 0xfffffb44
 *   @0x247324 andseq lr, r0, r12, lsl #23
 *   @0x247328 .word 0xfffffb48
 *   @0x24732c andseq lr, r0, r0, lsl #23
 *   @0x247330 .word 0xfffffb4c
 *   @0x247334 andseq lr, r0, r4, ror r11
 *   @0x247338 .word 0xfffffb50
 *   @0x24733c andseq lr, r0, r4, ror #22
 *   @0x247340 .word 0xfffffb54
 *   @0x247344 andseq lr, r0, r4, asr r11
 *   @0x247348 .word 0xfffffb58
 *   @0x24734c andseq lr, r0, r4, asr #22
 *   @0x247350 .word 0xfffffb5c
 *   @0x247354 andseq lr, r0, r8, lsr r11
 *   @0x247358 .word 0xfffffb60
 *   @0x24735c andseq lr, r0, r12, lsr #22
 *   @0x247360 .word 0xfffffb64
 *   @0x247364 andseq lr, r0, r0, lsr #22
 *   @0x247368 .word 0xfffffb68
 *   @0x24736c andseq lr, r0, r4, lsl r11
 *   @0x247370 .word 0xfffffb6c
 *   @0x247374 andseq lr, r0, r8, lsl #22
 *   @0x247378 .word 0xfffffb70
 *   @0x24737c andseq lr, r0, r0, lsl #22
 *   @0x247380 .word 0xfffffb74
 *   @0x247384 andseq lr, r0, r0, lsl #22
 *
 * ══ §5/6 InitPhysicsFunctions  0x150434..0x151210  size 3548  887 条（690 条指令 + 197 个池字）══
 * @func 0x150434 0x151210  size 3548  887 条
 * 注册 98 条｜唯一名 98｜唯一函数指针 98｜argc 0:9 1:35 2:25 3:7 4:9 5:2 7:2 8:3 9:1 11:1 12:3 13:1｜flag 0:28 1:70
 * 首条 #0 physics_world_create（0x150458）→ 末条 #97 physics_particle_set_gravity_scale（0x150ef8）
 * 名字族（前 8）: physics×98
 * 游戏实际调用的 99 个内建里落在本表: 0 个
 * 表: asm/init-tables/init-InitPhysicsFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: 无（本函数每条注册的四实参全部解出，控制流全部走到）
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x150434 push {r4, lr}
 *   @0x150438 mov r2, #1
 *   @0x15043c ldr r4, [pc, #0xab8]
 *   @0x150440 mov r3, r2
 *   @0x150444 ldr r1, [pc, #0xab4]
 *   @0x150448 add r4, pc, r4
 *   @0x15044c ldr r0, [pc, #0xab0]
 *   @0x150450 ldr r1, [r4, r1]
 *   @0x150454 add r0, pc, r0
 *   @0x150458 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 physics_world_create → F_PhysicsCreateWorld(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x15045c ldr r1, [pc, #0xaa4]
 *   @0x150460 ldr r0, [pc, #0xaa4]
 *   @0x150464 mov r2, #2
 *   @0x150468 mov r3, #1
 *   @0x15046c ldr r1, [r4, r1]
 *   @0x150470 add r0, pc, r0
 *   @0x150474 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 physics_world_gravity → F_PhysicsSetGravity(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x150478 ldr r1, [pc, #0xa90]
 *   @0x15047c ldr r0, [pc, #0xa90]
 *   @0x150480 mov r2, #1
 *   @0x150484 mov r3, r2
 *   @0x150488 ldr r1, [r4, r1]
 *   @0x15048c add r0, pc, r0
 *   @0x150490 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 physics_world_update_speed → F_PhysicsSetUpdateSpeed(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x150494 ldr r1, [pc, #0xa7c]
 *   @0x150498 ldr r0, [pc, #0xa7c]
 *   @0x15049c mov r2, #1
 *   @0x1504a0 mov r3, r2
 *   @0x1504a4 ldr r1, [r4, r1]
 *   @0x1504a8 add r0, pc, r0
 *   @0x1504ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 physics_world_update_iterations → F_PhysicsSetUpdateIterations(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1504b0 ldr r1, [pc, #0xa68]
 *   @0x1504b4 ldr r0, [pc, #0xa68]
 *   @0x1504b8 mov r2, #1
 *   @0x1504bc mov r3, r2
 *   @0x1504c0 ldr r1, [r4, r1]
 *   @0x1504c4 add r0, pc, r0
 *   @0x1504c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #4 physics_world_draw_debug → F_PhysicsDebugRenderAll(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1504cc ldr r1, [pc, #0xa54]
 *   @0x1504d0 ldr r0, [pc, #0xa54]
 *   @0x1504d4 mov r2, #1
 *   @0x1504d8 mov r3, r2
 *   @0x1504dc ldr r1, [r4, r1]
 *   @0x1504e0 add r0, pc, r0
 *   @0x1504e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #5 physics_pause_enable → F_PhysicsPause(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1504e8 ldr r1, [pc, #0xa40]
 *   @0x1504ec ldr r0, [pc, #0xa40]
 *   @0x1504f0 mov r2, #0
 *   @0x1504f4 mov r3, #1
 *   @0x1504f8 ldr r1, [r4, r1]
 *   @0x1504fc add r0, pc, r0
 *   @0x150500 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #6 physics_fixture_create → F_PhysicsCreateFixture(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x150504 ldr r1, [pc, #0xa2c]
 *   @0x150508 ldr r0, [pc, #0xa2c]
 *   @0x15050c mov r2, #1
 *   @0x150510 mov r3, r2
 *   @0x150514 ldr r1, [r4, r1]
 *   @0x150518 add r0, pc, r0
 *   @0x15051c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #7 physics_fixture_set_kinematic → F_PhysicsFixtureSetKinematic(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x150520 ldr r1, [pc, #0xa18]
 *   @0x150524 ldr r0, [pc, #0xa18]
 *   @0x150528 mov r2, #2
 *   @0x15052c mov r3, #1
 *   @0x150530 ldr r1, [r4, r1]
 *   @0x150534 add r0, pc, r0
 *   @0x150538 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #8 physics_fixture_set_awake → F_PhysicsFixtureSetAwake(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x15053c ldr r1, [pc, #0xa04]
 *   @0x150540 ldr r0, [pc, #0xa04]
 *   @0x150544 mov r2, #2
 *   @0x150548 mov r3, #1
 *   @0x15054c ldr r1, [r4, r1]
 *   @0x150550 add r0, pc, r0
 *   @0x150554 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #9 physics_fixture_set_density → F_PhysicsFixtureSetDensity(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x150558 ldr r1, [pc, #0x9f0]
 *   @0x15055c ldr r0, [pc, #0x9f0]
 *   @0x150560 mov r2, #2
 *   @0x150564 mov r3, #1
 *   @0x150568 ldr r1, [r4, r1]
 *   @0x15056c add r0, pc, r0
 *   @0x150570 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #10 physics_fixture_set_restitution → F_PhysicsFixtureSetRestitution(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x150574 ldr r1, [pc, #0x9dc]
 *   @0x150578 ldr r0, [pc, #0x9dc]
 *   @0x15057c mov r2, #2
 *   @0x150580 mov r3, #1
 *   @0x150584 ldr r1, [r4, r1]
 *   @0x150588 add r0, pc, r0
 *   @0x15058c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #11 physics_fixture_set_friction → F_PhysicsFixtureSetFriction(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x150590 ldr r1, [pc, #0x9c8]
 *   @0x150594 ldr r0, [pc, #0x9c8]
 *   @0x150598 mov r2, #2
 *   @0x15059c mov r3, #1
 *   @0x1505a0 ldr r1, [r4, r1]
 *   @0x1505a4 add r0, pc, r0
 *   @0x1505a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #12 physics_fixture_set_collision_group → F_PhysicsFixtureSetCollisionGroup(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1505ac ldr r1, [pc, #0x9b4]
 *   @0x1505b0 ldr r0, [pc, #0x9b4]
 *   @0x1505b4 mov r2, #2
 *   @0x1505b8 mov r3, #1
 *   @0x1505bc ldr r1, [r4, r1]
 *   @0x1505c0 add r0, pc, r0
 *   @0x1505c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #13 physics_fixture_set_sensor → F_PhysicsFixtureSetSensor(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1505c8 ldr r1, [pc, #0x9a0]
 *   @0x1505cc ldr r0, [pc, #0x9a0]
 *   @0x1505d0 mov r2, #2
 *   @0x1505d4 mov r3, #1
 *   @0x1505d8 ldr r1, [r4, r1]
 *   @0x1505dc add r0, pc, r0
 *   @0x1505e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #14 physics_fixture_set_linear_damping → F_PhysicsFixtureLinearDamping(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1505e4 ldr r1, [pc, #0x98c]
 *   @0x1505e8 ldr r0, [pc, #0x98c]
 *   @0x1505ec mov r2, #2
 *   @0x1505f0 mov r3, #1
 *   @0x1505f4 ldr r1, [r4, r1]
 *   @0x1505f8 add r0, pc, r0
 *   @0x1505fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #15 physics_fixture_set_angular_damping → F_PhysicsFixtureAngularDamping(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x150600 ldr r1, [pc, #0x978]
 *   @0x150604 ldr r0, [pc, #0x978]
 *   @0x150608 mov r2, #2
 *   @0x15060c mov r3, #1
 *   @0x150610 ldr r1, [r4, r1]
 *   @0x150614 add r0, pc, r0
 *   @0x150618 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #16 physics_fixture_set_circle_shape → F_PhysicsFixtureSetCircleShape(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x15061c ldr r1, [pc, #0x964]
 *   @0x150620 ldr r0, [pc, #0x964]
 *   @0x150624 mov r2, #3
 *   @0x150628 mov r3, #1
 *   @0x15062c ldr r1, [r4, r1]
 *   @0x150630 add r0, pc, r0
 *   @0x150634 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #17 physics_fixture_set_box_shape → F_PhysicsFixtureSetBoxShape(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x150638 ldr r1, [pc, #0x950]
 *   @0x15063c ldr r0, [pc, #0x950]
 *   @0x150640 mov r2, #5
 *   @0x150644 mov r3, #1
 *   @0x150648 ldr r1, [r4, r1]
 *   @0x15064c add r0, pc, r0
 *   @0x150650 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #18 physics_fixture_set_edge_shape → F_PhysicsFixtureSetEdgeShape(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x150654 ldr r1, [pc, #0x93c]
 *   @0x150658 ldr r0, [pc, #0x93c]
 *   @0x15065c mov r2, #1
 *   @0x150660 mov r3, r2
 *   @0x150664 ldr r1, [r4, r1]
 *   @0x150668 add r0, pc, r0
 *   @0x15066c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #19 physics_fixture_set_polygon_shape → F_PhysicsFixtureSetPolygonShape(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x150670 ldr r1, [pc, #0x928]
 *   @0x150674 ldr r0, [pc, #0x928]
 *   @0x150678 mov r2, #2
 *   @0x15067c mov r3, #1
 *   @0x150680 ldr r1, [r4, r1]
 *   @0x150684 add r0, pc, r0
 *   @0x150688 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #20 physics_fixture_set_chain_shape → F_PhysicsFixtureSetChainShape(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x15068c ldr r1, [pc, #0x914]
 *   @0x150690 ldr r0, [pc, #0x914]
 *   @0x150694 mov r2, #3
 *   @0x150698 mov r3, #1
 *   @0x15069c ldr r1, [r4, r1]
 *   @0x1506a0 add r0, pc, r0
 *   @0x1506a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #21 physics_fixture_add_point → F_PhysicsFixtureAddShapePoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x1506a8 ldr r1, [pc, #0x900]
 *   @0x1506ac ldr r0, [pc, #0x900]
 *   @0x1506b0 mov r2, #2
 *   @0x1506b4 mov r3, #1
 *   @0x1506b8 ldr r1, [r4, r1]
 *   @0x1506bc add r0, pc, r0
 *   @0x1506c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #22 physics_fixture_bind → F_PhysicsBindFixture(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1506c4 ldr r1, [pc, #0x8ec]
 *   @0x1506c8 ldr r0, [pc, #0x8ec]
 *   @0x1506cc mov r2, #4
 *   @0x1506d0 mov r3, #1
 *   @0x1506d4 ldr r1, [r4, r1]
 *   @0x1506d8 add r0, pc, r0
 *   @0x1506dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #23 physics_fixture_bind_ext → F_PhysicsBindFixtureExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x1506e0 ldr r1, [pc, #0x8d8]
 *   @0x1506e4 ldr r0, [pc, #0x8d8]
 *   @0x1506e8 mov r2, #1
 *   @0x1506ec mov r3, r2
 *   @0x1506f0 ldr r1, [r4, r1]
 *   @0x1506f4 add r0, pc, r0
 *   @0x1506f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #24 physics_fixture_delete → F_PhysicsDeleteFixture(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1506fc ldr r1, [pc, #0x8c4]
 *   @0x150700 ldr r0, [pc, #0x8c4]
 *   @0x150704 mov r2, #4
 *   @0x150708 mov r3, #1
 *   @0x15070c ldr r1, [r4, r1]
 *   @0x150710 add r0, pc, r0
 *   @0x150714 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #25 physics_apply_force → F_PhysicsApplyForce(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x150718 ldr r1, [pc, #0x8b0]
 *   @0x15071c ldr r0, [pc, #0x8b0]
 *   @0x150720 mov r2, #4
 *   @0x150724 mov r3, #1
 *   @0x150728 ldr r1, [r4, r1]
 *   @0x15072c add r0, pc, r0
 *   @0x150730 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #26 physics_apply_impulse → F_PhysicsApplyImpulse(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x150734 ldr r1, [pc, #0x89c]
 *   @0x150738 ldr r0, [pc, #0x89c]
 *   @0x15073c mov r2, #1
 *   @0x150740 mov r3, r2
 *   @0x150744 ldr r1, [r4, r1]
 *   @0x150748 add r0, pc, r0
 *   @0x15074c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #27 physics_apply_angular_impulse → F_PhysicsApplyAngularImpulse(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x150750 ldr r1, [pc, #0x888]
 *   @0x150754 ldr r0, [pc, #0x888]
 *   @0x150758 mov r2, #4
 *   @0x15075c mov r3, #1
 *   @0x150760 ldr r1, [r4, r1]
 *   @0x150764 add r0, pc, r0
 *   @0x150768 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #28 physics_apply_local_force → F_PhysicsApplyLocalForce(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x15076c ldr r1, [pc, #0x874]
 *   @0x150770 ldr r0, [pc, #0x874]
 *   @0x150774 mov r2, #4
 *   @0x150778 mov r3, #1
 *   @0x15077c ldr r1, [r4, r1]
 *   @0x150780 add r0, pc, r0
 *   @0x150784 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #29 physics_apply_local_impulse → F_PhysicsApplyLocalImpulse(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x150788 ldr r1, [pc, #0x860]
 *   @0x15078c ldr r0, [pc, #0x860]
 *   @0x150790 mov r2, #1
 *   @0x150794 mov r3, r2
 *   @0x150798 ldr r1, [r4, r1]
 *   @0x15079c add r0, pc, r0
 *   @0x1507a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #30 physics_apply_torque → F_PhysicsApplyTorque(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x1507a4 ldr r1, [pc, #0x84c]
 *   @0x1507a8 ldr r0, [pc, #0x84c]
 *   @0x1507ac mov r2, #4
 *   @0x1507b0 mov r3, #1
 *   @0x1507b4 ldr r1, [r4, r1]
 *   @0x1507b8 add r0, pc, r0
 *   @0x1507bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #31 physics_mass_properties → F_PhysicsSetMass(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x1507c0 ldr r1, [pc, #0x838]
 *   @0x1507c4 ldr r0, [pc, #0x838]
 *   @0x1507c8 mov r2, #0
 *   @0x1507cc mov r3, #1
 *   @0x1507d0 ldr r1, [r4, r1]
 *   @0x1507d4 add r0, pc, r0
 *   @0x1507d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #32 physics_draw_debug → F_PhysicsDebugRender(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x1507dc ldr r1, [pc, #0x824]
 *   @0x1507e0 ldr r0, [pc, #0x824]
 *   @0x1507e4 mov r2, #4
 *   @0x1507e8 mov r3, #1
 *   @0x1507ec ldr r1, [r4, r1]
 *   @0x1507f0 add r0, pc, r0
 *   @0x1507f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #33 physics_test_overlap → F_PhysicsTestOverlap(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x1507f8 ldr r1, [pc, #0x810]
 *   @0x1507fc ldr r0, [pc, #0x810]
 *   @0x150800 mov r2, #2
 *   @0x150804 mov r3, #1
 *   @0x150808 ldr r1, [r4, r1]
 *   @0x15080c add r0, pc, r0
 *   @0x150810 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #34 physics_remove_fixture → F_PhysicsRemoveFixture(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x150814 ldr r1, [pc, #0x7fc]
 *   @0x150818 ldr r0, [pc, #0x7fc]
 *   @0x15081c mov r2, #1
 *   @0x150820 mov r3, r2
 *   @0x150824 ldr r1, [r4, r1]
 *   @0x150828 add r0, pc, r0
 *   @0x15082c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #35 physics_get_friction → F_PhysicsGetFriction(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x150830 ldr r1, [pc, #0x7e8]
 *   @0x150834 ldr r0, [pc, #0x7e8]
 *   @0x150838 mov r2, #1
 *   @0x15083c mov r3, r2
 *   @0x150840 ldr r1, [r4, r1]
 *   @0x150844 add r0, pc, r0
 *   @0x150848 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #36 physics_get_density → F_PhysicsGetDensity(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x15084c ldr r1, [pc, #0x7d4]
 *   @0x150850 ldr r0, [pc, #0x7d4]
 *   @0x150854 mov r2, #1
 *   @0x150858 mov r3, r2
 *   @0x15085c ldr r1, [r4, r1]
 *   @0x150860 add r0, pc, r0
 *   @0x150864 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #37 physics_get_restitution → F_PhysicsGetRestitution(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x150868 ldr r1, [pc, #0x7c0]
 *   @0x15086c ldr r0, [pc, #0x7c0]
 *   @0x150870 mov r2, #2
 *   @0x150874 mov r3, #1
 *   @0x150878 ldr r1, [r4, r1]
 *   @0x15087c add r0, pc, r0
 *   @0x150880 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #38 physics_set_friction → F_PhysicsSetFriction(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x150884 ldr r1, [pc, #0x7ac]
 *   @0x150888 ldr r0, [pc, #0x7ac]
 *   @0x15088c mov r2, #2
 *   @0x150890 mov r3, #1
 *   @0x150894 ldr r1, [r4, r1]
 *   @0x150898 add r0, pc, r0
 *   @0x15089c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #39 physics_set_density → F_PhysicsSetDensity(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1508a0 ldr r1, [pc, #0x798]
 *   @0x1508a4 ldr r0, [pc, #0x798]
 *   @0x1508a8 mov r2, #2
 *   @0x1508ac mov r3, #1
 *   @0x1508b0 ldr r1, [r4, r1]
 *   @0x1508b4 add r0, pc, r0
 *   @0x1508b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #40 physics_set_restitution → F_PhysicsSetRestitution(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1508bc ldr r1, [pc, #0x784]
 *   @0x1508c0 ldr r0, [pc, #0x784]
 *   @0x1508c4 mov r2, #7
 *   @0x1508c8 mov r3, #1
 *   @0x1508cc ldr r1, [r4, r1]
 *   @0x1508d0 add r0, pc, r0
 *   @0x1508d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #41 physics_joint_distance_create → F_PhysicsCreateDistanceJoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x1508d8 ldr r1, [pc, #0x770]
 *   @0x1508dc ldr r0, [pc, #0x770]
 *   @0x1508e0 mov r2, #8
 *   @0x1508e4 mov r3, #1
 *   @0x1508e8 ldr r1, [r4, r1]
 *   @0x1508ec add r0, pc, r0
 *   @0x1508f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #42 physics_joint_rope_create → F_PhysicsCreateRopeJoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x1508f4 ldr r1, [pc, #0x75c]
 *   @0x1508f8 ldr r0, [pc, #0x75c]
 *   @0x1508fc mov r2, #11
 *   @0x150900 mov r3, #1
 *   @0x150904 ldr r1, [r4, r1]
 *   @0x150908 add r0, pc, r0
 *   @0x15090c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #43 physics_joint_revolute_create → F_PhysicsCreateRevoluteJoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=11 flag=1
 *   @0x150910 ldr r1, [pc, #0x748]
 *   @0x150914 ldr r0, [pc, #0x748]
 *   @0x150918 mov r2, #13
 *   @0x15091c mov r3, #1
 *   @0x150920 ldr r1, [r4, r1]
 *   @0x150924 add r0, pc, r0
 *   @0x150928 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #44 physics_joint_prismatic_create → F_PhysicsCreatePrismaticJoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=13 flag=1
 *   @0x15092c ldr r1, [pc, #0x734]
 *   @0x150930 ldr r0, [pc, #0x734]
 *   @0x150934 mov r2, #12
 *   @0x150938 mov r3, #1
 *   @0x15093c ldr r1, [r4, r1]
 *   @0x150940 add r0, pc, r0
 *   @0x150944 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #45 physics_joint_pulley_create → F_PhysicsCreatePulleyJoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=12 flag=1
 *   @0x150948 ldr r1, [pc, #0x720]
 *   @0x15094c ldr r0, [pc, #0x720]
 *   @0x150950 mov r2, #12
 *   @0x150954 mov r3, #1
 *   @0x150958 ldr r1, [r4, r1]
 *   @0x15095c add r0, pc, r0
 *   @0x150960 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #46 physics_joint_wheel_create → F_PhysicsCreateWheelJoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=12 flag=1
 *   @0x150964 ldr r1, [pc, #0x70c]
 *   @0x150968 ldr r0, [pc, #0x70c]
 *   @0x15096c mov r2, #5
 *   @0x150970 mov r3, #1
 *   @0x150974 ldr r1, [r4, r1]
 *   @0x150978 add r0, pc, r0
 *   @0x15097c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #47 physics_joint_gear_create → F_PhysicsCreateGearJoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x150980 ldr r1, [pc, #0x6f8]
 *   @0x150984 ldr r0, [pc, #0x6f8]
 *   @0x150988 mov r2, #8
 *   @0x15098c mov r3, #1
 *   @0x150990 ldr r1, [r4, r1]
 *   @0x150994 add r0, pc, r0
 *   @0x150998 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #48 physics_joint_weld_create → F_PhysicsCreateWeldJoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x15099c ldr r1, [pc, #0x6e4]
 *   @0x1509a0 ldr r0, [pc, #0x6e4]
 *   @0x1509a4 mov r2, #7
 *   @0x1509a8 mov r3, #0
 *   @0x1509ac ldr r1, [r4, r1]
 *   @0x1509b0 add r0, pc, r0
 *   @0x1509b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #49 physics_joint_friction_create → F_PhysicsCreateFrictionJoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=0
 *   @0x1509b8 ldr r1, [pc, #0x6d0]
 *   @0x1509bc ldr r0, [pc, #0x6d0]
 *   @0x1509c0 mov r2, #2
 *   @0x1509c4 mov r3, #1
 *   @0x1509c8 ldr r1, [r4, r1]
 *   @0x1509cc add r0, pc, r0
 *   @0x1509d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #50 physics_joint_enable_motor → F_PhysicsJointEnableMotor(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1509d4 ldr r1, [pc, #0x6bc]
 *   @0x1509d8 ldr r0, [pc, #0x6bc]
 *   @0x1509dc mov r2, #2
 *   @0x1509e0 mov r3, #1
 *   @0x1509e4 ldr r1, [r4, r1]
 *   @0x1509e8 add r0, pc, r0
 *   @0x1509ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #51 physics_joint_get_value → F_PhysicsJointGetValue(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x1509f0 ldr r1, [pc, #0x6a8]
 *   @0x1509f4 ldr r0, [pc, #0x6a8]
 *   @0x1509f8 mov r2, #3
 *   @0x1509fc mov r3, #1
 *   @0x150a00 ldr r1, [r4, r1]
 *   @0x150a04 add r0, pc, r0
 *   @0x150a08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #52 physics_joint_set_value → F_PhysicsJointSetValue(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x150a0c ldr r1, [pc, #0x694]
 *   @0x150a10 ldr r0, [pc, #0x694]
 *   @0x150a14 mov r2, #1
 *   @0x150a18 mov r3, r2
 *   @0x150a1c ldr r1, [r4, r1]
 *   @0x150a20 add r0, pc, r0
 *   @0x150a24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #53 physics_joint_delete → F_PhysicsDeleteJoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x150a28 ldr r1, [pc, #0x680]
 *   @0x150a2c ldr r0, [pc, #0x680]
 *   @0x150a30 mov r2, #8
 *   @0x150a34 mov r3, #1
 *   @0x150a38 ldr r1, [r4, r1]
 *   @0x150a3c add r0, pc, r0
 *   @0x150a40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #54 physics_particle_create → F_PhysicsCreateParticle(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x150a44 ldr r1, [pc, #0x66c]
 *   @0x150a48 ldr r0, [pc, #0x66c]
 *   @0x150a4c mov r2, #1
 *   @0x150a50 mov r3, r2
 *   @0x150a54 ldr r1, [r4, r1]
 *   @0x150a58 add r0, pc, r0
 *   @0x150a5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #55 physics_particle_delete → F_PhysicsDestroyParticle(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x150a60 ldr r1, [pc, #0x658]
 *   @0x150a64 ldr r0, [pc, #0x658]
 *   @0x150a68 mov r2, #3
 *   @0x150a6c mov r3, #0
 *   @0x150a70 ldr r1, [r4, r1]
 *   @0x150a74 add r0, pc, r0
 *   @0x150a78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #56 physics_particle_delete_region_circle → F_PhysicsDestroyParticleRegionCircle(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x150a7c ldr r1, [pc, #0x644]
 *   @0x150a80 ldr r0, [pc, #0x644]
 *   @0x150a84 mov r2, #4
 *   @0x150a88 mov r3, #0
 *   @0x150a8c ldr r1, [r4, r1]
 *   @0x150a90 add r0, pc, r0
 *   @0x150a94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #57 physics_particle_delete_region_box → F_PhysicsDestroyParticleRegionBox(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x150a98 ldr r1, [pc, #0x630]
 *   @0x150a9c ldr r0, [pc, #0x630]
 *   @0x150aa0 mov r2, #1
 *   @0x150aa4 mov r3, #0
 *   @0x150aa8 ldr r1, [r4, r1]
 *   @0x150aac add r0, pc, r0
 *   @0x150ab0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #58 physics_particle_delete_region_poly → F_PhysicsDestroyParticleRegionPoly(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x150ab4 ldr r1, [pc, #0x61c]
 *   @0x150ab8 ldr r0, [pc, #0x61c]
 *   @0x150abc mov r2, #2
 *   @0x150ac0 mov r3, #0
 *   @0x150ac4 ldr r1, [r4, r1]
 *   @0x150ac8 add r0, pc, r0
 *   @0x150acc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #59 physics_particle_set_flags → F_PhysicsSetParticleFlags(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x150ad0 ldr r1, [pc, #0x608]
 *   @0x150ad4 ldr r0, [pc, #0x608]
 *   @0x150ad8 mov r2, #2
 *   @0x150adc mov r3, #0
 *   @0x150ae0 ldr r1, [r4, r1]
 *   @0x150ae4 add r0, pc, r0
 *   @0x150ae8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #60 physics_particle_set_category_flags → F_PhysicsSetParticleCategoryFlags(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x150aec ldr r1, [pc, #0x5f4]
 *   @0x150af0 ldr r0, [pc, #0x5f4]
 *   @0x150af4 mov r2, #4
 *   @0x150af8 mov r3, #1
 *   @0x150afc ldr r1, [r4, r1]
 *   @0x150b00 add r0, pc, r0
 *   @0x150b04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #61 physics_particle_draw → F_PhysicsDrawParticles(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=1
 *   @0x150b08 ldr r1, [pc, #0x5e0]
 *   @0x150b0c ldr r0, [pc, #0x5e0]
 *   @0x150b10 mov r2, #9
 *   @0x150b14 mov r3, #1
 *   @0x150b18 ldr r1, [r4, r1]
 *   @0x150b1c add r0, pc, r0
 *   @0x150b20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #62 physics_particle_draw_ext → F_PhysicsDrawParticlesExt(RValue&, CInstance*, CInstance*, int, RValue*) argc=9 flag=1
 *   @0x150b24 ldr r1, [pc, #0x5cc]
 *   @0x150b28 ldr r0, [pc, #0x5cc]
 *   @0x150b2c mov r2, #0
 *   @0x150b30 mov r3, #1
 *   @0x150b34 ldr r1, [r4, r1]
 *   @0x150b38 add r0, pc, r0
 *   @0x150b3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #63 physics_particle_count → F_PhysicsParticleCount(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x150b40 ldr r1, [pc, #0x5b8]
 *   @0x150b44 ldr r0, [pc, #0x5b8]
 *   @0x150b48 mov r2, #2
 *   @0x150b4c mov r3, #1
 *   @0x150b50 ldr r1, [r4, r1]
 *   @0x150b54 add r0, pc, r0
 *   @0x150b58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #64 physics_particle_get_data → F_PhysicsParticleData(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x150b5c ldr r1, [pc, #0x5a4]
 *   @0x150b60 ldr r0, [pc, #0x5a4]
 *   @0x150b64 mov r2, #2
 *   @0x150b68 mov r3, #1
 *   @0x150b6c ldr r1, [r4, r1]
 *   @0x150b70 add r0, pc, r0
 *   @0x150b74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #65 physics_particle_get_data_particle → F_PhysicsParticleDataParticle(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x150b78 ldr r1, [pc, #0x590]
 *   @0x150b7c ldr r0, [pc, #0x590]
 *   @0x150b80 mov r2, #12
 *   @0x150b84 mov r3, #1
 *   @0x150b88 ldr r1, [r4, r1]
 *   @0x150b8c add r0, pc, r0
 *   @0x150b90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #66 physics_particle_group_begin → F_PhysicsBeginParticleGroup(RValue&, CInstance*, CInstance*, int, RValue*) argc=12 flag=1
 *   @0x150b94 ldr r1, [pc, #0x57c]
 *   @0x150b98 ldr r0, [pc, #0x57c]
 *   @0x150b9c mov r2, #2
 *   @0x150ba0 mov r3, #1
 *   @0x150ba4 ldr r1, [r4, r1]
 *   @0x150ba8 add r0, pc, r0
 *   @0x150bac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #67 physics_particle_group_circle → F_PhysicsParticleGroupSetCircle(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x150bb0 ldr r1, [pc, #0x568]
 *   @0x150bb4 ldr r0, [pc, #0x568]
 *   @0x150bb8 mov r2, #3
 *   @0x150bbc mov r3, #1
 *   @0x150bc0 ldr r1, [r4, r1]
 *   @0x150bc4 add r0, pc, r0
 *   @0x150bc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #68 physics_particle_group_box → F_PhysicsParticleGroupSetBox(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x150bcc ldr r1, [pc, #0x554]
 *   @0x150bd0 ldr r0, [pc, #0x554]
 *   @0x150bd4 mov r2, #1
 *   @0x150bd8 mov r3, r2
 *   @0x150bdc ldr r1, [r4, r1]
 *   @0x150be0 add r0, pc, r0
 *   @0x150be4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #69 physics_particle_group_polygon → F_PhysicsParticleGroupSetPoly(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x150be8 ldr r1, [pc, #0x540]
 *   @0x150bec ldr r0, [pc, #0x540]
 *   @0x150bf0 mov r2, #3
 *   @0x150bf4 mov r3, #1
 *   @0x150bf8 ldr r1, [r4, r1]
 *   @0x150bfc add r0, pc, r0
 *   @0x150c00 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #70 physics_particle_group_add_point → F_PhysicsParticleGroupAddPoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x150c04 ldr r1, [pc, #0x52c]
 *   @0x150c08 ldr r0, [pc, #0x52c]
 *   @0x150c0c mov r2, #0
 *   @0x150c10 mov r3, #1
 *   @0x150c14 ldr r1, [r4, r1]
 *   @0x150c18 add r0, pc, r0
 *   @0x150c1c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #71 physics_particle_group_end → F_PhysicsEndParticleGroup(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=1
 *   @0x150c20 ldr r1, [pc, #0x518]
 *   @0x150c24 ldr r0, [pc, #0x518]
 *   @0x150c28 mov r2, #2
 *   @0x150c2c mov r3, #1
 *   @0x150c30 ldr r1, [r4, r1]
 *   @0x150c34 add r0, pc, r0
 *   @0x150c38 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #72 physics_particle_group_join → F_PhysicsJoinParticleGroups(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x150c3c ldr r1, [pc, #0x504]
 *   @0x150c40 ldr r0, [pc, #0x504]
 *   @0x150c44 mov r2, #1
 *   @0x150c48 mov r3, r2
 *   @0x150c4c ldr r1, [r4, r1]
 *   @0x150c50 add r0, pc, r0
 *   @0x150c54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #73 physics_particle_group_delete → F_PhysicsDeleteParticleGroup(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x150c58 ldr r1, [pc, #0x4f0]
 *   @0x150c5c ldr r0, [pc, #0x4f0]
 *   @0x150c60 mov r2, #1
 *   @0x150c64 mov r3, r2
 *   @0x150c68 ldr r1, [r4, r1]
 *   @0x150c6c add r0, pc, r0
 *   @0x150c70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #74 physics_particle_group_count → F_PhysicsParticleGroupCount(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x150c74 ldr r1, [pc, #0x4dc]
 *   @0x150c78 ldr r0, [pc, #0x4dc]
 *   @0x150c7c mov r2, #3
 *   @0x150c80 mov r3, #1
 *   @0x150c84 ldr r1, [r4, r1]
 *   @0x150c88 add r0, pc, r0
 *   @0x150c8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #75 physics_particle_group_get_data → F_PhysicsParticleDataGroup(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x150c90 ldr r1, [pc, #0x4c8]
 *   @0x150c94 ldr r0, [pc, #0x4c8]
 *   @0x150c98 mov r2, #1
 *   @0x150c9c mov r3, #0
 *   @0x150ca0 ldr r1, [r4, r1]
 *   @0x150ca4 add r0, pc, r0
 *   @0x150ca8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #76 physics_particle_group_get_mass → F_PhysicsParticleGroupMass(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x150cac ldr r1, [pc, #0x4b4]
 *   @0x150cb0 ldr r0, [pc, #0x4b4]
 *   @0x150cb4 mov r2, #1
 *   @0x150cb8 mov r3, #0
 *   @0x150cbc ldr r1, [r4, r1]
 *   @0x150cc0 add r0, pc, r0
 *   @0x150cc4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #77 physics_particle_group_get_inertia → F_PhysicsParticleGroupInertia(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x150cc8 ldr r1, [pc, #0x4a0]
 *   @0x150ccc ldr r0, [pc, #0x4a0]
 *   @0x150cd0 mov r2, #1
 *   @0x150cd4 mov r3, #0
 *   @0x150cd8 ldr r1, [r4, r1]
 *   @0x150cdc add r0, pc, r0
 *   @0x150ce0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #78 physics_particle_group_get_centre_x → F_PhysicsParticleGroupCentreX(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x150ce4 ldr r1, [pc, #0x48c]
 *   @0x150ce8 ldr r0, [pc, #0x48c]
 *   @0x150cec mov r2, #1
 *   @0x150cf0 mov r3, #0
 *   @0x150cf4 ldr r1, [r4, r1]
 *   @0x150cf8 add r0, pc, r0
 *   @0x150cfc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #79 physics_particle_group_get_centre_y → F_PhysicsParticleGroupCentreY(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x150d00 ldr r1, [pc, #0x478]
 *   @0x150d04 ldr r0, [pc, #0x478]
 *   @0x150d08 mov r2, #1
 *   @0x150d0c mov r3, #0
 *   @0x150d10 ldr r1, [r4, r1]
 *   @0x150d14 add r0, pc, r0
 *   @0x150d18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #80 physics_particle_group_get_vel_x → F_PhysicsParticleGroupVelX(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x150d1c ldr r1, [pc, #0x464]
 *   @0x150d20 ldr r0, [pc, #0x464]
 *   @0x150d24 mov r2, #1
 *   @0x150d28 mov r3, #0
 *   @0x150d2c ldr r1, [r4, r1]
 *   @0x150d30 add r0, pc, r0
 *   @0x150d34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #81 physics_particle_group_get_vel_y → F_PhysicsParticleGroupVelY(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x150d38 ldr r1, [pc, #0x450]
 *   @0x150d3c ldr r0, [pc, #0x450]
 *   @0x150d40 mov r2, #1
 *   @0x150d44 mov r3, #0
 *   @0x150d48 ldr r1, [r4, r1]
 *   @0x150d4c add r0, pc, r0
 *   @0x150d50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #82 physics_particle_group_get_ang_vel → F_PhysicsParticleGroupAngVel(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x150d54 ldr r1, [pc, #0x43c]
 *   @0x150d58 ldr r0, [pc, #0x43c]
 *   @0x150d5c mov r2, #1
 *   @0x150d60 mov r3, #0
 *   @0x150d64 ldr r1, [r4, r1]
 *   @0x150d68 add r0, pc, r0
 *   @0x150d6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #83 physics_particle_group_get_x → F_PhysicsParticleGroupX(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x150d70 ldr r1, [pc, #0x428]
 *   @0x150d74 ldr r0, [pc, #0x428]
 *   @0x150d78 mov r2, #1
 *   @0x150d7c mov r3, #0
 *   @0x150d80 ldr r1, [r4, r1]
 *   @0x150d84 add r0, pc, r0
 *   @0x150d88 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #84 physics_particle_group_get_y → F_PhysicsParticleGroupY(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x150d8c ldr r1, [pc, #0x414]
 *   @0x150d90 ldr r0, [pc, #0x414]
 *   @0x150d94 mov r2, #1
 *   @0x150d98 mov r3, #0
 *   @0x150d9c ldr r1, [r4, r1]
 *   @0x150da0 add r0, pc, r0
 *   @0x150da4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #85 physics_particle_group_get_angle → F_PhysicsParticleGroupAngle(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x150da8 ldr r1, [pc, #0x400]
 *   @0x150dac ldr r0, [pc, #0x400]
 *   @0x150db0 mov r2, #2
 *   @0x150db4 mov r3, #0
 *   @0x150db8 ldr r1, [r4, r1]
 *   @0x150dbc add r0, pc, r0
 *   @0x150dc0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #86 physics_particle_set_group_flags → F_PhysicsSetParticleGroupFlags(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x150dc4 ldr r1, [pc, #0x3ec]
 *   @0x150dc8 ldr r0, [pc, #0x3ec]
 *   @0x150dcc mov r2, #1
 *   @0x150dd0 mov r3, #0
 *   @0x150dd4 ldr r1, [r4, r1]
 *   @0x150dd8 add r0, pc, r0
 *   @0x150ddc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #87 physics_particle_get_group_flags → F_PhysicsGetParticleGroupFlags(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x150de0 ldr r1, [pc, #0x3d8]
 *   @0x150de4 ldr r0, [pc, #0x3d8]
 *   @0x150de8 mov r2, #0
 *   @0x150dec mov r3, r2
 *   @0x150df0 ldr r1, [r4, r1]
 *   @0x150df4 add r0, pc, r0
 *   @0x150df8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #88 physics_particle_get_max_count → F_PhysicsParticleMaxCount(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x150dfc ldr r1, [pc, #0x3c4]
 *   @0x150e00 ldr r0, [pc, #0x3c4]
 *   @0x150e04 mov r2, #0
 *   @0x150e08 mov r3, r2
 *   @0x150e0c ldr r1, [r4, r1]
 *   @0x150e10 add r0, pc, r0
 *   @0x150e14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #89 physics_particle_get_radius → F_PhysicsParticleRadius(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x150e18 ldr r1, [pc, #0x3b0]
 *   @0x150e1c ldr r0, [pc, #0x3b0]
 *   @0x150e20 mov r2, #0
 *   @0x150e24 mov r3, r2
 *   @0x150e28 ldr r1, [r4, r1]
 *   @0x150e2c add r0, pc, r0
 *   @0x150e30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #90 physics_particle_get_density → F_PhysicsParticleDensity(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x150e34 ldr r1, [pc, #0x39c]
 *   @0x150e38 ldr r0, [pc, #0x39c]
 *   @0x150e3c mov r2, #0
 *   @0x150e40 mov r3, r2
 *   @0x150e44 ldr r1, [r4, r1]
 *   @0x150e48 add r0, pc, r0
 *   @0x150e4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #91 physics_particle_get_damping → F_PhysicsParticleDamping(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x150e50 ldr r1, [pc, #0x388]
 *   @0x150e54 ldr r0, [pc, #0x388]
 *   @0x150e58 mov r2, #0
 *   @0x150e5c mov r3, r2
 *   @0x150e60 ldr r1, [r4, r1]
 *   @0x150e64 add r0, pc, r0
 *   @0x150e68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #92 physics_particle_get_gravity_scale → F_PhysicsParticleGravityScale(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x150e6c ldr r1, [pc, #0x374]
 *   @0x150e70 ldr r0, [pc, #0x374]
 *   @0x150e74 mov r2, #1
 *   @0x150e78 mov r3, #0
 *   @0x150e7c ldr r1, [r4, r1]
 *   @0x150e80 add r0, pc, r0
 *   @0x150e84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #93 physics_particle_set_max_count → F_PhysicsParticleSetMaxCount(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x150e88 ldr r1, [pc, #0x360]
 *   @0x150e8c ldr r0, [pc, #0x360]
 *   @0x150e90 mov r2, #1
 *   @0x150e94 mov r3, #0
 *   @0x150e98 ldr r1, [r4, r1]
 *   @0x150e9c add r0, pc, r0
 *   @0x150ea0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #94 physics_particle_set_radius → F_PhysicsParticleSetRadius(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x150ea4 ldr r1, [pc, #0x34c]
 *   @0x150ea8 ldr r0, [pc, #0x34c]
 *   @0x150eac mov r2, #1
 *   @0x150eb0 mov r3, #0
 *   @0x150eb4 ldr r1, [r4, r1]
 *   @0x150eb8 add r0, pc, r0
 *   @0x150ebc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #95 physics_particle_set_density → F_PhysicsParticleSetDensity(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x150ec0 ldr r1, [pc, #0x338]
 *   @0x150ec4 ldr r0, [pc, #0x338]
 *   @0x150ec8 mov r2, #1
 *   @0x150ecc mov r3, #0
 *   @0x150ed0 ldr r1, [r4, r1]
 *   @0x150ed4 add r0, pc, r0
 *   @0x150ed8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #96 physics_particle_set_damping → F_PhysicsParticleSetDamping(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x150edc ldr r1, [pc, #0x324]
 *   @0x150ee0 ldr r0, [pc, #0x324]
 *   @0x150ee4 mov r2, #1
 *   @0x150ee8 mov r3, #0
 *   @0x150eec ldr r1, [r4, r1]
 *   @0x150ef0 add r0, pc, r0
 *   @0x150ef4 pop {r4, lr}
 *   @0x150ef8 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #97 physics_particle_set_gravity_scale → F_PhysicsParticleSetGravityScale(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x150efc eoreq r1, r10, r8, lsl #16
 *   @0x150f00 .word 0xffffdc88
 *   @0x150f04 andseq r4, pc, r0, lsr #23
 *   @0x150f08 .word 0xffffdc8c
 *   @0x150f0c mulseq pc, r12, r11
 *   @0x150f10 .word 0xffffdc90
 *   @0x150f14 mulseq pc, r8, r11
 *   @0x150f18 .word 0xffffdc94
 *   @0x150f1c mulseq pc, r8, r11
 *   @0x150f20 .word 0xffffdc98
 *   @0x150f24 mulseq pc, r12, r11
 *   @0x150f28 .word 0xffffdc9c
 *   @0x150f2c mulseq pc, r12, r11
 *   @0x150f30 .word 0xffffdca0
 *   @0x150f34 mulseq pc, r8, r11
 *   @0x150f38 .word 0xffffdca4
 *   @0x150f3c mulseq pc, r4, r11
 *   @0x150f40 .word 0xffffdca8
 *   @0x150f44 mulseq pc, r8, r11
 *   @0x150f48 .word 0xffffdcac
 *   @0x150f4c mulseq pc, r8, r11
 *   @0x150f50 .word 0xffffdcb0
 *   @0x150f54 mulseq pc, r8, r11
 *   @0x150f58 .word 0xffffdcb4
 *   @0x150f5c mulseq pc, r12, r11
 *   @0x150f60 .word 0xffffdcb8
 *   @0x150f64 andseq r4, pc, r0, lsr #23
 *   @0x150f68 .word 0xffffdcbc
 *   @0x150f6c andseq r4, pc, r8, lsr #23
 *   @0x150f70 .word 0xffffdcc0
 *   @0x150f74 andseq r4, pc, r8, lsr #23
 *   @0x150f78 .word 0xffffdcc4
 *   @0x150f7c ldrheq r4, [pc], -r0
 *   @0x150f80 .word 0xffffdcc8
 *   @0x150f84 ldrheq r4, [pc], -r8
 *   @0x150f88 .word 0xffffdccc
 *   @0x150f8c andseq r4, pc, r0, asr #23
 *   @0x150f90 .word 0xffffdcd0
 *   @0x150f94 andseq r4, pc, r4, asr #23
 *   @0x150f98 .word 0xffffdcd4
 *   @0x150f9c andseq r4, pc, r8, asr #23
 *   @0x150fa0 .word 0xffffdcd8
 *   @0x150fa4 ldrsbeq r4, [pc], -r0
 *   @0x150fa8 .word 0xffffdcdc
 *   @0x150fac ldrsbeq r4, [pc], -r4
 *   @0x150fb0 .word 0xffffdce0
 *   @0x150fb4 ldrsbeq r4, [pc], -r4
 *   @0x150fb8 .word 0xffffdce4
 *   @0x150fbc ldrsbeq r4, [pc], -r0
 *   @0x150fc0 .word 0xffffdce8
 *   @0x150fc4 ldrsbeq r4, [pc], -r0
 *   @0x150fc8 .word 0xffffdcec
 *   @0x150fcc andseq r4, pc, r12, asr #23
 *   @0x150fd0 .word 0xffffdcf0
 *   @0x150fd4 andseq r4, pc, r4, asr #23
 *   @0x150fd8 .word 0xffffdcf4
 *   @0x150fdc andseq r4, pc, r0, asr #23
 *   @0x150fe0 .word 0xffffdcf8
 *   @0x150fe4 andseq r4, pc, r4, asr #23
 *   @0x150fe8 .word 0xffffdcfc
 *   @0x150fec andseq r4, pc, r4, asr #23
 *   @0x150ff0 .word 0xffffdd00
 *   @0x150ff4 andseq r4, pc, r4, asr #23
 *   @0x150ff8 .word 0xffffdd04
 *   @0x150ffc andseq r4, pc, r0, asr #23
 *   @0x151000 .word 0xffffdd08
 *   @0x151004 ldrheq r4, [pc], -r12
 *   @0x151008 .word 0xffffdd0c
 *   @0x15100c ldrheq r4, [pc], -r4
 *   @0x151010 .word 0xffffdd10
 *   @0x151014 ldrheq r4, [pc], -r0
 *   @0x151018 .word 0xffffdd14
 *   @0x15101c andseq r4, pc, r12, lsr #23
 *   @0x151020 .word 0xffffdd18
 *   @0x151024 andseq r4, pc, r8, lsr #23
 *   @0x151028 .word 0xffffdd1c
 *   @0x15102c andseq r4, pc, r0, lsr #23
 *   @0x151030 .word 0xffffdd20
 *   @0x151034 mulseq pc, r12, r11
 *   @0x151038 .word 0xffffdd24
 *   @0x15103c mulseq pc, r8, r11
 *   @0x151040 .word 0xffffdd28
 *   @0x151044 mulseq pc, r0, r11
 *   @0x151048 .word 0xffffdd2c
 *   @0x15104c andseq r4, pc, r12, lsl #23
 *   @0x151050 .word 0xffffdd30
 *   @0x151054 mulseq pc, r0, r11
 *   @0x151058 .word 0xffffdd34
 *   @0x15105c mulseq pc, r0, r11
 *   @0x151060 .word 0xffffdd38
 *   @0x151064 mulseq pc, r4, r11
 *   @0x151068 .word 0xffffdd3c
 *   @0x15106c mulseq pc, r8, r11
 *   @0x151070 .word 0xffffdd40
 *   @0x151074 mulseq pc, r8, r11
 *   @0x151078 .word 0xffffdd44
 *   @0x15107c mulseq pc, r8, r11
 *   @0x151080 .word 0xffffdd48
 *   @0x151084 mulseq pc, r8, r11
 *   @0x151088 .word 0xffffdd4c
 *   @0x15108c mulseq pc, r8, r11
 *   @0x151090 .word 0xffffdd50
 *   @0x151094 mulseq pc, r12, r11
 *   @0x151098 .word 0xffffdd54
 *   @0x15109c mulseq pc, r12, r11
 *   @0x1510a0 .word 0xffffdd58
 *   @0x1510a4 mulseq pc, r8, r11
 *   @0x1510a8 .word 0xffffdd5c
 *   @0x1510ac mulseq pc, r4, r11
 *   @0x1510b0 .word 0xffffdd60
 *   @0x1510b4 mulseq pc, r0, r11
 *   @0x1510b8 .word 0xffffdd64
 *   @0x1510bc andseq r4, pc, r12, lsl #23
 *   @0x1510c0 .word 0xffffdd68
 *   @0x1510c4 andseq r4, pc, r8, lsl #23
 *   @0x1510c8 .word 0xffffdd6c
 *   @0x1510cc mulseq pc, r4, r11
 *   @0x1510d0 .word 0xffffdd70
 *   @0x1510d4 mulseq pc, r12, r11
 *   @0x1510d8 .word 0xffffdd74
 *   @0x1510dc andseq r4, pc, r4, lsr #23
 *   @0x1510e0 .word 0xffffdd78
 *   @0x1510e4 andseq r4, pc, r4, lsr #23
 *   @0x1510e8 .word 0xffffdd7c
 *   @0x1510ec andseq r4, pc, r12, lsr #23
 *   @0x1510f0 .word 0xffffdd80
 *   @0x1510f4 andseq r4, pc, r8, lsr #23
 *   @0x1510f8 .word 0xffffdd84
 *   @0x1510fc andseq r4, pc, r8, lsr #23
 *   @0x151100 .word 0xffffdd88
 *   @0x151104 andseq r4, pc, r4, lsr #23
 *   @0x151108 .word 0xffffdd8c
 *   @0x15110c andseq r4, pc, r4, lsr #23
 *   @0x151110 .word 0xffffdd90
 *   @0x151114 andseq r4, pc, r12, lsr #23
 *   @0x151118 .word 0xffffdd94
 *   @0x15111c ldrheq r4, [pc], -r0
 *   @0x151120 .word 0xffffdd98
 *   @0x151124 ldrheq r4, [pc], -r4
 *   @0x151128 .word 0xffffdd9c
 *   @0x15112c ldrheq r4, [pc], -r4
 *   @0x151130 .word 0xffffdda0
 *   @0x151134 ldrheq r4, [pc], -r8
 *   @0x151138 .word 0xffffdda4
 *   @0x15113c andseq r4, pc, r0, asr #23
 *   @0x151140 .word 0xffffdda8
 *   @0x151144 andseq r4, pc, r0, asr #23
 *   @0x151148 .word 0xffffddac
 *   @0x15114c andseq r4, pc, r0, asr #23
 *   @0x151150 .word 0xffffddb0
 *   @0x151154 andseq r4, pc, r4, asr #23
 *   @0x151158 .word 0xffffddb4
 *   @0x15115c andseq r4, pc, r8, asr #23
 *   @0x151160 .word 0xffffddb8
 *   @0x151164 andseq r4, pc, r12, asr #23
 *   @0x151168 .word 0xffffddbc
 *   @0x15116c ldrsbeq r4, [pc], -r0
 *   @0x151170 .word 0xffffddc0
 *   @0x151174 ldrsbeq r4, [pc], -r8
 *   @0x151178 .word 0xffffddc4
 *   @0x15117c andseq r4, pc, r0, ror #23
 *   @0x151180 .word 0xffffddc8
 *   @0x151184 andseq r4, pc, r8, ror #23
 *   @0x151188 .word 0xffffddcc
 *   @0x15118c ldrsheq r4, [pc], -r0
 *   @0x151190 .word 0xffffddd0
 *   @0x151194 ldrsheq r4, [pc], -r8
 *   @0x151198 .word 0xffffddd4
 *   @0x15119c andseq r4, pc, r0, lsl #24
 *   @0x1511a0 .word 0xffffddd8
 *   @0x1511a4 andseq r4, pc, r4, lsl #24
 *   @0x1511a8 .word 0xffffdddc
 *   @0x1511ac andseq r4, pc, r8, lsl #24
 *   @0x1511b0 .word 0xffffdde0
 *   @0x1511b4 andseq r4, pc, r0, lsl r12
 *   @0x1511b8 .word 0xffffdde4
 *   @0x1511bc andseq r4, pc, r8, lsl r12
 *   @0x1511c0 .word 0xffffdde8
 *   @0x1511c4 andseq r4, pc, r0, lsr #24
 *   @0x1511c8 .word 0xffffddec
 *   @0x1511cc andseq r4, pc, r4, lsr #24
 *   @0x1511d0 .word 0xffffddf0
 *   @0x1511d4 andseq r4, pc, r4, lsr #24
 *   @0x1511d8 .word 0xffffddf4
 *   @0x1511dc andseq r4, pc, r8, lsr #24
 *   @0x1511e0 .word 0xffffddf8
 *   @0x1511e4 andseq r4, pc, r12, lsr #24
 *   @0x1511e8 .word 0xffffddfc
 *   @0x1511ec andseq r4, pc, r4, lsr r12
 *   @0x1511f0 .word 0xffffde00
 *   @0x1511f4 andseq r4, pc, r8, lsr r12
 *   @0x1511f8 .word 0xffffde04
 *   @0x1511fc andseq r4, pc, r8, lsr r12
 *   @0x151200 .word 0xffffde08
 *   @0x151204 andseq r4, pc, r12, lsr r12
 *   @0x151208 .word 0xffffde0c
 *   @0x15120c andseq r4, pc, r0, asr #24
 *
 * ══ §6/6 InitGameFunctions  0x10c7d8..0x10d558  size 3456  864 条（673 条指令 + 191 个池字）══
 * @func 0x10c7d8 0x10d558  size 3456  864 条
 * 注册 95 条｜唯一名 95｜唯一函数指针 94｜argc -1:1 0:7 1:26 2:17 3:13 4:9 5:8 6:6 7:5 8:2 10:1｜flag 0:70 1:24 ?:1
 * 首条 #0 move_random（0x10c7fc）→ 末条 #94 rectangle_in_circle（0x10d258）
 * 名字族（前 8）: instance×22 mp×21 move×12 room×6 game×6 collision×5 place×4 position×4
 * 游戏实际调用的 99 个内建里落在本表: 22 个（collision_line, collision_point, distance_to_object, game_restart, instance_activate_all, instance_activate_object, instance_activate_region, instance_create, instance_deactivate_all, instance_deactivate_object, instance_destroy, instance_exists, instance_number, instance_place, motion_set, move_bounce_all, move_bounce_solid, move_towards_point, mp_potential_step, place_meeting, room_goto, room_restart）
 * 条件跳转 1 处: 0x10cdf8(bne)
 * 表: asm/init-tables/init-InitGameFunctions.tsv（idx/调用地址/name/fn/argc/flag 逐条）
 * 未定（open）: #55@0x10ce10(instance_create) —— 实参来自运行期全局值或共享尾未解，本卡不猜
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10c7d8 push {r4, r5, r6, lr}
 *   @0x10c7dc mov r2, #2
 *   @0x10c7e0 ldr r4, [pc, #0xa74]
 *   @0x10c7e4 mov r3, #0
 *   @0x10c7e8 ldr r1, [pc, #0xa70]
 *   @0x10c7ec add r4, pc, r4
 *   @0x10c7f0 ldr r0, [pc, #0xa6c]
 *   @0x10c7f4 add r0, pc, r0
 *   @0x10c7f8 ldr r1, [r4, r1]
 *   @0x10c7fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #0 move_random → F_MoveRandom(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x10c800 ldr r1, [pc, #0xa60]
 *   @0x10c804 ldr r0, [pc, #0xa60]
 *   @0x10c808 mov r2, #2
 *   @0x10c80c mov r3, #0
 *   @0x10c810 add r0, pc, r0
 *   @0x10c814 ldr r1, [r4, r1]
 *   @0x10c818 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #1 place_free → F_PlaceFree(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x10c81c ldr r1, [pc, #0xa4c]
 *   @0x10c820 ldr r0, [pc, #0xa4c]
 *   @0x10c824 mov r2, #2
 *   @0x10c828 mov r3, #0
 *   @0x10c82c add r0, pc, r0
 *   @0x10c830 ldr r1, [r4, r1]
 *   @0x10c834 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #2 place_empty → F_PlaceEmpty(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x10c838 ldr r1, [pc, #0xa38]
 *   @0x10c83c ldr r0, [pc, #0xa38]
 *   @0x10c840 mov r2, #3
 *   @0x10c844 mov r3, #0
 *   @0x10c848 add r0, pc, r0
 *   @0x10c84c ldr r1, [r4, r1]
 *   @0x10c850 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #3 place_meeting → F_PlaceMeeting(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x10c854 ldr r1, [pc, #0xa24]
 *   @0x10c858 ldr r0, [pc, #0xa24]
 *   @0x10c85c mov r2, #2
 *   @0x10c860 mov r3, #0
 *   @0x10c864 add r0, pc, r0
 *   @0x10c868 ldr r1, [r4, r1]
 *   @0x10c86c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #4 place_snapped → F_PlaceSnapped(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x10c870 ldr r1, [pc, #0xa10]
 *   @0x10c874 ldr r0, [pc, #0xa10]
 *   @0x10c878 mov r2, #2
 *   @0x10c87c mov r3, #0
 *   @0x10c880 add r0, pc, r0
 *   @0x10c884 ldr r1, [r4, r1]
 *   @0x10c888 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #5 move_snap → F_MoveSnap(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x10c88c ldr r1, [pc, #0x9fc]
 *   @0x10c890 ldr r0, [pc, #0x9fc]
 *   @0x10c894 mov r2, #3
 *   @0x10c898 mov r3, #0
 *   @0x10c89c add r0, pc, r0
 *   @0x10c8a0 ldr r1, [r4, r1]
 *   @0x10c8a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #6 move_towards_point → F_MoveTowardsPoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x10c8a8 ldr r1, [pc, #0x9e8]
 *   @0x10c8ac ldr r0, [pc, #0x9e8]
 *   @0x10c8b0 mov r2, #1
 *   @0x10c8b4 mov r3, #0
 *   @0x10c8b8 add r0, pc, r0
 *   @0x10c8bc ldr r1, [r4, r1]
 *   @0x10c8c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #7 move_contact → F_MoveContact(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x10c8c4 ldr r1, [pc, #0x9d4]
 *   @0x10c8c8 ldr r0, [pc, #0x9d4]
 *   @0x10c8cc mov r2, #2
 *   @0x10c8d0 mov r3, #0
 *   @0x10c8d4 add r0, pc, r0
 *   @0x10c8d8 ldr r1, [r4, r1]
 *   @0x10c8dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #8 move_contact_solid → F_MoveContactSolid(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x10c8e0 ldr r1, [pc, #0x9c0]
 *   @0x10c8e4 ldr r0, [pc, #0x9c0]
 *   @0x10c8e8 mov r2, #2
 *   @0x10c8ec mov r3, #0
 *   @0x10c8f0 add r0, pc, r0
 *   @0x10c8f4 ldr r1, [r4, r1]
 *   @0x10c8f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #9 move_contact_all → F_MoveContactAll(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x10c8fc ldr r1, [pc, #0x9ac]
 *   @0x10c900 ldr r0, [pc, #0x9ac]
 *   @0x10c904 mov r2, #2
 *   @0x10c908 mov r3, #0
 *   @0x10c90c add r0, pc, r0
 *   @0x10c910 ldr r1, [r4, r1]
 *   @0x10c914 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #10 move_outside_solid → F_MoveOutsideSolid(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x10c918 ldr r1, [pc, #0x998]
 *   @0x10c91c ldr r0, [pc, #0x998]
 *   @0x10c920 mov r2, #2
 *   @0x10c924 mov r3, #0
 *   @0x10c928 add r0, pc, r0
 *   @0x10c92c ldr r1, [r4, r1]
 *   @0x10c930 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #11 move_outside_all → F_MoveOutsideAll(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x10c934 ldr r1, [pc, #0x984]
 *   @0x10c938 ldr r0, [pc, #0x984]
 *   @0x10c93c mov r2, #1
 *   @0x10c940 mov r3, #0
 *   @0x10c944 ldr r5, [r4, r1]
 *   @0x10c948 add r0, pc, r0
 *   @0x10c94c mov r1, r5
 *   @0x10c950 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #12 move_bounce → F_MoveBounceSolid(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x10c954 ldr r0, [pc, #0x96c]
 *   @0x10c958 mov r1, r5
 *   @0x10c95c mov r2, #1
 *   @0x10c960 add r0, pc, r0
 *   @0x10c964 mov r3, #0
 *   @0x10c968 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #13 move_bounce_solid → F_MoveBounceSolid(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x10c96c ldr r1, [pc, #0x958]
 *   @0x10c970 ldr r0, [pc, #0x958]
 *   @0x10c974 mov r2, #1
 *   @0x10c978 mov r3, #0
 *   @0x10c97c add r0, pc, r0
 *   @0x10c980 ldr r1, [r4, r1]
 *   @0x10c984 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #14 move_bounce_all → F_MoveBounceAll(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x10c988 ldr r1, [pc, #0x944]
 *   @0x10c98c ldr r0, [pc, #0x944]
 *   @0x10c990 mov r2, #3
 *   @0x10c994 mov r3, #0
 *   @0x10c998 add r0, pc, r0
 *   @0x10c99c ldr r1, [r4, r1]
 *   @0x10c9a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #15 move_wrap → F_MoveWrap(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x10c9a4 ldr r1, [pc, #0x930]
 *   @0x10c9a8 ldr r0, [pc, #0x930]
 *   @0x10c9ac mov r2, #2
 *   @0x10c9b0 mov r3, #0
 *   @0x10c9b4 add r0, pc, r0
 *   @0x10c9b8 ldr r1, [r4, r1]
 *   @0x10c9bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #16 motion_set → F_MotionSet(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x10c9c0 ldr r1, [pc, #0x91c]
 *   @0x10c9c4 ldr r0, [pc, #0x91c]
 *   @0x10c9c8 mov r2, #2
 *   @0x10c9cc mov r3, #0
 *   @0x10c9d0 add r0, pc, r0
 *   @0x10c9d4 ldr r1, [r4, r1]
 *   @0x10c9d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #17 motion_add → F_MotionAdd(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x10c9dc ldr r1, [pc, #0x908]
 *   @0x10c9e0 ldr r0, [pc, #0x908]
 *   @0x10c9e4 mov r2, #2
 *   @0x10c9e8 mov r3, #0
 *   @0x10c9ec add r0, pc, r0
 *   @0x10c9f0 ldr r1, [r4, r1]
 *   @0x10c9f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #18 distance_to_point → F_DistanceToPoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x10c9f8 ldr r1, [pc, #0x8f4]
 *   @0x10c9fc ldr r0, [pc, #0x8f4]
 *   @0x10ca00 mov r2, #1
 *   @0x10ca04 mov r3, #0
 *   @0x10ca08 add r0, pc, r0
 *   @0x10ca0c ldr r1, [r4, r1]
 *   @0x10ca10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #19 distance_to_object → F_DistanceToObject(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x10ca14 ldr r1, [pc, #0x8e0]
 *   @0x10ca18 ldr r0, [pc, #0x8e0]
 *   @0x10ca1c mov r2, #4
 *   @0x10ca20 mov r3, #0
 *   @0x10ca24 add r0, pc, r0
 *   @0x10ca28 ldr r1, [r4, r1]
 *   @0x10ca2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #20 path_start → F_PathStart(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x10ca30 ldr r1, [pc, #0x8cc]
 *   @0x10ca34 ldr r0, [pc, #0x8cc]
 *   @0x10ca38 mov r2, #0
 *   @0x10ca3c mov r3, r2
 *   @0x10ca40 add r0, pc, r0
 *   @0x10ca44 ldr r1, [r4, r1]
 *   @0x10ca48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #21 path_end → F_PathEnd(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x10ca4c ldr r1, [pc, #0x8b8]
 *   @0x10ca50 ldr r0, [pc, #0x8b8]
 *   @0x10ca54 mov r2, #4
 *   @0x10ca58 mov r3, #0
 *   @0x10ca5c add r0, pc, r0
 *   @0x10ca60 ldr r1, [r4, r1]
 *   @0x10ca64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #22 mp_linear_step → F_MpLinearStep(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x10ca68 ldr r1, [pc, #0x8a4]
 *   @0x10ca6c ldr r0, [pc, #0x8a4]
 *   @0x10ca70 mov r2, #5
 *   @0x10ca74 mov r3, #1
 *   @0x10ca78 add r0, pc, r0
 *   @0x10ca7c ldr r1, [r4, r1]
 *   @0x10ca80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #23 mp_linear_path → F_MpLinearPath(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x10ca84 ldr r1, [pc, #0x890]
 *   @0x10ca88 ldr r0, [pc, #0x890]
 *   @0x10ca8c mov r2, #4
 *   @0x10ca90 mov r3, #0
 *   @0x10ca94 add r0, pc, r0
 *   @0x10ca98 ldr r1, [r4, r1]
 *   @0x10ca9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #24 mp_linear_step_object → F_MpLinearStepObject(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x10caa0 ldr r1, [pc, #0x87c]
 *   @0x10caa4 ldr r0, [pc, #0x87c]
 *   @0x10caa8 mov r2, #5
 *   @0x10caac mov r3, #1
 *   @0x10cab0 add r0, pc, r0
 *   @0x10cab4 ldr r1, [r4, r1]
 *   @0x10cab8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #25 mp_linear_path_object → F_MpLinearPathObject(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x10cabc ldr r1, [pc, #0x868]
 *   @0x10cac0 ldr r0, [pc, #0x868]
 *   @0x10cac4 mov r2, #4
 *   @0x10cac8 mov r3, #0
 *   @0x10cacc add r0, pc, r0
 *   @0x10cad0 ldr r1, [r4, r1]
 *   @0x10cad4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #26 mp_potential_settings → F_MpPotentialSettings(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x10cad8 ldr r1, [pc, #0x854]
 *   @0x10cadc ldr r0, [pc, #0x854]
 *   @0x10cae0 mov r2, #4
 *   @0x10cae4 mov r3, #0
 *   @0x10cae8 add r0, pc, r0
 *   @0x10caec ldr r1, [r4, r1]
 *   @0x10caf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #27 mp_potential_step → F_MpPotentialStep(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x10caf4 ldr r1, [pc, #0x840]
 *   @0x10caf8 ldr r0, [pc, #0x840]
 *   @0x10cafc mov r2, #6
 *   @0x10cb00 mov r3, #1
 *   @0x10cb04 add r0, pc, r0
 *   @0x10cb08 ldr r1, [r4, r1]
 *   @0x10cb0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #28 mp_potential_path → F_MpPotentialPath(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x10cb10 ldr r1, [pc, #0x82c]
 *   @0x10cb14 ldr r0, [pc, #0x82c]
 *   @0x10cb18 mov r2, #4
 *   @0x10cb1c mov r3, #0
 *   @0x10cb20 add r0, pc, r0
 *   @0x10cb24 ldr r1, [r4, r1]
 *   @0x10cb28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #29 mp_potential_step_object → F_MpPotentialStepObject(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x10cb2c ldr r1, [pc, #0x818]
 *   @0x10cb30 ldr r0, [pc, #0x818]
 *   @0x10cb34 mov r2, #6
 *   @0x10cb38 mov r3, #1
 *   @0x10cb3c add r0, pc, r0
 *   @0x10cb40 ldr r1, [r4, r1]
 *   @0x10cb44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #30 mp_potential_path_object → F_MpPotentialPathObject(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x10cb48 ldr r1, [pc, #0x804]
 *   @0x10cb4c ldr r0, [pc, #0x804]
 *   @0x10cb50 mov r2, #6
 *   @0x10cb54 mov r3, #1
 *   @0x10cb58 add r0, pc, r0
 *   @0x10cb5c ldr r1, [r4, r1]
 *   @0x10cb60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #31 mp_grid_create → F_MpGridCreate(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x10cb64 ldr r1, [pc, #0x7f0]
 *   @0x10cb68 ldr r0, [pc, #0x7f0]
 *   @0x10cb6c mov r2, #1
 *   @0x10cb70 mov r3, r2
 *   @0x10cb74 add r0, pc, r0
 *   @0x10cb78 ldr r1, [r4, r1]
 *   @0x10cb7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #32 mp_grid_destroy → F_MpGridDestroy(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x10cb80 ldr r1, [pc, #0x7dc]
 *   @0x10cb84 ldr r0, [pc, #0x7dc]
 *   @0x10cb88 mov r2, #1
 *   @0x10cb8c mov r3, r2
 *   @0x10cb90 add r0, pc, r0
 *   @0x10cb94 ldr r1, [r4, r1]
 *   @0x10cb98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #33 mp_grid_clear_all → F_MpGridClearAll(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x10cb9c ldr r1, [pc, #0x7c8]
 *   @0x10cba0 ldr r0, [pc, #0x7c8]
 *   @0x10cba4 mov r2, #3
 *   @0x10cba8 mov r3, #1
 *   @0x10cbac add r0, pc, r0
 *   @0x10cbb0 ldr r1, [r4, r1]
 *   @0x10cbb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #34 mp_grid_clear_cell → F_MpGridClearCell(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x10cbb8 ldr r1, [pc, #0x7b4]
 *   @0x10cbbc ldr r0, [pc, #0x7b4]
 *   @0x10cbc0 mov r2, #5
 *   @0x10cbc4 mov r3, #1
 *   @0x10cbc8 add r0, pc, r0
 *   @0x10cbcc ldr r1, [r4, r1]
 *   @0x10cbd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #35 mp_grid_clear_rectangle → F_MpGridClearRectangle(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x10cbd4 ldr r1, [pc, #0x7a0]
 *   @0x10cbd8 ldr r0, [pc, #0x7a0]
 *   @0x10cbdc mov r2, #3
 *   @0x10cbe0 mov r3, #1
 *   @0x10cbe4 add r0, pc, r0
 *   @0x10cbe8 ldr r1, [r4, r1]
 *   @0x10cbec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #36 mp_grid_add_cell → F_MpGridAddCell(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x10cbf0 ldr r1, [pc, #0x78c]
 *   @0x10cbf4 ldr r0, [pc, #0x78c]
 *   @0x10cbf8 mov r2, #3
 *   @0x10cbfc mov r3, #1
 *   @0x10cc00 add r0, pc, r0
 *   @0x10cc04 ldr r1, [r4, r1]
 *   @0x10cc08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #37 mp_grid_get_cell → F_MpGridGetCell(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x10cc0c ldr r1, [pc, #0x778]
 *   @0x10cc10 ldr r0, [pc, #0x778]
 *   @0x10cc14 mov r2, #5
 *   @0x10cc18 mov r3, #1
 *   @0x10cc1c add r0, pc, r0
 *   @0x10cc20 ldr r1, [r4, r1]
 *   @0x10cc24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #38 mp_grid_add_rectangle → F_MpGridAddRectangle(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x10cc28 ldr r1, [pc, #0x764]
 *   @0x10cc2c ldr r0, [pc, #0x764]
 *   @0x10cc30 mov r2, #3
 *   @0x10cc34 mov r3, #1
 *   @0x10cc38 add r0, pc, r0
 *   @0x10cc3c ldr r1, [r4, r1]
 *   @0x10cc40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #39 mp_grid_add_instances → F_MpGridAddInstances(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=1
 *   @0x10cc44 ldr r1, [pc, #0x750]
 *   @0x10cc48 ldr r0, [pc, #0x750]
 *   @0x10cc4c mov r2, #7
 *   @0x10cc50 mov r3, #1
 *   @0x10cc54 add r0, pc, r0
 *   @0x10cc58 ldr r1, [r4, r1]
 *   @0x10cc5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #40 mp_grid_path → F_MpGridPath(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x10cc60 ldr r1, [pc, #0x73c]
 *   @0x10cc64 ldr r0, [pc, #0x73c]
 *   @0x10cc68 mov r2, #1
 *   @0x10cc6c mov r3, r2
 *   @0x10cc70 add r0, pc, r0
 *   @0x10cc74 ldr r1, [r4, r1]
 *   @0x10cc78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #41 mp_grid_draw → F_MpGridDraw(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x10cc7c ldr r1, [pc, #0x728]
 *   @0x10cc80 ldr r0, [pc, #0x728]
 *   @0x10cc84 mov r2, #1
 *   @0x10cc88 mov r3, r2
 *   @0x10cc8c add r0, pc, r0
 *   @0x10cc90 ldr r1, [r4, r1]
 *   @0x10cc94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #42 mp_grid_to_ds_grid → F_MpGrid_to_DSGrid(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x10cc98 ldr r1, [pc, #0x714]
 *   @0x10cc9c ldr r0, [pc, #0x714]
 *   @0x10cca0 mov r2, #5
 *   @0x10cca4 mov r3, #0
 *   @0x10cca8 add r0, pc, r0
 *   @0x10ccac ldr r1, [r4, r1]
 *   @0x10ccb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #43 collision_point → F_CollisionPoint(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0x10ccb4 ldr r1, [pc, #0x700]
 *   @0x10ccb8 ldr r0, [pc, #0x700]
 *   @0x10ccbc mov r2, #7
 *   @0x10ccc0 mov r3, #0
 *   @0x10ccc4 add r0, pc, r0
 *   @0x10ccc8 ldr r1, [r4, r1]
 *   @0x10cccc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #44 collision_rectangle → F_CollisionRectangle(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=0
 *   @0x10ccd0 ldr r1, [pc, #0x6ec]
 *   @0x10ccd4 ldr r0, [pc, #0x6ec]
 *   @0x10ccd8 mov r2, #6
 *   @0x10ccdc mov r3, #0
 *   @0x10cce0 add r0, pc, r0
 *   @0x10cce4 ldr r1, [r4, r1]
 *   @0x10cce8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #45 collision_circle → F_CollisionCircle(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=0
 *   @0x10ccec ldr r1, [pc, #0x6d8]
 *   @0x10ccf0 ldr r0, [pc, #0x6d8]
 *   @0x10ccf4 mov r2, #7
 *   @0x10ccf8 mov r3, #0
 *   @0x10ccfc add r0, pc, r0
 *   @0x10cd00 ldr r1, [r4, r1]
 *   @0x10cd04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #46 collision_ellipse → F_CollisionEllipse(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=0
 *   @0x10cd08 ldr r1, [pc, #0x6c4]
 *   @0x10cd0c ldr r0, [pc, #0x6c4]
 *   @0x10cd10 mov r2, #7
 *   @0x10cd14 mov r3, #0
 *   @0x10cd18 add r0, pc, r0
 *   @0x10cd1c ldr r1, [r4, r1]
 *   @0x10cd20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #47 collision_line → F_CollisionLine(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=0
 *   @0x10cd24 ldr r1, [pc, #0x6b0]
 *   @0x10cd28 ldr r0, [pc, #0x6b0]
 *   @0x10cd2c mov r2, #2
 *   @0x10cd30 mov r3, #0
 *   @0x10cd34 add r0, pc, r0
 *   @0x10cd38 ldr r1, [r4, r1]
 *   @0x10cd3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #48 instance_find → F_InstanceFind(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x10cd40 ldr r1, [pc, #0x69c]
 *   @0x10cd44 ldr r0, [pc, #0x69c]
 *   @0x10cd48 mov r2, #1
 *   @0x10cd4c mov r3, #0
 *   @0x10cd50 add r0, pc, r0
 *   @0x10cd54 ldr r1, [r4, r1]
 *   @0x10cd58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #49 instance_exists → F_InstanceExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x10cd5c ldr r1, [pc, #0x688]
 *   @0x10cd60 ldr r0, [pc, #0x688]
 *   @0x10cd64 mov r2, #1
 *   @0x10cd68 mov r3, #0
 *   @0x10cd6c add r0, pc, r0
 *   @0x10cd70 ldr r1, [r4, r1]
 *   @0x10cd74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #50 instance_number → F_InstanceNumber(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x10cd78 ldr r1, [pc, #0x674]
 *   @0x10cd7c ldr r0, [pc, #0x674]
 *   @0x10cd80 mov r2, #3
 *   @0x10cd84 mov r3, #0
 *   @0x10cd88 add r0, pc, r0
 *   @0x10cd8c ldr r1, [r4, r1]
 *   @0x10cd90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #51 instance_position → F_InstancePosition(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x10cd94 ldr r1, [pc, #0x660]
 *   @0x10cd98 ldr r0, [pc, #0x660]
 *   @0x10cd9c mov r2, #3
 *   @0x10cda0 mov r3, #0
 *   @0x10cda4 add r0, pc, r0
 *   @0x10cda8 ldr r1, [r4, r1]
 *   @0x10cdac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #52 instance_nearest → F_InstanceNearest(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x10cdb0 ldr r1, [pc, #0x64c]
 *   @0x10cdb4 ldr r0, [pc, #0x64c]
 *   @0x10cdb8 mov r2, #3
 *   @0x10cdbc mov r3, #0
 *   @0x10cdc0 add r0, pc, r0
 *   @0x10cdc4 ldr r1, [r4, r1]
 *   @0x10cdc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #53 instance_furthest → F_InstanceFurthest(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x10cdcc ldr r1, [pc, #0x638]
 *   @0x10cdd0 ldr r0, [pc, #0x638]
 *   @0x10cdd4 mov r3, #0
 *   @0x10cdd8 mov r2, #3
 *   @0x10cddc add r0, pc, r0
 *   @0x10cde0 ldr r1, [r4, r1]
 *   @0x10cde4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #54 instance_place → F_InstancePlace(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x10cde8 ldr r3, [pc, #0x624]
 *   @0x10cdec ldr r3, [r4, r3]
 *   @0x10cdf0 ldrb r3, [r3]
 *   @0x10cdf4 cmp r3, #0
 *   @0x10cdf8 bne 0x10ce14 <_Z17InitGameFunctionsv+0x63c>   —— 条件跳转 → 0x10ce14
 *   @0x10cdfc ldr r1, [pc, #0x614]
 *   @0x10ce00 mov r2, #3
 *   @0x10ce04 ldr r0, [pc, #0x610]
 *   @0x10ce08 ldr r1, [r4, r1]
 *   @0x10ce0c add r0, pc, r0
 *   @0x10ce10 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #55 instance_create → F_InstanceCreate(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=None ⚠ ?
 *   @0x10ce14 ldr r1, [pc, #0x604]
 *   @0x10ce18 mov r2, #4
 *   @0x10ce1c ldr r0, [pc, #0x600]
 *   @0x10ce20 mov r3, #0
 *   @0x10ce24 ldr r1, [r4, r1]
 *   @0x10ce28 add r0, pc, r0
 *   @0x10ce2c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #56 instance_create_depth → F_InstanceCreateDepth(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x10ce30 ldr r1, [pc, #0x5f0]
 *   @0x10ce34 ldr r0, [pc, #0x5f0]
 *   @0x10ce38 mov r2, #4
 *   @0x10ce3c mov r3, #0
 *   @0x10ce40 ldr r1, [r4, r1]
 *   @0x10ce44 add r0, pc, r0
 *   @0x10ce48 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #57 instance_create_layer → F_InstanceCreateLayer(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x10ce4c ldr r1, [pc, #0x5dc]
 *   @0x10ce50 ldr r0, [pc, #0x5dc]
 *   @0x10ce54 mov r2, #1
 *   @0x10ce58 mov r3, #0
 *   @0x10ce5c ldr r1, [r4, r1]
 *   @0x10ce60 add r0, pc, r0
 *   @0x10ce64 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #58 instance_copy → F_InstanceCopy(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x10ce68 ldr r1, [pc, #0x5c8]
 *   @0x10ce6c ldr r0, [pc, #0x5c8]
 *   @0x10ce70 mov r2, #2
 *   @0x10ce74 mov r3, #0
 *   @0x10ce78 ldr r1, [r4, r1]
 *   @0x10ce7c add r0, pc, r0
 *   @0x10ce80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #59 instance_change → F_InstanceChange(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x10ce84 ldr r1, [pc, #0x5b4]
 *   @0x10ce88 ldr r0, [pc, #0x5b4]
 *   @0x10ce8c mvn r2, #0
 *   @0x10ce90 mov r3, #0
 *   @0x10ce94 ldr r1, [r4, r1]
 *   @0x10ce98 add r0, pc, r0
 *   @0x10ce9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #60 instance_destroy → F_InstanceDestroy(RValue&, CInstance*, CInstance*, int, RValue*) argc=-1 flag=0
 *   @0x10cea0 ldr r1, [pc, #0x5a0]
 *   @0x10cea4 ldr r0, [pc, #0x5a0]
 *   @0x10cea8 mov r2, #1
 *   @0x10ceac mov r3, #0
 *   @0x10ceb0 ldr r1, [r4, r1]
 *   @0x10ceb4 add r0, pc, r0
 *   @0x10ceb8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #61 instance_sprite → F_InstanceSprite(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x10cebc ldr r1, [pc, #0x58c]
 *   @0x10cec0 ldr r0, [pc, #0x58c]
 *   @0x10cec4 mov r2, #2
 *   @0x10cec8 mov r3, #0
 *   @0x10cecc ldr r1, [r4, r1]
 *   @0x10ced0 add r0, pc, r0
 *   @0x10ced4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #62 position_empty → F_PositionEmpty(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x10ced8 ldr r1, [pc, #0x578]
 *   @0x10cedc ldr r0, [pc, #0x578]
 *   @0x10cee0 mov r2, #3
 *   @0x10cee4 mov r3, #0
 *   @0x10cee8 ldr r1, [r4, r1]
 *   @0x10ceec add r0, pc, r0
 *   @0x10cef0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #63 position_meeting → F_PositionMeeting(RValue&, CInstance*, CInstance*, int, RValue*) argc=3 flag=0
 *   @0x10cef4 ldr r1, [pc, #0x564]
 *   @0x10cef8 ldr r0, [pc, #0x564]
 *   @0x10cefc mov r2, #2
 *   @0x10cf00 mov r3, #0
 *   @0x10cf04 ldr r1, [r4, r1]
 *   @0x10cf08 add r0, pc, r0
 *   @0x10cf0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #64 position_destroy → F_PositionDestroy(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=0
 *   @0x10cf10 ldr r1, [pc, #0x550]
 *   @0x10cf14 ldr r0, [pc, #0x550]
 *   @0x10cf18 mov r2, #4
 *   @0x10cf1c mov r3, #0
 *   @0x10cf20 ldr r1, [r4, r1]
 *   @0x10cf24 add r0, pc, r0
 *   @0x10cf28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #65 position_change → F_PositionChange(RValue&, CInstance*, CInstance*, int, RValue*) argc=4 flag=0
 *   @0x10cf2c ldr r1, [pc, #0x53c]
 *   @0x10cf30 ldr r0, [pc, #0x53c]
 *   @0x10cf34 mov r2, #1
 *   @0x10cf38 mov r3, #0
 *   @0x10cf3c ldr r1, [r4, r1]
 *   @0x10cf40 add r0, pc, r0
 *   @0x10cf44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #66 instance_id_get → F_InstanceIdGet(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x10cf48 ldr r1, [pc, #0x528]
 *   @0x10cf4c ldr r0, [pc, #0x528]
 *   @0x10cf50 mov r2, #1
 *   @0x10cf54 mov r3, #0
 *   @0x10cf58 ldr r1, [r4, r1]
 *   @0x10cf5c add r0, pc, r0
 *   @0x10cf60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #67 instance_deactivate_all → F_InstanceDeactivateAll(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x10cf64 ldr r1, [pc, #0x514]
 *   @0x10cf68 ldr r0, [pc, #0x514]
 *   @0x10cf6c mov r2, #1
 *   @0x10cf70 mov r3, #0
 *   @0x10cf74 ldr r1, [r4, r1]
 *   @0x10cf78 add r0, pc, r0
 *   @0x10cf7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #68 instance_deactivate_object → F_InstanceDeactivateObject(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x10cf80 ldr r1, [pc, #0x500]
 *   @0x10cf84 ldr r0, [pc, #0x500]
 *   @0x10cf88 mov r2, #6
 *   @0x10cf8c mov r3, #0
 *   @0x10cf90 ldr r1, [r4, r1]
 *   @0x10cf94 add r0, pc, r0
 *   @0x10cf98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #69 instance_deactivate_region → F_InstanceDeactivateRegion(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=0
 *   @0x10cf9c ldr r1, [pc, #0x4ec]
 *   @0x10cfa0 ldr r0, [pc, #0x4ec]
 *   @0x10cfa4 mov r2, #0
 *   @0x10cfa8 mov r3, r2
 *   @0x10cfac ldr r1, [r4, r1]
 *   @0x10cfb0 add r0, pc, r0
 *   @0x10cfb4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #70 instance_activate_all → F_InstanceActivateAll(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x10cfb8 ldr r1, [pc, #0x4d8]
 *   @0x10cfbc ldr r0, [pc, #0x4d8]
 *   @0x10cfc0 mov r2, #1
 *   @0x10cfc4 mov r3, #0
 *   @0x10cfc8 ldr r1, [r4, r1]
 *   @0x10cfcc add r0, pc, r0
 *   @0x10cfd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #71 instance_activate_object → F_InstanceActivateObject(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x10cfd4 ldr r1, [pc, #0x4c4]
 *   @0x10cfd8 ldr r0, [pc, #0x4c4]
 *   @0x10cfdc mov r2, #5
 *   @0x10cfe0 mov r3, #0
 *   @0x10cfe4 ldr r1, [r4, r1]
 *   @0x10cfe8 add r0, pc, r0
 *   @0x10cfec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #72 instance_activate_region → F_InstanceActivateRegion(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0x10cff0 ldr r1, [pc, #0x4b0]
 *   @0x10cff4 ldr r0, [pc, #0x4b0]
 *   @0x10cff8 mov r2, #5
 *   @0x10cffc mov r3, #0
 *   @0x10d000 ldr r1, [r4, r1]
 *   @0x10d004 add r0, pc, r0
 *   @0x10d008 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #73 instance_deactivate_region_special → F_InstanceDeactivateRegionSpecial(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=0
 *   @0x10d00c ldr r1, [pc, #0x49c]
 *   @0x10d010 ldr r0, [pc, #0x49c]
 *   @0x10d014 mov r2, #1
 *   @0x10d018 mov r3, #0
 *   @0x10d01c ldr r1, [r4, r1]
 *   @0x10d020 add r0, pc, r0
 *   @0x10d024 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #74 room_goto → F_RoomGoto(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x10d028 ldr r1, [pc, #0x488]
 *   @0x10d02c ldr r0, [pc, #0x488]
 *   @0x10d030 mov r2, #0
 *   @0x10d034 mov r3, r2
 *   @0x10d038 ldr r1, [r4, r1]
 *   @0x10d03c add r0, pc, r0
 *   @0x10d040 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #75 room_goto_previous → F_RoomGotoPrevious(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x10d044 ldr r1, [pc, #0x474]
 *   @0x10d048 ldr r0, [pc, #0x474]
 *   @0x10d04c mov r2, #0
 *   @0x10d050 mov r3, r2
 *   @0x10d054 ldr r1, [r4, r1]
 *   @0x10d058 add r0, pc, r0
 *   @0x10d05c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #76 room_goto_next → F_RoomGotoNext(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x10d060 ldr r1, [pc, #0x460]
 *   @0x10d064 ldr r0, [pc, #0x460]
 *   @0x10d068 mov r2, #1
 *   @0x10d06c mov r3, #0
 *   @0x10d070 ldr r1, [r4, r1]
 *   @0x10d074 add r0, pc, r0
 *   @0x10d078 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #77 room_previous → F_RoomPrevious(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x10d07c ldr r1, [pc, #0x44c]
 *   @0x10d080 ldr r0, [pc, #0x44c]
 *   @0x10d084 mov r2, #1
 *   @0x10d088 mov r3, #0
 *   @0x10d08c ldr r1, [r4, r1]
 *   @0x10d090 add r0, pc, r0
 *   @0x10d094 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #78 room_next → F_RoomNext(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x10d098 ldr r1, [pc, #0x438]
 *   @0x10d09c ldr r0, [pc, #0x438]
 *   @0x10d0a0 mov r2, #0
 *   @0x10d0a4 mov r3, r2
 *   @0x10d0a8 ldr r1, [r4, r1]
 *   @0x10d0ac add r0, pc, r0
 *   @0x10d0b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #79 room_restart → F_RoomRestart(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x10d0b4 ldr r1, [pc, #0x424]
 *   @0x10d0b8 ldr r0, [pc, #0x424]
 *   @0x10d0bc mov r2, #0
 *   @0x10d0c0 mov r3, r2
 *   @0x10d0c4 ldr r1, [r4, r1]
 *   @0x10d0c8 add r0, pc, r0
 *   @0x10d0cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #80 game_end → F_GameEnd(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x10d0d0 ldr r1, [pc, #0x410]
 *   @0x10d0d4 ldr r0, [pc, #0x410]
 *   @0x10d0d8 mov r2, #0
 *   @0x10d0dc mov r3, r2
 *   @0x10d0e0 ldr r1, [r4, r1]
 *   @0x10d0e4 add r0, pc, r0
 *   @0x10d0e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #81 game_restart → F_GameRestart(RValue&, CInstance*, CInstance*, int, RValue*) argc=0 flag=0
 *   @0x10d0ec ldr r1, [pc, #0x3fc]
 *   @0x10d0f0 ldr r0, [pc, #0x3fc]
 *   @0x10d0f4 mov r2, #1
 *   @0x10d0f8 mov r3, #0
 *   @0x10d0fc ldr r1, [r4, r1]
 *   @0x10d100 add r0, pc, r0
 *   @0x10d104 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #82 game_load → F_GameLoad(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x10d108 ldr r1, [pc, #0x3e8]
 *   @0x10d10c ldr r0, [pc, #0x3e8]
 *   @0x10d110 mov r2, #1
 *   @0x10d114 mov r3, #0
 *   @0x10d118 ldr r1, [r4, r1]
 *   @0x10d11c add r0, pc, r0
 *   @0x10d120 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #83 game_save → F_GameSave(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x10d124 ldr r1, [pc, #0x3d4]
 *   @0x10d128 ldr r0, [pc, #0x3d4]
 *   @0x10d12c mov r2, #1
 *   @0x10d130 mov r3, #0
 *   @0x10d134 ldr r1, [r4, r1]
 *   @0x10d138 add r0, pc, r0
 *   @0x10d13c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #84 game_save_buffer → F_GameSaveBuffer(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x10d140 ldr r1, [pc, #0x3c0]
 *   @0x10d144 ldr r0, [pc, #0x3c0]
 *   @0x10d148 mov r2, #1
 *   @0x10d14c mov r3, #0
 *   @0x10d150 ldr r1, [r4, r1]
 *   @0x10d154 add r0, pc, r0
 *   @0x10d158 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #85 game_load_buffer → F_GameLoadBuffer(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x10d15c ldr r1, [pc, #0x3ac]
 *   @0x10d160 ldr r0, [pc, #0x3ac]
 *   @0x10d164 mov r2, #2
 *   @0x10d168 mov r3, #1
 *   @0x10d16c ldr r1, [r4, r1]
 *   @0x10d170 add r0, pc, r0
 *   @0x10d174 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #86 transition_define → F_TransitionDefine(RValue&, CInstance*, CInstance*, int, RValue*) argc=2 flag=1
 *   @0x10d178 ldr r1, [pc, #0x398]
 *   @0x10d17c ldr r0, [pc, #0x398]
 *   @0x10d180 mov r2, #1
 *   @0x10d184 mov r3, r2
 *   @0x10d188 ldr r1, [r4, r1]
 *   @0x10d18c add r0, pc, r0
 *   @0x10d190 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #87 transition_exists → F_TransitionExists(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=1
 *   @0x10d194 ldr r1, [pc, #0x384]
 *   @0x10d198 ldr r0, [pc, #0x384]
 *   @0x10d19c mov r2, #1
 *   @0x10d1a0 mov r3, #0
 *   @0x10d1a4 ldr r1, [r4, r1]
 *   @0x10d1a8 add r0, pc, r0
 *   @0x10d1ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #88 sleep → F_Sleep(RValue&, CInstance*, CInstance*, int, RValue*) argc=1 flag=0
 *   @0x10d1b0 ldr r1, [pc, #0x370]
 *   @0x10d1b4 ldr r0, [pc, #0x370]
 *   @0x10d1b8 mov r2, #6
 *   @0x10d1bc mov r3, #1
 *   @0x10d1c0 ldr r1, [r4, r1]
 *   @0x10d1c4 add r0, pc, r0
 *   @0x10d1c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #89 point_in_rectangle → F_Point_In_Rectangle(RValue&, CInstance*, CInstance*, int, RValue*) argc=6 flag=1
 *   @0x10d1cc ldr r1, [pc, #0x35c]
 *   @0x10d1d0 ldr r0, [pc, #0x35c]
 *   @0x10d1d4 mov r2, #8
 *   @0x10d1d8 mov r3, #1
 *   @0x10d1dc ldr r1, [r4, r1]
 *   @0x10d1e0 add r0, pc, r0
 *   @0x10d1e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #90 point_in_triangle → F_Point_In_Triangle(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x10d1e8 ldr r1, [pc, #0x348]
 *   @0x10d1ec ldr r0, [pc, #0x348]
 *   @0x10d1f0 mov r2, #5
 *   @0x10d1f4 mov r3, #1
 *   @0x10d1f8 ldr r1, [r4, r1]
 *   @0x10d1fc add r0, pc, r0
 *   @0x10d200 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #91 point_in_circle → F_Point_In_Circle(RValue&, CInstance*, CInstance*, int, RValue*) argc=5 flag=1
 *   @0x10d204 ldr r1, [pc, #0x334]
 *   @0x10d208 ldr r0, [pc, #0x334]
 *   @0x10d20c mov r2, #8
 *   @0x10d210 mov r3, #1
 *   @0x10d214 ldr r1, [r4, r1]
 *   @0x10d218 add r0, pc, r0
 *   @0x10d21c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #92 rectangle_in_rectangle → F_Rectangle_In_Rectangle(RValue&, CInstance*, CInstance*, int, RValue*) argc=8 flag=1
 *   @0x10d220 ldr r1, [pc, #0x320]
 *   @0x10d224 ldr r0, [pc, #0x320]
 *   @0x10d228 mov r2, #10
 *   @0x10d22c mov r3, #1
 *   @0x10d230 ldr r1, [r4, r1]
 *   @0x10d234 add r0, pc, r0
 *   @0x10d238 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #93 rectangle_in_triangle → F_Rectangle_In_Triangle(RValue&, CInstance*, CInstance*, int, RValue*) argc=10 flag=1
 *   @0x10d23c ldr r1, [pc, #0x30c]
 *   @0x10d240 ldr r0, [pc, #0x30c]
 *   @0x10d244 mov r2, #7
 *   @0x10d248 mov r3, #1
 *   @0x10d24c ldr r1, [r4, r1]
 *   @0x10d250 add r0, pc, r0
 *   @0x10d254 pop {r4, r5, r6, lr}
 *   @0x10d258 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>   —— 注册 #94 rectangle_in_circle → F_Rectangle_In_Circle(RValue&, CInstance*, CInstance*, int, RValue*) argc=7 flag=1
 *   @0x10d25c eoreq r5, lr, r4, ror #8
 *   @0x10d260 .word 0xffffc478
 *   @0x10d264 eoreq r11, r2, r0, lsr pc
 *   @0x10d268 .word 0xffffc47c
 *   @0x10d26c eoreq r11, r2, r0, lsr #30
 *   @0x10d270 .word 0xffffc480
 *   @0x10d274 eoreq r11, r2, r0, lsl pc
 *   @0x10d278 .word 0xffffc484
 *   @0x10d27c eoreq r11, r2, r0, lsl #30
 *   @0x10d280 .word 0xffffc488
 *   @0x10d284 .word 0x0022bef4
 *   @0x10d288 .word 0xffffc48c
 *   @0x10d28c eoreq r11, r2, r8, ror #29
 *   @0x10d290 .word 0xffffc490
 *   @0x10d294 .word 0x0022bed8
 *   @0x10d298 .word 0xffffc494
 *   @0x10d29c .word 0x0022bed0
 *   @0x10d2a0 .word 0xffffc498
 *   @0x10d2a4 eoreq r11, r2, r4, asr #29
 *   @0x10d2a8 .word 0xffffc49c
 *   @0x10d2ac .word 0x0022bebc
 *   @0x10d2b0 .word 0xffffc4a0
 *   @0x10d2b4 .word 0x0022beb4
 *   @0x10d2b8 .word 0xffffc4a4
 *   @0x10d2bc eoreq r11, r2, r12, lsr #29
 *   @0x10d2c0 .word 0xffffc4a8
 *   @0x10d2c4 eoreq r11, r2, r0, lsr #29
 *   @0x10d2c8 mlaeq r2, r4, lr, r11
 *   @0x10d2cc .word 0xffffc4ac
 *   @0x10d2d0 eoreq r11, r2, r12, lsl #29
 *   @0x10d2d4 .word 0xffffc4b0
 *   @0x10d2d8 eoreq r11, r2, r0, lsl #29
 *   @0x10d2dc .word 0xffffc4b4
 *   @0x10d2e0 eoreq r11, r2, r0, ror lr
 *   @0x10d2e4 .word 0xffffc4b8
 *   @0x10d2e8 eoreq r11, r2, r0, ror #28
 *   @0x10d2ec .word 0xffffc4bc
 *   @0x10d2f0 eoreq r11, r2, r0, asr lr
 *   @0x10d2f4 .word 0xffffc4c0
 *   @0x10d2f8 eoreq r11, r2, r8, asr #28
 *   @0x10d2fc .word 0xffffc4c4
 *   @0x10d300 eoreq r11, r2, r0, asr #28
 *   @0x10d304 .word 0xffffc4c8
 *   @0x10d308 eoreq r11, r2, r0, lsr lr
 *   @0x10d30c .word 0xffffc4cc
 *   @0x10d310 eoreq r11, r2, r0, lsr #28
 *   @0x10d314 .word 0xffffc4d0
 *   @0x10d318 eoreq r11, r2, r4, lsl lr
 *   @0x10d31c .word 0xffffc4d4
 *   @0x10d320 eoreq r11, r2, r8, lsl #28
 *   @0x10d324 .word 0xffffc4d8
 *   @0x10d328 eoreq r11, r2, r4, lsl #28
 *   @0x10d32c .word 0xffffc4dc
 *   @0x10d330 eoreq r11, r2, r0, lsl #28
 *   @0x10d334 .word 0xffffc4e0
 *   @0x10d338 .word 0x0022bdfc
 *   @0x10d33c .word 0xffffc4e4
 *   @0x10d340 .word 0x0022bdf4
 *   @0x10d344 .word 0xffffc4e8
 *   @0x10d348 eoreq r11, r2, r12, ror #27
 *   @0x10d34c .word 0xffffc4ec
 *   @0x10d350 eoreq r11, r2, r12, ror #27
 *   @0x10d354 .word 0xffffc4f0
 *   @0x10d358 eoreq r11, r2, r12, ror #27
 *   @0x10d35c .word 0xffffc4f4
 *   @0x10d360 eoreq r11, r2, r0, ror #27
 *   @0x10d364 .word 0xffffc4f8
 *   @0x10d368 .word 0x0022bdd4
 *   @0x10d36c .word 0xffffc4fc
 *   @0x10d370 eoreq r11, r2, r12, asr #27
 *   @0x10d374 .word 0xffffc500
 *   @0x10d378 eoreq r11, r2, r4, asr #27
 *   @0x10d37c .word 0xffffc504
 *   @0x10d380 eoreq r11, r2, r0, asr #27
 *   @0x10d384 .word 0xffffc508
 *   @0x10d388 .word 0x0022bdb8
 *   @0x10d38c .word 0xffffc50c
 *   @0x10d390 .word 0x0022bdb0
 *   @0x10d394 .word 0xffffc510
 *   @0x10d398 eoreq r11, r2, r12, lsr #27
 *   @0x10d39c .word 0xffffc514
 *   @0x10d3a0 eoreq r11, r2, r8, lsr #27
 *   @0x10d3a4 .word 0xffffc518
 *   @0x10d3a8 mlaeq r2, r12, sp, r11
 *   @0x10d3ac .word 0xffffc51c
 *   @0x10d3b0 mlaeq r2, r0, sp, r11
 *   @0x10d3b4 .word 0xffffc520
 *   @0x10d3b8 eoreq r11, r2, r8, lsl #27
 *   @0x10d3bc .word 0xffffc524
 *   @0x10d3c0 eoreq r11, r2, r12, ror sp
 *   @0x10d3c4 .word 0xffffc528
 *   @0x10d3c8 eoreq r11, r2, r4, ror sp
 *   @0x10d3cc .word 0xffffc52c
 *   @0x10d3d0 eoreq r11, r2, r12, ror #26
 *   @0x10d3d4 .word 0xffffc530
 *   @0x10d3d8 eoreq r11, r2, r4, ror #26
 *   @0x10d3dc .word 0xffffc534
 *   @0x10d3e0 eoreq r11, r2, r8, asr sp
 *   @0x10d3e4 .word 0xffffc538
 *   @0x10d3e8 eoreq r11, r2, r12, asr #26
 *   @0x10d3ec .word 0xffffc53c
 *   @0x10d3f0 eoreq r11, r2, r0, asr #26
 *   @0x10d3f4 .word 0xffffc540
 *   @0x10d3f8 eoreq r11, r2, r4, lsr sp
 *   @0x10d3fc .word 0xffffc544
 *   @0x10d400 eoreq r11, r2, r12, lsr #26
 *   @0x10d404 .word 0xffffc548
 *   @0x10d408 eoreq r11, r2, r4, lsr #26
 *   @0x10d40c .word 0xffffc54c
 *   @0x10d410 eoreq r11, r2, r12, lsl sp
 *   @0x10d414 .word 0xffffbcd4
 *   @0x10d418 .word 0xffffc550
 *   @0x10d41c .word 0x0022bcfc
 *   @0x10d420 .word 0xffffc554
 *   @0x10d424 .word 0x0022bcf0
 *   @0x10d428 .word 0xffffc558
 *   @0x10d42c eoreq r11, r2, r12, ror #25
 *   @0x10d430 .word 0xffffc55c
 *   @0x10d434 eoreq r11, r2, r8, ror #25
 *   @0x10d438 .word 0xffffc560
 *   @0x10d43c .word 0x0022bcdc
 *   @0x10d440 .word 0xffffc564
 *   @0x10d444 .word 0x0022bcd0
 *   @0x10d448 .word 0xffffc568
 *   @0x10d44c eoreq r11, r2, r8, asr #25
 *   @0x10d450 .word 0xffffc56c
 *   @0x10d454 .word 0x0022bcbc
 *   @0x10d458 .word 0xffffc570
 *   @0x10d45c .word 0x0022bcb0
 *   @0x10d460 .word 0xffffc574
 *   @0x10d464 eoreq r11, r2, r8, lsr #25
 *   @0x10d468 .word 0xffffc578
 *   @0x10d46c eoreq r11, r2, r0, lsr #25
 *   @0x10d470 .word 0xffffc57c
 *   @0x10d474 mlaeq r2, r4, r12, r11
 *   @0x10d478 .word 0xffffc580
 *   @0x10d47c eoreq r11, r2, r8, lsl #25
 *   @0x10d480 .word 0xffffc584
 *   @0x10d484 eoreq r11, r2, r4, lsl #25
 *   @0x10d488 .word 0xffffc588
 *   @0x10d48c eoreq r11, r2, r4, lsl #25
 *   @0x10d490 .word 0xffffc58c
 *   @0x10d494 eoreq r11, r2, r4, lsl #25
 *   @0x10d498 .word 0xffffc590
 *   @0x10d49c eoreq r11, r2, r0, lsl #25
 *   @0x10d4a0 .word 0xffffc594
 *   @0x10d4a4 eoreq r11, r2, r0, lsl #25
 *   @0x10d4a8 .word 0xffffc598
 *   @0x10d4ac eoreq r11, r2, r0, lsl #25
 *   @0x10d4b0 .word 0xffffc59c
 *   @0x10d4b4 eoreq r11, r2, r8, lsl #25
 *   @0x10d4b8 .word 0xffffc5a0
 *   @0x10d4bc eoreq r11, r2, r8, ror r12
 *   @0x10d4c0 .word 0xffffc5a4
 *   @0x10d4c4 eoreq r11, r2, r0, ror r12
 *   @0x10d4c8 .word 0xffffc5a8
 *   @0x10d4cc eoreq r11, r2, r4, ror #24
 *   @0x10d4d0 .word 0xffffc5ac
 *   @0x10d4d4 eoreq r11, r2, r8, asr r12
 *   @0x10d4d8 .word 0xffffc5b0
 *   @0x10d4dc eoreq r11, r2, r8, asr #24
 *   @0x10d4e0 .word 0xffffc5b4
 *   @0x10d4e4 eoreq r11, r2, r12, lsr r12
 *   @0x10d4e8 .word 0xffffc5b8
 *   @0x10d4ec eoreq r11, r2, r12, lsr #24
 *   @0x10d4f0 .word 0xffffc5bc
 *   @0x10d4f4 eoreq r11, r2, r0, lsr #24
 *   @0x10d4f8 .word 0xffffc5c0
 *   @0x10d4fc eoreq r11, r2, r0, lsl r12
 *   @0x10d500 .word 0xffffc5c4
 *   @0x10d504 eoreq r11, r2, r0, lsl #24
 *   @0x10d508 .word 0xffffc5c8
 *   @0x10d50c .word 0x0022bbf8
 *   @0x10d510 .word 0xffffc5cc
 *   @0x10d514 .word 0x0022bbf0
 *   @0x10d518 .word 0xffffc5d0
 *   @0x10d51c eoreq r11, r2, r8, ror #23
 *   @0x10d520 .word 0xffffc5d4
 *   @0x10d524 eoreq r11, r2, r0, ror #23
 *   @0x10d528 .word 0xffffc5d8
 *   @0x10d52c eoreq r11, r2, r12, asr #23
 *   @0x10d530 .word 0xffffc5dc
 *   @0x10d534 eoreq r11, r2, r4, asr #23
 *   @0x10d538 .word 0xffffc5e0
 *   @0x10d53c .word 0x0022bbbc
 *   @0x10d540 .word 0xffffc5e4
 *   @0x10d544 .word 0x0022bbb0
 *   @0x10d548 .word 0xffffc5e8
 *   @0x10d54c eoreq r11, r2, r12, lsr #23
 *   @0x10d550 .word 0xffffc5ec
 *   @0x10d554 eoreq r11, r2, r8, lsr #23
 */
