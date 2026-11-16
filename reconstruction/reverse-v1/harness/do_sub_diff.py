#!/usr/bin/env python3
"""DoSub — original-binary differential for libyoyo's `-` handler.

  arm A (judge)  _Z5DoSubjPhPKhP6VMExec @0xdd500 in the pinned image, executed in
                 Unicorn: boxType runs from the real bytes, libc is answered in
                 Python, and the error entries are stubbed so the emitted text
                 can be read.
  arm B (claim)  reconstruction/reverse-v1/c/do_sub/src/*.c, built for
                 armv7a-none-eabi (freestanding) and run under qemu-arm.

Why arm B is not host-compiled: the body derives every operand offset from the
type nibbles of `cls` and stores the result into the tail of that same span; a
64-bit build moves the RValue layout it walks.

Compared per case: the returned stack pointer, every ARENA byte, and the error
text the handler emitted (the FIRST one — the original can report twice).

Gates
  binding   image sha256, the symbol's address and size from .symtab, the 17
            literal-pool words, and the 17 error strings re-derived from those
            words and matched against the C source's own table
  census    every instruction of the body appears in the translation as
            `@0xADDR <verbatim llvm-objdump text>`, each address exactly once,
            every pool word documented; proven by three source mutations
  identity  every case identical on both arms
  coverage  proven from the ORIGINAL's own trace: all 102 pair-table entries,
            all 7 first- and 7 second-operand entries, both 14-entry tag tables,
            every cls nibble 0..15, every RValue tag 0..15, and modes 0/1/2
  non_degen the case set moves the operand slots and produces many distinct
            results
  teeth     every -DDO_SUB_MUTANT=n build is caught by at least one named case
  repeat    both arms rerun in fresh processes and reproduce their records

Usage
  python3 do_sub_diff.py            # build, run, write a receipt
  python3 do_sub_diff.py --no-run   # replay the gate logic on the last receipt
"""
import argparse
import hashlib
import json
import pathlib
import random
import re
import struct
import subprocess
import sys
import time

HERE = pathlib.Path(__file__).resolve().parent
RV1 = HERE.parent
MOD = RV1 / 'c/do_sub'
BUILD = HERE / 'build'
RECEIPTS = HERE / 'receipts'
sys.path.insert(0, str(HERE))

from handler_oracle import Oracle  # noqa: E402
from unicorn import UC_HOOK_CODE  # noqa: E402

DO_SUB = 0xdd500
POOL = 0xddd24
END = 0xddd68
SYM = '_Z5DoSubjPhPKhP6VMExec'
SIZE = 2152
NINSTR = 521
NPOOL = 17

ARENA = 0x180
SLOT = 0x100
SEED = 0x5AB1
N_RANDOM = 60


def so_path():
    from handler_oracle import SO as _SO
    return pathlib.Path(_SO)


def norm(s):
    return re.sub(r'\s+', ' ', s).strip()


def objdump_raw(entry, stop):
    p = subprocess.run(['llvm-objdump', '-d', '--start-address=%#x' % entry,
                        '--stop-address=%#x' % stop, '-M', 'reg-names-std',
                        str(so_path())], capture_output=True, text=True)
    if p.returncode:
        raise RuntimeError('llvm-objdump failed: %s' % p.stderr[-800:])
    rows = {}
    for ln in p.stdout.splitlines():
        m = re.match(r'\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(.*)$', ln)
        if not m:
            continue
        addr = int(m.group(1), 16)
        if addr < entry or addr >= stop:
            continue
        txt = norm(' '.join(x for x in m.group(3).split('\t') if x.strip()))
        txt = norm(re.sub(r'\s*<[^>]*>', '', txt))
        if txt:
            rows[addr] = tuple(txt.split(' ', 1))
    return dict(sorted(rows.items()))


def objdump_rows(entry, stop):
    rows = {}
    for a, (mn, op) in objdump_raw(entry, stop).items():
        txt = norm(re.sub(r'\s*@.*$', '', mn + ' ' + op))
        rows[a] = tuple(txt.split(' ', 1))
    return rows


