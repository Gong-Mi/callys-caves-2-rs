#!/usr/bin/env python3
"""Opcode differential comparator (milestone 1).

Runs both implementations once over the same JSONL case file and compares the
answers line by line:

    python3 diff/run_diff.py --c c-recon/build/opcode_diff \
                             --rust target/release/opcode_diff \
                             --cases diff/cases.jsonl

Compared fields, per `reconstruction/contracts/opcode-diff-protocol.md`:
    ok, sp, result.bytes, result.tag, error

Failure modes, all reported with case index + op + both full JSON lines + the
one-line input that reproduces it:
  * any of the five fields differs;
  * `id` is not echoed exactly;
  * a side emits fewer or more lines than there are cases (a missing line is a
    failure at the first index that runs out, never silently ignored);
  * a side emits a line that is not a protocol record (bad JSON, missing
    fields, non-32-hex bytes, non-boolean ok ...).

Exit codes:
    0  outputs identical
    1  differential failure (field/id/line/schema mismatch)
    2  harness error: bad arguments, missing or non-executable binary,
       unreadable/malformed cases file, timeout, or a side exiting non-zero

A missing binary is a hard error before either side runs: no partial results,
no synthesized output. That is deliberate — a comparator that invents a line is
worse than one that refuses to run.

Optional sidecar `<cases>.meta.json` (written by gen_cases.py) is used for two
advisory checks that never change the exit code on their own:
  * a case marked `expect: "error"` that both sides report as ok;
  * a case with an `error_hint` where both sides agree on a different string.
Both mean "the two implementations share a belief that the card contradicts",
which a pure two-way diff cannot see.
"""

from __future__ import annotations

import argparse
import json
import os
import subprocess
import sys
import tempfile
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any, Sequence

ABSENT = "<absent>"
TAGS = frozenset(range(15)) | {0x00FFFFFF}
HEX = frozenset("0123456789abcdefABCDEF")


# ------------------------------------------------------------- input --------

def fail(msg: str) -> int:
    print(f"run_diff: error: {msg}", file=sys.stderr)
    return 2


def load_cases(path: Path) -> list[dict]:
    raw = path.read_bytes()
    if not raw.strip():
        raise ValueError(f"cases file is empty: {path}")
    out: list[dict] = []
    for lineno, line in enumerate(raw.decode("utf-8").splitlines(), 1):
        if not line.strip():
            raise ValueError(f"{path}:{lineno}: blank line in a JSONL case file")
        try:
            obj = json.loads(line)
        except json.JSONDecodeError as exc:
            raise ValueError(f"{path}:{lineno}: not JSON: {exc}") from exc
        if not isinstance(obj, dict):
            raise ValueError(f"{path}:{lineno}: case is not an object")
        for key in ("id", "op", "mode", "type", "a", "b"):
            if key not in obj:
                raise ValueError(f"{path}:{lineno}: missing {key!r}")
        if not isinstance(obj["id"], int) or not isinstance(obj["mode"], int):
            raise ValueError(f"{path}:{lineno}: id/mode must be integers")
        if not isinstance(obj["type"], int) or not isinstance(obj["op"], str):
            raise ValueError(f"{path}:{lineno}: type/op have the wrong type")
        for side in ("a", "b"):
            rv = obj[side]
            if not isinstance(rv, dict) or "bytes" not in rv or "tag" not in rv:
                raise ValueError(f"{path}:{lineno}: {side} is not "
                                 "{bytes, tag}")
            data = rv["bytes"]
            if not isinstance(data, str) or len(data) != 32 \
                    or not set(data) <= HEX:
                raise ValueError(f"{path}:{lineno}: {side}.bytes is not "
                                 "32 hex chars")
            if not isinstance(rv["tag"], int) or rv["tag"] not in TAGS:
                raise ValueError(f"{path}:{lineno}: {side}.tag "
                                 f"{rv['tag']!r} outside 0..14/0x00FFFFFF")
        out.append(obj)
    return out


