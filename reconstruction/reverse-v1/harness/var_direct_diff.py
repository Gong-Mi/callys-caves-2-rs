#!/usr/bin/env python3
"""Variable_GetValue_Direct — original-binary differential (Level A, one function).

Two arms, same inputs:
  arm A (judge)  the original bytes at 0x1f3b8c, executed in Unicorn over a
                 staged object + slot table + builtin-variable table
  arm B (claim)  reconstruction/reverse-v1/c/variable_direct/, host-compiled

What is compared per case: the return value, the 16 bytes of the destination
RValue, and the ordered call log with the *slot address arithmetic* the body
performed (printed as an offset from the staged table, never as a raw pointer).

Scope, stated up front: the three library-internal callees (GET_RValue
0xd13bc, YYObjectBase::InternalGetYYVar 0x196a70 and the builtin table
entry's fn) are NOT recovered yet.  Both arms therefore run IDENTICAL stubs for
them.  A green run proves this body's dispatch, ordering and slot arithmetic -
it says nothing about those callees, and it is not device equivalence.

Gates:
  * identity   every case identical on both arms on all three facets (return
               value, the 16 destination bytes, the ordered call log)
  * coverage   each of the body's decisions is actually taken (see COVER)
  * repeat     both arms rerun in a second process reproduce their records
  * teeth      every -DMUTANT source rewrite is caught by at least one case;
               a green mutant means the case set does not exercise that
               decision, so the identity above is worthless.

Teeth attribution: a mutant that walks off mapped memory kills the case batch
at the first such case.  That crash is re-diagnosed one case per process, so
the crashing cases are named as crashes and every other case is still judged
field by field (mode `mismatch+driver-abort`).  A mutant whose only symptom is
a crash keeps the `driver-abort` label - it is discrimination, but weaker: the
case set cannot say which field moved.

Usage:
  python3 var_direct_diff.py            # build, run both arms, write receipt
  python3 var_direct_diff.py --no-run   # replay gates on the last receipt
"""
import argparse
import hashlib
import json
import pathlib
import struct
import subprocess
import sys
import time
from typing import NamedTuple

HERE = pathlib.Path(__file__).resolve().parent
RV1 = HERE.parent
MOD = RV1 / 'c' / 'variable_direct'
BUILD = HERE / 'build'
RECEIPTS = HERE / 'receipts'
sys.path.insert(0, str(HERE))
from handler_oracle import Oracle  # noqa: E402
from unicorn import UC_HOOK_CODE  # noqa: E402
from unicorn.arm_const import (  # noqa: E402
    UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_PC, UC_ARM_REG_LR)

PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
ENTRY = 0x1f3b8c
GET_RVALUE = 0xd13bc
INT_GET_YYVAR = 0x196a70
GOT_BVAR = 0x3edc40

NSLOTS = 256
NBVAR = 10000
STRIDE = 16
VARID_SLOT_BASE = 100000
INT_MIN = -0x80000000
MARK_BYTE = 0xA0
TAG_ARRAY = 2      # RValue tag word for an array slot (staged, read by nobody)


# ── cases ────────────────────────────────────────────────────────────────────
class Case(NamedTuple):
    """One input tuple.  slot_tag is staged at +0 of the resolved slot.

    slot_tag exists so the arrindex cases really are array slots (tag 2) rather
    than scalar slots with a strange index; it is inert here - both arms' GET_RValue
    stubs ignore the tag, so it cannot influence the verdict - and it is listed
    as such in the receipt.  It is staged anyway because that is the slot shape
    an arrindex is supposed to mean, and a future non-stub GET_RValue will read it.
    """

    varid: int
    arrindex: int
    flag24: int
    table_mode: int
    intget_slot: int
    slot_tag: int
    label: str

    def args(self):
        return (self.varid, self.arrindex, self.flag24, self.table_mode,
                self.intget_slot, self.slot_tag)

    def as_dict(self):
        return dict(self._asdict())


