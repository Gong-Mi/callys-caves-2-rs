#!/usr/bin/env python3
"""Check the pinned VM bodies, then compile/run ONLY the rebuilt C fixture."""
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
ENTRIES = (
    ("VM_ExecRelease", "_ZN2VM11ExecReleaseER6VMExecP6RValue", 0xE4540, 0xE47C8, "vm_exec_release.c"),
    ("PerformReturn", "_Z13PerformReturnPhP6VMExec", 0xE42D8, 0xE44D4, "perform_return.c"),
)
SOURCES = [row[-1] for row in ENTRIES]
FLAGS = [
    "--target=armv7a-none-eabi", "-march=armv7-a", "-marm", "-mfloat-abi=softfp",
    "-std=c11", "-ffreestanding", "-fno-builtin", "-fno-stack-protector",
    "-Wall", "-Wextra", "-Werror", "-nostdlib", "-static", "-fuse-ld=lld", "-Wl,-e,_start",
]
PASS = "PASS exec-release: entry dispatch catch unwind return pool; perform-return: null reloads empty-args\n"
RELEASE_MUTANTS = (
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
RETURN_MUTANTS = (
    ("map_uses_held_buffer", "const volatile VMBuffer *map_buffer = s->buffer;",
     "const volatile VMBuffer *map_buffer = buffer;", "return-split-table-reload"),
    ("stale_argc_after_free", "        argc = g_ArgumentCount;", "        (void)g_ArgumentCount;",
     "frame-return-does-not-exit"),
    ("arg_clears_word_4", "            value[2] = 0;",
     "            value[2] = 0;\n            value[1] = 0;", "return-three-word-arg-clear"),
    ("arg_restores_base_without_offset", "Argument = (uint8_t *)(stack + argument_offset);",
     "(void)argument_offset;\n    Argument = (uint8_t *)stack;", "return-relative-argument-offset"),
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
    bodies = {}
    for name, symbol, start, stop, _ in ENTRIES:
        syms = dynsym.get_symbol_by_name(symbol) or []
        size = stop - start
        need(len(syms) == 1 and syms[0]["st_value"] == start and syms[0]["st_size"] == size,
             f"{name}: unexpected original symbol/extent/ISA")
        offset, = elf.address_offsets(start, size)
        body = raw[offset:offset + size]
        rows = (REVERSE / f"asm/index-{name}.tsv").read_text().splitlines()
        need(len(rows) * 4 == size, f"{name}: wrong original index population")
        for i, row in enumerate(rows):
            addr, word, _, _ = row.split("\t")
            need(int(addr, 16) == start + 4 * i, f"bad index address for row {i}")
            need(int(word, 16) == int.from_bytes(body[4 * i:4 * i + 4], "little"),
                 f"original word mismatch at 0x{addr}")
        bodies[name] = (digest(body), len(rows))
    return bodies


def link(folder, opt, sources):
    return subprocess.run(["clang", *FLAGS, opt, "-I", str(folder),
                           *(str(folder / name) for name in sources), str(folder / "check.c"),
                           "-o", str(folder / "fixture.elf")], capture_output=True, text=True, timeout=30)


def build_and_run(folder, opt, expected_status, expected_stdout):
    exe = folder / "fixture.elf"
    result = link(folder, opt, SOURCES)
    need(result.returncode == 0, f"{opt} synthetic fixture link failed: {result.stderr}")
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
    bodies = bind_original(opt.so)
    source = {name: (MODULE / "src" / name).read_bytes() for name in SOURCES}
    header = (MODULE / "src/vm_exec_release.h").read_bytes()
    fixture = (MODULE / "fixture/check.c").read_bytes()
    scratch = Path(os.environ.get("TMPDIR") or Path.home() / ".hermes/cache/scratch")
    with tempfile.TemporaryDirectory(dir=scratch, prefix="cally_exec_release_") as temp:
        root = Path(temp)
        (root / "vm_exec_release.h").write_bytes(header)
        (root / "check.c").write_bytes(fixture)
        for name, _, start, _, path in ENTRIES:
            body_sha, words = bodies[name]
            (root / path).write_bytes(source[path])
            print(f"BINDING v1 code={start:#x} body_sha256={body_sha} fixture_sha256={digest(fixture)} "
                  f"impl_sha256={digest(source[path])} header_sha256={digest(header)} entry={name}")
            print(f"STATIC entry={name} index_words={words} original_executed=false")
        missing_return = link(root, "-O2", [SOURCES[0]])
        need(missing_return.returncode != 0 and "undefined symbol: PerformReturn" in missing_return.stderr
             and "vm_exec_release.c" in missing_return.stderr,
             f"PerformReturn must be linked from its real TU, got {missing_return.stderr!r}")
        print("EXPECTED_LINK_RED without perform_return.c: PerformReturn")
        for level in ("-O0", "-O2"):
            build_and_run(root, level, 0, PASS)
            print(f"{level}: {PASS.strip()}")
        for path, cases in zip(SOURCES, (RELEASE_MUTANTS, RETURN_MUTANTS), strict=True):
            clean = source[path].decode()
            for name, old, new, observation in cases:
                need(clean.count(old) == 1, f"nonunique mutation site: {name}")
                (root / path).write_text(clean.replace(old, new))
                build_and_run(root, "-O2", 1, f"FAIL {observation}\n")
                print(f"EXPECTED_RED {name}: {observation}")
            (root / path).write_bytes(source[path])
    mutations = len(RELEASE_MUTANTS) + len(RETURN_MUTANTS)
    print(f"RESULT PASS synthetic_only=true positive_profiles=2 mutations={mutations} link_controls=1")


if __name__ == "__main__":
    main()