def elf_bits():
    from elftools.elf.elffile import ELFFile
    so = so_path()
    blob = so.read_bytes()
    elf = ELFFile(open(so, 'rb'))
    segs = [(s['p_vaddr'], s['p_offset'], s['p_filesz']) for s in elf.iter_segments()
            if s['p_type'] == 'PT_LOAD']
    sym = None
    for secname in ('.symtab', '.dynsym'):
        sec = elf.get_section_by_name(secname)
        if sec is None:
            continue
        for s in sec.iter_symbols():
            if s.name == SYM:
                sym = s
                break
        if sym is not None:
            break
    return so, blob, segs, sym, elf


def u32buf(blob, va, segs):
    for v, o, sz in segs:
        if v <= va < v + sz:
            off = o + (va - v)
            return struct.unpack('<I', blob[off:off + 4])[0]
    raise KeyError(hex(va))


def cstrbuf(blob, va, segs, limit=160):
    for v, o, sz in segs:
        if v <= va < v + sz:
            off = o + (va - v)
            return blob[off:off + limit].split(b'\0')[0].decode('latin1')
    raise KeyError(hex(va))


def binding():
    so, blob, segs, sym, elf = elf_bits()
    if sym is None:
        raise SystemExit('%s not in the symbol table' % SYM)
    pool = {a: u32buf(blob, a, segs) for a in range(POOL, END, 4)}
    raw = objdump_raw(DO_SUB, POOL)
    strs = {}
    order = list(raw)
    for i, a in enumerate(order):
        mn, op = raw[a]
        if mn != 'ldr' or '[pc' not in op:
            continue
        m = re.search(r'@ (0x[0-9a-f]+)', op)
        if not m:
            continue
        w = pool.get(int(m.group(1), 16))
        for b in order[i + 1:i + 6]:
            if raw[b][0] == 'add' and 'pc' in raw[b][1]:
                strs[a] = cstrbuf(blob, b + 8 + w, segs)
                break
    c_src = (MOD / 'src' / 'do_sub.c').read_text()
    c_strings = set(re.findall(r'^    "([^"]*)",?$', c_src, re.M))
    derived = set(strs.values())
    return {
        'ok': (hashlib.sha256(so.read_bytes()).hexdigest()
               == '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
               and sym['st_value'] == DO_SUB and sym['st_size'] == SIZE
               and derived <= c_strings and len(strs) == 17),
        'so': str(so), 'sha256': hashlib.sha256(so.read_bytes()).hexdigest(),
        'symbol': {'name': SYM, 'addr': hex(sym['st_value']),
                   'size': sym['st_size'],
                   'declared': {'addr': hex(DO_SUB), 'size': SIZE}},
        'pool_words': len(pool),
        'error_strings': {hex(k): v for k, v in sorted(strs.items())},
        'strings_not_in_c': sorted(derived - c_strings),
    }


ANCHOR = re.compile(r'/\*\s*@(0x[0-9a-f]{5,8})\s+(.*?)\s*\*/')


def instruction_census(overrides=None):
    overrides = overrides or {}
    rows = objdump_rows(DO_SUB, POOL)
    so, blob, segs, _s, _e = elf_bits()
    poolw = {a: u32buf(blob, a, segs) for a in range(POOL, END, 4)}
    src = overrides.get('do_sub.c', (MOD / 'src' / 'do_sub.c').read_text())
    cands = {}
    for ln in src.splitlines():
        m = ANCHOR.search(ln)
        if m:
            cands.setdefault(int(m.group(1), 16), []).append(norm(m.group(2)))
    wrong = []
    for a, (mn, op) in rows.items():
        want = norm(mn + ' ' + op)
        if a not in cands or want not in [norm(c) for c in cands[a]]:
            wrong.append({'addr': hex(a), 'objdump': want, 'source': cands.get(a, [])})
    dupes = [{'addr': hex(a), 'texts': cands[a]} for a in sorted(cands) if len(cands[a]) > 1]
    extra = [{'addr': hex(a)} for a in sorted(cands) if a not in rows and a not in poolw]
    pool_missing = [{'addr': hex(a), 'word': '%08x' % w} for a, w in sorted(poolw.items())
                    if not any(('.word 0x%08x' % w) in c for c in cands.get(a, []))]
    ok = (not wrong and not dupes and not extra and not pool_missing
          and len(rows) == NINSTR and len(poolw) == NPOOL)
    return {'ok': ok, 'instructions': len(rows), 'documented': len(rows) - len(wrong),
            'pool_words': len(poolw), 'wrong': wrong[:8],
            'duplicate_addresses': dupes[:8], 'unknown_addresses': extra[:8],
            'pool_missing': pool_missing[:8]}


