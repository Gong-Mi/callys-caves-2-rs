//! CODE interpreter. Deliberately separate from generated event bodies.
//!
//! The stack is `Vec<Value>`: every slot carries the RValue tag from
//! `reconstruction/contracts/value-model.md` (real / int32 / int64 / string /
//! undefined / null / bool), so integer wraparound, i64 pairs and the ±1e-05
//! comparison tolerance happen on the tag the original VM would have seen
//! instead of being flattened into one `f64`.
use serde::Deserialize;
pub use crate::value::{Payload, Value, STRING_REF_BASE};
use crate::value::BitOp;

#[derive(Debug, Clone, Deserialize)]
pub struct Bundle {
    pub schema: u32,
    #[serde(default)]
    pub string_table: Vec<String>,
    pub objects: Vec<Object>,
    #[serde(default)]
    pub room_bindings: Vec<RoomBinding>,
    pub codes: Vec<Code>,
}

#[derive(Debug, Clone, Deserialize)]
pub struct RoomBinding {
    pub room_id: usize,
    pub room_name: String,
    pub object_id: i32,
    pub instance_id: i32,
    pub code_id: usize,
}

#[derive(Debug, Clone, Deserialize)]
pub struct Object {
    pub id: i32,
    pub name: String,
    pub sprite: i32,
    pub depth: i32,
    /// GM persistent flag from the original asset data. An instance of a
    /// persistent object survives room switches (transition_to_room retains
    /// it; every room re-places its own transient copies). Old IR files
    /// without the field default to non-persistent.
    #[serde(default)]
    pub persistent: bool,
    #[serde(default = "default_parent")]
    pub parent: i32,
    #[serde(default)]
    pub parent_chain: Vec<i32>,
    pub events: Vec<Event>,
}

