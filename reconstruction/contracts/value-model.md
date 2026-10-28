# 值模型契约（语义化框架的第一块）

两个实现必须按同一份值模型说话，否则差分只是在比"两个不同的东西"。本契约全部来自逆向卡里已证的指令级事实，
每条都给了出处；未证的部分明确标 open，不许在实现里偷偷补。

## 1. RValue 布局

    16 字节，类型 tag 在 offset +12 的高字节（低 24 位可能与类型/持有者信息复用）
    +0  .. +7   载荷（real 为 IEEE754 double 小端；int64 为 64 位）
    +8  .. +11  第二字（string 的 len 等；未用时为 0）
    +12 .. +15  tag 字节 + 3 字节附加位

    tag 取值 0..14（DoPushGlobal 的 15 路跳转表，claims RVALUE-002/003）

      0 / 13  real（double）            cards/DoConv.c、boxType.c
      1       string（_RefThing 12B{ptr,refcnt+4,len+8}）   cards/FREE_RValue__Pre.c
      2       array 容器{+0 refcount,+4 Chunk*,+8 holder 回指,+0x10 chunk 数}  同上
      3       pointer（bit3 = 允许虚删除）  同上
      5       undefined                cards/F_JS_ToNumber.c（RVALUE-004）
      7       int32                    cards/DoAdd.c
      10      int64                    cards/DoAdd.c
      12      null（显式 0.0）          cards/F_JS_ToNumber.c
      0x00FFFFFF  「尚未解析的变量引用」占位   cards/DoPushLocal.c、Variable_GetValue.c

## 2. 类型提升与运算（以 DoSet/DoAdd 的已证分支为准）

    比较（DoSet，opcode 21）  实数比较带 ±1e-05 容差；K=1..6 = < <= == != >= >
                              K=14/15 = === / !==；K=7..10 是 JS 抽象关系慢路径（open）
    加法（DoAdd，opcode 12）  mode=(arg>>8)&0xF；type=(左<<4)|右；tag 1 走字符串拼接
                              （YYString{+0 buf,+4 count,+8 len} 12B）
    乘法（DoMul）             字符串重复特例：Alloc(len*count+1) + 循环 strcat
    取余（DoMod）             浮点除零阈值 1e-10；常量路径把 NaN/±Inf/0 折成 0x7FFFFFFFFFFFFFFF
    除法（DoDiv）             整数除零 → VMError("DoDiv :: Divide by zero")；实数除零不判
    余数（DoRem）             **写回的是商**（__divsi3 / ldivmod 的 r0:r1）
    位运算（And/Or/Xor）      实数先 __fixdfdi 截断成 int64 → 按位 → 回 double；
                              bool×bool 为逻辑语义 tag 13；bool 与 int32 直接组合 → VMError
    移位（Shl/Shr）           快路径 int32 用 ARM 原生 lsl/asr（低 8 位、≥32 归零/符号填）；
                              慢路径才 and #31；bit15 切换 >> 与 >>>（open）

## 3. 栈效应

r1（第 2 实参）是**值栈顶指针**，处理器返回新的栈顶（cards/DoPushImmediate.c）。

    push 类      sp -= 4 / 8 / 16（按载荷宽度；DoPush 的 kind 决定 8/4/16 三档）
    pop 类       sp += count*16（DoPop 的 [15:0] 有符号 count）
    dup          sp -= n*size，拷贝 [sp-n*size, sp)
    二元运算     sp += 右宽 + 左宽 - 结果宽
    比较（DoSet）sp += 12（两操作数 16+16 → 结果 4）

## 4. 变量 id 空间

    基址 100000：脚本 id、局部槽、全局槽都用 id-100000
    槽步长 16 字节；局部表 self+4；全局表来自 GOT 单例 +4
    实例变量表 hash = key+1，只比 hash 不比 key；未命中读时惰性创建，
      默认 tag 来自 this+0x58（CInstance 构造写 0x00FFFFFF）

## 5. 错误

    VMError 不是 abort/setjmp：置 Code_Error_Occured=1 后正常返回，
      唯一终止是 g_bLaunchedFromPlayer==0 时 exit(-1)
    错误串必须用 .rodata 原文（卡里逐条抄录）：`DoDiv :: Divide by zero`、
      `DoAdd :: undefined value`、`DoAdd :: Malformed variable`、`DoSub:: Execution Error`（原文双冒号无空格）
    JSThrow 走 g_exceptionVar + g_fThrownExceptionUnwinding + UnwindExceptionStack

## 6. 本契约的 open（实现时必须显式报错，不许猜）

    · tag 4 / 6 / 8 / 9 / 11 的语义名（只在部分卡里出现）
    · DoSet K=7..10 的四个 JS 抽象关系算子
    · Shl/Shr 的 bit15 到底选 >> 还是 >>>
    · tag3 pointer 与 tag6 object 的分界（只有 6 走 DeterminePotentialRoot）
    · 16 字节里 +8..+11 在 string/array 之外的含义
