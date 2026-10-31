# Claims 对新标准的合规审计（只读，不改账）

标准来源：reverse-toolkit `db/SCHEMA.md` §1「状态词是门，body 才是证文」，2026-10-31 收紧后的四态判定条件。

生成：`python3 scripts/claim_standard_audit.py`。本文件不改任何 claim 的 status，只给出机器分类与样本，供决定降级/补证据。

## 总量

| 项 | 数 |
| --- | --- |
| 原始行（全部 claims*.jsonl，含根部的聚合文件） | 1762 |
| **去重后 claims（权威总数）** | **1742** |
| 文件数 | 91 |
| 重复 id（一条在多文件里出现） | 20 |
| 正文分类：device / behavior / static / naked | 87 / 694 / 898 / 63 |

## 按 status × 正文分类

| status | device | behavior | static | naked |
| --- | --- | --- | --- | --- |
| `proven` | 81 | 591 | 759 | 42 |
| `narrowed` | 2 | 51 | 57 | 7 |
| `refuted` | 1 | 3 | 6 | 1 |
| `inferred` | 0 | 3 | 4 | 0 |
| `open` | 3 | 46 | 72 | 13 |

## 判定（按标准读）

- proven 属静态事实（可复查地址，非运行结果）：**759**
- proven 待降 narrowed（正文断言行为、证据只有地址）：**591**
- open 占位（符合）：**134**
- narrowed 仅地址/无装置（标准要求写明证到哪面）：**115**
- proven 合格（有装置）：**81**
- proven 无判据 → 按 open：**42**
- refuted 仅地址（缺反例判据）：**10**
- narrowed 有装置：**2**
- refuted 有反例装置：**1**

## 样本（每桶最多 3 条，用来挑战分类）


### inferred × behavior

- `BMOT-014`（Builtins_Motion.c）sign 的两个边界按 ARM VFP 规则推：比较是与 +0.0 做的 ⇒ -0.0 走「非负」路返回 +0.0；NaN 时 VCMP 置 N=0,Z=0,C=1,V=1，blt
- `CSI-018`（CInstance_Setters.c）SetDirection 的 ±inf 会死循环、NaN 会直通：第二条 while 的退出条件是 d <= 360.0f，inf-360 仍为 inf ⇒ bgt 恒真；NaN 
- `BY-015`（RoomDestruct.c）Room_Add 路径创建的房间每次销毁都会漏掉 96 B 容器 + 两块 4 B 子表：CreateWADStorage 只写 +0xac/+0xb0/+0x58/+0x5c，而

### inferred × static

- `IBI-014`（Builtins_Instance.c）g_InstanceActivateDeactive(0x542a4c) 是 List<CInstance*>（{ptr,cap,count} 12 字节），4 个开关函数都往里追
- `AUB-010`（Builtins_AudioPart.c）颜色三槽 +0x7c/+0x80/+0x84 由 +0x78 的模式字选择：ParticleType_Color1 写 +0x78=0、Color2 写 1、Color3 写 2 
- `ANON268FB4-12`（anon_268fb4.c）上下文说的「6 处 bl 指向」= 区间内 5 处自递归（0x26bcd4/0x26be20/0x26bfb0/0x26c480/0x26c8c8）+ 区间外 1 处；外部那 1 

### narrowed × behavior

- `HANDLER-A10`（DoSet.c）K=12/13 走 JS 抽象相等 helper（e2424 JS_Global_abstractEqualityComparison(&res,右,左)），随后按返回 RValu
- `HANDLER-A11`（DoSet.c）K=11 判为「左操作数 in 右操作数」的属性存在性测试：右操作数 tag 必须 ==6（对象）否则 e26e4 JSThrowTypeError；左操作数经 e3a80 F_J
- `CSER-010`（CRoom_Serialise.c）实例链的排序键不对称：链上存的是插入时的快照 CInstance+0x184，比较时对新实例取实时 depth +0x180（Serialise 侧 0x1aacbc-0x1aac

### narrowed × device

- `AUD-001`（Audio.c）Audio.c 现在 8 节齐全、2,326 条锚点（8 段互不连续区间，无一条缺失指令）。§1 Audio_Quit 与 §2 Audio_Tick 是前一批写成的正文级语义；§
- `NEG-ORA-010`（DoNeg.c）DoNeg 的 mode 1（通用取负：boxType → F_JS_ToNumber → 取负，NaN 规范成 0x7FFFFFFF_FFFFFFFF）与 mode 2（纯数值化

### narrowed × naked