def cases():
    """Deterministic; the same list, in the same order, on every rerun.

    Labels carry the arithmetic the case is supposed to pin, because three of
    the original labels were wrong (see CASE_LABEL_CORRECTIONS): varid 10000 is
    NOT slot 0, it is slot 10000-100000 = -90000.
    """
    return [
        Case(0, INT_MIN, 1, 1, 0, 0, 'builtin #0'),
        Case(9999, 0, 1, 1, 0, 0, 'builtin #9999 (<= boundary)'),
        Case(5000, INT_MIN, 1, 1, 0, 0, 'builtin #5000, array index INT_MIN'),
        Case(10000, INT_MIN, 1, 1, 0, 0,
             'varid 10000 -> slot -90000, delta -1440000 (label was "slot 0")'),
        Case(10007, 3, 1, 1, 0, 0,
             'varid 10007 -> slot -89993, delta -1439888, array index 3 '
             '(label was "slot 7")'),
        Case(10000, INT_MIN, 0, 1, 0, 0, 'flag 0 -> return 0, out untouched'),
        Case(10000, INT_MIN, 1, 0, 5, 0, 'table NULL -> InternalGetYYVar'),
        Case(10050, 7, 1, 0, 0, 0, 'table NULL, slot -89950, array index 7'),
        Case(99999, INT_MIN, 1, 1, 0, 0, 'slot -1 -> address BELOW the table'),
        Case(-1, INT_MIN, 1, 1, 0, 0, 'negative varid -> slot path (unsigned bls)'),
        Case(100000, INT_MIN, 1, 1, 0, 0, 'exactly 100000 -> slot 0'),
        # The unguarded gap [10001, 99999]: no rejection, negative slot index,
        # address BELOW the staged table.  Two points inside the gap pin the
        # delta, not just its sign, so a later stride/base "fix" cannot pass.
        Case(50000, INT_MIN, 1, 1, 0, 0,
             'gap varid 50000 -> slot -50000, delta -800000'),
        Case(99998, INT_MIN, 1, 1, 0, 0, 'gap varid 99998 -> slot -2, delta -32'),
        # Real in-table cells (varid = 100000 + slot).  Before this, every
        # slot-path case sat at slot -9xxxx, so the table's own 16 B cells were
        # never addressed and the swap mutant could only be caught by a crash.
        Case(100255, INT_MIN, 1, 1, 0, 0,
             'slot 255, last 16 B cell of the table (+4080)'),
        # arrindex domain edges over an array-typed slot (tag 2).  The value of
        # an array slot is consumed by GET_RValue; the body must hand the index
        # through untouched, including the 0x7fffffff edge.
        Case(100000, INT_MIN, 1, 1, 0, TAG_ARRAY,
             'slot 0 (tag 2 array), arrindex INT_MIN (scalar sentinel)'),
        Case(100000, 0, 1, 1, 0, TAG_ARRAY, 'slot 0 (tag 2 array), arrindex 0'),
        Case(100000, 1, 1, 1, 0, TAG_ARRAY, 'slot 0 (tag 2 array), arrindex 1'),
        Case(100000, 0x7fffffff, 1, 1, 0, TAG_ARRAY,
             'slot 0 (tag 2 array), arrindex 0x7fffffff'),
        # obj[+0x24] non-zero but obj[+4] NULL and varid exactly 100000: the
        # lazy path must be entered with slot 0, not with a leftover index.
        Case(100000, INT_MIN, 4, 0, 0, 0,
             'flag 4, table NULL, varid 100000 -> lazy slot 0'),
    ]


CASE_LABEL_CORRECTIONS = [
    {'was': 'slot 0, scalar', 'now': 'varid 10000 -> slot -90000, delta -1440000',
     'why': 'varid 10000 is not slot 0: slot = varid - 100000 = -90000, so the '
            'slot address is 1440000 B BELOW the staged table'},
    {'was': 'slot 7, array index 3',
     'now': 'varid 10007 -> slot -89993, delta -1439888, array index 3',
     'why': 'same base error; varid 10007 is slot -89993, not slot 7'},
    {'was': 'table NULL, slot 50, array index 7',
     'now': 'table NULL, slot -89950, array index 7',
     'why': 'same base error; InternalGetYYVar received -89950, not 50'},
]


def _gap_negative_slot(r):
    """varid inside [10001,99999] logs exactly (varid-100000)*16 as the offset."""
    c = r['case']
    if not (10001 <= c['varid'] <= 99999):
        return False
    delta = (c['varid'] - VARID_SLOT_BASE) * STRIDE
    return delta < 0 and any(x[0] == 'G' and x[1] == delta for x in r['calls'])


