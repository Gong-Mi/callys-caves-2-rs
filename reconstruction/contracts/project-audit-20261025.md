# 项目审计 2026-10-25（callys-caves-2-rs）

审计范围：6 条主线问题。只读核对的对象是当前工作树
`~/cally/callys-caves-2-rs`（HEAD `b3ac80e`，detached）、`.github/workflows/*`、
`c-recon/{gen,fixtures,tests,src,tools}`、`reconstruction/contracts/boss1-trex-kill-chain.md`。
本轮**未**跑 1068 测试、**未**跑 `batch_diff.py`、**未**访问 k80u。

---

## 先说三条与问题描述不一致的现场事实（已核对，会影响修复优先级）

1. **C 线在 CI 里完全没有门**。grep `.github/workflows/*`，没有任何一个 workflow 提到
   `c-recon`。唯一构建 C 线的入口是 `scripts/dev_smoke.sh`（本机三步冒烟），而它把要生成的
   文件硬编码成 `... gen/gml_0012.c gen/gml_0792.c ... tests/collision_test.c`。所以
   "权威实现方向"目前既无 CI 门、也无构建清单抽象——这比"只生成了 2/1354"更根本，也正是
   "口径失真"能长期存在的机制。
2. **`c-recon/tests/objects_test.c`（321 行）不在冒烟构建里**。dev_smoke 只编
   `collision_test.c`，这个对象层测试从来没进过验收链。要么它是死测试，要么它被手工跑过、
   结果没进任何账。
3. **机器状态比问题描述更危险、也更脏**：`HEAD` 是 **detached b3ac80e**，无分支，
   `origin/main..HEAD` 是 **131 个提交**（不是 19——19 是今天的量）。`git status` 除 14 个被
   跟踪产物外，还有未跟踪的 `android-build/classes.dex`、5 个 `.class`，以及
   `build-prague.log / nextest-prague.log / test-prague.log / test-prague2.log` 四个日志——
   `.gitignore` 只挡了 `*.apk`/`*.so`，不挡 `.idsig`、`classes/`、`compiled/`、`*.log`。

---

## 逐条：影响 / 优先级 / 最小第一批

### #5-a 仓库卫生（产物被跟踪）

**影响**：每次构建即脏树，`git diff` 无法当作"本批改了什么"的证据；今天这 14 项与未提交的
4 项混在同一个 status 里，任何提交都得靠人眼挑文件——这是**污染后续所有提交归因**的元问题。
同时 untracked 日志会让 `git add -A` 顺手把 3.4M 的 nextest 日志塞进历史。

**优先级：P0（最先做，30 分钟，无风险）**。

**最小第一批**：

- `git rm --cached android-build/aligned.apk.idsig android-build/classes/classes.dex
  android-build/classes/com/gongmi/callyscaves2/MainActivity.class
  android-build/compiled/res.flat.zip`（`res/drawable/icon.png`、manifest、`res/values`、
  `src/`、`tests/` 保留跟踪——它们是输入）。
- `.gitignore` 追加 `android-build/classes/`、`android-build/compiled/`、
  `android-build/*.idsig`、`*.log`。
- **验收**：`bash scripts/build_apk.sh` 跑完后再 `git status --short`，除 `src` 外 **0 项**；
  再 `git ls-files android-build | wc -l` 应从 14 降到 9。

### #6 双机平行 + 本地 131 提交无分支

**影响**：detached HEAD + 无远端 ref = 一次 `git checkout main` 就让 131 个提交变成只能靠
reflog 找回的对象。k80u 那边 `collision.c / ir_scene.rs / collision-broad-phase.md` 迟早
三方对撞；现在连"我方基线 SHA"都没有可推的锚点。

**优先级：P0（与上条同批，10 分钟）**。

**最小第一批**：`git switch -c test/boss1-trex-stun-chain`（离开 detached）→
`git bundle create ~/cally-131.bundle origin/main..HEAD`（已有 `cally-all.bundle`，这是
增量）→ 是否 `push` 仍按默认"只本地提交"**先问**。**验收**：`git worktree list` 首行不再是
`(detached HEAD)`；`git bundle verify` 通过。对撞本身（rebase）留到有 origin ref 之后再做。

### #1 主线漂移

