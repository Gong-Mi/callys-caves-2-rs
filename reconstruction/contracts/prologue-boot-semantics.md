# 原版带档启动的序章重放语义（恢复 GML 静态判定 · WL14 / 2026-10-16）

面向 WL4 生命周期矩阵登记的**缺陷候选②**「每次前后台往返都重放序章——是否与原版一致待
真机/GM 对照」（`host-lifecycle-native-probe.md` §0/§3.1/§5-3）。本线只用**恢复 GML 静态
证据**还原原版「带档启动」的完整画面序列，给候选②定性。**不改生产代码**。

基线与证据基座：

- worktree `wl14-prologue-boot`，分支 `wip/wl14-prologue-boot`，基线 `origin/main` = `4783233`
- 恢复 GML：`~/cally-recovered-gml-fd6fc01/restored-source/gml/`（另 4 棵 `cally-recovered-gml-*`
  逐字节相同，见 §1）；恢复器自带 `index.json` / `objects.json` / `rooms.json` 作为**事件名与
  房号的权威映射**（不靠文件名猜事件）

## 0. 结论摘要

- **判定（序章重放语义轴）：忠实原版 —— 缺陷候选② 关线。**
  原版**带档启动同样重放序章**：读档与生成序章是 Game Start 里同一段代码的两个独立步骤，
  三份 ini 分支全部走完之后**无条件** `instance_create(x, y, obj_introduction)`
  （CODE 17：`0017__gml_Object_obj_player_Other_2.gml` l.4-294 读档 / l.1540 生成序章）。
  全树**不存在**任何 `file_exists`/进度/档位条件能让启动跳过序章；序章也**没有定时自退**，
  只有 taplock（`alarm[0] = 120` 步）过期后的**真实点按**才退场（CODE 554 l.15-21），
  退场时 `instance_activate_all()` 唤醒同一间房（CODE 549 l.1）直接进 gameplay。
  ⇒ 重写端「带档启动/往返后先看到序章、点掉后进 gameplay 且状态恢复」的**序列与触发条件
  忠实原版**，不是移植偏差。
- **残留（未关，已细化）：触发域轴。** 原版 GML 里序章的**唯一**创建点是 obj_player 的
  **Game Start**（Event 7/2，全 objects.json 唯一一个 subtype 2），语义上**每进程一次**；
  原版在同一进程内的前台恢复**不会**重建序章。而重写端把「每次 surface 重建」等同「引擎
  启动」（WL4 §3.1：每轮 nativeInit ⇒ 新 `GameState` ⇒ 重放序章）。两者是否等价取决于
  **原版 runner 的后台存活语义**（Android 后台是否杀进程、onResume 是否重跑 Game Start），
  该层**不在恢复树内**（`README.txt` 明示 runner/工程元数据不提供）⇒ 本线不冒充已验，
  把候选②从「序章重放对不对」**窄化**为宿主层登记项（见 §5）。
- **修复方向（交父代理）**：若真机证明原版往返不重放序章，修复点应在**宿主「往返不重建
  GameState」**（原版 runner 只重绑 surface、不重跑 Game Start），**不是**给序章加跳过分支
  ——后者会破坏冷启动忠实性（原版每进程启动必放序章，无例外）。

## 1. 证据基座与 SHA 核对（防树漂移）

| 对象 | 值 |
|---|---|
| 恢复 GML 树（5 棵 `cally-recovered-gml-*`）对 `0017/0548/0016/...` 的 SHA | 5 棵**逐字节相同** |
| 全树指纹 `find . -name '*.gml' \| sort \| xargs sha256sum \| sha256sum` | `36df1a110e4a2795026be9292184b4c5d307206b17d1032071118ce566a0d732`（1354 文件） |
| `index.json` 交叉核对 | 抽 3 处：id 17 / 548 / 360 的 `gml_sha256` **等于**本地 `sha256sum` ⇒ 本地文件即 index 记录 |
| 原版游戏数据 SHA256 | `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`（`restored-source/README.txt`） |
| 原版 APK / runner | APK `d608f455…`（2.1.9, `com.vdogames.callyscaves2`）/ libyoyo `3bbedd09…`——**既有登记值**（`live-oracle.md`），本线未复算 |

