# opcode 差分协议（里程碑 1）

两个实现读同一份 JSONL，逐行回答同一道题，输出逐字节可比。

## 调用方式

    <binary> < cases.jsonl > out.jsonl

两个二进制都是**流式**的：每读一行、写一行，不缓冲到结束（便于定位第一处分歧）。

## 输入行

    {"id": 17, "op": "add", "mode": 0, "type": 102,
     "a": {"bytes": "0000000000000000"…(32 hex), "tag": 0},
     "b": {"bytes": "…", "tag": 7}}

    id      用例号（两个实现必须原样回显）
    op      见下表
    mode    opcode 参数里的模式位（DoAdd 的 (arg>>8)&0xF 等）；无模式时填 0
    type    opcode 参数里的类型字节（DoAdd 的 (arg>>16)&0xFF）；无类型时填 0
    a/b     两个操作数：16 字节小端 hex（32 个字符）+ tag

## 输出行

    {"id": 17, "ok": true, "sp": -16, "result": {"bytes": "…", "tag": 0}}
    {"id": 18, "ok": false, "error": "DoDiv :: Divide by zero"}

    sp      相对输入的栈顶位移（负数=下移、正数=上移），失败时为 0
    result  成功时的结果 RValue（16 字节 + tag）
    error   失败时的错误串，必须与原版 .rodata 里的文案一致（卡片里已抄录）

## op 表（第一版只做这些）

    push_immediate   a 忽略，mode 当 16 位立即数（有符号）
    dup              a = 栈顶，mode=0 普通复制
    conv             a = 源，type = (dst<<4)|src 里的 dst（见 DoConv 卡）
    add sub mul div rem mod and or xor shl shr neg not
    set_lt set_le set_eq set_ne set_ge set_gt          （DoSet 的 K=1..6）

## 判据

    两边输出逐行相等：ok、sp、result.bytes、result.tag、error 全部一致。
    第一条不等的行打印：用例号、op、两边完整输出、最小输入三元组（a/b/mode/type）。

## 明确不在这份协议里的

    变量表读写（Variable_*）、调用帧（DoCall*）、with 环境（DoPushEnv）——
    它们需要完整 VM 状态，放到里程碑 2 的整段轨迹差分里做。
