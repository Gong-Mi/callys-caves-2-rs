#!/usr/bin/env python3
"""Original arm: Unicorn memory oracle for spSkeletonJson_readSkeletonData
@0x28b84c in libyoyo_armv7.so (SHA256 3bbedd09...).

Synthetic-memory layer (registered in the receipt):
  * complete PT_LOAD/BSS mapping, VFP enabled;
  * Json_create @0x287320 is answered with a staged tree of 32-byte nodes
    (the same tree the rebuild arm builds, see level_a_model.py);
  * _malloc/_free are answered through the .data ABS32 slots 0x3f7790/0x3f7794
    (the original's own _malloc/_free still execute and reach these slots) and
    through the malloc/free PLT entries the loader calls directly;
  * strlen/strcmp/strcasecmp/strcpy/strncpy/strncat/memset/memcpy/strdup/
    strtoul/setlocale are answered in Python against emulator memory;
  * cos/sin (double, core-register softfp) are PRESCRIBED to 1.0/0.0 on both
    arms so spRegionAttachment_updateOffset offsets are comparable;
  * the error reporter's console vcall (dbg_csol -> .bss 0x47a118 -> vtable+0xc)
    lands on a planted, inert object;
  * attachments are produced by a planted attachment-loader vtable whose
    createAttachment builds the same attachment record the rebuild fixture
    builds (region 10x20 atlas shape, mesh unit UVs).

No device claim: this is the original function executing over synthetic memory.
"""
import pathlib
import struct
import sys

from elftools.elf.elffile import ELFFile
from unicorn import Uc, UC_ARCH_ARM, UC_MODE_ARM, UC_HOOK_CODE, UC_HOOK_MEM_UNMAPPED
from unicorn.arm_const import (
    UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R3,
    UC_ARM_REG_SP, UC_ARM_REG_LR, UC_ARM_REG_PC,
    UC_ARM_REG_C1_C0_2, UC_ARM_REG_FPEXC,
)

ROOT = pathlib.Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / 'harness'))
import handler_oracle as ho  # noqa: E402  (PLT layout derivation precedent)

SO = '/data/data/com.termux/files/home/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so'
PIN = '3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a'
PLT = ho.plt_symbols(SO)

ENTRY = 0x28b84c
SENT = 0xdead0000
STACK, STACK_SIZE = 0x70000000, 0x20000
HEAP, HEAP_SIZE = 0x71000000, 0x200000
SCRATCH, SCRATCH_SIZE = 0x73000000, 0x40000


