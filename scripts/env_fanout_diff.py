#!/usr/bin/env python3
"""Fixture-driven C<->VM differential for the `with` / `instance_destroy` slice.

`batch_diff.py` builds one generic world per body (owning object + a player), so
the fixture it can express has exactly one instance of every other object. That
is enough to prove "the body ran", and not enough to prove the things the
environment slice is about: several targets in one `with`, a target that is
already retired, a target that is deactivated, the same body run twice, or a
`with` nested inside another `with`.

This runner replays hand-written scenarios instead. Each scenario is a state
file in `c-recon/fixtures/env` (protocol in `c-recon/src/main.c`), and must carry
a `<name>.expect` file listing dump lines that must be present (a line starting
with `!` asserts that no dump line starts with the rest). `COUNT_INST <object>
<count>` asserts the total number of instances of an object, so "exactly once"
cannot be reduced to checking one hand-picked instance id. The diff proves the
two implementations agree; the expectations prove the scenario actually walked
the path it was written for - a scenario that stops selecting its targets would
otherwise still diff clean, because both sides would be empty.

    # Default: rebuild the checked-in C driver and the current Rust example.
    python3 scripts/env_fanout_diff.py --work "$TMPDIR/env"
    # Generate every body, not only the checked-in fixtures.
    python3 scripts/env_fanout_diff.py --build-c --work "$TMPDIR/env"
    # Explicit caller-managed binaries are an opt-in fast path.
    python3 scripts/env_fanout_diff.py --c-bin c-recon/build/state_dump

Exit codes: 0 = every scenario identical and every expectation met,
1 = a difference or a missed expectation, 2 = harness failure.
"""
from __future__ import annotations

import argparse
import os
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
IR = ROOT / "crates/core/src/generated/full_ir.json"
ASSET = ROOT / "assets/game.droid"
FIXTURES = ROOT / "c-recon/fixtures/env"


def c_binary(work: Path) -> Path:
    """Generate + compile every body into `work` (reuses batch_diff's build)."""
    sys.path.insert(0, str(ROOT / "scripts"))
    import batch_diff  # noqa: E402  (path is set up above)

    return batch_diff.build_c(work)


def checked_in_c_binary(work: Path) -> Path:
    """Compile the current checked-in C sources; existence alone is not proof."""
    binary = work / "checked-in-state_dump"
    sources = [ROOT / "c-recon/src" / f"{name}.c" for name in
               ("main", "host", "collision", "objects", "builtins2", "rooms", "draw")]
    sources += [ROOT / "c-recon/gen/registry.c",
                ROOT / "c-recon/gen/objects_data.c",
                ROOT / "c-recon/gen/rooms_data.c",
                ROOT / "c-recon/gen/sprites.c"]
    sources += sorted((ROOT / "c-recon/gen").glob("gml_*.c"))
    subprocess.run(["clang", "-std=c11", "-O2", "-ffp-contract=off", "-w",
                    "-I", str(ROOT / "c-recon/include"),
                    *[str(path) for path in sources], "-o", str(binary), "-lm"],
                   cwd=ROOT, check=True)
    return binary


def rust_binary(explicit: str) -> Path:
    if explicit:
        path = Path(explicit).expanduser()
        if not path.is_file():
            raise SystemExit(f"rust binary not found: {path}")
        return path

    # An existing binary is not evidence that it was built from this ROOT.
    # Always let cargo rebuild the current example; only an explicit --rust-bin
    # opts into a caller-managed binary. Relative CARGO_TARGET_DIR follows
    # cargo's own cwd (the repository root).
    target = Path(os.environ.get("CARGO_TARGET_DIR", str(ROOT / "target"))).expanduser()
    if not target.is_absolute():
        target = ROOT / target
    env = dict(os.environ, CARGO_TARGET_DIR=str(target))
    subprocess.run(["cargo", "build", "-q", "--profile", "ci-test", "-p", "callys-core",
                    "--example", "ir_state_dump"], cwd=ROOT, env=env, check=True)
    built = target / "ci-test/examples/ir_state_dump"
    if not built.is_file():
        raise SystemExit(f"cargo build did not produce {built}")
    return built


