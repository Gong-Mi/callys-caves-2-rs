#!/usr/bin/env python3
"""Generic Unicorn oracle for one libyoyo ARMv7 function.

Why this exists (new evidence standard, reverse-toolkit db/SCHEMA.md §1):
a `proven` claim must carry a reproducible judgement - device, input domain,
command, receipt - not just an instruction citation. For the C-ification line
the device is the original function itself, executed in Unicorn; the receipt is
a JSON file that a rerun reproduces byte for byte.

This module owns ONLY the process plumbing: map the pinned ELF, enable the VFP,
stub out the callees a pure function may reach (VMError / JSThrow* / FREE_*),
and call an entry point with four words in r0..r3 plus a caller-written stack.

It deliberately does not know any handler's semantics - that belongs in the
per-handler harness, so a wrong model cannot hide inside the plumbing.
"""
import os
import pathlib
import struct

from elftools.elf.elffile import ELFFile
from unicorn import Uc, UC_ARCH_ARM, UC_MODE_ARM, UC_HOOK_CODE
from unicorn.arm_const import (
    UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R3,
    UC_ARM_REG_SP, UC_ARM_REG_LR, UC_ARM_REG_PC,
    UC_ARM_REG_C1_C0_2, UC_ARM_REG_FPEXC,
)

ROOT = pathlib.Path(__file__).resolve().parents[2]
_CANDIDATES = [
    os.environ.get('CALLY_LIBYOYO'),
    str(ROOT / 'reconstruction/live-mem/libyoyo_armv7.so'),
    os.path.expanduser('~/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so'),
    os.path.expanduser('~/cally-oracle/libyoyo.so'),
]
SO = next((p for p in _CANDIDATES if p and os.path.exists(p)), _CANDIDATES[1])

SENTINEL = 0xdead0000
STACK = 0x70000000
STACK_SIZE = 0x20000
HEAP = 0x71000000
HEAP_SIZE = 0x80000

# Callees a strong-typed handler arm reaches. Each is answered in Python so the
# unrelocated GOT never has to resolve: the call is RECORDED (that is evidence),
# then returned to the caller.
# libc/allocator entries in .plt (derived from .rel.plt; .plt base 0xb64e8,
# 16 bytes/entry, entry i at base+16*(i+1)). A loader parser cannot run without
# these: it allocates its frame/mask arrays.
PLT_LIBC = {
    0xb6558: 'malloc',
    0xb6578: 'free',
    0xb65e8: 'memset',
    0xb65f8: 'memcpy',
    0xb6718: 'memmove',
    0xb6e88: 'realloc',
}

STUBS = {
    0xd4210: 'VMError',                 # void VMError(VMExec*, const char*, ...)
    0x254b04: 'JSThrowReferenceError',  # void (const char*)
    0x24e58c: 'JSThrowTypeError',       # void (const char*)
    0xc0a7c: 'FREE_RValue__Pre',        # void (RValue*)
}


