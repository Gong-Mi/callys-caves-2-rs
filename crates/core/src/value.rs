//! 带 tag 的值模型 —— `reconstruction/contracts/value-model.md` 的 Rust 侧。
//!
//! 原来的 `code_vm` 把整个栈摊成 `f64`：tag 没有位置，int32/int64 的宽度、
//! 整数的回绕、`undefined`/`null`、字符串引用全都被折进 double 的位模式里。
//! 本模块把那 16 字节 RValue 的**类型**部分显式化：
//!
//! ```text
//! Value { tag: u8, payload }        // tag 取值见 value-model.md §1
//!   0 / 13  Real(f64)      double（DoConv 卡 dst=5 叶子写 tag 0；tag 13 是 bool 的
//!                          RValue 表示：8 字节 double 的 0.0/1.0 只换 tag）
//!   1       Str(u32)       string，载荷是**池下标**（见下）
//!   2       Opaque(u32)    array（本 crate 不建模容器，只保留 tag 好让算子按卡报错）
//!   3       Opaque(u32)    pointer（同上；bit3 = 允许虚删除，未建模）
//!   5       Undefined
//!   7       Int32(i32)
//!   10      Int64(i64)
//!   12      Null           显式 0.0（card: F_JS_ToNumber.c / RVALUE-004）
//! ```
//!
//! # 为什么 `Str` 是池下标而不是指针
//!
//! 原版的 tag 1 是 `_RefThing<const char*>{text, refcnt, len}` 的指针，指向堆缓冲。
//! 这里没有那块堆 —— 字符串池的所有权在 host（`ir_scene::Scene` 的
//! `dynamic_strings` + bundle 的 `string_table`），VM 只是拿着一个下标。下标空间
//! 与旧编码一一对应：
//!
//! ```text
//!     index <  bundle.string_table.len()            → bundle 里的字面量
//!     index >= bundle.string_table.len()            → host 运行期建的第 (index - len) 个串
//! ```
//!
//! 旧的 `STRING_REF_BASE + index` 编码仍然保留在 `to_legacy_numeric` /
//! `from_legacy_numeric` 里，因为 `ir_scene` 的实例变量表还是数字表
//! （`BTreeMap<String, f64>`）——见 `Value` 的「边界编码」一节。
//!
//! # 边界编码（不是值模型的一部分）
//!
//! `Scene` 的字段/数组/全局表是 `f64`，60 个内建也是 `f64`。值跨过 host 边界时
//! 用 `to_legacy_numeric`（数字原值、字符串回到 `STRING_REF_BASE + index`）折算，
//! 回来时用 `from_legacy_numeric` 还原 tag。**这是迁移中的过渡层**，不是值模型：
//! 它保得住数字与字符串引用，保不住 bool/undefined/null 的 tag（存进 f64 表就只剩
//! 数值）。哪些边界还该改成 `Value`，见仓库里 `Host::call` 的注释。
use std::fmt;

/// tag 0：real（8 字节 double）。
pub const TAG_REAL: u8 = 0;
/// tag 1：string（载荷是池下标，不是指针）。
pub const TAG_STRING: u8 = 1;
/// tag 2：array 容器。
pub const TAG_ARRAY: u8 = 2;
/// tag 3：pointer（载荷 bit3 = 允许虚删除，未建模）。
pub const TAG_POINTER: u8 = 3;
/// tag 5：undefined。
pub const TAG_UNDEFINED: u8 = 5;
/// tag 7：int32。
pub const TAG_INT32: u8 = 7;
/// tag 10：int64。
pub const TAG_INT64: u8 = 10;
/// tag 12：null（显式 0.0）。
pub const TAG_NULL: u8 = 12;
/// tag 13：real 的第二编码 —— 原版在 RValue 里把 bool 写成 8 字节 double 的
/// 0.0/1.0 只换 tag（DoConv 卡 dst=5 叶子、DoAnd/DoXor 的 bool 内核）。
pub const TAG_BOOL: u8 = 13;
/// `0x00FFFFFF`「尚未解析的变量引用」占位。它是 24 位值，装不进 `u8` 的 `tag`
/// 字段，所以这里用 `0xFF` 当哨兵，原始 24 位值放在 `Payload::Opaque` 里。
pub const TAG_UNRESOLVED: u8 = 0xff;