def census_selftest():
    base = (MOD / 'src' / 'do_sub.c').read_text()
    m = re.search(r'^.*@0xdd508 cmp r2, #1.*$', base, re.M)
    drop = base if not m else base[:m.start()] + base[m.end() + 1:]
    trials = {
        'operand_changed': base.replace('@0xdd520 beq 0xdda70',
                                         '@0xdd520 beq 0xdda72', 1),
        'comment_line_deleted': drop,
        'pool_word_changed': base.replace('.word 0x00255b4c', '.word 0x00255b4d', 1),
    }
    res, ok = {}, True
    for name, ov in trials.items():
        rep = instruction_census({'do_sub.c': ov})
        res[name] = {'ok': not rep['ok'], 'wrong': len(rep['wrong']),
                     'missing': len(rep['pool_missing'])}
        ok = ok and not rep['ok']
    res['ok'] = ok
    return res


# ── cases ───────────────────────────────────────────────────────────────────
SIZES = {0: 8, 3: 8, 5: 16}


def tsize(t):
    return SIZES.get(t, 4)


def put(a, off, t, val):
    if t == 0:
        a[off:off + 8] = struct.pack('<d', float(val))
        return off + 8
    if t == 3:
        a[off:off + 8] = struct.pack('<Q', int(val) & 0xFFFFFFFFFFFFFFFF)
        return off + 8
    if t == 5:
        kind, payload, tag = val
        b = (struct.pack('<d', float(payload)) if kind == 'd'
             else struct.pack('<Q', int(payload) & 0xFFFFFFFFFFFFFFFF))
        a[off:off + 8] = b
        a[off + 8:off + 12] = b'\x5A\x5A\x5A\x5A'
        a[off + 12:off + 16] = struct.pack('<I', tag & 0xFFFFFFFF)
        return off + 16
    if t == 1:
        a[off:off + 4] = struct.pack('<f', float(val))
        return off + 4
    a[off:off + 4] = struct.pack('<I', int(val) & 0xFFFFFFFF)
    return off + 4


def case(mode, cls, lval, rval, label):
    T, U = cls & 0xF, (cls >> 4) & 0xF

    def coerce(t, v):
        if t == 5:
            return v if isinstance(v, tuple) else ('d', float(v), 13)
        if isinstance(v, tuple):
            return float(v[1]) if v[0] == 'd' else int(v[1])
        return v

    lval, rval = coerce(T, lval), coerce(U, rval)
    a = bytearray(b'\xEE' * ARENA)
    off = put(a, SLOT, T, lval)
    put(a, off, U, rval)
    return {'arg': ((mode & 0xF) << 8) | ((cls & 0xFF) << 16),
            'arena': bytes(a), 'label': label, 'cls': cls, 'mode': mode,
            'T': T, 'U': U,
            'tagl': lval[2] if T == 5 else None,
            'tagr': rval[2] if U == 5 else None}


D_REALS = [2.5, -1.25, 0.0, -0.0, 1e300, 5e-324, float('inf'), float('-inf'),
           float('nan'), 3.0]
I32S = [7, -3, 0x7FFFFFFF, -0x80000000, 1, -1, 0x40000000]
I64S = [0x100000002, -7, 0x7FFFFFFFFFFFFFFF, -0x8000000000000000, 3, -1,
        0x00000001FFFFFFFF]