fn default_parent() -> i32 {
    -100
}
#[derive(Debug, Clone, Deserialize)]
pub struct Event { pub event_type: i32, pub subtype: i32, pub codes: Vec<usize> }
#[derive(Debug, Clone, Deserialize)]
pub struct Code { pub id: usize, pub start: usize, pub end: usize, pub instructions: Vec<Instruction> }
#[derive(Debug, Clone, Deserialize)]
pub struct Instruction { pub offset: usize, pub code_offset: usize, pub words_raw: Vec<u32>, #[serde(flatten)] pub op: Op }
#[derive(Debug, Clone, Deserialize)]
#[serde(tag = "op", rename_all = "snake_case")]
pub enum Op {
    Constant { value: f64 },
    /// 带 tag 的立即数。`push_immediate` 在卡里是 `sxth` 后压 4 字节 int32
    /// （tag 7），lowered 的 `Constant` 只有 real 载荷、装不下这个 tag，所以单列
    /// 一个变体：`value` 是数值，`tag` 是原版写进 RValue +12 的类型。
    ConstantTagged { value: f64, tag: u8 },
    String { string_id: usize },
    Load { name: String, selector: i32, array: bool, #[serde(default)] other: bool },
    /// 从**声明了存储类**的槽读操作数（DoAdd/DoSet/DoRem 的格式 nibble）。宽度
    /// 由指令字决定而不是由运行期 tag 决定：0/3→8、1/2/4/6→4、5→16。
    /// 普通的 `Load` 仍按值的 tag 推宽度（变量读出来是 RValue）。
    LoadSlot { name: String, width: u8 },
    Store { name: String, selector: i32, array: bool, #[serde(default)] other: bool },
    LoadLocal { name: String },
    StoreLocal { name: String }, Cast { to: u8 },
    Add, Sub, Mul, Div,
    /// DoRem：**写回商**（卡已证名字与实现不符），没有 mode 慢路径。
    Rem { mode: u8, ty: u8 },
    /// DoMod：mode==1 是常量路径（NaN 不报错），其余与 mode 0 同路。
    Mod { mode: u8, ty: u8 },
    Or { mode: u8, ty: u8 },
    Xor { mode: u8, ty: u8 },
    Shl { mode: u8, ty: u8 },
    Shr { mode: u8, ty: u8 },
    /// DoNeg：mode 0/3..15 强类型取负、1 通用取负、2 纯数值化。
    Neg { mode: u8, ty: u8 },
    /// DoNot：mode 0/3..15 是按位取反，1 是逻辑 `!`，2 是 JS 的 `~`。
    /// 裸 `Not` 保留给旧 IR 的「逻辑非」语义。
    NotMode { mode: u8, ty: u8 },
    Not, Dup,
    /// DoSet 的 K=1..6，带 type 字节：0xFF 已由适配层归一成 0x55，格式码
    /// 7..15 走「给值不给错」，其余两侧按声明类 + tag 解析。
    CmpMode { comparison: u8, ty: u8 },
    /// DoDup 的 swap 模式（`arg & 0xFF00 != 0`）：只接受 type==5；n/m 都是
    /// 16 字节槽计数，协议只带 bits[11:8]，m 按 0 处理 → 交换是空操作。
    DupMode { mode: u8, ty: u8 },
    And,
    /// DoAnd 带上 mode/type（`And` 是旧 IR 的 tag 分派形式，保持不动）。
    AndMode { mode: u8, ty: u8 },
    Cmp { comparison: u8 }, B { target: usize }, Bt { target: usize }, Bf { target: usize },
    Pushenv { target: usize }, Popenv { target: usize }, Call { name: String, argc: usize }, Popz, Exit,
}
#[derive(Debug, Clone, PartialEq)]
pub struct VmError { pub code: usize, pub offset: usize, pub message: String }
impl std::fmt::Display for VmError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result { write!(f, "CODE {} @0x{:x}: {}", self.code, self.offset, self.message) }
}
impl std::error::Error for VmError {}
pub trait Host {
    fn read(&mut self, instance: i32, selector: i32, name: &str, index: Option<i32>) -> Result<Value, String>;
    fn write(&mut self, instance: i32, selector: i32, name: &str, index: Option<i32>, value: Value) -> Result<(), String>;
    fn call(&mut self, bundle: &Bundle, instance: i32, name: &str, args: &[Value]) -> Result<Value, String>;
    fn select(&self, instance: i32, selector: i32) -> Result<Vec<i32>, String>;
    /// GMS `+` concatenates when an operand is a string (DoAdd mode1: ToString
    /// both sides, then join). The VM delegates here as soon as either operand
    /// is `Value::string(..)`; hosts without a string pool keep the error.
    fn string_concat(&mut self, _bundle: &Bundle, _lhs: Value, _rhs: Value) -> Result<Value, String> {
        Err("string concatenation is unsupported by this host".into())
    }
    /// Text behind a string reference. The default resolves the bundle's literal
    /// table only (that needs no host state); hosts that own runtime-built
    /// strings override this to cover the tail of the pool.
    fn string_text(&self, bundle: &Bundle, value: Value) -> Result<String, String> {
        match value.payload {
            Payload::Str(index) if (index as usize) < bundle.string_table.len() => {
                Ok(bundle.string_table[index as usize].clone())
            }
            Payload::Str(index) => Err(format!("string reference {index} is not in the bundle string table")),
            _ => Err(format!("{value} is not a string")),
        }
    }
    fn instruction(&mut self, _code: usize, _offset: usize) {}
    /// 每条指令执行后的值栈字节位移（负数 = 栈向下长，与卡里的 `sp` 同号）。
    /// 诊断口：差分适配层用它取单条算子的位移，正常运行不实现也无成本。
    fn stack_pointer(&mut self, _sp: i32) {}
}
pub fn prologue_bundle() -> Bundle { serde_json::from_str(include_str!("generated/prologue_ir.json")).expect("generated IR schema") }
/// Selector / array index: an int32 slot is taken as-is, anything else must be an
/// integral real in range (a bad index is a scheduling bug, not a silent zero).
fn integer(v: Value) -> Result<i32, String> {
    match v.payload {
        Payload::Int32(i) => Ok(i),
        _ => {
            let x = v.to_real().map_err(|_| format!("unsupported non-i32 selector/index {v}"))?;
            if x.is_finite() && x.fract() == 0.0 && x >= i32::MIN as f64 && x <= i32::MAX as f64 { Ok(x as i32) }
            else { Err(format!("unsupported non-i32 selector/index {x}")) }
        }
    }
}
/// Which CODE bodies actually executed — an execution ledger, not a coverage
/// claim about behaviour.
///
/// WHY: the semantic census can only see citations in text, so a body that a
/// suite genuinely runs end to end still reads as "no evidence" if nobody wrote
/// its id down. Recording the bodies as the VM enters them turns that into a
/// mechanical statement: these ids ran under these suites.
///
/// Gating: recording is off unless something turns it on, so the hook costs one
/// `OnceLock::get()` per CODE body in normal runs. Two switches:
///   * `enable_memory()` / `executed()` for tests in the same process;
///   * `CALLY_CODE_TRACE=<path>` read once at the first record, for suites run
///     as separate processes (append-only, one id per line).
pub mod coverage {
    use std::collections::BTreeSet;
    use std::io::Write;
    use std::path::PathBuf;
    use std::sync::{Mutex, OnceLock};

    /// Decimal rendering without pulling the formatting machinery into the
    /// per-body path.
    fn itoa(mut n: usize) -> String {
        if n == 0 {
            return "0".to_string();
        }
        let mut digits = [0u8; 20];
        let mut i = digits.len();
        while n > 0 {
            i -= 1;
            digits[i] = b'0' + (n % 10) as u8;
            n /= 10;
        }
        String::from_utf8_lossy(&digits[i..]).into_owned()
    }

    enum Sink {
        Memory,
        File(PathBuf),
    }

