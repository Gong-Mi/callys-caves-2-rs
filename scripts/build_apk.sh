#!/bin/bash
set -euo pipefail

# Build a self-contained ARM64 APK that bundles:
#   - classes.dex (MainActivity + JNI glue)
#   - lib/arm64-v8a/libcallys_client.so (the Rust engine)
#   - assets/* (textures + audio + JSON metadata)
#
# Portable by design: the same script builds
#   (a) on Termux/Android, where the Rust host *is* aarch64-linux-android
#       (no --target needed, uses the Termux clang sysroot; see
#        ~/.cargo/config.toml), and
#   (b) on a Linux CI host, cross-compiling with the Android NDK clang
#       (CALLY_TARGET=aarch64-linux-android + CARGO_TARGET_*_LINKER).
#
# Environment knobs (all optional):
#   CALLY_ROOT        repo root (default: parent of this script)
#   CALLY_BUILD_DIR   output/work dir (default: $ROOT/android-build)
#   ANDROID_SDK_ROOT | ANDROID_SDK | ANDROID_HOME   SDK location
#   ANDROID_NDK_HOME  NDK location (also used to locate clang on CI)
#   CALLY_TARGET      cargo --target triple ('' = host build)
#   CALLY_SO_SRC      explicit path to the built libcallys_client.so
#   CALLY_KEYSTORE    signing keystore (default ~/.config/callyscaves2/debug.keystore)
#   CALLY_KEYPASS     keystore password (default: android)
#   CALLY_GENERATE_CI_KEYSTORE=1
#       create a THROWAWAY keystore when CALLY_KEYSTORE is missing. This is
#       for CI build verification only: the resulting APK can never update a
#       device build (different signing identity). Never use it for a
#       device install; the device key stays out of CI.

ROOT="${CALLY_ROOT:-$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)}"
BUILD="${CALLY_BUILD_DIR:-$ROOT/android-build}"
SDK="${ANDROID_SDK_ROOT:-${ANDROID_SDK:-${ANDROID_HOME:-/data/data/com.termux/files/home/android-sdk}}}"
PLATFORM_API=36
ANDROID_JAR="$SDK/platforms/android-$PLATFORM_API/android.jar"
D8_JAR="$SDK/cmdline-tools/latest/lib/r8.jar"
JAVA=java
KEYSTORE="${CALLY_KEYSTORE:-${HOME}/.config/callyscaves2/debug.keystore}"
KEY_PASS="${CALLY_KEYPASS:-android}"
TARGET="${CALLY_TARGET:-}"

# --- toolchain discovery -----------------------------------------------------
# Prefer whatever is already on PATH (Termux: pkg/android-tools), then fall
# back to the SDK build-tools so a CI host needs no extra PATH wrangling.
if ! command -v aapt2 >/dev/null 2>&1; then
    BT="$(ls -d "$SDK"/build-tools/* 2>/dev/null | sort -V | tail -1 || true)"
    if [ -n "${BT:-}" ]; then
        export PATH="$BT:$PATH"
    fi
fi
for tool in aapt2 zipalign apksigner d8; do
    if ! command -v "$tool" >/dev/null 2>&1; then
        echo "WARNING: '$tool' not found on PATH (SDK=$SDK)" >&2
    fi
done

# On CI ubuntu the LLVM tools are versioned (llvm-readelf-18) or only the GNU
# one is present; both print a DT_RUNPATH line for -d.
READELF="$(command -v llvm-readelf || command -v readelf || true)"
if [ -z "$READELF" ]; then
    echo "ERROR: neither llvm-readelf nor readelf is available" >&2
    exit 1
fi

# The linker must match the target triple; on a non-Android host the default
# cc linker would produce an x86_64 object and the NDK clang is required.
if [ -n "$TARGET" ]; then
    if [ -z "${CARGO_TARGET_AARCH64_LINUX_ANDROID_LINKER:-}" ]; then
        NDK="${ANDROID_NDK_HOME:-}"
        if [ -z "$NDK" ]; then
            NDK="$(ls -d "$SDK"/ndk/* 2>/dev/null | sort -V | tail -1 || true)"
        fi
        if [ -x "$NDK/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android24-clang" ]; then
            export CARGO_TARGET_AARCH64_LINUX_ANDROID_LINKER="$NDK/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android24-clang"
        else
            echo "ERROR: no NDK clang for aarch64-linux-android (NDK='$NDK'); set ANDROID_NDK_HOME or CARGO_TARGET_AARCH64_LINUX_ANDROID_LINKER" >&2
            exit 1
        fi
    fi
fi

cd "$ROOT"
# shellcheck disable=SC2086
cargo build --release -p callys-client --features android ${TARGET:+--target "$TARGET"}

SO_SRC="${CALLY_SO_SRC:-$ROOT/target/${TARGET:+$TARGET/}release/libcallys_client.so}"
if [ ! -f "$SO_SRC" ]; then
    echo "ERROR: built cdylib not found: $SO_SRC" >&2
    exit 1
fi

