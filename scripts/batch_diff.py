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


def create_codes(bundle):
    """object id -> its Create body, so a fixture can run Create before the body
    under test. A Step that reads what Create wrote is the normal case; running
    it on an uninitialised instance measures the fixture, not the lowering."""
    out = {}
    for o in bundle["objects"]:
        for e in o["events"]:
            if e["event_type"] == 0 and e["subtype"] == 0 and e["codes"]:
                out[o["id"]] = e["codes"][0]
    return out


def owners(bundle):
    own = {}
    for o in bundle["objects"]:
        for e in o["events"]:
            for c in e.get("codes", []):
                own.setdefault(c, o["id"])
    return own


def build_c(work: Path) -> Path:
    """Generate every body and compile one corpus driver into `work`.

    Takes ~25 s on the phone (8-way parallel clang). Generated C stays in the
    work dir: `c-recon/gen` only carries the bodies the checked-in fixtures
    need, and dumping 1352 more files there would dirty the tree.
    """
    gen, obj = work / "gen", work / "obj"
    gen.mkdir(parents=True, exist_ok=True)
    obj.mkdir(parents=True, exist_ok=True)
    bundle = "crates/core/src/generated/full_ir.json"
    subprocess.run([sys.executable, "scripts/ir_to_c.py", "--ir", bundle,
                    "--all", "--outdir", str(gen)], check=True)
    subprocess.run([sys.executable, "scripts/gen_registry.py", "--gen", str(gen),
                    "--out", str(gen / "registry.c")], check=True)
    srcs = [f"c-recon/src/{n}.c" for n in
            ("main", "host", "collision", "objects", "builtins2")]
    srcs += [str(gen / "registry.c"), "c-recon/gen/objects_data.c",
             "c-recon/gen/sprites.c"]
    srcs += [str(p) for p in sorted(gen.glob("gml_*.c"))]
    common = ["clang", "-std=c11", "-O2", "-ffp-contract=off", "-w",
              "-I", "c-recon/include", "-c"]
    procs = []
    for src in srcs:
        while len(procs) >= 8:
            if procs.pop(0).wait() != 0:
                raise SystemExit(f"compile failed: {src}")
        procs.append(subprocess.Popen(common + [src, "-o", str(obj / (Path(src).stem + ".o"))]))
    while procs:
        if procs.pop(0).wait() != 0:
            raise SystemExit("compile failed")
    binary = work / "state_dump"
    subprocess.run(["clang", "-o", str(binary), *[str(p) for p in sorted(obj.glob("*.o"))],
                    "-lm"], check=True)
    return binary


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--ir", default="crates/core/src/generated/full_ir.json")
    ap.add_argument("--asset", default="assets/game.droid")
    ap.add_argument("--c-bin", default="c-recon/build/state_dump")
    ap.add_argument("--build-c", action="store_true",
                    help="regenerate + compile every body into --work (~25 s)")
    ap.add_argument("--rust-bin", default="",
                    help="existing ir_state_dump binary; skips the cargo check")
    ap.add_argument("--work", default=".hermes-batch")
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--only", default="", help="comma separated code ids")
    ap.add_argument("--code-file", default="", help="file with one code id per line")
    ap.add_argument("--matrix", action="store_true", help="run each body under several fixtures")
    ap.add_argument("--sequence", action="store_true",
                    help="run the owner's Create event before the body")
    ap.add_argument("--ticks", type=int, default=0,
                    help="append N scheduler ticks after the sequence")
    args = ap.parse_args()

    bundle = json.load(open(args.ir))
    own = owners(bundle)
    c_impl, c_prefixes = c_implemented()
    creates = create_codes(bundle)
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
    if args.build_c:
        args.c_bin = str(build_c(work))
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

    # Fixture variants: one body, several worlds. A single fixture leaves every
    # branch that depends on position, scale, angle, liveness or a global
    # untouched, so "identical" would only mean "the same path ran twice".
    variants = [("v0", [])]
    if args.matrix:
        both = lambda k, v: [(100000, k, v), (100001, k, v)]
        variants = [
            ("v0", []),
            ("v1", both("x", 0) + both("y", 0)),
            ("v2", both("x", 1023) + both("y", 767)),
            ("v3", both("x", -5) + both("y", -5)),
            ("v4", both("image_xscale", -1) + both("image_yscale", -1) + both("image_angle", 90)),
            ("v5", [(100000, "alive", 0)]),
            ("v6", [(100000, "active", 0)]),
            ("v7", [(100000, "hsp", -3), (100000, "vsp", 2), (100000, "facing", 1)]),
            # Walls and neighbours: nothing above ever puts a solid in the room,
            # so place_meeting / instance_place / mp_potential_step all took the
            # "no obstacle" branch.
            ("v8", [(100002, "obj", 34), (100002, "x", 512), (100002, "y", 200)]),
            ("v9", [(100002, "obj", 34), (100002, "x", 502), (100002, "y", 200),
                    (100003, "obj", 34), (100003, "x", 512), (100003, "y", 210)]),
            # A second instance of the same object: `with` must hit both, and
            # first-match collision must take the lowest id.
            ("v10", [("__sameobj__", 100002, None)]),
            # No sprite: the box degenerates to an integer point.
            ("v11", [(100000, "sprite_index", -1), (100001, "sprite_index", -1)]),
            # Rotation with a non-unit scale.
            ("v12", both("image_angle", 45) + both("image_xscale", 2) + both("image_yscale", 2)),
            # Small room: room_width/room_height clamps change branch.
            ("v13", [("__room__", "ROOMW", 320), ("__room__", "ROOMH", 240)]),
            # Globals that gate damage, audio and progression.
            ("v14", [("__global__", "health1", 0), ("__global__", "maxhp", 4),
                     ("__global__", "soundmute", 1), ("__global__", "rebuff", 1),
                     ("__global__", "level", 5), ("__global__", "experience", 99),
                     ("__global__", "xptolevelup", 30), ("__global__", "score", 7)]),
            # Far outside the room in both axes.
            ("v15", both("x", 10000) + both("y", 10000)),
            # Different RNG seeds: random_range picks other values, so the
            # branches behind them actually run.
            ("v16", [("__seed__", 12345, 0)]),
            ("v17", [("__seed__", 999999999, 0)]),
        ]

    fixtures = []   # (code, path)
    for c in codes:
        obj = own.get(c, -1)
        # A minimal world: the owning object plus the player. Most Step bodies
        # read obj_player fields directly, and the VM refuses a body whose
        # receiver does not exist, so without a player the corpus would measure
        # the fixture rather than the lowering.
        # A sequence runs Create first; a single CODE line remains the default
        # so existing fixtures keep their meaning.
        head = [f"CODE {c}"]
        ccode = creates.get(obj)
        if args.sequence and ccode is not None and ccode != c:
            head = [f"RUN {ccode} 100000", f"RUN {c} 100000"]
        if args.ticks:
            head = head + [f"TICK {args.ticks}"]
        lines = head + ["ROOMW {ROOMW}", "ROOMH {ROOMH}", f"INST 100000 {obj} 1"]
        if obj != 0:
            lines.append("INST 100001 0 1")
            lines.append("FIELD 100001 sprite_index 29")
            lines.append("FIELD 100001 x 500")
            lines.append("FIELD 100001 y 200")
        lines.append("CURRENT 100000")
        base = list(lines)
        for name, extra in variants:
            body = list(base)
            room = dict(ROOMW=1024, ROOMH=768)
            for (iid, key, val) in extra:
                if iid == "__room__":
                    room[key] = val
                elif iid == "__seed__":
                    body.append(f"SEED {key}")
                elif iid == "__sameobj__":
                    body.append(f"INST {key} {obj} 1")
                elif iid == "__global__":
                    body.append(f"GLOBAL {key} {val}")
                elif key == "obj":
                    body.append(f"INST {iid} {val} 1")
                else:
                    body.append(f"FIELD {iid} {key} {val}")
            text = "\n".join(body) + "\n"
            text = text.replace("{ROOMW}", str(room["ROOMW"])).replace("{ROOMH}", str(room["ROOMH"]))
            p = fx / f"{c}.{name}.txt"
            p.write_text(text)
            fixtures.append((c, p))

    with open(work / "codes.txt", "w") as f:
        for (c, p) in fixtures:
            f.write(f"{c} {p}\n")

    env = dict(os.environ, CARGO_TARGET_DIR=os.path.expanduser("~/callys-caves-2-rs/target"))
    print(f"[batch] {len(codes)} bodies, {len(missing_owner)} without an owning object", flush=True)
    base = ([args.rust_bin] if args.rust_bin else
            ["cargo", "run", "-q", "--profile", "ci-test", "-p", "callys-core",
             "--example", "ir_state_dump", "--"])
    r = subprocess.run(
        base + ["--ir", args.ir, "--codes", str(work / "codes.txt"),
                "--outdir", str(rout), "--asset", args.asset],
        capture_output=True, text=True, env=env)
    if r.returncode != 0:
        print(r.stderr[-3000:], file=sys.stderr)
        return 2

    # One C process for the whole corpus. Starting the driver per fixture costs
    # ~9 ms each, which is nothing for 30 bodies and dominant for a 24k-fixture
    # matrix; the corpus mode re-inits the engine per body, so isolation holds.
    cproc = subprocess.run([args.c_bin, "--codes", str(work / "codes.txt"),
                            "--outdir", str(cout)], capture_output=True, text=True)
    if cproc.returncode != 0:
        print(cproc.stderr[-3000:], file=sys.stderr)
        return 2

    classes = {"identical": [], "differ": [], "c_gap": [], "vm_reject": [], "c_only": [], "c_fail": [], "not_built": []}
    detail = {}
    for (c, p) in fixtures:
        rf = rout / f"{p.stem}.txt"
        rust = rf.read_text() if rf.exists() else "MISSING"
        cf = cout / f"{p.stem}.txt"
        ctext = cf.read_text() if cf.exists() else "MISSING"
        if ctext.startswith(("C_NO_BODY", "C_MISSING_BODY")):
            classes["not_built"].append(c)
            continue
        if ctext.startswith(("C_FIXTURE_ERROR", "C_FAIL")) or ctext == "MISSING":
            classes["c_fail"].append(c)
            detail[c] = ctext.strip()[:200]
            continue
        # The VM names the body and bytecode offset on a nested failure; the C
        # side has the body but no instruction site, so drop both.
        strip = lambda t: re.sub(r"\s*@0x[0-9a-f]+| offset=\d+", "", t)
        if rust.startswith("ERROR"):
            # Both sides can refuse the same body for the same reason; that is
            # agreement, not a gap. Only a different outcome is interesting.
            if strip(rust) == strip(ctext):
                classes["identical"].append(c)
            else:
                classes["c_only"].append(c)
                detail[c] = f"vm={rust.strip()!r} c={ctext.strip()[:120]!r}"
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
        # The VM appends the bytecode offset to its error; the C side has no
        # per-instruction site, so compare the message itself.
        if strip(rust) == strip(ctext):
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
    with open(work / "c_only.tsv", "w") as f:
        for c in classes["c_only"]:
            f.write(f"{c}\t{detail.get(c, '')}\n")
    with open(work / "c_fail.tsv", "w") as f:
        for c in classes["c_fail"]:
            f.write(f"{c}\t{detail.get(c, '')}\n")

    print("\n-- first 15 differ --")
    for c in classes["differ"][:15]:
        print(f"{c:>6}  {detail.get(c, '')}")
    print("\n-- first 15 c_only --")
    for c in classes["c_only"][:15]:
        print(f"{c:>6}  {detail.get(c, '')}")
    print("\n-- first 10 c_fail --")
    for c in classes["c_fail"][:10]:
        print(f"{c:>6}  {detail.get(c, '')}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
