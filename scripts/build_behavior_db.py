#!/usr/bin/env python3
"""Build the behaviour DB: facts from the shipped IR, cards from hand-written JSON.

Facts are derived and reproducible (delete the .db, rerun, same rows).
Cards are claims: each one must carry a tier, an anchor and (when host_authored)
an explicit original_gap, or the build fails.

Usage:
  python3 scripts/build_behavior_db.py \
      --ir crates/core/src/generated/full_ir.json \
      --cards reconstruction/db/cards \
      --schema reconstruction/db/schema.sql \
      --out reconstruction/db/cally.db
"""
from __future__ import annotations

import argparse
import glob
import json
import os
import sqlite3
import sys

TIERS = {
    "bytecode_anchored",
    "oracle_anchored",
    "device_anchored",
    "test_anchored",
    "host_authored",
    "unverified",
}
EVIDENCE_KINDS = {"bytecode", "oracle", "device", "test", "contract"}


def load_ir(path):
    with open(path, "r", encoding="utf-8") as fh:
        ir = json.load(fh)
    if ir.get("schema") != 1:
        raise SystemExit(f"unsupported IR schema: {ir.get('schema')!r}")
    return ir


def code_owners(ir):
    """code_id -> (object_id, event_type, subtype). RoomCC codes stay NULL."""
    owner = {}
    for obj in ir["objects"]:
        for ev in obj.get("events", []):
            for cid in ev.get("codes", []):
                owner.setdefault(cid, (obj["id"], ev["event_type"], ev["subtype"]))
    return owner


def build_facts(conn, ir):
    owner = code_owners(ir)
    conn.executemany(
        "INSERT INTO fact_object(id,name,persistent,depth,sprite) VALUES(?,?,?,?,?)",
        [
            (o["id"], o["name"], int(bool(o.get("persistent"))), o.get("depth"), o.get("sprite"))
            for o in ir["objects"]
        ],
    )

    code_rows = []
    call_rows = []
    for code in ir["codes"]:
        cid = code["id"]
        obj_id, ev_type, subtype = owner.get(cid, (None, None, None))
        code_rows.append(
            (cid, obj_id, ev_type, subtype, len(code["instructions"]), code["sha256"], code["name"])
        )
        sites = {}
        for ins in code["instructions"]:
            if ins.get("op") == "call" and ins.get("name"):
                sites[ins["name"]] = sites.get(ins["name"], 0) + 1
        call_rows.extend((cid, name, n) for name, n in sites.items())

    conn.executemany(
        "INSERT INTO fact_code(id,owner_object,event_type,subtype,instructions,sha256,name)"
        " VALUES(?,?,?,?,?,?,?)",
        code_rows,
    )
    conn.executemany(
        "INSERT INTO fact_builtin_call(code_id,name,sites) VALUES(?,?,?)", call_rows
    )
    conn.executemany(
        "INSERT INTO fact_room_binding(id,room,code_id) VALUES(?,?,?)",
        # id is the RoomCC index (0..550), not the room id: one room can carry
        # several RoomCC instances, so room_id repeats.
        [(i, b["room_id"], b["code_id"]) for i, b in enumerate(ir["room_bindings"])],
    )
    return len(code_rows), len(call_rows), len(ir["room_bindings"])


def validate_card(card, path):
    errs = []
    cid = card.get("id", "")
    if not cid:
        errs.append("missing id")
    if card.get("tier") not in TIERS:
        errs.append(f"bad tier {card.get('tier')!r}")
    for key in ("title", "trigger", "preconditions", "effects", "anchor"):
        if not str(card.get(key, "")).strip():
            errs.append(f"empty {key}")
    if card.get("host_authored"):
        if not str(card.get("original_gap", "")).strip():
            errs.append("host_authored requires original_gap")
    if card.get("tier") in {"unverified", "host_authored"} and not str(
        card.get("original_gap", "")
    ).strip():
        errs.append(f"tier {card['tier']} requires original_gap")
    for ev in card.get("evidence", []):
        if ev.get("kind") not in EVIDENCE_KINDS:
            errs.append(f"bad evidence kind {ev.get('kind')!r}")
        if not str(ev.get("ref", "")).strip():
            errs.append("evidence without ref")
    if errs:
        raise SystemExit(f"{path}: " + "; ".join(errs))
    return cid