if [ ! -f "$KEYSTORE" ]; then
    if [ "${CALLY_GENERATE_CI_KEYSTORE:-0}" = "1" ]; then
        echo "NOTICE: generating a THROWAWAY CI signing identity at $KEYSTORE" >&2
        echo "NOTICE: CI-built APKs are verification artifacts; device installs use the local key." >&2
        mkdir -p "$(dirname "$KEYSTORE")"
        keytool -genkeypair -keystore "$KEYSTORE" -storepass "$KEY_PASS" \
            -keypass "$KEY_PASS" -alias androiddebugkey -keyalg RSA -keysize 2048 \
            -validity 10000 -dname "CN=CI Verification Only, O=callys-caves-2-rs CI, C=US" \
            >/dev/null 2>&1
    else
        echo "ERROR: fixed signing keystore is missing: $KEYSTORE" >&2
        echo "Create/provision it explicitly or set CALLY_KEYSTORE; refusing to generate a new signing identity." >&2
        exit 1
    fi
fi

mkdir -p "$BUILD"
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
# Every source under src/ goes into the dex: a hardcoded list silently drops a
# newly added host class (InputViewport.java was exactly that).
mkdir -p classes
mapfile -t JAVA_SOURCES < <(find src -name '*.java' | sort)
if [ ${#JAVA_SOURCES[@]} -eq 0 ]; then
    echo "ERROR: no Java sources under $BUILD/src" >&2
    exit 1
fi
javac --release 17 -cp "$ANDROID_JAR" -d classes "${JAVA_SOURCES[@]}"

# 4. d8 -> classes.dex
D8_BIN="$(command -v d8 || true)"
run_d8() {
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
}

run_d8
# A d8 that exits 0 without writing a dex silently produces a broken APK
# further down (the injector cannot open classes.dex). Retry through r8.jar
# when the PATH d8 is a no-op, then fail loudly if there is still no dex.
if [ ! -s classes.dex ] && [ -n "$D8_BIN" ] && [ -f "$D8_JAR" ]; then
    echo "WARNING: '$D8_BIN' produced no classes.dex; retrying with $D8_JAR" >&2
    rm -f classes.dex
    java -Xmx2G -cp "$D8_JAR" com.android.tools.r8.D8 \
        --lib "$ANDROID_JAR" --release --output . \
        --min-api 24 \
        $(find classes -name "*.class")
fi
if [ ! -s classes.dex ]; then
    echo "ERROR: d8 produced no classes.dex (d8='${D8_BIN:-none}', r8.jar='$D8_JAR')" >&2
    exit 1
fi

# 4b. strip any RUNPATH out of libcallys_client.so so the Android dynamic
# linker does not need a host sysroot at runtime. A Termux host build embeds
# RUNPATH=/data/data/com.termux/files/usr/lib; that path does not exist on a
# real device, so System.loadLibrary("callys_client") would dlopen-fail
# silently. An NDK cross build has no such RUNPATH and this is a no-op.
if "$READELF" -d "$SO_SRC" 2>/dev/null | grep -q RUNPATH; then
    if command -v patchelf >/dev/null 2>&1; then
        patchelf --remove-rpath "$SO_SRC"
    else
        echo "ERROR: $SO_SRC carries a RUNPATH and patchelf is not installed" >&2
        exit 1
    fi
fi
if "$READELF" -d "$SO_SRC" | grep -q RUNPATH; then
    echo "ERROR: RUNPATH remains in $SO_SRC" >&2
    exit 1
fi

# 5. inject dex + native lib + assets into base.apk
export BUILD ROOT SO_SRC
python3 - <<'PY'
import zipfile, os

root = os.environ.get("ROOT", "/data/data/com.termux/files/usr/tmp/cally-code-reverse")
build = os.environ.get("BUILD", os.path.join(root, "android-build"))
apk = os.path.join(build, "base.apk")
target_so = os.environ["SO_SRC"]
asset_root = os.path.join(root, "assets")

with zipfile.ZipFile(apk, "a") as z:
    # Shared libraries must stay STORED (uncompressed) so zipalign can place
    # them on the page boundary the loader needs on 16 KB-page devices.
    with open(os.path.join(build, "classes.dex"), "rb") as fh:
        z.writestr(zipfile.ZipInfo("classes.dex", date_time=(2026, 1, 1, 0, 0, 0)), fh.read(),
                   compress_type=zipfile.ZIP_STORED)
    with open(target_so, "rb") as fh:
        z.writestr(zipfile.ZipInfo("lib/arm64-v8a/libcallys_client.so", date_time=(2026, 1, 1, 0, 0, 0)), fh.read(),
                   compress_type=zipfile.ZIP_STORED)
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

# 6. zipalign. -P 16 page-aligns uncompressed shared libraries for 16 KB-page
# devices (Android 15+ requirement); -f 4 keeps the 4-byte resource alignment.
zipalign -P 16 -f 4 base.apk aligned.apk

# 7. sign
apksigner sign --ks "$KEYSTORE" --ks-pass "pass:$KEY_PASS" aligned.apk

# 8. verify
apksigner verify --verbose aligned.apk

# 9. copy
cp aligned.apk CallysCaves2_64bit_Rust.apk
ls -lh CallysCaves2_64bit_Rust.apk