def load_meta(path: Path | None) -> dict[int, dict]:
    if path is None or not path.exists():
        return {}
    try:
        doc = json.loads(path.read_text(encoding="utf-8"))
        return {int(entry["id"]): entry for entry in doc.get("cases", [])}
    except (json.JSONDecodeError, KeyError, TypeError, ValueError):
        print(f"run_diff: warning: ignoring unreadable meta file {path}",
              file=sys.stderr)
        return {}


# ------------------------------------------------------------- running -----

@dataclass
class Side:
    name: str
    path: str
    returncode: int
    stdout: bytes
    stderr: str
    timed_out: bool = False

    @property
    def lines(self) -> list[str]:
        return self.stdout.decode("utf-8", "replace").splitlines()


def check_binary(path: Path | None, flag: str) -> str | None:
    if path is None:
        return f"{flag} was not given"
    if not path.exists():
        return f"{flag} binary does not exist: {path}"
    if path.is_dir():
        return f"{flag} path is a directory: {path}"
    if not os.access(path, os.X_OK):
        return f"{flag} binary is not executable: {path}"
    return None


def run_side(name: str, path: Path, cases_bytes: bytes, timeout: float) -> Side:
    with tempfile.TemporaryFile() as err_file:
        proc = subprocess.Popen(
            [str(path)], stdin=subprocess.PIPE, stdout=subprocess.PIPE,
            stderr=err_file)
        try:
            out, _ = proc.communicate(cases_bytes, timeout=timeout)
            timed_out = False
        except subprocess.TimeoutExpired:
            proc.kill()
            out, _ = proc.communicate()
            timed_out = True
        err_file.seek(0)
        err_text = err_file.read().decode("utf-8", "replace")
    return Side(name=name, path=str(path), returncode=proc.returncode,
                stdout=out, stderr=err_text, timed_out=timed_out)


# ---------------------------------------------------------- comparison -----

def parse_record(raw: str) -> tuple[dict | None, str | None]:
    text = raw.strip()
    if not text:
        return None, "blank output line"
    try:
        obj = json.loads(text)
    except json.JSONDecodeError as exc:
        return None, f"not JSON ({exc.msg})"
    if not isinstance(obj, dict):
        return None, "output line is not a JSON object"
    if not isinstance(obj.get("id"), int):
        return None, "missing/invalid id"
    ok = obj.get("ok")
    if not isinstance(ok, bool):
        return None, "missing/invalid ok (must be a JSON boolean)"
    if ok:
        sp = obj.get("sp")
        if not isinstance(sp, int):
            return None, "ok=true but sp is missing/not an integer"
        result = obj.get("result")
        if not isinstance(result, dict):
            return None, "ok=true but result is missing"
        data = result.get("bytes")
        if not isinstance(data, str) or len(data) != 32 \
                or not set(data) <= HEX:
            return None, "result.bytes is not 32 hex chars"
        tag = result.get("tag")
        if not isinstance(tag, int):
            return None, "result.tag is missing/not an integer"
    else:
        if not isinstance(obj.get("sp"), int):
            return None, "ok=false but sp is missing/not an integer"
        if not isinstance(obj.get("error"), str) or not obj["error"]:
            return None, "ok=false but error is missing/empty"
    return obj, None


def fields(record: dict | None) -> dict[str, Any]:
    if record is None:
        return {k: ABSENT for k in
                ("ok", "sp", "result.bytes", "result.tag", "error")}
    result = record.get("result")
    result = result if isinstance(result, dict) else {}
    error = record.get("error")
    data = result.get("bytes")
    return {
        "ok": record.get("ok", ABSENT),
        "sp": record.get("sp", ABSENT),
        "result.bytes": data.lower() if isinstance(data, str) else ABSENT,
        "result.tag": result.get("tag", ABSENT),
        "error": error if error not in (None, "") else ABSENT,
    }


FIELDS = ("ok", "sp", "result.bytes", "result.tag", "error")


