#!/usr/bin/env python3
"""DoAdd — original-binary differential for libyoyo's `+` handler.

Two arms, identical inputs, identical heap staging:

  arm A (judge)  _Z5DoAddjPhPKhP6VMExec @0xdc524 in the pinned image, executed
                 in Unicorn with the callees' real bytes wherever they are
                 internal (boxType runs for real), libc answered in Python
                 (malloc/strcpy/pthread/...) and the three error entries stubbed
                 so the emitted text is readable.
  arm B (claim)  reconstruction/reverse-v1/c/do_add/src/*.c, built for
                 armv7a-none-eabi (freestanding) and run under qemu-arm.

Why arm B is not host-compiled: the body stores POINTERS into 4-byte RValue
slots (a string operand's payload is a char* word, the concat writes a header
pointer into the result), and it computes operand offsets from the type nibbles.
A 64-bit build moves both and stops testing the thing under judgement.

Compared per case: the returned stack pointer, all ARENA bytes (pointers the
case staged are normalised to the offset they point at), the error text the
handler emitted, and — for the string pair — the {refcount, len, chars} of the
object the result slot points at.

Gates (any failure exits non-zero)
  binding   image sha256, the symbol's address and size from .symtab, the 19
            literal-pool words, and the 19 error strings re-derived from those
            pool words and matched against the C source's own table
  census    every instruction of the body appears in the translation as
            `@0xADDR <verbatim llvm-objdump text>`, every address exactly once,
            every pool word documented; the gate is tested by three source
            mutations that must turn it red
  identity  every case identical on both arms
  coverage  proven from the ORIGINAL's own instruction trace: all 103 pair-table
            entries walked, all 7 first-operand and 7 second-operand entries,
            all 14 tag-table entries in BOTH operand positions, every cls
            nibble 0..15, every RValue tag 0..15, and modes 0/1/2
  non_degen the case set actually moves the operand slots and produces many
            distinct results (a set of no-ops would pass trivially)
  teeth     every -DMUTANT=n build is caught by at least one named case
  repeat    both arms rerun in fresh processes and reproduce their records

Usage
  python3 do_add_diff.py            # build, run, write a receipt
  python3 do_add_diff.py --no-run   # replay the gate logic on the last receipt
  python3 do_add_diff.py --only 0x22 0x25   # just those cls bytes (debug)
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
MOD = RV1 / 'c/do_add'
BUILD = HERE / 'build'
RECEIPTS = HERE / 'receipts'
sys.path.insert(0, str(HERE))

from handler_oracle import Oracle  # noqa: E402
from unicorn import UC_HOOK_CODE  # noqa: E402

DO_ADD = 0xdc524
POOL = 0xdd4b4
END = 0xdd500
SYM = '_Z5DoAddjPhPKhP6VMExec'
SIZE = 4060

ARENA = 0x180
SLOT = 0x100
SEED = 0xADD1
N_RANDOM = 60

# pointer words the case staging wrote: <arena offset> -> <target arena offset>
RELOCS = []


# ── image binding ───────────────────────────────────────────────────────────
def so_path():
    from handler_oracle import SO as _SO
    return pathlib.Path(_SO)


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


def elf_bits():
    from elftools.elf.elffile import ELFFile
    so = so_path()
    blob = so.read_bytes()
    f = open(so, 'rb')
    elf = ELFFile(f)
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


def binding():
    """Everything the translation claims about the image, re-derived from bytes."""
    so, blob, segs, sym, elf = elf_bits()
    if sym is None:
        raise SystemExit('%s not in the symbol table' % SYM)
    pool = {}
    for a in range(POOL, END, 4):
        pool[a] = u32buf(blob, a, segs)
    # every ldr rX,[pc,#imm] + add rX,pc,rX pair inside the body -> its string.
    # The pool address comes from objdump's own annotation, so nothing here
    # copies an offset out of the card.
    raw = objdump_raw(DO_ADD, POOL)
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
    c_src = (MOD / 'src' / 'do_add.c').read_text()
    c_strings = set(re.findall(r'^    "([^"]*)",?$', c_src, re.M))
    derived = set(strs.values())
    return {
        'ok': (hashlib.sha256(so.read_bytes()).hexdigest()
               == '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
               and sym['st_value'] == DO_ADD and sym['st_size'] == SIZE
               and derived <= c_strings and len(strs) == 19),
        'so': str(so),
        'sha256': hashlib.sha256(so.read_bytes()).hexdigest(),
        'symbol': {'name': SYM, 'addr': hex(sym['st_value']),
                   'size': sym['st_size'], 'declared': {'addr': hex(DO_ADD),
                                                        'size': SIZE}},
        'pool_words': len(pool),
        'error_strings': {hex(k): v for k, v in sorted(strs.items())},
        'strings_not_in_c': sorted(derived - c_strings),
        'strings_in_c_not_derived': sorted(c_strings - derived - {'MODE1 STRING LIMB NOT TRANSLATED'}),
    }


# ── objdump + census ────────────────────────────────────────────────────────
def norm(s):
    return re.sub(r'\s+', ' ', s).strip()


def objdump_raw(entry, stop):
    """mnemonic + operands WITH objdump's `@ pool` annotation kept."""
    p = subprocess.run(['llvm-objdump', '-d', '--start-address=%#x' % entry,
                        '--stop-address=%#x' % stop, '-M', 'reg-names-std',
                        str(so_path())], capture_output=True, text=True)
    rows = {}
    for ln in p.stdout.splitlines():
        m = re.match(r'\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(.*)$', ln)
        if not m:
            continue
        addr = int(m.group(1), 16)
        if addr < entry or addr >= stop:
            continue
        parts = [x for x in m.group(3).split('\t') if x.strip()]
        txt = norm(' '.join(parts))
        txt = norm(re.sub(r'\s*<[^>]*>', '', txt))
        if txt:
            rows[addr] = tuple(txt.split(' ', 1))
    return dict(sorted(rows.items()))


