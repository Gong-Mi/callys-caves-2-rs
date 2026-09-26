# 渲染 Draw 层批次 4：商店升级底座、翻页开关与武器获得庆祝屏

覆盖商店系统的全套绘制层，共 20 个 Draw CODE（含 `obj_foundweapon` CODE 408、`obj_store` CODE 475、`obj_storepageswitch` CODE 490、`obj_storepageswitch2` CODE 493 以及 16 个商店强化台座 `obj_powerupgrade*` 等 CODE 415..448）。全部经出货字节码在 IR 宿主上实测后固化，并与恢复 GML 交叉核对。

## 机制 1：武器获得全屏庆祝演出（`obj_foundweapon`，CODE 408）

玩家在关卡中初次拾取新武器时，游戏创建 `obj_foundweapon` (82) 展示全屏通告：
1. **背景幕布**: 以 `spr_pause` (123) 为底，缩放 `scale(0.96, 0.8)` 铺满屏幕；
2. **武器巨幅图标**: 根据当前拾取的武器类型（`global.<weapon> == 1`），以 7x 放大比例（`scale(7.0, 7.0)`）在 `(vx + 220, vy + 120)` 绘制对应枪械精灵（如 `spr_gunshotgun` 127）；
3. **通告横幅**: 在 `(vx + 80, vy + 30)` 绘制对应文本（从 STRG 索引 744..756 抽取，如 "You have found the Shotgun!"）；
4. **点击继续**: 当 `taplock == 1` 时，在 `(vx + 150, vy + 200)` 绘制 "Tap to Continue"（STRG 743）；`taplock == 0` 时此提示隐藏。

---

## 机制 2：商店强化台座矩阵（16 个物品对象，CODE 415..448）

商店物品分为 Page 1 与 Page 2 两页，每页 8 个台座：
- **公共布局结构**:
  - 底座绘制：`draw_sprite_ext(spr_storepedestal, 0, x, y, 1.2, 1.1, 0, -1, 1)`（精灵 154）；
  - 武器/技能小图标：在 `(x + 135, y + 15)` 以 0.7x 缩放绘制代表精灵；
  - 标题文本：`draw_text(x + 5, y, title)`，如 "Triple Jump:"、"Reduce Enemy HP 1:" 等；
  - 标价文本：`draw_text(x + 5, y + 15, price)`，如 "$3,000"、"$5,000" 等。
- **售罄印章 (`spr_soldout`, 148)**:
  - 检查对应全局购买标志 `if (global.<item>bought == 1)`；
  - 当已购买时，在 `(x, y)` 叠加绘制售罄章：`draw_sprite_ext(spr_soldout, 0, x, y, 0.6, 0.55, 0, -1, 1)`。
- **血量补满特殊覆盖 (`obj_healthrefill`, CODE 448)**:
  - 台座始终标价 "$250"；
  - 当实例字段 `drawhealthfull == 1`（玩家当前生命满格）时，在 `(x + 40, y + 15)` 叠加醒目字样 "HEALTH FULL!"（STRG 824）。

---

## 机制 3：商店导航与页面生成（CODE 475, 490, 493, 507, 512）

1. **入口与翻页按钮**:
   - `obj_store` (110, CODE 475): 绘制按钮背景框 `spr_weaponbox` (153)，在 `(x + 37, y)` 绘制 "Store"；点击创建 `obj_pause`；
   - `obj_storepageswitch` (116, CODE 490): 绘制按钮背景框，在 `(x + 12, y)` 绘制 "Next Page"；点击销毁 Page 1 并创建 `obj_pause2`；
   - `obj_storepageswitch2` (117, CODE 493): 绘制按钮背景框，在 `(x + 14, y)` 绘制 "Last Page"；点击销毁 Page 2 并创建 `obj_pause`。
2. **页面生成器卡司（实测字节码锚定）**:
   - **Page 1 (`obj_pause` Create, CODE 507)**:
     - 左列 `vx + 65`: `obj_healthrefill` (vy + 30), `obj_coinmultiplier2` (vy + 70), `obj_triplejump` (vy + 110), `obj_powerupgrade` (vy + 150)
     - 右列 `vx + 245`: `obj_swordupgrade` (vy + 30), `obj_strengthupgrade` (vy + 70), `obj_swordupgrade2` (vy + 110), `obj_healthregen` (vy + 150)
     - 翻页按钮 `(vx + 150, vy + 190)`: `obj_storepageswitch`
   - **Page 2 (`obj_pause2` Create, CODE 512)**:
     - 左列 `vx + 65`: `obj_maxhpupgrade` (vy + 30), `obj_maxhpupgrade2` (vy + 70), `obj_coinmultiplier5` (vy + 110), `obj_powerupgrade2` (vy + 150)
     - 右列 `vx + 245`: `obj_powerupgrade3` (vy + 30), `obj_swordupgrade3` (vy + 70), `obj_energywaveupgrade` (vy + 110), `obj_strengthupgrade2` (vy + 150)
     - 返回按钮 `(vx + 5, vy + 190)`: `obj_storepageswitch2`

---

## 夹具陷阱与实测固化

1. **`drawhealthfull` 是实例字段而非全局**: 源码中通过 `self.drawhealthfull` 读取（selector -1），若注入到 `globals` 则无法触发，实测已固化为向实例 `fields` 注入。
2. **`HEALTH FULL!` 是叠加显示**: 出货字节码在 `drawhealthfull == 1` 时并未分支跳过标价，而是直接在 `(x + 40, y + 15)` 叠加文本。
3. **按钮自定位与 view 相加**: 按钮位置以 `view_xview + offset` 计算，夹具中配置 `view_positions` 确保正确投射。

---

## 测试套件

`crates/core/tests/store_upgrades_ir.rs`（5 项测试通过）:
1. `foundweapon_overlay_draws_backdrop_tap_prompt_and_weapon_showcase`: 验证幕布 (123)、7x 放大枪械贴图、"You have found the Shotgun!" 横幅及 `taplock` 门控提示。
2. `upgrade_pedestals_draw_prices_and_overlay_soldout_when_bought`: 验证台座 (154)、价格标签与已购售罄印章 (148) 叠加。
3. `health_refill_swaps_price_for_health_full_banner`: 验证正常标价与满血状态下的 "HEALTH FULL!" 叠加绘制。
4. `store_navigation_buttons_draw_labels_and_box_sprites`: 验证 Store、Next Page、Last Page 三按钮的框体精灵 (153) 与坐标对齐。
5. `pause_store_generators_spawn_complete_page1_and_page2_catalogs`: 验证 `obj_pause` (Page 1) 与 `obj_pause2` (Page 2) 原生创建代码生成的全部 18 个对象实例卡司。

---

## 边界与未验层

- 本批闭环了商店系统的全部 20 个 Draw CODE；
- 剩余 Draw 事件主要为暂停菜单控制（obj_pause 自身的选项按钮、音量滑动条等 16 个 CODE）与 Lloyd 对话教程（16 个 CODE）；
- 真机/GPU 视觉层未验收（NOT RUN）。
