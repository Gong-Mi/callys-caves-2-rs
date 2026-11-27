#!/usr/bin/env python3
"""Run the *original* CSprite::LoadFromChunk (libyoyo 0x1e972c) over every real
SPRT record in assets/game.droid, and write the parsed destination struct for
each record as a normalised, reproducible receipt.

Why this exists: `sprite_probe.py` proves the trick works on one record by hand.
This script turns that into an exhaustive census - 178 records - so the C
reconstruction has a per-record oracle to diff against instead of a story about
one sprite.

What each row is: the 0x400-byte destination object the original ARM code wrote,
word by word, with every heap pointer replaced by ('A<alloc-index>+<offset>')
via ptrnorm.normalize(). Non-pointer words stay as raw hex, so a WAD-relative
offset can never be mistaken for a heap pointer.

What it is NOT: an interpretation of the struct. No field names are asserted
here; the layout claim belongs to the per-field diff (object_load_diff.py /
sprite_records.py). This file only records *what the code produced*.

Determinism: every record is executed twice, each time from a freshly built
Oracle, and the two normalised token lists must be byte-identical. A mismatch is
a hard failure, not a warning - it means the run carries hidden state.

Usage:
    $PREFIX/bin/python3 sprite_oracle.py                # all records -> sprite_oracle.tsv
    $PREFIX/bin/python3 sprite_oracle.py --ids 0,29,177 # subset
    $PREFIX/bin/python3 sprite_oracle.py --once         # skip the 2nd run
    $PREFIX/bin/python3 sprite_oracle.py --data PATH --out PATH

Exit code 0 = every record returned and every determinism check matched.
"""
import argparse
import hashlib
import os
import pathlib
import struct
import sys
import time

HERE = pathlib.Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))

from unicorn import UC_HOOK_MEM_WRITE                                  # noqa: E402
from unicorn.arm_const import UC_ARM_REG_PC                           # noqa: E402

from handler_oracle import (Oracle, SO, HEAP, HEAP_SIZE,              # noqa: E402
                            UnhookedImport)
from ptrnorm import normalize                                         # noqa: E402

REPO = HERE.parents[2]
WAD_CANDIDATES = [
    os.environ.get('CALLY_WAD'),
    str(REPO / 'assets/game.droid'),
    os.path.expanduser('~/callys-caves-2-rust/assets/game.droid'),
]
WAD_PATH = next((p for p in WAD_CANDIDATES if p and os.path.exists(p)), None)

WAD_BASE = 0x80000000     # game.droid mapped here
WAD_GLOBAL = 0x544c44     # engine global that holds the WAD base
SPRITE_ENTRY = 0x1e972c   # CSprite::LoadFromChunk(YYSprite*, uint8_t*)
DST = 0x20000000          # destination object, >= 0x400 bytes
DST_SIZE = 0x1000
DUMP = 0x400              # how much of dst is reported
SENTINEL = 0xdead0000

# Records sampled for the reported determinism proof (spread over the table:
# first, the anchor spr_player, two mid-table, the last one).
DET_SAMPLE = [0, 29, 88, 144, 177]

TSV_COLUMNS = [
    'id', 'offset', 'name', 'w', 'h', 'tpag_count',
    'ok', 'ret', 'n_calls', 'calls', 'n_allocs', 'allocs', 'n_writes',
    'norm_sha256', 'dst_sha256', 'tokens', 'suspicious', 'notes', 'det',
]


def sha(b):
    return hashlib.sha256(b).hexdigest()


def token_bytes(tokens):
    """Canonical bytes of a token list, for hashing without repr quirks."""
    out = bytearray()
    for t in tokens:
        if isinstance(t, tuple):
            _, idx, off = t
            out += b'A%x+%x;' % (idx, off)
        else:
            out += b'%08x;' % t
    return bytes(out)


def fmt_tokens(tokens):
    """Compact, single-cell rendering: raw word hex, or A<idx>+<off>."""
    return ','.join('A%d+%x' % (t[1], t[2]) if isinstance(t, tuple) else '%08x' % t
                    for t in tokens)


def so_range():
    """Address range the .so occupies once mapped (so a stored code pointer is
    classified instead of being lumped in with 'wild value')."""
    from elftools.elf.elffile import ELFFile
    lo, hi = 1 << 32, 0
    with open(SO, 'rb') as f:
        for seg in ELFFile(f).iter_segments():
            if seg['p_type'] != 'PT_LOAD':
                continue
            lo = min(lo, seg['p_vaddr'] & ~0xfff)
            hi = max(hi, seg['p_vaddr'] + seg['p_memsz'])
    return lo, hi


