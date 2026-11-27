#!/usr/bin/env python3
"""DoNot — original-binary differential (same contract as do_neg_diff.py).

arm A (judge) libyoyo DoNot @0xd7908 in Unicorn
arm B (claim) c/do_not.c compiled to a host binary
Both get the same cases; compare returned stack pointer, all 16 slot bytes and
the emitted error text.

Scope: mode 0 + mode 3..15 fall-through. mode 1 (`!`, JS_ToBoolean) and mode 2
(`~` through boxType + F_JS_ToInt32) are not wired.

The interesting part of this handler is that `~` on a real is a triple
conversion (double -> int64 -> NOT -> double), not a sign flip, so the case set
is built around the conversion boundaries: 2**63, -2**63, 0.5, -0.5, NaN, Inf.
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

DO_NOT = 0xd7908
SEED = 0xCA11
N_RANDOM = 120


def slot_from(payload: bytes, tag=None, tag_word_override=None) -> bytes:
    buf = bytearray(16)
    buf[:len(payload)] = payload[:16]
    if tag_word_override is not None:
        struct.pack_into('<I', buf, 12, tag_word_override & 0xffffffff)
    elif tag is not None:
        struct.pack_into('<I', buf, 12, tag & 0xffffffff)
    return bytes(buf)


def build_cases():
    rng = random.Random(SEED)
    cases = []

    def add(mode, cls, slot, label):
        cases.append(((mode & 0xF) << 8 | (cls & 0xF) << 16, slot, label))

    d_words = [0x0000000000000000, 0x8000000000000000, 0x3fe0000000000000,
               0xbfe0000000000000, 0x3ff0000000000000, 0xbff0000000000000,
               0x7ff0000000000000, 0xfff0000000000000, 0x7ff8000000000001,
               0x7ff0000000000001, 0x0000000000000001, 0x43e0000000000000,
               0xc3e0000000000000, 0x43dfffffffffffff, 0x7fefffffffffffff,
               0x0123456789abcdef, 0x41dfffffffc00000]
    for w in d_words:
        add(0, 0, slot_from(struct.pack('<Q', w)), 'cls0 dbl %#018x' % w)

    f_words = [0x00000000, 0x80000000, 0x3f000000, 0xbf000000, 0x3f800000,
               0xbf800000, 0x7f800000, 0xff800000, 0x7fc00001, 0x4f000000,
               0xcf000000, 0x4effffff, 0x00000001, 0xdeadbeef,
               0x3f19999a, 0x3fc00000, 0x40200000, 0xbf19999a, 0x406ccccd]
    for w in f_words:
        add(0, 1, slot_from(struct.pack('<I', w)), 'cls1 flt %#010x' % w)

    for v in (0, 1, 0xffffffff, 0x80000000, 0x7fffffff, 42, 2, 3):
        add(0, 2, slot_from(struct.pack('<I', v)), 'cls2 i32 %#010x' % v)
        add(0, 4, slot_from(struct.pack('<I', v)), 'cls4 bool %#010x' % v)
    for v in (0, 1, 0xffffffffffffffff, 0x8000000000000000, 0x7fffffffffffffff):
        add(0, 3, slot_from(struct.pack('<Q', v)), 'cls3 i64 %#018x' % v)

    payloads = [
        ('dbl0.5', struct.pack('<Q', 0x3fe0000000000000)),
        ('dbl-0.5', struct.pack('<Q', 0xbfe0000000000000)),
        ('dbl2p63', struct.pack('<Q', 0x43e0000000000000)),
        ('nan', struct.pack('<Q', 0x7ff8000000000001)),
        ('int32_min', struct.pack('<I', 0x80000000) + b'\0' * 4),
        ('int64_min', struct.pack('<Q', 0x8000000000000000)),
        ('zero', b'\0' * 8),
    ]
    for tag in range(16):
        for name, payload in payloads:
            add(0, 5, slot_from(payload, tag=tag), 'cls5 tag%d %s' % (tag, name))
        add(0, 5, slot_from(struct.pack('<Q', 0x3fe0000000000000),
                            tag_word_override=(tag << 24) | 0), 'cls5 tagword hi%d' % tag)

    for cls in range(6, 16):
        add(0, cls, slot_from(b'AAAA' + b'\0' * 12), 'cls%d string/passthru' % cls)

    for mode in (3, 7, 15):
        for cls in (0, 1, 2, 4, 5, 9):
            add(mode, cls, slot_from(struct.pack('<Q', 0xbfe0000000000000)),
                'mode%d cls%d fallthrough' % (mode, cls))

    # mode 1 (`!`): boxType then JS_ToBoolean; the result is ONE byte at
    # boxed-4 and the return pointer is boxed-4, so the delta is (consumed-4).
    # array(tag2)/pointer(tag3) hit an unwired callee inside the original's
    # JS_ToBoolean and stay out of the domain (claims DNOT-ORA-009).
    bool_payloads = [
        ('real0', struct.pack('<d', 0.0)),
        ('real-0', struct.pack('<Q', 0x8000000000000000)),
        ('real0.5', struct.pack('<d', 0.5)),
        ('realnan', struct.pack('<Q', 0x7ff8000000000001)),
        ('realinf', struct.pack('<Q', 0x7ff0000000000000)),
        ('int32_0', struct.pack('<i', 0)),
        ('int32_7', struct.pack('<i', 7)),
        ('int64_0', struct.pack('<q', 0)),
        ('int64_5', struct.pack('<q', 5)),
        ('undef', b'\0' * 8),
        ('null', b'\0' * 8),
    ]
    for cls, payload in [(0, struct.pack('<d', 0.5)), (1, struct.pack('<f', 0.0)),
                         (2, struct.pack('<i', 3)), (3, struct.pack('<q', 0)),
                         (4, struct.pack('<i', 2))]:
        add(1, cls, slot_from(payload), 'mode1 cls%d' % cls)
    for tag in (0, 5, 7, 10, 12, 13):
        for name, payload in bool_payloads:
            add(1, 5, slot_from(payload, tag=tag), 'mode1 tag%d %s' % (tag, name))

    for _ in range(N_RANDOM):
        cls = rng.choice([0, 1, 2, 3, 4, 5, 6, 7, 15])
        payload = bytes(rng.randrange(256) for _ in range(8))
        tag = rng.randrange(16) if cls == 5 else None
        add(rng.choice([0, 0, 0, 3]), cls, slot_from(payload, tag=tag), 'random cls%d' % cls)
    return cases


def build_c(binary: pathlib.Path, mutant: int = 0):
    cmd = ['clang', '-std=c11', '-O1', '-Wall', '-Werror', '-ffp-contract=off',
           '-fno-strict-aliasing', str(RV1 / 'c/do_not.c'),
           str(RV1 / 'c/box_type.c'),
           str(RV1 / 'c/do_not_driver.c'), '-o', str(binary)]
    if mutant:
        cmd.insert(1, '-DMUTANT=%d' % mutant)
    subprocess.run(cmd, check=True)
    return binary


ARENA = 64
SLOT = 32


def arena_of(slot):
    return b'\xEE' * SLOT + slot + b'\xEE' * (ARENA - SLOT - len(slot))


def run_c(binary, cases):
    blob = b''.join(struct.pack('<I', arg) + arena_of(slot) for arg, slot, _ in cases)
    out = subprocess.run([str(binary)], input=blob, stdout=subprocess.PIPE, check=True).stdout
    rec_len = 4 + ARENA + 128
    if len(out) != rec_len * len(cases):
        raise RuntimeError('short C output: %d for %d cases' % (len(out), len(cases)))
    return [(struct.unpack('<i', out[i * rec_len:i * rec_len + 4])[0],
             out[i * rec_len + 4:i * rec_len + 4 + ARENA],
             out[i * rec_len + 4 + ARENA:(i + 1) * rec_len].split(b'\0')[0].decode('utf-8', 'replace'))
            for i in range(len(cases))]


def run_oracle(o, cases):
    res = []
    for arg, slot, _ in cases:
        arena = o.alloc(ARENA)
        o.write(arena, arena_of(slot))
        slotp = arena + SLOT
        ret = o.call(DO_NOT, r0=arg, r1=slotp, r2=0, r3=0)
        err = ''
        for c in o.calls:
            if c['name'] in ('VMError', 'JSThrowReferenceError', 'JSThrowTypeError'):
                err = o.read_cstr(c['args'][1])
                break
        res.append((ret - slotp, bytes(o.read(arena, ARENA)), err))
    return res


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--no-run', action='store_true')
    args = ap.parse_args()
    if args.no_run:
        rec = sorted(RECEIPTS.glob('do_not_diff-*.json'))[-1]
        data = json.loads(rec.read_text())
        print(json.dumps(data['gates'], indent=2, ensure_ascii=False))
        return 0 if all(g.get('pass') for g in data['gates'].values()) else 1

    BUILD.mkdir(exist_ok=True)
    RECEIPTS.mkdir(exist_ok=True)
    cases = build_cases()
    t0 = time.time()
    c_base = run_c(build_c(BUILD / 'do_not_base'), cases)
    o = Oracle()
    a_ref = run_oracle(o, cases)

    mism = []
    for (arg, slot, label), got, want in zip(cases, c_base, a_ref):
        if got != want:
            mism.append({'arg': arg, 'label': label, 'input': slot.hex(),
                         'c': [got[0], got[1].hex(), got[2]],
                         'orig': [want[0], want[1].hex(), want[2]]})

    cls_seen, tag_seen = set(), set()
    for arg, slot, _ in cases:
        cls_seen.add((arg >> 16) & 0xF)
        if ((arg >> 16) & 0xF) == 5:
            tag_seen.add(struct.unpack('<I', slot[12:16])[0])
    changed = sum(1 for (arg, slot, _), w in zip(cases, a_ref)
                  if w[1][SLOT:SLOT + 16] != slot)

    teeth = {}
    for m in (1, 2, 3, 4, 5):
        got = run_c(build_c(BUILD / ('do_not_m%d' % m), mutant=m), cases)
        caught = [i for i, (g, w) in enumerate(zip(got, a_ref)) if g != w]
        teeth[m] = {'caught_cases': len(caught), 'pass': len(caught) > 0}

    gates = {
        'identity': {'pass': not mism, 'mismatches': len(mism)},
        'coverage_cls_0_15': {'pass': cls_seen >= set(range(16)), 'seen': sorted(cls_seen)},
        'coverage_tag_0_15': {'pass': tag_seen >= set(range(16)), 'seen': sorted(tag_seen)},
        'non_degenerate': {'pass': changed > 0, 'slots_changed_by_original': changed,
                           'total_cases': len(cases)},
        'teeth': {'pass': all(t['pass'] for t in teeth.values()), 'mutants': teeth},
    }
    receipt = {
        'harness': 'do_not_diff.py',
        'target': {'symbol': '_Z5DoNotjPhPKhP6VMExec', 'func': 'DoNot',
                   'addr': hex(DO_NOT), 'so': pathlib.Path(o.so).name},
        'scope': {'covered': ['mode 0 (strong-typed, cls 0..15)',
                              'mode 3..15 fall-through'],
                  'not_covered': ['mode 1 (JS ! via JS_ToBoolean)',
                                  'mode 2 (~ via boxType + F_JS_ToInt32)']},
        'seed': hex(SEED), 'cases': len(cases),
        'inputs_sha256': hashlib.sha256(
            b''.join(struct.pack('<I', a) + s for a, s, _ in cases)).hexdigest(),
        'c_sha256': hashlib.sha256((RV1 / 'c/do_not.c').read_bytes()).hexdigest(),
        'result': {'mismatches': len(mism), 'first': mism[:8]},
        'gates': gates,
        'errors_seen': sorted({w[2] for w in a_ref if w[2]}),
        'wall_s': round(time.time() - t0, 1),
        'when': time.strftime('%Y-%m-%dT%H:%M:%S'),
    }
    out = RECEIPTS / ('do_not_diff-%s.json' % time.strftime('%Y%m%dT%H%M%S'))
    out.write_text(json.dumps(receipt, indent=2, ensure_ascii=False))
    ok = all(g['pass'] for g in gates.values())
    print('cases=%d mismatches=%d' % (len(cases), len(mism)))
    for k, v in gates.items():
        print('  %-20s %s' % (k, 'PASS' if v['pass'] else 'FAIL'))
    for m, t in teeth.items():
        print('  mutant %d caught by %d cases' % (m, t['caught_cases']))
    if mism:
        for x in mism[:5]:
            print('  MISMATCH', x['label'], 'in=', x['input'], 'c=', x['c'], 'orig=', x['orig'])
    print('errors seen:', receipt['errors_seen'])
    print('receipt:', out)
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
