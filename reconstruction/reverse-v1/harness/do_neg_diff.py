#!/usr/bin/env python3
"""DoNeg — original-binary differential under the new evidence standard.

Two arms, same inputs:
  arm A (judge)     libyoyo's own DoNeg @0xe096c, executed in Unicorn
  arm B (claim)     reconstruction/reverse-v1/c/do_neg.c, compiled to a host binary

Compared per case: returned stack pointer, all 16 slot bytes, and the error text
the handler emits (VMError string read out of the guest, matched byte for byte).

Scope: mode 0 + the mode 3..15 fall-through. mode 1 / mode 2 call
boxType and F_JS_ToNumber and are NOT covered - the receipt says so.

Gates (a failure here aborts with a non-zero exit):
  * identity      every case identical
  * coverage      every cls 0..15 and every tag 0..15 actually appear
  * non-degenerate  the case set contains cases where the result differs from
                    the input (a set of no-ops would pass trivially)
  * TEETH          each -DMUTANT=n build must produce at least one mismatch; a
                    green mutant means the case set does not exercise that
                    decision and the identity is worthless

Usage:
  python3 do_neg_diff.py            # build, run, write receipt
  python3 do_neg_diff.py --no-run   # replay the gate logic on the last receipt
"""
import argparse
import hashlib
import json
import math
import os
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

DO_NEG = 0xe096c
SEED = 0xCA11
N_RANDOM = 120


# ── case construction ────────────────────────────────────────────────────────
def slot_from(payload: bytes, tag: int | None = None, tag_word_override: int | None = None) -> bytes:
    buf = bytearray(16)
    buf[:len(payload)] = payload[:16]
    if tag_word_override is not None:
        struct.pack_into('<I', buf, 12, tag_word_override & 0xffffffff)
    elif tag is not None:
        struct.pack_into('<I', buf, 12, tag & 0xffffffff)
    return bytes(buf)


def build_cases():
    """Deterministic: identical list on every rerun, no time- or host-dependent input."""
    rng = random.Random(SEED)
    cases = []  # (arg, slot16, label)

    def add(mode, cls, slot, label):
        cases.append(((mode & 0xF) << 8 | (cls & 0xF) << 16, slot, label))

    # cls 0/1: float patterns chosen to separate sign-flip from arithmetic negate.
    d_words = [0x0000000000000000, 0x8000000000000000, 0x3ff8000000000000,
               0xbff8000000000000, 0x7ff0000000000000, 0xfff0000000000000,
               0x7ff8000000000001, 0x7ff0000000000001, 0x0000000000000001,
               0x7fefffffffffffff, 0x0000000100000002, 0x0123456789abcdef]
    for w in d_words:
        add(0, 0, slot_from(struct.pack('<Q', w)), 'cls0 dbl %#018x' % w)
    f_words = [0x00000000, 0x80000000, 0x3fc00000, 0xbfc00000, 0x7f800000,
               0xff800000, 0x7fc00001, 0x7f800001, 0x00000001, 0x7f7fffff,
               0xdeadbeef]
    for w in f_words:
        add(0, 1, slot_from(struct.pack('<I', w)), 'cls1 flt %#010x' % w)

    # cls 2/4: int32 incl. the wrap point; 200 randoms spread over cls 2 and 4.
    i32 = [0, 1, 0xffffffff, 0x80000000, 0x7fffffff, 0x80000001, 42]
    for v in i32:
        add(0, 2, slot_from(struct.pack('<I', v)), 'cls2 i32 %#010x' % v)
        add(0, 4, slot_from(struct.pack('<I', v)), 'cls4 i32 %#010x' % v)

    # cls 3: int64 incl. INT64_MIN wrap.
    i64 = [0, 1, 0xffffffffffffffff, 0x8000000000000000, 0x7fffffffffffffff,
           0x8000000000000001, 0x00000001ffffffff]
    for v in i64:
        add(0, 3, slot_from(struct.pack('<Q', v)), 'cls3 i64 %#018x' % v)

    # cls 5: every tag 0..15 x payload shapes, plus tag-word encodings.
    payloads = [
        ('dbl1.0', struct.pack('<Q', 0x3ff0000000000000)),
        ('dbl-0.0', struct.pack('<Q', 0x8000000000000000)),
        ('int32_min', struct.pack('<I', 0x80000000) + b'\0' * 4),
        ('int64_min', struct.pack('<Q', 0x8000000000000000)),
        ('zero', b'\0' * 8),
    ]
    for tag in range(16):
        for name, payload in payloads:
            add(0, 5, slot_from(payload, tag=tag), 'cls5 tag%d %s' % (tag, name))
        # the tag word is compared as a whole word (`ldr` + `cmp r2,#13`), so a
        # non-zero high byte must also be exercised - it is the difference
        # between "tag byte" and "tag word" models.
        add(0, 5, slot_from(struct.pack('<Q', 0x3ff0000000000000),
                            tag_word_override=(tag << 24) | 0), 'cls5 tagword hi%d' % tag)

    # cls 6: string arm; cls 7..15: pass-through.
    for cls in range(6, 16):
        add(0, cls, slot_from(b'AAAA' + b'\0' * 12), 'cls%d string/passthru' % cls)

    # mode 3..15 must fall through to the strong-typed arm.
    for mode in (3, 7, 15):
        for cls in (0, 2, 5, 9):
            add(mode, cls, slot_from(struct.pack('<Q', 0x3ff0000000000000)),
                'mode%d cls%d fallthrough' % (mode, cls))

    # random tail: keeps the domain from being a hand-picked happy path.
    for _ in range(N_RANDOM):
        cls = rng.choice([0, 1, 2, 3, 4, 5, 6, 7, 15])
        payload = bytes(rng.randrange(256) for _ in range(8))
        tag = rng.randrange(16) if cls == 5 else None
        add(rng.choice([0, 0, 0, 3]), cls, slot_from(payload, tag=tag), 'random cls%d' % cls)

    return cases


