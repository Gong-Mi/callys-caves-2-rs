#!/usr/bin/env python3
"""CObjectGM::LoadFromChunk — OBJT header parse, original vs C.

This is the first arm on the ASSET LOADING chain rather than on a VM handler:
the object table parser that turns a record in game.droid into the runtime
CObjectGM. Pinning it is what lets the asset-loading analysis rest on the
original's own behaviour instead of on our reading of the record layout.

Domain (what this arm claims): the fixed 0x20-byte header. Everything past
src+0x20 sits behind a data-version gate (`cmp r2,#5`, then `cmp r2,#8`) whose
version word is fetched through a pc-relative table that is not relocated in
this harness - the >8 path dereferences through it and faults with
UC_ERR_WRITE_UNMAPPED. So the tail is out of domain by construction, not by
choice (claims OBJ-ORA-004).

Compared per case: return value and dst[0..0x20].
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

LOAD = 0x19d688
SEED = 0xCA11
REC = 32
DST = 0x20


def build_cases():
    rng = random.Random(SEED)
    cases = []  # (record32, label)

    def add(rec, label):
        cases.append((bytes(rec) + b'\0' * (REC - len(rec)), label))

    add(b'\0' * REC, 'all zero')
    # one live byte at a time over the in-domain header
    for i in range(4, 32):
        rec = bytearray(REC)
        rec[i] = 0x11
        add(rec, 'src[%#04x]=0x11' % i)

    def with32(off, value, label):
        rec = bytearray(REC)
        struct.pack_into('<I', rec, off, value)
        add(rec, label)

    # sprite index: the tag bits decide whether bit31 is lifted into a global
    with32(4, 0x80000005, 'sprite hi bit only')
    with32(4, 0x10000005, 'sprite bit28 (tagged path, kept raw)')
    with32(4, 0x70000000, 'sprite bits 28..30')
    with32(4, 0x7fffffff, 'sprite low max')
    with32(4, 0xffffffff, 'sprite all ones')
    # flags
    with32(8, 1, 'visible=1')
    with32(0x0c, 1, 'solid=1')
    with32(0x14, 1, 'persistent=1')
    with32(0x14, 0x100, 'persistent!=0 (nonzero, not bool)')
    rec = bytearray(REC)
    struct.pack_into('<III', rec, 8, 0, 1, 0)
    struct.pack_into('<I', rec, 0x14, 1)
    add(rec, 'solid+persistent')
    # depth and the two following words
    with32(0x10, 0x80000000, 'depth INT32_MIN')
    with32(0x10, 0xffffffff, 'depth -1')
    with32(0x10, -1000 & 0xffffffff, 'depth -1000')
    with32(0x18, 0xdeadbeef, 'src18')
    with32(0x1c, 0xcafebabe, 'src1c')

    # random tail: all header fields at once
    for _ in range(60):
        add(bytes(rng.randrange(256) for _ in range(REC)), 'random record')
    return cases


def build_c(binary: pathlib.Path, mutant: int = 0):
    cmd = ['clang', '-std=c11', '-O1', '-Wall', '-Werror', '-ffp-contract=off',
           '-fno-strict-aliasing', str(RV1 / 'c/object_load.c'),
           str(RV1 / 'c/object_load_driver.c'), '-o', str(binary)]
    if mutant:
        cmd.insert(1, '-DMUTANT=%d' % mutant)
    subprocess.run(cmd, check=True)
    return binary


def run_c(binary, cases):
    blob = b''.join(rec for rec, _ in cases)
    out = subprocess.run([str(binary)], input=blob, stdout=subprocess.PIPE, check=True).stdout
    rec_len = 4 + DST + 4
    if len(out) != rec_len * len(cases):
        raise RuntimeError('short C output')
    res = []
    for i in range(len(cases)):
        r = out[i * rec_len:(i + 1) * rec_len]
        res.append((struct.unpack('<i', r[:4])[0], r[4:4 + DST]))
    return res


def run_oracle(o, cases):
    dst = o.alloc(0x100)
    src = o.alloc(REC)
    res = []
    for rec, _ in cases:
        o.write(dst, b'\0' * 0x100)
        o.write(src, rec)
        ret = o.call(LOAD, r0=dst, r1=src)
        res.append((ret, bytes(o.read(dst, DST))))
    return res


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--no-run', action='store_true')
    args = ap.parse_args()
    if args.no_run:
        rec = sorted(RECEIPTS.glob('object_load_diff-*.json'))[-1]
        data = json.loads(rec.read_text())
        print(json.dumps(data['gates'], indent=2, ensure_ascii=False))
        return 0 if all(g.get('pass') for g in data['gates'].values()) else 1

    BUILD.mkdir(exist_ok=True)
    RECEIPTS.mkdir(exist_ok=True)
    cases = build_cases()
    t0 = time.time()
    c_base = run_c(build_c(BUILD / 'object_load_base'), cases)
    o = Oracle()
    a_ref = run_oracle(o, cases)

    mism = []
    for (rec, label), got, want in zip(cases, c_base, a_ref):
        if got != want:
            mism.append({'label': label, 'src': rec.hex(), 'ret_c': got[0], 'ret_o': want[0],
                         'c': got[1].hex(), 'orig': want[1].hex()})

    # coverage: which header bytes actually influence the destination
    influencing = set()
    base_out = a_ref[0][1]
    for (rec, label), want in zip(cases, a_ref):
        if label.startswith('src[') and want[1] != base_out:
            influencing.add(int(label[4:8], 16))
    teeth = {}
    for m in (1, 2, 3, 4, 5):
        got = run_c(build_c(BUILD / ('object_load_m%d' % m), mutant=m), cases)
        caught = [i for i, (g, w) in enumerate(zip(got, a_ref)) if g != w]
        teeth[m] = {'caught_cases': len(caught), 'pass': len(caught) > 0}

    gates = {
        'identity': {'pass': not mism, 'mismatches': len(mism)},
        'coverage_header_bytes': {'pass': len(influencing) >= 14, 'influencing': sorted(influencing)},
        'non_degenerate': {'pass': base_out != a_ref[5][1] if len(a_ref) > 5 else True,
                           'note': 'flags and fields must move the destination'},
        'teeth': {'pass': all(v['pass'] for v in teeth.values()), 'mutants': teeth},
    }
    receipt = {
        'harness': 'object_load_diff.py',
        'target': {'symbol': '_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh',
                   'func': 'CObjectGM::LoadFromChunk', 'addr': hex(LOAD),
                   'so': pathlib.Path(o.so).name},
        'scope': {'covered': ['OBJT record header src+0x00..src+0x1f',
                              'flags assembly and the sprite bit31 accumulator'],
                  'not_covered': ['src+0x20.. tail (data-version gated; the version word '
                                  'comes through an unrelocated pc-relative table and the '
                                  '>8 path faults with UC_ERR_WRITE_UNMAPPED)']},
        'seed': hex(SEED), 'cases': len(cases),
        'inputs_sha256': hashlib.sha256(b''.join(r for r, _ in cases)).hexdigest(),
        'c_sha256': hashlib.sha256((RV1 / 'c/object_load.c').read_bytes()).hexdigest(),
        'result': {'mismatches': len(mism), 'first': mism[:6]},
        'gates': gates,
        'wall_s': round(time.time() - t0, 1),
        'when': time.strftime('%Y-%m-%dT%H:%M:%S'),
    }
    out = RECEIPTS / ('object_load_diff-%s.json' % time.strftime('%Y%m%dT%H%M%S'))
    out.write_text(json.dumps(receipt, indent=2, ensure_ascii=False))
    ok = all(g['pass'] for g in gates.values())
    print('cases=%d mismatches=%d' % (len(cases), len(mism)))
    for k, v in gates.items():
        print('  %-24s %s' % (k, 'PASS' if v['pass'] else 'FAIL'))
    for m, v in teeth.items():
        print('  mutant %d caught by %d cases' % (m, v['caught_cases']))
    for x in mism[:5]:
        print('  MISMATCH', x['label'], 'c=', x['c'], 'orig=', x['orig'])
    print('receipt:', out)
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