**更正（2026-10-25 当晚核实，原问题描述错误）**：`scripts/batch_diff.py --build-c`
会先用 `ir_to_c.py --all` 把 **1354/1354 个 body 全部生成 C** 编进一次性语料驱动
（生成放 work 目录，不进 `c-recon/gen/`，避免脏树；全量编译约 25s）。
所以 C 线的**生成本身是完整的**（0 refused），"只生成了 2/1354" 的说法作废。
`c-recon/gen/` 只带 2 个 body 是刻意设计（契约注释原文），不是进度。

**真正的影响**：单 body 执行的全量对账（ identical 1354 ）已经过了，但那是
"generic fixture 跑一条 body"；**行为级序列**（Create→ticks→body、多实例、
oracle 锚定）的 C 覆盖还很薄——checked-in fixtures 只有 code12_contact 和
code792 两个。也就是说，C 线缺的不是"生成"，是"深层验证与行为夹具"。

**优先级：P1**。

**最小第一批**：

1. 行为级序列对账：用现成的 `--sequence --ticks 30` 跑全量 corpus（Create→ticks→body），
   把 C↔VM 从"单 body"扩到"真实序列"。本次已跑（2026-10-25，结果记在下面）。
   以后作为 `dev_smoke.sh` 之外的定期深度校验，不接 CI（C 线只本地验证，用户裁决）。
2. 给已用 oracle 钉死的语义在 C 侧各配一条 checked-in fixture（`c-recon/fixtures/`）：
   碰撞取整/旋转（本批已加进 collision_test，109 checks）、掩码基址（base_probe），
   让 checked-in 的单 body 断言不只有 code12/code792 两个。

**验收**：`--sequence --ticks 30` 全量跑完 differ/c_only/c_fail 必须全为 0；
新 fixture 沿用"oracle 表驱动 + 变异门"的既有纪律。

**本次结果（2026-10-25，`--build-c --sequence --ticks 30` 全量）**：
`=== 1354 bodies ===  identical: 1354, differ: 0, c_gap: 0, c_only: 0,
vm_reject: 0, c_fail: 0, not_built: 0, no owner: 551 skipped, rc=0`。
即 Create→30 tick→body 的行为级序列上，C 宿主与 Rust VM 逐字节一致。
注意 "identical" 仍含"两侧同因 abort 的协议一致"成分；真正的原版等价仍只靠
oracle 锚定的那部分（碰撞几何族）。

### #3 等价层级没有机器登记

**影响**：新夹具退化成自洽是**默认路径**（batch_diff 的默认行为就是两侧跑同一个
full_ir.json），而 skill 里的纪律只能靠人读。这是 #2 反复翻车的制度成因。

**优先级：P1（与 #1 同一批做，因为 CI job 正好要读它）**。

**最小第一批**：一个 `reconstruction/contracts/equivalence-registry.json`，每行
`{id, tier, evidence_path, command}`，`tier ∈ {"c_vs_vm_selfconsistent","oracle_runner","original_runner"}`。
先只登记现有的：`code12_contact`/`code792`（tier=c_vs_vm_selfconsistent，**明确写不等于原版
等价**）、`real_sprite_table.py` + `rotated_instance_probe.py` 的旋转实例表（oracle_runner）、
CODE 308 trex 分支夹具（oracle_runner，注明 canhit 单次锁边界）。

**验收**：给 `c-recon/fixtures/*.txt` 加一条 guard 测试——**任何 fixture 无 registry 行即
失败**（沿用 census 那套 marker 守卫，本项目已有先例）。这样"新夹具必须先声明自己是哪一层"
变成机器强制。

### #2 证据分层 / 已定案里有洞

**影响**：三条翻车（布尔 `other` 字段、CODE 308 归错家族、单轮宽相盒）都不是"不小心"，而是
**静态扫描 + 单轮测量的固有产物**；可怕的是它们都被写成过结论。目前
`boss1-trex-kill-chain.md` 已经把两次自我更正写进去了（已核对），这部分是健康样本。

**优先级：P2（制度归 #3；具体未闭环洞见 #4）**。

**最小第一批**：把两个关键洞（sprite+0x24 字段归属、trex 首次武装点）作为
`tier: "unverified"` 行写进 #3 的 registry，并在 `boss1-trex-kill-chain.md` 的边界段改成
引用该行 id 而非叙述。**验收**：guard 测试对 `tier=="unverified"` 的行要求
`blocking_reason` 字段非空——防止"未验"被悄悄改成"已验"。

