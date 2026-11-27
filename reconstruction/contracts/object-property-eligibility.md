# Object value predicates and YYObjectBase property eligibility

原件固定为 `libyoyo_armv7.so`，SHA-256 `3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a`。当前共恢复六个 C++ 入口，合计 680B / 170 个 ARM 状态指令字。这里只恢复消费到的原始字与偏移，不声称完整 `YYObjectBase` 或 descriptor 布局、生命周期或原版运行等价。

| 入口 | 地址 / 大小 | 已恢复行为 |
|---|---:|---|
| `_ZN12YYObjectBase12IsExtensibleEv` | `0x19220c` / 12B | 返回对象 `+0x28` 字的 bit 0 |
| `_Z19JS_IsDataDescriptorP6RValue` | `0x2407e8` / 64B | unresolved kind 返回 0；kind 6 检查载荷对象 `+0x48` flags；其余 kind 返回 1 |
| `_Z22JS_IsGenericDescriptorP6RValue` | `0x240858` / 68B | 排除 kind 5，再依次查询 data/accessor predicates |
| `_Z23JS_IsAccessorDescriptorP6RValue` | `0x240828` / 48B | kind 6 且载荷对象 `+0x48 == 2` 时返回 1 |
| `_Z12JS_SameValueP6RValueS0_` | `0x24089c` / 212B | 按 mask 后的 kind 分派到 binary64、字符串、单字比较或常量结果 |
| `_Z9JS_CanPutP12YYObjectBasePKc` | `0x241cac` / 276B | own / prototype descriptor 写入资格分支 |

## 静态语义

- `IsExtensible` 精确做 `word(this+0x28) & 1`；`JS_CanPut@0x241cac` 在 `0x241d98` 直接调用并返回其结果。构造器原字在 `0x191934` 将 `1` 写入 `+0x28`，但构造器本体仍是未恢复依赖；这里只记录一个已消费偏移，不补全对象字段表。
- `JS_IsDataDescriptor` 计算 `(word(RValue+0x0c) & 0x00ffffff)`；kind `0x00ffffff` 返回 0，非 6 的其他 kind 返回 1；kind 6 时读取 `word(word(RValue+0)+0x48)`，该字恰等于 2 返回 0，否则返回 1。它的返回值只表示本函数实际编码的谓词，不为 descriptor 字段补造源级名字。
- `JS_IsAccessorDescriptor` 使用相同的 kind mask；kind 不等于 6 返回 0，kind=6 时仅当载荷对象 `+0x48` 字等于 2 返回 1。原件 `subs/rsbs/adcs` 序列经 32 位核算等价于 `flags == 2`；data/accessor 两个函数都只读取已观察的字段。
- `JS_IsGenericDescriptor` 先 mask `RValue+0x0c`；kind 5 返回 0。否则按原指令顺序调用 `JS_IsDataDescriptor`，非零即返回 0；再调用 `JS_IsAccessorDescriptor`，非零也返回 0；两者都为零才返回 1。由已恢复的两个 helper 合成，此谓词只在 kind `0x00ffffff` 时为 1；这只是本组已证分支的推论，不延伸为完整源级 descriptor 类型定义。
- `JS_SameValue` 先要求两个 `RValue+0x0c` 的低 24 位相等；高字节不参与 tag 比较。kind 0、7、8、11 读取双方 `RValue+0..+7` 两个 32 位字，按 little-endian binary64 做 VFP 浮点相等比较，unordered/NaN 返回 0。kind 1 沿 `RValue+0 → 载荷对象+0 → NUL 字符串` 并返回 `strcmp == 0`。kind 5、12 在 tag 相等后直接返回 1；kind 6 比较双方 `RValue+0` 单个 32 位字；kind 2、3、4、9、10 及大于 12 的 kind 返回 0。kind 数字保持原样，不为其补造源级类型名。原件唯一外部调用为 `strcmp@plt`（`0x240958 → 0x0b6574`；ELF 有 `R_ARM_JUMP_SLOT strcmp` @ `0x3f1c8c`）。
- `JS_CanPut` 仅写两个局部 RValue 镜像的 kind 字为 tag 5；不清零其他字。own descriptor kind 经 mask 后为 5 或 `0x00ffffff` 时进入 prototype 分支。own data descriptor 返回 RValue `+8` 的 bit 2；own accessor descriptor 依据载荷对象 `+4` 分支读取 kind（非零指针读 `+0x1c`，空指针则 `InternalGetYYVar(1)` 后读 RValue `+0x0c`），kind 5/`0x00ffffff` 返回 0，其余返回 1。
- 无 own descriptor 且 `YYObjectBase+0x18 == 0` 时返回 `IsExtensible`。否则走 `JS_GetProperty`：缺失/未解析或 accessor descriptor 返回 `IsExtensible`；data descriptor 返回结果 RValue `+8` 的 bit 2。bit 2 的源级字段名未恢复，不称为 `writable`。