/// 旧的字符串引用编码基点（2^40）。值模型里字符串是 `Str(index)`，这个常量只剩
/// 「host 边界的数字表编码」一个用途。
pub const STRING_REF_BASE: f64 = 1_099_511_627_776.0;

/// DoSet 的实数比较容差：`==` 是 `|左-右| <= 1e-05`，不是位相等
/// （DoSet 卡结论 3，常量在 .data 里经 GOT 两跳取）。
pub const COMPARE_EPSILON: f64 = 1e-05;

/// 值的载荷。`tag` 说「这是什么」，`payload` 说「值多大」。
///
/// `Opaque` 是值模型之外唯一多出来的分支：tag 2/3（以及 4/6/8/9/11 这些契约为
/// open 的 tag）在契约里只有 tag、没有已证的载荷布局。op_eval 要把输入的 tag
/// **原样**交给库，就必须能装住它们，所以留一条原始字（不参与任何运算，只用于
/// 报错与回显）。
#[derive(Debug, Clone, Copy, PartialEq)]
pub enum Payload {
    Real(f64),
    Int32(i32),
    Int64(i64),
    Str(u32),
    Undefined,
    Null,
    Bool(bool),
    Opaque(u32),
}

/// 16 字节 RValue 的类型 + 载荷。`Copy` 是有意的：Dup、局部变量、栈搬运都靠它。
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Value {
    pub tag: u8,
    pub payload: Payload,
}

impl Value {
    pub const fn real(v: f64) -> Self {
        Value { tag: TAG_REAL, payload: Payload::Real(v) }
    }
    pub const fn int32(v: i32) -> Self {
        Value { tag: TAG_INT32, payload: Payload::Int32(v) }
    }
    pub const fn int64(v: i64) -> Self {
        Value { tag: TAG_INT64, payload: Payload::Int64(v) }
    }
    /// 字符串引用：`index` 是池下标（见模块文档）。
    pub const fn string(index: u32) -> Self {
        Value { tag: TAG_STRING, payload: Payload::Str(index) }
    }
    pub const fn boolean(v: bool) -> Self {
        Value { tag: TAG_BOOL, payload: Payload::Bool(v) }
    }
    pub const fn undefined() -> Self {
        Value { tag: TAG_UNDEFINED, payload: Payload::Undefined }
    }
    pub const fn null() -> Self {
        Value { tag: TAG_NULL, payload: Payload::Null }
    }
    /// 契约里只有 tag、没有载荷布局的那些值（array/pointer/占位/open tag）。
    pub const fn opaque(tag: u8, raw: u32) -> Self {
        Value { tag, payload: Payload::Opaque(raw) }
    }

    /// tag 0/13 —— 契约里两个都是 real（13 是 bool 的 RValue 编码，载荷仍是 double）。
    pub fn is_real(&self) -> bool {
        matches!(self.payload, Payload::Real(_) | Payload::Bool(_))
    }
    pub fn is_string(&self) -> bool {
        self.tag == TAG_STRING
    }
    /// `0x00FFFFFF` 占位（tag 用 `TAG_UNRESOLVED` 哨兵表示）。
    pub fn is_unresolved(&self) -> bool {
        self.tag == TAG_UNRESOLVED
    }

