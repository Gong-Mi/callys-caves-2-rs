#!/usr/bin/env python3
"""Export the VM's static opcode table (dynsym `g_instructions`) from the ELF.

Fact base (verified on the shipped libyoyo ARMv7 build, sha256 3bbedd09...):
`.dynsym` defines `g_instructions` as an STT_OBJECT of 128 bytes at VA
0x3f20b4 in `.data`; all 32 slots carry an R_ARM_RELATIVE relocation whose
in-file word is the VA of a defined, executable Do*/PerformReturn handler.
This tool reads the ELF through pyelftools (no external `readelf` binary is
invoked), validates every slot against that named boundary, and emits one
row per opcode index:

    idx<TAB>0x<slot-va><TAB>mangled handler name

Repeated handlers in neighbouring slots (0x3f212c/0x3f2130 are both DoPopNull)
are legitimate and are not deduplicated. This is the named static object
`g_instructions`; the tool makes no claim about how any particular VM entry
point consumes it.

Fail-closed (`--dump` creates a new file only after every slot is validated):
    exit 1  input unreadable or dump cannot be created (including an existing path)
    exit 2  bad format: not ELFCLASS32, little-endian, EM_ARM, ET_DYN
    exit 3  named boundary unavailable (dynsym lacks `g_instructions`); any
            pointer runs are printed labelled candidate-only and are NEVER dumped
    exit 4  unknown table entry: a slot misses its R_ARM_RELATIVE relocation,
            or its word does not resolve to a defined executable
            Do*/PerformReturn symbol

Usage:
    python3 -B scripts/find_handler_table.py --so libyoyo_armv7.so \
        [--dump handler_table.tsv] [--min-run 8]
"""
from __future__ import annotations

import argparse
import io
import re
import struct
import sys
from pathlib import Path

try:
    from elftools.elf.elffile import ELFFile
    from elftools.common.exceptions import ELFParseError
except ImportError:  # pragma: no cover - environment guard
    print("error: pyelftools is required (pip install pyelftools)", file=sys.stderr)
    raise SystemExit(1)

R_ARM_RELATIVE = 23
TABLE_SYMBOL = "g_instructions"
HANDLER_PAT = re.compile(r"_Z\d+(Do[A-Z]|PerformReturn)")
CANDIDATE_SECTIONS = (".data.rel.ro", ".data.rel.ro.local", ".data", ".rodata")


class Reject(Exception):
    """Refusal with the process exit code it maps to."""

    def __init__(self, code: int, msg: str) -> None:
        super().__init__(msg)
        self.code = code


def load_validated(path: str):
    """Parse the ELF and pin it to the shipped ARM32 little-endian ET_DYN shape."""
    try:
        blob = Path(path).read_bytes()
    except OSError as exc:
        raise Reject(1, f"cannot read {path}: {exc}") from exc
    try:
        ef = ELFFile(io.BytesIO(blob))
    except Exception as exc:  # pyelftools raises assorted types
        raise Reject(2, f"bad format: not a parsable ELF ({exc})") from exc
    if ef.elfclass != 32:
        raise Reject(2, f"bad format: ELFCLASS{ef.elfclass}, only ELFCLASS32 supported")
    if not ef.little_endian:
        raise Reject(2, "bad format: big-endian ELF rejected")
    if ef["e_machine"] != "EM_ARM":
        raise Reject(2, f"bad format: e_machine={ef['e_machine']}, EM_ARM required")
    if ef["e_type"] != "ET_DYN":
        raise Reject(2, f"bad format: e_type={ef['e_type']}, ET_DYN required")
    return ef, blob


