#!/usr/bin/env python3
"""Regression tests for scripts/audit_object_matrix.py and the generated-report
guard it relies on. Fixture-driven: no test asserts counts that move when the
ledger regenerates - the join, the buckets, the partition and the boundaries
are what is pinned here."""
from __future__ import annotations

import os
import sys
import tempfile
import unittest

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

import audit_object_matrix as aom  # noqa: E402
import audit_semantic_coverage as asc  # noqa: E402


def code_entry(code_id: int, name: str, tier: str, executed: bool, pending: int = 0) -> dict:
    return {
        "code_id": code_id, "name": name, "object": "",
        "tier": tier, "executed": executed,
        "environment_ops_pending": pending, "constant_only_body": "",
        "evidence": {"contract": [], "test": [], "src": []},
    }


def census_of(entries: list[dict]) -> dict:
    return {"codes": {e["code_id"]: e for e in entries}}


def obj(oid: int, name: str, codes: list[int]) -> dict:
    return {"id": oid, "name": name,
            "events": [{"event_type": 0, "subtype": 0, "codes": list(codes)}]}


class BucketTests(unittest.TestCase):
    def test_every_known_tier_maps_to_a_bucket(self):
        for tier in asc.TIER_ORDER:
            self.assertIn(aom.BUCKET_OF.get(tier, "u"), aom.BUCKET_ORDER, tier)
        self.assertEqual(aom.BUCKET_OF["object_cited_contract"], "c")
        self.assertEqual(aom.BUCKET_OF["object_cited_test"], "t")
        self.assertEqual(aom.BUCKET_OF["env_classified"], "e")

    def test_unknown_tier_falls_to_uncited(self):
        self.assertEqual(aom.BUCKET_OF.get("something_new", "u"), "u")


class BuildTests(unittest.TestCase):
    def test_join_counts_and_partition(self):
        census = census_of([
            code_entry(1, "gml_Object_obj_alpha_Create_0", "cited_contract", True),
            code_entry(2, "gml_Object_obj_alpha_Step_0", "structural", False),
            code_entry(3, "gml_Object_obj_alpha_Alarm_0", "env_classified", True, pending=7),
            code_entry(9, "gml_RoomCC_rm_town_1_Create", "structural", True),
        ])
        bundle = [obj(11, "obj_alpha", [1, 2, 3])]
        m = aom.build_matrix(census, bundle)
        row = m["rows"][0]
        self.assertEqual(row["name"] if "name" in row else row["object"], "obj_alpha")
        self.assertEqual(row["codes"], 3)
        self.assertEqual(row["buckets"], {"c": 1, "t": 0, "s": 0, "e": 1, "u": 1})
        self.assertEqual(row["executed"], 2)
        self.assertEqual(row["unexecuted"], [2])
        self.assertEqual(row["pending"], 7)
        # The room code is not an object row; it lands in a container bucket.
        self.assertEqual(m["containers"]["RoomCC"]["codes"], 1)
        self.assertEqual(m["containers"]["RoomCC"]["executed"], 1)
        # Partition: every census code is either owned by a row or a container.
        owned = sum(r["codes"] for r in m["rows"])
        containers = sum(c["codes"] for c in m["containers"].values())
        self.assertEqual(owned + containers, len(census["codes"]))

    def test_object_without_events_is_a_zero_row(self):
        census = census_of([code_entry(9, "gml_RoomCC_rm_x_1_Create", "structural", True)])
        m = aom.build_matrix(census, [{"id": 5, "name": "obj_empty", "events": []}])
        row = m["rows"][0]
        self.assertEqual(row["codes"], 0)
        self.assertEqual(row["executed"], 0)
        self.assertEqual(row["unexecuted"], [])

    def test_totals_aggregate(self):
        census = census_of([
            code_entry(1, "gml_Object_obj_a_Create_0", "cited_test", True),
            code_entry(2, "gml_Object_obj_a_Step_0", "structural", False),
            code_entry(3, "gml_Object_obj_b_Create_0", "cited_contract", True),
        ])
        bundle = [obj(1, "obj_a", [1, 2]), obj(2, "obj_b", [3])]
        m = aom.build_matrix(census, bundle)
        t = m["totals"]
        self.assertEqual(t["objects"], 2)
        self.assertEqual(t["object_codes"], 3)
        self.assertEqual(t["executed"], 2)
        self.assertEqual(t["objects_with_unexecuted"], 1)
        self.assertEqual(t["total_codes"], 3)


class RenderTests(unittest.TestCase):
    def _matrix(self) -> dict:
        census = census_of([
            code_entry(1, "gml_Object_obj_a_Create_0", "cited_test", True),
            code_entry(2, "gml_Object_obj_a_Step_0", "object_cited_contract", False),
            code_entry(9, "gml_RoomCC_rm_x_1_Create", "structural", True),
        ])
        return aom.build_matrix(census, [obj(1, "obj_a", [1, 2])])

    def test_boundaries_and_marker_present(self):
        text = aom.render_markdown(self._matrix())
        self.assertIn(aom.MARKER, text)
        self.assertIn("not behavioural equivalence", text)
        self.assertIn("frozen 2026-09", text)
        self.assertIn("Still unexecuted", text)
        self.assertIn("| `obj_a` |", text)

    def test_render_is_deterministic(self):
        m = self._matrix()
        self.assertEqual(aom.render_markdown(m), aom.render_markdown(m))


class GeneratedGuardTests(unittest.TestCase):
    """Any generated report is skipped as a citation source, whichever script
    wrote it; a handwritten file is not."""

    def _write(self, text: str) -> str:
        fd, path = tempfile.mkstemp(suffix=".md")
        with os.fdopen(fd, "w", encoding="utf-8") as fh:
            fh.write(text)
        self.addCleanup(os.unlink, path)
        return path

    def test_census_report_is_skipped(self):
        path = self._write("Generated by `scripts/audit_semantic_coverage.py`. Do not hand-edit.\n")
        self.assertTrue(asc.is_generated(path))

    def test_object_matrix_is_skipped(self):
        path = self._write(aom.MARKER + "\nobj_alpha CODE 123\n")
        self.assertTrue(asc.is_generated(path))

    def test_handwritten_contract_is_not_skipped(self):
        path = self._write("# A contract mentioning obj_alpha CODE 123\n")
        self.assertFalse(asc.is_generated(path))


if __name__ == "__main__":
    unittest.main(verbosity=2)
