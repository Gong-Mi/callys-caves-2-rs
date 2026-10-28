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
//! `sp` 按 16 字节 RValue 槽记账（与协议示例 `"sp": -16` 一致）：二元 -16、一元 0、
//! `dup` +16、`push_immediate` -16、`conv` 0，失败 0。
//!
//! # op 覆盖
//!
//! `code_vm::Op` 只有 Constant/String/Load/Store/LoadLocal/StoreLocal/Cast/
//! Add/Sub/Mul/Div/Not/Dup/And/Cmp/B/Bt/Bf/Pushenv/Popenv/Call/Popz/Exit。
//! 因此 `rem`、`mod`、`or`、`xor`、`shl`、`shr`、`neg` 在 Rust 侧**没有**对应
//! 实现（不是本层没接，是库的 op 集里没有），一律回 `unsupported:<op>`。
//!
//! # 已知分歧（正是差分要暴露的东西，本层不修）
//!
//!   * `dup` 的 swap 变体在 `Op::Dup` 里没有参数（IR 的 Dup 只有普通复制），C 侧
//!     mode≠0 是 `DoDup` 的 swap 模式（非 16B RValue 的 type 直接报
//!     `Argument type N currently unhandled by DoDup swap mode`），本层跑的是复制。
//!   * DoDiv 的实数路径不判零，库的 `Value::div` 也照卡给 IEEE ±inf/NaN；但
//!     `execute` 每条指令后都拒收非有限值，于是 1.0/0.0 会变成
//!     `non-finite numeric value unsupported`（协议里是一条 error，不是 ±inf）。
//!   * DoRem 写回的是**商**（卡已证名字与实现不符），`Op` 里没有 rem → 未接。
//!   * `conv` 的目标类型 6（string）要在 host 的池里分配文本，VM 侧报
//!     `unsupported cast`，本层渲染成 `unsupported:conv`。
//!   * `push_immediate` 的 lowered 形式是 `Op::Constant`（real），所以这一行的
//!     结果 tag 是 0；C 侧按 4 字节 int32 给 tag 7。栈单位也不同（-16 vs -4）。
//!   * 库的 `Cmp` K 只到 1..6；K=7..10 / 14 / 15 在契约里是 open，回
//!     `unsupported comparison`（渲染成原文）。
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

/// 16 字节操作数在栈上的宽度（协议按 RValue 槽计，与卡片 16B 装箱路径一致）。
const SLOT: i32 = 16;

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

/// 16 字节 RValue → `Value`：tag 原样进值，字符串进本层池。
fn to_value(v: &RValue, host: &mut CaptureHost, op: &str) -> Result<Value, String> {
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
            let _ = op;
            Value::opaque(tag as u8, raw)
        }
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

fn load(name: &str) -> Op {
    Op::Load {
        name: name.to_string(),
        selector: 0,
        array: false,
        other: false,
    }
}

/// 一条用例：返回 (结果值, 栈顶位移)。
fn eval(op: &str, mode: i64, ty: i64, a: &RValue, b: &RValue) -> Result<Evaluated, String> {
    // 二元算子的名字（DoSet 的 K=1..6 与 Cmp 的 comparison 1..6 同序）。
    let binary = |op: &str| -> Option<Op> {
        Some(match op {
            "add" => Op::Add,
            "sub" => Op::Sub,
            "mul" => Op::Mul,
            "div" => Op::Div,
            "and" => Op::And,
            "set_lt" => Op::Cmp { comparison: 1 },
            "set_le" => Op::Cmp { comparison: 2 },
            "set_eq" => Op::Cmp { comparison: 3 },
            "set_ne" => Op::Cmp { comparison: 4 },
            "set_ge" => Op::Cmp { comparison: 5 },
            "set_gt" => Op::Cmp { comparison: 6 },
            _ => return None,
        })
    };

    if op == "push_immediate" {
        // mode 当 16 位立即数（有符号）；库的 lowered 形式就是 Op::Constant。
        let imm = ((mode as u32) & 0xffff) as u16 as i16 as f64;
        let host = run(CaptureHost::default(), vec![Op::Constant { value: imm }], 1)
            .map_err(|m| render_error(op, m))?;
        return Ok(Evaluated {
            value: host.values[0],
            sp: -SLOT,
            text: None,
        });
    }

    // 其余每个算子都从 Load 起手：tag 由 host 交给库，不经 f64 中转。
    // （needs_rhs 决定是否再取第二个操作数：dup / conv / not 是一元的。）
    let (ops, stores, needs_rhs): (Vec<Op>, usize, bool) = if op == "dup" {
        (vec![load("a"), Op::Dup], 2, false)
    } else if op == "conv" {
        let dst = ((ty >> 4) & 0x0f) as u8;
        (vec![load("a"), Op::Cast { to: dst }], 1, false)
    } else if op == "not" {
        (vec![load("a"), Op::Not], 1, false)
    } else if let Some(kernel) = binary(op) {
        (vec![load("a"), load("b"), kernel], 1, true)
    } else {
        // rem / mod / or / xor / shl / shr / neg：code_vm::Op 里没有，库侧无实现。
        return Err(format!("unsupported:{op}"));
    };

    let mut host = CaptureHost::default();
    let lhs = to_value(a, &mut host, op)?;
    host.push(lhs);
    if needs_rhs {
        let rhs = to_value(b, &mut host, op)?;
        host.push(rhs);
    }
    let host = run(host, ops, stores).map_err(|m| render_error(op, m))?;

    let value = host.values[0];
    let text = match value.payload {
        Payload::Str(index) => host.text(index),
        _ => None,
    };
    let sp = if op == "dup" {
        SLOT
    } else if needs_rhs {
        -SLOT
    } else {
        0
    };
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
    // 注意：**不能**用 ×16 把槽换成字节 —— 原版的 push_immediate 只推 4 字节、
    // 二元运算按操作数宽度推 8/4/16，不是固定 16 字节/槽。这里保留 VM 自己的槽计数，
    // 让差分如实暴露"栈单位不同"这一层差异，不做假换算。
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
