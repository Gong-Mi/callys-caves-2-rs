# Live-mem findings v2 — 套壳运行（CallyShell）活体等价验证

日期: 2026-10-06 · 方法: 裸 dalvikvm32 壳（无 Activity/无窗口），原版 APK d608f455… + libyoyo 3bbedd09…（与钉死值一致）
壳现场: `~/cally-work/shell32/`（src/CallyShell.java + BhCtx/BhPackageManager/BhShell，run.sh 一键）

## 0. 壳架构（复现配方）

- dalvikvm32 + 原版 classes.dex 直接上 classpath（JNI_OnLoad 与 Java 回调走真类）；编译期 stub（stubsrc/）不进 dex。
- framework natives 由 blockheads shell32 的 libbhshell.so + bootsp.dex 注册（regFramework → 29+ 模块）。
- EGL: EGL10 选 RGB565/depth16/ES2，PBuffer 1136×640（view0 生产画布分支）。
- 驱动序列照抄 DemoRenderer: SetKeyValue×7 → RenderSplash → Startup(apk, saveDir, pkg, 0) → Process(w,h,0,0,0,0,0,60) 循环 + canFlip→eglSwapBuffers。
- ms_context = BhCtx（Application 子类；getPackageManager→BhPackageManager，hasSystemFeature 恒 true，APK 路径/版本 2.1.9/installer com.android.vending，全部调用打 bhctx 日志）。
- RunnerActivity.CurrentActivity = Unsafe.allocateInstance（不进 ctor）— Process 会回调 HasVsyncHandler() 解引用 CurrentActivity.vsyncHandler。
- 音频: libopenal 在 hbt 翻译层下 OpenSL dlsym IID 全失败（不可用但非致命，游戏继续）。
- 未做: manifest metaData（SleepMargin/SplashscreenTime，走 mYYPrefs=null 路径）、扩展实例（AdColony 调用安静返回 null）、Gamepad、真 vsync（HasVsyncHandler=0）。

## 1. 活体对账（壳 pid 18153，rw_base 0xa2c95000）— 与 v1 真机逐项一致

| 量 | 壳（v2） | 真机（v1） |
|---|---|---|
| Run_Room_List | 114 | 114 |
| Current_Room / Current_View / New_Room | 0 / 0 / -1 | 0 / 0 / -1 |
| Draw_Automatic | 1 | 1 |
| g_InitialScreenSizeX/Y | 1136×640 | 1136×640 |
| g_ApplicationSurface | 0xFEEEDEAD（dead 哨兵） | 同 |
| g_Application_Surface_Autodraw | 1 | 1 |
| g_PrevViewArea* | -1.0f（清零态） | 同 |
| view[0] | vis=1, view 448×252 → port 1136×640 | 同 |
| view[1..7] | 8 槽 view/port 值逐槽一致 | 同 |

结论: 壳内 runner 的运行态与前台真机同一分支（1136×640→view0）。壳可作可复现、零前台干扰的活体 oracle：输入注入（TouchEvent/KeyEvent JNI 直接调）、逐帧内存观测、Unicorn 之外的第二观测通道。

## 2. 施工链（本轮踩坑→解法，均实证）

1. Looper.<clinit> 先炸 → shim 加载+regFramework 必须在第一个 framework 类初始化之前（提前到 realMain 最顶）。
2. 静态 Analysis 天花板无关（GML 字节码层级高），真正的壳坑全是 Java↔native 边界: Startup+332 PackageManagerHasSystemFeature 对 null 调 CallObjectMethod → 喂 ms_context。
3. PackageManager 94 个抽象方法全量生成（javap 驱动），重载按 (名,参数数) 区分; throws 里的 NameNotFoundException 是嵌套类，子类外必须带 PackageManager. 前缀。
4. sun.misc.Unsafe 不在 API 35 android.jar：编译期 stub + 全反射调用（Class.forName("sun.misc.Unsafe") 运行时仍在）。
5. strace 会扰动 hbt 翻译层（SIGFPE si_code 乱码/SIGABRT），壳的取证一律非 strace；exit(0) 与 SIGABRT 表现随 CheckJNI/时序漂移，以 logcat FATAL 栈 + shutdown hook 双判据定界（hook 打印=Java 侧退出，不打印=native exit）。
6. 进程发现勿用 cmdline 子串自匹配（扫描命令自己的 cmdline 会命中）；必须二次用 /proc/<pid>/maps 是否映射 libyoyo 复核。

