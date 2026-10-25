# obj_player Step (CODE 12) — 接触伤害相位契约

本文件只登记 **CODE 12 的一个相位**：`obj_knifebandit`（对象 15）的接触伤害块，
以及它作为其余敌人家族模板的形状。其余相位（其它家族、死亡级联、拾取/落水）不在
本契约内，后续批次各自扩展。

## 字节码坐标

- CODE 12 = `gml_Object_obj_player_Step_0`，start `3770532`，6163 条指令。
- 本相位：指令流 `[430..600]`（`constant 15; cast; instance_exists` 起，到该家族
  `bf` 落点 `3774392` 为止）。逐条读自 `crates/core/src/generated/full_ir.json`；
  恢复 GML `0012__gml_Object_obj_player_Step_0.gml` 仅作导航。

## 闸门树（两个 facing 各一棵，形状相同）

```
constant 15; cast; instance_exists          -> bf 跳过整族
hitknifebandit != -4 (cmp 4);  facing == K (cmp 3)
invulnerable == 0 && invulnerable2 == 0      # && 短路：`b` 跳过被压入的 constant 0
rebuff != 1 (cmp 4)
  HIT:   flashing = 1;  global.health1 -= 1
         hit.x > x (cmp 6, `other` 读)  -> invulnerable = 1; sliding1 = 1
         hit.x < x (cmp 1, else-if)     -> invulnerable2 = 1;
                                           facing 0 -> sliding1 = 1
                                           facing 1 -> sliding2 = 1
         alarm[4] = 10; alarm[7] = 20; alarm[8] = 23
         global.soundmute == 1 / == 0 -> audio_play_sound(24, 0, false)
         place_meeting(x + hspeed, y, par_wall=34) -> hspeed = 0
rebuff == 1
  DODGE: hit != -4; facing == K; invulnerable == 0 && invulnerable2 == 0
         !instance_exists(106) -> instance_create(x, y - 10, 106)
```

## 需要钉住的下发版行为（重写容易“修平”）

1. **同 x 命中不挂无敌**：`hit.x > x` / `hit.x < x` 都不成立时，`health1` 照扣，
   但 `invulnerable`/`invulnerable2` 都不置位，下一帧同一敌人可以再扣一血。
   不是笔误，是 `>`/`<` 双排除的必然结果。
2. **左/右侧对 sliding 的选择不对称**：`hit.x > x` 恒置 `sliding1`；
   `hit.x < x` 时 facing 0 置 `sliding1`、facing 1 置 `sliding2`。
3. **dodge 分支要重测闸门**：`rebuff == 1` 只在两个无敌位都清空时生效，
   且有 `!instance_exists(obj_dodged)` 一次性门。
4. **音效不参与扣血**：`soundmute == 1` 只静音，`health1` 照扣。
5. **墙检查用 `hspeed` 而不是 `hsp`**，且只在命中路径里；无墙时 `hspeed` 保持原值。

## 验收

套件：`crates/core/tests/player_contact_damage_ir.rs`（7 个测试）

- `the_block_carries_the_shipped_constants_the_matrix_asserts`：从活 bundle 的
  指令流重提 object id / alarm 三元组 / 音效 id / `par_wall` / dodge 生成点，
  防止 IR 重生成后矩阵还瞄着旧形状。
- `every_facing_gate_and_side_cell_matches_the_bytecode`：2 facing × 4 组
  (`invulnerable`,`invulnerable2`) × 3 侧 = **24 格全枚举**（不是抽样），
  每格断 `health1`、`flashing`、两个无敌位、两个 sliding、`alarm[4/7/8]`、
  音效数量。
- 其余：同 x 无锁存（连击两血）、已挂锁存挡第二击、rebuff 单次 dodge、
  dodge 仍需闸门、`soundmute` 静音、墙把 `hspeed` 归零。

## 夹具纪律（本相位踩过的）

- 玩家 Step 自带重力：每次 dispatch 前重钉 `y`/`vsp`，否则 `instance_place(x, y, …)`
  会随帧漂移。
- 碰撞宽相必须接 `sprite_bounds` + `sprite_bboxes` + `sprite_masks`
  （`assets/game.droid` 的 SPRT 录制框），否则共享框源退化成整数点盒，
  接触格会因为“点盒互叠”而假绿。
- 敌人 Create 会自己放位/置字段，建完必须显式重写 `x`/`y`。
- `obj_wall`（4）要显式写 `type = 1`：前面的移动相位靠它走 `hcollide.type == 1` 分支。

## 边界

重写端 IR 回归语义；不含原版 runner 等价、设备/GPU 或像素证据。本相位只覆盖
`obj_knifebandit` 一族，其余家族与死亡级联是后续批次（它们共享同一形状，
但音效 id、闸门顺序需逐族从字节码取，不能复用本文件的常量）。
