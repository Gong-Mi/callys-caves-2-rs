#!/usr/bin/env python3
"""Generic single-byte sweep for a `CX::LoadFromChunk(dst, src, ...)` parser.

Why: the record->struct map is exactly what the asset-loading analysis needs,
and the only trustworthy source for it is the original parser itself. Put one
non-zero byte in the source record at a time, run the original, and see which
destination bytes move. No model, no guessing.

Usage: python3 sweep_loader.py <addr-hex> [--dst 0x400] [--src 0x100] [--max 0x80]
"""
import argparse
import sys

sys.path.insert(0, '/data/data/com.termux/files/home/cally-worktrees/prague-db-20261027/reconstruction/reverse-v1/harness')
from handler_oracle import Oracle


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('addr')
    ap.add_argument('--dst', default='0x400')
    ap.add_argument('--src', default='0x100')
    ap.add_argument('--max', default='0x80')
    ap.add_argument('--r2', default='0')
    args = ap.parse_args()
    entry = int(args.addr, 16)
    dst_size = int(args.dst, 16)
    src_size = int(args.src, 16)
    limit = int(args.max, 16)
    r2 = int(args.r2, 16)

    o = Oracle()
    dst = o.alloc(dst_size)
    src = o.alloc(src_size)

    def run(blob):
        o.write(dst, b'\0' * dst_size)
        o.write(src, blob + b'\0' * (src_size - len(blob)))
        ret = o.call(entry, r0=dst, r1=src, r2=r2)
        return ret, bytes(o.read(dst, dst_size))

    try:
        ret0, base = run(b'')
    except Exception as e:
        print('baseline FAILED: %s (pc=%#x)' % (e, o.uc.reg_read(15)))
        return 1
    print('baseline ret=%#x  dst bytes changed vs zero: %s'
          % (ret0, [hex(i) for i, b in enumerate(base) if b][:24]))

    for i in range(limit):
        blob = bytearray(src_size)
        blob[i] = 0x11
        try:
            ret, got = run(bytes(blob))
        except Exception as e:
            print('  src[%#04x] FAULT %s (pc=%#x)' % (i, e, o.uc.reg_read(15)))
            continue
        diff = [j for j in range(dst_size) if got[j] != base[j]]
        if diff:
            print('  src[%#04x] -> dst %s  ret=%#x' % (i, [hex(x) for x in diff[:8]], ret))
    return 0


if __name__ == '__main__':
    sys.exit(main())