    /// 契约名，只用于报错和调试。
    pub fn type_name(&self) -> &'static str {
        match self.payload {
            Payload::Real(_) => "real",
            Payload::Int32(_) => "int32",
            Payload::Int64(_) => "int64",
            Payload::Str(_) => "string",
            Payload::Undefined => "undefined",
            Payload::Null => "null",
            Payload::Bool(_) => "bool",
            Payload::Opaque(_) => match self.tag {
                TAG_ARRAY => "array",
                TAG_POINTER => "pointer",
                TAG_UNRESOLVED => "unresolved variable",
                _ => "opaque",
            },
        }
    }

    /// 实数化。int32/int64 按值升、bool 走 0.0/1.0、null 是显式 0.0；
    /// 字符串与 undefined 没有数值（ToNumber 需要文本 / 是 NaN），这里报错而不是
    /// 偷偷给 0 —— 调用点要 0 就得自己说清楚。
    pub fn to_real(&self) -> Result<f64, String> {
        match self.payload {
            Payload::Real(v) => Ok(v),
            Payload::Int32(v) => Ok(v as f64),
            Payload::Int64(v) => Ok(v as f64),
            Payload::Bool(v) => Ok(if v { 1.0 } else { 0.0 }),
            Payload::Null => Ok(0.0),
            _ => Err(format!("{} (tag {}) has no real value", self.type_name(), self.tag)),
        }
    }

    /// int32。real 走 vcvt.s32 的语义（向零截断、饱和、NaN→0），int64 截断取低
    /// 32 位（DoConv 卡 dst2←3 是 4 字节拷贝）。
    pub fn to_int32(&self) -> Result<i32, String> {
        match self.payload {
            Payload::Real(v) => Ok(f2i32(v)),
            Payload::Int32(v) => Ok(v),
            Payload::Int64(v) => Ok(v as i32),
            Payload::Bool(v) => Ok(if v { 1 } else { 0 }),
            Payload::Null => Ok(0),
            _ => Err(format!("{} (tag {}) has no int32 value", self.type_name(), self.tag)),
        }
    }

    /// int64。real 走 __fixdfdi 的语义（向零截断、饱和、NaN→INT64_MIN）。
    pub fn to_int64(&self) -> Result<i64, String> {
        match self.payload {
            Payload::Real(v) => Ok(f2i64(v)),
            Payload::Int32(v) => Ok(v as i64),
            Payload::Int64(v) => Ok(v),
            Payload::Bool(v) => Ok(if v { 1 } else { 0 }),
            Payload::Null => Ok(0),
            _ => Err(format!("{} (tag {}) has no int64 value", self.type_name(), self.tag)),
        }
    }

    /// 真值（JS_ToBoolean / GML 的「非零即真」）。字符串在这里按非空处理 ——
    /// 空串要读文本，那是 host 的事（`Host::string_text`）。
    pub fn to_bool(&self) -> bool {
        match self.payload {
            Payload::Real(v) => v != 0.0,
            Payload::Int32(v) => v != 0,
            Payload::Int64(v) => v != 0,
            Payload::Bool(v) => v,
            Payload::Str(_) => true,
            Payload::Undefined | Payload::Null => false,
            Payload::Opaque(_) => true,
        }
    }

    /// 只有 real 可能非有限；整数与 bool 永远有限。栈上「不许出现非有限值」的
    /// 老不变量靠这个判。
    pub fn is_finite(&self) -> bool {
        match self.payload {
            Payload::Real(v) => v.is_finite(),
            _ => true,
        }
    }

    /// 数字表的边界编码（不是值模型的一部分，见模块文档）。数字给原值，字符串回到
    /// `STRING_REF_BASE + index`；bool 折成 1.0/0.0，null 是 0.0；undefined 与
    /// array/pointer 在数字表里没有表示 → 报错。
    pub fn to_legacy_numeric(&self) -> Result<f64, String> {
        match self.payload {
            Payload::Real(v) => Ok(v),
            Payload::Int32(v) => Ok(v as f64),
            Payload::Int64(v) => Ok(v as f64),
            Payload::Bool(v) => Ok(if v { 1.0 } else { 0.0 }),
            Payload::Null => Ok(0.0),
            Payload::Str(index) => Ok(STRING_REF_BASE + index as f64),
            _ => Err(format!("{} (tag {}) cannot be stored in the numeric table", self.type_name(), self.tag)),
        }
    }

    /// 数字表里的值还原成带 tag 的值。`>= STRING_REF_BASE` 的整数回到 tag 1，
    /// 其余一律 real（数字表分不出 int32 与 double，那是旧模型的损失，不在这里补）。
    pub fn from_legacy_numeric(v: f64) -> Value {
        if v.is_finite() && v >= STRING_REF_BASE {
            let offset = v - STRING_REF_BASE;
            if offset.fract() == 0.0 && offset <= u32::MAX as f64 {
                return Value::string(offset as u32);
            }
        }
        Value::real(v)
    }
}

