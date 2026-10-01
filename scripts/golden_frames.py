#!/usr/bin/env python3
"""Record / verify original-side golden frames captured on a real device.

The CI emulator stack cannot host the original yoyo runner at all (see runs
36652899080 / 36654952404 / 36655808019: the guest wedges at app startup with
no kernel, OOM, tombstone or GPU-backend signal). The original's visual
reference therefore comes from ONE real-device capture session, frozen here as
content-addressed goldens; CI compares the remake against these files instead
of ever running the original again.

Workflow (device side, needs the original APK installed):
    adb -s <device> exec-out screencap -p > golden/01_boot.png   # etc.
Write the manifest next to the shots:
    python3 scripts/golden_frames.py record golden/manifest.json
Verify integrity at any time (CI or locally):
    python3 scripts/golden_frames.py verify golden/manifest.json

Manifest entries pin: file name, sha256, byte length, and the device frame
the shot corresponds to. Remake-side comparison stays structural (queue
digests + the registered render-consumption boundaries); this tool only
guarantees the ORIGINAL reference cannot silently drift or rot.
"""
import hashlib
import json
import sys
from pathlib import Path

REQUIRED_KEYS = ("file", "sha256", "bytes", "scene")


def digest(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def record(manifest_path: Path):
    root = manifest_path.parent
    shots = sorted(p for p in root.iterdir() if p.suffix == ".png")
    if not shots:
        sys.exit(f"no PNG captures under {root}; run the adb screencap pass first")
    entries = []
    for p in shots:
        entries.append({
            "file": p.name,
            "sha256": digest(p),
            "bytes": p.stat().st_size,
            "scene": Path(p.stem).name,  # naming convention: <nn>_<scene>.png
        })
    manifest_path.write_text(json.dumps({"frames": entries}, indent=2) + "\n")
    print(f"recorded {len(entries)} golden frames -> {manifest_path}")


def verify(manifest_path: Path) -> int:
    root = manifest_path.parent
    data = json.loads(manifest_path.read_text())
    bad = 0
    for e in data["frames"]:
        missing = [k for k in REQUIRED_KEYS if k not in e]
        if missing:
            print(f"MANIFEST INCOMPLETE {e.get('file','?')}: missing {missing}")
            bad += 1
            continue
        p = root / e["file"]
        if not p.is_file():
            print(f"GOLDEN MISSING {p}")
            bad += 1
            continue
        if digest(p) != e["sha256"]:
            print(f"GOLDEN DRIFTED {p} (sha256 mismatch)")
            bad += 1
    print(f"{len(data['frames'])} entries, {bad} problems")
    return 1 if bad else 0


if __name__ == "__main__":
    if len(sys.argv) != 3 or sys.argv[1] not in ("record", "verify"):
        sys.exit(__doc__)
    path = Path(sys.argv[2])
    sys.exit(record(path) if sys.argv[1] == "record" else verify(path))
