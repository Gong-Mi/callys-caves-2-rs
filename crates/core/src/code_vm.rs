//! CODE interpreter. Deliberately separate from generated event bodies.
//!
//! The stack is `Vec<Value>`: every slot carries the RValue tag from
//! `reconstruction/contracts/value-model.md` (real / int32 / int64 / string /
//! undefined / null / bool), so integer wraparound, i64 pairs and the ±1e-05
//! comparison tolerance happen on the tag the original VM would have seen
//! instead of being flattened into one `f64`.
use serde::Deserialize;
pub use crate::value::{Payload, Value, STRING_REF_BASE};

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
    Constant { value: f64 }, String { string_id: usize },
    Load { name: String, selector: i32, array: bool, #[serde(default)] other: bool },
    Store { name: String, selector: i32, array: bool, #[serde(default)] other: bool },
    LoadLocal { name: String },
    StoreLocal { name: String }, Cast { to: u8 },
    Add, Sub, Mul, Div, Not, Dup, And, Cmp { comparison: u8 }, B { target: usize }, Bt { target: usize }, Bf { target: usize },
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
fn pop(stack: &mut Vec<Value>) -> Result<Value, String> { stack.pop().ok_or("stack underflow".into()) }

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

/// Runtime is numeric-only. Every event gets an empty stack and a bounded budget.
/// Unsupported code never falls back to the legacy handwritten state machines.
pub fn execute<H: Host>(bundle: &Bundle, code: usize, instance: i32, host: &mut H) -> Result<(), VmError> {
    let mut offset = 0;
    let result = (|| -> Result<(), String> {
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
        let mut stack = Vec::new();
        let mut locals = std::collections::BTreeMap::new();
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
                Op::String{string_id} => stack.push(Value::string(*string_id as u32)),
                Op::Load{name,selector,array,other} => {
                    let (s, index) = if *array {
                        let idx=integer(pop(&mut stack)?)?;
                        (integer(pop(&mut stack)?)?,Some(idx))
                    } else if *other {
                        (integer(pop(&mut stack)?)?, None)
                    } else {
                        (*selector,None)
                    };
                    stack.push(host.read(current,s,name,index)?);
                }
                Op::Store{name,selector,array,other} => {
                    let (s, index, value) = if *array {
                        let idx = integer(pop(&mut stack)?)?;
                        let s = integer(pop(&mut stack)?)?;
                        let val = pop(&mut stack)?;
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
                            let val = pop(&mut stack)?;
                            let dest = integer(pop(&mut stack)?)?;
                            (dest, None, val)
                        } else {
                            let dest = integer(pop(&mut stack)?)?;
                            let val = pop(&mut stack)?;
                            (dest, None, val)
                        }
                    } else {
                        let val = pop(&mut stack)?;
                        (*selector, None, val)
                    };
                    host.write(current,s,name,index,value)?;
                }
                Op::StoreLocal{name} => { let value=pop(&mut stack)?; locals.insert(name.clone(),value); }
                Op::Cast{to} => {
                    // DoConv type codes: src/dst are 0..6 (real/f32/int32/int64/bool/
                    // dynamic/string); the lowered IR only carries the dst.
                    let v=pop(&mut stack)?;
                    stack.push(v.cast(*to)?);
                }
                Op::Add|Op::Sub|Op::Mul|Op::Div|Op::Cmp{..} => {
                    let rhs=pop(&mut stack)?; let lhs=pop(&mut stack)?;
                    let v=match i.op {
                        // GMS joins strings with `+` (DoAdd mode1: either side a
                        // string -> ToString both, then concatenate). The host owns
                        // the string pool, so it resolves and stores the result.
                        Op::Add if lhs.is_string() || rhs.is_string() => host.string_concat(bundle, lhs, rhs)?,
                        Op::Add => lhs.add(rhs)?,
                        Op::Sub => lhs.sub(rhs)?,
                        Op::Mul => lhs.mul(rhs)?,
                        Op::Div => lhs.div(rhs)?,
                        Op::Cmp{comparison} => {
                            if lhs.is_string() || rhs.is_string() {
                                // DoSet 0x66: strcmp, then the same K = 1..6 order.
                                // A string against a non-string is a combination the
                                // card leaves open; unsupported combinations yield a
                                // value, not an error (only != is 1).
                                match (lhs.is_string(), rhs.is_string()) {
                                    (true, true) => {
                                        let a = host.string_text(bundle, lhs)?;
                                        let b = host.string_text(bundle, rhs)?;
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
                                lhs.compare(rhs, comparison)?
                            }
                        }
                        _=>unreachable!(),
                    }; stack.push(v);
                }
                // DoNot mode1: JS_ToBoolean then negate, result is a 4-byte int.
                Op::Not => { let v=pop(&mut stack)?; stack.push(v.logical_not()); }
                Op::Dup => { let v=pop(&mut stack)?; stack.push(v); stack.push(v); }
                // DoAnd: bool x bool is logical (short-circuit and, tag 13);
                // everything else is GML's ToInt64 & ToInt64, written back in the
                // width of the widest operand.
                Op::And => { let rhs=pop(&mut stack)?; let lhs=pop(&mut stack)?; stack.push(lhs.bit_and(rhs)?); }
                Op::LoadLocal{name} => { let v=*locals.get(name).ok_or(format!("undefined local {name}"))?; stack.push(v); }
                Op::B{target} => pc=boundaries[target],
                Op::Bt{target}|Op::Bf{target} => {
                    let yes=pop(&mut stack)?.to_bool();
                    if yes == matches!(i.op,Op::Bt{..}) { pc=boundaries[target]; }
                }
                Op::Pushenv{target} => {
                    let selector=integer(pop(&mut stack)?)?;
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
                    let args=(0..*argc).map(|_| stack.pop().unwrap()).collect::<Vec<_>>();
                    stack.push(host.call(bundle,current,name,&args)?);
                }
                Op::Popz => { pop(&mut stack)?; }
                Op::Exit => break,
            }
            // Only a real payload can be non-finite; integers and bools always pass.
            if stack.iter().any(|v| !v.is_finite()) { return Err("non-finite numeric value unsupported".into()); }
        }
        if !stack.is_empty() || !environments.is_empty() { return Err("unbalanced stack/environment at CODE exit".into()); }
        Ok(())
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