def dump_lines(path: Path) -> list[str]:
    return path.read_text().splitlines()


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--fixtures", default=str(FIXTURES))
    ap.add_argument("--work", default="")
    ap.add_argument("--build-c", action="store_true", help="generate + compile every body in --work")
    ap.add_argument("--c-bin", default="", help="caller-managed C binary; default rebuilds checked-in C")
    ap.add_argument("--rust-bin", default="")
    ap.add_argument("--ir", default=str(IR))
    ap.add_argument("--asset", default=str(ASSET))
    ap.add_argument("--keep", action="store_true")
    args = ap.parse_args()
    if args.build_c and args.c_bin:
        ap.error("--build-c and --c-bin are mutually exclusive")

    fixtures = Path(args.fixtures)
    scenarios = sorted(fixtures.glob("*.txt"))
    if not scenarios:
        print(f"no fixtures in {fixtures}", file=sys.stderr)
        return 2

    work = Path(args.work) if args.work else ROOT / ".hermes-env"
    bins = work / "bins"
    bins.mkdir(parents=True, exist_ok=True)
    cout, rout = bins / "c", bins / "rust"
    cout.mkdir(exist_ok=True)
    rout.mkdir(exist_ok=True)

    if args.build_c:
        c_bin = c_binary(work)
    elif args.c_bin:
        c_bin = Path(args.c_bin).expanduser()
    else:
        c_bin = checked_in_c_binary(work)
    if not c_bin.is_file():
        print(f"missing C binary {c_bin} (see c-recon/README.md)", file=sys.stderr)
        return 2
    r_bin = rust_binary(args.rust_bin)

    identical = differ = failed = 0
    expect_total = expect_missing = 0
    details: list[str] = []

    for fixture in scenarios:
        c_out = cout / f"{fixture.stem}.txt"
        r_out = rout / f"{fixture.stem}.txt"
        pc = subprocess.run([str(c_bin), str(fixture), str(c_out)],
                            capture_output=True, text=True)
        if pc.returncode != 0:
            failed += 1
            details.append(f"{fixture.stem}: C driver rc={pc.returncode} {pc.stderr.strip()[:200]}")
            continue
        pr = subprocess.run([str(r_bin), "--ir", args.ir, "--state", str(fixture),
                             "--out", str(r_out), "--asset", args.asset],
                            capture_output=True, text=True)
        if pr.returncode != 0:
            failed += 1
            details.append(f"{fixture.stem}: VM rc={pr.returncode} {pr.stderr.strip()[:200]}")
            continue
        c_text = c_out.read_text()
        if c_text.startswith(("C_NO_BODY", "C_MISSING_BODY", "C_FIXTURE_ERROR", "C_FAIL")):
            failed += 1
            details.append(f"{fixture.stem}: C sentinel {c_text.strip()[:80]}")
            continue
        r_text = r_out.read_text()
        if r_text.startswith("ERROR") or c_text.startswith("ERROR"):
            # A scenario the two sides refuse differently is a difference; one
            # they both refuse the same way is not the path the fixture meant.
            failed += 1
            details.append(f"{fixture.stem}: unexpected abort vm={r_text.strip()[:80]!r} "
                           f"c={c_text.strip()[:80]!r}")
            continue
        if r_text != c_text:
            differ += 1
            rl, cl = r_text.splitlines(), c_text.splitlines()
            first = next((f"vm={a!r} c={b!r}" for a, b in zip(rl, cl) if a != b),
                         f"len vm={len(rl)} c={len(cl)}")
            details.append(f"{fixture.stem}: DIFFER {first[:200]}")
            continue
        identical += 1

        expect_file = fixture.with_suffix(".expect")
        if not expect_file.is_file():
            expect_total += 1
            expect_missing += 1
            details.append(f"{fixture.stem}: missing non-empty {expect_file.name}")
            continue
        dumped = dump_lines(c_out)
        text_lines = set(dumped)
        directives_before = expect_total
        for want in expect_file.read_text().splitlines():
                want = want.strip()
                if not want or want.startswith("#"):
                    continue
                expect_total += 1
                if want.startswith("COUNT_DRAW "):
                    parts = want.split()
                    try:
                        if len(parts) != 3:
                            raise ValueError("want COUNT_DRAW <SPRITE|TEXT|HEALTHBAR|BACKGROUND|ANY> <count>")
                        kind, expected_count = parts[1], int(parts[2])
                        if kind not in {"SPRITE", "TEXT", "HEALTHBAR", "BACKGROUND", "ANY"}:
                            raise ValueError("unknown draw queue")
                        if expected_count < 0:
                            raise ValueError("count must be non-negative")
                    except ValueError as exc:
                        expect_missing += 1
                        details.append(f"{fixture.stem}: invalid expectation {want!r}: {exc}")
                        continue
                    actual_count = sum(1 for line in dumped
                                       if (fields := line.split()) and fields[0] == "DRAW"
                                       and (kind == "ANY" or fields[2] == kind))
                    if actual_count != expected_count:
                        expect_missing += 1
                        details.append(f"{fixture.stem}: {kind} draw count "
                                       f"{actual_count}, want {expected_count}")
                elif want.startswith("COUNT_INST "):
                    parts = want.split()
                    try:
                        if len(parts) != 3:
                            raise ValueError("want COUNT_INST <object> <count>")
                        object_id, expected_count = int(parts[1]), int(parts[2])
                        if expected_count < 0:
                            raise ValueError("count must be non-negative")
                    except ValueError as exc:
                        expect_missing += 1
                        details.append(f"{fixture.stem}: invalid expectation {want!r}: {exc}")
                        continue
                    actual_count = 0
                    for line in dumped:
                        fields = line.split()
                        if len(fields) == 4 and fields[0] == "INST" and int(fields[2]) == object_id:
                            actual_count += 1
                    if actual_count != expected_count:
                        expect_missing += 1
                        details.append(f"{fixture.stem}: object {object_id} count "
                                       f"{actual_count}, want {expected_count}")
                elif want.startswith("!"):
                    # Absence assertion: nothing may start with the rest. Used
                    # for "the fan-out did not run again" (no extra puff) and
                    # for "the empty branch touched no kill counter".
                    prefix = want[1:].strip()
                    if any(line.startswith(prefix) for line in dumped):
                        expect_missing += 1
                        details.append(f"{fixture.stem}: unexpected line matching {prefix!r}")
                elif want not in text_lines:
                    expect_missing += 1
                    details.append(f"{fixture.stem}: missing expectation {want!r}")
        if expect_total == directives_before:
            expect_total += 1
            expect_missing += 1
            details.append(f"{fixture.stem}: empty expectation file {expect_file.name}")

    if not args.keep:
        for path in (cout, rout):
            for f in path.glob("*.txt"):
                f.unlink()

    print(f"[env] {len(scenarios)} scenarios: identical={identical} differ={differ} "
          f"failed={failed}")
    print(f"[env] expectations: {expect_total - expect_missing}/{expect_total} met")
    for line in details:
        print("  " + line)
    ok = differ == 0 and failed == 0 and expect_missing == 0
    print(f"[env] {'PASS' if ok else 'FAIL'}")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