## 3. 未决 / 下一步

- ms_ID2InstanceE（本次读到 0xe4ac2080，ms_CurrentCreateCounter=19840）容器结构解码——v1 遗留项，现可在壳内任意暂停、单步、注入下做。
- GR_Window_View_Define 精确矩形算式（v1 遗留项 #2）：壳里 g_ViewPort 可在窗口变化时主动观测。
- Process 循环速率与 30Hz room speed 的时钟关系（重建逻辑时钟契约对照）。
- 输入注入通道（TouchEvent）+ 剧情/关卡推进的活体回归。

## 4. ID2InstanceE 容器结构（已验证，tools/verify_id2inst.py 6/6 ALL PASS）

验证运行: 壳 pid 14509 / rw_base 0xc61f4000（与第 2 次运行独立取数，非同一现场）。

- C1: 头部 {table, cap-1=511, count}；count = 存活实例数（180）。
- C2: 表 = 512 项 × 8 字节（两词同值）；在用的项数恰等于 count（180/180）。
     项下标 = id & 511 —— 180/180 零违例（直接映射，无链）。
- C3: 项内 node 即每实例记录: id 在 node+0x08。node+0x10 是全局记录列表
     的链接（180 个头共可达 680 条 = 存活 + 已销毁未回收记录）；
     已销毁记录的 +0x0c 指向已释放内存（/proc/pid/mem 读报 I/O error），
     可反向用作 liveness 判据。
- C4: 存活记录 node+0x0c → 变量作用域记录: 首词 vtable（libyoyo rw 段内，
     按 rw_base 相对校验），+0x24..+0x2c = {0x2b3(=g_nInstanceVariables 691),
     1, 691}；180/180 全中。
- C5: Run_Room+0x94 = 房间本地实例数（175）≤ 全局存活（180）；差 5 个 =
     存活但不在当前房间列表（持久全局对象）。room+0x10/0x14 = 1024×576。

未决: id&511 冲突策略（无链，疑为创建计数器跳过占位的 id）；绘制顺序
列表仍不在此容器（继续 room+0x80..0x90 列表头 / CRoom::AddInstance 线）。

## 5. 房间绘制顺序列表（二进制+活体双证，tools/draw_order_probe.py / town_draw_order.py）

反汇编（gobjdump -d -C libyoyo 3bbedd09…）:
- CRoom::AddInstance(CInstance*)@0x1ab654: 房间 +0x80=表头(min depth 端)、+0x84=表尾(max depth 端)；
  CInstance +0x178/+0x17c=前后链、+0x180=depth f32、+0x188=入表时排序键、+0x78=id、
  +0x80=CObjectGM*、+0x65=visible、+0x68=skip、+0x69=deactivated、+0xb4/+0xb8=x/y。
- DrawInstancesOnly@0x1b0f50: 从 [Run_Room+0x84] 起沿 +0x17c 走向表头 = 实际绘制序；
  跳过 +0x68/+0x69，+0x65==0 也跳过。深度严格递减、同深新 id 先绘（与 Unicorn
  [200002,200001] 证据一致）。
- CObjectGM+0x14 = 对象名字符串指针（实测解析出 obj_introduction 等）。
- 另一个容器: CRoom+0xc8 = AddInstanceToStorage 的 {count, 40B记录{depth,y,inst,seq,…}} —— 与绘制链表并存（用途待查，疑似持久化/存档用）。

活体（壳 run24, pid 5825）:
- 当前房间(rm_town, room0) 绘制表只有 5 实例: obj_introduction(d=1)、obj_logo、
  obj_phone、obj_viewresolution×2 —— 启动介绍屏；Run_Room_List 其余 113 房为 NULL
  （懒创建）。ID 表 180 ≠ 本房列表数：房间表只含本房实例。
- view0 x/y=0,0；createCounter 45024（无 vsync 限帧，游戏以 ~500步/s 快进）。
- 触摸注入: work/cmd.txt 控制线程（touch/key → JNI）已通（16 次 CTL 送达），
  但 mouse_check_button_pressed 不触发 —— 事件进了 native TouchEvent 却没变成
  游戏鼠标态；下一步反汇编 Java_..._RunnerJNILib_TouchEvent 查 gating
  （疑 focus/window 检查）。