- `CSI-011`（CInstance_Setters.c）SetID 与 id→实例索引的关系（旁证，扫描为下界）：按 GOT 0x3edc4c 的两种 pc 相对 idiom（ldr[pc,#imm]+ldr[pc,rX]、add pc
- `ANON26-007`（anon_26f1e8.c）第 3 / 第 4 实参（r2/r3）是跨递归不变量：各只有 1 个写点（0x26f200 str r2,[sp,#0x1c]、0x26f25c str r3,[sp,#0x18]
- `ANONBATCH2-28`（anon_batch2.c）库身份只到 narrowed：本卡提到的 pcre / ogg-vorbis / spine / jpeg 全部由「调用点具名符号 + 常数表 + 邻接」三方定位（§3 的 +0x

### narrowed × static

- `HANDLER-A12`（DoSet.c）K=7..10 是 JS 抽象关系比较慢路径：e20cc JS_Global_abstractRelationalComparison(&res, 右, 左, false) —— 
- `HANDLER-A18`（DoSet.c）e26f0-e2888 存在一段「类型字节归一化」：把 16B RValue 的实际 tag 折回紧凑编码（and #0xF0 + orr #2/#3/#6/#48/#96/#24
- `BATCHAA-11`（CLayerManager_DuplicateRoomLayers.c）type3 的 +0x1c 复合块布局：+0x00 = 记录数 n、+0x04 = 记录区首址(= 块基址+4+n*4)、随后 n 个 4 字节指针槽、再 n 个 48 字节记录（

### open × behavior

- `CDS-014`（CRoom_DeSerialise.c）本函数不清零 CRoom+0xb8（tile 计数）就进入 tile 循环：它把容量置成 n 后靠 AddTile 在 [count] 处追加。对 +0xb8 != 0 的既有房间
- `HOTHER-013`（HandleOther.c）未解：byte 0x5428E8（DoBreak 卡命名 g_isZeus）为什么会决定视口矩形走相机矩阵还是直读 view 字段 —— 一个调试器在线标志不该改变几何来源；也可能
- `CIAS-012`（CInstance_Assign.c）RValue kind 3/8/11/14 的类型名未定：本卡只证到行为（3/8 只抄指针、11/14 按 8 字节值拷贝、1/2 是引用计数、7 是实例根登记）；另 +0x0b0

### open × device

- `CDS-015`（CRoom_DeSerialise.c）因为 CDS-007 的逐条回退，读档后 room_maxtileid 不会被抬到流里 tile id 的最大值；下次 AddTile 产生的 id 会与流里已存在的 tile i
- `PNGG-019`（anon_2a7e2c_group.c）index 口径要修：三个 index-*.tsv 与全库 instructions.jsonl 都按 ARM 模式（asm_index.py 的 --triple=armv7-l
- `BATCHBM-22`（libpng_read.c）本卡正确性的唯一可用口径是「对 asm/index-libpng_read_all.tsv 逐字一致」（check_card_anchors → 1529/1529 EXACT）。

### open × naked

- `BMOT-017`（Builtins_Motion.c）open（未钉）：instance_number 的「相加」是否导致重复计数 —— objgm+0xd0 链与全局列表 0x542a64 何时同时非空未证；0x542a64 的身份
- `BMOT-018`（Builtins_Motion.c）open（未钉）：instance_activate_region 的回调 InstanceRegionActivate(0x10a390) 只解到「与静态区比较 + 两闸 + 追
- `BM2-011`（Builtins_Misc2.c）遗留未证（open）：Command_Bounce 0x1cafa0（660 B）四向命中的 8 种组合判据与 35 步角度扫描的步长/终止条件未逐条展开；SwitchRoom 对

### open × static

- `CDS-013`（CRoom_DeSerialise.c）视野记录 +0x28..+0x40 七个 int 只证到『都是 int、都在 +0x24 的 float 之后连续落位』，语义未命名（Draw_Room 不在这些偏移上读）
- `CDS-016`（CRoom_DeSerialise.c）bRegister == 0 时实例只进链、不进 ms_ID2InstanceE、也不进 CLayerManager；谁在这种情况下补建 ID 索引与层注册，本卡未找到
- `CDS-017`（CRoom_DeSerialise.c）CRoom+0x44（字节，读类型 6 后 strb，位置在 8 背景之后、8 视野之前）与 CRoom+0x00（CRoom::AddTile 结束时写入最新 tile 下标）的

### proven × behavior

- `HANDLER-A01`（DoSet.c）DoSet 不是「把栈顶写入变量槽」的赋值处理器：1863 条指令里没有 100000/99328 基址算术、没有 lsl #4 的 16 字节槽步长、没有 Code_Variab
- `HANDLER-A04`（DoSet.c）两个操作数都由 boxType(RValue& dst, eVM_Type t, uchar* sp) 装箱，返回值是消耗后的 sp；类型码与栈上宽度：0=8B double、1=
- `HANDLER-A05`（DoSet.c）栈效果固定为 pop 两个操作数、push 一个 4 字节整数：r4 = sp + size(右)，r7 = r4 + size(左)，sp_new = r7 - 4（e226c）

### proven × device

- `CN-001`（Call_Normal.c）Call_Normal 的 729 条锚点（727 真指令 + 2 个池字）与 asm/index-Call_Normal.tsv 逐字一致：check_card_anchors.
- `CNS-001`（Call_Normal_std.c）Call_Normal_std 的 729 条锚点与 index-Call_Normal_std.tsv 逐字一致：index=729 card=729 missing=0 ext
- `DC-001`（DLL_Call.c）DLL_Call 的 128 条锚点与 index-DLL_Call.tsv 逐字一致：index=128 card=128 missing=0 extra=0 mismatch=

### proven × naked

- `X-001`（四卡）这四张卡覆盖的四个函数（Call_Normal / Call_Normal_std / Call_RValue / DLL_Call）都是 .dynsym 里的 GLOBAL DE
- `X-002`（四卡）分工边界：字节码侧 DoCall(0xe8b48)/DoCallScript(0xe8588)/DoCallLibrary(0xe3e58) 用 VM 栈上的 RValue 串与 
- `X-003`（Call_Normal_std.c）旁证（无逐条卡）：Call_Real(0x21161c) 与 Call_Real_std(0x21012c) 同为 2444 B/611 条，块顺序被重排，指令多重集只差 1 条 

### proven × static

- `HANDLER-A02`（DoSet.c）opcode 参数位域：K=(arg>>8)&0xF 是算子号（1..6 见下）；T=(arg>>16)&0xFF 给两个操作数的静态类型，低半字节=栈顶（最后压入，右）操作数、高
- `HANDLER-A03`（DoSet.c）DoSet 分派树：K∈[7,10] → 泛型装箱比较（{8,9}→e2050，{7,10}→e21d4）；K∈{12,13}→e23bc；K∈{14,15}→e2570；K==1
- `HANDLER-A06`（DoSet.c）K=1..6 就是六个比较算子：1=<, 2=<=, 3===, 4=!=, 5=>=, 6=>。两个互相独立的证人：(a) double,double 路径先算 左-右 再与 ±

### refuted × behavior

- `LH-022`（LayerHelpers.c）（被反证）CLayerManager_AddInstance 卡正文第 22 行称「0x5428e8 字节非 0 → 直接返回」。机器码 1c5d2c ldrb r3,[r3] /
- `ADD-002`（DoAdd.c）撤回：早先写「DoAdd 全程只有 vadd.f64、整数一律提升成 double、没有整型加法」是错的。实际是双路：实数走 vadd.f64（7 处）；整数走三处内联 64 位加
- `TOI32-010`（F_JS_ToInt32.c）"F_JS_ToInt32 只做饱和、不做 2^32 取模"的读法不成立：取模确实存在，只是发生在 0x24d6c0 mov r1,#0（丢弃 int64 高字）而不是掩码/循环；

### refuted × device

- `NEG-ORA-007`（DoNeg.c）cls 6 的错误串逐字为 "DoNeg :: Execution Engine - Cannot operate on string type"（双冒号、**没有** ":1:"

### refuted × naked

- `ROOMCHAIN-002`（DoSlowDrawRoom.c）早先『绘制链 +0x84 / 步进链 +0x80 是两条链』的说法作废：它们是同一条链的头与尾；已回改 DoSlowDrawRoom/DoAStep/DoPushEnv/Start

### refuted × static

- `CEG-003`（Builtins_Misc2.c / Command_Change.c）【已推翻】早先说 Command_RestartGame 0x1c9f54 是 208 字节并写 -201，实测不成立： 该函数 size **88**、指令里是 `mvn r1,
- `ARB-010`（Builtins_DsString.c）**ds_map 的键是 RValue，不是字符串** —— CDS_Map::Find 开头按 tag 六路分派算哈希：字符串（tag1）用 CalcCRC_string(tex
- `BM2-006`（Builtins_Misc2.c）claims-batchAJ 的 CEG-003 说「Command_RestartGame 0x1c9f54（208 字节）把 New_Room 写成 -201」与二进制不符：本

## 怎么用这份审计

1. `proven × behavior` 是唯一需要立刻动的桶：正文断言运行期行为，证据只有指令地址。要么补一个装置（oracle/harness/seed/回执），要么把 status 降到 `narrowed` 并在正文写明「只证到静态字节，未证运行」。
2. `proven × static` 不是错，但只能当 `bytecode_anchored` 层引用，不得被下游当作行为门。
3. `refuted × 仅地址` 要补反例判据或指向被推翻条目，否则按 `open`。
4. 本工具不改账：降级是账本所有者的动作，改完须重跑 `verify_reverse_v1.py`。

