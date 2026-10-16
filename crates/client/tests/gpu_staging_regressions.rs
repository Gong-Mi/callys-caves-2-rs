//! Parent regressions for command staging, independent of a GL implementation.
use callys_client::{
    consume_command_list, AtlasPage, DepthSlot, GpuCommandList, GpuPaint, GpuQuadDst,
};
use callys_core::ir_scene::DrawPhase;

fn staged(flip_x: bool) -> Vec<f32> {
    let mut list = GpuCommandList::new();
    list.emit_sprite(
        DepthSlot { phase: DrawPhase::Room, depth: 0.0, emit_order: 0 },
        AtlasPage { tex: 0, rect: (2, 4, 4, 8), atlas: (16, 16) },
        (2, 4, 4, 8),
        GpuQuadDst::Rect { x: 10, y: 20, w: 8, h: 16, flip_x },
        GpuPaint::default(),
    );
    consume_command_list(&list, (64, 64)).staging
}

#[test]
fn mirrored_rect_reverses_uvs_without_changing_screen_geometry() {
    let plain = staged(false);
    let flipped = staged(true);
    for (i, mirrored_corner) in [1usize, 0, 3, 2].into_iter().enumerate() {
        assert_eq!(&plain[i * 8..i * 8 + 2], &flipped[i * 8..i * 8 + 2]);
        assert_eq!(
            &flipped[i * 8 + 2..i * 8 + 4],
            &plain[mirrored_corner * 8 + 2..mirrored_corner * 8 + 4],
            "mirroring must change the sampled texels at corner {i}",
        );
        assert_eq!(&plain[i * 8 + 4..i * 8 + 8], &flipped[i * 8 + 4..i * 8 + 8]);
    }
}