    static SINK: OnceLock<Option<Sink>> = OnceLock::new();
    static MEMORY: Mutex<Option<BTreeSet<usize>>> = Mutex::new(None);
    /// Serialises file appends. `write!(fh, "{code}\n")` issues more than one
    /// write for a formatted argument, and tests run in parallel threads: the
    /// interleaved writes appended *digit concatenations* (30 + 30 -> "3030",
    /// 1234 + 8 -> "12348") which looked exactly like out-of-range CODE ids.
    /// One `write_all` under this lock per entry keeps every line whole.
    static FILE_LOCK: Mutex<()> = Mutex::new(());

    /// Read the env switch once. `None` means "not tracing".
    fn sink() -> Option<&'static Sink> {
        SINK.get_or_init(|| {
            std::env::var("CALLY_CODE_TRACE")
                .ok()
                .filter(|p| !p.is_empty())
                .map(|p| Sink::File(PathBuf::from(p)))
        })
        .as_ref()
    }

    /// Start a process-local trace (tests).
    pub fn enable_memory() {
        let _ = SINK.set(Some(Sink::Memory));
        *MEMORY.lock().unwrap() = Some(BTreeSet::new());
    }

    /// The ids recorded since `enable_memory()`, or `None` when not tracing.
    pub fn executed() -> Option<BTreeSet<usize>> {
        MEMORY.lock().unwrap().clone()
    }

