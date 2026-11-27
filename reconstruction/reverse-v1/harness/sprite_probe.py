#!/usr/bin/env python3
"""Drive the original CSprite::LoadFromChunk (libyoyo 0x1e972c) to completion.

Purpose: prove that a real WAD `SPRT` record can be parsed by the *original*
ARM code inside Unicorn, not by a model of it. Every callee outside the
function's own text is a PLT import; the Oracle answers them and this probe
shows which ones were reached, in what order, with what arguments, and what
the function then stored into the destination object.

Usage:
    python3 sprite_probe.py                 # run; ret + calls + stores into dst
    python3 sprite_probe.py --reads         # also every load from the record
    python3 sprite_probe.py --trace         # tail of the executed address trace
    python3 sprite_probe.py --zero-record   # zero the record: run must diverge
    python3 sprite_probe.py --rec 0x1a34    # a different SPRT record offset

Exit code 0 = returned to the sentinel (function ran to completion).
"""
import argparse
import os
import pathlib
import struct
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))

from unicorn import UC_HOOK_CODE, UC_HOOK_MEM_READ, UC_HOOK_MEM_WRITE  # noqa: E402
from unicorn.arm_const import UC_ARM_REG_PC, UC_ARM_REG_LR           # noqa: E402

import handler_oracle                                                # noqa: E402
from handler_oracle import Oracle, SO                                # noqa: E402

ROOT = pathlib.Path(__file__).resolve().parents[3]   # repo root
WAD_CANDIDATES = [
    os.environ.get('CALLY_WAD'),
    str(ROOT / 'assets/game.droid'),
    os.path.expanduser('~/callys-caves-2-rs/assets/game.droid'),
]
WAD_PATH = next((p for p in WAD_CANDIDATES if p and os.path.exists(p)), None)

WAD_BASE = 0x80000000
WAD_GLOBAL = 0x544c44          # engine global holding the mapped WAD base
SPRITE_ENTRY = 0x1e972c        # CSprite::LoadFromChunk(YYSprite*, uint8_t*)
SPRITE_REC0 = 0xf0c            # file offset of SPRT record 0
DST = 0x20000000               # destination CSprite object (>=0x400 bytes)
DST_SIZE = 0x1000


def add_write_log(o, lo, hi):
    """Record every store the original function makes into [lo, hi)."""
    log = []

    def on_write(uc, _access, address, size, value, _d):
        log.append({'pc': uc.reg_read(UC_ARM_REG_PC), 'addr': address,
                    'size': size, 'value': value})

    o.uc.hook_add(UC_HOOK_MEM_WRITE, on_write, begin=lo, end=hi - 1)
    return log


def add_read_log(o, lo, hi):
    """Record every load from the source record [lo, hi)."""
    log = []

    def on_read(uc, _access, address, size, value, _d):
        log.append({'pc': uc.reg_read(UC_ARM_REG_PC), 'addr': address,
                    'size': size, 'value': value})

    o.uc.hook_add(UC_HOOK_MEM_READ, on_read, begin=lo, end=hi - 1)
    return log


def add_code_log(o, limit):
    seq = []

    def on_code(uc, address, size, _d):
        if len(seq) < limit:
            seq.append(address)

    o.uc.hook_add(UC_HOOK_CODE, on_code)
    return seq


def legacy_plt_symbols(so):
    """The pre-fix mapping: entries assumed to start at .plt+16, 12 bytes apart.

    Kept only to reproduce the old failure on demand: it is off by one entry,
    so each hook sits on the previous relocation's `ldr pc` and the entry the
    caller actually wanted keeps its unresolved GOT slot (-> PLT0 -> pc=0).
    """
    from elftools.elf.elffile import ELFFile
    out = {}
    with open(so, 'rb') as f:
        elf = ELFFile(f)
        base = elf.get_section_by_name('.plt')['sh_addr']
        rel = elf.get_section_by_name('.rel.plt')
        sym = elf.get_section_by_name('.dynsym')
        for i, r in enumerate(rel.iter_relocations()):
            out.setdefault(sym.get_symbol(r['r_info_sym']).name, base + 16 + 12 * i)
    return out


