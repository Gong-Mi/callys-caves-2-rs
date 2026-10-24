#!/usr/bin/env python3
"""Unicorn oracle for CSprite::PreciseCollision @0x1e4298 (libyoyo ARMv7).

The runner's own function is the judge for the three details our C/Rust port
cannot self-validate: rotation centre rounding, the un-rotate/un-scale rounding
mode, and the mask base offset.

Argument order, recovered from the call site at CInstance::Collision_Instance
@0x1957ac (softfp: every scalar is a 32-bit slot):

    PreciseCollision(frameA, rectA*, xA:int, yA:int, sxA, syA, angleA,
                     spriteB*, frameB, rectB*, xB:int, yB:int, sxB, syB, angleB)

YYRECT is {left, top, right, bottom} as ints at +0/+4/+8/+12.
A CSprite's mask table lives at +0x40 (8 bytes per frame, bits pointer at +4),
the frame count at +0x3c, the mask base at +0x24/+0x28, and +0x31 = 1 tells
UnpackWADMask the table is ready. Unpacked masks are one byte per pixel.

Usage:  python3 oracle_precise.py            (runs the sanity matrix)
"""
import struct
import sys

from unicorn import Uc, UC_ARCH_ARM, UC_MODE_ARM, UC_HOOK_CODE
from unicorn.arm_const import *
from elftools.elf.elffile import ELFFile

import os
import pathlib

ROOT = pathlib.Path(__file__).resolve().parents[3]
_CANDIDATES = [
    os.environ.get('CALLY_LIBYOYO'),
    str(ROOT / 'reconstruction/live-mem/libyoyo_armv7.so'),
    os.path.expanduser('~/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so'),
]
SO = next((p for p in _CANDIDATES if p and os.path.exists(p)), _CANDIDATES[1])
PRECISE = 0x1e4298
SENTINEL = 0xdead0000
STACK = 0x70000000
STACK_SIZE = 0x20000
HEAP = 0x71000000
HEAP_SIZE = 0x40000
SCRATCH = 0x71300000
SCRATCH_SIZE = 0x10000