def _last_slot(r):
    """The table's final 16 B cell is addressed (slot 255 -> +4080)."""
    c = r['case']
    want = (NSLOTS - 1) * STRIDE
    return (c['varid'] == VARID_SLOT_BASE + NSLOTS - 1 and
            any(x[0] == 'G' and x[1] == want for x in r['calls']))


def _arrindex_extremes(r):
    """0x7fffffff reaches GET_RValue unchanged (not narrowed, not sign-flipped)."""
    return any(x[0] == 'G' and len(x) > 2 and x[2] == 0x7fffffff
               for x in r['calls'])


COVER = {
    'builtin_path': lambda r: r['calls'] and r['calls'][0][0] == 'B',
    'slot_path_arg': lambda r: any(c[0] == 'G' and c[1] not in ('L', 'NULL')
                                   for c in r['calls']),
    'flag_zero_exit': lambda r: r['ret'] == 0 and not r['calls'],
    'lazy_path': lambda r: any(c[0] == 'I' for c in r['calls']),
    'below_table': lambda r: any(c[0] == 'G' and isinstance(c[1], int) and c[1] < 0
                                 for c in r['calls']),
    'array_index_passthrough': lambda r: any(len(c) > 2 and c[2] not in (INT_MIN,)
                                             for c in r['calls']),
    'gap_negative_slot': _gap_negative_slot,
    'last_slot': _last_slot,
    'arrindex_extremes': _arrindex_extremes,
}


# ── original arm ─────────────────────────────────────────────────────────────
def marker(base):
    return bytes((base + i) & 0xff for i in range(STRIDE))


class OracleStage:
    """One staged environment, hooks installed once.

    Per case only the inputs are rewritten and the call log is cleared.  Adding
    hooks per case would leave the previous case's hooks live on the same
    Unicorn instance, and they would keep appending to their own logs while
    stealing the PC from the new ones.
    """

    def __init__(self, o):
        self.o = o
        self.log = []
        self.intget_called = False
        self.stub = o.alloc(16, 4)
        o.write(self.stub, struct.pack('<I', 0xe12fff1e))   # bx lr: decode ok
        self.bvar = o.alloc(NBVAR * STRIDE)
        blob = bytearray(NBVAR * STRIDE)
        for i in range(NBVAR):
            struct.pack_into('<I', blob, i * STRIDE + 4, self.stub)
        o.write(self.bvar, bytes(blob))
        o.write(GOT_BVAR, struct.pack('<I', self.bvar))
        self.obj = o.alloc(0x40)
        self.table = o.alloc(NSLOTS * STRIDE)
        self.lazy = o.alloc(STRIDE)
        self.out = o.alloc(STRIDE)
        for addr, fn in ((GET_RVALUE, self.hook_get),
                         (INT_GET_YYVAR, self.hook_int),
                         (self.stub, self.hook_stub)):
            o.uc.hook_add(UC_HOOK_CODE, fn, begin=addr, end=addr)

    def hook_get(self, uc_, _a, _s, _d):
        dst = uc_.reg_read(UC_ARM_REG_R0)
        src = uc_.reg_read(UC_ARM_REG_R1)
        axi = to_i32(uc_.reg_read(UC_ARM_REG_R2))
        if src == 0:
            self.log.append(['G', 'NULL', axi, 0x2222])
            base = 0x40
        elif self.intget_called and src == self.lazy:
            self.log.append(['G', 'L', axi, 0x2222])
            base = 0x40
        else:
            off = src - self.table          # signed: a slot below the table is real
            self.log.append(['G', off, axi, 0x2222])
            base = 0x40 + (off & 0x1f)
        self.o.write(dst, marker(base & 0xff))
        uc_.reg_write(UC_ARM_REG_R0, 0x2222)
        uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

    def hook_int(self, uc_, _a, _s, _d):
        slot = to_i32(uc_.reg_read(UC_ARM_REG_R1))
        self.intget_called = True
        self.log.append(['I', slot])
        self.o.write(self.lazy, marker(0x80))
        uc_.reg_write(UC_ARM_REG_R0, self.lazy)
        uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

    def hook_stub(self, uc_, _a, _s, _d):
        axi = to_i32(uc_.reg_read(UC_ARM_REG_R1))
        dst = uc_.reg_read(UC_ARM_REG_R2)
        self.log.append(['B', axi, 0x1111])
        self.o.write(dst, marker(MARK_BYTE))
        uc_.reg_write(UC_ARM_REG_R0, 0x1111)
        uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

    def run(self, case):
        o = self.o
        varid, arrindex, flag24, table_mode, intget_slot, slot_tag = case.args()
        o.write(self.obj, b'\0' * 0x40)
        o.write(self.obj + 4, struct.pack('<I', self.table if table_mode else 0))
        o.write(self.obj + 0x24, struct.pack('<I', flag24 & 0xffffffff))
        o.write(self.table, b'\x5c' * (NSLOTS * STRIDE))
        o.write(self.lazy, b'\0' * STRIDE)
        o.write(self.out, b'\xee' * STRIDE)
        if slot_tag and table_mode:
            slot = varid - VARID_SLOT_BASE
            if 0 <= slot < NSLOTS:     # only inside the staged table
                o.write(self.table + slot * STRIDE, struct.pack('<I', slot_tag))
        self.log.clear()
        self.intget_called = False
        ret = o.call(ENTRY, r0=self.obj, r1=varid & 0xffffffff,
                     r2=arrindex & 0xffffffff, r3=self.out)
        return {'ret': to_i32(ret), 'out': bytes(o.read(self.out, STRIDE)).hex(),
                'calls': list(self.log), 'case': case.as_dict()}


