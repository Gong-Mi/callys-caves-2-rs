# 行为差分方案（离线，不碰原版 app）

前提：原版只作**静态字节来源**。运行期对照只在我们自己的两个实现之间做——
Rust VM（`crates/core`）与按逆向卡写的 C 参考实现。两边都在我们手里，可复现、可重跑。

## 差分的三条轴

    1 值栈轨迹     每条指令执行前后，栈顶 N 个 RValue 的 16 字节 + tag 必须逐字节相同
    2 变量与帧     局部/全局/实例三张表的槽号与内容、exec[0x4c] 帧深度、pc 序列
    3 错误路径     同一非法输入两个实现都必须走错误分支，错误串与后续控制流一致

像素、GL、音频、Box2D 不在差分轴内——它们与 VM 语义无关，且逆向卡只覆盖到字段读写。

## 里程碑 1：opcode 单元差分（先做这个）

不做整机，先用**随机输入**逐 opcode 比两个实现：

    输入生成   RValue 生成器覆盖 16 个字节 + tag 0..14 的组合（含 0x00FFFFFF 占位、
               NaN/±Inf/±0、空串/超长串、int32/int64 边界、数组/指针）
    每个 opcode 1000 组，固定种子（默认 0xCA11）
    被测 A      Rust：crates/core 的对应操作
    被测 B      C：按 cards/Do*.c 的语义写的参考实现（host_authored 明确标注）
    判据        栈顶内容逐字节相等 + 新 sp 相等 + 出错时错误串相等
    失败处理    落最小复现（输入三元组 + 两边输出），进 reconstruction/diff/failures/

为什么先做这个：opcode 是 VM 的原子语义，单元级差分能把"我们理解错了"和"我们实现错了"分开；
而且它不依赖整机启动、不依赖设备、不依赖原版进程。

## 里程碑 2：整段字节码轨迹差分

    夹具       从 shipped 游戏数据里取 CODE 体（crates/core/src/generated/full_ir.json 已有 1354 个）
    执行       两边都从同一初态跑同一 CODE 体，逐指令记录 (pc, opcode, sp, 栈顶 8 个 RValue)
    判据       轨迹逐条相同；出现第一条分叉时报 (指令序号, 偏移, 两边状态)
    范围       先跑 draw 与 prologue 两条链，再扩到全量 1354 体

## 现在已具备的前置条件（都来自逆向卡）

    opcode 表       asm/handler_table.tsv（32 项，0..31 ↔ Do*）
    RValue 布局     16 字节，tag 在 +12，0..14（0/13 real、1 string、2 array、3 pointer、
                    5 undefined、7 int32、10 int64）
    变量系统        id 基址 100000、槽步长 16、局部 self+4、全局 GOT 单例 +4、实例 hash=key+1
    调用帧          frame=sp-60；+0 pc/返回地址、+0x08 旧 Argument、+0x38 旧 sp 偏移、+0x4c 深度
    错误路径        VMError 置 Code_Error_Occured=1 后返回（不 abort）；JSThrow 走 UnwindExceptionStack

## 明确不做

    · 不再驱动原版 app 逐帧点按（速度上不可行、不可复现）
    · 不用截图/像素作为语义判据
    · 不把"两边都能跑"当成等价——必须有逐字节/逐条轨迹的证据
