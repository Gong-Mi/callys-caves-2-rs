// Link the GLES/EGL/NDK libraries for the Android cdylib.
//
// WHY a build script: linking by name on a Termux host picks the Termux Mesa
// libEGL ($PREFIX/lib/libEGL.so, SONAME libEGL.so.1) instead of the device's
// libEGL.so, and the device loader then fails to dlopen the library. Passing
// the NDK sysroot files by absolute path records the device names
// (libEGL.so / libGLESv3.so) - verified in a probe against the NDK r29
// sysroot. Plain -l is the fallback when no NDK is on the machine.

use std::path::{Path, PathBuf};

const LIBS: [&str; 4] = ["EGL", "GLESv3", "android", "log"];
const API: &str = "26";

fn ndk_lib_dir() -> Option<PathBuf> {
    let mut roots: Vec<PathBuf> = Vec::new();
    for key in ["ANDROID_NDK_HOME", "ANDROID_NDK_ROOT"] {
        if let Ok(value) = std::env::var(key) {
            root_from_ndk(Path::new(&value), &mut roots);
        }
    }
    for key in ["ANDROID_SDK_ROOT", "ANDROID_SDK", "ANDROID_HOME"] {
        if let Ok(value) = std::env::var(key) {
            collect_sdk_ndks(Path::new(&value), &mut roots);
        }
    }
    if let Ok(home) = std::env::var("HOME") {
        collect_sdk_ndks(&Path::new(&home).join("android-sdk"), &mut roots);
    }
    roots.into_iter().find(|dir| dir.is_dir())
}

fn root_from_ndk(ndk: &Path, out: &mut Vec<PathBuf>) {
    if let Some(dir) = sysroot_lib(ndk) {
        out.push(dir);
    }
}

fn collect_sdk_ndks(sdk: &Path, out: &mut Vec<PathBuf>) {
    let ndk_root = sdk.join("ndk");
    let Ok(entries) = std::fs::read_dir(&ndk_root) else { return };
    let mut versions: Vec<PathBuf> = entries
        .filter_map(|e| e.ok().map(|e| e.path()))
        .filter(|p| p.is_dir())
        .collect();
    versions.sort();
    for ndk in versions.into_iter().rev() {
        if let Some(dir) = sysroot_lib(&ndk) {
            out.push(dir);
        }
    }
}

fn sysroot_lib(ndk: &Path) -> Option<PathBuf> {
    let prebuilt = ndk.join("toolchains/llvm/prebuilt");
    let host = std::fs::read_dir(&prebuilt).ok()?.filter_map(|e| e.ok()).next()?;
    let dir = host
        .path()
        .join("sysroot/usr/lib/aarch64-linux-android")
        .join(API);
    dir.is_dir().then_some(dir)
}

fn main() {
    println!("cargo:rerun-if-env-changed=ANDROID_NDK_HOME");
    println!("cargo:rerun-if-env-changed=ANDROID_NDK_ROOT");
    println!("cargo:rerun-if-env-changed=ANDROID_SDK_ROOT");
    if std::env::var("CARGO_CFG_TARGET_OS").as_deref() != Ok("android") {
        return;
    }
    let lib_dir = ndk_lib_dir();
    for lib in LIBS {
        match &lib_dir {
            Some(dir) if dir.join(format!("lib{lib}.so")).exists() => {
                println!("cargo:rustc-link-arg={}", dir.join(format!("lib{lib}.so")).display());
            }
            _ => println!("cargo:rustc-link-lib={lib}"),
        }
    }
}