impl fmt::Display for Value {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result { write!(f, "{}:{}", self.type_name(), self.tag) }
}

/// `vcvt.s32.f64`：向零截断，饱和，NaN→0（DoConv/DoRem 卡里 ARM 的实际行为）。
pub fn f2i32(v: f64) -> i32 {
    if v.is_nan() {
        return 0;
    }
    if v >= 2147483648.0 {
        return i32::MAX;
    }
    if v <= -2147483648.0 {
        return i32::MIN;
    }
    v as i32
}

/// `__fixdfdi`：向零截断，饱和，NaN→INT64_MIN（diff/c/vm_ref.c 的 f2i64 同式）。
pub fn f2i64(v: f64) -> i64 {
    if v.is_nan() {
        return i64::MIN;
    }
    if v >= 9223372036854775808.0 {
        return i64::MAX;
    }
    if v <= -9223372036854775808.0 {
        return i64::MIN;
    }
    v as i64
}

/// 一个算子的报错模板。站点号那条是原版 .rodata 的写法，不是排版：
/// DoSub/DoDiv/DoAnd/DoConv/DoSet 的 tag 表错误串是 `'<Op> :1: illegal array use'`
/// （左右两侧的站点号），而 DoAdd/DoMul 只抄到不带站点号的 `'<Op> :: ...'`。
#[derive(Clone, Copy, Debug)]
pub struct Verdict {
    pub name: &'static str,
    /// 错误串带站点号（`DoSub :1: ...`）还是双冒号（`DoAdd :: ...`）。
    pub site: bool,
    /// 该算子的 Execution Error 原文；DoSub 的原文是**双冒号无空格**。
    pub execution: &'static str,
}

impl Verdict {
    fn tagged(&self, side: u8, what: &str) -> String {
        if self.site {
            format!("{} :{}: {}", self.name, side, what)
        } else {
            format!("{} :: {}", self.name, what)
        }
    }
    fn unsupported_string(&self) -> String {
        format!("{} :: Execution Engine - Cannot operate on string type", self.name)
    }
    fn exec(&self) -> String { self.execution.to_string() }
    fn illegal_use(&self, side: u8, tag: u8) -> String {
        match tag {
            TAG_ARRAY => self.tagged(side, "illegal array use"),
            TAG_POINTER => self.tagged(side, "illegal pointer use"),
            _ => self.tagged(side, "Malformed variable"),
        }
    }
}

pub const ADD: Verdict = Verdict { name: "DoAdd", site: false, execution: "DoAdd :: Execution Error" };
pub const SUB: Verdict = Verdict { name: "DoSub", site: true, execution: "DoSub:: Execution Error" };
pub const MUL: Verdict = Verdict { name: "DoMul", site: false, execution: "DoMul :: Execution Error" };
pub const DIV: Verdict = Verdict { name: "DoDiv", site: true, execution: "DoDiv :: Execution Error" };
pub const AND: Verdict = Verdict { name: "DoAnd", site: true, execution: "DoAnd :: Execution Error" };
pub const SET: Verdict = Verdict { name: "DoSet", site: true, execution: "DoSet :: Execution Error" };
pub const CONV: Verdict = Verdict { name: "DoConv", site: true, execution: "DoConv :: Execution Error" };

/// 算术操作数的存储类。契约的 0/3 是 8 字节、2 是 4 字节 —— 这里只留「宽度语义」
/// 三个档：real 走 double、int32 走 32 位回绕、int64 走 64 位。
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum NumClass {
    Real,
    Int32,
    Int64,
}

