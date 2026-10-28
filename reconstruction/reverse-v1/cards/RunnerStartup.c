/* cally 逆向卡：JNI 启动入口 + 全局变量初始化（原版 libyoyo.so，armv7）—— 一卡两节
 * @func 两节按地址升序，逐节自带 @func 头与逐条锚点：
 *   §1 0x29062c Java_com_yoyogames_runner_RunnerJNILib_Startup  size 5696  1424 条
 *        = 1199 条指令 + 225 个 literal 池字（0x290880..0x290bfc 共 224 个 + 0x291c68 1 个）
 *   §2 0x1fd184 InitGlobalVariables()                           size 4988  1247 条
 *        = 930 条指令 + 317 个 literal 池字（0x1fe00c..0x1fe4fc，整段在函数尾部）
 * 总账: 2671 锚点 = 2129 条指令 + 542 个池字；与 asm/index-RunnerJNILib_Startup.tsv（1424 行）和
 *       asm/index-InitGlobalVariables.tsv（1247 行）逐字一致：
 *       check_card_anchors.py 两节分别 index=1424 card=1424 missing=0 extra=0 mismatch=0 RESULT EXACT /
 *       index=1247 card=1247 missing=0 extra=0 mismatch=0 RESULT EXACT；
 *       把两份索引顺序 cat 成 2671 行后对整卡再跑一次：index=2671 card=2671 missing=0 extra=0 mismatch=0 RESULT EXACT。
 *       池字在 objdump 里被译成 andseq/andeq/ldrheq/.word 之类，**不是指令**，本卡按索引原文保留，
 *       并在每条池字后面注明「由哪条 ldr 取用、解析成什么」（GOT 偏移 / pc 相对串 / 常量）。
 * 级别: 正文（两节都逐条解码：§1 的 A..G 七段主流程 + 首次调用注册块 + APK 装载 + 收尾；§2 的 120 条
 *       Variable_BuiltIn_Add 全表 + 尾部快照 + 尾跳。getter/setter 只钉到符号名与地址，不读其内部）
 *       tier = bytecode_anchored
 * 锚点来源: 全部由 asm_index.py 从二进制生成，本卡未手写转录；语义注解由 GOT(.rel.dyn R_ARM_RELATIVE
 *       就地 addend)、pc 相对池字、.rodata 串三者交叉算出，脚本在 ~/.hermes/cache/scratch/rstartup/。
 * 二进制身份: ~/cally-oracle/libyoyo.so = 原版 APK lib/armeabi-v7a/libyoyo.so
 *       sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a（与
 *       callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so 同 sha）
 *
 * ── 一句话 ──────────────────────────────────────────────────────────
 *   §1 是 Java 侧 nativeStartup 的全部落地：打 banner → 建 JNIEnv 的 pthread key 并把 env 存进 TLS →
 *   FindClass 拿 RunnerJNILib → **只在第一次**把 jclass 做成全局引用并抓 79 个 static 方法 ID →
 *   从 Java 传来的 3 个字符串里取 apk 路径/save 目录/包名（zip_open 打开 APK）→ 组一条
 *   "-game game.droid" 命令行 → Init() 一串 INITIALIZE_* → BeginToEnd()（尾调 DoTheWork）→
 *   清空输入事件环 → 问 Java 要默认 framebuffer → 探 leanback/manufacturer → 收尾。
 *   §2 是 Init() 链尾的「内置变量注册表」：120 条 Variable_BuiltIn_Add（名字 + GV_* getter +
 *   SV_* setter + 一个在本构建里被立刻覆盖掉的 bool），注册完尾跳 InitYoYoBuiltInVariables 再补 5 条。
 *
 * ── 入参 / 返回（Java 侧声明与实参落位）────────────────────────────────
 *   Java: public static native void Startup(String apkFilePath, String saveFilesDir,
 *                                          String packageName, int sleepMargin);
 *   （cally-work/shell32/apk/jadx-out/sources/com/yoyogames/runner/RunnerJNILib.java:141）
 *   softfp 落位：r0 = JNIEnv*、r1 = jclass、r2 = apkFilePath(jstring)、r3 = saveFilesDir(jstring)、
 *   [sp+0] = packageName(jstring)、[sp+4] = sleepMargin(jint)。
 *   帧：push {r4..r11,lr}（36 B）+ sub sp,#52 ⇒ 形参区整体后移 88 = 0x58，
 *   于是 [sp+0x58] = packageName、[sp+0x5c] = sleepMargin（0x291af8 / 0x29086c 两处取用，逐条已钉）。
 *   返回 void：唯一的出口 0x29087c `pop {...pc}` 不回写 r0。
 *
 * ── 调用链（谁调它、它调谁）──────────────────────────────────────────
 *   Java RunnerActivity → RunnerJNILib.Startup(...)
 *     → §1 0x29062c
 *        ├ ImportGLLibrary 0x28fce4
 *        ├ setJNIEnv 0x290614 / getJNIEnv 0x290274（同一个 pthread key）
 *        ├ ProcessCommandLine 0x2a1cf0
 *        ├ Init 0x2a2914 ── 17 条初始化调用串联：RomDisk::Init / Timing_Init / InitFastCRC +
 *        │    12 条 INITIALIZE_*（PlatformSpecific…Main）+ SetupGMLFunctions + ProcessMessages；
 *        │    其第 12 条 INITIALIZE_Variable_BuiltIn 0x1ffbd0
 *        │    └ 0x1ffc90 `b 0x1fd184` = **尾跳 §2 InitGlobalVariables**
 *        │         └ 0x1fe008 `b 0x15dafc` = InitYoYoBuiltInVariables（再注册 5 条，见 §2 末）
 *        ├ BeginToEnd 0x2a180c ── 尾调 DoTheWork 0x2a16dc（见 DoTheWork 卡：srand48(2101988) →
 *        │    RunnerLoadWad → PrepareGame → Run_Start）
 *        ├ MemoryManager::Init 0x27c23c
 *        └ zip_open 0x2a4de0
 *   ⇒ 两个「`b` 而不是 `bl`」把链条接起来：InitGlobalVariables 的唯一调用者就是 INITIALIZE_Variable_BuiltIn
 *     （全库只有 0x1ffc90 一条分支指向 0x1fd184），而 INITIALIZE_Variable_BuiltIn 的唯一调用者是 Init。
 *
 * ── 重点一：JNI 入口拿到的 JavaVM / JNIEnv 存到哪里 ────────────────────
 *   1. **JNIEnv 只进线程局部存储，没有全局变量**：
 *        0x290698  bl pthread_key_create@plt，r0 = &0x756c04、r1 = 0
 *                  ⇒ 在 0x756c04 建一个 pthread key（析构回调 NULL）
 *        0x2906a0  bl setJNIEnv(env)
 *        setJNIEnv 0x290614 只有 4 条有效指令：
 *                  ldr r3,[pc,#0xc] → 0x290628 池字 0x161308；ldr r3,[pc,r3] → 槽 0x3f192c → 0x756c04；
 *                  ldr r0,[r3]（= key 值）；r1 = env；b pthread_setspecific@plt
 *                  ⇒ pthread_setspecific(*(u32*)0x756c04, env)
 *        getJNIEnv 0x290274 同构：池字 0x1616ac → 同一个槽 0x3f192c → 0x756c04 → b pthread_getspecific
 *        ⇒ 取出同一线程的 env。其它 JNI 入口（如 TouchEvent 0x291c84）每次进来都再调一次 setJNIEnv 刷新。
 *   2. **JavaVM 根本没被拿**：全库 instructions.jsonl 的 645,282 条指令里没有任何 `ldr rX,[rY,#0x36c]`（JNIEnv 函数表
 *      GetJavaVM 的下标 219 × 4）——即这份 libyoyo 从不调 GetJavaVM，也就没有 JavaVM* 可存。
 *      它不需要：所有回调都走 jclass + GetStaticMethodID 的静态调用。
 *   3. **jclass 不是入参存的**：入参 r1（jclass）在 0x290630 就被 r4=env 覆盖掉了，全函数没有再读；
 *      真正使用的 class 是 0x2906b8 FindClass("com/yoyogames/runner/RunnerJNILib") 的返回值，
 *      第一次调用时 NewGlobalRef 后存进 **0x756d44**（0x290c18 NewGlobalRef → 0x290c44 str r0,[r6]，
 *      r6 = &0x756d44）。0x756d44 是全库 JNI 辅助函数的公共 class 参数（全库 78 处槽引用，含本函数自己那 1 处）。
 *   4. 首个方法 ID 槽是 0x756c08，而 pthread key 就压在它前面 4 字节（0x756c04）——两者同属一块 .bss。
 *   5. 为什么必须用 TLS：Java 侧 Startup 是在 GL 渲染线程里调的（DemoRenderer.java:424/427 的
 *      eState.DoStartup 分支），而 TouchEvent/KeyEvent/Process 各有自己的线程；每个 JNI 入口进来先
 *      setJNIEnv 把自己的 env 写进本线程槽，函数体里再用 getJNIEnv 取回——env 天然是「每线程一份」，
 *      放进全局反而会串线程。
 *
 * ── 全局地图（本卡踩到的 GOT 槽；目标与「谁还读它」都按全库槽引用普查给出）──────
 *   GOT 槽      目标        含义（本卡证据）                                    其它读者
 *   0x3ed71c → 0x3eb70c   控制台对象指针槽（dbg_csol，obj 0x47a118）             LoadGameData/DoTheWork/…
 *   0x3ed948 → 0x3eb708   第二个控制台对象指针槽（obj 0x47a114）                 仅本卡
 *   0x3ed9ac → 0x756d44   全局 jclass（NewGlobalRef 后的 RunnerJNILib）          78 处 JNI 辅助
 *   0x3f192c → 0x756c04   pthread key（JNIEnv 的 TLS 键）                        getJNIEnv/setJNIEnv
 *   0x3f1944 → 0x7577bc   byte 门：Resume 置 1、Process 判它、本卡清 0             Resume/Process
 *   0x3f1948 → 0x479a31   byte 标志：RunGame 置 1、Process 读→返回 2、本卡清 0      RunGame/Process
 *   0x3f194c → 0x756d48   g_localInputEvents（128 槽 × 20 B = 2560 B）             TouchEvent/Process
 *   0x3f1958 → 0x756c70   GetDefaultFrameBuffer 的 jmethodID                      本卡
 *   0x3f0560 → 0x757748   默认 framebuffer id（Java 返回值落地）                    Graphics::SetRenderTarget
 *   0x3f0564 → 0x7577b8   顶点缓冲/绘制状态槽（本卡清 0）                           VertexBuffer/GraphicsRecorder
 *   0x3f1950 → 0x7577b4   leanback 特性标志（PackageManagerHasSystemFeature）      仅本卡写（无读者）
 *   0x3f1954 → 0x7577b0   「厂商 == AMAZON」标志（strupr+strcmp 的结果）            仅本卡写（无读者）
 *   0x3ee5bc → 0x479a28   sleepMargin（.data 初值 0x0a = 10）                       F_DisplayGet/SetSleepMargin
 *                                                                                /Timing_Sleep/Option_Load
 *   0x3f1968 → 0x542988   g_cmdline（malloc 8192，装 "-game game.droid"）           RunGame（2 处）
 *   0x3f1924 → 0x757764   apk 路径（GetStringUTFChars 的裸指针，未 strdup）          GetExeName
 *   0x3eff1c → 0x757768   zip_open 句柄                                           CreateFindData/LoadSave
 *   0x3eff18 → 0x544b94   包名（strdup）                                          GetOSSpecificJSON
 *   0x3f1920 → 0x757750   save 目录（strdup）                                     GetSavePrePend
 *   0x3f03e0 → 0x756758   MemoryManager 记账量（"allocated: %d" 打印的就是它）      MemoryManager/_Alloc/…
 *   0x3edc3c → 0x753108   builtin 变量条数（§2 开头读它）                          Variable_BuiltIn_Add/Find_Name
 *   0x3ee430 → 0x755064   builtin 条数快照（§2 开头写它）                          F_VariableGlobalGet/Set
 *   0x3edc40 → 0x75310c   builtin 变量数组基址（500 × 16 B = 8000 B，见 §2 open）
 *
 * ── §1 的五段（地址即锚点）────────────────────────────────────────────
 *   A 0x29062c..0x29066c  帧 + banner（串 0x3582a8「YoYo Games Android Runner V0.1」）
 *   B 0x290670..0x2906a0  清两个 byte 门 → ImportGLLibrary → pthread_key_create → setJNIEnv
 *   C 0x2906a4..0x2906cc  FindClass；0x756d44 == 0 → 首次，跳 0x290c00；!= 0 → 直接进 D
 *   D 0x2906d0..0x290878  主路径：ProcessCommandLine → Init → "Finished Init" → BeginToEnd →
 *                         清 2560 B 输入环 → getJNIEnv+CallStaticIntMethod(GetDefaultFrameBuffer)
 *                         → leanback → Build.MANUFACTURER/strupr/strcmp("AMAZON") → 存 sleepMargin → 返回
 *   E 0x290c00..0x291a80  首次块：NewGlobalRef + 79 × GetStaticMethodID（80 个 blx，无分支）
 *   F 0x291a84..0x291bf4  APK 装载：apk 路径 → zip_open → 包名/save 目录 strdup → 命令行 → MemoryManager::Init
 *                         → 0x291bf4 `b 0x2906d8` 汇入 D 的 ProcessCommandLine
 *   G 0x291bf8..0x291c64  三条 ReleaseStringUTFChars 释放块 + "Error loading APK" 失败打印
 *   H 0x290880..0x290bfc / 0x291c68  两处 literal 池（224 + 1 字）
 *
 * ── §1 的 79 个方法 ID（名字/签名逐条取自调用点的 r2/r3，落点是 str r0,[r12] 的目标）──
 *   校验：79 组「名字+签名」与上面那份 DEX 的 RunnerJNILib.java 声明 **79/79 全部吻合**
 *   （脚本把 Java 声明翻成 JNI 签名后逐条比对，0 处不一致）。表按调用序：
 *   290c58  0x756d40  OpenURL                    (Ljava/lang/String;)V
 *   290c90  0x756d3c  SendHighScore              (Ljava/lang/String;I)V
 *   290cbc  0x756d38  SendAchievement            (Ljava/lang/String;F)V
 *   290cf0  0x756d34  IncrementAchievement       (Ljava/lang/String;F)V
 *   290d1c  0x756d30  OpenAchievements           ()V
 *   290d48  0x756d2c  OpenLeaderboards           ()V
 *   290d7c  0x756d28  OsGetInfo                  ()I
 *   290da8  0x756d24  AchievementLoadFriends     ()V
 *   290dd8  0x756d20  AchievementLoadLeaderboard (Ljava/lang/String;III)V
 *   290e08  0x756d1c  CallExtensionFunction      (Ljava/lang/String;Ljava/lang/String;I[D[Ljava/lang/Object;)Ljava/lang/Object;
 *   290e34  0x756d18  AchievementLoadPic         (Ljava/lang/String;)V
 *   290e64  0x756d14  AchievementShow            (ILjava/lang/String;I)V
 *   290e90  0x756d10  AchievementEvent           (Ljava/lang/String;)V
 *   290ebc  0x756d0c  AchievementGetInfo         (Ljava/lang/String;)V
 *   290ee8  0x756d08  AchievementLogin           ()V
 *   290f14  0x756d04  AchievementLoginStatus     ()I
 *   290f40  0x756d00  AchievementLogout          ()V
 *   290f6c  0x756cfc  EnableAds                  (III)V
 *   290fa0  0x756cf8  MoveAds                    (III)V
 *   290fcc  0x756ce8  AdsSetup                   (Ljava/lang/String;)V
 *   291004  0x756cf4  DisableAds                 (I)V
 *   291030  0x756cf0  AdsEvent                   (Ljava/lang/String;)V
 *   29105c  0x756cec  AdsEventPreload            (Ljava/lang/String;)V
 *   291090  0x756ce4  AdsDisplayWidth            (I)I
 *   2910bc  0x756ce0  AdsDisplayHeight           (I)I
 *   2910ec  0x756cdc  LeaveRating                (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 *   291118  0x756cd8  EnableInAppBilling         ([Ljava/lang/String;)V
 *   291144  0x756cd4  RestoreInAppPurchases      ()V
 *   29117c  0x756cd0  AcquireInAppPurchase       (Ljava/lang/String;Ljava/lang/String;I)V
 *   2911ac  0x756ccc  ConsumeInAppPurchase       (Ljava/lang/String;Ljava/lang/String;)V
 *   2911d8  0x756cc8  GetInAppPurchaseDetail     (Ljava/lang/String;)V
 *   291204  0x756cc4  FacebookInit               (Ljava/lang/String;)V
 *   291238  0x756cc0  FacebookLogin              ([Ljava/lang/String;)V
 *   29126c  0x756ca8  FacebookAccessToken        ()Ljava/lang/String;
 *   291298  0x756ca4  FacebookUserId             ()Ljava/lang/String;
 *   2912c8  0x756cbc  FacebookGraphRequest       (Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;I)V
 *   2912f4  0x756cb8  FacebookDialog             (Ljava/lang/String;[Ljava/lang/String;I)V
 *   291328  0x756cb4  FacebookInviteDialog       (Ljava/lang/String;[Ljava/lang/String;I)V
 *   291354  0x756cb0  FacebookLogout             ()V
 *   291380  0x756cac  FacebookLoginStatus        ()Ljava/lang/String;
 *   2913b0  0x756ca0  FacebookCheckPermission    (Ljava/lang/String;)Z
 *   2913e0  0x756c9c  FacebookRequestPermissions ([Ljava/lang/String;Z)I
 *   29140c  0x756c98  HttpGet                    (Ljava/lang/String;I)V
 *   291438  0x756c94  HttpPost                   (Ljava/lang/String;Ljava/lang/String;I)V
 *   291468  0x756c90  HttpRequest                (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[BI)V
 *   291494  0x756c74  ClearGamepads              ()V
 *   2914c0  0x756c8c  PlayMP3                    (Ljava/lang/String;I)V
 *   2914ec  0x756c88  StopMP3                    ()V
 *   291518  0x756c84  PauseMP3                   ()V
 *   291544  0x756c80  ResumeMP3                  ()V
 *   291574  0x756c7c  SetMP3Volume               (F)V
 *   2915ac  0x756c78  PlayingMP3                 ()Z
 *   2915d8  0x756c70  GetDefaultFrameBuffer      ()I
 *   291604  0x756c6c  ShowMessage                (Ljava/lang/String;)V
 *   291630  0x756c68  setSystemUIVisibilityFlags (I)V
 *   291660  0x756c64  InputString                (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 *   29168c  0x756c60  ShowQuestion               (Ljava/lang/String;)I
 *   2916b8  0x756c3c  ShowMessageAsync           (Ljava/lang/String;I)V
 *   2916e4  0x756c38  InputStringAsync           (Ljava/lang/String;Ljava/lang/String;I)V
 *   291710  0x756c34  ShowQuestionAsync          (Ljava/lang/String;I)V
 *   29173c  0x756c5c  ShowLogin                  (Ljava/lang/String;Ljava/lang/String;I)V
 *   29176c  0x756c58  RestrictOrientation        (ZZZZZ)V
 *   291798  0x756c54  isNetworkConnected         ()Z
 *   2917c4  0x756c50  CheckPermission            (Ljava/lang/String;)I
 *   2917f0  0x756c4c  RequestPermission          (Ljava/lang/String;)V
 *   291820  0x756c48  powersaveEnable            (Z)V
 *   29184c  0x756c44  analyticsEvent             (Ljava/lang/String;)V
 *   29187c  0x756c40  analyticsEventExt          (Ljava/lang/String;[Ljava/lang/String;)V
 *   2918a8  0x756c30  cloudStringSave            (Ljava/lang/String;Ljava/lang/String;I)V
 *   2918d4  0x756c2c  cloudSynchronise           (I)V
 *   291900  0x756c28  DumpUsedMemory             ()V
 *   291930  0x756c24  SetLaunchedFromPlayer      (Ljava/lang/String;Z)V
 *   29195c  0x756c20  UsingGL2                   ()I
 *   29198c  0x756c1c  PushLocalNotification      (FLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 *   2919bc  0x756c18  PushGetLocalNotification   (II)I
 *   2919e8  0x756c14  PushCancelLocalNotification (I)I
 *   291a14  0x756c10  GetUDID                    ()Ljava/lang/String;
 *   291a40  0x756c0c  WaitForVsync               ()V
 *   291a6c  0x756c08  HasVsyncHandler            ()I

 * ── §2 的 120 条内置变量（注册序；getter/setter 全是 .symtab 里 GV_…/SV_… 的真实符号名）──
 *   1fd1c0  argument_relative          GV_ArgumentRelative        -                          b=0
 *   1fd1e0  argument                   GV_Argument                SV_Argument                b=1
 *   1fd200  argument0                  GV_Argument0               SV_Argument0               b=1
 *   1fd220  argument1                  GV_Argument1               SV_Argument1               b=1
 *   1fd240  argument2                  GV_Argument2               SV_Argument2               b=1
 *   1fd260  argument3                  GV_Argument3               SV_Argument3               b=1
 *   1fd280  argument4                  GV_Argument4               SV_Argument4               b=1
 *   1fd2a0  argument5                  GV_Argument5               SV_Argument5               b=1
 *   1fd2c0  argument6                  GV_Argument6               SV_Argument6               b=1
 *   1fd2e0  argument7                  GV_Argument7               SV_Argument7               b=1
 *   1fd300  argument8                  GV_Argument8               SV_Argument8               b=1
 *   1fd320  argument9                  GV_Argument9               SV_Argument9               b=1
 *   1fd340  argument10                 GV_Argument10              SV_Argument10              b=1
 *   1fd360  argument11                 GV_Argument11              SV_Argument11              b=1
 *   1fd380  argument12                 GV_Argument12              SV_Argument12              b=1
 *   1fd3a0  argument13                 GV_Argument13              SV_Argument13              b=1
 *   1fd3c0  argument14                 GV_Argument14              SV_Argument14              b=1
 *   1fd3e0  argument15                 GV_Argument15              SV_Argument15              b=1
 *   1fd3fc  argument_count             GV_ArgumentCount           -                          b=1
 *   1fd418  debug_mode                 GV_DebugMode               -                          b=1
 *   1fd434  pointer_invalid            GV_PointerInvalid          -                          b=0
 *   1fd450  pointer_null               GV_PointerNull             -                          b=0
 *   1fd46c  undefined                  GV_Undefined               -                          b=0
 *   1fd48c  room                       GV_Room                    SV_Room                    b=1
 *   1fd4a8  room_first                 GV_RoomFirst               -                          b=0
 *   1fd4c4  room_last                  GV_RoomLast                -                          b=0
 *   1fd4e4  transition_kind            GV_TransitionKind          SV_TransitionKind          b=1
 *   1fd504  transition_steps           GV_TransitionSteps         SV_TransitionSteps         b=1
 *   1fd524  score                      GV_Score                   SV_Score                   b=1
 *   1fd544  lives                      GV_Lives                   SV_Lives                   b=1
 *   1fd564  health                     GV_Health                  SV_Health                  b=1
 *   1fd580  game_id                    GV_GameId                  -                          b=0
 *   1fd59c  game_guid                  GV_GameGuId                -                          b=0
 *   1fd5b8  game_display_name          GV_GameDisplayName         -                          b=0
 *   1fd5d4  game_project_name          GV_GameProjectName         -                          b=0
 *   1fd5f0  game_save_id               GV_SaveDirectory           -                          b=0
 *   1fd60c  working_directory          GV_WorkingDirectory        -                          b=0
 *   1fd628  temp_directory             GV_TempDirectory           -                          b=0
 *   1fd644  program_directory          GV_ProgramDirectory        -                          b=0
 *   1fd660  instance_count             GV_InstanceCount           -                          b=0
 *   1fd67c  instance_id                GV_InstanceId              -                          b=0
 *   1fd69c  room_width                 GV_RoomWidth               SV_RoomWidth               b=0
 *   1fd6bc  room_height                GV_RoomHeight              SV_RoomHeight              b=0
 *   1fd6dc  room_caption               GV_RoomCaption             SV_RoomCaption             b=1
 *   1fd6fc  room_speed                 GV_RoomSpeed               SV_RoomSpeed               b=1
 *   1fd71c  room_persistent            GV_RoomPersistent          SV_RoomPersistent          b=1
 *   1fd744  background_color           GV_BackgroundColor         SV_BackgroundColor         b=1
 *   1fd76c  background_showcolor       GV_BackgroundShowColor     SV_BackgroundShowColor     b=1
 *   1fd784  background_colour          GV_BackgroundColor         SV_BackgroundColor         b=1
 *   1fd79c  background_showcolour      GV_BackgroundShowColor     SV_BackgroundShowColor     b=1
 *   1fd7bc  background_visible         GV_BackgroundVisible       SV_BackgroundVisible       b=1
 *   1fd7dc  background_foreground      GV_BackgroundForeground    SV_BackgroundForeground    b=1
 *   1fd7fc  background_index           GV_BackgroundIndex         SV_BackgroundIndex         b=1
 *   1fd81c  background_x               GV_BackgroundX             SV_BackgroundX             b=1
 *   1fd83c  background_y               GV_BackgroundY             SV_BackgroundY             b=1
 *   1fd858  background_width           GV_BackgroundWidth         -                          b=0
 *   1fd874  background_height          GV_BackgroundHeight        -                          b=0
 *   1fd894  background_htiled          GV_BackgroundHTiled        SV_BackgroundHTiled        b=1
 *   1fd8b4  background_vtiled          GV_BackgroundVTiled        SV_BackgroundVTiled        b=1
 *   1fd8d4  background_xscale          GV_BackgroundXScale        SV_BackgroundXScale        b=1
 *   1fd8f4  background_yscale          GV_BackgroundYScale        SV_BackgroundYScale        b=1
 *   1fd914  background_hspeed          GV_BackgroundHSpeed        SV_BackgroundHSpeed        b=1
 *   1fd934  background_vspeed          GV_BackgroundVSpeed        SV_BackgroundVSpeed        b=1
 *   1fd954  background_blend           GV_BackgroundBlend         SV_BackgroundBlend         b=1
 *   1fd974  background_alpha           GV_BackgroundAlpha         SV_BackgroundAlpha         b=1
 *   1fd994  view_enabled               GV_ViewEnabled             SV_ViewEnabled             b=1
 *   1fd9b0  view_current               GV_ViewCurrent             -                          b=0
 *   1fd9d0  view_visible               GV_ViewVisible             SV_ViewVisible             b=1
 *   1fd9f0  view_xview                 GV_ViewXview               SV_ViewXview               b=1
 *   1fda10  view_yview                 GV_ViewYview               SV_ViewYview               b=1
 *   1fda30  view_wview                 GV_ViewWview               SV_ViewWview               b=1
 *   1fda50  view_hview                 GV_ViewHview               SV_ViewHview               b=1
 *   1fda70  view_xport                 GV_ViewXport               SV_ViewXport               b=1
 *   1fda90  view_yport                 GV_ViewYport               SV_ViewYport               b=1
 *   1fdab0  view_wport                 GV_ViewWport               SV_ViewWport               b=1
 *   1fdad0  view_hport                 GV_ViewHport               SV_ViewHport               b=1
 *   1fdaf0  view_angle                 GV_ViewAngle               SV_ViewAngle               b=1
 *   1fdb10  view_hborder               GV_ViewHBorder             SV_ViewHBorder             b=1
 *   1fdb30  view_vborder               GV_ViewVBorder             SV_ViewVBorder             b=1
 *   1fdb50  view_hspeed                GV_ViewHSpeed              SV_ViewHSpeed              b=1
 *   1fdb70  view_vspeed                GV_ViewVspeed              SV_ViewVSpeed              b=1
 *   1fdb90  view_object                GV_ViewObject              SV_ViewObject              b=1
 *   1fdbb0  view_surface_id            GV_ViewSurfaceID           SV_ViewSurfaceID           b=1
 *   1fdbd0  view_camera                GV_ViewCamera              SV_ViewCamera              b=1
 *   1fdbec  mouse_x                    GV_MouseX                  -                          b=0
 *   1fdc08  mouse_y                    GV_MouseY                  -                          b=0
 *   1fdc28  mouse_button               GV_MouseButton             SV_MouseButton             b=1
 *   1fdc48  mouse_lastbutton           GV_MouseLastButton         SV_MouseLastButton         b=1
 *   1fdc68  keyboard_key               GV_KeyboardKey             SV_KeyboardKey             b=1
 *   1fdc88  keyboard_lastkey           GV_KeyboardLastKey         SV_KeyboardLastKey         b=1
 *   1fdca8  keyboard_lastchar          GV_KeyboardLastChar        SV_KeyboardLastChar        b=1
 *   1fdcc8  keyboard_string            GV_KeyboardString          SV_KeyboardString          b=1
 *   1fdce8  cursor_sprite              GV_CursorSprite            SV_CursorSprite            b=1
 *   1fdd08  show_score                 GV_ShowScore               SV_ShowScore               b=1
 *   1fdd28  show_lives                 GV_ShowLives               SV_ShowLives               b=1
 *   1fdd48  show_health                GV_ShowHealth              SV_ShowHealth              b=1
 *   1fdd68  caption_score              GV_CaptionScore            SV_CaptionScore            b=1
 *   1fdd88  caption_lives              GV_CaptionLives            SV_CaptionLives            b=1
 *   1fdda8  caption_health             GV_CaptionHealth           SV_CaptionHealth           b=1
 *   1fddc4  fps                        GV_Fps                     -                          b=0
 *   1fdde0  fps_real                   GV_FpsReal                 -                          b=0
 *   1fddfc  current_time               GV_CurrentTime             -                          b=0
 *   1fde18  current_year               GV_CurrentYear             -                          b=0
 *   1fde34  current_month              GV_CurrentMonth            -                          b=0
 *   1fde50  current_day                GV_CurrentDay              -                          b=0
 *   1fde6c  current_weekday            GV_CurrentWeekday          -                          b=0
 *   1fde88  current_hour               GV_CurrentHour             -                          b=0
 *   1fdea4  current_minute             GV_CurrentMinute           -                          b=0
 *   1fdec0  current_second             GV_CurrentSecond           -                          b=0
 *   1fdedc  event_type                 GV_EventType               -                          b=0
 *   1fdef8  event_number               GV_EventNumber             -                          b=0
 *   1fdf14  event_object               GV_EventObject             -                          b=0
 *   1fdf30  event_action               GV_EventAction             -                          b=0
 *   1fdf4c  secure_mode                GV_SecureMode              -                          b=0
 *   1fdf6c  error_occurred             GV_ErrorOccurred           SV_ErrorOccurred           b=1
 *   1fdf8c  error_last                 GV_ErrorLast               SV_ErrorLast               b=1
 *   1fdfac  gamemaker_registered       GV_GamemakerRegistered     -                          b=0
 *   1fdfc4  gamemaker_pro              GV_GamemakerRegistered     -                          b=0
 *   1fdfe0  application_surface        GV_ApplicationSurface      -                          b=0
 *   1fe000  font_texture_page_size     GV_FontTexturePageSize     SV_FontTexturePageSize     b=0 *
 *   分组（按名字前缀，合计 120）：argument* 19（argument_relative/argument/argument0..15）、
 *   room* 8、background* 19、view* 19、mouse* 4、keyboard* 4、current_* 8、event* 4、game* 7、
 *   其它 28（debug_mode/pointer_invalid/pointer_null/undefined/transition_…/score/lives/health/
 *   working_directory/temp_directory/program_directory/instance_count/instance_id/cursor_sprite/
 *   show_…/caption_…/fps/fps_real/secure_mode/error_…/application_surface/font_texture_page_size）。
 *   第 4 实参：78 条传 1、42 条传 0；setter 为 NULL 的有 41 条（只读变量）。
 *   ★ 但第 4 实参在本构建里是**死参**：Variable_BuiltIn_Add 的第一条指令 `ldr r3,[pc,#0x28c]` 就把
 *     r3 覆盖掉了，函数体从头到尾没有再读它；条目 +0xc 的字节其实是 (setter != NULL) 归一出来的
 *     （0x1f4e14 adds r1,r9,#0 / 0x1f4e1c movne r1,#1 / 0x1f4e3c strb r1,[r3,#0xc]）。
 *     ⇒ 表里 b 列只是「调用点实际传了什么」，不代表被存下来的值。
 *
 * ── 已证硬事实（§1，可直接引用）────────────────────────────────────────
 *   1. 入口第一条实际动作是 banner 打印：0x29066c blx（r7 = *(0x3eb70c) 的对象，vtable+0xc = Output），
 *      串 0x3582a8 = 三行「YoYo Games Android Runner V0.1」。**先打印，再初始化**。
 *   2. JNIEnv 的唯一归处是 TLS：pthread_key_create(&0x756c04, NULL)（0x290698）→ setJNIEnv(env)
 *      （0x2906a0 → 0x290614 → pthread_setspecific）。取值只有 getJNIEnv（0x290274 → pthread_getspecific）。
 *      全库没有第二个写 env 的地方，也没有 GetJavaVM（全库 645,282 条指令里零个 `ldr rX,[rY,#0x36c]`）。
 *   3. jclass 入参被丢弃（0x290648 起 r1 改作池字），用的 class 是 FindClass 的结果，
 *      且只在 0x756d44 == 0 时做 NewGlobalRef + 注册；非 0 就直接跳到主路径 0x2906d0。
 *   4. 注册块 0x290c00..0x291a80 是**无分支直线代码**（80 个 blx = 1 NewGlobalRef + 79 GetStaticMethodID，
 *      段内没有一条 b/beq/bne），所以「第一次」必然把 79 个方法 ID 全抓一遍。
 *   5. 79 组「名字+JNI 签名」与原版 DEX 的 RunnerJNILib.java 声明 79/79 完全一致（含
 *      CallExtensionFunction 的 `(Ljava/lang/String;Ljava/lang/String;I[D[Ljava/lang/Object;)Ljava/lang/Object;`
 *      这种长签名）—— 说明这张表就是该 Java 类的静态方法快照，没有改名/重载歧义。
 *   6. APK 装载只发生在首次块里：apk 路径经 GetStringUTFChars 后**不 strdup**，裸指针直接存 0x757764
 *      并立刻交给 zip_open；包名与 save 目录是真 strdup（0x291b0c / 0x291b48）。三个串用完都
 *      ReleaseStringUTFChars（0x291c28 / 0x291c10 / 0x291c00 三条释放路径）。
 *   7. 命令行是硬编码：malloc(8192)（0x291b84）后手工抄 16 字节 "-game game.droid"（ldm/stm + strb 补 NUL），
 *      指针存 0x542988；随后 ProcessCommandLine 收到的实参就是它（RunGame 两处直接读该全局）。**Java 传进来的参数不参与命令行拼装**。
 *   8. Init() 恒返回 1：0x2a2914 是 17 条初始化调用的直线串（3 条 RomDisk/Timing/FastCRC + 12 条 INITIALIZE_* + SetupGMLFunctions + ProcessMessages），唯一出口 `mov r0,#1`（0x2a296c）。
 *      所以 0x2906e8 的 `beq 0x290878`（Init()==0 直接返回）是**死分支**，除非某个 INITIALIZE_* 长跳。
 *   9. BeginToEnd() 返回后第一件事是把 g_localInputEvents（0x756d48）整块清 0，长度 2560 = 128 × 20 B
 *      （0x290708 ldr r0 = 0x756d48 / mov r1,#0 / mov r2,#2560 / memset）。同一地址在 TouchEvent 0x291d24
 *      与 Process 0x2946d4 按 id*20 索引——三个函数互证这是输入事件环。
 *  10. 「默认 framebuffer」是一次同步 JNI 调用：getJNIEnv → CallStaticIntMethod(jclass, mid=*(0x756c70))
 *      （0x290730 走的是 _ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz 这个 C++ 包装，
 *      不是函数表），返回值同时存 0x757748 并打印。0x757748 全库只有 Graphics::SetRenderTarget 读。
 *  11. leanback / AMAZON 两个探测结果写进 0x7577b4 / 0x7577b0，而这两个地址全库**没有任何读者**
 *      （各 1 处槽引用 = 本函数的写点）—— 即「是不是 TV / 是不是 Amazon 设备」在这份 .so 里是死写入。
 *  12. sleepMargin 是唯一被写回 .data 的入参：0x290874 str r2,[r3]，r2 = [sp+0x5c]，
 *      目标 0x479a28 的初值就是 0x0a（10），并被 F_DisplayGetSleepMargin/SetSleepMargin、Timing_Sleep、
 *      Option_Load、ProcessCommandLine 共 6 处引用 —— 与「Java 传 sleepMargin」语义自洽。
 *  13. 两个 byte 门在入口被清 0（0x29067c → 0x7577bc、0x290684 → 0x479a31），而它们分别被
 *      Resume（置 1）/Process（判门）与 RunGame（置 1）/Process（读后返回 2）使用 —— 即每次 Startup
 *      都把「已 resume」「已结束」两个状态复位。
 *
 * ── 已证硬事实（§2，可直接引用）──────────────────────────────────────
 *   1. 唯一入口是尾跳：0x1ffc90 `b 0x1fd184`（INITIALIZE_Variable_BuiltIn），而它由 Init() 的
 *      0x2a294c 调用。⇒ 只要 Startup 走到 Init()，这 120 条注册就跑一次。
 *   2. 第一条语句不是注册而是快照：0x1fd1b8 `str lr,[r12]`，lr = *(0x753108)（builtin 变量条数）、
 *      r12 = 0x755064。0x753108 是 {count@0, array@4} 结构（0x75310c 是数组基址），被
 *      Variable_BuiltIn_Add / Find_Name / FINALIZE_Variable_Main / CreateNameFile / CInstance::Ctor /
 *      JS_GlobalObjectSetup 共 7 处使用；0x755064 被 F_VariableGlobalGet/Set 当下界：
 *      索引 < *(0x755064) 就返回 undefined（0x114de4 ldr r12 / 0x114de8 ldr r3 / 0x114dec cmp r1,r3 / bge）。
 *      ⇒ 快照的语义是「内置变量区的上界 = 游戏自定义全局变量的起点」。
 *   3. 120 条 Variable_BuiltIn_Add 顺序硬编码，参数形态固定：r0 = 池字算出的名字串、r1/r2 = 两个 GOT 槽
 *      取出的 getter/setter、r3 = 立即数 0/1（死参，见上）。同一 getter 只服务一个名字
 *      （argument0..15 的 GV_ 间隔 0x88、SV_ 间隔 0x30，是模板化生成的一族函数）。
 *   4. 注册完不是 return 而是 `pop {r4,r5,r6,r7,r8,lr}` + `b 0x15dafc`（InitYoYoBuiltInVariables），
 *      后者再补 5 条只读变量：os_type / os_device / os_version / os_browser / browser_width
 *      （0x15db20 / 0x15db3c / 0x15db58 / 0x15db74 / 0x15db90，getter 0x159d20/0x156f2c/0x1589e4/0x156380/0x157958）。
 *      ⇒ 整条链共注册 **125** 条内置变量。
 *   5. 表容量 500：Variable_BuiltIn_Add 入口 `cmp r3,#500; beq 0x1f5024`（满则走溢出分支），
 *      而 INITIALIZE_Variable_BuiltIn 在 0x1ffc84 memset 了 8000 B = 500 × 16 B 的数组，两处上限互证。
 *   6. 追加语义而非覆盖：Variable_BuiltIn_Add 用「当前条数」当写入下标（0x1f4de4 moveq r10,r3 /
 *      0x1f4dfc mov r10,r2 / 0x1f4e38 str r0,[r4,r10,lsl #4]），条数在末尾 +1。⇒ 本函数**不幂等**：
 *      若 Java 侧第二次调 Startup（会再走一遍 Init），这 120 条会被再追加一遍（见 open）。
 *
 * ── open（不影响本节已钉的控制流，影响命名/外部契约）─────────────────────
 *   1. §1 的两个控制台对象（0x3eb70c → 0x47a118、0x3eb708 → 0x47a114）到底是 TConsole 还是
 *      TRelConsole/TErrStreamConsole 的实例：只钉到「obj→[0] 取虚表、[vtable+0xc] 取函数、(this,fmt,...)」，
 *      与 DoTheWork 卡同源的 open；虚表指针在 .bss，静态看不到写入点。
 *   2. 0x7577b4 / 0x7577b0 无读者：可能是「预留给后续版本」或「由被裁掉的代码读」，本卡只能证「写了没人读」。
 *   3. Init() 里 16 个 INITIALIZE_* 的各自行为未出卡（本卡只用「恒返回 1」这一条）。
 *   4. 0x7577b8（本卡清 0）的正式语义：被 VertexBuffer::Init/IsValid、CreateVertexBuffer、
 *      GraphicsRecorder::Draw 读，像「当前顶点缓冲/绘制状态」的槽，但字段没展开。
 *   5. §2 里 getter/setter 内部（GV_…/SV_…）一律没读；例如 GV_Score 是读 room 还是读全局实例，
 *      本卡不证。只证「谁被注册、注册到哪张表、第 4 实参是死参」。
 *   6. 重复调用 Startup 的实际次数（Java 侧生命周期）不在本卡范围；§2 事实 6 只说明「若重入会追加」。
 *   7. Variable_BuiltIn_Add 的 CHashMap 插入细节（哈希函数 0x1eeb88、桶项 12 B、同名复用策略）未逐条读。
 *
 * ── 段注 ────────────────────────────────────────────────────────
 */


/* ══ §1 Java_com_yoyogames_runner_RunnerJNILib_Startup 0x29062c ═══════════
 * @func 0x29062c 0x291c68 size 5696  1424 条（1199 指令 + 225 池字：0x290880..0x290bfc 224 个、
 *       0x291c68 1 个；池字不是指令，逐条注明取用点）
 * 级别: 正文（A..G 七段全钉，含首次调用门的两条路、79 个方法 ID 的落点、APK 装载的每一条释放路径、
 *       两处 byte 门与四处全局写入；未钉的是两个控制台实例的具体子类与 0x7577b8 的字段语义，见 open）
 * 符号: Java_com_yoyogames_runner_RunnerJNILib_Startup（.dynsym 直出，无 C++ 修饰）
 * ABI : softfp；r0=JNIEnv*、r1=jclass、r2/r3=两个 jstring、[sp+0]=第三个 jstring、[sp+4]=int
 * 返回: void（唯一出口 0x29087c 直接 pop，不回写 r0）
 * 调用者: Java 侧 RunnerJNILib.Startup（唯一；全库没有第二处引用本符号）
 * 同层: setJNIEnv 0x290614 / getJNIEnv 0x290274 / ImportGLLibrary 0x28fce4 / ProcessCommandLine 0x2a1cf0 /
 *       Init 0x2a2914 / BeginToEnd 0x2a180c / MemoryManager::Init 0x27c23c / zip_open 0x2a4de0 /
 *       PackageManagerHasSystemFeature 0x290288 / strupr 0xc4a74 /
 *       _ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz 0xf2878
 *
 * ── 这一段在做什么（按寄存器读，不按名字猜）──────────────────────────
 *   r4 = env 贯穿全函数（0x290630）；r5 = GOT 基址 0x3f1c58（0x290644 add r5,pc,r5，池字 0x16160c）；
 *   r7 = 控制台对象 *(0x3eb70c)；r6 先当 &0x756d44（0x2906c0），在主路径里被复用成第二个控制台对象
 *   *(0x3eb708)（0x29079c）；r8 = apkFilePath 入参 → 后来当 &0x542988；r10 = saveFilesDir 入参。
 *   栈帧 88 B：局部 [sp+0x24] 存 &isCopy、[sp+0x4]/[sp+0xc]/[sp+0x18] 存三个签名串，
 *   形参区在 [sp+0x58]（packageName）/ [sp+0x5c]（sleepMargin）。
 */
/* @0x29062c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x290630 mov r4, r0 */
/* @0x290634 ldr r5, [pc, #0x244] —— r5=0x16160c (pool 0x290880) */
/* @0x290638 mov r10, r3 */
/* @0x29063c ldr r0, [pc, #0x240] —— r0=0xffffbac4 (pool 0x290884) */
/* @0x290640 sub sp, sp, #52 */
/* @0x290644 add r5, pc, r5 —— r5=0x3f1c58 [pc+0x16160c] */
/* @0x290648 ldr r1, [pc, #0x238] —— r1=0xc7c48 (pool 0x290888) */
/* @0x29064c mov r8, r2 */
/* @0x290650 mov r6, #0 */


/* ── A. banner：进入函数第一件事就是打印 ─────────────────────────────
 *   r0 = r7 = *(0x3eb70c)（控制台对象 0x47a118），r3 = [r0] → 虚表，r3 = [r3+0xc] → 输出函数，
 *   r1 = 池字 0xc7c48 + pc → 0x3582a8。该串原文三行：
 *     "\n***************************************\n*   YoYo Games Android Runner V0.1    *\n
 *      ***************************************\t \n"
 *   与 DoTheWork 的三条 trace 同一个分派形（obj→[0]→[+0xc]→blx），只是走的是 0x3eb70c 这个槽。
 */
/* @0x290654 ldr r3, [r5, r0] —— r3=GOT[0x3ed71c] | ->0x3eb70c */
/* @0x290658 add r1, pc, r1 —— r1=0x3582a8 [pc+0xc7c48] | STR "\n***************************************\n*   YoYo Games Android Runner V0.1    *\n***************************************\t \n" */
/* @0x29065c ldr r7, [r3] —— r7=*(0x3eb70c) */
/* @0x290660 ldr r3, [r7] */
/* @0x290664 mov r0, r7 */
/* @0x290668 ldr r3, [r3, #0xc] */
/* @0x29066c blx r3 —— CALL indirect */


/* ── B1. 两个 byte 门复位（都是 strb 0）─────────────────────────────
 *   0x7577bc：Resume 0x2925bc 置 1、Process 0x294560 读它决定要不要跑这一帧 ⇒ 进门先清「已 resume」。
 *   0x479a31：RunGame 0x2a2ce8 / 0x2a2dc0 置 1、Process 0x2947cc 读它并返回 2 ⇒ 进门先清「已结束」。
 *   两个槽的其它读者都按全库槽引用普查列出（各 3 / 4 处），这里只写不读。
 */
/* @0x290670 ldr r2, [pc, #0x214] —— r2=0xfffffcec (pool 0x29088c) */
/* @0x290674 ldr r3, [pc, #0x214] —— r3=0xfffffcf0 (pool 0x290890) */
/* @0x290678 ldr r2, [r5, r2] —— r2=GOT[0x3f1944] | ->0x7577bc */
/* @0x29067c strb r6, [r2] —— WRITE *(0x7577bc) <- r6 */
/* @0x290680 ldr r3, [r5, r3] —— r3=GOT[0x3f1948] | ->0x479a31 */
/* @0x290684 strb r6, [r3] —— WRITE *(0x479a31) <- r6 */


/* ── B2. GL 库导入 → 建 JNIEnv 的 TLS key → 把 env 存进去 ──────────────
 *   0x290688 ImportGLLibrary()（0x28fce4，104 B，名字即语义）。
 *   0x29068c..0x290698：r0 = &0x756c04（GOT 0x3f192c）、r1 = r6 = 0 ⇒ pthread_key_create(&0x756c04, NULL)。
 *   0x29069c..0x2906a0：setJNIEnv(env) —— 0x290614 的实参就是 r0 = r4 = env。
 *   ★ 这是全函数唯一一处把 env 落到内存的地方，落点是 TLS（pthread key 0x756c04），不是全局。
 */
/* @0x290688 bl 0x28fce4 <_Z15ImportGLLibraryv> */
/* @0x29068c ldr r3, [pc, #0x200] —— r3=0xfffffcd4 (pool 0x290894) */
/* @0x290690 mov r1, r6 */
/* @0x290694 ldr r0, [r5, r3] —— r0=GOT[0x3f192c] | ->0x756c04 */
/* @0x290698 bl 0xb6d48 <pthread_key_create@plt> */
/* @0x29069c mov r0, r4 */
/* @0x2906a0 bl 0x290614 <setJNIEnv> */


/* ── C1. FindClass：拿 RunnerJNILib 的 jclass ────────────────────────
 *   0x2906b0 `ldr r3,[r3,#0x18]` = JNIEnv 函数表下标 6 = FindClass；
 *   r1 = 池字 0xc7b50 + pc → 0x35820c = "com/yoyogames/runner/RunnerJNILib"。
 *   返回的 jclass 留在 r0，直接进下一步的门（此时 r1 已被池字覆盖，入参 jclass 从此不再使用）。
 */
/* @0x2906a4 ldr r3, [r4] —— r3=*env (JNIEnv->functions) */
/* @0x2906a8 ldr r1, [pc, #0x1e8] —— r1=0xc7b50 (pool 0x290898) */
/* @0x2906ac mov r0, r4 */
/* @0x2906b0 ldr r3, [r3, #0x18] —— r3=env->FindClass()  [+0x18] */
/* @0x2906b4 add r1, pc, r1 —— r1=0x35820c [pc+0xc7b50] | STR "com/yoyogames/runner/RunnerJNILib" */
/* @0x2906b8 blx r3 —— CALL env->FindClass() */


/* ── C2. 首次调用门：0x756d44 == 0 ? ──────────────────────────────────
 *   r6 = &0x756d44（GOT 0x3ed9ac）；`ldr r3,[r6]; cmp r3,#0; beq 0x290c00`。
 *   == 0（本进程第一次）→ 跳 0x290c00：NewGlobalRef + 79 个 GetStaticMethodID + APK 装载，
 *   做完 0x291bf4 `b 0x2906d8` 汇入主路径。
 *   != 0（再次调用）→ 直接落到 0x2906d0 主路径（跳过注册与 APK 装载，但**仍然**跑 ProcessCommandLine/Init）。
 */
/* @0x2906bc ldr r3, [pc, #0x1d8] —— r3=0xffffbd54 (pool 0x29089c) */
/* @0x2906c0 ldr r6, [r5, r3] —— r6=GOT[0x3ed9ac] | ->0x756d44 */
/* @0x2906c4 ldr r3, [r6] —— r3=*(0x756d44) */
/* @0x2906c8 cmp r3, #0 */
/* @0x2906cc beq 0x290c00 <Java_com_yoyogames_runner_RunnerJNILib_Startup+0x5d4> */


/* ── D1. 主路径开头：命令行 → Init() ────────────────────────────────
 *   r8 = &0x542988（g_cmdline）；r0 = *(0x542988) → ProcessCommandLine(arg)。
 *   0x2906e0 Init()：0x2a2914 是 17 条初始化的直线串：RomDisk::Init / Timing_Init / InitFastCRC，然后 12 条 INITIALIZE_*
 *   （PlatformSpecific / Support_File / Graphics_Draw / Code_Constant / Graphics_Window / Particle_Main /
 *   Run_Global / Sound_DirectX / Variable_BuiltIn / Path / Score / Main），最后 CCameraManager::SetupGMLFunctions
 *   + ProcessMessages，
 *   唯一出口 `mov r0,#1` ⇒ 返回值恒 1，下面的 beq 是死分支（除非某个 INITIALIZE_* 长跳）。
 *   0x2906f4 串 0xc8588 + pc = 0x358c8c "Finished Init\n"，仍走 r7 那个控制台。
 */
/* @0x2906d0 ldr r3, [pc, #0x514] —— r3=0xfffffd10 (pool 0x290bec) */
/* @0x2906d4 ldr r8, [r5, r3] —— r8=GOT[0x3f1968] | ->0x542988 */
/* @0x2906d8 ldr r0, [r8] —— r0=*(0x542988) */
/* @0x2906dc bl 0x2a1cf0 <_Z18ProcessCommandLinePc> */
/* @0x2906e0 bl 0x2a2914 <_Z4Initv> */
/* @0x2906e4 cmp r0, #0 */
/* @0x2906e8 beq 0x290878 <Java_com_yoyogames_runner_RunnerJNILib_Startup+0x24c> */
/* @0x2906ec ldr r3, [r7] */
/* @0x2906f0 mov r0, r7 */
/* @0x2906f4 ldr r1, [pc, #0x1a4] —— r1=0xc8588 (pool 0x2908a0) */
/* @0x2906f8 ldr r3, [r3, #0xc] */
/* @0x2906fc add r1, pc, r1 —— r1=0x358c8c [pc+0xc8588] | STR "Finished Init\n" */
/* @0x290700 blx r3 —— CALL indirect */


/* ── D2. BeginToEnd() 与「返回后清输入环」─────────────────────────
 *   BeginToEnd 0x2a180c 尾调 DoTheWork（见 DoTheWork 卡：srand48(2101988) → RunnerLoadWad →
 *   LoadGameData → Variable_Global_Init → PrepareGame → Run_Start）。它返回说明整局已经跑完/放弃。
 *   回来第一件事：memset(*(0x756d48), 0, 2560)。0x756d48 就是 TouchEvent/Process 按 id*20 索引的
 *   g_localInputEvents（128 槽 × 20 B），2560 = 128×20 与 live-oracle 登记一致。
 */
/* @0x290704 bl 0x2a180c <_Z10BeginToEndv> */
/* @0x290708 ldr r3, [pc, #0x194] —— r3=0xfffffcf4 (pool 0x2908a4) */
/* @0x29070c mov r1, #0 */
/* @0x290710 mov r2, #2560 */
/* @0x290714 ldr r0, [r5, r3] —— r0=GOT[0x3f194c] | ->0x756d48 */
/* @0x290718 bl 0xb65b0 <memset@plt> */


/* ── D3. 问 Java 要默认 framebuffer id，并存/打印 ──────────────────
 *   getJNIEnv() 重新取 env（同一线程，TLS 命中）；r1 = *(0x756d44) = jclass；
 *   r2 = *(0x756c70) = "GetDefaultFrameBuffer" 的 jmethodID（0x2915e8 注册，签名 "()I"）；
 *   0x290730 走 **C++ 包装** _ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz（不是函数表下标）。
 *   返回值 r0：0x290754 存 0x757748（全库只有 Graphics::SetRenderTarget 读它），
 *   0x29075c 打印 "Finished BeginToEnd, default frame buffer is: %d\n"（0x358c9c）。
 */
/* @0x29071c bl 0x290274 <getJNIEnv> */
/* @0x290720 ldr r3, [pc, #0x3bc] —— r3=0xfffffd00 (pool 0x290ae4) */
/* @0x290724 ldr r1, [r6] —— r1=*(0x756d44) */
/* @0x290728 ldr r3, [r5, r3] —— r3=GOT[0x3f1958] | ->0x756c70 */
/* @0x29072c ldr r2, [r3] —— r2=*(0x756c70) */
/* @0x290730 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz> */
/* @0x290734 ldr lr, [pc, #0x16c] —— lr=0xffffe908 (pool 0x2908a8) */
/* @0x290738 ldr r12, [r7] */
/* @0x29073c ldr r1, [pc, #0x168] —— r1=0xc8550 (pool 0x2908ac) */
/* @0x290740 ldr lr, [r5, lr] —— lr=GOT[0x3f0560] | ->0x757748 */
/* @0x290744 add r1, pc, r1 —— r1=0x358c9c [pc+0xc8550] | STR "Finished BeginToEnd, default frame buffer is: %d\n" */
/* @0x290748 ldr r12, [r12, #0xc] */
/* @0x29074c mov r3, r0 */
/* @0x290750 mov r2, r0 */
/* @0x290754 str r3, [lr] —— WRITE *(0x757748) <- r3(g) */
/* @0x290758 mov r0, r7 */
/* @0x29075c blx r12 —— CALL indirect */


/* ── D4. leanback 探测 ─────────────────────────────────────────────
 *   先把 0x7577b8 清 0（顶点缓冲槽），再 PackageManagerHasSystemFeature("android.software.leanback")
 *   （0x290288；串 0x358cd0），结果存 0x7577b4；
 *   然后 r6 = *(0x3eb708)（第二个控制台对象 0x47a114）打印 "android.software.leanback = %d\n"（0x358cec）。
 *   ⚠ 0x7577b4 全库只有这一个写点、零个读点。
 */
/* @0x290760 ldr r3, [pc, #0x148] —— r3=0xffffe90c (pool 0x2908b0) */
/* @0x290764 ldr r0, [pc, #0x148] —— r0=0xc8558 (pool 0x2908b4) */
/* @0x290768 mov r2, #0 */
/* @0x29076c ldr r3, [r5, r3] —— r3=GOT[0x3f0564] | ->0x7577b8 */
/* @0x290770 add r0, pc, r0 —— r0=0x358cd0 [pc+0xc8558] | STR "android.software.leanback" */
/* @0x290774 str r2, [r3] —— WRITE *(0x7577b8) <- r2(g) */
/* @0x290778 bl 0x290288 <_Z30PackageManagerHasSystemFeaturePKc> */
/* @0x29077c ldr r12, [pc, #0x134] —— r12=0xfffffcf8 (pool 0x2908b8) */
/* @0x290780 ldr r3, [pc, #0x134] —— r3=0xffffbcf0 (pool 0x2908bc) */
/* @0x290784 ldr r1, [pc, #0x134] —— r1=0xc8558 (pool 0x2908c0) */
/* @0x290788 ldr r12, [r5, r12] —— r12=GOT[0x3f1950] | ->0x7577b4 */
/* @0x29078c add r1, pc, r1 —— r1=0x358cec [pc+0xc8558] | STR "android.software.leanback = %d\n" */
/* @0x290790 str r0, [r12] —— WRITE *(0x7577b4) <- r0(c) */
/* @0x290794 mov r2, r0 */
/* @0x290798 ldr r3, [r5, r3] —— r3=GOT[0x3ed948] | ->0x3eb708 */
/* @0x29079c ldr r6, [r3] —— r6=*(0x3eb708) */
/* @0x2907a0 ldr r3, [r6] */
/* @0x2907a4 mov r0, r6 */
/* @0x2907a8 ldr r3, [r3, #0xc] */
/* @0x2907ac blx r3 —— CALL indirect */

/* ── D5. Build.MANUFACTURER → 大写 → 与 "AMAZON" 比 ─────────────────
 *   FindClass("android/os/Build") → GetStaticFieldID(class,"MANUFACTURER","Ljava/lang/String;")
 *   （函数表 0x240 = 144）→ GetStaticObjectField（0x244 = 145）→ GetStringUTFChars（0x2a4 = 169，
 *   &isCopy = add r2,sp,#47）。
 *   0x290820..0x29083c 用 r6 那个控制台打印 "MANUFACTURER = %s\n"（池字 0xc8500 + pc = 0x358d34）。
 *   0x290844 strupr(manufacturer) → 0x290850 strcmp(大写串, "AMAZON")（0x358d48）。
 *   0x290858..0x290868：r0 = (strcmp == 0) ? 1 : 0（`rsbs r0,r0,#1` + `movlo r0,#0`）→ 0x7577b0。
 *   0x29086c..0x290874：[sp+0x5c]（sleepMargin 入参）→ 0x479a28（.data 初值 0x0a = 10）。
 *   注意此时 r4 已从 env 改成 manufacturer 指针（0x290830 mov r4,r0）—— 后面不再需要 env。
 */
/* @0x2907b0 ldr r3, [r4] —— r3=*env (JNIEnv->functions) */
/* @0x2907b4 ldr r1, [pc, #0x108] —— r1=0xc8548 (pool 0x2908c4) */
/* @0x2907b8 mov r0, r4 */
/* @0x2907bc add r1, pc, r1 —— r1=0x358d0c [pc+0xc8548] | STR "android/os/Build" */
/* @0x2907c0 ldr r3, [r3, #0x18] —— r3=env->FindClass()  [+0x18] */
/* @0x2907c4 blx r3 —— CALL env->FindClass() */
/* @0x2907c8 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x2907cc ldr r2, [pc, #0xf4] —— r2=0xb9164 (pool 0x2908c8) */
/* @0x2907d0 ldr r3, [pc, #0xf4] —— r3=0xc853c (pool 0x2908cc) */
/* @0x2907d4 ldr r12, [r12, #0x240] —— r12=env->GetStaticFieldID()  [+0x240] */
/* @0x2907d8 add r2, pc, r2 —— r2=0x349944 [pc+0xb9164] | STR "MANUFACTURER" */
/* @0x2907dc add r3, pc, r3 —— r3=0x358d20 [pc+0xc853c] | STR "Ljava/lang/String;" */
/* @0x2907e0 mov r1, r0 */
/* @0x2907e4 mov r7, r0 */
/* @0x2907e8 mov r0, r4 */
/* @0x2907ec blx r12 —— CALL env->GetStaticFieldID() */
/* @0x2907f0 ldr r3, [r4] —— r3=*env (JNIEnv->functions) */
/* @0x2907f4 mov r1, r7 */
/* @0x2907f8 ldr r3, [r3, #0x244] —— r3=env->GetStaticObjectField()  [+0x244] */
/* @0x2907fc mov r2, r0 */
/* @0x290800 mov r0, r4 */
/* @0x290804 blx r3 —— CALL env->GetStaticObjectField() */
/* @0x290808 ldr r3, [r4] —— r3=*env (JNIEnv->functions) */
/* @0x29080c add r2, sp, #47 */
/* @0x290810 ldr r3, [r3, #0x2a4] —— r3=env->GetStringUTFChars()  [+0x2a4] */
/* @0x290814 mov r1, r0 */
/* @0x290818 mov r0, r4 */
/* @0x29081c blx r3 —— CALL env->GetStringUTFChars() */
/* @0x290820 ldr r3, [r6] */
/* @0x290824 ldr r1, [pc, #0xa4] —— r1=0xc8500 (pool 0x2908d0) */
/* @0x290828 ldr r3, [r3, #0xc] */
/* @0x29082c add r1, pc, r1 —— r1=0x358d34 [pc+0xc8500] | STR "MANUFACTURER = %s\n" */
/* @0x290830 mov r4, r0 */
/* @0x290834 mov r0, r6 */
/* @0x290838 mov r2, r4 */
/* @0x29083c blx r3 —— CALL indirect */
/* @0x290840 mov r0, r4 */
/* @0x290844 bl 0xc4a74 <_Z6struprPc> */
/* @0x290848 ldr r1, [pc, #0x84] —— r1=0xc84f4 (pool 0x2908d4) */
/* @0x29084c add r1, pc, r1 —— r1=0x358d48 [pc+0xc84f4] | STR "AMAZON" */
/* @0x290850 bl 0xb6574 <strcmp@plt> */
/* @0x290854 ldr r2, [pc, #0x7c] —— r2=0xfffffcfc (pool 0x2908d8) */
/* @0x290858 ldr r3, [pc, #0x7c] —— r3=0xffffc964 (pool 0x2908dc) */
/* @0x29085c ldr r2, [r5, r2] —— r2=GOT[0x3f1954] | ->0x7577b0 */
/* @0x290860 rsbs r0, r0, #1 */
/* @0x290864 movlo r0, #0 */
/* @0x290868 str r0, [r2] —— WRITE *(0x7577b0) <- r0(env) */
/* @0x29086c ldr r2, [sp, #0x5c] */
/* @0x290870 ldr r3, [r5, r3] —— r3=GOT[0x3ee5bc] | ->0x479a28 */
/* @0x290874 str r2, [r3] —— WRITE *(0x479a28) <- r2(g) */


/* ── D6. 唯一出口 ──────────────────────────────────────────────────
 *   add sp,#52 / pop {r4..r11,pc}：不留返回值。紧接着就是 224 个池字（0x290880..0x290bfc），
 *   objdump 把它们译成 andseq/andeq/muleq/strheq 等，本卡逐条按「池字」标注取用点。
 */
/* @0x290878 add sp, sp, #52 */
/* @0x29087c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x290880 andseq r1, r6, r12, lsl #12 —— GOT 基址偏移 → r5 = 0x3f1c58（0x290634 取用） */
/* @0x290884 .word 0xffffbac4 —— GOT 偏移 → 槽 0x3ed71c → 0x3eb70c（0x29063c 取用） */
/* @0x290888 andeq r7, r12, r8, asr #24 —— pc 相对串偏移 → "\n***************************************\n*   YoYo Games Android Runner V0.1    *\n***************************************\t \n"（0x290648 取用） */
/* @0x29088c .word 0xfffffcec —— GOT 偏移 → 槽 0x3f1944 → 0x7577bc（0x290670 取用） */
/* @0x290890 .word 0xfffffcf0 —— GOT 偏移 → 槽 0x3f1948 → 0x479a31（0x290674 取用） */
/* @0x290894 .word 0xfffffcd4 —— GOT 偏移 → 槽 0x3f192c → 0x756c04（0x29068c 取用） */
/* @0x290898 andeq r7, r12, r0, asr r11 —— pc 相对串偏移 → "com/yoyogames/runner/RunnerJNILib"（0x2906a8 取用） */
/* @0x29089c .word 0xffffbd54 —— GOT 偏移 → 槽 0x3ed9ac → 0x756d44（0x2906bc 取用） */
/* @0x2908a0 andeq r8, r12, r8, lsl #11 —— pc 相对串偏移 → "Finished Init\n"（0x2906f4 取用） */
/* @0x2908a4 .word 0xfffffcf4 —— GOT 偏移 → 槽 0x3f194c → 0x756d48（0x290708 取用） */
/* @0x2908a8 .word 0xffffe908 —— GOT 偏移 → 槽 0x3f0560 → 0x757748（0x290734 取用） */
/* @0x2908ac andeq r8, r12, r0, asr r5 —— pc 相对串偏移 → "Finished BeginToEnd, default frame buffer is: %d\n"（0x29073c 取用） */
/* @0x2908b0 .word 0xffffe90c —— GOT 偏移 → 槽 0x3f0564 → 0x7577b8（0x290760 取用） */
/* @0x2908b4 andeq r8, r12, r8, asr r5 —— pc 相对串偏移 → "android.software.leanback"（0x290764 取用） */
/* @0x2908b8 .word 0xfffffcf8 —— GOT 偏移 → 槽 0x3f1950 → 0x7577b4（0x29077c 取用） */
/* @0x2908bc .word 0xffffbcf0 —— GOT 偏移 → 槽 0x3ed948 → 0x3eb708（0x290780 取用） */
/* @0x2908c0 andeq r8, r12, r8, asr r5 —— pc 相对串偏移 → "android.software.leanback = %d\n"（0x290784 取用） */
/* @0x2908c4 andeq r8, r12, r8, asr #10 —— pc 相对串偏移 → "android/os/Build"（0x2907b4 取用） */
/* @0x2908c8 andeq r9, r11, r4, ror #2 —— pc 相对串偏移 → "MANUFACTURER"（0x2907cc 取用） */
/* @0x2908cc andeq r8, r12, r12, lsr r5 —— pc 相对串偏移 → "Ljava/lang/String;"（0x2907d0 取用） */
/* @0x2908d0 andeq r8, r12, r0, lsl #10 —— pc 相对串偏移 → "MANUFACTURER = %s\n"（0x290824 取用） */
/* @0x2908d4 strdeq r8, r9, [r12], -r4 —— pc 相对串偏移 → "AMAZON"（0x290848 取用） */
/* @0x2908d8 .word 0xfffffcfc —— GOT 偏移 → 槽 0x3f1954 → 0x7577b0（0x290854 取用） */
/* @0x2908dc .word 0xffffc964 —— GOT 偏移 → 槽 0x3ee5bc → 0x479a28（0x290858 取用） */
/* @0x2908e0 andeq r7, r12, r0, lsl #14 —— pc 相对串偏移 → "(Ljava/lang/String;)V"（0x290c1c 取用） */
/* @0x2908e4 strdeq r7, r8, [r12], -r0 —— pc 相对串偏移 → "OpenURL"（0x290c20 取用） */
/* @0x2908e8 andeq r7, r12, r0, lsl r7 —— pc 相对串偏移 → "(Ljava/lang/String;I)V"（0x290c30 取用） */
/* @0x2908ec andeq r7, r12, r4, lsr r7 —— pc 相对串偏移 → "(Ljava/lang/String;F)V"（0x290c38 取用） */
/* @0x2908f0 .word 0xffffe2cc —— GOT 偏移 → 槽 0x3eff24 → 0x756d40（0x290c5c 取用） */
/* @0x2908f4 andeq r7, r12, r8, asr #13 —— pc 相对串偏移 → "SendHighScore"（0x290c68 取用） */
/* @0x2908f8 andeq r7, r12, r12, lsr r7 —— pc 相对串偏移 → "()V"（0x290c78 取用） */
/* @0x2908fc .word 0xffffe304 —— GOT 偏移 → 槽 0x3eff5c → 0x756d3c（0x290c94 取用） */
/* @0x290900 strheq r7, [r12], -r12 —— pc 相对串偏移 → "SendAchievement"（0x290c98 取用） */
/* @0x290904 .word 0xffffe30c —— GOT 偏移 → 槽 0x3eff64 → 0x756d38（0x290cc0 取用） */
/* @0x290908 strheq r7, [r12], -r8 —— pc 相对串偏移 → "IncrementAchievement"（0x290cc4 取用） */
/* @0x29090c andeq r7, r12, r8, ror #16 —— pc 相对串偏移 → "(III)V"（0x290cd8 取用） */
/* @0x290910 .word 0xffffe308 —— GOT 偏移 → 槽 0x3eff60 → 0x756d34（0x290cf4 取用） */
/* @0x290914 muleq r12, r12, r6 —— pc 相对串偏移 → "OpenAchievements"（0x290cf8 取用） */
/* @0x290918 .word 0xffffe2dc —— GOT 偏移 → 槽 0x3eff34 → 0x756d30（0x290d20 取用） */
/* @0x29091c andeq r7, r12, r8, lsl #13 —— pc 相对串偏移 → "OpenLeaderboards"（0x290d24 取用） */
/* @0x290920 .word 0xffffe2f8 —— GOT 偏移 → 槽 0x3eff50 → 0x756d2c（0x290d4c 取用） */
/* @0x290924 andeq r11, r11, r0, lsr #15 —— pc 相对串偏移 → "()I"（0x290d50 取用） */
/* @0x290928 andeq r7, r12, r12, ror #12 —— pc 相对串偏移 → "OsGetInfo"（0x290d54 取用） */
/* @0x29092c .word 0xffffe2bc —— GOT 偏移 → 槽 0x3eff14 → 0x756d28（0x290d80 取用） */
/* @0x290930 andeq r7, r12, r8, asr #12 —— pc 相对串偏移 → "AchievementLoadFriends"（0x290d84 取用） */
/* @0x290934 .word 0xffffe2ec —— GOT 偏移 → 槽 0x3eff44 → 0x756d24（0x290dac 取用） */
/* @0x290938 andeq r7, r12, r8, lsr r6 —— pc 相对串偏移 → "AchievementLoadLeaderboard"（0x290db0 取用） */
/* @0x29093c andeq r7, r12, r12, asr #12 —— pc 相对串偏移 → "(Ljava/lang/String;III)V"（0x290dc0 取用） */
/* @0x290940 .word 0xffffe2e4 —— GOT 偏移 → 槽 0x3eff3c → 0x756d20（0x290ddc 取用） */
/* @0x290944 andeq r7, r12, r0, asr #12 —— pc 相对串偏移 → "CallExtensionFunction"（0x290de0 取用） */
/* @0x290948 andeq r7, r12, r0, asr r6 —— pc 相对串偏移 → "(Ljava/lang/String;Ljava/lang/String;I[D[Ljava/lang/Object;)Ljava/lang/Object;"（0x290df0 取用） */
/* @0x29094c .word 0xfffff76c —— GOT 偏移 → 槽 0x3f13c4 → 0x756d1c（0x290e0c 取用） */
/* @0x290950 andeq r7, r12, r8, ror r6 —— pc 相对串偏移 → "AchievementLoadPic"（0x290e10 取用） */
/* @0x290954 .word 0xffffe2f0 —— GOT 偏移 → 槽 0x3eff48 → 0x756d18（0x290e38 取用） */
/* @0x290958 andeq r7, r12, r0, ror #12 —— pc 相对串偏移 → "AchievementShow"（0x290e3c 取用） */
/* @0x29095c andeq r7, r12, r8, ror #12 —— pc 相对串偏移 → "(ILjava/lang/String;I)V"（0x290e4c 取用） */
/* @0x290960 .word 0xffffe2e0 —— GOT 偏移 → 槽 0x3eff38 → 0x756d14（0x290e68 取用） */
/* @0x290964 andeq r7, r12, r8, asr r6 —— pc 相对串偏移 → "AchievementEvent"（0x290e6c 取用） */
/* @0x290968 .word 0xffffe2f4 —— GOT 偏移 → 槽 0x3eff4c → 0x756d10（0x290e94 取用） */
/* @0x29096c andeq r7, r12, r0, asr #12 —— pc 相对串偏移 → "AchievementGetInfo"（0x290e98 取用） */
/* @0x290970 .word 0xffffe2e8 —— GOT 偏移 → 槽 0x3eff40 → 0x756d0c（0x290ec0 取用） */
/* @0x290974 andeq r7, r12, r4, lsr #12 —— pc 相对串偏移 → "AchievementLogin"（0x290ec4 取用） */
/* @0x290978 .word 0xffffe2d4 —— GOT 偏移 → 槽 0x3eff2c → 0x756d08（0x290eec 取用） */
/* @0x29097c andeq r7, r12, r0, lsl r6 —— pc 相对串偏移 → "AchievementLoginStatus"（0x290ef0 取用） */
/* @0x290980 .word 0xffffe2d0 —— GOT 偏移 → 槽 0x3eff28 → 0x756d04（0x290f18 取用） */
/* @0x290984 strdeq r7, r8, [r12], -r8 —— pc 相对串偏移 → "AchievementLogout"（0x290f1c 取用） */
/* @0x290988 .word 0xffffe2d8 —— GOT 偏移 → 槽 0x3eff30 → 0x756d00（0x290f44 取用） */
/* @0x29098c andeq r7, r12, r0, ror #11 —— pc 相对串偏移 → "EnableAds"（0x290f48 取用） */
/* @0x290990 .word 0xffffe22c —— GOT 偏移 → 槽 0x3efe84 → 0x756cfc（0x290f70 取用） */
/* @0x290994 andeq r7, r12, r8, asr #11 —— pc 相对串偏移 → "MoveAds"（0x290f74 取用） */
/* @0x290998 muleq r12, r12, r6 —— pc 相对串偏移 → "([Ljava/lang/String;)V"（0x290f88 取用） */
/* @0x29099c .word 0xffffe228 —— GOT 偏移 → 槽 0x3efe80 → 0x756cf8（0x290fa4 取用） */
/* @0x2909a0 andeq r7, r12, r0, lsr #11 —— pc 相对串偏移 → "AdsSetup"（0x290fa8 取用） */
/* @0x2909a4 .word 0xffffe224 —— GOT 偏移 → 槽 0x3efe7c → 0x756ce8（0x290fd0 取用） */
/* @0x2909a8 muleq r12, r0, r5 —— pc 相对串偏移 → "(I)V"（0x290fd4 取用） */
/* @0x2909ac andeq r7, r12, r0, ror r5 —— pc 相对串偏移 → "DisableAds"（0x290fec 取用） */
/* @0x2909b0 .word 0xffffe230 —— GOT 偏移 → 槽 0x3efe88 → 0x756cf4（0x291008 取用） */
/* @0x2909b4 andeq r7, r12, r12, asr r5 —— pc 相对串偏移 → "AdsEvent"（0x29100c 取用） */
/* @0x2909b8 .word 0xffffe234 —— GOT 偏移 → 槽 0x3efe8c → 0x756cf0（0x291034 取用） */
/* @0x2909bc andeq r7, r12, r12, lsr r5 —— pc 相对串偏移 → "AdsEventPreload"（0x291038 取用） */
/* @0x2909c0 .word 0xffffe238 —— GOT 偏移 → 槽 0x3efe90 → 0x756cec（0x291060 取用） */
/* @0x2909c4 andeq r7, r12, r4, lsr r5 —— pc 相对串偏移 → "(I)I"（0x291064 取用） */
/* @0x2909c8 andeq r7, r12, r8, lsl r5 —— pc 相对串偏移 → "AdsDisplayWidth"（0x291068 取用） */
/* @0x2909cc .word 0xffffe23c —— GOT 偏移 → 槽 0x3efe94 → 0x756ce4（0x291094 取用） */
/* @0x2909d0 andeq r7, r12, r4, lsl #10 —— pc 相对串偏移 → "AdsDisplayHeight"（0x291098 取用） */
/* @0x2909d4 .word 0xffffe240 —— GOT 偏移 → 槽 0x3efe98 → 0x756ce0（0x2910c0 取用） */
/* @0x2909d8 andeq r7, r12, r12, ror #9 —— pc 相对串偏移 → "LeaveRating"（0x2910c4 取用） */
/* @0x2909dc strdeq r7, r8, [r12], -r0 —— pc 相对串偏移 → "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"（0x2910d4 取用） */
/* @0x2909e0 .word 0xffffe244 —— GOT 偏移 → 槽 0x3efe9c → 0x756cdc（0x2910f0 取用） */
/* @0x2909e4 andeq r7, r12, r0, lsl r5 —— pc 相对串偏移 → "EnableInAppBilling"（0x2910f4 取用） */
/* @0x2909e8 .word 0xffffe310 —— GOT 偏移 → 槽 0x3eff68 → 0x756cd8（0x29111c 取用） */
/* @0x2909ec andeq r7, r12, r0, lsl r5 —— pc 相对串偏移 → "RestoreInAppPurchases"（0x291120 取用） */
/* @0x2909f0 .word 0xffffe314 —— GOT 偏移 → 槽 0x3eff6c → 0x756cd4（0x291148 取用） */
/* @0x2909f4 andeq r7, r12, r12, lsl r5 —— pc 相对串偏移 → "(Ljava/lang/String;Ljava/lang/String;I)V"（0x29114c 取用） */
/* @0x2909f8 strdeq r7, r8, [r12], -r0 —— pc 相对串偏移 → "AcquireInAppPurchase"（0x291164 取用） */
/* @0x2909fc .word 0xffffe318 —— GOT 偏移 → 槽 0x3eff70 → 0x756cd0（0x291180 取用） */
/* @0x290a00 andeq r7, r12, r12, lsl #10 —— pc 相对串偏移 → "ConsumeInAppPurchase"（0x291184 取用） */
/* @0x290a04 andeq r7, r12, r12, lsl r5 —— pc 相对串偏移 → "(Ljava/lang/String;Ljava/lang/String;)V"（0x291194 取用） */
/* @0x290a08 .word 0xffffe31c —— GOT 偏移 → 槽 0x3eff74 → 0x756ccc（0x2911b0 取用） */
/* @0x290a0c andeq r7, r12, r12, lsl r5 —— pc 相对串偏移 → "GetInAppPurchaseDetail"（0x2911b4 取用） */
/* @0x290a10 .word 0xffffe320 —— GOT 偏移 → 槽 0x3eff78 → 0x756cc8（0x2911dc 取用） */
/* @0x290a14 andeq r7, r12, r8, lsl #10 —— pc 相对串偏移 → "FacebookInit"（0x2911e0 取用） */
/* @0x290a18 .word 0xffffe25c —— GOT 偏移 → 槽 0x3efeb4 → 0x756cc4（0x291208 取用） */
/* @0x290a1c andeq r7, r12, r8, ror #9 —— pc 相对串偏移 → "FacebookLogin"（0x29120c 取用） */
/* @0x290a20 muleq r12, r0, r5 —— pc 相对串偏移 → "(Ljava/lang/String;[Ljava/lang/String;I)V"（0x291220 取用） */
/* @0x290a24 .word 0xffffe2b0 —— GOT 偏移 → 槽 0x3eff08 → 0x756cc0（0x29123c 取用） */
/* @0x290a28 andeq r7, r12, r0, ror #9 —— pc 相对串偏移 → "()Ljava/lang/String;"（0x291240 取用） */
/* @0x290a2c andeq r7, r12, r0, asr #9 —— pc 相对串偏移 → "FacebookAccessToken"（0x291244 取用） */
/* @0x290a30 .word 0xffffe274 —— GOT 偏移 → 槽 0x3efecc → 0x756ca8（0x291270 取用） */
/* @0x290a34 andeq r7, r12, r0, asr #9 —— pc 相对串偏移 → "FacebookUserId"（0x291274 取用） */
/* @0x290a38 .word 0xffffe270 —— GOT 偏移 → 槽 0x3efec8 → 0x756ca4（0x29129c 取用） */
/* @0x290a3c andeq r7, r12, r4, lsr #9 —— pc 相对串偏移 → "FacebookGraphRequest"（0x2912a0 取用） */
/* @0x290a40 strheq r7, [r12], -r4 —— pc 相对串偏移 → "(Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;I)V"（0x2912b0 取用） */
/* @0x290a44 .word 0xffffe264 —— GOT 偏移 → 槽 0x3efebc → 0x756cbc（0x2912cc 取用） */
/* @0x290a48 andeq r7, r12, r4, asr #9 —— pc 相对串偏移 → "FacebookDialog"（0x2912d0 取用） */
/* @0x290a4c .word 0xffffe2b8 —— GOT 偏移 → 槽 0x3eff10 → 0x756cb8（0x2912f8 取用） */
/* @0x290a50 ldrdeq r7, r8, [r12], -r4 —— pc 相对串偏移 → "FacebookInviteDialog"（0x2912fc 取用） */
/* @0x290a54 andeq r7, r12, r12, lsr #13 —— pc 相对串偏移 → "(Ljava/lang/String;)I"（0x291310 取用） */
/* @0x290a58 .word 0xffffe268 —— GOT 偏移 → 槽 0x3efec0 → 0x756cb4（0x29132c 取用） */
/* @0x290a5c strheq r7, [r12], -r8 —— pc 相对串偏移 → "FacebookLogout"（0x291330 取用） */
/* @0x290a60 .word 0xffffe26c —— GOT 偏移 → 槽 0x3efec4 → 0x756cb0（0x291358 取用） */
/* @0x290a64 andeq r7, r12, r0, lsr #9 —— pc 相对串偏移 → "FacebookLoginStatus"（0x29135c 取用） */
/* @0x290a68 .word 0xffffe278 —— GOT 偏移 → 槽 0x3efed0 → 0x756cac（0x291384 取用） */
/* @0x290a6c andeq r7, r12, r8, lsl #9 —— pc 相对串偏移 → "FacebookCheckPermission"（0x291388 取用） */
/* @0x290a70 andeq r6, r12, r12, ror #29 —— pc 相对串偏移 → "(Ljava/lang/String;)Z"（0x291398 取用） */
/* @0x290a74 .word 0xffffe260 —— GOT 偏移 → 槽 0x3efeb8 → 0x756ca0（0x2913b4 取用） */
/* @0x290a78 andeq r7, r12, r0, ror r4 —— pc 相对串偏移 → "FacebookRequestPermissions"（0x2913b8 取用） */
/* @0x290a7c andeq r7, r12, r4, lsl #9 —— pc 相对串偏移 → "([Ljava/lang/String;Z)I"（0x2913c8 取用） */
/* @0x290a80 .word 0xffffe2b4 —— GOT 偏移 → 槽 0x3eff0c → 0x756c9c（0x2913e4 取用） */
/* @0x290a84 andeq r7, r12, r4, ror r4 —— pc 相对串偏移 → "HttpGet"（0x2913e8 取用） */
/* @0x290a88 .word 0xffffea0c —— GOT 偏移 → 槽 0x3f0664 → 0x756c98（0x291410 取用） */
/* @0x290a8c andeq r7, r12, r0, asr r4 —— pc 相对串偏移 → "HttpPost"（0x291414 取用） */
/* @0x290a90 .word 0xffffea10 —— GOT 偏移 → 槽 0x3f0668 → 0x756c94（0x29143c 取用） */
/* @0x290a94 andeq r7, r12, r0, lsr r4 —— pc 相对串偏移 → "HttpRequest"（0x291440 取用） */
/* @0x290a98 andeq r7, r12, r4, lsr r4 —— pc 相对串偏移 → "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[BI)V"（0x291450 取用） */
/* @0x290a9c .word 0xffffea14 —— GOT 偏移 → 槽 0x3f066c → 0x756c90（0x29146c 取用） */
/* @0x290aa0 andeq r7, r12, r8, asr #8 —— pc 相对串偏移 → "ClearGamepads"（0x291470 取用） */
/* @0x290aa4 .word 0xffffea18 —— GOT 偏移 → 槽 0x3f0670 → 0x756c74（0x291498 取用） */
/* @0x290aa8 andeq r7, r12, r0, lsr r4 —— pc 相对串偏移 → "PlayMP3"（0x29149c 取用） */
/* @0x290aac .word 0xfffff80c —— GOT 偏移 → 槽 0x3f1464 → 0x756c8c（0x2914c4 取用） */
/* @0x290ab0 andeq r7, r12, r8, lsl #8 —— pc 相对串偏移 → "StopMP3"（0x2914c8 取用） */
/* @0x290ab4 .word 0xfffff818 —— GOT 偏移 → 槽 0x3f1470 → 0x756c88（0x2914f0 取用） */
/* @0x290ab8 andeq r7, r12, r4, ror #7 —— pc 相对串偏移 → "PauseMP3"（0x2914f4 取用） */
/* @0x290abc .word 0xfffff810 —— GOT 偏移 → 槽 0x3f1468 → 0x756c84（0x29151c 取用） */
/* @0x290ac0 andeq r7, r12, r4, asr #7 —— pc 相对串偏移 → "ResumeMP3"（0x291520 取用） */
/* @0x290ac4 .word 0xfffff814 —— GOT 偏移 → 槽 0x3f146c → 0x756c80（0x291548 取用） */
/* @0x290ac8 andeq r7, r12, r8, lsr #7 —— pc 相对串偏移 → "SetMP3Volume"（0x29154c 取用） */
/* @0x290acc strheq r7, [r12], -r0 —— pc 相对串偏移 → "(F)V"（0x29155c 取用） */
/* @0x290ad0 .word 0xfffff81c —— GOT 偏移 → 槽 0x3f1474 → 0x756c7c（0x291578 取用） */
/* @0x290ad4 andeq r7, r12, r0, lsr #7 —— pc 相对串偏移 → "()Z"（0x29157c 取用） */
/* @0x290ad8 andeq r7, r12, r0, lsl #7 —— pc 相对串偏移 → "PlayingMP3"（0x291594 取用） */
/* @0x290adc .word 0xfffff820 —— GOT 偏移 → 槽 0x3f1478 → 0x756c78（0x2915b0 取用） */
/* @0x290ae0 andeq r7, r12, r8, ror #6 —— pc 相对串偏移 → "GetDefaultFrameBuffer"（0x2915b4 取用） */
/* @0x290ae4 .word 0xfffffd00 —— GOT 偏移 → 槽 0x3f1958 → 0x756c70（0x290720 取用） */
/* @0x290ae8 andeq r7, r12, r4, asr r3 —— pc 相对串偏移 → "ShowMessage"（0x2915e0 取用） */
/* @0x290aec .word 0xffffbd58 —— GOT 偏移 → 槽 0x3ed9b0 → 0x756c6c（0x291608 取用） */
/* @0x290af0 andeq r7, r12, r4, lsr r3 —— pc 相对串偏移 → "setSystemUIVisibilityFlags"（0x29160c 取用） */
/* @0x290af4 .word 0xffffe220 —— GOT 偏移 → 槽 0x3efe78 → 0x756c68（0x291634 取用） */
/* @0x290af8 andeq r7, r12, r4, lsr #6 —— pc 相对串偏移 → "InputString"（0x291638 取用） */
/* @0x290afc andeq r7, r12, r8, lsr #6 —— pc 相对串偏移 → "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;"（0x291648 取用） */
/* @0x290b00 .word 0xffffc1ac —— GOT 偏移 → 槽 0x3ede04 → 0x756c64（0x291664 取用） */
/* @0x290b04 andeq r7, r12, r8, lsr r3 —— pc 相对串偏移 → "ShowQuestion"（0x291668 取用） */
/* @0x290b08 .word 0xffffc1b0 —— GOT 偏移 → 槽 0x3ede08 → 0x756c60（0x291690 取用） */
/* @0x290b0c andeq r7, r12, r8, lsr r3 —— pc 相对串偏移 → "ShowMessageAsync"（0x291694 取用） */
/* @0x290b10 .word 0xffffc1c0 —— GOT 偏移 → 槽 0x3ede18 → 0x756c3c（0x2916bc 取用） */
/* @0x290b14 andeq r7, r12, r0, lsr #6 —— pc 相对串偏移 → "InputStringAsync"（0x2916c0 取用） */
/* @0x290b18 .word 0xffffc1b4 —— GOT 偏移 → 槽 0x3ede0c → 0x756c38（0x2916e8 取用） */
/* @0x290b1c andeq r7, r12, r8, lsl #6 —— pc 相对串偏移 → "ShowQuestionAsync"（0x2916ec 取用） */
/* @0x290b20 .word 0xffffc1b8 —— GOT 偏移 → 槽 0x3ede10 → 0x756c34（0x291714 取用） */
/* @0x290b24 strdeq r7, r8, [r12], -r0 —— pc 相对串偏移 → "ShowLogin"（0x291718 取用） */
/* @0x290b28 .word 0xffffc1bc —— GOT 偏移 → 槽 0x3ede14 → 0x756c5c（0x291740 取用） */
/* @0x290b2c ldrdeq r7, r8, [r12], -r0 —— pc 相对串偏移 → "RestrictOrientation"（0x291744 取用） */
/* @0x290b30 ldrdeq r7, r8, [r12], -r12 —— pc 相对串偏移 → "(ZZZZZ)V"（0x291754 取用） */
/* @0x290b34 .word 0xffffe27c —— GOT 偏移 → 槽 0x3efed4 → 0x756c58（0x291770 取用） */
/* @0x290b38 andeq r7, r12, r0, asr #5 —— pc 相对串偏移 → "isNetworkConnected"（0x291774 取用） */
/* @0x290b3c .word 0xffffe290 —— GOT 偏移 → 槽 0x3efee8 → 0x756c54（0x29179c 取用） */
/* @0x290b40 andeq r7, r12, r4, lsr #5 —— pc 相对串偏移 → "CheckPermission"（0x2917a0 取用） */
/* @0x290b44 .word 0xffffe298 —— GOT 偏移 → 槽 0x3efef0 → 0x756c50（0x2917c8 取用） */
/* @0x290b48 andeq r7, r12, r12, lsl #5 —— pc 相对串偏移 → "RequestPermission"（0x2917cc 取用） */
/* @0x290b4c .word 0xffffe29c —— GOT 偏移 → 槽 0x3efef4 → 0x756c4c（0x2917f4 取用） */
/* @0x290b50 andeq r7, r12, r4, ror r2 —— pc 相对串偏移 → "powersaveEnable"（0x2917f8 取用） */
/* @0x290b54 andeq r7, r12, r12, ror r2 —— pc 相对串偏移 → "(Z)V"（0x291808 取用） */
/* @0x290b58 .word 0xffffe294 —— GOT 偏移 → 槽 0x3efeec → 0x756c48（0x291824 取用） */
/* @0x290b5c andeq r7, r12, r12, asr r2 —— pc 相对串偏移 → "analyticsEvent"（0x291828 取用） */
/* @0x290b60 .word 0xffffe2a0 —— GOT 偏移 → 槽 0x3efef8 → 0x756c44（0x291850 取用） */
/* @0x290b64 andeq r7, r12, r0, asr #4 —— pc 相对串偏移 → "analyticsEventExt"（0x291854 取用） */
/* @0x290b68 andeq r7, r12, r12, asr #4 —— pc 相对串偏移 → "(Ljava/lang/String;[Ljava/lang/String;)V"（0x291864 取用） */
/* @0x290b6c .word 0xffffe2a4 —— GOT 偏移 → 槽 0x3efefc → 0x756c40（0x291880 取用） */
/* @0x290b70 andeq r7, r12, r0, asr r2 —— pc 相对串偏移 → "cloudStringSave"（0x291884 取用） */
/* @0x290b74 .word 0xffffe2fc —— GOT 偏移 → 槽 0x3eff54 → 0x756c30（0x2918ac 取用） */
/* @0x290b78 andeq r7, r12, r4, lsr r2 —— pc 相对串偏移 → "cloudSynchronise"（0x2918b0 取用） */
/* @0x290b7c .word 0xffffe300 —— GOT 偏移 → 槽 0x3eff58 → 0x756c2c（0x2918d8 取用） */
/* @0x290b80 andeq r7, r12, r8, lsl r2 —— pc 相对串偏移 → "DumpUsedMemory"（0x2918dc 取用） */
/* @0x290b84 .word 0xfffffd04 —— GOT 偏移 → 槽 0x3f195c → 0x756c28（0x291904 取用） */
/* @0x290b88 andeq r7, r12, r0, lsl #4 —— pc 相对串偏移 → "SetLaunchedFromPlayer"（0x291908 取用） */
/* @0x290b8c andeq r7, r12, r0, lsl r2 —— pc 相对串偏移 → "(Ljava/lang/String;Z)V"（0x291918 取用） */
/* @0x290b90 .word 0xffffe2ac —— GOT 偏移 → 槽 0x3eff04 → 0x756c24（0x291934 取用） */
/* @0x290b94 andeq r7, r12, r0, lsl #4 —— pc 相对串偏移 → "UsingGL2"（0x291938 取用） */
/* @0x290b98 .word 0xfffffd08 —— GOT 偏移 → 槽 0x3f1960 → 0x756c20（0x291960 取用） */
/* @0x290b9c andeq r7, r12, r0, ror #3 —— pc 相对串偏移 → "PushLocalNotification"（0x291964 取用） */
/* @0x290ba0 strdeq r7, r8, [r12], -r0 —— pc 相对串偏移 → "(FLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"（0x291974 取用） */
/* @0x290ba4 .word 0xffffe324 —— GOT 偏移 → 槽 0x3eff7c → 0x756c1c（0x291990 取用） */
/* @0x290ba8 andeq r7, r12, r4, lsl #4 —— pc 相对串偏移 → "PushGetLocalNotification"（0x291994 取用） */
/* @0x290bac andeq r10, r11, r0, ror #23 —— pc 相对串偏移 → "(II)I"（0x2919a4 取用） */
/* @0x290bb0 .word 0xffffe328 —— GOT 偏移 → 槽 0x3eff80 → 0x756c18（0x2919c0 取用） */
/* @0x290bb4 strdeq r7, r8, [r12], -r0 —— pc 相对串偏移 → "PushCancelLocalNotification"（0x2919c4 取用） */
/* @0x290bb8 .word 0xffffe32c —— GOT 偏移 → 槽 0x3eff84 → 0x756c14（0x2919ec 取用） */
/* @0x290bbc andeq r7, r12, r0, ror #3 —— pc 相对串偏移 → "GetUDID"（0x2919f0 取用） */
/* @0x290bc0 .word 0xffffe2a8 —— GOT 偏移 → 槽 0x3eff00 → 0x756c10（0x291a18 取用） */
/* @0x290bc4 strheq r7, [r12], -r8 —— pc 相对串偏移 → "WaitForVsync"（0x291a1c 取用） */
/* @0x290bc8 .word 0xfffffce4 —— GOT 偏移 → 槽 0x3f193c → 0x756c0c（0x291a44 取用） */
/* @0x290bcc andeq r7, r12, r0, lsr #3 —— pc 相对串偏移 → "HasVsyncHandler"（0x291a48 取用） */
/* @0x290bd0 .word 0xfffffd0c —— GOT 偏移 → 槽 0x3f1964 → 0x756c08（0x291a70 取用） */
/* @0x290bd4 andeq r7, r12, r4, ror #2 —— pc 相对串偏移 → "Loading APK %s"（0x291a98 取用） */
/* @0x290bd8 .word 0xfffffccc —— GOT 偏移 → 槽 0x3f1924 → 0x757764（0x291ab4 取用） */
/* @0x290bdc .word 0xffffe2c4 —— GOT 偏移 → 槽 0x3eff1c → 0x757768（0x291ad8 取用） */
/* @0x290be0 .word 0xffffe2c0 —— GOT 偏移 → 槽 0x3eff18 → 0x544b94（0x291b10 取用） */
/* @0x290be4 .word 0xfffffcc8 —— GOT 偏移 → 槽 0x3f1920 → 0x757750（0x291b4c 取用） */
/* @0x290be8 strheq r7, [r12], -r4 —— pc 相对串偏移 → "Just before strdup\n"（0x291b6c 取用） */
/* @0x290bec .word 0xfffffd10 —— GOT 偏移 → 槽 0x3f1968 → 0x542988（0x2906d0 取用） */
/* @0x290bf0 andeq r7, r12, r12, lsr #1 —— pc 相对串偏移 → "-game game.droid"（0x291b88 取用） */
/* @0x290bf4 andeq r7, r12, r12, lsl #1 —— pc 相对串偏移 → "CommandLine: %s\n"（0x291bbc 取用） */
/* @0x290bf8 .word 0xffffe788 —— GOT 偏移 → 槽 0x3f03e0 → 0x756758（0x291bd0 取用） */
/* @0x290bfc andeq r7, r12, r0, lsl #1 —— pc 相对串偏移 → "MemoryManager allocated: %d\n"（0x291bdc 取用） */


/* ── E. 首次块：NewGlobalRef + 79 个 GetStaticMethodID（无分支直线，80 个 blx）──
 *   E1 0x290c00..0x290c44：r1 = FindClass 结果、r0 = env、r2 = &isCopy →
 *      `ldr r3,[r3,#0x54]`（下标 21 = NewGlobalRef）→ r0 = 全局引用 → 0x290c44 str r0,[r6]（0x756d44）。
 *   E2 0x290c48..0x291a80：79 次 `ldr r12,[r4]; ldr r12,[r12,#0x1c4]`（下标 113 = GetStaticMethodID）
 *      + 一次 `str r0,[r12]` 落库。参数永远是 (env, jclass=*(0x756d44), 名字串, 签名串)。
 *      名字串来自池字 + pc（多数 `add r2,pc,r2`），签名串有时先 spill 到 [sp+4]/[sp+0xc]/[sp+0x18]
 *      再 `mov r3,r11/r9` 取回（例如 OpenURL 的两个串在 0x290c24/0x290c2c 算出，
 *      0x290c34 mov r3,r9、0x290c50 mov r0,r4 后调）。
 *      全表 79 行见卡头；落点集中 0x756c08..0x756d40（79 个互不相同的槽，pthread key 0x756c04 紧贴其下）。
 *   ⚠ 段内没有任何 b/beq/bne（全函数只有 11 条分支，全在 0x2906cc/0x2906e8/0x291ad4/0x291aec/
 *     0x291b28/0x291b60/0x291bf4 与三条释放回边），所以这 79 次调用没有条件保护。
 */
/* @0x290c00 ldr r3, [r4] —— r3=*env (JNIEnv->functions) */
/* @0x290c04 mov r1, r0 */
/* @0x290c08 mov r0, r4 */
/* @0x290c0c add r2, sp, #47 */
/* @0x290c10 str r2, [sp, #0x24] */
/* @0x290c14 ldr r3, [r3, #0x54] —— r3=env->NewGlobalRef()  [+0x54] */
/* @0x290c18 blx r3 —— CALL env->NewGlobalRef() */
/* @0x290c1c ldr r9, [pc, #-0x344] —— r9=0xc7700 (pool 0x2908e0) */
/* @0x290c20 ldr r2, [pc, #-0x344] —— r2=0xc76f0 (pool 0x2908e4) */
/* @0x290c24 add r9, pc, r9 —— r9=0x35832c [pc+0xc7700] | STR "(Ljava/lang/String;)V" */
/* @0x290c28 str r9, [sp, #0x4] */
/* @0x290c2c add r2, pc, r2 —— r2=0x358324 [pc+0xc76f0] | STR "OpenURL" */
/* @0x290c30 ldr r11, [pc, #-0x350] —— r11=0xc7710 (pool 0x2908e8) */
/* @0x290c34 mov r3, r9 */
/* @0x290c38 ldr r9, [pc, #-0x354] —— r9=0xc7734 (pool 0x2908ec) */
/* @0x290c3c add r11, pc, r11 —— r11=0x358354 [pc+0xc7710] | STR "(Ljava/lang/String;I)V" */
/* @0x290c40 add r9, pc, r9 —— r9=0x35837c [pc+0xc7734] | STR "(Ljava/lang/String;F)V" */
/* @0x290c44 str r0, [r6] —— WRITE *(0x3eb708+?) <- r0 */
/* @0x290c48 mov r1, r0 */
/* @0x290c4c ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x290c50 mov r0, r4 */
/* @0x290c54 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x290c58 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x290c5c ldr r12, [pc, #-0x374] —— r12=0xffffe2cc (pool 0x2908f0) */
/* @0x290c60 str r11, [sp, #0x18] */
/* @0x290c64 mov r3, r11 */
/* @0x290c68 ldr r2, [pc, #-0x37c] —— r2=0xc76c8 (pool 0x2908f4) */
/* @0x290c6c ldr r12, [r5, r12] —— r12=GOT[0x3eff24] | ->0x756d40 */
/* @0x290c70 ldr r1, [r6] */
/* @0x290c74 add r2, pc, r2 —— r2=0x358344 [pc+0xc76c8] | STR "SendHighScore" */
/* @0x290c78 ldr r11, [pc, #-0x388] —— r11=0xc773c (pool 0x2908f8) */
/* @0x290c7c add r11, pc, r11 —— r11=0x3583c0 [pc+0xc773c] | STR "()V" */
/* @0x290c80 str r0, [r12] —— WRITE *(0x756d40) <- r0(env) */
/* @0x290c84 mov r0, r4 */
/* @0x290c88 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x290c8c ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x290c90 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x290c94 ldr r12, [pc, #-0x3a0] —— r12=0xffffe304 (pool 0x2908fc) */
/* @0x290c98 ldr r2, [pc, #-0x3a0] —— r2=0xc76bc (pool 0x290900) */
/* @0x290c9c mov r3, r9 */
/* @0x290ca0 ldr r1, [r6] */
/* @0x290ca4 ldr r12, [r5, r12] —— r12=GOT[0x3eff5c] | ->0x756d3c */
/* @0x290ca8 add r2, pc, r2 —— r2=0x35836c [pc+0xc76bc] | STR "SendAchievement" */
/* @0x290cac str r0, [r12] —— WRITE *(0x756d3c) <- r0(env) */
/* @0x290cb0 mov r0, r4 */
/* @0x290cb4 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x290cb8 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x290cbc blx r12 —— CALL env->GetStaticMethodID() */
/* @0x290cc0 ldr r12, [pc, #-0x3c4] —— r12=0xffffe30c (pool 0x290904) */
/* @0x290cc4 ldr r2, [pc, #-0x3c4] —— r2=0xc76b8 (pool 0x290908) */
/* @0x290cc8 mov r3, r9 */
/* @0x290ccc ldr r1, [r6] */
/* @0x290cd0 ldr r12, [r5, r12] —— r12=GOT[0x3eff64] | ->0x756d38 */
/* @0x290cd4 add r2, pc, r2 —— r2=0x358394 [pc+0xc76b8] | STR "IncrementAchievement" */
/* @0x290cd8 ldr r9, [pc, #-0x3d4] —— r9=0xc7868 (pool 0x29090c) */
/* @0x290cdc add r9, pc, r9 —— r9=0x35854c [pc+0xc7868] | STR "(III)V" */
/* @0x290ce0 str r0, [r12] —— WRITE *(0x756d38) <- r0(env) */
/* @0x290ce4 mov r0, r4 */
/* @0x290ce8 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x290cec ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x290cf0 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x290cf4 ldr r12, [pc, #-0x3ec] —— r12=0xffffe308 (pool 0x290910) */
/* @0x290cf8 ldr r2, [pc, #-0x3ec] —— r2=0xc769c (pool 0x290914) */
/* @0x290cfc mov r3, r11 */
/* @0x290d00 ldr r1, [r6] */
/* @0x290d04 ldr r12, [r5, r12] —— r12=GOT[0x3eff60] | ->0x756d34 */
/* @0x290d08 add r2, pc, r2 —— r2=0x3583ac [pc+0xc769c] | STR "OpenAchievements" */
/* @0x290d0c str r0, [r12] —— WRITE *(0x756d34) <- r0(env) */
/* @0x290d10 mov r0, r4 */
/* @0x290d14 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x290d18 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x290d1c blx r12 —— CALL env->GetStaticMethodID() */
/* @0x290d20 ldr r12, [pc, #-0x410] —— r12=0xffffe2dc (pool 0x290918) */
/* @0x290d24 ldr r2, [pc, #-0x410] —— r2=0xc7688 (pool 0x29091c) */
/* @0x290d28 mov r3, r11 */
/* @0x290d2c ldr r1, [r6] */
/* @0x290d30 ldr r12, [r5, r12] —— r12=GOT[0x3eff34] | ->0x756d30 */
/* @0x290d34 add r2, pc, r2 —— r2=0x3583c4 [pc+0xc7688] | STR "OpenLeaderboards" */
/* @0x290d38 str r0, [r12] —— WRITE *(0x756d30) <- r0(env) */
/* @0x290d3c mov r0, r4 */
/* @0x290d40 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x290d44 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x290d48 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x290d4c ldr r12, [pc, #-0x434] —— r12=0xffffe2f8 (pool 0x290920) */
/* @0x290d50 ldr r3, [pc, #-0x434] —— r3=0xbb7a0 (pool 0x290924) */
/* @0x290d54 ldr r2, [pc, #-0x434] —— r2=0xc766c (pool 0x290928) */
/* @0x290d58 add r3, pc, r3 —— r3=0x34c500 [pc+0xbb7a0] | STR "()I" */
/* @0x290d5c str r3, [sp, #0xc] */
/* @0x290d60 ldr r12, [r5, r12] —— r12=GOT[0x3eff50] | ->0x756d2c */
/* @0x290d64 add r2, pc, r2 —— r2=0x3583d8 [pc+0xc766c] | STR "OsGetInfo" */
/* @0x290d68 ldr r1, [r6] */
/* @0x290d6c str r0, [r12] —— WRITE *(0x756d2c) <- r0(env) */
/* @0x290d70 mov r0, r4 */
/* @0x290d74 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x290d78 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x290d7c blx r12 —— CALL env->GetStaticMethodID() */
/* @0x290d80 ldr r12, [pc, #-0x45c] —— r12=0xffffe2bc (pool 0x29092c) */
/* @0x290d84 ldr r2, [pc, #-0x45c] —— r2=0xc7648 (pool 0x290930) */
/* @0x290d88 mov r3, r11 */
/* @0x290d8c ldr r1, [r6] */
/* @0x290d90 ldr r12, [r5, r12] —— r12=GOT[0x3eff14] | ->0x756d28 */
/* @0x290d94 add r2, pc, r2 —— r2=0x3583e4 [pc+0xc7648] | STR "AchievementLoadFriends" */
/* @0x290d98 str r0, [r12] —— WRITE *(0x756d28) <- r0(env) */
/* @0x290d9c mov r0, r4 */
/* @0x290da0 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x290da4 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x290da8 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x290dac ldr r3, [pc, #-0x480] —— r3=0xffffe2ec (pool 0x290934) */
/* @0x290db0 ldr r2, [pc, #-0x480] —— r2=0xc7638 (pool 0x290938) */
/* @0x290db4 ldr r1, [r6] */
/* @0x290db8 ldr r12, [r5, r3] —— r12=GOT[0x3eff44] | ->0x756d24 */
/* @0x290dbc add r2, pc, r2 —— r2=0x3583fc [pc+0xc7638] | STR "AchievementLoadLeaderboard" */
/* @0x290dc0 ldr r3, [pc, #-0x48c] —— r3=0xc764c (pool 0x29093c) */
/* @0x290dc4 add r3, pc, r3 —— r3=0x358418 [pc+0xc764c] | STR "(Ljava/lang/String;III)V" */
/* @0x290dc8 str r0, [r12] —— WRITE *(0x756d24) <- r0(env) */
/* @0x290dcc mov r0, r4 */
/* @0x290dd0 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x290dd4 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x290dd8 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x290ddc ldr r3, [pc, #-0x4a4] —— r3=0xffffe2e4 (pool 0x290940) */
/* @0x290de0 ldr r2, [pc, #-0x4a4] —— r2=0xc7640 (pool 0x290944) */
/* @0x290de4 ldr r1, [r6] */
/* @0x290de8 ldr r12, [r5, r3] —— r12=GOT[0x3eff3c] | ->0x756d20 */
/* @0x290dec add r2, pc, r2 —— r2=0x358434 [pc+0xc7640] | STR "CallExtensionFunction" */
/* @0x290df0 ldr r3, [pc, #-0x4b0] —— r3=0xc7650 (pool 0x290948) */
/* @0x290df4 add r3, pc, r3 —— r3=0x35844c [pc+0xc7650] | STR "(Ljava/lang/String;Ljava/lang/String;I[D[Ljava/lang/Object;)Ljava/lang/Object;" */
/* @0x290df8 str r0, [r12] —— WRITE *(0x756d20) <- r0(env) */
/* @0x290dfc mov r0, r4 */
/* @0x290e00 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x290e04 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x290e08 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x290e0c ldr r12, [pc, #-0x4c8] —— r12=0xfffff76c (pool 0x29094c) */
/* @0x290e10 ldr r2, [pc, #-0x4c8] —— r2=0xc7678 (pool 0x290950) */
/* @0x290e14 ldr r3, [sp, #0x4] */
/* @0x290e18 ldr r12, [r5, r12] —— r12=GOT[0x3f13c4] | ->0x756d1c */
/* @0x290e1c add r2, pc, r2 —— r2=0x35849c [pc+0xc7678] | STR "AchievementLoadPic" */
/* @0x290e20 ldr r1, [r6] */
/* @0x290e24 str r0, [r12] —— WRITE *(0x756d1c) <- r0(env) */
/* @0x290e28 mov r0, r4 */
/* @0x290e2c ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x290e30 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x290e34 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x290e38 ldr r3, [pc, #-0x4ec] —— r3=0xffffe2f0 (pool 0x290954) */
/* @0x290e3c ldr r2, [pc, #-0x4ec] —— r2=0xc7660 (pool 0x290958) */
/* @0x290e40 ldr r1, [r6] */
/* @0x290e44 ldr r12, [r5, r3] —— r12=GOT[0x3eff48] | ->0x756d18 */
/* @0x290e48 add r2, pc, r2 —— r2=0x3584b0 [pc+0xc7660] | STR "AchievementShow" */
/* @0x290e4c ldr r3, [pc, #-0x4f8] —— r3=0xc7668 (pool 0x29095c) */
/* @0x290e50 add r3, pc, r3 —— r3=0x3584c0 [pc+0xc7668] | STR "(ILjava/lang/String;I)V" */
/* @0x290e54 str r0, [r12] —— WRITE *(0x756d18) <- r0(env) */
/* @0x290e58 mov r0, r4 */
/* @0x290e5c ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x290e60 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x290e64 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x290e68 ldr r12, [pc, #-0x510] —— r12=0xffffe2e0 (pool 0x290960) */
/* @0x290e6c ldr r2, [pc, #-0x510] —— r2=0xc7658 (pool 0x290964) */
/* @0x290e70 ldr r3, [sp, #0x4] */
/* @0x290e74 ldr r12, [r5, r12] —— r12=GOT[0x3eff38] | ->0x756d14 */
/* @0x290e78 add r2, pc, r2 —— r2=0x3584d8 [pc+0xc7658] | STR "AchievementEvent" */
/* @0x290e7c ldr r1, [r6] */
/* @0x290e80 str r0, [r12] —— WRITE *(0x756d14) <- r0(env) */
/* @0x290e84 mov r0, r4 */
/* @0x290e88 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x290e8c ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x290e90 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x290e94 ldr r12, [pc, #-0x534] —— r12=0xffffe2f4 (pool 0x290968) */
/* @0x290e98 ldr r2, [pc, #-0x534] —— r2=0xc7640 (pool 0x29096c) */
/* @0x290e9c ldr r3, [sp, #0x4] */
/* @0x290ea0 ldr r12, [r5, r12] —— r12=GOT[0x3eff4c] | ->0x756d10 */
/* @0x290ea4 add r2, pc, r2 —— r2=0x3584ec [pc+0xc7640] | STR "AchievementGetInfo" */
/* @0x290ea8 ldr r1, [r6] */
/* @0x290eac str r0, [r12] —— WRITE *(0x756d10) <- r0(env) */
/* @0x290eb0 mov r0, r4 */
/* @0x290eb4 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x290eb8 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x290ebc blx r12 —— CALL env->GetStaticMethodID() */
/* @0x290ec0 ldr r12, [pc, #-0x558] —— r12=0xffffe2e8 (pool 0x290970) */
/* @0x290ec4 ldr r2, [pc, #-0x558] —— r2=0xc7624 (pool 0x290974) */
/* @0x290ec8 mov r3, r11 */
/* @0x290ecc ldr r1, [r6] */
/* @0x290ed0 ldr r12, [r5, r12] —— r12=GOT[0x3eff40] | ->0x756d0c */
/* @0x290ed4 add r2, pc, r2 —— r2=0x358500 [pc+0xc7624] | STR "AchievementLogin" */
/* @0x290ed8 str r0, [r12] —— WRITE *(0x756d0c) <- r0(env) */
/* @0x290edc mov r0, r4 */
/* @0x290ee0 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x290ee4 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x290ee8 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x290eec ldr r12, [pc, #-0x57c] —— r12=0xffffe2d4 (pool 0x290978) */
/* @0x290ef0 ldr r2, [pc, #-0x57c] —— r2=0xc7610 (pool 0x29097c) */
/* @0x290ef4 ldr r3, [sp, #0xc] */
/* @0x290ef8 ldr r12, [r5, r12] —— r12=GOT[0x3eff2c] | ->0x756d08 */
/* @0x290efc add r2, pc, r2 —— r2=0x358514 [pc+0xc7610] | STR "AchievementLoginStatus" */
/* @0x290f00 ldr r1, [r6] */
/* @0x290f04 str r0, [r12] —— WRITE *(0x756d08) <- r0(env) */
/* @0x290f08 mov r0, r4 */
/* @0x290f0c ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x290f10 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x290f14 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x290f18 ldr r12, [pc, #-0x5a0] —— r12=0xffffe2d0 (pool 0x290980) */
/* @0x290f1c ldr r2, [pc, #-0x5a0] —— r2=0xc75f8 (pool 0x290984) */
/* @0x290f20 mov r3, r11 */
/* @0x290f24 ldr r1, [r6] */
/* @0x290f28 ldr r12, [r5, r12] —— r12=GOT[0x3eff28] | ->0x756d04 */
/* @0x290f2c add r2, pc, r2 —— r2=0x35852c [pc+0xc75f8] | STR "AchievementLogout" */
/* @0x290f30 str r0, [r12] —— WRITE *(0x756d04) <- r0(env) */
/* @0x290f34 mov r0, r4 */
/* @0x290f38 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x290f3c ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x290f40 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x290f44 ldr r12, [pc, #-0x5c4] —— r12=0xffffe2d8 (pool 0x290988) */
/* @0x290f48 ldr r2, [pc, #-0x5c4] —— r2=0xc75e0 (pool 0x29098c) */
/* @0x290f4c mov r3, r9 */
/* @0x290f50 ldr r1, [r6] */
/* @0x290f54 ldr r12, [r5, r12] —— r12=GOT[0x3eff30] | ->0x756d00 */
/* @0x290f58 add r2, pc, r2 —— r2=0x358540 [pc+0xc75e0] | STR "EnableAds" */
/* @0x290f5c str r0, [r12] —— WRITE *(0x756d00) <- r0(env) */
/* @0x290f60 mov r0, r4 */
/* @0x290f64 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x290f68 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x290f6c blx r12 —— CALL env->GetStaticMethodID() */
/* @0x290f70 ldr r12, [pc, #-0x5e8] —— r12=0xffffe22c (pool 0x290990) */
/* @0x290f74 ldr r2, [pc, #-0x5e8] —— r2=0xc75c8 (pool 0x290994) */
/* @0x290f78 mov r3, r9 */
/* @0x290f7c ldr r1, [r6] */
/* @0x290f80 ldr r12, [r5, r12] —— r12=GOT[0x3efe84] | ->0x756cfc */
/* @0x290f84 add r2, pc, r2 —— r2=0x358554 [pc+0xc75c8] | STR "MoveAds" */
/* @0x290f88 ldr r9, [pc, #-0x5f8] —— r9=0xc769c (pool 0x290998) */
/* @0x290f8c add r9, pc, r9 —— r9=0x358630 [pc+0xc769c] | STR "([Ljava/lang/String;)V" */
/* @0x290f90 str r0, [r12] —— WRITE *(0x756cfc) <- r0(env) */
/* @0x290f94 mov r0, r4 */
/* @0x290f98 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x290f9c ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x290fa0 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x290fa4 ldr r12, [pc, #-0x610] —— r12=0xffffe228 (pool 0x29099c) */
/* @0x290fa8 ldr r2, [pc, #-0x610] —— r2=0xc75a0 (pool 0x2909a0) */
/* @0x290fac ldr r3, [sp, #0x4] */
/* @0x290fb0 ldr r12, [r5, r12] —— r12=GOT[0x3efe80] | ->0x756cf8 */
/* @0x290fb4 add r2, pc, r2 —— r2=0x35855c [pc+0xc75a0] | STR "AdsSetup" */
/* @0x290fb8 ldr r1, [r6] */
/* @0x290fbc str r0, [r12] —— WRITE *(0x756cf8) <- r0(env) */
/* @0x290fc0 mov r0, r4 */
/* @0x290fc4 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x290fc8 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x290fcc blx r12 —— CALL env->GetStaticMethodID() */
/* @0x290fd0 ldr r12, [pc, #-0x634] —— r12=0xffffe224 (pool 0x2909a4) */
/* @0x290fd4 ldr r2, [pc, #-0x634] —— r2=0xc7590 (pool 0x2909a8) */
/* @0x290fd8 ldr r1, [r6] */
/* @0x290fdc add r2, pc, r2 —— r2=0x358574 [pc+0xc7590] | STR "(I)V" */
/* @0x290fe0 str r2, [sp, #0x1c] */
/* @0x290fe4 ldr r12, [r5, r12] —— r12=GOT[0x3efe7c] | ->0x756ce8 */
/* @0x290fe8 mov r3, r2 */
/* @0x290fec ldr r2, [pc, #-0x648] —— r2=0xc7570 (pool 0x2909ac) */
/* @0x290ff0 add r2, pc, r2 —— r2=0x358568 [pc+0xc7570] | STR "DisableAds" */
/* @0x290ff4 str r0, [r12] —— WRITE *(0x756ce8) <- r0(env) */
/* @0x290ff8 mov r0, r4 */
/* @0x290ffc ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291000 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291004 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291008 ldr r12, [pc, #-0x660] —— r12=0xffffe230 (pool 0x2909b0) */
/* @0x29100c ldr r2, [pc, #-0x660] —— r2=0xc755c (pool 0x2909b4) */
/* @0x291010 ldr r3, [sp, #0x4] */
/* @0x291014 ldr r12, [r5, r12] —— r12=GOT[0x3efe88] | ->0x756cf4 */
/* @0x291018 add r2, pc, r2 —— r2=0x35857c [pc+0xc755c] | STR "AdsEvent" */
/* @0x29101c ldr r1, [r6] */
/* @0x291020 str r0, [r12] —— WRITE *(0x756cf4) <- r0(env) */
/* @0x291024 mov r0, r4 */
/* @0x291028 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x29102c ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291030 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291034 ldr r12, [pc, #-0x684] —— r12=0xffffe234 (pool 0x2909b8) */
/* @0x291038 ldr r2, [pc, #-0x684] —— r2=0xc753c (pool 0x2909bc) */
/* @0x29103c ldr r3, [sp, #0x4] */
/* @0x291040 ldr r12, [r5, r12] —— r12=GOT[0x3efe8c] | ->0x756cf0 */
/* @0x291044 add r2, pc, r2 —— r2=0x358588 [pc+0xc753c] | STR "AdsEventPreload" */
/* @0x291048 ldr r1, [r6] */
/* @0x29104c str r0, [r12] —— WRITE *(0x756cf0) <- r0(env) */
/* @0x291050 mov r0, r4 */
/* @0x291054 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291058 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x29105c blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291060 ldr r12, [pc, #-0x6a8] —— r12=0xffffe238 (pool 0x2909c0) */
/* @0x291064 ldr r3, [pc, #-0x6a8] —— r3=0xc7534 (pool 0x2909c4) */
/* @0x291068 ldr r2, [pc, #-0x6a8] —— r2=0xc7518 (pool 0x2909c8) */
/* @0x29106c add r3, pc, r3 —— r3=0x3585a8 [pc+0xc7534] | STR "(I)I" */
/* @0x291070 str r3, [sp, #0x20] */
/* @0x291074 ldr r12, [r5, r12] —— r12=GOT[0x3efe90] | ->0x756cec */
/* @0x291078 add r2, pc, r2 —— r2=0x358598 [pc+0xc7518] | STR "AdsDisplayWidth" */
/* @0x29107c ldr r1, [r6] */
/* @0x291080 str r0, [r12] —— WRITE *(0x756cec) <- r0(env) */
/* @0x291084 mov r0, r4 */
/* @0x291088 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x29108c ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291090 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291094 ldr r12, [pc, #-0x6d0] —— r12=0xffffe23c (pool 0x2909cc) */
/* @0x291098 ldr r2, [pc, #-0x6d0] —— r2=0xc7504 (pool 0x2909d0) */
/* @0x29109c ldr r3, [sp, #0x20] */
/* @0x2910a0 ldr r12, [r5, r12] —— r12=GOT[0x3efe94] | ->0x756ce4 */
/* @0x2910a4 add r2, pc, r2 —— r2=0x3585b0 [pc+0xc7504] | STR "AdsDisplayHeight" */
/* @0x2910a8 ldr r1, [r6] */
/* @0x2910ac str r0, [r12] —— WRITE *(0x756ce4) <- r0(env) */
/* @0x2910b0 mov r0, r4 */
/* @0x2910b4 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x2910b8 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x2910bc blx r12 —— CALL env->GetStaticMethodID() */
/* @0x2910c0 ldr r3, [pc, #-0x6f4] —— r3=0xffffe240 (pool 0x2909d4) */
/* @0x2910c4 ldr r2, [pc, #-0x6f4] —— r2=0xc74ec (pool 0x2909d8) */
/* @0x2910c8 ldr r1, [r6] */
/* @0x2910cc ldr r12, [r5, r3] —— r12=GOT[0x3efe98] | ->0x756ce0 */
/* @0x2910d0 add r2, pc, r2 —— r2=0x3585c4 [pc+0xc74ec] | STR "LeaveRating" */
/* @0x2910d4 ldr r3, [pc, #-0x700] —— r3=0xc74f0 (pool 0x2909dc) */
/* @0x2910d8 add r3, pc, r3 —— r3=0x3585d0 [pc+0xc74f0] | STR "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V" */
/* @0x2910dc str r0, [r12] —— WRITE *(0x756ce0) <- r0(env) */
/* @0x2910e0 mov r0, r4 */
/* @0x2910e4 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x2910e8 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x2910ec blx r12 —— CALL env->GetStaticMethodID() */
/* @0x2910f0 ldr r12, [pc, #-0x718] —— r12=0xffffe244 (pool 0x2909e0) */
/* @0x2910f4 ldr r2, [pc, #-0x718] —— r2=0xc7510 (pool 0x2909e4) */
/* @0x2910f8 mov r3, r9 */
/* @0x2910fc ldr r1, [r6] */
/* @0x291100 ldr r12, [r5, r12] —— r12=GOT[0x3efe9c] | ->0x756cdc */
/* @0x291104 add r2, pc, r2 —— r2=0x35861c [pc+0xc7510] | STR "EnableInAppBilling" */
/* @0x291108 str r0, [r12] —— WRITE *(0x756cdc) <- r0(env) */
/* @0x29110c mov r0, r4 */
/* @0x291110 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291114 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291118 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x29111c ldr r12, [pc, #-0x73c] —— r12=0xffffe310 (pool 0x2909e8) */
/* @0x291120 ldr r2, [pc, #-0x73c] —— r2=0xc7510 (pool 0x2909ec) */
/* @0x291124 mov r3, r11 */
/* @0x291128 ldr r1, [r6] */
/* @0x29112c ldr r12, [r5, r12] —— r12=GOT[0x3eff68] | ->0x756cd8 */
/* @0x291130 add r2, pc, r2 —— r2=0x358648 [pc+0xc7510] | STR "RestoreInAppPurchases" */
/* @0x291134 str r0, [r12] —— WRITE *(0x756cd8) <- r0(env) */
/* @0x291138 mov r0, r4 */
/* @0x29113c ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291140 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291144 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291148 ldr r12, [pc, #-0x760] —— r12=0xffffe314 (pool 0x2909f0) */
/* @0x29114c ldr r2, [pc, #-0x760] —— r2=0xc751c (pool 0x2909f4) */
/* @0x291150 ldr r1, [r6] */
/* @0x291154 add r2, pc, r2 —— r2=0x358678 [pc+0xc751c] | STR "(Ljava/lang/String;Ljava/lang/String;I)V" */
/* @0x291158 str r2, [sp, #0x10] */
/* @0x29115c ldr r12, [r5, r12] —— r12=GOT[0x3eff6c] | ->0x756cd4 */
/* @0x291160 mov r3, r2 */
/* @0x291164 ldr r2, [pc, #-0x774] —— r2=0xc74f0 (pool 0x2909f8) */
/* @0x291168 add r2, pc, r2 —— r2=0x358660 [pc+0xc74f0] | STR "AcquireInAppPurchase" */
/* @0x29116c str r0, [r12] —— WRITE *(0x756cd4) <- r0(env) */
/* @0x291170 mov r0, r4 */
/* @0x291174 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291178 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x29117c blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291180 ldr r3, [pc, #-0x78c] —— r3=0xffffe318 (pool 0x2909fc) */
/* @0x291184 ldr r2, [pc, #-0x78c] —— r2=0xc750c (pool 0x290a00) */
/* @0x291188 ldr r1, [r6] */
/* @0x29118c ldr r12, [r5, r3] —— r12=GOT[0x3eff70] | ->0x756cd0 */
/* @0x291190 add r2, pc, r2 —— r2=0x3586a4 [pc+0xc750c] | STR "ConsumeInAppPurchase" */
/* @0x291194 ldr r3, [pc, #-0x798] —— r3=0xc751c (pool 0x290a04) */
/* @0x291198 add r3, pc, r3 —— r3=0x3586bc [pc+0xc751c] | STR "(Ljava/lang/String;Ljava/lang/String;)V" */
/* @0x29119c str r0, [r12] —— WRITE *(0x756cd0) <- r0(env) */
/* @0x2911a0 mov r0, r4 */
/* @0x2911a4 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x2911a8 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x2911ac blx r12 —— CALL env->GetStaticMethodID() */
/* @0x2911b0 ldr r12, [pc, #-0x7b0] —— r12=0xffffe31c (pool 0x290a08) */
/* @0x2911b4 ldr r2, [pc, #-0x7b0] —— r2=0xc751c (pool 0x290a0c) */
/* @0x2911b8 ldr r3, [sp, #0x4] */
/* @0x2911bc ldr r12, [r5, r12] —— r12=GOT[0x3eff74] | ->0x756ccc */
/* @0x2911c0 add r2, pc, r2 —— r2=0x3586e4 [pc+0xc751c] | STR "GetInAppPurchaseDetail" */
/* @0x2911c4 ldr r1, [r6] */
/* @0x2911c8 str r0, [r12] —— WRITE *(0x756ccc) <- r0(env) */
/* @0x2911cc mov r0, r4 */
/* @0x2911d0 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x2911d4 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x2911d8 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x2911dc ldr r12, [pc, #-0x7d4] —— r12=0xffffe320 (pool 0x290a10) */
/* @0x2911e0 ldr r2, [pc, #-0x7d4] —— r2=0xc7508 (pool 0x290a14) */
/* @0x2911e4 ldr r3, [sp, #0x4] */
/* @0x2911e8 ldr r12, [r5, r12] —— r12=GOT[0x3eff78] | ->0x756cc8 */
/* @0x2911ec add r2, pc, r2 —— r2=0x3586fc [pc+0xc7508] | STR "FacebookInit" */
/* @0x2911f0 ldr r1, [r6] */
/* @0x2911f4 str r0, [r12] —— WRITE *(0x756cc8) <- r0(env) */
/* @0x2911f8 mov r0, r4 */
/* @0x2911fc ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291200 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291204 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291208 ldr r12, [pc, #-0x7f8] —— r12=0xffffe25c (pool 0x290a18) */
/* @0x29120c ldr r2, [pc, #-0x7f8] —— r2=0xc74e8 (pool 0x290a1c) */
/* @0x291210 mov r3, r9 */
/* @0x291214 ldr r1, [r6] */
/* @0x291218 ldr r12, [r5, r12] —— r12=GOT[0x3efeb4] | ->0x756cc4 */
/* @0x29121c add r2, pc, r2 —— r2=0x35870c [pc+0xc74e8] | STR "FacebookLogin" */
/* @0x291220 ldr r9, [pc, #-0x808] —— r9=0xc7590 (pool 0x290a20) */
/* @0x291224 add r9, pc, r9 —— r9=0x3587bc [pc+0xc7590] | STR "(Ljava/lang/String;[Ljava/lang/String;I)V" */
/* @0x291228 str r0, [r12] —— WRITE *(0x756cc4) <- r0(env) */
/* @0x29122c mov r0, r4 */
/* @0x291230 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291234 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291238 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x29123c ldr r12, [pc, #-0x820] —— r12=0xffffe2b0 (pool 0x290a24) */
/* @0x291240 ldr r3, [pc, #-0x820] —— r3=0xc74e0 (pool 0x290a28) */
/* @0x291244 ldr r2, [pc, #-0x820] —— r2=0xc74c0 (pool 0x290a2c) */
/* @0x291248 add r3, pc, r3 —— r3=0x358730 [pc+0xc74e0] | STR "()Ljava/lang/String;" */
/* @0x29124c str r3, [sp, #0x14] */
/* @0x291250 ldr r12, [r5, r12] —— r12=GOT[0x3eff08] | ->0x756cc0 */
/* @0x291254 add r2, pc, r2 —— r2=0x35871c [pc+0xc74c0] | STR "FacebookAccessToken" */
/* @0x291258 ldr r1, [r6] */
/* @0x29125c str r0, [r12] —— WRITE *(0x756cc0) <- r0(env) */
/* @0x291260 mov r0, r4 */
/* @0x291264 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291268 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x29126c blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291270 ldr r12, [pc, #-0x848] —— r12=0xffffe274 (pool 0x290a30) */
/* @0x291274 ldr r2, [pc, #-0x848] —— r2=0xc74c0 (pool 0x290a34) */
/* @0x291278 ldr r3, [sp, #0x14] */
/* @0x29127c ldr r12, [r5, r12] —— r12=GOT[0x3efecc] | ->0x756ca8 */
/* @0x291280 add r2, pc, r2 —— r2=0x358748 [pc+0xc74c0] | STR "FacebookUserId" */
/* @0x291284 ldr r1, [r6] */
/* @0x291288 str r0, [r12] —— WRITE *(0x756ca8) <- r0(env) */
/* @0x29128c mov r0, r4 */
/* @0x291290 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291294 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291298 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x29129c ldr r3, [pc, #-0x86c] —— r3=0xffffe270 (pool 0x290a38) */
/* @0x2912a0 ldr r2, [pc, #-0x86c] —— r2=0xc74a4 (pool 0x290a3c) */
/* @0x2912a4 ldr r1, [r6] */
/* @0x2912a8 ldr r12, [r5, r3] —— r12=GOT[0x3efec8] | ->0x756ca4 */
/* @0x2912ac add r2, pc, r2 —— r2=0x358758 [pc+0xc74a4] | STR "FacebookGraphRequest" */
/* @0x2912b0 ldr r3, [pc, #-0x878] —— r3=0xc74b4 (pool 0x290a40) */
/* @0x2912b4 add r3, pc, r3 —— r3=0x358770 [pc+0xc74b4] | STR "(Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;I)V" */
/* @0x2912b8 str r0, [r12] —— WRITE *(0x756ca4) <- r0(env) */
/* @0x2912bc mov r0, r4 */
/* @0x2912c0 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x2912c4 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x2912c8 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x2912cc ldr r12, [pc, #-0x890] —— r12=0xffffe264 (pool 0x290a44) */
/* @0x2912d0 ldr r2, [pc, #-0x890] —— r2=0xc74c4 (pool 0x290a48) */
/* @0x2912d4 mov r3, r9 */
/* @0x2912d8 ldr r1, [r6] */
/* @0x2912dc ldr r12, [r5, r12] —— r12=GOT[0x3efebc] | ->0x756cbc */
/* @0x2912e0 add r2, pc, r2 —— r2=0x3587ac [pc+0xc74c4] | STR "FacebookDialog" */
/* @0x2912e4 str r0, [r12] —— WRITE *(0x756cbc) <- r0(env) */
/* @0x2912e8 mov r0, r4 */
/* @0x2912ec ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x2912f0 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x2912f4 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x2912f8 ldr r12, [pc, #-0x8b4] —— r12=0xffffe2b8 (pool 0x290a4c) */
/* @0x2912fc ldr r2, [pc, #-0x8b4] —— r2=0xc74d4 (pool 0x290a50) */
/* @0x291300 mov r3, r9 */
/* @0x291304 ldr r1, [r6] */
/* @0x291308 ldr r12, [r5, r12] —— r12=GOT[0x3eff10] | ->0x756cb8 */
/* @0x29130c add r2, pc, r2 —— r2=0x3587e8 [pc+0xc74d4] | STR "FacebookInviteDialog" */
/* @0x291310 ldr r9, [pc, #-0x8c4] —— r9=0xc76ac (pool 0x290a54) */
/* @0x291314 add r9, pc, r9 —— r9=0x3589c8 [pc+0xc76ac] | STR "(Ljava/lang/String;)I" */
/* @0x291318 str r0, [r12] —— WRITE *(0x756cb8) <- r0(env) */
/* @0x29131c mov r0, r4 */
/* @0x291320 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291324 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291328 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x29132c ldr r12, [pc, #-0x8dc] —— r12=0xffffe268 (pool 0x290a58) */
/* @0x291330 ldr r2, [pc, #-0x8dc] —— r2=0xc74b8 (pool 0x290a5c) */
/* @0x291334 mov r3, r11 */
/* @0x291338 ldr r1, [r6] */
/* @0x29133c ldr r12, [r5, r12] —— r12=GOT[0x3efec0] | ->0x756cb4 */
/* @0x291340 add r2, pc, r2 —— r2=0x358800 [pc+0xc74b8] | STR "FacebookLogout" */
/* @0x291344 str r0, [r12] —— WRITE *(0x756cb4) <- r0(env) */
/* @0x291348 mov r0, r4 */
/* @0x29134c ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291350 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291354 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291358 ldr r12, [pc, #-0x900] —— r12=0xffffe26c (pool 0x290a60) */
/* @0x29135c ldr r2, [pc, #-0x900] —— r2=0xc74a0 (pool 0x290a64) */
/* @0x291360 ldr r3, [sp, #0x14] */
/* @0x291364 ldr r12, [r5, r12] —— r12=GOT[0x3efec4] | ->0x756cb0 */
/* @0x291368 add r2, pc, r2 —— r2=0x358810 [pc+0xc74a0] | STR "FacebookLoginStatus" */
/* @0x29136c ldr r1, [r6] */
/* @0x291370 str r0, [r12] —— WRITE *(0x756cb0) <- r0(env) */
/* @0x291374 mov r0, r4 */
/* @0x291378 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x29137c ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291380 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291384 ldr r3, [pc, #-0x924] —— r3=0xffffe278 (pool 0x290a68) */
/* @0x291388 ldr r2, [pc, #-0x924] —— r2=0xc7488 (pool 0x290a6c) */
/* @0x29138c ldr r1, [r6] */
/* @0x291390 ldr r12, [r5, r3] —— r12=GOT[0x3efed0] | ->0x756cac */
/* @0x291394 add r2, pc, r2 —— r2=0x358824 [pc+0xc7488] | STR "FacebookCheckPermission" */
/* @0x291398 ldr r3, [pc, #-0x930] —— r3=0xc6eec (pool 0x290a70) */
/* @0x29139c add r3, pc, r3 —— r3=0x358290 [pc+0xc6eec] | STR "(Ljava/lang/String;)Z" */
/* @0x2913a0 str r0, [r12] —— WRITE *(0x756cac) <- r0(env) */
/* @0x2913a4 mov r0, r4 */
/* @0x2913a8 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x2913ac ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x2913b0 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x2913b4 ldr r3, [pc, #-0x948] —— r3=0xffffe260 (pool 0x290a74) */
/* @0x2913b8 ldr r2, [pc, #-0x948] —— r2=0xc7470 (pool 0x290a78) */
/* @0x2913bc ldr r1, [r6] */
/* @0x2913c0 ldr r12, [r5, r3] —— r12=GOT[0x3efeb8] | ->0x756ca0 */
/* @0x2913c4 add r2, pc, r2 —— r2=0x35883c [pc+0xc7470] | STR "FacebookRequestPermissions" */
/* @0x2913c8 ldr r3, [pc, #-0x954] —— r3=0xc7484 (pool 0x290a7c) */
/* @0x2913cc add r3, pc, r3 —— r3=0x358858 [pc+0xc7484] | STR "([Ljava/lang/String;Z)I" */
/* @0x2913d0 str r0, [r12] —— WRITE *(0x756ca0) <- r0(env) */
/* @0x2913d4 mov r0, r4 */
/* @0x2913d8 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x2913dc ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x2913e0 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x2913e4 ldr r12, [pc, #-0x96c] —— r12=0xffffe2b4 (pool 0x290a80) */
/* @0x2913e8 ldr r2, [pc, #-0x96c] —— r2=0xc7474 (pool 0x290a84) */
/* @0x2913ec ldr r3, [sp, #0x18] */
/* @0x2913f0 ldr r12, [r5, r12] —— r12=GOT[0x3eff0c] | ->0x756c9c */
/* @0x2913f4 add r2, pc, r2 —— r2=0x358870 [pc+0xc7474] | STR "HttpGet" */
/* @0x2913f8 ldr r1, [r6] */
/* @0x2913fc str r0, [r12] —— WRITE *(0x756c9c) <- r0(env) */
/* @0x291400 mov r0, r4 */
/* @0x291404 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291408 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x29140c blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291410 ldr r12, [pc, #-0x990] —— r12=0xffffea0c (pool 0x290a88) */
/* @0x291414 ldr r2, [pc, #-0x990] —— r2=0xc7450 (pool 0x290a8c) */
/* @0x291418 ldr r3, [sp, #0x10] */
/* @0x29141c ldr r12, [r5, r12] —— r12=GOT[0x3f0664] | ->0x756c98 */
/* @0x291420 add r2, pc, r2 —— r2=0x358878 [pc+0xc7450] | STR "HttpPost" */
/* @0x291424 ldr r1, [r6] */
/* @0x291428 str r0, [r12] —— WRITE *(0x756c98) <- r0(env) */
/* @0x29142c mov r0, r4 */
/* @0x291430 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291434 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291438 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x29143c ldr r3, [pc, #-0x9b4] —— r3=0xffffea10 (pool 0x290a90) */
/* @0x291440 ldr r2, [pc, #-0x9b4] —— r2=0xc7430 (pool 0x290a94) */
/* @0x291444 ldr r1, [r6] */
/* @0x291448 ldr r12, [r5, r3] —— r12=GOT[0x3f0668] | ->0x756c94 */
/* @0x29144c add r2, pc, r2 —— r2=0x358884 [pc+0xc7430] | STR "HttpRequest" */
/* @0x291450 ldr r3, [pc, #-0x9c0] —— r3=0xc7434 (pool 0x290a98) */
/* @0x291454 add r3, pc, r3 —— r3=0x358890 [pc+0xc7434] | STR "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[BI)V" */
/* @0x291458 str r0, [r12] —— WRITE *(0x756c94) <- r0(env) */
/* @0x29145c mov r0, r4 */
/* @0x291460 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291464 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291468 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x29146c ldr r12, [pc, #-0x9d8] —— r12=0xffffea14 (pool 0x290a9c) */
/* @0x291470 ldr r2, [pc, #-0x9d8] —— r2=0xc7448 (pool 0x290aa0) */
/* @0x291474 mov r3, r11 */
/* @0x291478 ldr r1, [r6] */
/* @0x29147c ldr r12, [r5, r12] —— r12=GOT[0x3f066c] | ->0x756c90 */
/* @0x291480 add r2, pc, r2 —— r2=0x3588d0 [pc+0xc7448] | STR "ClearGamepads" */
/* @0x291484 str r0, [r12] —— WRITE *(0x756c90) <- r0(env) */
/* @0x291488 mov r0, r4 */
/* @0x29148c ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291490 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291494 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291498 ldr r12, [pc, #-0x9fc] —— r12=0xffffea18 (pool 0x290aa4) */
/* @0x29149c ldr r2, [pc, #-0x9fc] —— r2=0xc7430 (pool 0x290aa8) */
/* @0x2914a0 ldr r3, [sp, #0x18] */
/* @0x2914a4 ldr r12, [r5, r12] —— r12=GOT[0x3f0670] | ->0x756c74 */
/* @0x2914a8 add r2, pc, r2 —— r2=0x3588e0 [pc+0xc7430] | STR "PlayMP3" */
/* @0x2914ac ldr r1, [r6] */
/* @0x2914b0 str r0, [r12] —— WRITE *(0x756c74) <- r0(env) */
/* @0x2914b4 mov r0, r4 */
/* @0x2914b8 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x2914bc ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x2914c0 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x2914c4 ldr r12, [pc, #-0xa20] —— r12=0xfffff80c (pool 0x290aac) */
/* @0x2914c8 ldr r2, [pc, #-0xa20] —— r2=0xc7408 (pool 0x290ab0) */
/* @0x2914cc mov r3, r11 */
/* @0x2914d0 ldr r1, [r6] */
/* @0x2914d4 ldr r12, [r5, r12] —— r12=GOT[0x3f1464] | ->0x756c8c */
/* @0x2914d8 add r2, pc, r2 —— r2=0x3588e8 [pc+0xc7408] | STR "StopMP3" */
/* @0x2914dc str r0, [r12] —— WRITE *(0x756c8c) <- r0(env) */
/* @0x2914e0 mov r0, r4 */
/* @0x2914e4 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x2914e8 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x2914ec blx r12 —— CALL env->GetStaticMethodID() */
/* @0x2914f0 ldr r12, [pc, #-0xa44] —— r12=0xfffff818 (pool 0x290ab4) */
/* @0x2914f4 ldr r2, [pc, #-0xa44] —— r2=0xc73e4 (pool 0x290ab8) */
/* @0x2914f8 mov r3, r11 */
/* @0x2914fc ldr r1, [r6] */
/* @0x291500 ldr r12, [r5, r12] —— r12=GOT[0x3f1470] | ->0x756c88 */
/* @0x291504 add r2, pc, r2 —— r2=0x3588f0 [pc+0xc73e4] | STR "PauseMP3" */
/* @0x291508 str r0, [r12] —— WRITE *(0x756c88) <- r0(env) */
/* @0x29150c mov r0, r4 */
/* @0x291510 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291514 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291518 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x29151c ldr r12, [pc, #-0xa68] —— r12=0xfffff810 (pool 0x290abc) */
/* @0x291520 ldr r2, [pc, #-0xa68] —— r2=0xc73c4 (pool 0x290ac0) */
/* @0x291524 mov r3, r11 */
/* @0x291528 ldr r1, [r6] */
/* @0x29152c ldr r12, [r5, r12] —— r12=GOT[0x3f1468] | ->0x756c84 */
/* @0x291530 add r2, pc, r2 —— r2=0x3588fc [pc+0xc73c4] | STR "ResumeMP3" */
/* @0x291534 str r0, [r12] —— WRITE *(0x756c84) <- r0(env) */
/* @0x291538 mov r0, r4 */
/* @0x29153c ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291540 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291544 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291548 ldr r3, [pc, #-0xa8c] —— r3=0xfffff814 (pool 0x290ac4) */
/* @0x29154c ldr r2, [pc, #-0xa8c] —— r2=0xc73a8 (pool 0x290ac8) */
/* @0x291550 ldr r1, [r6] */
/* @0x291554 ldr r12, [r5, r3] —— r12=GOT[0x3f146c] | ->0x756c80 */
/* @0x291558 add r2, pc, r2 —— r2=0x358908 [pc+0xc73a8] | STR "SetMP3Volume" */
/* @0x29155c ldr r3, [pc, #-0xa98] —— r3=0xc73b0 (pool 0x290acc) */
/* @0x291560 add r3, pc, r3 —— r3=0x358918 [pc+0xc73b0] | STR "(F)V" */
/* @0x291564 str r0, [r12] —— WRITE *(0x756c80) <- r0(env) */
/* @0x291568 mov r0, r4 */
/* @0x29156c ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291570 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291574 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291578 ldr r12, [pc, #-0xab0] —— r12=0xfffff81c (pool 0x290ad0) */
/* @0x29157c ldr r2, [pc, #-0xab0] —— r2=0xc73a0 (pool 0x290ad4) */
/* @0x291580 ldr r1, [r6] */
/* @0x291584 add r2, pc, r2 —— r2=0x35892c [pc+0xc73a0] | STR "()Z" */
/* @0x291588 str r2, [sp, #0x8] */
/* @0x29158c ldr r12, [r5, r12] —— r12=GOT[0x3f1474] | ->0x756c7c */
/* @0x291590 mov r3, r2 */
/* @0x291594 ldr r2, [pc, #-0xac4] —— r2=0xc7380 (pool 0x290ad8) */
/* @0x291598 add r2, pc, r2 —— r2=0x358920 [pc+0xc7380] | STR "PlayingMP3" */
/* @0x29159c str r0, [r12] —— WRITE *(0x756c7c) <- r0(env) */
/* @0x2915a0 mov r0, r4 */
/* @0x2915a4 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x2915a8 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x2915ac blx r12 —— CALL env->GetStaticMethodID() */
/* @0x2915b0 ldr r12, [pc, #-0xadc] —— r12=0xfffff820 (pool 0x290adc) */
/* @0x2915b4 ldr r2, [pc, #-0xadc] —— r2=0xc7368 (pool 0x290ae0) */
/* @0x2915b8 ldr r3, [sp, #0xc] */
/* @0x2915bc ldr r12, [r5, r12] —— r12=GOT[0x3f1478] | ->0x756c78 */
/* @0x2915c0 add r2, pc, r2 —— r2=0x358930 [pc+0xc7368] | STR "GetDefaultFrameBuffer" */
/* @0x2915c4 ldr r1, [r6] */
/* @0x2915c8 str r0, [r12] —— WRITE *(0x756c78) <- r0(env) */
/* @0x2915cc mov r0, r4 */
/* @0x2915d0 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x2915d4 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x2915d8 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x2915dc ldr r12, [pc, #-0xb00] —— r12=0xfffffd00 (pool 0x290ae4) */
/* @0x2915e0 ldr r2, [pc, #-0xb00] —— r2=0xc7354 (pool 0x290ae8) */
/* @0x2915e4 ldr r3, [sp, #0x4] */
/* @0x2915e8 ldr r12, [r5, r12] —— r12=GOT[0x3f1958] | ->0x756c70 */
/* @0x2915ec add r2, pc, r2 —— r2=0x358948 [pc+0xc7354] | STR "ShowMessage" */
/* @0x2915f0 ldr r1, [r6] */
/* @0x2915f4 str r0, [r12] —— WRITE *(0x756c70) <- r0(env) */
/* @0x2915f8 mov r0, r4 */
/* @0x2915fc ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291600 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291604 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291608 ldr r12, [pc, #-0xb24] —— r12=0xffffbd58 (pool 0x290aec) */
/* @0x29160c ldr r2, [pc, #-0xb24] —— r2=0xc7334 (pool 0x290af0) */
/* @0x291610 ldr r3, [sp, #0x1c] */
/* @0x291614 ldr r12, [r5, r12] —— r12=GOT[0x3ed9b0] | ->0x756c6c */
/* @0x291618 add r2, pc, r2 —— r2=0x358954 [pc+0xc7334] | STR "setSystemUIVisibilityFlags" */
/* @0x29161c ldr r1, [r6] */
/* @0x291620 str r0, [r12] —— WRITE *(0x756c6c) <- r0(env) */
/* @0x291624 mov r0, r4 */
/* @0x291628 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x29162c ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291630 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291634 ldr r3, [pc, #-0xb48] —— r3=0xffffe220 (pool 0x290af4) */
/* @0x291638 ldr r2, [pc, #-0xb48] —— r2=0xc7324 (pool 0x290af8) */
/* @0x29163c ldr r1, [r6] */
/* @0x291640 ldr r12, [r5, r3] —— r12=GOT[0x3efe78] | ->0x756c68 */
/* @0x291644 add r2, pc, r2 —— r2=0x358970 [pc+0xc7324] | STR "InputString" */
/* @0x291648 ldr r3, [pc, #-0xb54] —— r3=0xc7328 (pool 0x290afc) */
/* @0x29164c add r3, pc, r3 —— r3=0x35897c [pc+0xc7328] | STR "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;" */
/* @0x291650 str r0, [r12] —— WRITE *(0x756c68) <- r0(env) */
/* @0x291654 mov r0, r4 */
/* @0x291658 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x29165c ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291660 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291664 ldr r12, [pc, #-0xb6c] —— r12=0xffffc1ac (pool 0x290b00) */
/* @0x291668 ldr r2, [pc, #-0xb6c] —— r2=0xc7338 (pool 0x290b04) */
/* @0x29166c mov r3, r9 */
/* @0x291670 ldr r1, [r6] */
/* @0x291674 ldr r12, [r5, r12] —— r12=GOT[0x3ede04] | ->0x756c64 */
/* @0x291678 add r2, pc, r2 —— r2=0x3589b8 [pc+0xc7338] | STR "ShowQuestion" */
/* @0x29167c str r0, [r12] —— WRITE *(0x756c64) <- r0(env) */
/* @0x291680 mov r0, r4 */
/* @0x291684 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291688 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x29168c blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291690 ldr r12, [pc, #-0xb90] —— r12=0xffffc1b0 (pool 0x290b08) */
/* @0x291694 ldr r2, [pc, #-0xb90] —— r2=0xc7338 (pool 0x290b0c) */
/* @0x291698 ldr r3, [sp, #0x18] */
/* @0x29169c ldr r12, [r5, r12] —— r12=GOT[0x3ede08] | ->0x756c60 */
/* @0x2916a0 add r2, pc, r2 —— r2=0x3589e0 [pc+0xc7338] | STR "ShowMessageAsync" */
/* @0x2916a4 ldr r1, [r6] */
/* @0x2916a8 str r0, [r12] —— WRITE *(0x756c60) <- r0(env) */
/* @0x2916ac mov r0, r4 */
/* @0x2916b0 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x2916b4 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x2916b8 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x2916bc ldr r12, [pc, #-0xbb4] —— r12=0xffffc1c0 (pool 0x290b10) */
/* @0x2916c0 ldr r2, [pc, #-0xbb4] —— r2=0xc7320 (pool 0x290b14) */
/* @0x2916c4 ldr r3, [sp, #0x10] */
/* @0x2916c8 ldr r12, [r5, r12] —— r12=GOT[0x3ede18] | ->0x756c3c */
/* @0x2916cc add r2, pc, r2 —— r2=0x3589f4 [pc+0xc7320] | STR "InputStringAsync" */
/* @0x2916d0 ldr r1, [r6] */
/* @0x2916d4 str r0, [r12] —— WRITE *(0x756c3c) <- r0(env) */
/* @0x2916d8 mov r0, r4 */
/* @0x2916dc ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x2916e0 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x2916e4 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x2916e8 ldr r12, [pc, #-0xbd8] —— r12=0xffffc1b4 (pool 0x290b18) */
/* @0x2916ec ldr r2, [pc, #-0xbd8] —— r2=0xc7308 (pool 0x290b1c) */
/* @0x2916f0 ldr r3, [sp, #0x18] */
/* @0x2916f4 ldr r12, [r5, r12] —— r12=GOT[0x3ede0c] | ->0x756c38 */
/* @0x2916f8 add r2, pc, r2 —— r2=0x358a08 [pc+0xc7308] | STR "ShowQuestionAsync" */
/* @0x2916fc ldr r1, [r6] */
/* @0x291700 str r0, [r12] —— WRITE *(0x756c38) <- r0(env) */
/* @0x291704 mov r0, r4 */
/* @0x291708 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x29170c ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291710 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291714 ldr r12, [pc, #-0xbfc] —— r12=0xffffc1b8 (pool 0x290b20) */
/* @0x291718 ldr r2, [pc, #-0xbfc] —— r2=0xc72f0 (pool 0x290b24) */
/* @0x29171c ldr r3, [sp, #0x10] */
/* @0x291720 ldr r12, [r5, r12] —— r12=GOT[0x3ede10] | ->0x756c34 */
/* @0x291724 add r2, pc, r2 —— r2=0x358a1c [pc+0xc72f0] | STR "ShowLogin" */
/* @0x291728 ldr r1, [r6] */
/* @0x29172c str r0, [r12] —— WRITE *(0x756c34) <- r0(env) */
/* @0x291730 mov r0, r4 */
/* @0x291734 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291738 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x29173c blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291740 ldr r3, [pc, #-0xc20] —— r3=0xffffc1bc (pool 0x290b28) */
/* @0x291744 ldr r2, [pc, #-0xc20] —— r2=0xc72d0 (pool 0x290b2c) */
/* @0x291748 ldr r1, [r6] */
/* @0x29174c ldr r12, [r5, r3] —— r12=GOT[0x3ede14] | ->0x756c5c */
/* @0x291750 add r2, pc, r2 —— r2=0x358a28 [pc+0xc72d0] | STR "RestrictOrientation" */
/* @0x291754 ldr r3, [pc, #-0xc2c] —— r3=0xc72dc (pool 0x290b30) */
/* @0x291758 add r3, pc, r3 —— r3=0x358a3c [pc+0xc72dc] | STR "(ZZZZZ)V" */
/* @0x29175c str r0, [r12] —— WRITE *(0x756c5c) <- r0(env) */
/* @0x291760 mov r0, r4 */
/* @0x291764 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291768 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x29176c blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291770 ldr r12, [pc, #-0xc44] —— r12=0xffffe27c (pool 0x290b34) */
/* @0x291774 ldr r2, [pc, #-0xc44] —— r2=0xc72c0 (pool 0x290b38) */
/* @0x291778 ldr r3, [sp, #0x8] */
/* @0x29177c ldr r12, [r5, r12] —— r12=GOT[0x3efed4] | ->0x756c58 */
/* @0x291780 add r2, pc, r2 —— r2=0x358a48 [pc+0xc72c0] | STR "isNetworkConnected" */
/* @0x291784 ldr r1, [r6] */
/* @0x291788 str r0, [r12] —— WRITE *(0x756c58) <- r0(env) */
/* @0x29178c mov r0, r4 */
/* @0x291790 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291794 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291798 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x29179c ldr r12, [pc, #-0xc68] —— r12=0xffffe290 (pool 0x290b3c) */
/* @0x2917a0 ldr r2, [pc, #-0xc68] —— r2=0xc72a4 (pool 0x290b40) */
/* @0x2917a4 mov r3, r9 */
/* @0x2917a8 ldr r1, [r6] */
/* @0x2917ac ldr r12, [r5, r12] —— r12=GOT[0x3efee8] | ->0x756c54 */
/* @0x2917b0 add r2, pc, r2 —— r2=0x358a5c [pc+0xc72a4] | STR "CheckPermission" */
/* @0x2917b4 str r0, [r12] —— WRITE *(0x756c54) <- r0(env) */
/* @0x2917b8 mov r0, r4 */
/* @0x2917bc ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x2917c0 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x2917c4 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x2917c8 ldr r12, [pc, #-0xc8c] —— r12=0xffffe298 (pool 0x290b44) */
/* @0x2917cc ldr r2, [pc, #-0xc8c] —— r2=0xc728c (pool 0x290b48) */
/* @0x2917d0 ldr r3, [sp, #0x4] */
/* @0x2917d4 ldr r12, [r5, r12] —— r12=GOT[0x3efef0] | ->0x756c50 */
/* @0x2917d8 add r2, pc, r2 —— r2=0x358a6c [pc+0xc728c] | STR "RequestPermission" */
/* @0x2917dc ldr r1, [r6] */
/* @0x2917e0 str r0, [r12] —— WRITE *(0x756c50) <- r0(env) */
/* @0x2917e4 mov r0, r4 */
/* @0x2917e8 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x2917ec ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x2917f0 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x2917f4 ldr r3, [pc, #-0xcb0] —— r3=0xffffe29c (pool 0x290b4c) */
/* @0x2917f8 ldr r2, [pc, #-0xcb0] —— r2=0xc7274 (pool 0x290b50) */
/* @0x2917fc ldr r1, [r6] */
/* @0x291800 ldr r12, [r5, r3] —— r12=GOT[0x3efef4] | ->0x756c4c */
/* @0x291804 add r2, pc, r2 —— r2=0x358a80 [pc+0xc7274] | STR "powersaveEnable" */
/* @0x291808 ldr r3, [pc, #-0xcbc] —— r3=0xc727c (pool 0x290b54) */
/* @0x29180c add r3, pc, r3 —— r3=0x358a90 [pc+0xc727c] | STR "(Z)V" */
/* @0x291810 str r0, [r12] —— WRITE *(0x756c4c) <- r0(env) */
/* @0x291814 mov r0, r4 */
/* @0x291818 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x29181c ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291820 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291824 ldr r12, [pc, #-0xcd4] —— r12=0xffffe294 (pool 0x290b58) */
/* @0x291828 ldr r2, [pc, #-0xcd4] —— r2=0xc725c (pool 0x290b5c) */
/* @0x29182c ldr r3, [sp, #0x4] */
/* @0x291830 ldr r12, [r5, r12] —— r12=GOT[0x3efeec] | ->0x756c48 */
/* @0x291834 add r2, pc, r2 —— r2=0x358a98 [pc+0xc725c] | STR "analyticsEvent" */
/* @0x291838 ldr r1, [r6] */
/* @0x29183c str r0, [r12] —— WRITE *(0x756c48) <- r0(env) */
/* @0x291840 mov r0, r4 */
/* @0x291844 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291848 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x29184c blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291850 ldr r3, [pc, #-0xcf8] —— r3=0xffffe2a0 (pool 0x290b60) */
/* @0x291854 ldr r2, [pc, #-0xcf8] —— r2=0xc7240 (pool 0x290b64) */
/* @0x291858 ldr r1, [r6] */
/* @0x29185c ldr r12, [r5, r3] —— r12=GOT[0x3efef8] | ->0x756c44 */
/* @0x291860 add r2, pc, r2 —— r2=0x358aa8 [pc+0xc7240] | STR "analyticsEventExt" */
/* @0x291864 ldr r3, [pc, #-0xd04] —— r3=0xc724c (pool 0x290b68) */
/* @0x291868 add r3, pc, r3 —— r3=0x358abc [pc+0xc724c] | STR "(Ljava/lang/String;[Ljava/lang/String;)V" */
/* @0x29186c str r0, [r12] —— WRITE *(0x756c44) <- r0(env) */
/* @0x291870 mov r0, r4 */
/* @0x291874 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291878 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x29187c blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291880 ldr r12, [pc, #-0xd1c] —— r12=0xffffe2a4 (pool 0x290b6c) */
/* @0x291884 ldr r2, [pc, #-0xd1c] —— r2=0xc7250 (pool 0x290b70) */
/* @0x291888 ldr r3, [sp, #0x10] */
/* @0x29188c ldr r12, [r5, r12] —— r12=GOT[0x3efefc] | ->0x756c40 */
/* @0x291890 add r2, pc, r2 —— r2=0x358ae8 [pc+0xc7250] | STR "cloudStringSave" */
/* @0x291894 ldr r1, [r6] */
/* @0x291898 str r0, [r12] —— WRITE *(0x756c40) <- r0(env) */
/* @0x29189c mov r0, r4 */
/* @0x2918a0 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x2918a4 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x2918a8 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x2918ac ldr r12, [pc, #-0xd40] —— r12=0xffffe2fc (pool 0x290b74) */
/* @0x2918b0 ldr r2, [pc, #-0xd40] —— r2=0xc7234 (pool 0x290b78) */
/* @0x2918b4 ldr r3, [sp, #0x1c] */
/* @0x2918b8 ldr r12, [r5, r12] —— r12=GOT[0x3eff54] | ->0x756c30 */
/* @0x2918bc add r2, pc, r2 —— r2=0x358af8 [pc+0xc7234] | STR "cloudSynchronise" */
/* @0x2918c0 ldr r1, [r6] */
/* @0x2918c4 str r0, [r12] —— WRITE *(0x756c30) <- r0(env) */
/* @0x2918c8 mov r0, r4 */
/* @0x2918cc ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x2918d0 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x2918d4 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x2918d8 ldr r12, [pc, #-0xd64] —— r12=0xffffe300 (pool 0x290b7c) */
/* @0x2918dc ldr r2, [pc, #-0xd64] —— r2=0xc7218 (pool 0x290b80) */
/* @0x2918e0 mov r3, r11 */
/* @0x2918e4 ldr r1, [r6] */
/* @0x2918e8 ldr r12, [r5, r12] —— r12=GOT[0x3eff58] | ->0x756c2c */
/* @0x2918ec add r2, pc, r2 —— r2=0x358b0c [pc+0xc7218] | STR "DumpUsedMemory" */
/* @0x2918f0 str r0, [r12] —— WRITE *(0x756c2c) <- r0(env) */
/* @0x2918f4 mov r0, r4 */
/* @0x2918f8 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x2918fc ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291900 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291904 ldr r3, [pc, #-0xd88] —— r3=0xfffffd04 (pool 0x290b84) */
/* @0x291908 ldr r2, [pc, #-0xd88] —— r2=0xc7200 (pool 0x290b88) */
/* @0x29190c ldr r1, [r6] */
/* @0x291910 ldr r12, [r5, r3] —— r12=GOT[0x3f195c] | ->0x756c28 */
/* @0x291914 add r2, pc, r2 —— r2=0x358b1c [pc+0xc7200] | STR "SetLaunchedFromPlayer" */
/* @0x291918 ldr r3, [pc, #-0xd94] —— r3=0xc7210 (pool 0x290b8c) */
/* @0x29191c add r3, pc, r3 —— r3=0x358b34 [pc+0xc7210] | STR "(Ljava/lang/String;Z)V" */
/* @0x291920 str r0, [r12] —— WRITE *(0x756c28) <- r0(env) */
/* @0x291924 mov r0, r4 */
/* @0x291928 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x29192c ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291930 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291934 ldr r12, [pc, #-0xdac] —— r12=0xffffe2ac (pool 0x290b90) */
/* @0x291938 ldr r2, [pc, #-0xdac] —— r2=0xc7200 (pool 0x290b94) */
/* @0x29193c ldr r3, [sp, #0xc] */
/* @0x291940 ldr r12, [r5, r12] —— r12=GOT[0x3eff04] | ->0x756c24 */
/* @0x291944 add r2, pc, r2 —— r2=0x358b4c [pc+0xc7200] | STR "UsingGL2" */
/* @0x291948 ldr r1, [r6] */
/* @0x29194c str r0, [r12] —— WRITE *(0x756c24) <- r0(env) */
/* @0x291950 mov r0, r4 */
/* @0x291954 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291958 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x29195c blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291960 ldr r3, [pc, #-0xdd0] —— r3=0xfffffd08 (pool 0x290b98) */
/* @0x291964 ldr r2, [pc, #-0xdd0] —— r2=0xc71e0 (pool 0x290b9c) */
/* @0x291968 ldr r1, [r6] */
/* @0x29196c ldr r12, [r5, r3] —— r12=GOT[0x3f1960] | ->0x756c20 */
/* @0x291970 add r2, pc, r2 —— r2=0x358b58 [pc+0xc71e0] | STR "PushLocalNotification" */
/* @0x291974 ldr r3, [pc, #-0xddc] —— r3=0xc71f0 (pool 0x290ba0) */
/* @0x291978 add r3, pc, r3 —— r3=0x358b70 [pc+0xc71f0] | STR "(FLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V" */
/* @0x29197c str r0, [r12] —— WRITE *(0x756c20) <- r0(env) */
/* @0x291980 mov r0, r4 */
/* @0x291984 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291988 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x29198c blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291990 ldr r3, [pc, #-0xdf4] —— r3=0xffffe324 (pool 0x290ba4) */
/* @0x291994 ldr r2, [pc, #-0xdf4] —— r2=0xc7204 (pool 0x290ba8) */
/* @0x291998 ldr r1, [r6] */
/* @0x29199c ldr r12, [r5, r3] —— r12=GOT[0x3eff7c] | ->0x756c1c */
/* @0x2919a0 add r2, pc, r2 —— r2=0x358bac [pc+0xc7204] | STR "PushGetLocalNotification" */
/* @0x2919a4 ldr r3, [pc, #-0xe00] —— r3=0xbabe0 (pool 0x290bac) */
/* @0x2919a8 add r3, pc, r3 —— r3=0x34c590 [pc+0xbabe0] | STR "(II)I" */
/* @0x2919ac str r0, [r12] —— WRITE *(0x756c1c) <- r0(env) */
/* @0x2919b0 mov r0, r4 */
/* @0x2919b4 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x2919b8 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x2919bc blx r12 —— CALL env->GetStaticMethodID() */
/* @0x2919c0 ldr r12, [pc, #-0xe18] —— r12=0xffffe328 (pool 0x290bb0) */
/* @0x2919c4 ldr r2, [pc, #-0xe18] —— r2=0xc71f0 (pool 0x290bb4) */
/* @0x2919c8 ldr r3, [sp, #0x20] */
/* @0x2919cc ldr r12, [r5, r12] —— r12=GOT[0x3eff80] | ->0x756c18 */
/* @0x2919d0 add r2, pc, r2 —— r2=0x358bc8 [pc+0xc71f0] | STR "PushCancelLocalNotification" */
/* @0x2919d4 ldr r1, [r6] */
/* @0x2919d8 str r0, [r12] —— WRITE *(0x756c18) <- r0(env) */
/* @0x2919dc mov r0, r4 */
/* @0x2919e0 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x2919e4 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x2919e8 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x2919ec ldr r12, [pc, #-0xe3c] —— r12=0xffffe32c (pool 0x290bb8) */
/* @0x2919f0 ldr r2, [pc, #-0xe3c] —— r2=0xc71e0 (pool 0x290bbc) */
/* @0x2919f4 ldr r3, [sp, #0x14] */
/* @0x2919f8 ldr r12, [r5, r12] —— r12=GOT[0x3eff84] | ->0x756c14 */
/* @0x2919fc add r2, pc, r2 —— r2=0x358be4 [pc+0xc71e0] | STR "GetUDID" */
/* @0x291a00 ldr r1, [r6] */
/* @0x291a04 str r0, [r12] —— WRITE *(0x756c14) <- r0(env) */
/* @0x291a08 mov r0, r4 */
/* @0x291a0c ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291a10 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291a14 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291a18 ldr r12, [pc, #-0xe60] —— r12=0xffffe2a8 (pool 0x290bc0) */
/* @0x291a1c ldr r2, [pc, #-0xe60] —— r2=0xc71b8 (pool 0x290bc4) */
/* @0x291a20 mov r3, r11 */
/* @0x291a24 ldr r1, [r6] */
/* @0x291a28 ldr r12, [r5, r12] —— r12=GOT[0x3eff00] | ->0x756c10 */
/* @0x291a2c add r2, pc, r2 —— r2=0x358bec [pc+0xc71b8] | STR "WaitForVsync" */
/* @0x291a30 str r0, [r12] —— WRITE *(0x756c10) <- r0(env) */
/* @0x291a34 mov r0, r4 */
/* @0x291a38 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291a3c ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291a40 blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291a44 ldr r12, [pc, #-0xe84] —— r12=0xfffffce4 (pool 0x290bc8) */
/* @0x291a48 ldr r2, [pc, #-0xe84] —— r2=0xc71a0 (pool 0x290bcc) */
/* @0x291a4c ldr r3, [sp, #0xc] */
/* @0x291a50 ldr r12, [r5, r12] —— r12=GOT[0x3f193c] | ->0x756c0c */
/* @0x291a54 add r2, pc, r2 —— r2=0x358bfc [pc+0xc71a0] | STR "HasVsyncHandler" */
/* @0x291a58 ldr r1, [r6] */
/* @0x291a5c str r0, [r12] —— WRITE *(0x756c0c) <- r0(env) */
/* @0x291a60 mov r0, r4 */
/* @0x291a64 ldr r12, [r4] —— r12=*env (JNIEnv->functions) */
/* @0x291a68 ldr r12, [r12, #0x1c4] —— r12=env->GetStaticMethodID()  [+0x1c4] */
/* @0x291a6c blx r12 —— CALL env->GetStaticMethodID() */
/* @0x291a70 ldr r3, [pc, #-0xea8] —— r3=0xfffffd0c (pool 0x290bd0) */
/* @0x291a74 add r2, sp, #47 */
/* @0x291a78 mov r1, r8 */
/* @0x291a7c ldr r3, [r5, r3] —— r3=GOT[0x3f1964] | ->0x756c08 */
/* @0x291a80 str r0, [r3] —— WRITE *(0x756c08) <- r0(env) */


/* ── F. APK 装载（只在首次块里走）──────────────────────────────────
 *   F1 0x291a84..0x291a90：GetStringUTFChars(env, r8 = apkFilePath, &isCopy) —— r8 就是入参 r2。
 *   F2 0x291a94..0x291ab0：用 r7 那个控制台打印 "Loading APK %s\n"（0x358c0c），r2 = 刚取到的 char*。
 *   F3 0x291abc..0x291ac8：r0 = 该 char*（**未 strdup**）→ 存 0x757764（GetExeName 读它）→ zip_open(path,0,0)。
 *   F4 0x291ad0..0x291ae0：zip_open == 0 → 跳 0x291c4c 打 "Error loading APK\n"（0x358c1c）再回来；
 *      非 0 → 句柄存 0x757768（CreateFindData / LoadSave::_ReadFile/_FileExists 读它）。
 */
/* @0x291a84 mov r0, r4 */
/* @0x291a88 ldr r3, [r4] —— r3=*env (JNIEnv->functions) */
/* @0x291a8c ldr r3, [r3, #0x2a4] —— r3=env->GetStringUTFChars()  [+0x2a4] */
/* @0x291a90 blx r3 —— CALL env->GetStringUTFChars() */
/* @0x291a94 ldr r3, [r7] —— r3=*env (JNIEnv->functions) */
/* @0x291a98 ldr r1, [pc, #-0xecc] —— r1=0xc7164 (pool 0x290bd4) */
/* @0x291a9c ldr r3, [r3, #0xc] —— r3=vtable+0xc  [+0xc] */
/* @0x291aa0 add r1, pc, r1 —— r1=0x358c0c [pc+0xc7164] | STR "Loading APK %s" */
/* @0x291aa4 mov r9, r0 */
/* @0x291aa8 mov r2, r0 */
/* @0x291aac mov r0, r7 */
/* @0x291ab0 blx r3 —— CALL vtable+0xc */
/* @0x291ab4 ldr r3, [pc, #-0xee4] —— r3=0xfffffccc (pool 0x290bd8) */
/* @0x291ab8 mov r1, #0 */
/* @0x291abc mov r0, r9 */
/* @0x291ac0 mov r2, r1 */
/* @0x291ac4 ldr r3, [r5, r3] —— r3=GOT[0x3f1924] | ->0x757764 */
/* @0x291ac8 str r9, [r3] —— WRITE *(0x757764) <- r9(env) */
/* @0x291acc blx 0x2a4de0 <zip_open> */
/* @0x291ad0 cmp r0, #0 */
/* @0x291ad4 beq 0x291c4c <Java_com_yoyogames_runner_RunnerJNILib_Startup+0x1620> */
/* @0x291ad8 ldr r3, [pc, #-0xf04] —— r3=0xffffe2c4 (pool 0x290bdc) */
/* @0x291adc ldr r3, [r5, r3] —— r3=GOT[0x3eff1c] | ->0x757768 */
/* @0x291ae0 str r0, [r3] —— WRITE *(0x757768) <- r0(env) */


/* ── F5. 三条字符串的释放 + 包名/save 目录 strdup ─────────────────
 *   0x291ae4..0x291aec：`cmp r9,#0; cmpne r8,#0; bne 0x291c30` —— r9 = apk 的 char*、r8 = 它的 jstring；
 *      两者都非空才去 ReleaseStringUTFChars（0x291c44，函数表 0x2a8 = 170），回来 `b 0x291af0`。
 *   0x291af0..0x291b28：GetStringUTFChars(env, [sp+0x58] = packageName) → r8 = char* → strdup →
 *      0x544b94（GetOSSpecificJSON 读）；再 Release（0x291c28）后 `b 0x291b2c`。
 *   0x291b2c..0x291b60：同一套给 r10 = saveFilesDir → strdup → 0x757750（GetSavePrePend 读）；
 *      再 Release（0x291c10）后 `b 0x291b64`。
 *   ⇒ 三条路径用的是同一组「判空 → Release → 跳回」回边，0x291c10/0x291c28/0x291c44 三个释放点。
 */
/* @0x291ae4 cmp r9, #0 */
/* @0x291ae8 cmpne r8, #0 */
/* @0x291aec bne 0x291c30 <Java_com_yoyogames_runner_RunnerJNILib_Startup+0x1604> */
/* @0x291af0 ldr r3, [r4] —— r3=*env (JNIEnv->functions) */
/* @0x291af4 add r2, sp, #47 */
/* @0x291af8 ldr r1, [sp, #0x58] */
/* @0x291afc mov r0, r4 */
/* @0x291b00 ldr r3, [r3, #0x2a4] —— r3=env->GetStringUTFChars()  [+0x2a4] */
/* @0x291b04 blx r3 —— CALL env->GetStringUTFChars() */
/* @0x291b08 mov r8, r0 */
/* @0x291b0c bl 0xb6640 <strdup@plt> */
/* @0x291b10 ldr r3, [pc, #-0xf38] —— r3=0xffffe2c0 (pool 0x290be0) */
/* @0x291b14 ldr r2, [sp, #0x58] */
/* @0x291b18 ldr r3, [r5, r3] —— r3=GOT[0x3eff18] | ->0x544b94 */
/* @0x291b1c cmp r8, #0 */
/* @0x291b20 cmpne r2, #0 */
/* @0x291b24 str r0, [r3] —— WRITE *(0x544b94) <- r0(env) */
/* @0x291b28 bne 0x291c14 <Java_com_yoyogames_runner_RunnerJNILib_Startup+0x15e8> */
/* @0x291b2c ldr r3, [r4] —— r3=*env (JNIEnv->functions) */
/* @0x291b30 add r2, sp, #47 */
/* @0x291b34 mov r1, r10 */
/* @0x291b38 mov r0, r4 */
/* @0x291b3c ldr r3, [r3, #0x2a4] —— r3=env->GetStringUTFChars()  [+0x2a4] */
/* @0x291b40 blx r3 —— CALL env->GetStringUTFChars() */
/* @0x291b44 mov r8, r0 */
/* @0x291b48 bl 0xb6640 <strdup@plt> */
/* @0x291b4c ldr r3, [pc, #-0xf70] —— r3=0xfffffcc8 (pool 0x290be4) */
/* @0x291b50 cmp r8, #0 */
/* @0x291b54 cmpne r10, #0 */
/* @0x291b58 ldr r3, [r5, r3] —— r3=GOT[0x3f1920] | ->0x757750 */
/* @0x291b5c str r0, [r3] —— WRITE *(0x757750) <- r0(env) */
/* @0x291b60 bne 0x291bf8 <Java_com_yoyogames_runner_RunnerJNILib_Startup+0x15cc> */


/* ── F6. 命令行 + 内存管理器 ──────────────────────────────────────
 *   0x291b7c 打印 "Just before strdup\n"（0x358c30，**位置在两次 strdup 之后**，串名与实际时机不符）。
 *   0x291b80 mov r0,#8192 → malloc；0x291b90 取串 "-game game.droid"（0x358c44）；
 *   0x291b9c..0x291bb0 ldm/stm 抄 16 B + `strb lr,[r12]` 补 NUL，指针存 0x542988（g_cmdline）。
 *   0x291bc8 打印 "CommandLine: %s\n"（0x358c58）→ MemoryManager::Init() →
 *   0x291bf0 打印 "MemoryManager allocated: %d\n"（0x358c6c），r2 = *(0x756758)（MemoryManager 记账量）。
 *   0x291bf4 `b 0x2906d8` —— 汇入主路径 ProcessCommandLine(g_cmdline)。**这条 b 让首次块不返回，
 *   而是把控制权交给 D 段**，所以整个函数只有 0x290878 一个出口。
 */
/* @0x291b64 ldr r3, [r7] —— r3=*env (JNIEnv->functions) */
/* @0x291b68 mov r0, r7 */
/* @0x291b6c ldr r1, [pc, #-0xf8c] —— r1=0xc70b4 (pool 0x290be8) */
/* @0x291b70 ldr r8, [pc, #-0xf8c] —— r8=0xfffffd10 (pool 0x290bec) */
/* @0x291b74 add r1, pc, r1 —— r1=0x358c30 [pc+0xc70b4] | STR "Just before strdup\n" */
/* @0x291b78 ldr r3, [r3, #0xc] —— r3=vtable+0xc  [+0xc] */
/* @0x291b7c blx r3 —— CALL vtable+0xc */
/* @0x291b80 mov r0, #8192 */
/* @0x291b84 bl 0xb6544 <malloc@plt> */
/* @0x291b88 ldr lr, [pc, #-0xfa0] —— lr=0xc70ac (pool 0x290bf0) */
/* @0x291b8c ldr r8, [r5, r8] —— r8=GOT[0x3f1968] | ->0x542988 */
/* @0x291b90 add lr, pc, lr —— lr=0x358c44 [pc+0xc70ac] | STR "-game game.droid" */
/* @0x291b94 mov r9, r0 */
/* @0x291b98 mov r12, r0 */
/* @0x291b9c ldm lr!, {r0, r1, r2, r3} */
/* @0x291ba0 str r9, [r8] —— WRITE *(0x542988) <- r9(env) */
/* @0x291ba4 ldr lr, [lr] */
/* @0x291ba8 stm r12!, {r0, r1, r2, r3} */
/* @0x291bac mov r2, r9 */
/* @0x291bb0 strb lr, [r12] */
/* @0x291bb4 mov r0, r7 */
/* @0x291bb8 ldr r3, [r7] —— r3=*env (JNIEnv->functions) */
/* @0x291bbc ldr r1, [pc, #-0xfd0] —— r1=0xc708c (pool 0x290bf4) */
/* @0x291bc0 ldr r3, [r3, #0xc] —— r3=vtable+0xc  [+0xc] */
/* @0x291bc4 add r1, pc, r1 —— r1=0x358c58 [pc+0xc708c] | STR "CommandLine: %s\n" */
/* @0x291bc8 blx r3 —— CALL vtable+0xc */
/* @0x291bcc bl 0x27c23c <_ZN13MemoryManager4InitEv> */
/* @0x291bd0 ldr r2, [pc, #-0xfe0] —— r2=0xffffe788 (pool 0x290bf8) */
/* @0x291bd4 ldr r3, [r7] —— r3=*env (JNIEnv->functions) */
/* @0x291bd8 mov r0, r7 */
/* @0x291bdc ldr r1, [pc, #-0xfe8] —— r1=0xc7080 (pool 0x290bfc) */
/* @0x291be0 ldr r2, [r5, r2] —— r2=GOT[0x3f03e0] | ->0x756758 */
/* @0x291be4 add r1, pc, r1 —— r1=0x358c6c [pc+0xc7080] | STR "MemoryManager allocated: %d\n" */
/* @0x291be8 ldr r3, [r3, #0xc] —— r3=vtable+0xc  [+0xc] */
/* @0x291bec ldr r2, [r2] —— r2=*(0x756758) */
/* @0x291bf0 blx r3 —— CALL vtable+0xc */
/* @0x291bf4 b 0x2906d8 <Java_com_yoyogames_runner_RunnerJNILib_Startup+0xac> */


/* ── G. 三条释放回边的落点（0x291bf8 / 0x291c14 / 0x291c30 与 0x291c4c）──
 *   0x291bf8：ReleaseStringUTFChars(env, saveFilesDir, r8) → b 0x291b64（回命令行组装）。
 *   0x291c14：ReleaseStringUTFChars(env, packageName, r8) → b 0x291b2c（去做 save 目录）。
 *   0x291c30：ReleaseStringUTFChars(env, apkFilePath, r9) → b 0x291af0（去做包名）。
 *   0x291c4c：zip_open 失败时打印 "Error loading APK\n"，0x291c64 `b 0x291ae4` 继续走释放/后续 ——
 *             **失败不返回**，只是少了一个 zip 句柄。
 */
/* @0x291bf8 ldr r3, [r4] —— r3=*env (JNIEnv->functions) */
/* @0x291bfc mov r1, r10 */
/* @0x291c00 mov r2, r8 */
/* @0x291c04 mov r0, r4 */
/* @0x291c08 ldr r3, [r3, #0x2a8] —— r3=env->ReleaseStringUTFChars()  [+0x2a8] */
/* @0x291c0c blx r3 —— CALL env->ReleaseStringUTFChars() */
/* @0x291c10 b 0x291b64 <Java_com_yoyogames_runner_RunnerJNILib_Startup+0x1538> */
/* @0x291c14 ldr r3, [r4] —— r3=*env (JNIEnv->functions) */
/* @0x291c18 mov r2, r8 */
/* @0x291c1c mov r0, r4 */
/* @0x291c20 ldr r1, [sp, #0x58] */
/* @0x291c24 ldr r3, [r3, #0x2a8] —— r3=env->ReleaseStringUTFChars()  [+0x2a8] */
/* @0x291c28 blx r3 —— CALL env->ReleaseStringUTFChars() */
/* @0x291c2c b 0x291b2c <Java_com_yoyogames_runner_RunnerJNILib_Startup+0x1500> */
/* @0x291c30 ldr r3, [r4] —— r3=*env (JNIEnv->functions) */
/* @0x291c34 mov r1, r8 */
/* @0x291c38 mov r2, r9 */
/* @0x291c3c mov r0, r4 */
/* @0x291c40 ldr r3, [r3, #0x2a8] —— r3=env->ReleaseStringUTFChars()  [+0x2a8] */
/* @0x291c44 blx r3 —— CALL env->ReleaseStringUTFChars() */
/* @0x291c48 b 0x291af0 <Java_com_yoyogames_runner_RunnerJNILib_Startup+0x14c4> */
/* @0x291c4c ldr r3, [r7] —— r3=*env (JNIEnv->functions) */
/* @0x291c50 mov r0, r7 */
/* @0x291c54 ldr r1, [pc, #0xc] —— r1=0xc6fb8 (pool 0x291c68) */
/* @0x291c58 ldr r3, [r3, #0xc] —— r3=vtable+0xc  [+0xc] */
/* @0x291c5c add r1, pc, r1 —— r1=0x358c1c [pc+0xc6fb8] | STR "Error loading APK" */
/* @0x291c60 blx r3 —— CALL vtable+0xc */
/* @0x291c64 b 0x291ae4 <Java_com_yoyogames_runner_RunnerJNILib_Startup+0x14b8> */


/* ── H2. 尾部最后一个池字（0x291c68）────────────────────────────
 *   0xc6fb8，由 0x291c54 `ldr r1,[pc,#0xc]` 取用：pc = 0x291c5c + 0xc6fb8 = 0x358c1c = "Error loading APK\n"。
 *   全函数到此结束（下一字节 0x291c6c 是下一个 JNI 入口 TouchEvent）。
 */
/* @0x291c68 strheq r6, [r12], -r8 —— pc 相对串偏移 → "Error loading APK"（0x291c54 取用） */
/* ══ §2 InitGlobalVariables 0x1fd184 ═════════════════════════════════
 * @func 0x1fd184 0x1fe4fc size 4988  1247 条（930 指令 + 317 池字：0x1fe00c..0x1fe4fc，
 *       代码段 0x1fd184..0x1fe008 全是直线，一条分支都没有）
 * 级别: 正文（120 条 Variable_BuiltIn_Add 的「名字/ getter / setter / 第 4 实参」全表逐条落地，
 *       首条快照写入、尾跳目标、表容量与追加语义全部钉住；未读的是 getter/setter 内部与哈希插入细节）
 * 符号: _Z19InitGlobalVariablesv → void InitGlobalVariables()
 * ABI : softfp；无入参
 * 返回: 无（尾跳 InitYoYoBuiltInVariables，后者的返回值即本函数的返回值）
 * 调用者: INITIALIZE_Variable_BuiltIn 0x1ffbd0 的尾跳（0x1ffc90 `b 0x1fd184`，全库唯一）
 * 同层: Variable_BuiltIn_Add 0x1f4da8、Variable_BuiltIn_Find 0x1f3a5c、Variable_BuiltIn_Find_Name 0x1f3b38、
 *       FINALIZE_Variable_Main 0x1f4d10、CreateNameFile 0x1ffb30、
 *       InitLocalVariables 0x1fed5c、InitYoYoBuiltInVariables 0x15dafc、
 *       F_VariableGlobalGet 0x114db0 / F_VariableGlobalSet 0x114e50 / F_VariableGlobalExists 0x1197a4（前两个是快照的读者）
 *
 * ── 一句话 ──────────────────────────────────────────────────────────
 *   先把「当前内置变量条数」抄进 0x755064 当分界线，然后用 120 条 Variable_BuiltIn_Add 把 GML 的
 *   内置全局变量（argument/room/background/view/mouse/keyboard/current_…/event/score/…）连同
 *   各自的 GV_* getter 与 SV_* setter 注册进 builtin 变量表，最后尾跳 InitYoYoBuiltInVariables
 *   再补 5 条只读（os_type/os_device/os_version/os_browser/browser_width）。
 *
 * ── 表结构（由 Variable_BuiltIn_Add 的写点反推，逐条有锚）───────────────
 *   计数与数组是紧邻的两块 .bss：0x753108 = 条数，0x75310c = 数组本体（就地摆放，不是指针），
 *   500 × 16 B = 8000 B，由 INITIALIZE_Variable_BuiltIn 在 0x1ffc84 直接 memset(0x75310c,0,8000) 清零。
 *   （同一簇里 0x7530fc 存的是另一个 1536 B 表 = 128 × 12 的局部变量表，别混。）
 *   条目 16 B：+0 名字（YYStrDup 出来的自有串）、+4 getter、+8 setter、+0xc 字节（= setter != NULL）。
 *   名字查找另有 CHashMap（Variable_BuiltIn_Add 里 CHashMapCalculateHash 0x1eeb88 + 12 B 桶项）。
 *   容量 500：0x1f4dcc `cmp r3,#500; beq 0x1f5024`。
 *
 * ── 首条语句：快照（不是注册）─────────────────────────────────────
 *   0x1fd188..0x1fd1b8：r4 = GOT 基址 0x3f1c58（池字 0x1f4ab8）；r2 = r3 = 0（给首条 Add 当 setter/bool）；
 *   r12 = 0x755064（GOT 0x3ee430）；r0 = 0x753108（GOT 0x3edc3c）→ lr = *(0x753108) = 条数；
 *   0x1fd1b8 `str lr,[r12]` ⇒ *(0x755064) = 当前内置变量条数。
 *   0x755064 的两个读者是 F_VariableGlobalGet / F_VariableGlobalSet：它们先 Variable_BuiltIn_Find(name)，
 *   若返回的索引 < *(0x755064) 就返回 undefined —— 即「内置变量不当作 GML 的全局变量读写」。
 */
/* @0x1fd184 push {r4, r5, r6, r7, r8, lr} */
/* @0x1fd188 mov r2, #0 */
/* @0x1fd18c ldr r4, [pc, #0xe78] —— r4=0x1f4ab8 (pool 0x1fe00c) */
/* @0x1fd190 mov r3, r2 */
/* @0x1fd194 ldr r12, [pc, #0xe74] —— r12=0xffffbfe4 (pool 0x1fe010) */
/* @0x1fd198 add r4, pc, r4 —— r4=0x3f1c58 [pc+0x1f4ab8] */
/* @0x1fd19c ldr r0, [pc, #0xe70] —— r0=0xffffc7d8 (pool 0x1fe014) */
/* @0x1fd1a0 ldr r1, [pc, #0xe70] —— r1=0xfffff1f0 (pool 0x1fe018) */
/* @0x1fd1a4 ldr lr, [r4, r12] —— lr=GOT[0x3edc3c] | ->0x753108 */
/* @0x1fd1a8 ldr r12, [r4, r0] —— r12=GOT[0x3ee430] | ->0x755064 */
/* @0x1fd1ac ldr r0, [pc, #0xe68] —— r0=0x1558cc (pool 0x1fe01c) */
/* @0x1fd1b0 ldr lr, [lr] —— lr=*(0x753108) */
/* @0x1fd1b4 add r0, pc, r0 —— r0=0x352a88 [pc+0x1558cc] | STR "argument_relative" */
/* @0x1fd1b8 str lr, [r12] —— WRITE *(0x755064) <- lr(x) */
/* @0x1fd1bc ldr r1, [r4, r1] —— r1=GOT[0x3f0e48] | ->0x1f79ac */

/* ── ① argument 族 19 条（0x1fd1c0..0x1fd3e0，步长 0x20 = 8 条指令/条）──────
 *   顺序：argument_relative（getter GV_ArgumentRelative 0x1f79ac、无 setter、bool 0）→
 *   argument（GV_/SV_Argument 0x1ffca4/0x1fa444）→ argument0..argument15
 *   （GV_Argument0..15 0x1ffe1c 起每 +0x88，SV_Argument0..15 0x1fa47c 起每 +0x30；最后一对落在
 *    0x200610/0x1fa748 = SV_Argument15）。注意「无 setter」的项是 r2 = 0（立即数），不是某个函数地址，别把 0x1fa748 当空指针。
 *   每条都是同一模板：ldr r1/r2 = GOT 槽 → ldr r0 = 池字 + pc（名字串）→ mov r3,#1 → bl。
 */
/* @0x1fd1c0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd1c4 ldr r1, [pc, #0xe54] —— r1=0xfffff1f4 (pool 0x1fe020) */
/* @0x1fd1c8 ldr r2, [pc, #0xe54] —— r2=0xfffff1f8 (pool 0x1fe024) */
/* @0x1fd1cc mov r3, #1 */
/* @0x1fd1d0 ldr r0, [pc, #0xe50] —— r0=0x1558b8 (pool 0x1fe028) */
/* @0x1fd1d4 ldr r1, [r4, r1] —— r1=GOT[0x3f0e4c] | ->0x1ffca4 */
/* @0x1fd1d8 ldr r2, [r4, r2] —— r2=GOT[0x3f0e50] | ->0x1fa444 */
/* @0x1fd1dc add r0, pc, r0 —— r0=0x352a9c [pc+0x1558b8] | STR "argument" */
/* @0x1fd1e0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd1e4 ldr r1, [pc, #0xe40] —— r1=0xfffff1fc (pool 0x1fe02c) */
/* @0x1fd1e8 ldr r2, [pc, #0xe40] —— r2=0xfffff200 (pool 0x1fe030) */
/* @0x1fd1ec mov r3, #1 */
/* @0x1fd1f0 ldr r0, [pc, #0xe3c] —— r0=0x1558a4 (pool 0x1fe034) */
/* @0x1fd1f4 ldr r1, [r4, r1] —— r1=GOT[0x3f0e54] | ->0x1ffe1c */
/* @0x1fd1f8 ldr r2, [r4, r2] —— r2=GOT[0x3f0e58] | ->0x1fa47c */
/* @0x1fd1fc add r0, pc, r0 —— r0=0x352aa8 [pc+0x1558a4] | STR "argument0" */
/* @0x1fd200 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd204 ldr r1, [pc, #0xe2c] —— r1=0xfffff204 (pool 0x1fe038) */
/* @0x1fd208 ldr r2, [pc, #0xe2c] —— r2=0xfffff208 (pool 0x1fe03c) */
/* @0x1fd20c mov r3, #1 */
/* @0x1fd210 ldr r0, [pc, #0xe28] —— r0=0x155890 (pool 0x1fe040) */
/* @0x1fd214 ldr r1, [r4, r1] —— r1=GOT[0x3f0e5c] | ->0x1ffea0 */
/* @0x1fd218 ldr r2, [r4, r2] —— r2=GOT[0x3f0e60] | ->0x1fa4a8 */
/* @0x1fd21c add r0, pc, r0 —— r0=0x352ab4 [pc+0x155890] | STR "argument1" */
/* @0x1fd220 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd224 ldr r1, [pc, #0xe18] —— r1=0xfffff20c (pool 0x1fe044) */
/* @0x1fd228 ldr r2, [pc, #0xe18] —— r2=0xfffff210 (pool 0x1fe048) */
/* @0x1fd22c mov r3, #1 */
/* @0x1fd230 ldr r0, [pc, #0xe14] —— r0=0x15587c (pool 0x1fe04c) */
/* @0x1fd234 ldr r1, [r4, r1] —— r1=GOT[0x3f0e64] | ->0x1fff28 */
/* @0x1fd238 ldr r2, [r4, r2] —— r2=GOT[0x3f0e68] | ->0x1fa4d8 */
/* @0x1fd23c add r0, pc, r0 —— r0=0x352ac0 [pc+0x15587c] | STR "argument2" */
/* @0x1fd240 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd244 ldr r1, [pc, #0xe04] —— r1=0xfffff214 (pool 0x1fe050) */
/* @0x1fd248 ldr r2, [pc, #0xe04] —— r2=0xfffff218 (pool 0x1fe054) */
/* @0x1fd24c mov r3, #1 */
/* @0x1fd250 ldr r0, [pc, #0xe00] —— r0=0x155868 (pool 0x1fe058) */
/* @0x1fd254 ldr r1, [r4, r1] —— r1=GOT[0x3f0e6c] | ->0x1fffb0 */
/* @0x1fd258 ldr r2, [r4, r2] —— r2=GOT[0x3f0e70] | ->0x1fa508 */
/* @0x1fd25c add r0, pc, r0 —— r0=0x352acc [pc+0x155868] | STR "argument3" */
/* @0x1fd260 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd264 ldr r1, [pc, #0xdf0] —— r1=0xfffff21c (pool 0x1fe05c) */
/* @0x1fd268 ldr r2, [pc, #0xdf0] —— r2=0xfffff220 (pool 0x1fe060) */
/* @0x1fd26c mov r3, #1 */
/* @0x1fd270 ldr r0, [pc, #0xdec] —— r0=0x155854 (pool 0x1fe064) */
/* @0x1fd274 ldr r1, [r4, r1] —— r1=GOT[0x3f0e74] | ->0x200038 */
/* @0x1fd278 ldr r2, [r4, r2] —— r2=GOT[0x3f0e78] | ->0x1fa538 */
/* @0x1fd27c add r0, pc, r0 —— r0=0x352ad8 [pc+0x155854] | STR "argument4" */
/* @0x1fd280 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd284 ldr r1, [pc, #0xddc] —— r1=0xfffff224 (pool 0x1fe068) */
/* @0x1fd288 ldr r2, [pc, #0xddc] —— r2=0xfffff228 (pool 0x1fe06c) */
/* @0x1fd28c mov r3, #1 */
/* @0x1fd290 ldr r0, [pc, #0xdd8] —— r0=0x155840 (pool 0x1fe070) */
/* @0x1fd294 ldr r1, [r4, r1] —— r1=GOT[0x3f0e7c] | ->0x2000c0 */
/* @0x1fd298 ldr r2, [r4, r2] —— r2=GOT[0x3f0e80] | ->0x1fa568 */
/* @0x1fd29c add r0, pc, r0 —— r0=0x352ae4 [pc+0x155840] | STR "argument5" */
/* @0x1fd2a0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd2a4 ldr r1, [pc, #0xdc8] —— r1=0xfffff22c (pool 0x1fe074) */
/* @0x1fd2a8 ldr r2, [pc, #0xdc8] —— r2=0xfffff230 (pool 0x1fe078) */
/* @0x1fd2ac mov r3, #1 */
/* @0x1fd2b0 ldr r0, [pc, #0xdc4] —— r0=0x15582c (pool 0x1fe07c) */
/* @0x1fd2b4 ldr r1, [r4, r1] —— r1=GOT[0x3f0e84] | ->0x200148 */
/* @0x1fd2b8 ldr r2, [r4, r2] —— r2=GOT[0x3f0e88] | ->0x1fa598 */
/* @0x1fd2bc add r0, pc, r0 —— r0=0x352af0 [pc+0x15582c] | STR "argument6" */
/* @0x1fd2c0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd2c4 ldr r1, [pc, #0xdb4] —— r1=0xfffff234 (pool 0x1fe080) */
/* @0x1fd2c8 ldr r2, [pc, #0xdb4] —— r2=0xfffff238 (pool 0x1fe084) */
/* @0x1fd2cc mov r3, #1 */
/* @0x1fd2d0 ldr r0, [pc, #0xdb0] —— r0=0x155818 (pool 0x1fe088) */
/* @0x1fd2d4 ldr r1, [r4, r1] —— r1=GOT[0x3f0e8c] | ->0x2001d0 */
/* @0x1fd2d8 ldr r2, [r4, r2] —— r2=GOT[0x3f0e90] | ->0x1fa5c8 */
/* @0x1fd2dc add r0, pc, r0 —— r0=0x352afc [pc+0x155818] | STR "argument7" */
/* @0x1fd2e0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd2e4 ldr r1, [pc, #0xda0] —— r1=0xfffff23c (pool 0x1fe08c) */
/* @0x1fd2e8 ldr r2, [pc, #0xda0] —— r2=0xfffff240 (pool 0x1fe090) */
/* @0x1fd2ec mov r3, #1 */
/* @0x1fd2f0 ldr r0, [pc, #0xd9c] —— r0=0x155804 (pool 0x1fe094) */
/* @0x1fd2f4 ldr r1, [r4, r1] —— r1=GOT[0x3f0e94] | ->0x200258 */
/* @0x1fd2f8 ldr r2, [r4, r2] —— r2=GOT[0x3f0e98] | ->0x1fa5f8 */
/* @0x1fd2fc add r0, pc, r0 —— r0=0x352b08 [pc+0x155804] | STR "argument8" */
/* @0x1fd300 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd304 ldr r1, [pc, #0xd8c] —— r1=0xfffff244 (pool 0x1fe098) */
/* @0x1fd308 ldr r2, [pc, #0xd8c] —— r2=0xfffff248 (pool 0x1fe09c) */
/* @0x1fd30c mov r3, #1 */
/* @0x1fd310 ldr r0, [pc, #0xd88] —— r0=0x1557f0 (pool 0x1fe0a0) */
/* @0x1fd314 ldr r1, [r4, r1] —— r1=GOT[0x3f0e9c] | ->0x2002e0 */
/* @0x1fd318 ldr r2, [r4, r2] —— r2=GOT[0x3f0ea0] | ->0x1fa628 */
/* @0x1fd31c add r0, pc, r0 —— r0=0x352b14 [pc+0x1557f0] | STR "argument9" */
/* @0x1fd320 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd324 ldr r1, [pc, #0xd78] —— r1=0xfffff24c (pool 0x1fe0a4) */
/* @0x1fd328 ldr r2, [pc, #0xd78] —— r2=0xfffff250 (pool 0x1fe0a8) */
/* @0x1fd32c mov r3, #1 */
/* @0x1fd330 ldr r0, [pc, #0xd74] —— r0=0x1557dc (pool 0x1fe0ac) */
/* @0x1fd334 ldr r1, [r4, r1] —— r1=GOT[0x3f0ea4] | ->0x200368 */
/* @0x1fd338 ldr r2, [r4, r2] —— r2=GOT[0x3f0ea8] | ->0x1fa658 */
/* @0x1fd33c add r0, pc, r0 —— r0=0x352b20 [pc+0x1557dc] | STR "argument10" */
/* @0x1fd340 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd344 ldr r1, [pc, #0xd64] —— r1=0xfffff254 (pool 0x1fe0b0) */
/* @0x1fd348 ldr r2, [pc, #0xd64] —— r2=0xfffff258 (pool 0x1fe0b4) */
/* @0x1fd34c mov r3, #1 */
/* @0x1fd350 ldr r0, [pc, #0xd60] —— r0=0x1557c8 (pool 0x1fe0b8) */
/* @0x1fd354 ldr r1, [r4, r1] —— r1=GOT[0x3f0eac] | ->0x2003f0 */
/* @0x1fd358 ldr r2, [r4, r2] —— r2=GOT[0x3f0eb0] | ->0x1fa688 */
/* @0x1fd35c add r0, pc, r0 —— r0=0x352b2c [pc+0x1557c8] | STR "argument11" */
/* @0x1fd360 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd364 ldr r1, [pc, #0xd50] —— r1=0xfffff25c (pool 0x1fe0bc) */
/* @0x1fd368 ldr r2, [pc, #0xd50] —— r2=0xfffff260 (pool 0x1fe0c0) */
/* @0x1fd36c mov r3, #1 */
/* @0x1fd370 ldr r0, [pc, #0xd4c] —— r0=0x1557b4 (pool 0x1fe0c4) */
/* @0x1fd374 ldr r1, [r4, r1] —— r1=GOT[0x3f0eb4] | ->0x200478 */
/* @0x1fd378 ldr r2, [r4, r2] —— r2=GOT[0x3f0eb8] | ->0x1fa6b8 */
/* @0x1fd37c add r0, pc, r0 —— r0=0x352b38 [pc+0x1557b4] | STR "argument12" */
/* @0x1fd380 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd384 ldr r1, [pc, #0xd3c] —— r1=0xfffff264 (pool 0x1fe0c8) */
/* @0x1fd388 ldr r2, [pc, #0xd3c] —— r2=0xfffff268 (pool 0x1fe0cc) */
/* @0x1fd38c mov r3, #1 */
/* @0x1fd390 ldr r0, [pc, #0xd38] —— r0=0x1557a0 (pool 0x1fe0d0) */
/* @0x1fd394 ldr r1, [r4, r1] —— r1=GOT[0x3f0ebc] | ->0x200500 */
/* @0x1fd398 ldr r2, [r4, r2] —— r2=GOT[0x3f0ec0] | ->0x1fa6e8 */
/* @0x1fd39c add r0, pc, r0 —— r0=0x352b44 [pc+0x1557a0] | STR "argument13" */
/* @0x1fd3a0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd3a4 ldr r1, [pc, #0xd28] —— r1=0xfffff26c (pool 0x1fe0d4) */
/* @0x1fd3a8 ldr r2, [pc, #0xd28] —— r2=0xfffff270 (pool 0x1fe0d8) */
/* @0x1fd3ac mov r3, #1 */
/* @0x1fd3b0 ldr r0, [pc, #0xd24] —— r0=0x15578c (pool 0x1fe0dc) */
/* @0x1fd3b4 ldr r1, [r4, r1] —— r1=GOT[0x3f0ec4] | ->0x200588 */
/* @0x1fd3b8 ldr r2, [r4, r2] —— r2=GOT[0x3f0ec8] | ->0x1fa718 */
/* @0x1fd3bc add r0, pc, r0 —— r0=0x352b50 [pc+0x15578c] | STR "argument14" */
/* @0x1fd3c0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd3c4 ldr r1, [pc, #0xd14] —— r1=0xfffff274 (pool 0x1fe0e0) */
/* @0x1fd3c8 ldr r2, [pc, #0xd14] —— r2=0xfffff278 (pool 0x1fe0e4) */
/* @0x1fd3cc mov r3, #1 */
/* @0x1fd3d0 ldr r0, [pc, #0xd10] —— r0=0x155778 (pool 0x1fe0e8) */
/* @0x1fd3d4 ldr r1, [r4, r1] —— r1=GOT[0x3f0ecc] | ->0x200610 */
/* @0x1fd3d8 ldr r2, [r4, r2] —— r2=GOT[0x3f0ed0] | ->0x1fa748 */
/* @0x1fd3dc add r0, pc, r0 —— r0=0x352b5c [pc+0x155778] | STR "argument15" */
/* @0x1fd3e0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd3e4 ldr r1, [pc, #0xd00] —— r1=0xfffff27c (pool 0x1fe0ec) */
/* @0x1fd3e8 ldr r0, [pc, #0xd00] —— r0=0x155768 (pool 0x1fe0f0) */
/* @0x1fd3ec mov r2, #0 */
/* @0x1fd3f0 mov r3, #1 */
/* @0x1fd3f4 ldr r1, [r4, r1] —— r1=GOT[0x3f0ed4] | ->0x200c88 */
/* @0x1fd3f8 add r0, pc, r0 —— r0=0x352b68 [pc+0x155768] | STR "argument_count" */
/* @0x1fd3fc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd400 ldr r1, [pc, #0xcec] —— r1=0xfffff280 (pool 0x1fe0f4) */
/* @0x1fd404 ldr r0, [pc, #0xcec] —— r0=0x15575c (pool 0x1fe0f8) */
/* @0x1fd408 mov r2, #0 */
/* @0x1fd40c mov r3, #1 */
/* @0x1fd410 ldr r1, [r4, r1] —— r1=GOT[0x3f0ed8] | ->0x200ea4 */
/* @0x1fd414 add r0, pc, r0 —— r0=0x352b78 [pc+0x15575c] | STR "debug_mode" */
/* @0x1fd418 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd41c ldr r1, [pc, #0xcd8] —— r1=0xfffff284 (pool 0x1fe0fc) */
/* @0x1fd420 ldr r0, [pc, #0xcd8] —— r0=0x15574c (pool 0x1fe100) */
/* @0x1fd424 mov r2, #0 */
/* @0x1fd428 mov r3, r2 */
/* @0x1fd42c ldr r1, [r4, r1] —— r1=GOT[0x3f0edc] | ->0x200a8c */
/* @0x1fd430 add r0, pc, r0 —— r0=0x352b84 [pc+0x15574c] | STR "pointer_invalid" */
/* @0x1fd434 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd438 ldr r1, [pc, #0xcc4] —— r1=0xfffff288 (pool 0x1fe104) */
/* @0x1fd43c ldr r0, [pc, #0xcc4] —— r0=0x155740 (pool 0x1fe108) */
/* @0x1fd440 mov r2, #0 */
/* @0x1fd444 mov r3, r2 */
/* @0x1fd448 ldr r1, [r4, r1] —— r1=GOT[0x3f0ee0] | ->0x200698 */
/* @0x1fd44c add r0, pc, r0 —— r0=0x352b94 [pc+0x155740] | STR "pointer_null" */
/* @0x1fd450 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd454 ldr r1, [pc, #0xcb0] —— r1=0xfffff28c (pool 0x1fe10c) */
/* @0x1fd458 ldr r0, [pc, #0xcb0] —— r0=0x134df8 (pool 0x1fe110) */
/* @0x1fd45c mov r2, #0 */
/* @0x1fd460 mov r3, r2 */
/* @0x1fd464 ldr r1, [r4, r1] —— r1=GOT[0x3f0ee4] | ->0x200890 */
/* @0x1fd468 add r0, pc, r0 —— r0=0x332268 [pc+0x134df8] | STR "undefined" */
/* @0x1fd46c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd470 ldr r1, [pc, #0xc9c] —— r1=0xfffff290 (pool 0x1fe114) */
/* @0x1fd474 ldr r2, [pc, #0xc9c] —— r2=0xfffff294 (pool 0x1fe118) */
/* @0x1fd478 mov r3, #1 */
/* @0x1fd47c ldr r0, [pc, #0xc98] —— r0=0x155714 (pool 0x1fe11c) */
/* @0x1fd480 ldr r1, [r4, r1] —— r1=GOT[0x3f0ee8] | ->0x1f79ec */
/* @0x1fd484 ldr r2, [r4, r2] —— r2=GOT[0x3f0eec] | ->0x1fa7d4 */
/* @0x1fd488 add r0, pc, r0 —— r0=0x352ba4 [pc+0x155714] | STR "room" */

/* ── ② room / 计分 / 游戏标识 / 目录 / 实例（0x1fd48c..0x1fd73c）────
 *   room(GV_Room/SV_Room)、room_first、room_last、transition_kind、transition_steps、
 *   score(GV_Score/SV_Score)、lives、health、game_id/guid/display_name/project_name/save_id、
 *   working_directory/temp_directory/program_directory、instance_count、instance_id、
 *   room_width/room_height（有 setter 但 bool 传 0）、room_caption、room_speed、room_persistent。
 *   只读项（setter = 0）与可写项混排 —— 说明第 4 实参不是「可写性」（它是死参，见卡头）。
 */
/* @0x1fd48c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd490 ldr r1, [pc, #0xc88] —— r1=0xfffff298 (pool 0x1fe120) */
/* @0x1fd494 ldr r0, [pc, #0xc88] —— r0=0x155700 (pool 0x1fe124) */
/* @0x1fd498 mov r2, #0 */
/* @0x1fd49c mov r3, r2 */
/* @0x1fd4a0 ldr r1, [r4, r1] —— r1=GOT[0x3f0ef0] | ->0x1f9bac */
/* @0x1fd4a4 add r0, pc, r0 —— r0=0x352bac [pc+0x155700] | STR "room_first" */
/* @0x1fd4a8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd4ac ldr r1, [pc, #0xc74] —— r1=0xfffff29c (pool 0x1fe128) */
/* @0x1fd4b0 ldr r0, [pc, #0xc74] —— r0=0x1556f0 (pool 0x1fe12c) */
/* @0x1fd4b4 mov r2, #0 */
/* @0x1fd4b8 mov r3, r2 */
/* @0x1fd4bc ldr r1, [r4, r1] —— r1=GOT[0x3f0ef4] | ->0x1f9be0 */
/* @0x1fd4c0 add r0, pc, r0 —— r0=0x352bb8 [pc+0x1556f0] | STR "room_last" */
/* @0x1fd4c4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd4c8 ldr r1, [pc, #0xc60] —— r1=0xfffff2a0 (pool 0x1fe130) */
/* @0x1fd4cc ldr r2, [pc, #0xc60] —— r2=0xfffff2a4 (pool 0x1fe134) */
/* @0x1fd4d0 mov r3, #1 */
/* @0x1fd4d4 ldr r0, [pc, #0xc5c] —— r0=0x1556dc (pool 0x1fe138) */
/* @0x1fd4d8 ldr r1, [r4, r1] —— r1=GOT[0x3f0ef8] | ->0x1f7a2c */
/* @0x1fd4dc ldr r2, [r4, r2] —— r2=GOT[0x3f0efc] | ->0x1fa778 */
/* @0x1fd4e0 add r0, pc, r0 —— r0=0x352bc4 [pc+0x1556dc] | STR "transition_kind" */
/* @0x1fd4e4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd4e8 ldr r1, [pc, #0xc4c] —— r1=0xfffff2a8 (pool 0x1fe13c) */
/* @0x1fd4ec ldr r2, [pc, #0xc4c] —— r2=0xfffff2ac (pool 0x1fe140) */
/* @0x1fd4f0 mov r3, #1 */
/* @0x1fd4f4 ldr r0, [pc, #0xc48] —— r0=0x1556cc (pool 0x1fe144) */
/* @0x1fd4f8 ldr r1, [r4, r1] —— r1=GOT[0x3f0f00] | ->0x1f7a6c */
/* @0x1fd4fc ldr r2, [r4, r2] —— r2=GOT[0x3f0f04] | ->0x1f8848 */
/* @0x1fd500 add r0, pc, r0 —— r0=0x352bd4 [pc+0x1556cc] | STR "transition_steps" */
/* @0x1fd504 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd508 ldr r1, [pc, #0xc38] —— r1=0xfffff2b0 (pool 0x1fe148) */
/* @0x1fd50c ldr r2, [pc, #0xc38] —— r2=0xfffff2b4 (pool 0x1fe14c) */
/* @0x1fd510 mov r3, #1 */
/* @0x1fd514 ldr r0, [pc, #0xc34] —— r0=0x1556c0 (pool 0x1fe150) */
/* @0x1fd518 ldr r1, [r4, r1] —— r1=GOT[0x3f0f08] | ->0x1f7a84 */
/* @0x1fd51c ldr r2, [r4, r2] —— r2=GOT[0x3f0f0c] | ->0x1fb26c */
/* @0x1fd520 add r0, pc, r0 —— r0=0x352be8 [pc+0x1556c0] | STR "score" */
/* @0x1fd524 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd528 ldr r1, [pc, #0xc24] —— r1=0xfffff2b8 (pool 0x1fe154) */
/* @0x1fd52c ldr r2, [pc, #0xc24] —— r2=0xfffff2bc (pool 0x1fe158) */
/* @0x1fd530 mov r3, #1 */
/* @0x1fd534 ldr r0, [pc, #0xc20] —— r0=0x1556a8 (pool 0x1fe15c) */
/* @0x1fd538 ldr r1, [r4, r1] —— r1=GOT[0x3f0f10] | ->0x1f7ac4 */
/* @0x1fd53c ldr r2, [r4, r2] —— r2=GOT[0x3f0f14] | ->0x1fb2c0 */
/* @0x1fd540 add r0, pc, r0 —— r0=0x352bf0 [pc+0x1556a8] | STR "lives" */
/* @0x1fd544 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd548 ldr r1, [pc, #0xc10] —— r1=0xfffff2c0 (pool 0x1fe160) */
/* @0x1fd54c ldr r2, [pc, #0xc10] —— r2=0xfffff2c4 (pool 0x1fe164) */
/* @0x1fd550 mov r3, #1 */
/* @0x1fd554 ldr r0, [pc, #0xc0c] —— r0=0x155690 (pool 0x1fe168) */
/* @0x1fd558 ldr r1, [r4, r1] —— r1=GOT[0x3f0f18] | ->0x1f7b04 */
/* @0x1fd55c ldr r2, [r4, r2] —— r2=GOT[0x3f0f1c] | ->0x1fb33c */
/* @0x1fd560 add r0, pc, r0 —— r0=0x352bf8 [pc+0x155690] | STR "health" */
/* @0x1fd564 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd568 ldr r1, [pc, #0xbfc] —— r1=0xfffff2c8 (pool 0x1fe16c) */
/* @0x1fd56c ldr r0, [pc, #0xbfc] —— r0=0x15567c (pool 0x1fe170) */
/* @0x1fd570 mov r2, #0 */
/* @0x1fd574 mov r3, r2 */
/* @0x1fd578 ldr r1, [r4, r1] —— r1=GOT[0x3f0f20] | ->0x1f7b30 */
/* @0x1fd57c add r0, pc, r0 —— r0=0x352c00 [pc+0x15567c] | STR "game_id" */
/* @0x1fd580 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd584 ldr r1, [pc, #0xbe8] —— r1=0xfffff2cc (pool 0x1fe174) */
/* @0x1fd588 ldr r0, [pc, #0xbe8] —— r0=0x155668 (pool 0x1fe178) */
/* @0x1fd58c mov r2, #0 */
/* @0x1fd590 mov r3, r2 */
/* @0x1fd594 ldr r1, [r4, r1] —— r1=GOT[0x3f0f24] | ->0x1f9c5c */
/* @0x1fd598 add r0, pc, r0 —— r0=0x352c08 [pc+0x155668] | STR "game_guid" */
/* @0x1fd59c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd5a0 ldr r1, [pc, #0xbd4] —— r1=0xfffff2d0 (pool 0x1fe17c) */
/* @0x1fd5a4 ldr r0, [pc, #0xbd4] —— r0=0x155658 (pool 0x1fe180) */
/* @0x1fd5a8 mov r2, #0 */
/* @0x1fd5ac mov r3, r2 */
/* @0x1fd5b0 ldr r1, [r4, r1] —— r1=GOT[0x3f0f28] | ->0x1f9c14 */
/* @0x1fd5b4 add r0, pc, r0 —— r0=0x352c14 [pc+0x155658] | STR "game_display_name" */
/* @0x1fd5b8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd5bc ldr r1, [pc, #0xbc0] —— r1=0xfffff2d4 (pool 0x1fe184) */
/* @0x1fd5c0 ldr r0, [pc, #0xbc0] —— r0=0x155650 (pool 0x1fe188) */
/* @0x1fd5c4 mov r2, #0 */
/* @0x1fd5c8 mov r3, r2 */
/* @0x1fd5cc ldr r1, [r4, r1] —— r1=GOT[0x3f0f2c] | ->0x1f9c38 */
/* @0x1fd5d0 add r0, pc, r0 —— r0=0x352c28 [pc+0x155650] | STR "game_project_name" */
/* @0x1fd5d4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd5d8 ldr r1, [pc, #0xbac] —— r1=0xfffff2d8 (pool 0x1fe18c) */
/* @0x1fd5dc ldr r0, [pc, #0xbac] —— r0=0x155648 (pool 0x1fe190) */
/* @0x1fd5e0 mov r2, #0 */
/* @0x1fd5e4 mov r3, r2 */
/* @0x1fd5e8 ldr r1, [r4, r1] —— r1=GOT[0x3f0f30] | ->0x1f9d0c */
/* @0x1fd5ec add r0, pc, r0 —— r0=0x352c3c [pc+0x155648] | STR "game_save_id" */
/* @0x1fd5f0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd5f4 ldr r1, [pc, #0xb98] —— r1=0xfffff2dc (pool 0x1fe194) */
/* @0x1fd5f8 ldr r0, [pc, #0xb98] —— r0=0x15563c (pool 0x1fe198) */
/* @0x1fd5fc mov r2, #0 */
/* @0x1fd600 mov r3, r2 */
/* @0x1fd604 ldr r1, [r4, r1] —— r1=GOT[0x3f0f34] | ->0x1f9c74 */
/* @0x1fd608 add r0, pc, r0 —— r0=0x352c4c [pc+0x15563c] | STR "working_directory" */
/* @0x1fd60c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd610 ldr r1, [pc, #0xb84] —— r1=0xfffff2e0 (pool 0x1fe19c) */
/* @0x1fd614 ldr r0, [pc, #0xb84] —— r0=0x155634 (pool 0x1fe1a0) */
/* @0x1fd618 mov r2, #0 */
/* @0x1fd61c mov r3, r2 */
/* @0x1fd620 ldr r1, [r4, r1] —— r1=GOT[0x3f0f38] | ->0x1f9d2c */
/* @0x1fd624 add r0, pc, r0 —— r0=0x352c60 [pc+0x155634] | STR "temp_directory" */
/* @0x1fd628 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd62c ldr r1, [pc, #0xb70] —— r1=0xfffff2e4 (pool 0x1fe1a4) */
/* @0x1fd630 ldr r0, [pc, #0xb70] —— r0=0x155628 (pool 0x1fe1a8) */
/* @0x1fd634 mov r2, #0 */
/* @0x1fd638 mov r3, r2 */
/* @0x1fd63c ldr r1, [r4, r1] —— r1=GOT[0x3f0f3c] | ->0x1f9cc0 */
/* @0x1fd640 add r0, pc, r0 —— r0=0x352c70 [pc+0x155628] | STR "program_directory" */
/* @0x1fd644 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd648 ldr r1, [pc, #0xb5c] —— r1=0xfffff2e8 (pool 0x1fe1ac) */
/* @0x1fd64c ldr r0, [pc, #0xb5c] —— r0=0x155620 (pool 0x1fe1b0) */
/* @0x1fd650 mov r2, #0 */
/* @0x1fd654 mov r3, r2 */
/* @0x1fd658 ldr r1, [r4, r1] —— r1=GOT[0x3f0f40] | ->0x1f7b70 */
/* @0x1fd65c add r0, pc, r0 —— r0=0x352c84 [pc+0x155620] | STR "instance_count" */
/* @0x1fd660 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd664 ldr r1, [pc, #0xb48] —— r1=0xfffff2ec (pool 0x1fe1b4) */
/* @0x1fd668 ldr r0, [pc, #0xb48] —— r0=0x155614 (pool 0x1fe1b8) */
/* @0x1fd66c mov r2, #0 */
/* @0x1fd670 mov r3, r2 */
/* @0x1fd674 ldr r1, [r4, r1] —— r1=GOT[0x3f0f44] | ->0x1fb0a8 */
/* @0x1fd678 add r0, pc, r0 —— r0=0x352c94 [pc+0x155614] | STR "instance_id" */
/* @0x1fd67c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd680 ldr r1, [pc, #0xb34] —— r1=0xfffff2f0 (pool 0x1fe1bc) */
/* @0x1fd684 ldr r2, [pc, #0xb34] —— r2=0xfffff2f4 (pool 0x1fe1c0) */
/* @0x1fd688 mov r3, #0 */
/* @0x1fd68c ldr r0, [pc, #0xb30] —— r0=0x155600 (pool 0x1fe1c4) */
/* @0x1fd690 ldr r1, [r4, r1] —— r1=GOT[0x3f0f48] | ->0x1f7bb4 */
/* @0x1fd694 ldr r2, [r4, r2] —— r2=GOT[0x3f0f4c] | ->0x1fce7c */
/* @0x1fd698 add r0, pc, r0 —— r0=0x352ca0 [pc+0x155600] | STR "room_width" */
/* @0x1fd69c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd6a0 ldr r1, [pc, #0xb20] —— r1=0xfffff2f8 (pool 0x1fe1c8) */
/* @0x1fd6a4 ldr r2, [pc, #0xb20] —— r2=0xfffff2fc (pool 0x1fe1cc) */
/* @0x1fd6a8 mov r3, #0 */
/* @0x1fd6ac ldr r0, [pc, #0xb1c] —— r0=0x1555ec (pool 0x1fe1d0) */
/* @0x1fd6b0 ldr r1, [r4, r1] —— r1=GOT[0x3f0f50] | ->0x1f7bf8 */
/* @0x1fd6b4 ldr r2, [r4, r2] —— r2=GOT[0x3f0f54] | ->0x1fce24 */
/* @0x1fd6b8 add r0, pc, r0 —— r0=0x352cac [pc+0x1555ec] | STR "room_height" */
/* @0x1fd6bc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd6c0 ldr r1, [pc, #0xb0c] —— r1=0xfffff300 (pool 0x1fe1d4) */
/* @0x1fd6c4 ldr r2, [pc, #0xb0c] —— r2=0xfffff304 (pool 0x1fe1d8) */
/* @0x1fd6c8 mov r3, #1 */
/* @0x1fd6cc ldr r0, [pc, #0xb08] —— r0=0x1555d8 (pool 0x1fe1dc) */
/* @0x1fd6d0 ldr r1, [r4, r1] —— r1=GOT[0x3f0f58] | ->0x1f9c98 */
/* @0x1fd6d4 ldr r2, [r4, r2] —— r2=GOT[0x3f0f5c] | ->0x1fae58 */
/* @0x1fd6d8 add r0, pc, r0 —— r0=0x352cb8 [pc+0x1555d8] | STR "room_caption" */
/* @0x1fd6dc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd6e0 ldr r1, [pc, #0xaf8] —— r1=0xfffff308 (pool 0x1fe1e0) */
/* @0x1fd6e4 ldr r2, [pc, #0xaf8] —— r2=0xfffff30c (pool 0x1fe1e4) */
/* @0x1fd6e8 mov r3, #1 */
/* @0x1fd6ec ldr r0, [pc, #0xaf4] —— r0=0x1555c8 (pool 0x1fe1e8) */
/* @0x1fd6f0 ldr r1, [r4, r1] —— r1=GOT[0x3f0f60] | ->0x1faeb0 */
/* @0x1fd6f4 ldr r2, [r4, r2] —— r2=GOT[0x3f0f64] | ->0x1fced4 */
/* @0x1fd6f8 add r0, pc, r0 —— r0=0x352cc8 [pc+0x1555c8] | STR "room_speed" */
/* @0x1fd6fc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd700 ldr r1, [pc, #0xae4] —— r1=0xfffff310 (pool 0x1fe1ec) */
/* @0x1fd704 ldr r2, [pc, #0xae4] —— r2=0xfffff314 (pool 0x1fe1f0) */
/* @0x1fd708 mov r3, #1 */
/* @0x1fd70c ldr r0, [pc, #0xae0] —— r0=0x1555b4 (pool 0x1fe1f4) */
/* @0x1fd710 ldr r1, [r4, r1] —— r1=GOT[0x3f0f68] | ->0x1f7c3c */
/* @0x1fd714 ldr r2, [r4, r2] —— r2=GOT[0x3f0f6c] | ->0x1fcf9c */
/* @0x1fd718 add r0, pc, r0 —— r0=0x352cd4 [pc+0x1555b4] | STR "room_persistent" */
/* @0x1fd71c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd720 ldr r1, [pc, #0xad0] —— r1=0xfffff318 (pool 0x1fe1f8) */
/* @0x1fd724 ldr r2, [pc, #0xad0] —— r2=0xfffff31c (pool 0x1fe1fc) */
/* @0x1fd728 mov r3, #1 */
/* @0x1fd72c ldr r0, [pc, #0xacc] —— r0=0x1555a4 (pool 0x1fe200) */
/* @0x1fd730 ldr r8, [r4, r1] —— r8=GOT[0x3f0f70] | ->0x1f7c80 */
/* @0x1fd734 ldr r7, [r4, r2] —— r7=GOT[0x3f0f74] | ->0x1fd010 */
/* @0x1fd738 add r0, pc, r0 —— r0=0x352ce4 [pc+0x1555a4] | STR "background_color" */
/* @0x1fd73c mov r1, r8 */
/* @0x1fd740 mov r2, r7 */

/* ── ③ background 族 19 条（0x1fd744..0x1fd974，步长 0x28）───────────
 *   color/showcolor/colour/showcolour（英美拼写各注册一遍，getter/setter 完全同址）、visible、
 *   foreground、index、x、y、width/height（只读）、htiled/vtiled、xscale/yscale、hspeed/vspeed、
 *   blend、alpha。顺序就是 GM 里 bg_* 的声明序。
 */
/* @0x1fd744 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd748 ldr r1, [pc, #0xab4] —— r1=0xfffff320 (pool 0x1fe204) */
/* @0x1fd74c ldr r2, [pc, #0xab4] —— r2=0xfffff324 (pool 0x1fe208) */
/* @0x1fd750 mov r3, #1 */
/* @0x1fd754 ldr r0, [pc, #0xab0] —— r0=0x155590 (pool 0x1fe20c) */
/* @0x1fd758 ldr r6, [r4, r1] —— r6=GOT[0x3f0f78] | ->0x1f7cc4 */
/* @0x1fd75c ldr r5, [r4, r2] —— r5=GOT[0x3f0f7c] | ->0x1fd068 */
/* @0x1fd760 add r0, pc, r0 —— r0=0x352cf8 [pc+0x155590] | STR "background_showcolor" */
/* @0x1fd764 mov r1, r6 */
/* @0x1fd768 mov r2, r5 */
/* @0x1fd76c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd770 ldr r0, [pc, #0xa98] —— r0=0x15558c (pool 0x1fe210) */
/* @0x1fd774 mov r1, r8 */
/* @0x1fd778 mov r2, r7 */
/* @0x1fd77c add r0, pc, r0 —— r0=0x352d10 [pc+0x15558c] | STR "background_colour" */
/* @0x1fd780 mov r3, #1 */
/* @0x1fd784 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd788 ldr r0, [pc, #0xa84] —— r0=0x155588 (pool 0x1fe214) */
/* @0x1fd78c mov r1, r6 */
/* @0x1fd790 mov r2, r5 */
/* @0x1fd794 add r0, pc, r0 —— r0=0x352d24 [pc+0x155588] | STR "background_showcolour" */
/* @0x1fd798 mov r3, #1 */
/* @0x1fd79c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd7a0 ldr r1, [pc, #0xa70] —— r1=0xfffff328 (pool 0x1fe218) */
/* @0x1fd7a4 ldr r2, [pc, #0xa70] —— r2=0xfffff32c (pool 0x1fe21c) */
/* @0x1fd7a8 mov r3, #1 */
/* @0x1fd7ac ldr r0, [pc, #0xa6c] —— r0=0x15557c (pool 0x1fe220) */
/* @0x1fd7b0 ldr r1, [r4, r1] —— r1=GOT[0x3f0f80] | ->0x1f7d08 */
/* @0x1fd7b4 ldr r2, [r4, r2] —— r2=GOT[0x3f0f84] | ->0x1fc8a8 */
/* @0x1fd7b8 add r0, pc, r0 —— r0=0x352d3c [pc+0x15557c] | STR "background_visible" */
/* @0x1fd7bc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd7c0 ldr r1, [pc, #0xa5c] —— r1=0xfffff330 (pool 0x1fe224) */
/* @0x1fd7c4 ldr r2, [pc, #0xa5c] —— r2=0xfffff334 (pool 0x1fe228) */
/* @0x1fd7c8 mov r3, #1 */
/* @0x1fd7cc ldr r0, [pc, #0xa58] —— r0=0x155570 (pool 0x1fe22c) */
/* @0x1fd7d0 ldr r1, [r4, r1] —— r1=GOT[0x3f0f88] | ->0x1f7d5c */
/* @0x1fd7d4 ldr r2, [r4, r2] —— r2=GOT[0x3f0f8c] | ->0x1fc92c */
/* @0x1fd7d8 add r0, pc, r0 —— r0=0x352d50 [pc+0x155570] | STR "background_foreground" */
/* @0x1fd7dc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd7e0 ldr r1, [pc, #0xa48] —— r1=0xfffff338 (pool 0x1fe230) */
/* @0x1fd7e4 ldr r2, [pc, #0xa48] —— r2=0xfffff33c (pool 0x1fe234) */
/* @0x1fd7e8 mov r3, #1 */
/* @0x1fd7ec ldr r0, [pc, #0xa44] —— r0=0x155568 (pool 0x1fe238) */
/* @0x1fd7f0 ldr r1, [r4, r1] —— r1=GOT[0x3f0f90] | ->0x1f7db0 */
/* @0x1fd7f4 ldr r2, [r4, r2] —— r2=GOT[0x3f0f94] | ->0x1fc9b0 */
/* @0x1fd7f8 add r0, pc, r0 —— r0=0x352d68 [pc+0x155568] | STR "background_index" */
/* @0x1fd7fc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd800 ldr r1, [pc, #0xa34] —— r1=0xfffff340 (pool 0x1fe23c) */
/* @0x1fd804 ldr r2, [pc, #0xa34] —— r2=0xfffff344 (pool 0x1fe240) */
/* @0x1fd808 mov r3, #1 */
/* @0x1fd80c ldr r0, [pc, #0xa30] —— r0=0x15555c (pool 0x1fe244) */
/* @0x1fd810 ldr r1, [r4, r1] —— r1=GOT[0x3f0f98] | ->0x1f7e04 */
/* @0x1fd814 ldr r2, [r4, r2] —— r2=GOT[0x3f0f9c] | ->0x1fca18 */
/* @0x1fd818 add r0, pc, r0 —— r0=0x352d7c [pc+0x15555c] | STR "background_x" */
/* @0x1fd81c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd820 ldr r1, [pc, #0xa20] —— r1=0xfffff348 (pool 0x1fe248) */
/* @0x1fd824 ldr r2, [pc, #0xa20] —— r2=0xfffff34c (pool 0x1fe24c) */
/* @0x1fd828 mov r3, #1 */
/* @0x1fd82c ldr r0, [pc, #0xa1c] —— r0=0x15554c (pool 0x1fe250) */
/* @0x1fd830 ldr r1, [r4, r1] —— r1=GOT[0x3f0fa0] | ->0x1f7e54 */
/* @0x1fd834 ldr r2, [r4, r2] —— r2=GOT[0x3f0fa4] | ->0x1fca70 */
/* @0x1fd838 add r0, pc, r0 —— r0=0x352d8c [pc+0x15554c] | STR "background_y" */
/* @0x1fd83c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd840 ldr r1, [pc, #0xa0c] —— r1=0xfffff350 (pool 0x1fe254) */
/* @0x1fd844 ldr r0, [pc, #0xa0c] —— r0=0x155540 (pool 0x1fe258) */
/* @0x1fd848 mov r2, #0 */
/* @0x1fd84c mov r3, r2 */
/* @0x1fd850 ldr r1, [r4, r1] —— r1=GOT[0x3f0fa8] | ->0x1f9f20 */
/* @0x1fd854 add r0, pc, r0 —— r0=0x352d9c [pc+0x155540] | STR "background_width" */
/* @0x1fd858 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd85c ldr r1, [pc, #0x9f8] —— r1=0xfffff354 (pool 0x1fe25c) */
/* @0x1fd860 ldr r0, [pc, #0x9f8] —— r0=0x155538 (pool 0x1fe260) */
/* @0x1fd864 mov r2, #0 */
/* @0x1fd868 mov r3, r2 */
/* @0x1fd86c ldr r1, [r4, r1] —— r1=GOT[0x3f0fac] | ->0x1f9f98 */
/* @0x1fd870 add r0, pc, r0 —— r0=0x352db0 [pc+0x155538] | STR "background_height" */
/* @0x1fd874 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd878 ldr r1, [pc, #0x9e4] —— r1=0xfffff358 (pool 0x1fe264) */
/* @0x1fd87c ldr r2, [pc, #0x9e4] —— r2=0xfffff35c (pool 0x1fe268) */
/* @0x1fd880 mov r3, #1 */
/* @0x1fd884 ldr r0, [pc, #0x9e0] —— r0=0x15552c (pool 0x1fe26c) */
/* @0x1fd888 ldr r1, [r4, r1] —— r1=GOT[0x3f0fb0] | ->0x1f7ea4 */
/* @0x1fd88c ldr r2, [r4, r2] —— r2=GOT[0x3f0fb4] | ->0x1fcac8 */
/* @0x1fd890 add r0, pc, r0 —— r0=0x352dc4 [pc+0x15552c] | STR "background_htiled" */
/* @0x1fd894 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd898 ldr r1, [pc, #0x9d0] —— r1=0xfffff360 (pool 0x1fe270) */
/* @0x1fd89c ldr r2, [pc, #0x9d0] —— r2=0xfffff364 (pool 0x1fe274) */
/* @0x1fd8a0 mov r3, #1 */
/* @0x1fd8a4 ldr r0, [pc, #0x9cc] —— r0=0x155520 (pool 0x1fe278) */
/* @0x1fd8a8 ldr r1, [r4, r1] —— r1=GOT[0x3f0fb8] | ->0x1f7ef8 */
/* @0x1fd8ac ldr r2, [r4, r2] —— r2=GOT[0x3f0fbc] | ->0x1fcb4c */
/* @0x1fd8b0 add r0, pc, r0 —— r0=0x352dd8 [pc+0x155520] | STR "background_vtiled" */
/* @0x1fd8b4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd8b8 ldr r1, [pc, #0x9bc] —— r1=0xfffff368 (pool 0x1fe27c) */
/* @0x1fd8bc ldr r2, [pc, #0x9bc] —— r2=0xfffff36c (pool 0x1fe280) */
/* @0x1fd8c0 mov r3, #1 */
/* @0x1fd8c4 ldr r0, [pc, #0x9b8] —— r0=0x155514 (pool 0x1fe284) */
/* @0x1fd8c8 ldr r1, [r4, r1] —— r1=GOT[0x3f0fc0] | ->0x1f7f4c */
/* @0x1fd8cc ldr r2, [r4, r2] —— r2=GOT[0x3f0fc4] | ->0x1fcbd0 */
/* @0x1fd8d0 add r0, pc, r0 —— r0=0x352dec [pc+0x155514] | STR "background_xscale" */
/* @0x1fd8d4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd8d8 ldr r1, [pc, #0x9a8] —— r1=0xfffff370 (pool 0x1fe288) */
/* @0x1fd8dc ldr r2, [pc, #0x9a8] —— r2=0xfffff374 (pool 0x1fe28c) */
/* @0x1fd8e0 mov r3, #1 */
/* @0x1fd8e4 ldr r0, [pc, #0x9a4] —— r0=0x155508 (pool 0x1fe290) */
/* @0x1fd8e8 ldr r1, [r4, r1] —— r1=GOT[0x3f0fc8] | ->0x1f7f9c */
/* @0x1fd8ec ldr r2, [r4, r2] —— r2=GOT[0x3f0fcc] | ->0x1fcc28 */
/* @0x1fd8f0 add r0, pc, r0 —— r0=0x352e00 [pc+0x155508] | STR "background_yscale" */
/* @0x1fd8f4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd8f8 ldr r1, [pc, #0x994] —— r1=0xfffff378 (pool 0x1fe294) */
/* @0x1fd8fc ldr r2, [pc, #0x994] —— r2=0xfffff37c (pool 0x1fe298) */
/* @0x1fd900 mov r3, #1 */
/* @0x1fd904 ldr r0, [pc, #0x990] —— r0=0x1554fc (pool 0x1fe29c) */
/* @0x1fd908 ldr r1, [r4, r1] —— r1=GOT[0x3f0fd0] | ->0x1f7fec */
/* @0x1fd90c ldr r2, [r4, r2] —— r2=GOT[0x3f0fd4] | ->0x1fcc80 */
/* @0x1fd910 add r0, pc, r0 —— r0=0x352e14 [pc+0x1554fc] | STR "background_hspeed" */
/* @0x1fd914 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd918 ldr r1, [pc, #0x980] —— r1=0xfffff380 (pool 0x1fe2a0) */
/* @0x1fd91c ldr r2, [pc, #0x980] —— r2=0xfffff384 (pool 0x1fe2a4) */
/* @0x1fd920 mov r3, #1 */
/* @0x1fd924 ldr r0, [pc, #0x97c] —— r0=0x1554f0 (pool 0x1fe2a8) */
/* @0x1fd928 ldr r1, [r4, r1] —— r1=GOT[0x3f0fd8] | ->0x1f803c */
/* @0x1fd92c ldr r2, [r4, r2] —— r2=GOT[0x3f0fdc] | ->0x1fccd8 */
/* @0x1fd930 add r0, pc, r0 —— r0=0x352e28 [pc+0x1554f0] | STR "background_vspeed" */
/* @0x1fd934 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd938 ldr r1, [pc, #0x96c] —— r1=0xfffff388 (pool 0x1fe2ac) */
/* @0x1fd93c ldr r2, [pc, #0x96c] —— r2=0xfffff38c (pool 0x1fe2b0) */
/* @0x1fd940 mov r3, #1 */
/* @0x1fd944 ldr r0, [pc, #0x968] —— r0=0x1554e4 (pool 0x1fe2b4) */
/* @0x1fd948 ldr r1, [r4, r1] —— r1=GOT[0x3f0fe0] | ->0x1f808c */
/* @0x1fd94c ldr r2, [r4, r2] —— r2=GOT[0x3f0fe4] | ->0x1fcd30 */
/* @0x1fd950 add r0, pc, r0 —— r0=0x352e3c [pc+0x1554e4] | STR "background_blend" */
/* @0x1fd954 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd958 ldr r1, [pc, #0x958] —— r1=0xfffff390 (pool 0x1fe2b8) */
/* @0x1fd95c ldr r2, [pc, #0x958] —— r2=0xfffff394 (pool 0x1fe2bc) */
/* @0x1fd960 mov r3, #1 */
/* @0x1fd964 ldr r0, [pc, #0x954] —— r0=0x1554d8 (pool 0x1fe2c0) */
/* @0x1fd968 ldr r1, [r4, r1] —— r1=GOT[0x3f0fe8] | ->0x1f80e0 */
/* @0x1fd96c ldr r2, [r4, r2] —— r2=GOT[0x3f0fec] | ->0x1fcdcc */
/* @0x1fd970 add r0, pc, r0 —— r0=0x352e50 [pc+0x1554d8] | STR "background_alpha" */
/* @0x1fd974 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd978 ldr r1, [pc, #0x944] —— r1=0xfffff398 (pool 0x1fe2c4) */
/* @0x1fd97c ldr r2, [pc, #0x944] —— r2=0xfffff39c (pool 0x1fe2c8) */
/* @0x1fd980 mov r3, #1 */
/* @0x1fd984 ldr r0, [pc, #0x940] —— r0=0x1554cc (pool 0x1fe2cc) */
/* @0x1fd988 ldr r1, [r4, r1] —— r1=GOT[0x3f0ff0] | ->0x1f8130 */
/* @0x1fd98c ldr r2, [r4, r2] —— r2=GOT[0x3f0ff4] | ->0x1fd0dc */
/* @0x1fd990 add r0, pc, r0 —— r0=0x352e64 [pc+0x1554cc] | STR "view_enabled" */

/* ── ④ view 族 19 条（0x1fd994..0x1fdbd0）─────────────────────────
 *   enabled、current（只读）、visible、xview/yview/wview/hview、xport/yport/wport/hport、angle、
 *   hborder/vborder、hspeed/vspeed、object、surface_id、camera。全部 18 个 view 变量 + view_current。
 */
/* @0x1fd994 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd998 ldr r1, [pc, #0x930] —— r1=0xfffff3a0 (pool 0x1fe2d0) */
/* @0x1fd99c ldr r0, [pc, #0x930] —— r0=0x1554c0 (pool 0x1fe2d4) */
/* @0x1fd9a0 mov r2, #0 */
/* @0x1fd9a4 mov r3, r2 */
/* @0x1fd9a8 ldr r1, [r4, r1] —— r1=GOT[0x3f0ff8] | ->0x1f8174 */
/* @0x1fd9ac add r0, pc, r0 —— r0=0x352e74 [pc+0x1554c0] | STR "view_current" */
/* @0x1fd9b0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd9b4 ldr r1, [pc, #0x91c] —— r1=0xfffff3a4 (pool 0x1fe2d8) */
/* @0x1fd9b8 ldr r2, [pc, #0x91c] —— r2=0xfffff3a8 (pool 0x1fe2dc) */
/* @0x1fd9bc mov r3, #1 */
/* @0x1fd9c0 ldr r0, [pc, #0x918] —— r0=0x1554b0 (pool 0x1fe2e0) */
/* @0x1fd9c4 ldr r1, [r4, r1] —— r1=GOT[0x3f0ffc] | ->0x1f81b4 */
/* @0x1fd9c8 ldr r2, [r4, r2] —— r2=GOT[0x3f1000] | ->0x1fc1f4 */
/* @0x1fd9cc add r0, pc, r0 —— r0=0x352e84 [pc+0x1554b0] | STR "view_visible" */
/* @0x1fd9d0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd9d4 ldr r1, [pc, #0x908] —— r1=0xfffff3ac (pool 0x1fe2e4) */
/* @0x1fd9d8 ldr r2, [pc, #0x908] —— r2=0xfffff3b0 (pool 0x1fe2e8) */
/* @0x1fd9dc mov r3, #1 */
/* @0x1fd9e0 ldr r0, [pc, #0x904] —— r0=0x1554a0 (pool 0x1fe2ec) */
/* @0x1fd9e4 ldr r1, [r4, r1] —— r1=GOT[0x3f1004] | ->0x1f8208 */
/* @0x1fd9e8 ldr r2, [r4, r2] —— r2=GOT[0x3f1008] | ->0x1fc278 */
/* @0x1fd9ec add r0, pc, r0 —— r0=0x352e94 [pc+0x1554a0] | STR "view_xview" */
/* @0x1fd9f0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fd9f4 ldr r1, [pc, #0x8f4] —— r1=0xfffff3b4 (pool 0x1fe2f0) */
/* @0x1fd9f8 ldr r2, [pc, #0x8f4] —— r2=0xfffff3b8 (pool 0x1fe2f4) */
/* @0x1fd9fc mov r3, #1 */
/* @0x1fda00 ldr r0, [pc, #0x8f0] —— r0=0x15548c (pool 0x1fe2f8) */
/* @0x1fda04 ldr r1, [r4, r1] —— r1=GOT[0x3f100c] | ->0x1f8258 */
/* @0x1fda08 ldr r2, [r4, r2] —— r2=GOT[0x3f1010] | ->0x1fc2d0 */
/* @0x1fda0c add r0, pc, r0 —— r0=0x352ea0 [pc+0x15548c] | STR "view_yview" */
/* @0x1fda10 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fda14 ldr r1, [pc, #0x8e0] —— r1=0xfffff3bc (pool 0x1fe2fc) */
/* @0x1fda18 ldr r2, [pc, #0x8e0] —— r2=0xfffff3c0 (pool 0x1fe300) */
/* @0x1fda1c mov r3, #1 */
/* @0x1fda20 ldr r0, [pc, #0x8dc] —— r0=0x155478 (pool 0x1fe304) */
/* @0x1fda24 ldr r1, [r4, r1] —— r1=GOT[0x3f1014] | ->0x1f82a8 */
/* @0x1fda28 ldr r2, [r4, r2] —— r2=GOT[0x3f1018] | ->0x1fc328 */
/* @0x1fda2c add r0, pc, r0 —— r0=0x352eac [pc+0x155478] | STR "view_wview" */
/* @0x1fda30 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fda34 ldr r1, [pc, #0x8cc] —— r1=0xfffff3c4 (pool 0x1fe308) */
/* @0x1fda38 ldr r2, [pc, #0x8cc] —— r2=0xfffff3c8 (pool 0x1fe30c) */
/* @0x1fda3c mov r3, #1 */
/* @0x1fda40 ldr r0, [pc, #0x8c8] —— r0=0x155464 (pool 0x1fe310) */
/* @0x1fda44 ldr r1, [r4, r1] —— r1=GOT[0x3f101c] | ->0x1f82f8 */
/* @0x1fda48 ldr r2, [r4, r2] —— r2=GOT[0x3f1020] | ->0x1fc380 */
/* @0x1fda4c add r0, pc, r0 —— r0=0x352eb8 [pc+0x155464] | STR "view_hview" */
/* @0x1fda50 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fda54 ldr r1, [pc, #0x8b8] —— r1=0xfffff3cc (pool 0x1fe314) */
/* @0x1fda58 ldr r2, [pc, #0x8b8] —— r2=0xfffff3d0 (pool 0x1fe318) */
/* @0x1fda5c mov r3, #1 */
/* @0x1fda60 ldr r0, [pc, #0x8b4] —— r0=0x155450 (pool 0x1fe31c) */
/* @0x1fda64 ldr r1, [r4, r1] —— r1=GOT[0x3f1024] | ->0x1f8348 */
/* @0x1fda68 ldr r2, [r4, r2] —— r2=GOT[0x3f1028] | ->0x1fc3d8 */
/* @0x1fda6c add r0, pc, r0 —— r0=0x352ec4 [pc+0x155450] | STR "view_xport" */
/* @0x1fda70 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fda74 ldr r1, [pc, #0x8a4] —— r1=0xfffff3d4 (pool 0x1fe320) */
/* @0x1fda78 ldr r2, [pc, #0x8a4] —— r2=0xfffff3d8 (pool 0x1fe324) */
/* @0x1fda7c mov r3, #1 */
/* @0x1fda80 ldr r0, [pc, #0x8a0] —— r0=0x15543c (pool 0x1fe328) */
/* @0x1fda84 ldr r1, [r4, r1] —— r1=GOT[0x3f102c] | ->0x1f839c */
/* @0x1fda88 ldr r2, [r4, r2] —— r2=GOT[0x3f1030] | ->0x1fc440 */
/* @0x1fda8c add r0, pc, r0 —— r0=0x352ed0 [pc+0x15543c] | STR "view_yport" */
/* @0x1fda90 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fda94 ldr r1, [pc, #0x890] —— r1=0xfffff3dc (pool 0x1fe32c) */
/* @0x1fda98 ldr r2, [pc, #0x890] —— r2=0xfffff3e0 (pool 0x1fe330) */
/* @0x1fda9c mov r3, #1 */
/* @0x1fdaa0 ldr r0, [pc, #0x88c] —— r0=0x155428 (pool 0x1fe334) */
/* @0x1fdaa4 ldr r1, [r4, r1] —— r1=GOT[0x3f1034] | ->0x1f83f0 */
/* @0x1fdaa8 ldr r2, [r4, r2] —— r2=GOT[0x3f1038] | ->0x1fc4a8 */
/* @0x1fdaac add r0, pc, r0 —— r0=0x352edc [pc+0x155428] | STR "view_wport" */
/* @0x1fdab0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdab4 ldr r1, [pc, #0x87c] —— r1=0xfffff3e4 (pool 0x1fe338) */
/* @0x1fdab8 ldr r2, [pc, #0x87c] —— r2=0xfffff3e8 (pool 0x1fe33c) */
/* @0x1fdabc mov r3, #1 */
/* @0x1fdac0 ldr r0, [pc, #0x878] —— r0=0x155414 (pool 0x1fe340) */
/* @0x1fdac4 ldr r1, [r4, r1] —— r1=GOT[0x3f103c] | ->0x1f8444 */
/* @0x1fdac8 ldr r2, [r4, r2] —— r2=GOT[0x3f1040] | ->0x1fc510 */
/* @0x1fdacc add r0, pc, r0 —— r0=0x352ee8 [pc+0x155414] | STR "view_hport" */
/* @0x1fdad0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdad4 ldr r1, [pc, #0x868] —— r1=0xfffff3ec (pool 0x1fe344) */
/* @0x1fdad8 ldr r2, [pc, #0x868] —— r2=0xfffff3f0 (pool 0x1fe348) */
/* @0x1fdadc mov r3, #1 */
/* @0x1fdae0 ldr r0, [pc, #0x864] —— r0=0x155400 (pool 0x1fe34c) */
/* @0x1fdae4 ldr r1, [r4, r1] —— r1=GOT[0x3f1044] | ->0x1f8498 */
/* @0x1fdae8 ldr r2, [r4, r2] —— r2=GOT[0x3f1048] | ->0x1fc578 */
/* @0x1fdaec add r0, pc, r0 —— r0=0x352ef4 [pc+0x155400] | STR "view_angle" */
/* @0x1fdaf0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdaf4 ldr r1, [pc, #0x854] —— r1=0xfffff3f4 (pool 0x1fe350) */
/* @0x1fdaf8 ldr r2, [pc, #0x854] —— r2=0xfffff3f8 (pool 0x1fe354) */
/* @0x1fdafc mov r3, #1 */
/* @0x1fdb00 ldr r0, [pc, #0x850] —— r0=0x1553ec (pool 0x1fe358) */
/* @0x1fdb04 ldr r1, [r4, r1] —— r1=GOT[0x3f104c] | ->0x1f84e8 */
/* @0x1fdb08 ldr r2, [r4, r2] —— r2=GOT[0x3f1050] | ->0x1fc5d0 */
/* @0x1fdb0c add r0, pc, r0 —— r0=0x352f00 [pc+0x1553ec] | STR "view_hborder" */
/* @0x1fdb10 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdb14 ldr r1, [pc, #0x840] —— r1=0xfffff3fc (pool 0x1fe35c) */
/* @0x1fdb18 ldr r2, [pc, #0x840] —— r2=0xfffff400 (pool 0x1fe360) */
/* @0x1fdb1c mov r3, #1 */
/* @0x1fdb20 ldr r0, [pc, #0x83c] —— r0=0x1553dc (pool 0x1fe364) */
/* @0x1fdb24 ldr r1, [r4, r1] —— r1=GOT[0x3f1054] | ->0x1f853c */
/* @0x1fdb28 ldr r2, [r4, r2] —— r2=GOT[0x3f1058] | ->0x1fc638 */
/* @0x1fdb2c add r0, pc, r0 —— r0=0x352f10 [pc+0x1553dc] | STR "view_vborder" */
/* @0x1fdb30 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdb34 ldr r1, [pc, #0x82c] —— r1=0xfffff404 (pool 0x1fe368) */
/* @0x1fdb38 ldr r2, [pc, #0x82c] —— r2=0xfffff408 (pool 0x1fe36c) */
/* @0x1fdb3c mov r3, #1 */
/* @0x1fdb40 ldr r0, [pc, #0x828] —— r0=0x1553cc (pool 0x1fe370) */
/* @0x1fdb44 ldr r1, [r4, r1] —— r1=GOT[0x3f105c] | ->0x1f8590 */
/* @0x1fdb48 ldr r2, [r4, r2] —— r2=GOT[0x3f1060] | ->0x1fc6a0 */
/* @0x1fdb4c add r0, pc, r0 —— r0=0x352f20 [pc+0x1553cc] | STR "view_hspeed" */
/* @0x1fdb50 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdb54 ldr r1, [pc, #0x818] —— r1=0xfffff40c (pool 0x1fe374) */
/* @0x1fdb58 ldr r2, [pc, #0x818] —— r2=0xfffff410 (pool 0x1fe378) */
/* @0x1fdb5c mov r3, #1 */
/* @0x1fdb60 ldr r0, [pc, #0x814] —— r0=0x1553b8 (pool 0x1fe37c) */
/* @0x1fdb64 ldr r1, [r4, r1] —— r1=GOT[0x3f1064] | ->0x1f85e4 */
/* @0x1fdb68 ldr r2, [r4, r2] —— r2=GOT[0x3f1068] | ->0x1fc708 */
/* @0x1fdb6c add r0, pc, r0 —— r0=0x352f2c [pc+0x1553b8] | STR "view_vspeed" */
/* @0x1fdb70 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdb74 ldr r1, [pc, #0x804] —— r1=0xfffff414 (pool 0x1fe380) */
/* @0x1fdb78 ldr r2, [pc, #0x804] —— r2=0xfffff418 (pool 0x1fe384) */
/* @0x1fdb7c mov r3, #1 */
/* @0x1fdb80 ldr r0, [pc, #0x800] —— r0=0x1553a4 (pool 0x1fe388) */
/* @0x1fdb84 ldr r1, [r4, r1] —— r1=GOT[0x3f106c] | ->0x1f8638 */
/* @0x1fdb88 ldr r2, [r4, r2] —— r2=GOT[0x3f1070] | ->0x1fc770 */
/* @0x1fdb8c add r0, pc, r0 —— r0=0x352f38 [pc+0x1553a4] | STR "view_object" */
/* @0x1fdb90 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdb94 ldr r1, [pc, #0x7f0] —— r1=0xfffff41c (pool 0x1fe38c) */
/* @0x1fdb98 ldr r2, [pc, #0x7f0] —— r2=0xfffff420 (pool 0x1fe390) */
/* @0x1fdb9c mov r3, #1 */
/* @0x1fdba0 ldr r0, [pc, #0x7ec] —— r0=0x155390 (pool 0x1fe394) */
/* @0x1fdba4 ldr r1, [r4, r1] —— r1=GOT[0x3f1074] | ->0x1f8b18 */
/* @0x1fdba8 ldr r2, [r4, r2] —— r2=GOT[0x3f1078] | ->0x1fc7d8 */
/* @0x1fdbac add r0, pc, r0 —— r0=0x352f44 [pc+0x155390] | STR "view_surface_id" */
/* @0x1fdbb0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdbb4 ldr r1, [pc, #0x7dc] —— r1=0xfffff424 (pool 0x1fe398) */
/* @0x1fdbb8 ldr r2, [pc, #0x7dc] —— r2=0xfffff428 (pool 0x1fe39c) */
/* @0x1fdbbc mov r3, #1 */
/* @0x1fdbc0 ldr r0, [pc, #0x7d8] —— r0=0x155380 (pool 0x1fe3a0) */
/* @0x1fdbc4 ldr r1, [r4, r1] —— r1=GOT[0x3f107c] | ->0x1f8b6c */
/* @0x1fdbc8 ldr r2, [r4, r2] —— r2=GOT[0x3f1080] | ->0x1fc840 */
/* @0x1fdbcc add r0, pc, r0 —— r0=0x352f54 [pc+0x155380] | STR "view_camera" */
/* @0x1fdbd0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdbd4 ldr r1, [pc, #0x7c8] —— r1=0xfffff42c (pool 0x1fe3a4) */
/* @0x1fdbd8 ldr r0, [pc, #0x7c8] —— r0=0x155370 (pool 0x1fe3a8) */
/* @0x1fdbdc mov r2, #0 */
/* @0x1fdbe0 mov r3, r2 */
/* @0x1fdbe4 ldr r1, [r4, r1] —— r1=GOT[0x3f1084] | ->0x1fa010 */
/* @0x1fdbe8 add r0, pc, r0 —— r0=0x352f60 [pc+0x155370] | STR "mouse_x" */

/* ── ⑤ 鼠标 / 键盘 / 计分板 / 时间（0x1fdbec..0x1fdec0）─────────────
 *   mouse_x/mouse_y（只读，GV_MouseX/GV_MouseY）、mouse_button、mouse_lastbutton、
 *   keyboard_key/lastkey/lastchar/string、cursor_sprite、
 *   show_score/show_lives/show_health、caption_score/lives/health、fps、fps_real、
 *   current_time/year/month/day/weekday/hour/minute/second（8 条只读，getter 全是 GV_Current*）。
 */
/* @0x1fdbec bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdbf0 ldr r1, [pc, #0x7b4] —— r1=0xfffff430 (pool 0x1fe3ac) */
/* @0x1fdbf4 ldr r0, [pc, #0x7b4] —— r0=0x15535c (pool 0x1fe3b0) */
/* @0x1fdbf8 mov r2, #0 */
/* @0x1fdbfc mov r3, r2 */
/* @0x1fdc00 ldr r1, [r4, r1] —— r1=GOT[0x3f1088] | ->0x1fa048 */
/* @0x1fdc04 add r0, pc, r0 —— r0=0x352f68 [pc+0x15535c] | STR "mouse_y" */
/* @0x1fdc08 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdc0c ldr r1, [pc, #0x7a0] —— r1=0xfffff434 (pool 0x1fe3b4) */
/* @0x1fdc10 ldr r2, [pc, #0x7a0] —— r2=0xfffff438 (pool 0x1fe3b8) */
/* @0x1fdc14 mov r3, #1 */
/* @0x1fdc18 ldr r0, [pc, #0x79c] —— r0=0x155344 (pool 0x1fe3bc) */
/* @0x1fdc1c ldr r1, [r4, r1] —— r1=GOT[0x3f108c] | ->0x1fa080 */
/* @0x1fdc20 ldr r2, [r4, r2] —— r2=GOT[0x3f1090] | ->0x1fb404 */
/* @0x1fdc24 add r0, pc, r0 —— r0=0x352f70 [pc+0x155344] | STR "mouse_button" */
/* @0x1fdc28 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdc2c ldr r1, [pc, #0x78c] —— r1=0xfffff43c (pool 0x1fe3c0) */
/* @0x1fdc30 ldr r2, [pc, #0x78c] —— r2=0xfffff440 (pool 0x1fe3c4) */
/* @0x1fdc34 mov r3, #1 */
/* @0x1fdc38 ldr r0, [pc, #0x788] —— r0=0x155334 (pool 0x1fe3c8) */
/* @0x1fdc3c ldr r1, [r4, r1] —— r1=GOT[0x3f1094] | ->0x1fa0b8 */
/* @0x1fdc40 ldr r2, [r4, r2] —— r2=GOT[0x3f1098] | ->0x1fb3b8 */
/* @0x1fdc44 add r0, pc, r0 —— r0=0x352f80 [pc+0x155334] | STR "mouse_lastbutton" */
/* @0x1fdc48 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdc4c ldr r1, [pc, #0x778] —— r1=0xfffff444 (pool 0x1fe3cc) */
/* @0x1fdc50 ldr r2, [pc, #0x778] —— r2=0xfffff448 (pool 0x1fe3d0) */
/* @0x1fdc54 mov r3, #1 */
/* @0x1fdc58 ldr r0, [pc, #0x774] —— r0=0x155328 (pool 0x1fe3d4) */
/* @0x1fdc5c ldr r1, [r4, r1] —— r1=GOT[0x3f109c] | ->0x1fa0f0 */
/* @0x1fdc60 ldr r2, [r4, r2] —— r2=GOT[0x3f10a0] | ->0x1fb498 */
/* @0x1fdc64 add r0, pc, r0 —— r0=0x352f94 [pc+0x155328] | STR "keyboard_key" */
/* @0x1fdc68 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdc6c ldr r1, [pc, #0x764] —— r1=0xfffff44c (pool 0x1fe3d8) */
/* @0x1fdc70 ldr r2, [pc, #0x764] —— r2=0xfffff450 (pool 0x1fe3dc) */
/* @0x1fdc74 mov r3, #1 */
/* @0x1fdc78 ldr r0, [pc, #0x760] —— r0=0x155318 (pool 0x1fe3e0) */
/* @0x1fdc7c ldr r1, [r4, r1] —— r1=GOT[0x3f10a4] | ->0x1fa124 */
/* @0x1fdc80 ldr r2, [r4, r2] —— r2=GOT[0x3f10a8] | ->0x1fb450 */
/* @0x1fdc84 add r0, pc, r0 —— r0=0x352fa4 [pc+0x155318] | STR "keyboard_lastkey" */
/* @0x1fdc88 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdc8c ldr r1, [pc, #0x750] —— r1=0xfffff454 (pool 0x1fe3e4) */
/* @0x1fdc90 ldr r2, [pc, #0x750] —— r2=0xfffff458 (pool 0x1fe3e8) */
/* @0x1fdc94 mov r3, #1 */
/* @0x1fdc98 ldr r0, [pc, #0x74c] —— r0=0x15530c (pool 0x1fe3ec) */
/* @0x1fdc9c ldr r1, [r4, r1] —— r1=GOT[0x3f10ac] | ->0x1fa158 */
/* @0x1fdca0 ldr r2, [r4, r2] —— r2=GOT[0x3f10b0] | ->0x1fa7fc */
/* @0x1fdca4 add r0, pc, r0 —— r0=0x352fb8 [pc+0x15530c] | STR "keyboard_lastchar" */
/* @0x1fdca8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdcac ldr r1, [pc, #0x73c] —— r1=0xfffff45c (pool 0x1fe3f0) */
/* @0x1fdcb0 ldr r2, [pc, #0x73c] —— r2=0xfffff460 (pool 0x1fe3f4) */
/* @0x1fdcb4 mov r3, #1 */
/* @0x1fdcb8 ldr r0, [pc, #0x738] —— r0=0x155300 (pool 0x1fe3f8) */
/* @0x1fdcbc ldr r1, [r4, r1] —— r1=GOT[0x3f10b4] | ->0x1fa1a4 */
/* @0x1fdcc0 ldr r2, [r4, r2] —— r2=GOT[0x3f10b8] | ->0x1fa840 */
/* @0x1fdcc4 add r0, pc, r0 —— r0=0x352fcc [pc+0x155300] | STR "keyboard_string" */
/* @0x1fdcc8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdccc ldr r1, [pc, #0x728] —— r1=0xfffff464 (pool 0x1fe3fc) */
/* @0x1fdcd0 ldr r2, [pc, #0x728] —— r2=0xfffff468 (pool 0x1fe400) */
/* @0x1fdcd4 mov r3, #1 */
/* @0x1fdcd8 ldr r0, [pc, #0x724] —— r0=0x1552f0 (pool 0x1fe404) */
/* @0x1fdcdc ldr r1, [r4, r1] —— r1=GOT[0x3f10bc] | ->0x1f874c */
/* @0x1fdce0 ldr r2, [r4, r2] —— r2=GOT[0x3f10c0] | ->0x1fb644 */
/* @0x1fdce4 add r0, pc, r0 —— r0=0x352fdc [pc+0x1552f0] | STR "cursor_sprite" */
/* @0x1fdce8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdcec ldr r1, [pc, #0x714] —— r1=0xfffff46c (pool 0x1fe408) */
/* @0x1fdcf0 ldr r2, [pc, #0x714] —— r2=0xfffff470 (pool 0x1fe40c) */
/* @0x1fdcf4 mov r3, #1 */
/* @0x1fdcf8 ldr r0, [pc, #0x710] —— r0=0x1552e0 (pool 0x1fe410) */
/* @0x1fdcfc ldr r1, [r4, r1] —— r1=GOT[0x3f10c4] | ->0x1f868c */
/* @0x1fdd00 ldr r2, [r4, r2] —— r2=GOT[0x3f10c8] | ->0x1fb4e0 */
/* @0x1fdd04 add r0, pc, r0 —— r0=0x352fec [pc+0x1552e0] | STR "show_score" */
/* @0x1fdd08 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdd0c ldr r1, [pc, #0x700] —— r1=0xfffff474 (pool 0x1fe414) */
/* @0x1fdd10 ldr r2, [pc, #0x700] —— r2=0xfffff478 (pool 0x1fe418) */
/* @0x1fdd14 mov r3, #1 */
/* @0x1fdd18 ldr r0, [pc, #0x6fc] —— r0=0x1552cc (pool 0x1fe41c) */
/* @0x1fdd1c ldr r1, [r4, r1] —— r1=GOT[0x3f10cc] | ->0x1f86cc */
/* @0x1fdd20 ldr r2, [r4, r2] —— r2=GOT[0x3f10d0] | ->0x1fb564 */
/* @0x1fdd24 add r0, pc, r0 —— r0=0x352ff8 [pc+0x1552cc] | STR "show_lives" */
/* @0x1fdd28 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdd2c ldr r1, [pc, #0x6ec] —— r1=0xfffff47c (pool 0x1fe420) */
/* @0x1fdd30 ldr r2, [pc, #0x6ec] —— r2=0xfffff480 (pool 0x1fe424) */
/* @0x1fdd34 mov r3, #1 */
/* @0x1fdd38 ldr r0, [pc, #0x6e8] —— r0=0x1552b8 (pool 0x1fe428) */
/* @0x1fdd3c ldr r1, [r4, r1] —— r1=GOT[0x3f10d4] | ->0x1f870c */
/* @0x1fdd40 ldr r2, [r4, r2] —— r2=GOT[0x3f10d8] | ->0x1fb5d4 */
/* @0x1fdd44 add r0, pc, r0 —— r0=0x353004 [pc+0x1552b8] | STR "show_health" */
/* @0x1fdd48 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdd4c ldr r1, [pc, #0x6d8] —— r1=0xfffff484 (pool 0x1fe42c) */
/* @0x1fdd50 ldr r2, [pc, #0x6d8] —— r2=0xfffff488 (pool 0x1fe430) */
/* @0x1fdd54 mov r3, #1 */
/* @0x1fdd58 ldr r0, [pc, #0x6d4] —— r0=0x1552a4 (pool 0x1fe434) */
/* @0x1fdd5c ldr r1, [r4, r1] —— r1=GOT[0x3f10dc] | ->0x1fa1c4 */
/* @0x1fdd60 ldr r2, [r4, r2] —— r2=GOT[0x3f10e0] | ->0x1f8850 */
/* @0x1fdd64 add r0, pc, r0 —— r0=0x353010 [pc+0x1552a4] | STR "caption_score" */
/* @0x1fdd68 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdd6c ldr r1, [pc, #0x6c4] —— r1=0xfffff48c (pool 0x1fe438) */
/* @0x1fdd70 ldr r2, [pc, #0x6c4] —— r2=0xfffff490 (pool 0x1fe43c) */
/* @0x1fdd74 mov r3, #1 */
/* @0x1fdd78 ldr r0, [pc, #0x6c0] —— r0=0x155294 (pool 0x1fe440) */
/* @0x1fdd7c ldr r1, [r4, r1] —— r1=GOT[0x3f10e4] | ->0x1fa1e8 */
/* @0x1fdd80 ldr r2, [r4, r2] —— r2=GOT[0x3f10e8] | ->0x1f887c */
/* @0x1fdd84 add r0, pc, r0 —— r0=0x353020 [pc+0x155294] | STR "caption_lives" */
/* @0x1fdd88 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdd8c ldr r1, [pc, #0x6b0] —— r1=0xfffff494 (pool 0x1fe444) */
/* @0x1fdd90 ldr r2, [pc, #0x6b0] —— r2=0xfffff498 (pool 0x1fe448) */
/* @0x1fdd94 mov r3, #1 */
/* @0x1fdd98 ldr r0, [pc, #0x6ac] —— r0=0x155284 (pool 0x1fe44c) */
/* @0x1fdd9c ldr r1, [r4, r1] —— r1=GOT[0x3f10ec] | ->0x1fa20c */
/* @0x1fdda0 ldr r2, [r4, r2] —— r2=GOT[0x3f10f0] | ->0x1f88a8 */
/* @0x1fdda4 add r0, pc, r0 —— r0=0x353030 [pc+0x155284] | STR "caption_health" */
/* @0x1fdda8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fddac ldr r1, [pc, #0x69c] —— r1=0xfffff49c (pool 0x1fe450) */
/* @0x1fddb0 ldr r0, [pc, #0x69c] —— r0=0x155278 (pool 0x1fe454) */
/* @0x1fddb4 mov r2, #0 */
/* @0x1fddb8 mov r3, r2 */
/* @0x1fddbc ldr r1, [r4, r1] —— r1=GOT[0x3f10f4] | ->0x1f87cc */
/* @0x1fddc0 add r0, pc, r0 —— r0=0x353040 [pc+0x155278] | STR "fps" */
/* @0x1fddc4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fddc8 ldr r1, [pc, #0x688] —— r1=0xfffff4a0 (pool 0x1fe458) */
/* @0x1fddcc ldr r0, [pc, #0x688] —— r0=0x155260 (pool 0x1fe45c) */
/* @0x1fddd0 mov r2, #0 */
/* @0x1fddd4 mov r3, r2 */
/* @0x1fddd8 ldr r1, [r4, r1] —— r1=GOT[0x3f10f8] | ->0x1f880c */
/* @0x1fdddc add r0, pc, r0 —— r0=0x353044 [pc+0x155260] | STR "fps_real" */
/* @0x1fdde0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdde4 ldr r1, [pc, #0x674] —— r1=0xfffff4a4 (pool 0x1fe460) */
/* @0x1fdde8 ldr r0, [pc, #0x674] —— r0=0x155250 (pool 0x1fe464) */
/* @0x1fddec mov r2, #0 */
/* @0x1fddf0 mov r3, r2 */
/* @0x1fddf4 ldr r1, [r4, r1] —— r1=GOT[0x3f10fc] | ->0x1fa27c */
/* @0x1fddf8 add r0, pc, r0 —— r0=0x353050 [pc+0x155250] | STR "current_time" */
/* @0x1fddfc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fde00 ldr r1, [pc, #0x660] —— r1=0xfffff4a8 (pool 0x1fe468) */
/* @0x1fde04 ldr r0, [pc, #0x660] —— r0=0x155244 (pool 0x1fe46c) */
/* @0x1fde08 mov r2, #0 */
/* @0x1fde0c mov r3, r2 */
/* @0x1fde10 ldr r1, [r4, r1] —— r1=GOT[0x3f1100] | ->0x1fa2b0 */
/* @0x1fde14 add r0, pc, r0 —— r0=0x353060 [pc+0x155244] | STR "current_year" */
/* @0x1fde18 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fde1c ldr r1, [pc, #0x64c] —— r1=0xfffff4ac (pool 0x1fe470) */
/* @0x1fde20 ldr r0, [pc, #0x64c] —— r0=0x155238 (pool 0x1fe474) */
/* @0x1fde24 mov r2, #0 */
/* @0x1fde28 mov r3, r2 */
/* @0x1fde2c ldr r1, [r4, r1] —— r1=GOT[0x3f1104] | ->0x1fa2f0 */
/* @0x1fde30 add r0, pc, r0 —— r0=0x353070 [pc+0x155238] | STR "current_month" */
/* @0x1fde34 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fde38 ldr r1, [pc, #0x638] —— r1=0xfffff4b0 (pool 0x1fe478) */
/* @0x1fde3c ldr r0, [pc, #0x638] —— r0=0x15522c (pool 0x1fe47c) */
/* @0x1fde40 mov r2, #0 */
/* @0x1fde44 mov r3, r2 */
/* @0x1fde48 ldr r1, [r4, r1] —— r1=GOT[0x3f1108] | ->0x1fa32c */
/* @0x1fde4c add r0, pc, r0 —— r0=0x353080 [pc+0x15522c] | STR "current_day" */
/* @0x1fde50 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fde54 ldr r1, [pc, #0x624] —— r1=0xfffff4b4 (pool 0x1fe480) */
/* @0x1fde58 ldr r0, [pc, #0x624] —— r0=0x15521c (pool 0x1fe484) */
/* @0x1fde5c mov r2, #0 */
/* @0x1fde60 mov r3, r2 */
/* @0x1fde64 ldr r1, [r4, r1] —— r1=GOT[0x3f110c] | ->0x1fa364 */
/* @0x1fde68 add r0, pc, r0 —— r0=0x35308c [pc+0x15521c] | STR "current_weekday" */
/* @0x1fde6c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fde70 ldr r1, [pc, #0x610] —— r1=0xfffff4b8 (pool 0x1fe488) */
/* @0x1fde74 ldr r0, [pc, #0x610] —— r0=0x155210 (pool 0x1fe48c) */
/* @0x1fde78 mov r2, #0 */
/* @0x1fde7c mov r3, r2 */
/* @0x1fde80 ldr r1, [r4, r1] —— r1=GOT[0x3f1110] | ->0x1fa39c */
/* @0x1fde84 add r0, pc, r0 —— r0=0x35309c [pc+0x155210] | STR "current_hour" */
/* @0x1fde88 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fde8c ldr r1, [pc, #0x5fc] —— r1=0xfffff4bc (pool 0x1fe490) */
/* @0x1fde90 ldr r0, [pc, #0x5fc] —— r0=0x155204 (pool 0x1fe494) */
/* @0x1fde94 mov r2, #0 */
/* @0x1fde98 mov r3, r2 */
/* @0x1fde9c ldr r1, [r4, r1] —— r1=GOT[0x3f1114] | ->0x1fa3d4 */
/* @0x1fdea0 add r0, pc, r0 —— r0=0x3530ac [pc+0x155204] | STR "current_minute" */
/* @0x1fdea4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdea8 ldr r1, [pc, #0x5e8] —— r1=0xfffff4c0 (pool 0x1fe498) */
/* @0x1fdeac ldr r0, [pc, #0x5e8] —— r0=0x1551f8 (pool 0x1fe49c) */
/* @0x1fdeb0 mov r2, #0 */
/* @0x1fdeb4 mov r3, r2 */
/* @0x1fdeb8 ldr r1, [r4, r1] —— r1=GOT[0x3f1118] | ->0x1fa40c */
/* @0x1fdebc add r0, pc, r0 —— r0=0x3530bc [pc+0x1551f8] | STR "current_second" */
/* @0x1fdec0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdec4 ldr r1, [pc, #0x5d4] —— r1=0xfffff4c4 (pool 0x1fe4a0) */
/* @0x1fdec8 ldr r0, [pc, #0x5d4] —— r0=0x14e4ac (pool 0x1fe4a4) */
/* @0x1fdecc mov r2, #0 */
/* @0x1fded0 mov r3, r2 */
/* @0x1fded4 ldr r1, [r4, r1] —— r1=GOT[0x3f111c] | ->0x1f88d4 */
/* @0x1fded8 add r0, pc, r0 —— r0=0x34c38c [pc+0x14e4ac] | STR "event_type" */

/* ── ⑥ 事件 / 安全 / 错误 / 杂项（0x1fdedc..0x1fe008）───────────────
 *   event_type/number/object/action（4 条只读）、secure_mode、error_occurred、error_last、
 *   gamemaker_registered / gamemaker_pro（两条共用 getter GV_GamemakerRegistered 0x1f8a98）、
 *   application_surface、font_texture_page_size（有 setter）。
 *   0x1fe004 `pop {r4,r5,r6,r7,r8,lr}` + 0x1fe008 `b 0x15dafc <InitYoYoBuiltInVariables>` ——
 *   本函数不返回，尾跳由后者补 5 条只读变量（os_type/os_device/os_version/os_browser/browser_width）。
 */
/* @0x1fdedc bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdee0 ldr r1, [pc, #0x5c0] —— r1=0xfffff4c8 (pool 0x1fe4a8) */
/* @0x1fdee4 ldr r0, [pc, #0x5c0] —— r0=0x1551d0 (pool 0x1fe4ac) */
/* @0x1fdee8 mov r2, #0 */
/* @0x1fdeec mov r3, r2 */
/* @0x1fdef0 ldr r1, [r4, r1] —— r1=GOT[0x3f1120] | ->0x1f8914 */
/* @0x1fdef4 add r0, pc, r0 —— r0=0x3530cc [pc+0x1551d0] | STR "event_number" */
/* @0x1fdef8 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdefc ldr r1, [pc, #0x5ac] —— r1=0xfffff4cc (pool 0x1fe4b0) */
/* @0x1fdf00 ldr r0, [pc, #0x5ac] —— r0=0x1551c4 (pool 0x1fe4b4) */
/* @0x1fdf04 mov r2, #0 */
/* @0x1fdf08 mov r3, r2 */
/* @0x1fdf0c ldr r1, [r4, r1] —— r1=GOT[0x3f1124] | ->0x1f8954 */
/* @0x1fdf10 add r0, pc, r0 —— r0=0x3530dc [pc+0x1551c4] | STR "event_object" */
/* @0x1fdf14 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdf18 ldr r1, [pc, #0x598] —— r1=0xfffff4d0 (pool 0x1fe4b8) */
/* @0x1fdf1c ldr r0, [pc, #0x598] —— r0=0x1551b8 (pool 0x1fe4bc) */
/* @0x1fdf20 mov r2, #0 */
/* @0x1fdf24 mov r3, r2 */
/* @0x1fdf28 ldr r1, [r4, r1] —— r1=GOT[0x3f1128] | ->0x1f8994 */
/* @0x1fdf2c add r0, pc, r0 —— r0=0x3530ec [pc+0x1551b8] | STR "event_action" */
/* @0x1fdf30 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdf34 ldr r1, [pc, #0x584] —— r1=0xfffff4d4 (pool 0x1fe4c0) */
/* @0x1fdf38 ldr r0, [pc, #0x584] —— r0=0x1551ac (pool 0x1fe4c4) */
/* @0x1fdf3c mov r2, #0 */
/* @0x1fdf40 mov r3, r2 */
/* @0x1fdf44 ldr r1, [r4, r1] —— r1=GOT[0x3f112c] | ->0x1f89d4 */
/* @0x1fdf48 add r0, pc, r0 —— r0=0x3530fc [pc+0x1551ac] | STR "secure_mode" */
/* @0x1fdf4c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdf50 ldr r1, [pc, #0x570] —— r1=0xfffff4d8 (pool 0x1fe4c8) */
/* @0x1fdf54 ldr r2, [pc, #0x570] —— r2=0xfffff4dc (pool 0x1fe4cc) */
/* @0x1fdf58 mov r3, #1 */
/* @0x1fdf5c ldr r0, [pc, #0x56c] —— r0=0x155198 (pool 0x1fe4d0) */
/* @0x1fdf60 ldr r1, [r4, r1] —— r1=GOT[0x3f1130] | ->0x1f89ec */
/* @0x1fdf64 ldr r2, [r4, r2] —— r2=GOT[0x3f1134] | ->0x1f8a2c */
/* @0x1fdf68 add r0, pc, r0 —— r0=0x353108 [pc+0x155198] | STR "error_occurred" */
/* @0x1fdf6c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdf70 ldr r1, [pc, #0x55c] —— r1=0xfffff4e0 (pool 0x1fe4d4) */
/* @0x1fdf74 ldr r2, [pc, #0x55c] —— r2=0xfffff4e4 (pool 0x1fe4d8) */
/* @0x1fdf78 mov r3, #1 */
/* @0x1fdf7c ldr r0, [pc, #0x558] —— r0=0x155188 (pool 0x1fe4dc) */
/* @0x1fdf80 ldr r1, [r4, r1] —— r1=GOT[0x3f1138] | ->0x1fa230 */
/* @0x1fdf84 ldr r2, [r4, r2] —— r2=GOT[0x3f113c] | ->0x1f8a6c */
/* @0x1fdf88 add r0, pc, r0 —— r0=0x353118 [pc+0x155188] | STR "error_last" */
/* @0x1fdf8c bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdf90 ldr r1, [pc, #0x548] —— r1=0xfffff4e8 (pool 0x1fe4e0) */
/* @0x1fdf94 ldr r0, [pc, #0x548] —— r0=0x155178 (pool 0x1fe4e4) */
/* @0x1fdf98 mov r2, #0 */
/* @0x1fdf9c mov r3, r2 */
/* @0x1fdfa0 ldr r5, [r4, r1] —— r5=GOT[0x3f1140] | ->0x1f8a98 */
/* @0x1fdfa4 add r0, pc, r0 —— r0=0x353124 [pc+0x155178] | STR "gamemaker_registered" */
/* @0x1fdfa8 mov r1, r5 */
/* @0x1fdfac bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdfb0 ldr r0, [pc, #0x530] —— r0=0x155174 (pool 0x1fe4e8) */
/* @0x1fdfb4 mov r2, #0 */
/* @0x1fdfb8 mov r1, r5 */
/* @0x1fdfbc mov r3, r2 */
/* @0x1fdfc0 add r0, pc, r0 —— r0=0x35313c [pc+0x155174] | STR "gamemaker_pro" */
/* @0x1fdfc4 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdfc8 ldr r1, [pc, #0x51c] —— r1=0xfffff4ec (pool 0x1fe4ec) */
/* @0x1fdfcc ldr r0, [pc, #0x51c] —— r0=0x155168 (pool 0x1fe4f0) */
/* @0x1fdfd0 mov r2, #0 */
/* @0x1fdfd4 mov r3, r2 */
/* @0x1fdfd8 ldr r1, [r4, r1] —— r1=GOT[0x3f1144] | ->0x1f8ad8 */
/* @0x1fdfdc add r0, pc, r0 —— r0=0x35314c [pc+0x155168] | STR "application_surface" */
/* @0x1fdfe0 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fdfe4 ldr r1, [pc, #0x508] —— r1=0xfffff4f0 (pool 0x1fe4f4) */
/* @0x1fdfe8 ldr r2, [pc, #0x508] —— r2=0xfffff4f4 (pool 0x1fe4f8) */
/* @0x1fdfec mov r3, #0 */
/* @0x1fdff0 ldr r0, [pc, #0x504] —— r0=0x15515c (pool 0x1fe4fc) */
/* @0x1fdff4 ldr r1, [r4, r1] —— r1=GOT[0x3f1148] | ->0x1f878c */
/* @0x1fdff8 ldr r2, [r4, r2] —— r2=GOT[0x3f114c] | ->0x1fa254 */
/* @0x1fdffc add r0, pc, r0 —— r0=0x353160 [pc+0x15515c] | STR "font_texture_page_size" */
/* @0x1fe000 bl 0x1f4da8 <_Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b> */
/* @0x1fe004 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1fe008 b 0x15dafc <_Z24InitYoYoBuiltInVariablesv> */

/* ── ⑦ 尾部 literal 池（0x1fe00c..0x1fe4fc，317 字）────────────────
 *   三种内容：① GOT 偏移（0xfffff1f0 这类负数，槽 = 0x3f1c58 + 偏移，指到 getter/setter）；
 *   ② pc 相对串偏移（0x00155xxx，配 add pc 得到名字串，如 0x352a88 "argument_relative"）；
 *   ③ 极少数常量。objdump 把它们译成 ldrheq/andseq/mulseq/.word，均不是指令。
 *   注释里的「由 0x… 取用」就是唯一的 ldr 取用点。
 */
/* @0x1fe00c ldrheq r4, [pc], -r8 —— 常量/偏移 0x001f4ab8（0x1fd18c 取用） */
/* @0x1fe010 .word 0xffffbfe4 —— GOT 偏移 → 槽 0x3edc3c → 0x753108（0x1fd194 取用） */
/* @0x1fe014 .word 0xffffc7d8 —— GOT 偏移 → 槽 0x3ee430 → 0x755064（0x1fd19c 取用） */
/* @0x1fe018 .word 0xfffff1f0 —— GOT 偏移 → 槽 0x3f0e48 → 0x1f79ac（GV_ArgumentRelative(CInstance*, int, RValue*)）（0x1fd1a0 取用） */
/* @0x1fe01c andseq r5, r5, r12, asr #17 —— pc 相对串偏移 → "argument_relative"（0x1fd1ac 取用） */
/* @0x1fe020 .word 0xfffff1f4 —— GOT 偏移 → 槽 0x3f0e4c → 0x1ffca4（GV_Argument(CInstance*, int, RValue*)）（0x1fd1c4 取用） */
/* @0x1fe024 .word 0xfffff1f8 —— GOT 偏移 → 槽 0x3f0e50 → 0x1fa444（SV_Argument(CInstance*, int, RValue*)）（0x1fd1c8 取用） */
/* @0x1fe028 ldrheq r5, [r5], -r8 —— pc 相对串偏移 → "argument"（0x1fd1d0 取用） */
/* @0x1fe02c .word 0xfffff1fc —— GOT 偏移 → 槽 0x3f0e54 → 0x1ffe1c（GV_Argument0(CInstance*, int, RValue*)）（0x1fd1e4 取用） */
/* @0x1fe030 .word 0xfffff200 —— GOT 偏移 → 槽 0x3f0e58 → 0x1fa47c（SV_Argument0(CInstance*, int, RValue*)）（0x1fd1e8 取用） */
/* @0x1fe034 andseq r5, r5, r4, lsr #17 —— pc 相对串偏移 → "argument0"（0x1fd1f0 取用） */
/* @0x1fe038 .word 0xfffff204 —— GOT 偏移 → 槽 0x3f0e5c → 0x1ffea0（GV_Argument1(CInstance*, int, RValue*)）（0x1fd204 取用） */
/* @0x1fe03c .word 0xfffff208 —— GOT 偏移 → 槽 0x3f0e60 → 0x1fa4a8（SV_Argument1(CInstance*, int, RValue*)）（0x1fd208 取用） */
/* @0x1fe040 mulseq r5, r0, r8 —— pc 相对串偏移 → "argument1"（0x1fd210 取用） */
/* @0x1fe044 .word 0xfffff20c —— GOT 偏移 → 槽 0x3f0e64 → 0x1fff28（GV_Argument2(CInstance*, int, RValue*)）（0x1fd224 取用） */
/* @0x1fe048 .word 0xfffff210 —— GOT 偏移 → 槽 0x3f0e68 → 0x1fa4d8（SV_Argument2(CInstance*, int, RValue*)）（0x1fd228 取用） */
/* @0x1fe04c andseq r5, r5, r12, ror r8 —— pc 相对串偏移 → "argument2"（0x1fd230 取用） */
/* @0x1fe050 .word 0xfffff214 —— GOT 偏移 → 槽 0x3f0e6c → 0x1fffb0（GV_Argument3(CInstance*, int, RValue*)）（0x1fd244 取用） */
/* @0x1fe054 .word 0xfffff218 —— GOT 偏移 → 槽 0x3f0e70 → 0x1fa508（SV_Argument3(CInstance*, int, RValue*)）（0x1fd248 取用） */
/* @0x1fe058 andseq r5, r5, r8, ror #16 —— pc 相对串偏移 → "argument3"（0x1fd250 取用） */
/* @0x1fe05c .word 0xfffff21c —— GOT 偏移 → 槽 0x3f0e74 → 0x200038（GV_Argument4(CInstance*, int, RValue*)）（0x1fd264 取用） */
/* @0x1fe060 .word 0xfffff220 —— GOT 偏移 → 槽 0x3f0e78 → 0x1fa538（SV_Argument4(CInstance*, int, RValue*)）（0x1fd268 取用） */
/* @0x1fe064 andseq r5, r5, r4, asr r8 —— pc 相对串偏移 → "argument4"（0x1fd270 取用） */
/* @0x1fe068 .word 0xfffff224 —— GOT 偏移 → 槽 0x3f0e7c → 0x2000c0（GV_Argument5(CInstance*, int, RValue*)）（0x1fd284 取用） */
/* @0x1fe06c .word 0xfffff228 —— GOT 偏移 → 槽 0x3f0e80 → 0x1fa568（SV_Argument5(CInstance*, int, RValue*)）（0x1fd288 取用） */
/* @0x1fe070 andseq r5, r5, r0, asr #16 —— pc 相对串偏移 → "argument5"（0x1fd290 取用） */
/* @0x1fe074 .word 0xfffff22c —— GOT 偏移 → 槽 0x3f0e84 → 0x200148（GV_Argument6(CInstance*, int, RValue*)）（0x1fd2a4 取用） */
/* @0x1fe078 .word 0xfffff230 —— GOT 偏移 → 槽 0x3f0e88 → 0x1fa598（SV_Argument6(CInstance*, int, RValue*)）（0x1fd2a8 取用） */
/* @0x1fe07c andseq r5, r5, r12, lsr #16 —— pc 相对串偏移 → "argument6"（0x1fd2b0 取用） */
/* @0x1fe080 .word 0xfffff234 —— GOT 偏移 → 槽 0x3f0e8c → 0x2001d0（GV_Argument7(CInstance*, int, RValue*)）（0x1fd2c4 取用） */
/* @0x1fe084 .word 0xfffff238 —— GOT 偏移 → 槽 0x3f0e90 → 0x1fa5c8（SV_Argument7(CInstance*, int, RValue*)）（0x1fd2c8 取用） */
/* @0x1fe088 andseq r5, r5, r8, lsl r8 —— pc 相对串偏移 → "argument7"（0x1fd2d0 取用） */
/* @0x1fe08c .word 0xfffff23c —— GOT 偏移 → 槽 0x3f0e94 → 0x200258（GV_Argument8(CInstance*, int, RValue*)）（0x1fd2e4 取用） */
/* @0x1fe090 .word 0xfffff240 —— GOT 偏移 → 槽 0x3f0e98 → 0x1fa5f8（SV_Argument8(CInstance*, int, RValue*)）（0x1fd2e8 取用） */
/* @0x1fe094 andseq r5, r5, r4, lsl #16 —— pc 相对串偏移 → "argument8"（0x1fd2f0 取用） */
/* @0x1fe098 .word 0xfffff244 —— GOT 偏移 → 槽 0x3f0e9c → 0x2002e0（GV_Argument9(CInstance*, int, RValue*)）（0x1fd304 取用） */
/* @0x1fe09c .word 0xfffff248 —— GOT 偏移 → 槽 0x3f0ea0 → 0x1fa628（SV_Argument9(CInstance*, int, RValue*)）（0x1fd308 取用） */
/* @0x1fe0a0 ldrsheq r5, [r5], -r0 —— pc 相对串偏移 → "argument9"（0x1fd310 取用） */
/* @0x1fe0a4 .word 0xfffff24c —— GOT 偏移 → 槽 0x3f0ea4 → 0x200368（GV_Argument10(CInstance*, int, RValue*)）（0x1fd324 取用） */
/* @0x1fe0a8 .word 0xfffff250 —— GOT 偏移 → 槽 0x3f0ea8 → 0x1fa658（SV_Argument10(CInstance*, int, RValue*)）（0x1fd328 取用） */
/* @0x1fe0ac ldrsbeq r5, [r5], -r12 —— pc 相对串偏移 → "argument10"（0x1fd330 取用） */
/* @0x1fe0b0 .word 0xfffff254 —— GOT 偏移 → 槽 0x3f0eac → 0x2003f0（GV_Argument11(CInstance*, int, RValue*)）（0x1fd344 取用） */
/* @0x1fe0b4 .word 0xfffff258 —— GOT 偏移 → 槽 0x3f0eb0 → 0x1fa688（SV_Argument11(CInstance*, int, RValue*)）（0x1fd348 取用） */
/* @0x1fe0b8 andseq r5, r5, r8, asr #15 —— pc 相对串偏移 → "argument11"（0x1fd350 取用） */
/* @0x1fe0bc .word 0xfffff25c —— GOT 偏移 → 槽 0x3f0eb4 → 0x200478（GV_Argument12(CInstance*, int, RValue*)）（0x1fd364 取用） */
/* @0x1fe0c0 .word 0xfffff260 —— GOT 偏移 → 槽 0x3f0eb8 → 0x1fa6b8（SV_Argument12(CInstance*, int, RValue*)）（0x1fd368 取用） */
/* @0x1fe0c4 ldrheq r5, [r5], -r4 —— pc 相对串偏移 → "argument12"（0x1fd370 取用） */
/* @0x1fe0c8 .word 0xfffff264 —— GOT 偏移 → 槽 0x3f0ebc → 0x200500（GV_Argument13(CInstance*, int, RValue*)）（0x1fd384 取用） */
/* @0x1fe0cc .word 0xfffff268 —— GOT 偏移 → 槽 0x3f0ec0 → 0x1fa6e8（SV_Argument13(CInstance*, int, RValue*)）（0x1fd388 取用） */
/* @0x1fe0d0 andseq r5, r5, r0, lsr #15 —— pc 相对串偏移 → "argument13"（0x1fd390 取用） */
/* @0x1fe0d4 .word 0xfffff26c —— GOT 偏移 → 槽 0x3f0ec4 → 0x200588（GV_Argument14(CInstance*, int, RValue*)）（0x1fd3a4 取用） */
/* @0x1fe0d8 .word 0xfffff270 —— GOT 偏移 → 槽 0x3f0ec8 → 0x1fa718（SV_Argument14(CInstance*, int, RValue*)）（0x1fd3a8 取用） */
/* @0x1fe0dc andseq r5, r5, r12, lsl #15 —— pc 相对串偏移 → "argument14"（0x1fd3b0 取用） */
/* @0x1fe0e0 .word 0xfffff274 —— GOT 偏移 → 槽 0x3f0ecc → 0x200610（GV_Argument15(CInstance*, int, RValue*)）（0x1fd3c4 取用） */
/* @0x1fe0e4 .word 0xfffff278 —— GOT 偏移 → 槽 0x3f0ed0 → 0x1fa748（SV_Argument15(CInstance*, int, RValue*)）（0x1fd3c8 取用） */
/* @0x1fe0e8 andseq r5, r5, r8, ror r7 —— pc 相对串偏移 → "argument15"（0x1fd3d0 取用） */
/* @0x1fe0ec .word 0xfffff27c —— GOT 偏移 → 槽 0x3f0ed4 → 0x200c88（GV_ArgumentCount(CInstance*, int, RValue*)）（0x1fd3e4 取用） */
/* @0x1fe0f0 andseq r5, r5, r8, ror #14 —— pc 相对串偏移 → "argument_count"（0x1fd3e8 取用） */
/* @0x1fe0f4 .word 0xfffff280 —— GOT 偏移 → 槽 0x3f0ed8 → 0x200ea4（GV_DebugMode(CInstance*, int, RValue*)）（0x1fd400 取用） */
/* @0x1fe0f8 andseq r5, r5, r12, asr r7 —— pc 相对串偏移 → "debug_mode"（0x1fd404 取用） */
/* @0x1fe0fc .word 0xfffff284 —— GOT 偏移 → 槽 0x3f0edc → 0x200a8c（GV_PointerInvalid(CInstance*, int, RValue*)）（0x1fd41c 取用） */
/* @0x1fe100 andseq r5, r5, r12, asr #14 —— pc 相对串偏移 → "pointer_invalid"（0x1fd420 取用） */
/* @0x1fe104 .word 0xfffff288 —— GOT 偏移 → 槽 0x3f0ee0 → 0x200698（GV_PointerNull(CInstance*, int, RValue*)）（0x1fd438 取用） */
/* @0x1fe108 andseq r5, r5, r0, asr #14 —— pc 相对串偏移 → "pointer_null"（0x1fd43c 取用） */
/* @0x1fe10c .word 0xfffff28c —— GOT 偏移 → 槽 0x3f0ee4 → 0x200890（GV_Undefined(CInstance*, int, RValue*)）（0x1fd454 取用） */
/* @0x1fe110 ldrsheq r4, [r3], -r8 —— pc 相对串偏移 → "undefined"（0x1fd458 取用） */
/* @0x1fe114 .word 0xfffff290 —— GOT 偏移 → 槽 0x3f0ee8 → 0x1f79ec（GV_Room(CInstance*, int, RValue*)）（0x1fd470 取用） */
/* @0x1fe118 .word 0xfffff294 —— GOT 偏移 → 槽 0x3f0eec → 0x1fa7d4（SV_Room(CInstance*, int, RValue*)）（0x1fd474 取用） */
/* @0x1fe11c andseq r5, r5, r4, lsl r7 —— pc 相对串偏移 → "room"（0x1fd47c 取用） */
/* @0x1fe120 .word 0xfffff298 —— GOT 偏移 → 槽 0x3f0ef0 → 0x1f9bac（GV_RoomFirst(CInstance*, int, RValue*)）（0x1fd490 取用） */
/* @0x1fe124 andseq r5, r5, r0, lsl #14 —— pc 相对串偏移 → "room_first"（0x1fd494 取用） */
/* @0x1fe128 .word 0xfffff29c —— GOT 偏移 → 槽 0x3f0ef4 → 0x1f9be0（GV_RoomLast(CInstance*, int, RValue*)）（0x1fd4ac 取用） */
/* @0x1fe12c ldrsheq r5, [r5], -r0 —— pc 相对串偏移 → "room_last"（0x1fd4b0 取用） */
/* @0x1fe130 .word 0xfffff2a0 —— GOT 偏移 → 槽 0x3f0ef8 → 0x1f7a2c（GV_TransitionKind(CInstance*, int, RValue*)）（0x1fd4c8 取用） */
/* @0x1fe134 .word 0xfffff2a4 —— GOT 偏移 → 槽 0x3f0efc → 0x1fa778（SV_TransitionKind(CInstance*, int, RValue*)）（0x1fd4cc 取用） */
/* @0x1fe138 ldrsbeq r5, [r5], -r12 —— pc 相对串偏移 → "transition_kind"（0x1fd4d4 取用） */
/* @0x1fe13c .word 0xfffff2a8 —— GOT 偏移 → 槽 0x3f0f00 → 0x1f7a6c（GV_TransitionSteps(CInstance*, int, RValue*)）（0x1fd4e8 取用） */
/* @0x1fe140 .word 0xfffff2ac —— GOT 偏移 → 槽 0x3f0f04 → 0x1f8848（SV_TransitionSteps(CInstance*, int, RValue*)）（0x1fd4ec 取用） */
/* @0x1fe144 andseq r5, r5, r12, asr #13 —— pc 相对串偏移 → "transition_steps"（0x1fd4f4 取用） */
/* @0x1fe148 .word 0xfffff2b0 —— GOT 偏移 → 槽 0x3f0f08 → 0x1f7a84（GV_Score(CInstance*, int, RValue*)）（0x1fd508 取用） */
/* @0x1fe14c .word 0xfffff2b4 —— GOT 偏移 → 槽 0x3f0f0c → 0x1fb26c（SV_Score(CInstance*, int, RValue*)）（0x1fd50c 取用） */
/* @0x1fe150 andseq r5, r5, r0, asr #13 —— pc 相对串偏移 → "score"（0x1fd514 取用） */
/* @0x1fe154 .word 0xfffff2b8 —— GOT 偏移 → 槽 0x3f0f10 → 0x1f7ac4（GV_Lives(CInstance*, int, RValue*)）（0x1fd528 取用） */
/* @0x1fe158 .word 0xfffff2bc —— GOT 偏移 → 槽 0x3f0f14 → 0x1fb2c0（SV_Lives(CInstance*, int, RValue*)）（0x1fd52c 取用） */
/* @0x1fe15c andseq r5, r5, r8, lsr #13 —— pc 相对串偏移 → "lives"（0x1fd534 取用） */
/* @0x1fe160 .word 0xfffff2c0 —— GOT 偏移 → 槽 0x3f0f18 → 0x1f7b04（GV_Health(CInstance*, int, RValue*)）（0x1fd548 取用） */
/* @0x1fe164 .word 0xfffff2c4 —— GOT 偏移 → 槽 0x3f0f1c → 0x1fb33c（SV_Health(CInstance*, int, RValue*)）（0x1fd54c 取用） */
/* @0x1fe168 mulseq r5, r0, r6 —— pc 相对串偏移 → "health"（0x1fd554 取用） */
/* @0x1fe16c .word 0xfffff2c8 —— GOT 偏移 → 槽 0x3f0f20 → 0x1f7b30（GV_GameId(CInstance*, int, RValue*)）（0x1fd568 取用） */
/* @0x1fe170 andseq r5, r5, r12, ror r6 —— pc 相对串偏移 → "game_id"（0x1fd56c 取用） */
/* @0x1fe174 .word 0xfffff2cc —— GOT 偏移 → 槽 0x3f0f24 → 0x1f9c5c（GV_GameGuId(CInstance*, int, RValue*)）（0x1fd584 取用） */
/* @0x1fe178 andseq r5, r5, r8, ror #12 —— pc 相对串偏移 → "game_guid"（0x1fd588 取用） */
/* @0x1fe17c .word 0xfffff2d0 —— GOT 偏移 → 槽 0x3f0f28 → 0x1f9c14（GV_GameDisplayName(CInstance*, int, RValue*)）（0x1fd5a0 取用） */
/* @0x1fe180 andseq r5, r5, r8, asr r6 —— pc 相对串偏移 → "game_display_name"（0x1fd5a4 取用） */
/* @0x1fe184 .word 0xfffff2d4 —— GOT 偏移 → 槽 0x3f0f2c → 0x1f9c38（GV_GameProjectName(CInstance*, int, RValue*)）（0x1fd5bc 取用） */
/* @0x1fe188 andseq r5, r5, r0, asr r6 —— pc 相对串偏移 → "game_project_name"（0x1fd5c0 取用） */
/* @0x1fe18c .word 0xfffff2d8 —— GOT 偏移 → 槽 0x3f0f30 → 0x1f9d0c（GV_SaveDirectory(CInstance*, int, RValue*)）（0x1fd5d8 取用） */
/* @0x1fe190 andseq r5, r5, r8, asr #12 —— pc 相对串偏移 → "game_save_id"（0x1fd5dc 取用） */
/* @0x1fe194 .word 0xfffff2dc —— GOT 偏移 → 槽 0x3f0f34 → 0x1f9c74（GV_WorkingDirectory(CInstance*, int, RValue*)）（0x1fd5f4 取用） */
/* @0x1fe198 andseq r5, r5, r12, lsr r6 —— pc 相对串偏移 → "working_directory"（0x1fd5f8 取用） */
/* @0x1fe19c .word 0xfffff2e0 —— GOT 偏移 → 槽 0x3f0f38 → 0x1f9d2c（GV_TempDirectory(CInstance*, int, RValue*)）（0x1fd610 取用） */
/* @0x1fe1a0 andseq r5, r5, r4, lsr r6 —— pc 相对串偏移 → "temp_directory"（0x1fd614 取用） */
/* @0x1fe1a4 .word 0xfffff2e4 —— GOT 偏移 → 槽 0x3f0f3c → 0x1f9cc0（GV_ProgramDirectory(CInstance*, int, RValue*)）（0x1fd62c 取用） */
/* @0x1fe1a8 andseq r5, r5, r8, lsr #12 —— pc 相对串偏移 → "program_directory"（0x1fd630 取用） */
/* @0x1fe1ac .word 0xfffff2e8 —— GOT 偏移 → 槽 0x3f0f40 → 0x1f7b70（GV_InstanceCount(CInstance*, int, RValue*)）（0x1fd648 取用） */
/* @0x1fe1b0 andseq r5, r5, r0, lsr #12 —— pc 相对串偏移 → "instance_count"（0x1fd64c 取用） */
/* @0x1fe1b4 .word 0xfffff2ec —— GOT 偏移 → 槽 0x3f0f44 → 0x1fb0a8（GV_InstanceId(CInstance*, int, RValue*)）（0x1fd664 取用） */
/* @0x1fe1b8 andseq r5, r5, r4, lsl r6 —— pc 相对串偏移 → "instance_id"（0x1fd668 取用） */
/* @0x1fe1bc .word 0xfffff2f0 —— GOT 偏移 → 槽 0x3f0f48 → 0x1f7bb4（GV_RoomWidth(CInstance*, int, RValue*)）（0x1fd680 取用） */
/* @0x1fe1c0 .word 0xfffff2f4 —— GOT 偏移 → 槽 0x3f0f4c → 0x1fce7c（SV_RoomWidth(CInstance*, int, RValue*)）（0x1fd684 取用） */
/* @0x1fe1c4 andseq r5, r5, r0, lsl #12 —— pc 相对串偏移 → "room_width"（0x1fd68c 取用） */
/* @0x1fe1c8 .word 0xfffff2f8 —— GOT 偏移 → 槽 0x3f0f50 → 0x1f7bf8（GV_RoomHeight(CInstance*, int, RValue*)）（0x1fd6a0 取用） */
/* @0x1fe1cc .word 0xfffff2fc —— GOT 偏移 → 槽 0x3f0f54 → 0x1fce24（SV_RoomHeight(CInstance*, int, RValue*)）（0x1fd6a4 取用） */
/* @0x1fe1d0 andseq r5, r5, r12, ror #11 —— pc 相对串偏移 → "room_height"（0x1fd6ac 取用） */
/* @0x1fe1d4 .word 0xfffff300 —— GOT 偏移 → 槽 0x3f0f58 → 0x1f9c98（GV_RoomCaption(CInstance*, int, RValue*)）（0x1fd6c0 取用） */
/* @0x1fe1d8 .word 0xfffff304 —— GOT 偏移 → 槽 0x3f0f5c → 0x1fae58（SV_RoomCaption(CInstance*, int, RValue*)）（0x1fd6c4 取用） */
/* @0x1fe1dc ldrsbeq r5, [r5], -r8 —— pc 相对串偏移 → "room_caption"（0x1fd6cc 取用） */
/* @0x1fe1e0 .word 0xfffff308 —— GOT 偏移 → 槽 0x3f0f60 → 0x1faeb0（GV_RoomSpeed(CInstance*, int, RValue*)）（0x1fd6e0 取用） */
/* @0x1fe1e4 .word 0xfffff30c —— GOT 偏移 → 槽 0x3f0f64 → 0x1fced4（SV_RoomSpeed(CInstance*, int, RValue*)）（0x1fd6e4 取用） */
/* @0x1fe1e8 andseq r5, r5, r8, asr #11 —— pc 相对串偏移 → "room_speed"（0x1fd6ec 取用） */
/* @0x1fe1ec .word 0xfffff310 —— GOT 偏移 → 槽 0x3f0f68 → 0x1f7c3c（GV_RoomPersistent(CInstance*, int, RValue*)）（0x1fd700 取用） */
/* @0x1fe1f0 .word 0xfffff314 —— GOT 偏移 → 槽 0x3f0f6c → 0x1fcf9c（SV_RoomPersistent(CInstance*, int, RValue*)）（0x1fd704 取用） */
/* @0x1fe1f4 ldrheq r5, [r5], -r4 —— pc 相对串偏移 → "room_persistent"（0x1fd70c 取用） */
/* @0x1fe1f8 .word 0xfffff318 —— GOT 偏移 → 槽 0x3f0f70 → 0x1f7c80（GV_BackgroundColor(CInstance*, int, RValue*)）（0x1fd720 取用） */
/* @0x1fe1fc .word 0xfffff31c —— GOT 偏移 → 槽 0x3f0f74 → 0x1fd010（SV_BackgroundColor(CInstance*, int, RValue*)）（0x1fd724 取用） */
/* @0x1fe200 andseq r5, r5, r4, lsr #11 —— pc 相对串偏移 → "background_color"（0x1fd72c 取用） */
/* @0x1fe204 .word 0xfffff320 —— GOT 偏移 → 槽 0x3f0f78 → 0x1f7cc4（GV_BackgroundShowColor(CInstance*, int, RValue*)）（0x1fd748 取用） */
/* @0x1fe208 .word 0xfffff324 —— GOT 偏移 → 槽 0x3f0f7c → 0x1fd068（SV_BackgroundShowColor(CInstance*, int, RValue*)）（0x1fd74c 取用） */
/* @0x1fe20c mulseq r5, r0, r5 —— pc 相对串偏移 → "background_showcolor"（0x1fd754 取用） */
/* @0x1fe210 andseq r5, r5, r12, lsl #11 —— pc 相对串偏移 → "background_colour"（0x1fd770 取用） */
/* @0x1fe214 andseq r5, r5, r8, lsl #11 —— pc 相对串偏移 → "background_showcolour"（0x1fd788 取用） */
/* @0x1fe218 .word 0xfffff328 —— GOT 偏移 → 槽 0x3f0f80 → 0x1f7d08（GV_BackgroundVisible(CInstance*, int, RValue*)）（0x1fd7a0 取用） */
/* @0x1fe21c .word 0xfffff32c —— GOT 偏移 → 槽 0x3f0f84 → 0x1fc8a8（SV_BackgroundVisible(CInstance*, int, RValue*)）（0x1fd7a4 取用） */
/* @0x1fe220 andseq r5, r5, r12, ror r5 —— pc 相对串偏移 → "background_visible"（0x1fd7ac 取用） */
/* @0x1fe224 .word 0xfffff330 —— GOT 偏移 → 槽 0x3f0f88 → 0x1f7d5c（GV_BackgroundForeground(CInstance*, int, RValue*)）（0x1fd7c0 取用） */
/* @0x1fe228 .word 0xfffff334 —— GOT 偏移 → 槽 0x3f0f8c → 0x1fc92c（SV_BackgroundForeground(CInstance*, int, RValue*)）（0x1fd7c4 取用） */
/* @0x1fe22c andseq r5, r5, r0, ror r5 —— pc 相对串偏移 → "background_foreground"（0x1fd7cc 取用） */
/* @0x1fe230 .word 0xfffff338 —— GOT 偏移 → 槽 0x3f0f90 → 0x1f7db0（GV_BackgroundIndex(CInstance*, int, RValue*)）（0x1fd7e0 取用） */
/* @0x1fe234 .word 0xfffff33c —— GOT 偏移 → 槽 0x3f0f94 → 0x1fc9b0（SV_BackgroundIndex(CInstance*, int, RValue*)）（0x1fd7e4 取用） */
/* @0x1fe238 andseq r5, r5, r8, ror #10 —— pc 相对串偏移 → "background_index"（0x1fd7ec 取用） */
/* @0x1fe23c .word 0xfffff340 —— GOT 偏移 → 槽 0x3f0f98 → 0x1f7e04（GV_BackgroundX(CInstance*, int, RValue*)）（0x1fd800 取用） */
/* @0x1fe240 .word 0xfffff344 —— GOT 偏移 → 槽 0x3f0f9c → 0x1fca18（SV_BackgroundX(CInstance*, int, RValue*)）（0x1fd804 取用） */
/* @0x1fe244 andseq r5, r5, r12, asr r5 —— pc 相对串偏移 → "background_x"（0x1fd80c 取用） */
/* @0x1fe248 .word 0xfffff348 —— GOT 偏移 → 槽 0x3f0fa0 → 0x1f7e54（GV_BackgroundY(CInstance*, int, RValue*)）（0x1fd820 取用） */
/* @0x1fe24c .word 0xfffff34c —— GOT 偏移 → 槽 0x3f0fa4 → 0x1fca70（SV_BackgroundY(CInstance*, int, RValue*)）（0x1fd824 取用） */
/* @0x1fe250 andseq r5, r5, r12, asr #10 —— pc 相对串偏移 → "background_y"（0x1fd82c 取用） */
/* @0x1fe254 .word 0xfffff350 —— GOT 偏移 → 槽 0x3f0fa8 → 0x1f9f20（GV_BackgroundWidth(CInstance*, int, RValue*)）（0x1fd840 取用） */
/* @0x1fe258 andseq r5, r5, r0, asr #10 —— pc 相对串偏移 → "background_width"（0x1fd844 取用） */
/* @0x1fe25c .word 0xfffff354 —— GOT 偏移 → 槽 0x3f0fac → 0x1f9f98（GV_BackgroundHeight(CInstance*, int, RValue*)）（0x1fd85c 取用） */
/* @0x1fe260 andseq r5, r5, r8, lsr r5 —— pc 相对串偏移 → "background_height"（0x1fd860 取用） */
/* @0x1fe264 .word 0xfffff358 —— GOT 偏移 → 槽 0x3f0fb0 → 0x1f7ea4（GV_BackgroundHTiled(CInstance*, int, RValue*)）（0x1fd878 取用） */
/* @0x1fe268 .word 0xfffff35c —— GOT 偏移 → 槽 0x3f0fb4 → 0x1fcac8（SV_BackgroundHTiled(CInstance*, int, RValue*)）（0x1fd87c 取用） */
/* @0x1fe26c andseq r5, r5, r12, lsr #10 —— pc 相对串偏移 → "background_htiled"（0x1fd884 取用） */
/* @0x1fe270 .word 0xfffff360 —— GOT 偏移 → 槽 0x3f0fb8 → 0x1f7ef8（GV_BackgroundVTiled(CInstance*, int, RValue*)）（0x1fd898 取用） */
/* @0x1fe274 .word 0xfffff364 —— GOT 偏移 → 槽 0x3f0fbc → 0x1fcb4c（SV_BackgroundVTiled(CInstance*, int, RValue*)）（0x1fd89c 取用） */
/* @0x1fe278 andseq r5, r5, r0, lsr #10 —— pc 相对串偏移 → "background_vtiled"（0x1fd8a4 取用） */
/* @0x1fe27c .word 0xfffff368 —— GOT 偏移 → 槽 0x3f0fc0 → 0x1f7f4c（GV_BackgroundXScale(CInstance*, int, RValue*)）（0x1fd8b8 取用） */
/* @0x1fe280 .word 0xfffff36c —— GOT 偏移 → 槽 0x3f0fc4 → 0x1fcbd0（SV_BackgroundXScale(CInstance*, int, RValue*)）（0x1fd8bc 取用） */
/* @0x1fe284 andseq r5, r5, r4, lsl r5 —— pc 相对串偏移 → "background_xscale"（0x1fd8c4 取用） */
/* @0x1fe288 .word 0xfffff370 —— GOT 偏移 → 槽 0x3f0fc8 → 0x1f7f9c（GV_BackgroundYScale(CInstance*, int, RValue*)）（0x1fd8d8 取用） */
/* @0x1fe28c .word 0xfffff374 —— GOT 偏移 → 槽 0x3f0fcc → 0x1fcc28（SV_BackgroundYScale(CInstance*, int, RValue*)）（0x1fd8dc 取用） */
/* @0x1fe290 andseq r5, r5, r8, lsl #10 —— pc 相对串偏移 → "background_yscale"（0x1fd8e4 取用） */
/* @0x1fe294 .word 0xfffff378 —— GOT 偏移 → 槽 0x3f0fd0 → 0x1f7fec（GV_BackgroundHSpeed(CInstance*, int, RValue*)）（0x1fd8f8 取用） */
/* @0x1fe298 .word 0xfffff37c —— GOT 偏移 → 槽 0x3f0fd4 → 0x1fcc80（SV_BackgroundHSpeed(CInstance*, int, RValue*)）（0x1fd8fc 取用） */
/* @0x1fe29c ldrsheq r5, [r5], -r12 —— pc 相对串偏移 → "background_hspeed"（0x1fd904 取用） */
/* @0x1fe2a0 .word 0xfffff380 —— GOT 偏移 → 槽 0x3f0fd8 → 0x1f803c（GV_BackgroundVSpeed(CInstance*, int, RValue*)）（0x1fd918 取用） */
/* @0x1fe2a4 .word 0xfffff384 —— GOT 偏移 → 槽 0x3f0fdc → 0x1fccd8（SV_BackgroundVSpeed(CInstance*, int, RValue*)）（0x1fd91c 取用） */
/* @0x1fe2a8 ldrsheq r5, [r5], -r0 —— pc 相对串偏移 → "background_vspeed"（0x1fd924 取用） */
/* @0x1fe2ac .word 0xfffff388 —— GOT 偏移 → 槽 0x3f0fe0 → 0x1f808c（GV_BackgroundBlend(CInstance*, int, RValue*)）（0x1fd938 取用） */
/* @0x1fe2b0 .word 0xfffff38c —— GOT 偏移 → 槽 0x3f0fe4 → 0x1fcd30（SV_BackgroundBlend(CInstance*, int, RValue*)）（0x1fd93c 取用） */
/* @0x1fe2b4 andseq r5, r5, r4, ror #9 —— pc 相对串偏移 → "background_blend"（0x1fd944 取用） */
/* @0x1fe2b8 .word 0xfffff390 —— GOT 偏移 → 槽 0x3f0fe8 → 0x1f80e0（GV_BackgroundAlpha(CInstance*, int, RValue*)）（0x1fd958 取用） */
/* @0x1fe2bc .word 0xfffff394 —— GOT 偏移 → 槽 0x3f0fec → 0x1fcdcc（SV_BackgroundAlpha(CInstance*, int, RValue*)）（0x1fd95c 取用） */
/* @0x1fe2c0 ldrsbeq r5, [r5], -r8 —— pc 相对串偏移 → "background_alpha"（0x1fd964 取用） */
/* @0x1fe2c4 .word 0xfffff398 —— GOT 偏移 → 槽 0x3f0ff0 → 0x1f8130（GV_ViewEnabled(CInstance*, int, RValue*)）（0x1fd978 取用） */
/* @0x1fe2c8 .word 0xfffff39c —— GOT 偏移 → 槽 0x3f0ff4 → 0x1fd0dc（SV_ViewEnabled(CInstance*, int, RValue*)）（0x1fd97c 取用） */
/* @0x1fe2cc andseq r5, r5, r12, asr #9 —— pc 相对串偏移 → "view_enabled"（0x1fd984 取用） */
/* @0x1fe2d0 .word 0xfffff3a0 —— GOT 偏移 → 槽 0x3f0ff8 → 0x1f8174（GV_ViewCurrent(CInstance*, int, RValue*)）（0x1fd998 取用） */
/* @0x1fe2d4 andseq r5, r5, r0, asr #9 —— pc 相对串偏移 → "view_current"（0x1fd99c 取用） */
/* @0x1fe2d8 .word 0xfffff3a4 —— GOT 偏移 → 槽 0x3f0ffc → 0x1f81b4（GV_ViewVisible(CInstance*, int, RValue*)）（0x1fd9b4 取用） */
/* @0x1fe2dc .word 0xfffff3a8 —— GOT 偏移 → 槽 0x3f1000 → 0x1fc1f4（SV_ViewVisible(CInstance*, int, RValue*)）（0x1fd9b8 取用） */
/* @0x1fe2e0 ldrheq r5, [r5], -r0 —— pc 相对串偏移 → "view_visible"（0x1fd9c0 取用） */
/* @0x1fe2e4 .word 0xfffff3ac —— GOT 偏移 → 槽 0x3f1004 → 0x1f8208（GV_ViewXview(CInstance*, int, RValue*)）（0x1fd9d4 取用） */
/* @0x1fe2e8 .word 0xfffff3b0 —— GOT 偏移 → 槽 0x3f1008 → 0x1fc278（SV_ViewXview(CInstance*, int, RValue*)）（0x1fd9d8 取用） */
/* @0x1fe2ec andseq r5, r5, r0, lsr #9 —— pc 相对串偏移 → "view_xview"（0x1fd9e0 取用） */
/* @0x1fe2f0 .word 0xfffff3b4 —— GOT 偏移 → 槽 0x3f100c → 0x1f8258（GV_ViewYview(CInstance*, int, RValue*)）（0x1fd9f4 取用） */
/* @0x1fe2f4 .word 0xfffff3b8 —— GOT 偏移 → 槽 0x3f1010 → 0x1fc2d0（SV_ViewYview(CInstance*, int, RValue*)）（0x1fd9f8 取用） */
/* @0x1fe2f8 andseq r5, r5, r12, lsl #9 —— pc 相对串偏移 → "view_yview"（0x1fda00 取用） */
/* @0x1fe2fc .word 0xfffff3bc —— GOT 偏移 → 槽 0x3f1014 → 0x1f82a8（GV_ViewWview(CInstance*, int, RValue*)）（0x1fda14 取用） */
/* @0x1fe300 .word 0xfffff3c0 —— GOT 偏移 → 槽 0x3f1018 → 0x1fc328（SV_ViewWview(CInstance*, int, RValue*)）（0x1fda18 取用） */
/* @0x1fe304 andseq r5, r5, r8, ror r4 —— pc 相对串偏移 → "view_wview"（0x1fda20 取用） */
/* @0x1fe308 .word 0xfffff3c4 —— GOT 偏移 → 槽 0x3f101c → 0x1f82f8（GV_ViewHview(CInstance*, int, RValue*)）（0x1fda34 取用） */
/* @0x1fe30c .word 0xfffff3c8 —— GOT 偏移 → 槽 0x3f1020 → 0x1fc380（SV_ViewHview(CInstance*, int, RValue*)）（0x1fda38 取用） */
/* @0x1fe310 andseq r5, r5, r4, ror #8 —— pc 相对串偏移 → "view_hview"（0x1fda40 取用） */
/* @0x1fe314 .word 0xfffff3cc —— GOT 偏移 → 槽 0x3f1024 → 0x1f8348（GV_ViewXport(CInstance*, int, RValue*)）（0x1fda54 取用） */
/* @0x1fe318 .word 0xfffff3d0 —— GOT 偏移 → 槽 0x3f1028 → 0x1fc3d8（SV_ViewXport(CInstance*, int, RValue*)）（0x1fda58 取用） */
/* @0x1fe31c andseq r5, r5, r0, asr r4 —— pc 相对串偏移 → "view_xport"（0x1fda60 取用） */
/* @0x1fe320 .word 0xfffff3d4 —— GOT 偏移 → 槽 0x3f102c → 0x1f839c（GV_ViewYport(CInstance*, int, RValue*)）（0x1fda74 取用） */
/* @0x1fe324 .word 0xfffff3d8 —— GOT 偏移 → 槽 0x3f1030 → 0x1fc440（SV_ViewYport(CInstance*, int, RValue*)）（0x1fda78 取用） */
/* @0x1fe328 andseq r5, r5, r12, lsr r4 —— pc 相对串偏移 → "view_yport"（0x1fda80 取用） */
/* @0x1fe32c .word 0xfffff3dc —— GOT 偏移 → 槽 0x3f1034 → 0x1f83f0（GV_ViewWport(CInstance*, int, RValue*)）（0x1fda94 取用） */
/* @0x1fe330 .word 0xfffff3e0 —— GOT 偏移 → 槽 0x3f1038 → 0x1fc4a8（SV_ViewWport(CInstance*, int, RValue*)）（0x1fda98 取用） */
/* @0x1fe334 andseq r5, r5, r8, lsr #8 —— pc 相对串偏移 → "view_wport"（0x1fdaa0 取用） */
/* @0x1fe338 .word 0xfffff3e4 —— GOT 偏移 → 槽 0x3f103c → 0x1f8444（GV_ViewHport(CInstance*, int, RValue*)）（0x1fdab4 取用） */
/* @0x1fe33c .word 0xfffff3e8 —— GOT 偏移 → 槽 0x3f1040 → 0x1fc510（SV_ViewHport(CInstance*, int, RValue*)）（0x1fdab8 取用） */
/* @0x1fe340 andseq r5, r5, r4, lsl r4 —— pc 相对串偏移 → "view_hport"（0x1fdac0 取用） */
/* @0x1fe344 .word 0xfffff3ec —— GOT 偏移 → 槽 0x3f1044 → 0x1f8498（GV_ViewAngle(CInstance*, int, RValue*)）（0x1fdad4 取用） */
/* @0x1fe348 .word 0xfffff3f0 —— GOT 偏移 → 槽 0x3f1048 → 0x1fc578（SV_ViewAngle(CInstance*, int, RValue*)）（0x1fdad8 取用） */
/* @0x1fe34c andseq r5, r5, r0, lsl #8 —— pc 相对串偏移 → "view_angle"（0x1fdae0 取用） */
/* @0x1fe350 .word 0xfffff3f4 —— GOT 偏移 → 槽 0x3f104c → 0x1f84e8（GV_ViewHBorder(CInstance*, int, RValue*)）（0x1fdaf4 取用） */
/* @0x1fe354 .word 0xfffff3f8 —— GOT 偏移 → 槽 0x3f1050 → 0x1fc5d0（SV_ViewHBorder(CInstance*, int, RValue*)）（0x1fdaf8 取用） */
/* @0x1fe358 andseq r5, r5, r12, ror #7 —— pc 相对串偏移 → "view_hborder"（0x1fdb00 取用） */
/* @0x1fe35c .word 0xfffff3fc —— GOT 偏移 → 槽 0x3f1054 → 0x1f853c（GV_ViewVBorder(CInstance*, int, RValue*)）（0x1fdb14 取用） */
/* @0x1fe360 .word 0xfffff400 —— GOT 偏移 → 槽 0x3f1058 → 0x1fc638（SV_ViewVBorder(CInstance*, int, RValue*)）（0x1fdb18 取用） */
/* @0x1fe364 ldrsbeq r5, [r5], -r12 —— pc 相对串偏移 → "view_vborder"（0x1fdb20 取用） */
/* @0x1fe368 .word 0xfffff404 —— GOT 偏移 → 槽 0x3f105c → 0x1f8590（GV_ViewHSpeed(CInstance*, int, RValue*)）（0x1fdb34 取用） */
/* @0x1fe36c .word 0xfffff408 —— GOT 偏移 → 槽 0x3f1060 → 0x1fc6a0（SV_ViewHSpeed(CInstance*, int, RValue*)）（0x1fdb38 取用） */
/* @0x1fe370 andseq r5, r5, r12, asr #7 —— pc 相对串偏移 → "view_hspeed"（0x1fdb40 取用） */
/* @0x1fe374 .word 0xfffff40c —— GOT 偏移 → 槽 0x3f1064 → 0x1f85e4（GV_ViewVspeed(CInstance*, int, RValue*)）（0x1fdb54 取用） */
/* @0x1fe378 .word 0xfffff410 —— GOT 偏移 → 槽 0x3f1068 → 0x1fc708（SV_ViewVSpeed(CInstance*, int, RValue*)）（0x1fdb58 取用） */
/* @0x1fe37c ldrheq r5, [r5], -r8 —— pc 相对串偏移 → "view_vspeed"（0x1fdb60 取用） */
/* @0x1fe380 .word 0xfffff414 —— GOT 偏移 → 槽 0x3f106c → 0x1f8638（GV_ViewObject(CInstance*, int, RValue*)）（0x1fdb74 取用） */
/* @0x1fe384 .word 0xfffff418 —— GOT 偏移 → 槽 0x3f1070 → 0x1fc770（SV_ViewObject(CInstance*, int, RValue*)）（0x1fdb78 取用） */
/* @0x1fe388 andseq r5, r5, r4, lsr #7 —— pc 相对串偏移 → "view_object"（0x1fdb80 取用） */
/* @0x1fe38c .word 0xfffff41c —— GOT 偏移 → 槽 0x3f1074 → 0x1f8b18（GV_ViewSurfaceID(CInstance*, int, RValue*)）（0x1fdb94 取用） */
/* @0x1fe390 .word 0xfffff420 —— GOT 偏移 → 槽 0x3f1078 → 0x1fc7d8（SV_ViewSurfaceID(CInstance*, int, RValue*)）（0x1fdb98 取用） */
/* @0x1fe394 mulseq r5, r0, r3 —— pc 相对串偏移 → "view_surface_id"（0x1fdba0 取用） */
/* @0x1fe398 .word 0xfffff424 —— GOT 偏移 → 槽 0x3f107c → 0x1f8b6c（GV_ViewCamera(CInstance*, int, RValue*)）（0x1fdbb4 取用） */
/* @0x1fe39c .word 0xfffff428 —— GOT 偏移 → 槽 0x3f1080 → 0x1fc840（SV_ViewCamera(CInstance*, int, RValue*)）（0x1fdbb8 取用） */
/* @0x1fe3a0 andseq r5, r5, r0, lsl #7 —— pc 相对串偏移 → "view_camera"（0x1fdbc0 取用） */
/* @0x1fe3a4 .word 0xfffff42c —— GOT 偏移 → 槽 0x3f1084 → 0x1fa010（GV_MouseX(CInstance*, int, RValue*)）（0x1fdbd4 取用） */
/* @0x1fe3a8 andseq r5, r5, r0, ror r3 —— pc 相对串偏移 → "mouse_x"（0x1fdbd8 取用） */
/* @0x1fe3ac .word 0xfffff430 —— GOT 偏移 → 槽 0x3f1088 → 0x1fa048（GV_MouseY(CInstance*, int, RValue*)）（0x1fdbf0 取用） */
/* @0x1fe3b0 andseq r5, r5, r12, asr r3 —— pc 相对串偏移 → "mouse_y"（0x1fdbf4 取用） */
/* @0x1fe3b4 .word 0xfffff434 —— GOT 偏移 → 槽 0x3f108c → 0x1fa080（GV_MouseButton(CInstance*, int, RValue*)）（0x1fdc0c 取用） */
/* @0x1fe3b8 .word 0xfffff438 —— GOT 偏移 → 槽 0x3f1090 → 0x1fb404（SV_MouseButton(CInstance*, int, RValue*)）（0x1fdc10 取用） */
/* @0x1fe3bc andseq r5, r5, r4, asr #6 —— pc 相对串偏移 → "mouse_button"（0x1fdc18 取用） */
/* @0x1fe3c0 .word 0xfffff43c —— GOT 偏移 → 槽 0x3f1094 → 0x1fa0b8（GV_MouseLastButton(CInstance*, int, RValue*)）（0x1fdc2c 取用） */
/* @0x1fe3c4 .word 0xfffff440 —— GOT 偏移 → 槽 0x3f1098 → 0x1fb3b8（SV_MouseLastButton(CInstance*, int, RValue*)）（0x1fdc30 取用） */
/* @0x1fe3c8 andseq r5, r5, r4, lsr r3 —— pc 相对串偏移 → "mouse_lastbutton"（0x1fdc38 取用） */
/* @0x1fe3cc .word 0xfffff444 —— GOT 偏移 → 槽 0x3f109c → 0x1fa0f0（GV_KeyboardKey(CInstance*, int, RValue*)）（0x1fdc4c 取用） */
/* @0x1fe3d0 .word 0xfffff448 —— GOT 偏移 → 槽 0x3f10a0 → 0x1fb498（SV_KeyboardKey(CInstance*, int, RValue*)）（0x1fdc50 取用） */
/* @0x1fe3d4 andseq r5, r5, r8, lsr #6 —— pc 相对串偏移 → "keyboard_key"（0x1fdc58 取用） */
/* @0x1fe3d8 .word 0xfffff44c —— GOT 偏移 → 槽 0x3f10a4 → 0x1fa124（GV_KeyboardLastKey(CInstance*, int, RValue*)）（0x1fdc6c 取用） */
/* @0x1fe3dc .word 0xfffff450 —— GOT 偏移 → 槽 0x3f10a8 → 0x1fb450（SV_KeyboardLastKey(CInstance*, int, RValue*)）（0x1fdc70 取用） */
/* @0x1fe3e0 andseq r5, r5, r8, lsl r3 —— pc 相对串偏移 → "keyboard_lastkey"（0x1fdc78 取用） */
/* @0x1fe3e4 .word 0xfffff454 —— GOT 偏移 → 槽 0x3f10ac → 0x1fa158（GV_KeyboardLastChar(CInstance*, int, RValue*)）（0x1fdc8c 取用） */
/* @0x1fe3e8 .word 0xfffff458 —— GOT 偏移 → 槽 0x3f10b0 → 0x1fa7fc（SV_KeyboardLastChar(CInstance*, int, RValue*)）（0x1fdc90 取用） */
/* @0x1fe3ec andseq r5, r5, r12, lsl #6 —— pc 相对串偏移 → "keyboard_lastchar"（0x1fdc98 取用） */
/* @0x1fe3f0 .word 0xfffff45c —— GOT 偏移 → 槽 0x3f10b4 → 0x1fa1a4（GV_KeyboardString(CInstance*, int, RValue*)）（0x1fdcac 取用） */
/* @0x1fe3f4 .word 0xfffff460 —— GOT 偏移 → 槽 0x3f10b8 → 0x1fa840（SV_KeyboardString(CInstance*, int, RValue*)）（0x1fdcb0 取用） */
/* @0x1fe3f8 andseq r5, r5, r0, lsl #6 —— pc 相对串偏移 → "keyboard_string"（0x1fdcb8 取用） */
/* @0x1fe3fc .word 0xfffff464 —— GOT 偏移 → 槽 0x3f10bc → 0x1f874c（GV_CursorSprite(CInstance*, int, RValue*)）（0x1fdccc 取用） */
/* @0x1fe400 .word 0xfffff468 —— GOT 偏移 → 槽 0x3f10c0 → 0x1fb644（SV_CursorSprite(CInstance*, int, RValue*)）（0x1fdcd0 取用） */
/* @0x1fe404 ldrsheq r5, [r5], -r0 —— pc 相对串偏移 → "cursor_sprite"（0x1fdcd8 取用） */
/* @0x1fe408 .word 0xfffff46c —— GOT 偏移 → 槽 0x3f10c4 → 0x1f868c（GV_ShowScore(CInstance*, int, RValue*)）（0x1fdcec 取用） */
/* @0x1fe40c .word 0xfffff470 —— GOT 偏移 → 槽 0x3f10c8 → 0x1fb4e0（SV_ShowScore(CInstance*, int, RValue*)）（0x1fdcf0 取用） */
/* @0x1fe410 andseq r5, r5, r0, ror #5 —— pc 相对串偏移 → "show_score"（0x1fdcf8 取用） */
/* @0x1fe414 .word 0xfffff474 —— GOT 偏移 → 槽 0x3f10cc → 0x1f86cc（GV_ShowLives(CInstance*, int, RValue*)）（0x1fdd0c 取用） */
/* @0x1fe418 .word 0xfffff478 —— GOT 偏移 → 槽 0x3f10d0 → 0x1fb564（SV_ShowLives(CInstance*, int, RValue*)）（0x1fdd10 取用） */
/* @0x1fe41c andseq r5, r5, r12, asr #5 —— pc 相对串偏移 → "show_lives"（0x1fdd18 取用） */
/* @0x1fe420 .word 0xfffff47c —— GOT 偏移 → 槽 0x3f10d4 → 0x1f870c（GV_ShowHealth(CInstance*, int, RValue*)）（0x1fdd2c 取用） */
/* @0x1fe424 .word 0xfffff480 —— GOT 偏移 → 槽 0x3f10d8 → 0x1fb5d4（SV_ShowHealth(CInstance*, int, RValue*)）（0x1fdd30 取用） */
/* @0x1fe428 ldrheq r5, [r5], -r8 —— pc 相对串偏移 → "show_health"（0x1fdd38 取用） */
/* @0x1fe42c .word 0xfffff484 —— GOT 偏移 → 槽 0x3f10dc → 0x1fa1c4（GV_CaptionScore(CInstance*, int, RValue*)）（0x1fdd4c 取用） */
/* @0x1fe430 .word 0xfffff488 —— GOT 偏移 → 槽 0x3f10e0 → 0x1f8850（SV_CaptionScore(CInstance*, int, RValue*)）（0x1fdd50 取用） */
/* @0x1fe434 andseq r5, r5, r4, lsr #5 —— pc 相对串偏移 → "caption_score"（0x1fdd58 取用） */
/* @0x1fe438 .word 0xfffff48c —— GOT 偏移 → 槽 0x3f10e4 → 0x1fa1e8（GV_CaptionLives(CInstance*, int, RValue*)）（0x1fdd6c 取用） */
/* @0x1fe43c .word 0xfffff490 —— GOT 偏移 → 槽 0x3f10e8 → 0x1f887c（SV_CaptionLives(CInstance*, int, RValue*)）（0x1fdd70 取用） */
/* @0x1fe440 mulseq r5, r4, r2 —— pc 相对串偏移 → "caption_lives"（0x1fdd78 取用） */
/* @0x1fe444 .word 0xfffff494 —— GOT 偏移 → 槽 0x3f10ec → 0x1fa20c（GV_CaptionHealth(CInstance*, int, RValue*)）（0x1fdd8c 取用） */
/* @0x1fe448 .word 0xfffff498 —— GOT 偏移 → 槽 0x3f10f0 → 0x1f88a8（SV_CaptionHealth(CInstance*, int, RValue*)）（0x1fdd90 取用） */
/* @0x1fe44c andseq r5, r5, r4, lsl #5 —— pc 相对串偏移 → "caption_health"（0x1fdd98 取用） */
/* @0x1fe450 .word 0xfffff49c —— GOT 偏移 → 槽 0x3f10f4 → 0x1f87cc（GV_Fps(CInstance*, int, RValue*)）（0x1fddac 取用） */
/* @0x1fe454 andseq r5, r5, r8, ror r2 —— pc 相对串偏移 → "fps"（0x1fddb0 取用） */
/* @0x1fe458 .word 0xfffff4a0 —— GOT 偏移 → 槽 0x3f10f8 → 0x1f880c（GV_FpsReal(CInstance*, int, RValue*)）（0x1fddc8 取用） */
/* @0x1fe45c andseq r5, r5, r0, ror #4 —— pc 相对串偏移 → "fps_real"（0x1fddcc 取用） */
/* @0x1fe460 .word 0xfffff4a4 —— GOT 偏移 → 槽 0x3f10fc → 0x1fa27c（GV_CurrentTime(CInstance*, int, RValue*)）（0x1fdde4 取用） */
/* @0x1fe464 andseq r5, r5, r0, asr r2 —— pc 相对串偏移 → "current_time"（0x1fdde8 取用） */
/* @0x1fe468 .word 0xfffff4a8 —— GOT 偏移 → 槽 0x3f1100 → 0x1fa2b0（GV_CurrentYear(CInstance*, int, RValue*)）（0x1fde00 取用） */
/* @0x1fe46c andseq r5, r5, r4, asr #4 —— pc 相对串偏移 → "current_year"（0x1fde04 取用） */
/* @0x1fe470 .word 0xfffff4ac —— GOT 偏移 → 槽 0x3f1104 → 0x1fa2f0（GV_CurrentMonth(CInstance*, int, RValue*)）（0x1fde1c 取用） */
/* @0x1fe474 andseq r5, r5, r8, lsr r2 —— pc 相对串偏移 → "current_month"（0x1fde20 取用） */
/* @0x1fe478 .word 0xfffff4b0 —— GOT 偏移 → 槽 0x3f1108 → 0x1fa32c（GV_CurrentDay(CInstance*, int, RValue*)）（0x1fde38 取用） */
/* @0x1fe47c andseq r5, r5, r12, lsr #4 —— pc 相对串偏移 → "current_day"（0x1fde3c 取用） */
/* @0x1fe480 .word 0xfffff4b4 —— GOT 偏移 → 槽 0x3f110c → 0x1fa364（GV_CurrentWeekday(CInstance*, int, RValue*)）（0x1fde54 取用） */
/* @0x1fe484 andseq r5, r5, r12, lsl r2 —— pc 相对串偏移 → "current_weekday"（0x1fde58 取用） */
/* @0x1fe488 .word 0xfffff4b8 —— GOT 偏移 → 槽 0x3f1110 → 0x1fa39c（GV_CurrentHour(CInstance*, int, RValue*)）（0x1fde70 取用） */
/* @0x1fe48c andseq r5, r5, r0, lsl r2 —— pc 相对串偏移 → "current_hour"（0x1fde74 取用） */
/* @0x1fe490 .word 0xfffff4bc —— GOT 偏移 → 槽 0x3f1114 → 0x1fa3d4（GV_CurrentMinute(CInstance*, int, RValue*)）（0x1fde8c 取用） */
/* @0x1fe494 andseq r5, r5, r4, lsl #4 —— pc 相对串偏移 → "current_minute"（0x1fde90 取用） */
/* @0x1fe498 .word 0xfffff4c0 —— GOT 偏移 → 槽 0x3f1118 → 0x1fa40c（GV_CurrentSecond(CInstance*, int, RValue*)）（0x1fdea8 取用） */
/* @0x1fe49c ldrsheq r5, [r5], -r8 —— pc 相对串偏移 → "current_second"（0x1fdeac 取用） */
/* @0x1fe4a0 .word 0xfffff4c4 —— GOT 偏移 → 槽 0x3f111c → 0x1f88d4（GV_EventType(CInstance*, int, RValue*)）（0x1fdec4 取用） */
/* @0x1fe4a4 andseq lr, r4, r12, lsr #9 —— pc 相对串偏移 → "event_type"（0x1fdec8 取用） */
/* @0x1fe4a8 .word 0xfffff4c8 —— GOT 偏移 → 槽 0x3f1120 → 0x1f8914（GV_EventNumber(CInstance*, int, RValue*)）（0x1fdee0 取用） */
/* @0x1fe4ac ldrsbeq r5, [r5], -r0 —— pc 相对串偏移 → "event_number"（0x1fdee4 取用） */
/* @0x1fe4b0 .word 0xfffff4cc —— GOT 偏移 → 槽 0x3f1124 → 0x1f8954（GV_EventObject(CInstance*, int, RValue*)）（0x1fdefc 取用） */
/* @0x1fe4b4 andseq r5, r5, r4, asr #3 —— pc 相对串偏移 → "event_object"（0x1fdf00 取用） */
/* @0x1fe4b8 .word 0xfffff4d0 —— GOT 偏移 → 槽 0x3f1128 → 0x1f8994（GV_EventAction(CInstance*, int, RValue*)）（0x1fdf18 取用） */
/* @0x1fe4bc ldrheq r5, [r5], -r8 —— pc 相对串偏移 → "event_action"（0x1fdf1c 取用） */
/* @0x1fe4c0 .word 0xfffff4d4 —— GOT 偏移 → 槽 0x3f112c → 0x1f89d4（GV_SecureMode(CInstance*, int, RValue*)）（0x1fdf34 取用） */
/* @0x1fe4c4 andseq r5, r5, r12, lsr #3 —— pc 相对串偏移 → "secure_mode"（0x1fdf38 取用） */
/* @0x1fe4c8 .word 0xfffff4d8 —— GOT 偏移 → 槽 0x3f1130 → 0x1f89ec（GV_ErrorOccurred(CInstance*, int, RValue*)）（0x1fdf50 取用） */
/* @0x1fe4cc .word 0xfffff4dc —— GOT 偏移 → 槽 0x3f1134 → 0x1f8a2c（SV_ErrorOccurred(CInstance*, int, RValue*)）（0x1fdf54 取用） */
/* @0x1fe4d0 mulseq r5, r8, r1 —— pc 相对串偏移 → "error_occurred"（0x1fdf5c 取用） */
/* @0x1fe4d4 .word 0xfffff4e0 —— GOT 偏移 → 槽 0x3f1138 → 0x1fa230（GV_ErrorLast(CInstance*, int, RValue*)）（0x1fdf70 取用） */
/* @0x1fe4d8 .word 0xfffff4e4 —— GOT 偏移 → 槽 0x3f113c → 0x1f8a6c（SV_ErrorLast(CInstance*, int, RValue*)）（0x1fdf74 取用） */
/* @0x1fe4dc andseq r5, r5, r8, lsl #3 —— pc 相对串偏移 → "error_last"（0x1fdf7c 取用） */
/* @0x1fe4e0 .word 0xfffff4e8 —— GOT 偏移 → 槽 0x3f1140 → 0x1f8a98（GV_GamemakerRegistered(CInstance*, int, RValue*)）（0x1fdf90 取用） */
/* @0x1fe4e4 andseq r5, r5, r8, ror r1 —— pc 相对串偏移 → "gamemaker_registered"（0x1fdf94 取用） */
/* @0x1fe4e8 andseq r5, r5, r4, ror r1 —— pc 相对串偏移 → "gamemaker_pro"（0x1fdfb0 取用） */
/* @0x1fe4ec .word 0xfffff4ec —— GOT 偏移 → 槽 0x3f1144 → 0x1f8ad8（GV_ApplicationSurface(CInstance*, int, RValue*)）（0x1fdfc8 取用） */
/* @0x1fe4f0 andseq r5, r5, r8, ror #2 —— pc 相对串偏移 → "application_surface"（0x1fdfcc 取用） */
/* @0x1fe4f4 .word 0xfffff4f0 —— GOT 偏移 → 槽 0x3f1148 → 0x1f878c（GV_FontTexturePageSize(CInstance*, int, RValue*)）（0x1fdfe4 取用） */
/* @0x1fe4f8 .word 0xfffff4f4 —— GOT 偏移 → 槽 0x3f114c → 0x1fa254（SV_FontTexturePageSize(CInstance*, int, RValue*)）（0x1fdfe8 取用） */
/* @0x1fe4fc andseq r5, r5, r12, asr r1 —— pc 相对串偏移 → "font_texture_page_size"（0x1fdff0 取用） */
