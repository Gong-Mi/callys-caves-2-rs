# YYObjectBase property-eligibility slice

原件固定为 `libyoyo_armv7.so`，SHA-256 `3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`。本切片恢复三个 C++ 入口，共 336B / 84 个 ARM 状态指令字；`YYObjectBase` 仍是部分类型视图，不声称完整类布局、对象生命周期或原版运行等价。

| 入口 | 地址 / 大小 | 角色 |
|---|---:|---|
| `_ZN12YYObjectBase12IsExtensibleEv` | `0x19220c` / 12B | 返回对象 `+0x28` 字的 bit 0 |
| `_Z23JS_IsAccessorDescriptorP6RValue` | `0x240828` / 48B | 按 RValue kind 与对象 `+0x48` flags 识别 accessor descriptor |
| `_Z9JS_CanPutP12YYObjectBasePKc` | `0x241cac` / 276B | own / prototype descriptor 写入资格分支 |

## 静态语义

- `IsExtensible` 精确做 `word(this+0x28) & 1`；`JS_CanPut@0x241cac` 在 `0x241d98` 直接调用并返回其结果。构造器原字在 `0x191934` 将 `1` 写入 `+0x28`，但构造器本体仍是未恢复依赖；这里仅记录一个已消费偏移，不补全对象字段表。
- `JS_IsAccessorDescriptor` 先取 `RValue+0x0c` 并清高字节，kind 不等于 6 返回 0；kind=6 时取 `RValue+0` 指向对象的 `+0x48` 字，只有该字恰等于 2 返回 1。原件的 `subs/rsbs/adcs` 三指令序列经无符号 32 位核算等价于 `flags == 2`。
- `JS_CanPut` 仅写两个局部 RValue 镜像的 kind 字为 tag 5；不清零其他字。own descriptor kind 经 `& 0x00ffffff` 后为 5 或 `0x00ffffff` 时才进入 prototype 分支。own data descriptor 返回 `RValue+8` 的 bit 2；own accessor descriptor 依据其对象 `+4` 分支读取 kind（非零指针读 `+0x1c`，空指针则 `InternalGetYYVar(1)` 后读 RValue `+0x0c`），kind 5/`0x00ffffff` 返回 0，其余返回 1。
- 无 own descriptor 且 `YYObjectBase+0x18 == 0` 时返回 `IsExtensible`。否则走 `JS_GetProperty`：缺失/未解析或 accessor descriptor 返回 `IsExtensible`；data descriptor 返回结果 RValue `+8` 的 bit 2。bit 2 的源级字段名未恢复，不称为 `writable`。

## 真实链接与验收

`JS_CanPut` 的直接边是 `JS_GetOwnProperty@0x241890`、`JS_IsAccessorDescriptor@0x240828`、`JS_GetProperty@0x2418dc`、`YYObjectBase::IsExtensible@0x19220c`、`YYObjectBase::InternalGetYYVar@0x196a70`；提供者均已在同模块恢复。

ARMv7 O0/O2 双档 `-Werror` 编译通过。父级 `ld.lld -r` 正链后，三个新符号均为定义，五条直接依赖均从 UND 消解；分别去掉 `js_helpers.cpp` 与 `object_allocation.cpp` 的负链，预期 `JS_GetOwnProperty`/`JS_GetProperty` 与 `InternalGetYYVar` 恢复为 UND。对象内重定位确认 `JS_CanPut` 保留对两个新 helper 的调用边。原件窗口逐字核对 84/84 字。目标未执行，最终镜像链接、调用者行为和全类 ABI 仍未证。

## 未闭合项

- `YYObjectBase` 的完整大小、继承、其余字段、vtable/typeinfo 及对象生命周期仍未恢复；`+0x28` 仅是本切片观测到的位字段。
- accessor descriptor 的 `+0x48` 标志来源、`+4` 载荷结构、`InternalGetYYVar(1)` 所指语义、RValue `+8` bit 2 的正式字段名、源级返回类型 spelling 均未证。
- `JS_CanPut` 的上层写入调用者、错误/异常路径、EHABI 与最终镜像布线未验；没有原版执行或行为等价声明。
