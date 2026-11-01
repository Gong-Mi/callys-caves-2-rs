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
def plt_symbols(so):
    """name -> PLT entry address, derived from the section headers.

    ARM PLT layout in this library: a 16-byte PLT0 (str lr / ldr lr / add lr /
    ldr pc) followed by 12-byte entries (`add ip,pc,#..; add ip,ip,#..;
    ldr pc,[ip,#..]!`), one per .rel.plt relocation in file order. Getting this
    stride wrong silently hooks the *neighbouring* function - which is exactly
    how an earlier version of this file "stubbed strlen" by accident.
    """
    out = {}
    with open(so, 'rb') as f:
        elf = ELFFile(f)
        base = elf.get_section_by_name('.plt')['sh_addr']
        rel = elf.get_section_by_name('.rel.plt')
        sym = elf.get_section_by_name('.dynsym')
        for i, r in enumerate(rel.iter_relocations()):
            name = sym.get_symbol(r['r_info_sym']).name
            out.setdefault(name, base + 16 + 12 * i)
    return out

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

        plt = plt_symbols(self.so)
        self.plt = plt
        self.libc_hooked = []
        for name, fn in (('malloc', hook_malloc), ('free', hook_free),
                         ('memset', hook_memset), ('memcpy', hook_memcpy),
                         ('memmove', hook_memcpy), ('realloc', hook_realloc)):
            addr = plt.get(name)
            if addr is None:
                continue
            u.hook_add(UC_HOOK_CODE, fn, begin=addr, end=addr)
            self.libc_hooked.append((name, addr))
        self._install_strings()
        self._install_math()
        self._install_printf()
        self._install_threads()

    def _install_threads(self):
        """pthread/semaphore family: answer without creating host threads.

        The loaders take a mutex around the resource cache; a real pthread is
        neither needed nor wanted here. pthread_create deliberately fails (11 =
        EAGAIN) so a parser that tries to spawn a worker takes its error path
        instead of silently doing nothing.
        """
        u = self.uc
        plt = plt_symbols(self.so)
        zero = ('pthread_mutexattr_init', 'pthread_mutexattr_settype',
                'pthread_mutexattr_destroy', 'pthread_mutex_init',
                'pthread_mutex_lock', 'pthread_mutex_unlock',
                'pthread_mutex_destroy', 'pthread_cond_init', 'pthread_cond_wait',
                'pthread_cond_signal', 'pthread_cond_broadcast',
                'pthread_cond_destroy', 'pthread_once', 'pthread_key_create',
                'sem_init', 'sem_post', 'sem_wait', 'sem_destroy',
                'pthread_attr_init', 'pthread_attr_setdetachstate',
                'pthread_attr_destroy', 'pthread_detach', 'pthread_join')
        fail = ('pthread_create',)

        def hook(name, ret):
            addr = plt.get(name)
            if addr is None:
                return

            def h(uc, _a, _s, _d):
                self.calls.append({'name': name,
                                   'args': [uc.reg_read(r) & 0xffffffff for r in
                                            (UC_ARM_REG_R0, UC_ARM_REG_R1,
                                             UC_ARM_REG_R2, UC_ARM_REG_R3)],
                                   'ret': ret})
                uc.reg_write(UC_ARM_REG_R0, ret & 0xffffffff)
                uc.reg_write(UC_ARM_REG_PC, uc.reg_read(UC_ARM_REG_LR))
            u.hook_add(UC_HOOK_CODE, h, begin=addr, end=addr)
            self.libc_hooked.append((name, addr))

        for n in zero:
            hook(n, 0)
        for n in fail:
            hook(n, 11)

    def _install_printf(self):
        """sprintf/snprintf subset - loaders use it to build resnames/paths.

        Supports %s %c %d %i %u %x %X %f with optional width/precision/zero pad.
        Anything else is emitted literally and recorded, so an unsupported
        conversion shows up in the receipt instead of silently mangling a name.
        """
        import re
        u = self.uc
        plt = plt_symbols(self.so)

        def rd_cstr(addr, limit=4096):
            out = bytearray()
            while limit:
                b = u.mem_read(addr + len(out), 1)[0]
                if b == 0:
                    break
                out.append(b)
                limit -= 1
            return bytes(out)

        def fmt_variadic(fmt, args):
            out = []
            ai = 0
            i = 0
            unsupported = []
            while i < len(fmt):
                ch = fmt[i:i + 1]
                if ch != b'%':
                    out.append(ch)
                    i += 1
                    continue
                m = re.match(rb'%([-+ 0#]*)(\d*)(?:\.(\d+))?([diuxXcsf%])', fmt[i:])
                if not m:
                    out.append(ch)
                    unsupported.append('%')
                    i += 1
                    continue
                flags, width, prec, conv = m.groups()
                i += m.end()
                conv = conv.decode()
                if conv == '%':
                    out.append(b'%')
                    continue
                v = args[ai] if ai < len(args) else 0
                ai += 1
                if conv == 's':
                    blob = rd_cstr(v)
                elif conv == 'c':
                    blob = bytes([v & 0xff])
                elif conv in 'di':
                    blob = str(struct.unpack('<i', struct.pack('<I', v & 0xffffffff))[0]).encode()
                elif conv == 'u':
                    blob = str(v & 0xffffffff).encode()
                elif conv in 'xX':
                    blob = format(v & 0xffffffff, conv).encode()
                elif conv == 'f':
                    d = struct.unpack('<d', struct.pack('<II', args[ai - 1], args[ai] if ai < len(args) else 0))[0]
                    ai += 1
                    blob = ('%.*f' % (int(prec) if prec else 6, d)).encode()
                else:
                    blob = b''
                if width:
                    w = int(width)
                    pad = b'0' if b'0' in flags else b' '
                    blob = blob.rjust(w, pad) if b'-' not in flags else blob.ljust(w, pad)
                out.append(blob)
            return b''.join(out), unsupported

        def hook_printf(name, has_size):
            addr = plt.get(name)
            if addr is None:
                return

            def h(uc, _a, _s, _d):
                regs = (UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R3)
                vals = [uc.reg_read(r) & 0xffffffff for r in regs]
                if has_size:
                    dst, size, fmtp = vals[0], vals[1], vals[2]
                    args = vals[3:]
                else:
                    dst, fmtp = vals[0], vals[1]
                    size = 1 << 20
                    args = vals[2:]
                sp = uc.reg_read(UC_ARM_REG_SP)
                k = 0
                while len(args) < 8:
                    args.append(struct.unpack('<I', bytes(uc.mem_read(sp + 4 * k, 4)))[0])
                    k += 1
                fmt = rd_cstr(fmtp, 1024)
                text, unsupported = fmt_variadic(fmt, args)
                text = text[:max(size - 1, 0)]
                u.mem_write(dst, text + b'\0')
                self.calls.append({'name': name, 'args': [dst, fmtp],
                                   'fmt': fmt.decode('latin1'),
                                   'out': text.decode('latin1'),
                                   'unsupported': unsupported})
                uc.reg_write(UC_ARM_REG_R0, len(text))
                uc.reg_write(UC_ARM_REG_PC, uc.reg_read(UC_ARM_REG_LR))
            u.hook_add(UC_HOOK_CODE, h, begin=addr, end=addr)
            self.libc_hooked.append((name, addr))

        hook_printf('sprintf', False)
        hook_printf('snprintf', True)

    def _install_math(self):
        """float math the loaders use for animation curves / geometry (softfp)."""
        import math
        u = self.uc
        plt = plt_symbols(self.so)

        def f32(v):
            return struct.unpack('<f', struct.pack('<f', v))[0]

        def hook(name, fn, arity=1):
            addr = plt.get(name)
            if addr is None:
                return

            def h(uc, _a, _s, _d):
                args = [f32(struct.unpack('<f', struct.pack('<I', uc.reg_read(r)))[0])
                        for r in (UC_ARM_REG_R0, UC_ARM_REG_R1)]
                try:
                    r = f32(fn(*args[:arity]))
                except (ValueError, OverflowError):
                    r = float('nan')
                self.calls.append({'name': name, 'args': args})
                uc.reg_write(UC_ARM_REG_R0,
                             struct.unpack('<I', struct.pack('<f', r))[0])
                uc.reg_write(UC_ARM_REG_PC, uc.reg_read(UC_ARM_REG_LR))
            u.hook_add(UC_HOOK_CODE, h, begin=addr, end=addr)
            self.libc_hooked.append((name, addr))

        for name, fn, ar in (('expf', math.exp, 1), ('ceilf', math.ceil, 1),
                             ('floorf', math.floor, 1), ('sqrtf', math.sqrt, 1),
                             ('sinf', math.sin, 1), ('cosf', math.cos, 1),
                             ('tanf', math.tan, 1), ('fabsf', abs, 1),
                             ('fmodf', math.fmod, 2), ('powf', math.pow, 2),
                             ('atan2f', math.atan2, 2), ('logf', math.log, 1)):
            hook(name, fn, ar)

    def _install_strings(self):
        """String functions a loader parser calls on WAD-resident names.

        They are answered against emulator memory, so the result depends only on
        the bytes in the mapped data file - no host state leaks into the run.
        """
        u = self.uc

        def rd_cstr(addr, limit=4096):
            out = bytearray()
            while limit:
                b = u.mem_read(addr + len(out), 1)[0]
                if b == 0:
                    break
                out.append(b)
                limit -= 1
            return bytes(out)

        def simple(name, fn):
            def hook(uc, _a, _s, _d):
                args = [uc.reg_read(r) & 0xffffffff for r in
                        (UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R3)]
                ret = fn(*args)
                self.calls.append({'name': name, 'args': args, 'ret': ret})
                uc.reg_write(UC_ARM_REG_R0, ret & 0xffffffff)
                uc.reg_write(UC_ARM_REG_PC, uc.reg_read(UC_ARM_REG_LR))
            return hook

        def f_strlen(dst, _b, _c, _d):
            return len(rd_cstr(dst))

        def f_strcmp(a, b, _c, _d):
            x, y = rd_cstr(a), rd_cstr(b)
            return 0 if x == y else (1 if x > y else -1) & 0xffffffff

        def f_strncmp(a, b, n, _d):
            x, y = rd_cstr(a)[:n], rd_cstr(b)[:n]
            return 0 if x == y else (1 if x > y else -1) & 0xffffffff

        def f_strcpy(dst, src, _c, _d):
            blob = rd_cstr(src)
            u.mem_write(dst, blob + b'\0')
            return dst

        def f_strncpy(dst, src, n, _d):
            blob = rd_cstr(src)[:n]
            u.mem_write(dst, blob + b'\0' * (n - len(blob)))
            return dst

        def f_strchr(s, ch, _c, _d):
            blob = rd_cstr(s)
            i = blob.find(bytes([ch & 0xff]))
            return 0 if i < 0 else s + i

        def f_strrchr(s, ch, _c, _d):
            blob = rd_cstr(s)
            i = blob.rfind(bytes([ch & 0xff]))
            return 0 if i < 0 else s + i

        def f_strstr(h, n, _c, _d):
            hay, needle = rd_cstr(h), rd_cstr(n)
            i = hay.find(needle)
            return 0 if i < 0 else h + i

        def f_atoi(s, _b, _c, _d):
            blob = rd_cstr(s).strip()
            try:
                return int(blob.split(b'\0')[0] or b'0')
            except ValueError:
                return 0

        def f_strtol(s, endp, _base, _d):
            blob = rd_cstr(s).strip()
            try:
                v = int(blob)
            except ValueError:
                v = 0
            if endp:
                u.mem_write(endp, struct.pack('<I', s))
            return v & 0xffffffff

        plt = plt_symbols(self.so)
        for name, fn in (('strlen', f_strlen), ('strcmp', f_strcmp),
                         ('strncmp', f_strncmp), ('strcpy', f_strcpy),
                         ('strncpy', f_strncpy), ('strchr', f_strchr),
                         ('strrchr', f_strrchr), ('strstr', f_strstr),
                         ('atoi', f_atoi), ('strtol', f_strtol)):
            addr = plt.get(name)
            if addr is None:
                continue
            u.hook_add(UC_HOOK_CODE, simple(name, fn), begin=addr, end=addr)
            self.libc_hooked.append((name, addr))

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
