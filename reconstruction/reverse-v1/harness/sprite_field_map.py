#!/usr/bin/env python3
"""Record-field -> destination-offset map for the original CSprite::LoadFromChunk.

Method (differential, per 32-bit slot):
    run(record)                  -> baseline dst bytes + malloc list
    run(record with slot=X)      -> dst bytes; diff vs baseline = effect of that slot
    run(record unchanged again)  -> must reproduce baseline byte for byte

The revert run is the falsifier: without it "nothing changed" cannot be told
apart from "the run silently diverged before touching dst".  Rust-free: every
number in sprite_field_map.tsv comes from the original ARM code in Unicorn via
handler_oracle.Oracle(libc=True), same plumbing sprite_probe.py uses.

Pointer words stored into dst are compared raw AND normalised (ptrnorm), because
a changed malloc size legitimately moves every later heap pointer: raw diff
alone would over-report, normalised diff alone would hide a real size change.

Usage:
    $PREFIX/bin/python3 sprite_field_map.py            # full sweep -> tsv
    $PREFIX/bin/python3 sprite_field_map.py --only w   # one field, prints rows
    $PREFIX/bin/python3 sprite_field_map.py --list     # field table only

Exit code 0 = every mutated run either returned or failed in a *named* way, and
every revert run reproduced the baseline.
"""
import argparse
import os
import pathlib
import struct
import sys
import time

HERE = pathlib.Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))

from unicorn import UcError, UC_HOOK_MEM_WRITE                          # noqa: E402
from unicorn.arm_const import UC_ARM_REG_PC                             # noqa: E402

import ptrnorm                                                          # noqa: E402
from handler_oracle import Oracle, SO                                   # noqa: E402

ROOT = HERE.parents[2]
WAD_CANDIDATES = [
    os.environ.get('CALLY_WAD'),
    str(ROOT / 'assets/game.droid'),
    os.path.expanduser('~/callys-caves-2-rs/assets/game.droid'),
]
WAD_PATH = next((p for p in WAD_CANDIDATES if p and os.path.exists(p)), None)

WAD_BASE = 0x80000000
WAD_GLOBAL = 0x544c44
SPRITE_ENTRY = 0x1e972c
REC0 = 0xf0c
DST = 0x20000000
DST_SIZE = 0x1000
OUT = HERE / 'sprite_field_map.tsv'

# Template: record 0 (spr_line, 128x8, 1 tpag, 1 mask, span 196).  One tpag and
# one mask keeps every offset inside the record's own bytes, so a mutation never
# silently reads a neighbouring record.
TEMPLATE = REC0

# (name, offset, kind) - kind drives which test values are meaningful.
FIELDS = [
    ('name_ptr',    0x00, 'ptr'),
    ('w',           0x04, 'size'),
    ('h',           0x08, 'size'),
    ('bbox_left',   0x0c, 'signed'),
    ('bbox_right',  0x10, 'signed'),
    ('bbox_bottom', 0x14, 'signed'),
    ('bbox_top',    0x18, 'signed'),
    ('transparent', 0x1c, 'flag'),
    ('smooth',      0x20, 'flag'),
    ('preload',     0x24, 'flag'),
    ('bboxmode',    0x28, 'flag'),
    ('sepmasks',    0x2c, 'flag'),
    ('origin_x',    0x30, 'signed'),
    ('origin_y',    0x34, 'signed'),
    ('tpag_count',  0x38, 'count'),
    ('tpag[0]',     0x3c, 'ptr'),
    ('mask_count',  0x40, 'count'),
    ('mask_word0',  0x44, 'blob'),
    ('mask_word1',  0x48, 'blob'),
    ('mask_tail',   0xc0, 'blob'),
]

VALUES = {
    'size':   [0x0, 0x1, 0x11, 0x100, 0x10000, 0xffffffff],
    'signed': [0x0, 0x1, 0x11, 0xffffffff, 0x7fffffff, 0x80000000],
    'flag':   [0x0, 0x1, 0x2, 0x11, 0xffffffff],
    'count':  [0x0, 0x1, 0x2, 0x3, 0xffffffff],
    'ptr':    [0x0, 0x11, REC0, 0x40, 0x7fffffff, 0xffffffff],
    'blob':   [0x0, 0xffffffff, 0x55555555],
}


