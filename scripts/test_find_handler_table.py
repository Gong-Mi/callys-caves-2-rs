#!/usr/bin/env python3
"""Regression tests for scripts/find_handler_table.py.

Default (synthetic) cases exercise the full CLI through argparse and the
independent pyelftools parse path and pass without any repo-external input.
Real-libyoyo cases are enabled by setting CALLY_LIBYOYO_SO. They are skipped
when not requested; an explicitly selected sample or missing reference TSV
that cannot satisfy the SHA-256/reference contract fails the suite.

Everything written by these tests lives under TMPDIR with the
cally_dispatch_tool_ prefix; the original .so is never executed or modified
(tamper cases operate on a controlled copy via plain local I/O).
"""
from __future__ import annotations

import hashlib
import os
import shutil
import struct
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
SCRIPT = HERE / "find_handler_table.py"
COMMITTED_TSV = ROOT / "reconstruction" / "reverse-v1" / "asm" / "handler_table.tsv"

REAL_SO_SHA256 = "3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a"

# --- synthetic ARM32 ET_DYN fixtures -----------------------------------------

R_ARM_RELATIVE = 23
DOA, DOB, PERFRET, HELPER = 0x1100, 0x1104, 0x1108, 0x110C
NAMES = {
    DOA: "_Z4DoAjj",
    DOB: "_Z4DoBjj",
    PERFRET: "_Z13PerformReturnjj",
    HELPER: "_Z6Helperjj",  # valid FUNC but NOT Do*/PerformReturn
}
TABLE_VA = 0x2010


def _strtab(names):
    buf = b"\0"
    offs = {}
    for n in names:
        offs[n] = len(buf)
        buf += n.encode() + b"\0"
    return buf, offs


def synth_elf(
    path,
    *,
    words=(DOA, DOB, PERFRET, DOB),
    table_symbol="g_instructions",
    obj_size=None,
    reloc_slots=None,
    reloc_type=R_ARM_RELATIVE,
    machine=0x28,  # EM_ARM
    e_type=3,  # ET_DYN
):
    """Write a minimal ELFCLASS32-LE EM_ARM ET_DYN with a g_instructions table."""
    nslots = len(words)
    obj_size = nslots * 4 if obj_size is None else obj_size
    reloc_slots = range(nslots) if reloc_slots is None else reloc_slots

    dynsym_names = ["g_instructions", *NAMES.values()]
    dynstr, dyn_offs = _strtab(dynsym_names)
    shstr, sh_offs = _strtab(
        [".text", ".data", ".rel.dyn", ".dynsym", ".dynstr", ".shstrtab"]
    )

    text = b"\x00" * 0x20
    data = b"\x00" * (TABLE_VA - 0x2000) + b"".join(struct.pack("<I", w) for w in words)
    rel = b"".join(
        struct.pack("<II", TABLE_VA + 4 * i, (0 << 8) | reloc_type) for i in reloc_slots
    )

    syms = [b"\x00" * 16]  # index 0
    if table_symbol is not None:
        syms.append(
            struct.pack(
                "<IIIBBH",
                dyn_offs[table_symbol],
                TABLE_VA,
                obj_size,
                (1 << 4) | 1,  # GLOBAL, STT_OBJECT
                0,
                2,  # .data
            )
        )
    for addr, nm in NAMES.items():
        syms.append(
            struct.pack("<IIIBBH", dyn_offs[nm], addr, 4, (1 << 4) | 2, 0, 1)  # .text FUNC
        )
    dynsym = b"".join(syms)

    ehsize, shentsize = 52, 40
    off = ehsize

    def place(blob):
        nonlocal off
        o = off
        off += len(blob)
        off += (-off) % 4
        return o

    o_text, o_data, o_rel = place(text), place(data), place(rel)
    o_dynsym, o_dynstr, o_shstr = place(dynsym), place(dynstr), place(shstr)
    shoff = off

    def pad4(b):
        return b + b"\x00" * ((-len(b)) % 4)

    body = b"".join(pad4(x) for x in (text, data, rel, dynsym, dynstr, shstr))

    # (name, type, flags, addr, offset, size, link, info, align, entsize)
    secdefs = [
        (".text", "PROGBITS", 0x6, 0x1000, o_text, len(text), 0, 0, 4, 0),
        (".data", "PROGBITS", 0x3, 0x2000, o_data, len(data), 0, 0, 4, 0),
        (".rel.dyn", "REL", 0x2, 0, o_rel, len(rel), 4, 0, 4, 8),
        (".dynsym", "DYNSYM", 0x2, 0, o_dynsym, len(dynsym), 5, 1, 4, 16),
        (".dynstr", "STRTAB", 0x2, 0, o_dynstr, len(dynstr), 0, 0, 1, 0),
        (".shstrtab", "STRTAB", 0x0, 0, o_shstr, len(shstr), 0, 0, 1, 0),
    ]
    hdr = struct.pack(
        "<16sHHIIIIIHHHHHH",
        b"\x7fELF\x01\x01\x01\x00" + b"\x00" * 8,
        e_type,
        machine,
        1,
        0x1000,
        0,  # no phdrs needed for parsing
        shoff,
        0x05000200,
        ehsize,
        0,
        0,
        shentsize,
        len(secdefs) + 1,
        6,  # shstrndx
    )
    SHT = {"PROGBITS": 1, "REL": 9, "DYNSYM": 11, "STRTAB": 3}
    shs = b"\x00" * shentsize  # NULL section
    for nm, t, fl, addr, o, size, link, info, al, es in secdefs:
        shs += struct.pack(
            "<10I", sh_offs[nm], SHT[t],
            fl, addr, o, size, link, info, al, es,
        )
    Path(path).write_bytes(hdr + body + shs)


