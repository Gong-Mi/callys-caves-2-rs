#!/usr/bin/env python3
"""Verify a built Cally's Caves 2 APK without an Android device.

Checks, in order (each printed as PASS/FAIL so a RED run names the broken
invariant):

  1. packaging    - the APK carries AndroidManifest.xml, classes.dex,
                    resources.arsc, the arm64 cdylib and the engine assets.
  2. elf          - libcallys_client.so is ELF64/aarch64, has no DT_RPATH /
                    DT_RUNPATH and needs no host sysroot (no /com.termux/
                    dependency), so the device linker can load it.
  3. 16kb pages   - every PT_LOAD is 16 KB aligned, and the stored (not
                    compressed) .so entry is 16 KB aligned inside the zip.
  4. dex classes  - every host class under android-build/src is in classes.dex
                    (a class missing from the dex is a missing JNI host).
  5. signature    - apksigner verify, when apksigner is on PATH (skipped, not
                    silently passed, when it is not).

Usage: python3 scripts/verify_apk.py <apk> [--expect-signer-sha256 HEX]
"""
from __future__ import annotations

import glob
import hashlib
import os
import shutil
import struct
import subprocess
import sys
import zipfile

REQUIRED_ENTRIES = [
    "AndroidManifest.xml",
    "classes.dex",
    "resources.arsc",
    "lib/arm64-v8a/libcallys_client.so",
    "assets/game.droid",
    "assets/full_ir.json",
    "assets/textures/texture_0.png",
]
# Expected dex contents are derived from the host sources so a newly added
# class cannot be left out of the dex without the verifier noticing.
LEGACY_DEX_CLASSES = [
    "com/gongmi/callyscaves2/MainActivity",
    "com/gongmi/callyscaves2/GlesPresenter",
    "com/gongmi/callyscaves2/PointerReleaseQueue",
]
DEFAULT_SOURCE_ROOT = os.path.join(
    os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "android-build", "src"
)


def dex_class_names(source_root: str) -> list[str]:
    """Class descriptors (com/gongmi/... form) for every .java under source_root."""
    names = []
    for directory, _, files in os.walk(source_root):
        for f in files:
            if f.endswith(".java"):
                rel = os.path.relpath(os.path.join(directory, f), source_root)
                names.append(os.path.splitext(rel)[0].replace(os.sep, "/"))
    return sorted(names)
SO_ENTRY = "lib/arm64-v8a/libcallys_client.so"
PAGE_16K = 0x4000
EM_AARCH64 = 183

results: list[tuple[str, bool, str]] = []


def check(name: str, ok: bool, detail: str = "") -> None:
    results.append((name, ok, detail))
    print(f"[{'PASS' if ok else 'FAIL'}] {name}{(' - ' + detail) if detail else ''}")


def elf64_load_segments(data: bytes):
    """Return (machine, [(p_offset, p_align), ...], dynamic_section_or_None)."""
    if data[:4] != b"\x7fELF" or data[4] != 2 or data[5] != 1:
        raise ValueError("not a little-endian ELF64 file")
    e_machine = struct.unpack_from("<H", data, 0x12)[0]
    e_phoff = struct.unpack_from("<Q", data, 0x20)[0]
    e_phentsize = struct.unpack_from("<H", data, 0x36)[0]
    e_phnum = struct.unpack_from("<H", data, 0x38)[0]
    loads, dynamic = [], None
    for i in range(e_phnum):
        off = e_phoff + i * e_phentsize
        p_type = struct.unpack_from("<I", data, off)[0]
        if p_type == 1:  # PT_LOAD
            p_offset = struct.unpack_from("<Q", data, off + 0x08)[0]
            p_vaddr = struct.unpack_from("<Q", data, off + 0x10)[0]
            p_filesz = struct.unpack_from("<Q", data, off + 0x20)[0]
            p_align = struct.unpack_from("<Q", data, off + 0x30)[0]
            if p_filesz:
                loads.append((p_offset, p_vaddr, p_align))
        elif p_type == 2:  # PT_DYNAMIC
            dynamic = (
                struct.unpack_from("<Q", data, off + 0x08)[0],
                struct.unpack_from("<Q", data, off + 0x20)[0],
            )
    return e_machine, loads, dynamic