## 真实链接与验收

`JS_CanPut` 的五条直接边是 `JS_GetOwnProperty@0x241890`、`JS_IsAccessorDescriptor@0x240828`、`JS_GetProperty@0x2418dc`、`YYObjectBase::IsExtensible@0x19220c`、`YYObjectBase::InternalGetYYVar@0x196a70`；它们在 O0/O2 正链中均由真实定义消解。分别省略 `js_helpers.cpp` 与 `object_allocation.cpp` 的负链，`JS_GetOwnProperty`/`JS_GetProperty` 与 `InternalGetYYVar` 按预期重新成为 UND。`JS_IsGenericDescriptor` 的两条直接边由已恢复的 data/accessor predicates 提供；O0/O2 正链都消解，分别移除 provider 的负控会重新留下对应 UND。该正链里的其他未恢复模块 UND 单独记录，不声称整个 object_base 或最终镜像已链接。

`JS_IsDataDescriptor` 原件 body 16/16 字核对，O0/O2 `-Werror` 编译及自身 relocatable link 通过，静态调用图为 6 个 caller / 9 个 call site。`JS_IsGenericDescriptor` body 17/17 字核对，唯一观察到的直接 caller 是 `JS_DefineOwnProperty_Internal@0x247d44` 的 `0x247e18`。

`JS_SameValue` 原件 body 53/53 字核对，O0/O2 `-Werror` 编译通过；对象只保留 `strcmp` 与 `__aeabi_unwind_cpp_pr0` 两个 UND，前者由原件 ELF 的真实 `R_ARM_JUMP_SLOT` 动态导入绑定，后者仍属 EHABI/final-link 开放项。两个观察到的 call site 均在 `JS_DefineOwnProperty_Internal@0x247d44`：`0x247de0`、`0x248328`。当前 `object_helpers.hpp` 的八个直接 include TU 加上 transitive `object_allocation.cpp`，各做 O0/O2 共 18/18 编译通过。

六个函数窗口逐字核对 170/170 字。目标未执行；最终镜像链接、行为等价、EHABI 与全类 ABI 未证。

## 未闭合项

- `YYObjectBase` 的完整大小、继承、其余字段、vtable/typeinfo 及对象生命周期仍未恢复；`+0x28` 仅是本切片观测到的位字段。
- accessor/data/generic descriptor 的源级类型与字段名、`+0x48` 标志来源、`+4` 载荷结构、`InternalGetYYVar(1)` 所指语义、RValue `+8` bit 2 的正式字段名均未证。
- `JS_Object_Put@0x24f118` 尚未恢复；其 408B 本体还直接调用 `JS_Argument_Put`、`JSThrowTypeError`、`Call_Accessor_Set`、`JS_DefineOwnProperty`、`JS_Array_Put` 和 `strcmp@plt` 等未闭合目标。`JS_DefineOwnProperty_Internal` 本身也未恢复，故其 caller 行为、错误/异常路径、EHABI 与最终镜像布线未验。没有原版执行或行为等价声明。
