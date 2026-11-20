#!/usr/bin/env python3
"""Host-only regressions for the legacy native evidence CLIs. No oracle runs."""
from __future__ import annotations

import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile
import unittest


SCRIPTS = Path(__file__).resolve().parent
RUNNER = SCRIPTS.parent / "reconstruction/reverse-v1/harness/run_all.sh"
ARMS = ["box_type_diff.py", "do_neg_diff.py", "do_not_diff.py",
        "object_load_diff.py", "var_direct_diff.py"]


class ToolGateTests(unittest.TestCase):
    def setUp(self):
        scratch = tempfile.TemporaryDirectory(prefix="cally-tool-gate-test-")
        self.addCleanup(scratch.cleanup)
        self.root = Path(scratch.name)
        self.env = {**os.environ, "TMPDIR": scratch.name,
                    "LLVM_PROFILE_FILE": str(self.root / "host-%p.profraw")}

    def cli(self, script, *args):
        return subprocess.run([sys.executable, "-B", SCRIPTS / script, *args],
                              env=self.env, capture_output=True, text=True, timeout=10)

    def wrapper(self, case):
        shell = shutil.which("sh")
        if shell is None:
            self.fail("POSIX sh is required for the real wrapper regression")
        fake = self.root / "python3"
        fake.write_text(f"#!{sys.executable}\n" + '''
import os, sys
with open(os.environ['GATE_VISITS'], 'a') as log:
    print(sys.argv[1], file=log)
if os.environ['GATE_CASE'] == 'profile-only':
    print('LLVM Profile: duplicate compiler diagnostic')
else:
    print('child payload: ' + sys.argv[1])
if sys.argv[1] == 'do_neg_diff.py' and os.environ['GATE_CASE'] == 'child-fails':
    sys.exit(3)
''', encoding="utf-8")
        fake.chmod(0o700)
        if case == "filter-fails":
            fake_filter = self.root / "grep"
            fake_filter.write_text(f"#!{shell}\nexit 2\n", encoding="utf-8")
            fake_filter.chmod(0o700)
        visits = self.root / "visits"
        env = {**self.env, "PATH": str(self.root) + os.pathsep + self.env["PATH"],
               "GATE_CASE": case, "GATE_VISITS": str(visits)}
        result = subprocess.run([shell, RUNNER], env=env, capture_output=True,
                                text=True, timeout=10)
        self.assertTrue(visits.is_file(), (result.stdout, result.stderr))
        self.assertEqual(visits.read_text().splitlines(), ARMS)
        return result

    def test_aggregate_reports_the_failed_oracle_despite_successful_filter(self):
        result = self.wrapper("child-fails")
        self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
        self.assertIn("do_neg_diff.py: exit 3", result.stderr)
        self.assertIn("child payload: var_direct_diff.py", result.stdout)

    def test_aggregate_accepts_clean_children_even_when_filter_hides_every_line(self):
        result = self.wrapper("profile-only")
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
        self.assertNotIn("LLVM Profile:", result.stdout)

    def test_aggregate_reports_real_filter_failure(self):
        result = self.wrapper("filter-fails")
        self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
        self.assertIn("box_type_diff.py: log filter exit 2", result.stderr)

    def global_card_check(self, *, second=True, duplicate=False, index_rows=(0x100, 0x104),
                          declared_empty=False, malformed_claims=False):
        asm, cards = self.root / "asm", self.root / "cards"
        asm.mkdir()
        cards.mkdir()
        (asm / "instructions.jsonl").write_text("".join(
            json.dumps({"a": a, "m": "mov", "w": "e1a00000", "o": "r0, r0"}) + "\n"
            for a in index_rows), encoding="utf-8")
        (cards / "a.c").write_text("/* @0x100 mov r0, r0 */\n" +
                                   ("/* @0x104 mov r0, r0 */\n" if second else ""))
        if duplicate:
            (cards / "b.c").write_text("/* @0x100 mov r0, r0 */\n")
        if declared_empty:
            (cards / "b.c").write_text("/* @func 0x100 0x108 */\n")
            (cards / "interfaces.c").write_text("/* Interface note: no function owner. */\n")
        if malformed_claims:
            (self.root / "claims-bad.jsonl").write_text("{invalid\n")
        return self.cli("verify_reverse_v1.py", "--root", self.root, "--strict")

    def test_global_gate_accepts_full_disjoint_cover(self):
        result = self.global_card_check()
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
        self.assertIn("missing_in_cards=0", result.stdout)

    def test_global_gate_rejects_lost_anchor(self):
        result = self.global_card_check(second=False)
        self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
        self.assertIn("missing_in_cards=1", result.stdout)
        self.assertIn("missing 0x104", result.stdout)

    def test_global_gate_rejects_overlapping_owner(self):
        result = self.global_card_check(duplicate=True)
        self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
        self.assertIn("addresses_claimed_by_two_cards=1", result.stdout)
        self.assertIn("shared 0x100", result.stdout)

    def test_global_gate_rejects_duplicate_census_address(self):
        result = self.global_card_check(index_rows=(0x100, 0x104, 0x100))
        self.assertEqual(result.returncode, 2, result.stdout + result.stderr)
        self.assertIn("duplicate census address 0x100", result.stderr)

    def test_declared_function_without_anchors_cannot_borrow_coverage(self):
        result = self.global_card_check(declared_empty=True)
        self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
        self.assertIn("EMPTY_FUNCTION_CARD", result.stdout)
        self.assertIn("missing_in_cards=0", result.stdout)
        self.assertIn("empty_function_cards=1", result.stdout)

    def test_invalid_claims_is_an_input_error_not_an_evidence_mismatch(self):
        result = self.global_card_check(malformed_claims=True)
        self.assertEqual(result.returncode, 2, result.stdout + result.stderr)
        self.assertIn("invalid claim ledger", result.stderr)
        self.assertIn("claims-bad.jsonl:1", result.stderr)
        self.assertNotIn("Traceback", result.stderr)
        self.assertNotIn("EXACT", result.stdout)

    def local_card_check(self, text, index="100\te3a00010\tmov\tr0, #0x10\n"):
        card = self.root / "slice.c"
        card.write_text(text)
        tsv = self.root / "index.tsv"
        tsv.write_text(index)
        return self.cli("check_card_anchors.py", "--card", card, "--index", tsv)

    def test_register_and_numeric_operand_identity(self):
        result = self.local_card_check("/* @0x100 mov r0, #16 */\n")
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
        self.assertIn("RESULT EXACT", result.stdout)

    def test_decimal_ten_does_not_match_hex_sixteen(self):
        result = self.local_card_check("/* @0x100 mov r0, #10 */\n")
        self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
        self.assertIn("mismatch=1", result.stdout)

    def test_late_identical_anchor_does_not_hide_earlier_conflict(self):
        result = self.local_card_check("/* @0x100 mov r1, #0x10 */\n"
                                       "/* @0x100 mov r0, #0x10 */\n")
        self.assertNotEqual(result.returncode, 0, result.stdout + result.stderr)
        self.assertIn("conflicting anchors at 0x100", result.stderr)

    def test_empty_index_and_card_cannot_certify_each_other(self):
        result = self.local_card_check("", index="")
        self.assertEqual(result.returncode, 2, result.stdout + result.stderr)
        self.assertIn("empty instruction index", result.stderr)

    def test_prose_only_address_reference_does_not_satisfy_a_card_anchor(self):
        result = self.local_card_check("/* Summary mentions @0x100 mov r0, #0x10 */\n")
        self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
        self.assertIn("missing=1", result.stdout)

    def test_prose_cross_reference_does_not_conflict_with_the_real_anchor(self):
        result = self.local_card_check("/* Summary: @0x100 returns a value. */\n"
                                       "/* @0x100 mov r0, #0x10 */\n")
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)

    def test_arrow_annotation_allows_consistent_duplicate_anchor(self):
        result = self.local_card_check("/* @0x100 mov r0, #16 → comment about result */\n"
                                       "/* @0x100 mov r0, #0x10 */\n")
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)

    def test_composite_mnemonic_is_a_summary_not_an_anchor(self):
        result = self.local_card_check("/* @0x100 mov/movt r0 → summary */\n"
                                       "/* @0x100 mov r0, #0x10 */\n")
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
        result = self.local_card_check("/* @0x100 mov/movt r0 → summary */\n")
        self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
        self.assertIn("missing=1", result.stdout)


if __name__ == "__main__":
    unittest.main()
