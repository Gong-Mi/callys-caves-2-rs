/* cally 逆向卡：Builtins_AudioPart（原版 libyoyo.so，armv7）—— 音频 3 个 + 粒子类型 7 个 + 粒子发射 1 个
 * 节: 11 个 @func 小节，顺序 = audio_play_sound / audio_sound_gain / audio_is_playing /
 *     part_type_orientation / part_type_direction / part_type_size / part_type_speed /
 *     part_type_color2 / part_type_gravity / part_type_life / part_particles_create
 *     （= 索引文件的段落顺序。注意不是地址序：3 个音频段落在 0x134xxx/0x135xxx，
 *      8 个粒子段落在 0x129xxx；索引把同族收在一起，地址是乱的）
 * 索引: asm/index-builtins_audio_part_all.tsv —— 278 条，11 段互不连续的区间，一段一个函数
 *   0x134b5c..0x134be4   35 条  F_AudioPlaySound            size 140  (池 0x134be4, 1 字)
 *   0x1351b8..0x135210   23 条  F_AudioSoundGain             size  92  (池 0x135210, 1 字)
 *   0x134e84..0x134ecc   19 条  F_AudioIsPlaying             size  76  (池 0x134ecc, 1 字)
 *   0x1292f0..0x129378   35 条  F_PartTypeOrientation        size 140  (无池)
 *   0x129280..0x1292ec   28 条  F_PartTypeDirection          size 112  (无池)
 *   0x129080..0x1290ec   28 条  F_PartTypeSize               size 112  (无池)
 *   0x129210..0x12927c   28 条  F_PartTypeSpeed              size 112  (无池)
 *   0x129580..0x1295c4   18 条  F_PartTypeColor2             size  72  (无池)
 *   0x12937c..0x1293c0   18 条  F_PartTypeGravity            size  72  (无池)
 *   0x129138..0x12917c   18 条  F_PartTypeLife               size  72  (无池)
 *   0x129aac..0x129b18   28 条  F_PartParticlesCreate        size 112  (无池)
 * 级别: 正文（11 个函数的形参落位、开关门、返回值写槽、尾跳目标、失败分支全部逐条落锚；
 *       被调 helper 的内部按节标注边界并给出实测字段偏移，凡未展开者列入 open。
 *       粒子描述符的字段表 = 「7 个 setter 写了哪些偏移」+「Clear 的默认值」两处独立落锚，
 *       不是按 GML 文档抄的；GML 形参名 ↔ 字段语义的对应处标 inferred）
 * 符号（全部取到 .dynsym 完整签名）:
 *   _Z16F_AudioPlaySoundR6RValueP9CInstanceS2_iPS_     0x134b5c
 *   _Z16F_AudioSoundGainR6RValueP9CInstanceS2_iPS_     0x1351b8
 *   _Z16F_AudioIsPlayingR6RValueP9CInstanceS2_iPS_     0x134e84
 *   _Z21F_PartTypeOrientationR6RValueP9CInstanceS2_iPS_ 0x1292f0
 *   _Z19F_PartTypeDirectionR6RValueP9CInstanceS2_iPS_  0x129280
 *   _Z14F_PartTypeSizeR6RValueP9CInstanceS2_iPS_       0x129080
 *   _Z15F_PartTypeSpeedR6RValueP9CInstanceS2_iPS_      0x129210
 *   _Z16F_PartTypeColor2R6RValueP9CInstanceS2_iPS_     0x129580
 *   _Z17F_PartTypeGravityR6RValueP9CInstanceS2_iPS_    0x12937c
 *   _Z14F_PartTypeLifeR6RValueP9CInstanceS2_iPS_       0x129138
 *   _Z21F_PartParticlesCreateR6RValueP9CInstanceS2_iPS_ 0x129aac
 * 形参约定（11 个一致）: r0 = RValue& ret, r1 = self, r2 = other, r3 = int argc,
 *   入口 [sp+0] = RValue* args。**r3(argc) 一个都没读**（3 个音频函数首条实质指令即 ldr 覆写 r3；
 *   8 个粒子函数根本不碰 r3），缺参不由内建兜底。
 * GOT 基址 0x3f1c58（全部 pc 相对池字 + add 得到，11 个函数里有 3 个用到池）。
 *
 * ══ 重点 1：音频「两套后端」的选择门（本卡新增，四条独立链全部落锚）═══════════════════
 *   .bss 里的音频全局块（.bss 覆盖 0x479a90..0x7579c8，这些字节出厂即 0）:
 *     0x755310  SoundHardware*   —— Audio_Init 0x2166d8 第一条 str 写入
 *     0x755314  u8  后端选择     —— 0 = 旧 Sound_（SND_/CSound/libopenal-WAV），非 0 = Audio_（CNoise）
 *     0x755318  int* 自增计数器  —— Audio_PlaySound 取号写进 CNoise+0x14
 *     0x75531c  ALuint* → 源名数组（alSource* 的第一个参数从这里取）
 *     0x755324  CAudioGroupMan*
 *     0x75530c  int  已加载音源数（按两处比较读作此义，inferred 名）—— **id 空间的分界**（见下）
 *     0x75529c  CNoise 池 { +0x38 int count, +0x3c CNoise** items }（三处 add 都落到 0x75529c）
 *     0x755358..0x755363  一串 u8 「禁用」开关（.bss，出厂 0），libyoyo 里全是只读守卫
 *
 *   (a) 后端门 = 0x755314：**同一族 GML 名有两套实现，开关决定哪套活着**
 *       Audio_Model() 0x216998（5 条 = 4 指令 + 1 池字: ldr r3,[pc,#8] / ldr r3,[pc,r3] / ldrb r0,[r3] / bx lr）
 *         ⇒ 该字节就是「当前音频模型」的读口，没有任何分支。
 *       F_SoundExists 0x12cba4：0x755314 != 0 → Audio_Exists(id)（0x217260）；== 0 → Sound_Exists(id)（0x21fbd0）
 *       F_SoundGetName 0x12cbfc：0x755314 != 0 → Audio_GetName；== 0 → Sound_Name
 *       F_SoundVolume 0x133b48 / F_SoundLoop 0x13655c / F_SoundIsPlaying 0x1364d4 / F_SoundPlay→YYGML_sound_play：
 *         0x755314 != 0 → 直接返回（YYGML_sound_play 0x1365f0 的门序同 F_SoundLoop：0x755314 然后 0x755363）
 *         ⇒ sound_play / sound_loop / sound_volume / sound_isplaying 这几个 GML 名是**旧后端专用**
 *       Audio 侧反过来：Audio_PlaySound 0x21b614 / Audio_SoundGain 0x21792c / Audio_SoundIsPlaying 0x2171a4：
 *         0x755314 == 0 → 直接返回（play 返回 -1、sound_gain 无返回、sound_is_playing 返回 0）
 *       ⇒ 0x755314 = 0 时 audio_* 全哑、sound_* 走旧后端（仍受 0x755363 闸）；非 0 时反过来。LoadGameData 用同一字节选
 *         Sound_Load / Audio_Load（既有 LoadGameData 卡 0x1de3e8 / 0x1de500 / 0x1de568 三处）。
 *   (b) 总开关 = 0x755363：**两族共用的一道闸**
 *       3 个 F_Audio* 函数入口各一条 ldrb + cmp + (bne/popne)：非 0 ⇒ 整函数空转
 *         （F_AudioPlaySound 0x134b70/0x134b78/0x134b7c、F_AudioSoundGain 0x1351c8/0x1351cc/0x1351d0、
 *          F_AudioIsPlaying 0x134e94/0x134e98/0x134e9c）
 *       F_SoundLoop 0x136564..0x136588 连查两道：0x755314 然后 0x755363；
 *       F_SoundVolume 0x133b58..0x133b74 同样两道；F_SoundIsPlaying 0x1364e4..0x136500 两道。
 *       Sound_Tick 0x21f1c4 也先查它；CheckLicense 0x1d2764 也读它（设备/许可信息在两条路径间分支）。
 *       唯一的写者是 Audio_Init 0x2166f4/0x2166f8（mov r2,#0 + strb）—— 只会**清零**。
 *   (c) 谁写 0x755314：本卡没查到。做法：627,423 条指令全表的 1500 条
 *       「ldr rX,[pc,#imm] + ldr rX,[pc,rX]」间接取址逐条还原成 GOT 槽，命中两槽的 90 条全部
 *       逐条看过，只有 Audio_Init 的 strb（且是 0x755363）；改走「ldr rX,[rBase,rOff]」的
 *       Audio_Init 形态也扫过。⇒ 写成 open 1。
 *   (d) id 空间分界（两处独立落锚，互证）:
 *       Audio_SoundGain 0x2179a8：if (*(int*)0x75530c <= id) 走 noise 路，否则走 snd 路
 *       Audio_SoundIsPlaying 0x2171b8：同一个比较，>= 计数 → Audio_GetNoiseFromID(id)
 *       ⇒ id < 音源数 = 音源号（定义）；id >= 音源数 = **活动 CNoise 实例号**（play 的返回值）
 *
 * ══ 重点 2：粒子类型描述符（0xA4 = 164 字节，本卡新增）══════════════════════════════
 *   ParticleType_Create 0x1a3068：MemoryManager::Alloc(164, "Particle_Main.cpp"@0x34cf88, line 0x1b9, 1)（0x1a310c/0x1a3114）
 *     再调 ParticleType_Clear(index) 填默认值；注册表 = 0x542468 的 cARRAY {+0 count, +4 len（Create 里与 count 同步写）, +8 T** items}
 *   ParticleType_Exists 0x1a2e14：id<0 || id>=*(0x542468) || *(0x542470)[id]==0 → 0
 *   7 个 setter 的写点（float 用 vstr.f32，int 用 str，bool 用 strb）:
 *     +0x0c size_min  +0x10 size_max  +0x14 size_incr  +0x18 size_wiggle   (Size 0x1a322c)
 *     +0x1c scale_x   +0x20 scale_y                                        (Scale 0x1a3278)
 *     +0x24 life_min  +0x28 life_max                                       (Life 0x1a32b4)
 *     +0x2c death_type +0x30 death_number                                  (Death 0x1a332c, 写入序相反)
 *     +0x34 step_type  +0x38 step_number                                   (Step 0x1a32f0, 写入序相反)
 *     +0x3c speed_min +0x40 speed_max +0x44 speed_incr +0x48 speed_wiggle  (Speed 0x1a3368)
 *     +0x4c dir_min   +0x50 dir_max   +0x54 dir_incr   +0x58 dir_wiggle    (Direction 0x1a33b4)
 *     +0x5c grav_x    +0x60 grav_y                                         (Gravity 0x1a3454)
 *     +0x64 orient_min +0x68 orient_max +0x6c orient_incr +0x70 orient_wiggle (Orientation 0x1a3400)
 *     +0x74 orient_relative (bool)                                         (Orientation)
 *     +0x78 color_mode +0x7c color1 +0x80 color2 +0x84 color3               (Color1/2/3, mode 0/1/2)
 *     +0x94 alpha1 +0x98 alpha2 +0x9c alpha3                                (Alpha1/2/3; Alpha2 中间值=(a+b)*0.5)
 *     +0x00 sprite +0x04/+0x05/+0x06 三个 bool +0x08 shape                  (Sprite 0x1a31e0 / Shape 0x1a31a4)
 *     +0xa0 blend (bool)                                                    (Blend 0x1a373c)
 *   默认值（ParticleType_Clear 0x1a2f7c 逐条）:
 *     +0x00 = -1 (0xFFFFFFFF)      +0x04 = 1   +0x05/+0x06 = 0   +0x08 = 0
 *     +0x0c/+0x10 = 1.0f           +0x14/+0x18 = 0
 *     +0x1c/+0x20 = 1.0f           +0x24/+0x28 = 100 (int)       +0x2c/+0x30/+0x34/+0x38 = 0
 *     +0x3c..+0x44 = 0             +0x48 = 0                     +0x4c..+0x58 = 0
 *     +0x5c = 0                    +0x60 = 270.0f (0x43870000)   ← 唯一非平凡默认值
 *     +0x64..+0x70 = 0             +0x74 = 0 (byte)              +0x78 = 0
 *     +0x7c/+0x80/+0x84 = 0x00FFFFFF (白)                         +0x94/+0x98/+0x9c = 1.0f
 *     Clear **没有**写 +0x88..+0x90 与 +0xa0 ⇒ 那两处只能靠 Alloc 的 4th 参数(=1，按语义读作清零)，
 *       +0xa0 的出厂值因此标 inferred 0。
 *   ⚠ 本卡纠正一个易错点：Size/Speed/Direction/Orientation 的**第 4 个 float 走栈**（不是寄存器），
 *      F_ 侧 str r0,[sp,#0x18]（Orientation 是 [sp]）+ 被调侧 vldr s15,[sp,#0x18] 两端互证。
 *
 * ══ 粒子系统与单个粒子（part_particles_create 的被调方，落锚在 11/11 节）═══════════════
 *   系统注册表 = 0x54245c（同型 cARRAY；ParticleSystem_Exists 0x1a3770 用 GOT 槽 0x3f07bc 取 count、0x3f07c0 取 items）；
 *   系统对象 ps: +0x00 capacity(int) +0x04 RParticle** items +0x08 count(int)
 *   单个粒子 = **64 字节**（0x1a3c30 mov r0,#64 → MemoryManager::Alloc(64, "Particle_Main.cpp"@0x34cf88, 0x586, 1)）
 *   扩容策略：capacity <= count 时 SetLength(&ps->items, (count+100)*4) 然后 capacity = count+100（+100，不是翻倍）
 *
 * ── open ─────────────────────────────────────────────────────────────
 *   1. 0x755314（后端选择）与 0x755363（总开关）在 libyoyo 的 627,423 条指令里**没有置 1 的写者**：
 *      只有 Audio_Init 把 0x755363 清零。两者都在 .bss ⇒ 纯 native 启动时都是 0
 *      （= 旧 Sound_ 后端，且总开关未拉下）。谁把它们打开（JNI? Java 侧? 另一个 .so?）本卡未证。
 *   2. 描述符 +0x88..+0x90（12 字节）与 +0xa0 之后（+0xa1..+0xa3）无 setter、Clear 也不写，语义未解。
 *   3. CNoise 的 +0x10（AL 源下标）由谁写：只证到 Audio_PlaySound 读它去索引 0x75531c 的源数组。
 *   4. +0x34 写的是 *(0x3f52d4)，+0x14 来自 *(0x755318) 指向的计数器 —— 是**两个**计数器，二者关系未证。
 *   5. Audio_SoundGain 的步长量化有两套节拍源（0x5428e8 分支：GetFPSE() vs *(*(0x54298c)+0xc)，空指针时取 33），
 *      哪一个在这台设备上生效未量。
 *   6. 音乐区间 [200000,299999] 的判据只证到「id-200000 <= 99999」，这个常量谁定义的未追。
 *   7. CreateParticle 0x1a2e5c 内部（描述符 → 粒子字段的拷贝）未展开。
 */

