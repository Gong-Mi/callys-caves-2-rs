//! opcode 单元差分的 **Rust 侧适配层**（里程碑 1，协议见
//! `reconstruction/contracts/opcode-diff-protocol.md`）。
//!
//! 这是适配层，不是第二份实现。语义来源是 `crates/core` 的 `code_vm`：
//! 每一行输入被翻译成一个合成的 CODE 体，交给 `code_vm::execute` 真正执行，
//! 结果从 `Host::write` 回调里取出。加/减/乘/除/与/非/比较/复制/转换全部命中
//! `execute` 里已有的分支；本文件只负责三件事：JSONL 线协议、RValue ↔ `Value`
//! 的搬运、把库的报错渲染成协议要求的文案。
//!
//! 用法：
//!
//!     cargo run --profile ci-test -p callys-core --example op_eval < cases.jsonl > out.jsonl
//!
//! 逐行读、逐行写、每行 flush（不缓冲到结束），便于定位第一处分歧。
//!
//! # 值模型
//!
//! `code_vm` 的栈是 `Vec<Value>`（见 `crates/core/src/value.rs`），每个槽带
//! `reconstruction/contracts/value-model.md` 的 tag。操作数**不是**先折成 f64 再
//! 压栈的：合成 CODE 体用 `Op::Load` 把两个操作数从 host 取进来，适配层在
//! `Host::read` 里把 16 字节 RValue 原样换成 `Value`：
//!
//!   * tag 0 → `Real(f64)`，tag 13 → `Real(f64)` 但保留 tag 13（bool 的 RValue
//!     表示就是 8 字节 double 只换 tag）；
//!   * tag 7 → `Int32`，tag 10 → `Int64` —— 整数宽度真的进了值，于是
//!     `int32+int32` 走 32 位回绕、含 int64 走 64 位；
//!   * tag 1 → `Str(pool index)`，12 字节内联文本先进本层的字符串池（下标空间与
//!     bundle 的 string_table 同一套：先字面量表、后运行期串）；`+` 的拼接由
//!     `Host::string_concat` 负责，比较走 `Host::string_text`；
//!   * tag 5 → `Undefined`，12 → `Null`；
//!   * 其余（2/3/4/6/8/9/11/14 与 0x00FFFFFF 占位）→ `Opaque(tag)`，库自己按卡片
//!     的 tag 表报错（array/pointer/undefined/Malformed），本层不替它决定。
//!
//! 输出把结果值的 tag **原样**写回 `result.tag`（不再一律 0），载荷按 tag 的宽度
//! 写进 16 字节：real/bool 8 字节 double、int32 4 字节、int64 8 字节、string ≤11
//! 字节内联 ASCII（与 `diff/c/vm_ref.c` 的镜像编码一致）。
//!
//! `sp` 由 VM 的**字节位移**给出（不是 16 字节槽）：`code_vm` 的栈槽带宽度
//! （int32/float32/bool/string 4、real/int64 8、RValue 16），`push_immediate`
//! 是 -4、二元是 `+右宽+左宽-结果宽`、`dup` 是 `-n*size`、比较是
//! `wa+wb-4`（两个 8 字节槽 → +12）。适配层从 `Host::stack_pointer` 的快照里
//! 取**算子里那条指令**的前后差，失败 0。
//!
//! # op 覆盖
//!
//! `code_vm::Op` 现在有全部 22 个协议算子对应的分支：Add/Sub/Mul/Div/And、
//! Rem/Mod/Or/Xor/Shl/Shr/Neg/Not（mode/type 位域按卡）、Cast、Constant/
//! ConstantTagged（push_immediate 的 tag 7）、Dup/DupMode（swap）与 DoSet 的
//! Cmp。格式 nibble 不是 5 时，操作数在进入 VM 前按**声明类**解码（class 0
//! double、1 f32、2 int32、3 int64、4 bool、6 string），这正是原版
//! `as_f64/as_i64/as_i32` 读裸槽的方式；nibble 5 才按 +12 tag 分派。
//!
//! # 已知分歧（本层不修，留给库）
//!
//!   * DoAdd/DoSub/DoMul/DoDiv/DoAnd 的 `mode != 0` 慢路径（boxType +
//!     F_JS_ToNumber/ToInt32）在库里还没有 mode 参数，走的是快路径语义。
//!   * `conv` 的 flags（mode bit8=ToBoolean、bit9=ToNumber）没有进 `Op::Cast`；
//!     只有 dst 参与。dst=6（string）要在 host 池里分配文本 → `unsupported cast`。
//!   * JS ToNumber 对字符串要 `strtod` 文本；VM 侧没有池，慢路径遇到字符串
//!     报该算子的字符串错误（DoNot mode1 的 ToBoolean 例外，走 host 文本）。
//!   * DoSet 的 K=7..10 / 14 / 15 在契约里是 open，仍是
//!     `unsupported comparison`。
//!
//! 输出行的字段集按协议的两个示例：成功 `{"id","ok","sp","result":{"bytes","tag"}}`，
//! 失败 `{"id","ok","error"}`（失败也带 `sp: 0`，协议要求）。

