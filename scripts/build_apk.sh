#!/bin/bash
set -e

# Build a self-contained ARM64 APK that bundles:
#   - classes.dex (MainActivity + JNI glue)
#   - lib/arm64-v8a/libcallys_client.so (the Rust engine)
#   - assets/* (textures + audio + JSON metadata)

ROOT="/data/data/com.termux/files/home/callys-caves-2-rs"
BUILD="$ROOT/android-build"
SDK="${ANDROID_SDK:-/data/data/com.termux/files/home/android-sdk}"
PLATFORM_API=36
ANDROID_JAR="$SDK/platforms/android-$PLATFORM_API/android.jar"
D8_JAR="$SDK/cmdline-tools/latest/lib/r8.jar"
JAVA=java
KEYSTORE="${HOME}/.android/debug.keystore"
KEY_PASS="android"

if [ ! -f "$KEYSTORE" ]; then
    mkdir -p "$(dirname "$KEYSTORE")"
    keytool -genkey -v -keystore "$KEYSTORE" \
        -alias androiddebugkey -storepass "$KEY_PASS" \
        -keypass "$KEY_PASS" -keyalg RSA -keysize 2048 \
        -validity 10000 \
        -dname "CN=Android Debug,O=Android,C=US" 2>&1 | tail -2
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
    src/com/gongmi/callyscaves2/MainActivity.java

# 4. d8 -> classes.dex
java -Xmx2G -cp "$D8_JAR" com.android.tools.r8.D8 \
    --lib "$ANDROID_JAR" --release --output . \
    --min-api 24 \
    $(find classes -name "*.class")

# 4b. strip the Termux RUNPATH out of libcallys_client.so so the
# Android dynamic linker can find libdl/liblog/libc without needing
# the Termux sysroot at runtime. The cdylib produced by `cargo
# build --release` on Termux embeds RUNPATH=/data/data/com.termux/
# files/usr/lib which doesn't exist on real Android devices, so
# System.loadLibrary("callys_client") would dlopen-fail silently.
SO_SRC="$ROOT/target/release/libcallys_client.so"
if [ -f "$SO_SRC" ]; then
    patchelf --remove-rpath "$SO_SRC" 2>/dev/null || true
fi

# 5. inject dex + native lib + assets into base.apk
python3 - <<'PY'
import zipfile, os
apk = "/data/data/com.termux/files/home/callys-caves-2-rs/android-build/base.apk"
build = "/data/data/com.termux/files/home/callys-caves-2-rs/android-build"
target_so = "/data/data/com.termux/files/home/callys-caves-2-rs/target/release/libcallys_client.so"
asset_root = "/data/data/com.termux/files/home/callys-caves-2-rs/assets"

with zipfile.ZipFile(apk, "a") as z:
    z.write(os.path.join(build, "classes.dex"), "classes.dex")
    z.write(target_so, "lib/arm64-v8a/libcallys_client.so")
    for root, _, files in os.walk(asset_root):
        for f in files:
            full = os.path.join(root, f)
            rel = os.path.relpath(full, asset_root)
            z.write(full, f"assets/{rel}")
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
