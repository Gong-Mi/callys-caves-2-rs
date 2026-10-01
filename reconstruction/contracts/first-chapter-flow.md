# 第一章完整流程契约：镇 → Caves → Boss 1

第一章按原版 room 拓扑定义为：

`rm_town → rm_level1 → rm_level2 → rm_level3 → rm_level4 → rm_level5 → rm_level6 → rm_level5 → rm_level7 → rm_level8 → rm_level8a → rm_boss1`

其中 rm_level6 是 room5 的宝库支线/回返房，rm_level8a 是进入 Boss1 前必须经过的武器支线，不允许用 `transition_to_room` 直接跳过。

## 流程验收

`crates/core/tests/first_chapter_flow_ir.rs` 的单项测试逐个查找当前房间中由原始 creation code 写入的 `warproom`，把玩家写到门实例位置，执行原始 CODE 13 碰撞事件，再消费 `target_room_warp` 完成客户端等价换房。

逐段断言：

- rm_level1：enemy×5、knifebandit×2、`level1visited=1`。
- rm_level2：enemy2×1、spikes×27。
- rm_level3：bat×2、watersurface×59、treasurechest×6。
- rm_level4：wolf×2、bat×2。
- rm_level5：enemy×2、knifebandit×1、wolf×2。
- rm_level6：treasurechest×14、enemy=0。
- rm_level7：knifebandit×1、shooter1×1、wolf×1、bat×2。
- rm_level8：enemy×3、knifebandit×8、wolf×1。
- rm_level8a：enemy×5、knifebandit×3、shooter1×2、wolf×3。
- rm_boss1：trex×1、bossboulder 至少 1、`boss1dead=0`，玩家仍存活。

## 重要测试纪律

流程测试不能在下一次踩门前无条件空跑多帧：原版 CODE 361 会按玩家距离休眠远处实例，包括下一张门的 active 状态。测试必须先走当前门，再对当前房卡司断言；否则会把原版休眠机制误判成门链缺失。

## 边界

本契约证明第一章的房间顺序、关键卡司、门链和 Boss1 入口；Boss1 击杀/掉落/巨石开启由 `boss1_trex_kill_chain_ir.rs` 独立覆盖。Android 真机前几关视觉、触摸手感和音频仍是独立验收层。
