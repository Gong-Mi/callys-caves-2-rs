#!/usr/bin/env python3
"""Contract tests for the read-only C++ static-module verifier."""
from __future__ import annotations

import contextlib
import hashlib
import io
import json
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parent))

import verify_cpp_module as verifier  # noqa: E402


class VerifyWordRowsTests(unittest.TestCase):
    def setUp(self) -> None:
        self.functions = [{"entry": "0x1000", "size": 8, "isa": "arm", "symbols": ["f"]}]
        self.rows = [
            {"entry": 0x1000, "va": 0x1000, "word": 0x11223344, "line": 2},
            {"entry": 0x1000, "va": 0x1004, "word": 0xAABBCCDD, "line": 3},
        ]
        self.image = {0x1000: bytes.fromhex("44332211"), 0x1004: bytes.fromhex("ddccbbaa")}
        self.read_vaddr = lambda va, size: self.image[va][:size]

    def test_exact_words_cover_the_entire_function(self) -> None:
        self.assertEqual([], verifier.verify_word_rows(self.functions, self.rows, self.read_vaddr))

    def test_wrong_word_is_rejected_against_elf_bytes(self) -> None:
        rows = [dict(row) for row in self.rows]
        rows[0]["word"] ^= 1
        errors = verifier.verify_word_rows(self.functions, rows, self.read_vaddr)
        self.assertTrue(any("word mismatch" in error for error in errors), errors)

    def test_missing_word_is_rejected_as_incomplete_coverage(self) -> None:
        errors = verifier.verify_word_rows(self.functions, self.rows[:1], self.read_vaddr)
        self.assertTrue(any("coverage mismatch" in error for error in errors), errors)

    def test_duplicate_word_address_is_rejected(self) -> None:
        errors = verifier.verify_word_rows(self.functions, self.rows + [dict(self.rows[1])], self.read_vaddr)
        self.assertTrue(any("duplicate" in error for error in errors), errors)

    def test_word_outside_function_is_rejected(self) -> None:
        rows = [dict(row) for row in self.rows]
        rows[1]["va"] = 0x1008
        errors = verifier.verify_word_rows(self.functions, rows, self.read_vaddr)
        self.assertTrue(any("outside function" in error for error in errors), errors)

    def test_non_arm_function_is_rejected_explicitly(self) -> None:
        functions = [dict(self.functions[0], isa="thumb")]
        errors = verifier.verify_word_rows(functions, self.rows, self.read_vaddr)
        self.assertTrue(any("unsupported ISA" in error for error in errors), errors)

    def test_arm_entry_must_be_absolutely_word_aligned(self) -> None:
        functions = [{"entry": 0x1002, "size": 4, "isa": "arm"}]
        rows = [{"entry": 0x1002, "va": 0x1002, "word": 0x11223344}]
        errors = verifier.verify_word_rows(functions, rows, lambda _va, _size: bytes.fromhex("44332211"))
        self.assertTrue(any("absolute" in error and "align" in error for error in errors), errors)

    def test_distinct_function_ranges_must_not_overlap(self) -> None:
        functions = [
            {"entry": 0x1000, "size": 8, "isa": "arm"},
            {"entry": 0x1004, "size": 4, "isa": "arm"},
        ]
        rows = [
            {"entry": 0x1000, "va": 0x1000, "word": 0x11223344},
            {"entry": 0x1000, "va": 0x1004, "word": 0xAABBCCDD},
            {"entry": 0x1004, "va": 0x1004, "word": 0xAABBCCDD},
        ]
        errors = verifier.verify_word_rows(functions, rows, self.read_vaddr)
        self.assertTrue(any("overlap" in error for error in errors), errors)

    def test_nested_ranges_are_checked_against_the_furthest_previous_end(self) -> None:
        functions = [
            {"entry": 0x1000, "size": 0x40, "isa": "arm"},
            {"entry": 0x1004, "size": 4, "isa": "arm"},
            {"entry": 0x1010, "size": 4, "isa": "arm"},
        ]
        errors = verifier.verify_word_rows(functions, [], self.read_vaddr)
        self.assertTrue(any("0x1010" in error and "overlap" in error for error in errors), errors)

    def test_function_size_must_be_an_integer_not_a_truncated_float(self) -> None:
        functions = [{"entry": 0x1000, "size": 4.5, "isa": "arm"}]
        rows = [{"entry": 0x1000, "va": 0x1000, "word": 0x11223344}]
        errors = verifier.verify_word_rows(functions, rows, self.read_vaddr)
        self.assertTrue(any("size" in error and "integer" in error for error in errors), errors)

    def test_huge_function_window_does_not_materialize_expected_addresses(self) -> None:
        size = 0x10000000
        functions = [{"entry": 0x1000, "size": size, "isa": "arm"}]

        def guarded_range(*args):
            values = range(*args)
            if len(values) > 1024:
                raise AssertionError("unbounded word-grid materialization")
            return values

        with patch.object(verifier, "range", guarded_range, create=True):
            errors = verifier.verify_word_rows(functions, [], self.read_vaddr)
        expected_words = size // 4
        self.assertTrue(any("coverage mismatch" in error for error in errors), errors)
        self.assertTrue(any(f"missing={expected_words}" in error for error in errors), errors)

    def test_rodata_inside_executable_load_is_not_executable_code(self) -> None:
        load_segments = [(0, 0x4000, b"", 5)]
        executable_sections = [(0x1000, 0x2000)]
        self.assertTrue(
            verifier.is_executable_code_range(0x1100, 8, load_segments, executable_sections)
        )
        self.assertFalse(
            verifier.is_executable_code_range(0x3000, 8, load_segments, executable_sections)
        )


