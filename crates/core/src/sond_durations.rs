//! Real playback length of every SOND entry, in seconds.
//!
//! GENERATED — do not hand-edit. Source of truth is
//! `reconstruction/contracts/audio-durations.json` (54/54 rows: the 29 embedded
//! `snd_*` WAVs measured from the `game.droid` AUDO chunk, the 25 streamed
//! `mus_*` OGGs measured from the APK's `assets/mus_*.ogg` granule/rate).
//! Regenerate with:
//!
//! ```text
//! jq -r '.[] | "    (\(.sond_id), \(.seconds)), // \(.name) (\(.source))"' \
//!     reconstruction/contracts/audio-durations.json
//! ```
//!
//! Why the engine needs it: the original runner reports `audio_is_playing(snd)`
//! as true for the sound's whole length. The asset carries no duration field —
//! the SOND record is name/flags/type/file/volume only — so the length has to
//! travel with the engine, exactly like the original runner's own audio device
//! knows the stream length. Without it the audio voice ledger can only retire a
//! non-looping voice on drain, which collapses every `audio_is_playing`
//! anti-stack gate (86 sites, incl. obj_music's 24-deep BGM chain) into
//! "nothing is ever playing".

use std::collections::BTreeMap;

/// (sond id, seconds), in SOND order.
pub const SOND_DURATION_SECS: [(i32, f64); 54] = [
    (0, 200.0), // bee (wav)
    (1, 0.191), // flamethrower (wav)
    (2, 1.084), // bombgun (wav)
    (3, 0.606), // jump (wav)
    (4, 4.0), // meetnewenemy (wav)
    (5, 0.815), // weaponswap (wav)
    (6, 1.0), // crescentwave (wav)
    (7, 1.3), // explode (wav)
    (8, 1.3), // explode2 (wav)
    (9, 0.556), // assaultrifle (wav)
    (10, 1.038), // fire (wav)
    (11, 0.864), // shotgun (wav)
    (12, 3.472), // rocket (wav)
    (13, 0.75), // sword (wav)
    (14, 0.75), // sword2 (wav)
    (15, 0.652), // laser (wav)
    (16, 0.528), // bow (wav)
    (17, 0.8), // blade (wav)
    (18, 0.597), // ice (wav)
    (19, 0.5), // coin (wav)
    (20, 0.5), // coin3 (wav)
    (21, 0.75), // enemyhit (wav)
    (22, 0.75), // impactsound1 (wav)
    (23, 0.75), // impactsound2 (wav)
    (24, 0.75), // impactsound5 (wav)
    (25, 1.709), // levelup (wav)
    (26, 2.981), // youhavedied (wav)
    (27, 4.39), // pickupstinger (wav)
    (28, 4.186), // weaponlevelup (wav)
    (29, 200.046), // egc (ogg)
    (30, 85.176), // sneaksbeat (ogg)
    (31, 43.624), // new4 (ogg)
    (32, 158.015), // townmusic (ogg)
    (33, 98.273), // searching (ogg)
    (34, 186.175), // supertrip (ogg)
    (35, 196.075), // cally2fez (ogg)
    (36, 296.064), // atmospheric (ogg)
    (37, 188.761), // acoustic (ogg)
    (38, 151.85), // amdm7 (ogg)
    (39, 138.762), // arpdisast (ogg)
    (40, 70.348), // happy (ogg)
    (41, 117.708), // sunrise (ogg)
    (42, 103.262), // mariokart (ogg)
    (43, 31.164), // menumusic (ogg)
    (44, 125.597), // newprogression (ogg)
    (45, 63.36), // soundwall (ogg)
    (46, 115.252), // strongtech (ogg)
    (47, 131.814), // synthonic (ogg)
    (48, 92.238), // techno (ogg)
    (49, 65.489), // technoending (ogg)
    (50, 25.164), // bosssongending (ogg)
    (51, 65.088), // bosssong (ogg)
    (52, 141.218), // blooddragon (ogg)
    (53, 132.552), // cally3 (ogg)
];

/// The `Scene::sound_durations` baseline: sond id -> seconds.
pub fn table() -> BTreeMap<i32, f64> {
    SOND_DURATION_SECS.iter().copied().collect()
}
