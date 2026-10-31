#!/usr/bin/env python3
"""boxType — original-binary differential (0xd7784).

boxType is the operand box that every generic handler path goes through, and it
has one non-obvious row: k=9 clears only [0] and [4] and leaves [8] alone, while
k=7/8/>9 touch nothing at all. Those are exactly the rows a "reasonable"
reimplementation gets wrong.

Compared per case: returned source pointer (as an offset from src) and all 16
destination bytes. The destination starts out poisoned with 0xEE so "did not
write" is observable.

Scope: types 0..9 plus >9. Not covered: any caller-side behaviour (who decides
the type), and k=6 on a real string object (only the pointer copy is exercised).
"""
import argparse
import hashlib
import json
import pathlib
import random
import struct
import subprocess
import sys
import time

HERE = pathlib.Path(__file__).resolve().parent
RV1 = HERE.parent
BUILD = HERE / 'build'
RECEIPTS = HERE / 'receipts'
sys.path.insert(0, str(HERE))
from handler_oracle import Oracle  # noqa: E402

BOXTYPE = 0xd7784
SEED = 0xCA11


def build_cases():
    rng = random.Random(SEED)
    cases = []  # (type, src16, label)

    def add(t, src, label):
        cases.append((t, src, label))

    # every type gets a value that is distinguishable if the wrong arm runs
    add(0, struct.pack('<d', 1.5) + b'\0' * 8, 'k0 double 1.5')
    add(1, struct.pack('<f', -2.5) + b'\0' * 12, 'k1 float -2.5')
    add(2, struct.pack('<i', -7) + b'\0' * 12, 'k2 int32 -7')
    add(3, struct.pack('<q', -12345678901) + b'\0' * 8, 'k3 int64')
    add(4, struct.pack('<i', 1) + b'\0' * 12, 'k4 bool 1')
    add(4, struct.pack('<i', 7) + b'\0' * 12, 'k4 bool 7 (no 0/1 normalisation)')
    add(5, bytes(range(16)), 'k5 rvalue copy')
    add(5, b'\x11' * 16, 'k5 rvalue copy 2')
    add(6, struct.pack('<I', 0x1234) + b'\xAA\xBB\xCC\xDD' + b'\0' * 8, 'k6 string ptr')
    add(7, b'\x55' * 16, 'k7 no-op')
    add(8, b'\x66' * 16, 'k8 no-op')
    add(9, b'\x77' * 16, 'k9 undefined')
    add(10, b'\x88' * 16, 'k10 out of range no-op')
    add(15, b'\x99' * 16, 'k15 out of range no-op')

    # numeric arms across their interesting values
    for v in (0, 1, -1, 2**31 - 1, -2**31):
        add(2, struct.pack('<i', v) + b'\0' * 12, 'k2 int32 %d' % v)
    for v in (0, 1, -1, 2**63 - 1, -2**63):
        add(3, struct.pack('<q', v) + b'\0' * 8, 'k3 int64 %d' % v)
    for f in (0.0, -0.0, 1.0, 0.1, 1e38, float('inf'), float('nan')):
        add(1, struct.pack('<f', f) + b'\0' * 12, 'k1 float %r' % f)
    for d in (0.0, -0.0, 0.1, 1e308, float('inf'), float('nan')):
        add(0, struct.pack('<d', d) + b'\0' * 8, 'k0 double %r' % d)

    # random tail: type 0..15 with random bytes, keeps the set off the happy path
    for _ in range(60):
        t = rng.randrange(16)
        add(t, bytes(rng.randrange(256) for _ in range(16)), 'random k%d' % t)
    return cases


def build_c(binary: pathlib.Path, mutant: int = 0):
    cmd = ['clang', '-std=c11', '-O1', '-Wall', '-Werror', '-ffp-contract=off',
           '-fno-strict-aliasing', str(RV1 / 'c/box_type.c'),
           str(RV1 / 'c/box_type_driver.c'), '-o', str(binary)]
    if mutant:
        cmd.insert(1, '-DMUTANT=%d' % mutant)
    subprocess.run(cmd, check=True)
    return binary