/* ══ 1/11  F_AudioPlaySound  0x134b5c  size 140  35 条  (池 0x134be4 一字)
 * @func 0x134b5c 0x134be8  size 140  35 条（34 条指令 + 1 个池字 0x134be4）
 * 符号 _Z16F_AudioPlaySoundR6RValueP9CInstanceS2_iPS_   GML 名 = .rodata 0x33f82c "audio_play_sound"
 * 参数: args = [sp+0x20]（0x134b74）
 *
 *   if (*(u8*)0x755363 != 0) goto epilogue;      // 0x134b70 ldrb r1,[r3]（GOT 0x3ef054 → 0x755363）
 *                                               // 0x134b78 cmp r1,#0 / 0x134b7c bne 0x134bdc
 *   ret.tag = 0;                                 // 0x134b80 str r1,[r0,#0xc]（r1 必定是 0）
 *   id   = YYGetInt32(args, 0);                  // 0x134b84..0x134b90
 *   gain = YYGetReal (args, 1);                  // 0x134b94..0x134ba0  ← 第二位是 double
 *   loop = YYGetInt32(args, 2);                  // 0x134ba8..0x134bac
 *   [sp] = loop;                                 // 0x134bb8  ← 第 3 个 int 走栈槽
 *   r = Audio_PlaySound(id, gain, loop);         // 0x134bc0 bl 0x21b5d8
 *   ret.data = (double)(int32)r;                 // 0x134bc4 vmov s15,r0 / 0x134bc8 vcvt.f64.s32
 *                                               // 0x134bd0 vmov r2,s14（d7 低字）/ 0x134bd4 mov r3,r1
 *                                               // 0x134bd8 stm r7,{r2,r3}（8 字节数据字，tag 已置 0）
 *
 * ABI 细节（两端互证，不是猜）:
 *   (int, double, int) 在 AAPCS 下 double 要偶数对齐 ⇒ r0=id、r2:r3=double、第 3 个 int 落到栈；
 *   F_ 侧 0x134bb0 mov r2,r4 / 0x134bb4 mov r3,r5 / 0x134bb8 str r0,[sp]；
 *   被调侧 0x21b690 ldr r2,[sp,#0x38] 读同一槽（0x38 = push 28 + vpush 8 + sub 20）。r1 是填充位。
 * 返回值: **有符号** int → real（0x134bc8 vcvt.f64.s32；对比 3/11 的 u32）。
 *   失败一律落到 0x21b7d4 的 mvn r0,#0 = -1（四条分支 0x21b604 / 0x21b618 / 0x21b63c / 0x21b670）。
 *
 * 被调边缘 Audio_PlaySound 0x21b5d8（744 B / 186 条，本卡只钉边界）:
 *   门① 0x21b5fc/0x21b600  0x755363 != 0 → -1
 *   门② 0x21b610/0x21b614  *(u8*)0x755314 == 0 → -1        ← 后端选择门
 *   snd = Audio_GetSound(id)（0x21b61c）；空 → 0x354034 "Error: no sound exists for soundid %d" → 返回 0
 *   CAudioGroupMan::IsGroupLoaded(*(0x755324), snd+0x4c)（0x21b628..0x21b634）；未加载 →
 *     0x35405c "%s: Audio Group %d is not loaded" → -1
 *   src = Audio_GetSoundSourceToPlay(id, (float)gain)（0x21b64c）
 *   id∈[200000,299999] 且 alGetSourcei(src, AL_SOURCE_STATE 0x1011)==AL_PLAYING 0x1012 → -1（不重启）
 *   CNoise 字段（r4 = noise）: +0x04 loop(>0→1/否则0) 0x21b6cc/0x21b6e8；+0x14 实例号
 *     *(0x755318)++ 0x21b6b0..0x21b6c0；+0x18 音源号 0x21b6ac；+0x1c (float)gain 0x21b6c8；
 *     +0x24 = 1.0f 0x21b6a8；+0x2c = 0 0x21b6b4；+0x34 = *(0x3f52d4) 0x21b6e0
 *   OpenAL: alSourcef(AL_MAX_DISTANCE 0x1023, *(0x3f52cc)) 0x21b6fc（该字按 f32 位型传，类型 inferred） /
 *           alSourcef(AL_GAIN 0x100a, snd+0x04) 0x21b710 /
 *           alSourcef(AL_PITCH 0x1003, snd+0x08) 0x21b724 /
 *           alSourcei(AL_LOOPING 0x202, 1) 0x21b738 /
 *           alSource3f(AL_POSITION 0x1004,0,0,0) 0x21b754 / alSource3f(AL_VELOCITY 0x1006,0,0,0) 0x21b770
 *   Audio_StartSoundNoise(snd, noise)（0x21b77c）；alGetError≠0 → 0x3540f8 "Error playing simple sound %d"
 *   成功返回 noise+0x14
 * 池字 0x134be4 = 0x002ba4e8：0x134b6c + 0x2ba4e8 = 0x3ef054（GOT 槽）→ 0x755363。
 *   ⚠ 门在 ret.tag=0 **之前**判 ⇒ 空转路上 ret 一个字节都不写（与 3/11 先写 tag 再判不同）。
 */

