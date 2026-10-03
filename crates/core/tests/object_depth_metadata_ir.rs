//! Independent raw OBJT metadata -> generated production IR consistency.
use callys_core::code_vm::load_bundle_from_file;
use std::path::Path;
fn u(b:&[u8],p:usize)->u32{u32::from_le_bytes(b[p..p+4].try_into().unwrap())}
#[test]
fn every_generated_object_depth_matches_original_objt_not_persistent() {
 let root=Path::new(env!("CARGO_MANIFEST_DIR")).join("../..");
 let bytes=std::fs::read(root.join("assets/game.droid")).unwrap();
 let mut p=8;while &bytes[p..p+4]!=b"OBJT"{p+=8+u(&bytes,p+4)as usize;} p+=8;
 let b=load_bundle_from_file(&root.join("crates/core/src/generated/full_ir.json")).unwrap();
 assert_eq!(b.objects.len(),u(&bytes,p)as usize);
 for o in &b.objects {
  let r=u(&bytes,p+4+o.id as usize*4)as usize;
  let raw_depth=u(&bytes,r+16)as i32;
  let persistent=u(&bytes,r+20)!=0;
  assert_eq!(o.depth,raw_depth,"OBJT {} {} depth must use +16, not persistent={persistent}",o.id,o.name);
  assert_eq!(o.persistent,persistent,"OBJT {} persistent source is unchanged",o.id);
 }
}
