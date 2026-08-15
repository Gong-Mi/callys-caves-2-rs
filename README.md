# Cally's Caves 2 — Rust reconstruction

A native 64-bit Rust reconstruction driven by the original GameMaker Studio 1.4 `game.droid` data.

This is not a wrapper around the legacy 32-bit `libyoyo.so`. The APK contains an AArch64 Rust engine, parses the original room/object/sprite/texture-page data, and renders the game with the extracted texture atlases.

## Current playable build

The Android client currently provides:

- all 114 original ROOM records and 191 OBJT records parsed from `game.droid`;
- original room geometry, wall/boulder/platform collisions and camera following;
- original player, wall, collectible, door and enemy texture-page sprites;
- movement, jumping, five weapon modes, projectiles, damage, collectibles and room-door transitions;
- multi-touch controls with latched tap handling for jump and attack;
- aspect-correct landscape rendering on Android;
- a self-contained arm64-v8a APK build.

The reconstruction is still being iterated. Original GameMaker bytecode behavior, exact room-transition creation code, progression, persistence, audio/music, menus/story scenes and the full enemy/boss behavior set remain separate reconstruction work; build success is not treated as gameplay parity.

## Controls

Android:

- lower-left blue areas: move left/right;
- lower-right yellow area: jump;
- lower-right red area: attack;
- tap the top strip: cycle weapon.

Desktop (`--features desktop`): A/D or arrows, W/Space jump, J/Z attack, 1–5 weapons.

## Build on Termux

```sh
cargo test --workspace --all-targets
cargo build --release -p callys-client --features android
bash scripts/build_apk.sh
```

Output:

```text
android-build/CallysCaves2_64bit_Rust.apk
```

The build script removes the Termux RUNPATH, assembles with native `aapt2`, D8 and `apksigner`, and verifies the final signature.

## Reverse-engineering utility

```sh
cargo run -p callys-asset --example inspect -- assets/game.droid
```

This prints every room's dimensions, object/tile counts and object-name distribution, plus relevant object-to-sprite mappings.

See `reconstruction/reverse-v1/apk/identity.md` for the pinned APK identity and observed runtime baseline.