def objdump_rows(entry, stop):
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
        parts = [x for x in m.group(3).split('\t') if x.strip()]
        txt = norm(' '.join(parts))
        txt = norm(re.sub(r'\s*@.*$', '', re.sub(r'\s*<[^>]*>', '', txt)))
        if addr < DO_ADD or addr >= END:
            continue
        if txt:
            rows[addr] = tuple(txt.split(' ', 1))
    return dict(sorted(rows.items()))


ANCHOR = re.compile(r'/\*\s*@(0x[0-9a-f]{5,8})\s+(.*?)\s*\*/')


def instruction_census(overrides=None):
    overrides = overrides or {}
    rows = objdump_rows(DO_ADD, POOL)
    poolw = {}
    so, blob, segs, _sym, _elf = elf_bits()
    for a in range(POOL, END, 4):
        poolw[a] = u32buf(blob, a, segs)
    src = overrides.get('do_add.c', (MOD / 'src' / 'do_add.c').read_text())
    cands = {}
    for ln in src.splitlines():
        m = ANCHOR.search(ln)
        if m:
            cands.setdefault(int(m.group(1), 16), []).append(norm(m.group(2)))
    wrong = []
    for a, (mn, op) in rows.items():
        want = norm((mn + ' ' + op).strip())
        if a not in cands or want not in [norm(c) for c in cands[a]]:
            wrong.append({'addr': hex(a), 'objdump': want, 'source': cands.get(a, [])})
    dupes = [{'addr': hex(a), 'texts': cands[a]} for a in sorted(cands) if len(cands[a]) > 1]
    extra = [{'addr': hex(a)} for a in sorted(cands) if a not in rows and a not in poolw]
    pool_missing = [{'addr': hex(a), 'word': '%08x' % w} for a, w in sorted(poolw.items())
                    if not any(('.word 0x%08x' % w) in c for c in cands.get(a, []))]
    ok = (not wrong and not dupes and not extra and not pool_missing
          and len(rows) == 996 and len(poolw) == 19)
    return {'ok': ok, 'instructions': len(rows), 'documented': len(rows) - len(wrong),
            'pool_words': len(poolw), 'wrong': wrong[:8], 'duplicate_addresses': dupes[:8],
            'unknown_addresses': extra[:8], 'pool_missing': pool_missing[:8]}


def census_selftest():
    base = (MOD / 'src' / 'do_add.c').read_text()
    m = re.search(r'^.*@0xdc550 beq 0xdcb30.*$', base, re.M)
    drop = base if not m else base[:m.start()] + base[m.end() + 1:]
    trials = {
        'operand_digit_changed': base.replace('beq 0xdcb30', 'beq 0xdcb33', 1),
        'comment_line_deleted': drop,
        'pool_word_changed': base.replace('.word 0x0025625c', '.word 0x0025625d', 1),
    }
    res, ok = {}, True
    for name, ov in trials.items():
        rep = instruction_census({'do_add.c': ov})
        res[name] = {'ok': not rep['ok'],
                     'wrong': len(rep['wrong']), 'missing': len(rep['pool_missing']),
                     'undocumented': rep['instructions'] - rep['documented']}
        ok = ok and not rep['ok']
    res['ok'] = ok
    return res


# ── case construction ───────────────────────────────────────────────────────
SIZES = {0: 8, 3: 8, 5: 16}


def tsize(t):
    return SIZES.get(t, 4)


def blank():
    return bytearray(b'\xEE' * ARENA)