use callys_core::code_vm::{self, Bundle, Code, Instruction, Op, Payload, Value};
use callys_core::value;
use serde_json::Value as Json;
use std::io::{self, BufRead, Write};

/// 一个 16 字节 RValue：载荷 + tag（低 24 位有效，高 8 位是标志）。
struct RValue {
    bytes: [u8; 16],
    tag: u32,
}

/// 16 字节操作数在栈上的宽度由**声明类**决定（0/3→8、1/2/4/6→4、5→16），
/// 不再有统一的「槽」常量。`code_vm::class_width` 是这张表的唯一实现。

/// 把两个操作数交给库、再把栈顶收回来。操作数经 `Host::read` 进入 VM，所以
/// tag 与整数宽度都是真的进了 `Value`，没有 f64 中转。
#[derive(Default)]
struct CaptureHost {
    /// 待 `read` 取走的操作数（先压左、再压右）。
    inputs: std::collections::VecDeque<Value>,
    /// 本层字符串池（下标从 0 起；合成的 bundle 没有字面量表）。
    strings: Vec<String>,
    /// 每条 `Store` 交出来的栈顶。
    values: Vec<Value>,
    /// 每条指令执行后的值栈字节位移（`Host::stack_pointer` 的快照）。
    pointers: Vec<i32>,
}

impl CaptureHost {
    fn push(&mut self, v: Value) {
        self.inputs.push_back(v);
    }
    /// 池下标 → 文本。合成的 bundle 没有 string_table，所以池从 0 开始，
    /// 等价于「bundle 字面量表为空 + 运行期串」。
    fn text(&self, index: u32) -> Option<String> {
        self.strings.get(index as usize).cloned()
    }
    /// 把一段文本放进池，返回 tag 1 的引用；相同文本复用同一下标。
    fn intern(&mut self, text: String) -> Value {
        if let Some(index) = self.strings.iter().position(|s| *s == text) {
            return Value::string(index as u32);
        }
        self.strings.push(text);
        Value::string((self.strings.len() - 1) as u32)
    }
}

impl code_vm::Host for CaptureHost {
    fn read(
        &mut self,
        _instance: i32,
        _selector: i32,
        name: &str,
        _index: Option<i32>,
    ) -> Result<Value, String> {
        self.inputs
            .pop_front()
            .ok_or_else(|| format!("adapter: unexpected read of {name}"))
    }

    fn write(
        &mut self,
        _instance: i32,
        _selector: i32,
        _name: &str,
        _index: Option<i32>,
        value: Value,
    ) -> Result<(), String> {
        self.values.push(value);
        Ok(())
    }

    fn call(
        &mut self,
        _b: &Bundle,
        _instance: i32,
        name: &str,
        _args: &[Value],
    ) -> Result<Value, String> {
        Err(format!("adapter: unexpected call to {name}"))
    }