/* ---- 1/11 F_AudioPlaySound 代码 0x134b5c..0x134be0 ---- */
/* @0x134b5c ldr r3, [pc, #0x80] */
/* @0x134b60 push {r4, r5, r6, r7, r8, lr} */
/* @0x134b64 ldr r3, [pc, r3] */
/* @0x134b68 sub sp, sp, #8 */
/* @0x134b6c mov r7, r0 */
/* @0x134b70 ldrb r1, [r3] */
/* @0x134b74 ldr r6, [sp, #0x20] */
/* @0x134b78 cmp r1, #0 */
/* @0x134b7c bne 0x134bdc <_Z16F_AudioPlaySoundR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x134b80 str r1, [r0, #0xc] */
/* @0x134b84 mov r0, r6 */
/* @0x134b88 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134b8c mov r1, #1 */
/* @0x134b90 mov r8, r0 */
/* @0x134b94 mov r0, r6 */
/* @0x134b98 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x134b9c mov r4, r0 */
/* @0x134ba0 mov r5, r1 */
/* @0x134ba4 mov r0, r6 */
/* @0x134ba8 mov r1, #2 */
/* @0x134bac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134bb0 mov r2, r4 */
/* @0x134bb4 mov r3, r5 */
/* @0x134bb8 str r0, [sp] */
/* @0x134bbc mov r0, r8 */
/* @0x134bc0 bl 0x21b5d8 <_Z15Audio_PlaySoundidi> */
/* @0x134bc4 vmov s15, r0 */
/* @0x134bc8 vcvt.f64.s32 d7, s15 */
/* @0x134bcc vmov r0, r1, d7 */
/* @0x134bd0 vmov r2, s14 */
/* @0x134bd4 mov r3, r1 */
/* @0x134bd8 stm r7, {r2, r3} */
/* @0x134bdc add sp, sp, #8 */
/* @0x134be0 pop {r4, r5, r6, r7, r8, pc} */
/* ---- pool：1 字（0x3ef054 → 0x755363，与 1/11 同一道总开关） ---- */
/* @0x134be4 eoreq r10, r11, r8, ror #9 */