def to_i32(v):
    return struct.unpack('<i', struct.pack('<I', v & 0xffffffff))[0]


# ── claim arm ────────────────────────────────────────────────────────────────
ARM_FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm',
             '-mfpu=vfpv3', '-mfloat-abi=softfp', '-std=c11', '-ffreestanding',
             '-fno-builtin', '-ffp-contract=off', '-fstack-protector-strong',
             '-mstack-protector-guard=global', '-ffunction-sections',
             '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
             '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,main']


def build_c(out_bin, mutant=None):
    """Build the claim arm for ARMv7 and run it under qemu-arm, so a pointer is
    4 bytes and the builtin table entry really keeps its getter at +4."""
    BUILD.mkdir(parents=True, exist_ok=True)
    src = MOD / 'src' / 'variable_direct.c'
    if mutant:
        text = src.read_text()
        for old, new in mutant['edits']:
            if text.count(old) != 1:
                raise RuntimeError('mutation site not unique: %r' % old)
            text = text.replace(old, new)
        src = BUILD / ('mut_%s.c' % mutant['name'])
        src.write_text(text)
    cmd = (['clang'] + ARM_FLAGS +
           ['-O1', '-I', str(MOD / 'src'), str(src),
            str(MOD / 'fixture' / 'driver.c'), '-o', str(out_bin)])
    p = subprocess.run(cmd, capture_output=True, text=True)
    if p.returncode:
        raise RuntimeError('build failed: %s' % p.stderr[-3000:])
    return out_bin


def run_c_arm(binary, case_list):
    blob = ''.join('%d %d %d %d %d %d\n' % tuple(c.args())
                   for c in case_list).encode()
    p = subprocess.run(['qemu-arm', str(binary)], input=blob, capture_output=True)
    if p.returncode:
        raise RuntimeError('driver exit %d: %s' % (p.returncode,
                                                   p.stderr.decode()[-2000:]))
    recs, cur = [], None
    for line in p.stdout.decode().splitlines():
        parts = line.split()
        if not parts:
            continue
        if parts[0] == 'CASE':
            cur = {'ret': 0, 'out': '', 'calls': []}
            recs.append(cur)
        elif parts[0] == 'RET':
            cur['ret'] = int(parts[1])
        elif parts[0] == 'OUT':
            cur['out'] = parts[1]
        elif parts[0] == 'CALLS':
            cur['ncalls'] = int(parts[1])
        elif parts[0] == 'B':
            cur['calls'].append(['B', int(parts[1]), int(parts[2])])
        elif parts[0] == 'G':
            arg = parts[1]
            arg = arg if arg in ('L', 'NULL') else int(arg)
            cur['calls'].append(['G', arg, int(parts[2]), int(parts[3])])
        elif parts[0] == 'I':
            cur['calls'].append(['I', int(parts[1])])
    return recs