@dataclass
class Problem:
    index: int
    case: dict
    c_raw: str | None
    r_raw: str | None
    c_rec: dict | None
    r_rec: dict | None
    reasons: list[str] = field(default_factory=list)
    diffs: dict[str, tuple[Any, Any]] = field(default_factory=dict)

    @property
    def op(self) -> str:
        return str(self.case.get("op", "?"))


@dataclass
class Outcome:
    cases: int
    c_lines: int
    r_lines: int
    problems: list[Problem]
    warnings: list[str]
    c: Side
    r: Side


def compare(cases: list[dict], c: Side, r: Side,
            meta: dict[int, dict]) -> Outcome:
    c_lines, r_lines = c.lines, r.lines
    problems: list[Problem] = []
    warnings: list[str] = []
    total_rows = max(len(c_lines), len(r_lines), len(cases))
    for i in range(total_rows):
        case = cases[i] if i < len(cases) else None
        c_raw = c_lines[i] if i < len(c_lines) else None
        r_raw = r_lines[i] if i < len(r_lines) else None
        reasons: list[str] = []
        extra_row = case is None
        if extra_row:
            reasons.append(f"extra output line beyond the {len(cases)} cases")
        elif c_raw is None:
            reasons.append("c: missing output line")
        if not extra_row and r_raw is None:
            reasons.append("rust: missing output line")

        c_rec, c_err = (None, None) if c_raw is None else parse_record(c_raw)
        r_rec, r_err = (None, None) if r_raw is None else parse_record(r_raw)
        if c_err:
            reasons.append(f"c: {c_err}")
        if r_err:
            reasons.append(f"rust: {r_err}")
        if case is not None:
            if c_rec is not None and c_rec.get("id") != case["id"]:
                reasons.append(f"c: echoed id {c_rec.get('id')!r}, "
                               f"case id is {case['id']}")
            if r_rec is not None and r_rec.get("id") != case["id"]:
                reasons.append(f"rust: echoed id {r_rec.get('id')!r}, "
                               f"case id is {case['id']}")

        diffs: dict[str, tuple[Any, Any]] = {}
        if c_rec is not None and r_rec is not None:
            cf, rf = fields(c_rec), fields(r_rec)
            for key in FIELDS:
                if cf[key] != rf[key]:
                    diffs[key] = (cf[key], rf[key])

        if reasons or diffs:
            problems.append(Problem(
                index=i,
                case=case if case is not None else {},
                c_raw=c_raw, r_raw=r_raw, c_rec=c_rec, r_rec=r_rec,
                reasons=reasons, diffs=diffs))

    # Advisory checks: a pure two-way diff cannot see a shared wrong belief.
    for i, case in enumerate(cases):
        info = meta.get(case["id"])
        if not info:
            continue
        c_rec = _record_at(c.lines, i)
        r_rec = _record_at(r.lines, i)
        if c_rec is None or r_rec is None:
            continue
        if info.get("expect") == "error" and c_rec.get("ok") and r_rec.get("ok"):
            warnings.append(
                f"case {case['id']} (op={case['op']}) was designed to fail "
                f"but both sides returned ok; error-string comparison was "
                f"not exercised")
        hint = info.get("error_hint") or ""
        if hint and not c_rec.get("ok") and not r_rec.get("ok"):
            c_err = fields(c_rec)["error"]
            r_err = fields(r_rec)["error"]
            if c_err == r_err and c_err != hint:
                warnings.append(
                    f"case {case['id']} (op={case['op']}) both sides say "
                    f"{c_err!r}, card says {hint!r}")
    return Outcome(cases=len(cases), c_lines=len(c_lines), r_lines=len(r_lines),
                   problems=problems, warnings=warnings, c=c, r=r)


def _record_at(lines: list[str], i: int) -> dict | None:
    if i >= len(lines):
        return None
    rec, err = parse_record(lines[i])
    return rec if err is None else None


# ------------------------------------------------------------- report ------

def show(value: Any) -> str:
    if value is ABSENT:
        return ABSENT
    return json.dumps(value, ensure_ascii=False)


def json_line(value: Any) -> str:
    return json.dumps(value, ensure_ascii=False, sort_keys=True,
                      separators=(", ", ": "))