/* ══ 2/11  F_AudioSoundGain  0x1351b8  size 92  23 条  (池 0x135210 一字)
 * @func 0x1351b8 0x135214  size 92  23 条（22 条指令 + 1 个池字 0x135210）
 * 符号 _Z16F_AudioSoundGainR6RValueP9CInstanceS2_iPS_   GML 名 = 0x33fa20 "audio_sound_gain"
 * 参数: args = [sp+0x10]（0x1351c4，push 16 后第一层）
 *
 *   if (*(u8*)0x755363 != 0) return;             // 0x1351c8 ldrb r1,[r3]（GOT 0x3ef054 → 0x755363）
 *                                               // 0x1351cc cmp r1,#0 / 0x1351d0 popne
 *   id = YYGetInt32(args,0);                     // 0x1351d4..0x1351e0
 *   g  = YYGetFloat(args,1);                     // 0x1351e4..0x1351f0  ← **float**，不是 real
 *   t  = YYGetInt32(args,2);                     // 0x1351f4..0x1351f8
 *   Audio_SoundGain(id, g, t);                   // 0x13520c b 0x2178f0（帧已拆，纯尾跳）
 *
 * 返回值: 无 —— r0 入口未保存、全函数没有一条 st* 到 [r0] ⇒ audio_sound_gain 不产生返回值。
 *   （对照 1/11：play 写 tag+8 字节，3/11：is_playing 写 tag+双精度）
 * 门只有一道（0x755363）：0x755314 的那道在**被调方**里，所以本函数空转与否由总开关决定。
 *
 * 被调边缘 Audio_SoundGain 0x2178f0（400 B / 100 条）:
 *   门① 0x217910/0x217918  0x755363 != 0 → return
 *   门② 0x217924/0x21792c  0x755314 == 0 → return          ← 后端选择门
 *   门③ 0x21793c/0x217944  *(u8*)0x5428e8 != 0 → 0x217a44 CTimingSource::GetFPSE() 分支：
 *          step_ms = 1000 / (int)fps（0x217a50..0x217a58 → 0x217964）
 *       否则 p = *(0x54298c)（0x217948..0x217950）；p==0 → 除数取 33（0x217958 moveq r1,#33），
 *          否则除数 = *(int*)(p+0xc)（0x217960）；step_ms = max(1000/除数, 1)（0x217964..0x217974）
 *   steps = max( t / step_ms, 1 )（0x217978 __divsi3 / 0x217994..0x21799c 钳位）
 *   gain  = max(gain, 0.0f)（0x217984 vcmp.f32 s16,#0；0x2179a4 vmovmi.f32 s16,s15；
 *          s15 来自 0x217a60 池字 = 0x00000000 = 0.0f）
 *   if (*(int*)0x75530c <= id)                    // 0x2179a8 cmp r3,r5 / 0x2179b0 ble
 *        Audio_SetGainForNoise(Audio_GetNoiseFromID(id), gain, t)   // 0x217a24..0x217a40 尾跳
 *   else snd = Audio_GetSound(id)（0x2179b4）；snd==0 → return
 *        t == 0 : 若 snd+0x04 == gain 且 snd+0x20 == 0 → 什么都不做（0x2179cc..0x2179e0）
 *                 否则 snd+0x04 = gain、snd+0x20 = 0、setGainForSoundImmediate(id, gain)
 *                 （0x2179e4..0x217a00 尾跳）
 *        t != 0 : snd+0x20 = steps（0x217a08）、snd+0x1c = (gain - snd+0x04)/steps（0x217a04..0x217a18）
 *                 ⇒ 线性斜坡：每帧加 snd+0x1c、共 steps 帧
 *   snd 结构（本卡只证用到的那几个字）: +0x04 当前 gain(f32)  +0x08 pitch(f32)
 *     +0x1c 每步增量(f32)  +0x20 剩余步数(int)  +0x4c 所属 AudioGroup(int)
 * 池字 0x135210 = 0x002b9e8c：0x1351c8 + 0x2b9e8c = 0x3ef054 → 0x755363。
 */

/* ---- 2/11 F_AudioSoundGain 代码 0x1351b8..0x13520c ---- */
/* @0x1351b8 ldr r3, [pc, #0x50] */
/* @0x1351bc push {r4, r5, r6, lr} */
/* @0x1351c0 ldr r3, [pc, r3] */
/* @0x1351c4 ldr r4, [sp, #0x10] */
/* @0x1351c8 ldrb r1, [r3] */
/* @0x1351cc cmp r1, #0 */
/* @0x1351d0 popne {r4, r5, r6, pc} */
/* @0x1351d4 mov r0, r4 */
/* @0x1351d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1351dc mov r1, #1 */
/* @0x1351e0 mov r6, r0 */
/* @0x1351e4 mov r0, r4 */
/* @0x1351e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1351ec mov r1, #2 */
/* @0x1351f0 mov r5, r0 */
/* @0x1351f4 mov r0, r4 */
/* @0x1351f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1351fc mov r1, r5 */
/* @0x135200 mov r2, r0 */
/* @0x135204 mov r0, r6 */
/* @0x135208 pop {r4, r5, r6, lr} */
/* @0x13520c b 0x2178f0 <_Z15Audio_SoundGainifi> */
/* ---- pool：1 字（0x3ef054 → 0x755363，同上） ---- */
/* @0x135210 eoreq r9, r11, r12, lsl #29 */

