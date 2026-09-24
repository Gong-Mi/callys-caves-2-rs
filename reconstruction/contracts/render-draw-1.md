# 渲染 Draw 层批次 1：HUD / 弹字 / 死亡界面 / 持枪覆盖层 + 运行期字符串值模型

CODE 370（obj_UI Draw）/693（obj_maptile Draw）/536（obj_coinadd Draw）/540+542+544（obj_youhavedied）/461（obj_damage Draw）/374（obj_muting Draw）全部经字节码在本引擎宿主实测后固化（恢复 GML 交叉核对）。字符串侧引入池化引用值模型，修掉"裸表索引当数字/数字当表索引"的两向混淆。

## 运行期字符串值模型（本批核心）

- **为什么需要**：GMS 1.4 值是 variant，字符串是引用不是数字；IR 是纯 f64 流，字面量被编译为 STRG 表索引（本作 3210 项）。运行期生成的字符串（`string()`、拼接）没有表项，裸索引与真实数字**不可区分**：实测 `draw_text(..., score)` 在 score=1370 时解析成 table[1370]=`spr_set3wall`（HUD 会画出精灵名），`draw_text(..., damage)` 在 damage=3 时解析成 table[3]=`flashing`。
- **模型**：池化引用 = `STRING_REF_BASE`(2^40) + 池索引；池 = bundle 字符串表 ⊕ `Scene.dynamic_strings`。`Op::String{id}` 压入 `BASE+id`；VM 的 `Op::Add` 在任一操作数 ≥ BASE 时委托 `Host::string_concat`（宿主 trait 新增，默认报错）——引用随值走，经 load/store/存档/快照不丢类型。
- **语义**：`string(x)` 对引用恒等、对数字用 GMS 数字渲染（整数无小数点、小数两位）；`string_format(val,tot,dec)` = dec 位小数 + tot 位宽；`string_digits` 只保留 ASCII 数字；拼接两侧先解析再连接，产出新引用。
- **消费端**：draw_text / draw_text_color / file_exists / file_delete / ini_open / ini_read_real / ini_write_real / ds_map_replace / ds_map_find_value 统一走 `arg_text`（引用解析、裸数字按 GMS 渲染）。
- **语料面（全量核对）**：`string()` 97 处、拼接 6 处（全在 obj_coinadd）、`string_format` 1 处（CODE 540）、`string_digits` 1 处（CODE 693）；draw_text 1753 处 = 1631 字面量 + 90 `string(...)` + 31 裸变量（score×18 / tips1×6 / tips2×6 / damage×1）+ 1 `string_digits(...)`。tips1/tips2 是**字符串变量**（Create 里赋字面量），与本模型同径解析。

## Draw 几何与文本（来自 CODE/恢复 GML）

