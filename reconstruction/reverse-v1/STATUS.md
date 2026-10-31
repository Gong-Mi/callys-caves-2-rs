# 状态与定性（2026-10-28 收手点）

一句话：**引擎的语义骨架已经定性完，剩下的是外围（12 张 init 表、约 600 个匿名段、库内部）。**
方法已钉死在 `METHOD.md`，接手的人不需要重新吵怎么算数。

## 账

    cards                245 张全部已提交；多节卡按 @func 算 9,083 节 + 3 张残段卡
    anchors              **649,229 条 = census 指令基线 100%**（每条指令恰好一张卡主张），全部 RESULT EXACT
    跨卡共享地址          0
    claims               1,742 条（proven 1,469 / narrowed 117 / open 138 / refuted 11 / inferred 7；
                         权威数以 verify_reverse_v1.py 为准，claims.jsonl 是含 20 条重复的局部聚合）
    运行期证据（新）      **4 条 oracle 臂**：DoNeg 378/378（mode 0+3..15+mode 1/2）、DoNot 404/404
                         （mode 0+3..15+mode 1）、boxType 97/97（类型 0..9 与越界）、
                         **CObjectGM::LoadFromChunk 104/104（OBJT 记录头 src+0x00..0x1f）**。
                         四臂各 5 个变异体有牙。最后一条是资源加载链上的第一个臂：字段映射是从
                         原件行为单字节扫描出来的，不是从资产文档抄的。剩余 46 个 Do* 与绝大多数
                         其它函数仍只有静态字节证据
    指令基线             649,229（Thumb 双遍解码）
    函数                 9,538 具名 + 272 匿名块 → 636 段
    覆盖口径（机械账，已闭合） asm/instructions.jsonl 的 649,229 条指令 **全部落锚**；跨卡共享地址 0。
                         可达集子账：1,439 函数 / 148,233 条 = 100%（Reach_01-14 + Anon_26f1e8）。
                                                  其余：All_15-68（54 张，可达集外的库函数）+ Residue_Attributed_01-03（17,581 条 Thumb-2 半字段，按 census 归组到 812 个具名函数）。
                         ⚠ 「每条指令都指到了」≠「每条语义都读懂了」：按卡级别（锚点发生次数口径，与严格 (addr,mnem)
                         计数的 649,229）：正文 79,473 = 12.2%，骨架 571,817 = 12.2% 之外骨架占 87.8%；
                         **桩 0 / 未标 0** —— 全部 245 张卡都已到骨架及以上；残段批已从「地址级」纠正为「按函数归属」（CSprite_SWF、anon_batch2、LibInterfaces、
                         Graphics_Interface、Stubs_TailJumps、Residue_01-03 的级别行已统一成工具可读形式）。
                         按 @func 计 正文 347 个函数 / 骨架 8,736 个。语义欠账全在骨架与桩卡里。
                         ⚠ 生成器缺陷已修（RESIDUE-001）：gen_func_cards.py 原用 4 字节步进取指令，
                         Thumb-2 函数会被漏掉一半字指令；现已改为按 instructions.jsonl 的真实地址遍历。
                         ⚠ 旧口径（63.6% → 78.4% → 87.6%）作废：分子取全库 @func（含不可达库函数）、分母只算可达字节。

## 运行期证据（oracle 臂，2026-11-01 起）

本线此前全部是 `bytecode_anchored`。现在有了第一个**原版二进制 vs C 重建**的差分臂：

    装置      reconstruction/reverse-v1/harness/{handler_oracle.py,do_neg_diff.py,do_not_diff.py}
    C 重建    reconstruction/reverse-v1/c/do_neg.c（tier: bytecode_anchored 的直译）
    判据      返回栈指针 / 16 字节槽 / VMError 文案，三面逐例全等
    输入域    seed 0xCA11，282 例；cls 0..15、tag 0..15 全覆盖 + 随机尾 120
    回执      receipts/do_neg_diff-20261101T002634.json、receipts/do_not_diff-20261101T003428.json
              （各含输入 sha256 与 C 源 sha256，重跑同结果）
    门        identity / coverage×2 / non_degenerate / teeth 全 PASS
    判别性反例 5 个 -DMUTANT 变异体分别被 2/17/20/31/14 例抓住

    由它纠正的原卡错误  DoNeg.c 段 2 把 cls 6 的文案写成 "DoNeg :1: …"，实际是 "DoNeg :: …"
                        （带 :1: 的是 cls 5 tag1）→ NEG-ORA-007 refuted；DoNot.c tag1 文案写成短式
                        "Cannot operate on string type"，实际是 "DoNot :: Execution Engine - …" → DNOT-ORA-004
    由它推翻的"合理模型" DoNot cls 0 的 ~ 不是符号翻转、也不是饱和转换：原版走
                        __fixdfdi(0x3194a0, 非饱和) → NOT → __floatdidf，实测 +Inf→-1.0、-Inf→+1.0、
                        2^63→2^63、DBL_MAX→-1.0 → DNOT-ORA-002（首轮 35 条 mismatch 抓出来的）
    装置边界            Unicorn 不建模 FPSCR.RMode，浮点→整型的舍入本装置判不了 → DNOT-ORA-005 narrowed
    由它新增的语义      tag 字是**整字比较**（无掩码），高字节非零一律 Malformed；NEG-ORA-006
    仍未覆盖            mode 1 / mode 2（需 boxType + F_JS_ToNumber 真实执行）→ NEG-ORA-010 narrowed

**怎么读这条账**：这是 1 个处理器的 1 个臂，不是 48 个处理器。其余 47 个 Do* 与全部房间/实例/
变量函数仍然只有静态字节证据。接下一个处理器的流程与门定义写在 `harness/README.md`，
新臂一律先写变异体再谈 identical。

**账本对新标准的合规性**（只读审计，不改 status）：
`reconstruction/contracts/claims-standard-audit.md`，由 `scripts/claim_standard_audit.py` 生成。
1,760 条去重 claims 里，正文带装置（oracle/harness/seed/回执）的 103 条，纯静态地址的 899 条，
**正文断言运行期行为但证据只有地址的 695 条**（这批按新标准只能当 `bytecode_anchored` 引用，
不得作行为门）。审计只给分类与样本，降级动作留给账本所有者，改完须重跑 `verify_reverse_v1.py`。

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

## 验牌（逐卡审计，2026-10-29 收口）

工具 `scripts/audit_cards.py`，账本 `reconstruction/reverse-v1/CARD-AUDIT.tsv`（每卡一行）。

    FAIL 三类  ① 无级别行 ② 锚点不在 asm/instructions.jsonl ③ @func 声明条数 ≠ 本卡在 [start,end) 里的锚点数
    不算 FAIL  partial（只覆盖函数一部分）——信息项；全库覆盖与互斥由 verify 的 anchors==649,229 / shared==0 保证
    END 约定   scripts/fix_card_metadata.py 已把所有 @func 头统一成「end 排他、size=end-start、count=本卡锚点数」

    **结果：245 张卡全部通过（244 一次过 + All_68 的一处 off-by-one 已修）**
    修的手段：150 张卡范围按自身锚点重算；68 张插入「部分覆盖: 本节 X/Y 条」；VMError 56→61；
              Reach_02 删掉已移交节的 @func；All_68 一处 10→11
    另立工具 scripts/merge_overlapping_sections.py（同函数多节可合并；本轮实测几乎无同函数重叠，未启用）