/* ══ 3/11  F_AudioIsPlaying  0x134e84  size 76  19 条  (池 0x134ecc 一字)
 * @func 0x134e84 0x134ed0  size 76  19 条（18 条指令 + 1 个池字 0x134ecc）
 * 符号 _Z16F_AudioIsPlayingR6RValueP9CInstanceS2_iPS_   GML 名 = .rodata 0x33f8e0 "audio_is_playing"
 * 参数: args = [sp+0x8]（0x134ea4 用，push 8 后第一层）
 *
 *   if (*(u8*)0x755363 != 0) return;             // 0x134e9c popne（GOT 0x3ef054 → 0x755363）
 *   ret.tag = 0;                                 // 0x134ea0 str r1,[r0,#0xc]（r1 = 0）
 *   id = YYGetInt32(args,0);                     // 0x134ea4..0x134ea8
 *   b  = Audio_SoundIsPlaying(id);               // 0x134eac bl 0x21717c
 *   ret.data = (double)(uint32)b;                // 0x134eb4 vcvt.f64.**u32** / 0x134ec4 stm r4,{r2,r3}
 *
 * 返回值: real 0/1，**无符号**转换（对比 1/11 的 s32）。
 * 被调边缘 Audio_SoundIsPlaying 0x21717c（228 B / 57 条）:
 *   门① 0x217190  0x755363 != 0 → 0
 *   门② 0x2171a4  0x755314 == 0 → 0                    ← 后端选择门
 *   if (*(int*)0x75530c <= id)                          // 0x2171b8 cmp / 0x2171bc ble
 *        return Audio_NoiseIsPlaying(Audio_GetNoiseFromID(id))   // 0x21723c..0x217244 尾跳
 *   else 扫 CNoise 池（基址 0x75529c: +0x38 count / +0x3c items）:
 *        for (i=0; i<count; i++) { n = items[i];
 *          if (n && n+0x18 == id && Audio_NoiseIsPlaying(n)) return 1; }   // 0x2171ec..0x217230
 *        return 0;                                                          // 0x217234
 *   ⇒ 「音源号」的 is_playing 是**扫所有活动实例**，不是查 snd 表；这与 2/11 的 id 分界同源。
 * 池字 0x134ecc = 0x002ba1c0：0x134e94 + 0x2ba1c0 = 0x3ef054 → 0x755363。
 */

/* ---- 3/11 F_AudioIsPlaying 代码 0x134e84..0x134ec8 ---- */
/* @0x134e84 ldr r3, [pc, #0x40] */
/* @0x134e88 push {r4, lr} */
/* @0x134e8c ldr r3, [pc, r3] */
/* @0x134e90 mov r4, r0 */
/* @0x134e94 ldrb r1, [r3] */
/* @0x134e98 cmp r1, #0 */
/* @0x134e9c popne {r4, pc} */
/* @0x134ea0 str r1, [r0, #0xc] */
/* @0x134ea4 ldr r0, [sp, #0x8] */
/* @0x134ea8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x134eac bl 0x21717c <_Z20Audio_SoundIsPlayingi> */
/* @0x134eb0 vmov s15, r0 */
/* @0x134eb4 vcvt.f64.u32 d7, s15 */
/* @0x134eb8 vmov r0, r1, d7 */
/* @0x134ebc vmov r2, s14 */
/* @0x134ec0 mov r3, r1 */
/* @0x134ec4 stm r4, {r2, r3} */
/* @0x134ec8 pop {r4, pc} */
/* ---- pool：1 字（0x3ef054 → 0x755363，同上） ---- */
/* @0x134ecc eoreq r10, r11, r0, asr #3 */

/* ══ 4/11  F_PartTypeOrientation  0x1292f0  size 140  35 条  (无池)
 * @func 0x1292f0 0x12938c  size 156  39 条（全是指令，池在别处：本函数没用池）
 * 符号 _Z21F_PartTypeOrientationR6RValueP9CInstanceS2_iPS_   GML: part_type_orientation(ind,omin,omax,oincr,owiggle,rel)   名串 .rodata 0x33cfe8
 * 参数: args = [sp+0x28]（0x1292fc：push 28 + sub 12）
 *
 *   ind = YYGetInt32(args,0);                    // 0x129300..0x129304 → r5
 *   a   = YYGetFloat(args,1);                    // 0x129310..0x129314 → r8
 *   b   = YYGetFloat(args,2);                    // 0x129320..0x129324 → r7
 *   c   = YYGetFloat(args,3);                    // 0x129330..0x129334 → r6
 *   d   = YYGetFloat(args,4);                    // 0x129340..0x129344 → r9
 *   rel = YYGetBool (args,5);                    // 0x129350..0x129354 → r0
 *   [sp]   = d;                                  // 0x129358
 *   [sp+4] = rel;                                // 0x129368
 *   r0=ind, r1=a, r2=b, r3=c;  tail → 0x1a3400 ParticleType_Orientation(ind,a,b,c,d,rel)
 *                                                // 0x12935c..0x129370
 *
 * 语义（被调 ParticleType_Orientation 0x1a3400，84 B / 21 条，逐条）:
 *   if (!ParticleType_Exists(ind)) return;                       // 0x1a3418 bl 0x1a2e14 / 0x1a3420 popeq
 *   pt = (*(0x542470))[ind];                                    // 0x1a3424..0x1a3434
 *   pt+0x70 = d (vstr s15, [r0,#112])   // 0x1a3438  ← 第 4 个 float（从栈取: 0x1a3428 vldr s15,[sp,#24]）
 *   pt+0x64 = a (str r8)                // 0x1a343c
 *   pt+0x68 = b (str r7)                // 0x1a3440
 *   pt+0x6c = c (str r6)                // 0x1a3444
 *   pt+0x74 = rel (strb r4)             // 0x1a3448  ← bool 走**字节**，不是字
 * 返回值: 无（ret 指针 r0 入口即被 YYGetInt32 覆盖，全函数无 st 到 [r0]）。
 */

