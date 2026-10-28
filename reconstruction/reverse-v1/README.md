# reverse-v1 — 原版 libyoyo.so 的 C 化逆向

目标不是"再写一个解释器"，而是把**原版 GameMaker runner** 逐函数还原成 C，
每一行都锚到二进制里的某条指令，再用**离线**手段（ART / javam 跑我们自己的实现）做行为差分。

**不做实时操作 app 的差分**：一遍遍驱动原版 app 在速度上不可行，也不可复现。
原版只作为静态字节来源；运行期对照一律在我们自己的 harness 里完成。

## 二进制

    libyoyo.so   ELF32 ARM (armeabi-v7a)，4,689,844 B，stripped
    sha256 3bbedd09ad0cc60f3f3cad86a257275f…（取自 APK 的 lib/armeabi-v7a/libyoyo.so）
    .text  0x000b6fd0..0x0031bb7c，2,509,740 B

## 覆盖账（"逆向完全部"的唯一口径）

    instructions        627,423      .text 里每一条 32 位指令
    attributed          627,423      100.00%，无未归属
    functions           9,623        含 371 个匿名区间（stripped 的静态函数/跳转表）
    有指令的函数        8,722
    零指令符号          562          别名/重叠符号，锚点记在拥有该地址的那一个上
    地址别名            337          同一地址多个符号名，只发一次锚点

    校验 scripts/check_bank_coverage.py → anchors=627,423 / duplicates=0 / missing=0
         / orphan=0 / mnemonic_mismatch=0 / RESULT TOTAL

## 目录

    asm/census.json           总量与归属统计
    asm/functions.tsv         9,623 行：addr / size / demangled / mangled / 首末指令 / 指令数
    asm/instructions.jsonl.xz 全部指令（a/w/m/o/f），45 MB → 3.8 MB
    asm/index-<func>.tsv      单函数索引（核心函数用）
    asm/<func>_0x<va>.asm     llvm-objdump 原始反汇编快照
    cards/<func>.c            人工逆向卡：级别 + 语义 + 逐条锚点
    cards/auto/bank_*.c       301 个自动覆盖卡组，含全部 9,623 个函数的逐条锚点
    claims.jsonl              主张账本：proven / narrowed / refuted / open

## 级别

    正文      逐行锚到指令，语义已从 asm 推出，可编译（Code_Execute）
    骨架      锚点全覆盖，语义只钉了顶部几条（ExecuteIt / VM::Exec / VM::ExecRelease）
    原始覆盖  锚点全覆盖，语义未钉（cards/auto 全部）

## 规矩

1. 锚点不接受手写转录：`asm_index.py` / `libyoyo_census.py` 从二进制生成，
   `check_card_anchors.py`（单卡）与 `check_bank_coverage.py`（全库）逐地址比对。
2. 只有 `RESULT EXACT` / `RESULT TOTAL` 才允许往上加语义。
3. objdump 把 literal pool 数据字译成指令时（如 `0031deec` → `eorseq`），
   卡里保留 objdump 写法，同时在注释里标"非指令"。
4. 主张状态四选一进 claims.jsonl；`narrowed` 必须写 narrowed 到什么程度。
5. 覆盖度 ≠ 语义等价：627,423 个锚点只证明"每条指令都被指到"，不证明"理解对了"。

## 已钉的语义

    Code_Execute    0x0cfc60   21 条  EXACT  正文
      纯转发 ExecuteIt；返回 0 时 Error_Show_Action(msg,false) + 全局字节写 0
    ExecuteIt       0x0cf914  211 条  EXACT  骨架
      按 code->type([+8]) 分派：<1 或 >3 → 返回 1；1..2 → 调 [code+0x64]+4 回调后返回 1；
      ==3 → 唯一真正执行路径，末尾 VM::Exec
    VM::Exec        0x0e7fd0  366 条  EXACT  骨架
      按全局 debug 标志二选一，分别调 ExecDebug(0xe47c8, 992 B) / ExecRelease(0xe4540, 648 B)
    VM::ExecRelease 0x0e4540  162 条  EXACT  骨架
      线程化派发：r6 = [VMExec+0x58][pc]，pc+1 写回 [+0x48]，blx r6；PerformReturn 走退栈

## 结构结论

原版没有 opcode 比较链，也没有跳转表分支树：`VMExec+0x58` 是一张**预解析的处理器指针表**，
主循环取表项后 `blx`。语义全在 48 个 `DoXxx(int, uchar* ip, uchar* base, VMExec*)` 里，
合计 70,532 B ≈ 17,633 条指令（最大 DoSet 7,452 B、DoPop 6,088 B、DoPush 5,488 B、DoAdd 4,060 B）。

## 下一步

    · 48 个 Do* 处理器逐个出卡（小 → 大），每张跑 check_card_anchors
    · 处理器齐了以后，在 javam/ART harness 里跑同一段 GML 字节码，比对
      "我们的 VM 状态轨迹"与"按 C 卡实现的轨迹"——两边都在我们手里，不碰原版 app
    · cards/auto 里的 8,722 个函数按调用图逐步升级为骨架/正文，优先 Do* 的直接依赖