def dynamic_entries(data: bytes, dynamic):
    """Yield (d_tag, d_val) pairs from the DT_NEEDED/DT_RPATH/DT_RUNPATH space."""
    if dynamic is None:
        return
    off, size = dynamic
    for i in range(size // 16):
        yield struct.unpack_from("<qQ", data, off + i * 16)


def binary_xml_strings(data: bytes) -> list[str]:
    """Decode the string pool of an Android binary XML (AXML) document.

    The file starts with a RES_XML_TYPE header (0x0003, 8 bytes); the first
    chunk after it is the RES_STRING_POOL_TYPE pool (0x0001). Strings are
    UTF-8 or UTF-16LE depending on the UTF8_FLAG (0x100) in the pool header.
    Reading the pool beats substring-scanning the file: the package name
    lives in UTF-16 here, so an ASCII byte scan never sees it.
    """
    if len(data) < 16:
        raise ValueError("truncated AXML")
    chunk_type, _header_size, _chunk_size = struct.unpack_from("<HHI", data, 0)
    if chunk_type != 0x0003:
        raise ValueError(f"expected XML chunk, got 0x{chunk_type:04x}")
    pos = 8
    while pos + 8 <= len(data):
        ctype, _hsize, csize = struct.unpack_from("<HHI", data, pos)
        if ctype == 0x0001:
            break
        if csize == 0:
            raise ValueError("zero-sized chunk before the string pool")
        pos += csize
    else:
        raise ValueError("no string pool chunk found")
    chunk = data[pos : pos + csize]
    string_count, _style_count, flags, strings_start = struct.unpack_from("<IIII", chunk, 8)
    utf8 = bool(flags & 0x100)
    offsets = struct.unpack_from(f"<{string_count}I", chunk, 28)
    out = []
    for off in offsets:
        at = strings_start + off
        if utf8:
            # u8 utf16 length, u8 byte length, bytes, NUL
            _chars, blen = chunk[at], chunk[at + 1]
            start = at + 2
            out.append(chunk[start : start + blen].decode("utf-8", "replace"))
        else:
            (chars,) = struct.unpack_from("<H", chunk, at)
            start = at + 2
            out.append(chunk[start : start + chars * 2].decode("utf-16-le", "replace"))
    return out


def sdk_tool(name: str) -> str | None:
    """Locate a build-tools binary from the Android SDK when PATH lacks it.

    CI verifies the APK in a different step than the build, so the SDK
    build-tools directory is not on PATH there; resolving it here keeps the
    signature check live instead of silently skipped.
    """
    sdk = (
        os.environ.get("ANDROID_SDK_ROOT")
        or os.environ.get("ANDROID_SDK")
        or os.environ.get("ANDROID_HOME")
        or "/data/data/com.termux/files/home/android-sdk"
    )
    for build_tools in sorted(
        glob.glob(os.path.join(sdk, "build-tools", "*")),
        key=lambda p: [int(x) if x.isdigit() else x for x in os.path.basename(p).split(".")],
    )[::-1]:
        candidate = os.path.join(build_tools, name)
        if os.path.isfile(candidate) and os.access(candidate, os.X_OK):
            return candidate
    return None


def main() -> int:
    argv = [a for a in sys.argv[1:] if not a.startswith("--")]
    if not argv:
        print(__doc__)
        return 2
    apk_path = argv[0]
    expect_signer = None
    if "--expect-signer-sha256" in sys.argv:
        expect_signer = sys.argv[sys.argv.index("--expect-signer-sha256") + 1]

    if not os.path.exists(apk_path):
        print(f"FAIL: {apk_path} does not exist")
        return 1
    print(f"APK: {apk_path}")
    print(f"sha256: {hashlib.sha256(open(apk_path, 'rb').read()).hexdigest()}")

    with zipfile.ZipFile(apk_path) as z:
        names = set(z.namelist())
        missing = [e for e in REQUIRED_ENTRIES if e not in names]
        check(
            "packaging: required entries present",
            not missing,
            f"missing {missing}" if missing else f"{len(REQUIRED_ENTRIES)} entries",
        )
        if missing:
            return 1

        so = z.read(SO_ENTRY)
        info = z.getinfo(SO_ENTRY)
        so_stored = info.compress_type == zipfile.ZIP_STORED
        # Local file header of the entry, to prove the loader-visible offset
        # is page aligned inside the APK.
        with open(apk_path, "rb") as fh:
            fh.seek(info.header_offset)
            header = fh.read(30)
            name_len, extra_len = struct.unpack_from("<HH", header, 26)
            data_off = info.header_offset + 30 + name_len + extra_len

        dex = z.read("classes.dex")
        manifest = z.read("AndroidManifest.xml")

    check("packaging: cdylib is STORED (uncompressed)", so_stored, {0: "ZIP_STORED", 8: "ZIP_DEFLATED"}.get(info.compress_type, str(info.compress_type)))

    try:
        machine, loads, dynamic = elf64_load_segments(so)
        elf_err = None
    except Exception as exc:  # noqa: BLE001 - a corrupt cdylib is a FAIL, not a crash
        machine, loads, dynamic = None, [], None
        elf_err = f"ELF parse: {exc}"
    check("elf: aarch64 shared object", machine == EM_AARCH64, elf_err or f"e_machine={machine}")

    bad_align = [(hex(o), hex(a)) for o, _, a in loads if a < PAGE_16K]
    check(
        "16kb: every PT_LOAD is 16 KB aligned",
        elf_err is None and not bad_align,
        elf_err or (f"offenders {bad_align}" if bad_align else f"{len(loads)} segments"),
    )

    check(
        "16kb: stored .so data offset is 16 KB aligned",
        data_off % PAGE_16K == 0,
        f"data_offset=0x{data_off:x}",
    )

    tags = list(dynamic_entries(so, dynamic))
    rpath = [t for t in tags if t[0] in (15, 29)]  # DT_RPATH / DT_RUNPATH
    check(
        "elf: no DT_RPATH/DT_RUNPATH",
        elf_err is None and not rpath,
        elf_err or (str(rpath) if rpath else ""),
    )

    needed_off = [v for t, v in tags if t == 1]  # DT_NEEDED -> strtab offsets
    strtab_off = next((v for t, v in tags if t == 5), None)  # DT_STRTAB (vaddr)
    host_deps = []
    if strtab_off is not None and needed_off:
        # Translate the strtab vaddr through the PT_LOAD map back to a file
        # offset; if it does not map, skip the read instead of guessing.
        for p_off, p_vaddr, _ in loads:
            if p_vaddr <= strtab_off < p_vaddr + 0x100000:
                base = p_off - p_vaddr
                for v in needed_off:
                    at = base + strtab_off + v
                    if 0 <= at < len(so):
                        end = so.index(b"\x00", at)
                        host_deps.append(so[at:end].decode("utf-8", "replace"))
                break
    check(
        "elf: no host-sysroot dependency",
        not [d for d in host_deps if "termux" in d or d.startswith("/")],
        ", ".join(host_deps) if host_deps else "no DT_NEEDED read",
    )

    src_root = DEFAULT_SOURCE_ROOT
    if "--source-root" in sys.argv:
        src_root = sys.argv[sys.argv.index("--source-root") + 1]
    from_sources = os.path.isdir(src_root)
    expected_classes = dex_class_names(src_root) if from_sources else LEGACY_DEX_CLASSES
    missing_classes = [c for c in expected_classes if c.encode() not in dex]
    if missing_classes:
        detail = f"missing {missing_classes}"
    elif from_sources:
        detail = f"{len(expected_classes)} classes from {src_root}"
    else:
        detail = f"{len(expected_classes)} classes (legacy list; {src_root} not found)"
    check("dex: host classes shipped", not missing_classes, detail)
    try:
        strings = binary_xml_strings(manifest)
        pkg = "com.gongmi.callyscaves2"
        check(
            "manifest: package + launch activity",
            pkg in strings and f"{pkg}.MainActivity" in strings,
            f"{len(strings)} pool strings",
        )
    except Exception as exc:  # noqa: BLE001 - any parse failure is a FAIL, not a crash
        check("manifest: package + launch activity", False, f"AXML parse: {exc}")

    apksigner = shutil.which("apksigner") or sdk_tool("apksigner")
    if apksigner:
        proc = subprocess.run(
            [apksigner, "verify", "-v", apk_path], capture_output=True, text=True
        )
        out = proc.stdout + proc.stderr
        detail = out.strip().splitlines()[-1] if out.strip() else f"exit {proc.returncode}, no output"
        check("signature: apksigner verify", proc.returncode == 0, detail)
        if expect_signer:
            # The digest is not part of `verify -v`; it needs --print-certs.
            certs = subprocess.run(
                [apksigner, "verify", "--print-certs", apk_path], capture_output=True, text=True
            )
            cert_out = certs.stdout + certs.stderr
            line = next(
                (l for l in cert_out.splitlines()
                 if "SHA-256 digest" in l and "certificate" in l.lower()),
                "",
            )
            got = line.split(":")[-1].strip().lower()
            check("signature: expected signer", got == expect_signer.lower(),
                  f"got {got or 'no certificate digest printed'}")
    else:
        results.append(("signature: apksigner verify", True, "SKIPPED - apksigner not on PATH or SDK"))
        print("[SKIP] signature: apksigner verify - apksigner not on PATH or SDK")

    failed = [r for r in results if not r[1]]
    print()
    print(f"{len(results) - len(failed)}/{len(results)} checks passed")
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