    fn select(&self, _instance: i32, _selector: i32) -> Result<Vec<i32>, String> {
        Err("adapter: unexpected select".into())
    }

    /// 记录每条指令后的字节位移；`eval` 只取算子里那条指令的前后差。
    fn stack_pointer(&mut self, sp: i32) {
        self.pointers.push(sp);
    }

    /// GMS 的 `+`：任一侧是串就 ToString 两边再拼（DoAdd mode1）。
    fn string_concat(&mut self, _b: &Bundle, lhs: Value, rhs: Value) -> Result<Value, String> {
        let text = format!("{}{}", self.as_text(lhs), self.as_text(rhs));
        Ok(self.intern(text))
    }

    /// 字符串比较要文本：先查本层池，数字按 GMS 的 string() 渲染。
    fn string_text(&self, _b: &Bundle, value: Value) -> Result<String, String> {
        match value.payload {
            Payload::Str(index) => self
                .text(index)
                .ok_or_else(|| format!("string reference {index} is not in the pool")),
            _ => Err(format!("{value} is not a string")),
        }
    }
}

impl CaptureHost {
    fn as_text(&self, v: Value) -> String {
        match v.payload {
            Payload::Str(index) => self.text(index).unwrap_or_default(),
            Payload::Bool(b) => if b { "1".to_string() } else { "0".to_string() },
            _ => gm_real_text(v.to_legacy_numeric().unwrap_or(0.0)),
        }
    }
}

/// GMS 1.4 的数字渲染（`string()` 的口径），与 `ir_scene::gm_real_text` 同式。
fn gm_real_text(v: f64) -> String {
    if !v.is_finite() {
        return "0".into();
    }
    if v.fract() == 0.0 && v.abs() < 9.0e15 {
        format!("{}", v as i64)
    } else {
        format!("{v:.2}")
    }
}

/// 把一串算子包成一个合法的合成 CODE 体（单字指令、连续 span、无分支），
/// 末尾补 `stores` 条 `Store` 把栈顶逐个交给 Host。
fn run(mut host: CaptureHost, ops: Vec<Op>, stores: usize) -> Result<CaptureHost, String> {
    let mut instructions: Vec<Instruction> = Vec::with_capacity(ops.len() + stores);
    let emit = |list: &mut Vec<Instruction>, op: Op| {
        let offset = list.len() * 4;
        list.push(Instruction {
            offset,
            code_offset: offset,
            words_raw: vec![0],
            op,
        });
    };
    for op in ops {
        emit(&mut instructions, op);
    }
    for _ in 0..stores {
        emit(
            &mut instructions,
            Op::Store {
                name: "out".to_string(),
                selector: 0,
                array: false,
                other: false,
            },
        );
    }
    let end = instructions.len() * 4;
    let bundle = Bundle {
        schema: 1,
        string_table: Vec::new(),
        objects: Vec::new(),
        room_bindings: Vec::new(),
        codes: vec![Code {
            id: 1,
            start: 0,
            end,
            instructions,
        }],
    };
    code_vm::execute(&bundle, 1, -1, &mut host).map_err(|e| e.message)?;
    if host.values.len() != stores {
        return Err(format!(
            "adapter: expected {stores} stack values, captured {}",
            host.values.len()
        ));
    }
    Ok(host)
}

fn hex_digit(b: u8) -> Option<u8> {
    match b {
        b'0'..=b'9' => Some(b - b'0'),
        b'a'..=b'f' => Some(b - b'a' + 10),
        b'A'..=b'F' => Some(b - b'A' + 10),
        _ => None,
    }
}

fn hex16(text: &str) -> Result<[u8; 16], String> {
    let raw = text.as_bytes();
    if raw.len() != 32 {
        return Err(format!("bytes must be 32 hex chars, got {}", raw.len()));
    }
    let mut out = [0u8; 16];
    for (i, slot) in out.iter_mut().enumerate() {
        let hi = hex_digit(raw[2 * i]).ok_or_else(|| "bytes is not hex".to_string())?;
        let lo = hex_digit(raw[2 * i + 1]).ok_or_else(|| "bytes is not hex".to_string())?;
        *slot = (hi << 4) | lo;
    }
    Ok(out)
}