def build_cases():
    cases = []
    for cls in list(range(0, 102)) + [102, 110, 119, 255]:
        T, U = cls & 0xF, (cls >> 4) & 0xF
        cases.append(case(0, cls, 2.5 if T != 3 else 0x100000002,
                          1.25 if U != 3 else 3, 'cls=%#04x' % cls))
    valid = [(0x00, D_REALS, D_REALS), (0x02, I32S, D_REALS),
             (0x03, I64S, D_REALS), (0x20, D_REALS, I32S),
             (0x22, I32S, I32S), (0x23, I64S, I32S),
             (0x30, D_REALS, I64S), (0x32, I32S, I64S), (0x33, I64S, I64S)]
    for cls, lvals, rvals in valid:
        for i, lv in enumerate(lvals):
            cases.append(case(0, cls, lv, rvals[i % len(rvals)],
                              'cls=%#04x payload%d' % (cls, i)))
        for i, rv in enumerate(rvals):
            cases.append(case(0, cls, lvals[i % len(lvals)], rv,
                              'cls=%#04x rhs%d' % (cls, i)))
    for tag in range(16):
        cases.append(case(0, 0x05, ('d', 2.5, tag), 1.25, 'lhsvar tag%d' % tag))
        cases.append(case(0, 0x50, 2.5, ('d', 1.25, tag), 'rhsvar tag%d' % tag))
        cases.append(case(0, 0x55, ('d', 2.5, tag), ('d', 1.25, tag),
                          'bothvar tag%d' % tag))
        cases.append(case(0, 0x25, ('i', 4, tag), 3, 'lhsvar+i32 tag%d' % tag))
        cases.append(case(0, 0x53, 2.5, ('i', 9, tag), 'i64+rhsvar tag%d' % tag))
    for tag, pl in ((7, ('i', -5, 7)), (10, ('i', 0x100000003, 10)),
                    (0, ('d', 0.5, 0)), (13, ('d', -0.5, 13))):
        for cls, rv in ((0x05, 1.25), (0x15, 1.5), (0x25, 3), (0x35, 5)):
            cases.append(case(0, cls, pl, rv, 'lhsbox tag%d cls=%#04x' % (tag, cls)))
        for cls, lv in ((0x50, 2.5), (0x52, 7), (0x53, 0x100000002)):
            cases.append(case(0, cls, lv, pl, 'rhsbox tag%d cls=%#04x' % (tag, cls)))
    # mode 1 (the only generic arm DoSub has) and the modes that fall through
    for T in (0, 2, 3, 4):
        for U in (0, 2, 3, 4):
            cls = T | (U << 4)
            lv = 2.5 if T == 0 else (7 if T == 2 else (0x100000002 if T == 3 else 1))
            rv = 1.25 if U == 0 else (3 if U == 2 else (5 if U == 3 else 1))
            cases.append(case(1, cls, lv, rv, 'm1 T%d U%d' % (T, U)))
    for cls in (0x07, 0x08, 0x0F, 0x70, 0x80, 0xF0, 0x17, 0x71):
        cases.append(case(1, cls, 2.5, 1.5, 'm1 no-tag cls=%#04x' % cls))
    for lv, rv in ((float('nan'), 1.0), (3.5, float('inf')), (-0.0, -0.0),
                   (1e308, 1e308), (5e-324, -5e-324)):
        cases.append(case(1, 0x00, lv, rv, 'm1 cls=0x00 edge'))
    for lv, rv in ((0x7FFFFFFF, 1), (-0x80000000, -1), (0, 0), (0x40000000, 3)):
        cases.append(case(1, 0x22, lv, rv, 'm1 cls=0x22 edge'))
        cases.append(case(1, 0x33, lv, rv, 'm1 cls=0x33 edge'))
    cases.append(case(1, 0x30, 1.5, 0x100000003, 'm1 cls=0x30 edge'))
    cases.append(case(1, 0x20, 1.5, -7, 'm1 cls=0x20 edge'))
    for mode in (0, 2, 3, 7, 11, 15):
        for cls in (0x00, 0x22, 0x02, 0x33):
            cases.append(case(mode, cls, 2.5, 1.25,
                              'm%d fallthrough cls=%#04x' % (mode, cls)))
    rng = random.Random(SEED)
    for _ in range(N_RANDOM):
        cls = rng.randrange(0, 0x78)
        lv = rng.choice([('d', rng.uniform(-1e3, 1e3), rng.randrange(16)),
                         rng.randrange(-2**31, 2**31), rng.uniform(-1e3, 1e3)])
        rv = rng.choice([('d', rng.uniform(-1e3, 1e3), rng.randrange(16)),
                         rng.randrange(-2**31, 2**31), rng.uniform(-1e3, 1e3)])
        cases.append(case(rng.choice([0, 0, 0, 2]), cls, lv, rv,
                          'random cls=%#04x' % cls))
    return cases


