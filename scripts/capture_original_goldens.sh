#!/usr/bin/env bash
# One real-device capture session for the ORIGINAL Cally's Caves 2.
#
# WHY THIS EXISTS: no CI emulator configuration can host the original yoyo
# runner (exclusion runs 36652899080 / 36654952404 / 36655808019: the guest
# wedges at app startup with no kernel/OOM/tombstone/GPU signal). The golden
# original frames must therefore be captured ONCE on a real device and frozen
# into reconstruction/golden-frames/ (see scripts/golden_frames.py).
#
# This script is intentionally NOT run by CI and NOT run by default: it
# installs the original APK and injects input into a foreground app, which
# requires explicit user authorization on the device it runs against.
#
# Usage (on a Termux host with the original installed, or via adb):
#   DEVICE=<serial> bash scripts/capture_original_goldens.sh <out_dir>
# Then:
#   python3 scripts/golden_frames.py record <out_dir>/manifest.json
#   git add <out_dir> && commit   # goldens become content-addressed CI input
set -euo pipefail

OUT=${1:?usage: capture_original_goldens.sh <out_dir>}
ADB=(adb)
[ -n "${DEVICE:-}" ] && ADB+=("-s" "$DEVICE")

APK_URL="https://github.com/Gong-Mi/callys-caves-2-rs/releases/download/original-apk-v1/callys_original.apk"
APK_SHA="d608f4557ad66326de36268b9ab062afec839344e57d85afb6220405ea8cd8c9"
PKG=com.vdogames.callyscaves2
ACT="$PKG/com.yoyogames.runner.MainActivity"   # runner standard component

mkdir -p "$OUT"

# --- 1. install (verify the pinned hash first; never run an unverified APK) ---
if [ ! -f "$OUT/callys_original.apk" ]; then
  curl -L --retry 3 -o "$OUT/callys_original.apk" "$APK_URL"
fi
echo "$APK_SHA  $OUT/callys_original.apk" | sha256sum -c -
"${ADB[@]}" install -r "$OUT/callys_original.apk"
"${ADB[@]}" shell pm list packages | grep -q "$PKG"

# --- 2. capture helpers -------------------------------------------------------
cap() { # cap <name> ; screencap -> PNG -> pull
  "${ADB[@]}" shell screencap -p "/storage/emulated/0/$1.png"
  "${ADB[@]}" pull "/storage/emulated/0/$1.png" "$OUT/$1.png" >/dev/null
  "${ADB[@]}" shell rm "/storage/emulated/0/$1.png"
  echo "captured $1 ($(sha256sum "$OUT/$1.png" | cut -c1-16))"
}
tap() { "${ADB[@]}" shell input tap "$1" "$2"; }
sleep4() { sleep 4; }

# --- 3. the scripted session (scene names double as manifest scene keys) ----
"${ADB[@]}" shell am force-stop "$PKG"
"${ADB[@]}" shell am start -n "$ACT" >/dev/null
sleep4; cap 01_boot            # sea/cliff backdrop + scrolling poster
sleep4; cap 02_poster_scroll   # mid-prologue frame band check
tap 1170 540                   # mb_left anywhere: page advance / tap-lock
sleep4; cap 03_town_entry      # rm_town under the ORIGINAL view-6 zoom
sleep4; cap 04_town_walk       # (pre: adb shell input swipe for a walk; manual)
# Lloyd sheet: stand next to Lloyd first (manual positioning or door warp is
# device-state dependent); the sheet is the freeze frame worth freezing:
tap 1170 540; sleep4; cap 05_lloyd_sheet
tap 1170 540; sleep4; cap 06_level1_spawn   # door-to-caves landing
"${ADB[@]}" shell am force-stop "$PKG"

echo
echo "Now: python3 scripts/golden_frames.py record $OUT/manifest.json"
echo "and move selected shots into reconstruction/golden-frames/ for CI."
echo "NOTE: taps above use the 960x540-logical layout of the remake rig; on"
echo "the original the same gameRect scaling applies (MainActivity parity lab"
echo "derivation), but VERIFY each frame visually before freezing the manifest"
echo "— goldens that captured a wrong moment are worse than no goldens."