def run_c(binary, cases):
    blob = b''.join(struct.pack('<I', t) + s for t, s, _ in cases)
    out = subprocess.run([str(binary)], input=blob, stdout=subprocess.PIPE, check=True).stdout
    if len(out) != 20 * len(cases):
        raise RuntimeError('short C output')
    return [(struct.unpack('<i', out[i * 20:i * 20 + 4])[0], out[i * 20 + 4:i * 20 + 20])
            for i in range(len(cases))]


def run_oracle(o, cases):
    res = []
    for t, src16, _ in cases:
        dst = o.alloc(16)
        src = o.alloc(16)
        o.write(src, src16)
        o.write(dst, b'\xEE' * 16)
        ret = o.call(BOXTYPE, r0=dst, r1=t, r2=src)
        res.append((ret - src, bytes(o.read(dst, 16))))
    return res


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--no-run', action='store_true')
    args = ap.parse_args()
    if args.no_run:
        rec = sorted(RECEIPTS.glob('box_type_diff-*.json'))[-1]
        data = json.loads(rec.read_text())
        print(json.dumps(data['gates'], indent=2, ensure_ascii=False))
        return 0 if all(g.get('pass') for g in data['gates'].values()) else 1

    BUILD.mkdir(exist_ok=True)
    RECEIPTS.mkdir(exist_ok=True)
    cases = build_cases()
    t0 = time.time()
    c_base = run_c(build_c(BUILD / 'box_type_base'), cases)
    o = Oracle()
    a_ref = run_oracle(o, cases)

    mism = []
    for (t, src16, label), got, want in zip(cases, c_base, a_ref):
        if got != want:
            mism.append({'type': t, 'label': label, 'src': src16.hex(),
                         'c': [got[0], got[1].hex()], 'orig': [want[0], want[1].hex()]})

    types_seen = {t for t, _, _ in cases}
    touched = sum(1 for (t, src16, _), w in zip(cases, a_ref) if w[1] != b'\xEE' * 16)

    teeth = {}
    for m in (1, 2, 3, 4, 5):
        got = run_c(build_c(BUILD / ('box_type_m%d' % m), mutant=m), cases)
        caught = [i for i, (g, w) in enumerate(zip(got, a_ref)) if g != w]
        teeth[m] = {'caught_cases': len(caught), 'pass': len(caught) > 0}

    gates = {
        'identity': {'pass': not mism, 'mismatches': len(mism)},
        'coverage_types_0_9': {'pass': types_seen >= set(range(10)), 'seen': sorted(types_seen)},
        'non_degenerate': {'pass': touched > 0, 'dsts_written_by_original': touched,
                           'total_cases': len(cases)},
        'teeth': {'pass': all(v['pass'] for v in teeth.values()), 'mutants': teeth},
    }
    receipt = {
        'harness': 'box_type_diff.py',
        'target': {'symbol': '_Z7boxTypeR6RValue8eVM_TypePh', 'func': 'boxType',
                   'addr': hex(BOXTYPE), 'so': pathlib.Path(o.so).name},
        'scope': {'covered': ['types 0..9', 'types >9 (no-op)'],
                  'not_covered': ['caller-side type decisions',
                                  'k=6 against a real string object (only the pointer copy)']},
        'seed': hex(SEED), 'cases': len(cases),
        'inputs_sha256': hashlib.sha256(
            b''.join(struct.pack('<I', t) + s for t, s, _ in cases)).hexdigest(),
        'c_sha256': hashlib.sha256((RV1 / 'c/box_type.c').read_bytes()).hexdigest(),
        'result': {'mismatches': len(mism), 'first': mism[:8]},
        'gates': gates,
        'wall_s': round(time.time() - t0, 1),
        'when': time.strftime('%Y-%m-%dT%H:%M:%S'),
    }
    out = RECEIPTS / ('box_type_diff-%s.json' % time.strftime('%Y%m%dT%H%M%S'))
    out.write_text(json.dumps(receipt, indent=2, ensure_ascii=False))
    ok = all(g['pass'] for g in gates.values())
    print('cases=%d mismatches=%d' % (len(cases), len(mism)))
    for k, v in gates.items():
        print('  %-22s %s' % (k, 'PASS' if v['pass'] else 'FAIL'))
    for m, v in teeth.items():
        print('  mutant %d caught by %d cases' % (m, v['caught_cases']))
    for x in mism[:6]:
        print('  MISMATCH', x['label'], 'c=', x['c'], 'orig=', x['orig'])
    print('receipt:', out)
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