class Oracle:
    def __init__(self, so=SO, extra_stubs=None, libc=False):
        """extra_stubs: {addr: name} answered in Python (no-op + recorded).

        Loader parsers often start by calling their own Clear()/Init(), which
        walks buffers or vtables an unrelocated image cannot provide. Stubbing
        those is legitimate as long as (a) the call is recorded, (b) both arms
        start from the same destination state, and (c) the receipt says which
        callees were stubbed.
        """
        self.so = so
        self.stubbed = dict(STUBS)
        if extra_stubs:
            self.stubbed.update(extra_stubs)
        self.libc = libc
        self.allocs = []        # [(addr, size)] in allocation order
        self._alloc_size = {}
        self.uc = Uc(UC_ARCH_ARM, UC_MODE_ARM)
        with open(so, 'rb') as f:
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
        for base, size in ((STACK, STACK_SIZE), (HEAP, HEAP_SIZE)):
            self.uc.mem_map(base, size)
        self.uc.reg_write(UC_ARM_REG_C1_C0_2, 0x00F00000)
        self.uc.reg_write(UC_ARM_REG_FPEXC, 0x40000000)
        self.heap = HEAP
        self.calls = []
        for addr, name in self.stubbed.items():
            self.uc.hook_add(UC_HOOK_CODE, self._stub(addr, name), begin=addr, end=addr)
        if libc:
            self._install_libc()

    def _install_libc(self):
        """Answer malloc/free/mem* in Python so a parser that builds arrays can run.

        Allocation is deterministic (bump allocator), so the same input record
        yields the same addresses on every run - and the receipt records the
        allocation list, which is what pointer normalisation later keys on.
        """
        u = self.uc

        def hook_malloc(uc, _a, _s, _d):
            size = uc.reg_read(UC_ARM_REG_R0) & 0xffffffff
            addr = self.alloc(max(size, 1))
            self.allocs.append((addr, size))
            self._alloc_size[addr] = size
            self.calls.append({'name': 'malloc', 'args': [size, 0, 0, 0], 'ret': addr})
            uc.reg_write(UC_ARM_REG_R0, addr)
            uc.reg_write(UC_ARM_REG_PC, uc.reg_read(UC_ARM_REG_LR))

        def hook_free(uc, _a, _s, _d):
            self.calls.append({'name': 'free', 'args': [uc.reg_read(UC_ARM_REG_R0), 0, 0, 0]})
            uc.reg_write(UC_ARM_REG_PC, uc.reg_read(UC_ARM_REG_LR))

        def hook_memset(uc, _a, _s, _d):
            dst, val, n = (uc.reg_read(r) & 0xffffffff for r in
                           (UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2))
            if n:
                uc.mem_write(dst, bytes([val & 0xff]) * n)
            self.calls.append({'name': 'memset', 'args': [dst, val, n]})
            uc.reg_write(UC_ARM_REG_R0, dst)
            uc.reg_write(UC_ARM_REG_PC, uc.reg_read(UC_ARM_REG_LR))

        def hook_memcpy(uc, _a, _s, _d):
            dst = uc.reg_read(UC_ARM_REG_R0) & 0xffffffff
            src = uc.reg_read(UC_ARM_REG_R1) & 0xffffffff
            n = uc.reg_read(UC_ARM_REG_R2) & 0xffffffff
            if n:
                uc.mem_write(dst, bytes(uc.mem_read(src, n)))
            self.calls.append({'name': 'memcpy', 'args': [dst, src, n]})
            uc.reg_write(UC_ARM_REG_R0, dst)
            uc.reg_write(UC_ARM_REG_PC, uc.reg_read(UC_ARM_REG_LR))

        def hook_realloc(uc, _a, _s, _d):
            ptr = uc.reg_read(UC_ARM_REG_R0) & 0xffffffff
            size = uc.reg_read(UC_ARM_REG_R1) & 0xffffffff
            old = self._alloc_size.get(ptr, 0)
            addr = self.alloc(max(size, 1))
            if old:
                uc.mem_write(addr, bytes(uc.mem_read(ptr, min(old, size))))
            self.allocs.append((addr, size))
            self._alloc_size[addr] = size
            self.calls.append({'name': 'realloc', 'args': [ptr, size, 0, 0], 'ret': addr})
            uc.reg_write(UC_ARM_REG_R0, addr)
            uc.reg_write(UC_ARM_REG_PC, uc.reg_read(UC_ARM_REG_LR))

        for addr, fn in ((0xb6558, hook_malloc), (0xb6578, hook_free),
                         (0xb65e8, hook_memset), (0xb65f8, hook_memcpy),
                         (0xb6718, hook_memcpy), (0xb6e88, hook_realloc)):
            u.hook_add(UC_HOOK_CODE, fn, begin=addr, end=addr)

    def _stub(self, addr, name):
        def hook(uc, _addr, _size, _data):
            # Copy varargs words so a caller-variadic stub stays inspectable.
            frame = [uc.reg_read(r) for r in (UC_ARM_REG_R0, UC_ARM_REG_R1,
                                              UC_ARM_REG_R2, UC_ARM_REG_R3)]
            self.calls.append({'name': name, 'args': frame})
            uc.reg_write(UC_ARM_REG_PC, uc.reg_read(UC_ARM_REG_LR))
            uc.reg_write(UC_ARM_REG_R0, 0)
        return hook

    def alloc(self, size, align=16):
        size = (size + align - 1) // align * align
        addr = self.heap
        self.heap += size
        if self.heap > HEAP + HEAP_SIZE:
            raise MemoryError('heap exhausted')
        return addr

    def read(self, addr, n):
        return self.uc.mem_read(addr, n)

    def write(self, addr, blob):
        self.uc.mem_write(addr, blob)

    def read_cstr(self, addr, limit=256):
        out = bytearray()
        for i in range(limit):
            b = self.uc.mem_read(addr + i, 1)[0]
            if b == 0:
                break
            out.append(b)
        return bytes(out).decode('utf-8', 'replace')

    def call(self, entry, r0=0, r1=0, r2=0, r3=0, stack_words=(), timeout_us=5_000_000):
        u = self.uc
        self.calls = []
        sp = STACK + STACK_SIZE - 0x100
        u.reg_write(UC_ARM_REG_SP, sp)
        u.reg_write(UC_ARM_REG_LR, SENTINEL)
        u.reg_write(UC_ARM_REG_R0, r0 & 0xffffffff)
        u.reg_write(UC_ARM_REG_R1, r1 & 0xffffffff)
        u.reg_write(UC_ARM_REG_R2, r2 & 0xffffffff)
        u.reg_write(UC_ARM_REG_R3, r3 & 0xffffffff)
        if stack_words:
            u.mem_write(sp, b''.join(struct.pack('<I', w & 0xffffffff) for w in stack_words))
        u.emu_start(entry, SENTINEL, timeout=timeout_us)
        if u.reg_read(UC_ARM_REG_PC) != SENTINEL:
            raise RuntimeError('did not return to sentinel: pc=%#x' % u.reg_read(UC_ARM_REG_PC))
        return u.reg_read(UC_ARM_REG_R0) & 0xffffffff