impl Value {
    /// 按卡片把操作数折进三个类之一。tag 13（bool）在 DoAdd/DoShl 的 14 路 tag 表里
    /// 都归进 real 类（DoAdd 卡 T4/T5 把 0 和 13 放同一支），所以 bool 这里也是
    /// Real —— 载荷本来就是 double 的 0.0/1.0。
    pub fn arithmetic_class(&self, verdict: &Verdict, side: u8) -> Result<NumClass, String> {
        match self.payload {
            Payload::Real(_) | Payload::Bool(_) => Ok(NumClass::Real),
            Payload::Int32(_) => Ok(NumClass::Int32),
            Payload::Int64(_) => Ok(NumClass::Int64),
            Payload::Str(_) => Err(verdict.unsupported_string()),
            Payload::Undefined => Err(verdict.tagged(side, "undefined value")),
            // tag 12 在卡片的 tag 表里落 default 支：DoAdd 卡「其余（4/6/8/9/11/12
            // 及 >13）→ Malformed variable」。null 的载荷是显式 0.0，但**算术**不看
            // 载荷 —— 只有 JS ToNumber 慢路径（mode1/2）才把它折成 0，而 lowered IR
            // 走的是强类型 tag 表这条。
            Payload::Null => Err(verdict.tagged(side, "Malformed variable")),
            Payload::Opaque(_) => Err(verdict.illegal_use(side, self.tag)),
        }
    }

    /// `左 + 右`。字符串拼接**不在这里**：GMS 的 `+` 在任一侧是 string 时走
    /// DoAdd mode1 的 ToString 两连，那需要 host 的字符串池，由 `code_vm` 调
    /// `Host::string_concat`。
    pub fn add(self, rhs: Value) -> Result<Value, String> {
        let a = self.arithmetic_class(&ADD, 1)?;
        let b = rhs.arithmetic_class(&ADD, 2)?;
        if a == NumClass::Real || b == NumClass::Real {
            Ok(Value::real(self.to_real()? + rhs.to_real()?))
        } else if a == NumClass::Int64 || b == NumClass::Int64 {
            // DoAdd 0x33/0x32/0x23：64 位 adds+adc，tag 10（32 位那侧先 asr #31 符号扩展）
            Ok(Value::int64(self.to_int64()?.wrapping_add(rhs.to_int64()?)))
        } else {
            // DoAdd 0x22：32 位回绕加法，tag 7
            Ok(Value::int32(self.to_int32()?.wrapping_add(rhs.to_int32()?)))
        }
    }

    /// `左 - 右`（DoSub：rsb/subs 取 A-B，含 real 时 vsub.f64）。
    pub fn sub(self, rhs: Value) -> Result<Value, String> {
        let a = self.arithmetic_class(&SUB, 1)?;
        let b = rhs.arithmetic_class(&SUB, 2)?;
        if a == NumClass::Real || b == NumClass::Real {
            Ok(Value::real(self.to_real()? - rhs.to_real()?))
        } else if a == NumClass::Int64 || b == NumClass::Int64 {
            Ok(Value::int64(self.to_int64()?.wrapping_sub(rhs.to_int64()?)))
        } else {
            Ok(Value::int32(self.to_int32()?.wrapping_sub(rhs.to_int32()?)))
        }
    }

    /// `左 * 右`（DoMul）。字符串路径是「次数 × 串」的重复（pair 6/38，要在 host 的
    /// 池里重新分配缓冲），VM 侧没有分配口子，所以字符串操作数一律按 DoMul 卡里
    /// 存在的 `DoMul :: Execution Error` 报错。
    pub fn mul(self, rhs: Value) -> Result<Value, String> {
        if self.is_string() || rhs.is_string() { return Err(MUL.exec()); }
        let a = self.arithmetic_class(&MUL, 1)?;
        let b = rhs.arithmetic_class(&MUL, 2)?;
        if a == NumClass::Real || b == NumClass::Real {
            Ok(Value::real(self.to_real()? * rhs.to_real()?))
        } else if a == NumClass::Int64 || b == NumClass::Int64 {
            Ok(Value::int64(self.to_int64()?.wrapping_mul(rhs.to_int64()?)))
        } else {
            Ok(Value::int32(self.to_int32()?.wrapping_mul(rhs.to_int32()?)))
        }
    }