# ── arms ────────────────────────────────────────────────────────────────────
def build_c(binary: pathlib.Path, mutant: int = 0):
    cmd = ['clang', '-std=c11', '-O1', '-Wall', '-Werror', '-ffp-contract=off',
           '-fno-strict-aliasing', str(RV1 / 'c/do_neg.c'),
           str(RV1 / 'c/do_neg_driver.c'), '-o', str(binary)]
    if mutant:
        cmd.insert(1, '-DMUTANT=%d' % mutant)
    subprocess.run(cmd, check=True)
    return binary


def run_c(binary: pathlib.Path, cases):
    blob = b''.join(struct.pack('<I', arg) + slot for arg, slot, _ in cases)
    proc = subprocess.run([str(binary)], input=blob, stdout=subprocess.PIPE, check=True)
    if len(proc.stdout) != 148 * len(cases):
        raise RuntimeError('short C output: %d bytes for %d cases'
                           % (len(proc.stdout), len(cases)))
    out = []
    for i in range(len(cases)):
        rec = proc.stdout[i * 148:(i + 1) * 148]
        out.append((struct.unpack('<I', rec[:4])[0], rec[4:20],
                    rec[20:].split(b'\0')[0].decode('utf-8', 'replace')))
    return out


def run_oracle(o: Oracle, cases):
    out = []
    for arg, slot, _label in cases:
        buf = o.alloc(16)
        o.write(buf, slot)
        ret = o.call(DO_NEG, r0=arg, r1=buf, r2=0, r3=0)
        err = ''
        for c in o.calls:
            if c['name'] in ('VMError', 'JSThrowReferenceError', 'JSThrowTypeError'):
                err = o.read_cstr(c['args'][1])
                break
        out.append((0 if ret == buf else 1, bytes(o.read(buf, 16)), err))
    return out


