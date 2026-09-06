//! Numeric CODE interpreter. Deliberately separate from generated event bodies.
use serde::Deserialize;

#[derive(Debug, Clone, Deserialize)]
pub struct Bundle { pub schema: u32, pub objects: Vec<Object>, pub codes: Vec<Code> }
#[derive(Debug, Clone, Deserialize)]
pub struct Object { pub id: i32, pub name: String, pub sprite: i32, pub depth: i32, pub events: Vec<Event> }
#[derive(Debug, Clone, Deserialize)]
pub struct Event { pub event_type: i32, pub subtype: i32, pub codes: Vec<usize> }
#[derive(Debug, Clone, Deserialize)]
pub struct Code { pub id: usize, pub start: usize, pub end: usize, pub instructions: Vec<Instruction> }
#[derive(Debug, Clone, Deserialize)]
pub struct Instruction { pub offset: usize, pub code_offset: usize, pub words_raw: Vec<u32>, #[serde(flatten)] pub op: Op }
#[derive(Debug, Clone, Deserialize)]
#[serde(tag = "op", rename_all = "snake_case")]
pub enum Op {
    Constant { value: f64 }, Load { name: String, selector: i32, array: bool },
    Store { name: String, selector: i32, array: bool }, LoadLocal { name: String },
    StoreLocal { name: String }, Cast { to: u8 },
    Add, Sub, Mul, Div, Not, Cmp { comparison: u8 }, B { target: usize }, Bt { target: usize }, Bf { target: usize },
    Pushenv { target: usize }, Popenv { target: usize }, Call { name: String, argc: usize }, Popz, Exit,
}
#[derive(Debug, Clone, PartialEq)]
pub struct VmError { pub code: usize, pub offset: usize, pub message: String }
impl std::fmt::Display for VmError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result { write!(f, "CODE {} @0x{:x}: {}", self.code, self.offset, self.message) }
}
impl std::error::Error for VmError {}
pub trait Host {
    fn read(&mut self, instance: i32, selector: i32, name: &str, index: Option<i32>) -> Result<f64, String>;
    fn write(&mut self, instance: i32, selector: i32, name: &str, index: Option<i32>, value: f64) -> Result<(), String>;
    fn call(&mut self, bundle: &Bundle, instance: i32, name: &str, args: &[f64]) -> Result<f64, String>;
    fn select(&self, instance: i32, selector: i32) -> Result<Vec<i32>, String>;
    fn instruction(&mut self, _code: usize, _offset: usize) {}
}
pub fn prologue_bundle() -> Bundle { serde_json::from_str(include_str!("generated/prologue_ir.json")).expect("generated IR schema") }
fn integer(v: f64) -> Result<i32, String> {
    if v.is_finite() && v.fract() == 0.0 && v >= i32::MIN as f64 && v <= i32::MAX as f64 { Ok(v as i32) }
    else { Err(format!("unsupported non-i32 selector/index {v}")) }
}
fn pop(stack: &mut Vec<f64>) -> Result<f64, String> { stack.pop().ok_or("stack underflow".into()) }

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
                Op::Constant{value} => stack.push(*value),
                Op::Load{name,selector,array} => {
                    let (s, index) = if *array { let idx=integer(pop(&mut stack)?)?; (integer(pop(&mut stack)?)?,Some(idx)) } else { (*selector,None) };
                    stack.push(host.read(current,s,name,index)?);
                }
                Op::Store{name,selector,array} => {
                    let (s, index) = if *array { let idx=integer(pop(&mut stack)?)?; (integer(pop(&mut stack)?)?,Some(idx)) } else { (*selector,None) };
                    let value=pop(&mut stack)?; host.write(current,s,name,index,value)?;
                }
                Op::StoreLocal{name} => { let value=pop(&mut stack)?; locals.insert(name.clone(),value); }
                Op::Cast{to} => {
                    let v=pop(&mut stack)?;
                    stack.push(match to { 0|5 => v, 4 => if v >= 0.5 {1.0} else {0.0}, 2 => integer(v.trunc())? as f64, _=>return Err("unsupported cast".into()) });
                }
                Op::Add|Op::Sub|Op::Mul|Op::Div|Op::Cmp{..} => {
                    let rhs=pop(&mut stack)?; let lhs=pop(&mut stack)?;
                    let v=match i.op {
                        Op::Add=>lhs+rhs, Op::Sub=>lhs-rhs, Op::Mul=>lhs*rhs,
                        Op::Div=>{ if rhs==0.0 {return Err("division by zero".into());} lhs/rhs }
                        Op::Cmp{comparison} => { let b=match comparison {1=>lhs<rhs,2=>lhs<=rhs,3=>lhs==rhs,4=>lhs!=rhs,5=>lhs>=rhs,6=>lhs>rhs,_=>return Err("unsupported comparison".into())}; if b {1.0} else {0.0} },
                        _=>unreachable!(),
                    }; stack.push(v);
                }
                Op::Not => { let v=pop(&mut stack)?; stack.push(if v>=0.5 {0.0} else {1.0}); }
                Op::LoadLocal{name} => { let v=*locals.get(name).ok_or(format!("undefined local {name}"))?; stack.push(v); }
                Op::B{target} => pc=boundaries[target],
                Op::Bt{target}|Op::Bf{target} => {
                    let yes=pop(&mut stack)? >= 0.5;
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
            if stack.iter().any(|x| !x.is_finite()) { return Err("non-finite numeric value unsupported".into()); }
        }
        if !stack.is_empty() || !environments.is_empty() { return Err("unbalanced stack/environment at CODE exit".into()); }
        Ok(())
    })();
    result.map_err(|message| VmError{code,offset,message})
}