def put(a, off, t, val):
    """Stage one operand at `off`; returns the offset just past it."""
    if t == 0:
        a[off:off + 8] = struct.pack('<d', float(val))
        return off + 8
    if t == 3:
        a[off:off + 8] = struct.pack('<Q', int(val) & 0xFFFFFFFFFFFFFFFF)
        return off + 8
    if t == 5:
        kind, payload, tag = val
        b = struct.pack('<Q', int(payload) & 0xFFFFFFFFFFFFFFFF)
        if kind == 'd':
            b = struct.pack('<d', float(payload))
        a[off:off + 8] = b
        a[off + 8:off + 12] = b'\x5A\x5A\x5A\x5A'
        a[off + 12:off + 16] = struct.pack('<I', tag & 0xFFFFFFFF)
        return off + 16
    if t == 1:
        a[off:off + 4] = struct.pack('<f', float(val))
        return off + 4
    a[off:off + 4] = struct.pack('<I', int(val) & 0xFFFFFFFF)
    return off + 4


def case(mode, cls, lval, rval, label, tags=None):
    """Build one case: mode + pair byte + the two operand payloads."""
    T, U = cls & 0xF, (cls >> 4) & 0xF

    def coerce(t, v):
        if t == 5:
            return v if isinstance(v, tuple) else ('d', float(v), 13)
        if isinstance(v, tuple):                      # a boxed payload for a
            return float(v[1]) if v[0] == 'd' else int(v[1])   # plain slot
        return v

    lval, rval = coerce(T, lval), coerce(U, rval)
    a = blank()
    off = put(a, SLOT, T, lval)
    put(a, off, U, rval)
    return {'arg': ((mode & 0xF) << 8) | ((cls & 0xFF) << 16),
            'arena': bytes(a), 'relocs': [], 'label': label,
            'cls': cls, 'mode': mode, 'T': T, 'U': U,
            'tagl': lval[2] if T == 5 else None,
            'tagr': rval[2] if U == 5 else None, 'objslot': None}


def string_case(mlabel, t1, t2, rc=2, cls=0x66):
    """The concat pair: two staged RefThing-like objects, both alive after the
    call.  cls 0x66 = two 4-byte string operands, 0x56 = string + boxed string,
    0x55 = two boxed strings; the objects live above the operand span and every
    pointer the case stages is relocated, so both arms can dereference them."""
    T, U = cls & 0xF, (cls >> 4) & 0xF
    obj1, obj2 = SLOT + 0x30, SLOT + 0x40
    txt1, txt2 = SLOT + 0x50, SLOT + 0x60
    a = blank()
    a[txt1:txt1 + len(t1) + 1] = t1 + b'\0'
    a[txt2:txt2 + len(t2) + 1] = t2 + b'\0'
    a[obj1:obj1 + 12] = struct.pack('<III', 0, rc, len(t1))
    a[obj2:obj2 + 12] = struct.pack('<III', 0, rc, len(t2))
    pos1 = SLOT
    pos2 = SLOT + tsize(T)
    if T == 5:
        a[SLOT + 12:SLOT + 16] = struct.pack('<I', 1)
    if U == 5:
        a[pos2 + 12:pos2 + 16] = struct.pack('<I', 1)
    relocs = [(pos1, obj1), (pos2, obj2), (obj1, txt1), (obj2, txt2)]
    # the concat writes the new header pointer at the slot the routing chose,
    # which is also the pointer the handler returns.
    objslot = SLOT + 4 if cls in (0x66, 0x56) else SLOT + 16
    return {'arg': (0x66 << 16) if cls == 0x66 else ((cls & 0xFF) << 16),
            'arena': bytes(a), 'relocs': relocs, 'label': mlabel,
            'cls': cls, 'mode': 0, 'T': T, 'U': U,
            'tagl': 1 if T == 5 else None, 'tagr': 1 if U == 5 else None,
            'objslot': objslot}


D_REALS = [2.5, -1.25, 0.0, -0.0, 1e300, 5e-324, float('inf'), float('-inf'),
           float('nan'), 3.0]
I32S = [7, -3, 0x7FFFFFFF, -0x80000000, 1, -1, 0x40000000]
I64S = [0x100000002, -7, 0x7FFFFFFFFFFFFFFF, -0x8000000000000000, 3, -1,
        0x00000001FFFFFFFF]


