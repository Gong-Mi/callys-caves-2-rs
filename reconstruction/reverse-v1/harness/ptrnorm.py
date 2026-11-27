#!/usr/bin/env python3
"""Pointer normalisation for struct comparisons.

A parsed loader object is full of heap pointers (frame arrays, mask blobs).
Two arms that allocate independently will never agree on raw bytes, so before
comparing a destination struct we replace every 4-byte word that falls inside a
recorded allocation with a stable token: ('alloc', index, offset).

The oracle side keys on Oracle.allocs (bump allocator, deterministic order); the
C side must allocate from its own arena in the same order, so the indices line
up. Anything that is not a known allocation stays as raw bytes, which keeps
"a pointer into the data file" (WAD offsets) distinguishable from "a heap
pointer" instead of lumping them together.

Usage:
    from ptrnorm import normalize
    a = normalize(struct_bytes, allocs)
    b = normalize(c_struct_bytes, c_allocs)
    assert a == b
"""
import struct

MAGIC = 0x70300000  # marker so a normalised token never collides with raw bytes


def _ranges(allocs):
    out = []
    for i, (addr, size) in enumerate(allocs):
        out.append((addr, addr + max(size, 1), i))
    return out


def normalize(blob, allocs, word=4):
    """Return a list of tokens: ints for raw words, ('alloc', i, off) for pointers."""
    ranges = _ranges(allocs)
    tokens = []
    for off in range(0, len(blob) - word + 1, word):
        v = struct.unpack_from('<I', blob, off)[0]
        hit = None
        for lo, hi, idx in ranges:
            if lo <= v < hi:
                hit = ('alloc', idx, v - lo)
                break
        tokens.append(hit if hit else v)
    return tokens


def describe(tokens):
    """Compact rendering for a receipt: only the pointer positions matter."""
    return [t if isinstance(t, tuple) else hex(t) for t in tokens]


def self_test():
    blob = struct.pack('<IIII', 0x1234, 0x71000020, 0x71000040, 0)
    allocs = [(0x71000020, 16), (0x71000030, 64)]
    got = normalize(blob, allocs)
    # 0x71000040 is inside the SECOND allocation (0x30..0x70), not the first -
    # the first run of this self-test got that wrong, not the normaliser.
    expect = [0x1234, ('alloc', 0, 0), ('alloc', 1, 16), 0]
    assert got == expect, (got, expect)
    # a WAD offset that happens to look like a pointer must NOT be swallowed
    blob2 = struct.pack('<I', 0x71000010)
    assert normalize(blob2, allocs) == [0x71000010]
    print('ptrnorm self-test ok')


if __name__ == '__main__':
    self_test()