/* ---- 4/11 F_PartTypeOrientation 代码 0x1292f0..0x129378 ---- */
/* @0x1292f0 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1292f4 sub sp, sp, #12 */
/* @0x1292f8 mov r1, #0 */
/* @0x1292fc ldr r4, [sp, #0x28] */
/* @0x129300 mov r0, r4 */
/* @0x129304 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129308 mov r1, #1 */
/* @0x12930c mov r5, r0 */
/* @0x129310 mov r0, r4 */
/* @0x129314 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129318 mov r1, #2 */
/* @0x12931c mov r8, r0 */
/* @0x129320 mov r0, r4 */
/* @0x129324 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129328 mov r1, #3 */
/* @0x12932c mov r7, r0 */
/* @0x129330 mov r0, r4 */
/* @0x129334 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129338 mov r1, #4 */
/* @0x12933c mov r6, r0 */
/* @0x129340 mov r0, r4 */
/* @0x129344 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129348 mov r1, #5 */
/* @0x12934c mov r9, r0 */
/* @0x129350 mov r0, r4 */
/* @0x129354 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x129358 str r9, [sp] */
/* @0x12935c mov r1, r8 */
/* @0x129360 mov r2, r7 */
/* @0x129364 mov r3, r6 */
/* @0x129368 str r0, [sp, #0x4] */
/* @0x12936c mov r0, r5 */
/* @0x129370 bl 0x1a3400 <_Z24ParticleType_Orientationiffffb> */
/* @0x129374 add sp, sp, #12 */
/* @0x129378 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ══ 5/11  F_PartTypeDirection  0x129280  size 112  28 条  (无池)
 * @func 0x129280 0x129300  size 128  32 条
 * 符号 _Z19F_PartTypeDirectionR6RValueP9CInstanceS2_iPS_   GML: part_type_direction(ind,dmin,dmax,dincr,dwiggle)   名串 .rodata 0x33cfd4
 * 参数: args = [sp+0x18]（0x129288）
 *
 *   ind = YYGetInt32(args,0);   // 0x12928c..0x129290 → r5
 *   a   = YYGetFloat(args,1);   // 0x12929c..0x1292a0 → r8
 *   b   = YYGetFloat(args,2);   // 0x1292ac..0x1292b0 → r7
 *   c   = YYGetFloat(args,3);   // 0x1292bc..0x1292c0 → r6
 *   d   = YYGetFloat(args,4);   // 0x1292cc..0x1292d0 → r0
 *   [sp+0x18] = d;              // 0x1292e0（= 被调方入口 [sp]，即第 4 个 float 的栈槽）
 *   r0=ind,r1=a,r2=b,r3=c; pop; tail → 0x1a33b4 ParticleType_Direction
 *
 * 语义（被调 0x1a33b4，76 B / 19 条）:
 *   if (!Exists) return;                       // 0x1a33c8..0x1a33d0
 *   pt+0x58 = d (vstr, [r0,#88])               // 0x1a33e8  ← 0x1a33d8 vldr s15,[sp,#24]
 *   pt+0x4c = a / pt+0x50 = b / pt+0x54 = c     // 0x1a33ec / 0x1a33f0 / 0x1a33f4
 * 返回值: 无。
 */

/* ---- 5/11 F_PartTypeDirection 代码 0x129280..0x1292ec ---- */
/* @0x129280 push {r4, r5, r6, r7, r8, lr} */
/* @0x129284 mov r1, #0 */
/* @0x129288 ldr r4, [sp, #0x18] */
/* @0x12928c mov r0, r4 */
/* @0x129290 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129294 mov r1, #1 */
/* @0x129298 mov r5, r0 */
/* @0x12929c mov r0, r4 */
/* @0x1292a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1292a4 mov r1, #2 */
/* @0x1292a8 mov r8, r0 */
/* @0x1292ac mov r0, r4 */
/* @0x1292b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1292b4 mov r1, #3 */
/* @0x1292b8 mov r7, r0 */
/* @0x1292bc mov r0, r4 */
/* @0x1292c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1292c4 mov r1, #4 */
/* @0x1292c8 mov r6, r0 */
/* @0x1292cc mov r0, r4 */
/* @0x1292d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1292d4 mov r1, r8 */
/* @0x1292d8 mov r2, r7 */
/* @0x1292dc mov r3, r6 */
/* @0x1292e0 str r0, [sp, #0x18] */
/* @0x1292e4 mov r0, r5 */
/* @0x1292e8 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1292ec b 0x1a33b4 <_Z22ParticleType_Directioniffff> */

/* ══ 6/11  F_PartTypeSize  0x129080  size 112  28 条  (无池)
 * @func 0x129080 0x1290f0  size 112  28 条
 * 符号 _Z14F_PartTypeSizeR6RValueP9CInstanceS2_iPS_        GML: part_type_size(ind,smin,smax,sincr,swiggle)   名串 .rodata 0x33cf74
 * 参数: args = [sp+0x18]（0x129088）
 *
 *   ind = YYGetInt32(args,0);   // 0x12908c..0x129090 → r5
 *   a   = YYGetFloat(args,1);   // 0x12909c..0x1290a0 → r8
 *   b   = YYGetFloat(args,2);   // 0x1290ac..0x1290b0 → r7
 *   c   = YYGetFloat(args,3);   // 0x1290bc..0x1290c0 → r6
 *   d   = YYGetFloat(args,4);   // 0x1290cc..0x1290d0 → r0
 *   [sp+0x18] = d;              // 0x1290e0
 *   tail → 0x1a322c ParticleType_Size
 *
 * 语义（被调 0x1a322c，76 B / 19 条）:
 *   if (!Exists) return;                       // 0x1a3240..0x1a3248
 *   pt+0x18 = d (vstr, [r0,#24])               // 0x1a3260  ← 0x1a3250 vldr s15,[sp,#24]
 *   pt+0x0c = a / pt+0x10 = b / pt+0x14 = c     // 0x1a3264 / 0x1a3268 / 0x1a326c
 * 返回值: 无。
 */

/* ---- 6/11 F_PartTypeSize 代码 0x129080..0x1290ec ---- */
/* @0x129080 push {r4, r5, r6, r7, r8, lr} */
/* @0x129084 mov r1, #0 */
/* @0x129088 ldr r4, [sp, #0x18] */
/* @0x12908c mov r0, r4 */
/* @0x129090 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129094 mov r1, #1 */
/* @0x129098 mov r5, r0 */
/* @0x12909c mov r0, r4 */
/* @0x1290a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1290a4 mov r1, #2 */
/* @0x1290a8 mov r8, r0 */
/* @0x1290ac mov r0, r4 */
/* @0x1290b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1290b4 mov r1, #3 */
/* @0x1290b8 mov r7, r0 */
/* @0x1290bc mov r0, r4 */
/* @0x1290c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1290c4 mov r1, #4 */
/* @0x1290c8 mov r6, r0 */
/* @0x1290cc mov r0, r4 */
/* @0x1290d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1290d4 mov r1, r8 */
/* @0x1290d8 mov r2, r7 */
/* @0x1290dc mov r3, r6 */
/* @0x1290e0 str r0, [sp, #0x18] */
/* @0x1290e4 mov r0, r5 */
/* @0x1290e8 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1290ec b 0x1a322c <_Z17ParticleType_Sizeiffff> */

