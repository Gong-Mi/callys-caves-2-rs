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

## 边界

- 全环止于交棒进 rm_challenge1：teaser 重启（game_restart→房0停乐）与
  challenge 五关内容由 #82/挑战套件拥有；本套件证明"结尾引擎在真进房的
  时间线上完整演出并把手交给下一个房间"，不重复所有权。
- 支线区域（rm_level*a、map、challenge 五关）不在 trunk 上，本套件不走。
- 原版语义（boss 死亡注入 hp 属"引擎不重算字段"注入点纪律，见
  boss_kill_chains 头注）；执行与断言均为本重写宿主的状态机回归，不声称
  与原 runner 像素/时序等价。