## 6. 触摸注入修正 + rm_town 全卡司绘制序首捕（已验证）

- TouchEvent JNI（0x291c6c）反汇编: 无 focus/window gating，直接写触摸态；
  **id 是分叉条件 —— id==0 走鼠标态路径，id>0 只进多点数组**。此前注入全用
  id=1，游戏永远收不到鼠标键。改 id=0 后一发送介绍屏即退场。
- cmd.txt 控制通道实证: `touch 0 0 568 320` + `touch 1 0 568 320`（间隔≥1帧）
  推进介绍屏 → 序章 → rm_town。
- rm_town 活体绘制表（壳 pid 27678, SIGSTOP）: 147 实例全捕获 —
  obj_player(id 100000 @416,494 d=0)、obj_lloyd(100046 @768,480 d=1)、
  HUD 按钮族、obj_bg/tree/house、obj_boulder×59、obj_wall×42、obj_wall_2×28。
  CObjectGM+0x14 名字解析全中。
- 排序契约活体确认: 深度沿绘制序严格递减（0 违例/147）；同深 id 递减
  （新先绘）128 比仅 1 例例外（该例外对即重建 spawn_seq tie-break 的边界
  用例，待定位）。
- 相机实证: view0=(192,324) 448×252 —— x 向玩家居中（416-224=192）；
  y=576-252=324 房间底 clamp（CCamera::CameraUpdate 边界分支，非居中）。
- room+0x94(=30) ≠ 绘制表长(147)：该字段语义仍待查（勿当实例数用）。

## 7. rm_town 全量普查 + tie 例外定位（tools/room_census.py，输出存档 census-town-run26.txt）

- 可复现性: 两次独立壳运行（pid 27678/23470）的 boot 后 town 态完全一致 —
  view0=(192,324)、绘制表 147、深度序 0 违例、tie 结构相同。壳可作确定性基线。
- tie 唯一例外定位: d=0 组内 obj_player(100000) 先于 obj_viewresolution(171015)
  绘制（其它 128 对全部新先绘）。171015 是介绍屏时代的持久实例（驻留 -884,-172），
  随房间切换被搬进 town 表 —— 携带实例的入表路径绕过/不同于 AddInstance 的
  同深插入规则。**契约含义: 持久 carry-in 实例可产生 tie 反转，重建的
  spawn_seq tie-break 必须对此有口径**（纯 AddInstance 语义不完备）。
- room+0x94 语义假设（两点精确吻合）: id_map_count = 房间绘制表数 + room+0x94
  （intro 态 180=5+175；town 态 177=147+30）。即 +0x94 = 存活但不在当前房间
  绘制表的实例数。待中态（关卡内）第三次确认。
- CRoom+0xc8 staging 容器在 town 态已释放（读 I/O error）——它是建房期临时
  容器（AddInstanceToStorage），非常驻；存档快照语义线索随其释放路径待查。
- id map 自洽: populated=177=header_count。

## 8. 音频时间线：hook 尝试（失败链完整记录）与轮询路线

目标: 音频通道在 hbt 下必坏（OpenSL dlsym IID 全失败），改从代码侧确定"什么时间播放什么"。

逆向成果（Audio_PlaySound@0x21b5d8 全函数反汇编）:
- 汇合点确认: F_AudioPlaySound@0x134b5c → Audio_PlaySound(int index, double prio, int loop)。
- 源结构体 (Audio_GetSoundSourceToPlay 返回, r4): +16=AL source 槽, +20=播放序号
  (全局计数器 0x3F1690 递增后写入), +24=声音索引, +28=priority, +36=音量, +44/+52=标志。
- 设备结构 VA 0x3F166C（+0=AL source id 数组）, 0x3F1668=源音量数组, 0x3EF2EC/0x3EEFD0
  为音频使能标志（Audio_PlaySound 前置检查）。
- Audio_StartSoundNoise(CSound*, CNoise*) 把源挂进 CSound 链表 —— 轮询"某声音是否
  在播"读 CSound 实例链即可。