事件名映射（来自 `objects.json` + `index.json` 的 `event_type`/`subtype`，非文件名推断）：

- `0017` = `obj_player` **event_type 7 / subtype 2 = Game Start**（objects.json l.485-494；index.json l.479-494）
- `0016` = `obj_player` type 7 / subtype 4 = **Room Start**（index.json l.450-466）
- `0015` = `obj_player` type 7 / subtype 5 = **Room End**（存档写出，整文件无 `room_goto`，index.json l.422-438）
- `0548/0549/0550-0553/0554/0555` = `obj_introduction` Create / Destroy / Alarm 3..0 / Step / Draw
  （objects.json l.16574-16660 起逐条 `code_id` 对齐）
- `rooms.json` 首条 = id 0 `rm_town` ⇒ **房间 0 = rm_town**；其实例表首条 `object_id: 0`
  （`instance_id: 100000`）= obj_player 就摆在这间房里；`rm_town` 实例表中**没有** `object_id: 137`
  （序章不是房间摆放物）
- 全树 `obj_introduction` 出现点 **2 处**：`0017:1540` 创建、`0548:13` `instance_activate_object`
- 全树 `"type": 7, "subtype": 2`（Game Start）**只有 obj_player 一个** ⇒ 启动链只有一条

## 2. 原版启动链静态还原（带档，逐拍）

前置：`savefile.ini` 存在（带档）。以下 t 为逻辑步（alarm 以 Create 为原点）。

| 拍 | 触发 | GML 依据（file:line） | 画面 / 状态 |
|---|---|---|---|
| 0 | 房间 0 = `rm_town` 实例按放置创建（含 obj_player `instance_id 100000`） | `rooms.json` id 0；GM 首房次序见 `game-start-p0.md` §What changed 第 1 条 | 城镇就绪但还没画出来 |
| 1 | **Game Start**（唯一创建点） | `0017` l.1 `AdColony_Init` → l.2-3 `global.warpfrommap=0; global.ending=0` → **l.4 `if (file_exists("savefile.ini"))` 读 320 键** → l.295 `else if (!file_exists(...))` 写默认并落盘 → l.870-895 `savefile2.ini` → l.896-1011 `savefile3.ini` → l.1012-1539 武器伤害阶梯 → **l.1540 `instance_create(x, y, obj_introduction);`（无条件，在两分支之外）** | global 已按档恢复，随后**必然**生成序章 |
| 2 | obj_introduction **Create** (CODE 548) | l.1-11 `taplock=0; moving=1; moving2=0;` + film 初始坐标；**l.12 `instance_deactivate_all(true)`**；l.13-14 激活 `obj_introduction` / `obj_viewresolution`；l.15 `instance_create(0,0,obj_phone)`；l.16 `image_speed=0.3`；l.17 `audio_play_sound(mus_new4,0,false)`；l.18-21 `alarm[0]=120; alarm[1]=30; alarm[2]=70; alarm[3]=70` | **整间 rm_town 被冻结**（deactivated = 不 step 也不 draw，见 `game-start-p0.md` §GM semantics correction 的 libyoyo 二进制验证）→ 屏幕上只剩 film 与框架 |
| 3 | 每步 Step (CODE 554) | l.1-7 `moving==1` ⇒ `xx1..xx4 -= 2`（快滑）；l.8-14 `moving2==1` ⇒ `-= 1`（慢滑）；**l.15-21 `if (taplock == 1) { if (mouse_check_button_pressed(mb_left)) { instance_destroy(); } }`** | 海报横向滑动；taplock 前点按被**设计性吞掉** |
| 4 | 定时拍（alarm） | @30 `moving=0; moving2=1`（CODE 552）；@70 `instance_create(0,50,obj_logo)`（CODE 551）+ `moving2=0`（CODE 550）；**@120 `taplock=1`（CODE 553，全树 `taplock` 唯一写点）** | 快滑→慢滑→停；logo 出现；约 2.0s 后解锁点按 |
| 5 | 每 Draw (CODE 555 + 0547 + 0546) | `0555` l.1-2 自身 x,y 钉到 `view_xview[view_current]`；l.3-75 按 `view_current ∈ {0,1,3,4,5,6}` 摆 obj_phone（`xx1..xx4`, `y=-2/30`）与 obj_logo（`x1..x4`, `y=70`）；film 本体由 obj_phone `draw_self`（`0547` l.1）画；obj_logo 以 `logoalpha` 每 Draw `+= 0.02` 淡入（`0546` l.25）。可见 view 由 `obj_viewresolution` 的 `alarm[0]=1`（CODE 537/538）按 display 尺寸选择 | 本机 1136x640 ⇒ CODE 538 走 `view_visible[0]` 分支；`obj_introduction` 自定义了 Draw ⇒ 其 `sprite_id 161` 的默认绘制被覆盖（惰性） |
| 6 | 点按退场 → **Destroy** (CODE 549) | l.1 `instance_activate_all();` l.2 `global.health1 = 4;` l.3-16 销毁 obj_phone / obj_logo | 城镇解冻，与 film 同一场景继续 |
| 7 | gameplay | 无 `room_goto`（全树 `room_goto` 只在门/地图/结局/「返回游戏」/重置数据路径：`0013` 碰撞门、`0692` maptile、`0787` finalboss、`0470` backtogame、`0476` mapmenu、`0478` yesrestoredata、`0698` final、`0019` KeyRelease）；玩家位由房间放置 + 首帧 Room Start(CODE 16) 决定；`obj_bg` Create(CODE 360) l.12-16 把 `rm_town` 的 `global.startx/starty` 设为 416/492 | 回到**同一间 rm_town**，global 已是档里那一份 |