- **obj_UI Draw CODE 370（41164 指令）**：Boss 血条按各 boss 相对几何（boss3 `x−20,y−50 .. x,y−40`；boss4 `x+10..x+30, y−80..−70`；boss5 `x..x−20`；trex `x..x+20`；finalboss `x−10..x+10`），amount = hp/maxhp×100。XP 条 view0 `+46,+4 .. +140,+11`，amount = experience/xptolevelup×100（level<20）、100（level≥20）。等级文本 view0：level<10 → `(+10,+8)`、≥10 → `(+2,+8)`，内容 `string(global.level)`。分数 `score`（sel=−1，落在 Scene.score）view0 → `(+170,+1)`。
- **obj_maptile Draw CODE 693**：`draw_self` + font2 + 白 + `draw_text(x+6, y+8, string_digits(string(other.goto)))`；selector −2 在无 other 上下文解析为自身，打印贴片自己的 `goto`。迷雾门与 goto 钉同在**房创建码**（`{room}visited==0 → destroy; goto=N`）。
- **obj_coinadd Draw CODE 536**：按 `view_current` 分 0/1/3/4/5/6 六支（view2 空支），文本 `"+" + string(global.coinpickup)` at `(player.x, player.y−70)`，配 spr_coin at `(x−10, y−60)`。
- **obj_youhavedied**：Create CODE 540 `coindeduct = irandom_range(30,99)`（GML 实参即 30,99）、`str1 = string_format(coindeduct, 2, 0)`、`instance_deactivate_all(true)` + 激活自身 + `audio_pause_all`、`alarm[0]=70`；Alarm 0 CODE 542 → `taplock=1`。Draw CODE 544（view0）：`"-"` at `(+5,+8)`、str1 文本 at `(+15,+10)`、spr_coin at `(+45,+27)`、`taplock==1` 时 `"Tap to Continue"` at `(+140,+220)`。
- **obj_damage Draw CODE 461**：`draw_set_alpha(1)` + c_red + font2 + `draw_text(x, y−20, damage)`。
- **obj_muting Draw CODE 374（8669 指令）= 持枪覆盖层矩阵**（"muting" 是对象名误称，本体画玩家的手持武器）：12 族武器（pistol/shotgun/assaultrifle/rocket/laser/bombgun/icegun/bow/flamethrower/bladegun/boomerang/spikegun）× 档位（≤3/≤6/≤9/≥10 选 frame 0..3）× facing(0/1) × swing/firing。持枪条件 `swing==1 && firing==0`；开火条件 `swing==1 && firing==1` → 枪前移 + 枪口火焰（`spr_*flare`，frame = obj_muting.frame，0..5，由 Step CODE 373 递增、≥6 回绕）。整段外层门：`room != rm_ending(110)` 且 `instance_exists(obj_player)`。
- **偏移表（facing 0；facing 1 镜像 x 且 xscale=−1）**：pistol 持 `+21,+7` / 开火 `+19,+7` + flare `+15,+5`；shotgun 持 `+15,+8`；rocket `+2,+12`；bombgun `+2,+5`；spikegun `+4,+7`（档0）或 `+4,+6`（档1-3）；flare 各族不同（assaultrifle `+25..+38,+5..+8`、icegun `+17..+35,+5..+6`、laser `+19..+31,+5..+6`、rocket `+22..+34,+2..+3`）。
- **精灵 id（实测资产）**：spr_gunpistol 125 / spr_pistolflare 126 / spr_gunshotgun 127 / spr_gunrocketlauncher 133 / spr_gunbombgun 140 / spr_spikegun 142 / spr_UI 84 / spr_youhavedied 163 / spr_coin 88。

## 夹具陷阱（本批实证）

- **武器门控必须在玩家创建之后**：obj_player Create（CODE 0）会重置武器激活位/全局；先设门控再建玩家必被覆盖（旧批已证，本批沿用）。
- **rm_map 贴片断言**：`{room}visited` 必须在 `load_room_from_data` **之前**注入，否则房创建码里的迷雾门直接销毁贴片。
- **房间卡司**：asset 索引 97（rm_boss3）自带 obj_UI(66)/obj_muting(67)/obj_weaponswap(126)，无需手动创建；room 110（rm_ending）不带覆盖层对象，否定用例需手动放置实例。
- **命令归因**：`draw_view` 一次派发全场，断言用 `DrawCommand.code`（CODE id）过滤来源对象。

## 测试

- `crates/core/tests/hud_draw_ir.rs` 7 项：Boss 血条几何+50%/25%、等级/分数文本（含反表字面量断言：level 12→"12"、score 1370→"1370" 而非 `spr_set3wall`、level 9 走另一 x 支）、XP 条几何+25%/100%、贴片 "39" + 迷雾门负对照、金币弹字 "+100"/"+7" + sprite 位置、死亡界面扣币文本（对 coindeduct 实测值）+ taplock 开关、"3" 而非 `flashing`。
- `crates/core/tests/weapon_overlay_ir.rs` 4 项：手枪四档 frame × 左右朝向（含单次绘制计数）、四族偏移表 + spikegun 三档（5/7/10 → frame 1/2/3）、枪口火焰用 obj_muting.frame 且 Step 递增/6 回绕、swing/firing 门 + rm_ending 整段关闭（含同状态在普通房的阳性对照）。

## 边界

- **字符串相等语义**：全语料仅 1 处字符串比较（obj_poisoniap Other_66 `product_id == "poisongem"`，IAP 桩路径不产生事件）。池化引用按索引比较，跨来源同文不同引用判不等——本作不可观测，登记为边界。
- **`string_format` 的 tot 补位字符**：coindeduct∈[30,99] 恒占满 tot=2，补位分支不可观测；实现取零填充，未与真机对照。
- **数字渲染两位小数分支**：本作绘制路径传入的数字全为整数（level/score/damage/coinpickup），小数分支（GMS `string(1/3)="0.33"`）不可观测。
- **值域上界**：≥2^40 的数字会被当成字符串引用；本作位置/hp/分数/资产 id 远小于该界。
- 真机/GPU 视觉层未验收（NOT RUN）。