def report_first(p: Problem, c_path: str, r_path: str) -> None:
    case = p.case
    print()
    print(f"=== FIRST DIFFERENCE: case index {p.index}"
          f" (id={case.get('id', '?')}) op={case.get('op', '?')}"
          f" mode={case.get('mode', '?')} type={case.get('type', '?')}"
          f" ===")
    if p.reasons:
        print("structural:")
        for reason in p.reasons:
            print(f"  - {reason}")
    if p.diffs:
        print("field diffs:")
        width = max(len(k) for k in p.diffs)
        for key, (cv, rv) in p.diffs.items():
            print(f"  {key:<{width}}  c={show(cv):<28} rust={show(rv)}")
    print(f"c   : {p.c_raw if p.c_raw is not None else '<missing line>'}")
    print(f"rust: {p.r_raw if p.r_raw is not None else '<missing line>'}")
    if "a" in case and "b" in case:
        a, b = case["a"], case["b"]
        print(f"input a: bytes={a['bytes']} tag={a['tag']}")
        print(f"input b: bytes={b['bytes']} tag={b['tag']}")
        repro = json.dumps({k: case[k] for k in
                            ("id", "op", "mode", "type", "a", "b")},
                           separators=(",", ":"), ensure_ascii=True)
        print("minimal repro (one JSONL line, feed to either binary):")
        print(f"  {repro}")
        print("  printf '%s\\n' "
              f"{shell_single_quote(repro)} | {c_path}")
        print("  printf '%s\\n' "
              f"{shell_single_quote(repro)} | {r_path}")


def shell_single_quote(text: str) -> str:
    return "'" + text.replace("'", "'\\''") + "'"


def report(outcome: Outcome, max_report: int, c_path: str, r_path: str,
           quiet: bool) -> None:
    for p in outcome.problems[:max_report]:
        if p is outcome.problems[0]:
            report_first(p, c_path, r_path)
        else:
            bits = []
            if p.reasons:
                bits.append("; ".join(p.reasons))
            if p.diffs:
                bits.append("fields " + ",".join(p.diffs))
            print(f"also: case {p.index} op={p.op}: {'; '.join(bits)}")
    if len(outcome.problems) > max_report:
        print(f"... {len(outcome.problems) - max_report} more differing "
              f"case(s) not listed (--max-report)")

    shown = outcome.warnings[:5]
    for warning in shown:
        print(f"run_diff: warning: {warning}", file=sys.stderr)
    if len(outcome.warnings) > len(shown):
        print(f"run_diff: warning: ... {len(outcome.warnings) - len(shown)} "
              f"more advisory warning(s) suppressed", file=sys.stderr)

    if not quiet:
        print(f"run_diff: cases={outcome.cases} "
              f"c_lines={outcome.c_lines} rust_lines={outcome.r_lines}")
        if outcome.problems:
            print(f"run_diff: {len(outcome.problems)} differing case(s)")
        else:
            print("run_diff: outputs identical")


# ------------------------------------------------------------ failures -----

def write_failures(outcome: Outcome, directory: Path) -> None:
    directory.mkdir(parents=True, exist_ok=True)
    for p in outcome.problems:
        doc = {
            "index": p.index,
            "case": {k: p.case[k] for k in
                     ("id", "op", "mode", "type", "a", "b") if k in p.case},
            "input_line": json.dumps(
                {k: p.case[k] for k in
                 ("id", "op", "mode", "type", "a", "b") if k in p.case},
                separators=(",", ":")),
            "c": {"raw": p.c_raw, "record": p.c_rec},
            "rust": {"raw": p.r_raw, "record": p.r_rec},
            "reasons": p.reasons,
            "field_diffs": {k: {"c": show(v[0]), "rust": show(v[1])}
                            for k, v in p.diffs.items()},
        }
        name = f"case_{p.case.get('id', p.index):08d}.json"
        (directory / name).write_text(
            json.dumps(doc, indent=1, ensure_ascii=False) + "\n",
            encoding="utf-8")