### 2.1 「跳过序章直接进游戏」的条件：**不存在**

- CODE 17 里 `file_exists("savefile.ini")` 只决定 global **从档来还是从默认来**（l.4 / l.295 两分支），
  序章创建在**两分支之外**（l.1540，缩进层级 = 顶层语句）。
- 序章范围内**没有**任何其他 `instance_destroy`：`0548/0549/0550/0551/0552/0553/0554/0555` 中
  `instance_destroy` 只出现 3 次——`0554:19`（点按退场，主路径）与 `0549:7,14`（Destroy 事件内
  清理 obj_phone / obj_logo）。**无定时退场**（与 `game-start-p0.md` 的
  `prologue_natural_end.rs` 断言一致：「no timer death exists; only a real tap retires the intro」）。
- 全树唯一的 Game Start 事件就是 obj_player 这一条 ⇒ 启动时**必放**序章；`rm_town` 实例表里也不
  存在预摆放的 `obj_introduction`（`rooms.json` id 0）。

### 2.2 handover 状态来源：**磁盘 ini，且在序章之前就已生效**

- 原版没有独立的「交棒」步骤，也不读内存快照：CODE 17 是**先读档（l.4-1011）后生成序章
  （l.1540）**，序章播放期间 global 已是档里那一份；`obj_introduction` Create 的
  `instance_deactivate_all(true)`（l.12）把「已恢复的城镇」冻在 film 后面，Destroy 的
  `instance_activate_all()`（`0549` l.1）把它唤醒 ⇒ 原版次序是**先恢复态、后放片**。
- 重写端次序相反：boot 时把快照压在 `pending_ir_restore`（`crates/client/src/lib.rs` 349-360
  `queue_boot_ir_restore`），直到序章 Destroy 后的 handover 才 `restore_ir_snapshot`（同文件
  646-650）。**可见结果等价由「冻结」保证**（film 期间房间不 step/draw），`game-start-p0.md`
  §What changed 第 2/3/5 条已把它写成设计契约。