def norm_c(rec):
    """The C driver prints `0` for a NULL src offset; keep the shapes aligned."""
    calls = []
    for c in rec['calls']:
        calls.append(c)
    return {'ret': rec['ret'], 'out': rec['out'], 'calls': calls}


# ── teeth ────────────────────────────────────────────────────────────────────
MUTANTS = [
    {'name': 'builtin_boundary_lt', 'edits': [
        ('if ((u32)v <= (u32)VARID_BUILTIN_MAX) {',
         'if ((u32)v < (u32)VARID_BUILTIN_MAX) {')]},
    {'name': 'drop_flag_zero_exit', 'edits': [
        ('if (rd(obj, YYB_VAR_FLAG) == 0)', 'if (0)')]},
    {'name': 'slot_stride_16_to_8', 'edits': [
        ('(int32_t)slot * RV_SLOT_STRIDE', '(int32_t)slot * 8')]},
    {'name': 'get_rvalue_args_swapped', 'edits': [
        ('return GET_RValue(out, src, arrindex);',
         'return GET_RValue(src, out, arrindex);')]},
    {'name': 'lazy_path_uses_table_math', 'edits': [
        ('src = InternalGetYYVar(obj, slot);',
         'src = (unsigned char *)table + (intptr_t)((int32_t)slot * RV_SLOT_STRIDE);')]},
    {'name': 'bvar_entry_stride_16_to_4', 'edits': [
        ('(u32)v * RV_SLOT_STRIDE', '(u32)v * 4')]},
]

# Why a mutant has no field-level catch, when it has none.  Recorded per mutant
# so the weaker `driver-abort` mode is explained rather than folklore.
MUTANT_NOTES = {
    'bvar_entry_stride_16_to_4': (
        'not reachable as a field mismatch in this fixture: all 10000 builtin '
        'entries carry the SAME stub, so landing on entry varid*4 instead of '
        'varid*16 still yields a callable fn pointer whenever varid*4+4 is a +4 '
        'word - only varid 9999 (word at base+39996 is a name field, value 0) '
        'faults on the indirect call, and that abort is what discriminates the '
        'mutant.  A field-level catch needs distinct per-entry getters, and a '
        'stub cannot report which entry it was reached through without them.'),
}


def same3(a, b):
    """The only equality this file accepts: return value, all 16 OUT bytes, the
    ordered call log.  'Not comparable' is never a pass."""
    return a['ret'] == b['ret'] and a['out'] == b['out'] and a['calls'] == b['calls']


def _digest(recs):
    return hashlib.sha256(json.dumps(
        [{k: r[k] for k in ('ret', 'out', 'calls')} for r in recs],
        sort_keys=True).encode()).hexdigest()


def _sample(case, a, r):
    """The facets that actually moved, so a field-level tooth is auditable
    without re-running the mutant."""
    return {'case': case.label,
            'ret': {'original': a['ret'], 'mutant': r['ret']},
            'out': {'original': a['out'], 'mutant': r['out']},
            'calls': {'original': a['calls'], 'mutant': r['calls']}}