class VerifyModuleTests(unittest.TestCase):
    def setUp(self) -> None:
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name) / "repo" / "reconstruction" / "reverse-v1"
        self.cpp = self.root / "cpp"
        self.module = self.cpp / "object_base"
        self.module.mkdir(parents=True)
        self.header_dir = self.cpp / "vm_exec"
        self.header_dir.mkdir()
        self.image = Path(self.temp.name) / "image.so"
        self.image.write_bytes(b"synthetic pinned image")
        self.body = bytes.fromhex("44332211")
        self.source = self.module / "one.cpp"
        self.source.write_bytes(b"int recovered_function;\n")
        self.header = self.header_dir / "vm_exec.hpp"
        self.header.write_bytes(b"struct YYObjectBase;\n")
        self.functions_file = self.module / "functions.json"
        self.words_file = self.module / "original-words.tsv"
        self.manifest = {
            "schema": verifier.SCHEMA,
            "image_sha256": hashlib.sha256(self.image.read_bytes()).hexdigest(),
            "header_path": "../vm_exec/vm_exec.hpp",
            "header_sha256": hashlib.sha256(self.header.read_bytes()).hexdigest(),
            "canonical_static_api_header": "../vm_exec/vm_exec.hpp",
            "canonical_api_header_sha256": hashlib.sha256(self.header.read_bytes()).hexdigest(),
            "additional_headers_sha256": {},
            "functions": [
                {
                    "entry": "0x1000",
                    "size": 4,
                    "symbols": ["f"],
                    "boundary": "defined_dynsym",
                    "body_sha256": hashlib.sha256(self.body).hexdigest(),
                    "isa": "arm",
                    "translation_source": "one.cpp",
                    "translation_source_sha256": hashlib.sha256(self.source.read_bytes()).hexdigest(),
                }
            ],
        }
        self.write_manifest()
        self.words_file.write_text(
            "entry\tva\tword\tmnemonic\toperands\n1000\t1000\t11223344\tldr\tr0, [r0]\n"
        )
        self.symbols = {(".dynsym", "f"): {(0x1000, 4)}}
        self.read_vaddr = lambda _address, _size: self.body

    def write_manifest(self) -> None:
        self.functions_file.write_text(json.dumps(self.manifest))

    def run_fake_elf(
        self,
        executable: bool = True,
        init_array_values: list[int | None] | None = None,
    ):
        values = [0x1000, 0x1004] if init_array_values is None else init_array_values
        fake = (
            self.symbols,
            self.read_vaddr,
            lambda _address, _size: executable,
            values,
        )
        return patch.object(verifier, "load_elf", return_value=fake)

    def test_matching_manifest_and_elf_inputs_pass(self) -> None:
        with self.run_fake_elf():
            report = verifier.verify_module(self.module, self.image)
        self.assertTrue(report["ok"], report["errors"])

    def test_canonical_header_hash_is_bound_to_its_declared_path(self) -> None:
        self.manifest["canonical_api_header_sha256"] = "0" * 64
        self.write_manifest()
        with self.run_fake_elf():
            report = verifier.verify_module(self.module, self.image)
        self.assertTrue(any("canonical API header SHA mismatch" in e for e in report["errors"]))

    def test_primary_header_hash_requires_a_path_and_is_checked(self) -> None:
        self.manifest["header_sha256"] = "0" * 64
        self.write_manifest()
        with self.run_fake_elf():
            report = verifier.verify_module(self.module, self.image)
        self.assertTrue(any("primary header SHA mismatch" in e for e in report["errors"]))

    def test_primary_header_hash_without_path_is_rejected(self) -> None:
        self.manifest.pop("header_path")
        self.write_manifest()
        with self.run_fake_elf():
            report = verifier.verify_module(self.module, self.image)
        self.assertTrue(any("header_path must be declared together" in e for e in report["errors"]))

    def test_unrecognized_top_level_hash_claim_is_rejected(self) -> None:
        self.manifest["mystery_sha256"] = "0" * 64
        self.write_manifest()
        with self.run_fake_elf():
            report = verifier.verify_module(self.module, self.image)
        self.assertTrue(any("unverified top-level hash claim" in e for e in report["errors"]))

    def test_duplicate_symbol_name_is_rejected(self) -> None:
        self.manifest["functions"][0]["symbols"] = ["f", "f"]
        self.write_manifest()
        with self.run_fake_elf():
            report = verifier.verify_module(self.module, self.image)
        self.assertTrue(any("duplicate symbol" in e for e in report["errors"]))

    def test_unknown_non_symbol_boundary_is_rejected(self) -> None:
        self.manifest["functions"][0]["symbols"] = []
        self.manifest["functions"][0]["boundary"] = "handwaved_boundary"
        self.write_manifest()
        with self.run_fake_elf():
            report = verifier.verify_module(self.module, self.image)
        self.assertTrue(any("unsupported non-symbol boundary" in e for e in report["errors"]))

    def test_known_non_symbol_boundary_is_allowed(self) -> None:
        self.manifest["functions"][0]["symbols"] = []
        self.manifest["functions"][0]["boundary"] = "init_array_relative_next_slot"
        self.write_manifest()
        with self.run_fake_elf():
            report = verifier.verify_module(self.module, self.image)
        self.assertTrue(report["ok"], report["errors"])

    def test_init_array_boundary_requires_a_matching_slot_target(self) -> None:
        self.manifest["functions"][0]["symbols"] = []
        self.manifest["functions"][0]["boundary"] = "init_array_relative_next_slot"
        self.write_manifest()
        with self.run_fake_elf(init_array_values=[]):
            report = verifier.verify_module(self.module, self.image)
        self.assertTrue(any("not uniquely referenced by .init_array" in e for e in report["errors"]))

    def test_init_array_boundary_requires_the_next_slot_as_end(self) -> None:
        self.manifest["functions"][0]["symbols"] = []
        self.manifest["functions"][0]["boundary"] = "init_array_relative_next_slot"
        self.write_manifest()
        with self.run_fake_elf(init_array_values=[0x1000, 0x1008]):
            report = verifier.verify_module(self.module, self.image)
        self.assertTrue(any("next .init_array target" in e for e in report["errors"]))

    def test_atexit_boundary_requires_the_next_dynsym_as_end(self) -> None:
        self.manifest["functions"][0]["symbols"] = []
        self.manifest["functions"][0]["boundary"] = "atexit_pointer_and_next_dynsym"
        self.write_manifest()
        self.symbols[(".dynsym", "following")]= {(0x1008, 4)}
        with self.run_fake_elf():
            report = verifier.verify_module(self.module, self.image)
        self.assertTrue(any("next dynsym" in e for e in report["errors"]))

    def test_atexit_boundary_accepts_the_exact_next_dynsym_end(self) -> None:
        self.manifest["functions"][0]["symbols"] = []
        self.manifest["functions"][0]["boundary"] = "atexit_pointer_and_next_dynsym"
        self.write_manifest()
        self.symbols[(".dynsym", "following")] = {(0x1004, 4)}
        with self.run_fake_elf():
            report = verifier.verify_module(self.module, self.image)
        self.assertTrue(report["ok"], report["errors"])

    def test_non_executable_function_range_is_rejected(self) -> None:
        with self.run_fake_elf(executable=False):
            report = verifier.verify_module(self.module, self.image)
        self.assertTrue(any("executable PT_LOAD" in e for e in report["errors"]))

    def test_non_object_manifest_is_a_controlled_input_error(self) -> None:
        self.functions_file.write_text("[]")
        args = ["verify_cpp_module.py", "--module", str(self.module), "--image", str(self.image)]
        stdout = io.StringIO()
        with patch.object(sys, "argv", args), contextlib.redirect_stdout(stdout):
            status = verifier.main()
        self.assertEqual(2, status)
        self.assertEqual("input_error", json.loads(stdout.getvalue())["kind"])

    def test_huge_function_size_returns_controlled_cli_refusal(self) -> None:
        size = 0x10000000
        self.manifest["functions"][0].update(
            size=size,
            symbols=[],
            boundary="init_array_relative_next_slot",
        )
        self.write_manifest()
        self.words_file.write_text("entry\tva\tword\tmnemonic\toperands\n")

        def unreadable(_address: int, _size: int) -> bytes:
            raise ValueError("range is not file-backed")

        def guarded_range(*args):
            values = range(*args)
            if len(values) > 1024:
                raise AssertionError("unbounded word-grid materialization")
            return values

        fake = (self.symbols, unreadable, lambda _address, _size: False, [])
        args = ["verify_cpp_module.py", "--module", str(self.module), "--image", str(self.image)]
        stdout = io.StringIO()
        with (
            patch.object(verifier, "load_elf", return_value=fake),
            patch.object(verifier, "range", guarded_range, create=True),
            patch.object(sys, "argv", args),
            contextlib.redirect_stdout(stdout),
        ):
            status = verifier.main()
        report = json.loads(stdout.getvalue())
        self.assertEqual(1, status)
        self.assertFalse(report["ok"])
        coverage = [error for error in report["errors"] if "coverage mismatch" in error]
        self.assertEqual(1, len(coverage), report["errors"])
        self.assertIn(f"missing={size // 4}", coverage[0])

    def test_word_tsv_rejects_rows_with_extra_fields(self) -> None:
        self.words_file.write_text(
            "entry\tva\tword\tmnemonic\toperands\n1000\t1000\t11223344\tldr\tr0, [r0]\textra\n"
        )
        with self.assertRaisesRegex(ValueError, "too many fields"):
            verifier.read_word_rows(self.words_file)


if __name__ == "__main__":
    unittest.main()