## 3. 对照判定

| 轴 | 原版（本线静态证据） | 重写端（WL4/p0 实测） | 判定 |
|---|---|---|---|
| 带档启动是否放序章 | **放，且无跳过分支**（`0017:1540`） | 放（`IR boot room=0 intro=true`） | **忠实原版** |
| 退场条件 | 只有 taplock(120) 后的真实点按（`0554:15-21`） | 同（同一段 bytecode，`prologue_natural_end.rs`） | **忠实原版** |
| 退场后去哪 | 同一间 rm_town 解冻，无 `room_goto` | 同一场景 handover 到 gameplay | **忠实原版** |
| 状态来源 | 磁盘 ini，序章前生效 | ini + `pending_ir_restore`（序章后应用） | 可见等价（冻结保证）；次序差异已记录 |
| **触发频率** | 序章创建点 = Game Start = **每进程一次**；同进程前台恢复不重建 | 每轮 nativeInit（每次 surface 重建）都重放 | **静态不可判** → §5 |

**结论**：缺陷候选②按任务给定的第一条判据（「原版同样重放序章 ⇒ 忠实原版」）**成立并关线**；
但它**不能**顺带证明「每次前后台往返」也忠实——那是一个**宿主触发域**问题，本线把它从
候选②里拆出来单独登记（§5），避免用「序章语义忠实」掩盖「往返即重建引擎」这条架构差异。

## 4. 证据清单（file:line + SHA256，恢复树 `restored-source/gml/`）

| 单元 | 事件（objects.json/index.json） | 关键行 | SHA256（= index.json `gml_sha256`） |
|---|---|---|---|
| `0017__gml_Object_obj_player_Other_2.gml` | obj_player · 7/2 Game Start | l.4 读档分支；l.295 默认分支；**l.1540 生成序章** | `dc640893db3b07c6fe5ce278157d039c7223acea70e4d40133aaf8b83569a23b` |
| `0548__gml_Object_obj_introduction_Create_0.gml` | obj_introduction · 0/0 Create | l.12 `instance_deactivate_all(true)`；l.15 obj_phone；l.17 `mus_new4`；l.18-21 alarm 120/30/70/70 | `1b4d4d8cbbcbd7d112c02c25c288df1b6001c2edb3b77b5d8c8b8d658a6d2c1c` |
| `0554__gml_Object_obj_introduction_Step_0.gml` | obj_introduction · 3/0 Step | l.15-21 taplock 门 + `instance_destroy()` | `42030a1ea4d13bd2be65ae638aae6439de0f84484f1ba562dde439350288ec3d` |
| `0549__gml_Object_obj_introduction_Destroy_0.gml` | obj_introduction · 1/0 Destroy | l.1 `instance_activate_all()`；l.2 `global.health1=4` | `36698589ca9f50d61b89412dc69cf434962b3ff9b76bedb173df3b60a11922dd` |
| `0553__gml_Object_obj_introduction_Alarm_0.gml` | obj_introduction · 2/0 Alarm 0 | l.1 `taplock = 1` | `7bd9965d57abce31ae772e70d4b147bd7e29b103ec00c41d248717ff00ec64a0` |
| `0552__…Alarm_1` / `0551__…Alarm_2` / `0550__…Alarm_3` | Alarm 1/2/3 | `moving=0; moving2=1` / `instance_create(0,50,obj_logo)` / `moving2=0` | `99bef8a52863a36ac53ca4e0750dbef51ef19b2c83385c356e05369c38a09e3f` / `f7510ad0eb3c6fc287d57eb3c4a74ade367ede3509fe9690a3ba3ab6a04d097d` / `eb4bfb99228adb5dd0cc0707b8d56eab162e695fe6933ae6985809ccb685bdf8` |
| `0555__gml_Object_obj_introduction_Draw_0.gml` | obj_introduction · 8/0 Draw | l.1-2 钉 view 原点；l.3-75 按 view 索引摆位 | `1c1f81cfba91bb126537459b30119f93bd1c6b05de2a384577838103c8683d3f` |
| `0016__gml_Object_obj_player_Other_4.gml` | obj_player · 7/4 Room Start | 全室 visited 标记（rm_town ⇒ `global.roomtownvisited=1`） | `cf491067d56fd74867040e94c278b5e21d8fa7e89a1c58214b6e24149baf4061` |
| `0015__gml_Object_obj_player_Other_5.gml` | obj_player · 7/5 Room End | 每次离房全量写出 `savefile.ini`（332 行，无 `room_goto`） | `77af50de0634fca1ae4e942448af7ac70aca5d452c17876c9b34008a5651f130` |
| `0360__gml_Object_obj_bg_Create_0.gml` | obj_bg · 0/0 Create | l.12-16 rm_town `startx/starty` 常量 | `89478ec7d8207b09e879593f988ac8a5248b8df8a672641479a67d768568a25b` |
| `0000__gml_Object_obj_player_Create_0.gml` | obj_player · 0/0 Create | l.8 `global.roomcamefrom=0` 等启动期复位 | `ddc475c1f874d2c45f8bae4f639a24aff1db76ec2f6419b1270ef298d73a730d` |