### #4 trex 毒/眩晕武装链

**影响**：机制性缺口。A6/A5 已经能直派验证，缺的是"谁武装它"；不闭环的话，真机上手感会与
重写端不同（重写端永远毒不上），后续所有 boss 战断言都建在沙上。

**优先级：P2（但探针很便宜，可以插在 P1 中间做）**。

**最小第一批 —— 换搜索维度，而不是第三次静态扫**：

三次静态扫描都按 `op=store && name==stunned/poisoned/alarm && selector==0` 找，**这只会命中
字面量字段名**。如果武装走的是间接写（`variable_instance_set` / `ds_map_set` / 字段名来自
变量或字符串池），静态扫永远看不见——这恰好解释了为什么全库 0 命中但游戏里毒明显存在。

具体动作：在 full_ir 里扫**builtin 调用**（不是 store），找 `variable_instance_set` /
`variable_instance_*` / `ds_map_set` / `with(...)` 之后的动态写，看是否有 body 传入
`stunned/poisoned` 的**字符串常量**或变量。

**验收**：要么命中一个具体 body（→ 转成 A6/A5 的武装夹具，走真实派发而非直派）；要么确认
全库无间接写并**把"engine 侧武装"这一支也排除**，然后把这个结论写成 registry 里的
`unverified` 行并停止投入。**注意这个扫描还没跑**（本轮工具上限），它是假设+具体查法，
不是结论。

### #5-b CI 地板（961s × 4 分片）

**影响**：只影响等待时间，不影响正确性；但 4 分片各编 168 个二进制，是结构性重复。已有实测：
sccache 只覆盖 6/182（链接不可缓存）、mold 已进 CI、分片墙钟 6m41s。

**优先级：P3（最后做）**。

**最小第一批**：只挑一个可 A/B 的杠杆——`ci-test` profile 加 `debug = 1`，或把 Build 拆成
prep job 上传 `target/`、分片 restore（对 176 个链接单元是唯一可能真正的杠杆）。

**验收**：同提交两次 run 对比 `Summary` 总数必须仍是 **1068 passed / 4 skipped**（数字一变
即作废），墙钟按**逐 step** 报，不报整腿；按项目纪律 A/B 交替、min-of-N，测不出收益就不进 diff。

---

## 执行顺序（一句话理由）

1. **#5-a 卫生** — 30 分钟，解锁可信 diff，无风险。
2. **#6 离 detached + 增量 bundle** — 10 分钟，防丢 131 个提交。
3. **#1 分母机器化 + c-recon CI job**（同时解掉 dev_smoke 硬编码与 `objects_test.c` 死测试）
   — 把"权威方向"从散文变成 CI 里的一个数字断言。
4. **#3 equivalence-registry + fixture guard** — CI job 正好要读它，同一批落地最省事。
5. **#4 间接写探针** — 便宜的判定性实验，命中就转夹具、不命中就登记为 unverified 并停。
6. **#5-b CI 地板** — 纯等待时间，最后。

## 今天可以直接开工的第一批（3 个可独立验收的切片）

- 切片 A：产物 untrack + `.gitignore` → `build_apk.sh` 后 `git status` 干净。
- 切片 B：`git switch -c` 离开 detached + 增量 bundle + `git bundle verify`。
- 切片 C：`c-recon` CI job（`find` 生成清单 + `collision_test` + `objects_test` +
  `batch_diff` + coverage.json 断言），故意删一个 `gen/*.c` 必须 RED。

## 本轮的证据边界

- 只读核对：工作树 git 状态/worktree list/HEAD、`.github/workflows/ci.yml`、
  `c-recon/gen` 与 `c-recon/fixtures` 文件清单、`c-recon/src|tests|tools|include`、
  `scripts/` 与 `dev_smoke.sh`、`reconstruction/contracts/boss1-trex-kill-chain.md`、
  `.gitignore`。
- 未执行：1068 测试全量、`scripts/batch_diff.py`、`c-recon/tests/*` 实跑、
  k80u 状态核实（83 项脏改、落后 origin/main 111 提交仍是口述）。
- #4 的间接写假设尚未取到证据，属待验查法，不是结论。