/* ══ 7/11  F_PartTypeSpeed  0x129210  size 112  28 条  (无池)
 * @func 0x129210 0x129290  size 128  32 条
 * 符号 _Z15F_PartTypeSpeedR6RValueP9CInstanceS2_iPS_       GML: part_type_speed(ind,smin,smax,sincr,swiggle)   名串 .rodata 0x33cfc4
 * 参数: args = [sp+0x18]（0x129218）
 *
 *   ind = YYGetInt32(args,0);   // 0x12921c..0x129220 → r5
 *   a   = YYGetFloat(args,1);   // 0x12922c..0x129230 → r8
 *   b   = YYGetFloat(args,2);   // 0x12923c..0x129240 → r7
 *   c   = YYGetFloat(args,3);   // 0x12924c..0x129250 → r6
 *   d   = YYGetFloat(args,4);   // 0x12925c..0x129260 → r0
 *   [sp+0x18] = d;              // 0x129270
 *   tail → 0x1a3368 ParticleType_Speed
 *
 * 语义（被调 0x1a3368，76 B / 19 条）:
 *   if (!Exists) return;                       // 0x1a337c..0x1a3384
 *   pt+0x48 = d (vstr, [r0,#72])               // 0x1a339c  ← 0x1a338c vldr s15,[sp,#24]
 *   pt+0x3c = a / pt+0x40 = b / pt+0x44 = c     // 0x1a33a0 / 0x1a33a4 / 0x1a33a8
 * 返回值: 无。
 */

/* ---- 7/11 F_PartTypeSpeed 代码 0x129210..0x12927c ---- */
/* @0x129210 push {r4, r5, r6, r7, r8, lr} */
/* @0x129214 mov r1, #0 */
/* @0x129218 ldr r4, [sp, #0x18] */
/* @0x12921c mov r0, r4 */
/* @0x129220 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129224 mov r1, #1 */
/* @0x129228 mov r5, r0 */
/* @0x12922c mov r0, r4 */
/* @0x129230 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129234 mov r1, #2 */
/* @0x129238 mov r8, r0 */
/* @0x12923c mov r0, r4 */
/* @0x129240 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129244 mov r1, #3 */
/* @0x129248 mov r7, r0 */
/* @0x12924c mov r0, r4 */
/* @0x129250 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129254 mov r1, #4 */
/* @0x129258 mov r6, r0 */
/* @0x12925c mov r0, r4 */
/* @0x129260 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129264 mov r1, r8 */
/* @0x129268 mov r2, r7 */
/* @0x12926c mov r3, r6 */
/* @0x129270 str r0, [sp, #0x18] */
/* @0x129274 mov r0, r5 */
/* @0x129278 pop {r4, r5, r6, r7, r8, lr} */
/* @0x12927c b 0x1a3368 <_Z18ParticleType_Speediffff> */

/* ══ 8/11  F_PartTypeColor2  0x129580  size 72  18 条  (无池)
 * @func 0x129580 0x1295c8  size 72  18 条
 * 符号 _Z16F_PartTypeColor2R6RValueP9CInstanceS2_iPS_      GML: part_type_color2(ind,c1,c2)   名串 .rodata 0x33d064（colour 别名 0x33d0f8）
 * 参数: args = [sp+0x10]（0x129588：push 16）
 *
 *   ind = YYGetInt32(args,0);   // 0x12958c..0x129590 → r6
 *   c1  = YYGetInt32(args,1);   // 0x12959c..0x1295a0 → r5
 *   c2  = YYGetInt32(args,2);   // 0x1295ac..0x1295b0 → r0
 *   r0=ind, r1=c1, r2=c2; pop; tail → 0x1a35d8 ParticleType_Color2
 *
 * 语义（被调 0x1a35d8，68 B / 17 条）:
 *   if (!Exists) return;                       // 0x1a35e8..0x1a35f0
 *   pt+0x7c = c1 (str r6) / pt+0x80 = c2 (str r5)   // 0x1a3608 / 0x1a360c
 *   pt+0x78 = 1 (str r2,#1)                          // 0x1a3610 ← **颜色模式 = 双色**
 *   ⇒ 颜色是 u32 打包值（不是 float），三个颜色槽 +0x7c/+0x80/+0x84 由 mode(+0x78) 选
 *     哪一种生效：Color1 写 +0x78=0，Color2 写 1，Color3 写 2 且填满三槽（0x1a359c/0x1a35d8/0x1a361c）。
 * 返回值: 无。
 */

/* ---- 8/11 F_PartTypeColor2 代码 0x129580..0x1295c4 ---- */
/* @0x129580 push {r4, r5, r6, lr} */
/* @0x129584 mov r1, #0 */
/* @0x129588 ldr r4, [sp, #0x10] */
/* @0x12958c mov r0, r4 */
/* @0x129590 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129594 mov r1, #1 */
/* @0x129598 mov r6, r0 */
/* @0x12959c mov r0, r4 */
/* @0x1295a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1295a4 mov r1, #2 */
/* @0x1295a8 mov r5, r0 */
/* @0x1295ac mov r0, r4 */
/* @0x1295b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1295b4 mov r1, r5 */
/* @0x1295b8 mov r2, r0 */
/* @0x1295bc mov r0, r6 */
/* @0x1295c0 pop {r4, r5, r6, lr} */
/* @0x1295c4 b 0x1a35d8 <_Z19ParticleType_Color2ijj> */

/* ══ 9/11  F_PartTypeGravity  0x12937c  size 72  18 条  (无池)
 * @func 0x12937c 0x1293c4  size 72  18 条
 * 符号 _Z17F_PartTypeGravityR6RValueP9CInstanceS2_iPS_     GML: part_type_gravity(ind,gx,gy)   名串 .rodata 0x33d000
 * 参数: args = [sp+0x10]（0x129384）
 *
 *   ind = YYGetInt32(args,0);   // 0x129388..0x12938c → r6
 *   gx  = YYGetFloat(args,1);   // 0x12939c..0x1293a0 → r5
 *   gy  = YYGetFloat(args,2);   // 0x1293ac..0x1293b0 → r0
 *   r0=ind, r1=gx, r2=gy; pop; tail → 0x1a3454 ParticleType_Gravity
 *
 * 语义（被调 0x1a3454，60 B / 15 条）:
 *   if (!Exists) return;                       // 0x1a3464..0x1a346c
 *   pt+0x5c = gx (str r6) / pt+0x60 = gy (str r5)   // 0x1a3480 / 0x1a3484
 * 默认值 pt+0x60 = 270.0f（Clear 0x1a3050 写入 0x43870000）⇒ 未调用时粒子**向下**落。
 * 返回值: 无。
 */

/* ---- 9/11 F_PartTypeGravity 代码 0x12937c..0x1293c0 ---- */
/* @0x12937c push {r4, r5, r6, lr} */
/* @0x129380 mov r1, #0 */
/* @0x129384 ldr r4, [sp, #0x10] */
/* @0x129388 mov r0, r4 */
/* @0x12938c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129390 mov r1, #1 */
/* @0x129394 mov r6, r0 */
/* @0x129398 mov r0, r4 */
/* @0x12939c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1293a0 mov r1, #2 */
/* @0x1293a4 mov r5, r0 */
/* @0x1293a8 mov r0, r4 */
/* @0x1293ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1293b0 mov r1, r5 */
/* @0x1293b4 mov r2, r0 */
/* @0x1293b8 mov r0, r6 */
/* @0x1293bc pop {r4, r5, r6, lr} */
/* @0x1293c0 b 0x1a3454 <_Z20ParticleType_Gravityiff> */