    /// `左 / 右`（DoDiv）。整数除零是软错误 `DoDiv :: Divide by zero`；**实数除零
    /// 不判**（DoDiv 卡：vdiv.f64 出 IEEE ±inf/NaN，原版不报错）。
    pub fn div(self, rhs: Value) -> Result<Value, String> {
        let a = self.arithmetic_class(&DIV, 1)?;
        let b = rhs.arithmetic_class(&DIV, 2)?;
        if a == NumClass::Real || b == NumClass::Real {
            return Ok(Value::real(self.to_real()? / rhs.to_real()?));
        }
        if a == NumClass::Int64 || b == NumClass::Int64 {
            let d = rhs.to_int64()?;
            let n = self.to_int64()?;
            if d == 0 {
                return Err("DoDiv :: Divide by zero".to_string());
            }
            // d == -1 时 n/d 溢出（INT64_MIN / -1），ARM 上 __aeabi_ldivmod 给回
            // 两补码的 -n，这里照抄 0u64 - n。
            return Ok(Value::int64(if d == -1 { (0u64.wrapping_sub(n as u64)) as i64 } else { n / d }));
        }
        let d = rhs.to_int32()?;
        let n = self.to_int32()?;
        if d == 0 {
            return Err("DoDiv :: Divide by zero".to_string());
        }
        Ok(Value::int32(if d == -1 { 0u32.wrapping_sub(n as u32) as i32 } else { n / d }))
    }

    /// `左 & 右`（DoAnd）。bool×bool 是**逻辑**语义（短路与，结果 tag 13）；其余按
    /// GML 的位算 = ToInt64(左) & ToInt64(右)，实数参与时写回 double。
    pub fn bit_and(self, rhs: Value) -> Result<Value, String> {
        if let (Payload::Bool(x), Payload::Bool(y)) = (self.payload, rhs.payload) {
            return Ok(Value::boolean(x && y));
        }
        let a = self.arithmetic_class(&AND, 1)?;
        let b = rhs.arithmetic_class(&AND, 2)?;
        if a == NumClass::Real || b == NumClass::Real {
            Ok(Value::real((self.to_int64()? & rhs.to_int64()?) as f64))
        } else if a == NumClass::Int64 || b == NumClass::Int64 {
            Ok(Value::int64(self.to_int64()? & rhs.to_int64()?))
        } else {
            Ok(Value::int32(self.to_int32()? & rhs.to_int32()?))
        }
    }

    /// DoSet 的 K=1..6：`< <= == != >= >`。整数对走精确整数比较；任一侧是 real
    /// （含 tag 13）时按卡片的 ±1e-05 容差比较差值。结果写 4 字节整数（tag 7，
    /// DoSet 卡：结果是一个 4 字节整数）。
    ///
    /// K=7..10（JS 抽象关系慢路径）与 K=14/15（===/!==）在契约里是 open，且
    /// 生成的 IR 一次也没发过，这里保持原来的 `unsupported comparison`。
    pub fn compare(self, rhs: Value, comparison: u8) -> Result<Value, String> {
        let a = self.arithmetic_class(&SET, 1)?;
        let b = rhs.arithmetic_class(&SET, 2)?;
        let truth = if a != NumClass::Real && b != NumClass::Real {
            let x = self.to_int64()?;
            let y = rhs.to_int64()?;
            match comparison {
                1 => x < y,
                2 => x <= y,
                3 => x == y,
                4 => x != y,
                5 => x >= y,
                6 => x > y,
                _ => return Err("unsupported comparison".to_string()),
            }
        } else {
            let diff = self.to_real()? - rhs.to_real()?;
            if diff.is_nan() {
                // vcmpe 无序时走 movls/movge 那一侧：只有 != 得 1。
                comparison == 4
            } else {
                match comparison {
                    1 => diff < -COMPARE_EPSILON,
                    2 => diff <= COMPARE_EPSILON,
                    3 => diff.abs() <= COMPARE_EPSILON,
                    4 => diff.abs() > COMPARE_EPSILON,
                    5 => diff >= -COMPARE_EPSILON,
                    6 => diff > COMPARE_EPSILON,
                    _ => return Err("unsupported comparison".to_string()),
                }
            }
        };
        Ok(Value::int32(if truth { 1 } else { 0 }))
    }

    /// 逻辑非（DoNot mode1：JS_ToBoolean 后取反，写 4 字节整数）。
    pub fn logical_not(self) -> Value {
        Value::int32(if self.to_bool() { 0 } else { 1 })
    }

