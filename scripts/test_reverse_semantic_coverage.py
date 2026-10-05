"""Semantic-coverage census contracts (fixtures, no original asset needed)."""
import os
import tempfile
import unittest

from audit_semantic_coverage import (
    LEDGER_COLUMNS,
    build_census,
    name_kind,
    object_of,
    read_ledger,
    render_markdown,
)


def ledger_text(rows):
    lines = ["\t".join(LEDGER_COLUMNS)]
    for row in rows:
        lines.append("\t".join(str(row[c]) for c in LEDGER_COLUMNS))
    return "\n".join(lines) + "\n"


def row(code_id, name, env=0, constant="false", behavior="no", stack="unknown"):
    return {"code_id": code_id, "name": name, "indexed": "yes", "disassembled": "yes",
            "structural_cfg": "yes", "constant_only_body": constant,
            "environment_ops_pending": env, "stack_semantics": stack,
            "behavior_verified": behavior}


def write(path, text):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", encoding="utf-8") as fh:
        fh.write(text)


class LedgerTests(unittest.TestCase):
    def test_missing_column_is_fatal(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = os.path.join(tmp, "progress.tsv")
            write(path, "code_id\tname\tindexed\n0\tx\tyes\n")
            with self.assertRaises(SystemExit):
                read_ledger(path)

    def test_ragged_row_is_fatal(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = os.path.join(tmp, "progress.tsv")
            write(path, "\t".join(LEDGER_COLUMNS) + "\n0\tname\n")
            with self.assertRaises(SystemExit):
                read_ledger(path)

    def test_reads_all_rows(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = os.path.join(tmp, "progress.tsv")
            write(path, ledger_text([row(0, "gml_Object_obj_player_Create_0"),
                                     row(1, "gml_Object_obj_bat_Step_0", env=4)]))
            rows = read_ledger(path)
            self.assertEqual([r["code_id"] for r in rows], ["0", "1"])
            self.assertEqual(rows[1]["environment_ops_pending"], "4")


class CensusTests(unittest.TestCase):
    """The tier a CODE gets must come from re-readable evidence, not the frozen columns."""

    def census(self, tmp, rows, *, contract="", test="", src=""):
        write(os.path.join(tmp, "reconstruction", "contracts", "fixture.md"), contract)
        write(os.path.join(tmp, "crates", "core", "tests", "fixture.rs"), test)
        write(os.path.join(tmp, "crates", "core", "src", "fixture.rs"), src)
        os.makedirs(os.path.join(tmp, "crates", "client", "tests"), exist_ok=True)
        ledger = os.path.join(tmp, "progress.tsv")
        write(ledger, ledger_text(rows))
        return build_census(tmp, ledger)

    def test_tier_promotion_by_citation(self):
        with tempfile.TemporaryDirectory() as tmp:
            census = self.census(
                tmp,
                [row(1, "gml_Object_obj_a_Step_0"),
                 row(7, "gml_Object_obj_b_Step_0"),
                 row(9, "gml_Object_obj_c_Step_0"),
                 row(42, "gml_Object_obj_d_Step_0")],
                contract="see CODE 42 for the panel\n",
                test="// CODE 7 drives the alarm ladder\n",
                src="// code_id = 9 is the door card\n",
            )
            tiers = {c["code_id"]: c["tier"] for c in census["codes"].values()}
            self.assertEqual(tiers[1], "structural")
            self.assertEqual(tiers[7], "cited_test")
            self.assertEqual(tiers[9], "cited_src")
            self.assertEqual(tiers[42], "cited_contract")

    def test_env_pending_outranks_object_name_citation(self):
        """A dedicated with()/environment contract outranks a bare object mention."""
        with tempfile.TemporaryDirectory() as tmp:
            census = self.census(
                tmp,
                [row(3, "gml_Object_obj_boss2_Alarm_0", env=170)],
                contract="// obj_boss2 is mentioned here\n",
            )
            code = census["codes"][3]
            self.assertEqual(code["tier"], "env_classified")
            self.assertEqual(census["env_scope"]["codes"], 1)
            self.assertEqual(census["env_scope"]["sites"], 170)

    def test_frozen_behavior_column_is_reported_and_ignored(self):
        """behavior_verified=yes must NOT promote a CODE; the column is not trusted."""
        with tempfile.TemporaryDirectory() as tmp:
            census = self.census(tmp, [row(5, "gml_Object_obj_x_Step_0", behavior="yes")])
            self.assertEqual(census["codes"][5]["tier"], "structural")
            self.assertEqual(census["frozen_columns"]["behavior_verified"], {"yes": 1})
            text = render_markdown(census)
            self.assertIn("behavior_verified", text)
            self.assertIn("not a", text)

    def test_test_citation_does_not_promote_its_object_sibling(self):
        with tempfile.TemporaryDirectory() as tmp:
            census = self.census(
                tmp,
                [row(11, "gml_Object_obj_same_Step_0"), row(12, "gml_Object_obj_same_Draw_0")],
                test="// obj_same is exercised here, CODE 11 is the step\n",
            )
            tiers = {c["code_id"]: c["tier"] for c in census["codes"].values()}
            # The object-name citation must NOT promote a sibling body to the
            # numeric tier; it lands in the weaker object_cited_* tier instead.
            self.assertEqual(tiers[11], "cited_test")
            self.assertEqual(tiers[12], "object_cited_test")

    def test_object_name_citation_is_a_weaker_tier_than_number_citation(self):
        with tempfile.TemporaryDirectory() as tmp:
            census = self.census(
                tmp,
                [row(50, "gml_Object_obj_named_Step_0"), row(51, "gml_Object_obj_named_Alarm_0"),
                 row(52, "gml_Object_obj_other_Step_0")],
                test="// obj_named is covered by an object-level suite\n",
            )
            tiers = {c["code_id"]: c["tier"] for c in census["codes"].values()}
            self.assertEqual(tiers[50], "object_cited_test")
            self.assertEqual(tiers[51], "object_cited_test")
            self.assertEqual(tiers[52], "structural")
            text = render_markdown(census)
            self.assertIn("object_cited_test", text)

    def test_objects_and_worklist_render(self):
        with tempfile.TemporaryDirectory() as tmp:
            census = self.census(
                tmp,
                [row(20, "gml_Object_obj_solo_Step_0"), row(21, "gml_Object_obj_solo_Alarm_0")],
            )
            self.assertEqual(census["object_evidence"]["obj_solo"]["codes"], 2)
            text = render_markdown(census)
            self.assertIn("obj_solo", text)
            self.assertIn("2 CODE bodies", text)


class SelfReferenceTests(unittest.TestCase):
    """The census must not read its own generated report as evidence."""

    def test_generated_report_is_skipped(self):
        with tempfile.TemporaryDirectory() as tmp:
            os.makedirs(os.path.join(tmp, "crates", "core", "tests"), exist_ok=True)
            os.makedirs(os.path.join(tmp, "crates", "core", "src"), exist_ok=True)
            contracts = os.path.join(tmp, "reconstruction", "contracts")
            os.makedirs(contracts, exist_ok=True)
            # A hand-written contract names the object: that is evidence.
            write(os.path.join(contracts, "real.md"), "// obj_alpha is analysed here\n")
            # A generated report names another object: that must NOT count.
            write(os.path.join(contracts, "generated.md"),
                  "Generated by `scripts/audit_semantic_coverage.py`. Do not hand-edit.\n"
                  "| object | uncited |\n| --- | --- |\n| `obj_beta` | 3 |\n")
            ledger = os.path.join(tmp, "progress.tsv")
            write(ledger, ledger_text([row(60, "gml_Object_obj_alpha_Step_0"),
                                       row(61, "gml_Object_obj_beta_Step_0")]))
            census = build_census(tmp, ledger)
            tiers = {c["code_id"]: c["tier"] for c in census["codes"].values()}
            self.assertEqual(tiers[60], "object_cited_contract")
            self.assertEqual(tiers[61], "structural",
                             "a generated report must not cite its own worklist objects")
            self.assertEqual(census["citation_sources"]["contract"]["files"], 1)


class NameTests(unittest.TestCase):
    def test_object_of(self):
        self.assertEqual(object_of("gml_Object_obj_boss2_Alarm_0"), "obj_boss2")
        self.assertEqual(object_of("gml_Object_obj_viewresolution_Draw_65"), "obj_viewresolution")

    def test_room_and_script_bodies_are_not_objects(self):
        """Room/script containers must not inflate the object census."""
        self.assertEqual(object_of("gml_RoomCC_rm_town_1_Create"), "")
        self.assertEqual(object_of("gml_Script_scr_foo"), "")
        self.assertEqual(object_of("gml_Room_rm_town_Create"), "")
        self.assertEqual(name_kind("gml_Object_obj_a_Step_0"), "Object")
        self.assertEqual(name_kind("gml_RoomCC_rm_town_1_Create"), "RoomCC")
        self.assertEqual(name_kind("gml_Script_scr_foo"), "Script")
        self.assertEqual(name_kind("gml_Font_fnt_x"), "other")

    def test_room_bodies_are_counted_separately_from_objects(self):
        with tempfile.TemporaryDirectory() as tmp:
            os.makedirs(os.path.join(tmp, "crates", "core", "tests"), exist_ok=True)
            os.makedirs(os.path.join(tmp, "crates", "core", "src"), exist_ok=True)
            os.makedirs(os.path.join(tmp, "reconstruction", "contracts"), exist_ok=True)
            ledger = os.path.join(tmp, "progress.tsv")
            write(ledger, ledger_text([row(30, "gml_Object_obj_a_Step_0"),
                                       row(31, "gml_RoomCC_rm_town_1_Create"),
                                       row(32, "gml_Script_scr_foo")]))
            census = build_census(tmp, ledger)
            self.assertEqual(sorted(census["object_evidence"]), ["obj_a"])
            self.assertEqual(census["kind_counts"]["RoomCC"], 1)
            self.assertEqual(census["kind_counts"]["Script"], 1)


if __name__ == "__main__":
    unittest.main()