class Oracle:
    def __init__(self):
        self.uc = Uc(UC_ARCH_ARM, UC_MODE_ARM)
        with open(SO, 'rb') as f:
            elf = ELFFile(f)
            for seg in elf.iter_segments():
                if seg['p_type'] != 'PT_LOAD':
                    continue
                vaddr = seg['p_vaddr']
                data = seg.data()
                page = vaddr & ~0xfff
                total = ((vaddr - page + seg['p_memsz']) + 0xfff) & ~0xfff
                try:
                    self.uc.mem_map(page, total)
                except Exception:
                    pass
                self.uc.mem_write(vaddr, data)
        for base, size in ((STACK, STACK_SIZE), (HEAP, HEAP_SIZE), (SCRATCH, SCRATCH_SIZE)):
            self.uc.mem_map(base, size)
        # VFP must be enabled explicitly or every vpush/vldr traps as invalid.
        self.uc.reg_write(UC_ARM_REG_C1_C0_2, 0x00F00000)   # CPACR: CP10/CP11 on
        self.uc.reg_write(UC_ARM_REG_FPEXC, 0x40000000)     # FPEXC.EN
        # sinf/cosf go through the PLT; the GOT is unrelocated here, so answer
        # them in Python. Softfp: the float argument and result are in r0.
        import math
        def float_hook(fn):
            def hook(uc, addr, size, data):
                x = struct.unpack('<f', struct.pack('<I', uc.reg_read(UC_ARM_REG_R0)))[0]
                y = fn(x)
                uc.reg_write(UC_ARM_REG_R0, struct.unpack('<I', struct.pack('<f', y))[0])
                uc.reg_write(UC_ARM_REG_PC, uc.reg_read(UC_ARM_REG_LR))
            return hook
        self.uc.hook_add(UC_HOOK_CODE, float_hook(math.sin), begin=0xb6580, end=0xb6580)
        self.uc.hook_add(UC_HOOK_CODE, float_hook(math.cos), begin=0xb658c, end=0xb658c)
        # PreciseCollisionPoint calls floorf through its own PLT stub.
        self.uc.hook_add(UC_HOOK_CODE, float_hook(math.floor), begin=0xb6910, end=0xb6910)
        self.next = HEAP

    def alloc(self, size):
        size = (size + 0xf) & ~0xf
        addr = self.next
        self.next += size
        if self.next > HEAP + HEAP_SIZE:
            raise MemoryError('heap exhausted')
        return addr

    def sprite(self, width, height, mask_rows, base_x=0, base_y=0):
        """mask_rows: list of strings/bytes, one byte per pixel row (0/1)."""
        spr = self.alloc(0x100)
        # +0x18 is the "has masks" gate the prologue checks (ble -> return 0).
        self.uc.mem_write(spr + 0x18, struct.pack('<I', 1))
        self.uc.mem_write(spr + 0x1c, struct.pack('<I', width))
        self.uc.mem_write(spr + 0x20, struct.pack('<I', height))
        self.uc.mem_write(spr + 0x24, struct.pack('<i', base_x))
        self.uc.mem_write(spr + 0x28, struct.pack('<i', base_y))
        self.uc.mem_write(spr + 0x31, b'\x01')
        self.uc.mem_write(spr + 0x3c, struct.pack('<I', 1))
        bits = self.alloc(width * height)
        flat = bytearray()
        for row in mask_rows:
            flat.extend(bytes(1 if c else 0 for c in row))
        self.uc.mem_write(bits, bytes(flat))
        # [sprite+0x40] points at the per-frame entry table; entry+4 is the
        # bits pointer (the runner indexes it as base + frame*8).
        entry = self.alloc(8)
        self.uc.mem_write(entry + 4, struct.pack('<I', bits))
        self.uc.mem_write(spr + 0x40, struct.pack('<I', entry))
        return spr

    def rect(self, left, top, right, bottom):
        r = self.alloc(16)
        self.uc.mem_write(r, struct.pack('<4i', left, top, right, bottom))
        return r

    def call(self, frame_a, rect_a, xa, ya, sxa, sya, ang_a,
             spr_b, frame_b, rect_b, xb, yb, sxb, syb, ang_b):
        u = self.uc
        u.reg_write(UC_ARM_REG_SP, STACK + STACK_SIZE - 0x100)
        u.reg_write(UC_ARM_REG_LR, SENTINEL)
        u.reg_write(UC_ARM_REG_R0, self._cur_a)
        u.reg_write(UC_ARM_REG_R1, frame_a & 0xffffffff)
        u.reg_write(UC_ARM_REG_R2, rect_a)
        u.reg_write(UC_ARM_REG_R3, xa & 0xffffffff)
        sp = STACK + STACK_SIZE - 0x100
        stack = [ya & 0xffffffff, self._f32(sxa), self._f32(sya), self._f32(ang_a),
                 spr_b, frame_b & 0xffffffff, rect_b, xb & 0xffffffff, yb & 0xffffffff,
                 self._f32(sxb), self._f32(syb), self._f32(ang_b)]
        u.mem_write(sp, b''.join(struct.pack('<I', v) for v in stack))
        u.emu_start(PRECISE, SENTINEL, timeout=5_000_000)
        if u.reg_read(UC_ARM_REG_PC) != SENTINEL:
            raise RuntimeError('did not return: pc=%#x' % u.reg_read(UC_ARM_REG_PC))
        return u.reg_read(UC_ARM_REG_R0)

    def precise(self, spr_a, frame_a, rect_a, xa, ya, sxa, sya, ang_a,
                spr_b, frame_b, rect_b, xb, yb, sxb, syb, ang_b):
        self._cur_a = spr_a
        return self.call(frame_a, rect_a, xa, ya, sxa, sya, ang_a,
                         spr_b, frame_b, rect_b, xb, yb, sxb, syb, ang_b)

    @staticmethod
    def _f32(v):
        return struct.unpack('<I', struct.pack('<f', v))[0]


def main():
    o = Oracle()
    # 8x8 sprite: left half solid / right half solid, byte per pixel.
    left = [1, 1, 1, 1, 0, 0, 0, 0]
    right = [0, 0, 0, 0, 1, 1, 1, 1]
    a = o.sprite(8, 8, [left] * 8)
    b = o.sprite(8, 8, [right] * 8)
    def box(x, y, w=8, h=8):
        return o.rect(x, y, x + w - 1, y + h - 1)

    same = o.precise(a, 0, box(0, 0), 0, 0, 1.0, 1.0, 0.0,
                     b, 0, box(0, 0), 0, 0, 1.0, 1.0, 0.0)
    print('same spot, disjoint halves ->', same, '(want 0)')
    moved = o.precise(a, 0, box(0, 0), 0, 0, 1.0, 1.0, 0.0,
                      b, 0, box(-4, 0), -4, 0, 1.0, 1.0, 0.0)
    print('shifted -4 (halves meet)  ->', moved, '(want 1)')
    other = o.precise(a, 0, box(0, 0), 0, 0, 1.0, 1.0, 0.0,
                      b, 0, box(4, 0), 4, 0, 1.0, 1.0, 0.0)
    print('shifted +4 (apart)        ->', other, '(want 0)')


if __name__ == '__main__':
    main()