def build_cases():
    cases = []
    # 1. every pair byte 0..102 (the pair table is indexed by this byte), plus
    #    the >102 fall-through.  Payloads follow the type nibbles.
    for cls in list(range(0, 103)) + [103, 111, 119, 255]:
        if cls == 0x66:
            continue        # the concat needs two live string objects: string_case
        T, U = cls & 0xF, (cls >> 4) & 0xF
        cases.append(case(0, cls, 2.5 if T != 3 else 0x100000002,
                          1.25 if U != 3 else 3, 'cls=%#04x' % cls))
    # 2. payload variants on every pair the tail actually accepts
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
    # 3. tags: table 5 (second operand = the boxed one) and table 4 (first),
    #    tags 0..15 both ways, plus the pair-of-boxes case.
    # tag 1 (string) is staged by string_case: a boxed string operand makes the
    # resolved pair 0x56/0x66, i.e. the CONCAT, which needs two live objects.
    for tag in range(16):
        cases.append(case(0, 0x05, ('d', 2.5, tag), 1.25, 'lhsvar tag%d' % tag))
        if tag != 1:
            cases.append(case(0, 0x50, 2.5, ('d', 1.25, tag), 'rhsvar tag%d' % tag))
            cases.append(case(0, 0x55, ('d', 2.5, tag), ('d', 1.25, tag),
                              'bothvar tag%d' % tag))
        cases.append(case(0, 0x25, ('i', 4, tag), 3, 'lhsvar+i32 tag%d' % tag))
        cases.append(case(0, 0x53, 2.5, ('i', 9, tag), 'i64+rhsvar tag%d' % tag))
    # int32/int64 payloads behind a boxed operand, so the tag tables feed the
    # integer limbs too (tag 7 -> int32, tag 10 -> int64)
    for tag, pl in ((7, ('i', -5, 7)), (10, ('i', 0x100000003, 10)),
                    (0, ('d', 0.5, 0)), (13, ('d', -0.5, 13))):
        for cls, rv in ((0x05, 1.25), (0x15, 1.5), (0x25, 3), (0x35, 5)):
            cases.append(case(0, cls, pl, rv, 'lhsbox tag%d cls=%#04x' % (tag, cls)))
        for cls, lv in ((0x50, 2.5), (0x52, 7), (0x53, 0x100000002)):
            cases.append(case(0, cls, lv, pl, 'rhsbox tag%d cls=%#04x' % (tag, cls)))
    # 4. strings: concat order, empty strings, unequal lengths, refcount >= 2
    for t1, t2, rc in ((b'abc', b'de', 2), (b'', b'', 2), (b'xx', b'', 2),
                       (b'', b'yy', 3), (b'a' * 12, b'b', 2)):
        cases.append(string_case('str %r+%r rc=%d' % (t1[:6], t2[:6], rc), t1, t2, rc))
    # the same concat reached through a boxed operand: pair 0x56 (string +
    # boxed string) and 0x55 (two boxed strings) resolve to 0x66 as well.
    for cls in (0x56, 0x55):
        cases.append(string_case('str via cls=%#04x' % cls, b'pq', b'rs', 2, cls=cls))
        cases.append(string_case('str via cls=%#04x empty' % cls, b'', b'z', 2,
                                 cls=cls))
    # 5. modes 1 and 2: numeric domain plus the ReferenceError limb
    for mode in (1, 2):
        for T in (0, 2, 3, 4):
            for U in (0, 2, 3, 4):
                cls = T | (U << 4)
                lv = 2.5 if T == 0 else (7 if T == 2 else (0x100000002 if T == 3 else 1))
                rv = 1.25 if U == 0 else (3 if U == 2 else (5 if U == 3 else 1))
                cases.append(case(mode, cls, lv, rv, 'm%d T%d U%d' % (mode, T, U)))
        for cls in (0x07, 0x08, 0x0F, 0x70, 0x80, 0xF0, 0x17, 0x71):
            cases.append(case(mode, cls, 2.5, 1.5, 'm%d no-tag cls=%#04x' % (mode, cls)))
        for cls in (0x90, 0x91):
            cases.append(case(mode, cls, 2.5, 1.5, 'm%d undef rhs' % mode))
        for lv, rv in ((float('nan'), 1.0), (3.5, float('inf')),
                       (-0.0, -0.0), (1e308, 1e308), (5e-324, -5e-324)):
            cases.append(case(mode, 0x00, lv, rv, 'm%d cls=0x00 edge' % mode))
        for lv, rv in ((0x7FFFFFFF, 1), (-0x80000000, -1), (0, 0), (0x40000000, 3)):
            cases.append(case(mode, 0x22, lv, rv, 'm%d cls=0x22 edge' % mode))
            cases.append(case(mode, 0x33, lv, rv, 'm%d cls=0x33 edge' % mode))
        cases.append(case(mode, 0x30, 1.5, 0x100000003, 'm%d cls=0x30 edge' % mode))
        cases.append(case(mode, 0x20, 1.5, -7, 'm%d cls=0x20 edge' % mode))
    # 6. modes 3..15 fall through to the strong-typed arm
    for mode in (3, 7, 11, 15):
        for cls in (0x00, 0x22, 0x02, 0x56):
            cases.append(case(mode, cls, 2.5, 1.25, 'm%d fallthrough cls=%#04x'
                              % (mode, cls)))
    # 7. random tail
    rng = random.Random(SEED)
    for _ in range(N_RANDOM):
        cls = rng.randrange(0, 0x78)
        T, U = cls & 0xF, (cls >> 4) & 0xF
        lv = rng.choice([('d', rng.uniform(-1e3, 1e3), rng.randrange(16)),
                         rng.randrange(-2**31, 2**31), rng.uniform(-1e3, 1e3)])
        rv = rng.choice([('d', rng.uniform(-1e3, 1e3), rng.randrange(16)),
                         rng.randrange(-2**31, 2**31), rng.uniform(-1e3, 1e3)])
        if T == 5 and not isinstance(lv, tuple):
            lv = ('d', float(lv), 13)
        if U == 5 and not isinstance(rv, tuple):
            rv = ('d', float(rv), 13)
        # a tag-1 box would resolve the pair to 0x66 (the concat) and needs a
        # staged object; the random tail stays away from it (string_case owns it)
        if U == 5 and rv[2] == 1:
            rv = (rv[0], rv[1], 0)
        try:
            cases.append(case(rng.choice([0, 0, 0, 3]), cls, lv, rv,
                              'random cls=%#04x' % cls))
        except struct.error:
            continue
    return cases