二进制补丁 hook（三次尝试均告失败，hbt 翻译层约束）:
1. 绝对 .word 跳转 → SEGV@0x1572ac（.text 无动态重定位，literal 不随基址重定位）。
2. add-pc/bx-r12 位置无关版 → SIGILL（hbt 对 add rx,rx,pc / 寄存器间接跳转不兼容）。
3. bl+lr 相对寻址版 → r1=0x2 崩在 strlen（hbt 的 lr 是 thunk 编号非真实 VA）。
教训: hbt 下补丁只能用纯直链 bl + 不依赖 pc/lr 的寻址；寄存器传参 ABI 正常。
运行时副本已恢复 pristine（sha256 同钉死值 3bbedd09…）。

轮询路线（下轮施工）: root 采样循环按 ~50ms 读 0x3F1690(播放计数)+0x5428C0
(g_GameTimer 找 tick 字段)+各 CSound 实例链 presence；Intro/town 各采样一段，
_counter 跳变时刻 = 播放事件时刻，CSound 链成员 = 在播集合；声音索引→名字用
contracts/audio-sond.json。全程不改二进制，100% hbt 安全。

## 9. 音频轮询路线：二级指针世界 + 音频被禁的证据链

- 校准修正: rw 段所有 VA 统一用 live = RW + (va - 0x3F2000)（data 与 bss 同式，
  Draw_Alpha=255/Run_Room_List=114 实证）；0x3F1000 变体是错的。
- 数据区大量二级指针: [slot] = 堆指针，需 deref 一层。例: 0x3F1690 是 bump
  分配顶指针（CNoise 池），非播放计数器——第 8 节的"计数器"判读已修正。
- 音频被禁证据链: F_AudioPlaySound 前置 gate（slot 0x3EF0D4 → 堆上字节 = 16 ≠ 0
  → bne skip）；同族 flag_startnoise/ps1/ps2 字节均非零。与 OpenAL 初始化失败
  （OpenSL dlsym IID 全挂）一致——Startup 把音频子系统标记为禁用，GML 的
  audio_play_sound 调用在 F_ 层被跳过，故轮询不到任何播放活动。
- 管理器 S(0x7553AC) slot = 0（音频禁用，从未填充）——同上结论。

下轮施工（全程无代码补丁或仅叶函数补丁，hbt 安全）:
1. root 写 0 清 4 个 gate 字节（运行时内存写，非补丁）。
2. libopenal 导出叶函数打 noop 补丁（alGetError→0, alSourcef/i/3f→ret,
   alSourcePlay→ret 等，每条 mov r0,#0; bx lr，不碰 pc/lr/绝对址）。
3. 播放状态机全速运转后，轮询 CNoise 池 bump 指针 + CSound 链 + 源结构
   (+24 声音索引 / +20 播放序) → 真实音频时间线；与 audio-sond.json 对名。

## 10. 音频时间线：静态表 + 动态事件追踪（已打通，分支归约为下一步）

结论先行: 壳内音频子系统被禁用（OpenAL 设备打开失败 → 管理器空 → 索引查找必空），
任何 hook/轮询都拿不到真实播放；**可行的"什么时间播放什么"= 事件级意图追踪**。

工具链（均在 reconstruction/live-mem/tools/）:
1. audio_static_table.py → audio-call-table.json: 1354 个恢复 GML 文件扫描出
   169 事件/450 个 audio_* 调用，带**音效实参**与**分支守卫**（缩进法解析
   if/else 链，422/450 有守卫）。
2. event_trace.py → 动态事件流: 读 Current_Object/Event_Type/Event_Number
   (0x54290C/08/04)，CObjectGM+0x4 反查对象索引→名字（20 个 GM 全标定:
   0=obj_player、6=obj_wall_2、66=obj_UI、68=obj_music、126=obj_weaponswap…）。
   逗号: 壳加 `work/paced` 开关把 Process 循环降到 ~30ms/帧（近实时），
   否则 500 步/s 会把事件流混叠。
3. audio-timeline-town.json: 事件流 × 静态表 join（882 行候选）。

