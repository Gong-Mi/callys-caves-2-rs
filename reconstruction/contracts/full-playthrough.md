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

## rm_ending 内的活体 credits 环（本批扩展）

rm_ending 的 RoomData 真放 obj_endmusic（asset 实测 623 摆放含 {obj_endmusic:1}），
所以翻页梯不必另建场景：入场后从 t=1（Create 在入场帧装好 alarm[0]=50）直接
量测，beats 必须与 #82 手搭场景的表逐拍相同（50/400/700/1000 页 1..4；窗口
1200 帧，A11=2660 的 obj_final 出生不在内，显式断言 final_spawn==0）。
RED 实录：先跑 20 帧 settle 再计数得到 30/380/680/980——恰是 settle 偏移，
确定性可解释；修法是删掉独立 settle 窗、把该量测循环本身当作入场稳定期，
obj_music 存活断言移到循环后。

## 边界

- 止步于 credits 前四页 + 1200 帧窗口：obj_final 面板、tap→rm_challenge1
  门与 teaser 重启由 #82 尾声批拥有（2965-tick 全环再跑一遍只会把失败归因
  混进本套件）；本批把"入场即演"的连续性补上，不重复所有权。
- 支线区域（rm_level*a、map、challenge 五关）不在 trunk 上，本套件不走。
- 原版语义（boss 死亡注入 hp 属"引擎不重算字段"注入点纪律，见
  boss_kill_chains 头注）；执行与断言均为本重写宿主的状态机回归，不声称
  与原 runner 像素/时序等价。
