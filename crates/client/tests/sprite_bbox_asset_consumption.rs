//! Sprite metadata must come from the supplied asset, not an ID-specific table.
use callys_client::GameState;
use callys_core::code_vm::{load_bundle_from_file, Host};
use std::{path::Path, sync::Arc};
fn u32_at(b:&[u8],p:usize)->u32 {u32::from_le_bytes(b[p..p+4].try_into().unwrap())}
#[test]
fn distance_reads_manual_bbox_from_the_loaded_asset_even_when_sprite_id_and_size_match() {
    let root=Path::new(env!("CARGO_MANIFEST_DIR")).join("../..");
    let mut bytes=std::fs::read(root.join("assets/game.droid")).unwrap();
    let mut chunk=8;
    while &bytes[chunk..chunk+4]!=b"SPRT" {chunk+=8+u32_at(&bytes,chunk+4) as usize;}
    let record=u32_at(&bytes,chunk+8+4+29*4) as usize;
    assert_eq!(u32_at(&bytes,record+16),22,"standing player original right bbox edge");
    // Asset edit: same id/dimensions/masks but a different manual right edge.
    // Source bytes, not the pixel mask or dimensions, are the bbox authority.
    bytes[record+16..record+20].copy_from_slice(&19u32.to_le_bytes());
    let temp=tempfile::tempdir().unwrap(); let path=temp.path().join("game.droid");
    std::fs::write(&path,bytes).unwrap();
    let mut s=GameState::new(&path).unwrap();
    s.enable_ir_gameplay(Arc::new(load_bundle_from_file(&root.join("crates/core/src/generated/full_ir.json")).unwrap())).unwrap();
    s.retire_prologue();
    let bundle=s.full_bundle.clone().unwrap();let scene=s.scene.as_mut().unwrap();
    let player=*scene.instances.iter().find(|(_,i)|i.object==0&&i.alive).unwrap().0;
    let lloyd=*scene.instances.iter().find(|(_,i)|i.object==154&&i.alive).unwrap().0;
    scene.write(player,-1,"mask_index",None,29.0).unwrap();
    scene.write(player,-1,"x",None,646.0).unwrap(); scene.write(player,-1,"y",None,494.0).unwrap();
    let distance=scene.call(&bundle,lloyd,"distance_to_object",&[0.0]).unwrap();
    assert_eq!(distance,103.0,"manual asset bbox right19 gives gap103, not cached original gap100");
}