fn hex_encode(bytes: &[u8; 16]) -> String {
    const DIGITS: &[u8; 16] = b"0123456789abcdef";
    let mut s = String::with_capacity(32);
    for b in bytes {
        s.push(DIGITS[(b >> 4) as usize] as char);
        s.push(DIGITS[(b & 0x0f) as usize] as char);
    }
    s
}

fn operand(v: &Json, key: &str) -> Result<RValue, String> {
    let obj = v
        .get(key)
        .ok_or_else(|| format!("bad_input: missing operand {key}"))?;
    let text = obj
        .get("bytes")
        .and_then(Json::as_str)
        .ok_or_else(|| format!("bad_input: {key}.bytes"))?;
    let tag = obj.get("tag").and_then(Json::as_i64).unwrap_or(0) as u32 & 0x00ff_ffff;
    Ok(RValue {
        bytes: hex16(text)?,
        tag,
    })
}

/// 12 字节内联 ASCII（NUL 截断）→ 文本，与 `diff/c/vm_ref.c` 的 `rv_text` 同口径。
fn inline_text(bytes: &[u8; 16]) -> String {
    let end = bytes[0..12].iter().position(|b| *b == 0).unwrap_or(12);
    String::from_utf8_lossy(&bytes[0..end]).into_owned()
}

/// 16 字节 RValue → `Value`：tag 原样进值，字符串进本层池。用于格式 nibble
/// 为 5（动态 RValue 槽）的读。
fn to_value(v: &RValue, host: &mut CaptureHost) -> Result<Value, String> {
    // 24 位 tag 截成 u8：0x00FFFFFF 占位落成 TAG_UNRESOLVED 哨兵，其余 tag 都 < 256。
    let tag = v.tag as u8;
    Ok(match tag {
        0 => Value::real(f64::from_le_bytes(v.bytes[0..8].try_into().unwrap())),
        // tag 13 是 real 的第二编码（8 字节 double + tag）：tag 留着，载荷是 double。
        value::TAG_BOOL => Value {
            tag: value::TAG_BOOL,
            payload: Payload::Real(f64::from_le_bytes(v.bytes[0..8].try_into().unwrap())),
        },
        value::TAG_INT32 => Value::int32(i32::from_le_bytes(v.bytes[0..4].try_into().unwrap())),
        value::TAG_INT64 => Value::int64(i64::from_le_bytes(v.bytes[0..8].try_into().unwrap())),
        value::TAG_STRING => host.intern(inline_text(&v.bytes)),
        value::TAG_UNDEFINED => Value::undefined(),
        value::TAG_NULL => Value::null(),
        // 2/3/4/6/8/9/11/14 与 0x00FFFFFF 占位：契约里只有 tag，没有已证的载荷
        // 布局。原样交给库，由它按卡片的 tag 表报错。
        tag => {
            let raw = u32::from_le_bytes(v.bytes[0..4].try_into().unwrap());
            Value::opaque(tag, raw)
        }
    })
}

/// 按**指令字声明的存储类**读裸槽：0 double、1 float32、2 int32、3 int64、
/// 4 bool、6 string；5 是动态 RValue（按 +12 tag），表外 7..15 没有内核
/// （值本身不参与运算，这里按 tag 兜底）。原版 `as_f64/as_i64/as_i32` 就是
/// 这样按声明类读裸槽的 —— 快路径不看 tag。
fn to_class_value(v: &RValue, cls: i64, host: &mut CaptureHost) -> Result<Value, String> {
    Ok(match cls {
        0 => Value::real(f64::from_le_bytes(v.bytes[0..8].try_into().unwrap())),
        1 => Value::real(f32::from_le_bytes(v.bytes[0..4].try_into().unwrap()) as f64),
        2 => Value::int32(i32::from_le_bytes(v.bytes[0..4].try_into().unwrap())),
        3 => Value::int64(i64::from_le_bytes(v.bytes[0..8].try_into().unwrap())),
        4 => Value::boolean(i32::from_le_bytes(v.bytes[0..4].try_into().unwrap()) != 0),
        6 => host.intern(inline_text(&v.bytes)),
        _ => to_value(v, host)?,
    })
}

