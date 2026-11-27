# 剩余工作的分桶（可达集 1,307 个未出卡函数，约 441 KB）

由 `scripts/reachability.py` 的未出卡列表按名字前缀分桶得到。分桶只为排顺序，不是"跳过谁"。

    桶                    函数数    字节     处理策略
    其它（C++ 方法为主）      825   213.0 KB  按调用图逐步拉；多数是 CRoom/CLayer/CInstance 的方法但名字没前缀
    匿名区（合并块）           21    66.5 KB  先做边界切分（找 push/prologue），否则会出一张万条锚点的空卡
    Box2D                  174    64.5 KB  接口级卡（类名+关键方法签名+调用点），不逐指令还原物理内核
    YY 基础                 59    17.3 KB  需要：YYObjectBase/CVariable/YYString 一族
    房间/层                 49    14.8 KB  ★语义核心，继续逐函数正文
    实例/对象                37    10.1 KB  ★语义核心
    字符串/正则/数值            21    11.6 KB  gdtoa/json_tokener/pcre 封装，注意与 GML 数字语义的关系
    精灵/动画                11    16.2 KB  CSprite::Draw* 家族，与 DrawInstances* 配合
    GL/渲染                 40    11.6 KB  接口级
    builtin F_              24     6.7 KB  游戏实际调用的 87 个里还没出卡的（含 Ad*/ads_* 等空实现）
    变量                    25     5.6 KB  ★语义核心（Variable_GetValue/SetValue 的直系）
    事件/命令                10     1.6 KB  ★语义核心
    音频                    11     1.2 KB  接口级

## 语义核心（★）合计

    房间/层 + 实例/对象 + 变量 + 事件/命令 + builtin F_ ≈ 145 个函数 / 44 KB

这是"游戏行为"这条线真正剩下的量；剩下的 1,160 个函数是库（Box2D/GL/音频/字符串/匿名区）。

## 排期

    第 6–10 轮   房间/实例/事件的序列化与生命周期（正在进行）
    第 11–14 轮  变量与 builtin F_ 的直系依赖；CRoom/CLayer 的 Add*/Remove* 方法
    第 15 轮起   精灵/动画 + 绘制快慢路径；字符串/数值（GML 数字语义）
    最后          Box2D / GL / 音频：接口级卡（签名 + 调用点 + 关键字段），不逐指令
    单独         匿名区 21 块：先切边界，再并入上面的桶

## 判据不变

每张卡：锚点与二进制逐字一致（`check_card_anchors.py` → RESULT EXACT）、级别诚实、
open 项点名。全库收口用 `verify_reverse_v1.py`。

## 匿名区已切分（2026-10-28）

`scripts/split_anon.py` 用两个独立信号（`bl` 直接目标 + ARM prologue）把 371 个 `anon_*` 合并块切成 752 段：

    有入口证据的段        478（其余 274 段为 region-start 或纯 literal 碎片）
    ≥ 64 B                365 段 / 423.9 KB
    ≥ 1 KB                 91 段 / 332.5 KB   ← 真正要出卡的"大匿名函数"在这里
    无证据且 ≤64 B         169 段 / 2.5 KB     ← 当数据看，不出卡

切分表：`asm/anon_splits.tsv`（start / size / parent_anon / evidence）。
注意：这些段**没有符号名**，卡里只能用 `anon_<addr>` 称呼；级别最多到"骨架 + 地址锚点"，
除非从调用点/caller 的用法反推出语义。