def run_cli(so, dump=None, extra=()):
    cmd = [sys.executable, "-B", str(SCRIPT), "--so", str(so), *extra]
    if dump is not None:
        cmd += ["--dump", str(dump)]
    return subprocess.run(cmd, capture_output=True, text=True, timeout=120)


def expected_tsv(words, base=TABLE_VA):
    return "".join(
        f"{i}\t0x{base + 4 * i:x}\t{NAMES[w]}\n" for i, w in enumerate(words)
    )


class SyntheticCliCases(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory(prefix="cally_dispatch_tool_")
        self.addCleanup(self.tmp.cleanup)
        self.dir = Path(self.tmp.name)

    def test_happy_stdout_and_dump_match_expected_rows(self):
        so = self.dir / "ok.so"
        synth_elf(so)
        dump = self.dir / "out.tsv"
        p = run_cli(so, dump=dump)
        self.assertEqual(p.returncode, 0, p.stderr)
        want = expected_tsv((DOA, DOB, PERFRET, DOB))
        self.assertEqual(p.stdout, want)
        self.assertEqual(dump.read_text(), want)  # slot 1 == slot 3 duplicate is legal

    def test_dump_refuses_input_and_existing_output(self):
        so = self.dir / "ok.so"
        synth_elf(so)
        dump = self.dir / "out.tsv"
        dump.write_bytes(b"previous evidence\n")
        for path in (so, dump):
            with self.subTest(path=path.name):
                before = path.read_bytes()
                p = run_cli(so, dump=path)
                self.assertEqual(p.returncode, 1, p.stderr)
                self.assertIn("cannot create dump", p.stderr)
                self.assertEqual(p.stdout, "")
                self.assertEqual(path.read_bytes(), before)

    def test_dump_refuses_dangling_symlink(self):
        so = self.dir / "ok.so"
        synth_elf(so)
        target = self.dir / "must-not-be-created.tsv"
        dump = self.dir / "out.tsv"
        dump.symlink_to(target)
        p = run_cli(so, dump=dump)
        self.assertEqual(p.returncode, 1, p.stderr)
        self.assertIn("cannot create dump", p.stderr)
        self.assertEqual(p.stdout, "")
        self.assertTrue(dump.is_symlink())
        self.assertFalse(target.exists())

    def test_unknown_entry_word_not_handler_rejected_without_dump(self):
        so = self.dir / "badword.so"
        synth_elf(so, words=(DOA, 0xDEADBEEF, PERFRET, DOB))
        dump = self.dir / "out.tsv"
        p = run_cli(so, dump=dump)
        self.assertEqual(p.returncode, 4, p.stderr)
        self.assertIn("unknown table entry", p.stderr)
        self.assertFalse(dump.exists(), "dump must not be written on rejection")

    def test_unknown_entry_nonhandler_function_rejected(self):
        so = self.dir / "helper.so"
        synth_elf(so, words=(DOA, HELPER, PERFRET, DOB))
        p = run_cli(so, dump=self.dir / "out.tsv")
        self.assertEqual(p.returncode, 4)
        self.assertIn("Do*/PerformReturn", p.stderr)

    def test_slot_without_relative_reloc_rejected(self):
        so = self.dir / "noreloc.so"
        synth_elf(so, reloc_slots=(0, 1, 3))
        p = run_cli(so, dump=self.dir / "out.tsv")
        self.assertEqual(p.returncode, 4)
        self.assertIn("no R_ARM_RELATIVE relocation", p.stderr)

    def test_wrong_reloc_type_rejected(self):
        so = self.dir / "wrongtype.so"
        synth_elf(so, reloc_type=2)  # R_ARM_ABS32 instead of RELATIVE
        p = run_cli(so, dump=self.dir / "out.tsv")
        self.assertEqual(p.returncode, 4)
        self.assertIn("R_ARM_RELATIVE required", p.stderr)

    def test_missing_named_symbol_candidates_only_exit3(self):
        so = self.dir / "nosym.so"
        synth_elf(so, table_symbol=None)
        dump = self.dir / "out.tsv"
        p = run_cli(so, dump=dump, extra=("--min-run", "4"))
        self.assertEqual(p.returncode, 3, p.stderr)
        self.assertIn("candidate", p.stderr)
        self.assertIn("--dump", p.stderr)
        self.assertFalse(dump.exists(), "candidates must never feed --dump")
        self.assertEqual(p.stdout, "", "no named table => no table rows on stdout")

    def test_bad_format_machine_rejected(self):
        so = self.dir / "x86.so"
        synth_elf(so, machine=0x3E)  # EM_X86_64
        p = run_cli(so)
        self.assertEqual(p.returncode, 2, p.stderr)
        self.assertIn("bad format", p.stderr)

    def test_bad_format_non_elf_rejected(self):
        so = self.dir / "junk.so"
        so.write_bytes(b"this is not an elf file, not even close")
        p = run_cli(so)
        self.assertEqual(p.returncode, 2, p.stderr)

    def test_bad_format_object_size_not_word_multiple(self):
        so = self.dir / "oddsize.so"
        synth_elf(so, obj_size=18)
        p = run_cli(so)
        self.assertEqual(p.returncode, 2, p.stderr)
        self.assertIn("multiple of 4", p.stderr)

    def test_unreadable_input_exit1(self):
        p = run_cli(self.dir / "absent.so")
        self.assertEqual(p.returncode, 1)
        self.assertIn("cannot read", p.stderr)


class RealSampleCases(unittest.TestCase):
    """Opt-in extras: real .so (sha256-pinned) + tracked committed TSV."""

    def setUp(self):
        selected = os.environ.get("CALLY_LIBYOYO_SO")
        if selected is None:
            self.skipTest("set CALLY_LIBYOYO_SO to enable the pinned real-sample cases")
        self.real_so = Path(selected)
        self.assertTrue(self.real_so.is_file(), f"libyoyo .so unavailable: {self.real_so}")
        self.assertEqual(hashlib.sha256(self.real_so.read_bytes()).hexdigest(), REAL_SO_SHA256)
        self.assertTrue(COMMITTED_TSV.is_file(), f"reference TSV missing: {COMMITTED_TSV}")
        self.tmp = tempfile.TemporaryDirectory(prefix="cally_dispatch_tool_")
        self.addCleanup(self.tmp.cleanup)
        self.dir = Path(self.tmp.name)

    def _first_slot_file_offset(self):
        from elftools.elf.elffile import ELFFile

        with self.real_so.open("rb") as stream:
            ef = ELFFile(stream)
            dyn = ef.get_section_by_name(".dynsym")
            g = next(s for s in dyn.iter_symbols() if s.name == "g_instructions")
            host = ef.get_section(g["st_shndx"])
            return host["sh_offset"] + (g["st_value"] - host["sh_addr"])

    def test_dump_byte_identical_to_committed_tsv(self):
        committed = COMMITTED_TSV.read_bytes()
        dump = self.dir / "out.tsv"
        p = run_cli(self.real_so, dump=dump)
        self.assertEqual(p.returncode, 0, p.stderr)
        self.assertEqual(dump.read_bytes(), committed)
        self.assertEqual(p.stdout.encode(), committed)

    def test_tampered_copy_entry_rejected_no_dump(self):
        copy_so = self.dir / "libyoyo_tampered_copy.so"
        shutil.copyfile(self.real_so, copy_so)  # controlled copy, plain local I/O
        off = self._first_slot_file_offset()
        with open(copy_so, "r+b") as fh:  # single table entry -> non-function word
            fh.seek(off)
            fh.write(struct.pack("<I", 0xDEADBEEF))
        dump = self.dir / "out.tsv"
        p = run_cli(copy_so, dump=dump)
        self.assertEqual(p.returncode, 4, p.stderr)
        self.assertIn("unknown table entry", p.stderr)
        self.assertFalse(dump.exists())
        self.assertEqual(
            hashlib.sha256(self.real_so.read_bytes()).hexdigest(),
            REAL_SO_SHA256,
            "original .so must be untouched",
        )


if __name__ == "__main__":
    unittest.main(verbosity=2)