/// 库的报错 → 协议里的 error 串。库现在直接吐卡片原文，这里只翻译它没有
/// 对应 op 的那几种。
fn render_error(op: &str, message: String) -> String {
    match message.as_str() {
        "unsupported cast" => format!("unsupported:{op}"),
        _ => message,
    }
}

/// 一条用例的结果：值 + 栈顶位移 + （字符串结果才有的）文本。
struct Evaluated {
    value: Value,
    sp: i32,
    text: Option<String>,
}

fn load_slot(name: &str, width: u8) -> Op {
    Op::LoadSlot { name: name.to_string(), width }
}

/// 4 bit 存储类 → 栈槽字节宽度（与 `code_vm::class_width` 同一张表）。
fn slot_width(cls: i64) -> u8 {
    code_vm::class_width((cls & 0x0F) as u8) as u8
}

/// 一条用例：返回 (结果值, 栈顶位移)。
fn eval(op: &str, mode: i64, ty: i64, a: &RValue, b: &RValue) -> Result<Evaluated, String> {
    let ty = (ty & 0xFF) as u8;
    // DoSet 的 0xFF 是「两侧都是 16 字节 RValue」的哨兵（vm_ref: ha=hb=5），
    // 先归一成 0x55，后面的宽度与声明类都按 5 处理。
    let ty = if op.starts_with("set_") && ty == 0xFF { 0x55 } else { ty };
    let mode_n = (mode as u32 & 0x0F) as u8;

    if op == "push_immediate" {
        // mode 当 16 位立即数（有符号）；卡里是 sxth + 4 字节 int32（tag 7）。
        let imm = ((mode as u32) & 0xffff) as u16 as i16 as f64;
        let host = run(
            CaptureHost::default(),
            vec![Op::ConstantTagged { value: imm, tag: value::TAG_INT32 }],
            1,
        )
        .map_err(|m| render_error(op, m))?;
        let sp = *host.pointers.first().ok_or("adapter: missing stack pointer")?;
        return Ok(Evaluated { value: host.values[0], sp, text: None });
    }

    // 22 个协议算子全部落到 code_vm 的变体上；kernel 为 None 的四个
    // （dup/conv/not/neg）由下面的 if 链决定 operand 形状。
    let kernel: Option<Op> = match op {
        "add" => Some(Op::Add),
        "sub" => Some(Op::Sub),
        "mul" => Some(Op::Mul),
        "div" => Some(Op::Div),
        "and" => Some(Op::AndMode { mode: mode_n, ty }),
        "rem" => Some(Op::Rem { mode: mode_n, ty }),
        "mod" => Some(Op::Mod { mode: mode_n, ty }),
        "or" => Some(Op::Or { mode: mode_n, ty }),
        "xor" => Some(Op::Xor { mode: mode_n, ty }),
        "shl" => Some(Op::Shl { mode: mode_n, ty }),
        "shr" => Some(Op::Shr { mode: mode_n, ty }),
        "set_lt" => Some(Op::CmpMode { comparison: 1, ty }),
        "set_le" => Some(Op::CmpMode { comparison: 2, ty }),
        "set_eq" => Some(Op::CmpMode { comparison: 3, ty }),
        "set_ne" => Some(Op::CmpMode { comparison: 4, ty }),
        "set_ge" => Some(Op::CmpMode { comparison: 5, ty }),
        "set_gt" => Some(Op::CmpMode { comparison: 6, ty }),
        "dup" | "conv" | "not" | "neg" => None,
        _ => return Err(format!("unsupported:{op}")),
    };

    let ha = (ty >> 4) & 0x0F;
    let hb = ty & 0x0F;
    // 这些算子的 mode≠0 是 JS 装箱慢路径：boxType 之后 F_JS_ToNumber /
    // F_JS_ToInt32 按 +12 tag 读值，与指令字的声明类无关。
    let js_path = (matches!(op, "and" | "or" | "xor" | "shl" | "shr") && mode != 0)
        || (matches!(op, "neg" | "not") && (mode == 1 || mode == 2));

    let (ops, stores, kernel_index) = if op == "dup" {
        let kernel = if mode == 0 {
            Op::Dup
        } else {
            Op::DupMode { mode: mode as u8, ty }
        };
        // 普通 dup 存两次（校验副本）；swap 只返回栈顶，存一次。
        let stores = if mode == 0 { 2 } else { 1 };
        (vec![load_slot("a", slot_width(ty as i64)), kernel], stores, 1)
    } else if op == "conv" {
        let dst = (ty >> 4) & 0x0F;
        (
            vec![load_slot("a", slot_width((ty & 0x0F) as i64)), Op::Cast { to: dst }],
            1,
            1,
        )
    } else if op == "not" {
        (
            vec![load_slot("a", slot_width((ty & 0x0F) as i64)), Op::NotMode { mode: mode_n, ty }],
            1,
            1,
        )
    } else if op == "neg" {
        (
            vec![load_slot("a", slot_width((ty & 0x0F) as i64)), Op::Neg { mode: mode_n, ty }],
            1,
            1,
        )
    } else {
        (
            vec![
                load_slot("a", slot_width(ha as i64)),
                load_slot("b", slot_width(hb as i64)),
                kernel.expect("binary kernel"),
            ],
            1,
            2,
        )
    };

    // 每个算子都从 Load 起手：格式 nibble 不是 5 时按声明类解码，nibble 5
    // 才按 +12 tag；dup 的 type 是元素宽度类，不动值的 tag 语义。
    let mut host = CaptureHost::default();
    let lhs = if op == "dup" {
        to_value(a, &mut host)?
    } else if js_path {
        to_value(a, &mut host)?
    } else {
        let cls = if op == "conv" || op == "not" || op == "neg" {
            (ty & 0x0F) as i64
        } else {
            ha as i64
        };
        to_class_value(a, cls, &mut host)?
    };
    host.push(lhs);
    if kernel_index == 2 {
        let rhs = if js_path {
            to_value(b, &mut host)?
        } else {
            to_class_value(b, hb as i64, &mut host)?
        };
        host.push(rhs);
    }
    let host = run(host, ops, stores).map_err(|m| render_error(op, m))?;

    let value = host.values[0];
    let text = match value.payload {
        Payload::Str(index) => host.text(index),
        _ => None,
    };
    if host.pointers.len() <= kernel_index {
        return Err("adapter: missing stack pointer".into());
    }
    // 算子里那条指令的前后差 = 卡里的 sp 位移（load 的宽度差已被抵消）。
    let sp = host.pointers[kernel_index] - host.pointers[kernel_index - 1];
    Ok(Evaluated { value, sp, text })
}