def load_records(path):
    """Read the independent record parse (id/offset/name/w/h/tpag_count).

    The offsets come from sprite_records.tsv, the independent reader - not from
    anything this script computes - so a bad offset cannot be self-consistent.
    """
    rows = []
    with open(path) as f:
        head = f.readline().rstrip('\n').split('\t')
        idx = {k: i for i, k in enumerate(head)}
        for line in f:
            parts = line.rstrip('\n').split('\t')
            if len(parts) < len(head):
                continue
            rows.append({
                'id': int(parts[idx['id']]),
                'offset': int(parts[idx['offset']], 0),
                'name': parts[idx['name']],
                'w': int(parts[idx['w']]),
                'h': int(parts[idx['h']]),
                'tpag': int(parts[idx['tpag_count']]),
                'bbox': tuple(int(parts[idx[k]]) for k in
                              ('bbox_left', 'bbox_right', 'bbox_bottom', 'bbox_top')),
                'origin': (int(parts[idx['origin_x']]), int(parts[idx['origin_y']])),
            })
    return rows


class Session:
    """One isolated execution: fresh Oracle, fresh heap, fresh dst.

    A fresh Oracle per record costs ~0.1 s and removes the whole class of
    'did the previous record's allocations leak into this one' mistakes - the
    allocation list is what ptrnorm keys on, so a leaked bump pointer would
    silently renormalise this record's pointers to the wrong indices.
    """

    def __init__(self, wad, so_lo, so_hi, guard_plt=True):
        self.o = Oracle(so=SO, libc=True, guard_plt=guard_plt)
        self.u = self.o.uc
        self.u.mem_map(WAD_BASE, (len(wad) + 0xfff) & ~0xfff)
        self.u.mem_write(WAD_BASE, wad)
        self.u.mem_write(WAD_GLOBAL, struct.pack('<I', WAD_BASE))
        self.u.mem_map(DST, DST_SIZE)
        self.u.mem_write(DST, b'\0' * DST_SIZE)
        self.so_lo, self.so_hi = so_lo, so_hi
        self.writes = []
        self.u.hook_add(UC_HOOK_MEM_WRITE, self._on_write, begin=DST,
                        end=DST + DST_SIZE - 1)

    def _on_write(self, uc, _access, address, size, value, _d):
        self.writes.append((uc.reg_read(UC_ARM_REG_PC), address, size, value))

    def classify(self, v):
        """Where a 4-byte word points, or what it plainly is."""
        if v == 0:
            return ('zero',)
        if v == SENTINEL:
            return ('sentinel',)
        for i, (addr, size) in enumerate(self.o.allocs):
            if addr <= v < addr + max(size, 1):
                return ('alloc', i, v - addr)
        if WAD_BASE <= v < WAD_BASE + 0x2000000:
            return ('wad',)
        if v < 0x1000:
            # ambiguous by construction: a bbox/dimension stays a small
            # integer, and a null-page pointer has the same shape. Value-only
            # classification cannot separate them, so this is NOT a suspicion
            # signal - it is counted and reported as such.
            return ('small',)
        if v >= 0xfffff000:
            # -4096..-1 as i32: an origin/bbox offset in every record that has
            # one (id 174 spr_mapicon: origin -12/-12 lands at dst[0x24]/[0x28]).
            # Same "value alone cannot decide" case as 'small'.
            return ('neg_small',)
        if HEAP <= v < HEAP + HEAP_SIZE:
            # heap-looking but no live allocation covers it: a stale or
            # never-recorded pointer - the one kind of value ptrnorm leaves raw
            # and therefore the one that can hide a bug.
            return ('heap_unbacked',)
        if self.so_lo <= v < self.so_hi:
            return ('so',)
        return ('other',)

    def run(self, rec_off):
        """Execute the original function once against one record."""
        err = None
        ret = None
        try:
            ret = self.o.call(SPRITE_ENTRY, r0=DST, r1=WAD_BASE + rec_off, r2=0)
        except UnhookedImport as exc:
            err = ('UnhookedImport', str(exc))
        except Exception as exc:                                # noqa: BLE001
            err = (type(exc).__name__, str(exc))
        dst = bytes(self.u.mem_read(DST, DUMP))
        return ret, dst, err