def run_once(wad, rec_off, patch):
    """One original-code run over `patch` = {rec-relative offset: bytes}."""
    blob = bytearray(wad)
    for off, data in patch.items():
        blob[rec_off + off:rec_off + off + len(data)] = data
    blob = bytes(blob)

    o = Oracle(so=SO, libc=True, guard_plt=True)
    u = o.uc
    u.mem_map(WAD_BASE, (len(blob) + 0xfff) & ~0xfff)
    u.mem_write(WAD_BASE, blob)
    u.mem_write(WAD_GLOBAL, struct.pack('<I', WAD_BASE))
    u.mem_map(DST, DST_SIZE)
    u.mem_write(DST, b'\0' * DST_SIZE)

    writes = []

    def on_write(uc, _access, address, size, value, _d):
        pc = uc.reg_read(UC_ARM_REG_PC)
        writes.append({'off': address - DST, 'size': size, 'value': value, 'pc': pc})

    u.hook_add(UC_HOOK_MEM_WRITE, on_write, begin=DST, end=DST + DST_SIZE - 1)

    err = ret = None
    try:
        ret = o.call(SPRITE_ENTRY, r0=DST, r1=WAD_BASE + rec_off, r2=0)
    except UcError as exc:                       # emulator-level: unmapped, bad insn
        err = 'UcError: %s' % exc
    except MemoryError as exc:                   # bump allocator ran out
        err = 'MemoryError: %s' % exc
    except Exception as exc:                     # noqa: BLE001 - named, not swallowed
        err = '%s: %s' % (type(exc).__name__, exc)
    dst = bytes(u.mem_read(DST, DST_SIZE))
    return {'ret': ret, 'err': err, 'dst': dst, 'writes': writes,
            'allocs': list(o.allocs), 'calls': list(o.calls)}