# ── gates ───────────────────────────────────────────────────────────────────
def gate_coverage(cases):
    cls_seen, tag_seen = set(), set()
    for arg, slot, _ in cases:
        cls_seen.add((arg >> 16) & 0xF)
        if ((arg >> 16) & 0xF) == 5:
            tag_seen.add(struct.unpack('<I', slot[12:16])[0])
    return cls_seen, tag_seen


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--no-run', action='store_true')
    args = ap.parse_args()
    if args.no_run:
        rec = sorted(RECEIPTS.glob('do_neg_diff-*.json'))[-1]
        data = json.loads(rec.read_text())
        print(json.dumps(data['gates'], indent=2, ensure_ascii=False))
        return 0 if all(g.get('pass') for g in data['gates'].values()) else 1

    BUILD.mkdir(exist_ok=True)
    RECEIPTS.mkdir(exist_ok=True)
    cases = build_cases()
    t0 = time.time()

    base = build_c(BUILD / 'do_neg_base')
    c_base = run_c(base, cases)
    o = Oracle()
    a_ref = run_oracle(o, cases)

    mismatches = []
    for (arg, slot, label), got, want in zip(cases, c_base, a_ref):
        if got != want:
            mismatches.append({'arg': arg, 'label': label, 'input': slot.hex(),
                               'c': [got[0], got[1].hex(), got[2]],
                               'orig': [want[0], want[1].hex(), want[2]]})

    # non-degenerate: the strong-typed arm must actually transform the slot
    changed = sum(1 for (arg, slot, _), want in zip(cases, a_ref) if want[1] != slot)
    cls_seen, tag_seen = gate_coverage(cases)

    teeth = {}
    for m in (1, 2, 3, 4, 5):
        b = build_c(BUILD / ('do_neg_m%d' % m), mutant=m)
        got = run_c(b, cases)
        caught = [i for i, (g, w) in enumerate(zip(got, a_ref)) if g != w]
        teeth[m] = {'caught_cases': len(caught), 'pass': len(caught) > 0}

    gates = {
        'identity': {'pass': not mismatches, 'mismatches': len(mismatches)},
        'coverage_cls_0_15': {'pass': cls_seen >= set(range(16)), 'seen': sorted(cls_seen)},
        'coverage_tag_0_15': {'pass': tag_seen >= set(range(16)), 'seen': sorted(tag_seen)},
        'non_degenerate': {'pass': changed > 0, 'slots_changed_by_original': changed,
                           'total_cases': len(cases)},
        'teeth': {'pass': all(t['pass'] for t in teeth.values()), 'mutants': teeth},
    }
    # A handler family also has to report which arms it did NOT cover.
    uncovered = ['mode 1 (generic negate: boxType + F_JS_ToNumber)',
                 'mode 2 (plain numeric coercion)']

    receipt = {
        'harness': 'do_neg_diff.py',
        'target': {'symbol': '_Z5DoNegjPhPKhP6VMExec',
                   'func': 'DoNeg', 'addr': hex(DO_NEG),
                   'so': os.path.basename(o.so)},
        'scope': {'covered': ['mode 0 (strong-typed, cls 0..15)',
                              'mode 3..15 fall-through'],
                  'not_covered': uncovered},
        'seed': hex(SEED), 'cases': len(cases),
        'inputs_sha256': hashlib.sha256(
            b''.join(struct.pack('<I', a) + s for a, s, _ in cases)).hexdigest(),
        'c_sha256': hashlib.sha256((RV1 / 'c/do_neg.c').read_bytes()).hexdigest(),
        'result': {'mismatches': len(mismatches), 'first': mismatches[:5]},
        'gates': gates,
        'errors_seen': sorted({w[2] for w in a_ref if w[2]}),
        'wall_s': round(time.time() - t0, 1),
        'when': time.strftime('%Y-%m-%dT%H:%M:%S'),
    }
    out = RECEIPTS / ('do_neg_diff-%s.json' % time.strftime('%Y%m%dT%H%M%S'))
    out.write_text(json.dumps(receipt, indent=2, ensure_ascii=False))

    ok = all(g['pass'] for g in gates.values())
    print('cases=%d identical=%d mismatches=%d' % (len(cases), len(cases) - len(mismatches), len(mismatches)))
    for k, v in gates.items():
        print('  %-20s %s' % (k, 'PASS' if v['pass'] else 'FAIL'))
    if teeth:
        for m, t in teeth.items():
            print('  mutant %d caught by %d cases' % (m, t['caught_cases']))
    print('errors seen:', receipt['errors_seen'])
    print('receipt:', out)
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