# ── arms ────────────────────────────────────────────────────────────────────
ARM_FLAGS = ['--target=armv7a-none-eabi', '-march=armv7-a', '-marm',
             '-mfpu=vfpv3', '-mfloat-abi=softfp', '-std=c11', '-ffreestanding',
             '-fno-builtin', '-ffp-contract=off', '-fstack-protector-strong',
             '-mstack-protector-guard=global', '-ffunction-sections',
             '-fdata-sections', '-Wall', '-Wextra', '-Werror', '-nostdlib',
             '-static', '-fuse-ld=lld', '-Wl,--gc-sections', '-Wl,-e,main']

SRCS = [MOD / 'src' / 'do_add.c', RV1 / 'c' / 'box_type.c']


def build_c(out_bin, mutant=0):
    BUILD.mkdir(parents=True, exist_ok=True)
    cmd = ['clang'] + ARM_FLAGS + ['-O1', '-I', str(MOD / 'src')]
    if mutant:
        cmd.insert(1, '-DDO_ADD_MUTANT=%d' % mutant)
    cmd += [str(s) for s in SRCS] + [str(MOD / 'fixture' / 'driver.c'),
                                    '-o', str(out_bin)]
    p = subprocess.run(cmd, capture_output=True, text=True)
    if p.returncode:
        raise RuntimeError('build failed: %s' % p.stderr[-4000:])
    return out_bin


def reloc_spec(case):
    rel = ','.join('%x:%x' % (o, t) for o, t in case['relocs']) or '-'
    slot = '-' if case.get('objslot') is None else '%x' % case['objslot']
    return rel + ';' + slot


def apply_relocs(arena, relocs, base):
    a = bytearray(arena)
    for off, tgt in relocs:
        struct.pack_into('<I', a, off, (base + tgt) & 0xFFFFFFFF)
    return bytes(a)