def build_cards(conn, cards_dir):
    paths = sorted(glob.glob(os.path.join(cards_dir, "*.json")))
    inserted = 0
    for path in paths:
        with open(path, "r", encoding="utf-8") as fh:
            card = json.load(fh)
        cid = validate_card(card, path)
        conn.execute(
            "INSERT INTO card(id,title,scope_object,scope_event,trigger,preconditions,effects,"
            "tier,host_authored,original_gap,anchor,notes)"
            " VALUES(?,?,?,?,?,?,?,?,?,?,?,?)",
            (
                cid,
                card["title"],
                card.get("scope_object"),
                card.get("scope_event"),
                card["trigger"],
                card["preconditions"],
                card["effects"],
                card["tier"],
                int(bool(card.get("host_authored"))),
                card.get("original_gap", ""),
                card["anchor"],
                card.get("notes"),
            ),
        )
        for code_id in card.get("codes", []):
            conn.execute("INSERT INTO card_code(card_id,code_id) VALUES(?,?)", (cid, code_id))
        for ev in card.get("evidence", []):
            conn.execute(
                "INSERT INTO card_evidence(card_id,kind,ref,note) VALUES(?,?,?,?)",
                (cid, ev["kind"], ev["ref"], ev.get("note")),
            )
        inserted += 1
    return inserted, len(paths)


def report(conn, ncodes, ncalls, nrooms, ncards, nfiles):
    q = conn.execute
    n_ir_codes = q("SELECT COUNT(*) FROM fact_code").fetchone()[0]
    n_ir_objs = q("SELECT COUNT(*) FROM fact_object").fetchone()[0]
    print(f"facts: objects={n_ir_objs} codes={n_ir_codes} builtin_call_rows={ncalls} room_bindings={nrooms}")
    print(f"cards: {ncards} (files scanned: {nfiles})")

    empty_owner = q("SELECT COUNT(*) FROM fact_code WHERE owner_object IS NULL").fetchone()[0]
    print(f"codes without owner_object (RoomCC expected 551): {empty_owner}")

    print("tier distribution:")
    rows = q("SELECT tier, COUNT(*) FROM card GROUP BY tier ORDER BY 2 DESC").fetchall()
    if not rows:
        print("  (no cards — any 'how far from the original' number is a claim, not data)")
    for tier, n in rows:
        print(f"  {tier:18s} {n}")

    print("top builtins by call sites:")
    for name, sites, codes in q(
        "SELECT name, SUM(sites) s, COUNT(DISTINCT code_id) c FROM fact_builtin_call"
        " GROUP BY name ORDER BY s DESC LIMIT 10"
    ):
        print(f"  {name:28s} sites={sites:6d} codes={codes}")

    # Integrity: every card_code must point at a real fact_code
    orphan = q(
        "SELECT COUNT(*) FROM card_code cc LEFT JOIN fact_code f ON f.id=cc.code_id"
        " WHERE f.id IS NULL"
    ).fetchone()[0]
    print(f"card_code rows pointing at unknown codes: {orphan}")
    return orphan


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--ir", default="crates/core/src/generated/full_ir.json")
    ap.add_argument("--cards", default="reconstruction/db/cards")
    ap.add_argument("--schema", default="reconstruction/db/schema.sql")
    ap.add_argument("--out", default="reconstruction/db/cally.db")
    args = ap.parse_args()

    ir = load_ir(args.ir)
    if os.path.exists(args.out):
        os.remove(args.out)
    conn = sqlite3.connect(args.out)
    conn.execute("PRAGMA foreign_keys = ON")
    with open(args.schema, "r", encoding="utf-8") as fh:
        conn.executescript(fh.read())

    ncodes, ncalls, nrooms = build_facts(conn, ir)
    ncards, nfiles = build_cards(conn, args.cards) if os.path.isdir(args.cards) else (0, 0)
    conn.commit()
    orphan = report(conn, ncodes, ncalls, nrooms, ncards, nfiles)
    conn.close()
    if orphan:
        sys.exit(2)


if __name__ == "__main__":
    main()