# ------------------------------------------------------------ self-test ----

SHIM = '''#!{python}
import hashlib, json, sys

MODE = "{mode}"
ZERO_WIDTH = {{7: 4, 10: 8}}

for line in sys.stdin:
    text = line.strip()
    if not text:
        continue
    case = json.loads(text)
    a, b = case["a"], case["b"]
    width = ZERO_WIDTH.get(b["tag"])
    raw = bytes.fromhex(b["bytes"])
    zero_divisor = (case["op"] in ("div", "rem", "mod")
                    and width is not None and raw[:width] == b"\\x00" * width)
    if zero_divisor:
        message = "DoDiv :: Divide by zero"
        if MODE == "rust":
            message = "DoDiv :: divide by zero"
        out = {{"id": case["id"], "ok": False, "sp": 0, "error": message}}
    else:
        digest = hashlib.sha256(text.encode()).digest()[:16]
        out = {{"id": case["id"], "ok": True,
               "sp": -16 if case["op"] == "push_immediate" else 16,
               "result": {{"bytes": digest.hex(),
                          "tag": (a["tag"] ^ b["tag"]) & 0x7}},
               "error": None}}
    print(json.dumps(out, separators=(",", ":")))
'''


def self_test(cases_path: Path, timeout: float) -> int:
    cases = load_cases(cases_path)
    tmp = Path(tempfile.mkdtemp(prefix="run_diff_selftest_"))
    made = {}
    for mode in ("c", "rust", "c2"):
        path = tmp / f"shim_{mode}.py"
        path.write_text(SHIM.format(python=sys.executable,
                                    mode="c" if mode == "c2" else mode))
        path.chmod(0o755)
        made[mode] = path
    cases_bytes = cases_path.read_bytes()

    def run(c_bin: Path, r_bin: Path) -> Outcome:
        c = run_side("c", c_bin, cases_bytes, timeout)
        r = run_side("rust", r_bin, cases_bytes, timeout)
        for side in (c, r):
            if side.timed_out or side.returncode != 0:
                raise RuntimeError(f"shim {side.path} failed: rc="
                                   f"{side.returncode} timed_out={side.timed_out}")
        return compare(cases, c, r, {})

    ok = True
    same = run(made["c"], made["c2"])
    if same.problems:
        print(f"self-test: FAIL identical pair produced "
              f"{len(same.problems)} difference(s)", file=sys.stderr)
        ok = False
    else:
        print(f"self-test: identical pair -> {same.cases} cases, "
              f"0 differences")

    diff = run(made["c"], made["rust"])

    def shim_zero(case: dict) -> bool:
        width = {7: 4, 10: 8}.get(case["b"]["tag"])
        return (case["op"] in ("div", "rem", "mod") and width is not None
                and bytes.fromhex(case["b"]["bytes"])[:width] == b"\x00" * width)
    zero_cases = [case for case in cases if shim_zero(case)]
    if not zero_cases:
        print("self-test: FAIL no divide-by-zero case to compare", file=sys.stderr)
        ok = False
    elif not diff.problems:
        print("self-test: FAIL error-string pair produced no difference",
              file=sys.stderr)
        ok = False
    elif diff.problems[0].case.get("id") != zero_cases[0]["id"]:
        print(f"self-test: FAIL first difference at id "
              f"{diff.problems[0].case.get('id')}, want {zero_cases[0]['id']}",
              file=sys.stderr)
        ok = False
    elif len(diff.problems) != len(zero_cases):
        print(f"self-test: FAIL {len(diff.problems)} differences, want "
              f"{len(zero_cases)} (one per zero divisor)",
              file=sys.stderr)
        ok = False
    elif any(list(p.diffs) != ["error"] for p in diff.problems):
        bad = next(p for p in diff.problems if list(p.diffs) != ["error"])
        print(f"self-test: FAIL case {bad.index} differs in "
              f"{list(bad.diffs)}, want ['error']", file=sys.stderr)
        ok = False
    else:
        c_err = diff.problems[0].diffs["error"][0]
        r_err = diff.problems[0].diffs["error"][1]
        print(f"self-test: error-string-only pair -> "
              f"{len(diff.problems)} difference(s), first at "
              f"id={zero_cases[0]['id']}, every diff is the error field")
        print(f"self-test:   c={c_err!r} rust={r_err!r}")

    print(f"self-test: {'PASS' if ok else 'FAIL'} (shims under {tmp})")
    return 0 if ok else 1