def run(rec_off=SPRITE_REC0, zero_record=False, code_limit=0, want_reads=False,
        guard_plt=True, so=SO, legacy_plt=False):
    wad = open(WAD_PATH, 'rb').read()
    if zero_record:
        blob = bytearray(wad)
        blob[rec_off:rec_off + 0x100] = b'\0' * 0x100
        wad = bytes(blob)

    if legacy_plt:
        handler_oracle.plt_symbols = legacy_plt_symbols
    o = Oracle(so=so, libc=True, guard_plt=guard_plt)
    u = o.uc
    u.mem_map(WAD_BASE, (len(wad) + 0xfff) & ~0xfff)
    u.mem_write(WAD_BASE, wad)
    u.mem_write(WAD_GLOBAL, struct.pack('<I', WAD_BASE))
    u.mem_map(DST, DST_SIZE)
    u.mem_write(DST, b'\0' * DST_SIZE)

    writes = add_write_log(o, DST, DST + DST_SIZE)
    reads = add_read_log(o, WAD_BASE + rec_off, WAD_BASE + rec_off + 0x100) \
        if want_reads else []
    seq = add_code_log(o, code_limit) if code_limit else []

    err = ret = None
    try:
        ret = o.call(SPRITE_ENTRY, r0=DST, r1=WAD_BASE + rec_off, r2=0)
    except Exception as exc:                       # noqa: BLE001 - report verbatim
        err = exc
    return {'oracle': o, 'ret': ret, 'err': err, 'writes': writes, 'reads': reads,
            'seq': seq, 'rec_off': rec_off, 'zero': zero_record,
            'record': bytes(u.mem_read(WAD_BASE + rec_off, 0x40))}


def report(r, args):
    o = r['oracle']
    print('so            =', SO)
    print('wad path      =', WAD_PATH)
    print('record        = file %#x (%s)' % (r['rec_off'],
                                            'zeroed' if r['zero'] else 'as shipped'))
    print('record[0:0x40]=', r['record'].hex())
    print('entry         = %#x  r0(dst)=%#x  r1(rec)=%#x  r2=0'
          % (SPRITE_ENTRY, DST, WAD_BASE + r['rec_off']))
    print('libc_hooked   = %d' % len(o.libc_hooked))
    for name, addr in o.libc_hooked:
        print('   %-30s %#x' % (name, addr))
    if r['err'] is not None:
        prev = [c for c in o.calls if not c.get('blocked')]
        print('RESULT        = FAILED')
        print('  error       =', r['err'])
        print('  last ok call=', (prev[-1]['name'] if prev else '(none)'))
        b = getattr(o, 'blocked', None)
        if b is not None:
            print('  blocked     = %s @ %#x args=%s'
                  % (b.name, b.addr, ['%#x' % a for a in b.arg_words]))
    else:
        print('RESULT        = returned, r0 = %#x' % r['ret'])
    print('dst[0:0x40]   =', bytes(o.uc.mem_read(DST, 0x40)).hex())
    print('stores into dst (%d):' % len(r['writes']))
    for w in r['writes'][:args.limit]:
        print('   pc=%#x  [%#x] <%d> = %#x' % (w['pc'], w['addr'] - DST,
                                              w['size'], w['value']))
    if len(r['writes']) > args.limit:
        print('   ... %d more' % (len(r['writes']) - args.limit))
    print('calls (%d):' % len(o.calls))
    for i, c in enumerate(o.calls[:args.limit]):
        extra = ''
        if 'ret' in c:
            extra = ' -> %#x' % c['ret']
        if 'out' in c:
            extra = ' fmt=%r out=%r' % (c['fmt'], c['out'])
        if c.get('blocked'):
            extra = '  <-- BLOCKED'
        print('  %3d %-26s %s%s' % (i, c['name'], c['args'], extra))
    if len(o.calls) > args.limit:
        print('  ... %d more' % (len(o.calls) - args.limit))
    if r['reads']:
        print('loads from record (%d):' % len(r['reads']))
        for d in r['reads'][:args.limit]:
            print('   pc=%#x  rec+%#x <%d> = %#x'
                  % (d['pc'], d['addr'] - (WAD_BASE + r['rec_off']),
                     d['size'], d['value']))
    if args.trace and r['seq']:
        print('trace: %d addrs, last 24:' % len(r['seq']))
        for a in r['seq'][-24:]:
            print('   %#x' % a)
        low = [a for a in r['seq'] if a < 0x1000]
        if low:
            i = r['seq'].index(low[0])
            print('first low addr %#x, context:' % low[0])
            for a in r['seq'][max(0, i - 3):i + 4]:
                print('   %#x' % a)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--trace', action='store_true')
    ap.add_argument('--reads', action='store_true')
    ap.add_argument('--zero-record', action='store_true')
    ap.add_argument('--rec', default='0x%x' % SPRITE_REC0)
    ap.add_argument('--no-guard', action='store_true',
                    help='let an unanswerable import run into PLT0 (old symptom)')
    ap.add_argument('--legacy-plt', action='store_true',
                    help='reproduce the pre-fix off-by-one PLT mapping')
    ap.add_argument('--limit', type=int, default=40)
    args = ap.parse_args()

    rec = int(args.rec, 0)
    r = run(rec_off=rec, zero_record=args.zero_record,
            code_limit=4000 if args.trace else 0, want_reads=args.reads,
            legacy_plt=args.legacy_plt, guard_plt=not args.no_guard)
    report(r, args)
    return 0 if r['err'] is None else 1


if __name__ == '__main__':
    sys.exit(main())
