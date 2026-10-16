# 全游戏连续通关（H 线连续性套件）

套件：`crates/client/tests/full_playthrough.rs`（1 项，dev 档本机 ~100s，
收集器 240s 超时档）。六个分段套件（first_chapter、mines/depths/core/lab/lair
trunks、boss_kill_chains）各自用 `transition_to_room` 播种入场；本套件不新增
分段证明，只补它们都缺的**连续性**：一次 `boot_like_android` 帧循环，从冷启动
经 11 跳第一章、boss1（真弹链 CODE 11→284→160）、16 跳 Mines、boss2、20 跳
Depths、boss3、15 跳 Core、boss4、17 跳 Lab、boss5、21 跳 Lair、boss6，
最后停在 rm_ending(110) 的入场 + 20 settle 帧。全程只经活体 `obj_warpanywhere`
门（CODE 13 碰撞，无 room_goto 注入），每跳钉 persistent-player=1、
obj_music 存活、ROOM 视图重播种可见。

## 连续性专属断言（只有单次连续运行能证）

- 六个 `bossNdead` global 在 rm_ending 里仍**全部累积**（分段套件每次重开
  GameState，flag 只在自己的房内可见；boss6 原版从不写 boss6dead，不伪造）；
- 玩家实例 id 全程唯一（persistent 语义跨 6 区、6 次 boss 死亡、60+ 门跳）；
- rm_ending 真 `draw_frame` 亮像素 >1000。

## RED 实测与根因（本套件抓到的真实现场差异）

首次跑到 rm_boss6 时注入 `hpfinalboss=0` 后 30 帧 boss 不死。诊断输出：
boss 实例 `active=false`，玩家站在 (128,142)。根因不是 boss6 机制，而是
**进房时序**：连续走法把玩家放在返程门锚点上，距 boss 出生点 ~547px，超出
CODE 361 休眠 sweep 的 450px 判定带，boss 在进入竞技场后立刻被挂起——
分段套件从 `transition_to_room` 播种时玩家落点是 ROOM 初始位，从未暴露这一点。
修复按夹具纪律：先把玩家搬到 boss 位置 bx−120（原版激活路径自然覆盖的走法，
镜像 `instance_activate_region` 语义），一帧 settle 后再注入；不动引擎、
不手改 active。

## rm_ending 内的活体 credits 环与交棒点按（本批扩展）

rm_ending 的 RoomData 真放 obj_endmusic（asset 实测 623 摆放含 {obj_endmusic:1}），
所以翻页梯不必另建场景：入场后量测循环从 t=1 起（Create 在入场帧装好
alarm[0]=50），跑 2975 帧，beats 必须与 #82 手搭场景的表逐拍相同——页 1..9
@50/400/…/2400、obj_final A11 出生 @2660、panel2@2760、taplock@2960，且原版
饥饿在**被进入的房间自己的时间线**上复现（credits 被 deactivate、a9 停在
140、drawcredit10 永不置位）。
RED 实录：先跑 20 帧 settle 再计数得到 30/380/680/980——恰是 settle 偏移，
确定性可解释；修法是删掉独立 settle 窗、把该量测循环本身当作入场稳定期，
obj_music 存活断言移到循环后。

交棒点按走客户端输入通道：把世界坐标 release 压进 `left_releases`
（即 `pointer_released` 所填的同一队列；相机原点使 screen_to_world 的画布
裸算式脆弱，故直接推世界坐标——队列语义相同、坐标语义精确），命中
obj_final 的 32×32 回退盒 → CODE 698 执行 instance_activate_all +
warpfrommap=1 + room_goto(105) → 帧循环自消费 warp → rm_challenge1 落地、
persistent player=1、亮像素>1000。

## 尾声段（challenge 五关 + teaser 重启回镇）

交棒进 rm_challenge1 后继续走四张前进门卡（RoomCC 1014/1016/1018/1020 的
warproom 常数，与 trunk 卡同一枚举方法；返程卡 1013/1015/1017/1019/1021
不走）到 rm_challenge5。该房 RoomData 真放 obj_finalchest(101)：玩家站上
宝箱，**自然碰撞派发**触发 CODE 454（创建 obj_tease + 宝箱自毁）——不是
直派。obj_tease Create 的 deactivate_all(true) 是可观测的：persistent 玩家
跨 warp 存活但被挂起（断言 !active）。跑原版梯到 alarm[0]=600：taplock 与
drawpanel3 同拍落拍（对 #82 表）。重启点按同样走 left_releases 队列、瞄准
teaser 的 sprite 162 盒中心 → CODE 702 `audio_stop_all + game_restart` →
warp 0 被帧循环消费 → rm_town 落地、player=1。

