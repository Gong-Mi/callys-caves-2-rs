use callys_core::code_vm::*;
use std::collections::BTreeMap;
#[derive(Default)]
struct ScalarHost { fields: BTreeMap<String, f64> }
impl Host for ScalarHost {
    fn read(&mut self, _:i32, s:i32, n:&str, i:Option<i32>) -> Result<f64,String> {
        if s != -1 || i.is_some() { return Err("unsupported address".into()); }
        self.fields.get(n).copied().ok_or(format!("undefined {n}"))
    }
    fn write(&mut self, _:i32, s:i32, n:&str, i:Option<i32>, v:f64) -> Result<(),String> {
        if s != -1 || i.is_some() { return Err("unsupported address".into()); }
        self.fields.insert(n.into(),v); Ok(())
    }
    fn call(&mut self,_:&Bundle,_:i32,n:&str,_:&[f64])->Result<f64,String>{Err(format!("unsupported builtin {n}"))}
    fn select(&self,_:i32,_:i32)->Result<Vec<i32>,String>{Err("unsupported selector".into())}
}
#[test]
fn original_code_552_executes_both_assignments() {
    let b=prologue_bundle(); let mut h=ScalarHost::default();
    h.fields.insert("moving".into(),1.0); h.fields.insert("moving2".into(),0.0);
    let result=execute(&b,552,100001,&mut h);
    assert!(result.is_ok(),"original CODE failed: {result:?}");
    assert_eq!(h.fields["moving"],0.0); assert_eq!(h.fields["moving2"],1.0);
}