def handler_funcs(ef) -> dict[int, str]:
    """VA -> mangled name for defined, executable Do*/PerformReturn symbols."""
    secs = list(ef.iter_sections())
    exec_idx = {
        i
        for i, s in enumerate(secs)
        if s["sh_type"] == "SHT_PROGBITS" and s["sh_flags"] & 0x4  # SHF_EXECINSTR
    }
    funcs: dict[int, str] = {}
    for s in secs:
        if s["sh_type"] not in ("SHT_SYMTAB", "SHT_DYNSYM"):
            continue
        for sym in s.iter_symbols():
            if (
                sym["st_info"]["type"] == "STT_FUNC"
                and sym["st_shndx"] in exec_idx
                and HANDLER_PAT.match(sym.name)
            ):
                funcs.setdefault(sym["st_value"], sym.name)
    return funcs


def named_table(ef):
    """Locate `g_instructions` in .dynsym; None when the name is absent."""
    secs = list(ef.iter_sections())
    for s in secs:
        if s["sh_type"] != "SHT_DYNSYM":
            continue
        for sym in s.iter_symbols():
            if sym.name != TABLE_SYMBOL:
                continue
            if sym["st_info"]["type"] != "STT_OBJECT":
                raise Reject(
                    2,
                    f"bad format: {TABLE_SYMBOL} is {sym['st_info']['type']}, STT_OBJECT required",
                )
            size = sym["st_size"]
            if size <= 0 or size % 4:
                raise Reject(
                    2, f"bad format: {TABLE_SYMBOL} st_size={size}, positive multiple of 4 required"
                )
            shndx = sym["st_shndx"]
            if not isinstance(shndx, int) or not (0 < shndx < len(secs)):
                raise Reject(2, f"bad format: {TABLE_SYMBOL} is not defined in a section")
            host = secs[shndx]
            va = sym["st_value"]
            if (
                host["sh_type"] == "SHT_NOBITS"
                or not host["sh_flags"] & 0x2  # SHF_ALLOC
                or not host["sh_addr"] <= va
                or va + size > host["sh_addr"] + host["sh_size"]
            ):
                raise Reject(
                    2,
                    f"bad format: {TABLE_SYMBOL} @0x{va:x} not inside allocated init data of {host.name}",
                )
            return va, size, host
    return None


def relative_relocs(ef, lo: int, hi: int) -> dict[int, int | None]:
    """R_ARM_RELATIVE r_offset -> RELA addend (None for REL, addend lives in the word)."""
    out: dict[int, int | None] = {}
    for s in ef.iter_sections():
        if s["sh_type"] not in ("SHT_REL", "SHT_RELA"):
            continue
        for e in s.iter_relocations():
            off = e["r_offset"]
            if not lo <= off < hi:
                continue
            if off % 4:
                raise Reject(4, f"unknown table entry: relocation at 0x{off:x} is not 4-byte aligned")
            if e["r_info_type"] != R_ARM_RELATIVE:
                raise Reject(
                    4,
                    f"unknown table entry: slot @0x{off:x} uses reloc type {e['r_info_type']}, R_ARM_RELATIVE required",
                )
            if off in out:
                raise Reject(4, f"unknown table entry: duplicate relocation for slot @0x{off:x}")
            is_rela = s["sh_type"] == "SHT_RELA"
            out[off] = (e["r_addend"] & 0xFFFFFFFF) if is_rela else None
    return out


