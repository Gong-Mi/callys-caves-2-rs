## Problem
The replacement parses ROOM tile records but the runtime drops them. `RoomData.tiles` is populated by the asset parser, yet `GameWorld::load_room()` only materializes ROOM objects and `draw_frame()` never consumes `room.tiles`.

Evidence from the current asset:
- `rm_level1`: 1,341 objects and 114 parsed tile records.
- The parsed tile fields include position, source rectangle, depth, and scale.
- The current renderer has no tile draw path.

This is a direct cause of the replacement map diverging from the original game.

## Scope of this issue / PR
- Preserve room tile records in runtime state.
- Render the original tile texture-page rectangles using the existing TPAG/atlas data.
- Apply tile position, source rectangle, scale, and depth ordering for this slice.
- Add parser/runtime/render tests for the tile path.

## Explicit non-goals
- Do not add unrelated object types.
- Do not rewrite enemy AI or warp logic.
- Do not claim full visual parity after this PR; object dispatch, draw events/depth, and missing object classes remain separate work.
- Do not use screenshots as semantic evidence.

## Acceptance
- A fixture with a known RoomTileInstance produces a corresponding atlas blit.
- The real asset still parses with `rm_level1` reporting 114 tiles.
- Existing tests remain green.
