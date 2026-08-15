# Original APK identity and runtime baseline

Evidence level A unless otherwise noted.

- Source: `/storage/emulated/0/Download/Cally's+Caves+2_2.1.9_APKPure.apk`
- Size: 38,369,459 bytes
- SHA-256: `d608f4557ad66326de36268b9ab062afec839344e57d85afb6220405ea8cd8c9`
- Package: `com.vdogames.callyscaves2`
- Version: `2.1.9` (`versionCode=2001009`)
- Launcher: `com.vdogames.callyscaves2.RunnerActivity`
- minSdk/targetSdk: 14/26
- Engine: GameMaker Studio runner (`assets/game.droid`, `libyoyo.so`)
- Native ABIs: armeabi, armeabi-v7a, mips, x86; all original native libraries are ELF32
- `assets/game.droid`: 28,098,976 bytes
- `assets/game.droid` SHA-256: `9eee3f3aa6718375f2cd24fbfa33e075879a291ba9d43214441d4408994347a6`
- Data inventory parsed by the Rust asset crate: 114 ROOM, 191 OBJT, 178 SPRT, 1,791 TPAG

## Original runtime observation on Android 16

The installed original launched successfully through the 32-bit compatibility path on rothko and loaded:

- `lib/arm/libopenal.so`
- `lib/arm/libyoyo.so`
- OpenGL ES 1 renderer with a 16-bit color EGL configuration

The observed first screen was the original pixel-art story intro. The runner logged `State->Splash`, `State->InitRunner`, then initialized OpenAL and the game data.

## Reconstruction corrections discovered in this pass

- SPRT frame references are absolute TPAG record pointers, not zero-based TPAG indices.
- The SPRT metadata span before `origin_x/origin_y` is 36 bytes (bbox fields plus five flags/pointers); the previous parser skipped 40 bytes and shifted every frame list.
- The replacement must copy all four extracted texture atlases beside `game.droid` before initializing Rust rendering.
- Android Canvas presentation must preserve the 960×540 logical aspect ratio; stretching to the physical Surface produced vertically distorted sprites and tiles.
- Brief tap events need a small render-frame latch or ACTION_UP can clear jump/attack before the native loop observes them.