class Oracle:
    def __init__(self, log=None):
        self.log = log or (lambda *a: None)
        self.plt_entries = PLT
        self.hooked_names = set()
        self.uc = Uc(UC_ARCH_ARM, UC_MODE_ARM)
        with open(SO, 'rb') as fh:
            elf = ELFFile(fh)
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
                if data:
                    self.uc.mem_write(vaddr, data)
        for base, size in ((STACK, STACK_SIZE), (HEAP, HEAP_SIZE),
                           (SCRATCH, SCRATCH_SIZE)):
            self.uc.mem_map(base, size)
        self.uc.reg_write(UC_ARM_REG_C1_C0_2, 0x00F00000)   # CP10/CP11
        self.uc.reg_write(UC_ARM_REG_FPEXC, 0x40000000)     # FPEXC.EN

        self.heap = HEAP
        self.heap_end = HEAP + HEAP_SIZE
        self.next = SCRATCH
        self.scratch_end = SCRATCH + SCRATCH_SIZE
        self.allocs = []
        self.frees = []
        self.calls = []
        self.attachments = []
        self.tree = 0
        self.root_disposes = 0     # Json_dispose(ROOT) calls (root release)
        self.json_fail = False     # Json_create answers NULL (parser failure)
        self.json_error = 'parse failed at 1'
        self.C_ptr = self.scratch_alloc(2, 2)
        self.uc.mem_write(self.C_ptr, b'C\0')
        self._install()
        self.uc.hook_add(UC_HOOK_MEM_UNMAPPED, self._unmapped)

    def _unmapped(self, uc, access, addr, size, value, user):
        self.log('UNMAPPED %#x access=%d pc=%#x lr=%#x' % (
            addr, access, uc.reg_read(UC_ARM_REG_PC),
            uc.reg_read(UC_ARM_REG_LR)))
        return False

    def scratch_alloc(self, n, align=8):
        self.next = (self.next + align - 1) & ~(align - 1)
        addr = self.next
        self.next += n
        if self.next > self.scratch_end:
            raise MemoryError('scratch exhausted')
        return addr

    def alloc(self, n):
        n = max((n + 15) & ~15, 16)
        addr = self.heap
        self.heap += n
        if self.heap > self.heap_end:
            raise MemoryError('heap exhausted')
        self.uc.mem_write(addr, b'\0' * n)
        self.allocs.append((addr, n))
        return addr

    def strz(self, text):
        blob = text.encode() if isinstance(text, str) else text
        addr = self.scratch_alloc(len(blob) + 1)
        self.uc.mem_write(addr, blob + b'\0')
        return addr

    def read_cstr(self, addr, limit=4096):
        if not addr:
            return ''
        out = bytearray()
        for k in range(limit):
            ch = self.uc.mem_read(addr + k, 1)[0]
            if ch == 0:
                break
            out.append(ch)
        return out.decode('utf-8', 'replace')

    # -- hook plumbing -----------------------------------------------------
    def _hook_code(self, addr, fn):
        def hook(uc, _a, _s, _d):
            fn(uc)
        self.uc.hook_add(UC_HOOK_CODE, hook, begin=addr, end=addr)

    def _ret(self, value):
        def fn(uc):
            uc.reg_write(UC_ARM_REG_R0, value & 0xffffffff)
            uc.reg_write(UC_ARM_REG_PC, uc.reg_read(UC_ARM_REG_LR))
        return fn

    def _hook_retfn(self, name, fn):
        addr = PLT.get(name)
        if addr is None:
            self.log('missing PLT', name)
            return
        self.hooked_names.add(name)

        def hook(uc):
            args = [uc.reg_read(r) & 0xffffffff for r in
                    (UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_R3)]
            ret = fn(*args)
            self.calls.append((name, args, ret))
            uc.reg_write(UC_ARM_REG_R0, ret & 0xffffffff)
            uc.reg_write(UC_ARM_REG_PC, uc.reg_read(UC_ARM_REG_LR))
        self._hook_code(addr, hook)

    # -- hooks -------------------------------------------------------------
    def _install(self):
        uc = self.uc
        self.malloc_stub = self.scratch_alloc(4, 4)
        self.free_stub = self.scratch_alloc(4, 4)
        # .data R_ARM_ABS32 malloc/free (addend 0 in the dumped image)
        uc.mem_write(0x3f7790, struct.pack('<I', self.malloc_stub))
        uc.mem_write(0x3f7794, struct.pack('<I', self.free_stub))

        def h_malloc(uc_):
            size = uc_.reg_read(UC_ARM_REG_R0) & 0xffffffff
            tag = uc_.reg_read(UC_ARM_REG_R1) & 0xffffffff
            line = uc_.reg_read(UC_ARM_REG_R2) & 0xffffffff
            addr = self.alloc(max(size, 1))
            self.calls.append(('_malloc', [size, tag, line], addr))
            uc_.reg_write(UC_ARM_REG_R0, addr)
            uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

        def h_free(uc_):
            ptr = uc_.reg_read(UC_ARM_REG_R0) & 0xffffffff
            self.frees.append(ptr)
            self.calls.append(('_free', [ptr], 0))
            uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))

        self._hook_code(self.malloc_stub, h_malloc)
        self.hooked_names.add('_malloc_slot')
        self._hook_code(self.free_stub, h_free)
        self.hooked_names.add('_free_slot')
        for name, fn in (('malloc', h_malloc), ('free', h_free)):
            if PLT.get(name):
                self._hook_code(PLT[name], fn)
                self.hooked_names.add(name)

        def h_json_create(uc_):
            ret = 0 if self.json_fail else self.tree
            self.calls.append(('Json_create',
                               [uc_.reg_read(UC_ARM_REG_R0)], ret))
            uc_.reg_write(UC_ARM_REG_R0, ret)
            uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))
        self._hook_code(0x287320, h_json_create)
        self.hooked_names.add('Json_create')

        # Json_getError @0x2872b8: answered with the staged text so the
        # "Invalid skeleton JSON: " tail is comparable on both arms.
        def h_json_error(uc_):
            ptr = self.strz(self.json_error)
            self.calls.append(('Json_getError', [], ptr))
            uc_.reg_write(UC_ARM_REG_R0, ptr)
            uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))
        self._hook_code(0x2872b8, h_json_error)
        self.hooked_names.add('Json_getError')

        # Json_dispose @0x2872c8: observe the argument, then let the original
        # body run (the hook does not touch PC).  Root release vs leak is the
        # disposition this counts on the original arm.
        def h_json_dispose(uc_):
            arg = uc_.reg_read(UC_ARM_REG_R0) & 0xffffffff
            if self.tree and arg == self.tree:
                self.root_disposes += 1
            self.calls.append(('Json_dispose', [arg], 0))
        self._hook_code(0x2872c8, h_json_dispose)
        self.hooked_names.add('Json_dispose')

        self._hook_retfn('setlocale', lambda cat, loc, *_: self.C_ptr)

        def f_strdup(src, *_):
            text = self.read_cstr(src)
            addr = self.alloc(len(text) + 1)
            uc.mem_write(addr, text.encode() + b'\0')
            return addr
        self._hook_retfn('strdup', f_strdup)

        def rd(addr, n=None):
            if n is None:
                return self.read_cstr(addr).encode('latin1')
            out = bytearray()
            for k in range(n):
                try:
                    ch = uc.mem_read(addr + k, 1)[0]
                except Exception:
                    break
                out.append(ch)
            return bytes(out)

        self._hook_retfn('strlen', lambda a, *_: len(rd(a)))

        def f_strcmp(a, b, *_):
            x, y = rd(a), rd(b)
            return 0 if x == y else (1 if x > y else -1) & 0xffffffff
        self._hook_retfn('strcmp', f_strcmp)

        def f_strcasecmp(a, b, *_):
            x, y = rd(a).lower(), rd(b).lower()
            return 0 if x == y else (1 if x > y else -1) & 0xffffffff
        self._hook_retfn('strcasecmp', f_strcasecmp)

        def f_strcpy(dst, src, *_):
            uc.mem_write(dst, rd(src) + b'\0')
            return dst
        self._hook_retfn('strcpy', f_strcpy)

        def f_strncpy(dst, src, n, *_):
            blob = rd(src)[:n]
            uc.mem_write(dst, blob + b'\0' * (n - len(blob)))
            return dst
        self._hook_retfn('strncpy', f_strncpy)

        def f_strncat(dst, src, n, *_):
            uc.mem_write(dst, rd(dst) + rd(src)[:n] + b'\0')
            return dst
        self._hook_retfn('strncat', f_strncat)

        def f_memset(dst, val, n, *_):
            if n:
                uc.mem_write(dst, bytes([val & 0xff]) * n)
            return dst
        self._hook_retfn('memset', f_memset)

        def f_memcpy(dst, src, n, *_):
            if n:
                uc.mem_write(dst, bytes(uc.mem_read(src, n)))
            return dst
        self._hook_retfn('memcpy', f_memcpy)

        def f_strtoul(src, endp, base, *_):
            text = rd(src).split(b'\0')[0].decode('latin1').strip()
            try:
                value = int(text[:8], 16)
            except Exception:
                value = 0
            if endp:
                uc.mem_write(endp, struct.pack('<I', src + len(text)))
            return value
        self._hook_retfn('strtoul', f_strtoul)

        def hook_double(name, value):
            addr = PLT.get(name)
            if addr is None:
                return
            self.hooked_names.add(name)

            def hook(uc_):
                self.calls.append((name, [uc_.reg_read(UC_ARM_REG_R0),
                                          uc_.reg_read(UC_ARM_REG_R1)], value))
                bits = struct.unpack('<Q', struct.pack('<d', value))[0]
                uc_.reg_write(UC_ARM_REG_R0, bits & 0xffffffff)
                uc_.reg_write(UC_ARM_REG_R1, bits >> 32)
                uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))
            self._hook_code(addr, hook)
        hook_double('cos', 1.0)
        hook_double('sin', 0.0)

        # ReportSpineError: dbg_csol -> 0x47a118 -> vtable -> +0xc
        console = 0x47a118
        vtable = self.scratch_alloc(16, 4)
        stub = self.scratch_alloc(4, 4)
        uc.mem_write(console, struct.pack('<I', vtable))
        uc.mem_write(vtable + 0xc, struct.pack('<I', stub))
        self._hook_code(stub, self._ret(0))
        self.hooked_names.add('console')

        self.guard_hit = None
        seen = set()
        for name, addr in sorted(self.plt_entries.items(),
                                 key=lambda kv: kv[1]):
            if name in self.hooked_names or addr in seen:
                continue
            seen.add(addr)

            def mk(n, a):
                def guard(uc_, _addr, _size, _data):
                    self.guard_hit = (n, a)
                    self.log('STOP unhooked PLT %s @%#x lr=%#x' % (
                        n, a, uc_.reg_read(UC_ARM_REG_LR)))
                    uc_.emu_stop()
                return guard
            uc.hook_add(UC_HOOK_CODE, mk(name, addr), begin=addr, end=addr)

    # -- planted attachment loader ----------------------------------------
    def _make_attachment(self, typ, name_ptr):
        size = {0: 0x9c, 1: 0x24, 2: 0x94, 3: 0x94, 4: 0x34}[typ]
        addr = self.alloc(size)
        uc = self.uc
        name = self.read_cstr(name_ptr)
        name_copy = self.alloc(len(name) + 1)
        uc.mem_write(name_copy, name.encode() + b'\0')
        # The stored type word (+0x04) must model the REAL atlas loader's
        # answers: identity for region/bbox/mesh/path; a linkedmesh request
        # answered as mesh (2) — the glue's jump table then routes it to the
        # shared mesh parser either way. The earlier '0 for (0,1,4)' made the
        # oracle's bbox/path attachments get parsed by the REGION parser.
        stored_type = {0: 0, 1: 1, 2: 2, 3: 2, 4: 4}[typ]
        uc.mem_write(addr, struct.pack('<IIII', name_copy,
                                       stored_type,
                                       self.avtable, 0))
        if typ == 0:
            for off in (0x1c, 0x20):
                uc.mem_write(addr + off, struct.pack('<f', 1.0))
            for off in (0x30, 0x34, 0x38, 0x3c):
                uc.mem_write(addr + off, struct.pack('<f', 1.0))
            for off, val in ((0x4c, 10), (0x50, 20), (0x54, 10), (0x58, 20)):
                uc.mem_write(addr + off, struct.pack('<i', val))
            uc.mem_write(addr + 0x7c, struct.pack(
                '<8f', 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 1.0))
        elif typ in (2, 3):
            for off in (0x68, 0x6c, 0x70, 0x74):
                uc.mem_write(addr + off, struct.pack('<f', 1.0))
            for off, val in ((0x40, 0.0), (0x44, 0.0),
                             (0x48, 1.0), (0x4c, 1.0)):
                uc.mem_write(addr + off, struct.pack('<f', val))
        self.attachments.append((typ, addr))
        return addr

    def _install_loader(self):
        uc = self.uc
        self.loader = self.scratch_alloc(16, 4)
        vtable = self.scratch_alloc(16, 4)
        self.avtable = self.scratch_alloc(16, 4)
        stubs = [self.scratch_alloc(4, 4) for _ in range(4)]
        uc.mem_write(self.loader, struct.pack('<IIII', 0, 0, vtable, 0))
        uc.mem_write(vtable, struct.pack('<IIII', stubs[0], stubs[1],
                                         stubs[2], stubs[3]))
        uc.mem_write(self.avtable, struct.pack('<IIII', stubs[3], stubs[3],
                                               stubs[3], stubs[3]))

        def h_create(uc_):
            typ = uc_.reg_read(UC_ARM_REG_R2) & 0xffffffff
            name = uc_.reg_read(UC_ARM_REG_R3) & 0xffffffff
            sp = uc_.reg_read(UC_ARM_REG_SP)
            path = struct.unpack('<I', bytes(uc_.mem_read(sp, 4)))[0]
            self.calls.append(('createAttachment', [typ, name, path], 0))
            att = self._make_attachment(typ, name)
            uc_.reg_write(UC_ARM_REG_R0, att)
            uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))
        self._hook_code(stubs[0], h_create)

        def h_conf(uc_):
            self.calls.append(('configureAttachment',
                               [uc_.reg_read(UC_ARM_REG_R0),
                                uc_.reg_read(UC_ARM_REG_R1)], 0))
            uc_.reg_write(UC_ARM_REG_PC, uc_.reg_read(UC_ARM_REG_LR))
        self._hook_code(stubs[1], h_conf)
        for stub in (stubs[2], stubs[3]):
            self._hook_code(stub, self._ret(0))

    # -- tree --------------------------------------------------------------
    def build_tree(self, nodes):
        uc = self.uc
        ptrs = []
        for node in nodes:
            addr = self.scratch_alloc(32, 4)
            ptrs.append(addr)
            uc.mem_write(addr, b'\0' * 32)
            if node.key is not None:
                uc.mem_write(addr + 0x1c,
                             struct.pack('<I', self.strz(node.key)))
            if node.s is not None:
                uc.mem_write(addr + 0x10,
                             struct.pack('<I', self.strz(node.s)))
            uc.mem_write(addr + 0x14,
                         struct.pack('<i', node.i if node.i is not None else 0))
            uc.mem_write(addr + 0x18,
                         struct.pack('<I', node.f if node.f is not None else 0))
            uc.mem_write(addr + 0x08,
                         struct.pack('<I', node.kind or 0))
            if node.declared is not None:
                uc.mem_write(addr + 0x0c,
                             struct.pack('<I', node.declared))
        index = {id(n): k for k, n in enumerate(nodes)}
        for k, node in enumerate(nodes):
            if node.kids:
                child = [ptrs[index[id(kid)]] for kid in node.kids]
                for a, b in zip(child, child[1:]):
                    uc.mem_write(a, struct.pack('<I', b))
                uc.mem_write(ptrs[k] + 4, struct.pack('<I', child[0]))
        self.tree = ptrs[0]
        return ptrs[0]

    def setup(self, scale=2.0, loader=True):
        if loader:
            self._install_loader()
        selfptr = self.scratch_alloc(28, 4)
        self.uc.mem_write(selfptr, b'\0' * 28)
        self.uc.mem_write(selfptr, struct.pack('<f', scale))
        if loader:
            self.uc.mem_write(selfptr + 4, struct.pack('<I', self.loader))
        self.selfptr = selfptr
        return selfptr

    def call(self):
        uc = self.uc
        sp = STACK + STACK_SIZE - 0x100
        uc.reg_write(UC_ARM_REG_SP, sp)
        uc.reg_write(UC_ARM_REG_LR, SENT)
        uc.reg_write(UC_ARM_REG_R0, self.selfptr)
        uc.reg_write(UC_ARM_REG_R1, self.strz('{}'))
        uc.emu_start(ENTRY, SENT, timeout=30_000_000)
        if self.guard_hit:
            raise RuntimeError('unhooked PLT %s @%#x' % self.guard_hit)
        if uc.reg_read(UC_ARM_REG_PC) != SENT:
            raise RuntimeError('did not return: pc=%#x' % uc.reg_read(UC_ARM_REG_PC))
        return uc.reg_read(UC_ARM_REG_R0) & 0xffffffff

    def run(self, tree_nodes, scale=2.0, json_fail=False, json_error=None):
        self.json_fail = json_fail
        if json_error is not None:
            self.json_error = json_error
        self.build_tree(tree_nodes)
        self.setup(scale=scale, loader=True)
        ret = self.call()
        error = self.read_cstr(
            struct.unpack('<I', bytes(self.uc.mem_read(self.selfptr + 8, 4)))[0])
        return ret, error
