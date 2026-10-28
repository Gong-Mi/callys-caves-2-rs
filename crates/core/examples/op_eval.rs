//! opcode 单元差分的 **Rust 侧适配层**（里程碑 1，协议见
//! `reconstruction/contracts/opcode-diff-protocol.md`）。
//!
//! 这是适配层，不是第二份实现。语义来源是 `crates/core` 的 `code_vm`：
//! 每一行输入被翻译成一个合成的 CODE 体（`Constant` 压操作数 + 对应算子 +
//! 一到两条 `Store` 把栈顶交出来），交给 `code_vm::execute` 真正执行，
//! 结果从 `Host::write` 回调里取出。加/减/乘/除/与/非/比较/复制/转换全部命中
//! `execute` 里已有的分支；本文件只负责三件事：JSONL 线协议、RValue ↔ f64 的
//! 搬运、把库的报错渲染成协议要求的文案。
//!
//! 用法：
//!
//!     cargo run --profile ci-test -p callys-core --example op_eval < cases.jsonl > out.jsonl
//!
//! 逐行读、逐行写、每行 flush（不缓冲到结束），便于定位第一处分歧。
//!
//! # 值模型（照抄 crates/core 的实际模型，不是卡片里的存储类表）
//!
//! `code_vm` 的栈是 `Vec<f64>`：每个数字就是 8 字节 f64，没有 tag 字、也没有
//! 卡片的 4B/8B/16B 裸槽之分。所以本层：
//!
//!   * 输入 tag 0/13（double）、7（int32）、10（int64）按数值装进 f64；
//!   * 运算结果统一按 tag 0（double）+ 8 字节 f64 载荷输出 —— 因为库里的值就是 f64，
//!     写成 tag 7/10 会是本层自己编的、库不认的表示；
//!   * tag 1（string）/2（array）/3（pointer）/5（undefined）/0x00FFFFFF 占位
//!     在数值 VM 里没有表示，逐例回 `unsupported:<op>`，不伪造；
//!   * `sp` 按 16 字节 RValue 槽记账（与协议示例 `"sp": -16` 一致）：
//!     二元 -16、一元 0、`dup` +16、`push_immediate` -16、`conv` 0，失败 0。
//!
//! # op 覆盖
//!
//! `code_vm::Op` 只有 Constant/String/Load/Store/LoadLocal/StoreLocal/Cast/
//! Add/Sub/Mul/Div/Not/Dup/And/Cmp/B/Bt/Bf/Pushenv/Popenv/Call/Popz/Exit。
//! 因此 `rem`、`mod`、`or`、`xor`、`shl`、`shr`、`neg` 在 Rust 侧**没有**对应
//! 实现（不是本层没接，是库的 op 集里没有），一律回 `unsupported:<op>`；
//! `conv` 的目标类型若落在 `Cast` 支持的 {0,5 恒等, 4 bool, 2 int32} 之外，
//! 库自己回 "unsupported cast"，本层同样渲染成 `unsupported:conv`。
//!
//! # 已知分歧（正是差分要暴露的东西，本层不修）
//!
//!   * DoDiv 的实数路径**不判除零**（IEEE ±inf/NaN），`code_vm` 的 `Div` 判
//!     `rhs == 0.0` 并返回 Err；整数除零在卡里是软错误（写 tag 后继续执行）。
//!   * DoSet 的数值比较带 ±1e-5 容差，`code_vm` 的 `Cmp` 是精确比较。
//!   * DoAdd 的 int32+int32 是 32 位回绕加法，`code_vm` 走 f64 加法（本层把
//!     tag 7/10 升成 f64 后也一样）。
//!   * `execute` 每执行一条指令都拒收非有限值，于是 NaN/±Inf 操作数在
//!     `Constant` 压栈那一步就得到 "non-finite numeric value unsupported"。
//!
//! 输出行的字段集按协议的两个示例：成功 `{"id","ok","sp","result":{"bytes","tag"}}`，
//! 失败 `{"id","ok","error"}`（失败不带 `sp`，与示例一致）。

use callys_core::code_vm::{self, Bundle, Code, Instruction, Op};
use serde_json::Value;
use std::io::{self, BufRead, Write};

/// 一个 16 字节 RValue：载荷 + tag（低 24 位有效，高 8 位是标志）。
struct RValue {
    bytes: [u8; 16],
    tag: u32,
}

/// 16 字节操作数在栈上的宽度（协议按 RValue 槽计，与卡片 16B 装箱路径一致）。
const SLOT: i32 = 16;

#[derive(Default)]
struct CaptureHost {
    values: Vec<f64>,
}

impl code_vm::Host for CaptureHost {
    fn read(
        &mut self,
        _instance: i32,
        _selector: i32,
        name: &str,
        _index: Option<i32>,
    ) -> Result<f64, String> {
        Err(format!("adapter: unexpected read of {name}"))
    }

    fn write(
        &mut self,
        _instance: i32,
        _selector: i32,
        _name: &str,
        _index: Option<i32>,
        value: f64,
    ) -> Result<(), String> {
        self.values.push(value);
        Ok(())
    }

    fn call(&mut self, _b: &Bundle, _instance: i32, name: &str, _args: &[f64]) -> Result<f64, String> {
        Err(format!("adapter: unexpected call to {name}"))
    }

    fn select(&self, _instance: i32, _selector: i32) -> Result<Vec<i32>, String> {
        Err("adapter: unexpected select".into())
    }
}

