"""Verify the Android host's audio constants against reconstruction/contracts/
audio-sond.json — the Java side keeps the platform contract (file names,
volumes) in one place; this check stops the two from drifting.

Fails when: MUSIC_NAMES/VOLUMES mismatch the SOND table, SFX_VOLUMES cover
REQUIRED_AUDIO_IDS with wrong volumes, or the music id base is wrong.
Run locally any time; wired into the reverse-code workflow."""
import json, re, sys

JAVA = "android-build/src/com/gongmi/callyscaves2/MainActivity.java"
rows = json.load(open("reconstruction/contracts/audio-sond.json"))
src = open(JAVA).read()

music = [r for r in rows if r["ext"].endswith(".ogg")]
assert len(music) == 25, len(music)
first_id = music[0]["sond_id"]
assert [r["sond_id"] for r in music] == list(range(first_id, first_id + 25)), \
    "music SOND ids must be contiguous"

errors = []

m = re.search(r"MUSIC_ID_BASE = (\d+)", src)
if not m or int(m.group(1)) != first_id:
    errors.append(f"MUSIC_ID_BASE must be {first_id}")

def read_array(name):
    m = re.search(r"\b" + name + r"\s*=\s*\{(.*?)\};", src, re.S)
    if not m:
        return None
    return [s.strip().strip('"') for s in m.group(1).replace("\n", " ").split(",") if s.strip()]

names = read_array("MUSIC_NAMES")
vols = read_array("MUSIC_VOLUMES")
if names is None:
    errors.append("MUSIC_NAMES missing")
else:
    want = ["mus_" + r["name"] + ".ogg" for r in music]
    if names != want:
        errors.append(f"MUSIC_NAMES drift: got {len(names)} entries, want {want[:3]}...")
if vols is None:
    errors.append("MUSIC_VOLUMES missing")
else:
    want = [str(r["volume"]) for r in music]
    got = [str(float(v.rstrip("fF"))) for v in vols]
    if got != want:
        errors.append(f"MUSIC_VOLUMES drift: {got[:6]}... want {want[:6]}...")

m = re.search(r"REQUIRED_AUDIO_IDS = \{([^}]*)\}", src)
if not m:
    errors.append("REQUIRED_AUDIO_IDS missing")
else:
    sfx_ids = [int(x.strip()) for x in m.group(1).split(",") if x.strip()]
    for sid in sfx_ids:
        vm = re.search(r"SFX_VOLUMES.put\(" + str(sid) + r",\s*([0-9.]+)f?\)", src)
        if not vm:
            errors.append(f"SFX_VOLUMES missing entry for id {sid}")
            continue
        want_vol = next(r["volume"] for r in rows if r["sond_id"] == sid)
        if abs(float(vm.group(1).rstrip("fF")) - want_vol) > 1e-4:
            errors.append(f"SFX volume for id {sid}: java {vm.group(1)} != sond {want_vol}")

if errors:
    print("AUDIO CONTRACT DRIFT:")
    for e in errors:
        print(" -", e)
    sys.exit(1)
print("audio contract verified: MUSIC_NAMES 25, MUSIC_VOLUMES 25, SFX_VOLUMES", len(sfx_ids))
