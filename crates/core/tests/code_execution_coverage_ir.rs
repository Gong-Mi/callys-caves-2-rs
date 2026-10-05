//! The execution ledger is OFF by default.
//!
//! Its own test binary on purpose: tracing state is process-global, so a file
//! that also calls `enable_memory()` cannot make this claim. `CALLY_CODE_TRACE`
//! is not set in this process.
use callys_core::code_vm::{coverage, execute, Bundle, Code, Host, Instruction, Op};

fn body(id: usize, start: usize) -> Code {
    Code {
        id,
        start,
        end: start + 4,
        instructions: vec![Instruction {
            offset: start,
            code_offset: 0,
            words_raw: vec![0],
            op: Op::Exit,
        }],
    }
}

fn bundle(schema: u32, codes: Vec<Code>) -> Bundle {
    Bundle { schema, string_table: Vec::new(), objects: Vec::new(), room_bindings: Vec::new(), codes }
}

/// The VM needs a Host; these bodies never touch it.
struct NullHost;

impl Host for NullHost {
    fn read(&mut self, _i: i32, _s: i32, name: &str, _x: Option<i32>) -> Result<f64, String> {
        Err(format!("unexpected read of {name}"))
    }
    fn write(&mut self, _i: i32, _s: i32, name: &str, _x: Option<i32>, _v: f64) -> Result<(), String> {
        Err(format!("unexpected write of {name}"))
    }
    fn call(&mut self, _b: &Bundle, _i: i32, name: &str, _a: &[f64]) -> Result<f64, String> {
        Err(format!("unexpected builtin {name}"))
    }
    fn select(&self, _i: i32, _s: i32) -> Result<Vec<i32>, String> {
        Ok(Vec::new())
    }
}

#[test]
fn executing_bodies_records_nothing_until_tracing_is_turned_on() {
    let b = bundle(1, vec![body(7, 0x100), body(9, 0x200)]);
    assert!(coverage::executed().is_none(), "tracing must be off by default");
    execute(&b, 7, 1, &mut NullHost).expect("exit body runs");
    execute(&b, 9, 1, &mut NullHost).expect("exit body runs");
    assert!(coverage::executed().is_none(), "an untraced run must not fabricate a ledger");
}
