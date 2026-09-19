"""Extract the 25 external mus_*.ogg music files from the original APK into
assets/music/ and write a SHA-256 manifest. Original music files live outside
game.droid (GMS Android packaging: SFX embedded, music streamed from APK
assets)."""
import hashlib, json, os, zipfile

APK = "/storage/emulated/0/Download/Cally's+Caves+2_2.1.9_APKPure.apk"
OUT = "assets/music"
os.makedirs(OUT, exist_ok=True)

with zipfile.ZipFile(APK) as z:
    names = [n for n in z.namelist() if n.startswith("assets/mus_") and n.endswith(".ogg")]
    names.sort()
    manifest = {}
    for n in names:
        data = z.read(n)
        base = os.path.basename(n)
        with open(os.path.join(OUT, base), "wb") as f:
            f.write(data)
        manifest[base] = {
            "bytes": len(data),
            "sha256": hashlib.sha256(data).hexdigest(),
        }
    print("extracted:", len(names))

json.dump(manifest, open(os.path.join(OUT, "manifest.json"), "w"), indent=1, sort_keys=True)
total = sum(v["bytes"] for v in manifest.values())
print("total bytes:", total)
for k in sorted(manifest):
    print(f"  {k}: {manifest[k]['bytes']}")