实测样例（town，paced）:
  obj_player.Step(0) c12 → 42 个 audio_play_sound，各带守卫
    e.g. audio_play_sound(snd_impactsound5)  guard: if(global.rebuff!=1) > else if(global.soundmute==0)
         audio_play_sound(snd_youhavedied)    guard: if(global.health1==1) > else if(global.soundmute==0)
         audio_play_sound(snd_coin)           guard: else if(hitpickup.type==4) > else if(global.soundmute==0)
  obj_music Other(4)=Room Start: 按 room 选 mus_bosssong/mus_techno（rm_boss1..6），
    主体曲由 Step/Alarm 的 theme[soundplay] + audio_is_playing 守卫驱动。
  obj_introduction.Create(0) c548 → audio_play_sound(mus_new4)（启动曲）。

未决（下一步）: 882 候选 → 每 tick 实际播放，需按守卫求值（live 读
global.* 与实例变量，变量表在恢复产物中有）；另 obj_music 的 audio_is_playing
守卫在音频禁用下恒真，重建设计时需按"音频子系统健康"分支处理。

## 11. 守卫求值基础设施：全局变量名字表 + 值访问（已打通）

RE 锚点（libyoyo 3bbedd09，全部现场验证）:
- g_pGlobal        0x544BE0 (bss) → 全局变量存储
- g_nGlobalVariables 0x544B4C = 691
- g_VarNamesGlobal 0x47A19C = {count=691, f1=657, elem_size=8, names_ptr}
- names_ptr → 691 个名字字符串指针数组（stride 4），实测解析出 417 个非空名字:
  7=gemsfromhouse 8=warpedfromlloyd 9=roomcamefrom 10=roomstart 11=rebuff
  13=keydrop 14=warplock 15=playerdied 18=musicmute 19=soundmute 20=health1 …
  全表已存 globals-name-map.json（供守卫求值 join）。

工具（tools/）: find_shell.sh（稳取 pid+rw_base，避开 /proc 目录误匹配）、
global_names.py / globals_dump.py（名字表与值）、globals_snapshot.py（区域快照+diff）。

状态:
- 值编码未最终定标: 4B/8B 两种解释各有合理/可疑项（rebuff 8B={0x00ffffff,0} 疑为
  undefined 标记），需一次受控变更（如点静音按钮）做 diff 标定；暂停按钮屏幕坐标
  换算未命中（obj_pausebutton world(512,324) → sy≈0，点击未开菜单），下轮先修
  触控坐标或从 obj_pausemenu 实例位置反推。
- 全局存储两次空闲快照无变化（paced 30ms/帧、town 静止），符合预期。

下一步: 用受控输入（静音/暂停）diff 标定 slot 编码 → 写守卫求值器（把
audio-call-table.json 的 524 条 global.* 守卫按 live 值求值）→ 882 候选收敛为
逐 tick 实际播放时间线。

## 12. 输入通道硬化 + 变量布局推进（本轮）

输入通道（重要工程修正）:
- 症状: CTL 线程停在 `touch 0 0 811 16` 之后再也不处理命令（日志只有 enter 无 done），
  g_MouseX 冻结在最后坐标、g_DoMouseButton 卡 1 → 后续 tap 全丢。
- 修法: ctl 改 claim-then-execute（先 rename 成 cmd.txt.run 再执行）+ 每次 native
  调用前后打点（CTL enter/done）。重跑后 tap 立即恢复（g_MouseX/Y = 注入坐标）。
- 判据: work/logs 里 CTL enter/done 成对出现；mouse_state.py 读 g_MouseX/Y
  (0x5346B8/0x5346B4)、g_DoMouseButton(0x535700)、g_MousePosX/Y(0x53468C/0x534664)
  可直接验证注入是否落地。

暂停菜单与音量开关（可复用坐标）:
- 暂停按钮命中: 画布 (811,16)（obj_pausebutton Draw: x=view_xview[0]+320、
  y=view_yview[0]，sprite 上半在视口外，必须点下半）。
- 菜单对象: obj_firstpause(512,324)、obj_backtogame(482,514)、
  obj_volume(292,384)、obj_volumemusic(292,424) world → 画布换算 ×2.5357/×2.5397
  （obj_volumemusic → (254,254)），其 Mouse_4 切换 global.musicmute 0↔1。
- Escape(27) KeyEvent 不触发暂停（obj_pause_KeyPress_27 是已有菜单内的关闭）。

变量存储布局（推进到 YYObjectBase 层）:
- RValue = **16 字节**（YYGetReal/YYGetInt32 里 `add r1, r0, r1, lsl #4`），
  类型字在 +12 高 8 位（type&0xff 分发 0..13）。此前 4/8 字节读全部作废。
