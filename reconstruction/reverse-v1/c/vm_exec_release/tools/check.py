#!/usr/bin/env python3
"""Check the pinned ExecRelease words, then compile/run ONLY the rebuilt C fixture."""
from __future__ import annotations

import argparse
import hashlib
import io
import os
import subprocess
import tempfile
from pathlib import Path

from elftools.elf.elffile import ELFFile

MODULE = Path(__file__).resolve().parents[1]
REVERSE = MODULE.parents[1]
IMAGE = "3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a"
FUNCTION = "_ZN2VM11ExecReleaseER6VMExecP6RValue"
START, STOP = 0xE4540, 0xE47C8
FLAGS = [
    "--target=armv7a-none-eabi", "-march=armv7-a", "-marm", "-mfloat-abi=softfp",
    "-std=c11", "-ffreestanding", "-fno-builtin", "-fno-stack-protector",
    "-Wall", "-Wextra", "-Werror", "-nostdlib", "-static", "-fuse-ld=lld", "-Wl,-e,_start",
]
PASS = "PASS exec-release: entry dispatch catch unwind return pool\n"
# Change one semantic line at a time; argc, table layout and source input are fixed.
MUTANTS = (
    ("param_width", "width += g_paramSize[(word >> 16) & 15u];",
     "width += 0u;", "dispatch-param-width"),
    ("catch_compares_parameter", "if (current != caught)",
     "if ((void)current, exec != caught)", "catch-live-exec"),
    ("frame_erases_word_8", "store_word(sp + 4, 0u);\n        goto enter_frame;",
     "store_word(sp + 4, 0u);\n        store_word(sp + 8, 0u);\n        goto enter_frame;", "frame-three-zeros"),
    ("pool_end_inclusive", "addr < base + 0x100008u",
     "addr <= base + 0x100008u", "pool-exclusive-end"),
    ("result_rereads_overlapping_word", "store_word(dst + 4, b);",
     "(void)b;\n        store_word(dst + 4, load_word(sp + 4));", "result-copy-overlap"),
)


def need(ok, message):
    if not ok:
        raise RuntimeError(message)


def digest(raw):
    return hashlib.sha256(raw).hexdigest()


def bind_original(path):
    raw = path.read_bytes()
    need(digest(raw) == IMAGE, "wrong original ELF SHA-256")
    elf = ELFFile(io.BytesIO(raw))
    dynsym = elf.get_section_by_name(".dynsym")
    syms = dynsym.get_symbol_by_name(FUNCTION) or []
    size = STOP - START
    need(len(syms) == 1 and syms[0]["st_value"] == START and syms[0]["st_size"] == size,
         "unexpected original symbol/extent/ISA")
    offset, = elf.address_offsets(START, size)
    body = raw[offset:offset + size]
    rows = (REVERSE / "asm/index-VM_ExecRelease.tsv").read_text().splitlines()
    need(len(rows) * 4 == size, "wrong original index population")
    for i, row in enumerate(rows):
        addr, word, _, _ = row.split("\t")
        need(int(addr, 16) == START + 4 * i, f"bad index address for row {i}")
        need(int(word, 16) == int.from_bytes(body[4 * i:4 * i + 4], "little"),
             f"original word mismatch at 0x{addr}")
    return digest(body), len(rows)


def build_and_run(folder, text, opt, expected_status, expected_stdout):
    src, exe = folder / "exec_release.c", folder / "fixture.elf"
    src.write_text(text)
    subprocess.run(["clang", *FLAGS, opt, "-I", str(folder), str(src),
                    str(folder / "check.c"), "-o", str(exe)], check=True, timeout=30)
    elf = ELFFile(io.BytesIO(exe.read_bytes()))
    need(elf.elfclass == 32 and elf.little_endian and elf["e_machine"] == "EM_ARM"
         and elf["e_type"] == "ET_EXEC"
         and not any(s["p_type"] in ("PT_DYNAMIC", "PT_INTERP") for s in elf.iter_segments()),
         "fixture is not a static ARM32 executable")
    check = subprocess.run(["qemu-arm", str(exe)], capture_output=True, text=True, timeout=10)
    need((check.returncode, check.stdout, check.stderr) == (expected_status, expected_stdout, ""),
         f"{opt} {expected_stdout.strip()}: exit={check.returncode} out={check.stdout!r} err={check.stderr!r}")


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--so", required=True, type=Path, help="hash-pinned original; static reads only")
    opt = p.parse_args()
    body_sha, words = bind_original(opt.so)
    source = (MODULE / "src/vm_exec_release.c").read_bytes()
    header = (MODULE / "src/vm_exec_release.h").read_bytes()
    fixture = (MODULE / "fixture/check.c").read_bytes()
    scratch = Path(os.environ.get("TMPDIR") or Path.home() / ".hermes/cache/scratch")
    with tempfile.TemporaryDirectory(dir=scratch, prefix="cally_exec_release_") as temp:
        root = Path(temp)
        (root / "vm_exec_release.h").write_bytes(header)
        (root / "check.c").write_bytes(fixture)
        print(f"BINDING v1 code=0xe4540 body_sha256={body_sha} fixture_sha256={digest(fixture)} "
              f"impl_sha256={digest(source)} header_sha256={digest(header)} entry=VM_ExecRelease")
        print(f"STATIC index_words={words} original_executed=false")
        clean = source.decode()
        for level in ("-O0", "-O2"):
            build_and_run(root, clean, level, 0, PASS)
            print(f"{level}: {PASS.strip()}")
        for name, old, new, observation in MUTANTS:
            need(clean.count(old) == 1, f"nonunique mutation site: {name}")
            build_and_run(root, clean.replace(old, new), "-O2", 1, f"FAIL {observation}\n")
            print(f"EXPECTED_RED {name}: {observation}")
    print(f"RESULT PASS synthetic_only=true positive_profiles=2 mutations={len(MUTANTS)}")


if __name__ == "__main__":
    main()
