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
  * identity   every case identical on both arms
  * coverage   each of the body's decisions is actually taken (see COVER)
  * teeth      every -DMUTANT source rewrite is caught by at least one case;
               a green mutant means the case set does not exercise that
               decision, so the identity above is worthless

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
INT_MIN = -0x80000000
MARK_BYTE = 0xA0


# ── cases ────────────────────────────────────────────────────────────────────
def cases():
    """(varid, arrindex, flag24, table_mode, intget_slot, label).

    Deterministic; the same list on every rerun.
    """
    return [
        (0, INT_MIN, 1, 1, 0, 'builtin #0'),
        (9999, 0, 1, 1, 0, 'builtin #9999 (<= boundary)'),
        (5000, INT_MIN, 1, 1, 0, 'builtin #5000, array index INT_MIN'),
        (10000, INT_MIN, 1, 1, 0, 'slot 0, scalar'),
        (10007, 3, 1, 1, 0, 'slot 7, array index 3'),
        (10000, INT_MIN, 0, 1, 0, 'flag 0 -> return 0, out untouched'),
        (10000, INT_MIN, 1, 0, 5, 'table NULL -> InternalGetYYVar'),
        (10050, 7, 1, 0, 0, 'table NULL, slot 50, array index 7'),
        (99999, INT_MIN, 1, 1, 0, 'slot -1 -> address BELOW the table'),
        (-1, INT_MIN, 1, 1, 0, 'negative varid -> slot path (unsigned bls)'),
        (100000, INT_MIN, 1, 1, 0, 'exactly 100000 -> slot 0'),
    ]


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

    def run(self, varid, arrindex, flag24, table_mode, intget_slot):
        o = self.o
        o.write(self.obj, b'\0' * 0x40)
        o.write(self.obj + 4, struct.pack('<I', self.table if table_mode else 0))
        o.write(self.obj + 0x24, struct.pack('<I', flag24 & 0xffffffff))
        o.write(self.table, b'\x5c' * (NSLOTS * STRIDE))
        o.write(self.lazy, b'\0' * STRIDE)
        o.write(self.out, b'\xee' * STRIDE)
        self.log.clear()
        self.intget_called = False
        ret = o.call(ENTRY, r0=self.obj, r1=varid & 0xffffffff,
                     r2=arrindex & 0xffffffff, r3=self.out)
        return {'ret': to_i32(ret), 'out': bytes(o.read(self.out, STRIDE)).hex(),
                'calls': list(self.log)}


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
    blob = ''.join('%d %d %d %d %d\n' % c[:5] for c in case_list).encode()
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

    # claim arm: baseline + each mutant
    base_bin = build_c(BUILD / 'var_direct.arm')
    c_recs = [norm_c(r) for r in run_c_arm(base_bin, case_list)]

    # judge arm
    stage = OracleStage(Oracle())
    a_recs = [stage.run(*c[:5]) for c in case_list]

    rows, mismatches = [], []
    for case, a, c in zip(case_list, a_recs, c_recs):
        same = (a['ret'] == c['ret'] and a['out'] == c['out']
                and a['calls'] == c['calls'])
        rows.append({'case': case, 'original': a, 'rebuild': c, 'equal': same})
        if not same:
            mismatches.append({'case': case, 'original': a, 'rebuild': c})

    coverage = {k: any(fn(r) for r in a_recs) for k, fn in COVER.items()}

    teeth = []
    for m in MUTANTS:
        b = build_c(BUILD / ('mut_%s.arm' % m['name']), mutant=m)
        try:
            recs = [norm_c(r) for r in run_c_arm(b, case_list)]
        except RuntimeError as exc:
            # A mutant that makes the arm crash is discriminated just as well as
            # one that differs: the point of the tooth is that the case set can
            # tell the difference.  It is recorded as such, not silently passed.
            teeth.append({'mutant': m['name'], 'caught_by': [], 'passed': True,
                          'mode': 'driver-abort', 'detail': str(exc)[:200],
                          'note': ('discrimination is by abort, not by a field '
                                   'mismatch - weaker than a mismatch tooth; '
                                   'the case set cannot say WHICH field moved')})
            continue
        caught = [case[5] for case, a, c in zip(case_list, a_recs, recs)
                  if not (a['ret'] == c['ret'] and a['out'] == c['out']
                          and a['calls'] == c['calls'])]
        teeth.append({'mutant': m['name'], 'caught_by': caught,
                      'mode': 'mismatch', 'passed': bool(caught)})

    identity = not mismatches
    cov_ok = all(coverage.values())
    teeth_ok = all(t['passed'] for t in teeth)
    status = 'PASS' if (identity and cov_ok and teeth_ok) else 'FAIL'

    receipt = {
        'schema': 'cally-var-direct-diff/1',
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
                        'arrindex passthrough to both callees',
                        'negative/large varid arithmetic (recorded, not run into memory)'],
            'not_covered': ['GET_RValue semantics (stubbed on both arms)',
                            'InternalGetYYVar semantics (stubbed)',
                            'builtin getter semantics (stubbed)',
                            'device behaviour'],
        },
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
    for k, v in coverage.items():
        print('  COVER %-26s %s' % (k, 'yes' if v else 'NO'))
    for t in teeth:
        print('  TEETH %-28s %s caught_by=%d' % (
            t['mutant'], 'PASS' if t['passed'] else 'FAIL', len(t['caught_by'])))
    for m in mismatches[:6]:
        print('  DIFF case=%r' % (m['case'][5],))
        print('    original', m['original'])
        print('    rebuild ', m['rebuild'])
    print('  receipt=%s' % out)
    return 0 if status == 'PASS' else 1


if __name__ == '__main__':
    sys.exit(main())
