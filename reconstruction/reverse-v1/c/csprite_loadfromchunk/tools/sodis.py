#!/usr/bin/env python3
"""Static-only reader/disassembler for libyoyo_armv7.so (no execution of target).

Provides:
  - vaddr -> file offset mapping from program headers (PT_LOAD)
  - ARM/Thumb disassembly of an address range via capstone
  - raw word/dword readers
  - literal-pool detection for PC-relative loads
"""
import struct, sys, json

SO = "/data/data/com.termux/files/home/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so"


class SOImage:
    def __init__(self, path=SO):
        self.path = path
        self.buf = open(path, "rb").read()
        assert self.buf[:4] == b"\x7fELF"
        self.is32 = self.buf[4] == 1
        e_phoff, = struct.unpack_from("<I", self.buf, 0x1C)
        e_phentsize, e_phnum = struct.unpack_from("<HH", self.buf, 0x2A)
        self.loads = []
        for i in range(e_phnum):
            off = e_phoff + i * e_phentsize
            p_type, p_offset, p_vaddr, p_paddr, p_filesz, p_memsz, p_flags, p_align = \
                struct.unpack_from("<IIIIIIII", self.buf, off)
            if p_type == 1:  # PT_LOAD
                self.loads.append(dict(off=p_offset, vaddr=p_vaddr, filesz=p_filesz,
                                       memsz=p_memsz, flags=p_flags))
        self.loads.sort(key=lambda s: s["vaddr"])

    def fileoff(self, va):
        for s in self.loads:
            if s["vaddr"] <= va < s["vaddr"] + s["filesz"]:
                return s["off"] + (va - s["vaddr"])
        return None

    def read(self, va, n):
        o = self.fileoff(va)
        if o is None:
            raise KeyError("vaddr 0x%x not in any PT_LOAD filesz" % va)
        return self.buf[o:o + n]

    def u32(self, va):
        return struct.unpack("<I", self.read(va, 4))[0]

    def s32(self, va):
        return struct.unpack("<i", self.read(va, 4))[0]

    def f32(self, va):
        return struct.unpack("<f", self.read(va, 4))[0]


def disasm(img, start, end, arm=True):
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM if arm else capstone.CS_MODE_THUMB)
    md.detail = True
    code = img.read(start, end - start)
    out = []
    for insn in md.disasm(code, start):
        out.append(insn)
    return out


def fmt(insns):
    lines = []
    for i in insns:
        lines.append("0x%08x  %-30s %s %s" % (i.address, i.bytes.hex(),
                                               i.mnemonic, i.op_str))
    return "\n".join(lines)


if __name__ == "__main__":
    img = SOImage()
    print("PT_LOAD:", json.dumps(img.loads, indent=1))
    a = int(sys.argv[1], 16) if len(sys.argv) > 1 else 0x1e972c
    b = int(sys.argv[2], 16) if len(sys.argv) > 2 else 0x1e9b68
    print(fmt(disasm(img, a, b)))
