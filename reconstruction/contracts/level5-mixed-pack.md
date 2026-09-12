# rm_level5 混编 pack 与 par_enemy 多态契约（mixed pack）

基于哈希固定的原版资产 `assets/game.droid`
SHA256 `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`。

## 现场卡司与链路

rm_level5（room 5）：obj_enemy×2 + obj_knifebandit×1 + obj_wolf×2——前四关
三种地面行为首次同场。进入方式沿用真实踩门：town→L1→（本测试用 transition
直达 L4，与上批 wolf 场景同构）→ CODE 812 门（warproom=5，落点 160,300）。
room 5 实际有三张门卡（813 回 L4 / 814→L6 / 815→L7），Mines 支线在此分叉。

## 多态证据（三条独立面）

1. **parent 链数据**：14/15/23 的 `parent_chain` 均含 par_enemy(11)——
   `Scene::select` 走父链解析，三种族同时是 `with (par_enemy)` 的接收者。
2. **CODE 284 单弹模 × 三种族字段**：子弹 Step 的分支序列
   （knifebandit→wolf→enemy→...）各自写自己 HP 字段名
   （hpknife / hpwolf / hp），并统一 `pistolxp += 1` 反哺——测试把三个
   存活者轮流拖进已验证的 40px duel 槽位，逐轮断言「自己字段归零 + 一次
   xp 反哺 + 自家 Alarm 0 级联移除（CODE 55/142/46）」。
3. **CODE 361 休眠多态**：`with (par_enemy)` 扫到远处 bandit（700px）时
   `instance_deactivate_object(id)` 使整族休眠；近处 wolf（60px）不受
   450px 门限影响持续巡逻——sweep 距离判定按实例计算，父链选择器只决定
   谁在遍历集内。

## 测试（`crates/core/tests/level5_mixed_pack_ir.rs`）

| 用例 | 断言 |
| --- | --- |
| `portal_level4_to_level5_delivers_the_mixed_pack` | 真实踩门→落点 (160,300)、卡司 2/1/2、三种族 parent 链含 11、20 帧三 Step 交错零错误、安全区 health1 无损 |
| `one_bullet_mold_kills_three_species_through_their_own_fields` | 三轮各杀一种：本种字段 1→0、xp 台账 1→2→3、各自家死亡级联移除、全程 health1=4、snd_explode 队列 |
| `dormancy_sweep_sleeps_the_far_bandit_while_the_near_wolf_paces` | 40 tick 内远 bandit 被父链 sweep 休眠、近 wolf 始终 active——per-instance 距离门 + 多态遍历集 |

## 施工中的自纠

- xp 台账总断言初版写 4.0（把每轮断言的期望值误当终值再加一），fresh
  start 为 0、三杀反哺三次即 3.0——RED 后按算术修正；
- 首版「三条火线上分列三敌」的轮次几何被敌人巡逻位移破坏（第 2 轮空弹），
  改用前批 trace 验证过的 40px duel 槽位 + 每 tick 重钉（并显式声明该
  纪律），单目标顺序歼灭。

## 边界

- 击杀顺序由 CODE 284 分支序 + 槽位几何共同决定，测试顺序无关（逐轮取
  首个存活者）；
- CODE 12 的 hitknifebandit 分支（sliding1/sliding2 变体）已在 H 线早期
  验收，本批不重复；
- Mines 分叉门 814/815（→L6/L7）机制与 812 同模板，未逐门再铺。