- Variable_Global_GetVari 路径: scope = *g_pGlobal；index = 传入值 − 100000(0x186a0)；
  快路径 base = [scope+4] + index*16；**该字段为 0 时走
  YYObjectBase::InternalGetYYVar(index)**（哈希路径）。
- 现场 scope(0x9ce3de80) = {vtable,0…,0x24=691,0x28=1,0x2c=691}，
  [scope+4]=0 → 走哈希路径 → 变量在 YYObjectBase 内部存储（下轮 RE 点）。

未决: YYObjectBase 变量存储/哈希布局（g_VarNamesGlobal 的 691 名字已就绪，
只差值侧寻址）；拿到后即可把 audio-call-table.json 的 524 条 global.* 守卫
按 live 值求值，收敛 882 候选为逐 tick 实际播放。

## 13. 全局变量读取 + 守卫求值器（打通，"什么时间播放什么"收敛机制就位）

变量布局最终解码（libyoyo 3bbedd09，全部现场验证）:
- scope = *(g_pGlobal 0x544BE0)；map = [scope+0x60]；mask=[map+8]；data=[map+16]
- **hash(i) = i + 1**（CHashMapCalculateHash@0x1b6e44 仅 `add r0,r0,#1`）
- 条目 12 字节 {?, RValue* @+4, hash @+8}；slot = hash & mask，线性探测，stored==0 未命中
- RValue 16 字节：payload +0..+11，类型字 +12（高 8 位；7=real/double，0=int）
- 实测验证：health1=4.0（对上 obj_introduction Destroy 赋值）、musicmute/soundmute=0、
  keydrop=2.0 —— 语义正确。
- 工具: global_get.py（单变量读取）/ guard_eval.py（守卫求值）。

守卫求值实测（town, paced）:
- obj_music.Other(4) c378（Room Start 的 boss 曲分支）: 17 条全 FALSE —— musicmute==0 为真，
  但 room==rm_bossN(10/27/48/64/82/104) 全假（当前 room=0=rm_town）→ 镇里不播 boss 曲。
  房间名映射来自 full_ir.room_bindings（114 房，room-index-map.json）。
- obj_player.Step c12: snd_youhavedied 分支 **FALSE**（global.health1=0 ≠ 1，判定正确）；
  snd_impactsound5 的 global 守卫（rebuff!=1、soundmute==0）全 TRUE，仅剩实例变量守卫；
  snd_coin 剩 hitpickup.type==4（实例变量）。
- 分类完备: TRUE/FALSE/UNRESOLVED(实例变量)/AUDIO-STATE(audio_is_playing，壳内恒假)。

未决（下轮，边界已收窄）: 实例变量读取 —— CInstance 作用域用同一 YYObjectBase 布局
（scope=instance+0x0c，+0x60=map，hash=index+1），只差"实例变量名→索引"表
（full_ir 的 VARI 记录）；到手后 obj_player/obj_house 等事件守卫可完全求值，
882 候选即可在任意 tick 收敛为实际播放集合。

## 14. 实例变量读取 + 端到端验证（"什么时间播放什么"的输入侧全部就绪）

实例变量（同名表布局 + CInstance 同 YYObjectBase）:
- CInstance 即 YYObjectBase: map=[inst+0x60]，hash(i)=i+1，条目 12B {?,RValue*@+4,hash@+8}。
- 名字表: g_VarNamesInstance 0x47A18C（691 槽 / 274 有名）、g_VarNamesLocal 0x47A17C
  （8 槽 / 0 有名）、g_VarNamesGlobal 0x47A19C（691 / 417 有名）。
- 工具: instance_get.py（按对象名找实例→读任意实例变量；--names 可列名字表）。
- 实测: obj_player invulnerable=0 facing=0 hsp=0（静止镇内，值合理）。

端到端动态验证（输入→状态→房间，全链路）:
- 注入按住右键(画布 340,550) 1.5s: obj_player.x 416 → **647**（与 v1 真机 town
  player x≈649 吻合）；松开后进入 rm_level1: global.level=1.0、roomstart=1.0（实读）。
- 说明输入注入、实例状态、全局状态、房间切换四层观测全部可用且互相印证。

