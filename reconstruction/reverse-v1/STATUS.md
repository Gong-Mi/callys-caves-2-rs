# 状态与定性（2026-10-28 收手点）

一句话：**引擎的语义骨架已经定性完，剩下的是外围（12 张 init 表、约 600 个匿名段、库内部）。**
方法已钉死在 `METHOD.md`，接手的人不需要重新吵怎么算数。

## 账

    cards                173 张全部已提交（INIT 5 张 / Audio 8 节 / GateBytes / Reach_01-02）；多节卡按 @func 算 469 节
    anchors              143,430 条，全部 RESULT EXACT
    跨卡共享地址          0
    claims               1,723 条（proven 1,456 / narrowed 116 / open 137 / refuted 7 / inferred 7）
    指令基线             649,229（Thumb 双遍解码）
    函数                 9,538 具名 + 272 匿名块 → 636 段
    覆盖口径（**已更正**） 分母 = 可达集 1,439 个函数 / 148,233 条指令（scripts/reachability.py --dump）。
                         已落锚指令 59,289 = 40.0%；整函数全锚 187 个（13.0%）；余 88,944 条指令。
                         ⚠ 旧口径（63.6% → 78.4% → 87.6%）是错的：分子取了全库所有 @func 起址（含不可达的
                         库函数），分母只用可达字节数，两边不是同一集合，数值系统性偏高。旧数字一律作废，
                         以后只报这一行。

## 已定性（有卡、有锚点、能指名到函数）

    VM 骨架        opcode 表（.data 0x3f20b4，32 项）｜线程化派发（VMExec+0x58 → blx）
                   48 个 Do* 处理器｜Code_Execute / ExecuteIt / VM::Exec / ExecRelease / PerformReturn
    值模型        RValue 16 B、tag 在 +12、0..14（0/13 real、1 string、2 array、3 pointer、5 undefined、
                   7 int32、10 int64、12 null、0x00FFFFFF = 未解析变量）
    变量系统      id 基址 100000、槽步长 16｜局部 self+4 / 全局 GOT 单例+4 / 实例 hash=key+1
                   Variable_GetValue/SetValue/GetObjectName/BuiltIn_Add/GetName_Scope/Global_Init
    调用帧        frame=sp-60；+0 pc、+0x08 旧 Argument、+0x38 旧 sp 偏移、+0x4c 深度
    函数表        80 B/项（name 内联 64B / fn +0x40 / argc +0x44 / flag +0x48 / +0x4c -1）；
                   InitYoYoFunctions 385 条（平台层，与游戏用的 87 个无交集）
    常量池        INITIALIZE_Code_Constant = GML 命名常量池（513 次调用→501 名，启动期 606）
    内建变量      InitGlobalVariables 120 + 5 = 125 个；实例侧 80 个字段（12 alarm + 68）
    房间/层       CRoom 292 B 字段表｜两链 +0x84 头/+0x80 尾/+0x17c next/+0x178 prev｜
                   CLayer 112 B + 三张 CHashMap｜层链按 +0x04 升序
    实例          CInstance 432 B 完整初值表｜两链搬运 UpdateActive｜bbox = int32 tagYYRECT
    事件          Perform_Event → Perform_Event_Object → Perform_Event_All 三层；Other 四趟
    绘制          DrawTheRoom 条件树（+0xdc / +0xb8 / +0x88）｜DoSlowDrawRoom 三股流｜
                   快路径二分支｜清屏 flag 只有 2 位且深度与模板同一位
    资源           game.droid 头部 8 B、31 tag 块链、24 个处理点｜WAD 地址 0x544c44
    存档          18 段（Command_SaveGame）｜CRoom/CInstance 序列化逐项互逆、丢字段清单
    JNI           JNIEnv 只存 TLS（0x756c04）、无 GetJavaVM、jclass 0x756d44、79 个方法 ID 与 DEX 79/79
    ISA           563 个 Thumb-2 具名函数 + 14 个匿名段（调用点编码证明）
    静态库        Box2D 2.3.0｜PCRE 8.34+ 的 8.x（版本串是构建模板）｜zlib 1.2.3 动态｜
                   libpng 1.4.19｜libjpeg｜spine-c｜freealut｜vorbisfile

## 未定性（按重要性）

    1  ~~12 个 Init*Functions 表~~ **已收（2026-10-28 后一批）**：26 个 Init* 函数全部出卡
       （cards/InitTables_{Core,Draw3D,Resource,InputAction,System}.c），2,434 条注册逐条解出四实参，
       游戏调用的 99 个内建里 97 个已指到注册点，另 2 个（AdColony_*）本构建无实现。
       残留 open：29 条运行期实参（14 条 joystick_* 的 flag = *(u8)0x5428e8、Init3D 13 条、InitGame 1 条、
       InitResource 1 条）与「同名双注册的查找语义」
    2  匿名段：≥512 B 共 143 段 / 226,028 B；已出骨架卡 8 段（cards/anon_batch6.c，按 in-degree 取的头部：
       anon_264c00(90)/26020c(88)/262680(61)/2636d4(19)/276e68(15)/2fc4e8(5)/300004(5)/234434(4)），
       余 97 段 / 213,116 B 未出卡（最大 anon_270108 15,156 B、anon_273c3c 12,844 B、anon_303c46 12,830 B）
    3  freetype（TT_RunIns 7.8 KB）、pcre compile_branch（23.5 KB）的内部
    4  几个反复出现的未定语义：g_isZeus(0x5428e8) —— **消费面已清（cards/GateBytes.c）**：52 个点全经槽
       0x3ed92c，唯一写点 0x1dd844 在 GetResolution 内，读点覆盖 DrawTheRoom/UpdateViews/存档/StartRoom/
       InitGame 等与 14 条 joystick_* 注册的 flag；语义（取值域、是否「Zeus/高清」开关）仍 open。
       0x755363 —— 消费面 31 点（CheckLicense/全部 Audio_*/SoundHardware::Init/ProcessCommandLine），
       **本普查未发现写点**；option_use_fast_collision(0x542379) 的写者、0x47f295 门字节、
       DoSet K=7..10 的四个 JS 抽象关系算子、Shl/Shr 的 bit15 仍 open
    5  Motion_Grid_Path 的障碍编码矛盾（入口按 <0 判失败、扩展闸门按 ≤0 判入）

## 实现侧（Rust VM）

    已完成   Vec<f64> → Vec<Value>{tag,payload}；补 Rem/Mod/Or/Xor/Shl/Shr/Neg；
             Constant 带 tag；Dup/Not 带 mode；sp 按操作数宽度记字节；放开非有限值
    差分     4,400 例：identical 4,207（95.6%），剩余 193
             剩余按 op：add 63、conv 48、sub 28、div 26、mul 24、neg 3、not 1
             按轴：ok 相反 101、错误串 25、sp+bytes+tag 28、sp 19、sp+bytes 7、bytes 13
    下一步   ① conv→string 需要 host 字符串池 + snprintf ② add/sub/div 的 pair 表与 mode1
             ③ sp 装箱 54 例（flags&2 进 Op）④ 之后才谈里程碑 2 的整段轨迹差分

## 接手顺序建议

    1  12 张 init 表（每轮 4 并发，增量落盘），把 87 个 builtin 的注册点全钉住
    2  匿名段按 in-degree 吃（≥512 B 的优先）；新遇到 Thumb 用调用点编码判
    3  差分收尾 193 例
    4  freetype/pcre 内部只做接口级，不逐指令