def build_rows(ef, blob):
    """Validate the named table; return (rows|None, funcs). rows: (idx, slot_va, name)."""
    funcs = handler_funcs(ef)
    tbl = named_table(ef)
    if tbl is None:
        return None, funcs
    va0, size, host = tbl
    relocs = relative_relocs(ef, va0, va0 + size)
    rows = []
    for i in range(size // 4):
        va = va0 + 4 * i
        if va not in relocs:
            raise Reject(4, f"unknown table entry: slot {i} @0x{va:x} has no R_ARM_RELATIVE relocation")
        addend = relocs[va]
        if addend is not None:
            word = addend
        else:
            foff = host["sh_offset"] + (va - host["sh_addr"])
            if foff + 4 > len(blob):
                raise Reject(4, f"unknown table entry: slot {i} @0x{va:x} lies outside the file image")
            word = struct.unpack_from("<I", blob, foff)[0]
        name = funcs.get(word)
        if name is None:
            raise Reject(
                4,
                f"unknown table entry: slot {i} @0x{va:x} word 0x{word:x} is not a defined executable Do*/PerformReturn symbol",
            )
        rows.append((i, va, name))
    return rows, funcs


def scan_candidates(ef, blob, funcs, min_run: int):
    """Pointer runs only — diagnostics with no named boundary, never dumped."""
    runs = []
    for s in ef.iter_sections():
        if s.name not in CANDIDATE_SECTIONS or s["sh_type"] == "SHT_NOBITS":
            continue
        base, off, size = s["sh_addr"], s["sh_offset"], s["sh_size"]
        end = min(size, len(blob) - off)
        hits: dict[int, int] = {}
        for i in range(0, max(end - 3, 0), 4):
            word = struct.unpack_from("<I", blob, off + i)[0]
            if word in funcs:
                hits[i] = word
        for i in sorted(hits):
            if i - 4 in hits:
                continue  # not a run start
            run = []
            cur = i
            while cur in hits:
                run.append(hits[cur])
                cur += 4
            if len(run) >= min_run:
                runs.append((base + i, len(run), run))
    runs.sort(key=lambda r: -r[1])
    return runs[:3]


def format_table(rows) -> str:
    return "".join(f"{i}\t0x{va:x}\t{name}\n" for i, va, name in rows)


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(
        description="Export the named static opcode table g_instructions from a libyoyo ARMv7 ELF.",
        epilog="Rows are validated against the named dynsym boundary; the dump file is "
        "written only when every slot resolves to a defined executable "
        "Do*/PerformReturn handler.",
    )
    ap.add_argument("--so", required=True, help="path to the ARMv7 shared object to parse")
    ap.add_argument("--dump", help="create a new TSV file; existing paths are never overwritten")
    ap.add_argument(
        "--min-run",
        type=int,
        default=8,
        help="candidate scan only: minimal consecutive Do*/PerformReturn pointer slots to "
        "list a run; has no effect on the named g_instructions table",
    )
    a = ap.parse_args(argv)

    try:
        ef, blob = load_validated(a.so)
        rows, funcs = build_rows(ef, blob)
    except Reject as exc:
        print(f"reject: {exc}", file=sys.stderr)
        return exc.code
    except ELFParseError as exc:  # lazily detected truncation/structural damage
        print(f"reject: bad format: {exc}", file=sys.stderr)
        return 2

    print(f"Do*/PerformReturn 函数 {len(funcs)} 个", file=sys.stderr)
    if rows is None:
        print(
            f"named boundary unavailable: dynsym 缺少 {TABLE_SYMBOL}；以下结果仅是 candidate，"
            "不构成原件静态表结论，--dump 不写出",
            file=sys.stderr,
        )
        found = scan_candidates(ef, blob, funcs, a.min_run)
        for va, n, run in found:
            print(f"candidate: VA 0x{va:x} 连续 {n} 个指针槽（仅 candidate）", file=sys.stderr)
        if not found:
            print("candidate: 无（min-run 以上）", file=sys.stderr)
        if a.dump:
            print(f"--dump {a.dump} 被忽略：只允许导出经命名边界验证的表", file=sys.stderr)
        return 3

    table = format_table(rows)
    if a.dump:
        try:
            # Exclusive creation also rejects links, including aliases of the input ELF.
            with Path(a.dump).open("x", encoding="utf-8") as output:
                output.write(table)
        except OSError as exc:
            print(f"reject: cannot create dump: {exc}", file=sys.stderr)
            return 1
    sys.stdout.write(table)
    print(
        f"校验通过：{TABLE_SYMBOL} @0x{rows[0][1]:x} 共 {len(rows)} 槽，全部 R_ARM_RELATIVE 且目标为已定义可执行处理函数",
        file=sys.stderr,
    )
    if a.dump:
        print(f"写入 {a.dump}: {len(rows)} 项（命名边界 g_instructions）", file=sys.stderr)
    return 0


if __name__ == "__main__":
    sys.exit(main())
