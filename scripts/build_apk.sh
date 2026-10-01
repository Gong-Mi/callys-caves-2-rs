#!/bin/bash
set -euo pipefail

# Build a self-contained ARM64 APK that bundles:
#   - classes.dex (MainActivity + JNI glue)
#   - lib/arm64-v8a/libcallys_client.so (the Rust engine)
#   - assets/* (textures + audio + JSON metadata)

ROOT="${CALLY_ROOT:-$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)}"
BUILD="$ROOT/android-build"
SDK="${ANDROID_SDK:-/data/data/com.termux/files/home/android-sdk}"
PLATFORM_API=36
ANDROID_JAR="$SDK/platforms/android-$PLATFORM_API/android.jar"
D8_JAR="$SDK/cmdline-tools/latest/lib/r8.jar"
D8_BIN="$(command -v d8 || true)"
JAVA=java
KEYSTORE="${CALLY_KEYSTORE:-${HOME}/.config/callyscaves2/debug.keystore}"
KEY_PASS="${CALLY_KEYPASS:-android}"

cd "$ROOT"
cargo build --release -p callys-client --features android

if [ ! -f "$KEYSTORE" ]; then
    echo "ERROR: fixed signing keystore is missing: $KEYSTORE" >&2
    echo "Create/provision it explicitly or set CALLY_KEYSTORE; refusing to generate a new signing identity." >&2
    exit 1
fi

cd "$BUILD"
rm -rf classes.dex base.apk aligned.apk unsigned.apk CallysCaves2_64bit_Rust.apk
rm -rf compiled classes classes.dex
mkdir -p compiled

# 1. compile resources
aapt2 compile --dir res -o compiled/res.flat.zip

# 2. link resources into base.apk
aapt2 link \
    -I "$ANDROID_JAR" \
    --manifest AndroidManifest.xml \
    -o base.apk \
    compiled/res.flat.zip

# 3. compile Java -> class
mkdir -p classes
javac --release 17 -cp "$ANDROID_JAR" -d classes \
    src/com/gongmi/callyscaves2/MainActivity.java src/com/gongmi/callyscaves2/PointerReleaseQueue.java

# 4. d8 -> classes.dex
if [ -n "$D8_BIN" ]; then
    "$D8_BIN" \
        --lib "$ANDROID_JAR" --release --output . \
        --min-api 24 \
        $(find classes -name "*.class")
elif [ -f "$D8_JAR" ]; then
    java -Xmx2G -cp "$D8_JAR" com.android.tools.r8.D8 \
        --lib "$ANDROID_JAR" --release --output . \
        --min-api 24 \
        $(find classes -name "*.class")
else
    echo "ERROR: neither d8 executable nor $D8_JAR exists" >&2
    exit 1
fi

# 4b. strip the Termux RUNPATH out of libcallys_client.so so the
# Android dynamic linker can find libdl/liblog/libc without needing
# the Termux sysroot at runtime. The cdylib produced by `cargo
# build --release` on Termux embeds RUNPATH=/data/data/com.termux/
# files/usr/lib which doesn't exist on real Android devices, so
# System.loadLibrary("callys_client") would dlopen-fail silently.
SO_SRC="$ROOT/target/release/libcallys_client.so"
if [ -f "$SO_SRC" ]; then
    patchelf --remove-rpath "$SO_SRC"
fi
if llvm-readelf -d "$SO_SRC" | grep -q RUNPATH; then
    echo "ERROR: Termux RUNPATH remains in $SO_SRC" >&2
    exit 1
fi

# 5. inject dex + native lib + assets into base.apk
export BUILD ROOT
python3 - <<'PY'
import zipfile, os

root = os.environ.get("ROOT", "/data/data/com.termux/files/usr/tmp/cally-code-reverse")
build = os.environ.get("BUILD", os.path.join(root, "android-build"))
apk = os.path.join(build, "base.apk")
target_so = os.path.join(root, "target/release/libcallys_client.so")
asset_root = os.path.join(root, "assets")

with zipfile.ZipFile(apk, "a") as z:
    z.write(os.path.join(build, "classes.dex"), "classes.dex")
    z.write(target_so, "lib/arm64-v8a/libcallys_client.so")
    full_ir = os.path.join(root, "crates/core/src/generated/full_ir.json")
    if os.path.exists(full_ir):
        # The 53MB IR JSON is highly compressible plain text; ZIP_STORED
        # (zipfile's default) shipped it raw and tripled the APK. Deflate it:
        # ~53MB -> ~10MB with no runtime cost beyond transparent unzip.
        with open(full_ir, "rb") as f:
            data = f.read()
        info = zipfile.ZipInfo("assets/full_ir.json", date_time=(2026, 1, 1, 0, 0, 0))
        info.compress_type = zipfile.ZIP_DEFLATED
        info.external_attr = 0o644 << 16
        z.writestr(info, data, compress_type=zipfile.ZIP_DEFLATED, compresslevel=9)
    for r, _, files in os.walk(asset_root):
        for f in files:
            full = os.path.join(r, f)
            rel = os.path.relpath(full, asset_root)
            # ogg/png/wav are already-compressed media: storing them avoids
            # pointless deflate time at zero size cost. Everything textual
            # gets deflated.
            ext = os.path.splitext(f)[1].lower()
            compress = zipfile.ZIP_DEFLATED if ext in (".json", ".txt", ".xml", ".wav", ".droid") else zipfile.ZIP_STORED
            info = zipfile.ZipInfo(f"assets/{rel}", date_time=(2026, 1, 1, 0, 0, 0))
            info.compress_type = compress
            info.external_attr = 0o644 << 16
            with open(full, "rb") as fh:
                z.writestr(info, fh.read(), compress_type=compress)
print("Injected dex, libcallys_client.so, and assets into base.apk")
PY

# 6. zipalign
zipalign -p -f 4 base.apk aligned.apk

# 7. sign
apksigner sign --ks "$KEYSTORE" --ks-pass "pass:$KEY_PASS" aligned.apk

# 8. verify
apksigner verify --verbose aligned.apk

# 9. copy
cp aligned.apk CallysCaves2_64bit_Rust.apk
ls -lh CallysCaves2_64bit_Rust.apk