def word_list(blob):
    return list(struct.unpack('<%dI' % (len(blob) // 4), blob))


def diff_words(base, mut):
    """Per-4-byte-word changes: [(off, before, after)] for words that differ."""
    bw, mw = word_list(base), word_list(mut)
    return [(4 * i, bw[i], mw[i]) for i in range(len(bw)) if bw[i] != mw[i]]


def diff_bytes(base, mut):
    """Contiguous differing byte ranges: [(start, end_exclusive)]."""
    out, i, n = [], 0, len(base)
    while i < n:
        if base[i] != mut[i]:
            j = i
            while j < n and base[j] != mut[j]:
                j += 1
            out.append((i, j))
            i = j
        else:
            i += 1
    return out


def fmt_ranges(ranges):
    return ','.join('0x%x' % a if a == b - 1 else '0x%x-0x%x' % (a, b - 1)
                    for a, b in ranges) or 'none'


def fmt_words(changes):
    return ','.join('0x%x:0x%x->0x%x' % c for c in changes) or 'none'


def _runs(offsets):
    """[1,2,3,7] -> [(1,4),(7,8)] for compact range rendering."""
    out = []
    for o in offsets:
        if out and o == out[-1][1]:
            out[-1] = (out[-1][0], o + 1)
        else:
            out.append((o, o + 1))
    return out


def fmt_allocs(allocs):
    return ' '.join('%d@%#x' % (s, a) for a, s in allocs) or '-'


def alloc_sig(allocs):
    return [s for _a, s in allocs]


def i32(v):
    v &= 0xffffffff
    return v - 0x100000000 if v & 0x80000000 else v


def ceil_sqrt(n):
    """Exact integer ceil(sqrt(n)) - no float rounding at perfect squares."""
    r = int(n ** 0.5)
    while r * r < n:
        r += 1
    while r > 0 and (r - 1) * (r - 1) >= n:
        r -= 1
    return r


def diag_predict(rec, off, value):
    """dst+0x2c candidate: ceil(sqrt(A^2+B^2)) with A=max(|ox|,|w-ox|), B=max(|oy|,|h-oy|).

    i.e. the origin's distance to the farthest of the two sprite edges, per axis.

    Returns None when a term leaves the range where plain integer maths is
    trustworthy (the original multiplies in 32 bits, so huge terms wrap).
    """
    f = {n: i32(struct.unpack_from('<I', rec, o)[0]) for n, o, _k in FIELDS}
    f[[n for n, o, _k in FIELDS if o == off][0]] = i32(value)
    a = max(abs(f['origin_x']), abs(f['w'] - f['origin_x']))
    b = max(abs(f['origin_y']), abs(f['h'] - f['origin_y']))
    if a < 0 or b < 0 or a > 0xffff or b > 0xffff:
        return None
    return ceil_sqrt(a * a + b * b)


def probe(wad, rec_off, name, off, kind, base_val, value, base, rec=b''):
    patch = {off: struct.pack('<I', value)}
    t0 = time.time()
    r = run_once(wad, rec_off, patch)
    raw_changes = diff_words(base['dst'], r['dst'])
    # Pointer-normalised view: did anything change beyond heap addresses moving?
    nb = ptrnorm.normalize(base['dst'], base['allocs'])
    nm = ptrnorm.normalize(r['dst'], r['allocs'])
    norm_changes = [i * 4 for i in range(len(nb)) if nb[i] != nm[i]]

    rr = run_once(wad, rec_off, {})              # the counterexample: back to baseline
    reverted = rr['dst'] == base['dst'] and alloc_sig(rr['allocs']) == alloc_sig(base['allocs'])
    same_as_base = r['dst'] == base['dst']

    pred = diag_predict(rec, off, value) if rec else None
    obs = struct.unpack_from('<I', r['dst'], 0x2c)[0]
    if not rec:
        pred_s = '-'
    elif pred is None:
        pred_s = 'n/a(32-bit wrap)'
    elif pred == obs:
        pred_s = 'ok'
    else:
        pred_s = 'pred=%d obs=%d' % (pred, obs)

    bytes_changed = [(i, base['dst'][i], r['dst'][i])
                     for i in range(len(base['dst'])) if base['dst'][i] != r['dst'][i]]
    # Which store instruction produced each changed byte, and with what width.
    seen, stores = set(), []
    for b, _bv, _av in bytes_changed:
        for w in r['writes']:
            if w['off'] <= b < w['off'] + w['size']:
                key = (w['off'], w['size'], w['pc'])
                if key not in seen and len(stores) < 10:
                    seen.add(key)
                    stores.append('0x%x<%d>@0x%x' % key)
    return {
        'field': name, 'rec_off': off, 'base_value': base_val, 'test_value': value,
        'ret': '-1' if r['ret'] is None else '%#x' % r['ret'],
        'err': r['err'] or '-',
        'dst_changed': 'no dst change' if not raw_changes else str(len(raw_changes)),
        'dst_byte_ranges': fmt_ranges(diff_bytes(base['dst'], r['dst'])),
        'dst_words': fmt_words(raw_changes),
        'dst_words_norm': ','.join('0x%x' % o for o in norm_changes) or 'none',
        'dst_bytes': ','.join('0x%x:0x%x->0x%x' % c for c in bytes_changed[:16])
                     or 'no dst change',
        'stores': ','.join(stores) or 'no store at changed bytes',
        'calls': ','.join(c['name'] for c in r['calls'][:24]) or '-',
        'diag_pred': pred_s,
        'raw_equals_base': 'yes' if same_as_base else 'no',
        'alloc_sizes': fmt_allocs(r['allocs']),
        'alloc_changed': 'no' if alloc_sig(r['allocs']) == alloc_sig(base['allocs']) else 'yes',
        'revert_equals_base': 'yes' if reverted else 'no',
        'revert_err': rr['err'] or '-',
        'mut_dst': r['dst'],
        'ms': '%d' % int((time.time() - t0) * 1000),
    }


COLUMNS = ['row', 'field', 'rec_off', 'base_value', 'test_value', 'ret', 'err',
           'dst_changed', 'dst_byte_ranges', 'dst_bytes', 'stores', 'dst_words',
           'dst_words_norm', 'diag_pred', 'raw_equals_base', 'alloc_sizes',
           'alloc_changed', 'revert_equals_base', 'revert_err', 'calls', 'ms']


def row(r):
    return [str(r.get(c, '')) for c in COLUMNS]


def write_tsv(rows, path):
    with open(path, 'w') as f:
        f.write('\t'.join(COLUMNS) + '\n')
        for r in rows:
            f.write('\t'.join(row(r)) + '\n')


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--only', default=None, help='comma-separated field names')
    ap.add_argument('--list', action='store_true')
    ap.add_argument('--rec', default='0x%x' % TEMPLATE)
    ap.add_argument('--out', default=str(OUT))
    args = ap.parse_args()

    fields = FIELDS
    if args.only:
        want = set(args.only.split(','))
        fields = [f for f in FIELDS if f[0] in want]
        missing = want - {f[0] for f in fields}
        if missing:
            raise SystemExit('unknown field(s): %s' % ','.join(sorted(missing)))
    if args.list:
        for n, o, k in FIELDS:
            print('%-12s +0x%02x  %s' % (n, o, k))
        return 0

    if not WAD_PATH:
        raise SystemExit('no WAD found (set CALLY_WAD)')
    wad = open(WAD_PATH, 'rb').read()
    rec_off = int(args.rec, 0)

    print('so       = %s' % SO)
    print('wad      = %s' % WAD_PATH)
    print('template = record @ file %#x' % rec_off)

    base = run_once(wad, rec_off, {})
    base2 = run_once(wad, rec_off, {})
    det = base['dst'] == base2['dst'] and alloc_sig(base['allocs']) == alloc_sig(base2['allocs'])
    print('baseline ret=%s err=%s allocs=%s'
          % ('%#x' % base['ret'] if base['ret'] is not None else '-',
             base['err'] or '-', fmt_allocs(base['allocs'])))
    print('determinism (two identical baseline runs): %s' % ('identical' if det else 'DIFFERS'))
    print('baseline dst[0:0x80] = %s' % base['dst'][:0x80].hex())

    rec = wad[rec_off:rec_off + 0x100]
    rows = [{'row': 'baseline', 'field': 'as-shipped', 'rec_off': 0,
             'base_value': '', 'test_value': '',
             'ret': '%#x' % base['ret'], 'err': base['err'] or '-',
             'dst_changed': '-', 'dst_byte_ranges': '-', 'dst_bytes': '-',
             'dst_words': '-', 'dst_words_norm': '-', 'diag_pred': '-',
             'raw_equals_base': 'yes',
             'alloc_sizes': fmt_allocs(base['allocs']),
             'alloc_changed': 'no',
             'revert_equals_base': 'identical' if det else 'DIFFERS',
             'revert_err': '-',
             'stores': ','.join('0x%x<%d>@0x%x' % (w['off'], w['size'], w['pc'])
                                for w in base['writes']),
             'calls': ','.join(c['name'] for c in base['calls'][:24]) or '-', 'ms': '0'}]

    failures = []
    diag = {'ok': 0, 'bad': [], 'na': 0}
    for name, off, kind in fields:
        bval = struct.unpack_from('<I', rec, off)[0]
        print('\n[%s] +0x%02x base=%#x kind=%s' % (name, off, bval, kind))
        touched, sites = None, []
        for v in VALUES[kind]:
            if v == bval:
                continue
            r = probe(wad, rec_off, name, off, kind, bval, v, base, rec)
            r['row'] = 'probe'
            rows.append(r)
            print('  =%#-10x ret=%-8s err=%-34s dst:%-12s %s | revert=%s alloc=%s'
                  % (v, r['ret'], r['err'][:34], r['dst_changed'],
                     r['dst_byte_ranges'][:60], r['revert_equals_base'],
                     r['alloc_changed']))
            if r['revert_equals_base'] != 'yes':
                failures.append('%s=%#x revert diverged' % (name, v))
            if r['diag_pred'] == 'ok':
                diag['ok'] += 1
            elif r['diag_pred'] == 'n/a(32-bit wrap)':
                diag['na'] += 1
            else:
                diag['bad'].append('%s=%#x %s' % (name, v, r['diag_pred']))
            if touched is None:
                touched = set()
            for lo, hi in diff_bytes(base['dst'], r['mut_dst']):
                touched.update(range(lo, hi))
            for s in r['stores'].split(','):
                if s and s != 'no store at changed bytes' and s not in sites:
                    sites.append(s)
        summ = {'row': 'summary', 'field': name, 'rec_off': off,
                'base_value': bval, 'test_value': 'all/%s' % kind,
                'ret': '-', 'err': '-',
                'dst_changed': 'none' if not touched else '%d bytes' % len(touched),
                'dst_byte_ranges': fmt_ranges(_runs(sorted(touched or []))) or 'none',
                'dst_bytes': '-',
                'stores': ','.join(sites[:8]) or 'no store', 'dst_words': '-', 'dst_words_norm': '-',
                'diag_pred': '-', 'raw_equals_base': '-',
                'alloc_sizes': '-', 'alloc_changed': '-',
                'revert_equals_base': '-', 'revert_err': '-',
                'calls': '-', 'ms': '-'}
        rows.append(summ)

    rows.append({'row': 'derived', 'field': 'dst+0x2c', 'rec_off': 0x2c,
                 'base_value': '', 'test_value': 'ceil(sqrt(A^2+B^2)), '
                 'A=max(|origin_x|,|w-origin_x|), B=max(|origin_y|,|h-origin_y|)',
                 'ret': '-', 'err': '-',
                 'dst_changed': '%d/%d probes match' % (diag['ok'],
                                                        diag['ok'] + len(diag['bad'])),
                 'dst_byte_ranges': 'not a record-field copy', 'dst_bytes': '-',
                 'stores': '-',
                 'dst_words': '-', 'dst_words_norm': '-',
                 'diag_pred': '%d ok, %d mismatch, %d out-of-range'
                              % (diag['ok'], len(diag['bad']), diag['na']),
                 'raw_equals_base': '-', 'alloc_sizes': '-', 'alloc_changed': '-',
                 'revert_equals_base': '-', 'revert_err': '-', 'calls': '-', 'ms': '-'})

    write_tsv(rows, args.out)
    print('\nwrote %s (%d rows)' % (args.out, len(rows)))
    print('revert failures: %d' % len(failures))
    for f in failures:
        print('  ' + f)
    print('dst+0x2c formula: %d ok, %d mismatch, %d out-of-range'
          % (diag['ok'], len(diag['bad']), diag['na']))
    for b in diag['bad']:
        print('  mismatch: ' + b)
    return 0 if not failures and det else 1


if __name__ == '__main__':
    sys.exit(main())