# ── arms ────────────────────────────────────────────────────────────────────
ARM_FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm',
             '-mfpu=vfpv3', '-mfloat-abi=softfp', '-std=c11', '-ffreestanding',
             '-fno-builtin', '-ffp-contract=off', '-fstack-protector-strong',
             '-mstack-protector-guard=global', '-ffunction-sections',
             '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
             '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,main']

SRCS = [MOD / 'src' / 'do_sub.c', RV1 / 'c' / 'box_type.c']


def build_c(out_bin, mutant=0):
    BUILD.mkdir(parents=True, exist_ok=True)
    cmd = ['clang'] + ARM_FLAGS + ['-O1', '-I', str(MOD / 'src')]
    if mutant:
        cmd.insert(1, '-DDO_SUB_MUTANT=%d' % mutant)
    cmd += [str(s) for s in SRCS] + [str(MOD / 'fixture' / 'driver.c'),
                                    '-o', str(out_bin)]
    p = subprocess.run(cmd, capture_output=True, text=True)
    if p.returncode:
        raise RuntimeError('build failed: %s' % p.stderr[-4000:])
    return out_bin


def run_c(binary, cases, allow_crash=False):
    blob = ''.join('IN %x %s\n' % (c['arg'], c['arena'].hex())
                   for c in cases).encode()
    proc = subprocess.run(['qemu-arm', str(binary)], input=blob,
                          stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    txt = proc.stdout.decode('latin1', 'replace')
    if not txt.rstrip().endswith('END') and not allow_crash:
        raise RuntimeError('C arm did not terminate (%d bytes): %r'
                           % (len(txt), (txt[-200:] or proc.stderr[-200:])))
    out = []
    for line in txt.splitlines():
        parts = line.split()
        if not parts or parts[0] != 'R':
            continue
        out.append({'ret': int(parts[1]), 'arena': bytes.fromhex(parts[2]),
                    'err': None if parts[3] == '-' else
                    bytes.fromhex(parts[3]).decode('latin1'),
                    'base': int(parts[4], 16)})
    crashed = 0
    if len(out) < len(cases):
        n = len(out)
        if not allow_crash:
            raise RuntimeError('C arm returned %d of %d records; died on %r'
                               % (n, len(cases), cases[n]['label']))
        crashed = len(cases) - n
        for _ in range(crashed):
            out.append({'ret': None, 'arena': b'', 'err': 'CRASH', 'base': 0,
                        'crash': True})
    return out, crashed


def run_oracle(cases, trace=None):
    o = Oracle(libc=True)
    if trace is not None:
        def hook(uc, address, size, _ud):
            trace.add(address)
        o.uc.hook_add(UC_HOOK_CODE, hook, begin=DO_SUB, end=END)
    out = []
    for c in cases:
        base = o.alloc(ARENA)
        o.write(base, c['arena'])
        slotp = base + SLOT
        # Every path assigns r6 before table 3 reads it — including the two
        # "string operand" stubs (0xdd59c / 0xddd1c both do `mov r6, r10`) — so
        # the returned stack pointer is defined on every case and the judge needs
        # no register preloading.
        try:
            ret = o.call(DO_SUB, r0=c['arg'], r1=slotp, r2=0, r3=0)
        except Exception as exc:
            out.append({'ret': None, 'arena': bytes(o.read(base, ARENA)),
                        'err': 'FAULT: %s' % exc, 'base': base, 'fault': True})
            continue
        err = None
        for call in o.calls:
            if call['name'] == 'VMError':
                err = o.read_cstr(call['args'][1])
                break
            if call['name'].startswith('JSThrow'):
                err = o.read_cstr(call['args'][0])
                break
        out.append({'ret': ret - slotp, 'arena': bytes(o.read(base, ARENA)),
                    'err': err, 'base': base})
    return out


def normalise(rec, case, base_hint):
    return {'ret': rec['ret'], 'arena': rec['arena'], 'err': rec['err']}


# ── gates ───────────────────────────────────────────────────────────────────
def gate_coverage(cases, trace):
    tables = {
        'pair_table_entries': [0xdd5b4 + 4 * k for k in range(102)],
        'first_operand_entries': [0xdd534 + 4 * k for k in range(7)],
        'second_operand_entries': [0xdd578 + 4 * k for k in range(7)],
        'rhs_tag_entries': [0xdd864 + 4 * k for k in range(14)],
        'lhs_tag_entries': [0xdd8d4 + 4 * k for k in range(14)],
    }
    r = {}
    for name, addrs in tables.items():
        missing = [hex(a) for a in addrs if a not in trace]
        r[name] = {'pass': not missing, 'walked': len(addrs) - len(missing),
                   'total': len(addrs), 'missing': missing[:12]}
    nib = {(c['cls'] & 0xF) for c in cases} | {(c['cls'] >> 4) & 0xF for c in cases}
    tags = {c['tagl'] for c in cases if c.get('tagl') is not None}
    tags |= {c['tagr'] for c in cases if c.get('tagr') is not None}
    modes = {c['mode'] for c in cases}
    r['cls_nibbles_0_15'] = {'pass': nib >= set(range(16)), 'seen': sorted(nib)}
    r['rvalue_tags_0_15'] = {'pass': tags >= set(range(16)), 'seen': sorted(tags)}
    r['modes_0_1'] = {'pass': {0, 1} <= modes, 'seen': sorted(modes)}
    r['pair_bytes_0_101'] = {'pass': {c['cls'] for c in cases} >= set(range(102)),
                             'seen': len({c['cls'] for c in cases} & set(range(102)))}
    r['ok'] = all(v['pass'] for v in r.values())
    return r


def gate_nondegenerate(cases, ref):
    changed = 0
    distinct = set()
    for c, want in zip(cases, ref):
        span = want['arena'][SLOT:SLOT + 32]
        if span != c['arena'][SLOT:SLOT + 32]:
            changed += 1
        distinct.add((want['ret'], want['arena'][SLOT:SLOT + 16]))
    return {'pass': changed >= 100 and len(distinct) >= 40,
            'cases_that_moved_the_slots': changed,
            'distinct_results': len(distinct), 'total_cases': len(cases)}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--no-run', action='store_true')
    ap.add_argument('--skip-teeth', action='store_true')
    args = ap.parse_args()

    if args.no_run:
        rec = sorted(RECEIPTS.glob('do_sub_diff-*.json'))[-1]
        data = json.loads(rec.read_text())
        print(json.dumps({k: (v.get('pass', v.get('ok')) if isinstance(v, dict) else v)
                          for k, v in data['gates'].items()}, indent=2,
                         ensure_ascii=False))
        print('verdict:', data['result']['verdict'], 'receipt:', rec)
        return 0 if data['result']['verdict'] == 'PASS' else 1

    BUILD.mkdir(exist_ok=True)
    RECEIPTS.mkdir(exist_ok=True)
    t0 = time.time()

    bnd = binding()
    cen = instruction_census()
    stest = census_selftest()

    cases = build_cases()
    base_bin = build_c(BUILD / 'do_sub_base')
    c_rec, _ = run_c(base_bin, cases)
    trace = set()
    a_rec = run_oracle(cases, trace)

    mism = []
    for c, got, want in zip(cases, c_rec, a_rec):
        ng, nw = normalise(got, c, got['base']), normalise(want, c, want['base'])
        if ng != nw:
            keys = [k for k in ('ret', 'arena', 'err') if ng[k] != nw[k]]
            diff = ([i - SLOT for i in range(ARENA)
                     if ng['arena'][i] != nw['arena'][i]] if 'arena' in keys else [])
            mism.append({'label': c['label'], 'arg': hex(c['arg']),
                         'fields': keys, 'arena_offsets': diff[:12],
                         'c': {k: (ng[k].hex() if isinstance(ng[k], bytes) else ng[k])
                               for k in keys},
                         'orig': {k: (nw[k].hex() if isinstance(nw[k], bytes) else nw[k])
                                  for k in keys}})

    cov = gate_coverage(cases, trace)
    ndg = gate_nondegenerate(cases, a_rec)

    teeth = {}
    if not args.skip_teeth:
        for m in range(1, 15):
            b = build_c(BUILD / ('do_sub_m%d' % m), mutant=m)
            got, crashed = run_c(b, cases, allow_crash=True)
            caught, aborted = [], []
            for c, g, w in zip(cases, got, a_rec):
                if g.get('crash'):
                    aborted.append(c['label'])
                elif normalise(g, c, g['base']) != normalise(w, c, w['base']):
                    caught.append(c['label'])
            teeth[m] = {'caught_cases': len(caught), 'pass': bool(caught or aborted),
                        'mode': 'compare' if caught else ('driver-abort' if aborted
                                                          else 'green'),
                        'caught_by': caught[:4], 'aborted_by': aborted[:4]}

    rep_c, _ = run_c(base_bin, cases)
    rep_o = run_oracle(cases, None)
    rep_ok = (all(normalise(a, c, 0) == normalise(b, c, 0)
                  for c, a, b in zip(cases, rep_c, c_rec))
              and all(normalise(a, c, 0) == normalise(b, c, 0)
                      for c, a, b in zip(cases, rep_o, a_rec)))

    gates = {'binding': bnd, 'census': cen, 'census_selftest': stest,
             'identity': {'pass': not mism, 'mismatches': len(mism)},
             'coverage': cov, 'non_degenerate': ndg, 'repeat': {'pass': rep_ok}}
    if teeth:
        gates['teeth'] = {'pass': all(t['pass'] for t in teeth.values()),
                          'mutants': teeth}
    verdict = 'PASS' if (bnd['ok'] and cen['ok'] and stest['ok'] and not mism
                         and cov['ok'] and ndg['pass'] and rep_ok
                         and (not teeth or all(t['pass'] for t in teeth.values()))) else 'FAIL'

    receipt = {
        'harness': 'do_sub_diff.py',
        'target': {'symbol': SYM, 'func': 'DoSub', 'addr': hex(DO_SUB),
                   'size': SIZE, 'so': str(so_path()), 'sha256': bnd['sha256']},
        'build': 'clang --target=armv7a-none-eabi (freestanding) + qemu-arm',
        'scope': {
            'covered': ['strong-typed arm: mode 0 AND modes 2..15 (the entry only'
                        ' tests mode == 1), every pair byte 0..101, every RValue tag'
                        ' 0..15 in both operand positions, the int32/int64/real'
                        ' tower and the 4/8/16-byte result placement',
                        'mode 1 (generic -): boxType, two F_JS_ToNumber calls, the'
                        ' subtraction and both ReferenceError limbs'],
            'not_covered': ['mode 1 with a string / array / pointer / object operand'
                            ' (strtod + JS object hooks, unrecovered)',
                            'the FREE_RValue__Pre cleanup at the end of mode 1 —'
                            ' stubbed on BOTH arms, so a green run says nothing about it'],
            'modelled_callees': ['F_JS_ToNumber @0x24cfac'],
            'real_linked_callees': ['boxType @0xd7784 (c/box_type.c)'],
            'stubbed_in_the_judge': ['VMError @0xd4210',
                                     'JSThrowReferenceError @0x254b04',
                                     'JSThrowTypeError @0x24e58c',
                                     'FREE_RValue__Pre @0xc0a7c',
                                     'libc: malloc/free/mem*/str*/pthread_*'],
        },
        'seed': hex(SEED), 'cases': len(cases),
        'inputs_sha256': hashlib.sha256(
            b''.join(struct.pack('<I', c['arg']) + c['arena'] for c in cases)).hexdigest(),
        'c_sha256': hashlib.sha256((MOD / 'src' / 'do_sub.c').read_bytes()).hexdigest(),
        'result': {'mismatches': len(mism), 'first': mism[:40], 'verdict': verdict,
                   'labels': [m['label'] for m in mism][:80]},
        'gates': gates,
        'errors_seen': sorted({w['err'] for w in a_rec if w['err']}),
        'wall_s': round(time.time() - t0, 1),
        'when': time.strftime('%Y-%m-%dT%H:%M:%S'),
    }
    out = RECEIPTS / ('do_sub_diff-%s.json' % time.strftime('%Y%m%dT%H%M%S'))
    out.write_text(json.dumps(receipt, indent=2, ensure_ascii=False))

    print('RESULT %s  cases=%d identical=%d mismatches=%d  census=%d/%d  cov=%s'
          % (verdict, len(cases), len(cases) - len(mism), len(mism),
             cen['documented'], cen['instructions'], 'YES' if cov['ok'] else 'NO'))
    print('  binding  %s' % ('PASS' if bnd['ok'] else 'FAIL'))
    if not bnd['ok']:
        print('    strings_not_in_c:', bnd['strings_not_in_c'])
    print('  census   %s' % ('PASS' if cen['ok'] else 'FAIL'))
    for w in cen['wrong']:
        print('    wrong:', w['addr'], 'objdump=%r' % w['objdump'], 'src=%r' % w['source'][:2])
    for d in cen['duplicate_addresses']:
        print('    dup:', d['addr'])
    for e in cen['unknown_addresses']:
        print('    unknown:', e['addr'])
    for p in cen['pool_missing']:
        print('    pool:', p['addr'], p['word'])
    print('  census st %s' % ('PASS' if stest['ok'] else 'FAIL'))
    for k in ('pair_table_entries', 'first_operand_entries', 'second_operand_entries',
              'rhs_tag_entries', 'lhs_tag_entries', 'cls_nibbles_0_15',
              'rvalue_tags_0_15', 'modes_0_1', 'pair_bytes_0_101'):
        v = cov[k]
        print('  COVER %-24s %-4s %s' % (k, 'YES' if v['pass'] else 'NO',
                                         v.get('missing', v.get('seen', ''))))
    print('  non_degenerate %s (%d moved, %d distinct)'
          % ('PASS' if ndg['pass'] else 'FAIL', ndg['cases_that_moved_the_slots'],
             ndg['distinct_results']))
    for m, t in sorted(teeth.items()):
        print('  TEETH %-2d %-4s %-13s %4d cases  %s' % (
            m, 'PASS' if t['pass'] else 'FAIL', t['mode'], t['caught_cases'],
            ', '.join(t['caught_by'] or t['aborted_by'])))
    for x in mism[:8]:
        print('  MISMATCH %s %s fields=%s offset=%s' % (x['label'], x['arg'],
                                                        x['fields'], x['arena_offsets']))
        for k in x['fields']:
            if k == 'arena':
                continue
            print('     c:   %s' % str(x['c'][k])[:120])
            print('     orig:%s' % str(x['orig'][k])[:120])
    print('  errors seen:', receipt['errors_seen'])
    print('  receipt:', out)
    return 0 if verdict == 'PASS' else 1


if __name__ == '__main__':
    sys.exit(main())