未决（最后一段，边界很小）:
- 复合守卫 `ref.member == N`（如 hitpickup.type==4）：需先读 ref 变量拿到目标实例
  再读其 member —— 两步读，机制已具备（instance_get 的查找可复用）。
- 完成后 guard_eval 即可对 450 条调用做全自动求值 → 任意 tick 的"实际播放集合"，
  与事件流工具联用即为完整音频时间线。

## 15. 音频时间线：状态求值已闭环，事件流采样受因果性限制（如实记录）

已完成（可复用）:
- guard_eval2.py：全表 450 条调用按 live 状态求值 → TRUE=126 / FALSE=58 /
  UNRESOLVED=227 / AUDIO-STATE=38 / REF-UNRESOLVED=1。判定样例正确:
  敌人死亡 Alarm → snd_explode；boss Destroy → mus_bosssongending/mus_technoending；
  snd_youhavedied 在 health1=0 时判 FALSE。
- 实例变量读取（obj_player invulnerable/facing/hsp）+ 全局变量 + room + 名字表全部可用。
- 壳新增 work/pace_ms（可调帧延迟，默认 30ms），用于放慢游戏做观测。

采样因果性限制（本轮实测结论）:
- 用 20ms/3ms 轮询 Current_Object 抓事件流，无论 paced 与否都严重混叠：
  paced 时游戏帧内工作在微秒级完成、其余时间在 sleep，采样几乎必然落在帧末，
  于是 Current_Object 恒为"该帧最后处理的对象"（实测 41 个样本全为 obj_wall_2）。
  未 paced 时 500 步/s 同样混叠。**单全局变量采样无法重建事件序列**。
- 结论: "事件何时触发"不应走内存轮询；正确顺序是 ①本仓已有的 Rust IR 仿真
  产事件序列（obj/event/tick），②用现在可读的 live 状态（全局/实例/房间）做
  交叉校验，③守卫求值器给出每次事件的"实际播放集合"。

交付物定位:
- 现状可交付: "给定当前 live 状态，各事件会播什么"（guard_eval2 --all 输出）。
- 时序层: 用重建 IR 的事件序列 + 同一套守卫求值即可产出逐 tick 音频时间线，
  不再依赖对原版内存的微秒级采样。

## 16. 重建侧逐 tick 音频时间线（IR 仿真）——并暴露一处语义缺陷

驱动: `crates/core/examples/audio_timeline.rs`（asset+IR 载入 → rm_town →
逐 tick `Scene::tick` + `drain_audio()`），输出 `tools/rebuild_timeline_town.txt`
（900 tick / 900 条命令）。

实测现象:
- 900 tick 内共 900 条 audio 命令，**每 tick 一条**，全部来自 code 377
  (obj_music_Step_0)，sond id 逐 tick 轮换（如 29=egc、32=townmusic、
  52=blooddragon、47=synthonic、45=soundwall …）。

原版语义（恢复 GML 0375/0377 + sond 表对照）:
- theme[] 在 obj_music Create (CODE 375) 按房间分支写入 **sond id**（29/32/34/36/37/44…）。
- Step (CODE 377) 是音乐序列器: `soundplay += 1; audio_play_sound(theme[soundplay],0,false)`
  被 13+ 条 `!audio_is_playing(mus_*)` 长链包住 —— **靠 audio_is_playing 截断序列**:
  一旦某轨在播，链短路，soundplay 不再推进；只有当前轨播完后才继续。

缺陷定位（重建侧）:
- `Scene::drain_audio()` 对非循环声部执行 `retain(|v| v.looping && !v.stopped)`
  → 每帧 drain 后，非循环声部从表中消失 → `audio_is_playing` 恒 false →
  obj_music Step 每 tick 都重新播放并推进 soundplay（0..16），整张播放表在 16 tick
  内轮完。原版引擎里非循环声部在其时长内保持 playing，门才会生效。
- 这正是 audio_voice_ir.rs 头部注释里"stub 对每个查询返回 0.0 导致 BGM 每 tick
  重启"的同类问题，只是换成了 drain 剪枝路径。

结论/契约要求: 非循环声部的"在播"状态必须按时长维持（需要 sond→时长的数据，
可从 game.droid 的声音资源头解析；audio-sond.json 目前无 duration 字段），
否则 obj_music 序列器与所有 audio_is_playing 门都会失真。
