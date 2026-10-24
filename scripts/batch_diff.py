#!/usr/bin/env python3
"""Run every lowered CODE body through both implementations and classify.

    python3 scripts/batch_diff.py --c-bin c-recon/build/state_dump \
        --work .hermes-batch

Both sides read the same fixture file, so a difference is a bug in the
generator, the C host, or the Rust example — never a fixture artefact.

Classes:
  identical   both ran, byte-equal dumps
  differ      both ran, dumps differ            <- the only ones that matter
  vm_reject   the VM refused the body (unknown builtin, bad receiver...)
  c_only      the VM refused but the C host ran the body to completion
  c_fail      the C driver exited non-zero
"""
import argparse
import json
import os
import re
import subprocess
import sys
from pathlib import Path

ROOM = "ROOMW 1024\nROOMH 768\n"


def c_implemented(sources=("c-recon/src/host.c", "c-recon/src/builtins2.c")):
    """Builtins the C host answers. A body that calls anything else is a host
    gap, not a divergence — reporting it as `differ` would hide real bugs."""
    names = set()
    for src in sources:
        text = Path(src).read_text()
        names |= set(re.findall(r'strcmp\(name, "([A-Za-z_][A-Za-z0-9_]*)"\)', text))
        # the ext file also matches with !strcmp
        names |= set(re.findall(r'strncmp\(name, "([A-Za-z_][A-Za-z0-9_]*)"', text))
        for m in re.finditer(r'!strcmp\(name, "([A-Za-z_][A-Za-z0-9_]*)"\)', text):
            names.add(m.group(1))
    # Namespace families answered by one strncmp branch: return them apart so
    # the caller can match by prefix instead of looking for a literal "draw_*".
    prefixes = tuple(m.group(1) for m in
                     re.finditer(r'!strncmp\(name, "([a-z_]+)", \d+\)', Path(sources[1]).read_text()))
    return names, prefixes


def calls_of(bundle):
    out = {}
    for c in bundle["codes"]:
        out[c["id"]] = {i["name"] for i in c["instructions"] if i["op"] == "call"}
    return out


