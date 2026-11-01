#!/usr/bin/env python3
"""Drive the original CSprite::LoadFromChunk (libyoyo 0x1e972c) to completion.

Purpose: prove that a real WAD `SPRT` record can be parsed by the *original*
ARM code inside Unicorn, not by a model of it. Everything the function calls
outside its own text (the PLT imports) must be answered; this probe records
which import is reached and, where the semantics are knowable off-line,
implements it faithfully in Python.

Usage:
    python3 sprite_probe.py              # run; report ret + call sequence
    python3 sprite_probe.py --trace      # also dump the tail of the code trace
    python3 sprite_probe.py --trace --full-trace

Exit code 0 = returned to sentinel (function ran to completion).
"""
import argparse
import pathlib
import struct
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))

from unicorn import UC_HOOK_CODE                      # noqa: E402
from unicorn.arm_const import UC_ARM_REG_PC, UC_ARM_REG_R0, UC_ARM_REG_R1  # noqa: E402

from handler_oracle import Oracle, plt_symbols, ROOT, SO  # noqa: E402

ROOT = pathlib.Path(__file__).resolve().parents[3]   # repo root
WAD_CANDIDATES = [
    os.environ.get('CALLY_WAD'),
    str(ROOT / 'assets/game.droid'),
    os.path.expanduser('~/callys-caves-2-rs/assets/game.droid'),
]
WAD_PATH = next((p for p in WAD_CANDIDATES if p and os.path.exists(p)), None)

WAD_BASE = 0x80000000
WAD_GLOBAL = 0x544c44          # engine global holding the mapped WAD base
SPRITE_ENTRY = 0x1e972c        # CSprite::LoadFromChunk
SPRITE_REC0 = 0xf0c            # file offset of SPRT record 0
DST = 0x20000000               # destination CSprite object (>=0x400 bytes)
DST_SIZE = 0x1000


def load_wad(path):
    return open(path, 'rb').read()


def build(oracle, wad, extra_stubs=None):
    """Map the WAD, point the engine global at it, zero the destination."""
    u = oracle.uc
    total = (len(wad) + 0xfff) & ~0xfff
    u.mem_map(WAD_BASE, total)
    u.mem_write(WAD_BASE, wad)
    u.mem_write(WAD_GLOBAL, struct.pack('<I', WAD_BASE))
    u.mem_map(DST, DST_SIZE)
    u.mem_write(DST, b'\0' * DST_SIZE)


def make_oracle(extra_stubs=None):
    o = Oracle(libc=True, extra_stubs=extra_stubs)
    o.plt = plt_symbols(o.so)
    return o


def trace_run(o, wad, limit=4000):
    """Run once with a code hook, return (ret_or_None, error, trace list)."""
    seq = []
    hooked = set(o.plt.values())

    def on_code(uc, address, size, _d):
        if len(seq) < limit:
            seq.append(address)

    o.uc.hook_add(UC_HOOK_CODE, on_code)
    try:
        ret = o.call(SPRITE_ENTRY, r0=DST, r1=WAD_BASE + SPRITE_REC0, r2=0)
        return ret, None, seq
    except Exception as exc:                     # noqa: BLE001 - report verbatim
        return None, exc, seq


def name_for(o, addr):
    for name, a in o.plt.items():
        if a == addr:
            return name
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--trace', action='store_true')
    ap.add_argument('--full-trace', action='store_true')
    ap.add_argument('--limit', type=int, default=60)
    args = ap.parse_args()

    wad = load_wad(ROOT / 'assets/game.droid')
    o = make_oracle()
    build(o, wad)

    ret, err, seq = trace_run(o, wad)

    print('so            =', SO)
    print('wad bytes     =', len(wad))
    print('entry         = %#x  r0(dst)=%#x  r1(sprt0)=%#x  r2=0'
          % (SPRITE_ENTRY, DST, WAD_BASE + SPRITE_REC0))
    print('calls made    =', len(o.calls))
    print('code addrs    =', len(seq))
    print('libc_hooked   =', len(o.libc_hooked))
    for name, addr in o.libc_hooked:
        print('   %-30s %#x' % (name, addr))
    if err is not None:
        print('RESULT: FAILED')
        print('  error =', err)
        print('  last successful call =',
              o.calls[-1]['name'] if o.calls else '(none)')
    else:
        print('RESULT: returned, r0 =', ret)
    print('dst[0:0x40]   =', bytes(o.uc.mem_read(DST, 0x40)).hex())
    print('call sequence:')
    for i, c in enumerate(o.calls[:args.limit]):
        extra = ''
        if 'ret' in c:
            extra = ' -> %#x' % c['ret']
        if 'out' in c:
            extra = ' fmt=%r out=%r' % (c['fmt'], c['out'])
        print('  %3d %-28s %s%s' % (i, c['name'], c['args'], extra))
    if len(o.calls) > args.limit:
        print('  ... %d more' % (len(o.calls) - args.limit))

    if args.trace and seq:
        print('trace tail (last 40):')
        for a in seq[-40:]:
            print('   %#x %s' % (a, name_for(o, a) or ''))
        low = [a for a in seq if a < 0x1000]
        if low:
            print('first low addr =', hex(low[0]))
            idx = seq.index(low[0])
            for a in seq[max(0, idx - 3):idx + 4]:
                print('   ctx %#x %s' % (a, name_for(o, a) or ''))
    return 0 if err is None else 1


if __name__ == '__main__':
    sys.exit(main())