/// 把一串算子包成一个合法的合成 CODE 体（单字指令、连续 span、无分支），
/// 末尾补 `stores` 条 `Store` 把栈顶逐个交给 Host。
fn run(ops: Vec<Op>, stores: usize) -> Result<Vec<f64>, String> {
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
    let mut host = CaptureHost::default();
    code_vm::execute(&bundle, 1, -1, &mut host).map_err(|e| e.message)?;
    if host.values.len() != stores {
        return Err(format!(
            "adapter: expected {stores} stack values, captured {}",
            host.values.len()
        ));
    }
    Ok(host.values)
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

fn operand(v: &Value, key: &str) -> Result<RValue, String> {
    let obj = v
        .get(key)
        .ok_or_else(|| format!("bad_input: missing operand {key}"))?;
    let text = obj
        .get("bytes")
        .and_then(Value::as_str)
        .ok_or_else(|| format!("bad_input: {key}.bytes"))?;
    let tag = obj.get("tag").and_then(Value::as_i64).unwrap_or(0) as u32 & 0x00ff_ffff;
    Ok(RValue {
        bytes: hex16(text)?,
        tag,
    })
}

/// RValue → 数值 VM 的 f64。只有 double / int32 / int64 三种 tag 有表示；
/// 其余（串、数组、指针、undefined、0x00FFFFFF 占位）在 `code_vm` 里没有
/// 对应表示，按"该 op 在这一行上没有实现"回报。
fn numeric(v: &RValue, op: &str) -> Result<f64, String> {
    match v.tag {
        0 | 13 => Ok(f64::from_le_bytes(v.bytes[0..8].try_into().unwrap())),
        7 => Ok(i32::from_le_bytes(v.bytes[0..4].try_into().unwrap()) as f64),
        10 => Ok(i64::from_le_bytes(v.bytes[0..8].try_into().unwrap()) as f64),
        _ => Err(format!("unsupported:{op}")),
    }
}

/// 库的报错 → 协议里的 error 串。出现位置由库决定，文案按协议的示例对齐。
fn render_error(op: &str, message: String) -> String {
    match message.as_str() {
        "unsupported cast" => format!("unsupported:{op}"),
        "division by zero" if op == "div" => "DoDiv :: Divide by zero".to_string(),
        _ => message,
    }
}

/// 一条用例：返回 (结果值, 栈顶位移)。
fn eval(op: &str, mode: i64, ty: i64, a: &RValue, b: &RValue) -> Result<(f64, i32), String> {
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
        let v = run(vec![Op::Constant { value: imm }], 1).map_err(|m| render_error(op, m))?;
        return Ok((v[0], -SLOT));
    }

    if op == "dup" {
        let x = numeric(a, op)?;
        let v = run(vec![Op::Constant { value: x }, Op::Dup], 2)
            .map_err(|m| render_error(op, m))?;
        // 第一次 Store 取到的是副本（栈顶），即该 op 的结果。
        return Ok((v[0], SLOT));
    }

    if op == "conv" {
        let x = numeric(a, op)?;
        let dst = ((ty >> 4) & 0x0f) as u8;
        let v = run(vec![Op::Constant { value: x }, Op::Cast { to: dst }], 1)
            .map_err(|m| render_error(op, m))?;
        return Ok((v[0], 0));
    }

    if op == "not" {
        let x = numeric(a, op)?;
        let v = run(vec![Op::Constant { value: x }, Op::Not], 1)
            .map_err(|m| render_error(op, m))?;
        return Ok((v[0], 0));
    }

    if let Some(kernel) = binary(op) {
        let lhs = numeric(a, op)?;
        let rhs = numeric(b, op)?;
        let v = run(
            vec![
                Op::Constant { value: lhs },
                Op::Constant { value: rhs },
                kernel,
            ],
            1,
        )
        .map_err(|m| render_error(op, m))?;
        return Ok((v[0], -SLOT));
    }

    // rem / mod / or / xor / shl / shr / neg：code_vm::Op 里没有，库侧无实现。
    Err(format!("unsupported:{op}"))
}

fn success_line(id: &str, sp: i32, value: f64) -> String {
    let mut bytes = [0u8; 16];
    bytes[0..8].copy_from_slice(&value.to_le_bytes());
    let mut line = String::with_capacity(96);
    line.push_str("{\"id\": ");
    line.push_str(id);
    line.push_str(", \"ok\": true, \"sp\": ");
    line.push_str(&sp.to_string());
    line.push_str(", \"result\": {\"bytes\": \"");
    line.push_str(&hex_encode(&bytes));
    line.push_str("\", \"tag\": 0}}");
    line
}

fn error_line(id: &str, message: &str) -> String {
    let mut line = String::with_capacity(96);
    line.push_str("{\"id\": ");
    line.push_str(id);
    line.push_str(", \"ok\": false, \"error\": ");
    line.push_str(&serde_json::to_string(message).unwrap_or_else(|_| "\"bad_input\"".into()));
    line.push('}');
    line
}

fn respond(line: &str) -> String {
    let parsed: Value = match serde_json::from_str(line) {
        Ok(v) => v,
        Err(e) => return error_line("0", &format!("bad_input: {e}")),
    };
    let id = match parsed.get("id") {
        Some(v) => serde_json::to_string(v).unwrap_or_else(|_| "0".into()),
        None => return error_line("0", "bad_input: missing id"),
    };
    let op = match parsed.get("op").and_then(Value::as_str) {
        Some(s) => s,
        None => return error_line(&id, "bad_input: missing op"),
    };
    let mode = parsed.get("mode").and_then(Value::as_i64).unwrap_or(0);
    let ty = parsed.get("type").and_then(Value::as_i64).unwrap_or(0);
    let (a, b) = match (operand(&parsed, "a"), operand(&parsed, "b")) {
        (Ok(a), Ok(b)) => (a, b),
        (Err(e), _) | (_, Err(e)) => return error_line(&id, &e),
    };
    match eval(op, mode, ty, &a, &b) {
        Ok((value, sp)) => success_line(&id, sp, value),
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