def teeth_one(m, case_list, a_recs):
    """Judge one mutant.  A batch that aborts is re-diagnosed one case per
    process: the crash belongs to the cases that crash, and each surviving case
    is still compared on all three fields."""
    b = build_c(BUILD / ('mut_%s.arm' % m['name']), mutant=m)
    batch_detail = None
    try:
        recs = [norm_c(r) for r in run_c_arm(b, case_list)]
    except RuntimeError as exc:
        recs = None
        batch_detail = str(exc).splitlines()[0][:200]

    if recs is not None:
        caught, sample = [], None
        for c, a, r in zip(case_list, a_recs, recs):
            if not same3(a, r):
                caught.append(c.label)
                if sample is None:
                    sample = _sample(c, a, r)
        return {'mutant': m['name'], 'caught_by': caught, 'aborted_cases': [],
                'mode': 'mismatch', 'field_level': True, 'passed': bool(caught),
                'sample_mismatch': sample}

    caught, aborted, detail, sample = [], [], {}, None
    for c, a in zip(case_list, a_recs):
        try:
            r = norm_c(run_c_arm(b, [c])[0])
        except RuntimeError as exc:
            aborted.append(c.label)
            detail[c.label] = str(exc).splitlines()[0][:120]
            continue
        if not same3(a, r):
            caught.append(c.label)
            if sample is None:
                sample = _sample(c, a, r)
    rec = {'mutant': m['name'], 'caught_by': caught, 'aborted_cases': aborted,
           'mode': 'mismatch+driver-abort' if caught else 'driver-abort',
           'field_level': bool(caught), 'passed': bool(caught or aborted),
           'batch_detail': batch_detail, 'abort_detail': detail,
           'sample_mismatch': sample}
    if not caught:
        rec['note'] = ('discrimination is by abort, not by a field mismatch - '
                       'weaker than a mismatch tooth; the case set cannot say '
                       'WHICH field moved')
        if m['name'] in MUTANT_NOTES:
            rec['why_not_field_level'] = MUTANT_NOTES[m['name']]
    return rec


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--run', action='store_true')
    ap.add_argument('--no-run', action='store_true')
    ap.add_argument('--out', type=pathlib.Path)
    args = ap.parse_args()

    RECEIPTS.mkdir(parents=True, exist_ok=True)
    BUILD.mkdir(parents=True, exist_ok=True)
    case_list = cases()

    if args.no_run:
        last = sorted(RECEIPTS.glob('var_direct_diff-*.json'))[-1]
        d = json.loads(last.read_text())
        print('RESULT %s (replayed %s)' % (d['status'], last.name))
        return 0 if d['status'] == 'PASS' else 1

    # claim arm: baseline
    base_bin = build_c(BUILD / 'var_direct.arm')
    c_recs = [norm_c(r) for r in run_c_arm(base_bin, case_list)]

    # judge arm
    stage = OracleStage(Oracle())
    a_recs = [stage.run(c) for c in case_list]

    rows, mismatches = [], []
    for case, a, c in zip(case_list, a_recs, c_recs):
        same = same3(a, c)
        rows.append({'case': case.as_dict(), 'original': a, 'rebuild': c,
                     'equal': same})
        if not same:
            mismatches.append({'case': case.as_dict(), 'original': a,
                               'rebuild': c})

    # repeat: a second process and a second Unicorn instance must reproduce the
    # records.  Both arms are rerun, not just the C one - the judge arm keeps
    # staged memory alive across cases, so a leak there would show up only on
    # the second pass through the same case.
    stage2 = OracleStage(Oracle())
    a2 = [stage2.run(c) for c in case_list]
    c2 = [norm_c(r) for r in run_c_arm(base_bin, case_list)]
    repeat = {
        'runs_per_arm': 2,
        'rerun_kind': {'original': 'second Unicorn instance, same case order',
                       'rebuild': 'second qemu-arm process, same stdin blob'},
        'original_identical': all(same3(x, y) for x, y in zip(a_recs, a2)),
        'rebuild_identical': all(same3(x, y) for x, y in zip(c_recs, c2)),
        'original_log_sha256': [_digest(a_recs), _digest(a2)],
        'rebuild_log_sha256': [_digest(c_recs), _digest(c2)],
        'note': 'identical digests inside an arm are the repeatability evidence; '
                'the two arms agreeing with each other is the identity gate',
    }
    rep_ok = repeat['original_identical'] and repeat['rebuild_identical']

    coverage = {k: any(fn(r) for r in a_recs) for k, fn in COVER.items()}
    teeth = [teeth_one(m, case_list, a_recs) for m in MUTANTS]

    identity = not mismatches
    cov_ok = all(coverage.values())
    teeth_ok = all(t['passed'] for t in teeth)
    status = 'PASS' if (identity and cov_ok and rep_ok and teeth_ok) else 'FAIL'

    receipt = {
        'schema': 'cally-var-direct-diff/2',
        'schema_changes_from_v1': [
            "rows[].case is now an object keyed by field name (was a positional "
            "array with the label last)",
            'new top-level keys: repeat, findings, case_label_corrections; '
            'scope.inert_staging',
            "teeth[]: aborted_cases, field_level, mode 'mismatch+driver-abort', "
            'why_not_field_level',
        ],
        'generated_utc': time.strftime('%Y-%m-%dT%H:%M:%SZ', time.gmtime()),
        'tier': 'oracle_anchored',
        'original_executed': True,
        'evidence_layer': ('synthetic memory oracle: the original ARM bytes at '
                           '0x1f3b8c executed over a staged object/slot table with '
                           'identical stubs on both arms; NOT device execution'),
        'BINDING': {
            'original_sha256': PIN,
            'entry': hex(ENTRY),
            'function': '_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue',
            'body_sha256': hashlib.sha256(
                (MOD / 'src' / 'variable_direct.c').read_bytes()).hexdigest(),
            'driver_sha256': hashlib.sha256(
                (MOD / 'fixture' / 'driver.c').read_bytes()).hexdigest(),
            'stub_callees': ['GET_RValue@0xd13bc',
                             'YYObjectBase::InternalGetYYVar@0x196a70',
                             'builtin var table entry fn'],
        },
        'scope': {
            'covered': ['varid<=9999 builtin table dispatch',
                        'flag[+0x24]==0 early exit, out untouched',
                        'slot address = table + (varid-100000)*16',
                        'table==NULL lazy path through InternalGetYYVar',
                        'arrindex passthrough to both callees (INT_MIN, 0, 1, '
                        '0x7fffffff)',
                        'unguarded varid gap [10001,99999] -> negative slot '
                        'delta (-800000 at varid 50000, -32 at 99998)',
                        'in-table cells: slot 0 (100000) and slot 255 (100255, '
                        'last cell, +4080)',
                        'flag[+0x24]!=0 with table==NULL at varid 100000 -> '
                        'lazy slot 0',
                        'second-run reproducibility of both arms'],
            'not_covered': ['GET_RValue semantics (stubbed on both arms)',
                            'InternalGetYYVar semantics (stubbed)',
                            'builtin getter semantics (stubbed)',
                            'device behaviour'],
            'inert_staging': ['slot_tag word at +0 of the resolved slot (tag 2 '
                              'for the arrindex cases): staged identically on '
                              'both arms, read by neither GET_RValue stub, so '
                              'it cannot move the verdict'],
        },
        'findings': [
            'three case labels were wrong about the slot base: varid 10000 / '
            '10007 / 10050 are slots -90000 / -89993 / -89950, not 0 / 7 / 50 '
            '(VARID_SLOT_BASE is 100000).  Labels corrected, arithmetic and '
            'inputs untouched.',
            'consequence: before this change no case addressed a table cell of '
            'the slot table at all (every slot-path case was at slot -9xxxx or '
            'below), which is why get_rvalue_args_swapped could only be caught '
            'by a segfault.',
            'the gap [10001,99999] is confirmed unguarded on the original '
            'bytes: valid flag + non-NULL table + varid 50000 reaches '
            'GET_RValue with a slot address 800000 B BELOW the table.',
        ],
        'case_label_corrections': CASE_LABEL_CORRECTIONS,
        'repeat': repeat,
        'cases': len(case_list),
        'rows': rows,
        'coverage': coverage,
        'teeth': teeth,
        'status': status,
    }
    out = args.out or (RECEIPTS / ('var_direct_diff-%s.json'
                                   % time.strftime('%Y%m%dT%H%M%S')))
    out.write_text(json.dumps(receipt, ensure_ascii=False, indent=1))

    print('RESULT %s  cases=%d identical=%d' % (status, len(case_list),
                                                sum(1 for r in rows if r['equal'])))
    print('  REPEAT second-run identical  original=%s rebuild=%s' % (
        'yes' if repeat['original_identical'] else 'NO',
        'yes' if repeat['rebuild_identical'] else 'NO'))
    for k, v in coverage.items():
        print('  COVER %-26s %s' % (k, 'yes' if v else 'NO'))
    for t in teeth:
        print('  TEETH %-28s %s caught_by=%d mode=%s aborted=%d' % (
            t['mutant'], 'PASS' if t['passed'] else 'FAIL',
            len(t['caught_by']), t['mode'], len(t['aborted_cases'])))
    for m in mismatches[:6]:
        print('  DIFF case=%r' % (m['case']['label'],))
        print('    original', m['original'])
        print('    rebuild ', m['rebuild'])
    print('  receipt=%s' % out)
    return 0 if status == 'PASS' else 1


if __name__ == '__main__':
    sys.exit(main())
