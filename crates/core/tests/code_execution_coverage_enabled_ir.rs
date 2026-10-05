//! The execution ledger records exactly the bodies that ran.
//!
//! One enabling test per binary: tracing state is process-global, so two tests
//! in this file would cross-talk (Rust runs them in parallel threads).
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
fn the_ledger_records_exactly_the_bodies_that_ran() {
    coverage::enable_memory();
    let b = bundle(1, vec![body(7, 0x100), body(9, 0x200)]);
    execute(&b, 7, 1, &mut NullHost).expect("body 7");
    execute(&b, 7, 1, &mut NullHost).expect("body 7 again");
    execute(&b, 9, 1, &mut NullHost).expect("body 9");
    assert_eq!(
        coverage::executed().expect("memory trace").into_iter().collect::<Vec<_>>(),
        vec![7, 9],
        "each body once, in id order"
    );

    // Failures before execution must not enter the ledger: a missing id ...
    assert!(execute(&b, 12345, 1, &mut NullHost).is_err());
    assert_eq!(coverage::executed().unwrap().len(), 2, "a missing id is not an execution");
    // ... and an unsupported schema.
    let bad = bundle(99, vec![body(3, 0x100)]);
    assert!(execute(&bad, 3, 1, &mut NullHost).is_err(), "schema 99 is unsupported");
    assert!(!coverage::executed().unwrap().contains(&3), "rejected schema is not an execution");
}