映射文件：`objects.json`（对象事件/action，l.16574 起 obj_introduction）、`rooms.json`（id 0 = rm_town）、
`index.json`（CODE id ↔ 单元名 ↔ SHA ↔ owner `event_type/subtype`）。

## 5. 未验层（逐项边界，不得冒充已验）

1. **原版 runner 的后台存活语义（决定性、静态层不可判）**：本线只证「原版序章创建点唯一 =
   Game Start」。Game Start「每进程一次、房间切换/前台恢复不重发」是**GM 运行期语义**（恢复树
   只含 code 单元，`README.txt` 明示 runner 与工程元数据不提供），本线**未**在原版 runner 上
   验证。原版 APK（`d608f455…`）与 libyoyo（`3bbedd09…`）**已在本地**
   （`reconstruction/live-mem/`、`reconstruction/reverse-v1/apk/`）⇒ 该轴可静态 RE 或真机
   「按 Home 再回」对照，属后续独立工作。
2. **帧率换算**：`alarm[0]=120` 的单位是**逻辑步**；`room_speed` 元数据不在恢复树内，本文的
   「≈2.0s」沿用既有契约口径（60fps）。taplock 打开点的精确 tick 只由运行期判定
   （p0 的 `prologue_natural_end.rs` 记 ~f119）。
3. **真机可见序列**：本线是**字节码静态推出**，未在真机原版 APK 上跑「带档冷启动→点按→
   gameplay」录屏对照；重写端侧是 WL4 的 native 层实测（`IR boot room=0 intro=true`）。
4. **重写端每次 nativeInit 都重放序章**为 WL4 已实测事实（`host-lifecycle-native-probe.md`
   §3.1），本线**不改**其结论，只把它归因到宿主触发域而非序章语义。

## 6. 复现

```sh
cd ~/cally-recovered-gml-fd6fc01/restored-source/gml
sha256sum 0017__gml_Object_obj_player_Other_2.gml            # dc6408…
grep -n "file_exists\|obj_introduction" 0017__*.gml           # l.4 / l.295 / l.1540
grep -rn "obj_introduction" .                                 # 仅 0017:1540 + 0548:13
grep -rn "instance_destroy" 0548* 0549* 055[0-5]*             # 仅 0549:7,14 / 0554:19
grep -rn "room_goto" .                                        # 门/地图/结局/返回/重置数据，无启动路径
find . -name '*.gml' | sort | xargs sha256sum | sha256sum      # 36df1a11…（树指纹）
# 事件名/房号权威映射：
grep -n '"name": "obj_introduction"' ../objects.json           # l.16575
head -5 ../rooms.json                                          # id 0 = rm_town
grep -n '"type": 7,' ../objects.json                           # 全树 Other 事件 6 条，subtype 2 仅 obj_player
```
