# 子代理批次中断的处置与打捞（2026-10-28 第三批，10 并发）

## 发生了什么

一次派 10 个并发子代理（本机上限）去解 13 个 `Init*Functions` + pcre + 类族 + 匿名段 + 音频。
**父进程在 19 分钟时被杀**（`Delegation owner exited before recording a terminal result`），
10 个子任务一个卡都没落盘。这是本周第二次整批丢失（上次是 7 并发，丢了 14 张卡中的 10 张）。

## 从中得到的操作结论

    并发上限用 4，不再用 10
      理由：子代理每个都在跑 ELF 扫描 + LLVM 反汇编 + 几万行 Python，10 并发把内存打满，
      父进程先死，子代理的产出全部回不来。

    子代理必须增量落盘
      任务书里明确要求：先写卡头 + 第一节 → 跑 check → 落盘 → 再追加下一节。
      这样即使被杀，盘上留下的是"半张卡"而不是"零张卡"。

    每批回来先 git status，不看子代理自述
      两次事故里，子代理的 transcript 都显得"接近完成"，但盘上什么都没有。
      以 `git status` + `verify_reverse_v1.py` 为准。

## 打捞：死掉的 10 个任务里已经算出来的中间结果

这些数字来自被打断的 transcript，**未落到卡上、未复核**，只作下一批的起点线索：

    InitGraphicFunctions   273 个不同目标地址；与本仓库已出卡 Builtins 体的地址交集 15 个
                           （0x119bc4/0x119bf4 display_*、0x11a59c/0x11a5cc window_*、0x11a9c4/0x11a9dc draw_set_*、
                             0x11b2e4 draw_healthbar、0x11bd58 draw_set_font、0x11db10/0x11dbd4 draw_background(_ext)、
                             0x121d70 draw_text、0x121fd8 draw_text_color、0x122748/0x1227c0 draw_sprite(_ext)、0x123134 draw_self）
                           与游戏实际调用名交集 15 个
    InitDataStructures     130 条（首 ds_set_precision、末 ds_grid_sort；无重名；flag 全 1；
                           argc 1×45 / 2×30 / 0×5 / 3×19 / 4×9 / 5×10 / 6×6 / 8×3 / -1×3）
    InitMathFunctions      117 条（首 is_bool、末 angle_difference；
                           argc 1×62 / 2×18 / 3×17 / -1×6 / 5×1 / 0×4 / 4×5 / 6×4）
    InitMiscFunctions      三支（main 4 条 + 两条 bne 分支各 71/92 条）；external_* 在 fall 支
    InitGameFunctions      有一道字节门（GOT 0x3ef054→0x755363、0x3ed92c→0x5428e8）会跳过部分注册
    Audio_Quit             0x21a664 遍历 `*(0x75529c)+0x34` 计数后 MemoryManager::Free

## 已重新派出的批次（4 并发）

    InitGraphicFunctions        清单化
    InitCore1                    InitDataStructures + InitMath（重点求与 87 个 builtin 的交集）
    InitCore2                    InitAction + InitInteraction + InitGame（含字节门）
    Audio.c                      Audio_/Sound_ 主要函数

剩下待派：InitResource+3D、InitSound+Particles+File、InitPhysics、pcre compile_branch、
CPath/CSkeleton/CVariable/CTimeLine、anon_batch6。