/* ══ 10/11  F_PartTypeLife  0x129138  size 72  18 条  (无池)
 * @func 0x129138 0x129180  size 72  18 条
 * 符号 _Z14F_PartTypeLifeR6RValueP9CInstanceS2_iPS_        GML: part_type_life(ind,life_min,life_max)   名串 .rodata 0x33cf94
 * 参数: args = [sp+0x10]（0x129140）
 *
 *   ind = YYGetInt32(args,0);   // 0x129144..0x129148 → r6
 *   a   = YYGetInt32(args,1);   // 0x129154..0x129158 → r5
 *   b   = YYGetInt32(args,2);   // 0x129164..0x129168 → r0
 *   r0=ind, r1=a, r2=b; pop; tail → 0x1a32b4 ParticleType_Life
 *
 * 语义（被调 0x1a32b4，60 B / 15 条）:
 *   if (!Exists) return;                       // 0x1a32c4..0x1a32cc
 *   pt+0x24 = a (str r6) / pt+0x28 = b (str r5)     // 0x1a32e0 / 0x1a32e4
 *   ⇒ 寿命是 **int**（帧数），不是 float；Clear 默认 100/100（0x1a3034/0x1a3038）。
 * 返回值: 无。
 */

/* ---- 10/11 F_PartTypeLife 代码 0x129138..0x12917c ---- */
/* @0x129138 push {r4, r5, r6, lr} */
/* @0x12913c mov r1, #0 */
/* @0x129140 ldr r4, [sp, #0x10] */
/* @0x129144 mov r0, r4 */
/* @0x129148 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12914c mov r1, #1 */
/* @0x129150 mov r6, r0 */
/* @0x129154 mov r0, r4 */
/* @0x129158 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12915c mov r1, #2 */
/* @0x129160 mov r5, r0 */
/* @0x129164 mov r0, r4 */
/* @0x129168 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12916c mov r1, r5 */
/* @0x129170 mov r2, r0 */
/* @0x129174 mov r0, r6 */
/* @0x129178 pop {r4, r5, r6, lr} */
/* @0x12917c b 0x1a32b4 <_Z17ParticleType_Lifeiii> */

/* ══ 11/11  F_PartParticlesCreate  0x129aac  size 112  28 条  (无池)
 * @func 0x129aac 0x129b1c  size 112  28 条
 * 符号 _Z21F_PartParticlesCreateR6RValueP9CInstanceS2_iPS_  GML: part_particles_create(ind,x,y,parttype,number)   名串 .rodata 0x33d2d0
 * 参数: args = [sp+0x18]（0x129ab4）
 *
 *   ps  = YYGetInt32(args,0);   // 0x129ab8..0x129abc → r5
 *   x   = YYGetFloat(args,1);   // 0x129ac8..0x129acc → r8
 *   y   = YYGetFloat(args,2);   // 0x129ad8..0x129adc → r7
 *   typ = YYGetInt32(args,3);   // 0x129ae8..0x129aec → r6
 *   n   = YYGetInt32(args,4);   // 0x129af8..0x129afc → r0
 *   [sp+0x18] = n;              // 0x129b0c（第 5 个参数走栈）
 *   r0=ps,r1=x,r2=y,r3=typ; pop; tail → 0x1a3b78 ParticleSystem_Particles_Create
 *
 * 语义（被调 0x1a3b78，376 B / 94 条）:
 *   if (!ParticleSystem_Exists(ps)) → 0x34d034 "part_particles_create :: particle system does not exist!"
 *      （0x1a3b94 bl 0x1a3770；0x1a3ba4 beq → 0x1a3c9c 错误路）
 *   if (!ParticleType_Exists(typ))  → 0x34d070 "part_particles_create :: particle type does not exist!"
 *      （0x1a3bac bl 0x1a2e14；0x1a3bb4 beq → 0x1a3cc4）
 *   if (n <= 0) return;                                   // 0x1a3bbc cmp r7,#0 / 0x1a3bcc ble
 *   sys = (ps 表)[ps];                                    // 0x1a3bc0..0x1a3bc8
 *   for (i = 1; i <= n; i++) {                            // 0x1a3c64 r5=1 / 0x1a3c68 r5++ / 0x1a3c5c cmp r7,r5 blt
 *     if (sys->capacity <= sys->count) {                  // 0x1a3c6c ldr r2,[r4] / 0x1a3c70 cmp / 0x1a3c74 bgt
 *        SetLength(&sys->items, (count+100)*4);           // 0x1a3c78..0x1a3c88
 *        sys->capacity = count + 100;                     // 0x1a3c90..0x1a3c94
 *     }
 *     k = sys->count++;                                    // 0x1a3bf4..0x1a3c00
 *     if (sys->items[k]) MemoryManager::Free(items[k]);     // 0x1a3c08..0x1a3c20
 *     rp = Alloc(64, "Particle_Main.cpp", 0x586, 1);        // 0x1a3c24..0x1a3c34  ← 单粒子 64 字节
 *     sys->items[k] = rp;                                  // 0x1a3c48
 *     CreateParticle(x, y, typ, rp);                        // 0x1a3c4c..0x1a3c58
 *   }
 *   ⇒ 逐个 new 64 字节（不是一次池分配）；槽满一次 +100（不是翻倍）。
 *   系统结构: +0x00 capacity  +0x04 RParticle** items  +0x08 count
 * 返回值: 无（ret 指针 r0 入口即被 YYGetInt32 覆盖，全函数无 st 到 [r0]）。
 */

/* ---- 11/11 F_PartParticlesCreate 代码 0x129aac..0x129b18 ---- */
/* @0x129aac push {r4, r5, r6, r7, r8, lr} */
/* @0x129ab0 mov r1, #0 */
/* @0x129ab4 ldr r4, [sp, #0x18] */
/* @0x129ab8 mov r0, r4 */
/* @0x129abc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129ac0 mov r1, #1 */
/* @0x129ac4 mov r5, r0 */
/* @0x129ac8 mov r0, r4 */
/* @0x129acc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129ad0 mov r1, #2 */
/* @0x129ad4 mov r8, r0 */
/* @0x129ad8 mov r0, r4 */
/* @0x129adc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x129ae0 mov r1, #3 */
/* @0x129ae4 mov r7, r0 */
/* @0x129ae8 mov r0, r4 */
/* @0x129aec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129af0 mov r1, #4 */
/* @0x129af4 mov r6, r0 */
/* @0x129af8 mov r0, r4 */
/* @0x129afc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x129b00 mov r1, r8 */
/* @0x129b04 mov r2, r7 */
/* @0x129b08 mov r3, r6 */
/* @0x129b0c str r0, [sp, #0x18] */
/* @0x129b10 mov r0, r5 */
/* @0x129b14 pop {r4, r5, r6, r7, r8, lr} */
/* @0x129b18 b 0x1a3b78 <_Z31ParticleSystem_Particles_Createiffii> */