/// 结果值 → 16 字节镜像 + tag。宽度按 tag 走，与 `diff/c/vm_ref.c` 的
/// `rv_set_*` 同一套：real/bool 8 字节 double、int32 4 字节、int64 8 字节、
/// string ≤11 字节内联 ASCII。
fn payload_bytes(value: &Value, text: Option<&str>) -> Result<[u8; 16], String> {
    let mut bytes = [0u8; 16];
    match value.payload {
        Payload::Real(v) => bytes[0..8].copy_from_slice(&v.to_le_bytes()),
        Payload::Int32(v) => bytes[0..4].copy_from_slice(&v.to_le_bytes()),
        Payload::Int64(v) => bytes[0..8].copy_from_slice(&v.to_le_bytes()),
        // bool 在 RValue 里就是 8 字节 double 的 0.0/1.0，只换 tag（DoConv 卡 dst=5）。
        Payload::Bool(v) => {
            let d = if v { 1.0f64 } else { 0.0f64 };
            bytes[0..8].copy_from_slice(&d.to_le_bytes());
        }
        Payload::Str(index) => {
            let text = text.ok_or_else(|| format!("string reference {index} is not in the pool"))?;
            let n = text.len().min(11);
            bytes[0..n].copy_from_slice(&text.as_bytes()[..n]);
        }
        // undefined 是 .bss 的 16 字节零常量，null 是显式 0.0 —— 两者载荷都是 0。
        Payload::Undefined | Payload::Null => {}
        Payload::Opaque(raw) => bytes[0..4].copy_from_slice(&raw.to_le_bytes()),
    }
    // tag 占 +12 的低 24 位；0x00FFFFFF 占位在 `Value` 里用 0xFF 当哨兵。
    let tag: u32 = if value.tag == value::TAG_UNRESOLVED {
        0x00ff_ffff
    } else {
        value.tag as u32
    };
    bytes[12..16].copy_from_slice(&tag.to_le_bytes());
    Ok(bytes)
}