**登记的实现边界**：本重写的 game_restart 是 room-0 warp，globals 跨重启
**累积**（断言 boss1dead 仍在钉住这个差异）；原版重建全部内存。这条是
宿主语义差异，不是对原版的声称。

## 地图 stint（连续环房间覆盖收口）

rm_level17 的地图段在同一个 `GameState` 内依次开启 rm_mapview0(1136×640)、
rm_map(960×640)、rm_mapview3(1024×768)，**三页都经真实返回路径回到 rm_level17**：
每次返回的贴片点击通过 `left_releases` 队列进入 client `step`，同帧完成 Mouse_7
派发与 room warp 消费，随后断言 `warpfrommap==1`、CODE 692/16 把玩家回钉到
startx/starty(128,204)、6 帧后 CODE 362 清旗标。旧版在 rm_mapview3 停下、其
client 侧返回从未被跑过；本批把它接进同一连续环。

**停车点夹具纪律（本批实测根因与两处更正）**：

- **归因更正**：整房复活不是 map 菜单 CODE 476 的 `instance_activate_all()`（恢复
  GML 逐条核对，CODE 476 无此调用）。真实链路：CODE 476 `with (obj_firstpause)
  instance_destroy()` → obj_firstpause Destroy CODE 495 结尾 `audio_stop_all();
  instance_activate_all();`——warp 消费那一 tick 玩家 Step（CODE 12）对整个房间运行。
- **缝的双读数（核心更正）**：旧文本「bbox 间距实测 5.4px」只是录制框读数，与引擎
  读数相反。引擎碰撞前相 `bounds_for_instance`（`ir_scene.rs:750-763`）用**整张
  精灵矩形**，原版 `Compute_BoundingBox` 用录制 SPRT bbox：同一 tick 玩家盒引擎读数
  (885,384)-(917,418) vs 史莱姆 (893,320.7)-(957,384.7) → y 相交 0.7px = **命中**；
  录制读数 (894,388)-(908,418) vs (906,359.7)-(942,384.7) → y 相距 3.3px = 不命中。
  **触发点是引擎整矩形前相在双读数缝上造出的假阳**；接触之后的全链（CODE 12→540、
  692、541 的 health1=4 + room_restart）逐条核对都是出货字节码。
- **6 tick 时间线**（1024×768 → rm_mapview3，停车 (900,400)，health1 注入 2）：
  t1 开图 tick 玩家 Step 吃接触 health1 2→1 → 同 Step 尾部 `global.health1==1`
  （恢复 GML 0012 第 2375–2387 行）建 obj_youhavedied，CODE 540 回钉 persistent
  玩家 (128,204) 后 `instance_deactivate_all(true)`；t1 帧尾客户端消费 rm_mapview3
  warp——死亡层非 persistent 被换房丢弃、玩家带 inactive 过去；t6 贴片返回点击 =
  CODE 692 `instance_activate_all()` + `warpfrommap=1` + room_goto(25) 同帧消费；
  t7 回 rm_level17 下一 tick health1 仍 1 → 建第二层、playerdied 1→2，obj_bg 被挂起
  CODE 362 不执行 → **现场 = obj_youhavedied 唯一 active、玩家 inactive、
  warpfrommap 卡 1**。
- **修法与门**：停车点 (428,204)（距 pin 300px；实测 120px 内、任何 active 状态下
  都没有敌人/危险实例）。本批把「事后 health1 断言」升级为**逐腿双读数门**
  `player_enemy_contacts`（引擎读数与录制读数都越界才放行）——该危险对 pre-tick
  断言不可见（CODE 495 的复活发生在伤害 tick 之前）。新增
  `the_map_open_contact_tick_hands_the_run_to_the_death_overlay_across_the_map_warp`
  把上述 6 tick 现场逐条钉住：它是**碰撞域修复的 canary**——把前相换成录制框后
  第一条断言必红，届时须按新碰撞语义**重铸**夹具，而不是重播旧夹具。
- **边界**：碰撞域生产修复点 = `bounds_for_instance`/`instance_place` 的整矩形
  前相 → 录制框/掩码（`crates/core/src`），由 feat/precise-collision-masks 线持有；
  本批不动 core、不删死亡派发、不补血。

## pending-view guard 的正反边界