    /// Record one CODE body. Called on every VM entry.
    pub fn record(code: usize) {
        match sink() {
            None => {}
            Some(Sink::Memory) => {
                if let Some(set) = MEMORY.lock().unwrap().as_mut() {
                    set.insert(code);
                }
            }
            Some(Sink::File(path)) => {
                let mut line = String::with_capacity(8);
                line.push_str(itoa(code).as_str());
                line.push('\n');
                let _guard = FILE_LOCK.lock().unwrap();
                if let Ok(mut fh) = std::fs::OpenOptions::new().create(true).append(true).open(path) {
                    let _ = fh.write_all(line.as_bytes());
                }
            }
        }
    }
}

/// 栈槽：16 字节 RValue 的**值** + 它在原版值栈上占的**字节宽度**。
///
/// 宽度不是固定 16：卡里的落点公式按操作数宽度推进 —— `push_immediate` 是 -4、
/// `int32+int32` 是 +4、`real+real` 是 +8、两个 16 字节 RValue 槽是 +28。
/// 宽度默认由值的 tag 推（`Value::stack_width`）；指令字声明了存储类的读用
/// `Op::LoadSlot` 显式给（0/3→8、1/2/4/6→4、5→16）。
#[derive(Debug, Clone, Copy)]
struct Slot { value: Value, width: i32 }

/// 值栈 + 字节位移。push 下移、pop 上移，于是二元运算的位移自然就是
/// `右宽 + 左宽 - 结果宽`（卡 DoAdd「结果落点」段 / DoSet 的 `r7-4`）。
#[derive(Debug, Default)]
struct ValueStack { slots: Vec<Slot>, sp: i32 }

impl ValueStack {
    fn push(&mut self, value: Value) { self.push_width(value, value.stack_width()) }
    fn push_width(&mut self, value: Value, width: i32) { self.sp -= width; self.slots.push(Slot { value, width }) }
    fn push_slot(&mut self, slot: Slot) { self.sp -= slot.width; self.slots.push(slot) }
    fn pop(&mut self) -> Result<Slot, String> {
        let slot = self.slots.pop().ok_or_else(|| "stack underflow".to_string())?;
        self.sp += slot.width;
        Ok(slot)
    }
    fn pop_value(&mut self) -> Result<Value, String> { Ok(self.pop()?.value) }
    fn top(&self) -> Result<Slot, String> { self.slots.last().copied().ok_or_else(|| "stack underflow".to_string()) }
    fn len(&self) -> usize { self.slots.len() }
    fn is_empty(&self) -> bool { self.slots.is_empty() }
}

/// 存储类 → 字节宽度（DoDup 宽度表 / DoAdd 的 `slot_w`）。
pub fn class_width(cls: u8) -> i32 {
    match cls { 0 | 3 => 8, 1 | 2 | 4 | 6 => 4, 5 => 16, _ => 0 }
}

const fn pair_bit(left: u8, right: u8) -> u64 { 1u64 << ((left as u32) * 7 + right as u32) }

/// (0 real, 2 int32, 3 int64) 的九种组合 —— DoSub/DoDiv/DoRem/DoMod 的合法表。
const P9: u64 = pair_bit(0, 0) | pair_bit(0, 2) | pair_bit(0, 3)
    | pair_bit(2, 0) | pair_bit(2, 2) | pair_bit(2, 3)
    | pair_bit(3, 0) | pair_bit(3, 2) | pair_bit(3, 3);
const REM_OK: u64 = P9;
const MOD_OK: u64 = P9;
/// DoAnd/DoOr 的 bool 组合：bool×bool 与 bool 和 real 混算。
const OR_OK: u64 = P9 | pair_bit(0, 4) | pair_bit(4, 0) | pair_bit(4, 4);
const AND_OK: u64 = OR_OK;
/// DoXor 卡：只有 (4,4) 是 bool 内核，其余带 4 的组合全部 VMError。
const XOR_OK: u64 = P9 | pair_bit(4, 4);
/// DoShl：表4 合并了 (real,int32)/(real,int64) 与 (int64,int32)/(int64,int64)。
const SHL_OK: u64 = pair_bit(0, 0) | pair_bit(0, 2) | pair_bit(0, 3)
    | pair_bit(2, 0) | pair_bit(2, 2)
    | pair_bit(3, 0) | pair_bit(3, 2) | pair_bit(3, 3);
/// DoSet 卡里 16 个已列出的类型组合（含 (4,6)/(6,4) 两条 bool×string）。
const SET_TYPES_OK: u64 = pair_bit(0, 0) | pair_bit(0, 2) | pair_bit(0, 4)
    | pair_bit(2, 0) | pair_bit(2, 2) | pair_bit(2, 3) | pair_bit(2, 4)
    | pair_bit(3, 0) | pair_bit(3, 2) | pair_bit(3, 3)
    | pair_bit(4, 0) | pair_bit(4, 2) | pair_bit(4, 4) | pair_bit(4, 6)
    | pair_bit(6, 4) | pair_bit(6, 6);
/// DoShr：pair ∈ {0,2,3,32,34,35,48,50,51}。
const SHR_OK: u64 = pair_bit(0, 0) | pair_bit(2, 0) | pair_bit(3, 0)
    | pair_bit(0, 2) | pair_bit(2, 2) | pair_bit(3, 2)
    | pair_bit(0, 3) | pair_bit(2, 3) | pair_bit(3, 3);

fn pair_ok(mask: u64, la: u8, lb: u8) -> bool { (mask >> (la as u32 * 7 + lb as u32)) & 1 != 0 }

/// 指令字的两个格式 nibble → 两侧真实存储类（nib==5 时按值的 tag 反查）。
fn resolve_pair(op: &crate::value::Verdict, ty: u8, a: Value, b: Value) -> Result<(u8, u8), String> {
    let la = crate::value::resolve_class(a, (ty >> 4) & 0xF, op, 1)?;
    let lb = crate::value::resolve_class(b, ty & 0xF, op, 2)?;
    Ok((la, lb))
}

/// JS 慢路径的数值化：字符串要读 host 的文本池再按 strtod 的前缀口径
/// （`F_JS_ToNumber`）；其余值原样交给 `Value::js_to_number`。
fn numeric_operand<H: Host>(bundle: &Bundle, host: &mut H, v: Value) -> Result<Value, String> {
    if v.is_string() {
        let text = host.string_text(bundle, v)?;
        return Ok(Value::real(crate::value::parse_js_number(&text)));
    }
    Ok(v)
}

/// 立即数按 tag 装成值（`push_immediate` 的 tag 7 走 int32）。
fn constant_value(value: f64, tag: u8) -> Value {
    match tag {
        crate::value::TAG_INT32 => Value::int32(crate::value::f2i32(value)),
        crate::value::TAG_INT64 => Value::int64(crate::value::f2i64(value)),
        crate::value::TAG_BOOL => Value::boolean(value != 0.0),
        crate::value::TAG_UNDEFINED => Value::undefined(),
        crate::value::TAG_NULL => Value::null(),
        crate::value::TAG_STRING => Value::string(crate::value::f2i32(value) as u32),
        _ => Value::real(value),
    }
}

/// Runtime is value-tagged. Every event gets an empty stack and a bounded budget.
/// Unsupported code never falls back to the legacy handwritten state machines.
pub fn execute<H: Host>(bundle: &Bundle, code: usize, instance: i32, host: &mut H) -> Result<(), VmError> {
    execute_with_sp(bundle, code, instance, host).map(|_| ())
}

/// 与 `execute` 同一条解释器，但把退出时的值栈字节位移交出来（负数 = 向下长）。
/// 差分适配层用 `Host::stack_pointer` 取**单条算子**的位移，这个返回值是全体的和。
pub fn execute_with_sp<H: Host>(bundle: &Bundle, code: usize, instance: i32, host: &mut H) -> Result<i32, VmError> {
    let mut offset = 0;
    let result = (|| -> Result<i32, String> {
        if bundle.schema != 1 { return Err("unsupported IR schema".into()); }
        let body = bundle.codes.iter().find(|c| c.id == code).ok_or("missing CODE body")?;
        offset = body.start;
        let mut boundaries = std::collections::BTreeMap::new();
        let mut next = body.start;
        for (n, i) in body.instructions.iter().enumerate() {
            if i.offset != next || i.code_offset != i.offset - body.start || i.words_raw.is_empty() {
                return Err("noncontiguous IR source span".into());
            }
            boundaries.insert(i.offset, n);
            next = next.checked_add(i.words_raw.len() * 4).ok_or("source span overflow")?;
        }
        if next != body.end { return Err("incomplete CODE body".into()); }
        boundaries.insert(body.end, body.instructions.len());
        for i in &body.instructions {
            let target = match i.op { Op::B{target}|Op::Bt{target}|Op::Bf{target}|Op::Pushenv{target}|Op::Popenv{target} => Some(target), _=>None };
            if target.is_some_and(|t| !boundaries.contains_key(&t)) { offset=i.offset; return Err("branch not on instruction boundary".into()); }
        }
        // The ledger records execution, so it is written only once the body has
        // been validated and is about to run - a missing id, an unsupported
        // schema or a malformed span must not appear as "executed".
        coverage::record(code);
        let mut stack = ValueStack::default();
        let mut locals: std::collections::BTreeMap<String, Slot> = std::collections::BTreeMap::new();
        let mut environments: Vec<(i32, std::vec::IntoIter<i32>)> = Vec::new();
        let mut current = instance;
        let mut pc = 0;
        let mut budget = 100_000;
        while pc < body.instructions.len() {
            let i = &body.instructions[pc]; offset=i.offset;
            host.instruction(code, offset);
            if budget == 0 { return Err("instruction budget exhausted".into()); }
            budget -= 1; pc += 1;
            match &i.op {
                // A lowered constant is a real. Legacy IR files may still carry a
                // pooled string reference as a constant, so decode that encoding.
                Op::Constant{value} => stack.push(Value::from_legacy_numeric(*value)),
                Op::ConstantTagged{value, tag} => stack.push(constant_value(*value, *tag)),
                Op::String{string_id} => stack.push(Value::string(*string_id as u32)),
                Op::Load{name,selector,array,other} => {
                    let (s, index) = if *array {
                        let idx=integer(stack.pop_value()?)?;
                        (integer(stack.pop_value()?)?,Some(idx))
                    } else if *other {
                        (integer(stack.pop_value()?)?, None)
                    } else {
                        (*selector,None)
                    };
                    stack.push(host.read(current,s,name,index)?);
                }
                // The opcode word declared this slot's storage class, so the byte
                // width is known even when the value's tag disagrees with it.
                Op::LoadSlot{name,width} => {
                    let v = host.read(current, 0, name, None)?;
                    stack.push_width(v, *width as i32);
                }
                Op::Store{name,selector,array,other} => {
                    let (s, index, value) = if *array {
                        let idx = integer(stack.pop_value()?)?;
                        let s = integer(stack.pop_value()?)?;
                        let val = stack.pop_value()?;
                        (s, Some(idx), val)
                    } else if *other {
                        // Two GMS pop variants, discriminated by the value-type
                        // nibble in the original wordcode (preserved in
                        // words_raw[0]); both collapse to other=true in the IR:
                        //   type1==2 (compound-assignment codegen): stack
                        //     [dest, value] — dup kept dest under the computed
                        //     value, so pop value first, then dest.
                        //   type1==5 (pushed value): stack [value, dest] —
                        //     pop dest first, then value.
                        let type1 = ((i.words_raw[0] >> 16) & 0xff) & 0x0f;
                        if type1 == 2 {
                            let val = stack.pop_value()?;
                            let dest = integer(stack.pop_value()?)?;
                            (dest, None, val)
                        } else {
                            let dest = integer(stack.pop_value()?)?;
                            let val = stack.pop_value()?;
                            (dest, None, val)
                        }
                    } else {
                        let val = stack.pop_value()?;
                        (*selector, None, val)
                    };
                    host.write(current,s,name,index,value)?;
                }
                Op::StoreLocal{name} => { let slot=stack.pop()?; locals.insert(name.clone(),slot); }
                Op::Cast{to} => {
                    // DoConv type codes: src/dst are 0..6 (real/f32/int32/int64/bool/
                    // dynamic/string); the lowered IR only carries the dst. The
                    // result occupies the destination class's width (dst 5 = 16 B).
                    let slot=stack.pop()?;
                    let v=slot.value.cast(*to)?;
                    stack.push_width(v, class_width(*to));
                }
                Op::Add|Op::Sub|Op::Mul|Op::Div|Op::Cmp{..} => {
                    let rhs=stack.pop()?; let lhs=stack.pop()?;
                    let v=match i.op {
                        // GMS joins strings with `+` (DoAdd mode1: either side a
                        // string -> ToString both, then concatenate). The host owns
                        // the string pool, so it resolves and stores the result.
                        Op::Add if lhs.value.is_string() || rhs.value.is_string() => host.string_concat(bundle, lhs.value, rhs.value)?,
                        Op::Add => lhs.value.add(rhs.value)?,
                        Op::Sub => lhs.value.sub(rhs.value)?,
                        Op::Mul => lhs.value.mul(rhs.value)?,
                        Op::Div => lhs.value.div(rhs.value)?,
                        Op::Cmp{comparison} => {
                            if lhs.value.is_string() || rhs.value.is_string() {
                                // DoSet 0x66: strcmp, then the same K = 1..6 order.
                                // A string against a non-string is a combination the
                                // card leaves open; unsupported combinations yield a
                                // value, not an error (only != is 1).
                                match (lhs.value.is_string(), rhs.value.is_string()) {
                                    (true, true) => {
                                        let a = host.string_text(bundle, lhs.value)?;
                                        let b = host.string_text(bundle, rhs.value)?;
                                        let ord = a.cmp(&b);
                                        let truth = match comparison {
                                            1 => ord.is_lt(), 2 => ord.is_le(), 3 => ord.is_eq(),
                                            4 => ord.is_ne(), 5 => ord.is_ge(), 6 => ord.is_gt(),
                                            _ => return Err("unsupported comparison".into()),
                                        };
                                        Value::int32(if truth {1} else {0})
                                    }
                                    _ => Value::int32(if comparison == 4 {1} else {0}),
                                }
                            } else {
                                lhs.value.compare(rhs.value, comparison)?
                            }
                        }
                        _=>unreachable!(),
                    };
                    // 字符串结果是 16 字节 RValue（DoAdd 0x66 的落点就是 -16）；
                    // 其余结果按值的 tag 定宽（int32/bool 4、real/int64 8）。
                    if v.is_string() { stack.push_width(v, 16) } else { stack.push(v) }
                }
                // ── DoRem / DoMod / DoOr / DoXor / DoShl / DoShr ──
                // The format nibbles come from the opcode word; class 5 is the
                // 16-byte RValue slot whose real class is the value's tag.
                Op::Rem{ty, ..} => {
                    let rhs=stack.pop()?; let lhs=stack.pop()?;
                    let (la,lb)=resolve_pair(&crate::value::REM, *ty, lhs.value, rhs.value)?;
                    if !pair_ok(REM_OK, la, lb) { return Err(crate::value::REM.pair_error(la, lb)); }
                    stack.push(lhs.value.rem(rhs.value, la, lb)?);
                }
                Op::Mod{mode, ty} => {
                    let rhs=stack.pop()?; let lhs=stack.pop()?;
                    let (la,lb)=resolve_pair(&crate::value::MOD, *ty, lhs.value, rhs.value)?;
                    if !pair_ok(MOD_OK, la, lb) { return Err(crate::value::MOD.pair_error(la, lb)); }
                    stack.push(lhs.value.modulo(rhs.value, la, lb, *mode == 1)?);
                }
                Op::Or{mode, ty} => {
                    let rhs=stack.pop()?; let lhs=stack.pop()?;
                    let (la,lb)=resolve_pair(&crate::value::OR, *ty, lhs.value, rhs.value)?;
                    if !pair_ok(OR_OK, la, lb) { return Err(crate::value::OR.pair_error(la, lb)); }
                    let (lv,rv) = if *mode != 0 {
                        (numeric_operand(bundle, host, lhs.value)?, numeric_operand(bundle, host, rhs.value)?)
                    } else { (lhs.value, rhs.value) };
                    let v=lv.bitwise(rv,&crate::value::OR,BitOp::Or,la,lb,*mode)?;
                    if *mode != 0 { stack.push_width(v, 16) } else { stack.push(v) }
                }
                Op::Xor{mode, ty} => {
                    let rhs=stack.pop()?; let lhs=stack.pop()?;
                    let (la,lb)=resolve_pair(&crate::value::XOR, *ty, lhs.value, rhs.value)?;
                    if !pair_ok(XOR_OK, la, lb) { return Err(crate::value::XOR.pair_error(la, lb)); }
                    let (lv,rv) = if *mode != 0 {
                        (numeric_operand(bundle, host, lhs.value)?, numeric_operand(bundle, host, rhs.value)?)
                    } else { (lhs.value, rhs.value) };
                    let v=lv.bitwise(rv,&crate::value::XOR,BitOp::Xor,la,lb,*mode)?;
                    if *mode != 0 { stack.push_width(v, 16) } else { stack.push(v) }
                }
                Op::Shl{mode, ty} => {
                    let rhs=stack.pop()?; let lhs=stack.pop()?;
                    let (la,lb)=resolve_pair(&crate::value::SHL, *ty, lhs.value, rhs.value)?;
                    if !pair_ok(SHL_OK, la, lb) { return Err(crate::value::SHL.pair_error(la, lb)); }
                    let (lv,rv) = if *mode != 0 {
                        (numeric_operand(bundle, host, lhs.value)?, numeric_operand(bundle, host, rhs.value)?)
                    } else { (lhs.value, rhs.value) };
                    let v=lv.shift(rv,&crate::value::SHL,la,lb,*mode,true)?;
                    if *mode != 0 { stack.push_width(v, 16) } else { stack.push(v) }
                }
                Op::Shr{mode, ty} => {
                    let rhs=stack.pop()?; let lhs=stack.pop()?;
                    let (la,lb)=resolve_pair(&crate::value::SHR, *ty, lhs.value, rhs.value)?;
                    if !pair_ok(SHR_OK, la, lb) { return Err(crate::value::SHR.pair_error(la, lb)); }
                    let (lv,rv) = if *mode != 0 {
                        (numeric_operand(bundle, host, lhs.value)?, numeric_operand(bundle, host, rhs.value)?)
                    } else { (lhs.value, rhs.value) };
                    let v=lv.shift(rv,&crate::value::SHR,la,lb,*mode,false)?;
                    if *mode != 0 { stack.push_width(v, 16) } else { stack.push(v) }
                }
                // DoNeg: mode 1/2 take the JS path before the class table (the
                // card's entry checks mode first); 0/3..15 is the typed path,
                // in place, where cls 6 is the string error and 7..15 have no
                // kernel (Execution Error).
                Op::Neg{mode, ty} => {
                    let slot=stack.pop()?;
                    let cls=(*ty & 0x0F) as u8;
                    if *mode == 1 || *mode == 2 {
                        let n=numeric_operand(bundle, host, slot.value)?;
                        let v=n.neg(*mode)?;
                        stack.push_width(v, 16);
                    } else if cls > 6 {
                        return Err("DoNeg :: Execution Error".to_string());
                    } else if cls == 6 {
                        return Err("DoNeg :1: Execution Engine - Cannot operate on string type".to_string());
                    } else {
                        // In place: the strong-typed path rewrites the payload and
                        // returns r6, so sp does not move whatever the result tag is.
                        stack.push_width(slot.value.neg(*mode)?, slot.width);
                    }
                }
                // DoNot: mode 1 is logical `!` (4-byte result), mode 2 is the JS
                // `~` (16-byte Real), 0/3..15 is the typed bitwise NOT, in place.
                Op::NotMode{mode, ty} => {
                    let slot=stack.pop()?;
                    let cls=(*ty & 0x0F) as u8;
                    match *mode {
                        1 => {
                            if cls > 6 { return Err("DoNot :: Execution Error".to_string()); }
                            if slot.value.is_unresolved() {
                                return Err("DoNot :: Malformed variable".to_string());
                            }
                            let truth = if slot.value.is_string() {
                                !host.string_text(bundle, slot.value)?.is_empty()
                            } else { slot.value.to_bool() };
                            stack.push_width(Value::int32(if truth {0} else {1}), 4);
                        }
                        2 => {
                            let n=numeric_operand(bundle, host, slot.value)?;
                            let v=n.bit_not(2, cls)?;
                            stack.push_width(v, 16);
                        }
                        _ => {
                            if cls > 6 { return Err("DoNot :: Execution Error".to_string()); }
                            if cls == 6 { return Err("DoNot :: Execution Engine - Cannot operate on string type".to_string()); }
                            // In place (卡：就地改载荷、sp 不动).
                            stack.push_width(slot.value.bit_not(0, cls)?, slot.width);
                        }
                    }
                }
                // DoNot mode1: JS_ToBoolean then negate, result is a 4-byte int.
                Op::Not => { let v=stack.pop_value()?; stack.push(v.logical_not()); }
                Op::Dup => { let slot=stack.pop()?; stack.push_slot(slot); stack.push_slot(slot); }
                // DoDup swap mode: only type==5 reaches the memcpy/memmove/memcpy
                // swap; the protocol carries n=mode but not m, so m=0 and the
                // swap degenerates to a no-op that returns the stack top.
                Op::DupMode{mode, ty} => {
                    if *mode == 0 {
                        let slot=stack.pop()?; stack.push_slot(slot); stack.push_slot(slot);
                    } else if *ty != 5 {
                        return Err(format!("Argument type {} currently unhandled by DoDup swap mode", ty));
                    } else {
                        let _ = stack.top()?;
                    }
                }
                // DoAnd: bool x bool is logical (short-circuit and, tag 13);
                // everything else is GML's ToInt64 & ToInt64, written back in the
                // width of the widest operand.
                Op::And => { let rhs=stack.pop()?; let lhs=stack.pop()?; stack.push(lhs.value.bit_and(rhs.value)?); }
                // DoSet：先按声明类解析两侧（数组/指针/undefined/表外 tag 都是
                // 错误），再按卡片的 16 组合表决定「比较」还是「未支持组合给值」。
                Op::CmpMode{comparison, ty} => {
                    let rhs=stack.pop()?; let lhs=stack.pop()?;
                    let ha=(*ty>>4)&0x0F; let hb=*ty&0x0F;
                    let value = if ha > 6 || hb > 6 {
                        // 表外格式码没有 dest 表项 → 给值不给错（K=4 得 1）。
                        Value::int32(if *comparison == 4 {1} else {0})
                    } else {
                        let la=crate::value::resolve_class(lhs.value, ha, &crate::value::SET, 1)?;
                        let lb=crate::value::resolve_class(rhs.value, hb, &crate::value::SET, 2)?;
                        if la == 6 && lb == 6 {
                            let a=host.string_text(bundle, lhs.value)?;
                            let b=host.string_text(bundle, rhs.value)?;
                            let ord=a.cmp(&b);
                            let truth = match *comparison {
                                1 => ord.is_lt(), 2 => ord.is_le(), 3 => ord.is_eq(),
                                4 => ord.is_ne(), 5 => ord.is_ge(), 6 => ord.is_gt(),
                                _ => return Err("unsupported comparison".into()),
                            };
                            Value::int32(if truth {1} else {0})
                        } else if la == 6 || lb == 6 || !pair_ok(SET_TYPES_OK, la, lb) {
                            // 字符串与数字混比 / 未支持组合：卡里给值（只有 != 得 1）。
                            Value::int32(if *comparison == 4 {1} else {0})
                        } else {
                            // 卡片数值路径：d = 左 - 右，与全局 1e-05 容差比较
                            // （整数对也走 double，不是精确整数比较）。
                            let d=lhs.value.to_real()? - rhs.value.to_real()?;
                            let truth = if d.is_nan() {
                                *comparison == 4
                            } else {
                                let eps=crate::value::COMPARE_EPSILON;
                                match *comparison {
                                    1 => d < -eps, 2 => d <= eps, 3 => d.abs() <= eps,
                                    4 => d.abs() > eps, 5 => d >= -eps, 6 => d > eps,
                                    _ => return Err("unsupported comparison".into()),
                                }
                            };
                            Value::int32(if truth {1} else {0})
                        }
                    };
                    stack.push_width(value, 4);
                }
                Op::AndMode{mode, ty} => {
                    let rhs=stack.pop()?; let lhs=stack.pop()?;
                    let (la,lb)=resolve_pair(&crate::value::AND, *ty, lhs.value, rhs.value)?;
                    if !pair_ok(AND_OK, la, lb) { return Err(crate::value::AND.pair_error(la, lb)); }
                    let (lv,rv) = if *mode != 0 {
                        (numeric_operand(bundle, host, lhs.value)?, numeric_operand(bundle, host, rhs.value)?)
                    } else { (lhs.value, rhs.value) };
                    let v=lv.bitwise(rv,&crate::value::AND,BitOp::And,la,lb,*mode)?;
                    if *mode != 0 { stack.push_width(v, 16) } else { stack.push(v) }
                }
                Op::LoadLocal{name} => { let slot=*locals.get(name).ok_or(format!("undefined local {name}"))?; stack.push_slot(slot); }
                Op::B{target} => pc=boundaries[target],
                Op::Bt{target}|Op::Bf{target} => {
                    let yes=stack.pop_value()?.to_bool();
                    if yes == matches!(i.op,Op::Bt{..}) { pc=boundaries[target]; }
                }
                Op::Pushenv{target} => {
                    let selector=integer(stack.pop_value()?)?;
                    let mut selected=host.select(current,selector)?.into_iter();
                    let first=selected.next(); environments.push((current,selected));
                    if let Some(id)=first { current=id; } else { pc=boundaries[target]; }
                }
                Op::Popenv{target} => {
                    let frame=environments.last_mut().ok_or("environment stack underflow")?;
                    if let Some(id)=frame.1.next() { current=id; pc=boundaries[target]; }
                    else { current=frame.0; environments.pop(); }
                }
                Op::Call{name,argc} => {
                    if *argc > stack.len() { return Err("call argument underflow".into()); }
                    let args=(0..*argc).map(|_| stack.pop_value().unwrap()).collect::<Vec<_>>();
                    stack.push(host.call(bundle,current,name,&args)?);
                }
                Op::Popz => { stack.pop()?; }
                Op::Exit => break,
            }
            host.stack_pointer(stack.sp);
        }
        if !stack.is_empty() || !environments.is_empty() { return Err("unbalanced stack/environment at CODE exit".into()); }
        Ok(stack.sp)
    })();
    result.map_err(|message| VmError{code,offset,message})
}

pub fn load_bundle_from_file<P: AsRef<std::path::Path>>(path: P) -> Result<Bundle, Box<dyn std::error::Error>> {
    // Read once and parse from the slice: `from_reader` pays a BufReader
    // boundary per token, and this file is 52 MB with ~245 k instructions, so
    // the per-process load is the dominant cost of both the test suite (162
    // binaries each parse it) and the body-by-body differential.
    let bytes = std::fs::read(path)?;
    let bundle = serde_json::from_slice(&bytes)?;
    Ok(bundle)
}