fn success_line(id: &str, result: &Evaluated) -> Result<String, String> {
    let bytes = payload_bytes(&result.value, result.text.as_deref())?;
    let tag = u32::from_le_bytes(bytes[12..16].try_into().unwrap());
    let mut line = String::with_capacity(96);
    line.push_str("{\"id\": ");
    line.push_str(id);
    line.push_str(", \"ok\": true, \"sp\": ");
    // sp 是 VM 的字节位移（卡的口径）：push_immediate -4、二元 +右宽+左宽-结果宽、
    // dup -n*size、DoSet wa+wb-4。不是 16 字节/槽，也没有任何比例换算。
    line.push_str(&result.sp.to_string());
    line.push_str(", \"result\": {\"bytes\": \"");
    line.push_str(&hex_encode(&bytes));
    line.push_str("\", \"tag\": ");
    line.push_str(&tag.to_string());
    line.push_str("}}");
    Ok(line)
}

fn error_line(id: &str, message: &str) -> String {
    // 协议：ok=false 时 sp 必须为 0（run_diff 会把缺 sp 当成 schema 违规）
    let mut line = String::with_capacity(96);
    line.push_str("{\"id\": ");
    line.push_str(id);
    line.push_str(", \"ok\": false, \"sp\": 0, \"error\": ");
    line.push_str(&serde_json::to_string(message).unwrap_or_else(|_| "\"bad_input\"".into()));
    line.push('}');
    line
}

fn respond(line: &str) -> String {
    let parsed: Json = match serde_json::from_str(line) {
        Ok(v) => v,
        Err(e) => return error_line("0", &format!("bad_input: {e}")),
    };
    let id = match parsed.get("id") {
        Some(v) => serde_json::to_string(v).unwrap_or_else(|_| "0".into()),
        None => return error_line("0", "bad_input: missing id"),
    };
    let op = match parsed.get("op").and_then(Json::as_str) {
        Some(s) => s,
        None => return error_line(&id, "bad_input: missing op"),
    };
    let mode = parsed.get("mode").and_then(Json::as_i64).unwrap_or(0);
    let ty = parsed.get("type").and_then(Json::as_i64).unwrap_or(0);
    let (a, b) = match (operand(&parsed, "a"), operand(&parsed, "b")) {
        (Ok(a), Ok(b)) => (a, b),
        (Err(e), _) | (_, Err(e)) => return error_line(&id, &e),
    };
    match eval(op, mode, ty, &a, &b) {
        Ok(result) => success_line(&id, &result).unwrap_or_else(|e| error_line(&id, &e)),
        Err(e) => error_line(&id, &e),
    }
}

fn main() {
    let stdin = io::stdin();
    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());
    for line in stdin.lock().lines() {
        let line = match line {
            Ok(l) => l,
            Err(_) => break,
        };
        if line.trim().is_empty() {
            continue;
        }
        let response = respond(&line);
        if writeln!(out, "{response}").is_err() {
            break;
        }
        // 逐行 flush：差分要的是"第一处分歧"的位置，不是攒到最后。
        if out.flush().is_err() {
            break;
        }
    }
}