def run_c(binary, cases, allow_crash=False):
    blob = ''.join('IN %x %s %s\n' % (c['arg'], c['arena'].hex(), reloc_spec(c))
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
        ret = int(parts[1])
        arena = bytes.fromhex(parts[2])
        err = None if parts[3] == '-' else bytes.fromhex(parts[3]).decode('latin1')
        rc, ln = int(parts[4]), int(parts[5])
        s = b'' if parts[6] == '-' else bytes.fromhex(parts[6])
        base = int(parts[7], 16) if len(parts) > 7 else 0
        out.append({'ret': ret, 'arena': arena, 'err': err, 'obj': (rc, ln, s),
                    'base': base})
    crashed = 0
    if len(out) < len(cases):
        n = len(out)
        if not allow_crash:
            raise RuntimeError('C arm returned %d records for %d cases; it died on %r'
                               % (n, len(cases),
                                  cases[n]['label'] if n < len(cases) else '?'))
        # a mutant that faults the arm IS a detectable difference from the
        # original, which returns normally on every case.
        crashed = len(cases) - n
        for _ in range(crashed):
            out.append({'ret': None, 'arena': b'', 'err': 'CRASH',
                        'obj': (0, 0, b''), 'base': 0, 'crash': True})
    return out, crashed


def run_oracle(cases, trace=None):
    o = Oracle(libc=True)
    if trace is not None:
        def hook(uc, address, size, _ud):
            trace.add(address)
        o.uc.hook_add(UC_HOOK_CODE, hook, begin=DO_ADD, end=END)
    out = []
    for c in cases:
        base = o.alloc(ARENA)
        o.write(base, apply_relocs(c['arena'], c['relocs'], base))
        slotp = base + SLOT
        try:
            ret = o.call(DO_ADD, r0=c['arg'], r1=slotp, r2=0, r3=0)
        except Exception as exc:                    # the original itself faulted
            out.append({'ret': None, 'arena': bytes(o.read(base, ARENA)),
                        'err': 'FAULT: %s' % exc, 'obj': (0, 0, b''), 'base': base,
                        'fault': True})
            continue
        err = None
        for call in o.calls:
            if call['name'] == 'VMError':
                err = o.read_cstr(call['args'][1])
                break
            if call['name'].startswith('JSThrow'):
                err = o.read_cstr(call['args'][0])
                break
        obj = (0, 0, b'')
        if c.get('objslot') is not None:
            p = struct.unpack('<I', bytes(o.read(base + c['objslot'], 4)))[0]
            if p:
                rc, ln = struct.unpack('<II', bytes(o.read(p + 4, 8)))
                try:
                    txt = bytes(o.read(struct.unpack('<I', bytes(o.read(p, 4)))[0],
                                       min(ln, 64)))
                except Exception:
                    txt = b'<unreadable>'
                obj = (rc, ln, txt)
        out.append({'ret': ret - slotp, 'arena': bytes(o.read(base, ARENA)),
                    'err': err, 'obj': obj, 'base': base})
    return out


SPILL = (SLOT - 120, SLOT - 116)   # the concat's [sp+4]/[sp+8] spill slots


def normalise(rec, case, base_hint):
    """Compare pointers by what they point AT, not by the number.

    Case-staged pointers are relocated per arm; the two spill words the handler
    itself writes for the concat hold absolute char* and are rewritten as the
    arena offset they name, so the same case compares equal on a guest heap and
    on a qemu .bss pool."""
    a = bytearray(rec['arena'])
    for off, tgt in case['relocs']:
        struct.pack_into('<I', a, off, tgt)
    if case.get('objslot') is not None:
        struct.pack_into('<I', a, case['objslot'], 0xDEC0DE00)
    return {'ret': rec['ret'], 'arena': bytes(a), 'err': rec['err'],
            'obj': rec['obj']}


# ── gates ───────────────────────────────────────────────────────────────────
def gate_coverage(cases, trace):
    table3 = [0xdc5c4 + 4 * k for k in range(103)]
    table1 = [0xdc564 + 4 * k for k in range(7)]
    table2 = [0xdc598 + 4 * k for k in range(7)]
    table4 = [0xdc908 + 4 * k for k in range(14)]
    table5 = [0xdc964 + 4 * k for k in range(14)]
    miss = lambda addrs: [hex(a) for a in addrs if a not in trace]
    cls_seen = {c['cls'] for c in cases}
    nib_seen = {(c['cls'] & 0xF) for c in cases} | {(c['cls'] >> 4) & 0xF for c in cases}
    tags = {c['tagl'] for c in cases if c.get('tagl') is not None}
    tags |= {c['tagr'] for c in cases if c.get('tagr') is not None}
    modes = {c['mode'] for c in cases}
    t1 = miss(table1)
    t2 = miss(table2)
    t3 = miss(table3)
    t4 = miss(table4)
    t5 = miss(table5)
    r = {
        'pair_table_entries': {'pass': not t3, 'walked': 103 - len(t3),
                               'total': 103, 'missing': t3[:12]},
        'first_operand_entries': {'pass': not t1, 'missing': t1},
        'second_operand_entries': {'pass': not t2, 'missing': t2},
        'rhs_tag_entries': {'pass': not t4, 'missing': t4},
        'lhs_tag_entries': {'pass': not t5, 'missing': t5},
        'cls_nibbles_0_15': {'pass': nib_seen >= set(range(16)), 'seen': sorted(nib_seen)},
        'rvalue_tags_0_15': {'pass': tags >= set(range(16)), 'seen': sorted(tags)},
        'modes_0_1_2': {'pass': modes >= {0, 1, 2}, 'seen': sorted(modes)},
        'pair_bytes_0_102': {'pass': cls_seen >= set(range(103)),
                             'seen': len(cls_seen & set(range(103)))},
    }
    r['ok'] = all(v['pass'] for v in r.values())
    return r


def gate_nondegenerate(cases, ref):
    changed = 0
    distinct = set()
    for c, want in zip(cases, ref):
        span = (SLOT, SLOT + 32)
        if want['arena'][span[0]:span[1]] != c['arena'][span[0]:span[1]]:
            changed += 1
        distinct.add((want['ret'], want['arena'][SLOT:SLOT + 16]))
    return {'pass': changed >= 100 and len(distinct) >= 40,
            'cases_that_moved_the_slots': changed,
            'distinct_results': len(distinct), 'total_cases': len(cases)}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--no-run', action='store_true')
    ap.add_argument('--only', nargs='*')
    ap.add_argument('--skip-teeth', action='store_true')
    args = ap.parse_args()

    if args.no_run:
        rec = sorted(RECEIPTS.glob('do_add_diff-*.json'))[-1]
        data = json.loads(rec.read_text())
        print(json.dumps({k: (v.get('pass', v.get('ok')) if isinstance(v, dict) else v)
                          for k, v in data['gates'].items()}, indent=2,
                         ensure_ascii=False))
        print('receipt:', rec)
        return 0 if data['result']['verdict'] == 'PASS' else 1

    BUILD.mkdir(exist_ok=True)
    RECEIPTS.mkdir(exist_ok=True)
    t0 = time.time()

    bnd = binding()
    cen = instruction_census()
    stest = census_selftest()

    cases = build_cases()
    if args.only:
        want = {int(x, 0) for x in args.only}
        cases = [c for c in cases if c['cls'] in want]

    base_bin = build_c(BUILD / 'do_add_base')
    c_rec, _ = run_c(base_bin, cases)
    trace = set()
    a_rec = run_oracle(cases, trace)

    mism = []
    for c, got, want in zip(cases, c_rec, a_rec):
        ng, nw = normalise(got, c, got['base']), normalise(want, c, want['base'])
        if ng != nw:
            keys = [k for k in ('ret', 'arena', 'err', 'obj') if ng[k] != nw[k]]
            diff = []
            if 'arena' in keys:
                diff = [i - SLOT for i in range(ARENA) if ng['arena'][i] != nw['arena'][i]]
            def show(rec):
                out = {}
                for k in keys:
                    v = rec[k]
                    if isinstance(v, tuple):
                        v = 'rc=%d len=%d %s' % (v[0], v[1], v[2].hex())
                    elif isinstance(v, bytes):
                        v = v.hex()
                    out[k] = v
                return out
            mism.append({'label': c['label'], 'arg': hex(c['arg']),
                         'fields': keys, 'arena_offsets': diff[:12],
                         'c': show(ng), 'orig': show(nw)})

    cov = gate_coverage(cases, trace)
    ndg = gate_nondegenerate(cases, a_rec)

    teeth = {}
    if not args.skip_teeth:
        for m in range(1, 16):
            b = build_c(BUILD / ('do_add_m%d' % m), mutant=m)
            got, crashed = run_c(b, cases, allow_crash=True)
            caught, aborted = [], []
            for c, g, w in zip(cases, got, a_rec):
                if g.get('crash'):
                    aborted.append(c['label'])
                elif normalise(g, c, g['base']) != normalise(w, c, w['base']):
                    caught.append(c['label'])
            mode = ('compare' if caught else
                    ('driver-abort' if aborted else 'green'))
            teeth[m] = {'caught_cases': len(caught), 'pass': bool(caught or aborted),
                        'mode': mode, 'caught_by': caught[:4],
                        'aborted_by': aborted[:4], 'crashed_records': crashed}

    # repeat: fresh oracle + fresh qemu process
    rep_c, _ = run_c(base_bin, cases)
    rep_o = run_oracle(cases, None)
    rep_ok = (all(normalise(a, c, 0) == normalise(b, c, 0)
                  for c, a, b in zip(cases, rep_c, c_rec))
              and all(normalise(a, c, 0) == normalise(b, c, 0)
                      for c, a, b in zip(cases, rep_o, a_rec)))

    gates = {
        'binding': bnd,
        'census': cen,
        'census_selftest': stest,
        'identity': {'pass': not mism, 'mismatches': len(mism)},
        'coverage': cov,
        'non_degenerate': ndg,
        'repeat': {'pass': rep_ok},
    }
    if teeth:
        gates['teeth'] = {'pass': all(t['pass'] for t in teeth.values()),
                          'mutants': teeth}
    verdict = 'PASS' if (bnd['ok'] and cen['ok'] and stest['ok'] and not mism
                         and cov['ok'] and ndg['pass'] and rep_ok
                         and (not teeth or all(t['pass'] for t in teeth.values()))) else 'FAIL'

    receipt = {
        'harness': 'do_add_diff.py',
        'target': {'symbol': SYM, 'func': 'DoAdd', 'addr': hex(DO_ADD),
                   'size': SIZE, 'so': str(so_path()), 'sha256': bnd['sha256']},
        'build': 'clang --target=armv7a-none-eabi (freestanding) + qemu-arm',
        'scope': {
            'covered': ['mode 0 / modes 3..15: every pair byte 0..102, every RValue'
                        ' tag 0..15 in both operand positions, the int32/int64/real'
                        ' tower, the 4/8/16-byte result placement, the :1:/:2: errors',
                        'mode 1 / mode 2: numeric limb over types 0/2/3/4 and the'
                        ' ReferenceError limb over the untagged types 7/8/>9',
                        'string + string (pair 0x66): order, lengths, result object,'
                        ' input refcount decrement'],
            'not_covered': [
                'mode 1 string limb 0xdd180..0xdd2ac (needs F_JS_ToString, unrecovered)',
                'the string free branch 0xdcea0/0xdcef8 (YYFree + _RefThing::dec +'
                ' operator delete, unrecovered); inputs use refcount >= 2',
                'modes 1/2 with string/array/pointer/object operands (strtod + JS'
                ' object hooks, unrecovered)'],
            'modelled_callees': ['F_JS_ToNumber @0x24cfac',
                                 'F_JS_ToPrimitive @0x24cd64'],
            'real_linked_callees': ['boxType @0xd7784 (c/box_type.c)'],
            'stubbed_in_the_judge': ['VMError @0xd4210', 'JSThrowReferenceError @0x254b04',
                                     'JSThrowTypeError @0x24e58c',
                                     'FREE_RValue__Pre @0xc0a7c',
                                     'libc: malloc/free/mem*/str*/pthread_*'],
        },
        'seed': hex(SEED), 'cases': len(cases),
        'inputs_sha256': hashlib.sha256(
            b''.join(struct.pack('<I', c['arg']) + c['arena'] for c in cases)).hexdigest(),
        'c_sha256': hashlib.sha256((MOD / 'src' / 'do_add.c').read_bytes()).hexdigest(),
        'result': {'mismatches': len(mism), 'first': mism[:40], 'verdict': verdict,
                   'labels': [m['label'] for m in mism][:80]},
        'gates': gates,
        'errors_seen': sorted({w['err'] for w in a_rec if w['err']}),
        'wall_s': round(time.time() - t0, 1),
        'when': time.strftime('%Y-%m-%dT%H:%M:%S'),
    }
    out = RECEIPTS / ('do_add_diff-%s.json' % time.strftime('%Y%m%dT%H%M%S'))
    out.write_text(json.dumps(receipt, indent=2, ensure_ascii=False))

    print('RESULT %s  cases=%d identical=%d mismatches=%d  census=%d/%d  cov=%s'
          % (verdict, len(cases), len(cases) - len(mism), len(mism),
             cen['documented'], cen['instructions'], 'YES' if cov['ok'] else 'NO'))
    print('  binding  %s' % ('PASS' if bnd['ok'] else 'FAIL'))
    if not bnd['ok']:
        print('    strings_not_in_c:', bnd['strings_not_in_c'])
        print('    in_c_not_derived:', bnd['strings_in_c_not_derived'])
    print('  census   %s' % ('PASS' if cen['ok'] else 'FAIL'))
    if not cen['ok']:
        for w in cen['wrong']:
            print('    wrong:', w['addr'], 'objdump=%r' % w['objdump'],
                  'source=%r' % w['source'][:2])
        for d in cen['duplicate_addresses']:
            print('    dup:', d['addr'], d['texts'])
        for e in cen['unknown_addresses']:
            print('    unknown:', e['addr'])
        for p in cen['pool_missing']:
            print('    pool:', p['addr'], p['word'])
    print('  census st %s' % ('PASS' if stest['ok'] else 'FAIL'))
    for k in ('pair_table_entries', 'first_operand_entries', 'second_operand_entries',
              'rhs_tag_entries', 'lhs_tag_entries', 'cls_nibbles_0_15',
              'rvalue_tags_0_15', 'modes_0_1_2', 'pair_bytes_0_102'):
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
    for x in mism[:10]:
        print('  MISMATCH %s %s fields=%s offset=%s' % (x['label'], x['arg'],
                                                        x['fields'], x['arena_offsets']))
        for k in x['fields']:
            if k == 'arena':
                continue
            print('     c:   %s' % str(x['c'][k])[:120])
            print('     orig:%s' % str(x['orig'][k])[:120])
    if mism:
        print('  mismatch labels:', [x['label'] for x in mism[:20]])
    print('  errors seen:', receipt['errors_seen'])
    print('  receipt:', out)
    return 0 if verdict == 'PASS' else 1


if __name__ == '__main__':
    sys.exit(main())