    /// DoConv 的类型码转换（`to` = dst，类型码 0..6 见 DoConv 卡）。
    ///
    /// * 0 real / 1 float32：`1` 先经 f32 再宽回 double（原版 vcvt.f32/vcvt.f64）
    /// * 2 int32 / 3 int64：截断语义见 `to_int32`/`to_int64`
    /// * 4 bool：real > 0.5、int32 > 0、int64 >= 1、string 与 "true" 比较
    /// * 5 动态：把 4 字节的整数槽**加宽**进 16 字节 RValue（int32 → real，tag 0），
    ///   其余原样保留自己的 tag
    /// * 6 string：要在 host 的池里分配文本（原版 snprintf + YYStrDup），VM 没有池
    ///   → 交给调用方报 `unsupported cast`
    pub fn cast(self, to: u8) -> Result<Value, String> {
        if self.is_unresolved() {
            return Err("DoConv :1: Could not find variable".to_string());
        }
        match to {
            0 => Ok(Value::real(self.conv_real()?)),
            1 => Ok(Value::real(self.conv_real()? as f32 as f64)),
            2 => Ok(Value::int32(self.conv_int32()?)),
            3 => Ok(Value::int64(self.conv_int64()?)),
            4 => Ok(Value::boolean(self.conv_bool()?)),
            5 => match self.payload {
                // dst=5 的 int32 叶子写 s32→f64 + tag 0（DoConv 卡 0xeb9f4）
                Payload::Int32(v) => Ok(Value::real(v as f64)),
                Payload::Str(_) | Payload::Undefined | Payload::Null => Ok(self),
                Payload::Real(_) | Payload::Int64(_) | Payload::Bool(_) => Ok(self),
                Payload::Opaque(_) => Err(CONV.illegal_use(1, self.tag)),
            },
            6 => Err("unsupported cast".to_string()),
            _ => Err(CONV.exec()),
        }
    }

    fn conv_real(self) -> Result<f64, String> {
        match self.payload {
            Payload::Real(v) => Ok(v),
            Payload::Int32(v) => Ok(v as f64),
            Payload::Int64(v) => Ok(v as f64),
            Payload::Bool(v) => Ok(if v { 1.0 } else { 0.0 }),
            // DoConv 的动态源把 tag 5 / tag 12 都派到 class 4 叶子（零），
            // 载荷就是 0.0 / false（claims RVALUE-004）。
            Payload::Null | Payload::Undefined => Ok(0.0),
            Payload::Str(_) => Err("unsupported cast".to_string()),
            Payload::Opaque(_) => Err(CONV.illegal_use(1, self.tag)),
        }
    }

    fn conv_int32(self) -> Result<i32, String> {
        match self.payload {
            Payload::Real(v) => Ok(f2i32(v)),
            Payload::Int32(v) => Ok(v),
            Payload::Int64(v) => Ok(v as i32),
            Payload::Bool(v) => Ok(if v { 1 } else { 0 }),
            Payload::Null | Payload::Undefined => Ok(0),
            Payload::Str(_) => Err("unsupported cast".to_string()),
            Payload::Opaque(_) => Err(CONV.illegal_use(1, self.tag)),
        }
    }

    fn conv_int64(self) -> Result<i64, String> {
        match self.payload {
            Payload::Real(v) => Ok(f2i64(v)),
            Payload::Int32(v) => Ok(v as i64),
            Payload::Int64(v) => Ok(v),
            Payload::Bool(v) => Ok(if v { 1 } else { 0 }),
            Payload::Null | Payload::Undefined => Ok(0),
            Payload::Str(_) => Err("unsupported cast".to_string()),
            Payload::Opaque(_) => Err(CONV.illegal_use(1, self.tag)),
        }
    }

    fn conv_bool(self) -> Result<bool, String> {
        match self.payload {
            Payload::Real(v) => Ok(v > 0.5),
            Payload::Int32(v) => Ok(v > 0),
            Payload::Int64(v) => Ok(v >= 1),
            Payload::Bool(v) => Ok(v),
            Payload::Null | Payload::Undefined => Ok(false),
            // 字符串 → bool 是 strcmp(text,"true")==0（不是「非空即真」），要文本。
            Payload::Str(_) => Err("unsupported cast".to_string()),
            Payload::Opaque(_) => Err(CONV.illegal_use(1, self.tag)),
        }
    }
}