def one_record(wad, rec, so_lo, so_hi):
    """Run a record in a brand-new session and describe the result."""
    s = Session(wad, so_lo, so_hi)
    t0 = time.time()
    ret, dst, err = s.run(rec['offset'])
    dt = time.time() - t0
    allocs = list(s.o.allocs)
    tokens = normalize(dst, allocs)
    calls = [c['name'] for c in s.o.calls]

    susp, notes = [], []
    # the function returns a bool in the ABI (r0 = 0/1) - label that instead of
    # letting 1 look like a wild low pointer
    ret_cls = (('bool',) if ret in (0, 1) else s.classify(ret or 0))
    if ret is not None:
        if ret_cls[0] == 'heap_unbacked':
            susp.append('ret_heap_unbacked:%#x' % ret)
        elif ret_cls[0] in ('other', 'sentinel'):
            susp.append('ret_wild:%#x' % ret)
        elif ret_cls[0] == 'alloc':
            notes.append('ret_in_alloc=A%d+%x' % (ret_cls[1], ret_cls[2]))
        else:
            notes.append('ret=%s' % ret_cls[0])

    so_ptrs, counts = [], {}
    for word_i, tok in enumerate(tokens):
        off = word_i * 4
        if isinstance(tok, tuple):
            # a stored pointer that lands inside a recorded allocation: this is
            # the normalised case, and the alloc index/offset is the receipt
            continue
        cls = s.classify(tok)
        if cls[0] == 'heap_unbacked':
            susp.append('dst[%#x]heap_unbacked:%#x' % (off, tok))
        elif cls[0] in ('other', 'sentinel'):
            susp.append('dst[%#x]wild:%#x' % (off, tok))
        counts[cls[0]] = counts.get(cls[0], 0) + 1
        if cls[0] == 'so':
            so_ptrs.append(off)
    notes.append('words=' + ','.join('%s:%d' % (k, counts[k]) for k in
                                     ('zero', 'small', 'alloc', 'wad', 'so',
                                      'heap_unbacked', 'other') if counts.get(k)))
    if so_ptrs:
        notes.append('so_ptrs=%d@%s' % (len(so_ptrs),
                                        ','.join('%#x' % o for o in so_ptrs[:4])))

    if err is not None:
        susp.append('err:%s' % err[0])
    if not s.writes:
        susp.append('no_writes')
    n_alloc = len(allocs)
    if n_alloc == 0 and rec['tpag'] > 0:
        notes.append('no_allocs_with_tpag')
    # cross-check against the independent parse: the second block the function
    # allocates tracks the record's TPAG count as 4*tpag+16 for every record but
    # one, so a deviation is worth a note (it is not by itself an error).
    if n_alloc >= 2:
        exp = 4 * rec['tpag'] + 16
        if allocs[1][1] != exp:
            notes.append('alloc1_vs_4tpag16=%d/%d' % (allocs[1][1], exp))

    # Do the record's own numbers survive into the object? This is the part of
    # the receipt that can be checked against the independent parse without
    # knowing the struct layout: which of the record's integers appear verbatim.
    words = [t for t in tokens if not isinstance(t, tuple)]
    u32 = lambda v: v & 0xffffffff
    seen = []
    for label, val in (('w', rec['w']), ('h', rec['h']),
                       ('bl', rec['bbox'][0]), ('br', rec['bbox'][1]),
                       ('bb', rec['bbox'][2]), ('bt', rec['bbox'][3]),
                       ('ox', rec['origin'][0]), ('oy', rec['origin'][1]),
                       ('n', rec['tpag'])):
        if u32(val) in words:
            seen.append(label)
    notes.append('fields_in_dst=' + (','.join(seen) or '-'))
    if 'w' not in seen and 'h' not in seen and n_alloc == 0 and not susp:
        susp.append('no_dims_no_allocs')

    return {
        'ret': ret, 'dst': dst, 'err': err, 'allocs': allocs, 'tokens': tokens,
        'calls': calls, 'writes': len(s.writes), 'dt': dt,
        'suspicious': susp, 'notes': notes,
    }


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--data', default=WAD_PATH)
    ap.add_argument('--records', default=str(HERE / 'sprite_records.tsv'))
    ap.add_argument('--out', default=str(HERE / 'sprite_oracle.tsv'))
    ap.add_argument('--ids', default='')
    ap.add_argument('--once', action='store_true',
                    help='single run per record (no determinism proof)')
    args = ap.parse_args()

    if not args.data or not os.path.exists(args.data):
        raise SystemExit('game.droid not found (set CALLY_WAD)')
    wad = open(args.data, 'rb').read()
    recs = load_records(args.records)
    if args.ids:
        want = {int(x, 0) for x in args.ids.split(',')}
        recs = [r for r in recs if r['id'] in want]
    so_lo, so_hi = so_range()

    print('so            =', SO)
    print('wad           =', args.data)
    print('records       =', len(recs), 'from', args.records)
    print('entry         = %#x  dst=%#x  r2=0' % (SPRITE_ENTRY, DST))
    print('so mapped     = %#x..%#x' % (so_lo, so_hi))
    print('oracle mode   = libc=True guard_plt=True, no extra stubs')
    print()

    rows, fails, susp_rows = [], [], []
    det_checked, det_mismatch = [], []
    t_start = time.time()

    for rec in recs:
        a = one_record(wad, rec, so_lo, so_hi)
        det = ''
        if not args.once:
            b = one_record(wad, rec, so_lo, so_hi)
            same = token_bytes(a['tokens']) == token_bytes(b['tokens'])
            alloc_same = a['allocs'] == b['allocs']
            det = 'match' if (same and alloc_same) else 'MISMATCH'
            det_checked.append((rec['id'], det))
            if det != 'match':
                det_mismatch.append(rec['id'])
                a['suspicious'].append('nondeterministic')
        row = {
            'id': rec['id'], 'offset': '0x%x' % rec['offset'], 'name': rec['name'],
            'w': rec['w'], 'h': rec['h'], 'tpag_count': rec['tpag'],
            'ok': 1 if a['err'] is None else 0,
            'ret': '0x%x' % a['ret'] if a['ret'] is not None else '',
            'n_calls': len(a['calls']), 'calls': ','.join(a['calls']),
            'n_allocs': len(a['allocs']),
            'allocs': ';'.join('%#x:%d' % (x, y) for x, y in a['allocs']) or '-',
            'n_writes': a['writes'],
            'norm_sha256': sha(token_bytes(a['tokens'])),
            'dst_sha256': sha(a['dst']),
            'tokens': fmt_tokens(a['tokens']),
            'suspicious': ';'.join(a['suspicious']) or '-',
            'notes': ';'.join(a['notes']),
            'det': det,
        }
        rows.append(row)
        if a['err'] is not None:
            fails.append((rec['id'], rec['name'], a['err']))
        if a['suspicious']:
            susp_rows.append((rec['id'], rec['name'], a['suspicious']))
        print('  id %3d %-24s %s ret=%s calls=%2d allocs=%s '
              'writes=%3d dst=%s%s'
              % (rec['id'], rec['name'], 'OK  ' if a['err'] is None else 'FAIL',
                 row['ret'] or '-', len(a['calls']), row['allocs'],
                 a['writes'], row['dst_sha256'][:12],
                 '  SUSPICIOUS' if a['suspicious'] else ''))

    with open(args.out, 'w') as f:
        f.write('\t'.join(TSV_COLUMNS) + '\n')
        for r in rows:
            f.write('\t'.join(str(r[c]) for c in TSV_COLUMNS) + '\n')

    # ---- report -----------------------------------------------------------
    el = time.time() - t_start
    print()
    print('=== SUMMARY ===')
    print('records run     = %d  (%.1fs total, %.3fs/record incl. 2nd run)'
          % (len(rows), el, el / max(len(rows), 1)))
    print('returned ok     = %d' % sum(r['ok'] for r in rows))
    print('raised          = %d' % len(fails))
    for rid, name, err in fails[:20]:
        print('   id %3d %-24s %s: %s' % (rid, name, err[0], err[1][:120]))
    print('suspicious rows = %d' % len(susp_rows))
    for rid, name, s in susp_rows[:40]:
        print('   id %3d %-24s %s' % (rid, name, ';'.join(s)[:200]))
    if not args.once:
        bad = [d for d in det_checked if d[1] != 'match']
        print('determinism     = %d/%d records double-run, %d mismatch'
              % (len(det_checked), len(det_checked), len(bad)))
        print('  sampled in report:')
        for rid in DET_SAMPLE:
            got = dict(det_checked).get(rid)
            if got is not None:
                row = next(r for r in rows if r['id'] == rid)
                print('    id %3d  %-7s norm_sha256=%s' % (rid, got,
                                                           row['norm_sha256']))
    digest = sha(''.join('%d:%s;' % (r['id'], r['norm_sha256']) for r in rows).encode())
    print('combined norm digest = %s  (sha256 over id:hash pairs, in id order)'
          % digest)
    print('written         = %s (%d data rows)' % (args.out, len(rows)))
    return 0 if (not fails and not det_mismatch) else 1


if __name__ == '__main__':
    sys.exit(main())