# ---------------------------------------------------------------- main -----

def main(argv: Sequence[str] | None = None) -> int:
    ap = argparse.ArgumentParser(
        description="Compare two opcode implementations line by line.")
    ap.add_argument("--c", dest="c_bin", help="C reference binary")
    ap.add_argument("--rust", dest="rust_bin", help="Rust VM binary")
    ap.add_argument("--cases", default="diff/cases.jsonl",
                    help="case JSONL (default diff/cases.jsonl)")
    ap.add_argument("--meta", default=None,
                    help="sidecar meta (default <cases>.meta.json)")
    ap.add_argument("--timeout", type=float, default=120.0,
                    help="seconds per binary before it is killed (default 120)")
    ap.add_argument("--max-report", type=int, default=10,
                    help="how many differing cases to list (default 10)")
    ap.add_argument("--failures-dir", default=None,
                    help="write one JSON per difference here "
                         "(default <cases dir>/failures)")
    ap.add_argument("--no-failures", action="store_true",
                    help="do not write failure artifacts")
    ap.add_argument("--quiet", action="store_true",
                    help="suppress the summary line")
    ap.add_argument("--self-test", action="store_true",
                    help="compare two local shims that differ only in one "
                         "error string, proving the comparator catches it")
    args = ap.parse_args(argv)

    cases_path = Path(args.cases)
    if not cases_path.exists():
        return fail(f"cases file does not exist: {cases_path}")
    try:
        cases = load_cases(cases_path)
    except (ValueError, OSError) as exc:
        return fail(str(exc))
    if args.timeout <= 0:
        return fail("--timeout must be > 0")

    if args.self_test:
        return self_test(cases_path, args.timeout)

    c_path = Path(args.c_bin) if args.c_bin else None
    r_path = Path(args.rust_bin) if args.rust_bin else None
    for flag, path in (("--c", c_path), ("--rust", r_path)):
        problem = check_binary(path, flag)
        if problem:
            return fail(problem)

    meta_path = Path(args.meta) if args.meta else Path(str(cases_path) +
                                                       ".meta.json")
    meta = load_meta(meta_path)

    cases_bytes = cases_path.read_bytes()
    c_side = run_side("c", c_path, cases_bytes, args.timeout)
    r_side = run_side("rust", r_path, cases_bytes, args.timeout)

    for side in (c_side, r_side):
        if side.timed_out:
            return fail(f"{side.name} binary timed out after {args.timeout}s "
                        f"and was killed: {side.path} (produced "
                        f"{len(side.lines)}/{len(cases)} lines)")
        if side.returncode != 0:
            tail = "\n".join(side.stderr.strip().splitlines()[-15:])
            return fail(f"{side.name} binary exited rc={side.returncode} "
                        f"after {len(side.lines)}/{len(cases)} lines: "
                        f"{side.path}\n{tail}")

    # Advisory meta is keyed by position in the case file.
    outcome = compare(cases, c_side, r_side, meta)

    if outcome.problems and not args.no_failures:
        directory = (Path(args.failures_dir) if args.failures_dir
                     else cases_path.parent / "failures")
        try:
            write_failures(outcome, directory)
            if not args.quiet:
                print(f"run_diff: wrote {len(outcome.problems)} failure "
                      f"record(s) to {directory}", file=sys.stderr)
        except OSError as exc:
            print(f"run_diff: warning: could not write failures to "
                  f"{directory}: {exc}", file=sys.stderr)

    report(outcome, max(1, args.max_report), str(c_path), str(r_path),
           args.quiet)
    return 0 if not outcome.problems else 1


if __name__ == "__main__":
    raise SystemExit(main())