def owners(bundle):
    own = {}
    for o in bundle["objects"]:
        for e in o["events"]:
            for c in e.get("codes", []):
                own.setdefault(c, o["id"])
    return own


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--ir", default="crates/core/src/generated/full_ir.json")
    ap.add_argument("--asset", default="assets/game.droid")
    ap.add_argument("--c-bin", default="c-recon/build/state_dump")
    ap.add_argument("--work", default=".hermes-batch")
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--only", default="", help="comma separated code ids")
    ap.add_argument("--code-file", default="", help="file with one code id per line")
    args = ap.parse_args()

    bundle = json.load(open(args.ir))
    own = owners(bundle)
    c_impl, c_prefixes = c_implemented()
    body_calls = calls_of(bundle)
    codes = [c["id"] for c in bundle["codes"]]
    if args.code_file:
        wanted = {int(x) for x in Path(args.code_file).read_text().split() if x.strip()}
        codes = [c for c in codes if c in wanted]
    if args.only:
        wanted = {int(x) for x in args.only.split(",") if x.strip()}
        codes = [c for c in codes if c in wanted]
    if args.limit:
        codes = codes[: args.limit]

    work = Path(args.work)
    fx = work / "fixtures"
    rout = work / "rust"
    cout = work / "c"
    for d in (fx, rout, cout):
        d.mkdir(parents=True, exist_ok=True)

    # RoomCC bodies (551 of them) belong to a room, not an object. They still
    # need a `self` anchor, so give them the player object: the body itself is
    # room-creation code and does not read player fields unless it means to.
    missing_owner = [c for c in codes if c not in own]
    for c in missing_owner:
        own[c] = 0
    with open(work / "codes.txt", "w") as f:
        for c in codes:
            f.write(f"{c} {fx / f'{c}.txt'}\n")

    for c in codes:
        obj = own.get(c, -1)
        # A minimal world: the owning object plus the player. Most Step bodies
        # read obj_player fields directly, and the VM refuses a body whose
        # receiver does not exist, so without a player the corpus would measure
        # the fixture rather than the lowering.
        lines = [f"CODE {c}", "ROOMW 1024", "ROOMH 768",
                 f"INST 100000 {obj} 1"]
        if obj != 0:
            lines.append("INST 100001 0 1")
            lines.append("FIELD 100001 sprite_index 29")
            lines.append("FIELD 100001 x 500")
            lines.append("FIELD 100001 y 200")
        lines.append("CURRENT 100000")
        (fx / f"{c}.txt").write_text("\n".join(lines) + "\n")

    env = dict(os.environ, CARGO_TARGET_DIR=os.path.expanduser("~/callys-caves-2-rs/target"))
    print(f"[batch] {len(codes)} bodies, {len(missing_owner)} without an owning object", flush=True)
    r = subprocess.run(
        ["cargo", "run", "-q", "--profile", "ci-test", "-p", "callys-core",
         "--example", "ir_state_dump", "--",
         "--ir", args.ir, "--codes", str(work / "codes.txt"),
         "--outdir", str(rout), "--asset", args.asset],
        capture_output=True, text=True, env=env)
    if r.returncode != 0:
        print(r.stderr[-3000:], file=sys.stderr)
        return 2

    classes = {"identical": [], "differ": [], "c_gap": [], "vm_reject": [], "c_only": [], "c_fail": [], "not_built": []}
    detail = {}
    for c in codes:
        rf = rout / f"{c}.txt"
        rust = rf.read_text() if rf.exists() else "MISSING"
        cf = cout / f"{c}.txt"
        p = subprocess.run([args.c_bin, str(fx / f"{c}.txt"), str(cf)],
                           capture_output=True, text=True)
        if p.returncode in (3, 4):
            classes["not_built"].append(c)
            continue
        if p.returncode != 0:
            classes["c_fail"].append(c)
            detail[c] = (p.stderr or "").strip()[:200]
            continue
        ctext = cf.read_text() if cf.exists() else "MISSING"
        if rust.startswith("ERROR"):
            classes["c_only"].append(c)
            continue
        if rust == "MISSING":
            classes["vm_reject"].append(c)
            continue
        gap = {n for n in body_calls.get(c, set())
               if n not in c_impl and not n.startswith(c_prefixes)}
        if gap:
            classes["c_gap"].append(c)
            detail[c] = "missing builtin(s): " + ", ".join(sorted(gap))[:200]
            continue
        if rust == ctext:
            classes["identical"].append(c)
        else:
            classes["differ"].append(c)
            rl, cl = rust.splitlines(), ctext.splitlines()
            first = next((f"rust={a!r} c={b!r}" for a, b in zip(rl, cl) if a != b),
                         f"len rust={len(rl)} c={len(cl)}")
            detail[c] = first[:240]

    total = sum(len(v) for v in classes.values())
    print(f"\n=== {total} bodies ===")
    for k in ("identical", "differ", "c_gap", "c_only", "vm_reject", "c_fail", "not_built"):
        print(f"{k:>10}: {len(classes[k])}")
    if missing_owner:
        print(f"no owner : {len(missing_owner)} (skipped)")

    with open(work / "differ.tsv", "w") as f:
        for c in classes["differ"]:
            f.write(f"{c}\t{detail.get(c, '')}\n")
    with open(work / "c_fail.tsv", "w") as f:
        for c in classes["c_fail"]:
            f.write(f"{c}\t{detail.get(c, '')}\n")

    print("\n-- first 15 differ --")
    for c in classes["differ"][:15]:
        print(f"{c:>6}  {detail.get(c, '')}")
    print("\n-- first 10 c_fail --")
    for c in classes["c_fail"][:10]:
        print(f"{c:>6}  {detail.get(c, '')}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