rm_mapview3 的 ROOM 记录 8 个静态 `view.visible` 均为 false；其
`obj_viewresolution` Create CODE 537 把 Alarm 0 置 1，下一逻辑 tick 的 CODE 538
按 1024×768 置 `view_visible[3]`。客户端（`lib.rs` gameplay Draw）只在
**resolver 类型 alive+active 且 `alarms[0]==1`** 时允许无 view 帧：清掉四个 draw
queue 并跳过该帧，其他无 view 情形一律 halt。

- **正例（隔离夹具）**：`a_pending_view_resolution_frame_skips_draw_and_clears_the_queues`
  在 rm_level17 先跑一帧正常绘制（断言四个队列非空），再造出精确 pending 形状
  （`view_visible=[false;8]` + resolver `alarms[0]=2`，使 guard 读取时恰为 1），
  断言该帧不 halt、`active_view_index()==None`、四队列归零，下一 tick 选到 view 且
  重新画出内容。**诚实边界**：shipped warp 路径上 `Scene::transition_to_room` 自己
  就会 `clear_draw_commands()`（`ir_scene.rs` 第 659 行），所以连续路线里 guard 的
  清队列是冗余的；"跳帧不泄露旧四队列"这条荷载断言只在上述隔离夹具（不经换房清除）
  里成立。
- **负例（矩阵）**：`a_viewless_frame_without_pending_view_resolution_still_halts`
  在 rm_level17（先断言该房确有 obj_viewresolution 实例）分别造出**无 resolver 实例 /
  resolver dead / resolver inactive / alarm 非 1** 四支，逐支断言仍以
  `no visible view for gameplay room` halt，永不被放宽的 guard 吞掉。bundle 的 191
  个对象里 obj_viewresolution 恒存在，所以 `resolver` 查找失败那一支在生产不可达，
  不在测试里伪造。

## 房间覆盖是观测，不是路线复述

连续套件的 114/114 主张来自**同一个 GameState 每步的 `current_room` 去重集合**
（测试内 `thread_local` 的 `OBSERVED_ROOMS`：`boot_like_android` 清空并记录 seed
房，`step` 成功一帧就记录当前房；集合语义使重复进房不重复计数）。套件结尾与
`state.asset.rooms` 全表**双向求差**：`missing==[]`、`extra==[]`、`distinct ==
asset.rooms.len()`（实测 114/114）。集合不由路线数组生成。生产 `GameState` 未改。

像素证明范围：三处房间渲染断言从「非零像素 >1000」改为**与明确清屏基线
（RGBA (15,18,30,255)，即缓冲区 BGRA 字节 [30,18,15,255]）不同的内容像素** + **不同颜色数**（负控见下）。实测 rm_ending
content=518400(全画布)/distinct=21、rm_challenge1 947 色、rm_level16a 822 色；整屏
被背景层覆盖，所以这只证明**载荷确实进了光栅器且是合成帧**，不是原版像素等价，也
不单独证明某个精灵/文字可见。负控 `the_pixel_content_gate_sees_the_clear_when_nothing_is_drawn`
移除同房四队列 + 瓦片 + 粒子后断言 content==0、distinct==1，证明该门对"无载荷"真的
会红。

**边界**：三页往返与 guard 断言都是本重写宿主的状态机/客户端回归；不是原版
runner、像素等价、GPU 或真机视觉验收（无原版像素等价 oracle）。PR #100 的
`Scene::transition_to_room` 全三页 core 往返仍是独立证据层，不与完整 client frame
loop 混称。

## 边界

- 重启回镇后再走**暗门支路**：CODE 17 基线种 `haskey=1`，rm_town 卡 803 是全 218
  门卡中唯一 `unlocked=0` 的锁门——CODE 13 钥匙分支消耗 haskey、置 unlocked=1、
  warp 进 rm_level16（Mines 死端区，trunk 不经），再经卡 850（16→16a）与卡 851
  （16a→17，shipped unlocked=1）把整条死端走进去并折回 trunk 的 rm_level17，
  途中 rm_level16a 通过像素内容门（content>0、822 色）。秘密支路由此进入连续链；房间覆盖变为
  trunk 全集 + 完整 16/16a 死端区（23/24 两房）。
- 支路之后的 challenge 五关内部玩法细节与
  teaser Draw 文本层由 #82/挑战套件拥有，本套件只走连续性。
- 原版语义（boss 死亡注入 hp 属"引擎不重算字段"注入点纪律，见
  boss_kill_chains 头注）；执行与断言均为本重写宿主的状态机回归，不声称
  与原 runner 像素/时序等价。
