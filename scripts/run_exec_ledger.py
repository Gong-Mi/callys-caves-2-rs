#!/usr/bin/env python3
"""Run every built test binary with CALLY_CODE_TRACE set to ONE shared ledger,
so the execution-evidence axis of the semantic census covers the whole suite
instead of only the four suites traced by hand before.

Each VM entry appends its CODE id (append-only, write_all under a lock in
code_vm::coverage), so parallel binaries share the ledger safely.

Usage: run_exec_ledger.py [target/release/deps] [ledger_out]
Skips binaries that crash or time out (still keeping whatever they appended).
"""
import os, subprocess, sys, glob, time

DEPS = sys.argv[1] if len(sys.argv) > 1 else "target/release/deps"
LEDGER = sys.argv[2] if len(sys.argv) > 2 else "reconstruction/live-mem/trace/cally-code-trace-full-ledger.txt"
os.makedirs(os.path.dirname(LEDGER), exist_ok=True)
open(LEDGER, "w").close()  # fresh ledger per full run

env = dict(os.environ, CALLY_CODE_TRACE=os.path.abspath(LEDGER),
           CALLY_CFG_LEDGER=os.path.expanduser("~/cally-cfg-evidence-ci-44a33c0/progress.tsv"))

patterns = [f"{DEPS}/*-*"]
# newer cargo in this tree places test executables under build/<hash>/out
patterns += glob.glob("target/release/build/*/*/out/*-*")
binaries = sorted({p for pat in patterns for p in glob.glob(pat)
                   if os.path.isfile(p) and os.access(p, os.X_OK)
                   and not p.endswith((".d", ".o", ".rlib", ".so"))
                   and "build_script" not in p and "build-script" not in p})
print(f"{len(binaries)} candidate binaries")
ok = fail = skipped = 0
t0 = time.time()
for b in binaries:
    try:
        r = subprocess.run([b], env=env, capture_output=True, text=True, timeout=1800)
        line = (r.stdout or "").strip().splitlines()
        tail = line[-1] if line else ""
        if r.returncode == 0:
            ok += 1
            status = "OK"
        else:
            fail += 1
            status = f"RC{r.returncode}"
        if "0 passed" in tail and "running 0 tests" in " ".join(line):
            skipped += 1
        print(f"  {os.path.basename(b):60s} {status:6s} {tail[:60]}")
    except subprocess.TimeoutExpired:
        fail += 1
        print(f"  {os.path.basename(b):60s} TIMEOUT")
    except Exception as e:
        fail += 1
        print(f"  {os.path.basename(b):60s} ERR {e}")

n = sum(1 for _ in open(LEDGER))
distinct = len({l.strip() for l in open(LEDGER) if l.strip().isdigit()})
print(f"done in {time.time()-t0:.0f}s: ok={ok} fail={fail} (empty-suites counted ok)")
print(f"ledger: {n} entries, {distinct} distinct CODE ids -> {LEDGER}")
