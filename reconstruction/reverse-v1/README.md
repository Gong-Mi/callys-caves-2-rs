# reverse-v1 — 原版 libyoyo.so 的 C 化逆向

目标不是"再写一个解释器"，而是把**原版 GameMaker runner** 的关键函数逐个还原成 C，
每一行都锚到二进制里的某条指令，再用差分证明与原版一致。

## 目录

    asm/index-<func>.tsv    由 scripts/asm_index.py 从 .so 生成（addr / word / mnem / operands）
    asm/<func>_0x<va>.asm   llvm-objdump 原始反汇编（证据快照）
    cards/<func>.c          逆向卡：级别 + 锚点 + C 重建
    claims.jsonl            主张账本：proven / narrowed / refuted / open

## 级别

    正文  逐行锚到指令，语义已从 asm 推出，可编译（如 Code_Execute）
    骨架  锚点全覆盖，但语义只钉了顶部几条（如 ExecuteIt）
    桩    只占位，未做

## 规矩

1. 锚点不接受手写转录：`scripts/asm_index.py` 生成 index，`scripts/check_card_anchors.py`
   逐地址比对 mnem/operands，缺一条、多一条、错一个操作数都算 FAIL。
2. 只有 `RESULT EXACT` 的卡才能往上加语义。
3. objdump 把 literal pool 的数据字译成指令时（如 `0031deec` → `eorseq`），
   卡里保留 objdump 的写法以通过比对，同时在注释里标"非指令"。
4. 主张状态必须四选一写进 claims.jsonl；`narrowed` 要写清 narrowed 到什么程度。

## 已进展

    Code_Execute  0x0cfc60..0x0cfcb4  21/21 锚点 EXACT  正文
                  纯转发 ExecuteIt；返回 0 时 Error_Show_Action(msg,false) 且全局字节写 0
    ExecuteIt     0x0cf914..0x0cfc60  211/211 锚点 EXACT  骨架
                  按 code->type([+8]) 分派：<1 或 >3 → 返回 1；1..2 → 调 [code+0x64]+4 回调后返回 1；
                  ==3 → 走唯一真正的执行路径，末尾 VM::Exec

## 下一步

    · 回溯 Code_Execute/ExecuteIt 的调用者，钉 type==1 与 type==2 的语义差别
    · 把 VM::Exec 的 9 个实参填法走通（这是"字节码怎么被执行"的核心）
    · VM::Exec 本体（大函数，需先定函数边界）之后才谈与自家 VM 的逐条差分
